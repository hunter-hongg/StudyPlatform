package main

import (
	"os"

	"fyne.io/fyne/v2"
	"fyne.io/fyne/v2/app"

	"StudyPlatform/internal/application"
	"StudyPlatform/internal/global"
	"StudyPlatform/internal/interfaces"
	"StudyPlatform/pkg/simple"
	"StudyPlatform/pkg/util"
)
func main() {
	os.MkdirAll(global.File_FilePathBase, 0755)
	os.MkdirAll(global.File_FilePath, 0755)
	os.MkdirAll(global.File_FilePathTongYong, 0755)
	os.MkdirAll(global.File_FilePathTongYongReal, 0755)
	os.MkdirAll(global.File_FilePathAncient, 0755)
	os.MkdirAll(global.File_FilePathCard, 0755)
	os.MkdirAll(global.File_FilePathBaoShi, 0755)
	os.MkdirAll(global.File_FilePathBank, 0755)
	os.MkdirAll(global.File_FilePathThingsSquare, 0755)
	os.MkdirAll(global.File_FilePathXianLu, 0755)
	os.MkdirAll(global.File_FilePathXianDan, 0755)
	os.MkdirAll(global.File_FilePathXianJi, 0755)
	os.MkdirAll(global.File_FilePathXianQi, 0755)

	global.Logger.SetLevel(util.LevelInfo)
	global.Logger.Info("程序正常启动")

    a := app.New()
	a.Settings().SetTheme(&simple.Font{})
    global.Main_Window = a.NewWindow("学习平台")
    
    controller := application.NewApp(global.Main_Window)
    controller.SwitchPage(interfaces.PageID_MainPage)
    
    global.Main_Window.Resize(fyne.NewSize(700, 700))
    global.Main_Window.ShowAndRun()
}
