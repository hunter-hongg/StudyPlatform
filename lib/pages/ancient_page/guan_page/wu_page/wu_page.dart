import 'package:flutter/material.dart';
import 'package:study_platform/vars/simple.dart';

class AGWuPage extends StatefulWidget {
  const AGWuPage({super.key});

  @override
  State<AGWuPage> createState() => _AGWuPageState();
}

class _AGWuPageState extends State<AGWuPage> {
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: Simple.simpleBar(
        title: '武官官职',
        back: Simple.backButton(context: context, route: '/apage/gpage'),
      ),
      body: Center(
        child: Column(
          children: [
            const SizedBox(height: 150),
            Simple.simpleClick(
              func: () {
                Navigator.pushNamed(context, '/apage/gpage/wupage/zhaopage');
              },
              show: '征召士兵',
            ),
            Simple.simpleSpace(),
            Simple.simpleClick(
              func: () {
                Navigator.pushNamed(context, '/apage/gpage/wupage/zengpage');
              },
              show: '增强兵力',
            ),
            Simple.simpleSpace(),
            Simple.simpleClick(
              func: () {
                Navigator.pushNamed(context, '/apage/gpage/wupage/zhengpage');
              },
              show: '领兵出征',
            ),
          ],
        ),
      ),
    );
  }
}
