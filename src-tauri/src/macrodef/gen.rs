//! 生成对应函数绑定

/// - 生成**FilePassword**的函数绑定
/// - 使用方法：`bind_filepassword![a, b];`
/// - 注意事项：
///   1. `a`对应的函数为`crate::global::f::a_reader()`
///   2. 生成函数为`a_readint()` `a_readstr()` `a_addnum`，均**自动导出**为tauri命令
#[macro_export]
macro_rules! bind_filepassword {
    // 批量生成版本
    ($($name:ident),*) => {
        $(
            paste::paste! {
                #[tauri::command]
                fn [<$name _readint>]() -> std::result::Result<i32, crate::error::SpError> {
                    let x = crate::global::f::[<$name _reader>]()?;
                    x.read_int()
                }
                #[tauri::command]
                fn [<$name _readstr>]() -> std::result::Result<String, crate::error::SpError> {
                    let x = crate::global::f::[<$name _reader>]()?;
                    x.read_str()
                }
                #[tauri::command]
                fn [<$name _addnum>](num: i32) -> std::result::Result<(), crate::error::SpError> {
                    let x = crate::global::f::[<$name _reader>]()?;
                    x.add_num(num)
                }
            }
        )*
    };
}