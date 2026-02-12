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

  static String filePathBank() {
    return "${filePath()}cc.bnkaac.c.io/";
  }

  static String filePathSetting() {
    return "${filePath()}settings/";
  }

  static String filePathTS() {
    return "${filePath()}tssqudirdpg/";
  }

  static String filePathBaowu() {
    return "${filePath()}baocdiran/";
  }

  static String filePathAncient() {
    return "${filePath()}adirspfm/";
  }

  static String filePathBook() {
    return "${filePath()}sjdirspf/";
  }

  static String filePathPao() {
    return "${filePath()}apcdir/";
  }

  static String filePathAWuGuan() {
    return "${filePathAncient()}fpawg.4of/";
  }

  static String filePathXXianLu() {
    return "${filePath()}xlccf.gfd.ew0/";
  }

  static List<String> dirs() {
    return [
      filePath(),
      filePathAncient(),
      filePathAWuGuan(),
      filePathBank(),
      filePathBaoShi(),
      filePathBaowu(),
      filePathBook(),
      filePathCard(),
      filePathPao(),
      filePathSetting(),
      filePathTongy(),
      filePathTongyReal(),
      filePathTS(),
      filePathXXianLu(),
    ];
  }
}
