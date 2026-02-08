import 'package:flutter/material.dart';
import 'package:study_platform/tool/file_password.dart';
import 'package:study_platform/vars/files.dart';
import 'package:study_platform/vars/simple.dart';

class AGWuZhaoPage extends StatefulWidget {
  const AGWuZhaoPage({super.key});

  @override
  State<AGWuZhaoPage> createState() => _AGWuZhaoPageState();
}

class _AGWuZhaoPageState extends State<AGWuZhaoPage> {
  int baiyin = 0;

  void update() {
    baiyin = Files.aBaiYinReader().readIntSafeSync();
  }

  List<Widget> buildUI(List<(String, FilePassword)> list) {
    var wid = <Widget>[], tmpWid = <Widget>[];
    for (var i = 0; i < list.length; i++) {
      tmpWid.add(Simple.simpleClick(
        func: () {
          // ...
        },
        show: '${list[i].$1}: ${list[i].$2.readIntSafeSync()}名',
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

  List<(String, FilePassword)> get list => [
        ('新兵', WuVar.xinLr()),
        ('普通兵', WuVar.puTongLr()),
        ('初级兵', WuVar.chuJiLr()),
        ('中级兵', WuVar.zhongJiLr()),
        ('高级兵', WuVar.gaoJiLr()),
        ('精锐兵', WuVar.jingRuiLr()),
        ('王牌兵', WuVar.wangPaiLr()),
        ('神级兵', WuVar.shenJiLr()),
      ];

  @override
  Widget build(BuildContext context) {
    update();
    return Scaffold(
      appBar: Simple.simpleBar(
        title: '征召士兵',
        back: Simple.backButton(context: context, route: '/apage/gpage/wupage'),
      ),
      body: Center(
        child: Column(
          children: [
            const SizedBox(height: 10),
            Simple.simpleShowText(show: "白银: $baiyin"),
            const SizedBox(height: 125),
            Simple.nullSpace(),
            ...buildUI(list),
          ],
        ),
      ),
    );
  }
}
