import 'package:flutter/material.dart';
import 'package:study_platform/vars/files.dart';
import 'package:study_platform/vars/simple.dart';
import 'package:study_platform/tool/random.dart';

class JinMang {
  static void dealS(BuildContext context, int bei) {
    // 检查是否有足够的金币
    if (!Files.jinBiReader().canMinusSafeSync(bei * 5)) {
      Simple.simpleWarn(
        context: context,
        show: "取出金币失败",
      );
      return;
    }

    // 计算奖励值
    final addji = bei * 200 + RandomGet.getIntClose(-100, 100);
    final addba = bei * 15 + RandomGet.getIntClose(-5, 5);
    final addxi = bei * 75 + RandomGet.getIntClose(-25, 25);

    // 添加奖励
    Files.jiFenReader().addNumSync(addji);
    Files.baoShiReader().addNumSync(addba);
    Files.xianBiReader().addNumSync(addxi);

    Navigator.pushNamed(context, '/thingpage/mangpage');

    // 显示奖励信息
    Simple.simpleInfo(
      context: context,
      show: "恭喜获得: \n$addji积分\n$addba宝石\n$addxi仙币",
    );
  }

  static void dealA(BuildContext context, int bei) {
    // 检查是否有足够的金币
    if (!Files.jinBiReader().canMinusSafeSync(bei * 5)) {
      Simple.simpleWarn(
        context: context,
        show: "取出金币失败",
      );
      return;
    }

    // 计算铜钱奖励
    final addt = bei * 500 + RandomGet.getIntClose(-200, 400);

    // 添加铜钱奖励
    Files.aTongQianReader().addNumSync(addt);

    Navigator.pushNamed(context, '/thingpage/mangpage');

    // 显示奖励信息
    Simple.simpleInfo(
      context: context,
      show: "恭喜获得$addt铜钱",
    );
  }
}
