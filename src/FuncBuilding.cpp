#include "func/simple.hpp"
#include "headers.hpp"
#include "type.hpp"
#include <wx/sizer.h>

void MyFrame::ancient_shop_bianli(WXBTNEVT&) {
    wxBoxSizer* vbox = Simple::Init(panel, this);

    Simple::Title("货币便利店铺", panel, vbox);

    wxGridSizer* grid = new wxGridSizer(3, 3, 4, 4);

    auto btn1 = Simple::ShopButton("兑换白银", panel, MyOrange);
    btn1 -> Bind(wxEVT_BUTTON, &MyFrame::ancient_shop_bianli_baiyin, this);
    grid -> Add(btn1, FLAG_CENTER);

    auto btn2 = Simple::ShopButton("兑换黄金", panel, MyOrange);
    btn2 -> Bind(wxEVT_BUTTON, &MyFrame::ancient_shop_bianli_huangjin, this);
    grid -> Add(btn2, FLAG_CENTER);

    auto btn3 = Simple::ShopButton("兑换铜钱", panel, MyOrange);
    btn3 -> Bind(wxEVT_BUTTON, &MyFrame::ancient_shop_bianli_tongbi, this);
    grid -> Add(btn3, FLAG_CENTER);

    vbox -> Add(grid, FLAG_CENTER);

    Simple::BackButton(&MyFrame::ancient_shop_bianli_all, panel, vbox, this);
}
void MyFrame::ancient_shop_bianli_all(WXBTNEVT&) {
    wxBoxSizer* vbox = Simple::Init(panel, this);

    Simple::Title("便利店铺", panel, vbox);

    auto btn1 = Simple::Button(&MyFrame::ancient_shop_bianli, "货币便利店铺", wxPanel *panel, wxBoxSizer *vbox, T *self)
}
