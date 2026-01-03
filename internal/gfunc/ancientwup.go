package gfunc

import "StudyPlatform/internal/global"

func AncientWuBinglp(now int, min int) int {
	return ((now - min)/5)*10+7
}

func AncientWuBinglg() int {
    return (
        global.File_AncientWuXinLr.ReadIntSafe() * global.File_AncientWuXinIr.ReadIntSafe()+
        global.File_AncientWuPuTongLr.ReadIntSafe() * global.File_AncientWuPuTongIr.ReadIntSafe()+
        global.File_AncientWuChuJiLr.ReadIntSafe() * global.File_AncientWuChuJiIr.ReadIntSafe()+
        global.File_AncientWuZhongJiLr.ReadIntSafe() * global.File_AncientWuZhongJiIr.ReadIntSafe()+
        global.File_AncientWuGaoJiLr.ReadIntSafe() * global.File_AncientWuGaoJiIr.ReadIntSafe()+
        global.File_AncientWuJingRuiLr.ReadIntSafe() * global.File_AncientWuJingRuiIr.ReadIntSafe()+
        global.File_AncientWuWangPaiLr.ReadIntSafe() * global.File_AncientWuWangPaiIr.ReadIntSafe()+
        global.File_AncientWuShenJiLr.ReadIntSafe() * global.File_AncientWuShenJiIr.ReadIntSafe()+
	0)
}