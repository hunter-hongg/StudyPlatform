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
