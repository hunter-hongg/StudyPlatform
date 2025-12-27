package pages

import (
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

type AncientGuanWenMainPage struct {
    router func(interfaces.PageID)
}

func NewAncientGuanWenMainPage() *AncientGuanWenMainPage {
    return &AncientGuanWenMainPage{}
}

func (p *AncientGuanWenMainPage) GetContent() fyne.CanvasObject {
	title := canvas.NewText("我的官职", color.Black)
	title.TextSize = 27

	showtong := canvas.NewText(
		"官职类型: 文官",
	simple.Blue)
	showtong.TextSize = 20

	showb := canvas.NewText(
		"品级: "+strconv.Itoa(global.File_AncientWenGuan.ReadLevel())+"级",
	simple.Blue)
	showb.TextSize = 20

	btnBack := widget.NewButton("返回", func(){
		p.router(interfaces.PageID_AncientGuanMainPage)
	})

	btn0 := widget.NewButton("我的俸禄", func(){
		if !global.File_AncientWenFengCheck.CheckTimes() {
			simple.DialogInfo("今日已领取俸禄", global.Main_Window)
			return
		}
		feng := global.File_AncientWenGuan.GetFengLu()
		global.File_AncientHuangJinReader.AddNum(feng)
		simple.DialogInfo("成功领取"+strconv.Itoa(feng)+"两黄金", global.Main_Window)
	})
	
	btn1 := widget.NewButton("我的政绩", func(){
		p.router(interfaces.PageID_AncientGuanWenZhengPage)
	})
	
	vbox := container.NewVBox(
		simple.HorizonCenter(title),
		simple.Spacer(20),
		simple.HorizonCenter(showtong),
		simple.HorizonCenter(showb),
		simple.Spacer(120),
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

func (p *AncientGuanWenMainPage) GetID() interfaces.PageID {
    return interfaces.PageID_AncientGuanWenMainPage
}

func (p *AncientGuanWenMainPage) SetRouter(fn func(interfaces.PageID)) {
    p.router = fn
}
