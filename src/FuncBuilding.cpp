#include "headers.hpp"

void MyFrame::ancient_shop_bianli(WXBTNEVT&) {
    wxBoxSizer* vbox = Simple::Init(panel, this);

    Simple::Title("便利店铺", panel, vbox);

    wxGridSizer* grid = new wxGridSizer(3, 3, 4, 4);

    vbox -> Add(grid);

    Simple::BackButton(&MyFrame::ancient_shopa, panel, vbox, this);
}
void MyFrame::ancient_shop_bianli_baiyin(WXBTNEVT&) {
    wxBoxSizer* vbox = Simple::Init(panel, this);

    Simple::Title("兑换白银", panel, vbox);

    Simple::BackButton(&MyFrame::ancient_shop_bianli_baiyin, panel, vbox, this);
}

