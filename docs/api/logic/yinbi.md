# API文档-logic/yinbi.dart

## `class Yinbi`
- **银币兑换**统一处理类
- 所有方法均为**静态方法**

## `static void dealCard2(BuildContext context, int minus, Cards cp1, Cards cp2, String scp1, String scp2, int cp1100)`
- **购买两种卡牌**的处理方法
- `context`为构建时`context`
- `minus`为减少的**银币数**
- `cp1`为**可能获得**的第一种卡牌
- `cp2`为**可能获得**的第二种卡牌
- `scp1`为**第一种卡牌名称**
- `scp2`为**第二种卡牌名称**
- `cp1100`为**第一种卡牌获得概率**，传入`x`代表概率`x%`，第二种卡牌概率**自动推导**。不检查`cp1100`入参的**范围**。
