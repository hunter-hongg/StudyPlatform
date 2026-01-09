import 'package:flutter/material.dart';
import 'package:flutter_riverpod/flutter_riverpod.dart';
import 'package:study_platform/logic/env_mod.dart';
import 'package:study_platform/vars/files.dart';
import 'package:study_platform/vars/styles.dart';

final counterProvider = StateProvider<int>((ref) => 0);
final user = EnvMod.getUser();

class HomePage extends ConsumerWidget {
  const HomePage({super.key});

  @override
  Widget build(BuildContext context, WidgetRef ref) {
    final jifenStr = Files.jiFenReader().readStrSafeSync();
    
    // 左边列的项目
    final List<Widget> leftColumnItems = [
      ElevatedButton(
        onPressed: () {},
        style: Styles.buttonSimpleStyle(),
        child: const Text("个人主页"),
      ),
      ElevatedButton(
        onPressed: () {},
        style: Styles.buttonSimpleStyle(),
        child: const Text("计算广场"),
      ),
    ];
    
    // 右边列的项目
    final List<Widget> rightColumnItems = [
      ElevatedButton(
        onPressed: () {},
        style: Styles.buttonSimpleStyle(),
        child: const Text("神话传说"),
      ),
      ElevatedButton(
        onPressed: () {},
        style: Styles.buttonSimpleStyle(),
        child: const Text("古代广场"),
      ),
    ];

    return Scaffold(
      appBar: AppBar(
        title: Text('欢迎$user来到学习平台'),
        centerTitle: true,
        titleTextStyle: Styles.titleStyle(),
      ),
      body: Column(
        children: [
          SizedBox(height: 10),
          Text('积分: $jifenStr', style: Styles.showstrStyle()),
          SizedBox(height: 80),
          Center(
            child: Row(
              spacing: 20,
            )
          ),
          Wrap(
            alignment: WrapAlignment.center,
            spacing: 20,
            children: [
              leftColumnItems[0], 
              rightColumnItems[0],
            ],
          ),
          SizedBox(height: 20,),
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