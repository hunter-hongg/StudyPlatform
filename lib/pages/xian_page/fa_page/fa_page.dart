import 'package:flutter/material.dart';
import 'package:study_platform/logic/trade.dart';
import 'package:study_platform/vars/dialog.dart';
import 'package:study_platform/vars/files.dart';
import 'package:study_platform/vars/simple.dart';
import 'package:study_platform/vars/styles.dart';

class XianFaPage extends StatefulWidget {
  const XianFaPage({super.key});

  @override
  State<XianFaPage> createState() => _XianFaPageState();
}

class _XianFaPageState extends State<XianFaPage> {
  var fali = 0;

  void update() {
    fali = Files.xFaLiReader().readIntSafeSync();
  }

  @override
  Widget build(BuildContext context) {
    update();
    return Scaffold(
      appBar: Simple.simpleBar(
        title: '我的法力',
        back: Simple.backButton(context: context, route: '/xianpage'),
      ),
      body: Center(
        child: Column(
          children: [
            const SizedBox(height: 5),
            Text('法力值: $fali', style: Styles.showstrStyle()),
            const SizedBox(height: 140),
            Simple.simpleClick(
              func: () {
                /* 10 -> 70 */
                Dialogs.dialogConfirm(context, "是否用10仙币增强70法力?").then(
                  (value) {
                    if (value) {
                      WidgetsBinding.instance.addPostFrameCallback((_) {
                        if (mounted) {
                          Trade.tradeF(
                            context,
                            Files.xianBiReader(),
                            Files.xFaLiReader(),
                            '仙币',
                            10,
                            70,
                            customMessage: "增强成功",
                          );
                          setState(() {
                            update();
                          });
                        }
                      });
                    }
                  },
                );
              },
              show: '增强法力',
            ),
            Simple.simpleSpace(),
            Simple.simpleClick(
              func: () {
                Navigator.pushNamed(context, '/xianpage/fapage');
              },
              show: '我的法力',
            ),
          ],
        ),
      ),
    );
  }
}
