package pages

import (
	"StudyPlatform/src/interfaces"
	_"StudyPlatform/src/pkg/global"
	_"StudyPlatform/src/pkg/jifen"
	"StudyPlatform/src/pkg/simple"
	_"strconv"

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

	// showjifen := canvas.NewText(
	// 	"积分: "+global.File_JiFenReader.ReadStrSafe(),	
	// simple.Blue)
	// showjifen.TextSize = 20
	//
	// showlevel := canvas.NewText(
	// 	"等级: "+strconv.Itoa(jifen.GetLevelFromJifen(global.File_JiFenReader.ReadIntSafe())),
	// simple.Blue)
	// showlevel.TextSize = 20

	btnBack := widget.NewButton("返回", func(){
		p.router(interfaces.PageID_OwnPage)
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
		// simple.HorizonCenter(showjifen),
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

func (p *TongMainPage) GetID() interfaces.PageID {
    return interfaces.PageID_TongMainPage
}

func (p *TongMainPage) SetRouter(fn func(interfaces.PageID)) {
    p.router = fn
}
