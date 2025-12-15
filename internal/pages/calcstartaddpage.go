package pages

/*
计算币获得规则:
加减练习:
限5次，答对+50计算币

*/

import (
	"StudyPlatform/internal/global"
	"StudyPlatform/internal/interfaces"
	"StudyPlatform/pkg/simple"

	"image/color"

	"fyne.io/fyne/v2"
	"fyne.io/fyne/v2/canvas"
	"fyne.io/fyne/v2/container"
	"fyne.io/fyne/v2/layout"
	"fyne.io/fyne/v2/widget"
)

type CalcStartAddPage struct {
    router func(interfaces.PageID)
}

func NewCalcStartAddPage() *CalcStartAddPage {
    return &CalcStartAddPage{}
}

func (p *CalcStartAddPage) GetContent() fyne.CanvasObject {
	global.Logger.Debug("正常启动")

	title := canvas.NewText("加法练习", color.Black)
	title.TextSize = 27

	btnBack := widget.NewButton("返回", func(){
		p.router(interfaces.PageID_CalcStartPage)
	})

	vbox := container.NewVBox(
		simple.HorizonCenter(title),
		simple.Spacer(200),
		simple.Spacer(100),
		simple.HorizonRight(btnBack),
		layout.NewSpacer(),
	)

    return container.NewBorder(
		vbox, 
		nil, nil, nil, nil, 
	)
}

func (p *CalcStartAddPage) GetID() interfaces.PageID {
    return interfaces.PageID_CalcStartAddPage
}

func (p *CalcStartAddPage) SetRouter(fn func(interfaces.PageID)) {
    p.router = fn
}
