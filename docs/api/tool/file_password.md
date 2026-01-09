# FilePassword 类文档

## 概述

`FilePassword` 是一个用于处理加密文件存储的 Dart 类。它将数字以加密形式存储在文件中，使用密码字符映射进行加解密操作。适用于需要简单加密存储的场景，如本地配置、用户数据等。

## 导入

```dart
import 'dart:io';
```

## 常量

- `original`：原始字符集，固定为 `"0123456789"`

## 构造函数

### FilePassword(String filename, String password)
主构造函数，创建 FilePassword 实例并验证密码。

**参数：**
- `filename`：要操作的文件路径
- `password`：加密密码，必须为10个不重复的字符

**特性：**
- 如果密码包含重复字符，会自动使用默认密码 `"1324096857"`
- 不会自动创建文件，文件在第一次读写操作时创建

**示例：**
```dart
final fp = FilePassword('data.txt', '9876543210');
```

### FilePassword.withDefault(String filename, String password, int defaultValue)
带默认值的构造函数，如果文件不存在则写入默认值。

**参数：**
- `filename`：要操作的文件路径
- `password`：加密密码，必须为10个不重复的字符
- `defaultValue`：文件不存在时写入的默认值

**示例：**
```dart
final fp = FilePassword.withDefault('data.txt', '9876543210', 100);
```

## 核心方法

### 读取方法

#### `Future<String> readPassword()`
读取文件中的加密内容。

**返回值：** 加密后的字符串
**异常：** 可能抛出 `IOException`

#### `String readPasswordSync()`
同步版本，读取文件中的加密内容。

#### `Future<String> readReal()`
读取并解密文件内容。

**返回值：** 解密后的实际数字字符串
**示例：** 如果文件中存储的是加密后的 `"abc"`，解密后可能返回 `"123"`

#### `String readRealSync()`
同步版本，读取并解密文件内容。

#### `Future<String> readStr()`
读取存储的数字并返回字符串格式。

**返回值：** 数字的字符串表示
**异常：** 可能抛出 `FormatException`（如果内容不是有效数字）

#### `String readStrSync()`
同步版本，读取存储的数字并返回字符串格式。

#### `Future<int> readInt()`
读取存储的数字并返回整数格式。

**返回值：** 整数
**异常：** 可能抛出 `FormatException`（如果内容不是有效数字）

#### `int readIntSync()`
同步版本，读取存储的数字并返回整数格式。

### 写入方法

#### `Future<void> write(int newNum)`
将数字加密后写入文件。

**参数：**
- `newNum`：要写入的数字

**异常：** 可能抛出 `IOException`

#### `void writeSync(int newNum)`
同步版本，将数字加密后写入文件。

### 算术操作

#### `Future<void> add(int num)`
读取当前值，加上指定值后写回文件。

**参数：**
- `num`：要加上的值（可正可负）

#### `void addSync(int num)`
同步版本，读取当前值，加上指定值后写回文件。

#### `Future<void> addNum(int a)`
增加存储数字，只处理非负数。

**参数：**
- `a`：要增加的非负数
**注意：** 如果 `a < 0`，操作会被忽略

#### `void addNumSync(int a)`
同步版本，增加存储数字。

#### `Future<void> minusNum(int a)`
减小存储数字，不检查结果是否为负数。

**参数：**
- `a`：要减小的非负数
**注意：** 如果 `a < 0`，操作会被忽略

#### `void minusNumSync(int a)`
同步版本，减小存储数字。

#### `Future<void> minusNumIf(int a)`
减小存储数字，如果不足则减至0。

**参数：**
- `a`：要减小的非负数
**注意：** 如果 `a < 0`，操作会被忽略

#### `void minusNumIfSync(int a)`
同步版本，减小存储数字。

### 比较和条件操作

#### `Future<bool> high(int a)`
判断存储的数字是否大于等于指定值。

**参数：**
- `a`：要比较的值
**返回值：** 如果存储值 ≥ `a` 返回 `true`，否则 `false`

#### `bool highSync(int a)`
同步版本，判断存储的数字是否大于等于指定值。

#### `Future<bool> canMinus(int a)`
判断是否足够减去指定值，如果足够则执行减法。

**参数：**
- `a`：要减去的非负数
**返回值：** 如果成功减去返回 `true`，否则 `false`

#### `bool canMinusSync(int a)`
同步版本，判断是否足够减去指定值。

### 安全方法（不抛出异常）

#### `Future<String> readStrSafe()`
安全读取字符串，发生异常时返回 `"0"`。

#### `String readStrSafeSync()`
同步版本，安全读取字符串。

#### `Future<int> readIntSafe()`
安全读取整数，发生异常时返回 `0`。

#### `int readIntSafeSync()`
同步版本，安全读取整数。

#### `Future<bool> canMinusSafe(int an)`
安全执行 `canMinus`，发生异常时返回 `false`。

#### `bool canMinusSafeSync(int an)`
同步版本，安全执行 `canMinus`。

## 加密原理

该类使用简单的字符替换加密：
- 原始字符集：`0 1 2 3 4 5 6 7 8 9`
- 密码字符集：用户提供的10个不重复字符
- 加密：将数字中的每个字符根据原始字符集索引替换为密码字符集中对应位置的字符
- 解密：反向操作

**示例：**
- 密码：`"9876543210"`
- 数字：`123`
- 加密过程：`1→8`, `2→7`, `3→6`
- 加密结果：`"876"`

## 错误处理

### IOException
文件操作异常，如：
- 文件创建失败
- 文件读取失败
- 文件写入失败

### FormatException
数据格式异常，如：
- 文件内容无法解密
- 解密后的内容不是有效数字

## 使用示例

### 基本使用
```dart
// 创建实例
final fp = FilePassword.withDefault('data.txt', '9876543210', 0);

// 写入数据
await fp.write(100);

// 读取数据
final value = await fp.readInt();  // 返回 100

// 增加数值
await fp.addNum(50);  // 现在值为 150

// 条件减少
if (await fp.canMinus(30)) {
  print('成功减去30');  // 现在值为 120
}
```

### 安全使用
```dart
// 使用安全方法避免异常
final safeValue = await fp.readIntSafe();  // 不会抛出异常
final canSubtract = await fp.canMinusSafe(200);  // 安全执行
```

### 同步操作
```dart
// 同步版本适合简单脚本
final fp = FilePassword('data.txt', '9876543210');
fp.writeSync(100);
final value = fp.readIntSync();
```

## 注意事项

1. **密码要求**：密码必须是10个不重复的字符
2. **文件创建**：文件在第一次读写时自动创建
3. **线程安全**：同步方法在单线程环境使用，异步方法适合Flutter应用
4. **数据一致性**：并发访问时需额外处理同步问题
5. **加密强度**：此加密适合简单场景，不适用于高安全需求

## 性能建议

1. 频繁读写时考虑使用同步方法
2. 大量操作时考虑批量处理
3. 多文件操作时注意文件句柄管理
4. 在Flutter中优先使用异步方法避免阻塞UI