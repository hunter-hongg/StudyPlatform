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

type OwnThingBaoshiChouAllPage struct {
    router func(interfaces.PageID)
}

func NewOwnThingBaoshiChouAllPage() *OwnThingBaoshiChouAllPage {
    return &OwnThingBaoshiChouAllPage{}
}

func (p *OwnThingBaoshiChouAllPage) GetContent() fyne.CanvasObject {
	global.Logger.Debug("正常启动")

	title := canvas.NewText("宝石抽奖", color.Black)
	title.TextSize = 27

	showbaoshi := canvas.NewText("宝石: "+global.File_BaoshiReader.ReadStrSafe(), simple.Blue)
	showbaoshi.TextSize = 20

	btnBack := widget.NewButton("返回", func(){
		p.router(interfaces.PageID_OwnThingBaoshiPage)
	})
	
	btnChou1 := widget.NewButton("宝石抽奖1", func() {
		p.router(interfaces.PageID_OwnThingBaoshiChou1Page)
	})

	vbox := container.NewVBox(
		simple.HorizonCenter(title),
		simple.Spacer(20),
		simple.HorizonCenter(showbaoshi),
		simple.Spacer(130),
		simple.HorizonCenter(btnChou1),
		simple.Spacer(100),
		simple.HorizonRight(btnBack),
		layout.NewSpacer(),
	)

    return container.NewBorder(
		vbox, 
		nil, nil, nil, nil, 
	)
}

func (p *OwnThingBaoshiChouAllPage) GetID() interfaces.PageID {
    return interfaces.PageID_OwnThingBaoshiChouAllPage
}

func (p *OwnThingBaoshiChouAllPage) SetRouter(fn func(interfaces.PageID)) {
    p.router = fn
}
