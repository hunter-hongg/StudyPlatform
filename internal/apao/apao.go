package apao

import (
	"bufio"
	"os"
	"strconv"
	"strings"
)

type Pao int

const (
	Green Pao = iota
	Red
	Purple
	Black
	White
	RealRed
	Blue
	Silver
)

type AncientPao struct {
	paonow string
	paoall string
}

func NewAncientPao(now, all string) *AncientPao {
	return &AncientPao{
		paonow: now,
		paoall: all,
	}
}

func (ap *AncientPao) GetNow() Pao {
	return ap.ReadNow()
}

func (ap *AncientPao) GetAll() []Pao {
	return ap.ReadAll()
}

func (ap *AncientPao) ReadNow() Pao {
	file, err := os.OpenFile(ap.paonow, os.O_APPEND|os.O_CREATE|os.O_WRONLY, 0644)
	if err != nil {
		return Green
	}
	file.Close()

	file, err = os.Open(ap.paonow)
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
	if err != nil || tmp < 0 || tmp > 7 {
		return Green
	}
	return Pao(tmp)
}

func (ap *AncientPao) ReadAll() []Pao {
	file, err := os.OpenFile(ap.paoall, os.O_APPEND|os.O_CREATE|os.O_WRONLY, 0644)
	if err != nil {
		return []Pao{Green}
	}
	file.Close()

	content, err := os.ReadFile(ap.paoall)
	if err != nil {
		return []Pao{Green}
	}

	alla := strings.Split(string(content), ",")
	rt := make([]Pao, 0)
	for _, i := range alla {
		if i == "" {
			continue
		}
		ttp, err := strconv.Atoi(i)
		if err != nil || ttp < 0 || ttp > 7 {
			ttp = 0
		}
		rt = append(rt, Pao(ttp))
	}

	rts := make(map[Pao]bool)
	for _, i := range rt {
		rts[i] = true
	}

	rtt := make([]Pao, 0, len(rts))
	for k := range rts {
		rtt = append(rtt, k)
	}
	return rtt
}

func (ap *AncientPao) Change(newpao Pao) int {
	tmp := ap.ReadAll()
	found := false
	for _, item := range tmp {
		if item == newpao {
			found = true
			break
		}
	}
	if !found {
		return 1
	}

	file, err := os.Create(ap.paonow)
	if err != nil {
		return 1
	}
	defer file.Close()

	_, err = file.WriteString(strconv.Itoa(int(newpao)))
	if err != nil {
		return 1
	}
	return 0
}

func (ap *AncientPao) Add(addpao Pao) {
	file, err := os.OpenFile(ap.paoall, os.O_APPEND|os.O_CREATE|os.O_WRONLY, 0644)
	if err != nil {
		return
	}
	defer file.Close()

	_, err = file.WriteString("," + strconv.Itoa(int(addpao)))
	if err != nil {
		return
	}
}

func (p Pao) String() string {
	switch p {
	case Green:
		return "青袍"
	case Red:
		return "赤袍"
	case Purple:
		return "紫袍"
	case Black:
		return "黑袍"
	case White:
		return "白袍"
	case RealRed:
		return "红袍"
	case Blue:
		return "蓝袍"
	case Silver:
		return "银袍"
	default:
		return "紫袍"
	}
}