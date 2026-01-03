package pages

import (
	"StudyPlatform/internal/global"
	"StudyPlatform/internal/interfaces"
	"StudyPlatform/pkg/simple"

	"image/color"

	"fyne.io/fyne/v2"
	"fyne.io/fyne/v2/canvas"
	"fyne.io/fyne/v2/container"
	"fyne.io/fyne/v2/layout"
	"fyne.io/fyne/v2/widget"
)

type LiHePage struct {
    router func(interfaces.PageID)
}

func NewLiHePage() *LiHePage {
    return &LiHePage{}
}

func (p *LiHePage) GetContent() fyne.CanvasObject {
	title := canvas.NewText("我的礼盒", color.Black)
	title.TextSize = 27

	btnBack := widget.NewButton("返回", func(){
		p.router(interfaces.PageID_OwnPage)
	})
	
	btnBasic := widget.NewButton("初始基础礼盒", func(){})
	var btnBasicStatus fyne.CanvasObject
	switch global.File_BasicLiHeOnce.CheckTimes() {
	case true: 
		btnBasicStatus = widget.NewButton("使用礼盒", func() {
			global.Logger.Debug("正常启动")
			global.File_JiFenReader.AddNum(200)
			global.File_JinBiReader.AddNum(5)
			global.File_BasicLiHeOnce.Use()
			simple.DialogInfo("使用成功，获得200积分+5金币", global.Main_Window)
			global.Logger.Debug("正常处理完毕")
			p.router(interfaces.PageID_LiHePage)
		})
	case false: 
		btnBasicStatus = widget.NewButton("礼盒已使用", func(){
			global.Logger.Warn("礼盒使用完毕 无法再次使用")
		})
	}

	vbox := container.NewVBox(
		simple.HorizonCenter(title),
		simple.Spacer(200),
		container.NewGridWithColumns(2, 
			simple.HorizonRight(btnBasic),
			simple.HorizonLeft(btnBasicStatus),
		),
		simple.Spacer(100),
		simple.HorizonRight(btnBack),
		layout.NewSpacer(),
	)

    return container.NewBorder(
		vbox, 
		nil, nil, nil, nil, 
	)
}

func (p *LiHePage) GetID() interfaces.PageID {
    return interfaces.PageID_LiHePage
}

func (p *LiHePage) SetRouter(fn func(interfaces.PageID)) {
    p.router = fn
}
