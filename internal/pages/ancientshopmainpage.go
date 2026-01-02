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

type AncientShopMainPage struct {
    router func(interfaces.PageID)
}

func NewAncientShopMainPage() *AncientShopMainPage {
    return &AncientShopMainPage{}
}

func (p *AncientShopMainPage) GetContent() fyne.CanvasObject {
	title := canvas.NewText("古代店铺", color.Black)
	title.TextSize = 27

	btnBack := widget.NewButton("返回", func(){
		p.router(interfaces.PageID_AncientMainPage)
	})
	
	btn0 := widget.NewButton("普通店铺", func(){
		p.router(interfaces.PageID_AncientShopSimplePage)
	})
	
	btn1 := widget.NewButton("便利店铺", func(){
		p.router(interfaces.PageID_AncientShopEasyPage)
	})
	
	btn2 := widget.NewButton("宝物店铺", func(){
		p.router(interfaces.PageID_AncientShopBaowuPage)
	})
	
	btn3 := widget.NewButton("古玩店铺", func(){
		p.router(interfaces.PageID_AncientShopGuwanPage)
	})

	btn4 := widget.NewButton("书籍店铺", func(){
		p.router(interfaces.PageID_AncientShopBookPage)
	})

	vbox := container.NewVBox(
		simple.HorizonCenter(title),
		simple.Spacer(140),
		simple.HorizonCenter(btn0),
		simple.HorizonCenter(btn1),
		simple.HorizonCenter(btn2),
		simple.HorizonCenter(btn3),
		simple.HorizonCenter(btn4),
		simple.Spacer(100),
		simple.HorizonRight(btnBack),
		layout.NewSpacer(),
	)

    return container.NewBorder(
		vbox, 
		nil, nil, nil, nil, 
	)
}

func (p *AncientShopMainPage) GetID() interfaces.PageID {
    return interfaces.PageID_AncientShopMainPage
}

func (p *AncientShopMainPage) SetRouter(fn func(interfaces.PageID)) {
    p.router = fn
}
