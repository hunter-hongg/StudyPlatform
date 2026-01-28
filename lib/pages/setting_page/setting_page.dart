import 'package:flutter/material.dart';
import 'package:flutter_riverpod/flutter_riverpod.dart';
import 'package:study_platform/vars/files.dart';
import 'package:study_platform/vars/simple.dart';

class SettingPage extends ConsumerWidget {
  const SettingPage({super.key});

  @override
  Widget build(BuildContext context, WidgetRef ref) {
    return Scaffold(
      appBar: Simple.simpleBar(
        title: '设置页面',
        back: Simple.backButton(context: context, route: '/'),
      ),
      body: Center(
        child: Column(
          children: [
            const SizedBox(height: 140),
            Simple.nullSpace(),
            Wrap(
              alignment: WrapAlignment.center,
              children: [
                ...Simple.simpleCheck(
                  show: "启用工具页面",
                  def: Setting.enableUtil().readStateSync(true),
                  func: (state) {
                    if (state == null) {
                      return;
                    }
                    Setting.enableUtil().setState(state);
                    Navigator.pushNamed(context, '/settingpage');
                  },
                ),
              ],
            )
          ],
        ),
      ),
    );
  }
}
