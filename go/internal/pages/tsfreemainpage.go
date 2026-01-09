package pages

import (
	"StudyPlatform/internal/global"
	"StudyPlatform/internal/interfaces"
	"StudyPlatform/pkg/simple"
	"StudyPlatform/pkg/util"
	"strconv"

	"image/color"

	"fyne.io/fyne/v2"
	"fyne.io/fyne/v2/canvas"
	"fyne.io/fyne/v2/container"
	"fyne.io/fyne/v2/layout"
	"fyne.io/fyne/v2/widget"
)

type ThingSquareFreeMainPage struct {
    router func(interfaces.PageID)
}

func NewThingSquareFreeMainPage() *ThingSquareFreeMainPage {
    return &ThingSquareFreeMainPage{}
}

func (p *ThingSquareFreeMainPage) GetContent() fyne.CanvasObject {
	title := canvas.NewText("免费领取", color.Black)
	title.TextSize = 27

	deal := func(fp *util.FilePassword, an int, des string, cf *util.CheckFile){
		if !cf.CheckTimes() {
			simple.DialogInfo("今日已经领取", global.Main_Window)
			return
		}
		fp.AddNum(an)
		simple.DialogInfo("成功领取"+strconv.Itoa(an)+des, global.Main_Window)
	}

	btnBack := widget.NewButton("返回", func(){
		p.router(interfaces.PageID_ThingSquareMainPage)
	})

	btnJi := widget.NewButton("免费积分", func(){
		deal(global.File_JiFenReader, 20, "积分", global.File_ThingSquareJiFenCheck)
	})

	btnXian := widget.NewButton("免费仙币", func(){
		deal(global.File_XianBiReader, 5, "仙币", global.File_ThingSquareXianBiCheck)
	})

	btnTong := widget.NewButton("免费铜钱", func(){
		deal(global.File_TongQianReader, 25, "铜钱", global.File_ThingSquareTongQianCheck)
	})

	btnBao := widget.NewButton("免费宝石", func(){
		deal(global.File_BaoshiReader, 1, "宝石", global.File_ThingSquareBaoShiCheck)
	})

	btnJin := widget.NewButton("免费金币", func() {
		deal(global.File_JinBiReader, 1, "金币", global.File_ThingSquareJinBiCheck)
	})

	vbox := container.NewVBox(
		simple.HorizonCenter(title),
		simple.Spacer(150),
		simple.HorizonCenter(btnJi),
		simple.HorizonCenter(btnXian),
		simple.HorizonCenter(btnTong),
		simple.HorizonCenter(btnBao),
		simple.HorizonCenter(btnJin),
		simple.Spacer(100),
		simple.HorizonRight(btnBack),
		layout.NewSpacer(),
	)

    return container.NewBorder(
		vbox, 
		nil, nil, nil, nil, 
	)
}

func (p *ThingSquareFreeMainPage) GetID() interfaces.PageID {
    return interfaces.PageID_ThingSquareFreeMainPage
}

func (p *ThingSquareFreeMainPage) SetRouter(fn func(interfaces.PageID)) {
    p.router = fn
}
