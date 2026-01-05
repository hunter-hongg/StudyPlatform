//! 错误相关类别

use serde::Serialize;
use thiserror::Error;

/// 统一错误类型
#[derive(Error, Debug, Serialize)]
pub enum SpError {
    #[error("无效的环境变量{0}")]
    NullEnvironment(String),

    #[error("文件操作错误{0}")]
    ErrorIO(String),

    #[error("Translation error: {0}")]
    ErrorTranslation(String),

    #[error("其他错误")]
    OtherError,
}

/// Result类型别名
pub type Result<T> = std::result::Result<T, SpError>;