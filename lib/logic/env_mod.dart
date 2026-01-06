import 'dart:io';

class EnvMod {
  static String getUser() {
    return Platform.environment["USER"] ?? "";
  }
}
