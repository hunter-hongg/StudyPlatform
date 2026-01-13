import 'package:flutter/material.dart';
import 'package:flutter_riverpod/flutter_riverpod.dart';
import 'package:study_platform/vars/files.dart';
import 'package:study_platform/vars/simple.dart';
import 'package:study_platform/vars/styles.dart';

class CalcShopPage extends ConsumerWidget {
  const CalcShopPage({super.key});

  @override
  Widget build(BuildContext context, WidgetRef ref) {
    return Scaffold(
      appBar: Simple.simpleBar(
        title: '兑换物品',
        back: Simple.backButton(context: context, route: '/calcpage'),
      ),
      body: Center(
        child: Column(
          children: [
            const SizedBox(height: 5),
            Text('计算币: ${Files.jiSuanBiReader().readStrSafeSync()}',
                style: Styles.showstrStyle()),
            const SizedBox(height: 130),
          ],
        ),
      ),
    );
  }
}
