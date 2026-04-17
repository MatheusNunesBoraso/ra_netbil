import 'package:flutter/material.dart';

import 'home_page.dart';

void main() {
  runApp(const RaNetbilApp());
}

class RaNetbilApp extends StatelessWidget {
  const RaNetbilApp({super.key});

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'RA Netbil',
      debugShowCheckedModeBanner: false,
      theme: ThemeData(
        colorScheme: ColorScheme.fromSeed(seedColor: const Color(0xFF6366F1)),
        useMaterial3: true,
      ),
      home: const HomePage(),
    );
  }
}
