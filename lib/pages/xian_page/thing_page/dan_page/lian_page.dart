import 'package:flutter/material.dart';
import 'package:study_platform/logic/trade.dart';
import 'package:study_platform/vars/files.dart';
import 'package:study_platform/vars/simple.dart';

class XianThingDanLiPage extends StatefulWidget {
  const XianThingDanLiPage({super.key});

  @override
  State<XianThingDanLiPage> createState() => _XianThingDanLiPageState();
}

class _XianThingDanLiPageState extends State<XianThingDanLiPage> {
  List<Widget> buildUI() {
    List<Widget> wid = [], tmpWid = [];
    var dans = ["碧丹", "青丹", "紫丹", "五色丹", "银丹", "金丹", "神丹"];
    var fps = [
      XianDan.puTongDan(),
      XianDan.biDan(),
      XianDan.qingDan(),
      XianDan.ziDan(),
      XianDan.wuSeDan(),
      XianDan.yinDan(),
      XianDan.jinDan(),
      XianDan.shenDan(),
    ];
    var needs = List.generate(5, (_) => Files.xQiFaLiReader());
    needs += List.generate(2, (_) => Files.xJiReader());
    var needsStr = List.generate(5, (_) => '仙器法力');
    needsStr += List.generate(2, (_) => '仙籍');
    var price = [10, 15, 20, 25, 30, 10, 20];
    for (int i = 0; i < dans.length; ++i) {
      tmpWid.add(
        Simple.simpleClick(
          func: () {
            Trade.tradeF2to1(
              context,
              needs[i],
              fps[i],
              fps[i + 1],
              needsStr[i],
              '仙丹',
              price[i],
              2,
              1,
              customMessage: "炼制成功",
            );
          },
          show: '${price[i]}${needsStr[i]}\n1${dans[i]}',
        ),
      );
      if (tmpWid.length == 3) {
        wid += [
          Simple.simpleRow(widgets: tmpWid),
          Simple.simpleSpace(),
        ];
        tmpWid = [];
      }
    }
    wid.add(Simple.simpleRow(widgets: tmpWid));
    return wid;
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: Simple.simpleBar(
        title: '炼制仙丹',
        back: Simple.backButton(
            context: context, route: '/xianpage/thingpage/danpage'),
      ),
      body: Center(
        child: Column(
          children: [
            const SizedBox(height: 5),
            Simple.simpleShowText(show: "每颗高级仙丹需要两颗低级仙丹+条件炼制"),
            const SizedBox(height: 140),
            ...buildUI(),
          ],
        ),
      ),
    );
  }
}
