# CheckFile 类文档

## 简介
文件检查工具类，用于基于日期的次数限制管理。支持同步/异步操作，常用于签到、频率限制等场景。

## 快速开始
```dart
final checker = CheckFile(
  filePath: 'data/daily.txt',
  addNum: 0,     // 0=今天，1=明天，-1=昨天
  allTimes: 3,   // 每天最多3次
);

bool allowed = await checker.checkTimes(); // 异步
bool allowedSync = checker.checkTimesSync(); // 同步
```

## 核心方法

### 1. 次数检查
- `checkTimes()` / `checkTimesSync()` - 检查并记录
- 返回 `true` = 未达限制，已记录
- 返回 `false` = 已达限制或出错

### 2. 数据管理
- `readAllDates()` - 读取所有日期
- `clearFile()` - 清空文件（测试用）
- `getTodayDate()` - 静态方法，获取今日日期

## 文件格式
```
&20240101&20240101&20240102
```
- `&` 分隔符
- 日期为 `YYYYMMDD` 整数格式
- 示例：2024年1月1日有2次记录

## 参数说明
| 参数 | 说明 |
|------|------|
| `filePath` | 存储文件路径 |
| `addNum` | 日期偏移（天） |
| `allTimes` | 每日最大次数 |

## 使用场景
1. **每日签到**：`addNum: 0, allTimes: 1`
2. **次数限制**：`addNum: 0, allTimes: 5`（每天5次）
3. **预约检查**：`addNum: 1, allTimes: 10`（明天最多10个）

## 注意事项
- 文件不存在会自动创建
- 所有异常被捕获，返回 `false`
- 同步/异步功能一致，按需选用
- 适合小规模数据（全文件读取）

## 示例代码
```dart
// 签到系统
final signIn = CheckFile(
  filePath: 'data/sign_in.txt',
  addNum: 0,
  allTimes: 1,
);

if (await signIn.checkTimes()) {
  print("签到成功");
  awardPoints();
} else {
  print("今日已签到");
}
```