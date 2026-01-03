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

type OwnThingBaoshiShopPage struct {
    router func(interfaces.PageID)
}

func NewOwnThingBaoshiShopPage() *OwnThingBaoshiShopPage {
    return &OwnThingBaoshiShopPage{}
}

func (p *OwnThingBaoshiShopPage) GetContent() fyne.CanvasObject {
	global.Logger.Debug("正常启动")

	dealBaoshiWithJifen := func(jifen, baoshi int) {
		if res, err := global.File_JiFenReader.CanMinus(jifen); (!res) || (err != nil) {
			simple.DialogInfo("取出积分失败",global.Main_Window)
			return
		}
		global.File_BaoshiReader.AddNum(baoshi)
		simple.DialogInfo("兑换成功", global.Main_Window)
		p.router(interfaces.PageID_OwnThingBaoshiShopPage)
	}

	title := canvas.NewText("获取宝石", color.Black)
	title.TextSize = 27

	showbaoshi := canvas.NewText(
		"宝石: "+global.File_BaoshiReader.ReadStrSafe(),
	simple.Blue)
	showbaoshi.TextSize = 20

	showjifen := canvas.NewText(
		"积分: "+global.File_JiFenReader.ReadStrSafe(),
	simple.Blue)
	showjifen.TextSize = 20

	btnBack := widget.NewButton("返回", func(){
		p.router(interfaces.PageID_OwnThingBaoshiPage)
	})

	btn1 := widget.NewButton("200积分 => 5宝石", func() {
		dealBaoshiWithJifen(200, 5)
	})

	btn2 := widget.NewButton("400积分 => 11宝石", func() {
		dealBaoshiWithJifen(400, 11)
	})

	btn3 := widget.NewButton("600积分 => 18宝石", func() {
		dealBaoshiWithJifen(600, 18)
	})

	btn4 := widget.NewButton("800积分 => 25宝石", func() {
		dealBaoshiWithJifen(800, 25)
	})

	btn5 := widget.NewButton("1000积分 => 35宝石", func() {
		dealBaoshiWithJifen(1000, 35)
	})

	vbox := container.NewVBox(
		simple.HorizonCenter(title),
		simple.Spacer(20),
		simple.HorizonCenter(showbaoshi),
		simple.HorizonCenter(showjifen),
		simple.Spacer(120),
		container.NewGridWithColumns(3, 
			btn1, btn2, btn3, 
			btn4, btn5, 
		),
		simple.Spacer(100),
		simple.HorizonRight(btnBack),
		layout.NewSpacer(),
	)

    return container.NewBorder(
		vbox, 
		nil, nil, nil, nil, 
	)
}

func (p *OwnThingBaoshiShopPage) GetID() interfaces.PageID {
    return interfaces.PageID_OwnThingBaoshiShopPage
}

func (p *OwnThingBaoshiShopPage) SetRouter(fn func(interfaces.PageID)) {
    p.router = fn
}
