// file: util/once_file.dart
import 'dart:io';
import 'dart:convert';

/// 一次性文件工具类
/// 用于标记某个操作是否已经执行过
class OnceFile {
  final File _file;
  final String? _content;

  /// 创建 OnceFile 实例
  /// [filePath]: 标记文件的路径
  /// [content]: 可选，写入文件的内容（默认是时间戳）
  OnceFile(String filePath, {String? content})
      : _file = File(filePath),
        _content = content ?? DateTime.now().toIso8601String();

  /// 检查是否可以执行（文件不存在时返回true）
  bool get canExecute => !_file.existsSync();

  /// 获取已执行的时间（文件存在时返回创建时间）
  DateTime? get executionTime {
    if (_file.existsSync()) {
      try {
        final stat = _file.statSync();
        return stat.modified;
      } catch (e) {
        return null;
      }
    }
    return null;
  }

  /// 读取文件内容
  String? readContent() {
    try {
      if (_file.existsSync()) {
        return _file.readAsStringSync();
      }
    } catch (e) {
      return null;
    }
    return null;
  }

  /// 使用标记（如果文件不存在则创建，已存在则更新访问时间）
  /// 返回是否成功创建了新的标记
  bool use() {
    try {
      if (!_file.existsSync()) {
        // 确保目录存在
        _file.parent.createSync(recursive: true);
        // 写入内容
        _file.writeAsStringSync(_content!);
        return true;
      }

      // 文件已存在，更新访问时间
      _file.setLastModifiedSync(DateTime.now());
      return false;
    } catch (e) {
      return false;
    }
  }

  /// 强制更新标记（无论文件是否存在都写入）
  void forceUpdate({String? newContent}) {
    try {
      _file.parent.createSync(recursive: true);
      final content = newContent ?? _content;
      _file.writeAsStringSync(content!);
    } catch (e) {
      throw Exception('Failed to update once file: $e');
    }
  }

  /// 清除标记（删除文件）
  bool clear() {
    try {
      if (_file.existsSync()) {
        _file.deleteSync();
        return true;
      }
      return false;
    } catch (e) {
      return false;
    }
  }

  /// 检查自上次执行以来是否已过指定天数
  bool isOlderThanDays(int days) {
    final time = executionTime;
    if (time == null) return true;

    final now = DateTime.now();
    final difference = now.difference(time);
    return difference.inDays >= days;
  }

  /// 异步版本的使用方法
  Future<bool> useAsync() async {
    try {
      final exists = await _file.exists();
      if (!exists) {
        await _file.parent.create(recursive: true);
        await _file.writeAsString(_content!);
        return true;
      }
      await _file.setLastModified(DateTime.now());
      return false;
    } catch (e) {
      return false;
    }
  }

  /// 异步读取内容
  Future<String?> readContentAsync() async {
    try {
      final exists = await _file.exists();
      if (exists) {
        return await _file.readAsString();
      }
    } catch (e) {
      return null;
    }
    return null;
  }

  /// 批量操作：一次性检查多个标记文件
  static Map<String, bool> checkMultiple(List<String> filePaths) {
    final results = <String, bool>{};
    for (final path in filePaths) {
      final onceFile = OnceFile(path);
      results[path] = onceFile.canExecute;
    }
    return results;
  }

  /// 批量标记：一次性创建多个标记文件
  static Map<String, bool> markMultiple(List<String> filePaths) {
    final results = <String, bool>{};
    for (final path in filePaths) {
      final onceFile = OnceFile(path);
      results[path] = onceFile.use();
    }
    return results;
  }
}

/// 带JSON支持的高级一次性文件
class JsonOnceFile<T> extends OnceFile {
  JsonOnceFile({
    required String filePath,
    T? initialData,
  }) : super(
          filePath,
          content: initialData != null
              ? jsonEncode(initialData)
              : jsonEncode({
                  'timestamp': DateTime.now().toIso8601String(),
                  'data': null,
                }),
        );

  /// 读取并解析JSON数据
  T? readJsonData() {
    final content = readContent();
    if (content != null) {
      try {
        return jsonDecode(content) as T;
      } catch (e) {
        return null;
      }
    }
    return null;
  }

  /// 使用JSON数据创建标记
  bool useWithData(T data) {
    try {
      final jsonData = jsonEncode({
        'timestamp': DateTime.now().toIso8601String(),
        'data': data,
      });

      if (!_file.existsSync()) {
        _file.parent.createSync(recursive: true);
        _file.writeAsStringSync(jsonData);
        return true;
      }
      return false;
    } catch (e) {
      return false;
    }
  }

  /// 异步读取JSON数据
  Future<T?> readJsonDataAsync() async {
    final content = await readContentAsync();
    if (content != null) {
      try {
        return jsonDecode(content) as T;
      } catch (e) {
        return null;
      }
    }
    return null;
  }
}
