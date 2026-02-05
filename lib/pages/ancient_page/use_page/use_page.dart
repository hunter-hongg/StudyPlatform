import 'package:flutter/material.dart';
import 'package:study_platform/vars/simple.dart';

class AUsePage extends StatefulWidget {
  const AUsePage({super.key});

  @override
  State<AUsePage> createState() => _AUsePageState();
}

class _AUsePageState extends State<AUsePage> {
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: Simple.simpleBar(
        title: '物品使用',
        back: Simple.backButton(context: context, route: '/apage'),
      ),
      body: Center(
        child: Column(
          children: [
            const SizedBox(height: 135),
            Simple.simpleClick(
              func: () {
                Navigator.pushNamed(context, '/apage/usepage/baopage');
              },
              show: '宝物卖出',
            ),
            Simple.simpleSpace(),
            Simple.simpleClick(
              func: () {
                Navigator.pushNamed(context, '/apage/usepage/bookspage');
              },
              show: '叫卖书籍',
            ),
            Simple.simpleSpace(),
            Simple.simpleClick(
              func: () {
                Navigator.pushNamed(context, '/apage/usepage/bookcpage');
              },
              show: '抄录新书',
            ),
          ],
        ),
      ),
    );
  }
}
