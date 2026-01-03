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

type AncientThingWearPage struct {
    router func(interfaces.PageID)
}

func NewAncientThingWearPage() *AncientThingWearPage {
    return &AncientThingWearPage{}
}

func (p *AncientThingWearPage) GetContent() fyne.CanvasObject {
	title := canvas.NewText("我的衣着", color.Black)
	title.TextSize = 27

	btnBack := widget.NewButton("返回", func(){
		p.router(interfaces.PageID_AncientThingMainPage)
	})

	btn0 := widget.NewButton("我的佩剑", func(){
		p.router(interfaces.PageID_AncientThingSwordPage)
	})

	btn2 := widget.NewButton("我的锦袍", func() {
		p.router(interfaces.PageID_AncientThingPaoPage)
	})
	
	vbox := container.NewVBox(
		simple.HorizonCenter(title),
		simple.Spacer(175),
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

func (p *AncientThingWearPage) GetID() interfaces.PageID {
    return interfaces.PageID_AncientThingWearPage
}

func (p *AncientThingWearPage) SetRouter(fn func(interfaces.PageID)) {
    p.router = fn
}
