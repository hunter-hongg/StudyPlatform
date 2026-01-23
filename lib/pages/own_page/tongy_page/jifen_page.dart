import 'package:flutter/material.dart';
import 'package:flutter_riverpod/flutter_riverpod.dart';
import 'package:study_platform/logic/tongy.dart';
import 'package:study_platform/vars/files.dart';
import 'package:study_platform/vars/logger.dart';
import 'package:study_platform/vars/simple.dart';
import 'package:study_platform/vars/styles.dart';

class TongyJifenPage extends ConsumerWidget {
  const TongyJifenPage({super.key});

  @override
  Widget build(BuildContext context, WidgetRef ref) {
    final TextEditingController toTongy = TextEditingController();
    return Scaffold(
      appBar: Simple.simpleBar(
        title: '积分兑换',
        back: Simple.backButton(context: context, route: '/ownpage/tongypage'),
      ),
      body: Center(
        child: Column(
          children: [
            const SizedBox(height: 5),
            Text(
                '积分: ${Files.jiFenReader().readStrSafeSync()}\n'
                '通用货币: ${Files.tongYongReader().readStrSafeSync()}',
                style: Styles.showstrStyle()),
            const SizedBox(height: 120),
            Simple.simpleText(show: "请输兑换的通用货币数"),
            Simple.simpleSpace(),
            Simple.simpleInput(
              controller: toTongy,
              label: '请输入兑换通用货币数量',
              hint: '请输入兑换通用货币数量',
            ),
            Simple.simpleSpace(),
            Simple.simpleClick(
              func: () {
                var res =
                    Tongy.dealRule(context, "积分", toTongy.text).toTongyReturn();
                if (res == TongyReturn.systemErr) {
                  globalLogger.fatal("系统运行出错，退出");
                }
              },
              show: "兑换",
            ),
          ],
        ),
      ),
    );
  }
}
