package pages

import (
	"StudyPlatform/internal/abookchao"
	"StudyPlatform/internal/global"
	"StudyPlatform/internal/interfaces"
	"StudyPlatform/pkg/cgo"
	"StudyPlatform/pkg/simple"
	"StudyPlatform/pkg/syn"
	"StudyPlatform/pkg/util"
	"strconv"

	"image/color"

	"fyne.io/fyne/v2"
	"fyne.io/fyne/v2/canvas"
	"fyne.io/fyne/v2/container"
	"fyne.io/fyne/v2/layout"
	"fyne.io/fyne/v2/widget"
)

type AncientSoldMainPage struct {
    router func(interfaces.PageID)
}

func NewAncientSoldMainPage() *AncientSoldMainPage {
    return &AncientSoldMainPage{}
}

func (p *AncientSoldMainPage) GetContent() fyne.CanvasObject {
	title := canvas.NewText("物品卖出", color.Black)
	title.TextSize = 27

	btnBack := widget.NewButton("返回", func(){
		p.router(interfaces.PageID_AncientMainPage)
	})

	btn0 := widget.NewButton("卖出宝物", func(){
		p.router(interfaces.PageID_AncientSoldBaowuPage)
	})
	
	btn1 := widget.NewButton("叫卖书籍", func(){
		if !global.File_AncientTongQianReader.CanMinusSafe(5) {
			simple.DialogInfo("铜钱不足", global.Main_Window)
			return
		}
		restype := cgo.GetRnd(1, 3) 
		var aff *util.AddFile
		var price int
		var shows string
		switch restype {
		case 1:
			price = cgo.GetRnd(7, 20)
			aff = global.File_AncientBook1
			shows = "普通书籍"
		case 2:
			price = cgo.GetRnd(18, 40)
			aff = global.File_AncientBook2
			shows = "珍稀书籍"
		case 3:
			price = cgo.GetRnd(38, 60)
			aff = global.File_AncientBook3
			shows = "典藏书籍"
		default:
			global.Logger.Error("生成等级错误")
			return
		}
		if !aff.CanMinusSafe(1) {
			simple.DialogInfo("书籍不足", global.Main_Window)
			return
		}
		global.File_AncientBaiYinReader.AddNum(price)
		simple.DialogInfo("叫卖成功，卖出一本"+shows+"获得"+strconv.Itoa(price)+"白银", global.Main_Window)
	})

	btn2 := widget.NewButton("抄录新书", func() {
		if !global.File_AncientBaiYinReader.CanMinusSafe(5) {
			simple.DialogInfo("白银不足", global.Main_Window)
			return 
		}
		lv1, lv2, lv3, lvdj, needhu := abookchao.CalcNeed()
		if res, err := global.File_AncientHuangJinReader.High(needhu); (!res) || (err != nil) {
			simple.DialogInfo("黄金不足", global.Main_Window)
			return
		}
		if !global.File_AncientBook1.High(lv1) {
			simple.DialogInfo("书籍不足", global.Main_Window)
			return
		}
		if !global.File_AncientBook2.High(lv2) {
			simple.DialogInfo("书籍不足", global.Main_Window)
			return
		}
		if !global.File_AncientBook3.High(lv3) {
			simple.DialogInfo("书籍不足", global.Main_Window)
			return
		}
		global.File_AncientHuangJinReader.MinusNum(needhu)
		global.File_AncientBook1.AddNum(-1)
		global.File_AncientBook2.AddNum(-1)
		global.File_AncientBook3.AddNum(-1)
		syn.Ignore(lvdj)
		bks := []*util.AddFile{
			global.File_AncientBookc1, global.File_AncientBookc2, global.File_AncientBookc3, 
			global.File_AncientBookc4, global.File_AncientBookc5,
		}
		if lvdj < 1 || lvdj > 5 {
			global.Logger.Error("错误的抄录等级")
			return
		}
		bks[lvdj - 1].AddNum(1)
		simple.DialogInfo("抄录成功 制作出一本"+strconv.Itoa(lvdj)+"级抄录书籍", global.Main_Window)
	})
	
	vbox := container.NewVBox(
		simple.HorizonCenter(title),
		simple.Spacer(170),
		simple.HorizonCenter(btn0),
		simple.HorizonCenter(btn1),
		simple.HorizonCenter(btn2),
		simple.Spacer(100),
		simple.HorizonRight(btnBack),
		layout.NewSpacer(),
	)

    return container.NewBorder(
		vbox, 
		nil, nil, nil, nil, 
	)
}

func (p *AncientSoldMainPage) GetID() interfaces.PageID {
    return interfaces.PageID_AncientSoldMainPage
}

func (p *AncientSoldMainPage) SetRouter(fn func(interfaces.PageID)) {
    p.router = fn
}
