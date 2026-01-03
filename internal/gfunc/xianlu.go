package gfunc

func GetXianLu(level int) int {
	now := level
    if(now <= 0) {
        return 0
    } else if (now <= 20) {
        return 50 + now * 40
    } else if (now <= 40) {
        return 70 + now * 50
    } else {
        return 70 + 40 * 50 
    }
};