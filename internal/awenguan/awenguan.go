package awenguan

import (
	"fmt"
	"io"
	"os"
	"strconv"
	"strings"
)

// AncientWenGuanConfig 结构体
type AncientWenGuanConfig struct {
	File   string
	AddNum int
}

func NewAncientWenGuanConfig(file string, an int) *AncientWenGuanConfig {
	ret := &AncientWenGuanConfig{
		File: file, 
		AddNum: an, 
	}
	ret.Create()
	return ret
}

// Create 创建文件（如果需要）
func (c *AncientWenGuanConfig) Create() error {
	_, err := os.OpenFile(c.File, os.O_RDWR|os.O_CREATE, 0644)
	return err
}

// ReadLevel 读取等级
func (c *AncientWenGuanConfig) ReadLevel() int {
	file, err := os.OpenFile(c.File, os.O_RDONLY, 0644)
	if err != nil {
		if os.IsNotExist(err) {
			// 文件不存在，创建并写入默认值
			newFile, err := os.Create(c.File)
			if err != nil {
				return 9
			}
			defer newFile.Close()
			
			content := strconv.Itoa(c.AddNum + 9)
			_, err = newFile.WriteString(content)
			if err != nil {
				return 9
			}
			return 9
		}
		return 9
	}
	defer file.Close()
	
	// 读取文件内容
	buffer := make([]byte, 16)
	n, err := file.Read(buffer)
	if err != nil && err != io.EOF {
		return 9
	}
	if n == 0 {
		return 9
	}
	
	// 解析内容
	content := strings.TrimSpace(string(buffer[:n]))
	readInt, err := strconv.Atoi(content)
	if err != nil {
		return 9
	}
	
	// 计算等级
	level := readInt - c.AddNum
	if level < 1 || level > 9 {
		return 9
	}
	
	return level
}

// NewLevel 设置新等级
func (c *AncientWenGuanConfig) NewLevel(newLevel int) error {
	file, err := os.Create(c.File)
	if err != nil {
		return err
	}
	defer file.Close()
	
	content := strconv.Itoa(c.AddNum + newLevel)
	_, err = file.WriteString(content)
	return err
}

// LevelUp 等级提升
func (c *AncientWenGuanConfig) LevelUp() error {
	currentLevel := c.ReadLevel()
	if currentLevel <= 1 || currentLevel > 9 {
		return fmt.Errorf("invalid current level: %d", currentLevel)
	}
	
	newLevel := currentLevel - 1
	return c.NewLevel(newLevel)
}

// LevelDown 等级降低
func (c *AncientWenGuanConfig) LevelDown() error {
	currentLevel := c.ReadLevel()
	if currentLevel < 1 || currentLevel >= 9 {
		return fmt.Errorf("invalid current level: %d", currentLevel)
	}
	
	newLevel := currentLevel + 1
	return c.NewLevel(newLevel)
}

// GetFengLu 获取俸禄
func (c *AncientWenGuanConfig) GetFengLu() int {
	level := c.ReadLevel()
	if level >= 6 {
		return (10 - level) * 5
	}
	return (10 - level) * 6
}
