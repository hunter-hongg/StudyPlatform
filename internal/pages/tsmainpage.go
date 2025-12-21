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

type ThingSquareMainPage struct {
    router func(interfaces.PageID)
}

func NewThingSquareMainPage() *ThingSquareMainPage {
    return &ThingSquareMainPage{}
}

func (p *ThingSquareMainPage) GetContent() fyne.CanvasObject {
	title := canvas.NewText("物品领取", color.Black)
	title.TextSize = 27

	btnBack := widget.NewButton("返回", func(){
		p.router(interfaces.PageID_MainPage)
	})

	btnFree := widget.NewButton("免费领取", func(){
		p.router(interfaces.PageID_ThingSquareFreeMainPage)
	})

	btnJin := widget.NewButton("金币领取", func(){
		p.router(interfaces.PageID_ThingSquareJinMainPage)
	})

	btnMang := widget.NewButton("金币盲盒", func(){
		// p.router(interfaces.PageID_LiHePage)
	})

	vbox := container.NewVBox(
		simple.HorizonCenter(title),
		simple.Spacer(170),
		simple.HorizonCenter(btnFree),
		simple.HorizonCenter(btnJin),
		simple.HorizonCenter(btnMang),
		simple.Spacer(100),
		simple.HorizonRight(btnBack),
		layout.NewSpacer(),
	)

    return container.NewBorder(
		vbox, 
		nil, nil, nil, nil, 
	)
}

func (p *ThingSquareMainPage) GetID() interfaces.PageID {
    return interfaces.PageID_ThingSquareMainPage
}

func (p *ThingSquareMainPage) SetRouter(fn func(interfaces.PageID)) {
    p.router = fn
}
