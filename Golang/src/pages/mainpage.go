package pages

import (
	"StudyPlatform/src/interfaces"
	"StudyPlatform/src/pkg/simple"

	"image/color"

	"fyne.io/fyne/v2"
	"fyne.io/fyne/v2/canvas"
	"fyne.io/fyne/v2/container"
	"fyne.io/fyne/v2/layout"
	"fyne.io/fyne/v2/widget"
)

type MainPage struct {
    router func(interfaces.PageID)
}

func NewMainPage() *MainPage {
    return &MainPage{}
}

func (p *MainPage) GetContent() fyne.CanvasObject {
	title := canvas.NewText("欢迎来到学习平台", color.Black)
	title.TextSize = 35

	btnToOwn := widget.NewButton("个人主页", func(){
		p.router(interfaces.PageID_OwnPage)
	})

	btnToShen := widget.NewButton("神话传说", func(){
		// p.router(interfaces.PageID_OwnPage)
	})

	vbox := container.NewVBox(
		simple.HorizonCenter(title),
		simple.Spacer(200),
		container.NewGridWithColumns(2, 
			simple.HorizonRight(btnToOwn),
			simple.HorizonLeft(btnToShen),
		),
		layout.NewSpacer(),
	)

    return container.NewBorder(
		vbox, 
		nil, nil, nil, nil, 
	)
}

func (p *MainPage) GetID() interfaces.PageID {
    return interfaces.PageID_MainPage
}

func (p *MainPage) SetRouter(fn func(interfaces.PageID)) {
    p.router = fn
}

