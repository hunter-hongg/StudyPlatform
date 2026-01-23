import 'dart:io';
import 'package:flutter/material.dart';
import 'package:study_platform/tool/logger.dart';
import 'package:study_platform/vars/dirs.dart';
import 'package:study_platform/vars/logger.dart';
import 'app.dart';

void main() {
  globalLogger.setLevel(LogLevel.trace);
  globalLogger.info("程序正常启动");
  for (var i = 0; i < Dirs.dirs().length; i++) {
    var d = Directory(Dirs.dirs()[i]);
    d.createSync(recursive: true);
  }
  runApp(const MyApp());
}
