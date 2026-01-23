import 'package:flutter/material.dart';
import 'package:flutter_riverpod/flutter_riverpod.dart';
import 'package:study_platform/logic/tongy.dart';
import 'package:study_platform/vars/files.dart';
import 'package:study_platform/vars/simple.dart';
import 'package:study_platform/vars/styles.dart';

class TongyPage extends ConsumerWidget {
  const TongyPage({super.key});

  @override
  Widget build(BuildContext context, WidgetRef ref) {
    return Scaffold(
      appBar: Simple.simpleBar(
        title: '通用货币',
        back: Simple.backButton(context: context, route: '/ownpage'),
      ),
      body: Center(
        child: Column(
          children: [
            const SizedBox(height: 5),
            Text('通用货币: ${Files.tongYongReader().readStrSafeSync()}',
                style: Styles.showstrStyle()),
            const SizedBox(height: 130),
            Simple.simpleClick(
              func: () {
                Simple.simpleInfo(context: context, show: Tongy.getRule());
              },
              show: "兑换规则",
            ),
            Simple.simpleSpace(),
            Simple.simpleClick(
              func: () {
                Navigator.pushNamed(context, '/ownpage/tongypage/jifenpage');
              },
              show: "积分兑换",
            ),
          ],
        ),
      ),
    );
  }
}
