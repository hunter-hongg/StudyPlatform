import 'package:study_platform/tool/poly.dart';
import 'package:study_platform/tool/random.dart';

class CalcPoly {
  static Polynomial _polyres = Polynomial.constant(1);
  static Polynomial _randompoly = Polynomial.zero();

  Polynomial get randompoly => _randompoly;

  static Polynomial getRandomPoly() {
    var tpoly = Polynomial.constant(1);
    for (int i = 0; i < 4; i++) {
      double rnd1 = RandomGet.getIntClose(1, 9).toDouble();
      double rnd2 = RandomGet.getIntClose(1, 9).toDouble();
      tpoly *= Polynomial([rnd1, rnd2]);
    }
    _randompoly = tpoly;
    return tpoly;
  }

  static void clear() {
    _polyres = Polynomial.constant(1);
  }

  static bool? userPoly(int zero, int one) {
    _polyres *= Polynomial([zero.toDouble(), one.toDouble()]);
    if (_polyres.degree >= 4) {
      var res = _checkPoly();
      clear();
      return res;
    }
    return null;
  }

  static bool _checkPoly() {
    if (_randompoly.degree < 4) {
      return false;
    }
    return (_polyres == _randompoly);
  }
}
