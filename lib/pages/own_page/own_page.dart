import 'package:flutter/material.dart';
import 'package:flutter_riverpod/flutter_riverpod.dart';
import 'package:study_platform/vars/backbutton.dart';
import 'package:study_platform/vars/files.dart';
import 'package:study_platform/vars/styles.dart';

class OwnPage extends ConsumerWidget {
  const OwnPage({super.key});

  @override
  Widget build(BuildContext context, WidgetRef ref) {
    final jifenStr = Files.jiFenReader().readStrSync();

    return Scaffold(
      appBar: AppBar(
        title: Text('个人主页'),
        centerTitle: true,
        titleTextStyle: Styles.titleDownStyle(),
        leading: BackButtons.backButton(context, '/'),
        automaticallyImplyLeading: false,
      ),
      body: Center(
        child: Column(
          children: [
            const SizedBox(height: 5),
            Text('积分: $jifenStr', style: Styles.showstrStyle()),
            const SizedBox(height: 110),
            ElevatedButton(
              onPressed: () {
                Navigator.pushNamed(context, '/ownpage/timepage');
              },
              style: Styles.buttonSimpleStyle(),
              child: Text(
                "学习计时",
                style: Styles.simpleTextStyle(),
              ),
            )
          ],
        ),
      ),
    );
  }
}
