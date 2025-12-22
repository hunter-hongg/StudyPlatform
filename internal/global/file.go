package global

import (
	"StudyPlatform/internal/xiansword"
	"StudyPlatform/pkg/util"
	"os"
)

var (
	User                            string              = os.Getenv("USER")
	Home                            string              = os.Getenv("HOME")
	File_FilePathBase               string              = Home+"/.store/"

	File_FilePath                   string              = File_FilePathBase + "学习平台储存/"
	File_FilePathTongYong           string              = File_FilePath + "tyhbdirapbb/"
    File_FilePathTongYongReal       string              = File_FilePathTongYong + "fptyr/"
	File_FilePathAncient            string              = File_FilePath + "adirspfm/"
	File_FilePathCard               string              = File_FilePath + "fpcdiralf/"
	File_FilePathBaoShi             string              = File_FilePath + "baosdirfos/"
	File_FilePathBank               string              = File_FilePath + "cc.bnkaac.c.io/"
	File_FilePathThingsSquare       string              = File_FilePath + "tssqudirdpg/"
	File_FilePathXianLu             string              = File_FilePath + "xlccf.gfd.ew0/"
	File_FilePathXianDan            string              = File_FilePath + "xdccdir.fdso.so12/"
	File_FilePathXianJi             string              = File_FilePath + "xjccdir.fjdo/"
	File_FilePathXianQi             string              = File_FilePath + "xqptdir/"
)

var ( // 普通数据存储
    File_JiFenReader                *util.FilePassword  = util.NewFilePassword(File_FilePath+"jifc.txt","hsiep10475")  
	File_TongYongReader             *util.FilePassword  = util.NewFilePassword(
																File_FilePathTongYongReal+"tyrelrd.cc", "qacjf34860")
	File_JiSuanBiReader             *util.FilePassword  = util.NewFilePassword(File_FilePath+"jsbc.txt","woda2fj341")
	File_TongQianReader             *util.FilePassword  = util.NewFilePassword(File_FilePath+"tb.avc","hifo356sjl")
	File_XianBiReader               *util.FilePassword  = util.NewFilePassword(
																File_FilePath+"xianbc.conc","woapf20sl1")
	File_JinBiReader                *util.FilePassword  = util.NewFilePassword(
																File_FilePathTongYong+"rd.conc","apslfnt104")
	File_YinBiReader                *util.FilePassword  = util.NewFilePassword(
																File_FilePathTongYong+"yb.conc.sdpg.1659", 
																"apfjr12409")
	File_BaoshiReader               *util.FilePassword  = util.NewFilePassword(
																File_FilePathBaoShi+"mbsc.conc","rosl3510dm")
	File_BankStoreReader            *util.FilePassword  = util.NewFilePassword(
																File_FilePathBank+"fhubasr", "aoidnrm301")
	File_BankJuanQuanReader         *util.FilePassword  = util.NewFilePassword(
																File_FilePathBank+"bjq.cc.ssdiowei_", "asoirm2156")
	File_XianLuPinJi                *util.FilePassword  = util.NewFilePassword(
																File_FilePathXianLu+"xlj.ds.cc.o239", "done20596w")
	File_XianFaLiReader             *util.FilePassword  = util.NewFilePassword(File_FilePath+"falc.conc","fjmep20kl1")
	File_XianJiReader               *util.FilePassword  = util.NewFilePassword(
																File_FilePathXianJi+"xjrd.dso.349fern.cc", "sdoih14853")
	File_XianQiFaLiReader           *util.FilePassword  = util.NewFilePassword(
																File_FilePathXianQi+"xqfl.conc","hjq40tp586")
	File_AncientTongQianReader      *util.FilePassword  = util.NewFilePassword(File_FilePath+"tb.avc","hifo356sjl")
	File_AncientBaiYinReader        *util.FilePassword  = util.NewFilePassword(File_FilePath+"bay.avc","3ifnyl1042")
	File_AncientHuangJinReader      *util.FilePassword  = util.NewFilePassword(File_FilePath+"huaj.avc","dgp395sk10")
)

var ( // 仙丹存储
	File_XianPuTongDanReader        *util.FilePassword  = util.NewFilePassword(File_FilePathXianDan+"pt.cc.xdcc.1304", "sdpf24j109")
	File_XianBiDanReader            *util.FilePassword  = util.NewFilePassword(File_FilePathXianDan+"bd.c.xdccm.eo4", "fqoeirm124")
	File_XianQingDanReader          *util.FilePassword  = util.NewFilePassword(File_FilePathXianDan+"qd.c.xdcc.ej.e", "fdoiem2401")
	File_XianZiDanReader            *util.FilePassword  = util.NewFilePassword(File_FilePathXianDan+"zd.c.xdcc.edos", "zdgofe2405")
	File_XianWuSeDanReader          *util.FilePassword  = util.NewFilePassword(File_FilePathXianDan+"ws.cd.gfgoi.xdcc", "dsoi23w105")
	File_XianYinDanReader           *util.FilePassword  = util.NewFilePassword(File_FilePathXianDan+"yd.c.xdcc.fdor", "sdognf3214")
	File_XianJinDanReader           *util.FilePassword  = util.NewFilePassword(File_FilePathXianDan+"jd.cc.xdcc.23dsj", "adogfn2104")
	File_XianShenDanReader          *util.FilePassword  = util.NewFilePassword(File_FilePathXianDan+"sd.cc.xdcc.239fh", "sdonv29810")
)

var ( // 仙器存储
	File_XianSword              *xiansword.SwordInFile  = xiansword.NewSwordInFile(File_FilePath+"swdif.conc")
)

var ( // 每日限次数据存储
	File_CalcAddCheck               *util.CheckFile     = util.NewCheckFile(File_FilePath+"jisbck1.txt",1049,7)
	File_CalcTimesCheck             *util.CheckFile     = util.NewCheckFile(File_FilePath+"jisbck2.txt",305,5)
	File_CalcDivCheck               *util.CheckFile     = util.NewCheckFile(File_FilePath+"jisbck3.chkl",302,5)
	File_ThingSquareJiFenCheck      *util.CheckFile     = util.NewCheckFile(File_FilePathThingsSquare+"tsjfcc.ck",6402,1)
	File_ThingSquareXianBiCheck     *util.CheckFile     = util.NewCheckFile(File_FilePathThingsSquare+"tsxbcc.ck",2202,1)
	File_ThingSquareTongQianCheck   *util.CheckFile     = util.NewCheckFile(File_FilePathThingsSquare+"tqchk.ck",2212,1)
	File_ThingSquareBaoShiCheck     *util.CheckFile     = util.NewCheckFile(File_FilePathThingsSquare+"fospbsck.dogck",1127,1)
	File_ThingSquareJinBiCheck      *util.CheckFile     = util.NewCheckFile(File_FilePathThingsSquare+"sdogh.dogck",2035,1)
	File_XianLuOk                   *util.CheckFile     = util.NewCheckFile(File_FilePathXianLu+"ck.clq.cc.3", 4091, 1)
)

var ( // 单次数据存储
	File_BasicLiHeOnce              *util.Oncefile      = util.NewOncefile(File_FilePath+"onfiblho.of.ooo")
)

var ( // 切片数据存储
	File_SanGuo1CardsName           []string            = []string{
		"卧龙","凤雏","曹操","孙权","刘备",
		"关羽","张飞","马超","黄忠","赵云",
		"张辽","徐晃","张郃","于禁","乐进",
		"许褚","典韦","关兴","张苞","曹纯",
		"周瑜","鲁肃","吕蒙","陆逊","陆抗",
		"徐盛","丁奉","马忠","潘璋","黄盖",
		"郭嘉","程昱","荀彧","荀攸","荀谌",
		"张昭","顾雍","阚泽","程秉","虞翻",
		"张南","冯习","魏延","姜维","邓艾","钟会",
	}

	File_Han1CardsName              []string            = []string{
		"刘邦","刘盈","刘恒","刘启","刘彻",
		"刘询","刘秀","刘庄","刘炟","刘贺",
		"萧何","韩信","张良","英布","吕后",
		"周勃","陈平","曹参","卫青","霍光",
		"王莽","邓禹","寇恂","班超","班固",
		"班昭","张骞","马援","苏武","李广",
		"刘安","刘长","刘歆","刘玄","王匡",
		"王凤","董卓","刘辩","刘协","刘宏",
		"伏完","董承","杨彪","王允","孔融",
	}
)

var ( // 卡牌数据存储
	File_SanGuo1Card                *util.Cards         = util.NewCards(
																File_FilePath+"capsgc1.txt",
																File_SanGuo1CardsName,9573)
	File_Han1Card                   *util.Cards         = util.NewCards(
																File_FilePathCard+"h1cac1.cac",
																File_Han1CardsName,7184)
)