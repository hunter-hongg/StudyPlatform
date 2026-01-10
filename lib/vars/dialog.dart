import 'package:flutter/material.dart';
import 'package:study_platform/vars/styles.dart';

class Dialogs {
  static SimpleDialog dialogAlert(String text) {
    return SimpleDialog(
      title: Center(
        child: Text(
          "警告",
          style: Styles.titleDownStyle(),
        )
      ),
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
}
