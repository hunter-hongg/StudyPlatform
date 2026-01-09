// example/usage_example.dart
import 'package:study_platform/tool/timer.dart';

void main() async {
  print('=== 示例1: 正计时器 ===');
  final stopwatchTimer = CTimer.forward(
    interval: Duration(seconds: 1),
    repeat: true,
    onTick: (elapsed) {
      print('运行时间: ${elapsed.inSeconds} 秒');
    },
  );
  
  stopwatchTimer.start();
  await Future.delayed(Duration(seconds: 3));
  stopwatchTimer.pause();
  print('暂停后时间: ${stopwatchTimer.elapsed.inSeconds} 秒');
  
  await Future.delayed(Duration(seconds: 2));
  stopwatchTimer.resume();
  await Future.delayed(Duration(seconds: 2));
  stopwatchTimer.stop();
  
  print('\n=== 示例2: 倒计时器 ===');
  final countdownTimer = CTimer.countdown(
    totalDuration: Duration(seconds: 5),
    interval: Duration(seconds: 1),
    onTick: (elapsed) {
      // print('剩余时间: ${countdownTimer.remaining?.inSeconds} 秒');
    },
    onComplete: () {
      print('倒计时完成！');
    },
  );
  
  countdownTimer.start();
  await Future.delayed(Duration(seconds: 6));
  
  print('\n=== 示例3: 监听器 ===');
  final timerWithListeners = CTimer.forward(
    interval: Duration(milliseconds: 500),
    repeat: true,
  );
  
  timerWithListeners.addTickListener((elapsed) {
    print('监听器1: ${elapsed.inMilliseconds}ms');
  });
  
  timerWithListeners.addTickListener((elapsed) {
    print('监听器2: ${elapsed.inMilliseconds}ms');
  });
  
  timerWithListeners.start();
  await Future.delayed(Duration(seconds: 2));
  timerWithListeners.dispose();
}