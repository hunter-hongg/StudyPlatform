#include "func/simple.hpp"
#include "headers.hpp"
#include "type.hpp"

void MyFrame::ancient_bookstore(WXBTNEVT&) {
    auto vbox = Simple::Init(panel, this);

    Simple::Title("卖出书籍", panel, vbox);

    Simple::BackButton(&MyFrame::ancient_square, panel, vbox, this);
}
