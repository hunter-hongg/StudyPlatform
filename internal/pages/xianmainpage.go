package pages

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

type XianMainPage struct {
    router func(interfaces.PageID)
}

func NewXianMainPage() *XianMainPage {
    return &XianMainPage{}
}

func (p *XianMainPage) GetContent() fyne.CanvasObject {
	title := canvas.NewText("神话传说", color.Black)
	title.TextSize = 27

	showx := canvas.NewText(
		"仙币: "+global.File_XianBiReader.ReadStrSafe(),	
	simple.Blue)
	showx.TextSize = 20

	btnBack := widget.NewButton("返回", func(){
		p.router(interfaces.PageID_MainPage)
	})

	btnT := widget.NewButton("我的物品", func(){
		// p.router(interfaces.PageID_TimerMainPage)
	})

	btnN := widget.NewButton("我的能力", func(){
		p.router(interfaces.PageID_XianSkillMainPage)
	})

	btnD := widget.NewButton("我的待遇", func(){
		p.router(interfaces.PageID_XianLuMainPage)
	})

	vbox := container.NewVBox(
		simple.HorizonCenter(title),
		simple.Spacer(20),
		simple.HorizonCenter(showx),
		simple.Spacer(130),
		simple.HorizonCenter(btnT),
		simple.HorizonCenter(btnN),
		simple.HorizonCenter(btnD),
		simple.Spacer(100),
		simple.HorizonRight(btnBack),
		layout.NewSpacer(),
	)

    return container.NewBorder(
		vbox, 
		nil, nil, nil, nil, 
	)
}

func (p *XianMainPage) GetID() interfaces.PageID {
    return interfaces.PageID_XianMainPage
}

func (p *XianMainPage) SetRouter(fn func(interfaces.PageID)) {
    p.router = fn
}
