import 'package:flutter/material.dart';
import 'package:flutter_riverpod/flutter_riverpod.dart';
import 'package:study_platform/vars/files.dart';
import 'package:study_platform/vars/simple.dart';
import 'package:study_platform/vars/styles.dart';

class BankJuanJiangPage extends ConsumerWidget {
  const BankJuanJiangPage({super.key});

  @override
  Widget build(BuildContext context, WidgetRef ref) {
    return Scaffold(
      appBar: Simple.simpleBar(
        title: '领取奖励',
        back: Simple.backButton(context: context, route: '/bankpage/juanpage'),
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
                Navigator.pushNamed(
                    context, '/bankpage/juanpage/jiangpage/jifenpage');
              },
              show: "积分奖励",
            ),
          ],
        ),
      ),
    );
  }
}
