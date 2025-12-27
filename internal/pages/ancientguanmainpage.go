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

type AncientGuanMainPage struct {
    router func(interfaces.PageID)
}

func NewAncientGuanMainPage() *AncientGuanMainPage {
    return &AncientGuanMainPage{}
}

func (p *AncientGuanMainPage) GetContent() fyne.CanvasObject {
	title := canvas.NewText("我的官职", color.Black)
	title.TextSize = 27

	btnBack := widget.NewButton("返回", func(){
		p.router(interfaces.PageID_AncientMainPage)
	})

	btn0 := widget.NewButton("作为文官", func(){
		p.router(interfaces.PageID_AncientGuanWenMainPage)
	})
	
	btn1 := widget.NewButton("作为武官", func(){
		p.router(interfaces.PageID_AncientGuanWuMainPage)
	})
	
	vbox := container.NewVBox(
		simple.HorizonCenter(title),
		simple.Spacer(200),
		simple.HorizonCenter(btn0),
		simple.HorizonCenter(btn1),
		simple.Spacer(100),
		simple.HorizonRight(btnBack),
		layout.NewSpacer(),
	)

    return container.NewBorder(
		vbox, 
		nil, nil, nil, nil, 
	)
}

func (p *AncientGuanMainPage) GetID() interfaces.PageID {
    return interfaces.PageID_AncientGuanMainPage
}

func (p *AncientGuanMainPage) SetRouter(fn func(interfaces.PageID)) {
    p.router = fn
}
