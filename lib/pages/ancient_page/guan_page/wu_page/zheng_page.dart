import 'package:flutter/material.dart';
import 'package:study_platform/logic/awuzheng.dart';
import 'package:study_platform/vars/simple.dart';

class AGWuZhengPage extends StatefulWidget {
  const AGWuZhengPage({super.key});

  @override
  State<AGWuZhengPage> createState() => _AGWuZhengPageState();
}

class _AGWuZhengPageState extends State<AGWuZhengPage> {
  List<Widget> buildUI() {
    List<Widget> wid = [], tmpWid = [];
    var choices = [
      Choices.jinGong,
      Choices.fangShou,
      Choices.xiuZheng,
      Choices.touXi,
    ];
    var show = [
      "进攻敌军",
      "防守城池",
      "休整兵马",
      "出其不意",
    ];
    for (var i = 0; i < choices.length; i++) {
      tmpWid.add(Simple.simpleClick(
        func: () {
          setState(() {
            aWuZhengDealWithChoice(context, choices[i], () {
              Navigator.pushNamed(context, '/apage/gpage/wupage');
            });
          });
        },
        show: show[i],
      ));
      if (tmpWid.length == 2) {
        wid.add(Simple.simpleRow(
          widgets: tmpWid,
        ));
        wid.add(Simple.simpleSpace());
        tmpWid = [];
      }
    }
    return wid;
  }

  @override
  Widget build(BuildContext context) {
    setState(() {
      aWuZhengInitialize();
    });
    return Scaffold(
      appBar: Simple.simpleBar(
        title: '领兵出征',
        back: Simple.backButton(context: context, route: '/apage/gpage/wupage'),
      ),
      body: Center(
        child: Column(
          children: [
            const SizedBox(height: 10),
            Simple.simpleShowText(
              show: "我的兵力: $aWuZhengMyBingl\n"
                  "敌方兵力: $aWuZhengOtherBingl",
            ),
            const SizedBox(height: 130),
            ...buildUI(),
          ],
        ),
      ),
    );
  }
}
