package pages

import (
	"StudyPlatform/internal/global"
	"StudyPlatform/internal/interfaces"
	"StudyPlatform/pkg/simple"

	"image/color"

	"fyne.io/fyne/v2"
	"fyne.io/fyne/v2/canvas"
	"fyne.io/fyne/v2/container"
	"fyne.io/fyne/v2/layout"
	"fyne.io/fyne/v2/widget"
)

type AncientThingBookPage struct {
	router func(interfaces.PageID)
}

func NewAncientThingBookPage() *AncientThingBookPage {
	return &AncientThingBookPage{}
}

func (p *AncientThingBookPage) GetContent() fyne.CanvasObject {
	title := canvas.NewText("我的书籍", color.Black)
	title.TextSize = 27

	btnBack := widget.NewButton("返回", func() {
		p.router(interfaces.PageID_AncientThingMainPage)
	})

	var btns []fyne.CanvasObject
	var things = []string{"普通书籍", "珍稀书籍", "典藏书籍"}
	var files = []string{global.File_AncientBook1.ReadStr(), global.File_AncientBook2.ReadStr(),
		global.File_AncientBook3.ReadStr()}

	for i := 0; i < 3; i++ {
		btns = append(btns,
			simple.HorizonCenter(
				widget.NewButton(
					things[i]+": "+files[i]+"本", func() {},
				),
			),
		)
	}

	vbox := container.NewVBox(
		simple.HorizonCenter(title),
		simple.Spacer(170),
		btns[0], btns[1], btns[2],
		simple.Spacer(100),
		simple.HorizonRight(btnBack),
		layout.NewSpacer(),
	)

	return container.NewBorder(
		vbox,
		nil, nil, nil, nil,
	)
}

func (p *AncientThingBookPage) GetID() interfaces.PageID {
	return interfaces.PageID_AncientThingBookPage
}

func (p *AncientThingBookPage) SetRouter(fn func(interfaces.PageID)) {
	p.router = fn
}
