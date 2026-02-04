import 'package:flutter/widgets.dart';
import 'package:study_platform/tool/addfile.dart';
import 'package:study_platform/tool/check_file.dart';
import 'package:study_platform/tool/file_password.dart';
import 'package:study_platform/vars/simple.dart';

class Trade {
  static void trade(
    BuildContext context,
    FilePassword fp1,
    FilePassword fp2,
    String thing1s,
    int thing1min,
    int thing2add, {
    String? route,
    String? customMessage,
  }) {
    if (!fp1.canMinusSafeSync(thing1min)) {
      Simple.simpleInfo(
        context: context,
        show: "$thing1s 不足",
      );
      return;
    }
    fp2.addNumSync(thing2add);
    if (route != null) {
      Navigator.pushNamed(context, route);
    }
    Simple.simpleInfo(
      context: context,
      show: customMessage ?? "兑换成功",
    );
  }

  static void tradeCheck(
    BuildContext context,
    FilePassword fp,
    CheckFile cp,
    int addnum, {
    String? route,
    String customMessage = "兑换成功",
  }) {
    if (!cp.checkTimesSync()) {
      Simple.simpleInfo(
        context: context,
        show: "今日次数使用完毕",
      );
      return;
    }
    fp.addNumSync(addnum);
    if (route != null) {
      Navigator.pushNamed(context, route);
    }
    Simple.simpleInfo(
      context: context,
      show: customMessage,
    );
  }

  static void tradeFunc(
    BuildContext context,
    FilePassword fp,
    String thing1s,
    int thing1min,
    void Function() func,
  ) {
    if (!fp.canMinusSafeSync(thing1min)) {
      Simple.simpleInfo(
        context: context,
        show: "$thing1s 不足",
      );
      return;
    }
    func();
  }

  static void tradeAdd(
    BuildContext context,
    FilePassword fp1,
    AddFile fp2,
    String thing1s,
    int thing1min,
    int thing2add, {
    String? route,
    String? customMessage,
  }) {
    if (!fp1.canMinusSafeSync(thing1min)) {
      Simple.simpleInfo(
        context: context,
        show: "$thing1s 不足",
      );
      return;
    }
    fp2.addNumSync(thing2add);
    if (route != null) {
      Navigator.pushNamed(context, route);
    }
    Simple.simpleInfo(
      context: context,
      show: customMessage ?? "兑换成功",
    );
  }

  static void tradePAdd(
    BuildContext context,
    AddFile fp1,
    FilePassword fp2,
    String thing1s,
    int thing1min,
    int thing2add, {
    String? route,
    String? customMessage,
  }) {
    if (!fp1.canMinus(thing1min)) {
      Simple.simpleInfo(
        context: context,
        show: "$thing1s 不足",
      );
      return;
    }
    fp2.addNumSync(thing2add);
    if (route != null) {
      Navigator.pushNamed(context, route);
    }
    Simple.simpleInfo(
      context: context,
      show: customMessage ?? "兑换成功",
    );
  }
}
