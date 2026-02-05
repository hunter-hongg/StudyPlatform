import 'dart:io';

import 'package:study_platform/tool/fileinter.dart';

/// AddFile 类用于处理文件中的数字值，支持增加、减少和比较操作
class AddFile implements AddAble, MinusAble {
  final String file;
  final int addnum;

  /// 构造函数，创建一个新的 AddFile 实例
  AddFile(this.file, this.addnum);

  /// 创建一个新的 AddFile 实例（工厂构造函数）
  factory AddFile.create(String filename, int addnum) {
    return AddFile(filename, addnum);
  }

  /// 读取文件内容并返回字符串
  String? _readFile() {
    try {
      File f = File(file);
      if (!f.existsSync()) {
        return null;
      }
      return f.readAsStringSync();
    } catch (e) {
      return null;
    }
  }

  /// 读取文件内容并返回整数值
  int readInt() {
    String? raw = _readFile();
    if (raw == null) {
      return 0;
    }
    
    try {
      int res = int.parse(raw.trim());
      return res - addnum;
    } catch (e) {
      return 0;
    }
  }

  /// 将文件中的整数值转换为字符串形式
  String readStr() {
    return readInt().toString();
  }

  /// 将指定字符串写入文件
  Future<void> write(String written) async {
    File f = File(file);
    await f.writeAsString(written);
  }

  /// 在文件中的数值基础上加上指定的值
  Future<void> addNum(int an) async {
    int res = readInt() + an + addnum;
    String rest = res.toString();
    await write(rest);
  }

  /// 尝试从文件中的数值减去指定的值
  /// 如果文件中的数值小于要减去的值，则返回false
  bool canMinus(int an) {
    int ri = readInt();
    if (ri < an) {
      return false;
    }
    int ann = -an;
    addNum(ann); // 这里应该是异步的，但为了保持API一致性，我们使用同步版本
    return true;
  }

  /// 检查文件中的数值是否大于等于指定值
  bool high(int an) {
    int ri = readInt();
    return ri >= an;
  }

  /// 异步版本的canMinus方法
  Future<bool> canMinusAsync(int an) async {
    int ri = readInt();
    if (ri < an) {
      return false;
    }
    int ann = -an;
    await addNum(ann);
    return true;
  }

  /// 安全版本的canMinus方法（异步）
  Future<bool> canMinusSafe(int an) async {
    return await canMinusAsync(an);
  }

  /// 安全版本的readInt方法
  int readIntSafe() {
    return readInt();
  }

  /// 安全版本的readStr方法
  String readStrSafe() {
    return readStr();
  }
  
  /// 同步版本的addNum方法
  @override
  void addNumSync(int an) {
    int res = readInt() + an + addnum;
    File(file).writeAsStringSync(res.toString());
  }
  
  /// 同步版本的canMinus方法
  @override
  bool canMinusSync(int an) {
    int ri = readInt();
    if (ri < an) {
      return false;
    }
    int ann = -an;
    addNumSync(ann);
    return true;
  }
}