import 'dart:math';

class RandomGet {
  static final Random _secureRandom = Random.secure();

  static Random getRandomDevice() {
    return _secureRandom;
  }

  /// 左闭右开
  static int getIntClosed(int min, int max) {
    return min + getRandomDevice().nextInt(max - min);
  }

  /// 全闭
  static int getIntClose(int min, int max) {
    return getIntClosed(min, max + 1);
  }

  static int getWith01() {
    if (getRandomDevice().nextBool()) {
      return 0;
    } else {
      return 1;
    }
  }
}
