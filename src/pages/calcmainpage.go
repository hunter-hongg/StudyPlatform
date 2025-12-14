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

type CalcMainPage struct {
    router func(interfaces.PageID)
}

func NewCalcMainPage() *CalcMainPage {
    return &CalcMainPage{}
}

func (p *CalcMainPage) GetContent() fyne.CanvasObject {
	title := canvas.NewText("计算广场", color.Black)
	title.TextSize = 27

	showjifen := canvas.NewText(
		"计算币: "+global.File_JiSuanBiReader.ReadStrSafe(),
	simple.Blue)
	showjifen.TextSize = 20

	// showlevel := canvas.NewText(
	// 	"等级: "+strconv.Itoa(jifen.GetLevelFromJifen(global.File_JiFenReader.ReadIntSafe())),
	// simple.Blue)
	// showlevel.TextSize = 20

	btnBack := widget.NewButton("返回", func(){
		p.router(interfaces.PageID_MainPage)
	})

	btnToStart := widget.NewButton("开始计算", func(){
		// p.router(interfaces.PageID_TimerMainPage)
	})

	btnToDui := widget.NewButton("兑换物品", func(){
		// p.router(interfaces.PageID_TongMainPage)
	})

	vbox := container.NewVBox(
		simple.HorizonCenter(title),
		simple.Spacer(20),
		simple.HorizonCenter(showjifen),
		simple.Spacer(150),
		simple.HorizonCenter(btnToStart),
		simple.HorizonCenter(btnToDui),
		simple.Spacer(100),
		simple.HorizonRight(btnBack),
		layout.NewSpacer(),
	)

    return container.NewBorder(
		vbox, 
		nil, nil, nil, nil, 
	)
}

func (p *CalcMainPage) GetID() interfaces.PageID {
    return interfaces.PageID_CalcMainPage
}

func (p *CalcMainPage) SetRouter(fn func(interfaces.PageID)) {
    p.router = fn
}
