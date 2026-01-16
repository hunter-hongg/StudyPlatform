import 'package:flutter/material.dart';
import 'package:flutter_riverpod/flutter_riverpod.dart';
import 'package:study_platform/vars/simple.dart';

class ThingMainPage extends ConsumerWidget {
  const ThingMainPage({super.key});

  @override
  Widget build(BuildContext context, WidgetRef ref) {
    return Scaffold(
      appBar: Simple.simpleBar(
        title: '物品主页',
        back: Simple.backButton(context: context, route: '/ownpage/thingpage'),
      ),
      body: Center(
        child: Column(
          children: [
            const SizedBox(height: 150),
            Simple.simpleClick(
              func: () {
                Navigator.pushNamed(
                    context, '/ownpage/thingpage/mainpage/cardpage');
              },
              show: "我的卡牌",
            ),
            Simple.simpleSpace(),
            Simple.simpleClick(
              func: () {
                // Navigator.pushNamed(context, '/ownpage/thingpage/mainpage');
              },
              show: "未知物品",
            )
          ],
        ),
      ),
    );
  }
}
