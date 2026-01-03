# Future包

## 概述

Future 包提供了一个类型安全的异步编程模型，支持单返回值、双返回值和三返回值的异步任务。它封装了 Goroutine 和 Channel，提供了类似于其他语言中 Future/Promise 模式的功能。

## 特性

- ✅ 类型安全：使用 Go 泛型，编译时类型检查
- ✅ 多返回值：支持 1-3 个返回值的异步任务
- ✅ 超时控制：所有操作均可设置超时
- ✅ 取消支持：通过 Context 支持任务取消
- ✅ 错误处理：集成错误返回机制
- ✅ 链式调用：支持 Then、Map 等组合操作
- ✅ 组合操作：支持 All、Any 等多任务组合

## 快速开始

### 基础用法

```go
package main

import (
    "fmt"
    "time"
    "yourmodule/future"
)

func main() {
    // 创建单返回值 Future
    f := future.New(func() string {
        time.Sleep(1 * time.Second)
        return "Hello, Future!"
    })
    
    // 阻塞获取结果
    result := f.Get()
    fmt.Println(result) // Hello, Future!
    
    // 带超时获取
    if val, ok := f.GetWithTimeout(500 * time.Millisecond); ok {
        fmt.Println("Got:", val)
    } else {
        fmt.Println("Timeout!")
    }
}
```

### 双返回值示例

```go
// 处理两个返回值的任务
f := future.New2(func() (int, string) {
    time.Sleep(2 * time.Second)
    return 42, "answer"
})

a, b := f.Get()
fmt.Printf("%d: %s\n", a, b) // 42: answer
```

## API 参考

### 接口定义

#### Future[T]
单返回值 Future 接口。

| 方法 | 签名 | 说明 |
|------|------|------|
| `Get()` | `() T` | 阻塞直到获取结果 |
| `GetWithTimeout()` | `(time.Duration) (T, bool)` | 带超时获取结果 |
| `Wait()` | `(...time.Duration) bool` | 等待任务完成 |
| `IsDone()` | `() bool` | 检查是否完成 |
| `Cancel()` | `()` | 取消任务 |
| `Error()` | `() error` | 获取错误信息 |

#### Future2[T1, T2]
双返回值 Future 接口。

| 方法 | 签名 | 说明 |
|------|------|------|
| `Get()` | `() (T1, T2)` | 阻塞直到获取结果 |
| `GetWithTimeout()` | `(time.Duration) (T1, T2, bool)` | 带超时获取结果 |

#### Future3[T1, T2, T3]
三返回值 Future 接口。

| 方法 | 签名 | 说明 |
|------|------|------|
| `Get()` | `() (T1, T2, T3)` | 阻塞直到获取结果 |
| `GetWithTimeout()` | `(time.Duration) (T1, T2, T3, bool)` | 带超时获取结果 |

### 构造函数

#### 单返回值
| 函数 | 签名 | 说明 |
|------|------|------|
| `New[T]` | `(func() T) Future[T]` | 创建 Future |
| `NewWithContext[T]` | `(context.Context, func() T) Future[T]` | 带 Context 创建 |
| `NewE[T]` | `(func() (T, error)) Future[T]` | 带错误返回 |
| `NewWithContextE[T]` | `(context.Context, func() (T, error)) Future[T]` | 带 Context 和错误 |

#### 双返回值
| 函数 | 签名 | 说明 |
|------|------|------|
| `New2[T1, T2]` | `(func() (T1, T2)) Future2[T1, T2]` | 创建双返回值 Future |
| `New2WithContext[T1, T2]` | `(context.Context, func() (T1, T2)) Future2[T1, T2]` | 带 Context 创建 |
| `New2E[T1, T2]` | `(func() (T1, T2, error)) Future2[T1, T2]` | 带错误返回 |
| `New2WithContextE[T1, T2]` | `(context.Context, func() (T1, T2, error)) Future2[T1, T2]` | 带 Context 和错误 |

#### 三返回值
| 函数 | 签名 | 说明 |
|------|------|------|
| `New3[T1, T2, T3]` | `(func() (T1, T2, T3)) Future3[T1, T2, T3]` | 创建三返回值 Future |
| `New3WithContext[T1, T2, T3]` | `(context.Context, func() (T1, T2, T3)) Future3[T1, T2, T3]` | 带 Context 创建 |

### 快捷函数

| 函数 | 等价于 | 说明 |
|------|--------|------|
| `Async[T]` | `New[T]` | 单返回值快捷方式 |
| `AsyncE[T]` | `NewE[T]` | 带错误快捷方式 |
| `Async2[T1, T2]` | `New2[T1, T2]` | 双返回值快捷方式 |
| `Async2E[T1, T2]` | `New2E[T1, T2]` | 双返回值带错误快捷方式 |
| `Async3[T1, T2, T3]` | `New3[T1, T2, T3]` | 三返回值快捷方式 |

### 组合操作

| 函数 | 签名 | 说明 |
|------|------|------|
| `Then[T1, T2]` | `(Future[T1], func(T1) T2) Future[T2]` | 链式调用 |
| `Then2[T1, T2, R]` | `(Future2[T1, T2], func(T1, T2) R) Future[R]` | 双返回值链式调用 |
| `All[T]` | `(...Future[T]) Future[[]T]` | 等待所有 Future |
| `Any[T]` | `(...Future[T]) Future[T]` | 等待任意 Future |
| `Map[T, R]` | `(Future[T], func(T) R) Future[R]` | 结果转换 |

## 使用示例

### 示例 1：基础异步任务

```go
func main() {
    // 创建异步任务
    task := future.New(func() int {
        time.Sleep(2 * time.Second)
        return computeExpensiveValue()
    })
    
    // 继续其他工作...
    doOtherWork()
    
    // 获取结果（如果未完成会阻塞）
    result := task.Get()
    fmt.Println("Result:", result)
}
```

### 示例 2：错误处理和超时

```go
func fetchData(url string) future.Future[string] {
    return future.NewE(func() (string, error) {
        resp, err := http.Get(url)
        if err != nil {
            return "", err
        }
        defer resp.Body.Close()
        
        data, err := io.ReadAll(resp.Body)
        return string(data), err
    })
}

func main() {
    f := fetchData("https://api.example.com/data")
    
    // 带超时获取
    if data, ok := f.GetWithTimeout(5 * time.Second); ok {
        fmt.Println("Data:", data)
    } else {
        fmt.Println("Timeout or error:", f.Error())
    }
}
```

### 示例 3：链式调用

```go
func process() {
    // 异步获取用户ID
    userIdFuture := future.New(func() int {
        return getUserID()
    })
    
    // 链式调用：获取用户ID后获取用户信息
    userFuture := future.Then(userIdFuture, func(id int) User {
        return getUserInfo(id)
    })
    
    // 再次链式调用：处理用户信息
    resultFuture := future.Then(userFuture, func(user User) string {
        return fmt.Sprintf("User: %s, Age: %d", user.Name, user.Age)
    })
    
    fmt.Println(resultFuture.Get())
}
```

### 示例 4：并行任务组合

```go
func main() {
    // 创建多个并行任务
    futures := []future.Future[int]{
        future.New(func() int { return fetchDataFromSource1() }),
        future.New(func() int { return fetchDataFromSource2() }),
        future.New(func() int { return fetchDataFromSource3() }),
    }
    
    // 等待所有任务完成
    allFuture := future.All(futures...)
    results := allFuture.Get()
    
    // 计算总和
    sum := 0
    for _, r := range results {
        sum += r
    }
    fmt.Println("Total:", sum)
}
```

### 示例 5：使用 Context 取消

```go
func main() {
    ctx, cancel := context.WithCancel(context.Background())
    
    // 创建可取消的 Future
    f := future.NewWithContext(ctx, func() string {
        time.Sleep(10 * time.Second) // 长时间任务
        return "result"
    })
    
    // 3秒后取消任务
    go func() {
        time.Sleep(3 * time.Second)
        cancel()
    }()
    
    // 尝试获取结果
    if val, ok := f.GetWithTimeout(5 * time.Second); ok {
        fmt.Println("Got:", val)
    } else {
        fmt.Println("Cancelled or timeout")
    }
}
```

## 性能考虑

1. **内存开销**：每个 Future 创建都会产生一个 Goroutine 和一个 Channel
2. **Goroutine 泄漏**：确保调用 `Get()` 或使用超时避免 Goroutine 泄漏
3. **取消及时性**：使用 Context 可以及时取消后台任务
4. **批量操作**：对于大量小任务，考虑使用 `future.All` 而非单独创建

## 最佳实践

### 1. 总是处理超时
```go
// 好：明确处理超时
if result, ok := f.GetWithTimeout(time.Second); ok {
    process(result)
} else {
    handleTimeout()
}

// 不好：可能永久阻塞
result := f.Get() // 如果任务永不完成，这里会永久阻塞
```

### 2. 使用错误感知的构造函数
```go
// 好：使用 NewE 处理错误
f := future.NewE(func() (Data, error) {
    return apiCallThatMightFail()
})

// 不好：错误被忽略
f := future.New(func() Data {
    data, _ := apiCallThatMightFail() // 错误被忽略！
    return data
})
```

### 3. 合理使用链式调用
```go
// 好：清晰的链式调用
future.New(getUserID).
    Then(getUserInfo).
    Then(processUser).
    Then(storeResult)

// 不好：过度嵌套
future.New(func() string {
    id := getUserID()
    user := getUserInfo(id)
    processed := processUser(user)
    return storeResult(processed)
})
```

### 4. 及时清理资源
```go
func processRequest() {
    ctx, cancel := context.WithTimeout(context.Background(), 5*time.Second)
    defer cancel() // 确保 Context 被取消
    
    f := future.NewWithContext(ctx, expensiveOperation)
    // ...
}
```

## 限制和注意事项

1. **泛型限制**：Go 泛型不支持方法类型参数，因此接口方法固定
2. **零值处理**：超时或取消时返回类型的零值
3. **Once Only**：每个 Future 的结果只能获取一次
4. **线程安全**：Future 实例是线程安全的，但结果只能读取一次

## 扩展建议

如需扩展此包，可考虑：

1. **添加回调支持**：`OnSuccess`, `OnFailure` 回调
2. **支持更多返回值**：`Future4`, `Future5` 等
3. **进度报告**：添加进度监控接口
4. **结果缓存**：支持结果缓存和重用
5. **批量取消**：批量取消多个 Future

**版本**: 1.0.0  
**要求**: Go 1.18+  