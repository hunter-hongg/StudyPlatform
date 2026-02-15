# XianSword API 文档

## 概述

XianSword 是一个用于管理仙剑系统的逻辑模块，提供了五行剑（金、木、水、火、土）的枚举定义、文件存储和异常处理功能。该模块允许将剑类型持久化到文件中，并在需要时从文件中读取。

## 枚举定义

### SwordEnum

SwordEnum 枚举定义了五行剑的不同类型，每个类型都有对应的中文名称：

| 枚举值 | 索引 | 中文名称 |
|-------|------|----------|
| gold  | 0    | 金剑     |
| wood  | 1    | 木剑     |
| water | 2    | 水剑     |
| fire  | 3    | 火剑     |
| soil  | 4    | 土剑     |

#### 方法

##### toString()

将枚举值转换为中文字符串表示。

- **返回值**: 对应剑的中文名称（例如："金剑"、"木剑"等）

##### fromInt(int value)

从整数值创建对应的 SwordEnum 枚举。

- **参数**:
  - value: 整数值（0-4）
- **返回值**: 对应的 SwordEnum 枚举值，如果值无效则默认返回 gold

## 函数

### swordToString(SwordEnum enumA)

将 SwordEnum 枚举转换为字符串。

- **参数**:
  - enumA: SwordEnum 枚举值
- **返回值**: 枚举的字符串表示

### newSwordException(String err)

创建 SwordException 实例的工厂函数。

- **参数**:
  - err: 错误消息
- **返回值**: SwordException 实例

## 异常类

### SwordException

SwordException 是自定义异常类，用于处理剑相关的错误情况。

#### 构造函数

```dart
SwordException(String msg)
```

- **参数**:
  - msg: 异常消息字符串

#### 方法

##### toString()

返回异常消息字符串。

- **返回值**: 异常消息

## 类定义

### SwordInFile

SwordInFile 类提供了将剑类型持久化到文件并从文件读取的功能。

#### 构造函数

```dart
SwordInFile(String file)
```

- **参数**:
  - file: 存储剑类型的文件路径

#### 工厂构造函数

```dart
SwordInFile.create(String file1)
```

- **参数**:
  - file1: 存储剑类型的文件路径
- **返回值**: SwordInFile 实例

#### 方法

##### _ensureFileExists()

私有方法，确保文件存在。如果文件不存在，则尝试创建它。

- **说明**: 该方法在构造函数中调用，确保后续的文件操作能够正常进行

##### get()

从文件中读取剑类型。

- **返回值**: SwordEnum 枚举值
- **说明**: 
  - 如果文件不存在、内容为空或无效，则默认返回 gold
  - 包含完整的错误处理，确保即使在异常情况下也能返回默认值

##### set(SwordEnum thing)

将剑类型写入文件。

- **参数**:
  - thing: 要存储的 SwordEnum 枚举值
- **返回值**: Future<void>
- **异常**: 如果写入失败，抛出 SwordException

## 使用示例

### 基本用法

```dart
// 创建文件管理器
SwordInFile swordFile = SwordInFile.create("path/to/sword_file.txt");

// 设置剑类型
await swordFile.set(SwordEnum.fire);

// 获取剑类型
SwordEnum currentSword = swordFile.get();
print(swordToString(currentSword)); // 输出: 火剑

// 使用枚举
SwordEnum mySword = SwordEnum.water;
print(mySword.toString()); // 输出: 水剑

// 从整数值创建枚举
SwordEnum fromValue = SwordEnum.fromInt(2); // water
```

### 错误处理

```dart
try {
  SwordInFile swordFile = SwordInFile.create("path/to/sword_file.txt");
  await swordFile.set(SwordEnum.wood);
} catch (e) {
  if (e is SwordException) {
    print("剑操作错误: ${e.toString()}");
  }
}
```

## 技术实现细节

1. **文件存储格式**: 文件中存储的是枚举的索引值（0-4），而不是字符串或其他格式
2. **错误处理机制**:
   - 文件创建过程中的错误会被忽略
   - 文件读取过程中的错误会被捕获并返回默认值 gold
   - 文件写入过程中的错误会抛出 SwordException
3. **默认值策略**: 当文件不存在、内容为空或无效时，默认返回 gold 剑
4. **异步操作**: set 方法是异步的，而 get 方法是同步的

## 注意事项

1. 确保文件路径具有正确的读写权限
2. 文件名可以根据实际需求自定义
3. 模块会自动处理文件不存在的情况
4. 建议在使用 set 方法时添加适当的错误处理