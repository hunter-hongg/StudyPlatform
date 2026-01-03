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
		return true
	}
	return false
}

func (of_ Oncefile) Use() error {
	_, err := of_.readFile()
	if os.IsNotExist(err) {
		fh, err2 := os.Create(of_.file)
		if err2 != nil {
			return err2
		}
		defer fh.Close()
		return nil
	}
	if err != nil {
		return err
	}
	return nil
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
