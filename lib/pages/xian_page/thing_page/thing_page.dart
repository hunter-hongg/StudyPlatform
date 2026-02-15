import 'package:flutter/material.dart';
import 'package:study_platform/vars/simple.dart';

class XianThingPage extends StatefulWidget {
  const XianThingPage({super.key});

  @override
  State<XianThingPage> createState() => _XianThingPageState();
}

class _XianThingPageState extends State<XianThingPage> {
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: Simple.simpleBar(
        title: '我的物品',
        back: Simple.backButton(context: context, route: '/xianpage'),
      ),
      body: Center(
        child: Column(
          children: [
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
            Simple.simpleSpace(),
            Simple.simpleClick(
              func: () {
                Navigator.pushNamed(context, '/xianpage/thingpage/jipage');
              },
              show: '我的仙籍',
            ),
          ],
        ),
      ),
    );
  }
}
