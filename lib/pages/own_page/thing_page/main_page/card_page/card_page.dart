import 'package:flutter/material.dart';
import 'package:flutter_riverpod/flutter_riverpod.dart';
import 'package:study_platform/vars/simple.dart';

class ThingMainCardPage extends ConsumerWidget {
  const ThingMainCardPage({super.key});

  @override
  Widget build(BuildContext context, WidgetRef ref) {
    return Scaffold(
      appBar: Simple.simpleBar(
        title: '我的卡牌',
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
                    context, '/ownpage/thingpage/mainpage/cardpage/sang1page');
              },
              show: "三国卡牌1",
            ),
            Simple.simpleSpace(),
            Simple.simpleClick(
              func: () {
                Navigator.pushNamed(
                    context, '/ownpage/thingpage/mainpage/cardpage/han1page');
              },
              show: "汉朝卡牌1",
            )
          ],
        ),
      ),
    );
  }
}
