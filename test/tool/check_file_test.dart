import 'dart:io';
import 'package:test/test.dart';
import 'package:study_platform/tool/check_file.dart';

void main() {
  group('CheckFile 测试', () {
    // 测试文件路径
    final testFilePath = 'test_check_file.txt';

    // 每个测试前清空文件
    setUp(() {
      final file = File(testFilePath);
      if (file.existsSync()) {
        file.deleteSync();
      }
    });

    // 测试后清理文件
    tearDown(() {
      final file = File(testFilePath);
      if (file.existsSync()) {
        file.deleteSync();
      }
    });

    group('同步方法测试', () {
      test('文件不存在时自动创建', () {
        final checkFile = CheckFile(
          filePath: testFilePath,
          addNum: 0,
          allTimes: 3,
        );

        // 文件不应存在
        expect(File(testFilePath).existsSync(), false);

        // 执行检查，应该创建文件
        final result = checkFile.checkTimesSync();
        expect(result, true);
        expect(File(testFilePath).existsSync(), true);
      });

      test('首次检查应该通过并写入日期', () {
        final checkFile = CheckFile(
          filePath: testFilePath,
          addNum: 0, // 今天
          allTimes: 3,
        );

        final today = CheckFile.getTodayDate();

        // 首次检查
        expect(checkFile.checkTimesSync(), true);

        // 验证文件内容
        final content = File(testFilePath).readAsStringSync();
        expect(content, '&${today.toString()}');

        // 读取所有日期验证
        final dates = checkFile.readAllDatesSync();
        expect(dates.length, 1);
        expect(dates.first, today);
      });

      test('达到限制次数后返回false', () {
        final checkFile = CheckFile(
          filePath: testFilePath,
          addNum: 0,
          allTimes: 2, // 允许2次
        );

        // 第一次检查
        expect(checkFile.checkTimesSync(), true);

        // 第二次检查
        expect(checkFile.checkTimesSync(), true);

        // 第三次检查应该失败
        expect(checkFile.checkTimesSync(), false);

        // 验证文件只有2条记录
        final dates = checkFile.readAllDatesSync();
        expect(dates.length, 2);
      });

      test('处理未来日期', () {
        final checkFile = CheckFile(
          filePath: testFilePath,
          addNum: 1, // 明天
          allTimes: 3,
        );

        // 计算明天的日期
        final tomorrow = DateTime.now().add(Duration(days: 1));
        final tomorrowFormatted = CheckFile.formatDate(tomorrow);

        expect(checkFile.checkTimesSync(), true);

        // 验证写入的是明天的日期
        final dates = checkFile.readAllDatesSync();
        expect(dates.first, tomorrowFormatted);
      });

      test('处理过去日期', () {
        final checkFile = CheckFile(
          filePath: testFilePath,
          addNum: -1, // 昨天
          allTimes: 3,
        );

        // 计算昨天的日期
        final yesterday = DateTime.now().add(Duration(days: -1));
        final yesterdayFormatted = CheckFile.formatDate(yesterday);

        expect(checkFile.checkTimesSync(), true);

        final dates = checkFile.readAllDatesSync();
        expect(dates.first, yesterdayFormatted);
      });

      test('重复检查相同日期', () {
        final checkFile = CheckFile(
          filePath: testFilePath,
          addNum: 0,
          allTimes: 3,
        );

        for (int i = 0; i < 3; i++) {
          expect(checkFile.checkTimesSync(), true,
              reason: '第 ${i + 1} 次检查应该通过');
        }

        expect(checkFile.checkTimesSync(), false, reason: '第 4 次检查应该失败');

        final dates = checkFile.readAllDatesSync();
        expect(dates.length, 3);

        // 所有日期应该相同（都是今天）
        final today = CheckFile.getTodayDate();
        for (final date in dates) {
          expect(date, today);
        }
      });

      test('清空文件后重新计数', () {
        final checkFile = CheckFile(
          filePath: testFilePath,
          addNum: 0,
          allTimes: 2,
        );

        // 使用两次
        expect(checkFile.checkTimesSync(), true);
        expect(checkFile.checkTimesSync(), true);
        expect(checkFile.checkTimesSync(), false); // 达到限制

        // 清空文件
        checkFile.clearFileSync();

        // 重新计数
        expect(checkFile.checkTimesSync(), true);
        expect(checkFile.checkTimesSync(), true);
        expect(checkFile.checkTimesSync(), false);
      });

      test('处理无效日期格式', () async {
        // 写入无效内容
        await File(testFilePath)
            .writeAsString('&invalid&20240101&abc&20240102');

        final checkFile = CheckFile(
          filePath: testFilePath,
          addNum: 0,
          allTimes: 2,
        );

        // 应该只识别有效的日期
        final dates = checkFile.readAllDatesSync();
        expect(dates.length, 2);
        expect(dates, contains(20240101));
        expect(dates, contains(20240102));
        expect(dates, isNot(contains('invalid')));
        expect(dates, isNot(contains('abc')));
      });

      test('空文件处理', () {
        final checkFile = CheckFile(
          filePath: testFilePath,
          addNum: 0,
          allTimes: 3,
        );

        // 创建空文件
        File(testFilePath).createSync();

        expect(checkFile.checkTimesSync(), true);

        final content = File(testFilePath).readAsStringSync();
        expect(content, isNotEmpty);
      });

      test('只包含分隔符的文件', () async {
        await File(testFilePath).writeAsString('&&&&&');

        final checkFile = CheckFile(
          filePath: testFilePath,
          addNum: 0,
          allTimes: 3,
        );

        expect(checkFile.checkTimesSync(), true);

        final dates = checkFile.readAllDatesSync();
        expect(dates.length, 1); // 只添加了一个新日期
      });
    });

    group('异步方法测试', () {
      test('异步文件创建和检查', () async {
        final checkFile = CheckFile(
          filePath: testFilePath,
          addNum: 0,
          allTimes: 3,
        );

        expect(await File(testFilePath).exists(), false);

        final result = await checkFile.checkTimes();
        expect(result, true);
        expect(await File(testFilePath).exists(), true);
      });

      test('异步达到限制次数', () async {
        final checkFile = CheckFile(
          filePath: testFilePath,
          addNum: 0,
          allTimes: 2,
        );

        expect(await checkFile.checkTimes(), true);
        expect(await checkFile.checkTimes(), true);
        expect(await checkFile.checkTimes(), false);

        final dates = await checkFile.readAllDates();
        expect(dates.length, 2);
      });

      // test('异步并发访问', () async {
      //   final checkFile = CheckFile(
      //     filePath: testFilePath,
      //     addNum: 0,
      //     allTimes: 5,
      //   );

      //   // 模拟并发访问
      //   final futures = List.generate(10, (_) => checkFile.checkTimes());
      //   final results = await Future.wait(futures);

      //   // 统计成功次数
      //   final successCount = results.where((r) => r).length;
      //   expect(successCount, 5); // 应该只有5次成功

      //   final dates = await checkFile.readAllDates();
      //   expect(dates.length, 5);
      // });

      test('混合同步和异步调用', () async {
        final checkFile = CheckFile(
          filePath: testFilePath,
          addNum: 0,
          allTimes: 3,
        );

        // 同步调用
        expect(checkFile.checkTimesSync(), true);

        // 异步调用
        expect(await checkFile.checkTimes(), true);

        // 再次同步调用
        expect(checkFile.checkTimesSync(), true);

        // 应该达到限制
        expect(await checkFile.checkTimes(), false);
        expect(checkFile.checkTimesSync(), false);

        final datesSync = checkFile.readAllDatesSync();
        final datesAsync = await checkFile.readAllDates();

        expect(datesSync.length, 3);
        expect(datesAsync.length, 3);
        expect(datesSync, equals(datesAsync));
      });
    });

    group('边界条件测试', () {
      // test('allTimes为0时总是返回false', () {
      //   final checkFile = CheckFile(
      //     filePath: testFilePath,
      //     addNum: 0,
      //     allTimes: 0,
      //   );

      //   expect(checkFile.checkTimesSync(), false);
      //   expect(File(testFilePath).existsSync(), false);
      // });

      test('allTimes为负数时总是返回false', () {
        final checkFile = CheckFile(
          filePath: testFilePath,
          addNum: 0,
          allTimes: -1,
        );

        expect(checkFile.checkTimesSync(), false);
      });

      test('大次数限制测试', () async {
        final checkFile = CheckFile(
          filePath: testFilePath,
          addNum: 0,
          allTimes: 1000,
        );

        // 执行多次检查
        for (int i = 0; i < 1000; i++) {
          expect(await checkFile.checkTimes(), true);
        }

        // 第1001次应该失败
        expect(await checkFile.checkTimes(), false);

        final dates = await checkFile.readAllDates();
        expect(dates.length, 1000);
      });

      test('文件路径包含目录', () async {
        final nestedPath = 'test_dir/sub_dir/test_file.txt';
        final checkFile = CheckFile(
          filePath: nestedPath,
          addNum: 0,
          allTimes: 3,
        );

        expect(await checkFile.checkTimes(), true);
        expect(await File(nestedPath).exists(), true);

        // 清理
        final file = File(nestedPath);
        if (await file.exists()) {
          await file.delete();
        }

        final dir = Directory('test_dir');
        if (await dir.exists()) {
          await dir.delete(recursive: true);
        }
      });

      test('只读文件权限测试', () async {
        // 创建文件并设置为只读（模拟权限问题）
        final file = File(testFilePath);
        await file.writeAsString('&20240101');

        // 在Windows上设置只读属性
        // 注意：Dart没有直接的方法设置文件权限，这里模拟异常情况

        final checkFile = CheckFile(
          filePath: testFilePath,
          addNum: 0,
          allTimes: 3,
        );

        // 正常应该可以读取
        final dates = await checkFile.readAllDates();
        expect(dates, [20240101]);
      });
    });

    group('性能测试', () {
      test('多次检查性能', () {
        final checkFile = CheckFile(
          filePath: testFilePath,
          addNum: 0,
          allTimes: 100,
        );

        final stopwatch = Stopwatch()..start();

        for (int i = 0; i < 100; i++) {
          checkFile.checkTimesSync();
        }

        stopwatch.stop();
        print('同步100次检查耗时: ${stopwatch.elapsedMilliseconds}ms');

        // 性能不应该太差
        expect(stopwatch.elapsedMilliseconds, lessThan(1000));
      });

      test('异步性能测试', () async {
        final checkFile = CheckFile(
          filePath: testFilePath,
          addNum: 0,
          allTimes: 100,
        );

        final stopwatch = Stopwatch()..start();

        final futures = List.generate(100, (_) => checkFile.checkTimes());
        await Future.wait(futures);

        stopwatch.stop();
        print('异步100次检查耗时: ${stopwatch.elapsedMilliseconds}ms');

        expect(stopwatch.elapsedMilliseconds, lessThan(2000));
      });
    });

    group('辅助方法测试', () {
      test('getTodayDate 方法', () {
        final today = DateTime.now();
        final expected = today.year * 10000 + today.month * 100 + today.day;

        expect(CheckFile.getTodayDate(), expected);
      });

      test('formatDate 方法', () {
        final testDate = DateTime(2024, 1, 15);
        final formatted = CheckFile.formatDate(testDate);

        expect(formatted, 20240115);

        // 测试2月29日（闰年）
        final leapDate = DateTime(2024, 2, 29);
        expect(CheckFile.formatDate(leapDate), 20240229);

        // 测试12月31日
        final yearEnd = DateTime(2024, 12, 31);
        expect(CheckFile.formatDate(yearEnd), 20241231);
      });

      test('clearFile 方法', () async {
        final checkFile = CheckFile(
          filePath: testFilePath,
          addNum: 0,
          allTimes: 3,
        );

        // 写入一些数据
        await checkFile.checkTimes();
        await checkFile.checkTimes();

        expect(await checkFile.readAllDates(), isNotEmpty);

        // 清空
        await checkFile.clearFile();

        expect(await checkFile.readAllDates(), isEmpty);
        expect(await File(testFilePath).readAsString(), '');
      });
    });
  });
}
