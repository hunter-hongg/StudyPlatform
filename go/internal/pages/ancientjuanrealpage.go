package pages

import (
	"StudyPlatform/internal/global"
	"StudyPlatform/internal/interfaces"
	"StudyPlatform/pkg/simple"
	"StudyPlatform/pkg/syn"
	"StudyPlatform/pkg/util"
	"strconv"

	"image/color"

	"fyne.io/fyne/v2"
	"fyne.io/fyne/v2/canvas"
	"fyne.io/fyne/v2/container"
	"fyne.io/fyne/v2/layout"
	"fyne.io/fyne/v2/widget"
)

type AncientJuanRealPage struct {
    router func(interfaces.PageID)
}

func NewAncientJuanRealPage() *AncientJuanRealPage {
    return &AncientJuanRealPage{}
}

func (p *AncientJuanRealPage) GetContent() fyne.CanvasObject {
	title := canvas.NewText("捐献古玩", color.Black)
	title.TextSize = 27

	deal := func(af util.MinusAble, minus int, add int, addj int) {
		if !af.CanMinusSafe(minus) {
			simple.DialogInfo("取出古玩失败", global.Main_Window)
			return
		}
		global.File_AncientBaiYinReader.AddNum(add)
		global.File_AncientJuanReader.AddNum(addj)
		simple.DialogInfo("捐献成功", global.Main_Window)
		p.router(interfaces.PageID_AncientJuanRealPage)
	}
	syn.Ignore(deal)

	showj := canvas.NewText(
		"捐献值: "+global.File_AncientJuanReader.ReadStrSafe(),
	simple.Blue)
	showj.TextSize = 20

	btnBack := widget.NewButton("返回", func(){
		p.router(interfaces.PageID_AncientJuanMainPage)
	})

	var btns []fyne.CanvasObject
	var afp = []util.MinusAble{
		global.File_AncientCiQiReader, global.File_AncientBeiKeReader, global.File_AncientYuPeiReader,
		global.File_AncientGuwanChaHu, global.File_AncientGuwanChaZhan,
	}
	var shows []string = []string {
		"瓷器", "碑刻", "玉佩", "茶壶", "茶盏",
	}
	var price []int = []int {
		30, 35, 30, 45, 35, 
	}
	var price2 = []int {
		20, 25, 20, 40, 30, 
	}

	for i := 0 ; i < len(shows) ; i++ {
		btns = append(btns, 
			widget.NewButton(
				"1"+shows[i]+"=>"+strconv.Itoa(price[i])+"白银+"+strconv.Itoa(price2[i])+"捐献值", func(){
					deal(afp[i], 1, price[i], price2[i])
				},
			),
		)
	}
	
	vbox := container.NewVBox(
		simple.HorizonCenter(title),
		simple.Spacer(20),
		simple.HorizonCenter(showj),
		simple.Spacer(140),
		container.NewGridWithColumns(2, btns...),
		simple.Spacer(100),
		simple.HorizonRight(btnBack),
		layout.NewSpacer(),
	)

    return container.NewBorder(
		vbox, 
		nil, nil, nil, nil, 
	)
}

func (p *AncientJuanRealPage) GetID() interfaces.PageID {
    return interfaces.PageID_AncientJuanRealPage
}

func (p *AncientJuanRealPage) SetRouter(fn func(interfaces.PageID)) {
    p.router = fn
}
