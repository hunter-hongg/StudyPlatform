import 'dart:io';
import 'package:flutter_test/flutter_test.dart';
import 'package:study_platform/tool/addfile.dart';

void main() {
  late Directory tempDir;
  late String tempFilePath;

  setUp(() {
    // 创建临时目录
    tempDir = Directory.systemTemp.createTempSync('addfile_test_');
    tempFilePath = '${tempDir.path}/test.txt';
  });

  tearDown(() {
    // 清理临时目录
    tempDir.deleteSync(recursive: true);
  });

  group('AddFile Tests', () {
    test('Initialization and creation', () {
      const addnum = 5;
      final addFile = AddFile(tempFilePath, addnum);
      
      expect(addFile.file, tempFilePath);
      expect(addFile.addnum, addnum);
    });

    test('Factory constructor works', () {
      const addnum = 10;
      final addFile = AddFile.create(tempFilePath, addnum);
      
      expect(addFile.file, tempFilePath);
      expect(addFile.addnum, addnum);
    });

    test('readInt returns 0 when file does not exist', () {
      final addFile = AddFile(tempFilePath, 5);
      final result = addFile.readInt();
      
      expect(result, 0);
    });

    test('readInt returns correct value when file exists', () async {
      const addnum = 5;
      const originalValue = 20;
      await File(tempFilePath).writeAsString('$originalValue');

      final addFile = AddFile(tempFilePath, addnum);
      final result = addFile.readInt();
      
      expect(result, originalValue - addnum); // Should be 15 (20 - 5)
    });

    test('readInt returns 0 when file contains invalid integer', () async {
      const addnum = 5;
      await File(tempFilePath).writeAsString('not_a_number');

      final addFile = AddFile(tempFilePath, addnum);
      final result = addFile.readInt();
      
      expect(result, 0);
    });

    test('readStr returns string representation of readInt', () async {
      const addnum = 3;
      const originalValue = 15;
      await File(tempFilePath).writeAsString('$originalValue');

      final addFile = AddFile(tempFilePath, addnum);
      final strResult = addFile.readStr();
      final intResult = addFile.readInt();
      
      expect(strResult, intResult.toString());
      expect(intResult, originalValue - addnum); // Should be 12 (15 - 3)
    });

    test('write method writes string to file', () async {
      const content = 'Hello World';
      final addFile = AddFile(tempFilePath, 0);
      
      await addFile.write(content);
      
      final fileContent = await File(tempFilePath).readAsString();
      expect(fileContent, content);
    });

    test('addNum increases the value in file', () async {
      const addnum = 5;
      const originalValue = 20;
      const addToValue = 10;
      
      await File(tempFilePath).writeAsString('$originalValue');
      
      final addFile = AddFile(tempFilePath, addnum);
      await addFile.addNum(addToValue);
      
      final result = addFile.readInt();
      expect(result, originalValue - addnum + addToValue); // (20-5)+10 = 25
    });

    test('canMinus returns false when file value is less than subtracted amount', () async {
      const addnum = 5;
      const originalValue = 8;
      
      await File(tempFilePath).writeAsString('$originalValue');
      
      final addFile = AddFile(tempFilePath, addnum);
      final result = addFile.canMinusSync(10); // Using sync version
      
      expect(result, false);
    });

    test('canMinus returns true and reduces value when possible', () async {
      const addnum = 5;
      const originalValue = 15;
      const subtractValue = 7;
      
      await File(tempFilePath).writeAsString('$originalValue');
      
      final addFile = AddFile(tempFilePath, addnum);
      final result = addFile.canMinusSync(subtractValue); // Using sync version
      
      expect(result, true);
      
      final finalValue = addFile.readInt();
      expect(finalValue, originalValue - addnum - subtractValue); // 15-5-7 = 3
    });

    test('high returns true when value is greater than or equal to threshold', () async {
      const addnum = 5;
      const originalValue = 15;
      
      await File(tempFilePath).writeAsString('$originalValue');
      
      final addFile = AddFile(tempFilePath, addnum);
      final resultHigh = addFile.high(8); // 10 >= 8
      final resultLow = addFile.high(12); // 10 >= 12
      
      expect(resultHigh, true);
      expect(resultLow, false);
    });

    test('readIntSafe and readStrSafe work the same as readInt and readStr', () async {
      const addnum = 3;
      const originalValue = 25;
      
      await File(tempFilePath).writeAsString('$originalValue');
      
      final addFile = AddFile(tempFilePath, addnum);
      
      expect(addFile.readIntSafe(), addFile.readInt());
      expect(addFile.readStrSafe(), addFile.readStr());
    });

    test('canMinusSafe works asynchronously', () async {
      const addnum = 5;
      const originalValue = 15;
      const subtractValue = 7;
      
      await File(tempFilePath).writeAsString('$originalValue');
      
      final addFile = AddFile(tempFilePath, addnum);
      final result = await addFile.canMinusSafe(subtractValue);
      
      expect(result, true);
      
      final finalValue = addFile.readInt();
      expect(finalValue, originalValue - addnum - subtractValue); // 15-5-7 = 3
    });

    test('ReadStr method returns string representation of ReadInt', () async {
      const addnum = 10;
      const originalValue = 30;
      
      await File(tempFilePath).writeAsString('$originalValue');
      
      final addFile = AddFile(tempFilePath, addnum);
      final resultAsStr = addFile.readStr();
      final resultAsInt = addFile.readInt();
      
      expect(resultAsStr, resultAsInt.toString());
      expect(resultAsStr, (originalValue - addnum).toString()); // 30 - 10 = 20
    });
  });
}