import 'dart:io';

class EnvMod {
  static String getUser() {
    return Platform.environment["USER"] ?? "";
  }

  static String getHome() {
    var user = getUser();
    return Platform.environment["HOME"] ?? "/home/$user";
  }

  static String getStdpath() {
    var home = getHome();
    return "$home/.store/学习平台储存/";
  }
}
