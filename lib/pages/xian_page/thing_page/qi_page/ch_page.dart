import 'package:flutter/material.dart';
import 'package:study_platform/logic/xiansword.dart';
import 'package:study_platform/vars/files.dart';
import 'package:study_platform/vars/simple.dart';

class XianThingQiChPage extends StatefulWidget {
  const XianThingQiChPage({super.key});

  @override
  State<XianThingQiChPage> createState() => _XianThingQiChPageState();
}

class _XianThingQiChPageState extends State<XianThingQiChPage> {
  String xianSword = "";

  void update() {
    xianSword = Special.xianSword().get().toString();
  }

  List<Widget> buildUI() {
    List<Widget> wid = [], tmpWid = [];
    var swords = ["金剑", "木剑", "水剑", "火剑", "土剑"];
    for (int i = 0; i < swords.length; i++) {
      tmpWid.add(
        Simple.simpleClick(
          func: () {
            Special.xianSword().set(SwordEnum.fromInt(i));
            setState(() {
              update();
            });
          },
          show: swords[i],
        ),
      );
      if (i % 2 == 1) {
        wid += [
          Simple.simpleRow(widgets: tmpWid),
          Simple.simpleSpace(),
        ];
        tmpWid = [];
      }
    }

    wid += [
      Simple.simpleRow(widgets: tmpWid),
    ];
    return wid;
  }

  @override
  Widget build(BuildContext context) {
    update();
    return Scaffold(
      appBar: Simple.simpleBar(
        title: '更换仙器',
        back: Simple.backButton(
            context: context, route: '/xianpage/thingpage/qipage'),
      ),
      body: Center(
        child: Column(
          children: [
            const SizedBox(height: 5),
            Simple.simpleShowText(
              show: "当前仙器: $xianSword\n",
            ),
            const SizedBox(height: 130),
            ...buildUI(),
          ],
        ),
      ),
    );
  }
}
