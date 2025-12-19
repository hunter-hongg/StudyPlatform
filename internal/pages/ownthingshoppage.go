package pages

import (
	"StudyPlatform/internal/global"
	"StudyPlatform/internal/interfaces"
	"StudyPlatform/pkg/simple"
	"slices"

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

type OwnThingShopPage struct {
    router func(interfaces.PageID)
}

func NewOwnThingShopPage() *OwnThingShopPage {
    return &OwnThingShopPage{}
}

func (p *OwnThingShopPage) GetContent() fyne.CanvasObject {
	global.Logger.Debug("正常启动")

	title := canvas.NewText("物品商城", color.Black)
	title.TextSize = 27

	btnBack := widget.NewButton("返回", func(){
		p.router(interfaces.PageID_OwnThingMainPage)
	})

	btnSold1 := widget.NewButton("50积分 => 三国卡牌1*3", func() {
		if res, err := global.File_JiFenReader.CanMinus(50); (!res)||(err != nil) {
			simple.DialogInfo("取出积分失败", global.Main_Window)
			return
		}
		var cardd []int
		for {
			maxlen := len(global.File_SanGuo1CardsName) - 1
			gend := int(C.getrnd(0, C.int(maxlen)))
			if !slices.Contains(cardd, gend){
				cardd = append(cardd, gend)
				if len(cardd) >= 3 {
					break
				}
			}
		}
		var showstr = "恭喜获得: \n"
		for _, i := range cardd {
			sttr := global.File_SanGuo1Card.GetByIndex(i)
			showstr += sttr + " - 稀有\n"
			global.File_SanGuo1Card.Write(i)
		}
		simple.DialogInfo(showstr, global.Main_Window)
	})
	btnSold2 := widget.NewButton("400积分 => 40仙币", func() {
		if res, err := global.File_JiFenReader.CanMinus(400); (!res) || (err != nil) {
			simple.DialogInfo("取出积分失败", global.Main_Window)
			return
		}
		global.File_XianBiReader.AddNum(40)
		simple.DialogInfo("购买成功", global.Main_Window)
		return
	})

	vbox := container.NewVBox(
		simple.HorizonCenter(title),
		simple.Spacer(200),
		container.NewGridWithColumns(3, 
			simple.HorizonRight(btnSold1),
			simple.HorizonCenter(btnSold2),
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

func (p *OwnThingShopPage) GetID() interfaces.PageID {
    return interfaces.PageID_OwnThingShopPage
}

func (p *OwnThingShopPage) SetRouter(fn func(interfaces.PageID)) {
    p.router = fn
}
