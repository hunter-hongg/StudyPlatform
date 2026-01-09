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

type BankGetPage struct {
    router func(interfaces.PageID)
}

func NewBankGetPage() *BankGetPage {
    return &BankGetPage{}
}

func (p *BankGetPage) GetContent() fyne.CanvasObject {
	title := canvas.NewText("取出积分", color.Black)
	title.TextSize = 27

	showcun := canvas.NewText(
		"存储积分: "+global.File_BankStoreReader.ReadStrSafe(),
	simple.Blue)
	showcun.TextSize = 20

	showjifen := canvas.NewText(
		"积分: "+global.File_JiFenReader.ReadStrSafe(),
	simple.Blue)
	showjifen.TextSize = 20

	btnBack := widget.NewButton("返回", func(){
		p.router(interfaces.PageID_BankMainPage)
	})

	tishi := canvas.NewText("请输入取出积分数: ", simple.Blue)
	tishi.TextSize = 20
	inputCun := widget.NewEntry()
	inputCun.Text = "请输入..."
	btnOk := widget.NewButton("取出", func(){
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
		global.File_JiFenReader.AddNum(readi)
		simple.DialogInfo("取出成功", global.Main_Window)
		p.router(interfaces.PageID_BankGetPage)
	})

	vbox := container.NewVBox(
		simple.HorizonCenter(title),
		simple.Spacer(20),
		simple.HorizonCenter(showjifen),
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

func (p *BankGetPage) GetID() interfaces.PageID {
    return interfaces.PageID_BankGetPage
}

func (p *BankGetPage) SetRouter(fn func(interfaces.PageID)) {
    p.router = fn
}
