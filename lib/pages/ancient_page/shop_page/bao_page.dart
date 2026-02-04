import 'package:flutter/material.dart';
import 'package:study_platform/logic/shopbao.dart';
import 'package:study_platform/tool/addfile.dart';
import 'package:study_platform/vars/files.dart';
import 'package:study_platform/vars/simple.dart';

class AShopBaoPage extends StatefulWidget {
  const AShopBaoPage({super.key});

  @override
  State<AShopBaoPage> createState() => _AShopBaoPageState();
}

class _AShopBaoPageState extends State<AShopBaoPage> {
  int huangj = 0;

  void update() {
    huangj = Files.aHuangJinReader().readIntSafeSync();
  }

  List<Widget> buildUI(List<(int, AddFile, String)> list) {
    var wid = <Widget>[], tmpWid = <Widget>[];
    for (var i = 0; i < list.length; i++) {
      var item = list[i];
      tmpWid.add(Simple.simpleClick(
        func: () {
          Shopbao.deal(context, item.$1, item.$2);
          setState(() {
            update();
          });
        },
        show: "${item.$1}黄金\n1${item.$3}",
      ));
      if (i % 3 == 2) {
        wid.add(Simple.simpleRow(widgets: tmpWid));
        wid.add(Simple.simpleSpace());
        tmpWid = <Widget>[];
      }
    }
    if (tmpWid.isNotEmpty) {
      wid.add(Simple.simpleRow(widgets: tmpWid));
    }
    return wid;
  }

  List<(int, AddFile, String)> buildList() {
    return [
      (500, AddFiles.aBaowuMingZhu(), "明珠"),
      (800, AddFiles.aBaowuYuDiao(), "玉雕"),
      (1200, AddFiles.aBaowuYuBi(), "玉璧"),
      (250, AddFiles.aBaowuChouDuan(), "绸缎"),
      (1000, AddFiles.aBaowuYuzhan(), "玉盏"),
      (1500, AddFiles.aBaowuHu(), "玉壶"),
      (500, AddFiles.aBaowuZhan(), "玉杯"),
    ];
  }

  @override
  Widget build(BuildContext context) {
    update();
    return Scaffold(
      appBar: Simple.simpleBar(
        title: '宝物店铺',
        back: Simple.backButton(context: context, route: '/apage/shoppage'),
      ),
      body: Center(
        child: Column(
          children: [
            const SizedBox(height: 5),
            Simple.simpleShowText(show: "黄金: $huangj"),
            const SizedBox(height: 120),
            Simple.nullSpace(),
            ...buildUI(buildList()),
          ],
        ),
      ),
    );
  }
}
