class Jifen {
  static int getLevel(int jif) {
    var level = ((jif - 200) / 150).toInt();
    if (level < 1) {
      return 1;
    } else if (level > 100) {
      return 100;
    } else {
      return level;
    }
  }
}
