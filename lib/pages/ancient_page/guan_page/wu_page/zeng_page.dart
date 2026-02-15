import 'package:flutter/material.dart';
import 'package:study_platform/logic/awubing.dart';
import 'package:study_platform/logic/trade.dart';
import 'package:study_platform/tool/file_password.dart';
import 'package:study_platform/vars/files.dart';
import 'package:study_platform/vars/simple.dart';

class AGWuZengPage extends StatefulWidget {
  const AGWuZengPage({super.key});

  @override
  State<AGWuZengPage> createState() => _AGWuZengPageState();
}

class _AGWuZengPageState extends State<AGWuZengPage> {
  int baiyin = 0;

  void update() {
    baiyin = Files.aBaiYinReader().readIntSafeSync();
  }

  List<Widget> buildUI(List<(String, FilePassword, int)> list) {
    var wid = <Widget>[], tmpWid = <Widget>[];
    for (var i = 0; i < list.length; i++) {
      tmpWid.add(Simple.simpleClick(
        func: () {
          Trade.trade(
            context,
            Files.aBaiYinReader(),
            list[i].$2,
            "白银",
            AWuBing.bingPlus(list[i].$2.readIntSafeSync(), list[i].$3),
            5,
            customMessage: "增强成功",
          );
          setState(() {
            update();
          });
        },
        show: '${list[i].$1}兵力: ${list[i].$2.readIntSafeSync()}',
      ));
      if (i % 3 == 2) {
        wid.add(Simple.simpleRow(
          widgets: tmpWid,
        ));
        wid.add(Simple.simpleSpace());
        tmpWid = [];
      }
    }
    if (tmpWid.isNotEmpty) {
      wid.add(Simple.simpleRow(
        widgets: tmpWid,
      ));
    }
    return wid;
  }

  List<(String, FilePassword, int)> list() {
    var tmpVar = [
      ('新兵', WuVar.xinIr(), WuConst.xinMin),
      ('普通兵', WuVar.puTongIr(), WuConst.puTongMin),
      ('初级兵', WuVar.chuJiIr(), WuConst.chuJiMin),
      ('中级兵', WuVar.zhongJiIr(), WuConst.zhongJiMin),
      ('高级兵', WuVar.gaoJiIr(), WuConst.gaoJiMin),
      ('精锐兵', WuVar.jingRuiIr(), WuConst.jingRuiMin),
      ('王牌兵', WuVar.wangPaiIr(), WuConst.wangPaiMin),
      ('神级兵', WuVar.shenJiIr(), WuConst.shenJiMin),
    ];
    return tmpVar;
  }

  @override
  Widget build(BuildContext context) {
    update();
    return Scaffold(
      appBar: Simple.simpleBar(
        title: '增强兵力',
        back: Simple.backButton(context: context, route: '/apage/gpage/wupage'),
      ),
      body: Center(
        child: Column(
          children: [
            const SizedBox(height: 10),
            Simple.simpleShowText(
              show: "白银: $baiyin\n"
                  "兵力: ${AWuBing.bingSum()}",
            ),
            const SizedBox(height: 115),
            Simple.nullSpace(),
            ...buildUI(list()),
          ],
        ),
      ),
    );
  }
}
