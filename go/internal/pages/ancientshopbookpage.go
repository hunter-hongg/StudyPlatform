package pages

import (
	"StudyPlatform/internal/global"
	"StudyPlatform/internal/interfaces"
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

type AncientShopBookPage struct {
    router func(interfaces.PageID)
}

func NewAncientShopBookPage() *AncientShopBookPage {
    return &AncientShopBookPage{}
}

func (p *AncientShopBookPage) GetContent() fyne.CanvasObject {
	title := canvas.NewText("书籍店铺", color.Black)
	title.TextSize = 27

	deal := func(af *util.AddFile, add int) {
		if !af.CanMinusSafe(1) {
			simple.DialogInfo("取出书籍失败", global.Main_Window)
			return
		}
		global.File_AncientBaiYinReader.AddNum(add)
		simple.DialogInfo("卖出成功", global.Main_Window)
		p.router(interfaces.PageID_AncientShopBookPage)
	}
	syn.Ignore(deal)

	showj := canvas.NewText(
		"白银: "+global.File_AncientBaiYinReader.ReadStrSafe(),
	simple.Blue)
	showj.TextSize = 20

	btnBack := widget.NewButton("返回", func(){
		p.router(interfaces.PageID_AncientShopMainPage)
	})

	var btns []fyne.CanvasObject
	var afp []*util.AddFile = []*util.AddFile{
		global.File_AncientBookc1, global.File_AncientBookc2, 
		global.File_AncientBookc3, global.File_AncientBookc4, 
		global.File_AncientBookc5,
	}
	var price []int = []int {
		90, 150, 200, 350, 675, 
	}

	for i := 0 ; i < len(afp) ; i++ {
		btns = append(btns, 
			widget.NewButton(
				"抄录书籍"+strconv.Itoa(i+1)+"级=>"+strconv.Itoa(price[i])+"两白银",
				func(){
					deal(afp[i], price[i])
				},
			),
		)
	}

	vbox := container.NewVBox(
		simple.HorizonCenter(title),
		simple.Spacer(20),
		simple.HorizonCenter(showj),
		simple.Spacer(140),
		container.NewGridWithColumns(2, btns...),
		simple.Spacer(100),
		simple.HorizonRight(btnBack),
		layout.NewSpacer(),
	)

    return container.NewBorder(
		vbox, 
		nil, nil, nil, nil, 
	)
}

func (p *AncientShopBookPage) GetID() interfaces.PageID {
    return interfaces.PageID_AncientShopBookPage
}

func (p *AncientShopBookPage) SetRouter(fn func(interfaces.PageID)) {
    p.router = fn
}
