import 'package:flutter/material.dart';
import 'package:study_platform/vars/files.dart';
import 'package:study_platform/vars/simple.dart';
import 'package:study_platform/vars/styles.dart';

class XianPage extends StatefulWidget {
  const XianPage({super.key});

  @override
  State<XianPage> createState() => _XianPageState();
}

class _XianPageState extends State<XianPage> {
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: Simple.simpleBar(
        title: '神话传说',
        back: Simple.backButton(context: context, route: '/'),
      ),
      body: Center(
        child: Column(
          children: [
            const SizedBox(height: 5),
            Text('仙币: ${Files.xianBiReader().readStrSafeSync()}',
                style: Styles.showstrStyle()),
            const SizedBox(height: 140),
            Simple.simpleClick(
              func: () {
                Navigator.pushNamed(context, '/xianpage/lupage');
              },
              show: '我的待遇',
            ),
            Simple.simpleSpace(),
            Simple.simpleClick(
              func: () {
                Navigator.pushNamed(context, '/xianpage/fapage');
              },
              show: '我的法力',
            ),
          ],
        ),
      ),
    );
  }
}
