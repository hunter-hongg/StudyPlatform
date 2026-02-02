import 'dart:io';

/// 表示袍子类型的枚举
enum Pao {
  green(0, '青袍'),
  red(1, '赤袍'),
  purple(2, '紫袍'),
  black(3, '黑袍'),
  white(4, '白袍'),
  realRed(5, '红袍'),
  blue(6, '蓝袍'),
  silver(7, '银袍');

  const Pao(this.value, this.displayName);
  final int value;
  final String displayName;

  @override
  String toString() => displayName;
}

/// 管理古代袍子状态的类
class AncientPao {
  final String _paonow; // 当前袍子状态文件
  final String _paoall; // 所有袍子解锁记录文件

  AncientPao(this._paonow, this._paoall);

  /// 获取当前袍子类型
  Pao getNow() {
    return readNow();
  }

  /// 获取所有已解锁的袍子类型
  List<Pao> getAll() {
    return readAll();
  }

  /// 读取当前袍子状态
  Pao readNow() {
    // 确保文件存在
    final file = File(_paonow);
    try {
      file.openWrite(mode: FileMode.append).close(); // 创建文件如果不存在
    } catch (e) {
      return Pao.green; // 如果无法创建文件，返回默认值
    }

    try {
      final content = file.readAsStringSync().trim();
      if (content.isEmpty) {
        return Pao.green;
      }

      final value = int.tryParse(content);
      if (value == null || value < 0 || value > Pao.values.length - 1) {
        return Pao.green;
      }

      return Pao.values.firstWhere(
        (p) => p.value == value,
        orElse: () => Pao.green,
      );
    } catch (e) {
      return Pao.green;
    }
  }

  /// 读取所有已解锁的袍子
  List<Pao> readAll() {
    // 确保文件存在
    final file = File(_paoall);
    try {
      file.openWrite(mode: FileMode.append).close(); // 创建文件如果不存在
    } catch (e) {
      return [Pao.green]; // 如果无法创建文件，返回默认值
    }

    try {
      final content = file.readAsStringSync();
      if (content.isEmpty) {
        return [Pao.green];
      }

      final allString = content.split(',');
      final result = <Pao>[];

      for (final item in allString) {
        if (item.trim().isEmpty) continue;

        final value = int.tryParse(item.trim());
        if (value == null || value < 0 || value > Pao.values.length - 1) {
          // 如果解析失败，使用默认值0 (green)
          result.add(Pao.green);
        } else {
          // 将数值转换为对应的Pao枚举
          final pao = Pao.values.firstWhere(
            (p) => p.value == value,
            orElse: () => Pao.green,
          );
          result.add(pao);
        }
      }

      // 去除重复项
      final uniqueResult = <Pao>{};
      uniqueResult.addAll(result);
      return uniqueResult.toList();
    } catch (e) {
      return [Pao.green];
    }
  }

  /// 更改当前袍子为新的袍子
  int change(Pao newPao) {
    final allPao = readAll();
    
    // 检查新袍子是否已经解锁
    bool found = false;
    for (final pao in allPao) {
      if (pao == newPao) {
        found = true;
        break;
      }
    }
    
    if (!found) {
      return 1; // 未找到该袍子，无法设置
    }

    try {
      final file = File(_paonow);
      file.writeAsStringSync(newPao.value.toString());
      return 0; // 成功
    } catch (e) {
      return 1; // 失败
    }
  }

  /// 添加一个新的袍子到解锁列表
  void add(Pao addPao) {
    try {
      final file = File(_paoall);
      final fileExists = file.existsSync();
      
      // 如果文件不存在，则直接写入袍子编号；否则在前面加逗号
      final content = fileExists ? ',${addPao.value}' : '${addPao.value}';
      file.writeAsStringSync(content, mode: FileMode.append);
    } catch (e) {
      // 如果写入失败，什么都不做
    }
  }
}

/// 工厂方法创建AncientPao实例
AncientPao createAncientPao(String nowFilePath, String allFilePath) {
  return AncientPao(nowFilePath, allFilePath);
}