import 'package:flutter/material.dart';
import 'package:study_platform/logic/trade.dart';
import 'package:study_platform/vars/files.dart';
import 'package:study_platform/vars/simple.dart';
import 'package:study_platform/vars/styles.dart';

class AShopEasyJinPage extends StatefulWidget {
  const AShopEasyJinPage({super.key});

  @override
  State<AShopEasyJinPage> createState() => _AShopEasyJinPageState();
}

class _AShopEasyJinPageState extends State<AShopEasyJinPage> {
  int huangj = 0, baiy = 0;

  void update() {
    huangj = Files.aHuangJinReader().readIntSafeSync();
    baiy = Files.aBaiYinReader().readIntSafeSync();
  }

  @override
  Widget build(BuildContext context) {
    update();
    final TextEditingController toGet = TextEditingController();
    return Scaffold(
      appBar: Simple.simpleBar(
        title: '兑换黄金',
        back: Simple.backButton(context: context, route: '/apage/shoppage/easypage'),
      ),
      body: Center(
        child: Column(
          children: [
            const SizedBox(height: 5),
            Text(
                '白银: $baiy\n'
                '黄金: $huangj',
                style: Styles.showstrStyle()),
            const SizedBox(height: 120),
            Simple.simpleText(show: "请输入兑换的黄金数"),
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
                Trade.trade(
                  context,
                  Files.aBaiYinReader(),
                  Files.aHuangJinReader(),
                  "白银",
                  thing1min * 10,
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
