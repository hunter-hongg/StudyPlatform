import 'package:flutter/material.dart';
import 'package:flutter_riverpod/flutter_riverpod.dart';
import 'package:study_platform/logic/bank.dart';
import 'package:study_platform/vars/files.dart';
import 'package:study_platform/vars/simple.dart';
import 'package:study_platform/vars/styles.dart';

class BankJuanJiangJifPage extends ConsumerWidget {
  const BankJuanJiangJifPage({super.key});

  @override
  Widget build(BuildContext context, WidgetRef ref) {
    final TextEditingController toGet = TextEditingController();
    return Scaffold(
      appBar: Simple.simpleBar(
        title: '积分奖励',
        back: Simple.backButton(context: context, route: '/bankpage/juanpage/jiangpage'),
      ),
      body: Center(
        child: Column(
          children: [
            const SizedBox(height: 5),
            Text(
                '捐献券: ${Files.bankJReader().readStrSafeSync()}\n'
                '积分: ${Files.jiFenReader().readStrSafeSync()}',
                style: Styles.showstrStyle()),
            const SizedBox(height: 120),
            Simple.simpleText(show: "请输入使用的捐献券数量"),
            Simple.simpleSpace(),
            Simple.simpleInput(
              controller: toGet,
              label: '请输入捐献券数量',
              hint: '请输入捐献券数量',
            ),
            Simple.simpleSpace(),
            Simple.simpleClick(
              func: () {
                Bank.juanToJif(context, toGet.text);
              },
              show: '领取',
            ),
          ],
        ),
      ),
    );
  }
}
