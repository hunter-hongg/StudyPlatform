# BookChao API 文档

## 概述

BookChao 是一个用于处理书籍超功能的逻辑类，提供了计算需求和奖励的相关功能。

## 类定义

### BookChao

BookChao 类提供两个主要功能：

#### calcNeed()
计算需要的数值，返回包含 lv1、lv2、lv3、dj 和 hj 的 CalcNeedResult 对象。

- **功能**: 根据随机生成的 lv3 值，按照特定规则计算出 lv1、lv2、max、dj 和 hj 的值
- **返回值**: CalcNeedResult 对象，包含以下属性:
  - lv1: 第一级数值
  - lv2: 第二级数值
  - lv3: 第三级数值
  - dj: 等级值
  - hj: 获得值

**算法逻辑**:
- 生成 1-10 的随机数作为 lv3
- 根据 lv3 的大小范围分配不同的 lv2、max、dj、hj 值:
  - lv3 <= 1: lv2 = 1-2 随机数, max = 4, dj = 1, hj = 5
  - lv3 <= 2: lv2 = 1-2 随机数, max = 6, dj = 2, hj = 10
  - lv3 <= 5: lv2 = 2-4 随机数, max = 10, dj = 3, hj = 15
  - lv3 <= 7: lv2 = 2-5 随机数, max = 15, dj = 4, hj = 20
  - lv3 <= 10: lv2 = 3-6 随机数, max = 20, dj = 5, hj = 30
- 最终 lv1 = max - lv3 - lv2

#### calcGet(int dj)
根据 dj 值计算获得的数量。

- **参数**: dj - 等级值 (整数)
- **返回值**: 对应的奖励值 (整数)
- **逻辑**:
  - dj = 1: 返回 90
  - dj = 2: 返回 150
  - dj = 3: 返回 200
  - dj = 4: 返回 350
  - dj = 5: 返回 675
  - 其他值: 返回 -1

### CalcNeedResult

用于存储 calcNeed() 函数返回结果的类，包含 lv1、lv2、lv3、dj 和 hj 五个整数值。

## 依赖关系

- 依赖 [random.dart](StudyPlatform/lib/tool/random.dart) 中的 RandomGet 类，用于生成随机数