import 'package:flutter/material.dart';
import 'package:flutter_riverpod/flutter_riverpod.dart';
import 'package:study_platform/logic/yinbi.dart';
import 'package:study_platform/vars/files.dart';
import 'package:study_platform/vars/simple.dart';

class ThingMainYinbiPage extends ConsumerWidget {
  const ThingMainYinbiPage({super.key});

  @override
  Widget build(BuildContext context, WidgetRef ref) {
    return Scaffold(
      appBar: Simple.simpleBar(
        title: '物品主页',
        back: Simple.backButton(
            context: context, route: '/ownpage/thingpage/mainpage'),
      ),
      body: Center(
        child: Column(
          children: [
            const SizedBox(height: 10),
            Simple.simpleShowText(
                show: "银币: ${Files.yinBiReader().readStrSafeSync()}"),
            const SizedBox(height: 130),
            Simple.nullSpace(),
            Wrap(
              alignment: WrapAlignment.center,
              spacing: 20,
              children: [
                Simple.simpleClick(
                  func: () {
                    Yinbi.dealCard2(context, 1, CardStore.sanGuo1(),
                        CardStore.han1(), "三国卡牌1", "汉朝卡牌1", 90);
                  },
                  show: "三国卡牌1\n汉朝卡牌1\n1银币",
                ),
              ],
            ),
          ],
        ),
      ),
    );
  }
}
