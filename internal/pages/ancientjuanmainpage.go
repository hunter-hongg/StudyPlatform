package pages

import (
	"StudyPlatform/internal/gfunc"
	"StudyPlatform/internal/global"
	"StudyPlatform/internal/interfaces"
	"StudyPlatform/pkg/simple"
	"strconv"

	"image/color"

	"fyne.io/fyne/v2"
	"fyne.io/fyne/v2/canvas"
	"fyne.io/fyne/v2/container"
	"fyne.io/fyne/v2/layout"
	"fyne.io/fyne/v2/widget"
)

type AncientJuanMainPage struct {
    router func(interfaces.PageID)
}

func NewAncientJuanMainPage() *AncientJuanMainPage {
    return &AncientJuanMainPage{}
}

func (p *AncientJuanMainPage) GetContent() fyne.CanvasObject {
	title := canvas.NewText("我的捐献", color.Black)
	title.TextSize = 27

	showtong := canvas.NewText(
		"捐献值: "+global.File_AncientJuanReader.ReadStrSafe(),
	simple.Blue)
	showtong.TextSize = 20

	showb := canvas.NewText(
		"等级: "+strconv.Itoa(gfunc.JuanGetLevel(global.File_AncientJuanReader.ReadIntSafe())),
	simple.Blue)
	showb.TextSize = 20

	btnBack := widget.NewButton("返回", func(){
		p.router(interfaces.PageID_AncientMainPage)
	})

	btn0 := widget.NewButton("捐献古玩", func(){
		p.router(interfaces.PageID_AncientJuanRealPage)
	})
	
	btn1 := widget.NewButton("领取奖励", func(){
	})
	
	vbox := container.NewVBox(
		simple.HorizonCenter(title),
		simple.Spacer(20),
		simple.HorizonCenter(showtong),
		simple.HorizonCenter(showb),
		simple.Spacer(100),
		simple.HorizonCenter(btn0),
		simple.HorizonCenter(btn1),
		simple.Spacer(100),
		simple.HorizonRight(btnBack),
		layout.NewSpacer(),
	)

    return container.NewBorder(
		vbox, 
		nil, nil, nil, nil, 
	)
}

func (p *AncientJuanMainPage) GetID() interfaces.PageID {
    return interfaces.PageID_AncientJuanMainPage
}

func (p *AncientJuanMainPage) SetRouter(fn func(interfaces.PageID)) {
    p.router = fn
}
