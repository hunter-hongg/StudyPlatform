# API文档-logic/state.dart

## `class StateDealing`
- 统一**状态**处理类
- 所有方法均为**静态方法**

## `static void dealState(BuildContext context, StateFile fp, bool def, void Function() func, String elseShow)`
- 处理状态的**具体方法**
- `fp`为目标状态文件
- `def`为**默认状态**，即**没有状态文件**时的状态
- `func`为**状态文件**存在时的状态
- `elseShow`为**状态文件**不存在时的状态
- **注意**：`elseShow`为**字符串**，请使用**单引号**
