import 'dart:io';
import 'package:test/test.dart';
import 'package:study_platform/tool/statefile.dart';

void main() {
  group('StateFile 测试', () {
    const testFilePath = 'test_state_file.txt';
    late StateFile stateFile;

    // 每个测试前清理文件
    setUp(() async {
      final file = File(testFilePath);
      if (await file.exists()) {
        await file.delete();
      }
      stateFile = StateFile(testFilePath);
    });

    // 测试后清理文件
    tearDown(() async {
      final file = File(testFilePath);
      if (await file.exists()) {
        await file.delete();
      }
    });

    test('设置 true 状态并异步读取', () async {
      // 设置状态为 true
      await stateFile.setState(true);

      // 异步读取验证
      final state = await stateFile.readState(false);
      expect(state, isTrue);

      // 验证文件内容
      final content = await File(testFilePath).readAsString();
      expect(content.trim(), 'True');
    });

    test('设置 false 状态并异步读取', () async {
      // 设置状态为 false
      await stateFile.setState(false);

      // 异步读取验证
      final state = await stateFile.readState(true);
      expect(state, isFalse);

      // 验证文件内容
      final content = await File(testFilePath).readAsString();
      expect(content.trim(), 'False');
    });

    test('设置 true 状态并同步读取', () async {
      // 设置状态为 true
      await stateFile.setState(true);

      // 同步读取验证
      final state = stateFile.readStateSync(false);
      expect(state, isTrue);
    });

    test('设置 false 状态并同步读取', () async {
      // 设置状态为 false
      await stateFile.setState(false);

      // 同步读取验证
      final state = stateFile.readStateSync(true);
      expect(state, isFalse);
    });

    test('文件不存在时返回默认值（异步）', () async {
      // 文件不存在，应该返回默认值 true
      final state = await stateFile.readState(true);
      expect(state, isTrue);

      // 文件不存在，应该返回默认值 false
      final state2 = await stateFile.readState(false);
      expect(state2, isFalse);
    });

    test('文件不存在时返回默认值（同步）', () {
      // 文件不存在，应该返回默认值 true
      final state = stateFile.readStateSync(true);
      expect(state, isTrue);

      // 文件不存在，应该返回默认值 false
      final state2 = stateFile.readStateSync(false);
      expect(state2, isFalse);
    });

    test('空文件时返回默认值（异步）', () async {
      // 创建空文件
      await File(testFilePath).writeAsString('');

      // 应该返回默认值 true
      final state = await stateFile.readState(true);
      expect(state, isTrue);
    });

    test('空文件时返回默认值（同步）', () {
      // 创建空文件
      File(testFilePath).writeAsStringSync('');

      // 应该返回默认值 false
      final state = stateFile.readStateSync(false);
      expect(state, isFalse);
    });

    test('空白字符文件解析（异步）', () async {
      // 创建带空白字符的文件
      await File(testFilePath).writeAsString('  True  \n\n');

      // 应该正确解析为 true
      final state = await stateFile.readState(false);
      expect(state, isTrue);
    });

    test('空白字符文件解析（同步）', () {
      // 创建带空白字符的文件
      File(testFilePath).writeAsStringSync('  False  \t\n');

      // 应该正确解析为 false
      final state = stateFile.readStateSync(true);
      expect(state, isFalse);
    });

    test('无效内容返回默认值（异步）', () async {
      // 创建无效内容文件
      await File(testFilePath).writeAsString('InvalidContent');

      // 应该返回默认值
      final state = await stateFile.readState(true);
      expect(state, isTrue);
    });

    test('无效内容返回默认值（同步）', () {
      // 创建无效内容文件
      File(testFilePath).writeAsStringSync('SomeRandomText');

      // 应该返回默认值
      final state = stateFile.readStateSync(false);
      expect(state, isFalse);
    });

    test('状态覆盖写入', () async {
      // 先写入 false
      await stateFile.setState(false);
      var state = await stateFile.readState(true);
      expect(state, isFalse);

      // 覆盖写入 true
      await stateFile.setState(true);
      state = await stateFile.readState(false);
      expect(state, isTrue);

      // 验证文件内容
      final content = await File(testFilePath).readAsString();
      expect(content.trim(), 'True');
    });

    test('大写敏感测试', () async {
      // 测试大小写敏感：应该只有 'True' 才为 true
      await File(testFilePath).writeAsString('true'); // 小写
      final state = await stateFile.readState(false);
      expect(state, isFalse);

      await File(testFilePath).writeAsString('TRUE'); // 大写
      final state2 = await stateFile.readState(true);
      expect(state2, isTrue); // 只有 'True' 才为 true
    });

    test('文件权限错误时应抛出异常', () async {
      // 在 Unix-like 系统上测试只读文件
      if (Platform.isLinux || Platform.isMacOS) {
        // 创建文件
        await stateFile.setState(true);

        // 设置为只读
        await Process.run('chmod', ['444', testFilePath]);

        // 尝试写入应该抛出异常
        try {
          await stateFile.setState(false);
          fail('应该抛出 StateException');
        } on StateException catch (e) {
          expect(e.toString(), contains('Failed to write state file'));
        } finally {
          // 恢复权限以便清理
          await Process.run('chmod', ['644', testFilePath]);
        }
      }
    });

    test('并发操作测试', () async {
      // 模拟并发操作
      final futures = <Future>[];

      for (var i = 0; i < 10; i++) {
        futures.add(stateFile.setState(i.isEven));
      }

      await Future.wait(futures);

      // 最终状态应该是最后一次写入的值
      final state = await stateFile.readState(true);
      expect(state, isFalse); // 最后一次是 i=9，所以是 false
    });
  });
}
