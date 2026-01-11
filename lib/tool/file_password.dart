import 'dart:io';
// import 'dart:convert';

const String original = "0123456789";

class FilePassword {
  final String fileName;
  final String password;

  FilePassword._(this.fileName, this.password);

  /// 创建FilePassword实例，检查密码是否包含重复字符
  factory FilePassword(String filename, String password) {
    return FilePassword._(filename, _validatePassword(password));
  }

  /// 创建FilePassword实例，如果文件不存在则写入默认值
  factory FilePassword.withDefault(
    String filename,
    String password,
    int defaultValue,
  ) {
    // 先检查文件是否存在，避免触发不必要的文件创建
    final file = File(filename);
    final fileExists = file.existsSync();

    // 创建实例
    final fp = FilePassword._(filename, _validatePassword(password));

    // 如果文件不存在，写入默认值
    if (!fileExists) {
      fp.writeSync(defaultValue);
    }

    return fp;
  }

  /// 验证密码是否包含重复字符
  static String _validatePassword(String password) {
    final charSet = <String>{};
    for (var i = 0; i < password.length; i++) {
      final char = password[i];
      if (charSet.contains(char)) {
        return "1324096857"; // 使用默认密码
      }
      charSet.add(char);
    }
    return password;
  }

  /// 字符转换辅助函数
  static int _translateChar(String char, String from, String to) {
    final index = from.indexOf(char);
    if (index == -1) {
      throw FormatException('Character "$char" not found in mapping table');
    }
    return to.codeUnitAt(index);
  }

  /// 读取文件中的密码
  Future<String> readPassword() async {
    final file = File(fileName);

    // 检查文件是否存在，不存在则创建
    if (!await file.exists()) {
      try {
        await file.create(recursive: true);
        // 写入密码的第一个字符
        await file.writeAsString(password[0]);
      } catch (e) {
        throw IOException('Failed to create file: $fileName, error: $e');
      }
    }

    // 读取文件内容
    try {
      final content = await file.readAsString();
      return content.trim();
    } catch (e) {
      throw IOException('Failed to open file: $fileName, error: $e');
    }
  }

  /// 读取文件中的密码（同步版本）
  String readPasswordSync() {
    final file = File(fileName);

    if (!file.existsSync()) {
      try {
        file.createSync(recursive: true);
        file.writeAsStringSync(password[0]);
      } catch (e) {
        throw IOException('Failed to create file: $fileName, error: $e');
      }
    }

    try {
      final content = file.readAsStringSync();
      return content.trim();
    } catch (e) {
      throw IOException('Failed to open file: $fileName, error: $e');
    }
  }

  /// 将文件中的加密密码转换为真实数字
  Future<String> readReal() async {
    final encrypted = await readPassword();
    return _decryptString(encrypted);
  }

  /// 将文件中的加密密码转换为真实数字（同步版本）
  String readRealSync() {
    final encrypted = readPasswordSync();
    return _decryptString(encrypted);
  }

  /// 解密字符串
  String _decryptString(String encrypted) {
    final result = StringBuffer();
    for (var i = 0; i < encrypted.length; i++) {
      final char = encrypted[i];
      final translated = _translateChar(char, password, original);
      result.writeCharCode(translated);
    }
    return result.toString();
  }

  /// 加密字符串
  String _encryptString(String input) {
    final result = StringBuffer();
    for (var i = 0; i < input.length; i++) {
      final char = input[i];
      final translated = _translateChar(char, original, password);
      result.writeCharCode(translated);
    }
    return result.toString();
  }

  /// 将数字加密后写入文件
  Future<void> write(int newNum) async {
    final numStr = newNum.toString();
    final result = _encryptString(numStr);

    try {
      final file = File(fileName);
      await file.create(recursive: true);
      await file.writeAsString(result);
      // print(file.readAsStringSync());
    } catch (e) {
      throw IOException('Failed to write to file: $fileName, error: $e');
    }
  }

  /// 将数字加密后写入文件（同步版本）
  void writeSync(int newNum) {
    final numStr = newNum.toString();
    final result = _encryptString(numStr);

    try {
      final file = File(fileName);
      file.createSync(recursive: true);
      file.writeAsStringSync(result);
    } catch (e) {
      throw IOException('Failed to write to file: $fileName, error: $e');
    }
  }

  /// 读取文件中的数字，加上指定值后再加密写入文件
  Future<void> add(int num) async {
    final realStr = await readReal();
    final currentNum = int.tryParse(realStr);

    if (currentNum == null) {
      throw FormatException('Invalid number in file: $realStr');
    }

    final newNum = currentNum + num;
    await write(newNum);
  }

  /// 读取文件中的数字，加上指定值后再加密写入文件（同步版本）
  void addSync(int num) {
    final realStr = readRealSync();
    final currentNum = int.tryParse(realStr);

    if (currentNum == null) {
      throw FormatException('Invalid number in file: $realStr');
    }

    final newNum = currentNum + num;
    writeSync(newNum);
  }

  /// 读取存储数字返回string
  Future<String> readStr() async {
    final realStr = await readReal();
    final num = int.tryParse(realStr);

    if (num == null) {
      throw FormatException('Invalid number format: $realStr');
    }

    return num.toString();
  }

  /// 读取存储数字返回string（同步版本）
  String readStrSync() {
    final realStr = readRealSync();
    final num = int.tryParse(realStr);

    if (num == null) {
      throw FormatException('Invalid number format: $realStr');
    }

    return num.toString();
  }

  /// 读取存储数字返回int
  Future<int> readInt() async {
    final realStr = await readReal();
    final num = int.tryParse(realStr);

    if (num == null) {
      throw FormatException('Invalid number format: $realStr');
    }

    return num;
  }

  /// 读取存储数字返回int（同步版本）
  int readIntSync() {
    final realStr = readRealSync();
    final num = int.tryParse(realStr);

    if (num == null) {
      throw FormatException('Invalid number format: $realStr');
    }

    return num;
  }

  /// 增加存储数字（只处理非负数）
  Future<void> addNum(int a) async {
    if (a < 0) return;
    await add(a);
  }

  /// 增加存储数字（只处理非负数，同步版本）
  void addNumSync(int a) {
    if (a < 0) return;
    addSync(a);
  }

  /// 减小存储数字，不检查是否为负数
  Future<void> minusNum(int a) async {
    if (a < 0) return;
    await add(-a);
  }

  /// 减小存储数字，不检查是否为负数（同步版本）
  void minusNumSync(int a) {
    if (a < 0) return;
    addSync(-a);
  }

  /// 减小存储数字，若不足则减至0
  Future<void> minusNumIf(int a) async {
    if (a < 0) return;

    final current = await readInt();
    if (current >= a) {
      await minusNum(a);
    } else {
      await minusNum(current);
    }
  }

  /// 减小存储数字，若不足则减至0（同步版本）
  void minusNumIfSync(int a) {
    if (a < 0) return;

    final current = readIntSync();
    if (current >= a) {
      minusNumSync(a);
    } else {
      minusNumSync(current);
    }
  }

  /// 判断是否大于等于指定数字
  Future<bool> high(int a) async {
    final current = await readInt();
    return current >= a;
  }

  /// 判断是否大于等于指定数字（同步版本）
  bool highSync(int a) {
    final current = readIntSync();
    return current >= a;
  }

  /// 判断是否大于等于指定数字，若满足则减去，不满足则不变
  Future<bool> canMinus(int a) async {
    if (a < 0) return false;

    final isHigh = await high(a);
    if (isHigh) {
      await minusNum(a);
      return true;
    }
    return false;
  }

  /// 判断是否大于等于指定数字，若满足则减去，不满足则不变（同步版本）
  bool canMinusSync(int a) {
    if (a < 0) return false;

    final isHigh = highSync(a);
    if (isHigh) {
      minusNumSync(a);
      return true;
    }
    return false;
  }

  /// 安全的读取字符串（不抛出异常）
  Future<String> readStrSafe() async {
    try {
      return await readStr();
    } catch (_) {
      return "0";
    }
  }

  /// 安全的读取字符串（不抛出异常，同步版本）
  String readStrSafeSync() {
    try {
      return readStrSync();
    } catch (_) {
      return "0";
    }
  }

  /// 安全的读取整数（不抛出异常）
  Future<int> readIntSafe() async {
    try {
      return await readInt();
    } catch (_) {
      return 0;
    }
  }

  /// 安全的读取整数（不抛出异常，同步版本）
  int readIntSafeSync() {
    try {
      return readIntSync();
    } catch (_) {
      return 0;
    }
  }

  /// 安全的canMinus（不抛出异常）
  Future<bool> canMinusSafe(int an) async {
    try {
      return await canMinus(an);
    } catch (_) {
      return false;
    }
  }

  /// 安全的canMinus（不抛出异常，同步版本）
  bool canMinusSafeSync(int an) {
    try {
      return canMinusSync(an);
    } catch (_) {
      return false;
    }
  }
}

/// 自定义IO异常类
class IOException implements Exception {
  final String message;
  IOException(this.message);

  @override
  String toString() => 'IOException: $message';
}
