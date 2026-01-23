# API文档-logic/trade.dart

## `class Trade`
- 交易抽象处理类**统一处理类**
- 方法均为**静态方法**

## `static void trade(BuildContext context, FilePassword fp1, FilePassword fp2, String thing1s, int thing1min, int thing2add, String? route)`
- 一对一**交易流程**
- `context`为构建时的`context`
- `fp1`为减少物品的`FilePassword`
- `fp2`为增加物品的`FilePassword`
- `thing1s`为减少物品的**名称**，在**物品不足**时会使用
- `thing1min`为减少物品减少的**数量**
- `thing2add`为增加物品增加的**数量**
- `route`为可选的**路由名称**，交易成功自动`Navigator.pushNamed`该路由
