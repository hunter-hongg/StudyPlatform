import 'package:flutter/material.dart';
import 'package:study_platform/vars/files.dart';
import 'package:study_platform/vars/simple.dart';

class XianThingDanShowPage extends StatefulWidget {
  const XianThingDanShowPage({super.key});

  @override
  State<XianThingDanShowPage> createState() => _XianThingDanShowPageState();
}

class _XianThingDanShowPageState extends State<XianThingDanShowPage> {
  List<Widget> buildUI() {
    var show = [
      "普通丹",
      "碧丹",
      "青丹",
      "紫丹",
      "五色丹",
      "银丹",
      "金丹",
      "神丹",
    ];
    var files = [
      XianDan.puTongDan(),
      XianDan.biDan(),
      XianDan.qingDan(),
      XianDan.ziDan(),
      XianDan.wuSeDan(),
      XianDan.yinDan(),
      XianDan.jinDan(),
      XianDan.shenDan(),
    ];
    List<Widget> wid = [], tmpWid = [];
    for (int i = 0; i < show.length; i++) {
      tmpWid.add(
        Simple.simpleClick(
          func: () {},
          show: '${show[i]}: ${files[i].readStrSafeSync()}颗',
        ),
      );
      if (i % 3 == 2) {
        wid.add(
          Simple.simpleRow(
            widgets: tmpWid,
          ),
        );
        wid.add(Simple.simpleSpace());
        tmpWid = [];
      }
    }
    if (tmpWid.isNotEmpty) {
      wid.add(
        Simple.simpleRow(
          widgets: tmpWid,
        ),
      );
    }
    return wid;
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: Simple.simpleBar(
        title: '仙丹查看',
        back: Simple.backButton(
            context: context, route: '/xianpage/thingpage/danpage'),
      ),
      body: Center(
        child: Column(
          children: [
            const SizedBox(height: 140),
            ...buildUI(),
          ],
        ),
      ),
    );
  }
}
