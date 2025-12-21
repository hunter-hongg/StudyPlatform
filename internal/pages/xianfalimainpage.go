package pages

/*
法力炼丹基准数额
20 => 1普通丹 to 15 => 1普通丹 
45 => 1碧丹   to 35 => 1碧丹
100 => 1青丹  to 80 => 1青丹
*/

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

type XianFaliMainPage struct {
    router func(interfaces.PageID)
}

func NewXianFaliMainPage() *XianFaliMainPage {
    return &XianFaliMainPage{}
}

func (p *XianFaliMainPage) GetContent() fyne.CanvasObject {
	title := canvas.NewText("我的法力", color.Black)
	title.TextSize = 27

	showx := canvas.NewText(
		"法力: "+global.File_XianFaLiReader.ReadStrSafe(),	
	simple.Blue)
	showx.TextSize = 20

	btnBack := widget.NewButton("返回", func(){
		p.router(interfaces.PageID_XianSkillMainPage)
	})

	btnp := widget.NewButton("仙币增强", func(){
		deal := func(){
			if res, err := global.File_XianBiReader.CanMinus(10); (!res) || (err != nil) {
				simple.DialogInfo("取出仙币失败", global.Main_Window)
				return
			}
			global.File_XianFaLiReader.AddNum(70)
			p.router(interfaces.PageID_XianFaliMainPage)
		}
		simple.DialogQuestion("是否使用10金币增强70法力?", global.Main_Window, deal, func(){})
	})

	vbox := container.NewVBox(
		simple.HorizonCenter(title),
		simple.Spacer(20),
		simple.HorizonCenter(showx),
		simple.Spacer(140),
		simple.HorizonCenter(btnp),
		simple.Spacer(100),
		simple.HorizonRight(btnBack),
		layout.NewSpacer(),
	)

    return container.NewBorder(
		vbox, 
		nil, nil, nil, nil, 
	)
}

func (p *XianFaliMainPage) GetID() interfaces.PageID {
    return interfaces.PageID_XianFaliMainPage
}

func (p *XianFaliMainPage) SetRouter(fn func(interfaces.PageID)) {
    p.router = fn
}
