import 'package:flutter/material.dart';
import 'package:flutter_riverpod/flutter_riverpod.dart';
import 'package:study_platform/vars/files.dart';
import 'package:study_platform/vars/simple.dart';
import 'package:study_platform/vars/styles.dart';

class CalcStartPage extends ConsumerWidget {
  const CalcStartPage({super.key});

  @override
  Widget build(BuildContext context, WidgetRef ref) {
    return Scaffold(
      appBar: Simple.simpleBar(
        title: '开始计算',
        back: Simple.backButton(context: context, route: '/calcpage'),
      ),
      body: Center(
        child: Column(
          children: [
            const SizedBox(height: 5),
            Text('计算币: ${Files.jiSuanBiReader().readStrSafeSync()}',
                style: Styles.showstrStyle()),
            const SizedBox(height: 110),
            Simple.simpleClick(
              func: () {
                Navigator.pushNamed(context, '/calcpage/startpage/addsubpage');
              },
              show: "加减练习",
            ),
            Simple.simpleSpace(),
            Simple.simpleClick(
              func: () {},
              show: "乘法练习",
            ),
            Simple.simpleSpace(),
            Simple.simpleClick(
              func: () {},
              show: "除法练习",
            ),
            Simple.simpleSpace(),
            Simple.simpleClick(
              func: () {},
              show: "因式分解",
            ),
          ],
        ),
      ),
    );
  }
}
