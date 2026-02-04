import 'package:flutter/material.dart';
import 'package:study_platform/logic/shopgu.dart';
import 'package:study_platform/tool/addfile.dart';
import 'package:study_platform/tool/file_password.dart';
import 'package:study_platform/vars/files.dart';
import 'package:study_platform/vars/simple.dart';

class AShopGuPage extends StatefulWidget {
  const AShopGuPage({super.key});

  @override
  State<AShopGuPage> createState() => _AShopGuPageState();
}

class _AShopGuPageState extends State<AShopGuPage> {
  int baiy = 0;

  void update() {
    baiy = Files.aBaiYinReader().readIntSafeSync();
  }

  List<Widget> buildUI(List<(int, AddFile, String)> list1,
      List<(int, FilePassword, String)> list2) {
    var wid = <Widget>[], tmpWid = <Widget>[];
    for (var i = 0; i < list1.length; i++) {
      var item = list1[i];
      tmpWid.add(Simple.simpleClick(
        func: () {
          Shopgu.dealA(context, item.$1, item.$2);
          setState(() {
            update();
          });
        },
        show: "${item.$1}白银\n1${item.$3}",
      ));
      if (i % 3 == 2) {
        wid.add(Simple.simpleRow(widgets: tmpWid));
        wid.add(Simple.simpleSpace());
        tmpWid = <Widget>[];
      }
    }
    for (var i = 0; i < list2.length; i++) {
      var item = list2[i];
      tmpWid.add(Simple.simpleClick(
        func: () {
          Shopgu.dealP(context, item.$1, item.$2);
          setState(() {
            update();
          });
        },
        show: "${item.$1}白银\n1${item.$3}",
      ));
      if (tmpWid.length % 3 == 0) {
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

  List<(int, AddFile, String)> buildListA() {
    return [
      (600, AddFiles.aGuwanChaHu(), "茶壶"),
      (300, AddFiles.aGuwanChaZhan(), "茶盏"),
    ];
  }

  List<(int, FilePassword, String)> buildListP() {
    return [
      (200, Files.aCiQiReader(), "瓷器"),
      (300, Files.aBeiKeReader(), "碑刻"),
      (200, Files.aYuPeiReader(), "玉佩"),
    ];
  }

  @override
  Widget build(BuildContext context) {
    update();
    return Scaffold(
      appBar: Simple.simpleBar(
        title: '古玩店铺',
        back: Simple.backButton(context: context, route: '/apage/shoppage'),
      ),
      body: Center(
        child: Column(
          children: [
            const SizedBox(height: 5),
            Simple.simpleShowText(show: "白银: $baiy"),
            const SizedBox(height: 120),
            Simple.nullSpace(),
            ...buildUI(buildListA(), buildListP()),
          ],
        ),
      ),
    );
  }
}
