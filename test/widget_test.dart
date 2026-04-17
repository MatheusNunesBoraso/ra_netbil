import 'package:flutter_test/flutter_test.dart';

import 'package:ra_netbil/main.dart';

void main() {
  testWidgets('Home mostra coleções cadastradas', (WidgetTester tester) async {
    await tester.pumpWidget(const RaNetbilApp());
    expect(find.text('Realidade Aumentada'), findsOneWidget);
    expect(find.text('Prisma'), findsOneWidget);
    expect(find.text('Ativamente'), findsOneWidget);
    expect(find.text('Frisbee'), findsOneWidget);
    expect(find.text('Alcance'), findsOneWidget);
    expect(find.text('Calesita'), findsOneWidget);
  });
}
