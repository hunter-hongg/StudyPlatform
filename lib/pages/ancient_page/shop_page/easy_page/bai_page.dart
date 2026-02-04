import 'package:flutter/material.dart';
import 'package:study_platform/logic/trade.dart';
import 'package:study_platform/vars/files.dart';
import 'package:study_platform/vars/simple.dart';
import 'package:study_platform/vars/styles.dart';

class AShopEasyBaiPage extends StatefulWidget {
  const AShopEasyBaiPage({super.key});

  @override
  State<AShopEasyBaiPage> createState() => _AShopEasyBaiPageState();
}

class _AShopEasyBaiPageState extends State<AShopEasyBaiPage> {
  int tongq = 0, baiy = 0;

  void update() {
    tongq = Files.aTongQianReader().readIntSafeSync();
    baiy = Files.aBaiYinReader().readIntSafeSync();
  }

  @override
  Widget build(BuildContext context) {
    update();
    final TextEditingController toGet = TextEditingController();
    return Scaffold(
      appBar: Simple.simpleBar(
        title: '兑换白银',
        back: Simple.backButton(context: context, route: '/apage/shoppage/easypage'),
      ),
      body: Center(
        child: Column(
          children: [
            const SizedBox(height: 5),
            Text(
                '铜钱: $tongq\n'
                '白银: $baiy',
                style: Styles.showstrStyle()),
            const SizedBox(height: 120),
            Simple.simpleText(show: "请输入兑换的白银数"),
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
                  Files.aTongQianReader(),
                  Files.aBaiYinReader(),
                  "铜钱",
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
