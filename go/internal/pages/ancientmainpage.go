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

type AncientMainPage struct {
    router func(interfaces.PageID)
}

func NewAncientMainPage() *AncientMainPage {
    return &AncientMainPage{}
}

func (p *AncientMainPage) GetContent() fyne.CanvasObject {
	title := canvas.NewText("古代广场", color.Black)
	title.TextSize = 27

	showtong := canvas.NewText(
		"铜钱: "+global.File_TongQianReader.ReadStrSafe(),
	simple.Blue)
	showtong.TextSize = 20

	showb := canvas.NewText(
		"白银: "+global.File_AncientBaiYinReader.ReadStrSafe(),
	simple.Blue)
	showb.TextSize = 20

	showj := canvas.NewText(
		"黄金: "+global.File_AncientHuangJinReader.ReadStrSafe(),
	simple.Blue)
	showj.TextSize = 20

	btnBack := widget.NewButton("返回", func(){
		p.router(interfaces.PageID_MainPage)
	})

	btn0 := widget.NewButton("我的物品", func(){
		p.router(interfaces.PageID_AncientThingMainPage)
	})
	
	btn1 := widget.NewButton("古代店铺", func(){
		p.router(interfaces.PageID_AncientShopMainPage)
	})
	
	btn2 := widget.NewButton("我的捐献", func(){
		p.router(interfaces.PageID_AncientJuanMainPage)
	})

	btn3 := widget.NewButton("物品使用", func(){
		p.router(interfaces.PageID_AncientSoldMainPage)
	})

	btn4 := widget.NewButton("我的官职", func(){
		p.router(interfaces.PageID_AncientGuanMainPage)
	})

	vbox := container.NewVBox(
		simple.HorizonCenter(title),
		simple.Spacer(20),
		simple.HorizonCenter(showtong),
		simple.HorizonCenter(showb),
		simple.HorizonCenter(showj),
		simple.Spacer(70),
		simple.HorizonCenter(btn0),
		simple.HorizonCenter(btn1),
		simple.HorizonCenter(btn4),
		simple.HorizonCenter(btn2),
		simple.HorizonCenter(btn3),
		simple.Spacer(100),
		simple.HorizonRight(btnBack),
		layout.NewSpacer(),
	)

    return container.NewBorder(
		vbox, 
		nil, nil, nil, nil, 
	)
}

func (p *AncientMainPage) GetID() interfaces.PageID {
    return interfaces.PageID_AncientMainPage
}

func (p *AncientMainPage) SetRouter(fn func(interfaces.PageID)) {
    p.router = fn
}
