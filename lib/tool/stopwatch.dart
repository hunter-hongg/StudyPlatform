enum StopWatchStatus {
  running,
  paused,
  stopped,
}

class StopwatchManager {
  final Stopwatch _stopwatch = Stopwatch();
  StopWatchStatus _status = StopWatchStatus.stopped;

  /// 开始计时
  void start() {
    _stopwatch.start();
    _status = StopWatchStatus.running;
  }

  /// 暂停计时
  void pause() {
    _stopwatch.stop();
    _status = StopWatchStatus.paused;
  }

  /// 恢复计时
  void resume() {
    _stopwatch.start();
    _status = StopWatchStatus.running;
  }

  /// 重置计时
  void reset() {
    _stopwatch.reset();
    _status = StopWatchStatus.stopped;
  }

  /// 获取当前已过去的时间
  Duration get elapsed => _stopwatch.elapsed;

  StopWatchStatus get status => _status;

  /// 格式化显示时间
  String formatTime() {
    final elapsed = _stopwatch.elapsed;
    final hours = elapsed.inHours.toString().padLeft(2, '0');
    final minutes = (elapsed.inMinutes % 60).toString().padLeft(2, '0');
    final seconds = (elapsed.inSeconds % 60).toString().padLeft(2, '0');
    final milliseconds =
        (elapsed.inMilliseconds % 1000).toString().padLeft(3, '0');

    return '$hours:$minutes:$seconds.$milliseconds';
  }
}
