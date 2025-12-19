package pages

import (
	"StudyPlatform/internal/global"
	"StudyPlatform/internal/interfaces"
	"StudyPlatform/pkg/simple"
	"strconv"

	_ "fmt"
	"image/color"

	"fyne.io/fyne/v2"
	"fyne.io/fyne/v2/canvas"
	"fyne.io/fyne/v2/container"
	"fyne.io/fyne/v2/layout"
	"fyne.io/fyne/v2/widget"
)

type OwnThingAllPage struct {
    router func(interfaces.PageID)
}

func NewOwnThingAllPage() *OwnThingAllPage {
    return &OwnThingAllPage{}
}

func (p *OwnThingAllPage) GetContent() fyne.CanvasObject {
	global.Logger.Debug("正常启动")

	cardCount := len(global.File_Han1Card.Get()) +
				 len(global.File_SanGuo1Card.Get())

	title := canvas.NewText("物品查看", color.Black)
	title.TextSize = 27

	btnBack := widget.NewButton("返回", func(){
		p.router(interfaces.PageID_OwnThingMainPage)
	})

	btnJifen := widget.NewButton("积分: "+global.File_JiFenReader.ReadStrSafe(), func(){})
	btnJinbi := widget.NewButton("金币: "+global.File_JinBiReader.ReadStrSafe(), func(){})
	btnCards := widget.NewButton("卡牌: "+strconv.Itoa(cardCount)+"张", func(){})

	vbox := container.NewVBox(
		simple.HorizonCenter(title),
		simple.Spacer(200),
		container.NewGridWithColumns(3, 
			btnJifen, layout.NewSpacer(), layout.NewSpacer(),
			layout.NewSpacer(), btnJinbi, layout.NewSpacer(), 
			layout.NewSpacer(), btnCards, layout.NewSpacer(), 
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

func (p *OwnThingAllPage) GetID() interfaces.PageID {
    return interfaces.PageID_OwnThingAllPage
}

func (p *OwnThingAllPage) SetRouter(fn func(interfaces.PageID)) {
    p.router = fn
}
