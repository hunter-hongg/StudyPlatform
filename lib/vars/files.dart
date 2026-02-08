import 'package:study_platform/logic/apao.dart';
import 'package:study_platform/logic/asword.dart';
import 'package:study_platform/logic/awenguan.dart';
import 'package:study_platform/tool/addfile.dart';
import 'package:study_platform/tool/cards.dart';
import 'package:study_platform/tool/check_file.dart';
import 'package:study_platform/tool/file_password.dart';
import 'package:study_platform/tool/once_file.dart';
import 'package:study_platform/tool/statefile.dart';
import 'package:study_platform/vars/cards.dart';
import 'package:study_platform/vars/dirs.dart';

class Files {
  static FilePassword jiFenReader() {
    return FilePassword("${Dirs.filePath()}jifc.txt", "hsiep10475");
  }

  static FilePassword jinBiReader() {
    return FilePassword("${Dirs.filePathTongy()}rd.conc", "apslfnt104");
  }

  static FilePassword jiSuanBiReader() {
    return FilePassword("${Dirs.filePath()}jsbc.txt", "woda2fj341");
  }

  static FilePassword xianBiReader() {
    return FilePassword("${Dirs.filePath()}xianbc.conc", "woapf20sl1");
  }

  static FilePassword aTongQianReader() {
    return FilePassword("${Dirs.filePath()}tb.avc", "hifo356sjl");
  }

  static FilePassword aBaiYinReader() {
    return FilePassword("${Dirs.filePath()}bay.avc", "3ifnyl1042");
  }

  static FilePassword aHuangJinReader() {
    return FilePassword("${Dirs.filePath()}huaj.avc", "dgp395sk10");
  }

  static FilePassword tongYongReader() {
    return FilePassword("${Dirs.filePathTongyReal()}tyrelrd.cc", "qacjf34860");
  }

  static FilePassword yinBiReader() {
    return FilePassword(
        "${Dirs.filePathTongy()}yb.conc.sdpg.1659", "apfjr12409");
  }

  static FilePassword baoShiReader() {
    return FilePassword("${Dirs.filePathBaoShi()}mbsc.conc", "rosl3510dm");
  }

  static FilePassword bankSReader() {
    return FilePassword("${Dirs.filePathBank()}fhubasr", "aoidnrm301");
  }

  static FilePassword bankJReader() {
    return FilePassword("${Dirs.filePathBank()}bjq.cc.ssdiowei_", "asoirm2156");
  }

  static FilePassword aCiQiReader() {
    return FilePassword("${Dirs.filePath()}cq.avgwc", "so3pfm10a2");
  }

  static FilePassword aBeiKeReader() {
    return FilePassword("${Dirs.filePath()}shb.avgwc", "sudo1048qp");
  }

  static FilePassword aYuPeiReader() {
    return FilePassword("${Dirs.filePath()}yup.avgwc", "sofp194327");
  }

  static FilePassword aJuanZhiReader() {
    return FilePassword("${Dirs.filePathAncient()}jzrd.conc", "dfpwm13058");
  }

  static FilePassword aWenZhengjReader() {
    return FilePassword("${Dirs.filePath()}zhejrder.awgcc", "eso1pam360");
  }
}

class LiheFiles {
  static OnceFile basicLihe() {
    return OnceFile("${Dirs.filePath()}onfiblho.of.ooo");
  }
}

class CheckFiles {
  static CheckFile calcAddsubCheck() {
    return CheckFile(
      filePath: "${Dirs.filePath()}jisbck1.txt",
      addNum: 1049,
      allTimes: 7,
    );
  }

  static CheckFile calcTimeCheck() {
    return CheckFile(
      filePath: "${Dirs.filePath()}jisbck2.txt",
      addNum: 305,
      allTimes: 5,
    );
  }

  static CheckFile calcDivCheck() {
    return CheckFile(
      filePath: "${Dirs.filePath()}jisbck3.chkl",
      addNum: 302,
      allTimes: 5,
    );
  }

  static CheckFile calcPolyCheck() {
    return CheckFile(
      filePath: "${Dirs.filePath()}jisbck92.chkl",
      addNum: 3259,
      allTimes: 5,
    );
  }

  static CheckFile tsJifenCheck() {
    return CheckFile(
      filePath: "${Dirs.filePathTS()}tsjfcc.ck",
      addNum: 1049,
      allTimes: 7,
    );
  }

  static CheckFile tsXianbiCheck() {
    return CheckFile(
      filePath: "${Dirs.filePathTS()}tsxbcc.ck",
      addNum: 2202,
      allTimes: 1,
    );
  }

  static CheckFile tsTongqianCheck() {
    return CheckFile(
      filePath: "${Dirs.filePathTS()}tqchk.ck",
      addNum: 2212,
      allTimes: 1,
    );
  }

  static CheckFile tsBaoshiCheck() {
    return CheckFile(
      filePath: "${Dirs.filePathTS()}fospbsck.dogck",
      addNum: 1127,
      allTimes: 1,
    );
  }

  static CheckFile tsJinbiCheck() {
    return CheckFile(
      filePath: "${Dirs.filePathTS()}sdogh.dogck",
      addNum: 2035,
      allTimes: 1,
    );
  }

  static CheckFile aJuanCheck() {
    return CheckFile(
      filePath: "${Dirs.filePathAncient()}jzrd.conc.lqck.conc",
      addNum: 1250,
      allTimes: 1,
    );
  }

  static CheckFile aWenFengCheck() {
    return CheckFile(
      filePath: "${Dirs.filePath()}flchk.awgcc",
      addNum: 4034,
      allTimes: 1,
    );
  }

  static CheckFile aWenZhengJiCheck() {
    return CheckFile(
      filePath: "${Dirs.filePathAncient()}zjzjck.ckawgcc",
      addNum: 4059,
      allTimes: 1,
    );
  }

  static CheckFile aWenZhengShCheck() {
    return CheckFile(
      filePath: "${Dirs.filePathAncient()}msmsck.ckawgcc.dsi.1234",
      addNum: 2125,
      allTimes: 1,
    );
  }
}

class CardStore {
  static Cards sanGuo1() {
    return Cards(
      filename: '${Dirs.filePath()}capsgc1.txt',
      cardname: CardList.sanGuo1(),
      addnum: 9573,
    );
  }

  static Cards han1() {
    return Cards(
      filename: "${Dirs.filePathCard()}h1cac1.cac",
      cardname: CardList.han1(),
      addnum: 7184,
    );
  }
}

class Setting {
  static StateFile enableUtil() {
    return StateFile("${Dirs.filePathSetting()}util.setting");
  }
}

class AddFiles {
  static AddFile aLvYuReader() {
    return AddFile("${Dirs.filePathBaowu()}jzcc.conc", 1657);
  }

  static AddFile aBaiYuReader() {
    return AddFile("${Dirs.filePathBaowu()}yzcc.conc", 1657);
  }

  static AddFile aGuwanChaHu() {
    return AddFile("${Dirs.filePathAncient()}apdfn.gwcc1.conc", 2353);
  }

  static AddFile aGuwanChaZhan() {
    return AddFile("${Dirs.filePathAncient()}asofn.gwcc2.conc", 2353);
  }

  static AddFile aBaowuMingZhu() {
    return AddFile("${Dirs.filePathBaowu()}baoyemz.bacc", 2109);
  }

  static AddFile aBaowuYuDiao() {
    return AddFile("${Dirs.filePathBaowu()}yudc.bacc", 2109);
  }

  static AddFile aBaowuYuBi() {
    return AddFile("${Dirs.filePathBaowu()}byubc.bacc", 2109);
  }

  static AddFile aBaowuChouDuan() {
    return AddFile("${Dirs.filePathBaowu()}baochoc.bacc", 2109);
  }

  static AddFile aBaowuYuzhan() {
    return AddFile("${Dirs.filePathBaowu()}baoyzex.bacce", 2024);
  }

  static AddFile aBaowuHu() {
    return AddFile("${Dirs.filePathBaowu()}bwcrdc1.onc", 2017);
  }

  static AddFile aBaowuZhan() {
    return AddFile("${Dirs.filePathBaowu()}bwcrd2.onc", 2017);
  }

  static AddFile aBook1() {
    return AddFile("${Dirs.filePathBook()}lv1cc.conc", 3406);
  }

  static AddFile aBook2() {
    return AddFile("${Dirs.filePathBook()}lv2cc.conc", 3406);
  }

  static AddFile aBook3() {
    return AddFile("${Dirs.filePathBook()}lv3cc.conc", 3406);
  }

  static AddFile aBookC1() {
    return AddFile("${Dirs.filePathBook()}lvc1cc", 2390);
  }

  static AddFile aBookC2() {
    return AddFile("${Dirs.filePathBook()}lvc2cc", 2990);
  }

  static AddFile aBookC3() {
    return AddFile("${Dirs.filePathBook()}lvc3cc", 2690);
  }

  static AddFile aBookC4() {
    return AddFile("${Dirs.filePathBook()}lvc4cc", 2300);
  }

  static AddFile aBookC5() {
    return AddFile("${Dirs.filePathBook()}lvc5cc", 2310);
  }
}

class Special {
  static AncientSword aSword() {
    return AncientSword(
      "${Dirs.filePath()}avswd.avc",
      "${Dirs.filePath()}avswa.avc",
    );
  }

  static AncientPao aPao() {
    return AncientPao(
      "${Dirs.filePathPao()}paon.paoc",
      "${Dirs.filePathPao()}paoa.paoac",
    );
  }

  static AncientWenGuanConfig aWenGuanConfig() {
    return AncientWenGuanConfig(
      file: "${Dirs.filePath()}awcfg.awgcc",
      addNum: 1052,
    );
  }
}

class WuConst {
  static int puTongMin = 3;
  static int chuJiMin = 6;
  static int xinMin = 1;
  static int zhongJiMin = 10;
  static int gaoJiMin = 20;
  static int jingRuiMin = 40;
  static int wangPaiMin = 90;
  static int shenJiMin = 20;
	static List<int> zhaoPrice = [
		1, 10, 30, 60, 150, 350, 700, 900, 
	];
}

class WuVar {
  static FilePassword xinLr() {
    return FilePassword(
        "${Dirs.filePathAWuGuan()}wgll.xawg.cc.43", "fm5o3kd104");
  }

  static FilePassword xinIr() {
    return FilePassword.withDefault(
      "${Dirs.filePathAWuGuan()}wgllbl.regio.xb.cc..x",
      "2309fj4i5p",
      WuConst.xinMin,
    );
  }

  static FilePassword puTongLr() {
    return FilePassword(
        "${Dirs.filePathAWuGuan()}wgll.pt.cc.ro3", "fivn310694");
  }

  static FilePassword chuJiLr() {
    return FilePassword(
        "${Dirs.filePathAWuGuan()}wgll.eo.cj.cc.30", "form30296l");
  }

  static FilePassword zhongJiLr() {
    return FilePassword(
        "${Dirs.filePathAWuGuan()}wgll.eo.zhj.39c.cc", "domt53p210");
  }

  static FilePassword gaoJiLr() {
    return FilePassword(
        "${Dirs.filePathAWuGuan()}wgll.em.gaoj.do3.cc", "dmei45103k");
  }

  static FilePassword jingRuiLr() {
    return FilePassword(
        "${Dirs.filePathAWuGuan()}wgll.emf.ro.jingr.di.cc", "1094nfmwl2");
  }

  static FilePassword wangPaiLr() {
    return FilePassword(
        "${Dirs.filePathAWuGuan()}wgll.od.wap.cc..e", "efoidm2590");
  }

  static FilePassword shenJiLr() {
    return FilePassword(
        "${Dirs.filePathAWuGuan()}wgll.shj.dfo.cc..", "eogfmt3960");
  }

  static FilePassword puTongIr() {
    return FilePassword.withDefault(
      "${Dirs.filePathAWuGuan()}wgllbl.ptcc.eoi..xdd",
      "doirm19840",
      WuConst.puTongMin,
    );
  }

  static FilePassword chuJiIr() {
    return FilePassword.withDefault(
      "${Dirs.filePathAWuGuan()}wgllbl.dsoi.cjcc..do",
      "sdoi4960al",
      WuConst.chuJiMin,
    );
  }

  static FilePassword zhongJiIr() {
    return FilePassword.withDefault(
      "${Dirs.filePathAWuGuan()}e.wgllbl.dso.cjcc.zj..d",
      "sdoim39501",
      WuConst.zhongJiMin,
    );
  }

  static FilePassword gaoJiIr() {
    return FilePassword.withDefault(
      "${Dirs.filePathAWuGuan()}r.wgllbl.d.dui.gj.dc",
      "sdiu38901l",
      WuConst.gaoJiMin,
    );
  }

  static FilePassword jingRuiIr() {
    return FilePassword.withDefault(
      "${Dirs.filePathAWuGuan()}wgllbl.df.d.jrcc.c.d",
      "dsorm28901",
      WuConst.jingRuiMin,
    );
  }

  static FilePassword wangPaiIr() {
    return FilePassword.withDefault(
      "${Dirs.filePathAWuGuan()}wgllbl.eo.eo.wp.d",
      "12984jfrkw",
      WuConst.wangPaiMin,
    );
  }

  static FilePassword shenJiIr() {
    return FilePassword.withDefault(
      "${Dirs.filePathAWuGuan()}wgllbl.eo.df.shjcc.",
      "eufmrl3029",
      WuConst.shenJiMin,
    );
  }
}
