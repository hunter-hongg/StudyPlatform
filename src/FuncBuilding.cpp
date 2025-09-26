#include <headers.hpp>

void MyFrame::bank_square(WXBTNEVT&) {
    auto vbox = Simple::Init(panel, this);

    Simple::Title("积分银行", panel, vbox);

    Simple::BackButton(&MyFrame::main_func, panel, vbox, this);
}
