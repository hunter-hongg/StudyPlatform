# Dirs 类文档

## 概述
路径工具类，提供文件路径获取功能。

## 方法

### `static String filePath()`
获取文件存储根路径。

**返回值：** 通过 `EnvMod.getStdpath()` 获取的文件存储根路径

**示例：**
```dart
String path = Dirs.filePath();
print(path); // 输出标准路径
```

**用途：**
- 获取应用文件存储路径
- 用于文件操作的基础路径