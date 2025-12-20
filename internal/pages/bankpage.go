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

type BankMainPage struct {
    router func(interfaces.PageID)
}

func NewBankMainPage() *BankMainPage {
    return &BankMainPage{}
}

func (p *BankMainPage) GetContent() fyne.CanvasObject {
	title := canvas.NewText("积分银行", color.Black)
	title.TextSize = 27

	showjifen := canvas.NewText(
		"存储积分: "+global.File_BankStoreReader.ReadStrSafe(),	
	simple.Blue)
	showjifen.TextSize = 20

	btnBack := widget.NewButton("返回", func(){
		p.router(interfaces.PageID_MainPage)
	})

	btnCun := widget.NewButton("存储积分", func(){
		// p.router(interfaces.PageID_TimerMainPage)
	})

	btnGet := widget.NewButton("领取积分", func(){
		// p.router(interfaces.PageID_OwnThingMainPage)
	})

	btnJuan := widget.NewButton("捐献积分", func(){
		// p.router(interfaces.PageID_LiHePage)
	})

	vbox := container.NewVBox(
		simple.HorizonCenter(title),
		simple.Spacer(20),
		simple.HorizonCenter(showjifen),
		simple.Spacer(140),
		simple.HorizonCenter(btnCun),
		simple.HorizonCenter(btnGet),
		simple.HorizonCenter(btnJuan),
		simple.Spacer(100),
		simple.HorizonRight(btnBack),
		layout.NewSpacer(),
	)

    return container.NewBorder(
		vbox, 
		nil, nil, nil, nil, 
	)
}

func (p *BankMainPage) GetID() interfaces.PageID {
    return interfaces.PageID_BankMainPage
}

func (p *BankMainPage) SetRouter(fn func(interfaces.PageID)) {
    p.router = fn
}
