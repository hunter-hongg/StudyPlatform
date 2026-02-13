import 'package:flutter/material.dart';
import 'package:study_platform/vars/simple.dart';

class XianThingDanPage extends StatefulWidget {
  const XianThingDanPage({super.key});

  @override
  State<XianThingDanPage> createState() => _XianThingDanPageState();
}

class _XianThingDanPageState extends State<XianThingDanPage> {
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: Simple.simpleBar(
        title: '我的仙丹',
        back: Simple.backButton(context: context, route: '/xianpage/thingpage'),
      ),
      body: Center(
        child: Column(
          children: [
            const SizedBox(height: 140),
            Simple.simpleClick(
              func: () {
                Navigator.pushNamed(
                    context, '/xianpage/thingpage/danpage/showpage');
              },
              show: '仙丹查看',
            ),
            Simple.simpleSpace(),
            Simple.simpleClick(
              func: () {
                Navigator.pushNamed(
                    context, '/xianpage/thingpage/danpage/hepage');
              },
              show: '仙丹召鹤',
            ),
          ],
        ),
      ),
    );
  }
}
