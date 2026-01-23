import 'package:flutter/material.dart';
import 'package:flutter_riverpod/flutter_riverpod.dart';
import 'package:study_platform/vars/files.dart';
import 'package:study_platform/vars/simple.dart';

class ThingMainBaoshiChouPage extends ConsumerWidget {
  const ThingMainBaoshiChouPage({super.key});

  @override
  Widget build(BuildContext context, WidgetRef ref) {
    return Scaffold(
      appBar: Simple.simpleBar(
        title: '宝石抽奖',
        back: Simple.backButton(
            context: context, route: '/ownpage/thingpage/mainpage/baoshipage'),
      ),
      body: Center(
        child: Column(
          children: [
            const SizedBox(height: 10),
            Simple.simpleShowText(
              show: "宝石: ${Files.baoShiReader().readStrSafeSync()}",
            ),
            const SizedBox(height: 140),
            Simple.simpleClick(
              func: () {
                Navigator.pushNamed(context,
                    '/ownpage/thingpage/mainpage/baoshipage/cpage/c1page');
              },
              show: "宝石抽奖1",
            ),
          ],
        ),
      ),
    );
  }
}
