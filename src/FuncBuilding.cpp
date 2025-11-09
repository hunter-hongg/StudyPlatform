#include "func/simple.hpp"
#include "type.hpp"
#include "function.hpp"

void MyFrame::ancient_shop_bianli(WXBTNEVT&) {
    auto vbox = Simple::Init(panel, this);

    Simple::Title("便利店铺", panel, vbox);

    Simple::BackButton(&MyFrame::ancient_shopa, panel, vbox, this);
}
