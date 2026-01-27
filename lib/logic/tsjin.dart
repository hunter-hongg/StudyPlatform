import 'package:flutter/material.dart';
import 'package:study_platform/logic/trade.dart';
import 'package:study_platform/tool/file_password.dart';
import 'package:study_platform/vars/files.dart';

class TSJin {
  static void trade(
      BuildContext context, FilePassword fp, int addNum, String desc) {
    Trade.trade(context, Files.jinBiReader(), fp, "金币", 1, addNum,
        route: '/thingpage/jinpage', customMessage: "成功领取$addNum$desc");
  }
}
