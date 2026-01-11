import 'package:flutter/material.dart';
import 'package:flutter_riverpod/flutter_riverpod.dart';
import 'package:study_platform/logic/lihe.dart';
import 'package:study_platform/tool/once_file.dart';
import 'package:study_platform/vars/dialog.dart';
import 'package:study_platform/vars/files.dart';
import 'package:study_platform/vars/logger.dart';
import 'package:study_platform/vars/simple.dart';
import 'package:study_platform/vars/styles.dart';

class LihePage extends ConsumerWidget {
  const LihePage({super.key});

  Widget getLihe(
      String show, OnceFile file, void Function() func, BuildContext context) {
    bool cane = file.canExecute;
    String showt;
    if (cane) {
      showt = "使用";
    } else {
      showt = "已使用";
    }
    return Wrap(
      alignment: WrapAlignment.center,
      children: [
        ElevatedButton(
          onPressed: () {},
          style: Styles.buttonSimpleStyle(),
          child: Text(
            show,
            style: Styles.simpleTextStyle(),
          ),
        ),
        const SizedBox(
          width: 30,
        ),
        ElevatedButton(
            onPressed: () {
              globalLogger.trace("礼盒使用按钮被点击");
              globalLogger.trace("礼盒使用状态: $cane");
              if (cane) {
                var res = file.use();
                if (res) func();
                globalLogger.trace("礼盒使用成功");
                Navigator.pushNamed(context, '/ownpage/lihepage');
                Dialogs.dialogShow(Dialogs.dialogInfo("礼盒使用完成"), context);
              } else {
                globalLogger.trace("礼盒已使用");
                Dialogs.dialogShow(Dialogs.dialogAlert("礼盒已使用"), context);
              }
            },
            style: Styles.buttonSimpleStyle(),
            child: Text(
              showt,
              style: Styles.simpleTextStyle(),
            )),
      ],
    );
  }

  @override
  Widget build(BuildContext context, WidgetRef ref) {
    return Scaffold(
      appBar: Simple.simpleBar(
        title: '我的礼盒',
        back: Simple.backButton(context: context, route: '/ownpage'),
      ),
      body: Center(
        child: Column(
          children: [
            const SizedBox(height: 110),
            Simple.nullSpace(),
            getLihe(
              "基础礼盒",
              LiheFiles.basicLihe(),
              Lihe.dealBasic,
              context,
            ),
          ],
        ),
      ),
    );
  }
}
