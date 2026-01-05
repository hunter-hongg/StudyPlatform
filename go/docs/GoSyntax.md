# Go语言高级语法

## 1. 并发编程模型

### 1.1 Goroutines（协程）
```go
// 基本goroutine
go func() {
    fmt.Println("异步执行")
}()

// 带参数的goroutine
for i := 0; i < 5; i++ {
    go func(n int) {
        fmt.Printf("Goroutine %d\n", n)
    }(i)
}

// 等待goroutine完成
var wg sync.WaitGroup
for i := 0; i < 3; i++ {
    wg.Add(1)
    go func(id int) {
        defer wg.Done()
        time.Sleep(time.Duration(id) * time.Second)
        fmt.Printf("任务 %d 完成\n", id)
    }(i)
}
wg.Wait()
```

### 1.2 Channels（通道）
```go
// 无缓冲通道（同步）
ch := make(chan int)
go func() {
    ch <- 42 // 发送阻塞直到接收
}()

value := <-ch // 接收阻塞直到发送
fmt.Println(value)

// 缓冲通道（异步）
bufCh := make(chan string, 2)
bufCh <- "消息1"
bufCh <- "消息2"
fmt.Println(<-bufCh) // 消息1
fmt.Println(<-bufCh) // 消息2

// 关闭通道与range
func producer(ch chan<- int) {
    for i := 0; i < 5; i++ {
        ch <- i * i
    }
    close(ch) // 关闭通道
}

func consumer(ch <-chan int) {
    for val := range ch { // 自动检测关闭
        fmt.Println("收到:", val)
    }
}

// 双向通道与单向通道转换
var ch chan int // 双向
var sendCh chan<- int = ch // 只发送
var recvCh <-chan int = ch // 只接收
```

### 1.3 Select语句
```go
// 基本select
select {
case msg := <-ch1:
    fmt.Println("从ch1收到:", msg)
case ch2 <- "data":
    fmt.Println("发送到ch2")
case <-time.After(1 * time.Second):
    fmt.Println("超时")
default:
    fmt.Println("无就绪通道")
}

// 多路复用模式
func fanIn(input1, input2 <-chan string) <-chan string {
    c := make(chan string)
    go func() {
        for {
            select {
            case s := <-input1:
                c <- s
            case s := <-input2:
                c <- s
            }
        }
    }()
    return c
}

// 非阻塞检查
select {
case val := <-ch:
    fmt.Println("收到:", val)
default:
    fmt.Println("无数据")
}

// 循环select
for {
    select {
    case data := <-dataChan:
        process(data)
    case <-stopChan:
        return
    case <-ticker.C:
        doHeartbeat()
    }
}
```

### 1.4 Context上下文
```go
// 基础Context
ctx, cancel := context.WithCancel(context.Background())
defer cancel() // 确保资源释放

go worker(ctx)

// 超时控制
timeoutCtx, cancel := context.WithTimeout(context.Background(), 5*time.Second)
defer cancel()

select {
case <-timeoutCtx.Done():
    fmt.Println("超时:", timeoutCtx.Err())
case result := <-doWork():
    fmt.Println("结果:", result)
}

// 值传递
ctx := context.WithValue(context.Background(), "userID", 123)
if userID, ok := ctx.Value("userID").(int); ok {
    fmt.Println("用户ID:", userID)
}

// 链式Context
func middleware(ctx context.Context) context.Context {
    return context.WithValue(ctx, "requestID", uuid.New())
}

func handler(ctx context.Context) {
    requestID := ctx.Value("requestID").(string)
    fmt.Println("请求ID:", requestID)
}
```

## 2. 反射（Reflection）

### 2.1 类型和值反射
```go
import "reflect"

// 类型反射
var x float64 = 3.4
fmt.Println("类型:", reflect.TypeOf(x))   // float64
fmt.Println("种类:", reflect.TypeOf(x).Kind()) // float64

// 值反射
v := reflect.ValueOf(x)
fmt.Println("值:", v.Float()) // 3.4
fmt.Println("种类:", v.Kind())   // reflect.Float64
fmt.Println("类型:", v.Type())   // float64

// 修改值（必须使用指针）
var y float64 = 1.2
pv := reflect.ValueOf(&y).Elem() // 获取可寻址的值
pv.SetFloat(2.4)
fmt.Println("修改后:", y) // 2.4
```

### 2.2 结构体反射
```go
type User struct {
    Name  string `json:"name" db:"user_name"`
    Age   int    `json:"age" db:"user_age"`
    Email string `json:"email,omitempty"`
}

func inspectStruct(s interface{}) {
    t := reflect.TypeOf(s)
    v := reflect.ValueOf(s)
    
    if t.Kind() == reflect.Ptr {
        t = t.Elem()
        v = v.Elem()
    }
    
    fmt.Printf("结构体: %s\n", t.Name())
    
    for i := 0; i < t.NumField(); i++ {
        field := t.Field(i)
        value := v.Field(i)
        
        fmt.Printf("  字段: %s\n", field.Name)
        fmt.Printf("    类型: %v\n", field.Type)
        fmt.Printf("    标签: %v\n", field.Tag)
        fmt.Printf("    值: %v\n", value.Interface())
        
        // 解析标签
        if jsonTag := field.Tag.Get("json"); jsonTag != "" {
            fmt.Printf("    JSON标签: %s\n", jsonTag)
        }
    }
}

// 动态调用方法
method := reflect.ValueOf(user).MethodByName("GetName")
if method.IsValid() {
    result := method.Call(nil)
    fmt.Println("方法结果:", result[0])
}
```

### 2.3 切片和Map反射
```go
// 切片反射
slice := []int{1, 2, 3}
sv := reflect.ValueOf(slice)
fmt.Println("切片长度:", sv.Len())        // 3
fmt.Println("切片容量:", sv.Cap())        // 3
fmt.Println("索引0:", sv.Index(0).Int()) // 1

// 创建新切片
newSlice := reflect.MakeSlice(reflect.TypeOf(slice), 0, 5)
newSlice = reflect.Append(newSlice, reflect.ValueOf(4))

// Map反射
m := map[string]int{"a": 1, "b": 2}
mv := reflect.ValueOf(m)

// 遍历Map
iter := mv.MapRange()
for iter.Next() {
    key := iter.Key().String()
    value := iter.Value().Int()
    fmt.Printf("%s: %d\n", key, value)
}

// 动态创建Map
mapType := reflect.MapOf(
    reflect.TypeOf(""),    // key类型
    reflect.TypeOf(0),     // value类型
)
newMap := reflect.MakeMap(mapType)
newMap.SetMapIndex(reflect.ValueOf("key"), reflect.ValueOf(42))
```

## 3. 接口高级用法

### 3.1 空接口和类型断言
```go
// 空接口接收任意类型
func process(v interface{}) {
    // 类型断言
    switch val := v.(type) {
    case int:
        fmt.Printf("整数: %d\n", val*2)
    case string:
        fmt.Printf("字符串: %s\n", strings.ToUpper(val))
    case []int:
        fmt.Printf("切片长度: %d\n", len(val))
    default:
        fmt.Printf("未知类型: %T\n", val)
    }
}

// 多重类型断言
var i interface{} = 42

if s, ok := i.(string); ok {
    fmt.Println("字符串:", s)
} else if n, ok := i.(int); ok {
    fmt.Println("整数:", n)
}

// 接口类型断言
type Writer interface {
    Write([]byte) (int, error)
}

var w io.Writer = os.Stdout
if file, ok := w.(*os.File); ok {
    fmt.Println("文件描述符:", file.Fd())
}
```

### 3.2 接口组合与嵌入
```go
type Reader interface {
    Read(p []byte) (n int, err error)
}

type Closer interface {
    Close() error
}

// 接口组合
type ReadCloser interface {
    Reader
    Closer
}

// 结构体嵌入接口
type BufferedReadCloser struct {
    io.Reader  // 嵌入接口
    buffer     []byte
}

func (b *BufferedReadCloser) Read(p []byte) (int, error) {
    // 可以直接使用嵌入的Reader
    return b.Reader.Read(p)
}

// 接口嵌入结构体
type AdvancedWriter struct {
    io.Writer
    Metrics struct {
        BytesWritten int64
        Writes       int
    }
}

func (aw *AdvancedWriter) Write(p []byte) (int, error) {
    n, err := aw.Writer.Write(p)
    aw.Metrics.BytesWritten += int64(n)
    aw.Metrics.Writes++
    return n, err
}
```

## 4. 泛型（Go 1.18+）

### 4.1 泛型函数和类型
```go
// 泛型函数
func Sum[T int | float64](nums []T) T {
    var total T
    for _, n := range nums {
        total += n
    }
    return total
}

// 泛型结构体
type Stack[T any] struct {
    items []T
}

func (s *Stack[T]) Push(item T) {
    s.items = append(s.items, item)
}

func (s *Stack[T]) Pop() (T, bool) {
    if len(s.items) == 0 {
        var zero T
        return zero, false
    }
    item := s.items[len(s.items)-1]
    s.items = s.items[:len(s.items)-1]
    return item, true
}

// 类型约束接口
type Number interface {
    ~int | ~int8 | ~int16 | ~int32 | ~int64 |
    ~uint | ~uint8 | ~uint16 | ~uint32 | ~uint64 |
    ~float32 | ~float64
}

func Max[T Number](a, b T) T {
    if a > b {
        return a
    }
    return b
}

// 可比较约束
func Contains[T comparable](slice []T, target T) bool {
    for _, v := range slice {
        if v == target {
            return true
        }
    }
    return false
}
```

### 4.2 泛型高级用法
```go
// 泛型map/reduce/filter
func Map[T1, T2 any](slice []T1, f func(T1) T2) []T2 {
    result := make([]T2, len(slice))
    for i, v := range slice {
        result[i] = f(v)
    }
    return result
}

func Filter[T any](slice []T, predicate func(T) bool) []T {
    var result []T
    for _, v := range slice {
        if predicate(v) {
            result = append(result, v)
        }
    }
    return result
}

// 泛型缓存
type Cache[K comparable, V any] struct {
    mu    sync.RWMutex
    items map[K]V
}

func NewCache[K comparable, V any]() *Cache[K, V] {
    return &Cache[K, V]{
        items: make(map[K]V),
    }
}

func (c *Cache[K, V]) Set(key K, value V) {
    c.mu.Lock()
    defer c.mu.Unlock()
    c.items[key] = value
}
```

## 5. 错误处理高级模式

### 5.1 错误包装和展开
```go
import "errors"

// 错误包装
func processFile(path string) error {
    data, err := os.ReadFile(path)
    if err != nil {
        return fmt.Errorf("读取文件 %s 失败: %w", path, err)
    }
    
    // 处理数据...
    return nil
}

// 错误检查
func handleError() {
    err := processFile("test.txt")
    
    // 检查特定错误
    if errors.Is(err, os.ErrNotExist) {
        fmt.Println("文件不存在")
        return
    }
    
    // 提取包装的错误
    var pathError *os.PathError
    if errors.As(err, &pathError) {
        fmt.Printf("路径错误: %v\n", pathError.Path)
    }
    
    // 自定义错误类型
    var customErr *CustomError
    if errors.As(err, &customErr) {
        fmt.Printf("自定义错误代码: %d\n", customErr.Code)
    }
}

// 错误链
type withStack struct {
    error
    stack []byte
}

func (w *withStack) Unwrap() error {
    return w.error
}

func Wrap(err error) error {
    if err == nil {
        return nil
    }
    return &withStack{
        error: err,
        stack: debug.Stack(),
    }
}
```

### 5.2 错误处理模式
```go
// 错误处理中间件
func withRecovery(fn func() error) (err error) {
    defer func() {
        if r := recover(); r != nil {
            err = fmt.Errorf("panic recovered: %v", r)
        }
    }()
    return fn()
}

// 重试机制
func withRetry(maxAttempts int, delay time.Duration, fn func() error) error {
    var lastErr error
    for i := 0; i < maxAttempts; i++ {
        if err := fn(); err != nil {
            lastErr = err
            time.Sleep(delay)
            continue
        }
        return nil
    }
    return fmt.Errorf("重试 %d 次后失败: %v", maxAttempts, lastErr)
}

// 错误分组
type MultiError []error

func (m MultiError) Error() string {
    var msgs []string
    for _, err := range m {
        msgs = append(msgs, err.Error())
    }
    return strings.Join(msgs, "; ")
}

func (m MultiError) Unwrap() []error {
    return m
}
```

## 6. 内存管理和指针高级用法

### 6.1 Unsafe包
```go
import "unsafe"

// 指针转换
func unsafeCast() {
    var i int64 = 42
    
    // int64 -> []byte
    ptr := unsafe.Pointer(&i)
    bytes := (*[8]byte)(ptr)[:] // 8是int64的字节数
    
    // []byte -> int64
    var j int64
    jPtr := unsafe.Pointer(&j)
    copy((*[8]byte)(jPtr)[:], bytes)
    
    fmt.Println("转换后:", j) // 42
}

// 结构体内存布局
type Person struct {
    Name string
    Age  int32
    City string
}

func inspectMemoryLayout() {
    p := Person{"Alice", 30, "Beijing"}
    
    // 获取结构体大小和对齐
    fmt.Printf("大小: %d\n", unsafe.Sizeof(p))
    fmt.Printf("对齐: %d\n", unsafe.Alignof(p))
    
    // 获取字段偏移
    nameField, _ := reflect.TypeOf(p).FieldByName("Name")
    fmt.Printf("Name偏移: %d\n", nameField.Offset)
}

// 字符串和切片底层
func stringSliceConversion() {
    // 字符串 -> []byte (无拷贝)
    s := "Hello"
    strHeader := (*reflect.StringHeader)(unsafe.Pointer(&s))
    bytes := *(*[]byte)(unsafe.Pointer(&reflect.SliceHeader{
        Data: strHeader.Data,
        Len:  strHeader.Len,
        Cap:  strHeader.Len,
    }))
    
    // 注意: 不要修改bytes，字符串是不可变的
    fmt.Printf("字符串内容: %s\n", bytes)
}
```

### 6.2 内存池和对象重用
```go
// sync.Pool使用
var bufferPool = sync.Pool{
    New: func() interface{} {
        return bytes.NewBuffer(make([]byte, 0, 1024))
    },
}

func getBuffer() *bytes.Buffer {
    return bufferPool.Get().(*bytes.Buffer)
}

func putBuffer(buf *bytes.Buffer) {
    buf.Reset()
    bufferPool.Put(buf)
}

// 自定义对象池
type ObjectPool[T any] struct {
    pool sync.Pool
}

func NewObjectPool[T any](newFunc func() T) *ObjectPool[T] {
    return &ObjectPool[T]{
        pool: sync.Pool{
            New: func() interface{} { return newFunc() },
        },
    }
}

func (p *ObjectPool[T]) Get() T {
    return p.pool.Get().(T)
}

func (p *ObjectPool[T]) Put(obj T) {
    p.pool.Put(obj)
}
```

## 7. 性能优化技巧

### 7.1 基准测试和性能分析
```go
// 基准测试
func BenchmarkConcat(b *testing.B) {
    for i := 0; i < b.N; i++ {
        var s string
        for j := 0; j < 100; j++ {
            s += "a"
        }
    }
}

func BenchmarkBuilder(b *testing.B) {
    for i := 0; i < b.N; i++ {
        var builder strings.Builder
        for j := 0; j < 100; j++ {
            builder.WriteString("a")
        }
        _ = builder.String()
    }
}

// 性能分析
func startProfiling() {
    f, err := os.Create("cpu.prof")
    if err != nil {
        log.Fatal(err)
    }
    pprof.StartCPUProfile(f)
    defer pprof.StopCPUProfile()
    
    // 内存分析
    defer func() {
        mf, _ := os.Create("mem.prof")
        defer mf.Close()
        pprof.WriteHeapProfile(mf)
    }()
}
```

### 7.2 优化技巧
```go
// 1. 预分配切片和map
func optimizedAllocation() {
    // 不好的方式
    var slice []int
    for i := 0; i < 1000; i++ {
        slice = append(slice, i)
    }
    
    // 好的方式
    slice2 := make([]int, 0, 1000)
    for i := 0; i < 1000; i++ {
        slice2 = append(slice2, i)
    }
    
    // Map预分配
    m := make(map[string]int, 100)
}

// 2. 减少内存分配
type Point struct {
    X, Y int
}

// 返回指针减少复制
func NewPoint(x, y int) *Point {
    return &Point{X: x, Y: y}
}

// 3. 使用sync.Pool减少GC压力
var pointPool = sync.Pool{
    New: func() interface{} {
        return &Point{}
    },
}

func getPoint(x, y int) *Point {
    p := pointPool.Get().(*Point)
    p.X, p.Y = x, y
    return p
}

func releasePoint(p *Point) {
    pointPool.Put(p)
}

// 4. 避免接口转换
type fastProcessor struct {
    data []byte
}

func (p *fastProcessor) process() {
    // 直接操作，避免接口开销
}

// 5. 使用bufio缓冲I/O
func bufferedIO() {
    file, _ := os.Open("large.txt")
    defer file.Close()
    
    // 使用缓冲读取
    reader := bufio.NewReaderSize(file, 64*1024)
    
    // 使用缓冲写入
    writer := bufio.NewWriterSize(os.Stdout, 64*1024)
    defer writer.Flush()
}
```

## 8. CGO与系统调用

### 8.1 CGO基础
```go
/*
#include <stdio.h>
#include <stdlib.h>

// C函数
int add(int a, int b) {
    return a + b;
}

// 结构体
typedef struct {
    int x;
    int y;
} Point;

void print_point(Point p) {
    printf("Point(%d, %d)\n", p.x, p.y);
}
*/
import "C"
import "unsafe"

func cgoExample() {
    // 调用C函数
    sum := C.add(10, 20)
    fmt.Printf("Sum: %d\n", sum)
    
    // 使用C结构体
    point := C.Point{x: 100, y: 200}
    C.print_point(point)
    
    // 内存管理
    cstr := C.CString("Hello from Go")
    defer C.free(unsafe.Pointer(cstr)) // 必须释放
    
    // 调用标准C函数
    C.printf(cstr)
}

// C回调函数
/*
extern void goCallback(int);
static void callGoCallback() {
    goCallback(42);
}
*/
import "C"

//export goCallback
func goCallback(value C.int) {
    fmt.Printf("回调值: %d\n", value)
}
```

### 8.2 系统调用
```go
import "syscall"

func syscallExample() {
    // 直接系统调用
    var utsname syscall.Utsname
    if err := syscall.Uname(&utsname); err != nil {
        log.Fatal(err)
    }
    
    // 转换C字符串
    machine := string(utsname.Machine[:])
    fmt.Println("系统架构:", machine)
    
    // 文件描述符操作
    fd, err := syscall.Open("test.txt", syscall.O_RDONLY, 0)
    if err != nil {
        log.Fatal(err)
    }
    defer syscall.Close(fd)
    
    // 非阻塞I/O
    syscall.SetNonblock(fd, true)
    
    // 信号处理
    ch := make(chan os.Signal, 1)
    signal.Notify(ch, syscall.SIGINT, syscall.SIGTERM)
    
    go func() {
        sig := <-ch
        fmt.Printf("收到信号: %v\n", sig)
    }()
}
```

## 9. 测试与调试高级技巧

### 9.1 表格驱动测试
```go
func TestAdd(t *testing.T) {
    tests := []struct {
        name     string
        a, b     int
        expected int
    }{
        {"正数", 1, 2, 3},
        {"零", 0, 0, 0},
        {"负数", -1, -2, -3},
        {"混合", -1, 1, 0},
    }
    
    for _, tt := range tests {
        t.Run(tt.name, func(t *testing.T) {
            result := Add(tt.a, tt.b)
            if result != tt.expected {
                t.Errorf("Add(%d, %d) = %d, 期望 %d",
                    tt.a, tt.b, result, tt.expected)
            }
        })
    }
}

// 子测试并行执行
func TestParallel(t *testing.T) {
    t.Run("组1", func(t *testing.T) {
        t.Parallel()
        // 测试代码...
    })
    
    t.Run("组2", func(t *testing.T) {
        t.Parallel()
        // 测试代码...
    })
}
```

### 9.2 模糊测试（Go 1.18+）
```go
func FuzzReverse(f *testing.F) {
    // 添加种子语料库
    f.Add("hello")
    f.Add("世界")
    
    f.Fuzz(func(t *testing.T, s string) {
        reversed := Reverse(s)
        doubleReversed := Reverse(reversed)
        
        if s != doubleReversed {
            t.Errorf("原字符串: %q, 两次反转后: %q", s, doubleReversed)
        }
        
        // 验证UTF-8有效性
        if utf8.ValidString(s) && !utf8.ValidString(reversed) {
            t.Errorf("反转破坏了UTF-8有效性: %q", reversed)
        }
    })
}
```

### 9.3 调试技巧
```go
// 1. 使用runtime包
func debugInfo() {
    // 堆栈信息
    buf := make([]byte, 1024)
    n := runtime.Stack(buf, false)
    fmt.Printf("堆栈: %s\n", buf[:n])
    
    // Goroutine信息
    fmt.Printf("Goroutine数: %d\n", runtime.NumGoroutine())
    
    // 内存统计
    var mem runtime.MemStats
    runtime.ReadMemStats(&mem)
    fmt.Printf("内存使用: %v MB\n", mem.Alloc/1024/1024)
}

// 2. 条件编译调试
// +build debug

package main

var debugMode = true

func debugLog(msg string) {
    if debugMode {
        log.Printf("[DEBUG] %s", msg)
    }
}

// 3. 使用pprof进行性能分析
func startPProf() {
    go func() {
        log.Println(http.ListenAndServe("localhost:6060", nil))
    }()
    
    // 手动触发GC进行内存分析
    runtime.GC()
    
    // 查看goroutine阻塞
    f, _ := os.Create("block.prof")
    pprof.Lookup("block").WriteTo(f, 0)
    f.Close()
}
```

## 10. 包设计与架构模式

### 10.1 接口设计模式
```go
// 策略模式
type PaymentStrategy interface {
    Pay(amount float64) error
}

type CreditCardPayment struct{}
func (c *CreditCardPayment) Pay(amount float64) error {
    fmt.Println("信用卡支付:", amount)
    return nil
}

type PayPalPayment struct{}
func (p *PayPalPayment) Pay(amount float64) error {
    fmt.Println("PayPal支付:", amount)
    return nil
}

// 工厂模式
func NewPayment(method string) (PaymentStrategy, error) {
    switch method {
    case "creditcard":
        return &CreditCardPayment{}, nil
    case "paypal":
        return &PayPalPayment{}, nil
    default:
        return nil, fmt.Errorf("不支持的支付方式")
    }
}

// 装饰器模式
type LoggingPayment struct {
    wrapped PaymentStrategy
}

func (l *LoggingPayment) Pay(amount float64) error {
    log.Printf("开始支付: %.2f", amount)
    err := l.wrapped.Pay(amount)
    if err != nil {
        log.Printf("支付失败: %v", err)
    } else {
        log.Println("支付成功")
    }
    return err
}
```

### 10.2 依赖注入
```go
// 构造函数注入
type Service struct {
    repo    Repository
    logger  Logger
    config  Config
}

func NewService(repo Repository, logger Logger, config Config) *Service {
    return &Service{
        repo:   repo,
        logger: logger,
        config: config,
    }
}

// 选项模式
type ServiceOption func(*Service)

func WithLogger(logger Logger) ServiceOption {
    return func(s *Service) {
        s.logger = logger
    }
}

func WithConfig(config Config) ServiceOption {
    return func(s *Service) {
        s.config = config
    }
}

func NewServiceWithOptions(repo Repository, opts ...ServiceOption) *Service {
    s := &Service{repo: repo}
    for _, opt := range opts {
        opt(s)
    }
    return s
}

// 使用wire进行依赖注入（需要安装wire工具）
// https://github.com/google/wire
```

## 总结

Go的高级语法涵盖了并发编程、反射、泛型、性能优化等多个方面。掌握这些特性可以帮助你：

1. **编写高性能代码**：通过内存池、预分配、减少GC压力
2. **构建可扩展系统**：使用goroutine和channel处理高并发
3. **实现灵活架构**：通过接口、泛型和设计模式
4. **确保代码质量**：通过测试、性能分析和调试
