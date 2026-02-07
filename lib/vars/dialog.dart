import 'package:flutter/material.dart';
import 'package:study_platform/vars/styles.dart';

class Dialogs {
  static SimpleDialog dialogAlert(String text) {
    return SimpleDialog(
      title: Center(
          child: Text(
        "警告",
        style: Styles.titleDownStyle(),
      )),
      children: [
        Center(
          child: Text(
            text,
            style: Styles.simpleTextStyle(),
          ),
        ),
      ],
    );
  }

  static SimpleDialog dialogInfo(String text) {
    return SimpleDialog(
      title: Center(
          child: Text(
        "信息",
        style: Styles.titleDownStyle(),
      )),
      children: [
        Center(
          child: Text(
            text,
            style: Styles.simpleTextStyle(),
          ),
        ),
      ],
    );
  }

  static void dialogShow(SimpleDialog x, BuildContext context) {
    showDialog(
      context: context,
      builder: (context) => x,
    );
  }

  static Future<bool> dialogConfirm(
    BuildContext context,
    String show,
  ) async {
    return await showDialog<bool>(
          context: context,
          builder: (BuildContext context) {
            return AlertDialog(
              title: Text(
                "确认",
                style: Styles.titleDownStyle(),
              ),
              content: Text(
                show,
                style: Styles.simpleTextStyle(),
              ),
              actions: <Widget>[
                TextButton(
                  child: Text(
                    '取消',
                    style: Styles.simpleTextDownStyle(),
                  ),
                  onPressed: () {
                    Navigator.of(context).pop(false); // 返回 false
                  },
                ),
                TextButton(
                  child: Text(
                    '确定',
                    style: Styles.simpleTextDownStyle(),
                  ),
                  onPressed: () {
                    Navigator.of(context).pop(true); // 返回 true
                  },
                ),
              ],
            );
          },
        ) ??
        false; // 防止返回 null
  }
}
