# Option 包文档

## 概述

`option` 包提供了 Rust 风格的 `Option` 和 `Result` 类型实现，用于在 Go 中处理可选值和错误处理。这个包旨在提供更安全、更表达性的方式来处理可能存在或不存在的值，以及操作的成功或失败结果。

## 核心概念

### Option[T]
`Option[T]` 表示一个可能包含值 `T` 或不包含值的容器。它类似于 Go 中的指针，但更加类型安全和表达性。

### Result[T, E]
`Result[T, E]` 表示一个操作的结果，它要么包含成功的值 `T`，要么包含错误 `E`。它提供了比 Go 标准错误处理更丰富的组合操作。

## 快速开始

```go
import "your-module/option"

func main() {
    // 创建 Option
    someValue := option.Some(42)
    noneValue := option.None[int]()
    
    // 安全地获取值
    value := someValue.UnwrapOr(0)  // 如果为 None，返回 0
    
    // 链式操作
    result := option.Map(someValue, func(x int) string {
        return fmt.Sprintf("value: %d", x)
    })
}
```

## API 参考

### Option 类型

#### `type Option[T any] struct`

`Option[T]` 是一个泛型结构体，表示可能包含类型为 `T` 的值。

**字段：**
- `value T` - 存储的值（如果存在）
- `present bool` - 表示值是否存在

#### 构造函数

##### `func Some[T any](value T) Option[T]`
创建一个包含值的 `Option`。

**参数：**
- `value T` - 要包装的值

**返回值：**
- `Option[T]` - 包含值的 Option

**示例：**
```go
opt := option.Some("hello")
```

##### `func None[T any]() Option[T]`
创建一个不包含值的 `Option`。

**返回值：**
- `Option[T]` - 空的 Option

**示例：**
```go
opt := option.None[string]()
```

#### 基本操作方法

##### `(o Option[T]) IsSome() bool`
检查 Option 是否包含值。

**返回值：**
- `bool` - 如果包含值返回 `true`，否则返回 `false`

##### `(o Option[T]) IsNone() bool`
检查 Option 是否为空。

**返回值：**
- `bool` - 如果为空返回 `true`，否则返回 `false`

##### `(o Option[T]) Unwrap() T`
获取 Option 中的值。如果 Option 为空，会 panic。

**返回值：**
- `T` - Option 中的值

**Panics：**
- 当 Option 为空时 panic

##### `(o Option[T]) UnwrapOr(defaultValue T) T`
获取 Option 中的值，如果为空则返回默认值。

**参数：**
- `defaultValue T` - 当 Option 为空时返回的默认值

**返回值：**
- `T` - Option 中的值或默认值

##### `(o Option[T]) UnwrapOrElse(f func() T) T`
获取 Option 中的值，如果为空则通过函数计算返回值。

**参数：**
- `f func() T` - 当 Option 为空时调用的函数

**返回值：**
- `T` - Option 中的值或函数计算结果

##### `(o Option[T]) Expect(msg string) T`
获取 Option 中的值，如果为空则用指定消息 panic。

**参数：**
- `msg string` - panic 时显示的消息

**返回值：**
- `T` - Option 中的值

**Panics：**
- 当 Option 为空时，用指定消息 panic

#### 转换函数

##### `func Map[T, U any](opt Option[T], f func(T) U) Option[U]`
将 Option 中的值通过函数转换，返回新的 Option。

**类型参数：**
- `T` - 输入类型
- `U` - 输出类型

**参数：**
- `opt Option[T]` - 输入的 Option
- `f func(T) U` - 转换函数

**返回值：**
- `Option[U]` - 转换后的 Option

**示例：**
```go
opt := option.Some(42)
strOpt := option.Map(opt, func(x int) string {
    return fmt.Sprintf("%d", x)
})  // Some("42")
```

##### `func MapOr[T, U any](opt Option[T], defaultValue U, f func(T) U) U`
将 Option 中的值通过函数转换，如果为空则返回默认值。

**类型参数：**
- `T` - 输入类型
- `U` - 输出类型

**参数：**
- `opt Option[T]` - 输入的 Option
- `defaultValue U` - 当 Option 为空时返回的默认值
- `f func(T) U` - 转换函数

**返回值：**
- `U` - 转换后的值或默认值

##### `func MapOrElse[T, U any](opt Option[T], defaultFn func() U, f func(T) U) U`
将 Option 中的值通过函数转换，如果为空则通过函数计算返回值。

**类型参数：**
- `T` - 输入类型
- `U` - 输出类型

**参数：**
- `opt Option[T]` - 输入的 Option
- `defaultFn func() U` - 当 Option 为空时调用的函数
- `f func(T) U` - 转换函数

**返回值：**
- `U` - 转换后的值或函数计算结果

##### `func AndThen[T, U any](opt Option[T], f func(T) Option[U]) Option[U]`
链式调用返回 Option 的函数。

**类型参数：**
- `T` - 输入类型
- `U` - 输出类型

**参数：**
- `opt Option[T]` - 输入的 Option
- `f func(T) Option[U]` - 返回 Option 的函数

**返回值：**
- `Option[U]` - 函数返回的 Option

**示例：**
```go
opt := option.Some(21)
result := option.AndThen(opt, func(x int) option.Option[string] {
    if x > 20 {
        return option.Some("big")
    }
    return option.None[string]()
})  // Some("big")
```

##### `func Filter[T any](opt Option[T], predicate func(T) bool) Option[T]`
过滤 Option 中的值，如果值满足谓词则返回原 Option，否则返回 None。

**参数：**
- `opt Option[T]` - 输入的 Option
- `predicate func(T) bool` - 谓词函数

**返回值：**
- `Option[T]` - 过滤后的 Option

#### 组合函数

##### `func Or[T any](opt Option[T], other Option[T]) Option[T]`
返回第一个包含值的 Option，如果两个都为空则返回第二个。

**参数：**
- `opt Option[T]` - 第一个 Option
- `other Option[T]` - 第二个 Option

**返回值：**
- `Option[T]` - 结果 Option

**示例：**
```go
a := option.None[int]()
b := option.Some(2)
result := option.Or(a, b)  // Some(2)
```

##### `func OrElse[T any](opt Option[T], f func() Option[T]) Option[T]`
返回第一个包含值的 Option，如果为空则通过函数计算返回值。

**参数：**
- `opt Option[T]` - 输入的 Option
- `f func() Option[T]` - 当 Option 为空时调用的函数

**返回值：**
- `Option[T]` - 结果 Option

##### `func And[T any](opt Option[T], other Option[T]) Option[T]`
如果两个 Option 都包含值，返回第二个，否则返回 None。

**参数：**
- `opt Option[T]` - 第一个 Option
- `other Option[T]` - 第二个 Option

**返回值：**
- `Option[T]` - 结果 Option

#### 与其他类型转换

##### `func ToResult[T, E any](opt Option[T], err E) Result[T, E]`
将 Option 转换为 Result。Some 转换为 Ok，None 转换为 Err。

**类型参数：**
- `T` - 值类型
- `E` - 错误类型

**参数：**
- `opt Option[T]` - 输入的 Option
- `err E` - 当 Option 为空时使用的错误值

**返回值：**
- `Result[T, E]` - 转换后的 Result

### Result 类型

#### `type Result[T any, E any] struct`

`Result[T, E]` 是一个泛型结构体，表示可能成功（包含值 `T`）或失败（包含错误 `E`）的操作结果。

**字段：**
- `value T` - 成功的值（如果操作成功）
- `err E` - 错误（如果操作失败）
- `ok bool` - 表示操作是否成功

#### 构造函数

##### `func Ok[T any, E any](value T) Result[T, E]`
创建成功的 Result。

**参数：**
- `value T` - 成功的值

**返回值：**
- `Result[T, E]` - 成功的 Result

##### `func Err[T any, E any](error E) Result[T, E]`
创建失败的 Result。

**参数：**
- `error E` - 错误值

**返回值：**
- `Result[T, E]` - 失败的 Result

#### 基本操作方法

##### `(r Result[T, E]) IsOk() bool`
检查 Result 是否成功。

**返回值：**
- `bool` - 如果成功返回 `true`

##### `(r Result[T, E]) IsErr() bool`
检查 Result 是否失败。

**返回值：**
- `bool` - 如果失败返回 `true`

##### `(r Result[T, E]) Unwrap() T`
获取 Result 中的值。如果 Result 失败，会 panic。

**返回值：**
- `T` - Result 中的值

**Panics：**
- 当 Result 失败时 panic

##### `(r Result[T, E]) UnwrapErr() E`
获取 Result 中的错误。如果 Result 成功，会 panic。

**返回值：**
- `E` - Result 中的错误

**Panics：**
- 当 Result 成功时 panic

##### `(r Result[T, E]) UnwrapOr(defaultValue T) T`
获取 Result 中的值，如果失败则返回默认值。

**参数：**
- `defaultValue T` - 当 Result 失败时返回的默认值

**返回值：**
- `T` - Result 中的值或默认值

##### `(r Result[T, E]) UnwrapOrElse(f func(E) T) T`
获取 Result 中的值，如果失败则通过函数计算返回值。

**参数：**
- `f func(E) T` - 当 Result 失败时调用的函数

**返回值：**
- `T` - Result 中的值或函数计算结果

##### `(r Result[T, E]) Expect(msg string) T`
获取 Result 中的值，如果失败则用指定消息 panic。

**参数：**
- `msg string` - panic 时显示的消息

**返回值：**
- `T` - Result 中的值

**Panics：**
- 当 Result 失败时，用指定消息 panic

##### `(r Result[T, E]) ToOption() Option[T]`
将 Result 转换为 Option。成功转换为 Some，失败转换为 None。

**返回值：**
- `Option[T]` - 转换后的 Option

#### 转换函数

##### `func MapResult[T, U, E any](res Result[T, E], f func(T) U) Result[U, E]`
将成功的值通过函数转换，错误保持不变。

**类型参数：**
- `T` - 输入类型
- `U` - 输出类型
- `E` - 错误类型

**参数：**
- `res Result[T, E]` - 输入的 Result
- `f func(T) U` - 转换函数

**返回值：**
- `Result[U, E]` - 转换后的 Result

##### `func MapErr[T, E, F any](res Result[T, E], f func(E) F) Result[T, F]`
将错误通过函数转换，成功的值保持不变。

**类型参数：**
- `T` - 值类型
- `E` - 输入错误类型
- `F` - 输出错误类型

**参数：**
- `res Result[T, E]` - 输入的 Result
- `f func(E) F` - 错误转换函数

**返回值：**
- `Result[T, F]` - 转换后的 Result

##### `func AndThenResult[T, U, E any](res Result[T, E], f func(T) Result[U, E]) Result[U, E]`
链式调用返回 Result 的函数。

**类型参数：**
- `T` - 输入类型
- `U` - 输出类型
- `E` - 错误类型

**参数：**
- `res Result[T, E]` - 输入的 Result
- `f func(T) Result[U, E]` - 返回 Result 的函数

**返回值：**
- `Result[U, E]` - 函数返回的 Result

##### `func OrElseResult[T, E, F any](res Result[T, E], f func(E) Result[T, F]) Result[T, F]`
处理错误情况，尝试从错误中恢复。

**类型参数：**
- `T` - 值类型
- `E` - 输入错误类型
- `F` - 输出错误类型

**参数：**
- `res Result[T, E]` - 输入的 Result
- `f func(E) Result[T, F]` - 错误处理函数

**返回值：**
- `Result[T, F]` - 处理后的 Result

### 工具函数

#### `func MatchOption[T any, U any](opt Option[T], someFunc func(T) U, noneFunc func() U) U`
模式匹配 Option，根据是否有值执行不同的函数。

**类型参数：**
- `T` - Option 的值类型
- `U` - 返回值类型

**参数：**
- `opt Option[T]` - 要匹配的 Option
- `someFunc func(T) U` - 当 Option 有值时执行的函数
- `noneFunc func() U` - 当 Option 为空时执行的函数

**返回值：**
- `U` - 匹配结果

**示例：**
```go
opt := option.Some(42)
result := option.MatchOption(opt,
    func(x int) string { return fmt.Sprintf("Got: %d", x) },
    func() string { return "Nothing" },
)  // "Got: 42"
```

#### `func MatchResult[T any, E any, U any](res Result[T, E], okFunc func(T) U, errFunc func(E) U) U`
模式匹配 Result，根据成功或失败执行不同的函数。

**类型参数：**
- `T` - 成功的值类型
- `E` - 错误类型
- `U` - 返回值类型

**参数：**
- `res Result[T, E]` - 要匹配的 Result
- `okFunc func(T) U` - 当 Result 成功时执行的函数
- `errFunc func(E) U` - 当 Result 失败时执行的函数

**返回值：**
- `U` - 匹配结果

#### `func Zip[T, U any](a Option[T], b Option[U]) Option[struct{First T; Second U}]`
将两个 Option 合并为一个包含元组的 Option。

**类型参数：**
- `T` - 第一个 Option 的类型
- `U` - 第二个 Option 的类型

**参数：**
- `a Option[T]` - 第一个 Option
- `b Option[U]` - 第二个 Option

**返回值：**
- `Option[struct{First T; Second U}]` - 合并后的 Option

**示例：**
```go
a := option.Some(1)
b := option.Some("hello")
zipped := option.Zip(a, b)  // Some({1, "hello"})
```

#### `func Unzip[T, U any](opt Option[struct{First T; Second U}]) (Option[T], Option[U])`
将包含元组的 Option 分解为两个 Option。

**类型参数：**
- `T` - 第一个值的类型
- `U` - 第二个值的类型

**参数：**
- `opt Option[struct{First T; Second U}]` - 要分解的 Option

**返回值：**
- `(Option[T], Option[U])` - 分解后的两个 Option

#### `func FromResult[T, E any](res Result[T, E]) Option[T]`
将 Result 转换为 Option，忽略错误。

**类型参数：**
- `T` - 值类型
- `E` - 错误类型

**参数：**
- `res Result[T, E]` - 要转换的 Result

**返回值：**
- `Option[T]` - 转换后的 Option

#### `func FromPtr[T any](ptr *T) Option[T]`
从指针创建 Option。如果指针不为 nil，返回 Some，否则返回 None。

**类型参数：**
- `T` - 指针指向的类型

**参数：**
- `ptr *T` - 指针

**返回值：**
- `Option[T]` - 转换后的 Option

#### `func ToPtr[T any](opt Option[T]) *T`
将 Option 转换为指针。如果 Option 有值，返回指向该值的指针，否则返回 nil。

**类型参数：**
- `T` - Option 的值类型

**参数：**
- `opt Option[T]` - 要转换的 Option

**返回值：**
- `*T` - 指针或 nil

#### `func Flatten[T any](opt Option[Option[T]]) Option[T]`
将嵌套的 Option 展平。

**参数：**
- `opt Option[Option[T]]` - 嵌套的 Option

**返回值：**
- `Option[T]` - 展平后的 Option

## 最佳实践

### 错误处理

```go
// 传统 Go 错误处理
func divide(a, b int) (int, error) {
    if b == 0 {
        return 0, errors.New("division by zero")
    }
    return a / b, nil
}

// 使用 Result
func divideResult(a, b int) option.Result[int, string] {
    if b == 0 {
        return option.Err[int, string]("division by zero")
    }
    return option.Ok[int, string](a / b)
}

// 链式处理
result := option.AndThenResult(
    divideResult(10, 2),
    func(x int) option.Result[string, string] {
        return option.Ok[string, string](fmt.Sprintf("Result: %d", x))
    },
)
```

### 安全地处理可选值

```go
type User struct {
    Name  string
    Email *string  // 可选的字段
}

func getUserEmail(user User) option.Option[string] {
    return option.FromPtr(user.Email)
}

// 使用链式操作
emailDisplay := option.Map(
    getUserEmail(user),
    func(email string) string {
        return fmt.Sprintf("Email: %s", email)
    },
).UnwrapOr("No email provided")
```

### 组合多个可能失败的操作

```go
func processData(path string) option.Result[string, error] {
    return option.AndThenResult(
        readFile(path),
        func(content string) option.Result[string, error] {
            return option.AndThenResult(
                parseJSON(content),
                func(data Data) option.Result[string, error] {
                    return validateAndProcess(data)
                },
            )
        },
    )
}
```

## 性能考虑

1. **零成本抽象**：大多数操作都是内联的，编译器可以优化
2. **无运行时开销**：与直接使用指针和错误相比，几乎没有额外开销
3. **内存效率**：结构体大小固定，无动态分配（除非值本身需要）

## 与标准库的互操作

```go
// 从标准错误创建 Result
func FromStdError[T any](value T, err error) option.Result[T, error] {
    if err != nil {
        return option.Err[T, error](err)
    }
    return option.Ok[T, error](value)
}

// 转换为标准错误
func (r Result[T, error]) ToStdError() (T, error) {
    if r.ok {
        return r.value, nil
    }
    var zero T
    return zero, r.err
}
```

## 注意事项

1. **泛型限制**：Go 1.18+ 的泛型有一些限制，不能用于所有场景
2. **接口方法**：接口中的方法不能有类型参数，因此使用独立函数设计
3. **nil 安全**：Option 和 Result 都提供了比裸指针更好的 nil 安全性

## 贡献

欢迎提交 Issue 和 Pull Request 来改进这个包。