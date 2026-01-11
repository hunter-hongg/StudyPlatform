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
}

class LiheFiles {
  static OnceFile basicLihe() {
    return OnceFile("${Dirs.filePath()}onfiblho.of.ooo");
  }
}
