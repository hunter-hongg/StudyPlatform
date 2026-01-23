# Polynomial 类文档

## 概述

`Polynomial` 类表示数学中的多项式，支持常见的算术运算（加减乘除）、微积分运算（求导、积分）和各种实用功能。多项式表示为：
```
aₙxⁿ + aₙ₋₁xⁿ⁻¹ + ... + a₁x + a₀
```

## 构造函数

### `Polynomial(List<double> coefficients)`
通过系数数组构造多项式。

**参数**：
- `coefficients`：系数数组，其中 `coefficients[i]` 是 xⁱ 的系数

**示例**：
```dart
// 创建多项式 3x² + 2x + 1
final p = Polynomial([1, 2, 3]);
```

### `Polynomial.zero()`
创建零多项式。

**示例**：
```dart
final zero = Polynomial.zero(); // 0
```

### `Polynomial.constant(double c)`
创建常数多项式。

**参数**：
- `c`：常数值

**示例**：
```dart
final constant = Polynomial.constant(5); // 5
```

### `Polynomial.linear(double a, double b)`
创建一次多项式（线性多项式）。

**参数**：
- `a`：x 的系数
- `b`：常数项

**示例**：
```dart
final linear = Polynomial.linear(2, -3); // 2x - 3
```

### `Polynomial.quadratic(double a, double b, double c)`
创建二次多项式。

**参数**：
- `a`：x² 的系数
- `b`：x 的系数
- `c`：常数项

**示例**：
```dart
final quadratic = Polynomial.quadratic(1, 0, -4); // x² - 4
```

## 属性

### `coefficients` (final)
系数数组，`coefficients[i]` 是 xⁱ 的系数。

### `degree`
获取多项式的次数（最高次项的次数）。

**返回值**：整数，表示多项式的次数。

**示例**：
```dart
final p = Polynomial([1, 2, 3]);
print(p.degree); // 输出：2
```

## 方法

### `coefficientAt(int power)`
获取指定次数的系数。

**参数**：
- `power`：要获取的次幂

**返回值**：该次幂的系数。如果次幂超出范围，返回 0。

**示例**：
```dart
final p = Polynomial([1, 2, 3]);
print(p.coefficientAt(1)); // 输出：2.0
print(p.coefficientAt(5)); // 输出：0.0
```

### `evaluate(double x)`
在指定点 x 处计算多项式的值。

**参数**：
- `x`：要计算的点

**返回值**：多项式在 x 处的值。

**示例**：
```dart
final p = Polynomial([1, 2, 3]); // 3x² + 2x + 1
print(p.evaluate(2)); // 输出：17.0
```

### `derivative()`
计算多项式的导数。

**返回值**：导数的多项式。

**示例**：
```dart
final p = Polynomial([1, 2, 3]); // 3x² + 2x + 1
final deriv = p.derivative();    // 6x + 2
```

### `integral()`
计算多项式的不定积分（常数项为0）。

**返回值**：积分的多项式。

**示例**：
```dart
final p = Polynomial([1, 2]);    // 2x + 1
final integ = p.integral();      // x² + x
```

### `scalarMultiply(double scalar)`
将多项式乘以一个标量。

**参数**：
- `scalar`：标量值

**返回值**：乘以标量后的新多项式。

**示例**：
```dart
final p = Polynomial([1, 2, 3]); // 3x² + 2x + 1
final scaled = p.scalarMultiply(2); // 6x² + 4x + 2
```

### `divide(Polynomial divisor)`
执行多项式除法。

**参数**：
- `divisor`：除数多项式

**返回值**：包含两个多项式的列表 `[商, 余数]`。

**抛出**：
- `ArgumentError`：如果除数为零多项式

**示例**：
```dart
final dividend = Polynomial([1, 2, 1]); // x² + 2x + 1
final divisor = Polynomial([1, 1]);     // x + 1
final result = dividend.divide(divisor);
print(result[0]); // 商：x + 1
print(result[1]); // 余数：0
```

### `toString()`
将多项式转换为字符串表示。

**返回值**：多项式的字符串表示。

**示例**：
```dart
final p = Polynomial([1, 2, 3]);
print(p.toString()); // 输出：3x^2 + 2x + 1
```

### `toStringBetter()` (扩展方法)
提供更好的字符串表示，处理整数和负系数。

**返回值**：格式更好的字符串表示。

**示例**：
```dart
final p = Polynomial([-1, -2, 3]);
print(p.toStringBetter()); // 输出：3x^2 - 2x - 1
```

## 运算符重载

### 算术运算符

#### `+` (加法)
多项式加法。

```dart
final p1 = Polynomial([1, 2, 3]); // 3x² + 2x + 1
final p2 = Polynomial([4, 5]);    // 5x + 4
final sum = p1 + p2;              // 3x² + 7x + 5
```

#### `-` (减法)
多项式减法。

```dart
final p1 = Polynomial([1, 2, 3]); // 3x² + 2x + 1
final p2 = Polynomial([4, 5]);    // 5x + 4
final diff = p1 - p2;             // 3x² - 3x - 3
```

#### `*` (乘法)
多项式乘法。

```dart
final p1 = Polynomial([1, 1]);    // x + 1
final p2 = Polynomial([1, 1]);    // x + 1
final product = p1 * p2;          // x² + 2x + 1
```

#### `~/` (整除)
多项式整除，返回商。

```dart
final dividend = Polynomial([1, 2, 1]); // x² + 2x + 1
final divisor = Polynomial([1, 1]);     // x + 1
final quotient = dividend ~/ divisor;   // x + 1
```

### 相等性运算符

#### `==` (相等)
判断两个多项式是否相等。

```dart
final p1 = Polynomial([1, 2, 3]);
final p2 = Polynomial([1, 2, 3]);
print(p1 == p2); // 输出：true
```

## 扩展方法

### 多项式与标量的运算

#### `+` (多项式加标量)
```dart
final p = Polynomial([1, 2, 3]); // 3x² + 2x + 1
final result = p + 5;            // 3x² + 2x + 6
```

#### `-` (多项式减标量)
```dart
final p = Polynomial([1, 2, 3]); // 3x² + 2x + 1
final result = p - 1;            // 3x² + 2x
```

#### `*` (多项式乘标量)
```dart
final p = Polynomial([1, 2, 3]); // 3x² + 2x + 1
final result = p * 2;            // 6x² + 4x + 2
```

### 标量与多项式的运算

#### `+` (标量加多项式)
```dart
final p = Polynomial([1, 2, 3]); // 3x² + 2x + 1
final result = 5.0 + p;          // 3x² + 2x + 6
```

#### `-` (标量减多项式)
```dart
final p = Polynomial([1, 2, 3]); // 3x² + 2x + 1
final result = 5.0 - p;          // -3x² - 2x + 4
```

#### `*` (标量乘多项式)
```dart
final p = Polynomial([1, 2, 3]); // 3x² + 2x + 1
final result = 2.0 * p;          // 6x² + 4x + 2
```

## 内部方法

### `_normalize(List<double> coeffs)` (静态方法)
规范化系数数组，去除尾部多余的零。

**参数**：
- `coeffs`：原始系数数组

**返回值**：规范化后的系数数组。

## 使用示例

```dart
void main() {
  // 创建多项式
  final p1 = Polynomial([1, 2, 3]);     // 3x² + 2x + 1
  final p2 = Polynomial.linear(2, -3);  // 2x - 3
  
  // 基本运算
  print('p1 = ${p1.toStringBetter()}');
  print('p2 = ${p2.toStringBetter()}');
  print('p1(2) = ${p1.evaluate(2)}');
  print('p1 的次数: ${p1.degree}');
  
  // 算术运算
  final sum = p1 + p2;
  final diff = p1 - p2;
  final product = p1 * p2;
  
  print('p1 + p2 = ${sum.toStringBetter()}');
  print('p1 - p2 = ${diff.toStringBetter()}');
  print('p1 * p2 = ${product.toStringBetter()}');
  
  // 微积分运算
  final derivative = p1.derivative();
  final integral = p1.integral();
  
  print('p1 的导数: ${derivative.toStringBetter()}');
  print('p1 的积分: ${integral.toStringBetter()}');
  
  // 除法
  final dividend = Polynomial([4, 3, 2, 1]); // x³ + 2x² + 3x + 4
  final divisor = Polynomial([1, 1]);        // x + 1
  final divisionResult = dividend.divide(divisor);
  
  print('被除数: ${dividend.toStringBetter()}');
  print('除数: ${divisor.toStringBetter()}');
  print('商: ${divisionResult[0].toStringBetter()}');
  print('余数: ${divisionResult[1].toStringBetter()}');
}
```

## 注意事项

1. **系数数组顺序**：系数数组按升序排列，`coefficients[i]` 是 xⁱ 的系数。
2. **规范化**：构造函数会自动规范化系数数组，去除尾部多余的零。
3. **除法边界**：当除数为零多项式时，会抛出 `ArgumentError`。
4. **浮点数精度**：由于使用 `double` 类型，可能存在浮点数精度问题。
5. **性能考虑**：乘法的时间复杂度为 O(n²)，除法的时间复杂度为 O(n²)。

## 实现细节

- 使用霍纳方法（Horner's method）进行多项式求值，提高效率和数值稳定性
- 多项式除法使用长除法算法
- 支持负系数和分数系数
- 提供了更好的字符串格式化扩展

## 相关数学概念

- **多项式次数**：多项式中最高次项的次数
- **多项式求值**：计算多项式在特定点的值
- **多项式除法**：返回商和余数，满足：被除数 = 除数 × 商 + 余数
- **多项式导数**：对多项式各项求导
- **多项式积分**：对多项式各项积分，常数项为0

这个多项式类适合用于教育、科学计算和需要多项式运算的各种应用场景。