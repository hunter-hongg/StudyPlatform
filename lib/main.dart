import 'package:flutter/material.dart';
import 'package:study_platform/tool/logger.dart';
import 'package:study_platform/vars/logger.dart';
import 'app.dart';

void main() {
  globalLogger.setLevel(LogLevel.trace);
  globalLogger.info("程序正常启动");
  runApp(const MyApp());
}
