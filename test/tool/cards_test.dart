import 'dart:io';
import 'package:test/test.dart';
import 'package:study_platform/tool/cards.dart';

void main() {
  group('Cards 类测试', () {
    const testFileName = 'test_cards.txt';
    const testCardNames = ['火焰卡', '寒冰卡', '雷电卡', '治疗卡', '护盾卡'];
    const testAddNum = 1000;
    
    late Cards cards;
    
    setUp(() {
      // 每次测试前清理测试文件
      final file = File(testFileName);
      if (file.existsSync()) {
        file.deleteSync();
      }
      
      cards = Cards(
        filename: testFileName,
        cardname: testCardNames,
        addnum: testAddNum,
      );
    });
    
    tearDown(() {
      // 每次测试后清理测试文件
      final file = File(testFileName);
      if (file.existsSync()) {
        file.deleteSync();
      }
    });
    
    test('构造函数正常创建对象', () {
      expect(cards.filename, equals(testFileName));
      expect(cards.cardname, equals(testCardNames));
      expect(cards.addnum, equals(testAddNum));
    });
    
    test('get() - 空文件返回空列表', () {
      final result = cards.get();
      expect(result, isEmpty);
    });
    
    test('get() - 有效数据解析', () {
      // 准备测试数据
      final file = File(testFileName);
      file.writeAsStringSync(',/x/1000,/x/1002,/x/1001');
      
      final result = cards.get();
      expect(result, equals(['火焰卡', '雷电卡', '寒冰卡'])); // 注意顺序
    });
    
    test('get() - 过滤无效前缀', () {
      final file = File(testFileName);
      file.writeAsStringSync('/y/1000,/x/1001,/z/1002');
      
      final result = cards.get();
      expect(result, equals(['寒冰卡']));
    });
    
    test('get() - 过滤无法解析的数字', () {
      final file = File(testFileName);
      file.writeAsStringSync('/x/abc,/x/1001,/x/123abc');
      
      final result = cards.get();
      expect(result, equals(['寒冰卡']));
    });
    
    test('get() - 去重功能', () {
      final file = File(testFileName);
      file.writeAsStringSync('/x/1001,/x/1001,/x/1002,/x/1001');
      
      final result = cards.get();
      expect(result.length, equals(2)); // 寒冰卡和雷电卡，去重后只出现一次
      expect(result, contains('寒冰卡'));
      expect(result, contains('雷电卡'));
    });
    
    test('get() - 超出范围的索引被忽略', () {
      final file = File(testFileName);
      file.writeAsStringSync('/x/999,/x/1001,/x/1005,/x/10000');
      
      final result = cards.get();
      expect(result, equals(['寒冰卡'])); // 只有 1001 有效
    });
    
    test('get() - 调整数字计算正确', () {
      // 使用不同的 addnum 测试
      final specialCards = Cards(
        filename: testFileName,
        cardname: testCardNames,
        addnum: 500,
      );
      
      final file = File(testFileName);
      file.writeAsStringSync('/x/501,/x/503');
      
      final result = specialCards.get();
      expect(result, equals(['寒冰卡', '治疗卡']));
    });
    
    test('write() - 写入有效索引', () {
      final result = cards.write(2); // 索引 2 = 雷电卡
      
      expect(result, equals(0)); // 返回 0 表示成功
      
      // 验证文件内容
      final file = File(testFileName);
      expect(file.existsSync(), isTrue);
      
      final content = file.readAsStringSync();
      expect(content, equals(',/x/1002')); // 1000 + 2
    });
    
    test('write() - 索引超出范围返回-1', () {
      final result1 = cards.write(-1);
      final result2 = cards.write(10); // 超出 cardname 长度
      
      expect(result1, equals(-1));
      expect(result2, equals(-1));
      
      // 确保文件没有被创建
      final file = File(testFileName);
      expect(file.existsSync(), isFalse);
    });
    
    test('write() - 多次写入', () {
      cards.write(0); // 火焰卡
      cards.write(2); // 雷电卡
      cards.write(1); // 寒冰卡
      
      final file = File(testFileName);
      final content = file.readAsStringSync();
      expect(content, equals(',/x/1000,/x/1002,/x/1001'));
    });
    
    test('write() - 文件创建功能', () {
      // 确保文件不存在
      final file = File(testFileName);
      expect(file.existsSync(), isFalse);
      
      // 写入数据
      final result = cards.write(1);
      
      expect(result, equals(0));
      expect(file.existsSync(), isTrue);
    });
    
    test('get() 和 write() 集成测试', () {
      // 写入一些数据
      cards.write(0); // 火焰卡
      cards.write(3); // 治疗卡
      cards.write(2); // 雷电卡
      
      // 读取并验证
      final result = cards.get();
      expect(result, equals(['火焰卡', '治疗卡', '雷电卡']));
    });
    
    test('getByIndex() - 有效索引', () {
      expect(cards.getByIndex(0), equals('火焰卡'));
      expect(cards.getByIndex(2), equals('雷电卡'));
      expect(cards.getByIndex(4), equals('护盾卡'));
    });
    
    test('getByIndex() - 无效索引返回空字符串', () {
      expect(cards.getByIndex(-1), equals(''));
      expect(cards.getByIndex(5), equals(''));
      expect(cards.getByIndex(100), equals(''));
    });
    
    test('复杂场景测试 - 完整流程', () {
      // 步骤 1: 初始状态
      expect(cards.get(), isEmpty);
      
      // 步骤 2: 写入多个卡片
      expect(cards.write(0), equals(0)); // 火焰卡
      expect(cards.write(2), equals(0)); // 雷电卡
      expect(cards.write(1), equals(0)); // 寒冰卡
      expect(cards.write(0), equals(0)); // 重复写入火焰卡
      
      // 步骤 3: 读取验证
      final retrieved = cards.get();
      expect(retrieved, equals(['火焰卡', '雷电卡', '寒冰卡'])); // 有去重
      
      // 步骤 4: 继续写入
      expect(cards.write(4), equals(0)); // 护盾卡
      expect(cards.write(3), equals(0)); // 治疗卡
      
      // 步骤 5: 再次读取
      final finalResult = cards.get();
      expect(finalResult.length, equals(5)); // 所有5张卡
      expect(finalResult, containsAll(testCardNames));
      
      // 步骤 6: 验证 getByIndex
      for (var i = 0; i < testCardNames.length; i++) {
        expect(cards.getByIndex(i), equals(testCardNames[i]));
      }
    });
  });
}