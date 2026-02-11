# API文档-logic/awuzheng.dart 

## `enum Choices`
* **战争策略选择**枚举类型
* 包含四种战术选择：
  * `jinGong`: 进攻敌军
  * `xiuZheng`: 休整兵马  
  * `fangShou`: 防御敌军
  * `touXi`: 趁其不备

## 全局变量
* `aWuZhengMyBingl`: 我方兵力值（初始为-1）
* `aWuZhengOtherBingl`: 敌方兵力值（初始为-1）
* `aWuZhengUserChoice`: 用户选择历史记录列表

## `bool aWuZhengInitialize()`
* **初始化战争系统**
* 设置双方初始兵力值
* 我方兵力基于`AWuBing.bingSum()`计算
* 敌方兵力在我方基础上随机浮动(-30到30)，最低为30
* **返回值**: 初始化成功返回`true`，已初始化返回`false`

## `(int, int) aWuZhengGetResult(Choices a, Choices b)`
* **根据双方选择计算战斗结果**
* `a`: 我方选择
* `b`: 敌方选择
* **返回值**: 元组`(我方损失, 敌方损失)`，包含随机浮动值

## `Choices aWuZhengGetChoice(int other, int self, List<Choices> usrchoices)`
* **AI智能选择战术**
* `other`: 敌方兵力
* `self`: 我方兵力
* `usrchoices`: 用户历史选择记录
* **策略逻辑**:
  * 检测用户选择模式，进行针对性反制
  * 根据兵力差距选择不同战术组合
  * 包含随机因素增加不确定性

## `String aWuZhengToString(Choices ch)`
* **将枚举值转换为中文描述**
* `ch`: 战术选择枚举值
* **返回值**: 对应的中文战术名称

## `void aWuZhengDealWithChoice`
```dart
void aWuZhengDealWithChoice(
  BuildContext context,
  Choices evt,
  void Function() navigate,
) 
```
* **处理用户选择**
* `context`: 上下文
* `evt`: 用户选择
* `navigate`: 导航回调函数
* **逻辑**:
  * 更新用户选择历史记录
  * 计算双方损失
  * 更新双方兵力值
  * 判断游戏是否结束
  * 根据结果更新UI
  * 如果游戏结束，弹出提示框，并调用`navigate`进行导航
