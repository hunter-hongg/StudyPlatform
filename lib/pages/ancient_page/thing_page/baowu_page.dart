import 'package:flutter/material.dart';
import 'package:study_platform/vars/files.dart';
import 'package:study_platform/vars/simple.dart';

class AThingBaowuPage extends StatefulWidget {
  const AThingBaowuPage({super.key});

  @override
  State<AThingBaowuPage> createState() => _AThingBaowuPageState();
}

class _AThingBaowuPageState extends State<AThingBaowuPage> {
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: Simple.simpleBar(
        title: '我的宝物',
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
                  show: "明珠: ${AddFiles.aBaowuMingZhu().readStrSafe()}件",
                ),
                Simple.simpleClick(
                  func: () {
                    setState(() {});
                  },
                  show: "玉雕: ${AddFiles.aBaowuYuDiao().readStrSafe()}块",
                ),
                Simple.simpleClick(
                  func: () {
                    setState(() {});
                  },
                  show: "玉璧: ${AddFiles.aBaowuYuBi().readStrSafe()}件",
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
                  show: "绸缎: ${AddFiles.aBaowuChouDuan().readStrSafe()}件",
                ),
                Simple.simpleClick(
                  func: () {
                    setState(() {});
                  },
                  show: "玉盏: ${AddFiles.aBaowuYuzhan().readStrSafe()}件",
                ),
                Simple.simpleClick(
                  func: () {
                    setState(() {});
                  },
                  show: "玉壶: ${AddFiles.aBaowuHu().readStrSafe()}件",
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
                  show: "玉杯: ${AddFiles.aBaowuZhan().readStrSafe()}件",
                ),
              ],
            ),
          ],
        ),
      ),
    );
  }
}