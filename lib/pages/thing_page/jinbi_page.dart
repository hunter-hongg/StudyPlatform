import 'package:flutter/material.dart';
import 'package:flutter_riverpod/flutter_riverpod.dart';
import 'package:study_platform/logic/tsjin.dart';
import 'package:study_platform/vars/files.dart';
import 'package:study_platform/vars/simple.dart';

class TSJinPage extends ConsumerWidget {
  const TSJinPage({super.key});

  @override
  Widget build(BuildContext context, WidgetRef ref) {
    return Scaffold(
      appBar: Simple.simpleBar(
        title: '金币领取',
        back: Simple.backButton(context: context, route: '/thingpage'),
      ),
      body: Center(
        child: Column(
          children: [
            const SizedBox(height: 5),
            Simple.simpleShowText(
                show: "金币: ${Files.jinBiReader().readStrSafeSync()}"),
            const SizedBox(height: 120),
            Simple.simpleClick(
              show: '领取宝石',
              func: () {
                TSJin.trade(
                  context,
                  Files.baoShiReader(),
                  8,
                  '宝石',
                );
              },
            ),
            Simple.simpleSpace(),
            Simple.simpleClick(
              show: '领取仙币',
              func: () {
                TSJin.trade(
                  context,
                  Files.xianBiReader(),
                  50,
                  '仙币',
                );
              },
            ),
            Simple.simpleSpace(),
            Simple.simpleClick(
              show: '领取铜钱',
              func: () {
                TSJin.trade(
                  context,
                  Files.aTongQianReader(),
                  65,
                  '铜钱',
                );
              },
            ),
          ],
        ),
      ),
    );
  }
}
