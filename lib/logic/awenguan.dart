import 'dart:io';

/// 古代文官配置类
class AncientWenGuanConfig {
  final String file;
  final int addNum;

  AncientWenGuanConfig({
    required this.file,
    required this.addNum,
  }) {
    create();
  }

  /// 创建文件（如果需要）
  void create() {
    try {
      File(file).openSync(mode: FileMode.writeOnlyAppend);
    } catch (e) {
      // 忽略创建文件的错误
    }
  }

  /// 读取等级
  int readLevel() {
    try {
      if (!File(file).existsSync()) {
        // 文件不存在，创建并写入默认值
        File(file).createSync();
        final content = (addNum + 9).toString();
        File(file).writeAsStringSync(content);
        return 9;
      }

      // 读取文件内容
      final content = File(file).readAsStringSync().trim();
      final readInt = int.tryParse(content);

      if (readInt == null) {
        return 9;
      }

      // 计算等级
      final level = readInt - addNum;
      if (level < 1 || level > 9) {
        return 9;
      }

      return level;
    } catch (e) {
      return 9;
    }
  }

  /// 设置新等级
  void setNewLevel(int newLevel) {
    try {
      final content = (addNum + newLevel).toString();
      File(file).writeAsStringSync(content);
    } catch (e) {
      // 忽略写入文件的错误
    }
  }

  /// 等级提升
  void levelUp() {
    final currentLevel = readLevel();
    if (currentLevel <= 1 || currentLevel > 9) {
      throw Exception('无效的当前等级: $currentLevel');
    }

    final newLevel = currentLevel - 1;
    setNewLevel(newLevel);
  }

  /// 等级降低
  void levelDown() {
    final currentLevel = readLevel();
    if (currentLevel < 1 || currentLevel >= 9) {
      throw Exception('无效的当前等级: $currentLevel');
    }

    final newLevel = currentLevel + 1;
    setNewLevel(newLevel);
  }

  /// 获取俸禄
  int getFengLu() {
    final level = readLevel();
    if (level >= 6) {
      return (10 - level) * 5;
    }
    return (10 - level) * 6;
  }
}
