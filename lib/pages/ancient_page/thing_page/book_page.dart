import 'package:flutter/material.dart';
import 'package:study_platform/vars/files.dart';
import 'package:study_platform/vars/simple.dart';

class AThingBookPage extends StatefulWidget {
  const AThingBookPage({super.key});

  @override
  State<AThingBookPage> createState() => _AThingBookPageState();
}

class _AThingBookPageState extends State<AThingBookPage> {
  List<Widget> buildUI(List<(String, String)> pairs) {
    var wid = <Widget>[], tmpWid = <Widget>[];
    for (int i = 0; i < pairs.length; i++) {
      tmpWid.add(Simple.simpleClick(
        func: () {
          setState(() {});
        },
        show: "${pairs[i].$1}: ${pairs[i].$2}本",
      ));
      if (i % 3 == 2) {
        wid.add(Simple.simpleRow(
          widgets: tmpWid,
        ));
        wid.add(Simple.simpleSpace());
        tmpWid = <Widget>[];
      }
    }

    if (tmpWid.isNotEmpty) {
      wid.add(Simple.simpleRow(
        widgets: tmpWid,
      ));
    }

    return wid;
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: Simple.simpleBar(
        title: '我的书籍',
        back: Simple.backButton(context: context, route: '/apage/thingpage'),
      ),
      body: Center(
        child: Column(
          children: [
            const SizedBox(height: 140),
            Simple.nullSpace(),
            ...buildUI([
              ("普通书籍", AddFiles.aBook1().readStrSafe()),
              ("珍稀书籍", AddFiles.aBook2().readStrSafe()),
              ("典藏书籍", AddFiles.aBook3().readStrSafe()),
              ("抄录书籍1级", AddFiles.aBookC1().readStrSafe()),
              ("抄录书籍2级", AddFiles.aBookC2().readStrSafe()),
              ("抄录书籍3级", AddFiles.aBookC3().readStrSafe()),
              ("抄录书籍4级", AddFiles.aBookC4().readStrSafe()),
              ("抄录书籍5级", AddFiles.aBookC5().readStrSafe()),
            ])
          ],
        ),
      ),
    );
  }
}
