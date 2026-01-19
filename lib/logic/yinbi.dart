import 'package:flutter/material.dart';
import 'package:study_platform/tool/cards.dart';
import 'package:study_platform/tool/random.dart';
import 'package:study_platform/vars/files.dart';
import 'package:study_platform/vars/simple.dart';

class Yinbi {
  static void dealCard2(BuildContext context, int minus, Cards cp1, Cards cp2,
      String scp1, String scp2, int cp1100) {
    if (!Files.yinBiReader().canMinusSafeSync(minus)) {
      Simple.simpleWarn(
        context: context,
        show: "银币不足",
      );
      return;
    }
    int randg = RandomGet.getIntClose(0, 100);
    Cards target;
    String showtarget;
    if (randg < cp1100) {
      target = cp1;
      showtarget = scp1;
    } else {
      target = cp2;
      showtarget = scp2;
    }
    int randcard = RandomGet.getIntClose(0, target.get().length);
    var randcname = target.getByIndex(randcard);
    target.write(randcard);
    Navigator.pushNamed(context, '/ownpage/thingpage/mainpage/yinbipage');
    Simple.simpleInfo(
        context: context, show: "恭喜获得: \n$showtarget - $randcname");
  }
}
