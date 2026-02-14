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
              show: "当前仙器: ${Special.xianSword().get().toString()}\n"
                  "仙器法力: ${Files.xQiFaLiReader().readStrSafeSync()}",
            ),
            const SizedBox(height: 120),
            Simple.simpleClick(
              func: () {
                Navigator.pushNamed(
                    context, '/xianpage/thingpage/qipage/chpage');
              },
              show: '更换仙器',
            ),
            Simple.simpleSpace(),
            Simple.simpleClick(
              func: () {
                Simple.simpleInfo(context: context, show: '请使用仙籍增强仙器法力');
              },
              show: '增强仙器',
            ),
          ],
        ),
      ),
    );
  }
}
