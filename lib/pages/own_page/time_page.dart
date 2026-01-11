import 'package:flutter/material.dart';
import 'package:flutter_riverpod/flutter_riverpod.dart';
import 'package:study_platform/logic/env_mod.dart';
import 'package:study_platform/logic/time_end.dart';
import 'package:study_platform/tool/stopwatch.dart';
import 'package:study_platform/vars/dialog.dart';
import 'package:study_platform/vars/files.dart';
import 'package:study_platform/vars/rule.dart';
import 'package:study_platform/vars/simple.dart';
import 'package:study_platform/vars/styles.dart';
import 'package:study_platform/vars/timers.dart';

final user = EnvMod.getUser();
final jifenStr = Files.jiFenReader().readStrSafeSync();

class TimePage extends ConsumerWidget {
  const TimePage({super.key});
  @override
  Widget build(BuildContext context, WidgetRef ref) {
    return Scaffold(
      appBar: Simple.simpleBar(
        title: '学习计时',
        back: Simple.backButton(context: context, route: '/ownpage'),
      ),
      body: Center(
        child: Column(
          children: [
            SizedBox(height: 140),
            Simple.simpleClick(
              func: () {
                if (jiFenTimer.status == StopWatchStatus.running) {
                  showDialog(
                    context: context,
                    builder: (context) => Dialogs.dialogAlert("已经开始计时"),
                  );
                } else {
                  jiFenTimer.reset();
                  jiFenTimer.start();
                }
              },
              show: "开始计时",
            ),
            Simple.simpleSpace(),
            Simple.simpleClick(
              func: () {
                if (jiFenTimer.status != StopWatchStatus.running) {
                  showDialog(
                      context: context,
                      builder: (context) => Dialogs.dialogAlert("未开始计时"));
                } else {
                  jiFenTimer.pause();
                  final showStr = TimeEnd.dealTimeEnd();
                  showDialog(
                      context: context,
                      builder: (context) => Dialogs.dialogInfo(showStr));
                }
              },
              show: "停止计时",
            ),
            Simple.simpleSpace(),
            Simple.simpleClick(
              func: () {
                showDialog(
                  context: context,
                  builder: (context) => Dialogs.dialogInfo(Rule.timeRule()),
                );
              },
              show: "计时规则",
            )
          ],
        ),
      ),
    );
  }
}
