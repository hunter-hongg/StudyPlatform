# 例外情况管理

## 已修复

## 已接受

### src-tauri/src/macrodef/gen.rs:8 - 编码规范Rust第5条
**日期**: 2026-01-04
**违反规则**: STANDARD.md 编码规范Rust第5条
**详细原因**: 生成宏时，clippy提醒使用`$crate`表示定义宏的`crate`，但是我想表达的是使用宏的`crate`，因此直接使用`crate`而不是`$crate`
**解决方案**: 略
**预计修复时间**: 略
**负责人**: hunter-hongg

## 待修复
