import 'package:flutter/material.dart';
import 'package:flutter_riverpod/flutter_riverpod.dart';
import 'package:study_platform/logic/calc_poly.dart';
import 'package:study_platform/tool/poly.dart';
import 'package:study_platform/vars/dialog.dart';
import 'package:study_platform/vars/files.dart';
import 'package:study_platform/vars/simple.dart';
import 'package:study_platform/vars/styles.dart';

class CalcPolyPage extends ConsumerWidget {
  const CalcPolyPage({super.key});

  @override
  Widget build(BuildContext context, WidgetRef ref) {
    final TextEditingController zerocon = TextEditingController();
    final TextEditingController onecon = TextEditingController();
    var pl = CalcPoly.getRandomPoly();
    String pls = pl.toStringBetter();
    return Scaffold(
      appBar: Simple.simpleBar(
        title: '因式分解',
        back: Simple.backButton(context: context, route: '/calcpage/startpage'),
      ),
      body: Center(
        child: Column(
          children: [
            const SizedBox(height: 160),
            Text(
              "请分解: $pls",
              style: Styles.simpleTextUpStyle(),
            ),
            const SizedBox(height: 40),
            FractionallySizedBox(
              widthFactor: 0.3,
              child: TextField(
                controller: zerocon,
                decoration: InputDecoration(
                  labelText: '请输入零次项',
                  hintText: '请输入零次项',
                  border: OutlineInputBorder(),
                ),
              ),
            ),
            Simple.simpleSpace(),
            FractionallySizedBox(
              widthFactor: 0.3,
              child: TextField(
                controller: onecon,
                decoration: InputDecoration(
                  labelText: '请输入一次项',
                  hintText: '请输入一次项',
                  border: OutlineInputBorder(),
                ),
              ),
            ),
            Simple.simpleSpace(),
            Simple.simpleClick(
              func: () {
                var intzero = int.tryParse(zerocon.text);
                var intone = int.tryParse(onecon.text);
                if ((intzero == null) || (intone == null)) {
                  Dialogs.dialogShow(Dialogs.dialogAlert("数字解析失败"), context);
                  return;
                }
                var res = CalcPoly.userPoly(intzero, intone);
                if (res == null) return;
                if (!CheckFiles.calcPolyCheck().checkTimesSync()) {
                  Dialogs.dialogShow(Dialogs.dialogInfo("今日次数使用完毕"), context);
                  return;
                }
                Navigator.pushNamed(context, '/calcpage/startpage/polypage');
                if (res) {
                  Dialogs.dialogShow(Dialogs.dialogInfo("计算正确 +180计算币"), context);
                  Files.jiSuanBiReader().addNum(180);
                } else {
                  Dialogs.dialogShow(Dialogs.dialogInfo("计算错误"), context);
                }
              },
              show: "提交",
            ),
          ],
        ),
      ),
    );
  }
}
