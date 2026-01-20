import 'package:study_platform/logic/env_mod.dart';

class Dirs {
  static String filePath() {
    return EnvMod.getStdpath();
  }

  static String filePathTongy() {
    return "${filePath()}tyhbdirapbb/";
  }

  static String filePathCard() {
    return "${filePath()}fpcdiralf/";
  }

  static String filePathTongyReal() {
    return "${filePathTongy()}fptyr/";
  }

  static String filePathBaoShi() {
    return "${filePath()}baosdirfos/";
  }

  static List<String> dirs() {
    return [
      filePath(),
      filePathTongy(),
      filePathCard(),
      filePathTongyReal(),
    ];
  }
}
