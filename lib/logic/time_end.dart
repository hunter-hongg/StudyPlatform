import 'package:study_platform/logic/jifen.dart';
import 'package:study_platform/vars/files.dart';
import 'package:study_platform/vars/timers.dart';

class TimeEnd {
  static String dealTimeEnd() {
    final scd = jiFenTimer.elapsed.inSeconds;
    final min = (scd / 60).toInt();
    final get = Jifen.getJifenFromSec(scd);
    Files.jiFenReader().addNumSync(get);
    return "计时结束\n"
        "本次共计$scd秒，合$min分钟\n"
        "获得$get积分\n";
  }
}
