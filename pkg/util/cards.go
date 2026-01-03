package util

import (
	"bufio"
	"os"
	"strconv"
	"strings"
)

type Cards struct {
	filename string
	cardname []string
	addnum   int
}

func NewCards(filename string, cardname []string, addnum int) *Cards {
	return &Cards{
		filename: filename,
		cardname: cardname,
		addnum:   addnum,
	}
}

func (c *Cards) Get() []string {
	file, err := os.OpenFile(c.filename, os.O_RDONLY|os.O_CREATE, 0644)
	if err != nil {
		return []string{}
	}
	file.Close()

	content, err := os.ReadFile(c.filename)
	if err != nil {
		return []string{}
	}

	rawstr := strings.TrimSpace(string(content))
	if rawstr == "" {
		return []string{}
	}

	rawvec := strings.Split(rawstr, ",")
	seen := make(map[int]bool)
	var realCardVec []string

	for _, item := range rawvec {
		item = strings.TrimSpace(item)
		if !strings.HasPrefix(item, "/x/") {
			continue
		}

		realstr := item[3:]
		num, err := strconv.Atoi(realstr)
		if err != nil {
			continue
		}

		adjustedNum := num - c.addnum
		if seen[adjustedNum] {
			continue
		}
		seen[adjustedNum] = true

		if adjustedNum >= 0 && adjustedNum < len(c.cardname) {
			realCardVec = append(realCardVec, c.cardname[adjustedNum])
		}
	}

	return realCardVec
}

func (c *Cards) Write(index int) int {
	if index < 0 || index >= len(c.cardname) {
		return -1
	}

	file, err := os.OpenFile(c.filename, os.O_APPEND|os.O_CREATE|os.O_WRONLY, 0644)
	if err != nil {
		return -1
	}
	defer file.Close()

	writer := bufio.NewWriter(file)
	_, err = writer.WriteString(",/x/" + strconv.Itoa(c.addnum+index))
	if err != nil {
		return -1
	}
	writer.Flush()

	return 0
}

func (c *Cards) GetByIndex(index int) string {
	if index < 0 || index >= len(c.cardname) {
		return ""
	}
	return c.cardname[index]
}