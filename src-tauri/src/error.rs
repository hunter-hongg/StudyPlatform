//! 错误相关类别

use serde::Serialize;
use thiserror::Error;

#[derive(Error, Debug, Serialize)]
pub enum SpError {
    #[error("无效的环境变量{0}")]
    NullEnvironment(String),

    #[error("文件操作错误{0}")]
    ErrorIO(String),

    #[error("其他错误")]
    OtherError,
}