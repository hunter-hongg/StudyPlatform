package pages

import (
	"StudyPlatform/src/interfaces"
	"StudyPlatform/src/pkg/global"
	"StudyPlatform/src/pkg/jifen"
	"StudyPlatform/src/pkg/simple"
	"strconv"

	"image/color"

	"fyne.io/fyne/v2"
	"fyne.io/fyne/v2/canvas"
	"fyne.io/fyne/v2/container"
	"fyne.io/fyne/v2/layout"
	"fyne.io/fyne/v2/widget"
)

type OwnPage struct {
    router func(interfaces.PageID)
}

func NewOwnPage() *OwnPage {
    return &OwnPage{}
}

func (p *OwnPage) GetContent() fyne.CanvasObject {
	title := canvas.NewText("个人主页", color.Black)
	title.TextSize = 27

	showjifen := canvas.NewText(
		"积分: "+global.File_JiFenReader.ReadStrSafe(),	
	simple.Blue)
	showjifen.TextSize = 20

	showlevel := canvas.NewText(
		"等级: "+strconv.Itoa(jifen.GetLevelFromJifen(global.File_JiFenReader.ReadIntSafe())),
	simple.Blue)
	showlevel.TextSize = 20

	btnBack := widget.NewButton("返回", func(){
		p.router(interfaces.PageID_MainPage)
	})

	btnToTimer := widget.NewButton("学习计时", func(){
		p.router(interfaces.PageID_TimerMainPage)
	})

	btnToThings := widget.NewButton("所有物品", func(){
		p.router(interfaces.PageID_OwnThingMainPage)
	})

	btnToTongMain := widget.NewButton("通用货币", func(){
		p.router(interfaces.PageID_TongMainPage)
	})

	vbox := container.NewVBox(
		simple.HorizonCenter(title),
		simple.Spacer(20),
		simple.HorizonCenter(showjifen),
		simple.HorizonCenter(showlevel),
		simple.Spacer(130),
		simple.HorizonCenter(btnToTimer),
		simple.HorizonCenter(btnToThings),
		simple.HorizonCenter(btnToTongMain),
		simple.Spacer(100),
		simple.HorizonRight(btnBack),
		layout.NewSpacer(),
	)

    return container.NewBorder(
		vbox, 
		nil, nil, nil, nil, 
	)
}

func (p *OwnPage) GetID() interfaces.PageID {
    return interfaces.PageID_OwnPage
}

func (p *OwnPage) SetRouter(fn func(interfaces.PageID)) {
    p.router = fn
}
