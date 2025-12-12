package main
import (

    "fyne.io/fyne/v2"
    "fyne.io/fyne/v2/app"

    "StudyPlatform/src/application"
    "StudyPlatform/src/interfaces"
	"StudyPlatform/src/pkg/simple"
)
func main() {
    a := app.New()
	a.Settings().SetTheme(&simple.Font{})
    window := a.NewWindow("双界面Demo")
    
    controller := application.NewApp(window)
    controller.SwitchPage(interfaces.PageID_MainPage)
    
    window.Resize(fyne.NewSize(700, 700))
    window.ShowAndRun()
}
