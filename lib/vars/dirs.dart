import 'package:study_platform/logic/env_mod.dart';

class Dirs {
  static String filePath() {
    return EnvMod.getStdpath();
  }

  static String filePathTongy() {
    return "${filePath()}tyhbdirapbb/";
  }

  static List<String> dirs() {
    return [
      filePath(),
      filePathTongy(),
    ];
  }
}
