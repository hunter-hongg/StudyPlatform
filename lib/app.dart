import 'package:flutter/material.dart';
import 'package:flutter_riverpod/flutter_riverpod.dart';
import 'package:study_platform/pages/calc_page/calc_page.dart';
import 'package:study_platform/pages/own_page/lihe_page.dart';
import 'package:study_platform/pages/own_page/thing_page/show_page.dart';
import 'package:study_platform/pages/own_page/thing_page/thing_page.dart';
import 'package:study_platform/pages/own_page/time_page.dart';
import 'pages/home_page.dart';
import 'pages/own_page/own_page.dart';

class MyApp extends StatelessWidget {
  const MyApp({super.key});

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
          '/calcpage': (context) => CalcPage(),
          '/ownpage': (context) => OwnPage(),
          '/ownpage/lihepage': (context) => LihePage(),
          '/ownpage/thingpage': (context) => ThingPage(),
          '/ownpage/thingpage/showpage': (context) => ThingShowPage(),
          '/ownpage/timepage': (context) => TimePage(),
        },
      ),
    );
  }
}
