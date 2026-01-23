# RandomGet 类文档

## 概述

`RandomGet` 是一个基于加密安全随机数生成器的工具类，提供高质量的随机数生成功能。所有方法均使用单例的 `Random.secure()` 实例，确保线程安全且性能高效。

## 类成员

### `getRandomDevice()`

```dart
static Random getRandomDevice()
```

**描述**：获取共享的加密安全随机数生成器实例。

**返回值**：
- 类型：`Random`
- 说明：使用 `Random.secure()` 创建的单例实例，所有方法共享同一个随机数源

**特性**：
- **加密安全**：使用操作系统提供的 CSPRNG（加密安全伪随机数生成器）
- **线程安全**：多个 Isolate 可安全调用同一实例
- **高性能**：避免重复创建 Random 实例的开销

**示例**：
```dart
// 获取随机数生成器
Random rng = RandomGet.getRandomDevice();

// 直接使用 Random 类的方法
int randomNum = rng.nextInt(100);
double randomDouble = rng.nextDouble();
bool randomBool = rng.nextBool();
```

---

### `getIntClosed(int min, int max)`

```dart
static int getIntClosed(int min, int max)
```

**描述**：生成**闭区间** `[min, max]` 的随机整数。

**参数**：
| 参数 | 类型 | 描述 | 约束条件 |
|------|------|------|----------|
| `min` | `int` | 最小值（包含） | 任意整数 |
| `max` | `int` | 最大值（包含） | 必须大于或等于 `min` |

**返回值**：
- 类型：`int`
- 范围：包含边界值，即 `min ≤ result ≤ max`

**算法**：
```dart
min + nextInt(max - min + 1)
```

**数学表示**：
```
result ∈ {x | min ≤ x ≤ max}
```

**边界情况**：
- 当 `min == max` 时，总是返回该值
- 当 `max < min` 时，抛出 `ArgumentError`

**示例**：
```dart
// 模拟骰子投掷：生成 1-6 的随机数
int diceRoll = RandomGet.getIntClosed(1, 6); // 1, 2, 3, 4, 5, 6

// 生成 [0, 100] 的随机整数
int percentage = RandomGet.getIntClosed(0, 100); // 包含 0 和 100

// 生成单一值
int constant = RandomGet.getIntClosed(5, 5); // 总是返回 5
```

---

### `getIntClose(int min, int max)`

```dart
static int getIntClose(int min, int max)
```

**描述**：生成**左闭右开区间** `[min, max)` 的随机整数。

**参数**：
| 参数 | 类型 | 描述 | 约束条件 |
|------|------|------|----------|
| `min` | `int` | 最小值（包含） | 任意整数 |
| `max` | `int` | 最大值（不包含） | 必须大于 `min` |

**返回值**：
- 类型：`int`
- 范围：包含最小值，不包含最大值，即 `min ≤ result < max`

**实现**：内部调用 `getIntClosed(min, max - 1)`

**数学表示**：
```
result ∈ {x | min ≤ x < max}
```

**特点**：
- 这是**最常用**的区间表示法
- 与 Dart 的 `List` 索引范围一致（0 ≤ index < length）
- 与大多数编程语言的数组/列表访问模式匹配

**示例**：
```dart
// 数组索引（最常用场景）
List<String> items = ['A', 'B', 'C', 'D'];
int randomIndex = RandomGet.getIntClose(0, items.length); // 0, 1, 2, 3

// 生成 [0, 10) 的随机数
int score = RandomGet.getIntClose(0, 10); // 0-9，不包含10

// 生成 [100, 200) 的随机数
int temperature = RandomGet.getIntClose(100, 200); // 100-199
```

---

### `getWith01()`

```dart
static int getWith01()
```

**描述**：生成随机比特位，均匀返回 0 或 1。

**返回值**：
- 类型：`int`
- 值：随机返回 0 或 1

**算法**：
```dart
nextBool() ? 0 : 1
```

**概率分布**：
- P(0) = 0.5
- P(1) = 0.5

**性能优势**：
- 比 `nextInt(2)` 稍微高效
- 代码更简洁易懂

**使用场景**：
- 二选一决策
- 随机开关状态
- 模拟布尔值的整数表示

**示例**：
```dart
// 模拟硬币抛掷
int coinToss = RandomGet.getWith01();
// 0 表示正面，1 表示反面
String result = coinToss == 0 ? '正面' : '反面';

// 随机选择
int choice = RandomGet.getWith01();
// 根据选择执行不同操作
if (choice == 0) {
  print('选择选项A');
} else {
  print('选择选项B');
}
```

## 方法对比表

| 方法 | 区间类型 | 数学表示 | 包含边界 | 适用场景 |
|------|----------|----------|----------|----------|
| `getIntClosed` | 闭区间 | [min, max] | 都包含 | 骰子、百分比、包含最大值的范围 |
| `getIntClose` | 左闭右开 | [min, max) | 包含min | 数组索引、列表访问、常规随机范围 |
| `getWith01` | 离散值 | {0, 1} | 不适用 | 二选一、随机比特、布尔决策 |

## 使用示例

### 基础示例

```dart
void main() {
  print('=== RandomGet 使用示例 ===');
  
  // 1. 闭区间示例
  print('闭区间 [1, 6] 模拟骰子:');
  for (int i = 0; i < 5; i++) {
    print('  骰子 ${i+1}: ${RandomGet.getIntClosed(1, 6)}');
  }
  
  // 2. 左闭右开区间示例
  print('\n左闭右开 [0, 10) 随机分数:');
  List<int> scores = [];
  for (int i = 0; i < 5; i++) {
    int score = RandomGet.getIntClose(0, 10);
    scores.add(score);
    print('  分数 ${i+1}: $score');
  }
  
  // 3. 随机比特示例
  print('\n随机比特 (0或1):');
  for (int i = 0; i < 10; i++) {
    int bit = RandomGet.getWith01();
    print('  ${bit}',);
  }
}
```

### 实用扩展方法

```dart
/// 扩展 List 类以支持随机操作
extension RandomListExtension<T> on List<T> {
  /// 随机获取一个元素（使用闭区间）
  T randomElement() {
    if (isEmpty) {
      throw StateError('Cannot get random element from empty list');
    }
    int index = RandomGet.getIntClosed(0, length - 1);
    return this[index];
  }
  
  /// 随机获取多个不重复的元素
  List<T> randomElements(int count, {bool allowDuplicates = false}) {
    if (count <= 0) return [];
    if (count > length && !allowDuplicates) {
      throw ArgumentError('Count cannot exceed list length when duplicates are not allowed');
    }
    
    List<T> result = [];
    List<int> availableIndices = List.generate(length, (index) => index);
    
    for (int i = 0; i < count; i++) {
      int randomIndex = RandomGet.getIntClosed(0, availableIndices.length - 1);
      int actualIndex = availableIndices[randomIndex];
      result.add(this[actualIndex]);
      
      if (!allowDuplicates) {
        availableIndices.removeAt(randomIndex);
      }
    }
    
    return result;
  }
}

/// 使用示例
void exampleUsage() {
  List<String> fruits = ['苹果', '香蕉', '橙子', '葡萄', '芒果'];
  
  // 随机选择一个水果
  String randomFruit = fruits.randomElement();
  print('随机水果: $randomFruit');
  
  // 随机选择3个不重复的水果
  List<String> randomFruits = fruits.randomElements(3);
  print('随机3个水果: $randomFruits');
}
```

### 随机密码生成器

```dart
class PasswordGenerator {
  static const String _lowercase = 'abcdefghijklmnopqrstuvwxyz';
  static const String _uppercase = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ';
  static const String _digits = '0123456789';
  static const String _symbols = '!@#\$%^&*()-_=+[]{}|;:,.<>?';
  
  /// 生成随机密码
  static String generate({
    int length = 12,
    bool includeLowercase = true,
    bool includeUppercase = true,
    bool includeDigits = true,
    bool includeSymbols = true,
  }) {
    if (length <= 0) {
      throw ArgumentError('密码长度必须大于0');
    }
    
    // 构建字符集
    String charset = '';
    if (includeLowercase) charset += _lowercase;
    if (includeUppercase) charset += _uppercase;
    if (includeDigits) charset += _digits;
    if (includeSymbols) charset += _symbols;
    
    if (charset.isEmpty) {
      throw ArgumentError('必须至少包含一种字符类型');
    }
    
    // 生成密码
    StringBuffer password = StringBuffer();
    for (int i = 0; i < length; i++) {
      int index = RandomGet.getIntClosed(0, charset.length - 1);
      password.write(charset[index]);
    }
    
    return password.toString();
  }
}

// 使用示例
void generatePasswords() {
  // 生成简单密码
  String simplePassword = PasswordGenerator.generate(
    length: 8,
    includeSymbols: false,
  );
  print('简单密码: $simplePassword');
  
  // 生成强密码
  String strongPassword = PasswordGenerator.generate(
    length: 16,
    includeLowercase: true,
    includeUppercase: true,
    includeDigits: true,
    includeSymbols: true,
  );
  print('强密码: $strongPassword');
}
```

## 错误处理

所有方法都包含边界检查：

```dart
// 错误的调用示例
try {
  // min > max，会抛出异常
  int result = RandomGet.getIntClosed(10, 5);
} catch (e) {
  print('错误: $e'); // 输出: Invalid argument(s): max must be >= min
}

try {
  // 空区间，会抛出异常
  int result = RandomGet.getIntClose(5, 5);
} catch (e) {
  print('错误: $e'); // 输出: Invalid argument(s): max must be > min
}
```

## 性能建议

1. **单例模式**：类已使用单例 `Random` 实例，避免重复创建开销
2. **方法选择**：根据具体需求选择合适的方法：
   - 仅需 0/1 时使用 `getWith01()`
   - 数组索引使用 `getIntClose()`
   - 包含最大值的范围使用 `getIntClosed()`
3. **批量生成**：对于大量随机数，考虑直接使用 `getRandomDevice()` 的原始方法

## 安全说明

- **加密安全**：使用 `Random.secure()` 确保生成的随机数具有密码学强度
- **适合场景**：密码生成、会话令牌、加密密钥等安全敏感应用
- **不适合**：需要确定性的随机数（如游戏种子），应使用普通 `Random()`