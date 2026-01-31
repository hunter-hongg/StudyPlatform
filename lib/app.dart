import 'package:flutter/material.dart';
import 'package:flutter_riverpod/flutter_riverpod.dart';
import 'package:study_platform/pages/pages.dart';

class MyApp extends StatelessWidget {
  const MyApp({super.key});

  List<String> routes() {
    return [
      '/',
      '/apage',
      '/apage/thingpage',
      '/apage/thingpage/caipage',
      '/bankpage',
      '/bankpage/getpage',
      '/bankpage/juanpage',
      '/bankpage/juanpage/jiangpage',
      '/bankpage/juanpage/jiangpage/jifenpage',
      '/bankpage/juanpage/realpage',
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
      '/settingpage',
      '/thingpage',
      '/thingpage/freepage',
      '/thingpage/jinpage',
      '/thingpage/mangpage',
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
          '/apage/thingpage': (context) => AThingPage(),
          '/apage/thingpage/caipage': (context) => AThingCaiPage(),
          '/bankpage': (context) => BankPage(),
          '/bankpage/getpage': (context) => BankGetPage(),
          '/bankpage/juanpage': (context) => BankJuanPage(),
          '/bankpage/juanpage/jiangpage': (context) => BankJuanJiangPage(),
          '/bankpage/juanpage/jiangpage/jifenpage': (context) =>
              BankJuanJiangJifPage(),
          '/bankpage/juanpage/realpage': (context) => BankJuanRealPage(),
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
          '/settingpage': (context) => SettingPage(),
          '/thingpage': (context) => TSPage(),
          '/thingpage/freepage': (context) => TSFreePage(),
          '/thingpage/jinpage': (context) => TSJinPage(),
          '/thingpage/mangpage': (context) => TSMangPage(),
          '/utilpage': (context) => UtilPage(),
        },
      ),
    );
  }
}
