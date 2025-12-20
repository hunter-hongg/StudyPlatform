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

type OwnThingBaoshiShopPage struct {
    router func(interfaces.PageID)
}

func NewOwnThingBaoshiShopPage() *OwnThingBaoshiShopPage {
    return &OwnThingBaoshiShopPage{}
}

func (p *OwnThingBaoshiShopPage) GetContent() fyne.CanvasObject {
	title := canvas.NewText("获取宝石", color.Black)
	title.TextSize = 27

	showbaoshi := canvas.NewText(
		"宝石: "+global.File_BaoshiReader.ReadStrSafe(),
	simple.Blue)
	showbaoshi.TextSize = 20

	btnBack := widget.NewButton("返回", func(){
		p.router(interfaces.PageID_OwnThingBaoshiPage)
	})

	vbox := container.NewVBox(
		simple.HorizonCenter(title),
		simple.Spacer(20),
		simple.HorizonCenter(showbaoshi),
		simple.Spacer(150),
		container.NewGridWithColumns(3, 
		),
		simple.Spacer(100),
		simple.HorizonRight(btnBack),
		layout.NewSpacer(),
	)

    return container.NewBorder(
		vbox, 
		nil, nil, nil, nil, 
	)
}

func (p *OwnThingBaoshiShopPage) GetID() interfaces.PageID {
    return interfaces.PageID_OwnThingBaoshiShopPage
}

func (p *OwnThingBaoshiShopPage) SetRouter(fn func(interfaces.PageID)) {
    p.router = fn
}
