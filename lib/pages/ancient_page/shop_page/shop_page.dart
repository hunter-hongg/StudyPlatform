import 'package:flutter/material.dart';
import 'package:study_platform/vars/simple.dart';

class AShopPage extends StatefulWidget {
  const AShopPage({super.key});

  @override
  State<AShopPage> createState() => _AShopPageState();
}

class _AShopPageState extends State<AShopPage> {
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: Simple.simpleBar(
        title: '古代店铺',
        back: Simple.backButton(context: context, route: '/apage'),
      ),
      body: Center(
        child: Column(
          children: [
            const SizedBox(height: 140),
            Simple.simpleClick(
              func: () {
                Navigator.pushNamed(
                    context, '/apage/shoppage/simplepage');
              },
              show: '普通店铺',
            ),
            Simple.simpleSpace(),
            Simple.simpleClick(
              func: () {
                Navigator.pushNamed(
                    context, '/apage/shoppage/easypage');
              },
              show: '便利店铺',
            ),
          ],
        ),
      ),
    );
  }
}
