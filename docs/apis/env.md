# API文档-crate::env模块

## `pub fn get_env(env: &str) -> Result<String, SpError>`
- 获取某个**环境变量**
- 使用方法：
    ```rust
    match get_env(""){
        Ok(val) => ..., 
        Err(val) => ...,
    }
    ```

## `fn env_get_user() -> Result<String, error::SpError>`
- 获取**用户名**
- 基于**env::get_env()**，使用方法相同
