import 'dart:math';

import '../vars/files.dart';

class AWuBing {
  static int bingPlus(int now, int min) {
    return max(((now - min) ~/ 5) * 10 + 7, 0);
  }

  static int bingSum() {
    return (WuVar.xinLr().readIntSafeSync() * WuVar.xinIr().readIntSafeSync() +
        WuVar.puTongLr().readIntSafeSync() *
            WuVar.puTongIr().readIntSafeSync() +
        WuVar.chuJiLr().readIntSafeSync() * WuVar.chuJiIr().readIntSafeSync() +
        WuVar.zhongJiLr().readIntSafeSync() *
            WuVar.zhongJiIr().readIntSafeSync() +
        WuVar.gaoJiLr().readIntSafeSync() * WuVar.gaoJiIr().readIntSafeSync() +
        WuVar.jingRuiLr().readIntSafeSync() *
            WuVar.jingRuiIr().readIntSafeSync() +
        WuVar.wangPaiLr().readIntSafeSync() *
            WuVar.wangPaiIr().readIntSafeSync() +
        WuVar.shenJiLr().readIntSafeSync() *
            WuVar.shenJiIr().readIntSafeSync());
  }
}
