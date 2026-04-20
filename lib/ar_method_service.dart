import 'package:shared_preferences/shared_preferences.dart';

import 'ar_method.dart';

class ArMethodService {
  static const _key = 'ar_method';
  static const _default = ArMethod.original;

  static Future<ArMethod> get() async {
    final prefs = await SharedPreferences.getInstance();
    final stored = prefs.getString(_key);
    if (stored == null) return _default;
    return ArMethod.values.firstWhere(
      (m) => m.name == stored,
      orElse: () => _default,
    );
  }

  static Future<void> set(ArMethod method) async {
    final prefs = await SharedPreferences.getInstance();
    await prefs.setString(_key, method.name);
  }
}
