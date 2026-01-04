use crate::{error::Result, util::PasswordFile};

// Learn more about Tauri commands at https://tauri.app/develop/calling-rust/
pub mod env;   // 环境变量相关定义
pub mod error; // 错误相关类别
pub mod util; // 工具模块
pub mod global; // 全局变量
pub mod macrodef; // 宏定义

bind_filepassword![jifen];

#[cfg_attr(mobile, tauri::mobile_entry_point)]
pub fn run() {
    tauri::Builder::default()
        .plugin(tauri_plugin_opener::init())
        .invoke_handler(
            tauri::generate_handler![
                env::get_env,
                env::get_user, 
                env::get_std,
                jifen_addnum, 
                jifen_readint,
                jifen_readstr,
            ], 
        )
        .run(tauri::generate_context!())
        .expect("error while running tauri application");
}
