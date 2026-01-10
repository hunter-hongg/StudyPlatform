import 'dart:async';
// import 'dart:collection';

/// 计时器状态枚举
enum TimerStatus {
  stopped,    // 已停止
  running,    // 运行中
  paused,     // 已暂停
  completed,  // 已完成（只用于倒计时）
}

/// 计时器类 - 支持正计时、倒计时、间隔计时
class CTimer {
  // 计时器状态
  TimerStatus _status = TimerStatus.stopped;
  
  // 内部计时器
  Timer? _timer;
  
  // 开始时间（毫秒）
  int _startTime = 0;
  
  // 暂停时累计的时间（毫秒）
  int _elapsedBeforePause = 0;
  
  // 暂停时间点
  int _pauseTime = 0;
  
  // 总计时时间（对于倒计时）
  final int? _totalDuration;
  
  // 计时器配置
  final Duration _interval;
  final bool _isCountdown;
  final bool _repeat;
  final void Function(Duration)? _onTick;
  final void Function()? _onComplete;
  
  // 监听器列表
  final List<void Function(Duration)> _tickListeners = [];
  final List<void Function()> _completeListeners = [];
  
  /// 获取当前状态
  TimerStatus get status => _status;
  
  /// 获取已过去的时间
  Duration get elapsed {
    if (_status == TimerStatus.stopped) {
      return Duration.zero;
    } else if (_status == TimerStatus.paused) {
      return Duration(milliseconds: _elapsedBeforePause);
    } else {
      final now = DateTime.now().millisecondsSinceEpoch;
      final elapsed = _elapsedBeforePause + (now - _startTime);
      return Duration(milliseconds: elapsed);
    }
  }
  
  /// 获取剩余时间（仅倒计时）
  Duration? get remaining {
    if (!_isCountdown || _totalDuration == null) return null;
    if (_status == TimerStatus.stopped) {
      return Duration(milliseconds: _totalDuration!);
    } else if (_status == TimerStatus.completed) {
      return Duration.zero;
    } else {
      final elapsedMs = elapsed.inMilliseconds;
      final remainingMs = _totalDuration! - elapsedMs;
      return Duration(milliseconds: remainingMs > 0 ? remainingMs : 0);
    }
  }
  
  /// 获取进度（0.0 - 1.0，仅倒计时）
  double? get progress {
    if (!_isCountdown || _totalDuration == null) return null;
    if (_status == TimerStatus.stopped) {
      return 0.0;
    } else if (_status == TimerStatus.completed) {
      return 1.0;
    } else {
      final elapsedMs = elapsed.inMilliseconds;
      final progress = elapsedMs / _totalDuration!;
      return progress > 1.0 ? 1.0 : progress;
    }
  }
  
  /// 私有构造函数
  CTimer._({
    required Duration interval,
    bool isCountdown = false,
    Duration? totalDuration,
    bool repeat = false,
    void Function(Duration)? onTick,
    void Function()? onComplete,
  }) : _interval = interval,
       _isCountdown = isCountdown,
       _totalDuration = totalDuration?.inMilliseconds,
       _repeat = repeat,
       _onTick = onTick,
       _onComplete = onComplete;
  
  /// 创建一个正计时器
  /// [interval] 触发间隔
  /// [repeat] 是否重复执行
  /// [onTick] 每次触发时的回调
  /// [onComplete] 计时器完成时的回调（非重复计时器）
  factory CTimer.forward({
    Duration interval = const Duration(seconds: 1),
    bool repeat = false,
    void Function(Duration)? onTick,
    void Function()? onComplete,
  }) {
    return CTimer._(
      interval: interval,
      isCountdown: false,
      repeat: repeat,
      onTick: onTick,
      onComplete: onComplete,
    );
  }
  
  /// 创建一个倒计时器
  /// [totalDuration] 总倒计时时间
  /// [interval] 触发间隔
  /// [onTick] 每次触发时的回调
  /// [onComplete] 计时器完成时的回调
  factory CTimer.countdown({
    required Duration totalDuration,
    Duration interval = const Duration(seconds: 1),
    void Function(Duration)? onTick,
    void Function()? onComplete,
  }) {
    return CTimer._(
      interval: interval,
      isCountdown: true,
      totalDuration: totalDuration,
      repeat: false,
      onTick: onTick,
      onComplete: onComplete,
    );
  }
  
  /// 添加tick监听器
  void addTickListener(void Function(Duration) listener) {
    _tickListeners.add(listener);
  }
  
  /// 移除tick监听器
  void removeTickListener(void Function(Duration) listener) {
    _tickListeners.remove(listener);
  }
  
  /// 添加完成监听器
  void addCompleteListener(void Function() listener) {
    _completeListeners.add(listener);
  }
  
  /// 移除完成监听器
  void removeCompleteListener(void Function() listener) {
    _completeListeners.remove(listener);
  }
  
  /// 开始计时
  void start() {
    if (_status == TimerStatus.running) {
      return;
    }
    
    if (_status == TimerStatus.paused) {
      // 从暂停恢复
      final pauseDuration = DateTime.now().millisecondsSinceEpoch - _pauseTime;
      _startTime += pauseDuration;
    } else {
      // 全新开始
      _startTime = DateTime.now().millisecondsSinceEpoch;
      _elapsedBeforePause = 0;
    }
    
    _status = TimerStatus.running;
    _startTimer();
  }
  
  /// 启动内部计时器
  void _startTimer() {
    _timer?.cancel();
    
    _timer = Timer.periodic(_interval, (timer) {
      if (_status != TimerStatus.running) {
        timer.cancel();
        return;
      }
      
      final currentElapsed = elapsed;
      
      // 检查倒计时是否完成
      if (_isCountdown && _totalDuration != null) {
        if (currentElapsed.inMilliseconds >= _totalDuration!) {
          _status = TimerStatus.completed;
          timer.cancel();
          
          // 触发完成回调
          _onComplete?.call();
          for (final listener in _completeListeners) {
            listener();
          }
          return;
        }
      } else if (!_repeat && !_isCountdown) {
        // 非重复正计时器，只执行一次
        _status = TimerStatus.completed;
        timer.cancel();
        
        // 触发完成回调
        _onComplete?.call();
        for (final listener in _completeListeners) {
          listener();
        }
        return;
      }
      
      // 触发tick回调
      _onTick?.call(currentElapsed);
      for (final listener in _tickListeners) {
        listener(currentElapsed);
      }
    });
  }
  
  /// 暂停计时
  void pause() {
    if (_status != TimerStatus.running) {
      return;
    }
    
    _status = TimerStatus.paused;
    _pauseTime = DateTime.now().millisecondsSinceEpoch;
    _elapsedBeforePause = elapsed.inMilliseconds;
    _timer?.cancel();
    _timer = null;
  }
  
  /// 恢复计时（从暂停状态）
  void resume() {
    if (_status != TimerStatus.paused) {
      return;
    }
    
    start();
  }
  
  /// 重置计时器
  void reset() {
    _timer?.cancel();
    _timer = null;
    _status = TimerStatus.stopped;
    _startTime = 0;
    _elapsedBeforePause = 0;
    _pauseTime = 0;
  }
  
  /// 停止计时器
  void stop() {
    reset();
  }
  
  /// 重启计时器
  void restart() {
    reset();
    start();
  }
  
  /// 销毁计时器，释放资源
  void dispose() {
    reset();
    _tickListeners.clear();
    _completeListeners.clear();
  }
}
