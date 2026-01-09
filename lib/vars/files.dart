import 'package:study_platform/tool/file_password.dart';
import 'package:study_platform/vars/dirs.dart';

class Files {
  static FilePassword jiFenReader() {
    var fp = Dirs.filePath();
    return FilePassword("${fp}jifc.txt", "hsiep10475");
  }
}
