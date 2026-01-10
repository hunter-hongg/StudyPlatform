import 'package:flutter/material.dart';
import 'package:flutter_riverpod/flutter_riverpod.dart';
import 'package:study_platform/logic/env_mod.dart';
import 'package:study_platform/tool/stopwatch.dart';
import 'package:study_platform/tool/timer.dart';
import 'package:study_platform/vars/dialog.dart';
import 'package:study_platform/vars/files.dart';
import 'package:study_platform/vars/logger.dart';
import 'package:study_platform/vars/styles.dart';
import 'package:study_platform/vars/timers.dart';

final user = EnvMod.getUser();
final jifenStr = Files.jiFenReader().readStrSafeSync();

class TimePage extends ConsumerWidget {
  const TimePage({super.key});
  @override
  Widget build(BuildContext context, WidgetRef ref) {
    return Scaffold(
      appBar: AppBar(
        title: Text('学习计时'),
        centerTitle: true,
        titleTextStyle: Styles.titleDownStyle(),
      ),
      body: Center(
        child: Column(
          children: [
            SizedBox(height: 140),
            ElevatedButton(
              onPressed: () {
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
              style: Styles.buttonSimpleStyle(),
              child: Text("开始计时", style: Styles.simpleTextStyle()),
            ),
            SizedBox(
              height: 20,
            ),
            ElevatedButton(
                onPressed: () {
                  if (jiFenTimer.status != StopWatchStatus.running) {
                    showDialog(
                        context: context,
                        builder: (context) => Dialogs.dialogAlert("未开始计时"));
                  } else {
                    jiFenTimer.pause();
                    final scd = jiFenTimer.elapsed.inMilliseconds;
                    final min = (scd / 60).toInt();
                    showDialog(
                        context: context,
                        builder: (context) => Dialogs.dialogInfo("计时结束\n"
                            "本次共计$scd秒，$min分钟\n"));
                  }
                },
                style: Styles.buttonSimpleStyle(),
                child: Text("停止计时", style: Styles.simpleTextStyle()))
          ],
        ),
      ),
    );
  }
}
