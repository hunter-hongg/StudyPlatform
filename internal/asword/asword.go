package asword

import (
	"bufio"
	"os"
	"strconv"
	"strings"
)

type Sword int

const (
	Green Sword = iota
	Red
	Purple
	Black
	White
	RealRed
	Blue
)

type AncientSword struct {
	swordnow string
	swordall string
}

func NewAncientSword(now, all string) *AncientSword {
	return &AncientSword{
		swordnow: now,
		swordall: all,
	}
}

func (as *AncientSword) GetNow() Sword {
	return as.ReadNow()
}

func (as *AncientSword) GetAll() []Sword {
	return as.ReadAll()
}

func (as *AncientSword) ReadNow() Sword {
	file, err := os.OpenFile(as.swordnow, os.O_APPEND|os.O_CREATE|os.O_WRONLY, 0644)
	if err != nil {
		return Green
	}
	file.Close()

	file, err = os.Open(as.swordnow)
	if err != nil {
		return Green
	}
	defer file.Close()

	scanner := bufio.NewScanner(file)
	var a string
	if scanner.Scan() {
		a = scanner.Text()
	}

	tmp, err := strconv.Atoi(a)
	if err != nil || tmp < 0 || tmp > 6 {
		return Green
	}
	return Sword(tmp)
}

func (as *AncientSword) ReadAll() []Sword {
	file, err := os.OpenFile(as.swordall, os.O_APPEND|os.O_CREATE|os.O_WRONLY, 0644)
	if err != nil {
		return []Sword{Green}
	}
	file.Close()

	file, err = os.Open(as.swordall)
	if err != nil {
		return []Sword{Green}
	}
	defer file.Close()

	content, err := os.ReadFile(as.swordall)
	if err != nil {
		return []Sword{Green}
	}

	alla := strings.Split(string(content), ",")
	rt := make([]Sword, 0)
	for _, i := range alla {
		if i == "" {
			continue
		}
		ttp, err := strconv.Atoi(i)
		if err != nil || ttp < 0 || ttp > 6 {
			ttp = 0
		}
		rt = append(rt, Sword(ttp))
	}

	rts := make(map[Sword]bool)
	for _, i := range rt {
		rts[i] = true
	}

	rtt := make([]Sword, 0, len(rts))
	for k := range rts {
		rtt = append(rtt, k)
	}
	return rtt
}

func (as *AncientSword) Change(newsword Sword) int {
	tmp := as.ReadAll()
	found := false
	for _, item := range tmp {
		if item == newsword {
			found = true
			break
		}
	}
	if !found {
		return 1
	}

	file, err := os.Create(as.swordnow)
	if err != nil {
		return 1
	}
	defer file.Close()

	_, err = file.WriteString(strconv.Itoa(int(newsword)))
	if err != nil {
		return 1
	}
	return 0
}

func (as *AncientSword) Add(addsword Sword) {
	file, err := os.OpenFile(as.swordall, os.O_APPEND|os.O_CREATE|os.O_WRONLY, 0644)
	if err != nil {
		return
	}
	defer file.Close()

	_, err = file.WriteString("," + strconv.Itoa(int(addsword)))
	if err != nil {
		return
	}
}

func (s Sword) String() string {
	switch s {
	case Green:
		return "青剑"
	case Red:
		return "赤剑"
	case Purple:
		return "紫剑"
	case Black:
		return "黑剑"
	case White:
		return "白剑"
	case RealRed:
		return "红剑"
	case Blue:
		return "蓝剑"
	default:
		return "紫剑"
	}
}
