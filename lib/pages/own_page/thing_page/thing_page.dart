import 'package:flutter/material.dart';
import 'package:flutter_riverpod/flutter_riverpod.dart';
import 'package:study_platform/vars/simple.dart';

class ThingPage extends ConsumerWidget {
  const ThingPage({super.key});

  @override
  Widget build(BuildContext context, WidgetRef ref) {
    return Scaffold(
      appBar: Simple.simpleBar(
        title: '我的物品',
        back: Simple.backButton(context: context, route: '/ownpage'),
      ),
      body: Center(
        child: Column(
          children: [
            const SizedBox(height: 150),
            Simple.simpleClick(
              func: () {
                Navigator.pushNamed(context, '/ownpage/thingpage/showpage');
              },
              show: "物品查看",
            ),
            Simple.simpleSpace(),
            Simple.simpleClick(
              func: () {
                Navigator.pushNamed(context, '/ownpage/thingpage/mainpage');
              },
              show: "物品主页",
            ),
            Simple.simpleSpace(),
            Simple.simpleClick(
              func: () {
                Navigator.pushNamed(context, '/ownpage/thingpage/shoppage');
              },
              show: "物品商城",
            )
          ],
        ),
      ),
    );
  }
}
