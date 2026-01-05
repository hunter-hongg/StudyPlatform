# 工具链 [2026-1-3]

## 要求
- 这是项目最初的**工具链**，修改请按照**STANDARD.md**规范，计入**DECISION.md**并且拖延**至少4天**

## 具体工具链
- 开发环境: **Ubuntu Linux** 升级无需按照规范
- 版本控制：**Git**
- 编辑器：**VS Code**
- 版本控制增强：**LazyGit**+**GitKraken**
- 桌面：**GNOME Wayland**
- 框架：**Tauri**+**Vue**
- 颜色主题：**Horizon**
- 图标主题：**Seti-folder**
- 包管理器：**pnpm**+**cargo**
- 知识库：**Obsidian**
- 浏览器：**Firefox**或**Chromium**
- 主力语言：**Rust**+**TypeScript**+**Vue**

## 版本锁定（强制）
- **Node.js**: 20.x (LTS)
- **Rust**: 1.75+ (通过rust-toolchain.toml锁定)
- **Tauri**: ^2.0.0
- **Vue**: ^3.4.0
- **TypeScript**: ^5.3.0
- **Pinia**: ^2.1.0

## 更新策略
1. 依赖更新每月只进行一次（每月第一个非关键周六）
2. 更新前需运行完整测试套件并确保通过
3. 重大版本升级（如Vue 3.4→4.0）需按照决策规范