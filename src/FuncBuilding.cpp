#include "func/simple.hpp"
#include "type.hpp"
#include "function.hpp"
#include <wx/sizer.h>

void MyFrame::ancient_shop_bianli(WXBTNEVT&) {
    wxBoxSizer* vbox = Simple::Init(panel, this);

    Simple::Title("便利店铺", panel, vbox);

    Simple::BackButton(&MyFrame::ancient_shopa, panel, vbox, this);
}

