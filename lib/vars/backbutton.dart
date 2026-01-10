import 'package:flutter/material.dart';

class BackButtons {
  static Widget backButton(BuildContext context, String route) {
    return IconButton(
      onPressed: () {
        Navigator.pushNamed(context, route);
      },
      icon: Icon(Icons.arrow_back),
    );
  }
}
