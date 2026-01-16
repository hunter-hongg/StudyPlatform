import 'package:flutter/material.dart';
import 'package:flutter_riverpod/flutter_riverpod.dart';
import 'package:study_platform/logic/exec.dart';
import 'package:study_platform/vars/files.dart';
import 'package:study_platform/vars/simple.dart';

class UtilPage extends ConsumerWidget {
  const UtilPage({super.key});

  @override
  Widget build(BuildContext context, WidgetRef ref) {
    final jifenStr = Files.jiFenReader().readStrSync();

    return Scaffold(
      appBar: Simple.simpleBar(
        title: '各种工具',
        back: Simple.backButton(context: context, route: '/'),
      ),
      body: Center(
        child: Column(
          children: [
            const SizedBox(height: 140),
            Simple.simpleClick(
              func: () {
                Exec.exec("NoteTool");
              },
              show: "笔记管理",
            ),
            Simple.simpleSpace(),
            Simple.simpleClick(
              func: () {
                Simple.simpleInfo(context: context, show: "退出后按Esc退出太空保卫");
                Future.delayed(Duration(seconds: 2), () {
                  Exec.exec("SpaceGo");
                });
              },
              show: "太空保卫",
            ),
            Simple.simpleSpace(),
          ],
        ),
      ),
    );
  }
}
