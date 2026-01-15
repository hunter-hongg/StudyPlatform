import 'dart:io';

class Cards {
  final String filename;
  final List<String> cardname;
  final int addnum;

  Cards({
    required this.filename,
    required this.cardname,
    required this.addnum,
  });

  List<String> get() {
    final file = File(filename);

    try {
      // 确保文件存在
      if (!file.existsSync()) {
        file.createSync(recursive: true);
        return [];
      }

      final content = file.readAsStringSync().trim();
      if (content.isEmpty) {
        return [];
      }

      final rawVec = content.split(',');
      final seen = <int>{};
      final realCardVec = <String>[];

      for (var item in rawVec) {
        item = item.trim();
        if (!item.startsWith('/x/')) {
          continue;
        }

        final realstr = item.substring(3);
        final num = int.tryParse(realstr);
        if (num == null) {
          continue;
        }

        final adjustedNum = num - addnum;
        if (seen.contains(adjustedNum)) {
          continue;
        }
        seen.add(adjustedNum);

        if (adjustedNum >= 0 && adjustedNum < cardname.length) {
          realCardVec.add(cardname[adjustedNum]);
        }
      }

      return realCardVec;
    } catch (e) {
      print('Error reading cards file: $e');
      return [];
    }
  }

  int write(int index) {
    if (index < 0 || index >= cardname.length) {
      return -1;
    }

    try {
      final file = File(filename);
      if (!file.existsSync()) {
        file.createSync(recursive: true);
      }

      final sink = file.openSync(mode: FileMode.append);
      sink.writeStringSync(',/x/${addnum + index}');
      sink.flushSync();
      sink.closeSync();

      return 0;
    } catch (e) {
      print('Error writing to cards file: $e');
      return -1;
    }
  }

  String getByIndex(int index) {
    if (index < 0 || index >= cardname.length) {
      return '';
    }
    return cardname[index];
  }
}
