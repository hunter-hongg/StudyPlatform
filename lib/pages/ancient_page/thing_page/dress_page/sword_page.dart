import 'package:flutter/material.dart';
import 'package:study_platform/logic/asword.dart';
import 'package:study_platform/vars/files.dart';
import 'package:study_platform/vars/simple.dart';

class AThingDressSwordPage extends StatefulWidget {
  const AThingDressSwordPage({super.key});

  @override
  State<AThingDressSwordPage> createState() => _AThingDressSwordPageState();
}

class _AThingDressSwordPageState extends State<AThingDressSwordPage> {
  String sword = "未知";

  void updateSword() {
    setState(() {
      sword = Special.aSword().getNow().toString();
    });
  }

  List<Widget> buildUI(List<(String, Sword)> pairs) {
    var widgets = <Widget>[], tmpWid = <Widget>[];
    for (int i = 0; i < pairs.length; i++) {
      var pair = pairs[i];
      tmpWid.add(
        Simple.simpleClick(
          func: () {
            Simple.simpleInfo(context: context, show: "切换成功");
            Special.aSword().change(pair.$2);
            updateSword();
          },
          show: pair.$1,
        ),
      );
      if (i % 3 == 2) {
        widgets.add(Simple.simpleRow(
          widgets: tmpWid,
        ));
        widgets.add(Simple.simpleSpace());
        tmpWid = <Widget>[];
      }
    }
    if (tmpWid.isNotEmpty) {
      widgets.add(Simple.simpleRow(
        widgets: tmpWid,
      ));
    }
    return widgets;
  }

  List<(String, Sword)> getSwords() {
    var swords = <(String, Sword)>[];
    for (var sword in Special.aSword().getAll()) {
      swords.add((sword.toString(), sword));
    }
    return swords;
  }

  @override
  Widget build(BuildContext context) {
    updateSword();
    return Scaffold(
      appBar: Simple.simpleBar(
        title: '我的佩剑',
        back: Simple.backButton(
          context: context,
          route: '/apage/thingpage/dresspage',
        ),
      ),
      body: Center(
        child: Column(
          children: [
            const SizedBox(height: 10),
            Simple.simpleShowText(show: "佩剑: $sword"),
            const SizedBox(height: 120),
            ...buildUI(getSwords()),
          ],
        ),
      ),
    );
  }
}
