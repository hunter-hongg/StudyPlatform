import 'package:flutter/material.dart';
import 'package:flutter_riverpod/flutter_riverpod.dart';
import 'package:study_platform/logic/bank.dart';
import 'package:study_platform/vars/files.dart';
import 'package:study_platform/vars/simple.dart';
import 'package:study_platform/vars/styles.dart';

class BankJuanRealPage extends ConsumerWidget {
  const BankJuanRealPage({super.key});

  @override
  Widget build(BuildContext context, WidgetRef ref) {
    final TextEditingController toGet = TextEditingController();
    return Scaffold(
      appBar: Simple.simpleBar(
        title: '捐献积分',
        back: Simple.backButton(context: context, route: '/bankpage/juanpage'),
      ),
      body: Center(
        child: Column(
          children: [
            const SizedBox(height: 5),
            Text(
                '捐献券: ${Files.bankJReader().readStrSafeSync()}\n'
                '存储积分: ${Files.bankSReader().readStrSafeSync()}',
                style: Styles.showstrStyle()),
            const SizedBox(height: 120),
            Simple.simpleText(show: "请输入捐献的积分数"),
            Simple.simpleSpace(),
            Simple.simpleInput(
              controller: toGet,
              label: '请输入捐献数量',
              hint: '请输入捐献数量',
            ),
            Simple.simpleSpace(),
            Simple.simpleClick(
              func: () {
                Bank.juan(context, toGet.text);
              },
              show: '捐献',
            ),
          ],
        ),
      ),
    );
  }
}
