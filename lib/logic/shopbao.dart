import 'package:flutter/material.dart';
import 'package:study_platform/logic/trade.dart';
import 'package:study_platform/tool/addfile.dart';
import 'package:study_platform/vars/files.dart';

class Shopbao {
  static void deal(BuildContext context, int minus, AddFile fp) {
    Trade.tradeAdd(
      context,
      Files.aHuangJinReader(),
      fp,
      "黄金",
      minus,
      1,
    );
  }
}
