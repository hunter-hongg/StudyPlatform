package pages

import (
	"StudyPlatform/src/interfaces"
	"StudyPlatform/src/pkg/global"
	"StudyPlatform/src/pkg/jifen"
	"StudyPlatform/src/pkg/simple"

	_"fmt"
	"image/color"

	"fyne.io/fyne/v2"
	"fyne.io/fyne/v2/canvas"
	"fyne.io/fyne/v2/container"
	"fyne.io/fyne/v2/layout"
	"fyne.io/fyne/v2/widget"
)

type TimerMainPage struct {
    router func(interfaces.PageID)
}

func NewTimerMainPage() *TimerMainPage {
    return &TimerMainPage{}
}

func (p *TimerMainPage) GetContent() fyne.CanvasObject {
	title := canvas.NewText("学习计时", color.Black)
	title.TextSize = 27

	btnBack := widget.NewButton("返回", func(){
		p.router(interfaces.PageID_OwnPage)
	})

	btnStart := widget.NewButton("开始计时", func(){
		global.TimerStartPage_Timer.Start()
	})
	btnEnd := widget.NewButton("结束计时", func(){
		if err := global.TimerStartPage_Timer.Stop(); err != nil {
			simple.DialogError(err, global.Main_Window)
			return
		}
		seconds_real := global.TimerStartPage_Timer.GetSeconds()
		// seconds_real := global.TimerStartPage_Timer.GetMilliseconds()
		seconds := int(seconds_real)
		jifenGet := jifen.GetJifenFromSeconds(seconds)
		_ = jifenGet
		// fmt.Printf("End, time: %d, jifen: %d\n", seconds, jifen)
	})
	btnRule := widget.NewButton("计时规则", func(){
	})

	vbox := container.NewVBox(
		simple.HorizonCenter(title),
		simple.Spacer(200),
		simple.HorizonCenter(btnStart),
		simple.HorizonCenter(btnEnd),
		simple.HorizonCenter(btnRule),
		simple.Spacer(100),
		simple.HorizonRight(btnBack),
		layout.NewSpacer(),
	)

    return container.NewBorder(
		vbox, 
		nil, nil, nil, nil, 
	)
}

func (p *TimerMainPage) GetID() interfaces.PageID {
    return interfaces.PageID_TimerMainPage
}

func (p *TimerMainPage) SetRouter(fn func(interfaces.PageID)) {
    p.router = fn
}
