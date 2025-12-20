package pages

import (
	"StudyPlatform/internal/global"
	"StudyPlatform/internal/interfaces"
	"StudyPlatform/pkg/cgo"
	"StudyPlatform/pkg/simple"

	_ "fmt"
	"image/color"

	"fyne.io/fyne/v2"
	"fyne.io/fyne/v2/canvas"
	"fyne.io/fyne/v2/container"
	"fyne.io/fyne/v2/layout"
	"fyne.io/fyne/v2/widget"
)

type OwnThingBaoshiChou1Page struct {
    router func(interfaces.PageID)
}

func NewOwnThingBaoshiChou1Page() *OwnThingBaoshiChou1Page {
    return &OwnThingBaoshiChou1Page{}
}

func (p *OwnThingBaoshiChou1Page) GetContent() fyne.CanvasObject {
	global.Logger.Debug("正常启动")

	title := canvas.NewText("宝石抽奖1", color.Black)
	title.TextSize = 27

	showbaoshi := canvas.NewText("宝石: "+global.File_BaoshiReader.ReadStrSafe(), simple.Blue)
	showbaoshi.TextSize = 20

	btnBack := widget.NewButton("返回", func(){
		p.router(interfaces.PageID_OwnThingBaoshiChouAllPage)
	})

	btnRule := widget.NewButton("显示规则", func() {
		simple.DialogInfo(""+
			"宝石抽奖1规则: \n"+
			"50% 100积分\n"+
			"20% 50仙币\n"+
			"20% 150铜钱\n"+
			"5%  5金币\n"+
			"5%  汉朝卡牌1 * 1", global.Main_Window,
		)
	})
	btnOk := widget.NewButton("2宝石抽奖", func() {
		if res, err := global.File_BaoshiReader.CanMinus(2); (!res) || (err != nil) {
			simple.DialogInfo("取出宝石失败", global.Main_Window)
			return
		}
		gl := cgo.GetRnd(1, 100)
		switch {
		case 0 < gl && gl <= 50:
			global.File_JiFenReader.AddNum(100)
			simple.DialogInfo("恭喜获得100积分", global.Main_Window)
		case 50 < gl && gl <= 70: 
			global.File_XianBiReader.AddNum(50)
			simple.DialogInfo("恭喜获得50仙币", global.Main_Window)
		case 70 < gl && gl <= 90: 
			global.File_JinBiReader.AddNum(5)
			simple.DialogInfo("恭喜获得5金币", global.Main_Window)
		case 90 < gl && gl <= 100: 
			gl2 := cgo.GetRnd(0, len(global.File_Han1CardsName) - 1)
			gs2 := global.File_Han1Card.GetByIndex(gl2)
			global.File_Han1Card.Write(gl2)
			simple.DialogInfo("恭喜获得汉朝卡牌1: \n"+gs2+" - 珍藏", global.Main_Window)
		default: 
			global.Logger.Error("错误的概率值")
		}
		p.router(interfaces.PageID_OwnThingBaoshiChou1Page)
	})
	
	vbox := container.NewVBox(
		simple.HorizonCenter(title),
		simple.Spacer(20),
		simple.HorizonCenter(showbaoshi),
		simple.Spacer(130),
		simple.HorizonCenter(btnRule),
		simple.HorizonCenter(btnOk),
		simple.Spacer(100),
		simple.HorizonRight(btnBack),
		layout.NewSpacer(),
	)

    return container.NewBorder(
		vbox, 
		nil, nil, nil, nil, 
	)
}

func (p *OwnThingBaoshiChou1Page) GetID() interfaces.PageID {
    return interfaces.PageID_OwnThingBaoshiChou1Page
}

func (p *OwnThingBaoshiChou1Page) SetRouter(fn func(interfaces.PageID)) {
    p.router = fn
}
