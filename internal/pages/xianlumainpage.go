package pages

import (
	"StudyPlatform/internal/gfunc"
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

type XianLuMainPage struct {
    router func(interfaces.PageID)
}

func NewXianLuMainPage() *XianLuMainPage {
    return &XianLuMainPage{}
}

func (p *XianLuMainPage) GetContent() fyne.CanvasObject {
	title := canvas.NewText("我的仙禄", color.Black)
	title.TextSize = 27

	showx := canvas.NewText(
		"等级: "+global.File_XianLuPinJi.ReadStrSafe(),	
	simple.Blue)
	showx.TextSize = 20

	btnBack := widget.NewButton("返回", func(){
		p.router(interfaces.PageID_XianMainPage)
	})

	btnl := widget.NewButton("领取仙禄", func(){
		if !global.File_XianLuOk.CheckTimes() {
			simple.DialogInfo("今日仙禄已领取", global.Main_Window)
			return
		}
		xl := gfunc.GetXianLu(
			global.File_XianLuPinJi.ReadIntSafe(),
		)
		global.File_XianBiReader.AddNum(xl)
		simple.DialogInfo("成功领取仙禄"+strconv.Itoa(xl)+"仙币", global.Main_Window)
	})

	btnp := widget.NewButton("升级仙禄", func(){
		need := 1400 + global.File_XianLuPinJi.ReadIntSafe()*100
		deal := func(){
			if res, err := global.File_XianBiReader.CanMinus(need); (!res) || (err != nil) {
				simple.DialogInfo("取出仙币失败", global.Main_Window)
				return
			}
			global.File_XianLuPinJi.AddNum(1)
			simple.DialogInfo("升级成功，现在仙禄等级为"+global.File_XianLuPinJi.ReadStrSafe()+"级", global.Main_Window)
			p.router(interfaces.PageID_XianLuMainPage)
		}
		simple.DialogQuestion(
			"是否花费"+strconv.Itoa(need)+"仙币升级仙禄?", global.Main_Window, deal, func(){},
		) 
	})

	vbox := container.NewVBox(
		simple.HorizonCenter(title),
		simple.Spacer(20),
		simple.HorizonCenter(showx),
		simple.Spacer(130),
		simple.HorizonCenter(btnl),
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

func (p *XianLuMainPage) GetID() interfaces.PageID {
    return interfaces.PageID_XianLuMainPage
}

func (p *XianLuMainPage) SetRouter(fn func(interfaces.PageID)) {
    p.router = fn
}
