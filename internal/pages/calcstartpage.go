package pages

/* 
计算币获得规则: 
加减练习: 
限5次，答对+50计算币

*/

import (
	"StudyPlatform/internal/interfaces"
	"StudyPlatform/internal/global"
	"StudyPlatform/pkg/simple"

	"image/color"

	"fyne.io/fyne/v2"
	"fyne.io/fyne/v2/canvas"
	"fyne.io/fyne/v2/container"
	"fyne.io/fyne/v2/layout"
	"fyne.io/fyne/v2/widget"
)

type CalcStartPage struct {
    router func(interfaces.PageID)
}

func NewCalcStartPage() *CalcStartPage {
    return &CalcStartPage{}
}

func (p *CalcStartPage) GetContent() fyne.CanvasObject {
	title := canvas.NewText("开始计算", color.Black)
	title.TextSize = 27

	showjis := canvas.NewText(
		"计算币: "+global.File_JiSuanBiReader.ReadStrSafe(),
	simple.Blue)
	showjis.TextSize = 20

	btnBack := widget.NewButton("返回", func(){
		p.router(interfaces.PageID_CalcMainPage)
	})

	btnToAdd := widget.NewButton("加减练习", func(){
		p.router(interfaces.PageID_CalcStartAddPage)
	})

	btnToTim := widget.NewButton("乘法练习", func(){
		p.router(interfaces.PageID_CalcStartTimPage)
	})

	btnToDiv := widget.NewButton("除法练习", func(){
		p.router(interfaces.PageID_CalcStartDivPage)
	})

	vbox := container.NewVBox(
		simple.HorizonCenter(title),
		simple.Spacer(20),
		simple.HorizonCenter(showjis),
		simple.Spacer(150),
		simple.HorizonCenter(btnToAdd),
		simple.HorizonCenter(btnToTim),
		simple.HorizonCenter(btnToDiv),
		simple.Spacer(100),
		simple.HorizonRight(btnBack),
		layout.NewSpacer(),
	)

    return container.NewBorder(
		vbox, 
		nil, nil, nil, nil, 
	)
}

func (p *CalcStartPage) GetID() interfaces.PageID {
    return interfaces.PageID_CalcStartPage
}

func (p *CalcStartPage) SetRouter(fn func(interfaces.PageID)) {
    p.router = fn
}
