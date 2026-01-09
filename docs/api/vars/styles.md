# Styles 类文档

## 概述

`Styles` 是一个 Flutter 样式工具类，提供了预定义的文本样式和按钮样式。通过静态方法返回常用的 UI 样式，有助于保持整个应用界面风格的一致性。

## 导入

```dart
import 'package:flutter/material.dart';
```

## 文本样式方法

### `static TextStyle titleStyle()`
**主标题样式**

返回一个适用于主标题的文本样式。

**样式特性：**
- 字体大小：35
- 字体粗细：粗体（`FontWeight.bold`）
- 颜色：黑色（`Colors.black`）

**使用场景：**
- 页面主标题
- 重要模块标题

**示例：**
```dart
Text(
  '欢迎使用',
  style: Styles.titleStyle(),
)
```

### `static TextStyle titleDownStyle()`
**副标题样式**

返回一个适用于副标题的文本样式。

**样式特性：**
- 字体大小：32
- 字体粗细：粗体（`FontWeight.bold`）
- 颜色：黑色（`Colors.black`）

**使用场景：**
- 页面副标题
- 次级模块标题
- 比主标题略小的标题

**示例：**
```dart
Text(
  '用户信息',
  style: Styles.titleDownStyle(),
)
```

### `static TextStyle showstrStyle()`
**展示文本样式**

返回一个用于展示信息的文本样式，通常用于显示数据或状态。

**样式特性：**
- 字体大小：22
- 字体粗细：正常（`FontWeight.normal`）
- 颜色：蓝色（`Colors.blue`）

**使用场景：**
- 数据显示
- 状态提示
- 数值展示

**示例：**
```dart
Text(
  '当前余额: 100元',
  style: Styles.showstrStyle(),
)
```

### `static TextStyle simpleTextStyle()`
**简单文本样式**

返回一个通用的文本样式，适用于普通文本内容。

**样式特性：**
- 字体大小：25
- 字体粗细：正常（`FontWeight.normal`）
- 颜色：黑色（`Colors.black`）

**使用场景：**
- 普通文本内容
- 按钮文字
- 描述性文字

**示例：**
```dart
Text(
  '这是一段描述文字',
  style: Styles.simpleTextStyle(),
)
```

## 按钮样式方法

### `static ButtonStyle buttonSimpleStyle()`
**简单按钮样式**

返回一个简单风格的按钮样式，适用于普通操作按钮。

**样式特性：**

| 属性 | 值 | 说明 |
|------|-----|------|
| 前景色 | `Colors.black` | 文字和图标颜色 |
| 背景色 | `Colors.white` | 按钮背景颜色 |
| 阴影深度 | 5 | 按钮阴影效果 |
| 内边距 | `EdgeInsets.symmetric(horizontal: 12, vertical: 15)` | 水平和垂直边距 |
| 文本样式 | `simpleTextStyle()` | 使用简单文本样式 |
| 形状 | `BeveledRectangleBorder()` | 斜角矩形边框 |

**视觉效果：**
- 白色背景，黑色文字
- 明显的阴影效果
- 适中的内边距
- 斜角边框设计

**使用场景：**
- 普通操作按钮
- 表单提交按钮
- 导航按钮

**示例：**
```dart
ElevatedButton(
  onPressed: () {},
  style: Styles.buttonSimpleStyle(),
  child: Text('确定'),
)
```

## 使用示例

### 完整页面示例
```dart
import 'package:flutter/material.dart';
import 'styles.dart';

class ExamplePage extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text('样式示例', style: Styles.titleStyle()),
      ),
      body: Center(
        child: Column(
          mainAxisAlignment: MainAxisAlignment.center,
          children: [
            // 使用主标题样式
            Text('用户中心', style: Styles.titleStyle()),
            SizedBox(height: 20),
            
            // 使用副标题样式
            Text('个人信息', style: Styles.titleDownStyle()),
            SizedBox(height: 30),
            
            // 使用展示文本样式
            Text('账户余额', style: Styles.showstrStyle()),
            Text('¥ 1,000.00', style: Styles.showstrStyle()),
            SizedBox(height: 30),
            
            // 使用简单文本样式
            Text(
              '请仔细阅读以下条款和条件',
              style: Styles.simpleTextStyle(),
            ),
            SizedBox(height: 40),
            
            // 使用按钮样式
            ElevatedButton(
              onPressed: () {
                // 按钮操作
              },
              style: Styles.buttonSimpleStyle(),
              child: Text('确认操作'),
            ),
          ],
        ),
      ),
    );
  }
}
```

### 自定义样式扩展
虽然 `Styles` 类提供了预设样式，但也可以基于这些样式进行扩展：

```dart
// 基于预设样式创建自定义样式
TextStyle customTitleStyle = Styles.titleStyle().copyWith(
  color: Colors.blue,
  fontStyle: FontStyle.italic,
);

// 基于按钮样式创建自定义按钮样式
ButtonStyle customButtonStyle = Styles.buttonSimpleStyle().copyWith(
  backgroundColor: MaterialStateProperty.all(Colors.blue),
  foregroundColor: MaterialStateProperty.all(Colors.white),
);
```

## 设计原则

1. **一致性**：所有样式都遵循统一的设计语言
2. **可读性**：适当的字体大小和颜色对比度确保良好的可读性
3. **层次感**：通过不同大小的字体创建视觉层次
4. **可用性**：按钮样式提供足够的点击区域和视觉反馈

## 最佳实践

1. **优先使用预设样式**：保持整个应用界面风格统一
2. **适当扩展**：当需要微调时，使用 `copyWith()` 方法基于预设样式创建新样式
3. **响应式考虑**：在构建响应式应用时，可能需要根据屏幕尺寸调整字体大小
4. **主题集成**：考虑与 Flutter 主题系统集成，支持暗色模式

## 样式对比表

| 样式名称 | 字体大小 | 字体粗细 | 颜色 | 主要用途 |
|---------|---------|---------|------|---------|
| `titleStyle()` | 35 | 粗体 | 黑色 | 主标题 |
| `titleDownStyle()` | 32 | 粗体 | 黑色 | 副标题 |
| `showstrStyle()` | 22 | 正常 | 蓝色 | 数据展示 |
| `simpleTextStyle()` | 25 | 正常 | 黑色 | 普通文本/按钮文字 |

## 注意事项

1. 这些样式是固定值，不响应系统字体大小设置
2. 颜色使用的是 Material Design 的预定义颜色
3. 按钮样式只适用于 `ElevatedButton`
4. 在需要支持多语言的应用中，可能需要调整字体大小以适应不同语言的文字长度# Styles 类文档

## 概述

`Styles` 是一个 Flutter 样式工具类，提供了预定义的文本样式和按钮样式。通过静态方法返回常用的 UI 样式，有助于保持整个应用界面风格的一致性。

## 导入

```dart
import 'package:flutter/material.dart';
```

## 文本样式方法

### `static TextStyle titleStyle()`
**主标题样式**

返回一个适用于主标题的文本样式。

**样式特性：**
- 字体大小：35
- 字体粗细：粗体（`FontWeight.bold`）
- 颜色：黑色（`Colors.black`）

**使用场景：**
- 页面主标题
- 重要模块标题

**示例：**
```dart
Text(
  '欢迎使用',
  style: Styles.titleStyle(),
)
```

### `static TextStyle titleDownStyle()`
**副标题样式**

返回一个适用于副标题的文本样式。

**样式特性：**
- 字体大小：32
- 字体粗细：粗体（`FontWeight.bold`）
- 颜色：黑色（`Colors.black`）

**使用场景：**
- 页面副标题
- 次级模块标题
- 比主标题略小的标题

**示例：**
```dart
Text(
  '用户信息',
  style: Styles.titleDownStyle(),
)
```

### `static TextStyle showstrStyle()`
**展示文本样式**

返回一个用于展示信息的文本样式，通常用于显示数据或状态。

**样式特性：**
- 字体大小：22
- 字体粗细：正常（`FontWeight.normal`）
- 颜色：蓝色（`Colors.blue`）

**使用场景：**
- 数据显示
- 状态提示
- 数值展示

**示例：**
```dart
Text(
  '当前余额: 100元',
  style: Styles.showstrStyle(),
)
```

### `static TextStyle simpleTextStyle()`
**简单文本样式**

返回一个通用的文本样式，适用于普通文本内容。

**样式特性：**
- 字体大小：25
- 字体粗细：正常（`FontWeight.normal`）
- 颜色：黑色（`Colors.black`）

**使用场景：**
- 普通文本内容
- 按钮文字
- 描述性文字

**示例：**
```dart
Text(
  '这是一段描述文字',
  style: Styles.simpleTextStyle(),
)
```

## 按钮样式方法

### `static ButtonStyle buttonSimpleStyle()`
**简单按钮样式**

返回一个简单风格的按钮样式，适用于普通操作按钮。

**样式特性：**

| 属性 | 值 | 说明 |
|------|-----|------|
| 前景色 | `Colors.black` | 文字和图标颜色 |
| 背景色 | `Colors.white` | 按钮背景颜色 |
| 阴影深度 | 5 | 按钮阴影效果 |
| 内边距 | `EdgeInsets.symmetric(horizontal: 12, vertical: 15)` | 水平和垂直边距 |
| 文本样式 | `simpleTextStyle()` | 使用简单文本样式 |
| 形状 | `BeveledRectangleBorder()` | 斜角矩形边框 |

**视觉效果：**
- 白色背景，黑色文字
- 明显的阴影效果
- 适中的内边距
- 斜角边框设计

**使用场景：**
- 普通操作按钮
- 表单提交按钮
- 导航按钮

**示例：**
```dart
ElevatedButton(
  onPressed: () {},
  style: Styles.buttonSimpleStyle(),
  child: Text('确定'),
)
```

## 使用示例

### 完整页面示例
```dart
import 'package:flutter/material.dart';
import 'styles.dart';

class ExamplePage extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text('样式示例', style: Styles.titleStyle()),
      ),
      body: Center(
        child: Column(
          mainAxisAlignment: MainAxisAlignment.center,
          children: [
            // 使用主标题样式
            Text('用户中心', style: Styles.titleStyle()),
            SizedBox(height: 20),
            
            // 使用副标题样式
            Text('个人信息', style: Styles.titleDownStyle()),
            SizedBox(height: 30),
            
            // 使用展示文本样式
            Text('账户余额', style: Styles.showstrStyle()),
            Text('¥ 1,000.00', style: Styles.showstrStyle()),
            SizedBox(height: 30),
            
            // 使用简单文本样式
            Text(
              '请仔细阅读以下条款和条件',
              style: Styles.simpleTextStyle(),
            ),
            SizedBox(height: 40),
            
            // 使用按钮样式
            ElevatedButton(
              onPressed: () {
                // 按钮操作
              },
              style: Styles.buttonSimpleStyle(),
              child: Text('确认操作'),
            ),
          ],
        ),
      ),
    );
  }
}
```

### 自定义样式扩展
虽然 `Styles` 类提供了预设样式，但也可以基于这些样式进行扩展：

```dart
// 基于预设样式创建自定义样式
TextStyle customTitleStyle = Styles.titleStyle().copyWith(
  color: Colors.blue,
  fontStyle: FontStyle.italic,
);

// 基于按钮样式创建自定义按钮样式
ButtonStyle customButtonStyle = Styles.buttonSimpleStyle().copyWith(
  backgroundColor: MaterialStateProperty.all(Colors.blue),
  foregroundColor: MaterialStateProperty.all(Colors.white),
);
```

## 设计原则

1. **一致性**：所有样式都遵循统一的设计语言
2. **可读性**：适当的字体大小和颜色对比度确保良好的可读性
3. **层次感**：通过不同大小的字体创建视觉层次
4. **可用性**：按钮样式提供足够的点击区域和视觉反馈

## 最佳实践

1. **优先使用预设样式**：保持整个应用界面风格统一
2. **适当扩展**：当需要微调时，使用 `copyWith()` 方法基于预设样式创建新样式
3. **响应式考虑**：在构建响应式应用时，可能需要根据屏幕尺寸调整字体大小
4. **主题集成**：考虑与 Flutter 主题系统集成，支持暗色模式

## 样式对比表

| 样式名称 | 字体大小 | 字体粗细 | 颜色 | 主要用途 |
|---------|---------|---------|------|---------|
| `titleStyle()` | 35 | 粗体 | 黑色 | 主标题 |
| `titleDownStyle()` | 32 | 粗体 | 黑色 | 副标题 |
| `showstrStyle()` | 22 | 正常 | 蓝色 | 数据展示 |
| `simpleTextStyle()` | 25 | 正常 | 黑色 | 普通文本/按钮文字 |

## 注意事项

1. 这些样式是固定值，不响应系统字体大小设置
2. 颜色使用的是 Material Design 的预定义颜色
3. 按钮样式只适用于 `ElevatedButton`
4. 在需要支持多语言的应用中，可能需要调整字体大小以适应不同语言的文字长度