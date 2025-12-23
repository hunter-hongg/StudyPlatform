package util

import (
	"bufio"
	"os"
	"strconv"
)

type AddFile struct {
	file string
	addnum int
}

func NewAddFile(filename string, addnum int) *AddFile {
	of := &AddFile{
		filename,
		addnum,
	}
	return of
}

func (of_ AddFile) readFile() (string, error) {
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

func (of_ AddFile) ReadInt() int {
	raw, err := of_.readFile() 
	if err != nil {
		return 0
	}
	res, err := strconv.Atoi(raw)
	if err != nil {
		return 0
	}
	res -= of_.addnum
	return res
}

func (of_ AddFile) ReadStr() string {
	return strconv.Itoa(of_.ReadInt())
}
