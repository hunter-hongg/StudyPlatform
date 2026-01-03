package pages


import (
	"StudyPlatform/internal/global"
	"StudyPlatform/internal/interfaces"
	"StudyPlatform/pkg/simple"
	"strconv"

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

type CalcStartTimPage struct {
    router func(interfaces.PageID)
}

func NewCalcStartTimPage() *CalcStartTimPage {
    return &CalcStartTimPage{}
}

func (p *CalcStartTimPage) GetContent() fyne.CanvasObject {
	global.Logger.Debug("正常启动")

	title := canvas.NewText("乘法练习", color.Black)
	title.TextSize = 27

	rndv1 := int(C.getrnd(10, 100))
	rndv2 := int(C.getrnd(10, 100))

	btnBack := widget.NewButton("返回", func(){
		p.router(interfaces.PageID_CalcStartPage)
	})

	showLabel := canvas.NewText(
		"请计算: "+strconv.Itoa(rndv1)+"*"+strconv.Itoa(rndv2),
		color.Black,
	)
	showLabel.TextSize = 20

	textctrl := widget.NewEntry()
	textctrl.Text = "请输入..."

	submit := widget.NewButton("提交结果", func(){
		if !global.File_CalcTimesCheck.CheckTimes() {
			simple.DialogInfo("今日次数已使用完毕", global.Main_Window)
			global.Logger.Info("次数使用完毕")
			return
		}
		res, err := strconv.Atoi(textctrl.Text)
		realres := rndv1 * rndv2
		if (realres != res) || (err != nil) {
			simple.DialogInfo("计算错误", global.Main_Window)
			global.Logger.Info("计算错误")
		} else {
			simple.DialogInfo("计算正确 +80计算币", global.Main_Window)
			global.File_JiSuanBiReader.AddNum(80)
			global.Logger.Info("计算正确")
		}
		p.router(interfaces.PageID_CalcStartTimPage)
	})

	vbox := container.NewVBox(
		simple.HorizonCenter(title),
		simple.Spacer(200),
		simple.HorizonLeft(showLabel),
		simple.HorizonLeftHalf(textctrl),
		simple.HorizonLeft(submit),
		simple.Spacer(100),
		simple.HorizonRight(btnBack),
		layout.NewSpacer(),
	)

    return container.NewBorder(
		vbox, 
		nil, nil, nil, nil, 
	)
}

func (p *CalcStartTimPage) GetID() interfaces.PageID {
    return interfaces.PageID_CalcStartTimPage
}

func (p *CalcStartTimPage) SetRouter(fn func(interfaces.PageID)) {
    p.router = fn
}
