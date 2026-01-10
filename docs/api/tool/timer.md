# CTimer 类文档

## 概述

`CTimer` 是一个功能完整的 Dart 计时器类，支持正计时、倒计时和间隔计时功能。它提供了丰富的控制方法和状态管理，适用于各种计时场景。

## 导入

```dart
import 'dart:async'; // 内部使用 Dart 原生 Timer
```

## 枚举：TimerStatus

| 枚举值 | 描述 |
|--------|------|
| `stopped` | 计时器已停止，未开始运行 |
| `running` | 计时器正在运行中 |
| `paused` | 计时器已暂停，可恢复运行 |
| `completed` | 倒计时已完成（仅倒计时模式） |

## 构造函数

### 工厂构造函数

#### `CTimer.forward()` - 创建正计时器
创建一个正向计时器，从 0 开始计时。

```dart
factory CTimer.forward({
  Duration interval = const Duration(seconds: 1),
  bool repeat = false,
  void Function(Duration)? onTick,
  void Function()? onComplete,
})
```

**参数：**
- `interval`：触发间隔，默认 1 秒
- `repeat`：是否重复执行，默认 `false`
- `onTick`：每次触发时的回调函数
- `onComplete`：计时器完成时的回调函数（非重复计时器）

#### `CTimer.countdown()` - 创建倒计时器
创建一个倒计时器，从指定时间开始倒计时。

```dart
factory CTimer.countdown({
  required Duration totalDuration,
  Duration interval = const Duration(seconds: 1),
  void Function(Duration)? onTick,
  void Function()? onComplete,
})
```

**参数：**
- `totalDuration`：总倒计时时间（必需）
- `interval`：触发间隔，默认 1 秒
- `onTick`：每次触发时的回调函数
- `onComplete`：计时器完成时的回调函数

## 属性

| 属性 | 类型 | 描述 | 只读 |
|------|------|------|------|
| `status` | `TimerStatus` | 当前计时器状态 | ✓ |
| `elapsed` | `Duration` | 已过去的时间 | ✓ |
| `remaining` | `Duration?` | 剩余时间（仅倒计时模式） | ✓ |
| `progress` | `double?` | 进度 0.0-1.0（仅倒计时模式） | ✓ |

## 方法

### 控制方法

#### `start()` - 开始计时
启动或恢复计时器。

```dart
void start()
```

- 如果计时器是全新状态，则从 0 开始计时
- 如果计时器处于暂停状态，则从暂停点恢复计时

#### `pause()` - 暂停计时
暂停正在运行的计时器。

```dart
void pause()
```

- 仅当 `status == TimerStatus.running` 时有效
- 暂停后会保存已过去的时间

#### `resume()` - 恢复计时
从暂停状态恢复计时。

```dart
void resume()
```

- 仅当 `status == TimerStatus.paused` 时有效
- 实际上是 `start()` 方法的别名，在暂停状态下调用

#### `stop()` - 停止计时
停止计时器并重置所有计时数据。

```dart
void stop()
```

#### `cancel()` - 取消计时
停止计时器并释放内部资源，但不重置已记录的时间。

```dart
void cancel()
```

#### `reset()` - 重置计时器
停止计时器并清除所有计时数据，恢复到初始状态。

```dart
void reset()
```

#### `restart()` - 重启计时器
重置并立即开始新的计时。

```dart
void restart()
```

#### `dispose()` - 销毁计时器
释放所有资源，包括清除监听器列表。调用后计时器不可再用。

```dart
void dispose()
```

### 监听器管理

#### `addTickListener()` - 添加 tick 监听器
添加计时器每次触发时的回调函数。

```dart
void addTickListener(void Function(Duration) listener)
```

#### `removeTickListener()` - 移除 tick 监听器
移除已注册的 tick 监听器。

```dart
void removeTickListener(void Function(Duration) listener)
```

#### `addCompleteListener()` - 添加完成监听器
添加计时器完成时的回调函数。

```dart
void addCompleteListener(void Function() listener)
```

#### `removeCompleteListener()` - 移除完成监听器
移除已注册的完成监听器。

```dart
void removeCompleteListener(void Function() listener)
```

## 使用示例

### 示例 1：正计时器

```dart
// 创建单次触发的正计时器
final timer = CTimer.forward(
  interval: Duration(milliseconds: 500),
  onTick: (elapsed) {
    print('已运行: ${elapsed.inSeconds} 秒');
  },
  onComplete: () {
    print('计时完成！');
  },
);

timer.start();
// 输出：每 500ms 打印一次，最后输出"计时完成！"
```

### 示例 2：重复正计时器

```dart
// 创建重复触发的正计时器
final stopwatch = CTimer.forward(
  interval: Duration(seconds: 1),
  repeat: true,
  onTick: (elapsed) {
    print('秒表: ${elapsed.inSeconds}s');
  },
);

stopwatch.start();
await Future.delayed(Duration(seconds: 5));
stopwatch.pause();
await Future.delayed(Duration(seconds: 2));
stopwatch.resume();
await Future.delayed(Duration(seconds: 3));
stopwatch.stop();
```

### 示例 3：倒计时器

```dart
// 创建 10 秒倒计时
final countdown = CTimer.countdown(
  totalDuration: Duration(seconds: 10),
  interval: Duration(seconds: 1),
  onTick: (elapsed) {
    print('剩余: ${countdown.remaining?.inSeconds} 秒');
  },
  onComplete: () {
    print('时间到！');
  },
);

// 添加额外的监听器
countdown.addTickListener((elapsed) {
  print('进度: ${(countdown.progress! * 100).toStringAsFixed(1)}%');
});

countdown.start();
```

### 示例 4：监听器管理

```dart
final timer = CTimer.forward(interval: Duration(milliseconds: 200));

void listener1(Duration elapsed) => print('监听器1: $elapsed');
void listener2(Duration elapsed) => print('监听器2: $elapsed');

timer.addTickListener(listener1);
timer.addTickListener(listener2);

timer.start();
await Future.delayed(Duration(seconds: 1));

// 移除一个监听器
timer.removeTickListener(listener2);

await Future.delayed(Duration(seconds: 1));
timer.stop();
```

## 实现细节

### 内部状态管理
- 使用 `_startTime` 记录开始时间戳
- 使用 `_elapsedBeforePause` 记录暂停前已过时间
- 使用 `_pauseTime` 记录暂停时间点
- 使用 `_timer` 存储 Dart 原生 Timer 实例

### 线程安全
- 所有状态变更都在主线程/Dart isolate 中执行
- 监听器回调在定时器的 timer 上下文中执行

### 资源管理
- 内部使用 Dart 的 `Timer.periodic` 实现定时触发
- `dispose()` 方法确保所有资源被正确释放
- 监听器列表在销毁时自动清空

## 注意事项

1. **命名空间**：为避免与 Dart 原生 `Timer` 类冲突，本类命名为 `CTimer`
2. **内存管理**：长时间运行的计时器应及时调用 `dispose()` 释放资源
3. **监听器泄漏**：在不需要时务必移除监听器，或确保在 `dispose()` 前清理
4. **倒计时精度**：受 Dart 事件循环影响，实际触发时间可能有微小误差

## 相关类型

- `dart:async.Timer` - Dart 原生计时器
- `Duration` - 时间间隔表示
- `DateTime` - 时间点表示
