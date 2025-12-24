package pages

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

type AncientShopBaowuPage struct {
    router func(interfaces.PageID)
}

func NewAncientShopBaowuPage() *AncientShopBaowuPage {
    return &AncientShopBaowuPage{}
}

func (p *AncientShopBaowuPage) GetContent() fyne.CanvasObject {
	title := canvas.NewText("宝物店铺", color.Black)
	title.TextSize = 27

	deal := func(af *util.AddFile, minus int, add int) {
		if res, err := global.File_AncientHuangJinReader.CanMinus(minus); (!res) || (err!=nil) {
			simple.DialogInfo("取出黄金失败", global.Main_Window)
			return
		}
		af.AddNum(add)
		simple.DialogInfo("兑换成功", global.Main_Window)
		p.router(interfaces.PageID_AncientShopBaowuPage)
	}
	syn.Ignore(deal)

	showj := canvas.NewText(
		"黄金: "+global.File_AncientHuangJinReader.ReadStrSafe(),
	simple.Blue)
	showj.TextSize = 20

	btnBack := widget.NewButton("返回", func(){
		p.router(interfaces.PageID_AncientMainPage)
	})

	var btns []fyne.CanvasObject
	var afp []*util.AddFile = []*util.AddFile{
		global.File_AncientBaoMingZhu, global.File_AncientBaoYuDiao,
		global.File_AncientBaoYuBi, global.File_AncientBaoChouDuan,
		global.File_AncientBaoYuzhan, global.File_AncientBaoHu,
		global.File_AncientBaoZhan,
	}
	var shows []string = []string {
		"500黄金=>1明珠", "800黄金=>1玉雕", "1200黄金=>1玉璧", "250黄金=>1绸缎",
		"1000黄金=>1玉盏", "1500黄金=>1玉壶", "2000黄金=>4玉杯",
	}
	var price []int = []int {
		500, 800, 1200, 250, 1000, 1500, 2000,
	}
	var getted []int = []int {
		1, 1, 1, 1, 1, 1, 4, 
	}

	for i := 0 ; i < len(shows) ; i++ {
		btns = append(btns, 
			widget.NewButton(
				shows[i], func(){
					deal(afp[i], price[i], getted[i])
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

func (p *AncientShopBaowuPage) GetID() interfaces.PageID {
    return interfaces.PageID_AncientShopBaowuPage
}

func (p *AncientShopBaowuPage) SetRouter(fn func(interfaces.PageID)) {
    p.router = fn
}
