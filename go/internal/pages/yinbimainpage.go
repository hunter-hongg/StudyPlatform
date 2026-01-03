package pages

import (
	"StudyPlatform/internal/global"
	"StudyPlatform/internal/interfaces"
	"StudyPlatform/pkg/simple"

	_ "fmt"
	"image/color"

	"fyne.io/fyne/v2"
	"fyne.io/fyne/v2/canvas"
	"fyne.io/fyne/v2/container"
	"fyne.io/fyne/v2/layout"
	"fyne.io/fyne/v2/widget"
)
/*
#cgo CFLAGS: -I../../cgo
#cgo LDFLAGS: -L../../lib -lRustRand
#include "RustRand.h"
*/
import "C"

type OwnThingYinbiPage struct {
    router func(interfaces.PageID)
}

func NewOwnThingYinbiPage() *OwnThingYinbiPage {
    return &OwnThingYinbiPage{}
}

func (p *OwnThingYinbiPage) GetContent() fyne.CanvasObject {
	global.Logger.Debug("正常启动")

	title := canvas.NewText("我的银币", color.Black)
	title.TextSize = 27

	showyin := canvas.NewText("银币: "+global.File_YinBiReader.ReadStrSafe(), simple.Blue)
	showyin.TextSize = 20

	btnBack := widget.NewButton("返回", func(){
		p.router(interfaces.PageID_OwnThingPagePage)
	})

	btnFc := widget.NewButton("1银币 => 三国卡牌1/汉朝卡牌1 * 1", func() {
		if res, err := global.File_YinBiReader.CanMinus(1) ; (!res) || (err != nil) {
			simple.DialogInfo("取出银币失败", global.Main_Window)
			return
		}
		gl := C.getrnd(1, 100)
		switch {
		case 0 < gl &&  gl <= 95: 
			// SanGuo1
			res := int(C.getrnd(0, C.int(len(global.File_SanGuo1CardsName))))
			strres := global.File_SanGuo1Card.GetByIndex(res)
			global.File_SanGuo1Card.Write(res)
			simple.DialogInfo("恭喜获得三国卡牌1: \n"+strres+" - 稀有", global.Main_Window)
		case 95 < gl && gl <= 100: 
			// Han1
			res := int(C.getrnd(0, C.int(len(global.File_Han1CardsName))))
			strres := global.File_Han1Card.GetByIndex(res)
			global.File_Han1Card.Write(res)
			simple.DialogInfo("恭喜获得汉朝卡牌1: \n"+strres+" - 珍藏", global.Main_Window)
		default: 
			global.Logger.Error("不符合范围的随机数")
		}
		p.router(interfaces.PageID_OwnThingYinbiPage)
	})
	
	vbox := container.NewVBox(
		simple.HorizonCenter(title),
		simple.Spacer(30),
		simple.HorizonCenter(showyin),
		simple.Spacer(130),
		container.NewGridWithColumns(2, 
			simple.HorizonRight(btnFc),
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

func (p *OwnThingYinbiPage) GetID() interfaces.PageID {
    return interfaces.PageID_OwnThingYinbiPage
}

func (p *OwnThingYinbiPage) SetRouter(fn func(interfaces.PageID)) {
    p.router = fn
}
