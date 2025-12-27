package pages

import (
	"StudyPlatform/internal/global"
	"StudyPlatform/internal/interfaces"
	"StudyPlatform/pkg/cgo"
	"StudyPlatform/pkg/simple"
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
	
	vbox := container.NewVBox(
		simple.HorizonCenter(title),
		simple.Spacer(170),
		simple.HorizonCenter(btn0),
		simple.HorizonCenter(btn1),
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
