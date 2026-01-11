// file: test/util/once_file_basic_test.dart
import 'dart:io';
import 'package:test/test.dart';
import 'package:study_platform/tool/once_file.dart';

void main() {
  group('OnceFile 基础功能测试', () {
    final testDir = Directory('test_temp');
    final testFile = '${testDir.path}/test_once.txt';

    setUpAll(() {
      if (testDir.existsSync()) {
        testDir.deleteSync(recursive: true);
      }
      testDir.createSync();
    });

    tearDownAll(() {
      if (testDir.existsSync()) {
        testDir.deleteSync(recursive: true);
      }
    });

    setUp(() {
      // 每次测试前清理文件
      if (File(testFile).existsSync()) {
        File(testFile).deleteSync();
      }
    });

    test('文件不存在时 canExecute 应为 true', () {
      final onceFile = OnceFile(testFile);
      expect(onceFile.canExecute, true);
    });

    test('use() 方法应创建文件', () {
      final onceFile = OnceFile(testFile);

      expect(onceFile.canExecute, true);

      final created = onceFile.use();
      expect(created, true);
      expect(File(testFile).existsSync(), true);
      expect(onceFile.canExecute, false);
    });

    test('重复 use() 应返回 false', () {
      final onceFile = OnceFile(testFile);

      // 第一次创建
      expect(onceFile.use(), true);
      expect(onceFile.canExecute, false);

      // 第二次不应创建
      expect(onceFile.use(), false);
    });

    test('clear() 方法应删除文件', () {
      final onceFile = OnceFile(testFile);

      onceFile.use();
      expect(File(testFile).existsSync(), true);

      final deleted = onceFile.clear();
      expect(deleted, true);
      expect(File(testFile).existsSync(), false);
      expect(onceFile.canExecute, true);
    });

    test('readContent() 应返回写入的内容', () {
      final customContent = '自定义内容 ${DateTime.now()}';
      final onceFile = OnceFile(testFile, content: customContent);

      onceFile.use();
      final content = onceFile.readContent();

      expect(content, isNotNull);
      expect(content, contains(customContent.substring(0, 10))); // 部分匹配
    });

    test('executionTime 应在文件存在时返回时间', () {
      final onceFile = OnceFile(testFile);

      onceFile.use();
      final time = onceFile.executionTime;

      expect(time, isNotNull);
      expect(time!.isBefore(DateTime.now().add(Duration(seconds: 1))), true);
    });

    test('forceUpdate() 应覆盖已有文件', () {
      final onceFile = OnceFile(testFile, content: '初始内容');

      onceFile.use();
      expect(onceFile.readContent(), contains('初始内容'));

      // 强制更新
      onceFile.forceUpdate(newContent: '新内容');
      expect(onceFile.readContent(), '新内容');
    });
  });

  group('JsonOnceFile 基本测试', () {
    final testDir = Directory('test_temp_json');
    final testFile = '${testDir.path}/test_json.json';

    setUpAll(() {
      if (testDir.existsSync()) {
        testDir.deleteSync(recursive: true);
      }
      testDir.createSync();
    });

    tearDownAll(() {
      if (testDir.existsSync()) {
        testDir.deleteSync(recursive: true);
      }
    });

    setUp(() {
      if (File(testFile).existsSync()) {
        File(testFile).deleteSync();
      }
    });

    test('使用初始数据创建 JsonOnceFile', () {
      final initialData = {'version': '1.0.0'};
      final jsonFile = JsonOnceFile<Map<String, dynamic>>(
        testFile,
        initialData: initialData,
      );

      jsonFile.use();
      final data = jsonFile.readJsonData();

      expect(data, isNotNull);
      expect(data!['version'], '1.0.0');
    });
  });
}
