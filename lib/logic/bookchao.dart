import 'package:study_platform/tool/random.dart';

/// 用于存储calcNeed结果的类
class CalcNeedResult {
  final int lv1;
  final int lv2;
  final int lv3;
  final int dj;
  final int hj;

  CalcNeedResult(this.lv1, this.lv2, this.lv3, this.dj, this.hj);
}

class BookChao {
  static CalcNeedResult calcNeed() {
    int lv3 = RandomGet.getIntClosed(1, 10);
    late int lv2;
    late int max;
    late int dj;
    late int hj;

    if (lv3 <= 1) {
      lv2 = RandomGet.getIntClosed(1, 2);
      max = 4;
      dj = 1;
      hj = 5;
    } else if (lv3 <= 2) {
      lv2 = RandomGet.getIntClosed(1, 2);
      max = 6;
      dj = 2;
      hj = 10;
    } else if (lv3 <= 5) {
      lv2 = RandomGet.getIntClosed(2, 4);
      max = 10;
      dj = 3;
      hj = 15;
    } else if (lv3 <= 7) {
      lv2 = RandomGet.getIntClosed(2, 5);
      max = 15;
      dj = 4;
      hj = 20;
    } else {  // lv3 <= 10
      lv2 = RandomGet.getIntClosed(3, 6);
      max = 20;
      dj = 5;
      hj = 30;
    }

    int lv1 = max - lv3 - lv2;
    return CalcNeedResult(lv1, lv2, lv3, dj, hj);
  }

  /// 根据dj值计算获得的数量
  static int calcGet(int dj) {
    switch (dj) {
      case 1:
        return 90;
      case 2:
        return 150;
      case 3:
        return 200;
      case 4:
        return 350;
      case 5:
        return 675;
      default:
        return -1;
    }
  }
}