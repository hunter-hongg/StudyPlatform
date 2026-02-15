import 'package:flutter/widgets.dart';
import 'package:study_platform/logic/awubing.dart';
import 'package:study_platform/tool/random.dart';
import 'package:study_platform/vars/files.dart';
import 'package:study_platform/vars/simple.dart';

// Choices 枚举类型
enum Choices {
  jinGong,
  xiuZheng,
  fangShou,
  touXi,
}

int aWuZhengMyBingl = -1;
int aWuZhengOtherBingl = -1;
List<Choices> aWuZhengUserChoice = [];

bool aWuZhengInitialize() {
  if (aWuZhengMyBingl < 0 && aWuZhengOtherBingl < 0) {
    var bsf = AWuBing.bingSum();
    var bot = AWuBing.bingSum() + RandomGet.getIntClose(-30, 30);
    if (bot <= 30) {
      bot = 30;
    }
    aWuZhengOtherBingl = bot;
    aWuZhengMyBingl = bsf;
    aWuZhengUserChoice = [];
    return true;
  }
  return false;
}

// GetResult 根据双方选择返回结果
(int, int) aWuZhengGetResult(Choices a, Choices b) {
  switch (a) {
    case Choices.jinGong:
      switch (b) {
        case Choices.jinGong:
          return (
            -30 + RandomGet.getIntClose(-5, 5),
            -30 + RandomGet.getIntClose(-5, 5),
          );
        case Choices.xiuZheng:
          return (
            -10 + RandomGet.getIntClose(-5, 5),
            -30 + RandomGet.getIntClose(-5, 5),
          );
        case Choices.fangShou:
          return (
            -35 + RandomGet.getIntClose(-5, 5),
            -5 + RandomGet.getIntClose(-5, 5),
          );
        case Choices.touXi:
          return (
            -20 + RandomGet.getIntClose(-5, 5),
            -40 + RandomGet.getIntClose(-5, 5),
          );
      }
    case Choices.xiuZheng:
      switch (b) {
        case Choices.jinGong:
          return (
            -30 + RandomGet.getIntClose(-5, 5),
            -10 + RandomGet.getIntClose(-5, 5),
          );
        case Choices.xiuZheng:
          return (
            20 + RandomGet.getIntClose(-5, 5),
            20 + RandomGet.getIntClose(-5, 5),
          );
        case Choices.fangShou:
          return (
            30 + RandomGet.getIntClose(-5, 5),
            -50 + RandomGet.getIntClose(-5, 5),
          );
        case Choices.touXi:
          return (
            -30 + RandomGet.getIntClose(-5, 5),
            -5 + RandomGet.getIntClose(-5, 5),
          );
      }
    case Choices.fangShou:
      switch (b) {
        case Choices.jinGong:
          return (
            -5 + RandomGet.getIntClose(-5, 5),
            -35 + RandomGet.getIntClose(-5, 5),
          );
        case Choices.xiuZheng:
          return (
            -50 + RandomGet.getIntClose(-5, 5),
            30 + RandomGet.getIntClose(-5, 5),
          );
        case Choices.fangShou:
          return (
            -20 + RandomGet.getIntClose(-5, 5),
            -20 + RandomGet.getIntClose(-5, 5),
          );
        case Choices.touXi:
          return (
            5 + RandomGet.getIntClose(-5, 5),
            -30 + RandomGet.getIntClose(-5, 5),
          );
      }
    case Choices.touXi:
      switch (b) {
        case Choices.jinGong:
          return (
            -40 + RandomGet.getIntClose(-5, 5),
            -20 + RandomGet.getIntClose(-5, 5),
          );
        case Choices.xiuZheng:
          return (
            -5 + RandomGet.getIntClose(-5, 5),
            -30 + RandomGet.getIntClose(-5, 5),
          );
        case Choices.fangShou:
          return (
            -30 + RandomGet.getIntClose(-5, 5),
            5 + RandomGet.getIntClose(-5, 5),
          );
        case Choices.touXi:
          return (
            -40 + RandomGet.getIntClose(-5, 5),
            -40 + RandomGet.getIntClose(-5, 5),
          );
      }
  }
}

// GetChoice 根据历史数据做出选择
Choices aWuZhengGetChoice(int other, int self, List<Choices> usrchoices) {
  int cha = self - other;
  if (cha < 0) {
    cha = -cha;
  }

  int usrcl = usrchoices.length;

  if (usrcl >= 4) {
    if (usrchoices[usrcl - 2] == usrchoices[usrcl - 3]) {
      Choices cho = usrchoices[usrcl - 2];
      Choices chk4 = usrchoices[usrcl - 4];
      Choices chk1 = usrchoices[usrcl - 1];

      if (cho == chk4 || cho == chk1) {
        switch (cho) {
          case Choices.jinGong:
            return Choices.fangShou;
          case Choices.fangShou:
            return Choices.xiuZheng;
          case Choices.xiuZheng:
            return Choices.jinGong;
          case Choices.touXi:
            return Choices.fangShou;
        }
      }
    }
  }

  if (self > other) {
    int t = RandomGet.getIntClose(0, 9);
    if (t < 4) {
      return Choices.jinGong;
    } else if (t < 6) {
      return Choices.xiuZheng;
    } else {
      return Choices.touXi;
    }
  } else if (cha < 90) {
    int t = RandomGet.getIntClose(0, 9);
    if (t < 2) {
      return Choices.jinGong;
    } else if (t < 4) {
      return Choices.xiuZheng;
    } else if (t < 8) {
      return Choices.fangShou;
    } else {
      return Choices.touXi;
    }
  } else {
    int t = RandomGet.getIntClose(0, 9);
    if (t < 2) {
      return Choices.jinGong;
    } else if (t < 8) {
      return Choices.fangShou;
    } else {
      return Choices.xiuZheng;
    }
  }
}

String aWuZhengToString(Choices ch) {
  switch (ch) {
    case Choices.jinGong:
      return "进攻敌军";
    case Choices.fangShou:
      return "防御敌军";
    case Choices.xiuZheng:
      return "休整兵马";
    case Choices.touXi:
      return "趁其不备";
  }
}

// DealWithChoice 处理用户选择并计算战斗结果
void aWuZhengDealWithChoice(
  BuildContext context,
  Choices evt,
  void Function() navigate,
) {
  // 添加用户选择到历史记录
  aWuZhengUserChoice.add(evt);

  // AI根据历史数据做出选择
  Choices oevt = aWuZhengGetChoice(
    aWuZhengOtherBingl,
    aWuZhengMyBingl,
    aWuZhengUserChoice,
  );

  // 计算战斗结果
  var (ress, reso) = aWuZhengGetResult(evt, oevt);

  String ops = ress > 0 ? "+" : "-";
  String opo = reso > 0 ? "+" : "-";

  // 更新兵力
  aWuZhengMyBingl += ress;
  aWuZhengOtherBingl += reso;

  // 显示战斗结果
  Simple.simpleInfo(
      context: context,
      show: "你的选择: ${aWuZhengToString(evt)}"
          "\n对方选择: ${aWuZhengToString(oevt)}"
          "\n你的兵力 $ops ${ress.abs().toString()}"
          "\n对方兵力 $opo ${reso.abs().toString()}");

  // 检查游戏结束条件
  if (aWuZhengOtherBingl < 0) {
    Simple.simpleInfo(
      context: context,
      show: "这次出征大获全胜\n胜不骄败不馁\n战果: 白银+550",
    );
    Files.aBaiYinReader().addNumSync(550);
    _resetGameState();
    navigate();
  } else if (aWuZhengMyBingl < 0) {
    Simple.simpleInfo(
      context: context,
      show: "这次出征败兵而归\n胜败乃兵家常事\n战果: 白银-50",
    );
    Files.aBaiYinReader().minusNumIfSync(50);
    _resetGameState();
    navigate();
  }
}

// 重置游戏状态
void _resetGameState() {
  aWuZhengOtherBingl = -1;
  aWuZhengMyBingl = -1;
  aWuZhengUserChoice.clear();
}
