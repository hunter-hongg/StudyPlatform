import 'package:flutter/material.dart';
import 'package:study_platform/logic/ajuan.dart';
import 'package:study_platform/logic/trade.dart';
import 'package:study_platform/vars/files.dart';
import 'package:study_platform/vars/simple.dart';

class AJuanPage extends StatefulWidget {
  const AJuanPage({super.key});

  @override
  State<AJuanPage> createState() => _AJuanPageState();
}

class _AJuanPageState extends State<AJuanPage> {
  int juan = Files.aJuanZhiReader().readIntSafeSync();
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: Simple.simpleBar(
        title: '我的捐献',
        back: Simple.backButton(context: context, route: '/apage'),
      ),
      body: Center(
        child: Column(
          children: [
            const SizedBox(
              height: 5,
            ),
            Simple.simpleShowText(
              show: "捐献值: $juan\n"
                  "等级: ${Ajuan.getLevel(juan)}\n",
            ),
            const SizedBox(height: 90),
            Simple.simpleClick(
              func: () {
                Navigator.pushNamed(context, '/apage/juanpage/guwanpage');
              },
              show: '捐献古玩',
            ),
            Simple.simpleSpace(),
            Simple.simpleClick(
              func: () {
                var hj = Ajuan.getHuangj(
                  Ajuan.getLevel(Files.aJuanZhiReader().readIntSafeSync()),
                );
                Trade.tradeCheck(
                  context,
                  Files.aHuangJinReader(),
                  CheckFiles.aJuanCheck(),
                  hj,
                  customMessage: "成功领取$hj两黄金",
                );
              },
              show: '领取资助',
            ),
          ],
        ),
      ),
    );
  }
}
