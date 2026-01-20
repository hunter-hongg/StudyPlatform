import 'package:flutter/widgets.dart';
import 'package:study_platform/vars/files.dart';
import 'package:study_platform/vars/simple.dart';

class Baoshi {
  static void get(BuildContext context, int jifenMinus, int baoshiAdd) {
    if (!Files.jiFenReader().canMinusSafeSync(jifenMinus)) {
      Simple.simpleInfo(context: context, show: "积分不足");
      return;
    }
    Files.baoShiReader().addNumSync(baoshiAdd);
    Navigator.pushNamed(
        context, '/ownpage/thingpage/mainpage/baoshipage/getpage');
    Simple.simpleInfo(context: context, show: "兑换成功");
  }
}
