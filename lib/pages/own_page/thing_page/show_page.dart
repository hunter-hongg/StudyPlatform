import 'package:flutter/material.dart';
import 'package:flutter_riverpod/flutter_riverpod.dart';
import 'package:study_platform/vars/files.dart';
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
            const SizedBox(height: 150),
            Simple.nullSpace(), 
            Wrap(
              alignment: WrapAlignment.center,
              children: [
                Simple.simpleClick(func: (){}, show: "积分: ${Files.jiFenReader().readStrSafeSync()}"),
                const SizedBox(width: 30,),
                Simple.simpleClick(func: (){}, show: "仙币: 0"),
                const SizedBox(width: 30,),
                Simple.simpleClick(func: (){}, show: "宝石: 0"),
              ],
            ),
            Simple.simpleSpace(),
            Wrap(
              alignment: WrapAlignment.center,
              children: [
                Simple.simpleClick(func: (){}, show: "银币: 0"),
                const SizedBox(width: 30,),
                Simple.simpleClick(func: (){}, show: "金币: ${Files.jinBiReader().readStrSafeSync()}"),
                const SizedBox(width: 30,),
                Simple.simpleClick(func: (){}, show: "计算币: ${Files.jiSuanBiReader().readStrSafeSync()}"),
              ],
            ),
            Simple.simpleSpace(),
            Simple.simpleClick(func: (){}, show: "卡牌: 0")
          ],
        ),
      ),
    );
  }
}
