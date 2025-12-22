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

type XianDanZhaoPage struct {
    router func(interfaces.PageID)
}

func NewXianDanZhaoPage() *XianDanZhaoPage {
    return &XianDanZhaoPage{}
}

func (p *XianDanZhaoPage) GetContent() fyne.CanvasObject {
	title := canvas.NewText("仙丹召鹤", color.Black)
	title.TextSize = 27

	deal := func(fpo *util.FilePassword, jifadd int, jinadd int) {
		if res, err := fpo.CanMinus(1); (!res) || (err!=nil){
			simple.DialogInfo("仙丹不足", global.Main_Window)
			return
		}
		rndp := cgo.GetRnd(-50, 100)
		global.File_JiFenReader.AddNum(jifadd+rndp)
		global.File_JinBiReader.AddNum(jinadd+rndp)
		simple.DialogInfo("召鹤成功 获得"+strconv.Itoa(jifadd+rndp)+"积分和"+strconv.Itoa(jinadd+rndp)+"金币", global.Main_Window)
	}

	btnBack := widget.NewButton("返回", func(){
		p.router(interfaces.PageID_XianDanMainPage)
	})

	btnT := widget.NewButton("银丹召鹤", func(){
		deal(global.File_XianYinDanReader, 700, 80)
	})
	
	btnN := widget.NewButton("金丹召鹤", func(){
		deal(global.File_XianJinDanReader, 1500, 200)
	})

	btnD := widget.NewButton("神丹召鹤", func(){
		deal(global.File_XianShenDanReader, 3500, 450)
	})
	
	vbox := container.NewVBox(
		simple.HorizonCenter(title),
		simple.Spacer(170),
		simple.HorizonCenter(btnT),
		simple.HorizonCenter(btnN),
		simple.HorizonCenter(btnD),
		simple.Spacer(100),
		simple.HorizonRight(btnBack),
		layout.NewSpacer(),
	)

    return container.NewBorder(
		vbox, 
		nil, nil, nil, nil, 
	)
}

func (p *XianDanZhaoPage) GetID() interfaces.PageID {
    return interfaces.PageID_XianDanZhaoPage
}

func (p *XianDanZhaoPage) SetRouter(fn func(interfaces.PageID)) {
    p.router = fn
}
