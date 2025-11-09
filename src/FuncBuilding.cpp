#include "headers.hpp"
#include <wx/event.h>

void MyFrame::ancient_shop_bianli(WXBTNEVT&) {
    wxBoxSizer* vbox = Simple::Init(panel, this);

    Simple::Title("便利店铺", panel, vbox);

    wxGridSizer* grid = new wxGridSizer(3, 3, 4, 4);

    auto btn1 = Simple::ShopButton("兑换白银", panel, MyOrange);
    btn1 -> Bind(wxEVT_BUTTON, &MyFrame::ancient_shop_bianli_baiyin, this);
    grid -> Add(btn1, FLAG_CENTER);

    vbox -> Add(grid, FLAG_CENTER);

    Simple::BackButton(&MyFrame::ancient_shopa, panel, vbox, this);
}
void MyFrame::ancient_shop_bianli_baiyin(WXBTNEVT&) {
    wxBoxSizer* vbox = Simple::Init(panel, this);

    Simple::Title("兑换白银", panel, vbox);

    Simple::BackButton(&MyFrame::ancient_shop_bianli, panel, vbox, this);
}

