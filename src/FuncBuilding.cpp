#include <headers.hpp>

fn MyFrame::bank_square(WXBTNEVT&) -> void {
    lmut vbox = Simple::Init(panel, this);

    Simple::Title("积分银行", panel, vbox);

    Simple::BackButton(&MyFrame::main_func, panel, vbox, this);
}
