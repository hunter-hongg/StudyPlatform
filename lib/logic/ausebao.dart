import 'package:flutter/widgets.dart';
import 'package:study_platform/logic/trade.dart';
import 'package:study_platform/tool/fileinter.dart';

class AUseBao {
  static void useBao(BuildContext context, MinusAble fp1, AddAble fp2,
      String thing1s, int thing2add) {
    Trade.tradeF(context, fp1, fp2, thing1s, 1, thing2add);
  }
}
