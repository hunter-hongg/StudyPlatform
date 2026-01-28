import 'dart:io';
import 'dart:async';

/// 管理状态文件的工具类，文件内容为 "True" 或 "False"
class StateFile {
  final String _filePath;

  /// 创建状态文件管理器
  StateFile(String filePath) : _filePath = filePath;

  /// 切换状态并写入文件
  Future<void> setState(bool state) async {
    try {
      final file = File(_filePath);
      await file.writeAsString(state ? 'True' : 'False');
    } on IOException catch (e) {
      throw StateException('Failed to write state file: $_filePath', e);
    }
  }

  /// 读取当前状态，如果读取失败则返回默认值
  Future<bool> readState(bool defaultValue) async {
    try {
      final contentraw = await _readContent();
      final content = contentraw.trim();
      if ((content != 'True') && (content != 'False')) {
        return defaultValue;
      }
      return content.trim() == 'True';
    } on IOException {
      return defaultValue;
    }
  }

  /// 同步读取当前状态，如果读取失败则返回默认值
  bool readStateSync(bool defaultValue) {
    try {
      final content = _readContentSync().trim();
      if ((content != 'True') && (content != 'False')) {
        return defaultValue;
      }
      return content.trim() == 'True';
    } on IOException {
      return defaultValue;
    }
  }

  /// 读取文件内容，如果文件不存在则返回空字符串
  Future<String> _readContent() async {
    final file = File(_filePath);

    if (!await file.exists()) {
      return '';
    }

    return await file.readAsString();
  }

  /// 同步读取文件内容，如果文件不存在则返回空字符串
  String _readContentSync() {
    final file = File(_filePath);

    if (!file.existsSync()) {
      return '';
    }

    return file.readAsStringSync();
  }
}

/// 状态操作异常
class StateException implements Exception {
  final String message;
  final Exception? cause;

  StateException(this.message, [this.cause]);

  @override
  String toString() => cause == null
      ? 'StateException: $message'
      : 'StateException: $message\nCaused by: $cause';
}
