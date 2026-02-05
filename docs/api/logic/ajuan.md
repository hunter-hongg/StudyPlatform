# API文档-logic/ajuan.dart

## `class Ajuan`
- 古玩捐献相关处理**统一类**
- 所有方法为**静态方法**

## `static int getLevel(int zhi)`
- 通过捐献值获取**等级**
- 入参为**捐献值**
- 返回对应的**等级**：
  - `0 <= zhi < 50` 返回 `1`
  - `50 <= zhi < 100` 返回 `2`
  - `100 <= zhi < 150` 返回 `3`
  - `150 <= zhi < 200` 返回 `4`
  - `zhi >= 200` 返回 `5`
  - 其他情况返回 `0`

## `static int getHuangj(int lev)`
- 通过等级获取**黄金奖励**
- 入参为**等级**
- 返回对应的**黄金数量**：
  - 等级 `0` 返回 `0`
  - 等级 `1` 返回 `10`
  - 等级 `2` 返回 `20`
  - 等级 `3` 返回 `35`
  - 等级 `4` 返回 `40`
  - 等级 `5` 返回 `55`
  - 其他等级返回 `10`

## `static void dealGuwan<T extends MinusAble>(BuildContext context, int yin, int zhi, String desc, T fp)`
- 处理**古玩捐献**交易
- `context`为构建时的`context`
- `yin`为消耗的**白银数量**
- `zhi`为获得的**捐献值**
- `desc`为**古玩描述**
- `fp`为古玩文件对象，需实现`MinusAble`接口
- 成功后会增加相应白银和捐献值，并显示成功提示
