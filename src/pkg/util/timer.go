package util

import (
    "fmt"
    "sync"
    "time"
)

// Timer 高性能计时器结构体
type Timer struct {
    startTime    time.Time     // 开始时间
    endTime      time.Time     // 结束时间
    isRunning    bool          // 运行状态
    elapsedTime  time.Duration // 累计时间
    mu           sync.Mutex    // 互斥锁，保证并发安全
    laps         []time.Duration // 分段计时记录
}

// NewTimer 创建新的计时器实例
func NewTimer() *Timer {
    return &Timer{
        isRunning:   false,
        elapsedTime: 0,
        laps:        make([]time.Duration, 0),
    }
}

// Start 开始计时
func (t *Timer) Start() error {
    t.mu.Lock()
    defer t.mu.Unlock()
    
    if t.isRunning {
        return fmt.Errorf("计时器已经在运行中")
    }
    
    t.startTime = time.Now()
    t.isRunning = true
    t.elapsedTime = 0
    t.laps = make([]time.Duration, 0) // 清空分段记录
    return nil
}

// Stop 结束计时
func (t *Timer) Stop() error {
    t.mu.Lock()
    defer t.mu.Unlock()
    
    if !t.isRunning {
        return fmt.Errorf("计时器未运行")
    }
    
    t.endTime = time.Now()
    t.isRunning = false
    t.elapsedTime = t.endTime.Sub(t.startTime)
    return nil
}

// Lap 记录分段时间
func (t *Timer) Lap() time.Duration {
    t.mu.Lock()
    defer t.mu.Unlock()
    
    if !t.isRunning {
        return 0
    }
    
    currentTime := time.Now()
    lapTime := currentTime.Sub(t.startTime)
    t.laps = append(t.laps, lapTime)
    return lapTime
}

// GetElapsedTime 获取经过的时间
func (t *Timer) GetElapsedTime() time.Duration {
    t.mu.Lock()
    defer t.mu.Unlock()
    
    if t.isRunning {
        return time.Since(t.startTime)
    }
    return t.elapsedTime
}

// 时间单位转换方法

// GetNanoseconds 获取纳秒数
func (t *Timer) GetNanoseconds() int64 {
    return t.GetElapsedTime().Nanoseconds()
}

// GetMicroseconds 获取微秒数
func (t *Timer) GetMicroseconds() float64 {
    elapsed := t.GetElapsedTime()
    return float64(elapsed.Nanoseconds()) / float64(time.Microsecond)
}

// GetMilliseconds 获取毫秒数
func (t *Timer) GetMilliseconds() float64 {
    elapsed := t.GetElapsedTime()
    return float64(elapsed.Nanoseconds()) / float64(time.Millisecond)
}

// GetSeconds 获取秒数
func (t *Timer) GetSeconds() float64 {
    return t.GetElapsedTime().Seconds()
}

// GetMinutes 获取分钟数
func (t *Timer) GetMinutes() float64 {
    return t.GetElapsedTime().Minutes()
}

// GetHours 获取小时数
func (t *Timer) GetHours() float64 {
    return t.GetElapsedTime().Hours()
}

// FormatDuration 格式化时间显示
func (t *Timer) FormatDuration() string {
    elapsed := t.GetElapsedTime()
    hours := int(elapsed.Hours())
    minutes := int(elapsed.Minutes()) % 60
    seconds := int(elapsed.Seconds()) % 60
    milliseconds := int(t.GetMilliseconds()) % 1000
    
    return fmt.Sprintf("%02d:%02d:%02d.%03d", hours, minutes, seconds, milliseconds)
}

// Reset 重置计时器
func (t *Timer) Reset() {
    t.mu.Lock()
    defer t.mu.Unlock()
    
    t.isRunning = false
    t.elapsedTime = 0
    t.startTime = time.Time{}
    t.endTime = time.Time{}
    t.laps = make([]time.Duration, 0)
}

// GetLaps 获取所有分段时间
func (t *Timer) GetLaps() []time.Duration {
    t.mu.Lock()
    defer t.mu.Unlock()
    
    laps := make([]time.Duration, len(t.laps))
    copy(laps, t.laps)
    return laps
}

// IsRunning 检查计时器是否在运行
func (t *Timer) IsRunning() bool {
    t.mu.Lock()
    defer t.mu.Unlock()
    return t.isRunning
}

// 高级功能：累计计时器（支持暂停/继续）
type AccumulativeTimer struct {
    totalElapsed time.Duration // 总累计时间
    currentStart time.Time     // 当前开始时间
    isRunning    bool          // 运行状态
    mu           sync.Mutex    // 互斥锁
    laps         []time.Duration // 分段记录
}

// NewAccumulativeTimer 创建累计计时器
func NewAccumulativeTimer() *AccumulativeTimer {
    return &AccumulativeTimer{
        isRunning:    false,
        totalElapsed: 0,
        laps:         make([]time.Duration, 0),
    }
}

// Start 开始或继续计时
func (at *AccumulativeTimer) Start() {
    at.mu.Lock()
    defer at.mu.Unlock()
    
    if !at.isRunning {
        at.currentStart = time.Now()
        at.isRunning = true
    }
}

// Pause 暂停计时
func (at *AccumulativeTimer) Pause() {
    at.mu.Lock()
    defer at.mu.Unlock()
    
    if at.isRunning {
        at.totalElapsed += time.Since(at.currentStart)
        at.isRunning = false
    }
}

// Reset 重置累计计时器
func (at *AccumulativeTimer) Reset() {
    at.mu.Lock()
    defer at.mu.Unlock()
    
    at.totalElapsed = 0
    at.isRunning = false
    at.currentStart = time.Time{}
    at.laps = make([]time.Duration, 0)
}

// Lap 记录分段时间
func (at *AccumulativeTimer) Lap() {
    at.mu.Lock()
    defer at.mu.Unlock()
    
    if at.isRunning {
        currentElapsed := at.totalElapsed + time.Since(at.currentStart)
        at.laps = append(at.laps, currentElapsed)
    }
}

// GetTotalTime 获取总时间
func (at *AccumulativeTimer) GetTotalTime() time.Duration {
    at.mu.Lock()
    defer at.mu.Unlock()
    
    if at.isRunning {
        return at.totalElapsed + time.Since(at.currentStart)
    }
    return at.totalElapsed
}
