import 'package:flutter/material.dart';
import 'package:study_platform/logic/trade.dart';
import 'package:study_platform/tool/file_password.dart';
import 'package:study_platform/tool/random.dart';
import 'package:study_platform/vars/files.dart';
import 'package:study_platform/vars/simple.dart';

class XianHe {
/*
	deal := func(fpo *util.FilePassword, jifadd int, jinadd int) {
		if res, err := fpo.CanMinus(1); (!res) || (err!=nil){
			simple.DialogInfo("仙丹不足", global.Main_Window)
			return
		}
		rndp := cgo.GetRnd(-50, 100)
		global.File_JiFenReader.AddNum(jifadd+rndp)
		global.File_JinBiReader.AddNum(jinadd+rndp)
		simple.DialogInfo("召鹤成功 获得"+strconv.Itoa(jifadd+rndp)+"积分和"+strconv.Itoa(jinadd+rndp)+"金币", global.Main_Window)
	}
  */
  static void zhao(BuildContext context, FilePassword xd, int jifadd, int jinadd) {
    Trade.tradeFFunc(context, xd, '仙丹', 1, () {
      var rnd = RandomGet.getIntClose(-50, 110);
      var jifshow = jifadd + rnd;
      var jinshow = jinadd + rnd;
      Files.jiFenReader().addNumSync(jifshow);
      Files.jinBiReader().addNumSync(jinshow);
      Simple.simpleInfo(
        context: context,
        show: '召鹤成功，获得$jifshow积分和$jinshow金币',
      );
    });
  }
}
