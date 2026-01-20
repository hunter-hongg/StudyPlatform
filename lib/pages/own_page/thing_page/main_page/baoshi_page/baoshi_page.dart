import 'package:flutter/material.dart';
import 'package:flutter_riverpod/flutter_riverpod.dart';
import 'package:study_platform/vars/simple.dart';

class ThingMainBaoshiPage extends ConsumerWidget {
  const ThingMainBaoshiPage({super.key});

  @override
  Widget build(BuildContext context, WidgetRef ref) {
    return Scaffold(
      appBar: Simple.simpleBar(
        title: '我的宝石',
        back: Simple.backButton(
            context: context, route: '/ownpage/thingpage/mainpage'),
      ),
      body: Center(
        child: Column(
          children: [
            const SizedBox(height: 150),
            Simple.simpleClick(
              func: () {
                Navigator.pushNamed(
                    context, '/ownpage/thingpage/mainpage/baoshipage/getpage');
              },
              show: '获取宝石',
            ),
            Simple.simpleSpace(),
            Simple.simpleClick(
              func: () {},
              show: '宝石抽奖',
            )
          ],
        ),
      ),
    );
  }
}
