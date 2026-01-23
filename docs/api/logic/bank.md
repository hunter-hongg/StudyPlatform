# API文档-logic/bank.dart

## `class Bank`
- 积分银行**统一处理类**
- 所有方法均为**静态方法**

## `static void store(BuildContext context, String storeNumRaw)`
- **存储积分**处理方法
- `context`为构建时的`context`
- `storeNumRaw`为存储内容**读取的字符串**，函数会自动**解析字符串**

## `static void get(BuildContext context, String getNumRaw)`
- **获取积分**处理方法
- 参数**构造类似**

## `static void juan(BuildContext context, String juanJifenRaw)`
- **捐献积分**处理方法
- 参数**构造类似**

## `static void juanToJif(BuildContext context, String juanRaw)`
- **从捐献券到积分**处理方法
- 参数**构造类似**
