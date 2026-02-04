import 'package:flutter/widgets.dart';
import 'package:study_platform/logic/trade.dart';
import 'package:study_platform/tool/addfile.dart';
import 'package:study_platform/tool/file_password.dart';
import 'package:study_platform/vars/files.dart';

class Shopgu {
  static void dealA(BuildContext context, int minus, AddFile fp) {
    Trade.tradeAdd(
      context,
      Files.aBaiYinReader(),
      fp,
      "白银",
      minus,
      1,
    );
  }

  static void dealP(BuildContext context, int minus, FilePassword fp) {
    Trade.trade(
      context,
      Files.aBaiYinReader(),
      fp,
      "白银",
      minus,
      1,
    );
  }
}
