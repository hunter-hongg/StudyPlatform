package pages

import (
	"StudyPlatform/src/interfaces"
	"StudyPlatform/src/pkg/global"
	"StudyPlatform/src/pkg/simple"

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

	btnBack := widget.NewButton("返回", func(){
		p.router(interfaces.PageID_MainPage)
	})

	// btnToTimer := widget.NewButton("学习计时", func(){
	// 	p.router(interfaces.PageID_TimerMainPage)
	// })
	//
	// btnToTongMain := widget.NewButton("通用货币", func(){
	// 	p.router(interfaces.PageID_TongMainPage)
	// })

	vbox := container.NewVBox(
		simple.HorizonCenter(title),
		simple.Spacer(20),
		simple.HorizonCenter(showtong),
		// simple.HorizonCenter(showlevel),
		simple.Spacer(130),
		// simple.HorizonCenter(btnToTimer),
		// simple.HorizonCenter(btnToTongMain),
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
