// file: util/logger.dart
import 'dart:io';
import 'dart:async';

/// 日志级别枚举
enum LogLevel {
  trace,
  debug,
  info,
  warn,
  error,
  fatal,
  panic;

  @override
  String toString() {
    switch (this) {
      case LogLevel.trace:
        return 'TRACE';
      case LogLevel.debug:
        return 'DEBUG';
      case LogLevel.info:
        return 'INFO';
      case LogLevel.warn:
        return 'WARN';
      case LogLevel.error:
        return 'ERROR';
      case LogLevel.fatal:
        return 'FATAL';
      case LogLevel.panic:
        return 'PANIC';
    }
  }
}

/// 日志条目
class LogEntry {
  final DateTime timestamp;
  final LogLevel level;
  final String message;
  final String file;
  final int line;
  final String function;

  LogEntry({
    required this.timestamp,
    required this.level,
    required this.message,
    required this.file,
    required this.line,
    required this.function,
  });
}

/// 日志记录器
class Logger {
  final _mutex = Lock();
  LogLevel _level = LogLevel.debug;
  IOSink? _output;
  File? _file;
  String? _filePath;
  int _maxSize = 10 * 1024 * 1024; // 10MB
  int _currentSize = 0;
  bool _console = true;
  bool _color = true;

  Logger();

  /// 创建新日志记录器
  factory Logger.newLogger() {
    return Logger();
  }

  /// 设置日志级别
  void setLevel(LogLevel level) {
    _mutex.synchronized(() {
      _level = level;
    });
  }

  /// 通过字符串设置日志级别
  void setLevelString(String levelStr) {
    final level = _parseLevelString(levelStr);
    setLevel(level);
  }

  /// 设置输出文件
  Future<void> setOutputFile(String filePath) async {
    await _mutex.synchronized(() async {
      // 关闭现有文件
      if (_file != null) {
        await _output?.flush();
        await _output?.close();
        _output = null;
        _file = null;
      }

      // 创建目录
      final dir = Directory.fromUri(Uri.file(filePath).resolve('..'));
      if (!await dir.exists()) {
        await dir.create(recursive: true);
      }

      // 打开新文件
      final file = File(filePath);
      _output = file.openWrite(mode: FileMode.append);
      _file = file;
      _filePath = filePath;

      // 获取文件大小
      try {
        final stat = await file.stat();
        _currentSize = stat.size;
      } catch (e) {
        _currentSize = 0;
      }
    });
  }

  /// 设置是否输出到控制台
  void setConsole(bool enabled) {
    _mutex.synchronized(() {
      _console = enabled;
    });
  }

  /// 设置是否使用颜色
  void setColor(bool enabled) {
    _mutex.synchronized(() {
      _color = enabled;
    });
  }

  /// 设置最大文件大小
  void setMaxSize(int size) {
    _mutex.synchronized(() {
      _maxSize = size;
    });
  }

  /// 检查是否需要切割
  bool _shouldRotate() {
    return _file != null && _currentSize >= _maxSize;
  }

  /// 执行日志文件切割
  Future<void> _rotate() async {
    if (_filePath == null) return;

    // 关闭当前文件
    await _output?.flush();
    await _output?.close();
    _output = null;

    // 重命名当前文件
    final timestamp =
        DateTime.now().toString().replaceAll(RegExp(r'[^0-9]'), '');
    final backupPath = '$_filePath.$timestamp.bak';

    final file = File(_filePath!);
    if (await file.exists()) {
      await file.rename(backupPath);
    }

    // 创建新文件
    final newFile = File(_filePath!);
    _output = newFile.openWrite(mode: FileMode.append);
    _file = newFile;
    _currentSize = 0;
  }

  /// 获取调用者信息
  (String, String, int) _getCallerInfo(int skip) {
    try {
      final stackTrace = StackTrace.current;
      final lines = stackTrace.toString().split('\n');

      if (lines.length > skip) {
        final line = lines[skip].trim();
        // 解析格式如: #2   Logger._getCallerInfo (file:///path/to/file.dart:10:11)
        final regex = RegExp(r'#\d+\s+([^(]+)\(([^:]+):(\d+):\d+\)');
        final match = regex.firstMatch(line);

        if (match != null) {
          final function = match.group(1)?.trim() ?? 'unknown';
          final fullPath = match.group(2) ?? 'unknown';
          final fileName = fullPath.split('/').last;
          final lineNumber = int.tryParse(match.group(3) ?? '0') ?? 0;

          return (fileName, function, lineNumber);
        }
      }
    } catch (e) {
      // 如果解析失败，返回默认值
    }

    return ('???', '???', 0);
  }

  /// 解析日志级别字符串
  LogLevel _parseLevelString(String levelStr) {
    switch (levelStr.toLowerCase()) {
      case 'trace':
        return LogLevel.trace;
      case 'debug':
        return LogLevel.debug;
      case 'info':
        return LogLevel.info;
      case 'warn':
      case 'warning':
        return LogLevel.warn;
      case 'error':
        return LogLevel.error;
      case 'fatal':
        return LogLevel.fatal;
      case 'panic':
        return LogLevel.panic;
      default:
        throw ArgumentError('invalid log level: $levelStr');
    }
  }

  /// 获取级别对应的颜色代码
  int _getLevelColor(LogLevel level) {
    switch (level) {
      case LogLevel.trace:
      case LogLevel.debug:
        return 36; // cyan
      case LogLevel.info:
        return 32; // green
      case LogLevel.warn:
        return 33; // yellow
      case LogLevel.error:
      case LogLevel.fatal:
      case LogLevel.panic:
        return 31; // red
      default:
        return 37; // white
    }
  }

  /// 添加颜色
  String _colorize(String text, int colorCode) {
    return '\x1B[${colorCode}m$text\x1B[0m';
  }

  /// 记录日志
  void _log(LogLevel level, String format, List<Object?> args) {
    if (level.index < _level.index) {
      return;
    }

    _mutex.synchronized(() {
      // 检查文件切割
      if (_shouldRotate()) {
        _rotate().catchError((e) {
          stderr.writeln('日志切割失败: $e');
        });
      }

      // 获取调用信息
      final (file, function, line) = _getCallerInfo(3);

      // 格式化消息
      String message;
      if (args.isEmpty) {
        message = format;
      } else {
        // 简单的格式化，替换 %s, %d 等
        message = format;
        for (final arg in args) {
          message = message.replaceFirst('%s', arg?.toString() ?? 'null');
          message =
              message.replaceFirst('%d', (arg as num?)?.toString() ?? '0');
          message =
              message.replaceFirst('%f', (arg as num?)?.toString() ?? '0.0');
        }
      }

      // 创建日志条目
      final timestamp = DateTime.now();
      final timestampStr = '${timestamp.year.toString().padLeft(4, '0')}-'
          '${timestamp.month.toString().padLeft(2, '0')}-'
          '${timestamp.day.toString().padLeft(2, '0')} '
          '${timestamp.hour.toString().padLeft(2, '0')}:'
          '${timestamp.minute.toString().padLeft(2, '0')}:'
          '${timestamp.second.toString().padLeft(2, '0')}.'
          '${timestamp.millisecond.toString().padLeft(3, '0')}';

      final levelStr = level.toString();

      // 构建日志行
      final logLine =
          '[$timestampStr] [$levelStr] [$file:$function:$line] $message\n';

      // 输出到文件
      if (_output != null) {
        try {
          _output!.write(logLine);
          _currentSize += logLine.length;
        } catch (e) {
          stderr.writeln('写入日志文件失败: $e');
        }
      }

      // 输出到控制台（如果需要）
      if (_console) {
        if (_color) {
          final coloredLevel = _colorize(levelStr, _getLevelColor(level));
          final coloredLine =
              '[$timestampStr] [$coloredLevel] [$file:$function:$line] $message';
          print(coloredLine);
        } else {
          stdout.write(logLine);
        }
      }

      // 特殊级别处理
      if (level == LogLevel.fatal) {
        Future.microtask(() => exit(1));
      } else if (level == LogLevel.panic) {
        throw Exception(message);
      }
    });
  }

  /// 跟踪级别日志
  void trace(String format,
      [Object? arg1, Object? arg2, Object? arg3, Object? arg4, Object? arg5]) {
    _log(LogLevel.trace, format,
        [arg1, arg2, arg3, arg4, arg5].where((e) => e != null).toList());
  }

  /// 调试级别日志
  void debug(String format,
      [Object? arg1, Object? arg2, Object? arg3, Object? arg4, Object? arg5]) {
    _log(LogLevel.debug, format,
        [arg1, arg2, arg3, arg4, arg5].where((e) => e != null).toList());
  }

  /// 信息级别日志
  void info(String format,
      [Object? arg1, Object? arg2, Object? arg3, Object? arg4, Object? arg5]) {
    _log(LogLevel.info, format,
        [arg1, arg2, arg3, arg4, arg5].where((e) => e != null).toList());
  }

  /// 警告级别日志
  void warn(String format,
      [Object? arg1, Object? arg2, Object? arg3, Object? arg4, Object? arg5]) {
    _log(LogLevel.warn, format,
        [arg1, arg2, arg3, arg4, arg5].where((e) => e != null).toList());
  }

  /// 错误级别日志
  void error(String format,
      [Object? arg1, Object? arg2, Object? arg3, Object? arg4, Object? arg5]) {
    _log(LogLevel.error, format,
        [arg1, arg2, arg3, arg4, arg5].where((e) => e != null).toList());
  }

  /// 致命级别日志
  void fatal(String format,
      [Object? arg1, Object? arg2, Object? arg3, Object? arg4, Object? arg5]) {
    _log(LogLevel.fatal, format,
        [arg1, arg2, arg3, arg4, arg5].where((e) => e != null).toList());
  }

  /// 恐慌级别日志
  void panic(String format,
      [Object? arg1, Object? arg2, Object? arg3, Object? arg4, Object? arg5]) {
    _log(LogLevel.panic, format,
        [arg1, arg2, arg3, arg4, arg5].where((e) => e != null).toList());
  }

  /// 刷新缓冲区
  Future<void> flush() async {
    await _mutex.synchronized(() async {
      if (_output != null) {
        await _output!.flush();
      }
    });
  }

  /// 关闭日志器
  Future<void> close() async {
    await _mutex.synchronized(() async {
      if (_output != null) {
        await _output!.flush();
        await _output!.close();
        _output = null;
        _file = null;
      }
    });
  }
}

/// 用于模拟 Go 中的 sync.Mutex
class Lock {
  bool _locked = false;
  final List<Completer<void>> _waiting = [];

  Future<void> synchronized(FutureOr<void> Function() func) async {
    // 等待锁
    while (_locked) {
      final completer = Completer<void>();
      _waiting.add(completer);
      await completer.future;
    }

    _locked = true;

    try {
      final result = func();
      if (result is Future) {
        await result;
      }
    } finally {
      _locked = false;

      // 唤醒一个等待的协程
      if (_waiting.isNotEmpty) {
        final completer = _waiting.removeAt(0);
        completer.complete();
      }
    }
  }

  void synchronizedVoid(void Function() func) {
    // 简单同步版本，适用于不需要异步的操作
    while (_locked) {
      // 忙等待 - 在实际使用中应避免，这里只是为了模拟
      Future.delayed(Duration(microseconds: 1));
    }

    _locked = true;
    try {
      func();
    } finally {
      _locked = false;
    }
  }
}
