# Logger 类文档

## 简介
Dart 日志记录器，支持多级别、文件输出、控制台颜色、日志轮转等功能。

## 快速开始
```dart
final logger = Logger();

// 基础用法
logger.info('系统启动');
logger.warn('磁盘空间不足: %d GB', 5);

// 配置输出
logger.setLevel(LogLevel.debug);
logger.setOutputFile('logs/app.log');
logger.setConsole(true);
```

## 日志级别
```dart
enum LogLevel {
  trace,   // 跟踪
  debug,   // 调试
  info,    // 信息
  warn,    // 警告
  error,   // 错误
  fatal,   // 致命（自动退出）
  panic,   // 恐慌（抛出异常）
}
```

## 核心功能

### 1. 级别控制
```dart
logger.setLevel(LogLevel.info);        // 设置级别
logger.setLevelString('debug');         // 字符串设置
```

### 2. 输出目标
```dart
logger.setOutputFile('logs/app.log');  // 输出到文件
logger.setConsole(true);               // 输出到控制台
logger.setColor(true);                 // 控制台颜色
```

### 3. 文件管理
```dart
logger.setMaxSize(10 * 1024 * 1024);   // 10MB限制
// 超过大小自动轮转：app.log → app.log.20240101120000.bak
```

## 日志方法
```dart
// 所有方法支持最多5个参数
logger.trace('详细跟踪信息');
logger.debug('调试信息: %s', value);
logger.info('用户登录: %s', username);
logger.warn('API响应慢: %d ms', 1200);
logger.error('数据库连接失败: %s', error);

// 特殊级别
logger.fatal('系统崩溃，即将退出'); // 自动调用 exit(1)
logger.panic('无法恢复的错误');    // 抛出异常
```

## 日志格式
```
[2024-01-01 12:00:00.123] [INFO] [main.dart:main:25] 系统启动成功
```
- 时间戳
- 级别（彩色显示）
- 文件:函数:行号
- 消息

## 异步安全
- 使用 `Lock` 类保证线程安全
- 所有写操作同步执行
- 支持 `flush()` 和 `close()` 方法

## 示例配置
```dart
void setupLogger() {
  final logger = Logger();
  
  // 开发环境
  if (isDevelopment) {
    logger.setLevel(LogLevel.debug);
    logger.setConsole(true);
    logger.setColor(true);
  }
  
  // 生产环境
  else {
    logger.setLevel(LogLevel.info);
    logger.setOutputFile('logs/app.log');
    logger.setMaxSize(50 * 1024 * 1024); // 50MB
    logger.setConsole(false);
  }
  
  // 全局使用
  globalLogger = logger;
}
```

## 使用场景
```dart
// API请求日志
logger.info('API请求: %s %s', method, url);
logger.debug('请求参数: %s', jsonEncode(params));

// 错误处理
try {
  await riskyOperation();
} catch (e) {
  logger.error('操作失败: %s', e.toString());
  logger.trace('堆栈: %s', StackTrace.current);
}

// 性能监控
final stopwatch = Stopwatch()..start();
await expensiveTask();
logger.debug('任务耗时: %d ms', stopwatch.elapsedMilliseconds);
```

## 注意事项
1. **文件权限**：确保对日志目录有写入权限
2. **性能影响**：TRACE/DEBUG 级别可能影响性能
3. **磁盘空间**：定期清理旧日志文件
4. **异常安全**：日志写入失败不会影响主程序
5. **调用信息**：自动捕获文件名、函数名和行号

## 简单示例
```dart
import 'util/logger.dart';

void main() async {
  final logger = Logger()
    ..setLevel(LogLevel.info)
    ..setConsole(true)
    ..setColor(true);

  logger.info('应用程序启动');
  
  try {
    await runApp();
    logger.info('应用程序正常退出');
  } catch (e) {
    logger.fatal('应用程序崩溃: %s', e);
  }
}
```