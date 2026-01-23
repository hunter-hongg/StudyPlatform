# **Exec 类 API 文档**

## **类概述**
`Exec` 类是一个工具类，提供静态方法来定位和异步执行位于 Dart 应用程序 `external` 目录下的外部命令。所有方法均返回 `Future<int>` 类型，代表命令执行的退出码。

## **公有方法**

### **1. `exec` 方法**
执行一个不带参数的外部命令。

**签名**
```dart
static Future<int> exec(String name)
```

**参数**
- `name` (String): 要执行的外部命令文件的名称。

**返回值**
- `Future<int>`: 命令执行后的退出码。执行成功通常返回 `0`，若出现异常则返回 `-1`。

**示例**
```dart
int exitCode = await Exec.exec('my_script');
if (exitCode == 0) {
    print('命令执行成功。');
}
```

**异常**
- 当指定的外部命令文件不存在时，底层方法会抛出 `Exception`。

---

### **2. `run` 方法**
执行一个带有参数列表的外部命令，并继承当前进程的环境变量。

**签名**
```dart
static Future<int> run(String name, List<String> args)
```

**参数**
- `name` (String): 要执行的外部命令文件的名称。
- `args` (List<String>): 传递给命令的参数列表。

**返回值**
- `Future<int>`: 命令执行后的退出码。执行成功通常返回 `0`，若出现异常则返回 `-1`。

**示例**
```dart
int exitCode = await Exec.run('converter', ['input.txt', 'output.json']);
```

---

### **3. `proc` 方法**
执行一个带有自定义环境变量的外部命令。

**签名**
```dart
static Future<int> proc(String name, List<String> args, Map<String, String> env)
```

**参数**
- `name` (String): 要执行的外部命令文件的名称。
- `args` (List<String>): 传递给命令的参数列表。
- `env` (Map<String, String>): 自定义的环境变量键值对，将用于命令的执行环境。

**返回值**
- `Future<int>`: 命令执行后的退出码。执行成功通常返回 `0`，若出现异常则返回 `-1`。

**示例**
```dart
Map<String, String> customEnv = {'LANG': 'en_US.UTF-8', 'DEBUG': 'true'};
int exitCode = await Exec.proc('processor', ['--verbose'], customEnv);
```

## **私有方法说明**
- `_getCommandPath`: 根据当前 Dart 可执行文件的位置，在 `external` 子目录下构建并验证目标命令的完整路径。
- `_runCommand`: 核心执行逻辑，封装了 `Process.run`，负责调用命令并处理基础异常。

## **使用前提**
确保你的 Dart 应用程序发布或部署时，需要调用的外部命令文件已放置在正确位置：
`<你的应用根目录>/external/` 目录下。
