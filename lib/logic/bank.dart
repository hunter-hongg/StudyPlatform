import 'package:flutter/widgets.dart';
import 'package:study_platform/logic/trade.dart';
import 'package:study_platform/tool/random.dart';
import 'package:study_platform/vars/files.dart';

class Bank {
  static void store(BuildContext context, String storeNumRaw) {
    int storeNum = int.tryParse(storeNumRaw) ?? 0;
    Trade.trade(context, Files.jiFenReader(), Files.bankSReader(), "积分",
        storeNum, storeNum,
        route: '/bankpage/storepage');
  }

  static void get(BuildContext context, String getNumRaw) {
    int getNum = int.tryParse(getNumRaw) ?? 0;
    Trade.trade(context, Files.bankSReader(), Files.jiFenReader(), "存储积分",
        getNum, getNum,
        route: '/bankpage/getpage');
  }

  static void juan(BuildContext context, String juanJifenRaw) {
    int juanJifen = int.tryParse(juanJifenRaw) ?? 0;
    int getJuanQuan;
    if (juanJifen < 200) {
      getJuanQuan = 0;
    } else {
      getJuanQuan = 1 + (juanJifen ~/ 150) + RandomGet.getIntClosed(0, 1);
    }
    Trade.trade(context, Files.bankSReader(), Files.bankJReader(), "存储积分",
        juanJifen, getJuanQuan,
        route: '/bankpage/juanpage/realpage',
        customMessage: "兑换成功，获得$getJuanQuan捐献券");
  }

  static void juanToJif(BuildContext context, String juanRaw) {
    int juanUse = int.tryParse(juanRaw) ?? 0;
    int jifenGet = 200 * juanUse + RandomGet.getIntClosed(-100, 100);
    Trade.trade(context, Files.bankJReader(), Files.jiFenReader(), "捐献券",
        juanUse, jifenGet,
        route: '/bankpage/juanpage/jiangpage/jifenpage',
        customMessage: "兑换成功，获得$jifenGet积分");
  }
}
