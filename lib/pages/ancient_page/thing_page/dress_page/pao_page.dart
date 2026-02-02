import 'package:flutter/material.dart';
import 'package:study_platform/logic/apao.dart';
import 'package:study_platform/vars/files.dart';
import 'package:study_platform/vars/simple.dart';

class AThingDressPaoPage extends StatefulWidget {
  const AThingDressPaoPage({super.key});

  @override
  State<AThingDressPaoPage> createState() => _AThingDressPaoPageState();
}

class _AThingDressPaoPageState extends State<AThingDressPaoPage> {
  String pao = "未知";

  void updatePao() {
    setState(() {
      pao = Special.aPao().getNow().toString();
    });
  }

  List<Widget> buildUI(List<(String, Pao)> pairs) {
    var widgets = <Widget>[], tmpWid = <Widget>[];
    for (int i = 0; i < pairs.length; i++) {
      var pair = pairs[i];
      tmpWid.add(
        Simple.simpleClick(
          func: () {
            Simple.simpleInfo(context: context, show: "切换成功");
            Special.aPao().change(pair.$2);
            updatePao();
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

  List<(String, Pao)> getPaos() {
    var paos = <(String, Pao)>[];
    for (var pao in Special.aPao().getAll()) {
      paos.add((pao.toString(), pao));
    }
    return paos;
  }

  @override
  Widget build(BuildContext context) {
    updatePao();
    return Scaffold(
      appBar: Simple.simpleBar(
        title: '我的锦袍',
        back: Simple.backButton(
          context: context,
          route: '/apage/thingpage/dresspage',
        ),
      ),
      body: Center(
        child: Column(
          children: [
            const SizedBox(height: 10),
            Simple.simpleShowText(show: "锦袍: $pao"),
            const SizedBox(height: 120),
            ...buildUI(getPaos()),
          ],
        ),
      ),
    );
  }
}
