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

type BankJuanMainPage struct {
    router func(interfaces.PageID)
}

func NewBankJuanMainPage() *BankJuanMainPage {
    return &BankJuanMainPage{}
}

func (p *BankJuanMainPage) GetContent() fyne.CanvasObject {
	title := canvas.NewText("捐献积分", color.Black)
	title.TextSize = 27

	showjifen := canvas.NewText(
		"存储积分: "+global.File_BankStoreReader.ReadStrSafe(),	
	simple.Blue)
	showjifen.TextSize = 20

	btnBack := widget.NewButton("返回", func(){
		p.router(interfaces.PageID_BankMainPage)
	})

	btnJuan := widget.NewButton("捐献积分", func(){
		p.router(interfaces.PageID_BankJuanRealPage)
	})

	btnJiang := widget.NewButton("领取奖励", func(){
		// p.router(interfaces.PageID_BankGetPage)
	})

	vbox := container.NewVBox(
		simple.HorizonCenter(title),
		simple.Spacer(20),
		simple.HorizonCenter(showjifen),
		simple.Spacer(140),
		simple.HorizonCenter(btnJuan),
		simple.HorizonCenter(btnJiang),
		simple.Spacer(100),
		simple.HorizonRight(btnBack),
		layout.NewSpacer(),
	)

    return container.NewBorder(
		vbox, 
		nil, nil, nil, nil, 
	)
}

func (p *BankJuanMainPage) GetID() interfaces.PageID {
    return interfaces.PageID_BankJuanMainPage
}

func (p *BankJuanMainPage) SetRouter(fn func(interfaces.PageID)) {
    p.router = fn 
}
