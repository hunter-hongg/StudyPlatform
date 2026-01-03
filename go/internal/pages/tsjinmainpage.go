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

type ThingSquareJinMainPage struct {
    router func(interfaces.PageID)
}

func NewThingSquareJinMainPage() *ThingSquareJinMainPage {
    return &ThingSquareJinMainPage{}
}

func (p *ThingSquareJinMainPage) GetContent() fyne.CanvasObject {
	title := canvas.NewText("金币领取", color.Black)
	title.TextSize = 27

	deal := func(fp *util.FilePassword, an int, des string){
		if res, err := global.File_JinBiReader.CanMinus(1); (!res) || (err != nil) {
			simple.DialogInfo("取出金币失败", global.Main_Window)
			return
		}
		fp.AddNum(an)
		simple.DialogInfo("成功领取"+strconv.Itoa(an)+des, global.Main_Window)
		p.router(interfaces.PageID_ThingSquareJinMainPage)
	}

	shoj := canvas.NewText("金币: "+global.File_JinBiReader.ReadStrSafe(), simple.Blue)
	shoj.TextSize = 20

	btnBack := widget.NewButton("返回", func(){
		p.router(interfaces.PageID_ThingSquareMainPage)
	})

	btnJi := widget.NewButton("领取宝石", func(){
		deal(global.File_BaoshiReader, 8, "宝石")
	})

	btnXian := widget.NewButton("领取仙币", func(){
		deal(global.File_XianBiReader, 50, "仙币" )
	})

	btnTong := widget.NewButton("领取铜钱", func(){
		deal(global.File_TongQianReader, 65, "铜钱")
	})

	vbox := container.NewVBox(
		simple.HorizonCenter(title),
		simple.Spacer(30),
		simple.HorizonCenter(shoj),
		simple.Spacer(120),
		simple.HorizonCenter(btnJi),
		simple.HorizonCenter(btnXian),
		simple.HorizonCenter(btnTong),
		simple.Spacer(100),
		simple.HorizonRight(btnBack),
		layout.NewSpacer(),
	)

    return container.NewBorder(
		vbox, 
		nil, nil, nil, nil, 
	)
}

func (p *ThingSquareJinMainPage) GetID() interfaces.PageID {
    return interfaces.PageID_ThingSquareJinMainPage
}

func (p *ThingSquareJinMainPage) SetRouter(fn func(interfaces.PageID)) {
    p.router = fn
}
