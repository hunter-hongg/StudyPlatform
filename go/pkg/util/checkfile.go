package util

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
	"time"
)

type CheckFile struct {
	file      string
	addNum    int
	allTimes  int
}

func NewCheckFile(file string, addNum int, allTimes int) *CheckFile {
	return &CheckFile{
		file:     file,
		addNum:   addNum,
		allTimes: allTimes,
	}
}

func (cf *CheckFile) CheckTimes() bool {
	return cf.check(cf.allTimes)
}

func (cf *CheckFile) check(num int) bool {
	if err := cf.ensureFileExists(); err != nil {
		return false
	}
	
	content, err := cf.readFile()
	if err != nil {
		return false
	}
	
	dates := cf.split(content, '&')
	targetDate := cf.getTargetDate()
	count := cf.countOccurrences(dates, targetDate)
	
	if count >= num {
		return false
	}
	
	if err := cf.appendDate(targetDate); err != nil {
		return false
	}
	
	return true
}

func (cf *CheckFile) ensureFileExists() error {
	file, err := os.OpenFile(cf.file, os.O_APPEND|os.O_CREATE|os.O_WRONLY, 0644)
	if err != nil {
		return err
	}
	defer file.Close()
	return nil
}

func (cf *CheckFile) readFile() (string, error) {
	file, err := os.Open(cf.file)
	if err != nil {
		return "", err
	}
	defer file.Close()
	
	scanner := bufio.NewScanner(file)
	if scanner.Scan() {
		return scanner.Text(), nil
	}
	return "", nil
}

func (cf *CheckFile) split(s string, delimiter rune) []int {
	if s == "" {
		return []int{}
	}
	
	parts := strings.Split(s, string(delimiter))
	var result []int
	
	for _, part := range parts {
		if part != "" {
			if num, err := strconv.Atoi(part); err == nil {
				result = append(result, num)
			}
		}
	}
	return result
}

func (cf *CheckFile) getTargetDate() int {
	now := time.Now()
	targetDate := now.AddDate(0, 0, cf.addNum)
	
	year := targetDate.Year()
	month := int(targetDate.Month())
	day := targetDate.Day()
	
	return year*10000 + month*100 + day
}

func (cf *CheckFile) countOccurrences(dates []int, targetDate int) int {
	count := 0
	for _, date := range dates {
		if date == targetDate {
			count++
		}
	}
	return count
}

func (cf *CheckFile) appendDate(date int) error {
	file, err := os.OpenFile(cf.file, os.O_APPEND|os.O_WRONLY, 0644)
	if err != nil {
		return err
	}
	defer file.Close()
	
	_, err = file.WriteString(fmt.Sprintf("&%d", date))
	return err
}
