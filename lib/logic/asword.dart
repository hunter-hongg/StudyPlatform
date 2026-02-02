import 'dart:io';

enum Sword {
  green,
  red,
  purple,
  black,
  white,
  realRed,
  blue;

  @override
  String toString() {
    switch (this) {
      case Sword.green:
        return "青剑";
      case Sword.red:
        return "赤剑";
      case Sword.purple:
        return "紫剑";
      case Sword.black:
        return "黑剑";
      case Sword.white:
        return "白剑";
      case Sword.realRed:
        return "红剑";
      case Sword.blue:
        return "蓝剑";
    }
  }
}

class AncientSword {
  final String swordNow;
  final String swordAll;

  AncientSword(this.swordNow, this.swordAll);

  /// 获取当前剑
  Sword getNow() {
    return readNow();
  }

  /// 获取所有剑
  List<Sword> getAll() {
    return readAll();
  }

  /// 读取当前剑
  Sword readNow() {
    // 确保文件存在
    try {
      File(swordNow).openWrite(mode: FileMode.append);
    } catch (e) {
      // 如果无法打开文件，返回默认值
    }

    File file;
    try {
      file = File(swordNow);
      if (!file.existsSync()) {
        file.createSync(recursive: true);
      }
    } catch (e) {
      return Sword.green;
    }

    try {
      String content = file.readAsStringSync();
      if (content.isEmpty) {
        return Sword.green;
      }
      
      int value = int.tryParse(content.trim()) ?? -1;
      if (value >= 0 && value <= Sword.values.length - 1) {
        return Sword.values[value];
      } else {
        return Sword.green;
      }
    } catch (e) {
      return Sword.green;
    }
  }

  /// 读取所有剑
  List<Sword> readAll() {
    // 确保文件存在
    try {
      File(swordAll).openWrite(mode: FileMode.append);
    } catch (e) {
      // 如果无法打开文件，返回默认值
    }

    File file;
    try {
      file = File(swordAll);
      if (!file.existsSync()) {
        file.createSync(recursive: true);
      }
    } catch (e) {
      return [Sword.green];
    }

    try {
      String content = file.readAsStringSync();
      if (content.isEmpty) {
        return [Sword.green];
      }

      List<String> allSwords = content.split(',');
      List<Sword> result = <Sword>[];

      for (String item in allSwords) {
        if (item.isEmpty) continue;
        
        int? value = int.tryParse(item.trim());
        if (value != null && value >= 0 && value <= Sword.values.length - 1) {
          result.add(Sword.values[value]);
        } else {
          // 如果解析失败，默认添加green
          result.add(Sword.green);
        }
      }

      // 去除重复项
      Set<Sword> uniqueSwords = result.toSet();
      return uniqueSwords.toList();
    } catch (e) {
      return [Sword.green];
    }
  }

  /// 更改当前剑
  int change(Sword newSword) {
    List<Sword> swords = readAll();
    bool found = false;

    for (Sword sword in swords) {
      if (sword == newSword) {
        found = true;
        break;
      }
    }

    if (!found) {
      return 1; // 表示失败
    }

    File file;
    try {
      file = File(swordNow);
      file.writeAsStringSync(newSword.index.toString());
    } catch (e) {
      return 1; // 表示失败
    }

    return 0; // 表示成功
  }

  /// 添加新剑
  void add(Sword addSword) {
    File file;
    try {
      file = File(swordAll);
      if (!file.existsSync()) {
        file.createSync(recursive: true);
      }
      
      // 先读取现有内容
      String existingContent = file.readAsStringSync();
      String separator = existingContent.isEmpty ? '' : ',';
      file.writeAsStringSync('$existingContent$separator${addSword.index}');
    } catch (e) {
      // 如果出错不做任何操作
    }
  }
}