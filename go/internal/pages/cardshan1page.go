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

type OwnThingCardsHan1Page struct {
    router func(interfaces.PageID)
}

func NewOwnThingCardsHan1Page() *OwnThingCardsHan1Page {
    return &OwnThingCardsHan1Page{}
}

func (p *OwnThingCardsHan1Page) GetContent() fyne.CanvasObject {
	global.Logger.Debug("正常启动")

	title := canvas.NewText("汉朝卡牌1", color.Black)
	title.TextSize = 27

	btnBack := widget.NewButton("返回", func(){
		p.router(interfaces.PageID_OwnThingCardsMainPage)
	})

	var cards []fyne.CanvasObject

	gett := global.File_Han1Card.Get()
	for _, i := range gett {
		cards = append(cards, simple.HorizonCenter(widget.NewButton(i+"\n珍藏", func(){})))
	}
	
	vbox := container.NewVBox(
		simple.HorizonCenter(title),
		simple.Spacer(200),
		container.NewGridWithColumns(10, cards...),
		simple.Spacer(100),
		simple.HorizonRight(btnBack),
		layout.NewSpacer(),
	)

    return container.NewBorder(
		vbox, 
		nil, nil, nil, nil, 
	)
}

func (p *OwnThingCardsHan1Page) GetID() interfaces.PageID {
    return interfaces.PageID_OwnThingCardsHan1Page
}

func (p *OwnThingCardsHan1Page) SetRouter(fn func(interfaces.PageID)) {
    p.router = fn
}
