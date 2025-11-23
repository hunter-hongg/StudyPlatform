#include "func/simple.hpp"
#include <headers.hpp>

auto MyFrame::tongy_show(WXBTNEVT&) -> void {
    Simple::Message(
        "通用货币兑换规则: \n"
        "1000积分 1通用货币\n"
    );
}
auto MyFrame::bank_square(WXBTNEVT&) -> void {
    auto vbox = Simple::Init(panel, this);

    Simple::TitleNoSpacer("积分银行", panel, vbox);
    Simple::ShowButton("已存积分: "+Bank::BankStore.Read(), panel, vbox);

    Simple::Button(&MyFrame::bank_store, "存储积分", panel, vbox, this);
    Simple::Button(&MyFrame::bank_get, "领取积分", panel, vbox, this);
    Simple::Button(&MyFrame::bank_juan, "捐献积分", panel, vbox, this);

    Simple::BackButton(&MyFrame::main_func, panel, vbox, this);
}
auto MyFrame::tongy_all(WXBTNEVT&) -> void {
    auto vbox = Simple::Init(panel, this);

    Simple::TitleNoSpacer("通用货币", panel, vbox);
    Simple::ShowButton("通用货币: "+TongYongReal::Reader.read_str(),
                       panel, vbox);

    Simple::Button(&MyFrame::tongy, "积分兑换", panel, vbox, this);
    Simple::Button(&MyFrame::tongy_show, "兑换规则", panel, vbox, this);

    Simple::BackButton(&MyFrame::mine, panel, vbox, this);
}
