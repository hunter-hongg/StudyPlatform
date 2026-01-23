import 'package:flutter/material.dart';
import 'package:flutter_riverpod/flutter_riverpod.dart';
import 'package:study_platform/logic/bank.dart';
import 'package:study_platform/vars/files.dart';
import 'package:study_platform/vars/simple.dart';
import 'package:study_platform/vars/styles.dart';

class BankGetPage extends ConsumerWidget {
  const BankGetPage({super.key});

  @override
  Widget build(BuildContext context, WidgetRef ref) {
    final TextEditingController toGet = TextEditingController();
    return Scaffold(
      appBar: Simple.simpleBar(
        title: '获取积分',
        back: Simple.backButton(context: context, route: '/bankpage'),
      ),
      body: Center(
        child: Column(
          children: [
            const SizedBox(height: 5),
            Text(
                '积分: ${Files.jiFenReader().readStrSafeSync()}\n'
                '存储积分: ${Files.bankSReader().readStrSafeSync()}',
                style: Styles.showstrStyle()),
            const SizedBox(height: 120),
            Simple.simpleText(show: "请输入获取的积分数"),
            Simple.simpleSpace(),
            Simple.simpleInput(
              controller: toGet,
              label: '请输入获取数量',
              hint: '请输入获取数量',
            ),
            Simple.simpleSpace(),
            Simple.simpleClick(
              func: () {
                Bank.get(context, toGet.text);
              },
              show: '获取',
            ),
          ],
        ),
      ),
    );
  }
}
