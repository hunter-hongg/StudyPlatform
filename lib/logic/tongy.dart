import 'package:flutter/material.dart';
import 'package:study_platform/tool/file_password.dart';
import 'package:study_platform/vars/files.dart';
import 'package:study_platform/vars/simple.dart';

enum TongyReturn {
  success,
  userErr,
  systemErr,
  otherErr,
}

class Tongy {
  static List<(int, int, String, FilePassword)> get _rule {
    return [
      (1000, 1, "积分", Files.jiFenReader()),
    ];
  }

  static List<(int, int, String, FilePassword)> get rules => _rule;

  static String getRule() {
    var rule = "通用货币兑换规则:";
    for (int i = 0; i < _rule.length; ++i) {
      rule += "\n${_rule[i].$1}${_rule[i].$3} <=> ${_rule[i].$2}通用货币";
    }
    return rule;
  }

  static int dealRule(BuildContext context, String type, String gets) {
    int? get = int.tryParse(gets);
    if (get == null) {
      Simple.simpleWarn(context: context, show: "数字解析失败");
      return -2;
    }
    int mark = -1;
    for (int i = 0; i < _rule.length; ++i) {
      if (_rule[i].$3 == type) {
        mark = i;
        break;
      }
    }
    if (mark == -1) {
      Simple.simpleWarn(context: context, show: "系统错误: 错误的兑换规则");
      return -1;
    }
    var rule = _rule[mark];
    var need = get * rule.$1;
    if (!rule.$4.canMinusSafeSync(need)) {
      Simple.simpleInfo(context: context, show: "对应物品不足");
      return -2;
    }
    Files.tongYongReader().addNumSync(get);
    Navigator.pushNamed(context, '/ownpage/tongypage/jifenpage');
    Simple.simpleInfo(context: context, show: "兑换成功");
    return 0;
  }
}

extension ToTongyReturn on int {
  TongyReturn toTongyReturn() {
    switch (this) {
      case 0:
        return TongyReturn.success;
      case -1:
        return TongyReturn.systemErr;
      case -2:
        return TongyReturn.userErr;
      default:
        return TongyReturn.otherErr;
    }
  }
}
