import 'package:flutter/material.dart';
import 'package:study_platform/logic/trade.dart';
import 'package:study_platform/tool/file_password.dart';
import 'package:study_platform/tool/random.dart';
import 'package:study_platform/vars/files.dart';
import 'package:study_platform/vars/simple.dart';

class XianHe {
  static void zhao(BuildContext context, FilePassword xd, int jifadd, int jinadd) {
    Trade.tradeFFunc(context, xd, '仙丹', 1, () {
      var rnd = RandomGet.getIntClose(-50, 110);
      var jifshow = jifadd + rnd;
      var jinshow = jinadd + rnd;
      Files.jiFenReader().addNumSync(jifshow);
      Files.jinBiReader().addNumSync(jinshow);
      Simple.simpleInfo(
        context: context,
        show: '召鹤成功，获得$jifshow积分和$jinshow金币',
      );
    });
  }
}
