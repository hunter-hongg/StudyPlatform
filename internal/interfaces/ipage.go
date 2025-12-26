package interfaces

import "fyne.io/fyne/v2"

type PageID int

const (
    PageID_MainPage PageID = iota
    PageID_OwnPage
	PageID_OwnThingMainPage
	PageID_OwnThingShopPage
	PageID_OwnThingAllPage
	PageID_OwnThingPagePage
	PageID_OwnThingCardsMainPage
	PageID_OwnThingCardsSanGuo1Page
	PageID_OwnThingCardsHan1Page
	PageID_OwnThingYinbiPage
	PageID_OwnThingBaoshiPage
	PageID_OwnThingBaoshiShopPage
	PageID_OwnThingBaoshiChouAllPage
	PageID_OwnThingBaoshiChou1Page
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
	PageID_AncientThingMainPage
	PageID_AncientThingCaiPage
	PageID_AncientThingGuwanPage
	PageID_AncientThingBaowuPage
	PageID_AncientThingShujiPage
	PageID_AncientThingWearPage
	PageID_AncientThingSwordPage
	PageID_AncientThingPaoPage
	PageID_AncientThingBookPage
	PageID_AncientShopMainPage
	PageID_AncientShopSimplePage
	PageID_AncientShopEasyPage
	PageID_AncientShopEasyTongPage
	PageID_AncientShopEasyYinPage
	PageID_AncientShopEasyJinPage
	PageID_AncientShopBaowuPage
	PageID_AncientShopGuwanPage
	PageID_AncientJuanMainPage
	PageID_AncientJuanRealPage
	PageID_AncientSoldMainPage
	PageID_AncientSoldBaowuPage
	PageID_ToolsPage
	PageID_BankMainPage
	PageID_BankCunPage
	PageID_BankGetPage
	PageID_BankJuanMainPage
	PageID_BankJuanRealPage
	PageID_BankJuanGetMainPage
	PageID_BankJuanGetJifenPage
	PageID_ThingSquareMainPage
	PageID_ThingSquareFreeMainPage
	PageID_ThingSquareJinMainPage
	PageID_ThingSquareMangMainPage
	PageID_XianMainPage
	PageID_XianLuMainPage
	PageID_XianSkillMainPage
	PageID_XianFaliMainPage
	PageID_XianFaliDanPage
	PageID_XianThingMainPage
	PageID_XianJiMainPage
	PageID_XianQiMainPage
	PageID_XianQiChangePage
	PageID_XianDanMainPage
	PageID_XianDanShowPage
	PageID_XianDanLianPage
	PageID_XianDanZhaoPage
)

type IPage interface {
    GetContent() fyne.CanvasObject  // 返回界面内容
    GetID() PageID                 // 获取唯一标识
    SetRouter(func(PageID))        // 注入路由函数
}
