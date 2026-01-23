import 'package:flutter/material.dart';
import 'package:flutter_riverpod/flutter_riverpod.dart';
import 'package:study_platform/logic/bank.dart';
import 'package:study_platform/vars/files.dart';
import 'package:study_platform/vars/simple.dart';
import 'package:study_platform/vars/styles.dart';

class BankStorePage extends ConsumerWidget {
  const BankStorePage({super.key});

  @override
  Widget build(BuildContext context, WidgetRef ref) {
    final TextEditingController toStore = TextEditingController();
    return Scaffold(
      appBar: Simple.simpleBar(
        title: '存储积分',
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
            Simple.simpleText(show: "请输入存储的积分数"),
            Simple.simpleSpace(),
            Simple.simpleInput(
              controller: toStore,
              label: '请输入存储数量',
              hint: '请输入存储数量',
            ),
            Simple.simpleSpace(),
            Simple.simpleClick(
              func: () {
                Bank.store(context, toStore.text);
              },
              show: '存储',
            ),
          ],
        ),
      ),
    );
  }
}
