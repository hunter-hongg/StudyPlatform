package pages

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

type AncientThingBaowuPage struct {
    router func(interfaces.PageID)
}

func NewAncientThingBaowuPage() *AncientThingBaowuPage {
    return &AncientThingBaowuPage{}
}

func (p *AncientThingBaowuPage) GetContent() fyne.CanvasObject {
	title := canvas.NewText("我的宝物", color.Black)
	title.TextSize = 27

	btnBack := widget.NewButton("返回", func(){
		p.router(interfaces.PageID_AncientThingMainPage)
	})

	var btns []fyne.CanvasObject
	var things = []string{"明珠", "玉雕", "玉璧", "绸缎", "玉盏", "玉壶", "玉杯"}
	var files = []string{global.File_AncientBaoMingZhu.ReadStr(), global.File_AncientBaoYuDiao.ReadStr(), 
						 global.File_AncientBaoYuBi.ReadStr(), global.File_AncientBaoChouDuan.ReadStr(),
						 global.File_AncientBaoYuzhan.ReadStr(), global.File_AncientBaoHu.ReadStr(), global.File_AncientBaoZhan.ReadStr()}
	var end = []string{"颗", "块", "块", "匹", "件", "件", "件"}

	for i := 0 ; i < 7 ; i++ {
		if i == 6 {
			btns = append(btns, 
				layout.NewSpacer(),
			)
		}
		btns = append(btns, 
			widget.NewButton(
				things[i]+": "+files[i]+end[i], func() {},
			),
		)
	}

	vbox := container.NewVBox(
		simple.HorizonCenter(title),
		simple.Spacer(170),
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

func (p *AncientThingBaowuPage) GetID() interfaces.PageID {
    return interfaces.PageID_AncientThingBaowuPage
}

func (p *AncientThingBaowuPage) SetRouter(fn func(interfaces.PageID)) {
    p.router = fn
}
