import 'package:flutter/material.dart';
import 'package:flutter_riverpod/flutter_riverpod.dart';
import 'package:study_platform/vars/files.dart';
import 'package:study_platform/vars/simple.dart';
import 'package:study_platform/vars/styles.dart';

class APage extends ConsumerWidget {
  const APage({super.key});

  @override
  Widget build(BuildContext context, WidgetRef ref) {
    return Scaffold(
      appBar: Simple.simpleBar(
        title: '古代广场',
        back: Simple.backButton(context: context, route: '/'),
      ),
      body: Center(
        child: Column(
          children: [
            const SizedBox(height: 5),
            Text(
              '铜钱: ${Files.aTongQianReader().readStrSafeSync()}\n'
              '白银: ${Files.aBaiYinReader().readStrSafeSync()}\n'
              '黄金: ${Files.aHuangJinReader().readStrSafeSync()}',
              style: Styles.showstrStyle(),
            ),
            const SizedBox(height: 70),
            Simple.simpleClick(
              func: () {
                Navigator.pushNamed(context, '/apage/thingpage');
              },
              show: "我的物品",
            ),
            Simple.simpleSpace(),
            Simple.simpleClick(
              func: () {
                Navigator.pushNamed(context, '/apage/shoppage');
              },
              show: '古代店铺',
            ),
            Simple.simpleSpace(),
            Simple.simpleClick(
              func: () {
                Navigator.pushNamed(context, '/apage/juanpage');
              },
              show: '我的捐献',
            ),
            Simple.simpleSpace(),
            Simple.simpleClick(
              func: () {
                Navigator.pushNamed(context, '/apage/usepage');
              },
              show: '物品使用',
            ),
          ],
        ),
      ),
    );
  }
}
