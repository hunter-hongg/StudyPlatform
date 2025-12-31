package pages

import (
	"StudyPlatform/internal/interfaces"
	"StudyPlatform/pkg/simple"

	"image/color"

	"fyne.io/fyne/v2"
	"fyne.io/fyne/v2/canvas"
	"fyne.io/fyne/v2/container"
	"fyne.io/fyne/v2/layout"
	"fyne.io/fyne/v2/widget"
)

type AncientGuanWuMainPage struct {
    router func(interfaces.PageID)
}

func NewAncientGuanWuMainPage() *AncientGuanWuMainPage {
    return &AncientGuanWuMainPage{}
}

func (p *AncientGuanWuMainPage) GetContent() fyne.CanvasObject {
	title := canvas.NewText("我的官职", color.Black)
	title.TextSize = 27
	
	showtong := canvas.NewText(
		"官职类型: 武官",
	simple.Blue)
	showtong.TextSize = 20
	
	// showb := canvas.NewText(
	// 	"品级: "+strconv.Itoa(global.File_AncientWenGuan.ReadLevel())+"级",
	// simple.Blue)
	// showb.TextSize = 20

	btnBack := widget.NewButton("返回", func(){
		p.router(interfaces.PageID_AncientGuanMainPage)
	})

	btn0 := widget.NewButton("征召士兵", func(){
		p.router(interfaces.PageID_AncientGuanWuZhaobingPage)
	})
	
	btn1 := widget.NewButton("增强兵力", func(){
		p.router(interfaces.PageID_AncientGuanWuZengbingPage)
	})
	
	btn2 := widget.NewButton("领兵出征", func(){
		p.router(interfaces.PageID_AncientGuanWuChuzhengPage)
	})
	
	vbox := container.NewVBox(
		simple.HorizonCenter(title),
		simple.Spacer(20),
		simple.HorizonCenter(showtong),
		simple.Spacer(130),
		simple.HorizonCenter(btn0),
		simple.HorizonCenter(btn1),
		simple.HorizonCenter(btn2),
		simple.Spacer(100),
		simple.HorizonRight(btnBack),
		layout.NewSpacer(),
	)

    return container.NewBorder(
		vbox, 
		nil, nil, nil, nil, 
	)
}

func (p *AncientGuanWuMainPage) GetID() interfaces.PageID {
    return interfaces.PageID_AncientGuanWuMainPage
}

func (p *AncientGuanWuMainPage) SetRouter(fn func(interfaces.PageID)) {
    p.router = fn
}
