import 'package:flutter/material.dart';
import 'package:study_platform/tool/addfile.dart';
import 'package:study_platform/tool/random.dart';
import 'package:study_platform/vars/files.dart';
import 'package:study_platform/vars/simple.dart';

class AUseBooks {
  static void deal(BuildContext context) {
    // 检查铜钱是否足够（5铜钱）
    if (!Files.aTongQianReader().canMinusSafeSync(5)) {
      Simple.simpleInfo(context: context, show: "铜钱不足");
      return;
    }

    // 随机生成书籍类型（1-3）
    int restype = RandomGet.getIntClose(1, 3);
    
    AddFile? aff;
    int price = 0;
    String shows = "";
    
    switch (restype) {
      case 1:
        price = RandomGet.getIntClose(7, 20);
        aff = AddFiles.aBook1();
        shows = "普通书籍";
        break;
      case 2:
        price = RandomGet.getIntClose(18, 40);
        aff = AddFiles.aBook2();
        shows = "珍稀书籍";
        break;
      case 3:
        price = RandomGet.getIntClose(38, 60);
        aff = AddFiles.aBook3();
        shows = "典藏书籍";
        break;
      default:
        // 错误处理已在switch中覆盖所有情况
        return;
    }
    
    // 检查书籍是否足够
    if (!aff.canMinusSync(1)) {
      Simple.simpleInfo(context: context, show: "书籍不足");
      return;
    }
    
    // 添加白银并显示结果
    Files.aBaiYinReader().addNumSync(price);
    Simple.simpleInfo(
      context: context, 
      show: "叫卖成功\n卖出一本$shows\n获得$price白银"
    );
  }
}