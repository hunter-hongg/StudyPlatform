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

type OwnThingPagePage struct {
    router func(interfaces.PageID)
}

func NewOwnThingPagePage() *OwnThingPagePage {
    return &OwnThingPagePage{}
}

func (p *OwnThingPagePage) GetContent() fyne.CanvasObject {
	global.Logger.Debug("正常启动")

	title := canvas.NewText("物品主页", color.Black)
	title.TextSize = 27

	btnBack := widget.NewButton("返回", func(){
		p.router(interfaces.PageID_OwnThingMainPage)
	})
	
	btnCards := widget.NewButton("我的卡牌", func() {
		p.router(interfaces.PageID_OwnThingCardsMainPage)
	})
	btnYinbi := widget.NewButton("我的银币", func() {
		p.router(interfaces.PageID_OwnThingYinbiPage)
	})
	btnBaoshi := widget.NewButton("我的宝石", func() {
		p.router(interfaces.PageID_OwnThingBaoshiPage)
	})

	vbox := container.NewVBox(
		simple.HorizonCenter(title),
		simple.Spacer(200),
		simple.HorizonCenter(btnYinbi),
		simple.HorizonCenter(btnBaoshi),
		simple.HorizonCenter(btnCards),
		simple.Spacer(100),
		simple.HorizonRight(btnBack),
		layout.NewSpacer(),
	)

    return container.NewBorder(
		vbox, 
		nil, nil, nil, nil, 
	)
}

func (p *OwnThingPagePage) GetID() interfaces.PageID {
    return interfaces.PageID_OwnThingPagePage
}

func (p *OwnThingPagePage) SetRouter(fn func(interfaces.PageID)) {
    p.router = fn
}
