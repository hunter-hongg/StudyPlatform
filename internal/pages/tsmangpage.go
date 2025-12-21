package pages

import (
	"StudyPlatform/internal/global"
	"StudyPlatform/internal/interfaces"
	"StudyPlatform/pkg/cgo"
	"StudyPlatform/pkg/simple"
	"strconv"

	"image/color"

	"fyne.io/fyne/v2"
	"fyne.io/fyne/v2/canvas"
	"fyne.io/fyne/v2/container"
	"fyne.io/fyne/v2/layout"
	"fyne.io/fyne/v2/widget"
)

type ThingSquareMangMainPage struct {
    router func(interfaces.PageID)
}

func NewThingSquareMangMainPage() *ThingSquareMangMainPage {
    return &ThingSquareMangMainPage{}
}

func (p *ThingSquareMangMainPage) GetContent() fyne.CanvasObject {
	title := canvas.NewText("金币盲盒", color.Black)
	title.TextSize = 27

	showji := canvas.NewText(
		"金币: "+global.File_JinBiReader.ReadStrSafe(),
	simple.Blue)
	showji.TextSize = 20

	btnBack := widget.NewButton("返回", func(){
		p.router(interfaces.PageID_ThingSquareMainPage)
	})

	dealS := func(bei int) {
		if res, err := global.File_JinBiReader.CanMinus(bei * 5); (!res) || (err != nil) {
			simple.DialogInfo("取出金币失败", global.Main_Window)
			return
		}
		addji := bei * 200 + cgo.GetRnd(-100, 100) 
		addba := bei * 15 + cgo.GetRnd(-5, 5)
		addxi := bei * 75 + cgo.GetRnd(-25, 25)
		global.File_JiFenReader.AddNum(addji)
		global.File_BaoshiReader.AddNum(addba)
		global.File_XianBiReader.AddNum(addxi)
		simple.DialogInfo("恭喜获得: \n"+strconv.Itoa(addji)+"积分\n"+strconv.Itoa(addba)+"宝石\n"+strconv.Itoa(addxi)+"仙币", global.Main_Window)
		p.router(interfaces.PageID_ThingSquareMangMainPage)
	}
	dealA := func(bei int) {
		if res, err := global.File_JinBiReader.CanMinus(bei * 5); (!res) || (err != nil) {
			simple.DialogInfo("取出金币失败", global.Main_Window)
			return
		}
		addt := bei * 500 + cgo.GetRnd(-200, 400)
		global.File_TongQianReader.AddNum(addt)
		simple.DialogInfo("恭喜获得"+strconv.Itoa(addt)+"铜钱", global.Main_Window)
		p.router(interfaces.PageID_ThingSquareMangMainPage)
	}

	btnS1 := widget.NewButton("5金币盲盒", func(){
		dealS(1)
	})

	btnS2 := widget.NewButton("10金币盲盒", func(){
		dealS(2)
	})

	btnS3 := widget.NewButton("15金币盲盒", func(){
		dealS(3)
	})

	btnA1 := widget.NewButton("5金币古代盲盒", func(){
		dealA(1)
	})

	btnA2 := widget.NewButton("10金币古代盲盒", func(){
		dealA(2)
	})

	btnA3 := widget.NewButton("15金币古代盲盒", func(){
		dealA(3)
	})

	vbox := container.NewVBox(
		simple.HorizonCenter(title),
		simple.Spacer(20),
		simple.HorizonCenter(showji),
		simple.Spacer(140),
		container.NewGridWithColumns(3, 
			btnS1,
			btnS2,
			btnS3,
			btnA1,
			btnA2,
			btnA3,
		),
		simple.Spacer(100),
		simple.HorizonRight(btnBack),
		layout.NewSpacer(),
	)

    return container.NewBorder(
		vbox, 
		nil, nil, nil, nil, 
	)
}

func (p *ThingSquareMangMainPage) GetID() interfaces.PageID {
    return interfaces.PageID_ThingSquareMangMainPage
}

func (p *ThingSquareMangMainPage) SetRouter(fn func(interfaces.PageID)) {
    p.router = fn
}
