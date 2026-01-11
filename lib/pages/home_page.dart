import 'package:flutter/material.dart';
import 'package:flutter_riverpod/flutter_riverpod.dart';
import 'package:study_platform/logic/env_mod.dart';
import 'package:study_platform/logic/jifen.dart';
import 'package:study_platform/vars/files.dart';
import 'package:study_platform/vars/logger.dart';
import 'package:study_platform/vars/simple.dart';
import 'package:study_platform/vars/styles.dart';

final counterProvider = StateProvider<int>((ref) => 0);
final user = EnvMod.getUser();

class HomePage extends ConsumerWidget {
  const HomePage({super.key});

  @override
  Widget build(BuildContext context, WidgetRef ref) {
    globalLogger.trace("主页面成功加载");
    final jifenStr = Files.jiFenReader().readStrSafeSync();
    final jifenInt = Files.jiFenReader().readIntSafeSync();
    final jifenLev = Jifen.getLevel(jifenInt);

    // 左边列的项目
    final List<Widget> leftColumnItems = [
      Simple.simpleClick(
        func: () {
          Navigator.pushNamed(context, '/ownpage');
        },
        show: "个人主页",
      ),
      Simple.simpleClick(
        func: () {
          Navigator.pushNamed(context, '/calcpage');
        },
        show: "计算广场",
      ),
    ];

    // 右边列的项目
    final List<Widget> rightColumnItems = [
      Simple.simpleClick(
        func: () {},
        show: "神话传说",
      ),
      Simple.simpleClick(
        func: () {},
        show: "计算广场",
      ),
    ];

    return Scaffold(
      appBar: Simple.simpleBar(
        title: "欢迎$user来到学习平台",
      ),
      body: Column(
        children: [
          SizedBox(height: 10),
          Text('积分: $jifenStr', style: Styles.showstrStyle()),
          Text('等级: $jifenLev', style: Styles.showstrStyle()),
          SizedBox(height: 95),
          Simple.nullSpace(),
          Wrap(
            alignment: WrapAlignment.center,
            spacing: 20,
            children: [
              leftColumnItems[0],
              rightColumnItems[0],
            ],
          ),
          Simple.simpleSpace(),
          Wrap(
            alignment: WrapAlignment.center,
            spacing: 20,
            children: [
              leftColumnItems[1],
              rightColumnItems[1],
            ],
          )
        ],
      ),
    );
  }
}
