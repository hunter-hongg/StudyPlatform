import 'package:flutter/material.dart';
import 'package:study_platform/vars/files.dart';
import 'package:study_platform/vars/simple.dart';

class AThingCaiPage extends StatefulWidget {
  const AThingCaiPage({super.key});

  @override
  State<AThingCaiPage> createState() => _AThingCaiPageState();
}

class _AThingCaiPageState extends State<AThingCaiPage> {
  @override
  Widget build(BuildContext context) {
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
                  func: () {
                    setState(() {});
                  },
                  show: "铜钱: ${Files.aTongQianReader().readStrSafeSync()}枚",
                ),
                Simple.simpleClick(
                  func: () {
                    setState(() {});
                  },
                  show: "白银: ${Files.aBaiYinReader().readStrSafeSync()}两",
                ),
                Simple.simpleClick(
                  func: () {
                    setState(() {});
                  },
                  show: "黄金: ${Files.aHuangJinReader().readStrSafeSync()}两",
                ),
              ],
            ),
            Simple.simpleSpace(),
            Simple.simpleRow(
              widgets: [
                Simple.simpleClick(
                  func: () {
                    setState(() {});
                  },
                  show: "绿玉: ${AddFiles.aLvYuReader().readStrSafe()}块",
                ),
                Simple.simpleClick(
                  func: () {
                    setState(() {});
                  },
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
