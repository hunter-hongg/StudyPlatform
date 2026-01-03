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

type AncientThingPaoPage struct {
    router func(interfaces.PageID)
}

func NewAncientThingPaoPage() *AncientThingPaoPage {
    return &AncientThingPaoPage{}
}

func (p *AncientThingPaoPage) GetContent() fyne.CanvasObject {
	title := canvas.NewText("我的锦袍", color.Black)
	title.TextSize = 27

	shows := canvas.NewText(
		"当前锦袍: "+global.File_AncientPao.GetNow().String(), simple.Blue,
	)
	shows.TextSize = 20

	btnBack := widget.NewButton("返回", func(){
		p.router(interfaces.PageID_AncientThingMainPage)
	})

	var btns []fyne.CanvasObject
	leng := global.File_AncientPao.GetAll()
	for i := 0 ; i < len(leng) ; i++ {
		btns = append(btns, 
			widget.NewButton(
				leng[i].String(), func(){
					global.File_AncientPao.Change(leng[i])
					p.router(interfaces.PageID_AncientThingPaoPage)
				},
			),
		)
	}

	vbox := container.NewVBox(
		simple.HorizonCenter(title),
		simple.Spacer(20),
		simple.HorizonCenter(shows),
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

func (p *AncientThingPaoPage) GetID() interfaces.PageID {
    return interfaces.PageID_AncientThingPaoPage
}

func (p *AncientThingPaoPage) SetRouter(fn func(interfaces.PageID)) {
    p.router = fn
}
