package pages

import (
	"StudyPlatform/internal/global"
	"StudyPlatform/internal/interfaces"
	"StudyPlatform/pkg/simple"

	"image/color"

	"fyne.io/fyne/v2"
	"fyne.io/fyne/v2/canvas"
	"fyne.io/fyne/v2/container"
	"fyne.io/fyne/v2/layout"
	"fyne.io/fyne/v2/widget"
)

type XianQiMainPage struct {
    router func(interfaces.PageID)
}

func NewXianQiMainPage() *XianQiMainPage {
    return &XianQiMainPage{}
}

func (p *XianQiMainPage) GetContent() fyne.CanvasObject {
	title := canvas.NewText("我的仙器", color.Black)
	title.TextSize = 27

	showx := canvas.NewText(
		"仙器法力: "+global.File_XianQiFaLiReader.ReadStrSafe(),	
	simple.Blue)
	showx.TextSize = 20

	showt := canvas.NewText(
		"当前仙器: "+global.File_XianSword.Get().String(),
	simple.Blue)
	showt.TextSize = 20

	btnBack := widget.NewButton("返回", func(){
		p.router(interfaces.PageID_XianThingMainPage)
	})

	btnT := widget.NewButton("更换仙器", func(){
		p.router(interfaces.PageID_XianQiChangePage)
	})
	
	btnN := widget.NewButton("增强法力", func(){
		simple.DialogInfo("请使用仙籍增强仙器法力", global.Main_Window)
	})

	vbox := container.NewVBox(
		simple.HorizonCenter(title),
		simple.Spacer(20),
		simple.HorizonCenter(showt),
		simple.HorizonCenter(showx),
		simple.Spacer(100),
		simple.HorizonCenter(btnT),
		simple.HorizonCenter(btnN),
		simple.Spacer(100),
		simple.HorizonRight(btnBack),
		layout.NewSpacer(),
	)

    return container.NewBorder(
		vbox, 
		nil, nil, nil, nil, 
	)
}

func (p *XianQiMainPage) GetID() interfaces.PageID {
    return interfaces.PageID_XianQiMainPage
}

func (p *XianQiMainPage) SetRouter(fn func(interfaces.PageID)) {
    p.router = fn
}
