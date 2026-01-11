# OnceFile 文档

## 概述

`OnceFile` 是一个用于标记操作是否已执行过的 Dart 工具类。它通过文件系统来持久化存储执行状态，支持同步和异步操作，并提供 JSON 数据序列化功能。

## 核心类

### OnceFile

主类，提供基本的文件标记功能。

#### 构造函数

```dart
OnceFile(String filePath, {String? content})
```

- `filePath`: 标记文件的路径
- `content`: 可选，写入文件的内容（默认是当前时间戳的 ISO8601 字符串）

#### 属性

| 属性 | 类型 | 描述 |
|------|------|------|
| `canExecute` | `bool` | 检查是否可以执行操作（文件不存在时返回 `true`） |
| `executionTime` | `DateTime?` | 获取已执行的时间（文件存在时返回修改时间） |

#### 方法

##### `readContent()`
读取标记文件的内容。
- **返回**: `String?` - 文件内容，如果文件不存在或读取失败则返回 `null`

##### `use()`
使用标记。如果文件不存在则创建，已存在则更新访问时间。
- **返回**: `bool` - 是否成功创建了新的标记（`true` 表示首次创建）
- **异常**: 无（失败时返回 `false`）

##### `forceUpdate({String? newContent})`
强制更新标记，无论文件是否存在都写入。
- `newContent`: 可选的新内容，不提供则使用初始化时的内容
- **异常**: 失败时抛出 `Exception`

##### `clear()`
清除标记（删除文件）。
- **返回**: `bool` - 是否成功删除

##### `isOlderThanDays(int days)`
检查自上次执行以来是否已过指定天数。
- `days`: 天数阈值
- **返回**: `bool` - 如果未执行过或已超过指定天数则返回 `true`

##### `useAsync()`
`use()` 方法的异步版本。
- **返回**: `Future<bool>` - 是否成功创建了新的标记

##### `readContentAsync()`
`readContent()` 方法的异步版本。
- **返回**: `Future<String?>` - 文件内容

#### 静态方法

##### `checkMultiple(List<String> filePaths)`
批量检查多个标记文件的状态。
- **返回**: `Map<String, bool>` - 文件路径到是否可执行的映射

##### `markMultiple(List<String> filePaths)`
批量创建多个标记文件。
- **返回**: `Map<String, bool>` - 文件路径到是否首次创建的映射

---

### JsonOnceFile<T>

继承自 `OnceFile`，提供 JSON 数据序列化支持。

#### 构造函数

```dart
JsonOnceFile(
  String filePath, {
  T? initialData,
})
```

- `filePath`: 标记文件的路径
- `initialData`: 可选的初始数据

#### 方法

##### `readJsonData()`
读取并解析 JSON 数据。
- **返回**: `T?` - 解析后的数据对象

##### `useWithData(T data)`
使用 JSON 数据创建标记。
- `data`: 要存储的数据对象
- **返回**: `bool` - 是否成功创建了新的标记

##### `readJsonDataAsync()`
`readJsonData()` 的异步版本。
- **返回**: `Future<T?>` - 解析后的数据对象

## 使用示例

### 基本用法

```dart
// 创建标记文件
final onceFile = OnceFile('/path/to/mark.txt');

// 检查是否可以执行
if (onceFile.canExecute) {
  print('首次执行操作');
  onceFile.use(); // 创建标记
} else {
  print('操作已执行于: ${onceFile.executionTime}');
}

// 检查是否超过7天
if (onceFile.isOlderThanDays(7)) {
  print('距离上次执行已超过7天');
  onceFile.forceUpdate(); // 强制更新
}

// 清除标记
onceFile.clear();
```

### JSON 数据存储

```dart
// 存储复杂数据
final jsonOnceFile = JsonOnceFile<Map<String, dynamic>>(
  '/path/to/data.json',
  initialData: {'version': '1.0', 'count': 0},
);

// 使用数据创建标记
final result = jsonOnceFile.useWithData({
  'version': '1.1',
  'count': 5,
  'lastRun': DateTime.now().toIso8601String(),
});

// 读取数据
final data = jsonOnceFile.readJsonData();
print('Stored data: $data');
```

### 批量操作

```dart
// 批量检查
final filesToCheck = [
  '/path/to/mark1.txt',
  '/path/to/mark2.txt',
  '/path/to/mark3.txt',
];

final status = OnceFile.checkMultiple(filesToCheck);
status.forEach((path, canExecute) {
  print('$path: ${canExecute ? "可执行" : "已执行"}');
});

// 批量标记
OnceFile.markMultiple(filesToCheck);
```

### 异步操作

```dart
// 异步使用
final onceFile = OnceFile('/path/to/mark.txt');

void performAsyncOperation() async {
  final isFirstTime = await onceFile.useAsync();
  if (isFirstTime) {
    print('首次异步执行');
  }
  
  final content = await onceFile.readContentAsync();
  print('文件内容: $content');
}
```

## 注意事项

1. **文件权限**: 确保应用有适当的文件系统读写权限。
2. **异常处理**: 文件操作可能因权限不足、磁盘空间不足等原因失败，建议适当处理异常。
3. **并发访问**: 在并发环境中，多个进程/线程可能同时访问同一文件，需要考虑同步机制。
4. **数据序列化**: 使用 `JsonOnceFile` 时，确保数据类型 `T` 可被 `jsonEncode` 和 `jsonDecode` 正确处理。
5. **目录创建**: `use()` 和 `forceUpdate()` 方法会自动创建不存在的目录。

## 适用场景

- 应用首次启动初始化
- 定期任务执行标记
- 用户操作一次性提示
- 数据迁移状态跟踪
- 缓存有效性检查

## 依赖

- `dart:io`: 文件系统操作
- `dart:convert`: JSON 编解码

这个工具类提供了简单而强大的机制来跟踪操作执行状态，适用于各种需要持久化标记的场景。