import 'dart:io';

enum SwordEnum {
  gold,
  wood,
  water,
  fire,
  soil;

  @override
  String toString() {
    switch (this) {
      case SwordEnum.gold:
        return "金剑";
      case SwordEnum.wood:
        return "木剑";
      case SwordEnum.water:
        return "水剑";
      case SwordEnum.fire:
        return "火剑";
      case SwordEnum.soil:
        return "土剑";
    }
  }

  static SwordEnum fromInt(int value) {
    if (value < 0 || value > 4) {
      return SwordEnum.gold;
    }
    return SwordEnum.values[value];
  }
}

String swordToString(SwordEnum enumA) {
  return enumA.toString();
}

class SwordException implements Exception {
  final String msg;

  SwordException(this.msg);

  @override
  String toString() => msg;
}

SwordException newSwordException(String err) {
  return SwordException(err);
}

class SwordInFile {
  final String file;

  SwordInFile(this.file) {
    _ensureFileExists();
  }

  factory SwordInFile.create(String file1) {
    return SwordInFile(file1);
  }

  void _ensureFileExists() {
    File f = File(file);
    if (!f.existsSync()) {
      try {
        f.createSync();
      } catch (e) {
        // 忽略创建文件时的错误
      }
    }
  }

  SwordEnum get() {
    try {
      File f = File(file);
      if (!f.existsSync()) {
        return SwordEnum.gold;
      }

      String data = f.readAsStringSync();
      String content = data.trim();
      if (content.isEmpty) {
        return SwordEnum.gold;
      }

      int value = int.tryParse(content) ?? -1;
      if (value < 0 || value > 4) {
        return SwordEnum.gold;
      }

      return SwordEnum.fromInt(value);
    } catch (e) {
      return SwordEnum.gold;
    }
  }

  Future<void> set(SwordEnum thing) async {
    try {
      File f = File(file);
      await f.writeAsString(thing.index.toString());
    } catch (e) {
      throw newSwordException("写入文件失败: $e");
    }
  }
}