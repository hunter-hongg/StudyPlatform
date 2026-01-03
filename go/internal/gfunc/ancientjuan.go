package gfunc

func JuanGetLevel(zhi int) int {
	switch {
	case 0 <= zhi && zhi < 50: 
		return 1 
	case 50 <= zhi && zhi < 100: 
		return 2 
	case 100 <= zhi && zhi < 150:
		return 3
	case 150 <= zhi && zhi < 200:
		return 4
	case 200 <= zhi:
		return 5
	default:
		return 0
	}
}

func JuanGetHuangjin(lev int) int {
	switch lev {
	case 0:
		return 0
	case 1:
		return 10
	case 2:
		return 20
	case 3:
		return 35
	case 4:
		return 40
	case 5:
		return 55
	default:
		return 10
	}
}
