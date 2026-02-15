import 'package:flutter/material.dart';
import 'package:study_platform/logic/trade.dart';
import 'package:study_platform/vars/files.dart';
import 'package:study_platform/vars/simple.dart';
import 'package:study_platform/vars/styles.dart';

/*
法力炼丹基准数额
20 => 1普通丹 to 15 => 1普通丹
45 => 1碧丹   to 35 => 1碧丹
100 => 1青丹  to 80 => 1青丹
*/

class XianFaLdanPage extends StatefulWidget {
  const XianFaLdanPage({super.key});

  @override
  State<XianFaLdanPage> createState() => _XianFaLdanPageState();
}

class _XianFaLdanPageState extends State<XianFaLdanPage> {
  var fali = 0;

  void update() {
    fali = Files.xFaLiReader().readIntSafeSync();
  }

  @override
  Widget build(BuildContext context) {
    update();
    return Scaffold(
      appBar: Simple.simpleBar(
        title: '法力炼丹',
        back: Simple.backButton(context: context, route: '/xianpage/fapage'),
      ),
      body: Center(
        child: Column(
          children: [
            const SizedBox(height: 5),
            Text('法力: $fali', style: Styles.showstrStyle()),
            const SizedBox(height: 140),
            Simple.simpleClick(
              func: () {
                Trade.tradeF(
                  context,
                  Files.xFaLiReader(),
                  XianDan.puTongDan(),
                  '法力',
                  15,
                  1,
                  customMessage: "炼制成功",
                );
                setState(() {
                  update();
                });
              },
              show: '炼制普通丹',
            ),
            Simple.simpleSpace(),
            Simple.simpleClick(
              func: () {
                Trade.tradeF(
                  context,
                  Files.xFaLiReader(),
                  XianDan.biDan(),
                  '法力',
                  35,
                  1,
                  customMessage: "炼制成功",
                );
                setState(() {
                  update();
                });
              },
              show: '炼制碧丹',
            ),
            Simple.simpleSpace(),
            Simple.simpleClick(
              func: () {
                Trade.tradeF(
                  context,
                  Files.xFaLiReader(),
                  XianDan.qingDan(),
                  '法力',
                  80,
                  1,
                  customMessage: "炼制成功",
                );
                setState(() {
                  update();
                });
              },
              show: '炼制青丹',
            ),
          ],
        ),
      ),
    );
  }
}
