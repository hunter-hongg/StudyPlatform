import 'package:flutter/material.dart';
import 'package:flutter_riverpod/flutter_riverpod.dart';
import 'package:study_platform/logic/free.dart';
import 'package:study_platform/vars/files.dart';
import 'package:study_platform/vars/simple.dart';

class TSFreePage extends ConsumerWidget {
  const TSFreePage({super.key});

  @override
  Widget build(BuildContext context, WidgetRef ref) {
    return Scaffold(
      appBar: Simple.simpleBar(
        title: '免费领取',
        back: Simple.backButton(context: context, route: '/thingpage'),
      ),
      body: Center(
        child: Column(
          children: [
            const SizedBox(height: 120),
            Simple.simpleClick(
              show: '免费积分',
              func: () {
                Free.get(
                  context,
                  Files.jiFenReader(),
                  CheckFiles.tsJifenCheck(),
                  20,
                  '积分',
                );
              },
            ),
            Simple.simpleSpace(),
            Simple.simpleClick(
              show: '免费仙币',
              func: () {
                Free.get(
                  context,
                  Files.xianBiReader(),
                  CheckFiles.tsXianbiCheck(),
                  5,
                  '仙币',
                );
              },
            ),
            Simple.simpleSpace(),
            Simple.simpleClick(
              show: '免费铜钱',
              func: () {
                Free.get(
                  context,
                  Files.aTongQianReader(),
                  CheckFiles.tsTongqianCheck(),
                  25,
                  '铜钱',
                );
              },
            ),
            Simple.simpleSpace(),
            Simple.simpleClick(
              show: '免费宝石',
              func: () {
                Free.get(
                  context,
                  Files.baoShiReader(),
                  CheckFiles.tsBaoshiCheck(),
                  1,
                  '宝石',
                );
              },
            ),
            Simple.simpleSpace(),
            Simple.simpleClick(
              show: '免费金币',
              func: () {
                Free.get(
                  context,
                  Files.jinBiReader(),
                  CheckFiles.tsJinbiCheck(),
                  1,
                  '金币',
                );
              },
            ),
          ],
        ),
      ),
    );
  }
}
