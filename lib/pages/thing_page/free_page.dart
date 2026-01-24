import 'package:flutter/material.dart';
import 'package:flutter_riverpod/flutter_riverpod.dart';
import 'package:study_platform/vars/simple.dart';

class TSFreePage extends ConsumerWidget {
  const TSFreePage({super.key});

  @override
  Widget build(BuildContext context, WidgetRef ref) {
    return Scaffold(
      appBar: Simple.simpleBar(
        title: '免费物品',
        back: Simple.backButton(context: context, route: '/thingpage'),
      ),
      body: Center(
        child: Column(
          children: [
            const SizedBox(height: 140),
            Simple.nullSpace(),
          ],
        ),
      ),
    );
  }
}
