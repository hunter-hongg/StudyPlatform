//! 环境变量相关定义

use std::env;
use crate::error::{SpError, Result};

/// 获取某个环境变量
/// 使用方法：match get_env(){
///     Ok(val) => ..., 
///     Err(val) => ...,
/// }
#[tauri::command]
pub fn get_env(env: &str) -> Result<String> {
    match env::var(env) {
        Ok(val) => Ok(val),
        Err(e) => Err(SpError::NullEnvironment(e.to_string()))
    }
}

/// 获取用户名
/// 使用方法与get env相同
#[tauri::command]
pub fn get_user() ->  Result<String> {
    get_env("USER")
}

/// 获取标准数据存储路径
/// 使用方法与get_env相同
#[tauri::command]
pub fn get_std() -> Result<String> {
    match get_env("HOME") {
        Ok(val) => Ok(val+"/.store/学习平台储存/"),
        Err(e) => Err(e),
    }
}


#[cfg(test)] 
mod tests {
    use super::*;
    #[test]
    #[ignore = "环境不一致"]
    fn test_get_user() {
        // 本测试依赖用户名称
        // 我的用户名称为coding，故此处使用coding测试
        match get_user() {
            Ok(val) => assert_eq!(val, "coding"),
            Err(_) => panic!("获取USER时出现SpError错误"),
        }
    }
    #[test]
    #[ignore = "环境不一致"]
    fn test_bad_get_user() {
        // 条件同上
        match get_user() {
            Ok(val) => assert_ne!(val, "hunter-hongg"),
            Err(_) => panic!("获取USER时出现SpError错误"),
        }
    }
    #[test]
    #[ignore = "环境不一致"]
    fn test_get_std(){
        // 测试条件同上
        match get_std() {
            Ok(val) => assert_eq!(val, "/home/coding/.store/学习平台储存/"),
            Err(e) => panic!("{}", e),
        }
    }
}