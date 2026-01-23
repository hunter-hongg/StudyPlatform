# API文档-logic/tongy.dart

## `enum TongyReturn`
- 返回值**定义枚举**
- 完整定义: 
```dart
enum TongyReturn {
  success,
  userErr,
  systemErr,
  otherErr,
}
```

## `class Tongy`
- 通用货币**统一处理类**
- 都是**静态方法**

## `static List<(int, int, String, FilePassword)> get _rule`
- 获取**兑换规则**
- 私有方法

## `static List<(int, int, String, FilePassword)> get rules`
- 获取**兑换规则**
- 公有方法

## `static String getRule()`
- 获取**格式化后**的交换规则
- 返回**字符串**

## `static int dealRule(BuildContext context, String type, String gets)`
- 执行**兑换规则**
- 从**物品**兑换到**通用货币**
- **context**为构建的**context**
- **type**为规则名，不存在返回`-1`
- **gets**为增加的**通用货币**
- 如果**物品不足**或**gets解析失败**返回`-2`
- 正常情况返回`0`

## `extension ToTongyReturn on int`
- 为**int**类型写的**转换方法**
- 从**int**转换到**TongyReturn**

## `TongyReturn toTongyReturn()`
- 真正的**转换方法**
- `-1`转为**systemErr**
- `-2`转为**userErr**
- `0`转为**success**
- 其他转为**otherErr**
