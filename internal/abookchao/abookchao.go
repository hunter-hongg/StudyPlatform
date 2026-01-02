package abookchao

import "StudyPlatform/pkg/cgo"

func CalcNeed() (lv1 int, lv2 int, lv3 int, dj int, hj int) {
	var max int 
	lv3 = cgo.GetRnd(1, 10)
	switch {
	case lv3 <= 1:
		lv2 = cgo.GetRnd(1, 2)
		max = 4
		dj = 1
		hj = 5
	case lv3 <= 2:
		lv2 = cgo.GetRnd(1, 2)
		max = 6
		dj = 2
		hj = 10
	case lv3 <= 5:
		lv2 = cgo.GetRnd(2, 4)
		max = 10
		dj = 3
		hj = 15
	case lv3 <= 7:
		lv2 = cgo.GetRnd(2, 5)
		max = 15
		dj = 4
		hj = 20
	case lv3 <= 10:
		lv2 = cgo.GetRnd(3, 6)
		max = 20
		dj = 5
		hj = 30
	}
	lv1 = max - lv3 - lv2
	return
}

func CalcGet(dj int) int {
	switch dj {
	case 1:
		return 90
	case 2:
		return 150
	case 3:
		return 200
	case 4:
		return 350
	case 5:
		return 675
	default:
		return -1
	}
}