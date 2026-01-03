package pages

import (
	"StudyPlatform/internal/interfaces"
	"StudyPlatform/internal/global"
	"StudyPlatform/pkg/simple"

	_ "fmt"
	"image/color"

	"fyne.io/fyne/v2"
	"fyne.io/fyne/v2/canvas"
	"fyne.io/fyne/v2/container"
	"fyne.io/fyne/v2/layout"
	"fyne.io/fyne/v2/widget"
)

type OwnThingBaoshiPage struct {
    router func(interfaces.PageID)
}

func NewOwnThingBaoshiPage() *OwnThingBaoshiPage {
    return &OwnThingBaoshiPage{}
}

func (p *OwnThingBaoshiPage) GetContent() fyne.CanvasObject {
	global.Logger.Debug("正常启动")

	title := canvas.NewText("我的宝石", color.Black)
	title.TextSize = 27

	showbaoshi := canvas.NewText("宝石: "+global.File_BaoshiReader.ReadStrSafe(), simple.Blue)
	showbaoshi.TextSize = 20

	btnBack := widget.NewButton("返回", func(){
		p.router(interfaces.PageID_OwnThingPagePage)
	})
	
	btnGet := widget.NewButton("获取宝石", func() {
		p.router(interfaces.PageID_OwnThingBaoshiShopPage)
	})
	btnChou := widget.NewButton("宝石抽奖", func() {
		p.router(interfaces.PageID_OwnThingBaoshiChouAllPage)
	})

	vbox := container.NewVBox(
		simple.HorizonCenter(title),
		simple.Spacer(20),
		simple.HorizonCenter(showbaoshi),
		simple.Spacer(130),
		simple.HorizonCenter(btnGet),
		simple.HorizonCenter(btnChou),
		simple.Spacer(100),
		simple.HorizonRight(btnBack),
		layout.NewSpacer(),
	)

    return container.NewBorder(
		vbox, 
		nil, nil, nil, nil, 
	)
}

func (p *OwnThingBaoshiPage) GetID() interfaces.PageID {
    return interfaces.PageID_OwnThingBaoshiPage
}

func (p *OwnThingBaoshiPage) SetRouter(fn func(interfaces.PageID)) {
    p.router = fn
}
