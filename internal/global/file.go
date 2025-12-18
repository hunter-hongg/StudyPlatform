package global

import (
	"os"
	"StudyPlatform/pkg/util"
)

var (
	User                            string              = os.Getenv("USER")
	Home                            string              = os.Getenv("HOME")
	File_FilePathBase               string              = Home+"/.store/"

	File_FilePath                   string              = File_FilePathBase + "学习平台储存/"
	File_FilePathTongYong           string              = File_FilePath + "tyhbdirapbb/";
    File_FilePathTongYongReal       string              = File_FilePathTongYong + "fptyr/";
	File_FilePathAncient            string              = File_FilePath + "adirspfm/";
	File_FilePathCard               string              = File_FilePath + "fpcdiralf/";
)

var (
    File_JiFenReader                *util.FilePassword  = util.NewFilePassword(File_FilePath+"jifc.txt","hsiep10475")  
	File_TongYongReader             *util.FilePassword  = util.NewFilePassword(
																File_FilePathTongYongReal+"tyrelrd.cc", "qacjf34860")
	File_JiSuanBiReader             *util.FilePassword  = util.NewFilePassword(File_FilePath+"jsbc.txt","woda2fj341")
	File_TongQianReader             *util.FilePassword  = util.NewFilePassword(File_FilePath+"tb.avc","hifo356sjl")
	File_JinBiReader                *util.FilePassword  = util.NewFilePassword(File_FilePathTongYong+"rd.conc","apslfnt104")
)

var (
	File_CalcAddCheck               *util.CheckFile     = util.NewCheckFile(File_FilePath+"jisbck1.txt",1049,7)
	File_CalcTimesCheck             *util.CheckFile     = util.NewCheckFile(File_FilePath+"jisbck2.txt",305,5)
	File_CalcDivCheck               *util.CheckFile     = util.NewCheckFile(File_FilePath+"jisbck3.chkl",302,5)
)

var (
	File_BasicLiHeOnce              *util.Oncefile      = util.NewOncefile(File_FilePath+"onfiblho.of.ooo")
)

var (
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

var (
	File_SanGuo1Card                *util.Cards         = util.NewCards(File_FilePath+"capsgc1.txt",File_SanGuo1CardsName,9573);
	File_Han1Card                   *util.Cards         = util.NewCards(File_FilePathCard+"h1cac1.cac",File_Han1CardsName,7184);
)