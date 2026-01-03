package pages

import (
	"StudyPlatform/internal/interfaces"
	"StudyPlatform/internal/global"
	"StudyPlatform/pkg/simple"
	"strconv"

	"image/color"

	"fyne.io/fyne/v2"
	"fyne.io/fyne/v2/canvas"
	"fyne.io/fyne/v2/container"
	"fyne.io/fyne/v2/layout"
	"fyne.io/fyne/v2/widget"
)

type AncientShopEasyTongPage struct {
    router func(interfaces.PageID)
}

func NewAncientShopEasyTongPage() *AncientShopEasyTongPage {
    return &AncientShopEasyTongPage{}
}

func (p *AncientShopEasyTongPage) GetContent() fyne.CanvasObject {
	title := canvas.NewText("兑换白银", color.Black)
	title.TextSize = 27

	showtong := canvas.NewText(
		"铜钱: "+global.File_TongQianReader.ReadStrSafe(),
	simple.Blue)
	showtong.TextSize = 20

	showb := canvas.NewText(
		"黄金: "+global.File_AncientHuangJinReader.ReadStrSafe(),
	simple.Blue)
	showb.TextSize = 20

	btnBack := widget.NewButton("返回", func(){
		p.router(interfaces.PageID_AncientShopEasyPage)
	})

	tishi := canvas.NewText("请输入兑换铜钱数: ", simple.Blue)
	tishi.TextSize = 20
	inputCun := widget.NewEntry()
	inputCun.Text = "请输入..."
	btnOk := widget.NewButton("兑换", func(){
		read := inputCun.Text
		readi, err := strconv.Atoi(read)
		if err != nil {
			simple.DialogError(err, global.Main_Window)
			return
		}
		if readi % 100 != 0 {
			simple.DialogInfo("铜钱兑换需要以100枚为单位", global.Main_Window)
			return
		}
		if res, err := global.File_AncientHuangJinReader.CanMinus(readi/100);(!res) || (err != nil) {
			simple.DialogInfo("取出黄金时出错", global.Main_Window)
			return
		}
		global.File_AncientTongQianReader.AddNum(readi)
		simple.DialogInfo("兑换成功", global.Main_Window)
		p.router(interfaces.PageID_AncientShopEasyTongPage)
	})

	vbox := container.NewVBox(
		simple.HorizonCenter(title),
		simple.Spacer(20),
		simple.HorizonCenter(showb),
		simple.HorizonCenter(showtong),
		simple.Spacer(130),
		simple.HorizonLeft(tishi),
		simple.HorizonLeftHalf(inputCun),
		simple.HorizonLeft(btnOk),
		simple.Spacer(100),
		simple.HorizonRight(btnBack),
		layout.NewSpacer(),
	)

    return container.NewBorder(
		vbox, 
		nil, nil, nil, nil, 
	)
}

func (p *AncientShopEasyTongPage) GetID() interfaces.PageID {
    return interfaces.PageID_AncientShopEasyTongPage
}

func (p *AncientShopEasyTongPage) SetRouter(fn func(interfaces.PageID)) {
    p.router = fn
}
