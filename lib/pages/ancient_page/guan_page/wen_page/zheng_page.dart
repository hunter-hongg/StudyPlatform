import 'package:flutter/material.dart';
import 'package:flutter_riverpod/flutter_riverpod.dart';
import 'package:study_platform/logic/awenguanzheng.dart';
import 'package:study_platform/logic/trade.dart';
import 'package:study_platform/tool/random.dart';
import 'package:study_platform/vars/dialog.dart';
import 'package:study_platform/vars/files.dart';
import 'package:study_platform/vars/simple.dart';

var _huiLoading = StateProvider<bool>((ref) => false);
var _zhenLoading = StateProvider<bool>((ref) => false);

class AGWenZhengPage extends ConsumerStatefulWidget {
  const AGWenZhengPage({super.key});

  @override
  ConsumerState<AGWenZhengPage> createState() => _AGWenZhengPageState();
}

class _AGWenZhengPageState extends ConsumerState<AGWenZhengPage> {
  int zhengji = 0;

  void update() {
    zhengji = Files.aWenZhengjReader().readIntSafeSync();
  }

  @override
  Widget build(BuildContext context) {
    update();
    return Scaffold(
      appBar: Simple.simpleBar(
        title: '我的政绩',
        back:
            Simple.backButton(context: context, route: '/apage/gpage/wenpage'),
      ),
      body: Center(
        child: Column(
          children: [
            const SizedBox(height: 5),
            Simple.simpleShowText(
              show: "政绩: $zhengji",
            ),
            const SizedBox(height: 110),
            Simple.simpleClick(
              func: () {
                Trade.tradeCheck(
                  context,
                  Files.aWenZhengjReader(),
                  CheckFiles.aWenZhengShCheck(),
                  25,
                  customMessage: "面圣成功\n政绩+25",
                );
                setState(() {
                  update();
                });
              },
              show: '进京面圣',
            ),
            Simple.simpleSpace(),
            Simple.simpleButtonAsync(
              func: () async {
                final need = RandomGet.getIntClose(3, 6);
                final result = await Dialogs.dialogConfirm(
                  context,
                  "是否用$need块绿玉贿赂权贵?",
                );
                if (result) {
                  WidgetsBinding.instance.addPostFrameCallback((_) {
                    if (mounted) {
                      Trade.tradeF(
                        context,
                        AddFiles.aLvYuReader(),
                        Files.aWenZhengjReader(),
                        "绿玉",
                        need,
                        40,
                        customMessage: "贿赂成功\n政绩+40",
                      );
                      setState(() {
                        update();
                      });
                    }
                  });
                }
              },
              show: '贿赂权贵',
              loading: _huiLoading,
              ref: ref,
            ),
            Simple.simpleSpace(),
            Simple.simpleButtonAsync(
              func: () async {
                final result = await Dialogs.dialogConfirm(
                  context,
                  "是否用100两白银赈济灾民?",
                );
                if (result) {
                  WidgetsBinding.instance.addPostFrameCallback((_) {
                    if (mounted) {
                      Trade.tradeFMinusCheck(
                        context,
                        Files.aBaiYinReader(),
                        Files.aWenZhengjReader(),
                        CheckFiles.aWenZhengJiCheck(),
                        100,
                        20,
                        "白银",
                        customMessage: "赈济成功\n政绩+20",
                      );
                      setState(() {
                        update();
                      });
                    }
                  });
                }
              },
              show: '赈济灾民',
              loading: _zhenLoading,
              ref: ref,
            ),
            Simple.simpleSpace(),
            Simple.simpleClick(
              func: () {
                final currentLevel = Special.aWenGuanConfig().readLevel();
                final need = AWenGuanZheng.getneed(currentLevel);
                Trade.tradeFFunc(
                  context,
                  Files.aWenZhengjReader(),
                  "政绩",
                  need,
                  () {
                    Special.aWenGuanConfig().levelUp();
                    Simple.simpleInfo(
                      context: context,
                      show: "升官成功",
                    );
                  },
                );
                setState(() {
                  update();
                });
              },
              show: '官升一级',
            ),
          ],
        ),
      ),
    );
  }
}
