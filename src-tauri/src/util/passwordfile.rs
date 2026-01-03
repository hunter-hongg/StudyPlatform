//! 兼容的密码存取实现

use std::collections::HashSet;
use std::fs::{self, File};
use std::io::Write;
use std::path::Path;

const ORIGINAL: &str = "0123456789";

pub struct FilePassword {
    file_name: String,
    password: String,
}

impl FilePassword {
    /// 创建 FilePassword 实例，检查密码是否包含重复字符
    pub fn new(filename: &str, password: &str) -> Self {
        let validated_password = Self::validate_password(password);
        FilePassword {
            file_name: filename.to_string(),
            password: validated_password,
        }
    }

    /// 创建 FilePassword 实例，如果文件不存在则写入默认值
    pub fn new_with_default(
        filename: &str, 
        password: &str, 
        default_value: i32
    ) -> Result<Self, crate::error::SpError> {
        let fp = Self::new(filename, password);
        
        // 检查文件是否存在
        if !Path::new(filename).exists() {
            fp.write(default_value)?;
        }
        Ok(fp)
    }

    /// 验证密码是否包含重复字符
    fn validate_password(password: &str) -> String {
        let mut char_set = HashSet::new();
        for c in password.chars() {
            if char_set.contains(&c) {
                return "1324096857".to_string(); // 使用默认密码
            }
            char_set.insert(c);
        }
        password.to_string()
    }

    /// 字符转换辅助函数
    fn translate_char(c: char, from: &str, to: &str) -> Result<char, crate::error::SpError> {
        from.find(c)
            .and_then(|idx| to.chars().nth(idx))
            .ok_or_else(|| {
                crate::error::SpError::ErrorTranslation(
                    format!("character '{}' not found in mapping table", c)
                )
            })
    }

    /// 读取文件中的密码
    pub fn read_password(&self) -> Result<String, crate::error::SpError> {
        // 检查文件是否存在，不存在则创建
        if !Path::new(&self.file_name).exists() {
            let mut file = File::create(&self.file_name)
                .map_err(|e| crate::error::SpError::ErrorIO(format!("failed to create file: {}", e)))?;
            
            // 写入密码的第一个字符
            if let Some(first_char) = self.password.chars().next() {
                write!(file, "{}", first_char)
                    .map_err(|e| crate::error::SpError::ErrorIO(format!("failed to write to file: {}", e)))?;
            }
        }

        // 读取文件内容
        let content = fs::read_to_string(&self.file_name)
            .map_err(|e| crate::error::SpError::ErrorIO(format!("failed to read file: {}", e)))?;
        
        Ok(content.trim().to_string())
    }

    /// 将文件中的加密密码转换为真实数字
    pub fn read_real(&self) -> Result<String, crate::error::SpError> {
        let encrypted = self.read_password()?;
        
        let mut result = String::new();
        for c in encrypted.chars() {
            let translated = Self::translate_char(c, &self.password, ORIGINAL)?;
            result.push(translated);
        }
        Ok(result)
    }

    /// 将数字加密后写入文件
    pub fn write(&self, new_num: i32) -> Result<(), crate::error::SpError> {
        let num_str = new_num.to_string();
        let mut result = String::new();
        
        for c in num_str.chars() {
            match Self::translate_char(c, ORIGINAL, &self.password) {
                Ok(translated) => result.push(translated),
                Err(e) => return Err(crate::error::SpError::ErrorIO(
                    format!("invalid number format during translation: {}", e)
                )),
            }
        }

        let mut file = File::create(&self.file_name)
            .map_err(|e| crate::error::SpError::ErrorIO(format!("failed to create file for writing: {}", e)))?;
        
        file.write_all(result.as_bytes())
            .map_err(|e| crate::error::SpError::ErrorIO(format!("failed to write to file: {}", e)))?;
        
        Ok(())
    }

    /// 读取文件中的数字，加上指定值后再加密写入文件
    pub fn add(&self, num: i32) -> Result<(), crate::error::SpError> {
        let real_str = self.read_real()?;
        
        let current_num: i32 = real_str
            .parse()
            .map_err(|e| crate::error::SpError::ErrorIO(
                format!("failed to parse number from file: {}", e)
            ))?;
        
        let new_num = current_num + num;
        self.write(new_num)?;
        Ok(())
    }

    /// 读取存储数字返回 string
    pub fn read_str(&self) -> Result<String, crate::error::SpError> {
        let real_str = self.read_real()?;
        
        // 转换为数字再转回字符串，确保格式正确
        match real_str.parse::<i32>() {
            Ok(num) => Ok(num.to_string()),
            Err(e) => Err(crate::error::SpError::ErrorIO(
                format!("invalid number format: {}", e)
            )),
        }
    }

    /// 读取存储数字返回 i32
    pub fn read_int(&self) -> Result<i32, crate::error::SpError> {
        let real_str = self.read_real()?;
        
        real_str
            .parse()
            .map_err(|e| crate::error::SpError::ErrorIO(
                format!("failed to parse integer: {}", e)
            ))
    }

    /// 增加存储数字
    pub fn add_num(&self, a: i32) -> Result<(), crate::error::SpError> {
        if a < 0 {
            return Ok(()); // 负数不操作
        }
        self.add(a)
    }

    /// 减小存储数字，不检查是否为负数
    pub fn minus_num(&self, a: i32) -> Result<(), crate::error::SpError> {
        if a < 0 {
            return Ok(()); // 负数不操作
        }
        self.add(-a)
    }

    /// 减小存储数字，若不足则减至0
    pub fn minus_num_if(&self, a: i32) -> Result<(), crate::error::SpError> {
        if a < 0 {
            return Ok(());
        }

        let current = self.read_int()?;

        if current >= a {
            self.minus_num(a)
        } else {
            self.minus_num(current)
        }
    }

    /// 判断是否大于等于指定数字
    pub fn high(&self, a: i32) -> Result<bool, crate::error::SpError> {
        let current = self.read_int()?;
        Ok(current >= a)
    }

    /// 判断是否大于等于指定数字，若满足则减去，不满足则不变
    pub fn can_minus(&self, a: i32) -> Result<bool, crate::error::SpError> {
        if a < 0 {
            return Ok(false);
        }

        let is_high = self.high(a)?;

        if is_high {
            self.minus_num(a)?;
            Ok(true)
        } else {
            Ok(false)
        }
    }

    /// 安全的读取字符串版本（忽略错误）
    pub fn read_str_safe(&self) -> String {
        self.read_str().unwrap_or_default()
    }

    /// 安全的读取整数版本（忽略错误）
    pub fn read_int_safe(&self) -> i32 {
        self.read_int().unwrap_or(0)
    }

    /// 安全的 CanMinus 版本（忽略错误）
    pub fn can_minus_safe(&self, an: i32) -> bool {
        self.can_minus(an).unwrap_or(false)
    }
}