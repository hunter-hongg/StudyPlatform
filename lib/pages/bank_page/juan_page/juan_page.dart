import 'package:flutter/material.dart';
import 'package:flutter_riverpod/flutter_riverpod.dart';
import 'package:study_platform/vars/files.dart';
import 'package:study_platform/vars/simple.dart';
import 'package:study_platform/vars/styles.dart';

class BankJuanPage extends ConsumerWidget {
  const BankJuanPage({super.key});

  @override
  Widget build(BuildContext context, WidgetRef ref) {
    return Scaffold(
      appBar: Simple.simpleBar(
        title: '积分捐献',
        back: Simple.backButton(context: context, route: '/bankpage'),
      ),
      body: Center(
        child: Column(
          children: [
            const SizedBox(height: 5),
            Text('捐献券: ${Files.bankJReader().readStrSafeSync()}',
                style: Styles.showstrStyle()),
            const SizedBox(height: 110),
            Simple.simpleClick(
              func: () {
                Navigator.pushNamed(context, '/bankpage/juanpage/realpage');
              },
              show: "捐献积分",
            ),
            Simple.simpleSpace(),
            Simple.simpleClick(
              func: () {
                Navigator.pushNamed(context, '/bankpage/juanpage/jiangpage');
              },
              show: "领取奖励",
            ),
          ],
        ),
      ),
    );
  }
}
