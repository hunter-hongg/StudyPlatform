# API文档-logic/apao.dart

## `enum Pao`
- 袍子类型枚举定义
- 包含以下类型：
  - green (0, '青袍')
  - red (1, '赤袍') 
  - purple (2, '紫袍')
  - black (3, '黑袍')
  - white (4, '白袍')
  - realRed (5, '红袍')
  - blue (6, '蓝袍')
  - silver (7, '银袍')

## `class AncientPao`
- 古代袍子管理系统的核心类
- 管理当前袍子状态和所有已解锁袍子记录

### 构造函数
```dart
AncientPao(String paonow, String paoall)
```
- **paonow**: 当前袍子状态文件路径
- **paoall**: 所有袍子解锁记录文件路径

### `Pao getNow()`
- 获取当前袍子类型
- **返回值**: Pao 枚举类型的当前袍子
- **说明**: 调用 readNow() 方法读取当前袍子状态

### `List<Pao> getAll()`
- 获取所有已解锁的袍子类型
- **返回值**: Pao 枚举类型的列表
- **说明**: 调用 readAll() 方法读取所有解锁袍子记录

### `Pao readNow()`
- 读取当前袍子状态
- **返回值**: Pao 枚举类型的袍子
- **说明**: 
  - 如果文件不存在会自动创建
  - 文件为空或读取失败时返回 Pao.green
  - 数值超出范围时返回 Pao.green

### `List<Pao> readAll()`
- 读取所有已解锁的袍子
- **返回值**: Pao 枚举类型的列表
- **说明**:
  - 自动去除重复项
  - 如果文件不存在会自动创建
  - 文件为空或读取失败时返回 [Pao.green]
  - 解析失败的数值会使用默认值 Pao.green

### `int change(Pao newPao)`
- 更改当前袍子为新的袍子
- **参数**: newPao - 要设置的新袍子类型
- **返回值**: 
  - 0 表示成功
  - 1 表示失败（新袍子未解锁）
- **说明**: 只能切换到已解锁的袍子类型

### `void add(Pao addPao)`
- 添加一个新的袍子到解锁列表
- **参数**: addPao - 要添加的袍子类型
- **说明**: 
  - 将新袍子添加到解锁记录文件中
  - 文件不存在时会创建新文件
  - 写入失败时不抛出异常

## `AncientPao createAncientPao(String nowFilePath, String allFilePath)`
- 工厂方法创建 AncientPao 实例
- **参数**:
  - nowFilePath: 当前袍子状态文件路径
  - allFilePath: 所有袍子解锁记录文件路径
- **返回值**: AncientPao 实例

## 依赖关系
- 依赖 `dart:io` 包进行文件操作
- 使用 File 类进行文件读写操作
- 采用同步文件操作方式