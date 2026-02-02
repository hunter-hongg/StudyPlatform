# AncientSword API 文档

## 概述

AncientSword 是一个用于管理古剑系统的逻辑类，提供了对当前剑和拥有的所有剑的读取、修改和添加功能。

## 枚举定义

### Sword

Sword 枚举定义了剑的不同类型：

- green (青剑)
- red (赤剑)
- purple (紫剑)
- black (黑剑)
- white (白剑)
- realRed (红剑)
- blue (蓝剑)

## 类定义

### AncientSword

AncientSword 类提供以下功能：

#### 构造函数

```dart
AncientSword(String swordNow, String swordAll)
```

- **swordNow**: 存储当前选择剑的文件路径
- **swordAll**: 存储所有拥有剑的文件路径

#### getNow()

获取当前选择的剑。

- **返回值**: Sword 枚举类型的剑

#### getAll()

获取所有拥有的剑。

- **返回值**: Sword 枚举类型的列表

#### readNow()

读取当前选择的剑。

- **返回值**: Sword 枚举类型的剑
- **说明**: 如果文件不存在或读取失败，返回默认值 green

#### readAll()

读取所有拥有的剑。

- **返回值**: Sword 枚举类型的列表
- **说明**: 读取 swordAll 文件中的剑数据，自动去除重复项，如果文件不存在或读取失败，返回 [Sword.green]

#### change(Sword newSword)

更改当前选择的剑。

- **参数**: newSword - 要更改为的新剑
- **返回值**: 0 表示成功，1 表示失败
- **说明**: 仅当 newSword 在拥有的剑列表中时才能更改

#### add(Sword addSword)

添加一把新剑到拥有的剑列表。

- **参数**: addSword - 要添加的剑
- **说明**: 将新剑添加到 swordAll 文件中

## 依赖关系

- 依赖 `dart:io` 包进行文件操作
- 依赖 `dart:convert` 包处理字符串转换