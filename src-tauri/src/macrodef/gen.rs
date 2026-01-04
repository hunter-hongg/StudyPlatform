//! 生成对应函数绑定

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