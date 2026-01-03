# API文档-crate::env模块

## `pub fn get_user() -> Result<String, SpError>`
- 获取用户的**用户名**，用于前端显示
- 使用方法：
    ```rust
    match get_user(){
        Ok(val) => ..., 
        Err(val) => ...,
    }
    ```
