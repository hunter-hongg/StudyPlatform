package pages

import (
	"StudyPlatform/src/interfaces"
	"StudyPlatform/src/pkg/global"
	"StudyPlatform/src/pkg/simple"

	"image/color"

	"fyne.io/fyne/v2"
	"fyne.io/fyne/v2/canvas"
	"fyne.io/fyne/v2/container"
	"fyne.io/fyne/v2/layout"
	"fyne.io/fyne/v2/widget"
)

type CalcShopPage struct {
    router func(interfaces.PageID)
}

func NewCalcShopPage() *CalcShopPage {
    return &CalcShopPage{}
}

func (p *CalcShopPage) GetContent() fyne.CanvasObject {
	title := canvas.NewText("兑换物品", color.Black)
	title.TextSize = 27

	showjis := canvas.NewText(
		"计算币: "+global.File_JiSuanBiReader.ReadStrSafe(),
	simple.Blue)
	showjis.TextSize = 20

	btnBack := widget.NewButton("返回", func(){
		p.router(interfaces.PageID_CalcMainPage)
	})

	btnToJi := widget.NewButton("200计算币=>10积分", func(){
		res, err := global.File_JiSuanBiReader.CanMinus(200)
		if (!res) || (err != nil) {
			simple.DialogInfo("取计算币出错", global.Main_Window)
			return
		}
		global.File_JiFenReader.AddNum(10)
		simple.DialogInfo("兑换成功", global.Main_Window)
		p.router(interfaces.PageID_CalcShopPage)
	})

	vbox := container.NewVBox(
		simple.HorizonCenter(title),
		simple.Spacer(20),
		simple.HorizonCenter(showjis),
		simple.Spacer(150),
		container.NewGridWithColumns(3, 
			simple.HorizonRight(btnToJi),
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

func (p *CalcShopPage) GetID() interfaces.PageID {
    return interfaces.PageID_CalcShopPage
}

func (p *CalcShopPage) SetRouter(fn func(interfaces.PageID)) {
    p.router = fn
}
