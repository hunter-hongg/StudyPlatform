package util

import (
	"bufio"
	"os"
)

type TFFile struct {
	file string
}

func NewTFFile(filename string) *TFFile {
	of := &TFFile{
		filename,
	}
	return of
}

func (of TFFile) SwitchTo(state bool) error {
	fptr, err := os.Create(of.file)
	if err != nil {
		return err 
	}
	if state {
		fptr.WriteString("True")
	} else {
		fptr.WriteString("False")
	}
	return nil
}

func (of TFFile) GetState(def bool) bool {
	res, err := of.readFile()
	if err != nil {
		return def
	}
	if res == "True" {
		return true
	}
	return false
}

func (of_ TFFile) readFile() (string, error) {
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
