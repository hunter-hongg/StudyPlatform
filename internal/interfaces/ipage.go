package interfaces

import "fyne.io/fyne/v2"

type PageID int

const (
    PageID_MainPage PageID = iota
    PageID_OwnPage
	PageID_OwnThingMainPage
	PageID_OwnThingAllPage
	PageID_OwnThingPagePage
	PageID_OwnThingCardsMainPage
	PageID_OwnThingCardsSanGuo1Page
	PageID_OwnThingCardsHan1Page
	PageID_LiHePage
	PageID_TimerMainPage
	PageID_TongMainPage
	PageID_TongJifenPage
	PageID_CalcMainPage
	PageID_CalcShopPage
	PageID_CalcStartPage
	PageID_CalcStartAddPage
	PageID_CalcStartTimPage
	PageID_CalcStartDivPage
	PageID_AncientMainPage
)

type IPage interface {
    GetContent() fyne.CanvasObject  // 返回界面内容
    GetID() PageID                 // 获取唯一标识
    SetRouter(func(PageID))        // 注入路由函数
}
