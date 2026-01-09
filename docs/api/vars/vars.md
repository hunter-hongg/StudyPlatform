# Files 类文档

## 概述
文件操作工具类，封装常用文件访问功能。

## 方法

### `static FilePassword jiFenReader()`
创建积分文件读取器。

**返回值：** `FilePassword` 实例
**文件路径：** `${Dirs.filePath()}jifc.txt`
**加密密码：** `"hsiep10475"`

**示例：**
```dart
FilePassword fp = Files.jiFenReader();
int score = fp.readIntSync();
```
