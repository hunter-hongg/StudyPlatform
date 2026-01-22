import 'package:flutter/widgets.dart';
import 'package:study_platform/tool/random.dart';
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

  static String c1Rule() {
    return "宝石抽奖1规则: \n"
        "100积分: 50%\n"
        "50仙币: 20%\n"
        "150铜钱: 20%\n"
        "5金币: 5%\n"
        "汉朝卡牌1*1: 5%\n"
        "消耗物品 2宝石\n";
  }

  static void c1Exec(BuildContext context) {
    if (!Files.baoShiReader().canMinusSafeSync(2)) {
      Simple.simpleInfo(
        context: context,
        show: "宝石不足",
      );
      return;
    }
    var choice = RandomGet.getIntClose(0, 100);
    int choiceType;
    String show = "";
    if (choice < 50) {
      choiceType = 1;
    } else if (choice < 70) {
      choiceType = 2;
    } else if (choice < 90) {
      choiceType = 3;
    } else if (choice < 95) {
      choiceType = 4;
    } else {
      choiceType = 5;
    }
    switch (choiceType) {
      case 1:
        show = "100积分";
        Files.jiFenReader().addNumSync(100);
      case 2:
        show = "50仙币";
        Files.xianBiReader().addNumSync(50);
      case 3:
        show = "150铜钱";
        Files.aTongQianReader().addNumSync(150);
      case 4:
        show = "5金币";
        Files.jinBiReader().addNumSync(5);
      case 5:
        var cres = RandomGet.getIntClose(0, CardStore.han1().get().length);
        show = "汉朝卡牌1: ${CardStore.han1().getByIndex(cres)}";
        CardStore.han1().write(cres);
      default:
        show = "错误物品";
    }
    Navigator.pushNamed(
        context, '/ownpage/thingpage/mainpage/baoshipage/cpage/c1page');
    Simple.simpleInfo(
      context: context,
      show: "恭喜获得: \n$show",
    );
  }
}
