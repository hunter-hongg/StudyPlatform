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
	"StudyPlatform/pkg/syn"
	"StudyPlatform/pkg/util"

	"image/color"

	"fyne.io/fyne/v2"
	"fyne.io/fyne/v2/canvas"
	"fyne.io/fyne/v2/container"
	"fyne.io/fyne/v2/layout"
	"fyne.io/fyne/v2/widget"
)

type XianFaliDanPage struct {
    router func(interfaces.PageID)
}

func NewXianFaliDanPage() *XianFaliDanPage {
    return &XianFaliDanPage{}
}

func (p *XianFaliDanPage) GetContent() fyne.CanvasObject {
	title := canvas.NewText("法力炼丹", color.Black)
	title.TextSize = 27

	deal := func(need int, fp *util.FilePassword){
		if res, err := global.File_XianFaLiReader.CanMinus(need); (!res) || (err != nil) {
			simple.DialogInfo("运用法力失败", global.Main_Window)
			return
		}
		fp.AddNum(1)
		simple.DialogInfo("炼制成功", global.Main_Window)
		p.router(interfaces.PageID_XianFaliDanPage)
	}
	syn.Ignore(deal)

	showx := canvas.NewText(
		"法力: "+global.File_XianFaLiReader.ReadStrSafe(),	
	simple.Blue)
	showx.TextSize = 20

	btnBack := widget.NewButton("返回", func(){
		p.router(interfaces.PageID_XianFaliMainPage)
	})

	btn1 := widget.NewButton("炼制普通丹", func(){
		dealb := func(){
			deal(15, global.File_XianPuTongDanReader)
		}
		simple.DialogQuestion("是否耗费15法力炼制1普通丹?", global.Main_Window, dealb, func(){})
	})

	btn2 := widget.NewButton("炼制碧丹", func(){
		dealb := func(){
			deal(35, global.File_XianBiDanReader)
		}
		simple.DialogQuestion("是否耗费35法力炼制1碧丹?", global.Main_Window, dealb, func(){})
	})

	btn3 := widget.NewButton("炼制青丹", func(){
		dealb := func(){
			deal(80, global.File_XianQingDanReader)
		}
		simple.DialogQuestion("是否耗费80法力炼制1青丹?", global.Main_Window, dealb, func(){})
	})

	vbox := container.NewVBox(
		simple.HorizonCenter(title),
		simple.Spacer(20),
		simple.HorizonCenter(showx),
		simple.Spacer(140),
		simple.HorizonCenter(btn1),
		simple.HorizonCenter(btn2), 
		simple.HorizonCenter(btn3),
		simple.Spacer(100),
		simple.HorizonRight(btnBack),
		layout.NewSpacer(),
	)

    return container.NewBorder(
		vbox, 
		nil, nil, nil, nil, 
	)
}

func (p *XianFaliDanPage) GetID() interfaces.PageID {
    return interfaces.PageID_XianFaliDanPage
}

func (p *XianFaliDanPage) SetRouter(fn func(interfaces.PageID)) {
    p.router = fn
}
