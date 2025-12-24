package pages

import (
	"StudyPlatform/internal/apao"
	"StudyPlatform/internal/asword"
	"StudyPlatform/internal/global"
	"StudyPlatform/internal/interfaces"
	"StudyPlatform/pkg/cgo"
	"StudyPlatform/pkg/simple"
	"StudyPlatform/pkg/util"

	"image/color"

	"fyne.io/fyne/v2"
	"fyne.io/fyne/v2/canvas"
	"fyne.io/fyne/v2/container"
	"fyne.io/fyne/v2/layout"
	"fyne.io/fyne/v2/widget"
)

type AncientShopSimplePage struct {
    router func(interfaces.PageID)
}

func NewAncientShopSimplePage() *AncientShopSimplePage {
    return &AncientShopSimplePage{}
}

func (p *AncientShopSimplePage) GetContent() fyne.CanvasObject {
	dealb := func(fp *util.AddFile, need int, get int){
		if res, err := global.File_AncientBaiYinReader.CanMinus(need); (!res) || (err!=nil) {
			simple.DialogInfo("取出白银失败", global.Main_Window)
			return
		}
		fp.AddNum(get)
		simple.DialogInfo("购买成功", global.Main_Window)
	}
	title := canvas.NewText("普通店铺", color.Black)
	title.TextSize = 27

	btnBack := widget.NewButton("返回", func(){
		p.router(interfaces.PageID_AncientShopMainPage)
	})

	/*
	书籍价格 白银 <= 本
	5 <= 50
	3 <= 75
	2 <= 100
	*/

	var btns []fyne.CanvasObject
	var showb  = []string{"100黄金=>1佩剑", "300黄金=>1锦袍", "50白银=>5普通书籍", "75白银=>3珍稀书籍", "100白银=>2典藏书籍"}
	var showf  = []func() {
		func(){
			if res, err := global.File_AncientHuangJinReader.CanMinus(100); (!res) || (err!=nil) {
				simple.DialogInfo("取出黄金出错", global.Main_Window)
				return
			}
			res2 := cgo.GetRnd(0, 6)
			global.File_AncientSword.Add(asword.Sword(res2))
			simple.DialogInfo("恭喜获得"+asword.Sword(res2).String()+"一把", global.Main_Window)
		},
		func(){
			if res, err := global.File_AncientHuangJinReader.CanMinus(300); (!res) || (err!=nil) {
				simple.DialogInfo("取出黄金出错", global.Main_Window)
				return
			}
			res2 := cgo.GetRnd(0, 7)
			global.File_AncientPao.Add(apao.Pao(res2))
			simple.DialogInfo("恭喜获得"+apao.Pao(res2).String()+"一件", global.Main_Window)
		},
		func() {
			dealb(global.File_AncientBook1, 50, 5)
		},
		func() {
			dealb(global.File_AncientBook2, 75, 3)
		},
		func() {
			dealb(global.File_AncientBook3, 100, 2)
		},
	}

	for i := 0 ; i < len(showb) ; i++ {
		btns = append(btns, 
			widget.NewButton(
				showb[i], showf[i],
			),
		)
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

func (p *AncientShopSimplePage) GetID() interfaces.PageID {
    return interfaces.PageID_AncientShopSimplePage
}

func (p *AncientShopSimplePage) SetRouter(fn func(interfaces.PageID)) {
    p.router = fn
}
