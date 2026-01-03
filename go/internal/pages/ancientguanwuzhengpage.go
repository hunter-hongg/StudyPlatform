package pages

import (
	"StudyPlatform/internal/achuzheng"
	"StudyPlatform/internal/gfunc"
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

type AncientGuanWuChuzhengPage struct {
    router func(interfaces.PageID)
}

func NewAncientGuanWuChuzhengPage() *AncientGuanWuChuzhengPage {
    return &AncientGuanWuChuzhengPage{}
}

func (p *AncientGuanWuChuzhengPage) GetContent() fyne.CanvasObject {
	title := canvas.NewText("领兵出征", color.Black)
	title.TextSize = 27

	if global.AncientZheng_BingOther < 0 && global.AncientZheng_BingSelf < 0 {
		bsf := gfunc.AncientWuBinglg()
		bot := gfunc.AncientWuBinglg() + cgo.GetRnd(-100, 100)
		if bot <= 30 {
			bot = 30
		}
		global.AncientZheng_BingOther = bot 
		global.AncientZheng_BingSelf = bsf
		global.AncientZheng_UserChoice = []achuzheng.Choices{}
	}

	deal := func(evt achuzheng.Choices) {
		global.AncientZheng_UserChoice = append(global.AncientZheng_UserChoice, evt)
		oevt := achuzheng.GetChoice(
			global.AncientZheng_BingSelf,
			global.AncientZheng_BingOther, 
			global.AncientZheng_UserChoice,
		)
		ress, reso := achuzheng.GetResult(evt, oevt)
		var ops string
		var opo string
		if ress > 0 {
			ops = "+"
		} else {
			ops = "-"
		}
		if reso > 0 {
			opo = "+"
		} else {
			opo = "-"
		}
		global.AncientZheng_BingSelf += ress
		global.AncientZheng_BingOther += reso
		simple.DialogInfo(
			"你的选择: "+achuzheng.ToString(evt)+"\n对方选择: "+achuzheng.ToString(oevt)+
			"\n你的兵力"+ops+strconv.Itoa(util.IAbs(ress))+"\n对方兵力"+opo+strconv.Itoa(util.IAbs(reso)), 
			global.Main_Window,
		)
		if global.AncientZheng_BingOther < 0 {
			simple.DialogInfo("这次出征大获全胜\n胜不骄败不馁\n战果: 白银+550", global.Main_Window)
			global.File_AncientBaiYinReader.AddNum(550)
			goto NEXTTIME
		} else if global.AncientZheng_BingSelf < 0 {
			simple.DialogInfo("这次出征败兵而归\n胜败乃兵家常事\n战果: 白银-50", global.Main_Window)
			global.File_AncientBaiYinReader.MinusNumIf(50)
			goto NEXTTIME
		}
		p.router(interfaces.PageID_AncientGuanWuChuzhengPage)
		return
		NEXTTIME: 
		global.AncientZheng_BingOther = -1
		global.AncientZheng_BingSelf = -1
		p.router(interfaces.PageID_AncientGuanWuMainPage)
	}
	syn.Ignore(deal)

	showj := canvas.NewText(
		"我方兵力: "+strconv.Itoa(global.AncientZheng_BingSelf),
	simple.Blue)
	showj.TextSize = 20

	showd := canvas.NewText(
		"对方兵力: "+strconv.Itoa(global.AncientZheng_BingOther),
	simple.Blue)
	showd.TextSize = 20

	btnBack := widget.NewButton("返回", func(){
		p.router(interfaces.PageID_AncientGuanWuMainPage)
	})

	var btns []fyne.CanvasObject
	var choices = []achuzheng.Choices{
		achuzheng.JinGong, 
		achuzheng.FangShou, 
		achuzheng.XiuZheng, 
		achuzheng.TouXi,
	}
	var shows = []string{
		"进攻敌军", "防守敌军", "休整兵马", "趁其不备",
	}

	for i := 0 ; i < 4 ; i++ {
		btns = append(btns, 
			widget.NewButton(
				shows[i], func() {
					deal(choices[i])
				},
			),
		)
	}
	
	vbox := container.NewVBox(
		simple.HorizonCenter(title),
		simple.Spacer(20),
		simple.HorizonCenter(showj),
		simple.HorizonCenter(showd),
		simple.Spacer(110),
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

func (p *AncientGuanWuChuzhengPage) GetID() interfaces.PageID {
    return interfaces.PageID_AncientGuanWuChuzhengPage
}

func (p *AncientGuanWuChuzhengPage) SetRouter(fn func(interfaces.PageID)) {
    p.router = fn
}
