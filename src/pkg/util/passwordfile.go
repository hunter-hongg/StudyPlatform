package util

import (
	"errors"
	"fmt"
	"os"
	"strconv"
	"strings"
)

const original = "0123456789"

type FilePassword struct {
	fileName string
	password string
}

// NewFilePassword 创建FilePassword实例，检查密码是否包含重复字符
func NewFilePassword(filename, password string) *FilePassword {
	fp := &FilePassword{
		fileName: filename,
		password: validatePassword(password),
	}
	return fp
}

// NewFilePasswordWithDefault 创建FilePassword实例，如果文件不存在则写入默认值
func NewFilePasswordWithDefault(filename, password string, defaultValue int) *FilePassword {
	fp := NewFilePassword(filename, password)
	
	// 检查文件是否存在
	if _, err := os.Stat(filename); os.IsNotExist(err) {
		fp.Write(defaultValue)
	}
	return fp
}

// validatePassword 验证密码是否包含重复字符
func validatePassword(password string) string {
	charSet := make(map[rune]bool)
	for _, c := range password {
		if charSet[c] {
			return "1324096857" // 使用默认密码
		}
		charSet[c] = true
	}
	return password
}

// translateChar 字符转换辅助函数
func translateChar(c byte, from, to string) (byte, error) {
	index := strings.IndexByte(from, c)
	if index == -1 {
		return 0, errors.New("character not found in mapping table")
	}
	return to[index], nil
}

// ReadPassword 读取文件中的密码
func (fp *FilePassword) ReadPassword() (string, error) {
	// 检查文件是否存在，不存在则创建
	if _, err := os.Stat(fp.fileName); os.IsNotExist(err) {
		file, err := os.Create(fp.fileName)
		if err != nil {
			return "", fmt.Errorf("failed to create file: %s", fp.fileName)
		}
		// 写入密码的第一个字符
		file.WriteString(string(fp.password[0]))
		file.Close()
	}

	// 读取文件内容
	content, err := os.ReadFile(fp.fileName)
	if err != nil {
		return "", fmt.Errorf("failed to open file: %s", fp.fileName)
	}

	return string(content), nil
}

// ReadReal 将文件中的加密密码转换为真实数字
func (fp *FilePassword) ReadReal() (string, error) {
	encrypted, err := fp.ReadPassword()
	if err != nil {
		return "", err
	}

	result := ""
	for _, c := range encrypted {
		translated, err := translateChar(byte(c), fp.password, original)
		if err != nil {
			return "", errors.New("error in character translation")
		}
		result += string(translated)
	}
	return result, nil
}

// Write 将数字加密后写入文件
func (fp *FilePassword) Write(newNum int) error {
	numStr := strconv.Itoa(newNum)
	result := ""
	for _, c := range numStr {
		translated, err := translateChar(byte(c), original, fp.password)
		if err != nil {
			return errors.New("invalid number format")
		}
		result += string(translated)
	}

	file, err := os.Create(fp.fileName)
	if err != nil {
		return fmt.Errorf("failed to open file for writing: %s", fp.fileName)
	}
	defer file.Close()

	_, err = file.WriteString(result)
	return err
}

// Add 读取文件中的数字，加上指定值后再加密写入文件
func (fp *FilePassword) Add(num int) error {
	realStr, err := fp.ReadReal()
	if err != nil {
		return errors.New("error reading real value")
	}

	currentNum, err := strconv.Atoi(realStr)
	if err != nil {
		return errors.New("invalid number in file")
	}

	newNum := currentNum + num
	return fp.Write(newNum)
}

// ReadStr 读取存储数字返回string
func (fp *FilePassword) ReadStr() (string, error) {
	realStr, err := fp.ReadReal()
	if err != nil {
		return "", err
	}
	
	// 转换为数字再转回字符串，确保格式正确
	if num, err := strconv.Atoi(realStr); err == nil {
		return strconv.Itoa(num), nil
	}
	return "", errors.New("invalid number format")
}

// ReadInt 读取存储数字返回int
func (fp *FilePassword) ReadInt() (int, error) {
	realStr, err := fp.ReadReal()
	if err != nil {
		return 0, err
	}
	return strconv.Atoi(realStr)
}

// AddNum 增加存储数字
func (fp *FilePassword) AddNum(a int) error {
	if a < 0 {
		return nil // 负数不操作
	}
	return fp.Add(a)
}

// MinusNum 减小存储数字，不检查是否为负数
func (fp *FilePassword) MinusNum(a int) error {
	if a < 0 {
		return nil // 负数不操作
	}
	return fp.Add(-a)
}

// MinusNumIf 减小存储数字，若不足则减至0
func (fp *FilePassword) MinusNumIf(a int) error {
	if a < 0 {
		return nil
	}

	current, err := fp.ReadInt()
	if err != nil {
		return err
	}

	if current >= a {
		return fp.MinusNum(a)
	} else {
		return fp.MinusNum(current)
	}
}

// High 判断是否大于等于指定数字
func (fp *FilePassword) High(a int) (bool, error) {
	current, err := fp.ReadInt()
	if err != nil {
		return false, err
	}
	return current >= a, nil
}

// CanMinus 判断是否大于等于指定数字，若满足则减去，不满足则不变
func (fp *FilePassword) CanMinus(a int) (bool, error) {
	if a < 0 {
		return false, nil
	}

	isHigh, err := fp.High(a)
	if err != nil {
		return false, err
	}

	if isHigh {
		err = fp.MinusNum(a)
		if err != nil {
			return false, err
		}
		return true, nil
	}
	return false, nil
}

func (fp *FilePassword) ReadStrSafe() string {
	str, _ := fp.ReadStr()
	return str
}
func (fp *FilePassword) ReadIntSafe() int {
	inte, _ := fp.ReadInt()
	return inte
}
