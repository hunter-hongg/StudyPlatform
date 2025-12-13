package global

import (
	"os"
	"StudyPlatform/src/pkg/util"
)

var (
	File_FilePathBase     string              = os.Getenv("HOME")+"/.store/"
	File_FilePath         string              = File_FilePathBase + "学习平台储存/"
    File_JiFenReader      *util.FilePassword  = util.NewFilePassword(File_FilePath+"jifc.txt","hsiep10475")  
)
