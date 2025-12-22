package pages

import (
	"StudyPlatform/internal/global"
	"StudyPlatform/internal/interfaces"
	"StudyPlatform/internal/xiansword"
	"StudyPlatform/pkg/simple"

	"image/color"

	"fyne.io/fyne/v2"
	"fyne.io/fyne/v2/canvas"
	"fyne.io/fyne/v2/container"
	"fyne.io/fyne/v2/layout"
	"fyne.io/fyne/v2/widget"
)

type XianQiChangePage struct {
    router func(interfaces.PageID)
}

func NewXianQiChangePage() *XianQiChangePage {
    return &XianQiChangePage{}
}

func (p *XianQiChangePage) GetContent() fyne.CanvasObject {
	title := canvas.NewText("更换仙器", color.Black)
	title.TextSize = 27

	showt := canvas.NewText(
		"当前仙器: "+global.File_XianSword.Get().String(),
	simple.Blue)
	showt.TextSize = 20

	btnBack := widget.NewButton("返回", func(){
		p.router(interfaces.PageID_XianQiMainPage)
	})

	var qiname []string = []string{"金剑", "木剑", "水剑", "火剑", "土剑"}
	var qivar  []xiansword.SwordEnum = []xiansword.SwordEnum{xiansword.Gold, xiansword.Wood, xiansword.Water, xiansword.Fire, xiansword.Soil}
	var btns   []fyne.CanvasObject

	for i := 0 ; i < 5 ; i++ {
		btns = append(btns, 
			widget.NewButton(qiname[i], func() {
				global.File_XianSword.Set(qivar[i])
				simple.DialogInfo("切换成功", global.Main_Window)
				p.router(interfaces.PageID_XianQiChangePage)
			}),
		)
	}

	vbox := container.NewVBox(
		simple.HorizonCenter(title),
		simple.Spacer(20),
		simple.HorizonCenter(showt),
		simple.Spacer(130),
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

func (p *XianQiChangePage) GetID() interfaces.PageID {
    return interfaces.PageID_XianQiChangePage
}

func (p *XianQiChangePage) SetRouter(fn func(interfaces.PageID)) {
    p.router = fn
}
