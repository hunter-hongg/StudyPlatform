package pages

import (
	"StudyPlatform/src/interfaces"
	"StudyPlatform/src/pkg/global"
	"StudyPlatform/src/pkg/simple"
	"strconv"

	"image/color"

	"fyne.io/fyne/v2"
	"fyne.io/fyne/v2/canvas"
	"fyne.io/fyne/v2/container"
	"fyne.io/fyne/v2/layout"
	"fyne.io/fyne/v2/widget"
)

type TongJifenPage struct {
    router func(interfaces.PageID)
}

func NewTongJifenPage() *TongJifenPage {
    return &TongJifenPage{}
}

func (p *TongJifenPage) GetContent() fyne.CanvasObject {
	title := canvas.NewText("积分兑换", color.Black)
	title.TextSize = 27

	showtong := canvas.NewText(
		"通用货币: "+global.File_TongYongReader.ReadStrSafe(),
	simple.Blue)
	showtong.TextSize = 20

	showjifen := canvas.NewText(
		"积分: "+global.File_JiFenReader.ReadStrSafe(),
	simple.Blue)
	showjifen.TextSize = 20

	btnBack := widget.NewButton("返回", func(){
		p.router(interfaces.PageID_TongMainPage)
	})

	tishi := canvas.NewText("请输入兑换通用货币数: ", simple.Blue)
	tishi.TextSize = 20
	inputTong := widget.NewEntry()
	inputTong.Text = "请输入..."
	btnOk := widget.NewButton("兑换", func(){
		read := inputTong.Text
		readi, err := strconv.Atoi(read)
		if err != nil {
			simple.DialogError(err, global.Main_Window)
			return
		}
		if res, err := global.File_JiFenReader.CanMinus(readi * 1000);(!res) || (err != nil) {
			simple.DialogInfo("取出积分时出错", global.Main_Window)
			return
		}
		global.File_TongYongReader.AddNum(readi)
		simple.DialogInfo("兑换成功", global.Main_Window)
		p.router(interfaces.PageID_TongJifenPage)
	})

	vbox := container.NewVBox(
		simple.HorizonCenter(title),
		simple.Spacer(20),
		simple.HorizonCenter(showjifen),
		simple.HorizonCenter(showtong),
		simple.Spacer(130),
		simple.HorizonLeft(tishi),
		simple.HorizonLeftHalf(inputTong),
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

func (p *TongJifenPage) GetID() interfaces.PageID {
    return interfaces.PageID_TongJifenPage
}

func (p *TongJifenPage) SetRouter(fn func(interfaces.PageID)) {
    p.router = fn
}
