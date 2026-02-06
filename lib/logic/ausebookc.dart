import 'package:flutter/material.dart';
import 'package:study_platform/logic/bookchao.dart';
import 'package:study_platform/tool/addfile.dart';
import 'package:study_platform/vars/files.dart';
import 'package:study_platform/vars/simple.dart';

class AUseBookc {
  /// 处理抄录逻辑
  static void deal(BuildContext context) {
    // 检查白银是否足够
    if (!Files.aBaiYinReader().canMinusSafeSync(5)) {
      Simple.simpleInfo(context: context, show: "白银不足");
      return;
    }

    // 计算所需材料
    CalcNeedResult result = BookChao.calcNeed();

    // 检查黄金是否足够
    if (!Files.aHuangJinReader().highSync(result.hj)) {
      Simple.simpleInfo(context: context, show: "黄金不足");
      return;
    }

    // 检查各级书籍是否足够
    if (!AddFiles.aBook1().high(result.lv1)) {
      Simple.simpleInfo(context: context, show: "书籍不足");
      return;
    }

    if (!AddFiles.aBook2().high(result.lv2)) {
      Simple.simpleInfo(context: context, show: "书籍不足");
      return;
    }

    if (!AddFiles.aBook3().high(result.lv3)) {
      Simple.simpleInfo(context: context, show: "书籍不足");
      return;
    }

    // 扣除消耗的材料
    Files.aHuangJinReader().minusNumSync(result.hj);
    AddFiles.aBook1().addNumSync(-result.lv1);
    AddFiles.aBook2().addNumSync(-result.lv2);
    AddFiles.aBook3().addNumSync(-result.lv3);

    // 根据等级添加对应的抄录书籍
    List<AddFile> bookList = [
      AddFiles.aBookC1(),
      AddFiles.aBookC2(),
      AddFiles.aBookC3(),
      AddFiles.aBookC4(),
      AddFiles.aBookC5(),
    ];

    if (result.dj < 1 || result.dj > 5) {
      Simple.simpleInfo(context: context, show: "错误的抄录等级");
      return;
    }

    // 添加对应等级的抄录书籍
    bookList[result.dj - 1].addNumSync(1);

    // 显示成功信息
    Simple.simpleInfo(
      context: context,
      show: "抄录成功\n制作出一本${result.dj}级抄录书籍",
    );
  }
}
