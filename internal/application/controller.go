package application

import (
    "fyne.io/fyne/v2"
    "StudyPlatform/internal/interfaces"
    "StudyPlatform/internal/pages"
)

type AppController struct {
    window    fyne.Window
    pages     map[interfaces.PageID]interfaces.IPage
    currentID interfaces.PageID
}

func NewApp(window fyne.Window) *AppController {
    c := &AppController{
        window: window,
        pages:  make(map[interfaces.PageID]interfaces.IPage),
    }
    
    c.registerPage(pages.NewMainPage())
    c.registerPage(pages.NewOwnPage())
	c.registerPage(pages.NewTimerMainPage())
	c.registerPage(pages.NewTongMainPage())
	c.registerPage(pages.NewTongJifenPage())
	c.registerPage(pages.NewCalcMainPage())
	c.registerPage(pages.NewCalcShopPage())
	c.registerPage(pages.NewAncientMainPage())
	c.registerPage(pages.NewOwnThingMainPage())
	c.registerPage(pages.NewOwnThingAllPage())
	c.registerPage(pages.NewCalcStartPage())
	c.registerPage(pages.NewCalcStartAddPage())
	c.registerPage(pages.NewCalcStartTimPage())
	c.registerPage(pages.NewCalcStartDivPage())
    c.registerPage(pages.NewLiHePage())
    c.registerPage(pages.NewOwnThingPagePage())
    c.registerPage(pages.NewOwnThingCardsMainPage())
    c.registerPage(pages.NewOwnThingCardsSanGuo1Page())
    c.registerPage(pages.NewOwnThingCardsHan1Page())
    c.registerPage(pages.NewOwnThingShopPage())
    c.registerPage(pages.NewOwnThingYinbiPage())
    c.registerPage(pages.NewOwnThingBaoshiPage())
    c.registerPage(pages.NewOwnThingBaoshiShopPage())
    c.registerPage(pages.NewOwnThingBaoshiChouAllPage())
    c.registerPage(pages.NewOwnThingBaoshiChou1Page())
    c.registerPage(pages.NewToolsPage())
    c.registerPage(pages.NewBankMainPage())
    c.registerPage(pages.NewBankCunPage())
    c.registerPage(pages.NewBankGetPage())
    c.registerPage(pages.NewBankJuanMainPage())
    c.registerPage(pages.NewBankJuanRealPage())
    c.registerPage(pages.NewBankJuanGetMainPage())
    c.registerPage(pages.NewBankJuanGetJifenPage())
    c.registerPage(pages.NewThingSquareMainPage())
    c.registerPage(pages.NewThingSquareFreeMainPage())
    c.registerPage(pages.NewThingSquareJinMainPage())
    c.registerPage(pages.NewThingSquareMangMainPage())
    c.registerPage(pages.NewXianMainPage())
    c.registerPage(pages.NewXianLuMainPage())
    c.registerPage(pages.NewXianSkillMainPage())
    c.registerPage(pages.NewXianFaliMainPage())
    c.registerPage(pages.NewXianFaliDanPage())
    c.registerPage(pages.NewXianThingMainPage())
    c.registerPage(pages.NewXianDanMainPage())
    c.registerPage(pages.NewXianDanShowPage())
    c.registerPage(pages.NewXianJiMainPage())
    c.registerPage(pages.NewXianQiMainPage())
    c.registerPage(pages.NewXianQiChangePage())
    c.registerPage(pages.NewXianDanLianPage())
    c.registerPage(pages.NewXianDanZhaoPage())
    c.registerPage(pages.NewAncientThingMainPage())
    c.registerPage(pages.NewAncientThingCaiPage())
    c.registerPage(pages.NewAncientThingGuwanPage())
    c.registerPage(pages.NewAncientThingBaowuPage())
    c.registerPage(pages.NewAncientThingBookPage())
    c.registerPage(pages.NewAncientThingWearPage())
    c.registerPage(pages.NewAncientThingSwordPage())
    c.registerPage(pages.NewAncientThingPaoPage())
    c.registerPage(pages.NewAncientShopMainPage())
    c.registerPage(pages.NewAncientShopSimplePage())
    c.registerPage(pages.NewAncientShopEasyPage())
    c.registerPage(pages.NewAncientShopEasyYinPage())
    c.registerPage(pages.NewAncientShopEasyJinPage())
    c.registerPage(pages.NewAncientShopEasyTongPage())
    c.registerPage(pages.NewAncientShopBaowuPage())
    c.registerPage(pages.NewAncientShopGuwanPage())
    c.registerPage(pages.NewAncientJuanMainPage())
    c.registerPage(pages.NewAncientJuanRealPage())
    c.registerPage(pages.NewAncientSoldMainPage())
    c.registerPage(pages.NewAncientSoldBaowuPage())
    c.registerPage(pages.NewAncientGuanMainPage())
    c.registerPage(pages.NewAncientGuanWenMainPage())
    
    return c
}

func (c *AppController) registerPage(page interfaces.IPage) {
    page.SetRouter(c.SwitchPage)
    c.pages[page.GetID()] = page
}

func (c *AppController) SwitchPage(id interfaces.PageID) {
    if page, exists := c.pages[id]; exists {
        c.window.SetContent(page.GetContent())
        c.currentID = id
    }
}
