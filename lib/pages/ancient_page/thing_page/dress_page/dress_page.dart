import 'package:flutter/material.dart';
import 'package:study_platform/vars/simple.dart';

class AThingDressPage extends StatefulWidget {
  const AThingDressPage({super.key});

  @override
  State<AThingDressPage> createState() => _AThingDressPageState();
}

class _AThingDressPageState extends State<AThingDressPage> {
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: Simple.simpleBar(
        title: '我的衣着',
        back: Simple.backButton(context: context, route: '/apage/thingpage'),
      ),
      body: Center(
        child: Column(
          children: [
            const SizedBox(height: 140),
            Simple.simpleClick(
              func: () {
                Navigator.pushNamed(
                    context, '/apage/thingpage/dresspage/swordpage');
              },
              show: '我的佩剑',
            ),
            Simple.simpleSpace(),
            Simple.simpleClick(
              func: () {
                Navigator.pushNamed(
                    context, '/apage/thingpage/dresspage/paopage');
              },
              show: '我的锦袍',
            ),
          ],
        ),
      ),
    );
  }
}
