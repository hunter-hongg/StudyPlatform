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

type AncientShopEasyPage struct {
    router func(interfaces.PageID)
}

func NewAncientShopEasyPage() *AncientShopEasyPage {
    return &AncientShopEasyPage{}
/*  */}

func (p *AncientShopEasyPage) GetContent() fyne.CanvasObject {
	title := canvas.NewText("便利店铺", color.Black)
	title.TextSize = 27

	btnBack := widget.NewButton("返回", func(){
		p.router(interfaces.PageID_AncientShopMainPage)
	})

	btn0 := widget.NewButton("兑换铜钱", func(){
		p.router(interfaces.PageID_AncientShopEasyTongPage)
	})
	
	btn2 := widget.NewButton("兑换白银", func(){
		p.router(interfaces.PageID_AncientShopEasyYinPage)
	})

	btn1 := widget.NewButton("兑换黄金", func(){
		p.router(interfaces.PageID_AncientShopEasyJinPage)
	})
	
	vbox := container.NewVBox(
		simple.HorizonCenter(title),
		simple.Spacer(170),
		simple.HorizonCenter(btn0),
		simple.HorizonCenter(btn2),
		simple.HorizonCenter(btn1),
		simple.Spacer(100),
		simple.HorizonRight(btnBack),
		layout.NewSpacer(),
	)

    return container.NewBorder(
		vbox, 
		nil, nil, nil, nil, 
	)
}

func (p *AncientShopEasyPage) GetID() interfaces.PageID {
    return interfaces.PageID_AncientShopEasyPage
}

func (p *AncientShopEasyPage) SetRouter(fn func(interfaces.PageID)) {
    p.router = fn
}
