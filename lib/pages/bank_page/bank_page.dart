import 'package:flutter/material.dart';
import 'package:flutter_riverpod/flutter_riverpod.dart';
import 'package:study_platform/vars/files.dart';
import 'package:study_platform/vars/simple.dart';
import 'package:study_platform/vars/styles.dart';

class BankPage extends ConsumerWidget {
  const BankPage({super.key});

  @override
  Widget build(BuildContext context, WidgetRef ref) {
    return Scaffold(
      appBar: Simple.simpleBar(
        title: '积分银行',
        back: Simple.backButton(context: context, route: '/'),
      ),
      body: Center(
        child: Column(
          children: [
            const SizedBox(height: 5),
            Text('存储积分: ${Files.bankSReader().readStrSafeSync()}',
                style: Styles.showstrStyle()),
            const SizedBox(height: 110),
            Simple.simpleClick(
              func: () {
                Navigator.pushNamed(context, '/bankpage/storepage');
              },
              show: "存储积分",
            ),
            Simple.simpleSpace(),
            Simple.simpleClick(
              func: () {
                // Navigator.pushNamed(context, '/ownpage/thingpage');
              },
              show: "取出积分",
            ),
            Simple.simpleSpace(),
            Simple.simpleClick(
              func: () {
                // Navigator.pushNamed(context, '/ownpage/lihepage');
              },
              show: "积分捐献",
            ),
          ],
        ),
      ),
    );
  }
}
