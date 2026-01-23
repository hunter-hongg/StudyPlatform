# API文档-logic/calc_poly.dart

## `class CalcPoly`
- **因式分解**统一**处理类**
- 所有方法**静态方法**

## `static Polynomial getRandomPoly()`
- `Polynomial`导入自`package:study_platform/tool/poly.dart`
- 生成并**返回与保存**随机多项式
- 次数固定为**四次**
- 反复调用**自动清空之前的**

## `static bool? userPoly(int zero, int one)`
- 获取**用户输入**因式
- 返回`null`表示未到达**指定次数**需要继续输入
- 返回非`null`表示到达**指定次数**，返回值为用户分解**是否正确**
- 返回`bool`会**自动清空**用户输入

## `static void clear()`
- 清空**用户输入的因式**

## `static bool _checkPoly()`
- 私有方法**不可调用**
- 判断**用户输入**是否正确
- `userPoly()`到达对应次数后**自动触发**
