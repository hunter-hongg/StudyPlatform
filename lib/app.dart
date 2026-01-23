import 'package:flutter/material.dart';
import 'package:flutter_riverpod/flutter_riverpod.dart';
import 'package:study_platform/pages/ancient_page/ancient_page.dart';
import 'package:study_platform/pages/bank_page/bank_page.dart';
import 'package:study_platform/pages/bank_page/store_page.dart';
import 'package:study_platform/pages/calc_page/calc_page.dart';
import 'package:study_platform/pages/calc_page/shop_page.dart';
import 'package:study_platform/pages/calc_page/start_page/addsub_page.dart';
import 'package:study_platform/pages/calc_page/start_page/div_page.dart';
import 'package:study_platform/pages/calc_page/start_page/poly_page.dart';
import 'package:study_platform/pages/calc_page/start_page/start_page.dart';
import 'package:study_platform/pages/calc_page/start_page/tim_page.dart';
import 'package:study_platform/pages/own_page/lihe_page.dart';
import 'package:study_platform/pages/own_page/thing_page/main_page/baoshi_page/baoshi_page.dart';
import 'package:study_platform/pages/own_page/thing_page/main_page/baoshi_page/chou_page/c1_page.dart';
import 'package:study_platform/pages/own_page/thing_page/main_page/baoshi_page/chou_page/chou_page.dart';
import 'package:study_platform/pages/own_page/thing_page/main_page/baoshi_page/get_page.dart';
import 'package:study_platform/pages/own_page/thing_page/main_page/card_page/card_page.dart';
import 'package:study_platform/pages/own_page/thing_page/main_page/card_page/han1_page.dart';
import 'package:study_platform/pages/own_page/thing_page/main_page/card_page/sang1_page.dart';
import 'package:study_platform/pages/own_page/thing_page/main_page/main_page.dart';
import 'package:study_platform/pages/own_page/thing_page/main_page/yinbi_page.dart';
import 'package:study_platform/pages/own_page/thing_page/shop_page.dart';
import 'package:study_platform/pages/own_page/thing_page/show_page.dart';
import 'package:study_platform/pages/own_page/thing_page/thing_page.dart';
import 'package:study_platform/pages/own_page/time_page.dart';
import 'package:study_platform/pages/own_page/tongy_page/jifen_page.dart';
import 'package:study_platform/pages/own_page/tongy_page/tongy_page.dart';
import 'package:study_platform/pages/util_page/util_page.dart';
import 'pages/home_page.dart';
import 'pages/own_page/own_page.dart';

class MyApp extends StatelessWidget {
  const MyApp({super.key});

  List<String> routes() {
    return [
      '/',
      '/apage',
      '/bankpage',
      '/bankpage/storepage',
      '/calcpage',
      '/calcpage/shoppage',
      '/calcpage/startpage',
      '/calcpage/startpage/addsubpage',
      '/calcpage/startpage/divpage',
      '/calcpage/startpage/polypage',
      '/calcpage/startpage/timpage',
      '/ownpage',
      '/ownpage/lihepage',
      '/ownpage/thingpage',
      '/ownpage/thingpage/mainpage',
      '/ownpage/thingpage/mainpage/baoshipage',
      '/ownpage/thingpage/mainpage/baoshipage/getpage',
      '/ownpage/thingpage/mainpage/baoshipage/cpage',
      '/ownpage/thingpage/mainpage/baoshipage/cpage/c1page',
      '/ownpage/thingpage/mainpage/cardpage',
      '/ownpage/thingpage/mainpage/cardpage/han1page',
      '/ownpage/thingpage/mainpage/cardpage/sang1page',
      '/ownpage/thingpage/mainpage/yinbipage',
      '/ownpage/thingpage/shoppage',
      '/ownpage/thingpage/showpage',
      '/ownpage/timepage',
      '/ownpage/tongypage',
      '/ownpage/tongypage/jifenpage',
      '/utilpage',
    ];
  }

  @override
  Widget build(BuildContext context) {
    return ProviderScope(
      child: MaterialApp(
        title: '学习平台',
        theme: ThemeData(
          primarySwatch: Colors.blue,
        ),
        initialRoute: '/',
        routes: {
          '/': (context) => HomePage(),
          '/apage': (context) => APage(),
          '/bankpage': (context) => BankPage(),
          '/bankpage/storepage': (context) => BankStorePage(),
          '/calcpage': (context) => CalcPage(),
          '/calcpage/shoppage': (context) => CalcShopPage(),
          '/calcpage/startpage': (context) => CalcStartPage(),
          '/calcpage/startpage/addsubpage': (context) => CalcAddsubPage(),
          '/calcpage/startpage/divpage': (context) => CalcDivPage(),
          '/calcpage/startpage/polypage': (context) => CalcPolyPage(),
          '/calcpage/startpage/timpage': (context) => CalcTimPage(),
          '/ownpage': (context) => OwnPage(),
          '/ownpage/lihepage': (context) => LihePage(),
          '/ownpage/thingpage': (context) => ThingPage(),
          '/ownpage/thingpage/mainpage': (context) => ThingMainPage(),
          '/ownpage/thingpage/mainpage/baoshipage': (context) =>
              ThingMainBaoshiPage(),
          '/ownpage/thingpage/mainpage/baoshipage/getpage': (context) =>
              ThingMainBaoshiGetPage(),
          '/ownpage/thingpage/mainpage/baoshipage/cpage': (context) =>
              ThingMainBaoshiChouPage(),
          '/ownpage/thingpage/mainpage/baoshipage/cpage/c1page': (context) =>
              ThingMainBaoshiChou1Page(),
          '/ownpage/thingpage/mainpage/cardpage': (context) =>
              ThingMainCardPage(),
          '/ownpage/thingpage/mainpage/cardpage/han1page': (context) =>
              ThingMainCardHan1Page(),
          '/ownpage/thingpage/mainpage/cardpage/sang1page': (context) =>
              ThingMainCardSang1Page(),
          '/ownpage/thingpage/mainpage/yinbipage': (context) =>
              ThingMainYinbiPage(),
          '/ownpage/thingpage/shoppage': (context) => ThingShopPage(),
          '/ownpage/thingpage/showpage': (context) => ThingShowPage(),
          '/ownpage/timepage': (context) => TimePage(),
          '/ownpage/tongypage': (context) => TongyPage(),
          '/ownpage/tongypage/jifenpage': (context) => TongyJifenPage(),
          '/utilpage': (context) => UtilPage(),
        },
      ),
    );
  }
}
