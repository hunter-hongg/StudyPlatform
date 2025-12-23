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

type AncientThingMainPage struct {
    router func(interfaces.PageID)
}

func NewAncientThingMainPage() *AncientThingMainPage {
    return &AncientThingMainPage{}
}

func (p *AncientThingMainPage) GetContent() fyne.CanvasObject {
	title := canvas.NewText("我的物品", color.Black)
	title.TextSize = 27

	btnBack := widget.NewButton("返回", func(){
		p.router(interfaces.PageID_AncientMainPage)
	})

	btn0 := widget.NewButton("我的财物", func(){
		p.router(interfaces.PageID_AncientThingCaiPage)
	})

	btn2 := widget.NewButton("我的古玩", func() {
		p.router(interfaces.PageID_AncientThingGuwanPage)
	})
	
	vbox := container.NewVBox(
		simple.HorizonCenter(title),
		simple.Spacer(150),
		simple.HorizonCenter(btn0),
		simple.HorizonCenter(btn2),
		simple.Spacer(100),
		simple.HorizonRight(btnBack),
		layout.NewSpacer(),
	)

    return container.NewBorder(
		vbox, 
		nil, nil, nil, nil, 
	)
}

func (p *AncientThingMainPage) GetID() interfaces.PageID {
    return interfaces.PageID_AncientThingMainPage
}

func (p *AncientThingMainPage) SetRouter(fn func(interfaces.PageID)) {
    p.router = fn
}
