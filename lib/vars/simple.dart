import 'package:flutter/material.dart';
import 'package:study_platform/vars/dialog.dart';
import 'package:study_platform/vars/styles.dart';

class Simple {
  static Widget simpleClick(
      {required void Function() func, required String show}) {
    return ElevatedButton(
      onPressed: func,
      style: Styles.buttonSimpleStyle(),
      child: Text(
        show,
        style: Styles.simpleTextStyle(),
      ),
    );
  }

  static Widget backButton(
      {required BuildContext context, required String route}) {
    return IconButton(
      onPressed: () {
        Navigator.pushNamed(context, route);
      },
      icon: Icon(Icons.arrow_back),
    );
  }

  static Widget simpleSpace() {
    return SizedBox(
      height: 20,
    );
  }

  static Widget nullSpace() {
    return Center(
        child: Row(
      spacing: 20,
    ));
  }

  static AppBar simpleBar({required String title, Widget? back}) {
    return AppBar(
      title: Text(title),
      centerTitle: true,
      titleTextStyle: Styles.titleStyle(),
      automaticallyImplyLeading: false,
      leading: back,
    );
  }

  static void simpleWarn(
      {required BuildContext context, required String show}) {
    Dialogs.dialogShow(Dialogs.dialogAlert(show), context);
  }

  static void simpleInfo(
      {required BuildContext context, required String show}) {
    Dialogs.dialogShow(Dialogs.dialogInfo(show), context);
  }

  static Widget simpleInput(
      {required TextEditingController controller,
      required String label,
      required String hint}) {
    return FractionallySizedBox(
      widthFactor: 0.3,
      child: TextField(
        controller: controller,
        decoration: InputDecoration(
          labelText: label,
          hintText: hint,
          border: OutlineInputBorder(),
        ),
      ),
    );
  }

  static Widget simpleText({required String show}) {
    return Text(
      show,
      style: Styles.simpleTextStyle(),
    );
  }

  static Widget simpleShowText({required String show}) {
    return Text(
      show,
      style: Styles.showstrStyle(),
    );
  }
}
