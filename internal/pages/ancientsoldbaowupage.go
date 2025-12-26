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

type AncientSoldBaowuPage struct {
    router func(interfaces.PageID)
}

func NewAncientSoldBaowuPage() *AncientSoldBaowuPage {
    return &AncientSoldBaowuPage{}
}

func (p *AncientSoldBaowuPage) GetContent() fyne.CanvasObject {
	title := canvas.NewText("宝物卖出", color.Black)
	title.TextSize = 27

	deal := func(af *util.AddFile, minus int, raf *util.AddFile, add int) {
		if !af.CanMinus(minus){
			simple.DialogInfo("取出宝物失败", global.Main_Window)
			return
		}
		raf.AddNum(add)
		simple.DialogInfo("卖出成功", global.Main_Window)
		p.router(interfaces.PageID_AncientSoldBaowuPage)
	}
	syn.Ignore(deal)

	showj := canvas.NewText(
		"绿玉: "+global.File_AncientLvYuReader.ReadStrSafe(),
	simple.Blue)
	showj.TextSize = 20

	showb := canvas.NewText(
		"白玉: "+global.File_AncientBaiYuReader.ReadStrSafe(),
	simple.Blue)
	showb.TextSize = 20

	btnBack := widget.NewButton("返回", func(){
		p.router(interfaces.PageID_AncientSoldMainPage)
	})

	var btns []fyne.CanvasObject
	var afp []*util.AddFile = []*util.AddFile{
		global.File_AncientBaoMingZhu, global.File_AncientBaoYuDiao,
		global.File_AncientBaoYuBi, global.File_AncientBaoChouDuan,
		global.File_AncientBaoYuzhan, global.File_AncientBaoHu,
		global.File_AncientBaoZhan,
	}
	var shows []string = []string {
		"明珠", "玉雕", "玉璧", "绸缎", "玉盏", "玉壶", "玉杯",
	}
	var price []int = []int {
		10, 15, 5, 2, 5, 7, 9, 
	}
	var rafs = []*util.AddFile{
		global.File_AncientBaiYuReader, global.File_AncientBaiYuReader, 
		global.File_AncientLvYuReader, global.File_AncientLvYuReader, 
		global.File_AncientLvYuReader, global.File_AncientLvYuReader, 
		global.File_AncientLvYuReader,
	}
	var rafss []string 
	for _, i := range rafs {
		switch i {
		case global.File_AncientBaiYuReader:
			rafss = append(rafss, "白玉")
		case global.File_AncientLvYuReader:
			rafss = append(rafss, "绿玉")
		}
	}

	for i := 0 ; i < len(shows) ; i++ {
		btns = append(btns, 
			widget.NewButton(
				shows[i]+"=>"+strconv.Itoa(price[i])+rafss[i], func(){
					deal(afp[i], 1, rafs[i], price[i])
				},
			),
		)
	}

	vbox := container.NewVBox(
		simple.HorizonCenter(title),
		simple.Spacer(20),
		simple.HorizonCenter(showj),
		simple.HorizonCenter(showb),
		simple.Spacer(100),
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

func (p *AncientSoldBaowuPage) GetID() interfaces.PageID {
    return interfaces.PageID_AncientSoldBaowuPage
}

func (p *AncientSoldBaowuPage) SetRouter(fn func(interfaces.PageID)) {
    p.router = fn
}
