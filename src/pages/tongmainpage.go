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

type TongMainPage struct {
    router func(interfaces.PageID)
}

func NewTongMainPage() *TongMainPage {
    return &TongMainPage{}
}

func (p *TongMainPage) GetContent() fyne.CanvasObject {
	title := canvas.NewText("通用货币", color.Black)
	title.TextSize = 27

	showtong := canvas.NewText(
		"通用货币: "+global.File_TongYongReader.ReadStrSafe(),
	simple.Blue)
	showtong.TextSize = 20
	//
	// showlevel := canvas.NewText(
	// 	"等级: "+strconv.Itoa(jifen.GetLevelFromJifen(global.File_JiFenReader.ReadIntSafe())),
	// simple.Blue)
	// showlevel.TextSize = 20

	btnBack := widget.NewButton("返回", func(){
		p.router(interfaces.PageID_OwnPage)
	})

	btnDuiJifen := widget.NewButton("积分兑换", func(){
		p.router(interfaces.PageID_TongJifenPage)
	})
	btnRule := widget.NewButton("兑换规则", func(){
		rule := ""+
				"通用货币兑换规则: \n"+
				"1000积分 1通用货币"
		simple.DialogInfo(rule, global.Main_Window)
	})

	vbox := container.NewVBox(
		simple.HorizonCenter(title),
		simple.Spacer(20),
		simple.HorizonCenter(showtong),
		// simple.HorizonCenter(showlevel),
		simple.Spacer(150),
		simple.HorizonCenter(btnRule),
		simple.HorizonCenter(btnDuiJifen),
		simple.Spacer(100),
		simple.HorizonRight(btnBack),
		layout.NewSpacer(),
	)

    return container.NewBorder(
		vbox, 
		nil, nil, nil, nil, 
	)
}

func (p *TongMainPage) GetID() interfaces.PageID {
    return interfaces.PageID_TongMainPage
}

func (p *TongMainPage) SetRouter(fn func(interfaces.PageID)) {
    p.router = fn
}
