import 'package:flutter/material.dart';
import 'package:logging/logging.dart';
import 'package:study_platform/vars/logger.dart';
import 'app.dart';

void main() {
  Logger.root.level = Level.ALL; // 设置日志级别
  Logger.root.onRecord.listen((record) {
    print('${record.level.name}: ${record.time}: ${record.message}');
  });
  globalLogger = Logger('Logger');
  runApp(const MyApp());
}