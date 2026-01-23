# API文档-logic/othing_shop.md

## `class OthingShop`
- 物品商城**统一处理类**
- 都是**静态方法**

## `static void deal(BuildContext context, int jifenMin, FilePassword fp, int addNum)`
- 物品商城**普通购买**处理方法
- **context**为**build**函数入参
- **jifenMin**为减少的积分
- **fp**为增加物品的**文件变量**
- **addNum**为增加数量

## `static void dealCard(BuildContext context, int jifenMin, Cards cp, int addNum)`
- 物品商城**卡牌购买**处理方法
- **context**为**build**函数入参
- **jifenMin**为减少的积分
- **fp**为增加卡牌的**文件变量**
- **addNum**为增加卡牌数量
- 增加的卡牌**保证不重叠**但**不保证与现有卡牌不重叠**
