import 'package:flutter/material.dart';
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
}
