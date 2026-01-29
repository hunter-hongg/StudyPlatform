import 'package:flutter/material.dart';
import 'package:flutter_riverpod/flutter_riverpod.dart';
import 'package:study_platform/vars/simple.dart';

class AThingPage extends ConsumerWidget {
  const AThingPage({super.key});

  @override
  Widget build(BuildContext context, WidgetRef ref) {
    return Scaffold(
      appBar: Simple.simpleBar(
        title: '我的物品',
        back: Simple.backButton(context: context, route: '/apage'),
      ),
      body: Center(
        child: Column(
          children: [
            const SizedBox(height: 140),
            Simple.simpleClick(
              func: () {
                Navigator.pushNamed(context, '/apage/thingpage/caipage');
              },
              show: '我的财物',
            ),
          ],
        ),
      ),
    );
  }
}
