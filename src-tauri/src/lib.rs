// Learn more about Tauri commands at https://tauri.app/develop/calling-rust/
pub mod env;   // 环境变量相关定义
pub mod error; // 错误相关类别

/// 获取**用户名**
/// 基于**env::get_env()**，使用方法相同
#[tauri::command]
fn env_get_user() -> Result<String, error::SpError> {
    env::get_env("USER")
}

#[cfg_attr(mobile, tauri::mobile_entry_point)]
pub fn run() {
    tauri::Builder::default()
        .plugin(tauri_plugin_opener::init())
        .invoke_handler(
            tauri::generate_handler![env_get_user]
        )
        .run(tauri::generate_context!())
        .expect("error while running tauri application");
}
