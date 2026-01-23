import 'package:flutter/widgets.dart';
import 'package:study_platform/logic/trade.dart';
import 'package:study_platform/vars/files.dart';

class Bank {
  static void store(BuildContext context, String storeNumRaw) {
    int storeNum = int.tryParse(storeNumRaw) ?? 0;
    Trade.trade(context, Files.jiFenReader(), Files.bankSReader(), "积分",
        storeNum, storeNum, '/bankpage/storepage');
  }
}
