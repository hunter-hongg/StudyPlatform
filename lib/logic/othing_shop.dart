import 'package:flutter/widgets.dart';
import 'package:study_platform/tool/cards.dart';
import 'package:study_platform/tool/file_password.dart';
import 'package:study_platform/tool/random.dart';
import 'package:study_platform/vars/files.dart';
import 'package:study_platform/vars/simple.dart';

class OthingShop {
  static void deal(
      BuildContext context, int jifenMin, FilePassword fp, int addNum) {
    if (!Files.jiFenReader().canMinusSafeSync(jifenMin)) {
      Simple.simpleInfo(
        context: context,
        show: "积分不足",
      );
      return;
    }
    fp.addNumSync(addNum);
    Navigator.pushNamed(context, '/ownpage/thingpage/shoppage');
    Simple.simpleInfo(
      context: context,
      show: "兑换成功",
    );
  }

  static void dealCard(
      BuildContext context, int jifenMin, Cards cp, int addNum) {
    if (!Files.jiFenReader().canMinusSafeSync(jifenMin)) {
      Simple.simpleInfo(
        context: context,
        show: "积分不足",
      );
      return;
    }
    var cdlist = <int>[];
    var showStr = "恭喜获得卡牌: ";
    final clen = cp.get().length;
    while (cdlist.length < addNum) {
      var randadd = RandomGet.getIntClose(0, clen);
      if ((randadd < 0) || (randadd >= clen)) continue;
      if (cdlist.contains(randadd)) continue;
      final showString = cp.getByIndex(randadd);
      showStr += "\n$showString - 稀有";
      cp.write(randadd);
      cdlist.add(randadd);
    }
    Navigator.pushNamed(context, '/ownpage/thingpage/shoppage');
    Simple.simpleInfo(
      context: context,
      show: showStr,
    );
  }
}
