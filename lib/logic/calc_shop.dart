import 'package:flutter/cupertino.dart';
import 'package:study_platform/tool/file_password.dart';
import 'package:study_platform/vars/files.dart';
import 'package:study_platform/vars/simple.dart';

class CalcShop {
  static void deal(BuildContext context, int minus, FilePassword fp, int add) {
    if (!Files.jiSuanBiReader().canMinusSafeSync(minus)) {
      Simple.simpleWarn(
        context: context,
        show: "计算币不足",
      );
      return;
    }
    fp.addNumSync(add);
    Navigator.pushNamed(context, '/calcpage/shoppage');
    Simple.simpleInfo(
      context: context,
      show: "兑换成功",
    );
  }

}