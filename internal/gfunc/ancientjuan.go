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