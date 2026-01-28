import 'package:flutter/material.dart';
import 'package:study_platform/logic/trade.dart';
import 'package:study_platform/tool/check_file.dart';
import 'package:study_platform/tool/file_password.dart';

class Free {
  static void get(
      BuildContext context, FilePassword fp, CheckFile cp, int addnum, String desc) {
    Trade.tradeCheck(
      context,
      fp,
      cp,
      addnum,
      customMessage: "成功领取$addnum$desc",
    );
  }
}
