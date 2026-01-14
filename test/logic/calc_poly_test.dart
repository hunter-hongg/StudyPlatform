import 'package:flutter_test/flutter_test.dart';
import 'package:study_platform/logic/calc_poly.dart';
import 'package:study_platform/tool/poly.dart';

void main() {
  test('测试随机生成', () {
    var rnd = CalcPoly.getRandomPoly();
    print(rnd.toStringBetter());
    expect(rnd.degree, 4);
  });

  test('测试用户输入', () {
    CalcPoly.getRandomPoly();
    expect(CalcPoly.userPoly(1, 1), null);
    expect(CalcPoly.userPoly(1, 1), null);
    expect(CalcPoly.userPoly(1, 1), null);
    expect(CalcPoly.userPoly(1, 0), null);
    expect(CalcPoly.userPoly(1, 1), isNotNull);
  });
}
