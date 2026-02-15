import 'package:flutter/material.dart';
import 'package:study_platform/logic/trade.dart';
import 'package:study_platform/vars/dialog.dart';
import 'package:study_platform/vars/files.dart';
import 'package:study_platform/vars/simple.dart';

class XianThingJiPage extends StatefulWidget {
  const XianThingJiPage({super.key});

  @override
  State<XianThingJiPage> createState() => _XianThingJiPageState();
}

class _XianThingJiPageState extends State<XianThingJiPage> {
  int ji = 0;

  void update() {
    ji = Files.xJiReader().readIntSafeSync();
  }

  @override
  Widget build(BuildContext context) {
    update();
    return Scaffold(
      appBar: Simple.simpleBar(
        title: '我的仙籍',
        back: Simple.backButton(context: context, route: '/xianpage/thingpage'),
      ),
      body: Center(
        child: Column(
          children: [
            const SizedBox(height: 5),
            Simple.simpleShowText(show: "仙籍: $ji"),
            const SizedBox(height: 120),
            Simple.simpleClick(
              func: () {
                Dialogs.dialogConfirm(context, '是否用5仙币兑换20仙籍？').then(
                  (val) {
                    if (val) {
                      WidgetsBinding.instance.addPostFrameCallback((_) {
                        if (mounted) {
                          Trade.tradeF(
                            context,
                            Files.xianBiReader(),
                            Files.xJiReader(),
                            '仙币',
                            5,
                            20,
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
              show: '购买仙籍',
            ),
            Simple.simpleSpace(),
            Simple.simpleClick(
              func: () {
                Dialogs.dialogConfirm(context, '是否用10仙籍增强100法力？').then(
                  (val) {
                    if (val) {
                      WidgetsBinding.instance.addPostFrameCallback((_) {
                        if (mounted) {
                          Trade.tradeF(
                            context,
                            Files.xJiReader(),
                            Files.xFaLiReader(),
                            '仙籍',
                            10,
                            100,
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
                Dialogs.dialogConfirm(context, '是否用10仙籍增强90仙器法力？').then(
                  (val) {
                    if (val) {
                      WidgetsBinding.instance.addPostFrameCallback((_) {
                        if (mounted) {
                          Trade.tradeF(
                            context,
                            Files.xJiReader(),
                            Files.xQiFaLiReader(),
                            '仙籍',
                            10,
                            90,
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
              show: '增强仙器',
            ),
          ],
        ),
      ),
    );
  }
}
