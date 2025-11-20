#include "clog.h"
#include "func/simple.hpp"
#include "headers.hpp"
#include "mine/MyColour.h"
#include "type.hpp"
#include <wx/sizer.h>

void MyFrame::ancient_shop_bianli_all(WXBTNEVT&) {
    wxBoxSizer* vbox = Simple::Init(panel, this);

    Simple::Title("便利店铺", panel, vbox);

    auto btn1 = Simple::Button(&MyFrame::ancient_shop_bianli, "货币便利店铺", panel, vbox, this);
    btn1 -> SetForegroundColour(MyDarkRed);

    auto btn2 = Simple::Button(&MyFrame::ancient_shop_bianli_book, "书籍便利店铺", panel, vbox, this);
    btn2 -> SetForegroundColour(MyDarkRed);

    Simple::BackButton(&MyFrame::ancient_shopa, panel, vbox, this);

    CLogger_log(Logfile, CLogger_DEBUG, "便利店铺=>总界面: 正常启动");
}
void MyFrame::ancient_shop_bianli_book(WXBTNEVT&) {
    wxBoxSizer* vbox = Simple::Init(panel, this);

    Simple::Title("书籍便利店铺", panel, vbox);

    wxGridSizer* grid = new wxGridSizer(3, 1, 4, 4);

    auto btn1 = Simple::ShopButton("兑换书籍", panel, MyOrange);
    btn1 -> Bind(wxEVT_BUTTON, &MyFrame::ancient_shop_bianli_baiyin, this);
    grid -> Add(btn1, FLAG_CENTER);

    // auto btn2 = Simple::ShopButton("兑换黄金", panel, MyOrange);
    // btn2 -> Bind(wxEVT_BUTTON, &MyFrame::ancient_shop_bianli_huangjin, this);
    // grid -> Add(btn2, FLAG_CENTER);
    //
    // auto btn3 = Simple::ShopButton("兑换铜钱", panel, MyOrange);
    // btn3 -> Bind(wxEVT_BUTTON, &MyFrame::ancient_shop_bianli_tongbi, this);
    // grid -> Add(btn3, FLAG_CENTER);

    vbox -> Add(grid, FLAG_CENTER);

    Simple::BackButton(&MyFrame::ancient_shop_bianli_all, panel, vbox, this);

}
