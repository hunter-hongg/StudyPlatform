package xiansword

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

type SwordEnum int

const (
	Gold SwordEnum = iota
	Wood
	Water
	Fire
	Soil
)

func (s SwordEnum) String() string {
	switch s {
	case Gold:
		return "金剑"
	case Wood:
		return "木剑"
	case Water:
		return "水剑"
	case Fire:
		return "火剑"
	case Soil:
		return "土剑"
	default:
		return "未知剑"
	}
}

func SwordToString(enumA SwordEnum) string {
	return enumA.String()
}

type SwordException struct {
	msg string
}

func (s SwordException) Error() string {
	return s.msg
}

func NewSwordException(err string) SwordException {
	return SwordException{msg: err}
}

type SwordInFile struct {
	file string
}

func NewSwordInFile(file1 string) *SwordInFile {
	file := &SwordInFile{file: file1}
	file.ensureFileExists()
	return file
}

func (s *SwordInFile) ensureFileExists() {
	if _, err := os.Stat(s.file); os.IsNotExist(err) {
		file, err := os.Create(s.file)
		if err == nil {
			file.Close()
		}
	}
}

func (s *SwordInFile) Get() SwordEnum {
	data, err := os.ReadFile(s.file)
	if err != nil {
		return Gold
	}
	
	content := strings.TrimSpace(string(data))
	if content == "" {
		return Gold
	}
	
	tmp2, err := strconv.Atoi(content)
	if err != nil {
		return Gold
	}
	
	if tmp2 < 0 || tmp2 > 4 {
		return Gold
	}
	
	return SwordEnum(tmp2)
}

func (s *SwordInFile) Set(thing SwordEnum) error {
	tmp := int(thing)
	
	file, err := os.Create(s.file)
	if err != nil {
		return NewSwordException(fmt.Sprintf("无法创建文件: %v", err))
	}
	defer file.Close()
	
	_, err = file.WriteString(strconv.Itoa(tmp))
	if err != nil {
		return NewSwordException(fmt.Sprintf("写入文件失败: %v", err))
	}
	
	return nil
}