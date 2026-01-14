import 'dart:io';

/// 文件检查工具类，用于跟踪和管理特定日期的记录
///
/// 功能：
/// 1. 检查指定日期在文件中的出现次数
/// 2. 在次数未达到限制时追加新记录
/// 3. 支持未来日期的计算和检查
class CheckFile {
  final String filePath;
  final int addNum;
  final int allTimes;

  /// 创建 CheckFile 实例
  ///
  /// [filePath]: 存储日期的文件路径
  /// [addNum]: 相对于当前日期的偏移天数（正数为未来，负数为过去）
  /// [allTimes]: 允许的最大次数限制
  CheckFile({
    required this.filePath,
    required this.addNum,
    required this.allTimes,
  });

  // ========== 异步版本 ==========

  /// 异步检查是否达到最大次数限制
  ///
  /// 返回 `true` 表示可以继续（未达到限制）
  /// 返回 `false` 表示已达到限制
  Future<bool> checkTimes() async {
    return await _check(allTimes);
  }

  /// 异步检查指定次数限制
  Future<bool> _check(int num) async {
    try {
      // 确保文件存在
      await _ensureFileExistsAsync();

      // 读取文件内容
      final content = await _readFileAsync();

      // 解析日期列表
      final dates = _split(content);

      // 获取目标日期
      final targetDate = _getTargetDate();

      // 统计出现次数
      final count = _countOccurrences(dates, targetDate);

      // 检查是否达到限制
      if (count >= num) {
        return false;
      }

      // 追加新日期记录
      await _appendDateAsync(targetDate);

      return true;
    } catch (e) {
      // 发生任何错误都返回 false，避免意外继续
      print('CheckFile 异步检查失败: $e');
      return false;
    }
  }

  /// 异步确保文件存在
  Future<void> _ensureFileExistsAsync() async {
    final file = File(filePath);
    if (!await file.exists()) {
      await file.create(recursive: true);
    }
  }

  /// 异步读取文件内容
  Future<String> _readFileAsync() async {
    final file = File(filePath);

    try {
      return await file.readAsString();
    } on FileSystemException {
      return '';
    }
  }

  /// 异步追加日期到文件
  Future<void> _appendDateAsync(int date) async {
    final file = File(filePath);
    final exists = await file.exists();

    await file.writeAsString(
      exists ? '&$date' : '$date',
      mode: FileMode.append,
      flush: true,
    );
  }

  // ========== 同步版本 ==========

  /// 同步检查是否达到最大次数限制
  ///
  /// 返回 `true` 表示可以继续（未达到限制）
  /// 返回 `false` 表示已达到限制
  bool checkTimesSync() {
    return _checkSync(allTimes);
  }

  /// 同步检查指定次数限制
  bool _checkSync(int num) {
    try {
      // 确保文件存在
      _ensureFileExistsSync();

      // 读取文件内容
      final content = _readFileSync();

      // 解析日期列表
      final dates = _split(content);

      // 获取目标日期
      final targetDate = _getTargetDate();

      // 统计出现次数
      final count = _countOccurrences(dates, targetDate);

      // 检查是否达到限制
      if (count >= num) {
        return false;
      }

      // 追加新日期记录
      _appendDateSync(targetDate);

      return true;
    } catch (e) {
      // 发生任何错误都返回 false
      print('CheckFile 同步检查失败: $e');
      return false;
    }
  }

  /// 同步确保文件存在
  void _ensureFileExistsSync() {
    final file = File(filePath);
    if (!file.existsSync()) {
      file.createSync(recursive: true);
    }
  }

  /// 同步读取文件内容
  String _readFileSync() {
    final file = File(filePath);

    try {
      return file.readAsStringSync();
    } on FileSystemException {
      return '';
    }
  }

  /// 同步追加日期到文件
  void _appendDateSync(int date) {
    final file = File(filePath);
    final exists = file.existsSync();

    final sink = file.openSync(mode: FileMode.append);
    try {
      final content = exists ? '&$date' : '$date';
      sink.writeStringSync(content);
    } finally {
      sink.closeSync();
    }
  }

  // ========== 共用方法 ==========

  /// 分割字符串为日期整数列表
  ///
  /// 格式：`&20240101&20240102&20240103`
  List<int> _split(String content) {
    if (content.isEmpty) {
      return [];
    }

    final parts = content.split('&');
    final result = <int>[];

    for (final part in parts) {
      if (part.isNotEmpty) {
        final parsedValue = int.tryParse(part);
        if (parsedValue != null) {
          result.add(parsedValue);
        }
      }
    }

    return result;
  }

  /// 获取目标日期（YYYYMMDD 格式）
  int _getTargetDate() {
    final now = DateTime.now();
    final targetDate = now.add(Duration(days: addNum));

    final year = targetDate.year;
    final month = targetDate.month;
    final day = targetDate.day;

    return year * 10000 + month * 100 + day;
  }

  /// 统计目标日期在列表中的出现次数
  int _countOccurrences(List<int> dates, int targetDate) {
    return dates.where((date) => date == targetDate).length;
  }

  // ========== 工具方法 ==========

  /// 清空文件内容（主要用于测试）
  Future<void> clearFile() async {
    final file = File(filePath);
    if (await file.exists()) {
      await file.writeAsString('');
    }
  }

  /// 同步清空文件内容
  void clearFileSync() {
    final file = File(filePath);
    if (file.existsSync()) {
      file.writeAsStringSync('');
    }
  }

  /// 读取文件中的所有日期
  Future<List<int>> readAllDates() async {
    final content = await _readFileAsync();
    return _split(content);
  }

  /// 同步读取文件中的所有日期
  List<int> readAllDatesSync() {
    final content = _readFileSync();
    return _split(content);
  }

  /// 获取今天的日期（YYYYMMDD 格式）
  static int getTodayDate() {
    final now = DateTime.now();
    return now.year * 10000 + now.month * 100 + now.day;
  }

  /// 格式化日期为 YYYYMMDD
  static int formatDate(DateTime date) {
    return date.year * 10000 + date.month * 100 + date.day;
  }
}
