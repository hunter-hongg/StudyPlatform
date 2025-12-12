package pages

import (
    "fyne.io/fyne/v2"
    "fyne.io/fyne/v2/container"
    "fyne.io/fyne/v2/widget"
    "StudyPlatform/src/interfaces"
)

type SettingsPage struct {
    router func(interfaces.PageID)
}

func NewSettingsPage() *SettingsPage {
    return &SettingsPage{}
}

func (p *SettingsPage) GetContent() fyne.CanvasObject {
    btn := widget.NewButton("退出设置", func() {
        p.router(interfaces.PageID_MainPage)
    })
    return container.NewCenter(btn)
}

func (p *SettingsPage) GetID() interfaces.PageID {
    return interfaces.PageID_SettingsPage
}

func (p *SettingsPage) SetRouter(fn func(interfaces.PageID)) {
    p.router = fn
}
