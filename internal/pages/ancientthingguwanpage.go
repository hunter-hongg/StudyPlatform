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

type AncientThingGuwanPage struct {
    router func(interfaces.PageID)
}

func NewAncientThingGuwanPage() *AncientThingGuwanPage {
    return &AncientThingGuwanPage{}
}

func (p *AncientThingGuwanPage) GetContent() fyne.CanvasObject {
	title := canvas.NewText("我的古玩", color.Black)
	title.TextSize = 27

	btnBack := widget.NewButton("返回", func(){
		p.router(interfaces.PageID_AncientThingMainPage)
	})

	var btns []fyne.CanvasObject
	var things = []string{"瓷器", "碑刻", "玉佩", "茶壶", "茶盏"}
	var files = []string{global.File_AncientCiQiReader.ReadStrSafe(), global.File_AncientBeiKeReader.ReadStrSafe(), 
						 global.File_AncientYuPeiReader.ReadStrSafe(), 
						 global.File_AncientGuwanChaHu.ReadStr(), global.File_AncientGuwanChaZhan.ReadStr()}
	var end = []string{"件", "块", "件", "件", "件"}

	for i := 0 ; i < 5 ; i++ {
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

func (p *AncientThingGuwanPage) GetID() interfaces.PageID {
    return interfaces.PageID_AncientThingGuwanPage
}

func (p *AncientThingGuwanPage) SetRouter(fn func(interfaces.PageID)) {
    p.router = fn
}
