import 'package:flutter/material.dart';
import 'package:flutter_riverpod/flutter_riverpod.dart';
import 'package:study_platform/vars/files.dart';
import 'package:study_platform/vars/simple.dart';
import 'package:study_platform/vars/styles.dart';

class CalcPage extends ConsumerWidget {
  const CalcPage({super.key});

  @override
  Widget build(BuildContext context, WidgetRef ref) {
    return Scaffold(
      appBar: Simple.simpleBar(
        title: '计算广场',
        back: Simple.backButton(context: context, route: '/'),
      ),
      body: Center(
        child: Column(
          children: [
            const SizedBox(height: 5),
            Text('计算币: ${Files.jiSuanBiReader().readStrSafeSync()}', style: Styles.showstrStyle()),
            const SizedBox(height: 110),
          ],
        ),
      ),
    );
  }
}
