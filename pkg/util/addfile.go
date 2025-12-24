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

func (of_ AddFile) Write(written string) error {
	fptr, err := os.Create(of_.file)
	if err != nil { return err }
	_, err = fptr.WriteString(written)
	return err
}

func (of_ AddFile) AddNum(an int) error {
	res := of_.ReadInt() + an + of_.addnum
	rest := strconv.Itoa(res)
	return of_.Write(rest)
}

func (of_ AddFile) CanMinus(an int) bool {
	ri := of_.ReadInt()
	if ri < an {
		return false
	}
	ann := -an
	of_.AddNum(ann)
	return true
}