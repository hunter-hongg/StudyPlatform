import 'package:flutter/material.dart';
import 'package:study_platform/logic/shopbook.dart';
import 'package:study_platform/tool/addfile.dart';
import 'package:study_platform/vars/files.dart';
import 'package:study_platform/vars/simple.dart';

class AShopBookPage extends StatefulWidget {
  const AShopBookPage({super.key});

  @override
  State<AShopBookPage> createState() => _AShopBookPageState();
}

class _AShopBookPageState extends State<AShopBookPage> {
  int baiy = 0;

  void update() {
    baiy = Files.aBaiYinReader().readIntSafeSync();
  }

  List<Widget> buildUI(List<(int, AddFile, int)> list) {
    var wid = <Widget>[], tmpWid = <Widget>[];
    for (var i = 0; i < list.length; i++) {
      var item = list[i];
      tmpWid.add(Simple.simpleClick(
        func: () {
          Shopbook.sell(context, item.$1, item.$2, item.$3);
          setState(() {
            update();
          });
        },
        show: "抄录书籍${item.$3}级\n${item.$1}白银",
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

  List<(int, AddFile, int)> buildList() {
    return [
      (90, AddFiles.aBookC1(), 1),
      (150, AddFiles.aBookC2(), 2),
      (200, AddFiles.aBookC3(), 3),
      (350, AddFiles.aBookC4(), 4),
      (675, AddFiles.aBookC5(), 5),
    ];
  }

  @override
  Widget build(BuildContext context) {
    update();
    return Scaffold(
      appBar: Simple.simpleBar(
        title: '书籍店铺',
        back: Simple.backButton(context: context, route: '/apage/shoppage'),
      ),
      body: Center(
        child: Column(
          children: [
            const SizedBox(height: 5),
            Simple.simpleShowText(show: "白银: $baiy"),
            const SizedBox(height: 120),
            Simple.nullSpace(),
            ...buildUI(buildList()),
          ],
        ),
      ),
    );
  }
}
