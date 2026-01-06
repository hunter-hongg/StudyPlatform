//! 全局文件变量

use crate::{env::get_std, util::PasswordFile, error::Result};

pub fn jifen_reader() -> Result<PasswordFile> {
    let std = get_std()?;
    Ok(PasswordFile::new(&(std+"jifc.txt"), "hsiep10475"))
}
