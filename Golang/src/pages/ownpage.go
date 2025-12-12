package pages

import (
	"StudyPlatform/src/interfaces"
	"StudyPlatform/src/pkg/simple"

	"image/color"

	"fyne.io/fyne/v2"
	"fyne.io/fyne/v2/canvas"
	"fyne.io/fyne/v2/container"
	"fyne.io/fyne/v2/layout"
	"fyne.io/fyne/v2/widget"
)

type OwnPage struct {
    router func(interfaces.PageID)
}

func NewOwnPage() *OwnPage {
    return &OwnPage{}
}

func (p *OwnPage) GetContent() fyne.CanvasObject {
	title := canvas.NewText("个人主页", color.Black)
	title.TextSize = 27

	btnBack := widget.NewButton("返回", func(){
		p.router(interfaces.PageID_MainPage)
	})

	btnToTimer := widget.NewButton("学习计时", func(){
		p.router(interfaces.PageID_TimerMainPage)
	})

	vbox := container.NewVBox(
		simple.HorizonCenter(title),
		simple.Spacer(200),
		simple.HorizonCenter(btnToTimer),
		simple.Spacer(100),
		simple.HorizonRight(btnBack),
		layout.NewSpacer(),
	)

    return container.NewBorder(
		vbox, 
		nil, nil, nil, nil, 
	)
}

func (p *OwnPage) GetID() interfaces.PageID {
    return interfaces.PageID_OwnPage
}

func (p *OwnPage) SetRouter(fn func(interfaces.PageID)) {
    p.router = fn
}
