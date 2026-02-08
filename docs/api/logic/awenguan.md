# AncientWenGuanConfig 文档

## 概述

`AncientWenGuanConfig` 是一个用于管理古代文官等级配置的类，通过文件持久化存储文官等级信息，并提供等级读取、设置、提升、降低以及计算俸禄等功能。

## 类定义

```dart
class AncientWenGuanConfig {
  final String file;
  final int addNum;

  AncientWenGuanConfig({
    required this.file,
    required this.addNum,
  }) {
    create();
  }

  // 方法定义...
}
```

## 构造函数

### AncientWenGuanConfig

```dart
AncientWenGuanConfig({
  required this.file,
  required this.addNum,
});
```

**参数：**
- `file` (String): 用于存储等级信息的文件路径
- `addNum` (int): 用于等级计算的偏移值

**说明：**
构造函数会自动调用 `create()` 方法创建（如果需要）存储文件。

## 公共属性

### file

```dart
final String file;
```

存储等级信息的文件路径。

### addNum

```dart
final int addNum;
```

用于等级计算的偏移值，实际存储值为 `等级 + addNum`。

## 公共方法

### create

```dart
void create();
```

**功能：** 创建存储文件（如果需要）。

**说明：**
- 使用 `FileMode.writeOnlyAppend` 模式打开文件
- 如果创建文件失败，会忽略错误

### readLevel

```dart
int readLevel();
```

**功能：** 读取当前文官等级。

**返回值：**
- `int`: 当前文官等级（1-9之间）

**说明：**
1. 如果文件不存在，会创建文件并写入默认值 `addNum + 9`，返回默认等级 9
2. 如果文件内容无法解析为整数，返回默认等级 9
3. 如果计算出的等级不在 1-9 范围内，返回默认等级 9
4. 如果发生其他错误，返回默认等级 9

### setNewLevel

```dart
void setNewLevel(int newLevel);
```

**功能：** 设置新的文官等级。

**参数：**
- `newLevel` (int): 新的等级值

**说明：**
- 将 `newLevel + addNum` 的结果写入文件
- 如果写入失败，会忽略错误

### levelUp

```dart
void levelUp();
```

**功能：** 提升文官等级（等级值减 1）。

**异常：**
- 如果当前等级 `<= 1` 或 `> 9`，会抛出 `Exception('无效的当前等级: $currentLevel')`

**说明：**
- 等级提升时，实际等级值减小（1 为最高等级，9 为最低等级）
- 例如：当前等级为 3，提升后变为 2

### levelDown

```dart
void levelDown();
```

**功能：** 降低文官等级（等级值加 1）。

**异常：**
- 如果当前等级 `< 1` 或 `>= 9`，会抛出 `Exception('无效的当前等级: $currentLevel')`

**说明：**
- 等级降低时，实际等级值增加（1 为最高等级，9 为最低等级）
- 例如：当前等级为 3，降低后变为 4

### getFengLu

```dart
int getFengLu();
```

**功能：** 根据当前等级计算俸禄。

**返回值：**
- `int`: 计算得出的俸禄值

**计算规则：**
- 等级 >= 6 时：`(10 - 等级) * 5`
- 等级 < 6 时：`(10 - 等级) * 6`

**示例：**
- 等级 1：`(10 - 1) * 6 = 54`
- 等级 5：`(10 - 5) * 6 = 30`
- 等级 6：`(10 - 6) * 5 = 20`
- 等级 9：`(10 - 9) * 5 = 5`

## 使用示例

```dart
// 创建文官配置实例
final config = AncientWenGuanConfig(
  file: 'wenguan_level.txt',
  addNum: 100,
);

// 读取当前等级
int level = config.readLevel();
print('当前等级: $level');

// 提升等级
try {
  config.levelUp();
  print('等级提升成功');
} catch (e) {
  print('等级提升失败: $e');
}

// 降低等级
try {
  config.levelDown();
  print('等级降低成功');
} catch (e) {
  print('等级降低失败: $e');
}

// 设置新等级
config.setNewLevel(5);

// 获取俸禄
int fengLu = config.getFengLu();
print('当前俸禄: $fengLu');
```

## 注意事项

1. 等级范围限制为 1-9（1 为最高等级，9 为最低等级）
2. 所有文件操作都包含异常处理，确保程序稳定性
3. 文件内容为纯文本格式，存储的是 `等级 + addNum` 的计算结果
4. 构造函数会自动创建存储文件
5. 等级提升和降低操作可能抛出异常，使用时需要注意捕获