# AddFile 类文档

## 概述

`AddFile` 是一个用于处理文件中数字值的 Dart 类，支持对文件中的数值进行增加、减少和比较操作。该类提供了一套便捷的 API 来管理存储在文件中的整数值。

## 类定义

```dart
class AddFile {
  final String file;
  final int addnum;
}
```

### 属性

- `file`: 要操作的文件路径
- `addnum`: 一个偏移量，用于在读取和写入数值时进行调整

## 构造函数

### AddFile(String file, int addnum)

基本构造函数，创建一个新的 `AddFile` 实例。

```dart
final addFile = AddFile('/path/to/file.txt', 10);
```

### AddFile.create(String filename, int addnum)

工厂构造函数，创建一个新的 `AddFile` 实例。

```dart
final addFile = AddFile.create('/path/to/file.txt', 10);
```

## 方法

### readInt()

读取文件内容并返回整数值。如果文件不存在或内容不是有效的整数，返回 0。

```dart
int value = addFile.readInt();
```

### readStr()

将文件中的整数值转换为字符串形式。

```dart
String value = addFile.readStr();
```

### write(String written)

将指定字符串异步写入文件。

```dart
await addFile.write('123');
```

### addNum(int an)

在文件中的数值基础上加上指定的值（异步操作）。

```dart
await addFile.addNum(10);
```

### canMinus(int an)

尝试从文件中的数值减去指定的值。如果文件中的数值小于要减去的值，则返回 false，否则执行减法操作并返回 true。

```dart
bool success = addFile.canMinus(5);
```

### high(int an)

检查文件中的数值是否大于等于指定值。

```dart
bool isHigh = addFile.high(100);
```

### canMinusAsync(int an)

异步版本的 `canMinus` 方法。

```dart
bool success = await addFile.canMinusAsync(5);
```

### canMinusSafe(int an)

安全版本的 `canMinus` 方法（异步）。

```dart
bool success = await addFile.canMinusSafe(5);
```

### readIntSafe()

安全版本的 `readInt` 方法。

```dart
int value = addFile.readIntSafe();
```

### readStrSafe()

安全版本的 `readStr` 方法。

```dart
String value = addFile.readStrSafe();
```

### addNumSync(int an)

同步版本的 `addNum` 方法。

```dart
addFile.addNumSync(10);
```

### canMinusSync(int an)

同步版本的 `canMinus` 方法。

```dart
bool success = addFile.canMinusSync(5);
```

## 使用示例

```dart
import 'package:studyplatform/tool/addfile.dart';

void main() {
  // 创建 AddFile 实例
  final addFile = AddFile('data.txt', 100);
  
  // 读取文件中的数值
  int currentValue = addFile.readInt();
  print('Current value: $currentValue');
  
  // 向文件中的数值添加 50
  addFile.addNumSync(50);
  
  // 检查是否有足够的数值进行减法操作
  if (addFile.canMinusSync(25)) {
    print('Successfully reduced value by 25');
  } else {
    print('Not enough value to reduce by 25');
  }
  
  // 检查文件中的数值是否大于等于指定值
  if (addFile.high(100)) {
    print('Value is high enough');
  }
}
```

## 注意事项

1. `addnum` 参数在读取和写入时会被考虑，读取时会从文件中的值减去 `addnum`，写入时会加上 `addnum`。
2. 一些方法提供了同步和异步两种版本，根据使用场景选择合适的版本。
3. 当文件不存在时，某些操作可能会返回默认值（如 0）。
4. 执行减法操作时需要注意值的范围，防止负数结果。