import 'package:study_platform/tool/cards.dart';
import 'package:study_platform/tool/check_file.dart';
import 'package:study_platform/tool/file_password.dart';
import 'package:study_platform/tool/once_file.dart';
import 'package:study_platform/vars/dirs.dart';

class Files {
  static FilePassword jiFenReader() {
    var fp = Dirs.filePath();
    return FilePassword("${fp}jifc.txt", "hsiep10475");
  }

  static FilePassword jinBiReader() {
    return FilePassword("${Dirs.filePathTongy()}rd.conc", "apslfnt104");
  }

  static FilePassword jiSuanBiReader() {
    return FilePassword("${Dirs.filePath()}jsbc.txt", "woda2fj341");
  }
}

class LiheFiles {
  static OnceFile basicLihe() {
    return OnceFile("${Dirs.filePath()}onfiblho.of.ooo");
  }
}

class CheckFiles {
  static CheckFile calcAddsubCheck() {
    return CheckFile(
      filePath: "${Dirs.filePath()}jisbck1.txt",
      addNum: 1049,
      allTimes: 7,
    );
  }

  static CheckFile calcTimeCheck() {
    return CheckFile(
      filePath: "${Dirs.filePath()}jisbck2.txt",
      addNum: 305,
      allTimes: 5,
    );
  }

  static CheckFile calcDivCheck() {
    return CheckFile(
      filePath: "${Dirs.filePath()}jisbck3.chkl",
      addNum: 302,
      allTimes: 5,
    );
  }

  static CheckFile calcPolyCheck() {
    return CheckFile(
      filePath: "${Dirs.filePath()}jisbck92.chkl",
      addNum: 3259,
      allTimes: 5,
    );
  }
}

class CardList {
  static List<String> sanGuo1() {
    return [
      "卧龙", "凤雏", "曹操", "孙权", "刘备", "关羽",
      "张飞", "马超", "黄忠", "赵云", "张辽", "徐晃",
      "张郃", "于禁", "乐进", "许褚", "典韦", "关兴",
      "张苞", "曹纯", "周瑜", "鲁肃", "吕蒙", "陆逊",
      "陆抗", "徐盛", "丁奉", "马忠", "潘璋", "黄盖",
      "郭嘉", "程昱", "荀彧", "荀攸", "荀谌", "张昭",
      "顾雍", "阚泽", "程秉", "虞翻", "张南", "冯习",
      "魏延", "姜维", "邓艾", "钟会",
    ];
  }
}

class CardStore {
  static Cards sanGuo1() {
    return Cards(
      filename: '${Dirs.filePath()}capsgc1.txt',
      cardname: CardList.sanGuo1(),
      addnum: 9573,
    );
  }
}