import 'package:flutter/material.dart';
import 'package:flutter_riverpod/flutter_riverpod.dart';
import 'package:study_platform/vars/files.dart';
import 'package:study_platform/vars/simple.dart';
import 'package:study_platform/vars/styles.dart';

class OwnPage extends ConsumerWidget {
  const OwnPage({super.key});

  @override
  Widget build(BuildContext context, WidgetRef ref) {
    final jifenStr = Files.jiFenReader().readStrSync();

    return Scaffold(
      appBar: Simple.simpleBar(
        title: '个人主页',
        back: Simple.backButton(context: context, route: '/'),
      ),
      body: Center(
        child: Column(
          children: [
            const SizedBox(height: 5),
            Text('积分: $jifenStr', style: Styles.showstrStyle()),
            const SizedBox(height: 110),
            Simple.simpleClick(
              func: () {
                Navigator.pushNamed(context, '/ownpage/timepage');
              },
              show: "学习计时",
            ),
            Simple.simpleSpace(),
            Simple.simpleClick(
              func: () {
                Navigator.pushNamed(context, '/ownpage/lihepage');
              },
              show: "我的礼盒",
            ),
          ],
        ),
      ),
    );
  }
}
