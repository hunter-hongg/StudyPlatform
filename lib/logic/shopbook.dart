import 'package:flutter/widgets.dart';
import 'package:study_platform/logic/trade.dart';
import 'package:study_platform/tool/addfile.dart';
import 'package:study_platform/vars/files.dart';

class Shopbook {
  static void sell(BuildContext context, int add, AddFile fp, int level) {
    Trade.tradePAdd(
      context,
      fp,
      Files.aBaiYinReader(),
      "抄录书籍$level级",
      1,
      add,
    );
  }
}
