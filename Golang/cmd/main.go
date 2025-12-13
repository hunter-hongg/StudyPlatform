package main

import (
	"fyne.io/fyne/v2"
	"fyne.io/fyne/v2/app"

	"StudyPlatform/src/application"
	"StudyPlatform/src/interfaces"
	"StudyPlatform/src/pkg/global"
	"StudyPlatform/src/pkg/simple"
)
func main() {
    a := app.New()
	a.Settings().SetTheme(&simple.Font{})
    global.Main_Window = a.NewWindow("学习平台")
    
    controller := application.NewApp(global.Main_Window)
    controller.SwitchPage(interfaces.PageID_MainPage)
    
    global.Main_Window.Resize(fyne.NewSize(700, 700))
    global.Main_Window.ShowAndRun()
}
