package pages

import (
	"StudyPlatform/internal/interfaces"
	"StudyPlatform/pkg/simple"

	"image/color"

	"fyne.io/fyne/v2"
	"fyne.io/fyne/v2/canvas"
	"fyne.io/fyne/v2/container"
	"fyne.io/fyne/v2/layout"
	"fyne.io/fyne/v2/widget"
)

type BankJuanGetMainPage struct {
    router func(interfaces.PageID)
}

func NewBankJuanGetMainPage() *BankJuanGetMainPage {
    return &BankJuanGetMainPage{}
}

func (p *BankJuanGetMainPage) GetContent() fyne.CanvasObject {
	title := canvas.NewText("领取奖励", color.Black)
	title.TextSize = 27

	btnBack := widget.NewButton("返回", func(){
		p.router(interfaces.PageID_BankJuanMainPage)
	})

	btnJifen := widget.NewButton("积分奖励", func(){
		p.router(interfaces.PageID_BankJuanGetJifenPage)
	})

	vbox := container.NewVBox(
		simple.HorizonCenter(title),
		simple.Spacer(200),
		simple.HorizonCenter(btnJifen),
		simple.Spacer(100),
		simple.HorizonRight(btnBack),
		layout.NewSpacer(),
	)

    return container.NewBorder(
		vbox, 
		nil, nil, nil, nil, 
	)
}

func (p *BankJuanGetMainPage) GetID() interfaces.PageID {
    return interfaces.PageID_BankJuanGetMainPage
}

func (p *BankJuanGetMainPage) SetRouter(fn func(interfaces.PageID)) {
    p.router = fn 
}
