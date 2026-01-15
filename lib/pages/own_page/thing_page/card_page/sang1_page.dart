import 'package:flutter/material.dart';
import 'package:flutter_riverpod/flutter_riverpod.dart';
import 'package:study_platform/vars/files.dart';
import 'package:study_platform/vars/simple.dart';
import 'package:study_platform/vars/styles.dart';

class ThingMainCardSang1Page extends ConsumerWidget {
  const ThingMainCardSang1Page({super.key});

  List<Widget> buildCards(List<String> cards) {
    var wid = <Widget>[];
    for (var i = 0; i <= cards.length ~/ 16; ++i) {
      var limit = ((cards.length < (i + 1) * 16) ? cards.length : (i + 1) * 16);
        var widj = <Widget>[];
        for (var j = i * 16; j < limit; ++j) {
          widj += [
            ElevatedButton(
              onPressed: (){},
              style: Styles.buttonSimpleStyle(),
              child: Text(
                "${cards[j]}\n稀有",
                style: Styles.simpleTextDownStyle(),
              ),
            )
          ];
        }
        wid += [
          Simple.simpleSpace(),
          Wrap(
            alignment: WrapAlignment.center,
            spacing: 15,
            children: widj,
          )
        ];
    }
    return wid;
  }

  @override
  Widget build(BuildContext context, WidgetRef ref) {
    var cards = CardStore.sanGuo1().get();
    return Scaffold(
      appBar: Simple.simpleBar(
        title: '三国卡牌1',
        back: Simple.backButton(
            context: context, route: '/ownpage/thingpage/mainpage/cardpage'),
      ),
      body: Center(
        child: Column(
          children: [
            const SizedBox(height: 120),
            Simple.nullSpace(),
            ...buildCards(cards),
          ],
        ),
      ),
    );
  }
}
