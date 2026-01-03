package achuzheng

import (
	"StudyPlatform/pkg/cgo"
)

// Choices 枚举类型
type Choices int

const (
	JinGong Choices = iota
	XiuZheng
	FangShou
	TouXi
)

// GetResult 根据双方选择返回结果
func GetResult(a, b Choices) (int, int) {
	switch {
	case a == JinGong && b == JinGong:
		return -30 + cgo.GetRnd(-5, 5), -30 + cgo.GetRnd(-5, 5)
	
	case (a == JinGong && b == XiuZheng) || (a == XiuZheng && b == JinGong):
		if a == JinGong {
			return -10 + cgo.GetRnd(-5, 5), -30 + cgo.GetRnd(-5, 5)
		}
		return -30 + cgo.GetRnd(-5, 5), -10 + cgo.GetRnd(-5, 5)
	
	case (a == JinGong && b == FangShou) || (a == FangShou && b == JinGong):
		if a == JinGong {
			return -35 + cgo.GetRnd(-5, 5), -5 + cgo.GetRnd(-5, 5)
		}
		return -5 + cgo.GetRnd(-5, 5), -35 + cgo.GetRnd(-5, 5)
	
	case (a == JinGong && b == TouXi) || (a == TouXi && b == JinGong):
		if a == JinGong {
			return -20 + cgo.GetRnd(-5, 5), -40 + cgo.GetRnd(-5, 5)
		}
		return -40 + cgo.GetRnd(-5, 5), -20 + cgo.GetRnd(-5, 5)
	
	case a == XiuZheng && b == XiuZheng:
		return 20 + cgo.GetRnd(-5, 5), 20 + cgo.GetRnd(-5, 5)
	
	case (a == XiuZheng && b == FangShou) || (a == FangShou && b == XiuZheng):
		if a == XiuZheng {
			return 30 + cgo.GetRnd(-5, 5), -50 + cgo.GetRnd(-5, 5)
		}
		return -50 + cgo.GetRnd(-5, 5), 30 + cgo.GetRnd(-5, 5)
	
	case (a == XiuZheng && b == TouXi) || (a == TouXi && b == XiuZheng):
		if a == XiuZheng {
			return -30 + cgo.GetRnd(-5, 5), -5 + cgo.GetRnd(-5, 5)
		}
		return -5 + cgo.GetRnd(-5, 5), -30 + cgo.GetRnd(-5, 5)
	
	case a == FangShou && b == FangShou:
		return -20 + cgo.GetRnd(-5, 5), -20 + cgo.GetRnd(-5, 5)
	
	case (a == FangShou && b == TouXi) || (a == TouXi && b == FangShou):
		if a == FangShou {
			return 5 + cgo.GetRnd(-5, 5), -30 + cgo.GetRnd(-5, 5)
		}
		return -30 + cgo.GetRnd(-5, 5), 5 + cgo.GetRnd(-5, 5)
	
	case a == TouXi && b == TouXi:
		return -40 + cgo.GetRnd(-5, 5), -40 + cgo.GetRnd(-5, 5)
	
	default:
		return 0, 0
	}
}

// GetChoice 根据历史数据做出选择
func GetChoice(other, self int, usrchoices []Choices) Choices {
	cha := self - other
	if cha < 0 {
		cha = -cha
	}
	
	usrcl := len(usrchoices)
	
	if usrcl >= 4 {
		if usrchoices[usrcl-2] == usrchoices[usrcl-3] {
			cho := usrchoices[usrcl-2]
			chk4 := usrchoices[usrcl-4]
			chk1 := usrchoices[usrcl-1]
			
			if cho == chk4 || cho == chk1 {
				switch cho {
				case JinGong:
					return FangShou
				case FangShou:
					return XiuZheng
				case XiuZheng:
					return JinGong
				case TouXi:
					return FangShou
				}
			}
		}
	}
	
	if self > other {
		t := cgo.GetRnd(0, 9)
		if t < 4 {
			return JinGong
		} else if t < 6 {
			return XiuZheng
		} else {
			return TouXi
		}
	} else if cha < 90 {
		t := cgo.GetRnd(0, 9)
		if t < 2 {
			return JinGong
		} else if t < 4 {
			return XiuZheng
		} else if t < 8 {
			return FangShou
		} else {
			return TouXi
		}
	} else {
		t := cgo.GetRnd(0, 9)
		if t < 2 {
			return JinGong
		} else if t < 8 {
			return FangShou
		} else {
			return XiuZheng
		}
	}
}

func ToString(ch Choices) string {
	switch ch {
	case JinGong:
		return "进攻敌军"
	case FangShou:
		return "防御敌军"
	case XiuZheng:
		return "休整兵马"
	case TouXi:
		return "趁其不备"
	default:
		return ""
	}
}