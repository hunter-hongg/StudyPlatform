package pages

import (
	"StudyPlatform/internal/global"
	"StudyPlatform/internal/interfaces"
	"StudyPlatform/pkg/cgo"
	"StudyPlatform/pkg/simple"
	"strconv"

	"image/color"

	"fyne.io/fyne/v2"
	"fyne.io/fyne/v2/canvas"
	"fyne.io/fyne/v2/container"
	"fyne.io/fyne/v2/layout"
	"fyne.io/fyne/v2/widget"
)

type AncientGuanWenZhengPage struct {
    router func(interfaces.PageID)
}

func NewAncientGuanWenZhengPage() *AncientGuanWenZhengPage {
    return &AncientGuanWenZhengPage{}
}

func (p *AncientGuanWenZhengPage) GetContent() fyne.CanvasObject {
	title := canvas.NewText("我的政绩", color.Black)
	title.TextSize = 27

	showb := canvas.NewText(
		"政绩: "+strconv.Itoa(global.File_AncientWenZhengjiReader.ReadIntSafe()),
	simple.Blue)
	showb.TextSize = 20

	btnBack := widget.NewButton("返回", func(){
		p.router(interfaces.PageID_AncientGuanWenMainPage)
	})

	btn0 := widget.NewButton("进宫面圣", func(){
		/* +25 */
		if !global.File_AncientWenZhengshCheck.CheckTimes() {
			simple.DialogInfo("今日已进行过面圣", global.Main_Window)
			return
		}
		global.File_AncientWenZhengjiReader.AddNum(25)
		simple.DialogInfo("面圣成功政绩+25", global.Main_Window)
		p.router(interfaces.PageID_AncientGuanWenZhengPage)
	})
	
	btn1 := widget.NewButton("贿赂权贵", func(){
		/* 3-6 -> 40*/
		need := cgo.GetRnd(3, 6)
		simple.DialogQuestion(
			"是否使用"+strconv.Itoa(need)+"块绿玉贿赂权贵?", global.Main_Window, 
			func() {
				if !global.File_AncientLvYuReader.CanMinusSafe(need) {
					simple.DialogInfo("绿玉不足", global.Main_Window)
					return
				}
				global.File_AncientWenZhengjiReader.AddNum(40)
				simple.DialogInfo("贿赂成功政绩+40", global.Main_Window)
				p.router(interfaces.PageID_AncientGuanWenZhengPage)
			}, func() {},
		)
	})

	btn2 := widget.NewButton("赈济灾民", func(){
		/* 100 -> 20 */
		simple.DialogQuestion(
			"现在有灾民100人，每人需1两白银，是否赈济?", global.Main_Window,
			func() {
				if res, err := global.File_AncientBaiYinReader.High(100); (!res) || (err != nil) {
					simple.DialogInfo("白银不足", global.Main_Window)
					return
				}
				if !global.File_AncientWenZhengjiCheck.CheckTimes() {
					simple.DialogInfo("今日已经赈济", global.Main_Window)
					return
				}
				global.File_AncientBaiYinReader.MinusNum(100)
				global.File_AncientWenZhengjiReader.AddNum(20)
				simple.DialogInfo("赈济成功政绩+20", global.Main_Window)
				p.router(interfaces.PageID_AncientGuanWenZhengPage)
			}, func(){},
		)
	})
	
	btn3 := widget.NewButton("官升一级", func(){
		/* 4->3 80 */
		needz := 20 + (9 - global.File_AncientWenGuan.ReadLevel()) * 10
		if !global.File_AncientWenZhengjiReader.CanMinusSafe(needz) {
			simple.DialogInfo("升官失败", global.Main_Window)
			return
		}
		global.File_AncientWenGuan.LevelUp()
		simple.DialogInfo("升官成功", global.Main_Window)
		p.router(interfaces.PageID_AncientGuanWenZhengPage)
	})

	vbox := container.NewVBox(
		simple.HorizonCenter(title),
		simple.Spacer(20),
		simple.HorizonCenter(showb),
		simple.Spacer(130),
		simple.HorizonCenter(btn0),
		simple.HorizonCenter(btn1),
		simple.HorizonCenter(btn2),
		simple.HorizonCenter(btn3),
		simple.Spacer(100),
		simple.HorizonRight(btnBack),
		layout.NewSpacer(),
	)

    return container.NewBorder(
		vbox, 
		nil, nil, nil, nil, 
	)
}

func (p *AncientGuanWenZhengPage) GetID() interfaces.PageID {
    return interfaces.PageID_AncientGuanWenZhengPage
}

func (p *AncientGuanWenZhengPage) SetRouter(fn func(interfaces.PageID)) {
    p.router = fn
}
