use crate::error::Result;

/// 从积分获取等级
/// 规则为起底200，每150增加一级
/// 带边界处理（1级-100级）
/// 返回Result类型需处理
#[tauri::command]
pub fn jifen_getlevel(jif: i32) -> Result<i32> {
	let default_level = (jif - 200) / 150;
	if default_level < 1 {
		Ok(1)
	} else if default_level > 100 {
		Ok(100)
	} else {
        Ok(default_level)
	}
}

#[cfg(test)]
mod tests {
	use super::*;

	#[test]
	fn test_getlevel() {
		match jifen_getlevel(0) {
			Ok(val) => assert_eq!(val, 1),
			Err(e) => panic!("{}", e),
		}
		match jifen_getlevel(500) {
			Ok(val) => assert_eq!(val, 2),
			Err(e) => panic!("{}", e),
		}
		match jifen_getlevel(100000) {
			Ok(val) => assert_eq!(val, 100),
			Err(e) => panic!("{}", e),
		}
	}
}