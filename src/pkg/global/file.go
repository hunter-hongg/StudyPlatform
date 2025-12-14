package global

import (
	"os"
	"StudyPlatform/src/pkg/util"
)

var (
	User                            string              = os.Getenv("USER")
	Home                            string              = os.Getenv("HOME")
	File_FilePathBase               string              = Home+"/.store/"

	File_FilePath                   string              = File_FilePathBase + "学习平台储存/"
	File_FilePathTongYong           string              = File_FilePath + "tyhbdirapbb/";
    File_FilePathTongYongReal       string              = File_FilePathTongYong + "fptyr/";
	File_FilePathAncient            string              = File_FilePath + "adirspfm/";
)

var (
    File_JiFenReader                *util.FilePassword  = util.NewFilePassword(File_FilePath+"jifc.txt","hsiep10475")  
	File_TongYongReader             *util.FilePassword  = util.NewFilePassword(
																File_FilePathTongYongReal+"tyrelrd.cc", "qacjf34860")
	File_JiSuanBiReader             *util.FilePassword  = util.NewFilePassword(File_FilePath+"jsbc.txt","woda2fj341")
	File_TongQianReader             *util.FilePassword  = util.NewFilePassword(File_FilePath+"tb.avc","hifo356sjl")
	File_JinBiReader                *util.FilePassword  = util.NewFilePassword(File_FilePathTongYong+"rd.conc","apslfnt104")
)
