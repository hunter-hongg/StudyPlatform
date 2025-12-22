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

type XianDanLianPage struct {
    router func(interfaces.PageID)
}

func NewXianDanLianPage() *XianDanLianPage {
    return &XianDanLianPage{}
}

func (p *XianDanLianPage) GetContent() fyne.CanvasObject {
	title := canvas.NewText("炼制仙丹", color.Black)
	title.TextSize = 27

	deal := func(fpo *util.FilePassword, fpn *util.FilePassword, fpt *util.FilePassword, fptneed int) {
		if res, err := fpo.High(2); (!res) || (err != nil) {
			simple.DialogInfo("仙丹出错", global.Main_Window)
			return
		}
		if res, err := fpt.High(fptneed); (!res) || (err!=nil) {
			simple.DialogInfo("炼制出错", global.Main_Window)
			return
		}
		fpo.MinusNum(2)
		fpt.MinusNum(fptneed)
		fpn.AddNum(1)
		simple.DialogInfo("炼制成功", global.Main_Window)
	}
	syn.Ignore(deal)

	sm := canvas.NewText(
		"注意: 每颗高等级仙丹需要由2颗低等级仙丹加上指定条件炼制成功", simple.Blue,
	)
	sm.TextSize = 18

	level1 := []string{"普通丹", "碧丹", "青丹", "紫丹", "五色丹", "银丹"}
	level1f := []*util.FilePassword{global.File_XianPuTongDanReader, global.File_XianBiDanReader, global.File_XianQingDanReader,
									global.File_XianZiDanReader, global.File_XianWuSeDanReader, global.File_XianYinDanReader}
	var btns []fyne.CanvasObject

	for i := 1; i < len(level1); i++ {
		btns = append(btns, 
			widget.NewButton(
				strconv.Itoa(i * 5 + 5)+"仙器法力=>1"+level1[i], func() {
					deal(level1f[i-1], level1f[i], global.File_XianQiFaLiReader, i * 5 + 5)
				},
			),
		)
	}

	btnBack := widget.NewButton("返回", func(){
		p.router(interfaces.PageID_XianDanMainPage)
	})

	vbox := container.NewVBox(
		simple.HorizonCenter(title),
		simple.Spacer(20),
		simple.HorizonCenter(sm),
		simple.Spacer(130),
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

func (p *XianDanLianPage) GetID() interfaces.PageID {
    return interfaces.PageID_XianDanLianPage
}

func (p *XianDanLianPage) SetRouter(fn func(interfaces.PageID)) {
    p.router = fn
}
