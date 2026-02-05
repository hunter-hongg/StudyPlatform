import 'package:flutter/material.dart';
import 'package:study_platform/logic/ajuan.dart';
import 'package:study_platform/tool/fileinter.dart';
import 'package:study_platform/vars/files.dart';
import 'package:study_platform/vars/simple.dart';

class AJuanGuwanPage extends StatefulWidget {
  const AJuanGuwanPage({super.key});

  @override
  State<AJuanGuwanPage> createState() => _AJuanGuwanPageState();
}

class _AJuanGuwanPageState extends State<AJuanGuwanPage> {
  int juanz = 0;

  void update() {
    juanz = Files.aJuanZhiReader().readIntSafeSync();
  }

  List<Widget> buildUI(List<(int, int, MinusAble, String)> list) {
    var wid = <Widget>[], tmpWid = <Widget>[];
    for (var i = 0; i < list.length; i++) {
      var item = list[i];
      tmpWid.add(Simple.simpleClick(
        func: () {
          Ajuan.dealGuwan(context, item.$1, item.$2, item.$4, item.$3);
          setState(() {
            update();
          });
        },
        show: "1${item.$4}\n${item.$1}白银+${item.$2}捐献值",
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

  List<(int, int, MinusAble, String)> buildList() {
    return [
      (30, 20, Files.aCiQiReader(), "瓷器"),
      (35, 25, Files.aBeiKeReader(), "碑刻"),
      (30, 20, Files.aYuPeiReader(), "玉佩"),
      (45, 40, AddFiles.aGuwanChaHu(), "茶壶"),
      (35, 30, AddFiles.aGuwanChaZhan(), "茶盏"),
    ];
  }

  @override
  Widget build(BuildContext context) {
    update();
    return Scaffold(
      appBar: Simple.simpleBar(
        title: '古玩捐献',
        back: Simple.backButton(context: context, route: '/apage/juanpage'),
      ),
      body: Center(
        child: Column(
          children: [
            const SizedBox(height: 5),
            Simple.simpleShowText(show: "捐献值: $juanz"),
            const SizedBox(height: 120),
            Simple.nullSpace(),
            ...buildUI(buildList()),
          ],
        ),
      ),
    );
  }
}
