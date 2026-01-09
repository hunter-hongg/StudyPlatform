# API文档-logic/jifen.dart

## `class Jifen`
- 积分相关处理**统一的类**
- 所有方法为**静态方法**

## `static int getLevel(int jif)`
- 通过积分获取**等级**
- 入参为**积分值**
- 如果入参`<350`返回`1`
- 否则返回`(jif-200)/150`取整
- 等级`>100`返回`100`
