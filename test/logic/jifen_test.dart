import 'package:study_platform/logic/jifen.dart';
import 'package:test/test.dart';

void main() {
  test("测试从积分获取等级", () {
    var dj1 = Jifen.getLevel(10);
    expect(dj1, 1);
    var dj2 = Jifen.getLevel(500);
    expect(dj2, 2);
    var dj3 = Jifen.getLevel(700000);
    expect(dj3, 100);
  });
}
