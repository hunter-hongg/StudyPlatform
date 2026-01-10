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

  static int getJifenFromSec(int seconds) {
    if (seconds < 60) {
      return 1;
    } else if (seconds < 300) {
      return (seconds / 30).toInt();
    } else if (seconds < 1500) {
      return (seconds / 20).toInt();
    } else {
      return (seconds / 15).toInt();
    }
  }
}
