# API文档-crate::macrodef::gen模块

## `macro_rules! bind_filepassword`
- 生成**FilePassword**的函数绑定
- 使用方法：`bind_filepassword![a, b];`
- 注意事项：
  1. `a`对应的函数为`crate::global::f::a_reader()`
  2. 生成函数为`a_readint()` `a_readstr()` `a_addnum`，均**自动导出**为tauri命令
  3. 宏已经使用`#[macro_export]`导出到`crate`
