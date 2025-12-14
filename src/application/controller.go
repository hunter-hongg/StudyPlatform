package application

import (
    "fyne.io/fyne/v2"
    "StudyPlatform/src/interfaces"
    "StudyPlatform/src/pages"
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
