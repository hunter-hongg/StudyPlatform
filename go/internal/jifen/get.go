package jifen

func GetJifenFromSeconds(seconds int) int {
	if seconds < 60 {
		return 1
	} else if seconds < 300 {
		return seconds / 30
	} else if seconds < 1500 {
		return seconds / 20
	} else {
		return seconds / 15
	}
}
func GetLevelFromJifen(jifen int) int {
	level := (jifen - 200) / 150
	if level < 1 {
		return 1
	} else if level > 100 {
		return 100
	} else {
		return level
	}
}
