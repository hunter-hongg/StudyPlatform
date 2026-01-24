import 'package:flutter/material.dart';
import 'package:flutter_riverpod/flutter_riverpod.dart';
import 'package:study_platform/vars/simple.dart';

class TSPage extends ConsumerWidget {
  const TSPage({super.key});

  @override
  Widget build(BuildContext context, WidgetRef ref) {
    return Scaffold(
      appBar: Simple.simpleBar(
        title: '物品领取',
        back: Simple.backButton(context: context, route: '/'),
      ),
      body: Center(
        child: Column(
          children: [
            const SizedBox(height: 140),
            Simple.simpleClick(
              func: () {
                Navigator.pushNamed(context, '/thingpage/freepage');
              },
              show: '免费领取',
            ),
            Simple.simpleSpace(),
            Simple.simpleClick(
              func: () {},
              show: '金币领取',
            ),
            Simple.simpleSpace(),
            Simple.simpleClick(
              func: () {},
              show: '金币盲盒',
            ),
          ],
        ),
      ),
    );
  }
}
