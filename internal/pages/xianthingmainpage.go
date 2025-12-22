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

type XianThingMainPage struct {
    router func(interfaces.PageID)
}

func NewXianThingMainPage() *XianThingMainPage {
    return &XianThingMainPage{}
}

func (p *XianThingMainPage) GetContent() fyne.CanvasObject {
	title := canvas.NewText("我的物品", color.Black)
	title.TextSize = 27

	btnBack := widget.NewButton("返回", func(){
		p.router(interfaces.PageID_XianMainPage)
	})

	btnT := widget.NewButton("我的仙器", func(){
		// p.router(interfaces.PageID_XianThingMainPage)
	})
	
	btnN := widget.NewButton("我的仙籍", func(){
		p.router(interfaces.PageID_XianJiMainPage)
	})

	btnD := widget.NewButton("我的仙丹", func(){
		p.router(interfaces.PageID_XianDanMainPage)
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

func (p *XianThingMainPage) GetID() interfaces.PageID {
    return interfaces.PageID_XianThingMainPage
}

func (p *XianThingMainPage) SetRouter(fn func(interfaces.PageID)) {
    p.router = fn
}
