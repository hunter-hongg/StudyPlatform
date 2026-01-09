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

type BankCunPage struct {
    router func(interfaces.PageID)
}

func NewBankCunPage() *BankCunPage {
    return &BankCunPage{}
}

func (p *BankCunPage) GetContent() fyne.CanvasObject {
	title := canvas.NewText("存储积分", color.Black)
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

	tishi := canvas.NewText("请输入存储积分数: ", simple.Blue)
	tishi.TextSize = 20
	inputCun := widget.NewEntry()
	inputCun.Text = "请输入..."
	btnOk := widget.NewButton("存储", func(){
		read := inputCun.Text
		readi, err := strconv.Atoi(read)
		if err != nil {
			simple.DialogError(err, global.Main_Window)
			return
		}
		if res, err := global.File_JiFenReader.CanMinus(readi);(!res) || (err != nil) {
			simple.DialogInfo("取出积分时出错", global.Main_Window)
			return
		}
		global.File_BankStoreReader.AddNum(readi)
		simple.DialogInfo("存储成功", global.Main_Window)
		p.router(interfaces.PageID_BankCunPage)
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

func (p *BankCunPage) GetID() interfaces.PageID {
    return interfaces.PageID_BankCunPage
}

func (p *BankCunPage) SetRouter(fn func(interfaces.PageID)) {
    p.router = fn
}
