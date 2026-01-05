# API文档-crate::domain::jifen

## `pub fn jifen_getlevel(jif: i32) -> Result<i32>`
- **从积分获取等级**
- 规则为起底`200`，每`150`增加一级
- 带**边界处理**（1级-100级）
- 返回`Result`类型需处理
