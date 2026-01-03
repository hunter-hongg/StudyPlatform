package pages

import (
	"StudyPlatform/internal/gfunc"
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

type AncientGuanWuZengbingPage struct {
    router func(interfaces.PageID)
}

func NewAncientGuanWuZengbingPage() *AncientGuanWuZengbingPage {
    return &AncientGuanWuZengbingPage{}
}

func (p *AncientGuanWuZengbingPage) GetContent() fyne.CanvasObject {
	title := canvas.NewText("增强兵力", color.Black)
	title.TextSize = 27

	/* +5 */

	deal := func(af *util.FilePassword, min int) {
		need := gfunc.AncientWuBinglp(af.ReadIntSafe(), min)
		if !global.File_AncientBaiYinReader.CanMinusSafe(need){
			simple.DialogInfo("取出白银失败", global.Main_Window)
			return
		}
		af.AddNum(5)
		simple.DialogInfo("增强成功", global.Main_Window)
		p.router(interfaces.PageID_AncientGuanWuZengbingPage)
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
		global.File_AncientWuXinIr, global.File_AncientWuPuTongIr, global.File_AncientWuChuJiIr,
		global.File_AncientWuZhongJiIr, global.File_AncientWuGaoJiIr, global.File_AncientWuJingRuiIr,
		global.File_AncientWuWangPaiIr, global.File_AncientWuShenJiIr,
	}
	var afm = []int {
		global.File_AncientWuBinglXinMin, global.File_AncientWuBinglPuTongMin, global.File_AncientWuBinglChuJiMin, 
		global.File_AncientWuBinglZhongJiMin, global.File_AncientWuBinglGaoJiMin, global.File_AncientWuBinglJingRuiMin, 
		global.File_AncientWuBinglWangPaiMin, global.File_AncientWuBinglShenJiMin,
	}
	var shows []string = []string {
		"新兵", "普通兵", "初级兵", "中级兵", "高级兵", "精锐兵", "王牌兵", "神级兵",
	}

	for i := 0 ; i < len(shows) ; i++ {
		btns = append(btns, 
			widget.NewButton(
				shows[i]+": 兵力"+afp[i].ReadStrSafe(), 
				func(){
					ij := i
					simple.DialogQuestion(
						"是否花费"+strconv.Itoa(gfunc.AncientWuBinglp(afp[i].ReadIntSafe(), afm[i]))+"白银增加"+shows[ij]+"的兵力", global.Main_Window, 
						func(){
							deal(afp[i], afm[i])
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

func (p *AncientGuanWuZengbingPage) GetID() interfaces.PageID {
    return interfaces.PageID_AncientGuanWuZengbingPage
}

func (p *AncientGuanWuZengbingPage) SetRouter(fn func(interfaces.PageID)) {
    p.router = fn
}
