# ARC包

## 概述

`arc` 包提供了一个原子引用计数智能指针实现，类似于 Rust 的 `Arc<T>`。它允许多个所有者同时持有对同一数据的引用，并在最后一个引用被释放时自动清理内存。

## 主要类型

### Arc[T any]
原子引用计数智能指针。

```go
type Arc[T any] struct {
    // 未导出字段
}
```

### Weak[T any]
弱引用，不会增加引用计数，可以升级为强引用。

```go
type Weak[T any] struct {
    // 未导出字段
}
```

### Ref[T any]
只读引用包装器。

```go
type Ref[T any] struct {
    // 未导出字段
}
```

## 核心函数

### NewArc
```go
func NewArc[T any](value T) *Arc[T]
```
创建新的 `Arc` 实例，初始引用计数为 1。

**参数：**
- `value`: 要包装的数据

**返回值：**
- 新的 `Arc` 实例

**示例：**
```go
arc := NewArc(42)
defer arc.Drop()
```

### Clone
```go
func (a *Arc[T]) Clone() *Arc[T]
```
创建 `Arc` 的克隆，原子地增加引用计数。

**返回值：**
- 新的 `Arc` 实例（共享相同数据）

**注意：** 克隆后必须调用 `Drop()` 释放引用。

### Deref
```go
func (a *Arc[T]) Deref() *T
```
获取内部数据的引用（类似 Rust 的 `Deref` trait）。

**返回值：**
- 指向内部数据的指针，如果 `Arc` 为空则返回 `nil`

**示例：**
```go
data := arc.Deref()
if data != nil {
    fmt.Println(*data)
}
```

### Drop
```go
func (a *Arc[T]) Drop()
```
减少引用计数，当计数为 0 时释放内存。应该在使用完 `Arc` 后调用。

### StrongCount
```go
func (a *Arc[T]) StrongCount() int64
```
获取当前的强引用计数。

**返回值：**
- 引用计数值，如果 `Arc` 为空则返回 0

### GetMut
```go
func (a *Arc[T]) GetMut() *T
```
尝试获取可变引用。仅当引用计数为 1（没有其他引用）时成功。

**返回值：**
- 可变引用指针，如果不满足条件则返回 `nil`

### TryUnwrap
```go
func (a *Arc[T]) TryUnwrap() (T, bool)
```
尝试获取所有权。如果引用计数为 1，则返回内部数据并释放 `Arc`。

**返回值：**
- `(data, true)` 如果成功获取所有权
- `(zero, false)` 如果失败

## 弱引用操作

### Downgrade
```go
func (a *Arc[T]) Downgrade() *Weak[T]
```
从 `Arc` 创建弱引用。弱引用不会阻止数据被释放。

### Upgrade
```go
func (w *Weak[T]) Upgrade() *Arc[T]
```
尝试将弱引用升级为强引用。如果数据仍然存在，则创建新的 `Arc`。

## 线程安全访问

### With
```go
func (a *Arc[T]) With(fn func(*T)) bool
```
提供线程安全的访问方式。在执行回调函数期间保持引用。

**参数：**
- `fn`: 回调函数，接收数据指针

**返回值：**
- `true` 如果成功执行

### MapArc
```go
func MapArc[T, U any](a *Arc[T], fn func(T) U) *Arc[U]
```
应用函数到 `Arc` 中的数据并返回新的 `Arc`。

**参数：**
- `a`: 输入 `Arc`
- `fn`: 转换函数

**返回值：**
- 包含转换结果的新的 `Arc`

## 实用函数

### ArcSlice
```go
func ArcSlice[T any](values ...T) []*Arc[T]
```
从多个值创建 `Arc` 切片。

### MergeArcs
```go
func MergeArcs[T any](arcs ...*Arc[T]) *Arc[[]T]
```
合并多个 `Arc` 到一个包含切片的 `Arc`。

### Swap
```go
func (a *Arc[T]) Swap(other *Arc[T])
```
交换两个 `Arc` 的内容。

### Reset
```go
func (a *Arc[T]) Reset(value T)
```
重置 `Arc`，释放当前引用并设置新值。

### AsRef
```go
func (a *Arc[T]) AsRef() *Ref[T]
```
创建只读引用包装器。

## 高级功能

### MemoryBarrier
```go
func (a *Arc[T]) MemoryBarrier()
```
创建内存屏障，确保内存操作的顺序性。

### CompareAndSwap
```go
func (a *Arc[T]) CompareAndSwap(oldValue, newValue T) bool
```
比较并交换 `Arc` 的内容（仅当引用计数为 1 时）。

## Ref 类型方法

### Ref.Deref
```go
func (r *Ref[T]) Deref() *T
```
获取底层数据的引用。

### Ref.Release
```go
func (r *Ref[T]) Release()
```
释放只读引用。

## 测试辅助

### IsNil
```go
func (a *Arc[T]) IsNil() bool
```
检查 `Arc` 是否为空。

### UnsafeRawPtr
```go
func (a *Arc[T]) UnsafeRawPtr() unsafe.Pointer
```
获取底层指针（仅用于调试和测试）。

## 使用示例

### 基本用法
```go
// 创建 Arc
arc1 := NewArc("hello")
defer arc1.Drop()

// 克隆
arc2 := arc1.Clone()
defer arc2.Drop()

// 访问数据
data := arc1.Deref()
fmt.Println(*data)

// 获取引用计数
count := arc1.StrongCount()
fmt.Println("引用计数:", count)
```

### 弱引用示例
```go
arc := NewArc(100)
weak := arc.Downgrade()

// 升级弱引用
if upgraded := weak.Upgrade(); upgraded != nil {
    defer upgraded.Drop()
    fmt.Println(*upgraded.Deref())
}
```

### 线程安全访问
```go
arc := NewArc(42)
defer arc.Drop()

arc.With(func(data *int) {
    // 安全地访问数据
    *data = *data + 1
})
```

## 注意事项

1. **内存管理**：`Clone()` 后必须调用 `Drop()`，否则会导致内存泄漏
2. **并发安全**：所有操作都是原子性的，可安全用于并发环境
3. **可变性**：`GetMut()` 仅在唯一引用时可用，否则返回 `nil`
4. **弱引用**：弱引用不会阻止内存释放，使用前必须先调用 `Upgrade()`
5. **性能**：引用计数操作使用原子操作，比普通指针有额外开销

## 内部实现

`Arc` 内部使用 `arcInternal` 结构体存储数据和引用计数：
```go
type arcInternal[T any] struct {
    data T
    ref  int64 // 原子计数器
}
```

所有引用计数操作都使用 `sync/atomic` 包保证原子性。

## 兼容性

- 需要 Go 1.18+（支持泛型）
- 使用 `unsafe.Pointer` 实现，跨平台兼容
- 无外部依赖
