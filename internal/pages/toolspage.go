package pages

import (
	"StudyPlatform/internal/global"
	"StudyPlatform/internal/interfaces"
	"StudyPlatform/pkg/simple"
	"os"
	"os/exec"
	"path/filepath"

	"image/color"

	"fyne.io/fyne/v2"
	"fyne.io/fyne/v2/canvas"
	"fyne.io/fyne/v2/container"
	"fyne.io/fyne/v2/layout"
	"fyne.io/fyne/v2/widget"
)

type ToolsPage struct {
    router func(interfaces.PageID)
}

func NewToolsPage() *ToolsPage {
    return &ToolsPage{}
}

func (p *ToolsPage) GetContent() fyne.CanvasObject {
	title := canvas.NewText("各类工具", color.Black)
	title.TextSize = 27

	btnBack := widget.NewButton("返回", func(){
		p.router(interfaces.PageID_MainPage)
	})

	btnNote := widget.NewButton("笔记管理", func() {
		dirnamee, _ := os.Executable()
		dirnamee = filepath.Dir(dirnamee)
		cmdr := exec.Command(dirnamee+"/util/NoteTool")
		cmdr.Start()
		cmdr.Wait()
	})

	btn2 := widget.NewButton("太空保卫", func(){
		simple.DialogQuestion(
			"即将启动太空保卫 关闭窗口后请按Esc退出", global.Main_Window, 
			func() {
				dirnamee, _ := os.Executable()
				dirnamee = filepath.Dir(dirnamee)
				cmdr := exec.Command(dirnamee+"/util/SpaceGo")
				cmdr.Start()
				cmdr.Wait()
			}, func(){},
		)
	})

	vbox := container.NewVBox(
		simple.HorizonCenter(title),
		simple.Spacer(200),
		simple.HorizonCenter(btnNote),
		simple.HorizonCenter(btn2),
		simple.Spacer(100),
		simple.HorizonRight(btnBack),
		layout.NewSpacer(),
	)

    return container.NewBorder(
		vbox, 
		nil, nil, nil, nil, 
	)
}

func (p *ToolsPage) GetID() interfaces.PageID {
    return interfaces.PageID_ToolsPage
}

func (p *ToolsPage) SetRouter(fn func(interfaces.PageID)) {
    p.router = fn
}
