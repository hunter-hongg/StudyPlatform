import 'package:flutter/material.dart';
import 'package:study_platform/logic/ausebao.dart';
import 'package:study_platform/tool/addfile.dart';
import 'package:study_platform/vars/files.dart';
import 'package:study_platform/vars/simple.dart';

class AUseBaoPage extends StatefulWidget {
  const AUseBaoPage({super.key});

  @override
  State<AUseBaoPage> createState() => _AUseBaoPageState();
}

class _AUseBaoPageState extends State<AUseBaoPage> {
  int lvyu = 0, baiyu = 0;

  void update() {
    lvyu = AddFiles.aLvYuReader().readIntSafe();
    baiyu = AddFiles.aBaiYuReader().readIntSafe();
  }

  List<Widget> buildUI(List<(String, AddFile, int, AddFile, String)> list) {
    var wid = <Widget>[], tmpWid = <Widget>[];
    for (var i = 0; i < list.length; i++) {
      var item = list[i];
      tmpWid.add(Simple.simpleClick(
        func: () {
          AUseBao.useBao(context, item.$2, item.$4, item.$1, item.$3);
          setState(() {
            update();
          });
        },
        show: "1${item.$1}\n${item.$3}${item.$5}",
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

  List<(String, AddFile, int, AddFile, String)> buildList() {
    return [
      ("明珠", AddFiles.aBaowuMingZhu(), 10, AddFiles.aBaiYuReader(), "白玉"),
      ("玉雕", AddFiles.aBaowuYuDiao(), 15, AddFiles.aBaiYuReader(), "白玉"),
      ("玉璧", AddFiles.aBaowuYuBi(), 5, AddFiles.aLvYuReader(), "绿玉"),
      ("绸缎", AddFiles.aBaowuChouDuan(), 2, AddFiles.aLvYuReader(), "绿玉"),
      ("玉盏", AddFiles.aBaowuYuzhan(), 5, AddFiles.aLvYuReader(), "绿玉"),
      ("玉壶", AddFiles.aBaowuHu(), 7, AddFiles.aLvYuReader(), "绿玉"),
      ("玉杯", AddFiles.aBaowuZhan(), 9, AddFiles.aLvYuReader(), "绿玉"),
    ];
  }

  @override
  Widget build(BuildContext context) {
    update();
    return Scaffold(
      appBar: Simple.simpleBar(
        title: '宝物卖出',
        back: Simple.backButton(context: context, route: '/apage/usepage'),
      ),
      body: Center(
        child: Column(
          children: [
            const SizedBox(height: 5),
            Simple.simpleShowText(show: '绿玉: $lvyu\n白玉: $baiyu'),
            const SizedBox(height: 90),
            Simple.nullSpace(),
            ...buildUI(buildList()),
          ],
        ),
      ),
    );
  }
}
