package pages

/*
计算币获得规则:
加减练习:
限5次，答对+50计算币
*/

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

type CalcStartAddPage struct {
    router func(interfaces.PageID)
}

func NewCalcStartAddPage() *CalcStartAddPage {
    return &CalcStartAddPage{}
}

func (p *CalcStartAddPage) GetContent() fyne.CanvasObject {
	getop := func(op int) string {
		switch op {
		case 0: 
			return "+"
		case 1:
			return "-"
		default: 
			return "-"
		}
	}
	getres := func(v1 int, op int, v2 int) int {
		switch op {
		case 0: 
			return v1 + v2 
		case 1:
			return v1 - v2
		default: 
			return v1 - v2
		}
	}
	_ = getres

	global.Logger.Debug("正常启动")

	title := canvas.NewText("加减练习", color.Black)
	title.TextSize = 27

	rndv1 := int(C.getrnd(100, 10000))
	rndv2 := int(C.getrnd(100, 10000))
	op := int(C.getrnd(0, 1))

	global.CalcNumber1_CalcAdd = int(rndv1)
	global.CalcNumber2_CalcAdd = int(rndv2)
	global.CalcOp_CalcAdd      = int(op)

	btnBack := widget.NewButton("返回", func(){
		p.router(interfaces.PageID_CalcStartPage)
	})

	showLabel := canvas.NewText(
		"请计算: "+strconv.Itoa(rndv1)+getop(op)+strconv.Itoa(rndv2),
		color.Black,
	)
	showLabel.TextSize = 20

	textctrl := widget.NewEntry()
	textctrl.Text = "请输入..."

	submit := widget.NewButton("提交结果", func(){
		if !global.File_CalcAddCheck.CheckTimes() {
			simple.DialogInfo("今日次数已使用完毕", global.Main_Window)
			global.Logger.Info("次数使用完毕")
			return
		}
		res, err := strconv.Atoi(textctrl.Text)
		realres := getres(global.CalcNumber1_CalcAdd, global.CalcOp_CalcAdd, global.CalcNumber2_CalcAdd)
		if (realres != res) || (err != nil) {
			simple.DialogInfo("计算错误", global.Main_Window)
			global.Logger.Info("计算错误")
		} else {
			simple.DialogInfo("计算正确 +60计算币", global.Main_Window)
			global.File_JiSuanBiReader.AddNum(60)
			global.Logger.Info("计算正确")
		}
		p.router(interfaces.PageID_CalcStartAddPage)
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

func (p *CalcStartAddPage) GetID() interfaces.PageID {
    return interfaces.PageID_CalcStartAddPage
}

func (p *CalcStartAddPage) SetRouter(fn func(interfaces.PageID)) {
    p.router = fn
}
