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

type OwnThingCardsMainPage struct {
    router func(interfaces.PageID)
}

func NewOwnThingCardsMainPage() *OwnThingCardsMainPage {
    return &OwnThingCardsMainPage{}
}

func (p *OwnThingCardsMainPage) GetContent() fyne.CanvasObject {
	global.Logger.Debug("正常启动")

	title := canvas.NewText("我的卡牌", color.Black)
	title.TextSize = 27

	btnBack := widget.NewButton("返回", func(){
		p.router(interfaces.PageID_OwnThingPagePage)
	})
	
	btnCards := widget.NewButton("三国卡牌1", func() {
		p.router(interfaces.PageID_OwnThingCardsSanGuo1Page)
	})
	
	btnCards2 := widget.NewButton("汉朝卡牌1", func() {
		p.router(interfaces.PageID_OwnThingCardsHan1Page)
	})
	
	vbox := container.NewVBox(
		simple.HorizonCenter(title),
		simple.Spacer(200),
		simple.HorizonCenter(btnCards),
		simple.HorizonCenter(btnCards2),
		simple.Spacer(100),
		simple.HorizonRight(btnBack),
		layout.NewSpacer(),
	)

    return container.NewBorder(
		vbox, 
		nil, nil, nil, nil, 
	)
}

func (p *OwnThingCardsMainPage) GetID() interfaces.PageID {
    return interfaces.PageID_OwnThingCardsMainPage
}

func (p *OwnThingCardsMainPage) SetRouter(fn func(interfaces.PageID)) {
    p.router = fn
}
