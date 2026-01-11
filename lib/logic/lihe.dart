import 'package:study_platform/vars/files.dart';

class Lihe {
  static void dealBasic() {
    // 200积分 5金币
    Files.jiFenReader().addNumSync(200);
    Files.jinBiReader().addNumSync(5);
  }
}
