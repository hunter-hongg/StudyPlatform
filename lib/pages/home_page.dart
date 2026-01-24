import 'package:flutter/material.dart';
import 'package:flutter_riverpod/flutter_riverpod.dart';
import 'package:study_platform/logic/env_mod.dart';
import 'package:study_platform/logic/jifen.dart';
import 'package:study_platform/logic/state.dart';
import 'package:study_platform/vars/files.dart';
import 'package:study_platform/vars/logger.dart';
import 'package:study_platform/vars/simple.dart';
import 'package:study_platform/vars/styles.dart';

final user = EnvMod.getUser();

class HomePage extends ConsumerWidget {
  const HomePage({super.key});

  List<Widget> buildGrid(
      BuildContext context, List<Widget> left, List<Widget> right) {
    var wid = <Widget>[];
    if (left.length != right.length) return wid;
    for (int i = 0; i < left.length; ++i) {
      wid += [
        Wrap(
          alignment: WrapAlignment.center,
          spacing: 20,
          children: [
            left[i],
            right[i],
          ],
        ),
        Simple.simpleSpace(),
      ];
    }
    wid.removeLast();
    return wid;
  }

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
      Simple.simpleClick(
        func: () {},
        show: "物品领取",
      ),
      Simple.simpleClick(
        func: () {
          StateDealing.dealState(
            context,
            Setting.enableUtil(),
            true,
            () {
              Navigator.pushNamed(context, '/utilpage');
            },
            "工具未开启, 请前往设置开启",
          );
        },
        show: "工具页面",
      ),
    ];

    // 右边列的项目
    final List<Widget> rightColumnItems = [
      Simple.simpleClick(
        func: () {},
        show: "神话传说",
      ),
      Simple.simpleClick(
        func: () {
          Navigator.pushNamed(context, '/apage');
        },
        show: "古代广场",
      ),
      Simple.simpleClick(
        func: () {
          Navigator.pushNamed(context, '/bankpage');
        },
        show: "积分银行",
      ),
      Simple.simpleClick(
        func: () {
          Navigator.pushNamed(context, '/settingpage');
        },
        show: "设置页面",
      ),
    ];

    return Scaffold(
      appBar: Simple.simpleBar(
        title: "欢迎$user 来到学习平台",
      ),
      body: Column(
        children: [
          SizedBox(height: 10),
          Text('积分: $jifenStr', style: Styles.showstrStyle()),
          Text('等级: $jifenLev', style: Styles.showstrStyle()),
          SizedBox(height: 95),
          Simple.nullSpace(),
          ...buildGrid(
            context,
            leftColumnItems,
            rightColumnItems,
          ),
        ],
      ),
    );
  }
}
