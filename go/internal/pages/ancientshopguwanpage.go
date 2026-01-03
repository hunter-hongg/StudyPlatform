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

type AncientShopGuwanPage struct {
    router func(interfaces.PageID)
}

func NewAncientShopGuwanPage() *AncientShopGuwanPage {
    return &AncientShopGuwanPage{}
}

func (p *AncientShopGuwanPage) GetContent() fyne.CanvasObject {
	title := canvas.NewText("古玩店铺", color.Black)
	title.TextSize = 27

	deal := func(af util.AddAble, minus int, add int) {
		if res, err := global.File_AncientBaiYinReader.CanMinus(minus); (!res) || (err!=nil) {
			simple.DialogInfo("取出白银失败", global.Main_Window)
			return
		}
		af.AddNum(add)
		simple.DialogInfo("兑换成功", global.Main_Window)
		p.router(interfaces.PageID_AncientShopGuwanPage)
	}
	syn.Ignore(deal)

	showj := canvas.NewText(
		"白银: "+global.File_AncientBaiYinReader.ReadStrSafe(),
	simple.Blue)
	showj.TextSize = 20

	btnBack := widget.NewButton("返回", func(){
		p.router(interfaces.PageID_AncientShopMainPage)
	})

	var btns []fyne.CanvasObject
	var afp = []util.AddAble{
		global.File_AncientCiQiReader, global.File_AncientBeiKeReader, global.File_AncientYuPeiReader,
		global.File_AncientGuwanChaHu, global.File_AncientGuwanChaZhan,
	}
	var shows []string = []string {
		"瓷器", "碑刻", "玉佩", "茶壶", "茶盏",
	}
	var price []int = []int {
		200, 300, 200, 600, 300, 
	}

	for i := 0 ; i < len(shows) ; i++ {
		btns = append(btns, 
			widget.NewButton(
				strconv.Itoa(price[i])+"白银=>1"+shows[i], func(){
					deal(afp[i], price[i], 1)
				},
			),
		)
	}
	
	vbox := container.NewVBox(
		simple.HorizonCenter(title),
		simple.Spacer(20),
		simple.HorizonCenter(showj),
		simple.Spacer(140),
		container.NewGridWithColumns(3, btns...),
		simple.Spacer(100),
		simple.HorizonRight(btnBack),
		layout.NewSpacer(),
	)

    return container.NewBorder(
		vbox, 
		nil, nil, nil, nil, 
	)
}

func (p *AncientShopGuwanPage) GetID() interfaces.PageID {
    return interfaces.PageID_AncientShopGuwanPage
}

func (p *AncientShopGuwanPage) SetRouter(fn func(interfaces.PageID)) {
    p.router = fn
}
