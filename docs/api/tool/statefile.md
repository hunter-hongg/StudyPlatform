# StateFile 工具类文档

## 概述

StateFile 是一个用于管理状态文件的 Dart 工具类，专门设计用来处理内容为 "True" 或 "False" 的文本文件。此类提供了异步和同步两种方式来设置和读取状态值。

## 功能特性

- **状态管理**：支持将布尔值保存为 "True"/"False" 字符串到文件
- **异步操作**：提供异步的状态设置和读取方法
- **同步操作**：提供同步的状态读取方法
- **错误处理**：妥善处理文件 I/O 异常
- **容错机制**：当文件不存在或内容无效时返回默认值

## 类定义

### StateFile 类

```dart
class StateFile {
  final String _filePath;
  // ...
}
```

#### 构造函数

- StateFile(String filePath) - 创建状态文件管理器实例

#### 方法

| 方法 | 返回类型 | 描述 |
|------|----------|------|
| setState(bool state) | Future<void> | 切换状态并写入文件 |
| readState(bool defaultValue) | Future<bool> | 异步读取当前状态，失败时返回默认值 |
| readStateSync(bool defaultValue) | bool | 同步读取当前状态，失败时返回默认值 |

#### 私有方法

| 方法 | 返回类型 | 描述 |
|------|----------|------|
| _readContent() | Future<String> | 异步读取文件内容，不存在时返回空字符串 |
| _readContentSync() | String | 同步读取文件内容，不存在时返回空字符串 |

### StateException 类

自定义异常类，用于处理状态文件操作中的错误。

#### 属性

- message - 错误消息
- cause - 原始异常原因（可选）

#### 构造函数

- StateException(this.message, [this.cause])

## 使用示例

```dart
// 创建状态文件管理器
final stateFile = StateFile('/path/to/state.txt');

// 设置状态
await stateFile.setState(true);  // 写入 "True" 到文件

// 读取状态
bool currentState = await stateFile.readState(false);  // 从文件读取状态，默认为 false
bool syncState = stateFile.readStateSync(true);       // 同步读取状态，默认为 true
```

## 异常处理

- 所有文件 I/O 操作都使用 try-catch 包装
- 文件写入失败时抛出 StateException
- 读取失败时返回传入的默认值，不抛出异常

## 注意事项

- 文件内容必须为 "True" 或 "False"（大小写敏感）
- 如果文件内容不是 "True" 或 "False"，将返回默认值
- 文件不存在时，读取操作会返回默认值
- 所有异步方法都返回 Future 对象，需正确处理