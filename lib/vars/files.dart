import 'package:study_platform/tool/cards.dart';
import 'package:study_platform/tool/check_file.dart';
import 'package:study_platform/tool/file_password.dart';
import 'package:study_platform/tool/once_file.dart';
import 'package:study_platform/vars/cards.dart';
import 'package:study_platform/vars/dirs.dart';

class Files {
  static FilePassword jiFenReader() {
    return FilePassword("${Dirs.filePath()}jifc.txt", "hsiep10475");
  }

  static FilePassword jinBiReader() {
    return FilePassword("${Dirs.filePathTongy()}rd.conc", "apslfnt104");
  }

  static FilePassword jiSuanBiReader() {
    return FilePassword("${Dirs.filePath()}jsbc.txt", "woda2fj341");
  }

  static FilePassword xianBiReader() {
    return FilePassword("${Dirs.filePath()}xianbc.conc", "woapf20sl1");
  }

  static FilePassword aTongQianReader() {
    return FilePassword("${Dirs.filePath()}tb.avc", "hifo356sjl");
  }

  static FilePassword tongYongReader() {
    return FilePassword("${Dirs.filePathTongyReal()}tyrelrd.cc", "qacjf34860");
  }

  static FilePassword yinBiReader() {
    return FilePassword(
        "${Dirs.filePathTongy()}yb.conc.sdpg.1659", "apfjr12409");
  }

  static FilePassword baoShiReader() {
    return FilePassword("${Dirs.filePathBaoShi()}mbsc.conc", "rosl3510dm");
  }

  static FilePassword bankSReader() {
    return FilePassword("${Dirs.filePathBank()}fhubasr", "aoidnrm301");
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

class CardStore {
  static Cards sanGuo1() {
    return Cards(
      filename: '${Dirs.filePath()}capsgc1.txt',
      cardname: CardList.sanGuo1(),
      addnum: 9573,
    );
  }

  static Cards han1() {
    return Cards(
      filename: "${Dirs.filePathCard()}h1cac1.cac",
      cardname: CardList.han1(),
      addnum: 7184,
    );
  }
}
