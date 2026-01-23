import 'dart:math';

/// 多项式类，表示形如 a_n*x^n + a_{n-1}*x^{n-1} + ... + a_1*x + a_0 的多项式
class Polynomial {
  /// 系数数组，coefficients[i] 是 x^i 的系数
  final List<double> coefficients;

  /// 通过系数数组构造多项式
  /// 例如：Polynomial([1, 2, 3]) 表示 3x² + 2x + 1
  Polynomial(List<double> coefficients)
      : coefficients = _normalize(coefficients);

  /// 零多项式
  Polynomial.zero() : coefficients = [0];

  /// 常数多项式
  Polynomial.constant(double c) : coefficients = [c];

  /// 一次多项式 (ax + b)
  Polynomial.linear(double a, double b) : coefficients = [b, a];

  /// 二次多项式 (ax² + bx + c)
  Polynomial.quadratic(double a, double b, double c) : coefficients = [c, b, a];

  /// 规范化系数数组（去除尾部多余的零，但保留至少一个元素）
  static List<double> _normalize(List<double> coeffs) {
    List<double> normalized = List.from(coeffs);

    // 移除尾部为零的系数，但至少保留一个系数
    while (normalized.length > 1 && normalized.last == 0) {
      normalized.removeLast();
    }

    return normalized;
  }

  /// 多项式的次数（最高次项的次数）
  int get degree => coefficients.length - 1;

  /// 获取指定次数的系数
  double coefficientAt(int power) {
    if (power < 0 || power >= coefficients.length) return 0;
    return coefficients[power];
  }

  /// 在点 x 处求值
  double evaluate(double x) {
    double result = 0;
    for (int i = coefficients.length - 1; i >= 0; i--) {
      result = result * x + coefficients[i];
    }
    return result;
  }

  /// 转换为字符串表示
  @override
  String toString() {
    if (coefficients.length == 1 && coefficients[0] == 0) {
      return "0";
    }

    final terms = <String>[];

    for (int i = coefficients.length - 1; i >= 0; i--) {
      final coeff = coefficients[i];

      if (coeff == 0) continue;

      String term;
      if (i == 0) {
        term = coeff.toString();
      } else if (i == 1) {
        term = coeff == 1 ? "x" : "${coeff}x";
      } else {
        term = coeff == 1 ? "x^$i" : "${coeff}x^$i";
      }

      if (terms.isNotEmpty && coeff > 0) {
        term = "+ $term";
      }

      terms.add(term);
    }

    return terms.join(" ").replaceAll("+ -", "- ");
  }

  /// 加法：this + other
  Polynomial operator +(Polynomial other) {
    final maxLength = max(coefficients.length, other.coefficients.length);
    final resultCoeffs = List<double>.filled(maxLength, 0);

    for (int i = 0; i < maxLength; i++) {
      final a = i < coefficients.length ? coefficients[i] : 0;
      final b = i < other.coefficients.length ? other.coefficients[i] : 0;
      resultCoeffs[i] = (a + b).toDouble();
    }

    return Polynomial(resultCoeffs);
  }

  /// 减法：this - other
  Polynomial operator -(Polynomial other) {
    final maxLength = max(coefficients.length, other.coefficients.length);
    final resultCoeffs = List<double>.filled(maxLength, 0);

    for (int i = 0; i < maxLength; i++) {
      final a = i < coefficients.length ? coefficients[i] : 0;
      final b = i < other.coefficients.length ? other.coefficients[i] : 0;
      resultCoeffs[i] = (a - b).toDouble();
    }

    return Polynomial(resultCoeffs);
  }

  /// 多项式乘法
  Polynomial operator *(Polynomial other) {
    final resultDegree = degree + other.degree;
    final resultCoeffs = List<double>.filled(resultDegree + 1, 0);

    for (int i = 0; i <= degree; i++) {
      for (int j = 0; j <= other.degree; j++) {
        resultCoeffs[i + j] += coefficients[i] * other.coefficients[j];
      }
    }

    return Polynomial(resultCoeffs);
  }

  /// 乘以标量
  Polynomial scalarMultiply(double scalar) {
    if (scalar == 0) return Polynomial.zero();

    final resultCoeffs = coefficients.map((c) => c * scalar).toList();
    return Polynomial(resultCoeffs);
  }

  /// 多项式除法，返回商和余数
  /// 返回 [商, 余数]
  List<Polynomial> divide(Polynomial divisor) {
    if (divisor.coefficients.length == 1 && divisor.coefficients[0] == 0) {
      throw ArgumentError("除数不能为零多项式");
    }

    if (degree < divisor.degree) {
      return [Polynomial.zero(), Polynomial(coefficients.toList())];
    }

    final dividend = coefficients.toList();
    final divisorCoeffs = divisor.coefficients;
    final divisorDegree = divisor.degree;
    final quotientDegree = degree - divisorDegree;

    final quotientCoeffs = List<double>.filled(quotientDegree + 1, 0);

    for (int i = quotientDegree; i >= 0; i--) {
      if (i + divisorDegree >= dividend.length) continue;

      final factor = dividend[i + divisorDegree] / divisorCoeffs.last;
      quotientCoeffs[i] = factor;

      for (int j = 0; j <= divisorDegree; j++) {
        if (i + j < dividend.length) {
          dividend[i + j] -= factor * divisorCoeffs[j];
        }
      }
    }

    // 余数的系数就是 dividend 中剩下的部分
    final remainderCoeffs = dividend.sublist(0, divisorDegree);

    return [Polynomial(quotientCoeffs), Polynomial(remainderCoeffs)];
  }

  /// 除法运算符（只返回商）
  Polynomial operator ~/(Polynomial divisor) {
    return divide(divisor)[0];
  }

  /// 求导
  Polynomial derivative() {
    if (coefficients.length == 1) {
      return Polynomial.zero();
    }

    final derivCoeffs = List<double>.filled(coefficients.length - 1, 0);
    for (int i = 1; i < coefficients.length; i++) {
      derivCoeffs[i - 1] = coefficients[i] * i;
    }

    return Polynomial(derivCoeffs);
  }

  /// 求积分（常数项为0）
  Polynomial integral() {
    final integCoeffs = List<double>.filled(coefficients.length + 1, 0);
    for (int i = 0; i < coefficients.length; i++) {
      integCoeffs[i + 1] = coefficients[i] / (i + 1);
    }

    return Polynomial(integCoeffs);
  }

  /// 判断是否相等
  @override
  bool operator ==(Object other) {
    if (identical(this, other)) return true;
    if (other is! Polynomial) return false;

    if (degree != other.degree) return false;

    for (int i = 0; i <= degree; i++) {
      if (coefficients[i] != other.coefficients[i]) {
        return false;
      }
    }

    return true;
  }

  @override
  int get hashCode =>
      coefficients.fold(0, (hash, coeff) => hash * 31 + coeff.hashCode);
}

/// 扩展方法：支持多项式与标量的运算
extension PolynomialScalarOperations on Polynomial {
  /// 多项式加标量（实际上是将标量视为常数多项式）
  Polynomial operator +(double scalar) => this + Polynomial.constant(scalar);

  /// 多项式减标量
  Polynomial operator -(double scalar) => this - Polynomial.constant(scalar);

  /// 多项式乘标量
  Polynomial operator *(double scalar) => scalarMultiply(scalar);
}

extension PolynomialBetterString on Polynomial {
  bool _isInt(double a) {
    return (a.toInt() - a <= 0.0000005);
  }

  String _doubleToString(double a) {
    if (_isInt(a)) {
      return a.toInt().toString();
    }
    return a.toString();
  }

  String toStringBetter() {
    if (coefficients.length == 1 && coefficients[0] == 0) {
      return "0";
    }

    final terms = <String>[];

    for (int i = coefficients.length - 1; i >= 0; i--) {
      final coeff = coefficients[i];

      if (coeff == 0) continue;

      String term;
      if (i == 0) {
        term = _doubleToString(coeff);
      } else if (i == 1) {
        if (coeff == 1) {
          term = "x";
        } else if (coeff == -1) {
          term = "- x";
        } else if (coeff > 0) {
          term = "${_doubleToString(coeff)}x";
        } else {
          term = "- ${_doubleToString(coeff)}x";
        }
      } else {
        if (coeff == 1) {
          term = "x^$i";
        } else if (coeff == -1) {
          term = "- x^$i";
        } else if (coeff > 0) {
          term = "${_doubleToString(coeff)}x^$i";
        } else {
          term = "- ${_doubleToString(coeff)}x^$i";
        }
      }

      if (terms.isNotEmpty && coeff > 0) {
        term = "+ $term";
      }

      terms.add(term);
    }

    return terms.join(" ").replaceAll("+ -", "- ");
  }
}
