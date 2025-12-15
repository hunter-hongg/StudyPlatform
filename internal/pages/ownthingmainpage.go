package pages

import (
	"StudyPlatform/internal/interfaces"
	"StudyPlatform/pkg/simple"

	_ "fmt"
	"image/color"

	"fyne.io/fyne/v2"
	"fyne.io/fyne/v2/canvas"
	"fyne.io/fyne/v2/container"
	"fyne.io/fyne/v2/layout"
	"fyne.io/fyne/v2/widget"
)

type OwnThingMainPage struct {
    router func(interfaces.PageID)
}

func NewOwnThingMainPage() *OwnThingMainPage {
    return &OwnThingMainPage{}
}

func (p *OwnThingMainPage) GetContent() fyne.CanvasObject {
	title := canvas.NewText("所有物品", color.Black)
	title.TextSize = 27

	btnBack := widget.NewButton("返回", func(){
		p.router(interfaces.PageID_OwnPage)
	})

	btnStart := widget.NewButton("物品查看", func(){
		p.router(interfaces.PageID_OwnThingAllPage)
	})
	vbox := container.NewVBox(
		simple.HorizonCenter(title),
		simple.Spacer(200),
		simple.HorizonCenter(btnStart),
		simple.Spacer(100),
		simple.HorizonRight(btnBack),
		layout.NewSpacer(),
	)

    return container.NewBorder(
		vbox, 
		nil, nil, nil, nil, 
	)
}

func (p *OwnThingMainPage) GetID() interfaces.PageID {
    return interfaces.PageID_OwnThingMainPage
}

func (p *OwnThingMainPage) SetRouter(fn func(interfaces.PageID)) {
    p.router = fn
}
