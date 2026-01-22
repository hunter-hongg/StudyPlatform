import 'package:flutter/material.dart';
import 'package:flutter_riverpod/flutter_riverpod.dart';
import 'package:study_platform/logic/baoshi.dart';
import 'package:study_platform/vars/files.dart';
import 'package:study_platform/vars/simple.dart';

class ThingMainBaoshiChou1Page extends ConsumerWidget {
  const ThingMainBaoshiChou1Page({super.key});

  @override
  Widget build(BuildContext context, WidgetRef ref) {
    return Scaffold(
      appBar: Simple.simpleBar(
        title: '宝石抽奖',
        back: Simple.backButton(
            context: context,
            route: '/ownpage/thingpage/mainpage/baoshipage/cpage'),
      ),
      body: Center(
        child: Column(
          children: [
            const SizedBox(height: 10),
            Simple.simpleShowText(
              show: "宝石: ${Files.baoShiReader().readStrSafeSync()}",
            ),
            const SizedBox(height: 140),
            Simple.simpleClick(
              func: () {
                Simple.simpleInfo(
                  context: context,
                  show: Baoshi.c1Rule(),
                );
              },
              show: "抽奖规则",
            ),
            Simple.simpleSpace(),
            Simple.simpleClick(
              func: () {
                Baoshi.c1Exec(context);
              },
              show: "进行抽奖",
            ),
          ],
        ),
      ),
    );
  }
}
