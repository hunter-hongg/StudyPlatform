import 'package:flutter/material.dart';
import 'package:flutter_riverpod/flutter_riverpod.dart';
import 'package:study_platform/vars/files.dart';
import 'package:study_platform/vars/simple.dart';

class AThingCaiPage extends ConsumerWidget {
  const AThingCaiPage({super.key});

  @override
  Widget build(BuildContext context, WidgetRef ref) {
    return Scaffold(
      appBar: Simple.simpleBar(
        title: '我的财物',
        back: Simple.backButton(context: context, route: '/apage/thingpage'),
      ),
      body: Center(
        child: Column(
          children: [
            const SizedBox(height: 140),
            Simple.nullSpace(),
            Simple.simpleRow(
              widgets: [
                Simple.simpleClick(
                  func: () {},
                  show: "铜钱: ${Files.aTongQianReader().readStrSafeSync()}枚",
                ),
                Simple.simpleClick(
                  func: () {},
                  show: "白银: ${Files.aBaiYinReader().readStrSafeSync()}两",
                ),
                Simple.simpleClick(
                  func: () {},
                  show: "黄金: ${Files.aHuangJinReader().readStrSafeSync()}两",
                ),
              ],
            ),
            Simple.simpleSpace(),
            Simple.simpleRow(
              widgets: [
                Simple.simpleClick(
                  func: () {},
                  show: "绿玉: ${AddFiles.aLvYuReader().readStrSafe()}块",
                ),
                Simple.simpleClick(
                  func: () {},
                  show: "白玉: ${AddFiles.aBaiYuReader().readStrSafe()}块",
                ),
              ],
            )
          ],
        ),
      ),
    );
  }
}
