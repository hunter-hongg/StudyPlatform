import 'package:flutter/material.dart';
import 'package:flutter_riverpod/flutter_riverpod.dart';
import 'pages/home_page.dart';

class MyApp extends StatelessWidget {
  const MyApp({super.key});

  @override
  Widget build(BuildContext context) {
    return ProviderScope( // Riverpod全局容器
      child: MaterialApp(
        title: 'Minimal Counter',
        home: HomePage(),
      ),
    );
  }
}