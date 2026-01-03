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

type BankJuanRealPage struct {
    router func(interfaces.PageID)
}

func NewBankJuanRealPage() *BankJuanRealPage {
    return &BankJuanRealPage{}
}

func (p *BankJuanRealPage) GetContent() fyne.CanvasObject {
	title := canvas.NewText("捐献积分", color.Black)
	title.TextSize = 27

	showcun := canvas.NewText(
		"存储积分: "+global.File_BankStoreReader.ReadStrSafe(),
	simple.Blue)
	showcun.TextSize = 20

	showjuan := canvas.NewText(
		"捐献券: "+global.File_BankJuanQuanReader.ReadStrSafe(),
	simple.Blue)
	showjuan.TextSize = 20

	btnBack := widget.NewButton("返回", func(){
		p.router(interfaces.PageID_BankJuanMainPage)
	})

	tishi := canvas.NewText("请输入捐献积分数: ", simple.Blue)
	tishi.TextSize = 20
	inputCun := widget.NewEntry()
	inputCun.Text = "请输入..."
	btnOk := widget.NewButton("捐献", func(){
		read := inputCun.Text
		readi, err := strconv.Atoi(read)
		if err != nil {
			simple.DialogError(err, global.Main_Window)
			return
		}
		if res, err := global.File_BankStoreReader.CanMinus(readi);(!res) || (err != nil) {
			simple.DialogInfo("取出存储积分时出错", global.Main_Window)
			return
		}
		deal := func(ji int) int {
			if ji < 200 {
				return 0
			} else {
				return 1 + (ji / 150) + cgo.GetRnd(0, 1)
			}
		}
		ress := deal(readi)
		global.File_BankJuanQuanReader.AddNum(ress)
		simple.DialogInfo("捐献成功，获得"+strconv.Itoa(ress)+"捐献券", global.Main_Window)
		p.router(interfaces.PageID_BankJuanRealPage)
	})

	vbox := container.NewVBox(
		simple.HorizonCenter(title),
		simple.Spacer(20),
		simple.HorizonCenter(showjuan),
		simple.HorizonCenter(showcun),
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

func (p *BankJuanRealPage) GetID() interfaces.PageID {
    return interfaces.PageID_BankJuanRealPage
}

func (p *BankJuanRealPage) SetRouter(fn func(interfaces.PageID)) {
    p.router = fn
}
