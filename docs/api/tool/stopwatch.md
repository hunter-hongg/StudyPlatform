# StopwatchManager 使用文档

## 概述

`StopwatchManager` 是一个基于 Dart 原生 `Stopwatch` 封装的秒表管理器，提供简单易用的计时功能。它支持开始、暂停、恢复和重置操作，并可以随时获取已过去的时间。

## 类定义

### StopWatchStatus 枚举
表示秒表的状态：
- `running` - 运行中
- `paused` - 已暂停  
- `stopped` - 已停止（未开始或已重置）

### StopwatchManager 类

#### 属性
- `status` - 获取当前秒表状态
- `elapsed` - 获取已过去的时间（Duration 类型）

#### 方法

##### `start()`
开始计时。
- **条件**：秒表处于 `stopped` 或 `paused` 状态
- **效果**：状态变为 `running`，开始计时

##### `pause()`
暂停计时。
- **条件**：秒表处于 `running` 状态
- **效果**：状态变为 `paused`，停止计时但保留已计时时间

##### `resume()`
恢复计时。
- **条件**：秒表处于 `paused` 状态
- **效果**：状态变为 `running`，从暂停点继续计时

##### `reset()`
重置计时器。
- **效果**：状态变为 `stopped`，清除所有计时数据

##### `elapsed`
获取已过去的时间。
- **返回**：`Duration` 类型，表示从开始到当前（或暂停时）经过的时间
- **特性**：随时可调用，无需等待特定时间

##### `formatTime()`
格式化显示时间。
- **返回**：格式为 `HH:MM:SS.mmm` 的字符串
  - `HH`：小时（2位，前补零）
  - `MM`：分钟（2位，前补零）
  - `SS`：秒（2位，前补零）
  - `mmm`：毫秒（3位，前补零）
- **示例**：`01:23:45.678`

## 使用示例

### 基础用法
```dart
void main() {
  final stopwatch = StopwatchManager();
  
  // 开始计时
  stopwatch.start();
  print('状态: ${stopwatch.status}'); // running
  
  // 模拟一些操作
  Future.delayed(Duration(seconds: 2), () {
    // 获取时间
    print('已过去: ${stopwatch.elapsed.inSeconds} 秒'); // 2
    print('格式化: ${stopwatch.formatTime()}'); // 00:00:02.000
    
    // 暂停
    stopwatch.pause();
    print('状态: ${stopwatch.status}'); // paused
    
    // 暂停后时间不变
    Future.delayed(Duration(seconds: 1), () {
      print('暂停1秒后: ${stopwatch.elapsed.inSeconds} 秒'); // 2
      
      // 恢复
      stopwatch.resume();
      
      Future.delayed(Duration(seconds: 1), () {
        print('恢复后1秒: ${stopwatch.elapsed.inSeconds} 秒'); // 3
        
        // 重置
        stopwatch.reset();
        print('状态: ${stopwatch.status}'); // stopped
        print('重置后: ${stopwatch.elapsed.inSeconds} 秒'); // 0
      });
    });
  });
}
```

### 实际应用场景

#### 1. 测量代码执行时间
```dart
Future<void> measureExecutionTime() async {
  final stopwatch = StopwatchManager();
  
  stopwatch.start();
  
  // 执行需要测量的代码
  await someAsyncOperation();
  await anotherAsyncOperation();
  
  final elapsed = stopwatch.elapsed;
  print('操作耗时: ${elapsed.inMilliseconds}ms');
  print('详细时间: ${stopwatch.formatTime()}');
  
  stopwatch.reset();
}
```

#### 2. 游戏计时
```dart
class GameSession {
  final StopwatchManager _timer = StopwatchManager();
  
  void startGame() {
    _timer.start();
    print('游戏开始 - ${_timer.formatTime()}');
  }
  
  void pauseGame() {
    _timer.pause();
    print('游戏暂停 - 总用时: ${_timer.formatTime()}');
  }
  
  void endGame() {
    final totalTime = _timer.formatTime();
    _timer.reset();
    print('游戏结束 - 总用时: $totalTime');
  }
}
```

#### 3. 性能监控
```dart
class PerformanceMonitor {
  final StopwatchManager _stopwatch = StopwatchManager();
  final List<Duration> _measurements = [];
  
  void startMeasurement(String operationName) {
    print('开始测量: $operationName');
    _stopwatch.reset();
    _stopwatch.start();
  }
  
  void endMeasurement(String operationName) {
    _stopwatch.pause();
    final duration = _stopwatch.elapsed;
    _measurements.add(duration);
    
    print('$operationName 耗时: ${_stopwatch.formatTime()}');
    _stopwatch.reset();
  }
}
```

### 状态转换图
```
     stopped
       ↓ start()
     running
       ↓ pause()
     paused
       ↓ resume()
     running
       ↓ reset()
     stopped
```

### 注意事项

1. **线程安全**：`StopwatchManager` 不是线程安全的，应在同一隔离（isolate）中使用
2. **精度**：计时精度取决于系统，通常是毫秒级
3. **多次调用**：在相同状态下多次调用 `start()`、`pause()`、`resume()` 是安全的（幂等操作）
4. **内存管理**：长时间运行的秒表不会导致内存泄漏，但应及时重置不需要的计时器

### 扩展建议

如果需要以下功能，可以考虑扩展此类：

1. **回调通知**：添加时间变化时的回调
2. **分段计时**：支持记录多个分段的时间
3. **持久化**：支持保存和恢复计时状态
4. **格式化选项**：支持自定义时间格式
5. **最大时长限制**：设置最大计时时间

### 与其他计时器的比较

| 特性 | StopwatchManager | Timer | Future.delayed |
|------|-----------------|-------|----------------|
| 随时获取时间 | ✅ | ❌ | ❌ |
| 暂停/恢复 | ✅ | ❌ | ❌ |
| 精确控制 | ✅ | ✅ | ✅ |
| 轻量级 | ✅ | ✅ | ✅ |
| 回调支持 | ❌ | ✅ | ✅ |
| 重复执行 | ❌ | ✅ | ❌ |

### 版本兼容性

- 要求 Dart 2.12+（支持空安全）
- 兼容所有平台（Flutter、Web、服务器端）