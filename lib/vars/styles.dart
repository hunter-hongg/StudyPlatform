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
  
  static ButtonStyle buttonSimpleStyle() {
   return ElevatedButton.styleFrom(
      foregroundColor: Colors.black,      // 文字/图标色
      backgroundColor: Colors.white,
      elevation: 5,                       // 阴影深度
      padding: EdgeInsets.symmetric(horizontal: 32, vertical: 15),
      textStyle: simpleTextStyle(),
      shape: BeveledRectangleBorder(),
    ); 
  }
}
