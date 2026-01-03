//! 环境变量相关定义

use std::env;
use crate::error::SpError;

/// 获取某个环境变量
/// 使用方法：match get_env(){
///     Ok(val) => ..., 
///     Err(val) => ...,
/// }
pub fn get_env(env: &str) -> Result<String, SpError> {
    match env::var(env) {
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
        match get_env("USER") {
            Ok(val) => assert_eq!(val, "coding"),
            Err(_) => panic!("获取USER时出现SpError错误"),
        }
    }
    #[test]
    fn test_bad_get_user() {
        // 条件同上
        match get_env("USER") {
            Ok(val) => assert_ne!(val, "hunter-hongg"),
            Err(_) => panic!("获取USER时出现SpError错误"),
        }
    }
}