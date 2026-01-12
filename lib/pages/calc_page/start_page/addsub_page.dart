import 'package:flutter/material.dart';
import 'package:flutter_riverpod/flutter_riverpod.dart';
import 'package:study_platform/tool/random.dart';
import 'package:study_platform/vars/dialog.dart';
import 'package:study_platform/vars/files.dart';
import 'package:study_platform/vars/logger.dart';
import 'package:study_platform/vars/simple.dart';
import 'package:study_platform/vars/styles.dart';

class CalcAddsubPage extends ConsumerWidget {
  const CalcAddsubPage({super.key});

  @override
  Widget build(BuildContext context, WidgetRef ref) {
    int op = RandomGet.getWith01();
    String opReal = (op == 0) ? '+' : '-';
    int opNum1 = RandomGet.getIntClosed(1000, 20000);
    int opNum2 = RandomGet.getIntClosed(1000, 20000);
    int realRes = (op == 0) ? (opNum1 + opNum2) : (opNum1 - opNum2);
    return Scaffold(
      appBar: Simple.simpleBar(
        title: '加减练习',
        back: Simple.backButton(context: context, route: '/calcpage/startpage'),
      ),
      body: Center(
        child: Column(
          children: [
            const SizedBox(height: 160),
            Text(
              "请解决: $opNum1 $opReal $opNum2 ",
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
                  globalLogger.trace("加减法页面输入内容为$input");
                  var pres = int.tryParse(input);
                  if (pres == null) {
                    Dialogs.dialogShow(Dialogs.dialogAlert("数字解析失败"), context);
                    globalLogger.warn("加减法页面解析失败$input");
                    return;
                  }
                  Navigator.pushNamed(
                      context, '/calcpage/startpage/addsubpage');
                  if (realRes == pres) {
                    Dialogs.dialogShow(Dialogs.dialogInfo("计算正确"), context);
                    globalLogger.trace("加减法页面计算正确 +60计算币");
                    Files.jiSuanBiReader().addNum(60);
                  } else {
                    Dialogs.dialogShow(Dialogs.dialogInfo("计算错误"), context);
                    globalLogger.trace("加减法页面计算错误");
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
