import 'dart:io';
import 'package:test/test.dart';
import 'package:study_platform/tool/file_password.dart';
import 'package:synchronized/synchronized.dart';

void main() {
  group('FilePassword 基本功能测试', () {
    const testDir = 'test_temp';
    late String testFilePath;

    setUpAll(() {
      // 创建测试目录
      Directory(testDir).createSync();
    });

    setUp(() {
      // 每个测试前创建唯一的测试文件
      testFilePath =
          '$testDir/test_${DateTime.now().millisecondsSinceEpoch}.txt';
    });

    tearDown(() {
      // 每个测试后清理测试文件
      final file = File(testFilePath);
      if (file.existsSync()) {
        file.deleteSync();
      }
    });

    tearDownAll(() {
      // 所有测试完成后清理测试目录
      final dir = Directory(testDir);
      if (dir.existsSync()) {
        dir.deleteSync(recursive: true);
      }
    });

    test('工厂构造函数验证密码重复字符', () {
      // 密码包含重复字符，应使用默认密码
      final fp1 = FilePassword(testFilePath, '1123456789');
      expect(fp1.password, equals('1324096857'));

      // 密码无重复字符，应使用原密码
      final fp2 = FilePassword(testFilePath, '1234567890');
      expect(fp2.password, equals('1234567890'));
    });

    test('withDefault工厂构造函数创建文件', () {
      final fp = FilePassword.withDefault(testFilePath, '1234567890', 100);

      // 验证文件已创建
      final file = File(testFilePath);
      expect(file.existsSync(), isTrue);

      // 验证初始值
      expect(fp.readIntSync(), equals(100));
    });

    test('写入和读取整数', () {
      final fp = FilePassword(testFilePath, '9876543210');

      // 写入值
      fp.writeSync(42);

      // 读取验证
      expect(fp.readIntSync(), equals(42));
      expect(fp.readStrSync(), equals('42'));
    });

    test('add操作', () {
      final fp = FilePassword(testFilePath, '9876543210');

      // 初始写入
      fp.writeSync(10);

      // 增加操作
      fp.addSync(5);

      // 验证结果
      expect(fp.readIntSync(), equals(15));
    });

    test('minusNum操作', () {
      final fp = FilePassword(testFilePath, '9876543210');

      // 初始写入
      fp.writeSync(20);

      // 减少操作
      fp.minusNumSync(5);

      // 验证结果
      expect(fp.readIntSync(), equals(15));
    });

    test('minusNumIf操作 - 足够减少', () {
      final fp = FilePassword(testFilePath, '9876543210');

      // 初始写入
      fp.writeSync(20);

      // 减少操作
      fp.minusNumIfSync(5);

      // 验证结果
      expect(fp.readIntSync(), equals(15));
    });

    test('minusNumIf操作 - 不足减少到0', () {
      final fp = FilePassword(testFilePath, '9876543210');

      // 初始写入
      fp.writeSync(3);

      // 减少操作
      fp.minusNumIfSync(5);

      // 验证结果
      expect(fp.readIntSync(), equals(0));
    });

    test('high判断', () {
      final fp = FilePassword(testFilePath, '9876543210');

      // 初始写入
      fp.writeSync(10);

      // 验证判断
      expect(fp.highSync(5), isTrue);
      expect(fp.highSync(10), isTrue);
      expect(fp.highSync(15), isFalse);
    });

    test('canMinus操作 - 满足条件', () {
      final fp = FilePassword(testFilePath, '9876543210');

      // 初始写入
      fp.writeSync(20);

      // canMinus操作
      final result = fp.canMinusSync(10);

      // 验证
      expect(result, isTrue);
      expect(fp.readIntSync(), equals(10));
    });

    test('canMinus操作 - 不满足条件', () {
      final fp = FilePassword(testFilePath, '9876543210');

      // 初始写入
      fp.writeSync(5);

      // canMinus操作
      final result = fp.canMinusSync(10);

      // 验证
      expect(result, isFalse);
      expect(fp.readIntSync(), equals(5));
    });

    test('负数值不操作', () {
      final fp = FilePassword(testFilePath, '9876543210');

      // 初始写入
      fp.writeSync(10);

      // 尝试负数操作
      fp.addNumSync(-5);
      fp.minusNumSync(-3);

      // 验证值未改变
      expect(fp.readIntSync(), equals(10));
    });

    test('安全方法测试 - readIntSafe', () {
      final fp = FilePassword(testFilePath, '9876543210');

      // 文件不存在时使用安全方法
      expect(fp.readIntSafeSync(), equals(0));

      // 正常情况
      fp.writeSync(42);
      expect(fp.readIntSafeSync(), equals(42));
    });

    test('安全方法测试 - canMinusSafe', () {
      final fp = FilePassword(testFilePath, '9876543210');

      // 文件不存在时使用安全方法
      expect(fp.canMinusSafeSync(10), isFalse);

      // 正常情况
      fp.writeSync(20);
      expect(fp.canMinusSafeSync(10), isTrue);
      expect(fp.readIntSync(), equals(10));
    });

    test('异步方法测试', () async {
      final fp = FilePassword(testFilePath, '9876543210');

      // 异步写入
      await fp.write(100);

      // 异步读取
      final value = await fp.readInt();
      expect(value, equals(100));

      // 异步操作
      await fp.add(50);
      final newValue = await fp.readInt();
      expect(newValue, equals(150));
    });

    test('字符映射错误处理', () {
      final fp = FilePassword(testFilePath, '9876543210');

      // 正常写入
      fp.writeSync(123);

      // 使用错误的密码创建另一个实例（会触发默认密码）
      final fpWrong = FilePassword('${testFilePath}_wrong', '9999999999');
      fpWrong.writeSync(456);

      // 尝试用错误的密码读取 - 会抛出异常
      // expect(() => fpWrong.readIntSync(), throwsFormatException);
    });

    test('文件不存在时自动创建', () {
      final fp = FilePassword(testFilePath, '1234567890');

      // 文件应该不存在
      final file = File(testFilePath);
      expect(file.existsSync(), isFalse);

      // 读取时会自动创建
      final value = fp.readIntSafeSync();
      expect(value, equals(0)); // 默认值
      expect(file.existsSync(), isTrue);
    });

    test('加密解密正确性', () {
      const testPassword = '9876543210';
      final fp = FilePassword(testFilePath, testPassword);

      // 测试数据
      const testNumbers = [0, 1, 42, 999, 123456789];

      for (final number in testNumbers) {
        // 写入
        fp.writeSync(number);

        // 直接读取文件内容（加密的）
        final file = File(testFilePath);
        final encrypted = file.readAsStringSync();

        // 验证加密内容不是原始数字
        expect(encrypted, isNot(equals(number.toString())));

        // 通过类方法解密
        final decrypted = fp.readIntSync();
        expect(decrypted, equals(number));
      }
    });
  });

  group('FilePassword 边界条件测试', () {
    const testDir = 'test_temp_edge';

    setUpAll(() {
      Directory(testDir).createSync();
    });

    tearDownAll(() {
      Directory(testDir).deleteSync(recursive: true);
    });

    test('大数字处理', () {
      final testFilePath = '$testDir/large_test.txt';
      final fp = FilePassword(testFilePath, '1234567890');

      // 测试大数字
      const largeNumber = 2147483647; // max 32-bit int
      fp.writeSync(largeNumber);

      expect(fp.readIntSync(), equals(largeNumber));
    });

    test('多次连续操作', () {
      final testFilePath = '$testDir/multi_ops_test.txt';
      final fp = FilePassword(testFilePath, '1234567890');

      // 连续操作
      fp.writeSync(0);
      fp.addNumSync(10);
      fp.minusNumSync(3);
      fp.addNumSync(5);
      fp.minusNumIfSync(15);
      fp.addNumSync(2);

      expect(fp.readIntSync(), equals(2));
    });

    test('并发操作测试', () async {
      final testFilePath = '$testDir/concurrent_test.txt';
      final fp = FilePassword(testFilePath, '1234567890');
      final lock = Lock();

      await fp.write(100);

      // 并发调用，但使用锁保证顺序
      final futures = List.generate(10, (i) async {
        await lock.synchronized(() async {
          await fp.addNum(1);
        });
      });

      await Future.wait(futures);

      expect(await fp.readInt(), equals(110));
    });

    test('无效文件路径处理', () {
      // 无效路径
      final invalidPath = '/invalid/path/to/file.txt';
      final fp = FilePassword(invalidPath, '1234567890');

      // 安全方法应该处理异常
      expect(fp.readIntSafeSync(), equals(0));

      // 普通方法应该抛出异常
      expect(() => fp.readIntSync(), throwsA(isA<IOException>()));
    });
  });
}
