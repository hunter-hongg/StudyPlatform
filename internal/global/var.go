package global

import (
	"StudyPlatform/pkg/util"

	"fyne.io/fyne/v2"
)

var Logger *util.Logger = util.NewLogger()

var TimerStartPage_Timer *util.Timer = util.NewTimer()

var Main_Window fyne.Window
