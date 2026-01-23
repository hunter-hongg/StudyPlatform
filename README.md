# StudyPlatform学习平台
## 简介
* 学习平台是一个旨在让学习更加乐趣的项目，有优秀的跨平台GUI界面，使用Dart/Flutter开发。
* 目前主要支持Linux，Windows支持正在计划中，暂未计划macOS与移动端支持
## 安装
* 从Github Release页面下载安装
* 手动安装
  1. 安装`Flutter`工具链
  2. `git clone https://github.com/hunter-hongg/StudyPlatform && cd StudyPlatform` 克隆仓库
  3. `flutter doctor`检查依赖
  4. `flutter build linux --release`构建
  5. 手动复制`build/linux/x64/release/bundle`文件夹
## 使用
* 运行目录下的`study_platform`文件即可执行
## 数据存储
* Linux: `~/.store/学习平台储存/`
* 其他平台正在规划中
## 卸载
* 删除对应文件夹即可卸载
* 如不想保留数据，删除存储文件夹
