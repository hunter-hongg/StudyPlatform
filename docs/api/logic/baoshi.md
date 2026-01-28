# API文档-logic/baoshi.dart

## `class Baoshi`
- 统一**宝石**处理类
- 所有方法均为**静态方法**

## `static void get(BuildContext context, int jifenMinus, int baoshiAdd)`
- 获取宝石**处理方法**
- `jifenMinus`: 积分消耗
- `baoshiAdd`: 宝石增加
- **返回**: 无
- **使用**: `Baoshi.get(context, 10, 1);`

## `static String c1Rule()`
- 获取**宝石抽奖1兑换规则**
- **返回**: 规则字符串
  
## `static void c1Exec(BuildContext context)`
- 执行**宝石抽奖1**
- **返回**: 无
- **使用**: `Baoshi.c1Exec(context);`
