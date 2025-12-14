package interfaces

import "fyne.io/fyne/v2"

type PageID int

const (
    PageID_MainPage PageID = iota
    PageID_OwnPage
	PageID_TimerMainPage
	PageID_TongMainPage
)

type IPage interface {
    GetContent() fyne.CanvasObject  // 返回界面内容
    GetID() PageID                 // 获取唯一标识
    SetRouter(func(PageID))        // 注入路由函数
}
