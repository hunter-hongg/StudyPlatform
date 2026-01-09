# API文档-logic/env_mod.dart

## `class EnvMod`
- 所有**环境相关**变量获取处
- 所有方法**都是静态方法**无需创建对象

## `static String getUser()`
- EnvMod类静态方法
- 获取用户**用户名**
- 实质获取`USER`环境变量
- 若不存在返回**空字符串**

## `static String getHome()`
- EnvMod类静态方法
- 获取用户**家目录**
- 实质获取`HOME`环境变量
- 若不存在返回`/home/$user`其中`user`为`getUser()`函数返回值

## `static String getStdpath()`
- EnvMod类静态方法
- 获取数据**存储根目录**
- 实质返回`$home/.store/学习平台储存/`其中`home`为`getHome()`函数返回值
