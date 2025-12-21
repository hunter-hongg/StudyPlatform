package pages

import (
	"StudyPlatform/internal/interfaces"
	"StudyPlatform/pkg/simple"

	"image/color"

	"fyne.io/fyne/v2"
	"fyne.io/fyne/v2/canvas"
	"fyne.io/fyne/v2/container"
	"fyne.io/fyne/v2/layout"
	"fyne.io/fyne/v2/widget"
)

type XianDanMainPage struct {
    router func(interfaces.PageID)
}

func NewXianDanMainPage() *XianDanMainPage {
    return &XianDanMainPage{}
}

func (p *XianDanMainPage) GetContent() fyne.CanvasObject {
	title := canvas.NewText("我的仙丹", color.Black)
	title.TextSize = 27

	btnBack := widget.NewButton("返回", func(){
		p.router(interfaces.PageID_XianThingMainPage)
	})

	btnT := widget.NewButton("查看仙丹", func(){
		p.router(interfaces.PageID_XianDanShowPage)
	})
	
	btnN := widget.NewButton("炼制仙丹", func(){
		// p.router(interfaces.PageID_XianSkillMainPage)
	})

	btnD := widget.NewButton("仙丹召鹤", func(){
		// p.router(interfaces.PageID_XianDanMainPage)
	})
	
	vbox := container.NewVBox(
		simple.HorizonCenter(title),
		simple.Spacer(170),
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

func (p *XianDanMainPage) GetID() interfaces.PageID {
    return interfaces.PageID_XianDanMainPage
}

func (p *XianDanMainPage) SetRouter(fn func(interfaces.PageID)) {
    p.router = fn
}
