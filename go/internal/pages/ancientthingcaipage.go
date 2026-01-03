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

type AncientThingCaiPage struct {
    router func(interfaces.PageID)
}

func NewAncientThingCaiPage() *AncientThingCaiPage {
    return &AncientThingCaiPage{}
}

func (p *AncientThingCaiPage) GetContent() fyne.CanvasObject {
	title := canvas.NewText("我的财物", color.Black)
	title.TextSize = 27

	btnBack := widget.NewButton("返回", func(){
		p.router(interfaces.PageID_AncientThingMainPage)
	})

	var btns []fyne.CanvasObject
	var things = []string{"铜钱", "白银", "宝石", "绿玉", "白玉"}
	var files = []string{global.File_AncientTongQianReader.ReadStrSafe(), global.File_AncientBaiYinReader.ReadStrSafe(), 
						 global.File_AncientHuangJinReader.ReadStrSafe(), 
						 global.File_AncientLvYuReader.ReadStr(), global.File_AncientBaiYuReader.ReadStr()}
	var end = []string{"枚", "两", "两", "块", "块"}

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

func (p *AncientThingCaiPage) GetID() interfaces.PageID {
    return interfaces.PageID_AncientThingCaiPage
}

func (p *AncientThingCaiPage) SetRouter(fn func(interfaces.PageID)) {
    p.router = fn
}
