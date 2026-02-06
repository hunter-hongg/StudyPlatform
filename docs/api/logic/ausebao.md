# API文档-logic/ausebao.dart

## `class AUseBao`
* **宝物使用**统一处理类
* 所有方法均为**静态**方法

## `static void useBao`
```dart
static void useBao(
  BuildContext context, 
  MinusAble fp1, 
  AddAble fp2, 
  String thing1s, 
  int thing2add,
)
```
* **宝物卖出**统一处理方法
* `fp1`为卖出宝物的文件
* `fp2`为增加玉的文件
* `thing1s`为宝物名称
* `thing2add`为宝物卖出时增加多少玉
