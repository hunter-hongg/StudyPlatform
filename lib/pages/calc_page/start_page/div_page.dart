import 'package:flutter/material.dart';
import 'package:flutter_riverpod/flutter_riverpod.dart';
import 'package:study_platform/tool/random.dart';
import 'package:study_platform/vars/dialog.dart';
import 'package:study_platform/vars/files.dart';
import 'package:study_platform/vars/logger.dart';
import 'package:study_platform/vars/simple.dart';
import 'package:study_platform/vars/styles.dart';

class CalcDivPage extends ConsumerWidget {
  const CalcDivPage({super.key});

  @override
  Widget build(BuildContext context, WidgetRef ref) {
    int opNum1 = RandomGet.getIntClosed(10, 100);
    int realRes = RandomGet.getIntClosed(10, 100);
    int opNum2 = opNum1 * realRes;
    return Scaffold(
      appBar: Simple.simpleBar(
        title: '除法练习',
        back: Simple.backButton(context: context, route: '/calcpage/startpage'),
      ),
      body: Center(
        child: Column(
          children: [
            const SizedBox(height: 160),
            Text(
              "请解决: $opNum2 / $opNum1 ",
              style: Styles.simpleTextUpStyle(),
            ),
            const SizedBox(height: 40),
            FractionallySizedBox(
              widthFactor: 0.3,
              child: TextField(
                decoration: InputDecoration(
                  labelText: '请输入答案',
                  hintText: '请输入答案(Enter提交)',
                  border: OutlineInputBorder(),
                ),
                onSubmitted: (input) {
                  var pres = int.tryParse(input);
                  if (pres == null) {
                    Dialogs.dialogShow(Dialogs.dialogAlert("数字解析失败"), context);
                    return;
                  }
                  if (!CheckFiles.calcDivCheck().checkTimesSync()) {
                    Dialogs.dialogShow(
                        Dialogs.dialogAlert("今日次数使用完毕"), context);
                    return;
                  }
                  Navigator.pushNamed(context, '/calcpage/startpage/divpage');
                  if (realRes == pres) {
                    Dialogs.dialogShow(Dialogs.dialogInfo("计算正确"), context);
                    Files.jiSuanBiReader().addNumSync(80);
                  } else {
                    Dialogs.dialogShow(Dialogs.dialogInfo("计算错误"), context);
                    globalLogger.trace("乘法页面计算错误");
                  }
                },
              ),
            ),
          ],
        ),
      ),
    );
  }
}
