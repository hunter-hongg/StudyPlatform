import 'package:flutter/material.dart';
import 'package:flutter_riverpod/flutter_riverpod.dart';
import 'package:study_platform/logic/env_mod.dart';
import 'package:study_platform/vars/files.dart';
import 'package:study_platform/vars/styles.dart';

// Riverpod状态提供者（全局可访问）
final counterProvider = StateProvider<int>((ref) => 0);
final user = EnvMod.getUser();

class HomePage extends ConsumerWidget {
  const HomePage({super.key});
  // ConsumerWidget用于访问状态
  @override
  Widget build(BuildContext context, WidgetRef ref) {
    final jifenStr = Files.jiFenReader().readStrSafeSync();
    return Scaffold(
      appBar: AppBar(
        title: Text('欢迎$user来到学习平台'),
        centerTitle: true,
        titleTextStyle: Styles.titleStyle(),
      ),
      body: Center(
        child: Column(
          children: [
            SizedBox(height: 5,),
            Text('积分: $jifenStr',
                style: Styles.showstrStyle())
            //   const SizedBox(height: 20),
            //   ElevatedButton(
            //     onPressed: () async {
            //       final current = ref.read(counterProvider);
            //       final newCount = await CounterService.incrementFromBackend(current);
            //       ref.read(counterProvider.notifier).state = newCount;
            //     },
            //     child: const Text('点击+1'),
            //   ),
          ],
        ),
      ),
    );
  }
}
