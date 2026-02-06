import 'package:flutter/material.dart';
import 'package:study_platform/logic/trade.dart';
import 'package:study_platform/vars/files.dart';
import 'package:study_platform/vars/simple.dart';

class AGWenPage extends StatefulWidget {
  const AGWenPage({super.key});

  @override
  State<AGWenPage> createState() => _AGWenPageState();
}

class _AGWenPageState extends State<AGWenPage> {
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: Simple.simpleBar(
        title: '文官官职',
        back: Simple.backButton(context: context, route: '/apage/gpage'),
      ),
      body: Center(
        child: Column(
          children: [
            const SizedBox(height: 5),
            Simple.simpleShowText(
              show: "文官品级: ${Special.aWenGuanConfig().readLevel()}品",
            ),
            const SizedBox(height: 140),
            Simple.simpleClick(
              func: () {
                var add = Special.aWenGuanConfig().getFengLu();
                Trade.tradeCheck(
                  context,
                  Files.aHuangJinReader(),
                  CheckFiles.aWenFengCheck(),
                  add,
                  customMessage: "成功领取$add两黄金",
                );
              },
              show: '我的俸禄',
            ),
            Simple.simpleSpace(),
            Simple.simpleClick(
              func: () {
                Navigator.pushNamed(context, '/apage/gpage/wupage/zhengpage');
              },
              show: '我的政绩',
            ),
          ],
        ),
      ),
    );
  }
}
