# API文档-crate::env模块

## `pub fn get_env(env: &str) -> Result<String>`
- 获取某个**环境变量**
- 使用方法：
    ```rust
    match get_env(""){
        Ok(val) => ..., 
        Err(val) => ...,
    }
    ```

## `pub fn get_user() -> Result<String>`
- 获取**用户名**
- 使用方法与`get_env`相同

## `pub fn get_std() -> Result<String> `
- 获取标准**数据存储路径**
- 使用方法与`get_env`相同
