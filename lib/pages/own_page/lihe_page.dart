import 'package:flutter/material.dart';
import 'package:flutter_riverpod/flutter_riverpod.dart';
import 'package:study_platform/vars/simple.dart';

class LihePage extends ConsumerWidget {
  const LihePage({super.key});

  @override
  Widget build(BuildContext context, WidgetRef ref) {
    return Scaffold(
      appBar: Simple.simpleBar(
        title: '我的礼盒',
        back: Simple.backButton(context: context, route: '/ownpage'),
      ),
      body: Center(
        child: Column(
          children: [
            const SizedBox(height: 5),
            const SizedBox(height: 110),
          ],
        ),
      ),
    );
  }
}
