import 'package:flutter/material.dart';
import 'package:study_platform/vars/files.dart';
import 'package:study_platform/vars/simple.dart';

class XianThingQiPage extends StatefulWidget {
  const XianThingQiPage({super.key});

  @override
  State<XianThingQiPage> createState() => _XianThingQiPageState();
}

class _XianThingQiPageState extends State<XianThingQiPage> {
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: Simple.simpleBar(
        title: '我的仙器',
        back: Simple.backButton(context: context, route: '/xianpage/thingpage'),
      ),
      body: Center(
        child: Column(
          children: [
            const SizedBox(height: 5),
            Simple.simpleShowText(
                show: "当前仙器: ${Special.xianSword().get().toString()}"),
            const SizedBox(height: 140),
            Simple.simpleClick(
              func: () {
                Navigator.pushNamed(context, '/xianpage/thingpage/danpage');
              },
              show: '我的仙丹',
            ),
            Simple.simpleSpace(),
            Simple.simpleClick(
              func: () {
                Navigator.pushNamed(context, '/xianpage/thingpage/qipage');
              },
              show: '我的仙器',
            ),
          ],
        ),
      ),
    );
  }
}
