import 'package:flutter/material.dart';
import 'package:study_platform/logic/asword.dart';
import 'package:study_platform/logic/apao.dart';
import 'package:study_platform/logic/trade.dart';
import 'package:study_platform/tool/addfile.dart';
import 'package:study_platform/tool/random.dart';
import 'package:study_platform/vars/files.dart';
import 'package:study_platform/vars/simple.dart';

class AShopSimplePage extends StatefulWidget {
  const AShopSimplePage({super.key});

  @override
  State<AShopSimplePage> createState() => _AShopSimplePageState();
}

class _AShopSimplePageState extends State<AShopSimplePage> {
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: Simple.simpleBar(
        title: '普通店铺',
        back: Simple.backButton(context: context, route: '/apage/shoppage'),
      ),
      body: Center(
        child: Column(
          children: [
            const SizedBox(height: 140),
            Simple.nullSpace(),
            Simple.simpleRow(
              widgets: [
                Simple.simpleClick(
                  func: () {
                    Trade.tradeFunc(
                      context,
                      Files.aHuangJinReader(),
                      "黄金",
                      100,
                      () {
                        int rres = RandomGet.getIntClose(0, 6);
                        Sword sword = Sword.values[rres];
                        Special.aSword().add(sword);
                        Simple.simpleInfo(
                          context: context,
                          show: "恭喜获得${sword.toString()}",
                        );
                      },
                    );
                  },
                  show: "100黄金\n1佩剑",
                ),
                Simple.simpleClick(
                  func: () {
                    Trade.tradeFunc(
                      context,
                      Files.aHuangJinReader(),
                      "黄金",
                      300,
                      () {
                        int rres = RandomGet.getIntClose(0, 7);
                        Pao pao = Pao.values[rres];
                        Special.aPao().add(pao);
                        Simple.simpleInfo(
                          context: context,
                          show: "恭喜获得${pao.toString()}",
                        );
                      },
                    );
                  },
                  show: "300黄金\n1锦袍",
                ),
                Simple.simpleClick(
                  func: () {
                    Trade.tradeAdd(
                      context,
                      Files.aBaiYinReader(),
                      AddFiles.aBook1(),
                      "白银",
                      50,
                      5,
                    );
                  },
                  show: '50白银\n5普通书籍',
                )
              ],
            ),
            Simple.simpleSpace(),
            Simple.simpleRow(widgets: [
              Simple.simpleClick(
                func: () {
                  Trade.tradeAdd(
                    context,
                    Files.aBaiYinReader(),
                    AddFiles.aBook2(),
                    "白银",
                    75,
                    3,
                  );
                },
                show: '75白银\n3珍稀书籍',
              ),
              Simple.simpleClick(
                func: () {
                  Trade.tradeAdd(
                    context,
                    Files.aBaiYinReader(),
                    AddFiles.aBook3(),
                    "白银",
                    100,
                    2,
                  );
                },
                show: '100白银\n2典藏书籍',
              ),
            ])
          ],
        ),
      ),
    );
  }
}
