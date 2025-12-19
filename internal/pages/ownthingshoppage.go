package pages

import (
	"StudyPlatform/internal/global"
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

type OwnThingShopPage struct {
    router func(interfaces.PageID)
}

func NewOwnThingShopPage() *OwnThingShopPage {
    return &OwnThingShopPage{}
}

func (p *OwnThingShopPage) GetContent() fyne.CanvasObject {
	global.Logger.Debug("正常启动")

	title := canvas.NewText("物品商城", color.Black)
	title.TextSize = 27

	btnBack := widget.NewButton("返回", func(){
		p.router(interfaces.PageID_OwnThingMainPage)
	})

	btnSold1 := widget.NewButton("50积分 => 三国卡牌1*3", func() {

	})

	vbox := container.NewVBox(
		simple.HorizonCenter(title),
		simple.Spacer(200),
		container.NewGridWithColumns(3, 
			simple.HorizonRight(btnSold1),
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

func (p *OwnThingShopPage) GetID() interfaces.PageID {
    return interfaces.PageID_OwnThingShopPage
}

func (p *OwnThingShopPage) SetRouter(fn func(interfaces.PageID)) {
    p.router = fn
}
