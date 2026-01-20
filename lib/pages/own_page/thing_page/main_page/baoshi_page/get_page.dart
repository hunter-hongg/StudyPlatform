import 'package:flutter/material.dart';
import 'package:flutter_riverpod/flutter_riverpod.dart';
import 'package:study_platform/logic/baoshi.dart';
import 'package:study_platform/vars/files.dart';
import 'package:study_platform/vars/simple.dart';

class ThingMainBaoshiGetPage extends ConsumerWidget {
  const ThingMainBaoshiGetPage({super.key});

  List<Widget> buildUI(
      BuildContext context, List<int> jifenMin, List<int> baoshiAdd) {
    var wid = <Widget>[];
    if ((jifenMin.length != baoshiAdd.length) || (jifenMin.isEmpty)) {
      return wid;
    }
    for (int i = 0; i < jifenMin.length; ++i) {
      wid.add(
        Simple.simpleClick(
          func: () {
            Baoshi.get(context, jifenMin[i], baoshiAdd[i]);
          },
          show: "${jifenMin[i]}积分\n${baoshiAdd[i]}宝石",
        ),
      );
    }
    return wid;
  }

  @override
  Widget build(BuildContext context, WidgetRef ref) {
    return Scaffold(
      appBar: Simple.simpleBar(
        title: '宝石获取',
        back: Simple.backButton(
            context: context, route: '/ownpage/thingpage/mainpage/baoshipage'),
      ),
      body: Center(
        child: Column(
          children: [
            const SizedBox(height: 10),
            Simple.simpleShowText(
                show: "积分: ${Files.jiFenReader().readStrSafeSync()}\n"
                    "宝石: ${Files.baoShiReader().readStrSafeSync()}"),
            const SizedBox(height: 120),
            Simple.nullSpace(),
            Wrap(
              alignment: WrapAlignment.center,
              spacing: 20,
              children: [
                ...buildUI(
                  context,
                  [200, 400, 600, 800, 1000],
                  [5, 11, 18, 25, 35],
                ),
              ],
            ),
          ],
        ),
      ),
    );
  }
}
