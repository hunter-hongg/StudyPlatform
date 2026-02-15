import 'package:flutter/material.dart';
import 'package:study_platform/logic/xianhe.dart';
import 'package:study_platform/vars/files.dart';
import 'package:study_platform/vars/simple.dart';

class XianThingDanHePage extends StatefulWidget {
  const XianThingDanHePage({super.key});

  @override
  State<XianThingDanHePage> createState() => _XianThingDanHePageState();
}

class _XianThingDanHePageState extends State<XianThingDanHePage> {
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: Simple.simpleBar(
        title: '仙丹召鹤',
        back: Simple.backButton(
            context: context, route: '/xianpage/thingpage/danpage'),
      ),
      body: Center(
        child: Column(
          children: [
            const SizedBox(height: 140),
            Simple.simpleClick(
              func: () {
                XianHe.zhao(context, XianDan.yinDan(), 700, 80);
              },
              show: '银丹召鹤',
            ),
            Simple.simpleSpace(),
            Simple.simpleClick(
              func: () {
                XianHe.zhao(context, XianDan.jinDan(), 1500, 200);
              },
              show: '金丹召鹤',
            ),
            Simple.simpleSpace(),
            Simple.simpleClick(
              func: () {
                XianHe.zhao(context, XianDan.shenDan(), 3500, 450);
              },
              show: '神丹召鹤',
            ),
          ],
        ),
      ),
    );
  }
}
