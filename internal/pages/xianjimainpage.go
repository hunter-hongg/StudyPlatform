package pages

import (
	"StudyPlatform/internal/global"
	"StudyPlatform/internal/interfaces"
	"StudyPlatform/pkg/simple"
	"StudyPlatform/pkg/util"

	"image/color"

	"fyne.io/fyne/v2"
	"fyne.io/fyne/v2/canvas"
	"fyne.io/fyne/v2/container"
	"fyne.io/fyne/v2/layout"
	"fyne.io/fyne/v2/widget"
)

type XianJiMainPage struct {
    router func(interfaces.PageID)
}

func NewXianJiMainPage() *XianJiMainPage {
    return &XianJiMainPage{}
}

func (p *XianJiMainPage) GetContent() fyne.CanvasObject {
	title := canvas.NewText("我的仙籍", color.Black)
	title.TextSize = 27

	dealUp := func(fp *util.FilePassword, an int) {
		if res, err := global.File_XianJiReader.CanMinus(10) ; (!res) || (err != nil) {
			simple.DialogInfo("取出仙籍失败", global.Main_Window)
			return
		}
		fp.AddNum(an)
		simple.DialogInfo("使用成功", global.Main_Window)
		p.router(interfaces.PageID_XianJiMainPage)
	}

	showx := canvas.NewText(
		"仙籍: "+global.File_XianJiReader.ReadStrSafe(),	
	simple.Blue)
	showx.TextSize = 20

	btnBack := widget.NewButton("返回", func(){
		p.router(interfaces.PageID_XianThingMainPage)
	})
	
	btnT := widget.NewButton("购买仙籍", func(){
		/* 20本仙籍 5仙币 */
		deal := func(){
			if res, err := global.File_XianBiReader.CanMinus(5); (!res) || (err != nil) {
				simple.DialogInfo("取出仙币失败", global.Main_Window)
				return
			}
			global.File_XianJiReader.AddNum(20)
			simple.DialogInfo("购买成功", global.Main_Window)
			p.router(interfaces.PageID_XianJiMainPage)
		}
		simple.DialogQuestion("是否花费5仙币购买20仙籍?",global.Main_Window, deal, func(){})
	})
	
	btnN := widget.NewButton("增强法力", func(){
		// 10仙籍 => 100法力
		simple.DialogQuestion(
			"是否使用10仙籍获得100法力?", global.Main_Window, 
			func() {
				dealUp(global.File_XianFaLiReader, 100)
			}, func(){},
		)
	})

	btnD := widget.NewButton("增强仙器", func(){
		// 10仙籍 => 90法力
		simple.DialogQuestion(
			"是否使用10仙籍获得90仙器法力?", global.Main_Window, 
			func() {
				dealUp(global.File_XianQiFaLiReader, 90)
			}, func(){},
		)
	})
	
	vbox := container.NewVBox(
		simple.HorizonCenter(title),
		simple.Spacer(20),
		simple.HorizonCenter(showx),
		simple.Spacer(130),
		simple.HorizonCenter(btnT),
		simple.HorizonCenter(btnN),
		simple.HorizonCenter(btnD),
		simple.Spacer(100),
		simple.HorizonRight(btnBack),
		layout.NewSpacer(),
	)

    return container.NewBorder(
		vbox, 
		nil, nil, nil, nil, 
	)
}

func (p *XianJiMainPage) GetID() interfaces.PageID {
    return interfaces.PageID_XianJiMainPage
}

func (p *XianJiMainPage) SetRouter(fn func(interfaces.PageID)) {
    p.router = fn
}
