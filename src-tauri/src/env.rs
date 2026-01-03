//! 环境变量相关定义

use std::env;
use crate::error::SpError;

/// 获取用户的用户名，用于前端显示
/// 使用方法：match get_user(){
///     Ok(val) => ..., 
///     Err(val) => ...,
/// }
pub fn get_user() -> Result<String, SpError> {
    match env::var("USER") {
        Ok(val) => Ok(val),
        Err(e) => Err(SpError::NullEnvironment(e.to_string()))
    }
}

#[cfg(test)] 
mod tests {
    use super::*;
    #[test]
    fn test_get_user() {
        // 本测试依赖用户名称
        // 我的用户名称为coding，故此处使用coding测试
        match get_user() {
            Ok(val) => assert_eq!(val, "coding"),
            Err(_) => panic!("获取USER时出现SpError错误"),
        }
    }
}