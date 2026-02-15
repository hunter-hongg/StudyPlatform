import 'package:flutter/material.dart';
import 'package:study_platform/logic/trade.dart';
import 'package:study_platform/logic/xxianlu.dart';
import 'package:study_platform/vars/files.dart';
import 'package:study_platform/vars/simple.dart';
import 'package:study_platform/vars/styles.dart';

class XianLuPage extends StatefulWidget {
  const XianLuPage({super.key});

  @override
  State<XianLuPage> createState() => _XianLuPageState();
}

class _XianLuPageState extends State<XianLuPage> {
  var xianlu = 0;
  void update() {
    xianlu = Files.xXianLuPinReader().readIntSafeSync();
  }

  @override
  Widget build(BuildContext context) {
    update();
    return Scaffold(
      appBar: Simple.simpleBar(
        title: '我的仙禄',
        back: Simple.backButton(context: context, route: '/xianpage'),
      ),
      body: Center(
        child: Column(
          children: [
            const SizedBox(height: 5),
            Text('仙禄等级: $xianlu', style: Styles.showstrStyle()),
            const SizedBox(height: 140),
            Simple.simpleClick(
              func: () {
                var add = XXianLu.getXianLu(xianlu);
                Trade.tradeCheck(context, Files.xianBiReader(),
                    CheckFiles.xXianLuOkCheck(), add,
                    customMessage: '成功领取$add仙币仙禄');
              },
              show: '领取仙禄',
            ),
            Simple.simpleSpace(),
            Simple.simpleClick(
              func: () {
                var need = XXianLu.getLevelNeed(xianlu);
                Trade.tradeF(
                  context,
                  Files.xianBiReader(),
                  Files.xXianLuPinReader(),
                  '仙币',
                  need,
                  1,
                  customMessage: '成功使用$need仙币升级仙禄',
                );
                setState(() {
                  update();
                });
              },
              show: '升级仙禄',
            ),
          ],
        ),
      ),
    );
  }
}
