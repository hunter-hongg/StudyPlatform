package pages

import (
	"StudyPlatform/internal/global"
	"StudyPlatform/internal/interfaces"
	"StudyPlatform/pkg/cgo"
	"StudyPlatform/pkg/simple"
	"strconv"

	"image/color"

	"fyne.io/fyne/v2"
	"fyne.io/fyne/v2/canvas"
	"fyne.io/fyne/v2/container"
	"fyne.io/fyne/v2/layout"
	"fyne.io/fyne/v2/widget"
)

type BankJuanGetJifenPage struct {
    router func(interfaces.PageID)
}

func NewBankJuanGetJifenPage() *BankJuanGetJifenPage {
    return &BankJuanGetJifenPage{}
}

func (p *BankJuanGetJifenPage) GetContent() fyne.CanvasObject {
	title := canvas.NewText("积分奖励", color.Black)
	title.TextSize = 27

	showji := canvas.NewText(
		"积分: "+global.File_JiFenReader.ReadStrSafe(),
	simple.Blue)
	showji.TextSize = 20

	showjuan := canvas.NewText(
		"捐献券: "+global.File_BankJuanQuanReader.ReadStrSafe(),
	simple.Blue)
	showjuan.TextSize = 20

	btnBack := widget.NewButton("返回", func(){
		p.router(interfaces.PageID_BankJuanGetMainPage)
	})

	tishi := canvas.NewText("请输入使用捐献券数: ", simple.Blue)
	tishi.TextSize = 20
	inputCun := widget.NewEntry()
	inputCun.Text = "请输入..."
	btnOk := widget.NewButton("使用", func(){
		read := inputCun.Text
		readi, err := strconv.Atoi(read)
		if err != nil {
			simple.DialogError(err, global.Main_Window)
			return
		}
		if res, err := global.File_BankJuanQuanReader.CanMinus(readi);(!res) || (err != nil) {
			simple.DialogInfo("取出捐献券时出错", global.Main_Window)
			return
		}
		deal := func(ju int) int {
			return 200*ju + cgo.GetRnd(-100, 100)
		}
		ress := deal(readi)
		global.File_JiFenReader.AddNum(ress)
		simple.DialogInfo("使用成功，获得"+strconv.Itoa(ress)+"积分", global.Main_Window)
		p.router(interfaces.PageID_BankJuanGetJifenPage)
	})

	vbox := container.NewVBox(
		simple.HorizonCenter(title),
		simple.Spacer(20),
		simple.HorizonCenter(showjuan),
		simple.HorizonCenter(showji),
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

func (p *BankJuanGetJifenPage) GetID() interfaces.PageID {
    return interfaces.PageID_BankJuanGetJifenPage
}

func (p *BankJuanGetJifenPage) SetRouter(fn func(interfaces.PageID)) {
    p.router = fn
}
