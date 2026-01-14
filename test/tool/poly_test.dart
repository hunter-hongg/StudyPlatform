import 'package:test/test.dart';
import 'package:study_platform/tool/poly.dart';

void main() {
  group('Polynomial 构造函数测试', () {
    test('从系数数组构造', () {
      // 3x² + 2x + 1
      final p = Polynomial([1, 2, 3]);
      expect(p.coefficients, equals([1, 2, 3]));
      expect(p.degree, equals(2));
    });

    test('规范化系数数组 - 去除尾部零', () {
      // 3x² + 2x + 1 + 0x³
      final p = Polynomial([1, 2, 3, 0, 0]);
      expect(p.coefficients, equals([1, 2, 3]));
      expect(p.degree, equals(2));
    });

    test('零多项式', () {
      final p = Polynomial.zero();
      expect(p.coefficients, equals([0]));
      expect(p.degree, equals(0));
      expect(p.toString(), equals('0'));
    });

    test('常数多项式', () {
      final p = Polynomial.constant(5);
      expect(p.coefficients, equals([5]));
      expect(p.degree, equals(0));
      expect(p.toString(), equals('5.0'));
    });

    test('一次多项式', () {
      final p = Polynomial.linear(2, -3); // 2x - 3
      expect(p.coefficients, equals([-3, 2]));
      expect(p.degree, equals(1));
      expect(p.toString(), equals('2.0x -3.0'));
    });

    test('二次多项式', () {
      final p = Polynomial.quadratic(1, 0, -4); // x² - 4
      expect(p.coefficients, equals([-4, 0, 1]));
      expect(p.degree, equals(2));
      expect(p.toString(), equals('x^2 -4.0'));
    });
  });

  group('多项式基本操作测试', () {
    test('获取系数', () {
      final p = Polynomial([1, 2, 3]); // 3x² + 2x + 1
      expect(p.coefficientAt(0), equals(1));
      expect(p.coefficientAt(1), equals(2));
      expect(p.coefficientAt(2), equals(3));
      expect(p.coefficientAt(3), equals(0)); // 越界返回0
      expect(p.coefficientAt(-1), equals(0)); // 负指数返回0
    });

    test('求值', () {
      final p = Polynomial([1, 2, 3]); // 3x² + 2x + 1
      expect(p.evaluate(0), equals(1));
      expect(p.evaluate(1), equals(6));
      expect(p.evaluate(2), equals(17));
      expect(p.evaluate(-1), equals(2));
    });

    test('转换为字符串', () {
      expect(Polynomial([0]).toString(), equals('0'));
      expect(Polynomial([5]).toString(), equals('5.0'));
      expect(Polynomial([-5]).toString(), equals('-5.0'));
      expect(Polynomial([1, 1]).toString(), equals('x + 1.0')); // x + 1
      expect(Polynomial([1, -1]).toString(), equals('-1.0x + 1.0')); // -x + 1
      expect(Polynomial([0, 2]).toString(), equals('2.0x')); // 2x
      expect(Polynomial([1, 2, 3]).toString(), equals('3.0x^2 + 2.0x + 1.0'));
      expect(Polynomial([-1, 2, -3]).toString(), equals('-3.0x^2 + 2.0x -1.0'));
      expect(Polynomial([0, 0, 1]).toString(), equals('x^2')); // x²
      expect(Polynomial([9, 1, 0, 5, -1]).toStringBetter(), equals("- x^4 + 5x^3 + x + 9"));
    });
  });

  group('多项式算术运算测试', () {
    test('加法', () {
      final p1 = Polynomial([1, 2, 3]); // 3x² + 2x + 1
      final p2 = Polynomial([4, 5]); // 5x + 4

      final sum = p1 + p2; // 3x² + 7x + 5
      expect(sum.coefficients, equals([5, 7, 3]));

      // 不同长度的多项式相加
      final p3 = Polynomial([1]); // 1
      final p4 = Polynomial([0, 2, 3]); // 3x² + 2x
      final sum2 = p3 + p4; // 3x² + 2x + 1
      expect(sum2.coefficients, equals([1, 2, 3]));
    });

    test('减法', () {
      final p1 = Polynomial([5, 3, 2]); // 2x² + 3x + 5
      final p2 = Polynomial([1, 2]); // 2x + 1

      final diff = p1 - p2; // 2x² + x + 4
      expect(diff.coefficients, equals([4, 1, 2]));

      // 产生零多项式
      final p3 = Polynomial([1, 2, 3]);
      final p4 = Polynomial([1, 2, 3]);
      final diff2 = p3 - p4;
      expect(diff2.coefficients, equals([0]));
    });

    test('乘法', () {
      final p1 = Polynomial([1, 1]); // x + 1
      final p2 = Polynomial([1, 1]); // x + 1

      final product = p1 * p2; // x² + 2x + 1
      expect(product.coefficients, equals([1, 2, 1]));

      // 乘以常数多项式
      final p3 = Polynomial([2, 3]); // 3x + 2
      final constant = Polynomial.constant(2); // 2
      final product2 = p3 * constant; // 6x + 4
      expect(product2.coefficients, equals([4, 6]));

      // 乘以零多项式
      final zero = Polynomial.zero();
      final product3 = p3 * zero;
      expect(product3.coefficients, equals([0]));
    });

    test('乘以标量', () {
      final p = Polynomial([1, 2, 3]); // 3x² + 2x + 1

      final scaled = p.scalarMultiply(2); // 6x² + 4x + 2
      expect(scaled.coefficients, equals([2, 4, 6]));

      final scaledByZero = p.scalarMultiply(0);
      expect(scaledByZero.coefficients, equals([0]));

      final scaledByNegative = p.scalarMultiply(-1); // -3x² - 2x - 1
      expect(scaledByNegative.coefficients, equals([-1, -2, -3]));
    });
  });

  group('多项式除法测试', () {
    test('整除情况', () {
      // (x² + 2x + 1) ÷ (x + 1) = x + 1
      final dividend = Polynomial([1, 2, 1]); // x² + 2x + 1
      final divisor = Polynomial([1, 1]); // x + 1

      final result = dividend.divide(divisor);
      final quotient = result[0]; // x + 1
      final remainder = result[1]; // 0

      expect(quotient.coefficients, equals([1, 1]));
      expect(remainder.coefficients, equals([0]));
    });

    test('不整除情况', () {
      // (x³ + 2x² + 3x + 4) ÷ (x + 1) = x² + x + 2 余 2
      final dividend = Polynomial([4, 3, 2, 1]); // x³ + 2x² + 3x + 4
      final divisor = Polynomial([1, 1]); // x + 1

      final result = dividend.divide(divisor);
      final quotient = result[0]; // x² + x + 2
      final remainder = result[1]; // 2

      expect(quotient.coefficients, equals([2, 1, 1]));
      expect(remainder.coefficients, equals([2]));
    });

    test('被除数次数小于除数', () {
      // (x + 1) ÷ (x² + 1) = 0 余 (x + 1)
      final dividend = Polynomial([1, 1]); // x + 1
      final divisor = Polynomial([1, 0, 1]); // x² + 1

      final result = dividend.divide(divisor);
      final quotient = result[0]; // 0
      final remainder = result[1]; // x + 1

      expect(quotient.coefficients, equals([0]));
      expect(remainder.coefficients, equals([1, 1]));
    });

    test('除法运算符 ~/', () {
      final dividend = Polynomial([1, 2, 1]); // x² + 2x + 1
      final divisor = Polynomial([1, 1]); // x + 1

      final quotient = dividend ~/ divisor; // x + 1
      expect(quotient.coefficients, equals([1, 1]));
    });

    test('除数为零多项式 - 异常', () {
      final dividend = Polynomial([1, 2, 3]);
      final zero = Polynomial.zero();

      expect(() => dividend.divide(zero), throwsArgumentError);
    });
  });

  group('微积分运算测试', () {
    test('求导', () {
      // 3x² + 2x + 1 的导数是 6x + 2
      final p = Polynomial([1, 2, 3]);
      final derivative = p.derivative();
      expect(derivative.coefficients, equals([2, 6]));

      // 常数多项式的导数是0
      final constant = Polynomial.constant(5);
      expect(constant.derivative().coefficients, equals([0]));

      // 零多项式的导数是0
      final zero = Polynomial.zero();
      expect(zero.derivative().coefficients, equals([0]));
    });
  });

  group('相等性和哈希码测试', () {
    test('相等性', () {
      final p1 = Polynomial([1, 2, 3]);
      final p2 = Polynomial([1, 2, 3]);
      final p3 = Polynomial([1, 2, 4]);
      final p4 = Polynomial([1, 2, 3, 0]); // 被规范化后与 p1 相同

      expect(p1 == p2, isTrue);
      expect(p1 == p3, isFalse);
      expect(p1 == p4, isTrue);
    });

    test('哈希码', () {
      final p1 = Polynomial([1, 2, 3]);
      final p2 = Polynomial([1, 2, 3]);
      final p3 = Polynomial([1, 2, 4]);

      expect(p1.hashCode, equals(p2.hashCode));
      expect(p1.hashCode, isNot(equals(p3.hashCode)));
    });
  });
}
