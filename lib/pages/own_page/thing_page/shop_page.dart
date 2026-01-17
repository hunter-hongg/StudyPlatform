import 'package:flutter/material.dart';
import 'package:flutter_riverpod/flutter_riverpod.dart';
import 'package:study_platform/logic/othing_shop.dart';
import 'package:study_platform/vars/files.dart';
import 'package:study_platform/vars/simple.dart';
import 'package:study_platform/vars/styles.dart';

class ThingShopPage extends ConsumerWidget {
  const ThingShopPage({super.key});

  @override
  Widget build(BuildContext context, WidgetRef ref) {
    return Scaffold(
      appBar: Simple.simpleBar(
        title: '物品商城',
        back: Simple.backButton(context: context, route: '/ownpage/thingpage'),
      ),
      body: Center(
        child: Column(
          children: [
            const SizedBox(height: 5),
            Text('积分: ${Files.jiFenReader().readStrSafeSync()}',
                style: Styles.showstrStyle()),
            const SizedBox(height: 130),
            Simple.nullSpace(),
            Wrap(
              alignment: WrapAlignment.center,
              spacing: 20,
              children: [
                Simple.simpleClick(
                  func: () {
                    OthingShop.deal(context, 200, Files.aTongQianReader(), 175);
                  },
                  show: "200积分\n175铜钱",
                ),
                Simple.simpleClick(
                  func: () {
                    OthingShop.deal(context, 400, Files.jinBiReader(), 5);
                  },
                  show: "400积分\n5金币",
                ),
                Simple.simpleClick(
                  func: () {
                    OthingShop.deal(context, 400, Files.xianBiReader(), 40);
                  },
                  show: "400积分\n40仙币",
                ),
              ],
            ),
            Simple.simpleSpace(),
            Wrap(
              alignment: WrapAlignment.center,
              spacing: 20,
              children: [
                Simple.simpleClick(
                  func: () {
                    OthingShop.dealCard(context, 50, CardStore.sanGuo1(), 3);
                  },
                  show: "50积分\n三国卡牌1*3",
                ),
              ],
            )
          ],
        ),
      ),
    );
  }
}
