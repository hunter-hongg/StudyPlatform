package pages

import (
	"StudyPlatform/internal/global"
	"StudyPlatform/internal/interfaces"
	"StudyPlatform/pkg/simple"
	"StudyPlatform/pkg/util"

	"image/color"

	"fyne.io/fyne/v2"
	"fyne.io/fyne/v2/canvas"
	"fyne.io/fyne/v2/container"
	"fyne.io/fyne/v2/layout"
	"fyne.io/fyne/v2/widget"
)

type XianDanShowPage struct {
    router func(interfaces.PageID)
}

func NewXianDanShowPage() *XianDanShowPage {
    return &XianDanShowPage{}
}

func (p *XianDanShowPage) GetContent() fyne.CanvasObject {
	title := canvas.NewText("我的仙丹", color.Black)
	title.TextSize = 27

	btnBack := widget.NewButton("返回", func(){
		p.router(interfaces.PageID_XianThingMainPage)
	})

	var btns []fyne.CanvasObject
	dans := [...]util.FilePassword{
		*global.File_XianPuTongDanReader, *global.File_XianBiDanReader, *global.File_XianQingDanReader, 
		*global.File_XianZiDanReader, *global.File_XianWuSeDanReader, *global.File_XianYinDanReader, 
		*global.File_XianJinDanReader, *global.File_XianShenDanReader, 
	}
	indexstr := [...]string{"普通丹", "碧丹", "青丹", "紫丹", "五色丹", "银丹", "金丹", "神丹"}
	for index, i := range dans {
		btns = append(btns, widget.NewButton(
			indexstr[index]+": "+i.ReadStrSafe()+"颗", func(){},
		))
	}

	vbox := container.NewVBox(
		simple.HorizonCenter(title),
		simple.Spacer(170),
		container.NewGridWithColumns(3, btns...),
		simple.Spacer(100),
		simple.HorizonRight(btnBack),
		layout.NewSpacer(),
	)

    return container.NewBorder(
		vbox, 
		nil, nil, nil, nil, 
	)
}

func (p *XianDanShowPage) GetID() interfaces.PageID {
    return interfaces.PageID_XianDanShowPage
}

func (p *XianDanShowPage) SetRouter(fn func(interfaces.PageID)) {
    p.router = fn
}
