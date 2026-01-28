import 'package:flutter/material.dart';
import 'package:study_platform/tool/statefile.dart';
import 'package:study_platform/vars/simple.dart';

class StateDealing {
  static void dealState(BuildContext context, StateFile fp, bool def,
      void Function() func, String elseShow) {
    if (fp.readStateSync(def)) {
      func();
    } else {
      Simple.simpleInfo(context: context, show: elseShow);
    }
  }
}
