package util

import (
	"bufio"
	"os"
)

type Oncefile struct {
	file string
}

func NewOncefile(filename string) *Oncefile {
	of := &Oncefile{
		filename,
	}
	return of
}

func (of_ Oncefile) CheckTimes() bool {
	_, err := of_.readFile()
	if os.IsNotExist(err) {
		os.Create(of_.file)
		return true
	}
	return false
}

func (of_ Oncefile) readFile() (string, error) {
	file, err := os.Open(of_.file)
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
