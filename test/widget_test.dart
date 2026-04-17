import 'package:flutter_test/flutter_test.dart';

import 'package:ra_netbil/main.dart';

void main() {
  testWidgets('Home renders title and scan button', (WidgetTester tester) async {
    await tester.pumpWidget(const RaNetbilApp());
    expect(find.text('RA Netbil'), findsWidgets);
    expect(find.text('Escanear capa'), findsOneWidget);
  });
}
