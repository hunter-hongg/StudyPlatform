package pages

import (
	"StudyPlatform/internal/interfaces"
	"StudyPlatform/internal/global"
	"StudyPlatform/internal/jifen"
	"StudyPlatform/pkg/simple"

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
	title := canvas.NewText("欢迎"+global.User+"来到多重平台", color.Black)
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
		p.router(interfaces.PageID_XianMainPage)
	})

	btnToCalc := widget.NewButton("计算广场", func(){
		p.router(interfaces.PageID_CalcMainPage)
	})

	btnToAncient := widget.NewButton("古代广场", func(){
		p.router(interfaces.PageID_AncientMainPage)
	})

	btnBank := widget.NewButton("积分银行", func() {
		p.router(interfaces.PageID_BankMainPage)
	})

	btnTs := widget.NewButton("物品领取", func() {
		p.router(interfaces.PageID_ThingSquareMainPage)
	})
	btnToTools := widget.NewButton("工具页面", func() {
		if global.File_SettingEnableUtil.GetState(true){
			p.router(interfaces.PageID_ToolsPage)
		} else {
			simple.DialogInfo("工具已禁用 请前往设置开启", global.Main_Window)
		}
	})
	btnToSetting := widget.NewButton("设置界面", func(){
		p.router(interfaces.PageID_SettingMainPage)
	})

	vbox := container.NewVBox(
		simple.HorizonCenter(title),
		simple.Spacer(20),
		simple.HorizonCenter(showjifen),
		simple.HorizonCenter(showlevel),
		simple.Spacer(100),
		container.NewGridWithColumns(2, 
			simple.HorizonRight(btnToOwn),
			simple.HorizonLeft(btnToShen),
			simple.HorizonRight(btnToCalc),
			simple.HorizonLeft(btnToAncient),
			simple.HorizonRight(btnTs),
			simple.HorizonLeft(btnBank),
			simple.HorizonRight(btnToTools),
			simple.HorizonLeft(btnToSetting),
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

