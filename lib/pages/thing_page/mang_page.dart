import 'package:flutter/material.dart';
import 'package:flutter_riverpod/flutter_riverpod.dart';
import 'package:study_platform/logic/jin_mang.dart';
import 'package:study_platform/vars/files.dart';
import 'package:study_platform/vars/simple.dart';

class TSMangPage extends ConsumerWidget {
  const TSMangPage({super.key});

  @override
  Widget build(BuildContext context, WidgetRef ref) {
    return Scaffold(
      appBar: Simple.simpleBar(
        title: '金币盲盒',
        back: Simple.backButton(context: context, route: '/thingpage'),
      ),
      body: Center(
        child: Column(
          children: [
            const SizedBox(height: 5),
            Simple.simpleShowText(
                show: "金币: ${Files.jinBiReader().readStrSafeSync()}"),
            const SizedBox(height: 120),
            Simple.nullSpace(),
            Wrap(
              alignment: WrapAlignment.center,
              spacing: 20,
              children: [
                Simple.simpleClick(
                  show: '5金币盲盒',
                  func: () {
                    JinMang.dealS(context, 1);
                  },
                ),
                Simple.simpleClick(
                  show: '10金币盲盒',
                  func: () {
                    JinMang.dealS(context, 2);
                  },
                ),
                Simple.simpleClick(
                  show: '15金币盲盒',
                  func: () {
                    JinMang.dealS(context, 3);
                  },
                ),
              ],
            ),
            Simple.simpleSpace(),
            Wrap(
              alignment: WrapAlignment.center,
              spacing: 20,
              children: [
                Simple.simpleClick(
                  show: '5金币古代盲盒',
                  func: () {
                    JinMang.dealA(context, 1);
                  },
                ),
                Simple.simpleClick(
                  show: '10金币古代盲盒',
                  func: () {
                    JinMang.dealA(context, 2);
                  },
                ),
                Simple.simpleClick(
                  show: '15金币古代盲盒',
                  func: () {
                    JinMang.dealA(context, 3);
                  },
                ),
              ],
            )
          ],
        ),
      ),
    );
  }
}
