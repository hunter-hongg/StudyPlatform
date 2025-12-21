package pages

import (
	"StudyPlatform/internal/interfaces"
	"StudyPlatform/internal/global"
	"StudyPlatform/pkg/simple"

	"image/color"

	"fyne.io/fyne/v2"
	"fyne.io/fyne/v2/canvas"
	"fyne.io/fyne/v2/container"
	"fyne.io/fyne/v2/layout"
	"fyne.io/fyne/v2/widget"
)

type XianSkillMainPage struct {
    router func(interfaces.PageID)
}

func NewXianSkillMainPage() *XianSkillMainPage {
    return &XianSkillMainPage{}
}

func (p *XianSkillMainPage) GetContent() fyne.CanvasObject {
	title := canvas.NewText("我的能力", color.Black)
	title.TextSize = 27

	btnBack := widget.NewButton("返回", func(){
		p.router(interfaces.PageID_XianMainPage)
	})

	btnf := widget.NewButton("我的法力", func(){
		p.router(interfaces.PageID_XianFaliMainPage)
	})

	vbox := container.NewVBox(
		simple.HorizonCenter(title),
		simple.Spacer(200),
		simple.HorizonCenter(btnf),
		simple.Spacer(100),
		simple.HorizonRight(btnBack),
		layout.NewSpacer(),
	)

    return container.NewBorder(
		vbox, 
		nil, nil, nil, nil, 
	)
}

func (p *XianSkillMainPage) GetID() interfaces.PageID {
    return interfaces.PageID_XianSkillMainPage
}

func (p *XianSkillMainPage) SetRouter(fn func(interfaces.PageID)) {
    p.router = fn
}
