import 'package:flutter/material.dart';
import 'package:study_platform/vars/simple.dart';

class AGPage extends StatefulWidget {
  const AGPage({super.key});

  @override
  State<AGPage> createState() => _AGPageState();
}

class _AGPageState extends State<AGPage> {
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: Simple.simpleBar(
        title: '我的官职',
        back: Simple.backButton(context: context, route: '/apage'),
      ),
      body: Center(
        child: Column(
          children: [
            const SizedBox(height: 160),
            Simple.simpleClick(
              func: () {
                Navigator.pushNamed(context, '/apage/gpage/wenpage');
              },
              show: '作为文官',
            ),
            Simple.simpleSpace(),
            Simple.simpleClick(
              func: () {
                Navigator.pushNamed(context, '/apage/gpage/wupage');
              },
              show: '作为武官',
            ),
          ],
        ),
      ),
    );
  }
}
