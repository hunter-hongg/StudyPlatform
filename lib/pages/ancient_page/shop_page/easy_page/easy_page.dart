import 'package:flutter/material.dart';
import 'package:study_platform/vars/simple.dart';

class AShopEasyPage extends StatefulWidget {
  const AShopEasyPage({super.key});

  @override
  State<AShopEasyPage> createState() => _AShopEasyPageState();
}

class _AShopEasyPageState extends State<AShopEasyPage> {
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: Simple.simpleBar(
        title: '便利店铺',
        back: Simple.backButton(context: context, route: '/apage/shoppage'),
      ),
      body: Center(
        child: Column(
          children: [
            const SizedBox(height: 140),
            Simple.simpleClick(
              func: () {
                Navigator.pushNamed(
                    context, '/apage/shoppage/easypage/tongpage');
              },
              show: '铜钱店铺',
            ),
            Simple.simpleSpace(),
            Simple.simpleClick(
              func: () {
                Navigator.pushNamed(
                    context, '/apage/shoppage/easypage/baipage');
              },
              show: '白银店铺',
            ),
            Simple.simpleSpace(),
            Simple.simpleClick(
              func: () {
                Navigator.pushNamed(
                    context, '/apage/shoppage/easypage/jinpage');
              },
              show: '黄金店铺',
            ),
          ],
        ),
      ),
    );
  }
}
