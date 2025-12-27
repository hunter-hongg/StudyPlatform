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

type AncientGuanWuZhaobingPage struct {
    router func(interfaces.PageID)
}

func NewAncientGuanWuZhaobingPage() *AncientGuanWuZhaobingPage {
    return &AncientGuanWuZhaobingPage{}
}

func (p *AncientGuanWuZhaobingPage) GetContent() fyne.CanvasObject {
	title := canvas.NewText("征召士兵", color.Black)
	title.TextSize = 27

	// 1 -> 10 -> 30 -> 60 -> 150 -> 350 -> 750 -> 1000
	// 单位白银

	deal := func(af util.AddAble, minus int, add int) {
		if !global.File_AncientBaiYinReader.CanMinusSafe(minus){
			simple.DialogInfo("取出白银失败", global.Main_Window)
			return
		}
		af.AddNum(add)
		simple.DialogInfo("征召成功", global.Main_Window)
		p.router(interfaces.PageID_AncientGuanWuZhaobingPage)
	}
	syn.Ignore(deal)

	showj := canvas.NewText(
		"白银: "+global.File_AncientBaiYinReader.ReadStrSafe(),
	simple.Blue)
	showj.TextSize = 20

	btnBack := widget.NewButton("返回", func(){
		p.router(interfaces.PageID_AncientGuanWuMainPage)
	})

	var btns []fyne.CanvasObject
	var afp = []*util.FilePassword{
		global.File_AncientWuXinLr, global.File_AncientWuPuTongLr, global.File_AncientWuChuJiLr,
		global.File_AncientWuZhongJiLr, global.File_AncientWuGaoJiLr, global.File_AncientWuJingRuiLr,
		global.File_AncientWuWangPaiLr, global.File_AncientWuShenJiLr,
	}
	var shows []string = []string {
		"新兵", "普通兵", "初级兵", "中级兵", "高级兵", "精锐兵", "王牌兵", "神级兵",
	}
	var price []int = []int {
		1, 10, 30, 60, 150, 350, 700, 900, 
	}

	for i := 0 ; i < len(shows) ; i++ {
		btns = append(btns, 
			widget.NewButton(
				shows[i]+": "+afp[i].ReadStrSafe()+"名", 
				func(){
					ij := i
					simple.DialogQuestion(
						"是否花费"+strconv.Itoa(price[ij])+"白银征召1"+shows[ij], global.Main_Window, 
						func(){
							deal(afp[i], price[i], 1)
						}, func(){},
					)
				},
			),
		)
	}
	
	vbox := container.NewVBox(
		simple.HorizonCenter(title),
		simple.Spacer(20),
		simple.HorizonCenter(showj),
		simple.Spacer(140),
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

func (p *AncientGuanWuZhaobingPage) GetID() interfaces.PageID {
    return interfaces.PageID_AncientGuanWuZhaobingPage
}

func (p *AncientGuanWuZhaobingPage) SetRouter(fn func(interfaces.PageID)) {
    p.router = fn
}
