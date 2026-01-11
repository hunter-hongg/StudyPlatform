import 'package:flutter/material.dart';
import 'package:flutter_riverpod/flutter_riverpod.dart';
import 'package:study_platform/vars/simple.dart';

class ThingShowPage extends ConsumerWidget {
  const ThingShowPage({super.key});

  @override
  Widget build(BuildContext context, WidgetRef ref) {

    return Scaffold(
      appBar: Simple.simpleBar(
        title: '物品查看',
        back: Simple.backButton(context: context, route: '/ownpage/thingpage'),
      ),
      body: Center(
        child: Column(
          children: [
            const SizedBox(height: 110),
          ],
        ),
      ),
    );
  }
}
