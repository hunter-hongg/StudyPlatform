package util

import (
    "fmt"
    "io"
    "os"
    "path"
    "runtime"
    "strings"
    "sync"
    "time"
)

type LogLevel int

const (
    LevelTrace LogLevel = iota
    LevelDebug
    LevelInfo
    LevelWarn
    LevelError
    LevelFatal
    LevelPanic
)

const (
    colorRed    = 31
    colorGreen  = 32
    colorYellow = 33
    colorBlue   = 34
    colorCyan   = 36
    colorWhite  = 37
)

type LogEntry struct {
    Timestamp time.Time
    Level     LogLevel
    Message   string
    File      string
    Line      int
    Function  string
}

type Logger struct {
    mu         sync.Mutex
    level      LogLevel
    output     io.Writer
    file       *os.File
    filePath   string
    maxSize    int64
    currentSize int64
    console    bool
    color      bool
}

func NewLogger() *Logger {
    return &Logger{
        level:   LevelDebug,
        output:  os.Stdout,
        console: true,
        color:   true,
        maxSize: 10 * 1024 * 1024,  
    }
}

func (l LogLevel) String() string {
    switch l {
    case LevelTrace:
        return "TRACE"
    case LevelDebug:
        return "DEBUG"
    case LevelInfo:
        return "INFO"
    case LevelWarn:
        return "WARN"
    case LevelError:
        return "ERROR"
    case LevelFatal:
        return "FATAL"
    case LevelPanic:
        return "PANIC"
    default:
        return "UNKNOWN"
    }
}

func (logger *Logger) SetLevel(level LogLevel) {
    logger.mu.Lock()
    defer logger.mu.Unlock()
    logger.level = level
}

func (logger *Logger) SetLevelString(levelStr string) error {
    level, err := parseLevelString(levelStr)
    if err != nil {
        return err
    }
    logger.SetLevel(level)
    return nil
}

func (logger *Logger) SetOutputFile(filePath string) error {
    logger.mu.Lock()
    defer logger.mu.Unlock()

    // 关闭现有文件
    if logger.file != nil {
        logger.file.Close()
    }

    // 创建目录
    dir := path.Dir(filePath)
    if err := os.MkdirAll(dir, 0755); err != nil {
        return err
    }

    // 打开新文件
    file, err := os.OpenFile(filePath, os.O_CREATE|os.O_WRONLY|os.O_APPEND, 0644)
    if err != nil {
        return err
    }

    // 获取文件信息
    info, err := file.Stat()
    if err != nil {
        file.Close()
        return err
    }

    logger.file = file
    logger.filePath = filePath
    logger.currentSize = info.Size()
    logger.output = file
    
    return nil
}

func (logger *Logger) SetConsole(enabled bool) {
    logger.mu.Lock()
    defer logger.mu.Unlock()
    logger.console = enabled
}

func (logger *Logger) SetColor(enabled bool) {
    logger.mu.Lock()
    defer logger.mu.Unlock()
    logger.color = enabled
}

func (logger *Logger) SetMaxSize(size int64) {
    logger.mu.Lock()
    defer logger.mu.Unlock()
    logger.maxSize = size
}

func (logger *Logger) shouldRotate() bool {
    return logger.file != nil && logger.currentSize >= logger.maxSize
}

func (logger *Logger) rotate() error {
    if logger.file == nil {
        return nil
    }

    // 关闭当前文件
    logger.file.Close()

    // 重命名当前文件
    timestamp := time.Now().Format("20060102150405")
    backupPath := logger.filePath + "." + timestamp + ".bak"
    
    if err := os.Rename(logger.filePath, backupPath); err != nil {
        return err
    }

    // 创建新文件
    file, err := os.OpenFile(logger.filePath, os.O_CREATE|os.O_WRONLY|os.O_APPEND, 0644)
    if err != nil {
        return err
    }

    logger.file = file
    logger.currentSize = 0
    logger.output = file
    
    return nil
}

func getCallerInfo(skip int) (string, string, int) {
    pc, file, line, ok := runtime.Caller(skip)
    if !ok {
        return "???", "???", 0
    }

    function := runtime.FuncForPC(pc).Name()
    functionName := path.Base(function)
    fileName := path.Base(file)

    return fileName, functionName, line
}

func parseLevelString(levelStr string) (LogLevel, error) {
    switch strings.ToLower(levelStr) {
    case "trace":
        return LevelTrace, nil
    case "debug":
        return LevelDebug, nil
    case "info":
        return LevelInfo, nil
    case "warn", "warning":
        return LevelWarn, nil
    case "error":
        return LevelError, nil
    case "fatal":
        return LevelFatal, nil
    case "panic":
        return LevelPanic, nil
    default:
        return LevelInfo, fmt.Errorf("invalid log level: %s", levelStr)
    }
}

func getLevelColor(level LogLevel) int {
    switch level {
    case LevelTrace, LevelDebug:
        return colorCyan
    case LevelInfo:
        return colorGreen
    case LevelWarn:
        return colorYellow
    case LevelError, LevelFatal, LevelPanic:
        return colorRed
    default:
        return colorWhite
    }
}

func colorize(text string, colorCode int) string {
    return fmt.Sprintf("\033[%dm%s\033[0m", colorCode, text)
}

func (logger *Logger) log(level LogLevel, format string, args ...interface{}) {
    if level < logger.level {
        return
    }

    logger.mu.Lock()
    defer logger.mu.Unlock()

    // 检查文件切割
    if logger.shouldRotate() {
        if err := logger.rotate(); err != nil {
            fmt.Fprintf(os.Stderr, "日志切割失败: %v\n", err)
        }
    }

    // 获取调用信息
    file, function, line := getCallerInfo(3)
    
    // 格式化消息
    message := format
    if len(args) > 0 {
        message = fmt.Sprintf(format, args...)
    }

    // 创建日志条目
    timestamp := time.Now().Format("2006-01-02 15:04:05.000")
    levelStr := level.String()
    
    // 构建日志行
    logLine := fmt.Sprintf("[%s] [%s] [%s:%s:%d] %s\n", 
        timestamp, levelStr, file, function, line, message)

    // 输出到文件或控制台
    if logger.file != nil {
        n, err := fmt.Fprint(logger.output, logLine)
        if err == nil {
            logger.currentSize += int64(n)
        }
    }

    // 输出到控制台（如果需要）
    if logger.console {
        if logger.color {
            coloredLevel := colorize(levelStr, getLevelColor(level))
            coloredLine := fmt.Sprintf("[%s] [%s] [%s:%s:%d] %s", 
                timestamp, coloredLevel, file, function, line, message)
            fmt.Println(coloredLine)
        } else {
            fmt.Print(logLine)
        }
    }

    // 特殊级别处理
    if level == LevelFatal {
        os.Exit(1)
    } else if level == LevelPanic {
        panic(message)
    }
}

func (logger *Logger) Trace(format string, args ...interface{}) {
    logger.log(LevelTrace, format, args...)
}

func (logger *Logger) Debug(format string, args ...interface{}) {
    logger.log(LevelDebug, format, args...)
}

func (logger *Logger) Info(format string, args ...interface{}) {
    logger.log(LevelInfo, format, args...)
}

func (logger *Logger) Warn(format string, args ...interface{}) {
    logger.log(LevelWarn, format, args...)
}

func (logger *Logger) Error(format string, args ...interface{}) {
    logger.log(LevelError, format, args...)
}

func (logger *Logger) Fatal(format string, args ...interface{}) {
    logger.log(LevelFatal, format, args...)
}

func (logger *Logger) Panic(format string, args ...interface{}) {
    logger.log(LevelPanic, format, args...)
}

func (logger *Logger) Flush() {
    logger.mu.Lock()
    defer logger.mu.Unlock()
    
    if logger.file != nil {
        if file, ok := logger.output.(*os.File); ok {
            file.Sync()
        }
    }
}

func (logger *Logger) Close() {
    logger.mu.Lock()
    defer logger.mu.Unlock()
    
    if logger.file != nil {
        logger.file.Sync()
        logger.file.Close()
        logger.file = nil
    }
}

