# API文档-logic/trade.dart

## `class Trade`

- 交易抽象处理类**统一处理类**
- 方法均为**静态方法**

## `static void trade`

```dart
static void trade(
  BuildContext context,
  FilePassword fp1,
  FilePassword fp2,
  String thing1s,
  int thing1min,
  int thing2add,
  {
  String? route,
  String? customMessage,
  })
```

- 一对一**交易流程**
- `context`为构建时的`context`
- `fp1`为减少物品的`FilePassword`
- `fp2`为增加物品的`FilePassword`
- `thing1s`为减少物品的**名称**，在**物品不足**时会使用
- `thing1min`为减少物品减少的**数量**
- `thing2add`为增加物品增加的**数量**
- `route`为可选的**路由名称**，交易成功自动`Navigator.pushNamed`该路由
- `customMessage`为可选的**消息显示**，默认为`"兑换成功"`

## `static void tradeCheck`
```dart
static void tradeCheck(
  BuildContext context,
  FilePassword fp,
  CheckFile cp,
  int addnum, 
  {
  String? route,
  String customMessage = "兑换成功",
  }) 
```
- 零对一**获取物品流程**，**检查限次数文件**
- `context`为构建时的`context`
- `fp`为增加物品的`FilePassword`
- `cp`为检查限次数的`CheckFile`
- `addnum`为增加物品增加的**数量**
- `route`为可选的**路由名称**，交易成功自动`Navigator.pushNamed`该路由
- `customMessage`为可选的**消息显示**，默认为`"兑换成功"`

## `static void tradeFunc`

```dart
static void tradeFunc(
  BuildContext context,
  FilePassword fp,
  String thing1s,
  int thing1min,
  void Function() func,
) 
```

- 一对一**交易流程**，**自定义函数**
- `context`为构建时的`context`
- `fp`为减少物品的`FilePassword`
- `thing1s`为减少物品的**名称**，在**物品不足**时会使用
- `thing1min`为减少物品减少的**数量**
- `func`为自定义的**处理函数**

## `static void tradeAdd`
```dart
static void tradeAdd(
  BuildContext context,
  FilePassword fp1,
  AddFile fp2,
  String thing1s,
  int thing1min,
  int thing2add, {
  String? route,
  String? customMessage,
}) 
```
- 一对一**交易流程**，增加物品为`AddFile`
- 参数与`trade`一致

## `static void tradePAdd`
```dart
static void tradePAdd(
  BuildContext context,
  AddFile fp1,
  FilePassword fp2,
  String thing1s,
  int thing1min,
  int thing2add, {
  String? route,
  String? customMessage,
}) 
```
- 一对一**交易流程**，减少物品为`AddFile`
- 参数与`trade`一致

## `static void tradeF`
```dart
static void tradeF<T extends MinusAble, U extends AddAble>(
  BuildContext context,
  T fp1,
  U fp2,
  String thing1s,
  int thing1min,
  int thing2add, {
  String? route,
  String? customMessage,
})
```
- 泛型**交易流程**，支持任意减法和加法类型
- `context`为构建时的`context`
- `fp1`为减少物品的对象，需实现`MinusAble`接口
- `fp2`为增加物品的对象，需实现`AddAble`接口
- `thing1s`为减少物品的**名称**，在**物品不足**时会使用
- `thing1min`为减少物品减少的**数量**
- `thing2add`为增加物品增加的**数量**
- `route`为可选的**路由名称**，交易成功自动`Navigator.pushNamed`该路由
- `customMessage`为可选的**消息显示**，默认为`"兑换成功"`

## `static void tradeFFunc`
```dart
static void tradeFFunc<T extends MinusAble>(
  BuildContext context,
  T fp1,
  String thing1s,
  int thing1min,
  void Function() func,
)
```
- 泛型**交易流程**，**自定义函数**，支持任意减法类型
- `context`为构建时的`context`
- `fp1`为减少物品的对象，需实现`MinusAble`接口
- `thing1s`为减少物品的**名称**，在**物品不足**时会使用
- `thing1min`为减少物品减少的**数量**
- `func`为自定义的**处理函数**
