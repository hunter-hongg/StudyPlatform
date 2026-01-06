# 密码存取模块文档

## 概述

该模块提供了一个安全的密码存取实现，用于将数字以加密形式存储在文件中。使用自定义的字符映射表进行加密/解密操作。

## 主要功能

- 将数字加密后存储到文件
- 从加密文件中读取并解密数字
- 对存储的数字进行加、减操作
- 检查数字是否满足特定条件

## 核心结构体

### `FilePassword`

```rust
pub struct FilePassword {
    file_name: String,
    password: String,
}
```

**字段说明:**
- `file_name`: 存储密码的文件路径
- `password`: 加密密钥（字符映射表）

## 构造函数

### `new()`
```rust
pub fn new(filename: &str, password: &str) -> Self
```
创建 `FilePassword` 实例，自动验证密码是否包含重复字符。

### `new_with_default()`
```rust
pub fn new_with_default(
    filename: &str, 
    password: &str, 
    default_value: i32
) -> Result<Self, crate::error::SpError>
```
创建实例，如果文件不存在则创建并写入默认值。

## 密码验证规则

- 密码不能包含重复字符
- 如果密码包含重复字符，将使用默认密码 `"1324096857"`
- 密码长度应与原始字符集（`"0123456789"`）相同

## 核心方法

### 读取操作

#### `read_password()`
```rust
pub fn read_password(&self) -> Result<String, SpError>
```
读取文件中的加密字符串。

#### `read_real()`
```rust
pub fn read_real(&self) -> Result<String, SpError>
```
读取并解密文件内容，返回原始数字字符串。

#### `read_str()`
```rust
pub fn read_str(&self) -> Result<String, SpError>
```
读取并验证存储的数字，返回字符串格式。

#### `read_int()`
```rust
pub fn read_int(&self) -> Result<i32, SpError>
```
读取并解析存储的数字为整数。

### 写入操作

#### `write()`
```rust
pub fn write(&self, new_num: i32) -> Result<(), SpError>
```
将数字加密后写入文件。

#### `add()`
```rust
pub fn add(&self, num: i32) -> Result<(), SpError>
```
读取当前值，加上指定数值后写回。

### 数学运算

#### `add_num()`
```rust
pub fn add_num(&self, a: i32) -> Result<(), SpError>
```
增加存储的数字（仅正数生效）。

#### `minus_num()`
```rust
pub fn minus_num(&self, a: i32) -> Result<(), SpError>
```
减少存储的数字（仅正数生效）。

#### `minus_num_if()`
```rust
pub fn minus_num_if(&self, a: i32) -> Result<(), SpError>
```
安全减少，不足时减至0。

### 条件检查

#### `high()`
```rust
pub fn high(&self, a: i32) -> Result<bool, SpError>
```
检查存储的数字是否大于等于指定值。

#### `can_minus()`
```rust
pub fn can_minus(&self, a: i32) -> Result<bool, SpError>
```
检查是否足够减去指定值，如果足够则执行减法操作。

### 安全版本方法

#### `read_str_safe()`
```rust
pub fn read_str_safe(&self) -> String
```
读取字符串，出错时返回空字符串。

#### `read_int_safe()`
```rust
pub fn read_int_safe(&self) -> i32
```
读取整数，出错时返回0。

#### `can_minus_safe()`
```rust
pub fn can_minus_safe(&self, an: i32) -> bool
```
安全版本的 `can_minus`，出错时返回 `false`。

## 加密原理

### 字符映射表
- 原始字符集: `"0123456789"`
- 加密字符集: 用户提供的密码（不含重复字符）

### 加密过程
将数字字符串中的每个字符根据映射表进行替换：
```
原始: "123" → 加密: password[1] + password[2] + password[3]
```

### 解密过程
将加密字符串中的每个字符反向映射回原始字符集。

## 错误处理

模块使用 `SpError` 类型处理错误，包括：
- 文件I/O错误
- 字符转换错误
- 数字解析错误

## 使用示例

```rust
// 创建实例
let fp = FilePassword::new("data.txt", "9876543210");

// 写入初始值
fp.write(100)?;

// 读取值
let value = fp.read_int()?;  // 100

// 增加数值
fp.add_num(50)?;  // 现在为150

// 条件检查
if fp.high(100)? {
    fp.minus_num(100)?;  // 减去100
}

// 安全使用
let safe_value = fp.read_int_safe();  // 出错时返回0
```

## 注意事项

1. 密码长度应为10个字符且不含重复
2. 文件不存在时会自动创建
3. 负数操作会被忽略
4. 建议使用安全版本的方法处理潜在错误

## 测试用例

模块包含完整的测试套件，验证：
- 基本读写操作
- 数学运算
- 条件检查
- 错误处理

## 依赖

- `std::collections::HashSet` - 用于密码重复检查
- `std::fs` - 文件系统操作
- `std::io::Write` - 文件写入功能
- `std::path::Path` - 路径处理