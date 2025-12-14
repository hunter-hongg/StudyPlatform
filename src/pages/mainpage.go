package pages

import (
	"StudyPlatform/src/interfaces"
	"StudyPlatform/src/pkg/global"
	"StudyPlatform/src/pkg/simple"
	"StudyPlatform/src/pkg/jifen"

	"strconv"
	"image/color"

	"fyne.io/fyne/v2"
	"fyne.io/fyne/v2/canvas"
	"fyne.io/fyne/v2/container"
	"fyne.io/fyne/v2/layout"
	"fyne.io/fyne/v2/widget"
)

type MainPage struct {
    router func(interfaces.PageID)
}

func NewMainPage() *MainPage {
    return &MainPage{}
}

func (p *MainPage) GetContent() fyne.CanvasObject {
	title := canvas.NewText("欢迎"+global.User+"来到学习平台", color.Black)
	title.TextSize = 35

	showjifen := canvas.NewText("积分: "+global.File_JiFenReader.ReadStrSafe(), simple.Blue)
	showjifen.TextSize = 20

	showlevel := canvas.NewText(
		"等级: "+strconv.Itoa(jifen.GetLevelFromJifen(global.File_JiFenReader.ReadIntSafe())),
	simple.Blue)
	showlevel.TextSize = 20

	btnToOwn := widget.NewButton("个人主页", func(){
		p.router(interfaces.PageID_OwnPage)
	})

	btnToShen := widget.NewButton("神话传说", func(){
		// p.router(interfaces.PageID_OwnPage)
	})

	btnToCalc := widget.NewButton("计算广场", func(){
		p.router(interfaces.PageID_CalcMainPage)
	})

	vbox := container.NewVBox(
		simple.HorizonCenter(title),
		simple.Spacer(20),
		simple.HorizonCenter(showjifen),
		simple.HorizonCenter(showlevel),
		simple.Spacer(130),
		container.NewGridWithColumns(2, 
			simple.HorizonRight(btnToOwn),
			simple.HorizonLeft(btnToShen),
			simple.HorizonRight(btnToCalc),
		),
		layout.NewSpacer(),
	)

    return container.NewBorder(
		vbox, 
		nil, nil, nil, nil, 
	)
}

func (p *MainPage) GetID() interfaces.PageID {
    return interfaces.PageID_MainPage
}

func (p *MainPage) SetRouter(fn func(interfaces.PageID)) {
    p.router = fn
}

