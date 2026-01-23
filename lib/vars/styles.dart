import 'package:flutter/material.dart';

class Styles {
  static TextStyle titleStyle() {
    return TextStyle(
      fontSize: 35,
      fontWeight: FontWeight.bold,
      color: Colors.black,
    );
  }

  static TextStyle titleDownStyle() {
    return TextStyle(
      fontSize: 32,
      fontWeight: FontWeight.bold,
      color: Colors.black,
    );
  }

  static TextStyle showstrStyle() {
    return TextStyle(
      fontSize: 22,
      fontWeight: FontWeight.normal,
      color: Colors.blue,
    );
  }

  static TextStyle simpleTextStyle() {
    return TextStyle(
      fontSize: 25,
      fontWeight: FontWeight.normal,
      color: Colors.black,
    );
  }

  static TextStyle simpleTextUpStyle() {
    return TextStyle(
      fontSize: 28,
      fontWeight: FontWeight.normal,
      color: Colors.black,
    );
  }

  static TextStyle simpleTextDownStyle() {
    return TextStyle(
      fontSize: 20,
      fontWeight: FontWeight.normal,
      color: Colors.black,
    );
  }

  static ButtonStyle buttonSimpleStyle() {
    return ElevatedButton.styleFrom(
      foregroundColor: Colors.black,
      backgroundColor: Colors.white,
      elevation: 5,
      padding: EdgeInsets.symmetric(horizontal: 12, vertical: 15),
      textStyle: simpleTextStyle(),
      shape: BeveledRectangleBorder(),
    );
  }
}
