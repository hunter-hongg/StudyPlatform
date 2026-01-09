import 'package:flutter/material.dart';
import 'package:flutter_riverpod/flutter_riverpod.dart';
import 'package:study_platform/logic/env_mod.dart';
import 'package:study_platform/vars/files.dart';
import 'package:study_platform/vars/styles.dart';

final user = EnvMod.getUser();
final jifenStr = Files.jiFenReader().readStrSafeSync();

class OwnPage extends ConsumerWidget {
  const OwnPage ({super.key});
  @override
  Widget build(BuildContext context, WidgetRef ref) {
    return Scaffold(
      appBar: AppBar(
        title: Text('个人主页'),
        centerTitle: true,
        titleTextStyle: Styles.titleDownStyle(),
      ),
      body: Center(
        child: Column(
          children: [
            SizedBox(height: 5,),
            Text('积分: $jifenStr',
                style: Styles.showstrStyle())
          ],
        ),
      ),
    );
  }
}
