import 'package:flutter/material.dart';
import 'package:study_platform/logic/trade.dart';
import 'package:study_platform/vars/files.dart';
import 'package:study_platform/vars/simple.dart';
import 'package:study_platform/vars/styles.dart';

class AShopEasyTongPage extends StatefulWidget {
  const AShopEasyTongPage({super.key});

  @override
  State<AShopEasyTongPage> createState() => _AShopEasyTongPageState();
}

class _AShopEasyTongPageState extends State<AShopEasyTongPage> {
  int huangj = 0, tongq = 0;

  void update() {
    huangj = Files.aHuangJinReader().readIntSafeSync();
    tongq = Files.aTongQianReader().readIntSafeSync();
  }

  @override
  Widget build(BuildContext context) {
    update();
    final TextEditingController toGet = TextEditingController();
    return Scaffold(
      appBar: Simple.simpleBar(
        title: '兑换铜钱',
        back: Simple.backButton(context: context, route: '/apage/shoppage/easypage'),
      ),
      body: Center(
        child: Column(
          children: [
            const SizedBox(height: 5),
            Text(
                '黄金: $huangj\n'
                '铜钱: $tongq',
                style: Styles.showstrStyle()),
            const SizedBox(height: 120),
            Simple.simpleText(show: "请输入兑换的铜钱数"),
            Simple.simpleSpace(),
            Simple.simpleInput(
              controller: toGet,
              label: '请输入兑换数量',
              hint: '请输入兑换数量',
            ),
            Simple.simpleSpace(),
            Simple.simpleClick(
              func: () {
                var thing1min = int.tryParse(toGet.text);
                if (thing1min == null) {
                  Simple.simpleInfo(
                    context: context,
                    show: "解析失败",
                  );
                  return;
                }
                if (thing1min % 100 != 0) {
                  Simple.simpleInfo(
                    context: context,
                    show: "铜钱必须是100的倍数",
                  );
                  return;
                }
                Trade.trade(
                  context,
                  Files.aHuangJinReader(),
                  Files.aTongQianReader(),
                  "黄金",
                  thing1min ~/ 100,
                  thing1min,
                );
                setState(() {
                  update();
                });
              },
              show: '兑换',
            ),
          ],
        ),
      ),
    );
  }
}
