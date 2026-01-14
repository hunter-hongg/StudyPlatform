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
