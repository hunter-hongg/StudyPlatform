import 'package:flutter/material.dart';
import 'package:study_platform/logic/trade.dart';
import 'package:study_platform/tool/fileinter.dart';
import 'package:study_platform/vars/files.dart';
import 'package:study_platform/vars/simple.dart';

class Ajuan {
  static int getLevel(int zhi) {
    if (0 <= zhi && zhi < 50) {
      return 1;
    } else if (50 <= zhi && zhi < 100) {
      return 2;
    } else if (100 <= zhi && zhi < 150) {
      return 3;
    } else if (150 <= zhi && zhi < 200) {
      return 4;
    } else if (200 <= zhi) {
      return 5;
    } else {
      return 0;
    }
  }

  static int getHuangj(int lev) {
    switch (lev) {
      case 0:
        return 0;
      case 1:
        return 10;
      case 2:
        return 20;
      case 3:
        return 35;
      case 4:
        return 40;
      case 5:
        return 55;
      default:
        return 10;
    }
  }

  static void dealGuwan<T extends MinusAble>(
    BuildContext context,
    int yin,
    int zhi,
    String desc,
    T fp,
  ) {
    Trade.tradeFFunc(context, fp, desc, 1, () {
      Files.aBaiYinReader().addNumSync(yin);
      Files.aJuanZhiReader().addNumSync(zhi);
      Simple.simpleInfo(
        context: context,
        show: "捐献成功",
      );
    });
  }
}
