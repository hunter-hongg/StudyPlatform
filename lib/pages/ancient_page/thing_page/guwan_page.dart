import 'package:flutter/material.dart';
import 'package:study_platform/vars/files.dart';
import 'package:study_platform/vars/simple.dart';

class AThingGuwanPage extends StatefulWidget {
  const AThingGuwanPage({super.key});

  @override
  State<AThingGuwanPage> createState() => _AThingGuwanPageState();
}

class _AThingGuwanPageState extends State<AThingGuwanPage> {
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
                  show: "瓷器: ${Files.aCiQiReader().readStrSafeSync()}件",
                ),
                Simple.simpleClick(
                  func: () {
                    setState(() {});
                  },
                  show: "碑刻: ${Files.aBeiKeReader().readStrSafeSync()}块",
                ),
                Simple.simpleClick(
                  func: () {
                    setState(() {});
                  },
                  show: "玉佩: ${Files.aYuPeiReader().readStrSafeSync()}件",
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
                  show: "茶壶: ${AddFiles.aGuwanChaHu().readStrSafe()}件",
                ),
                Simple.simpleClick(
                  func: () {
                    setState(() {});
                  },
                  show: "茶盏: ${AddFiles.aGuwanChaZhan().readStrSafe()}件",
                ),
              ],
            )
          ],
        ),
      ),
    );
  }
}
