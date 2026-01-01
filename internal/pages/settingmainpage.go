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

type SettingMainPage struct {
    router func(interfaces.PageID)
}

func NewSettingMainPage() *SettingMainPage {
    return &SettingMainPage{}
}

func (p *SettingMainPage) GetContent() fyne.CanvasObject {
	title := canvas.NewText("设置界面", color.Black)
	title.TextSize = 27

	title2 := canvas.NewText("注: 部分设置完成后请重启学习平台", color.Black)
	title2.TextSize = 18

	btnBack := widget.NewButton("返回", func(){
		p.router(interfaces.PageID_MainPage)
	})

	btnTheme := widget.NewCheck("启用暗色主题", func(checked bool){ 
		if checked {
			global.File_SettingThemeDark.SwitchTo(true)
		} else {
			global.File_SettingThemeDark.SwitchTo(false)
		}
	})
	hasc := global.File_SettingThemeDark.GetState(false)
	btnTheme.SetChecked(hasc)

	vbox := container.NewVBox(
		simple.HorizonCenter(title),
		simple.Spacer(20),
		simple.HorizonCenter(title2),
		simple.Spacer(130),
		container.NewGridWithColumns(2, 
			simple.HorizonRight(btnTheme), 
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

func (p *SettingMainPage) GetID() interfaces.PageID {
    return interfaces.PageID_SettingMainPage
}

func (p *SettingMainPage) SetRouter(fn func(interfaces.PageID)) {
    p.router = fn
}
