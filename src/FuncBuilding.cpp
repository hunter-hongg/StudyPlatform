#include <headers.hpp>

fn MyFrame::bank_square(WXBTNEVT&) -> void {
    lmut vbox = Simple::Init(panel, this);

    Simple::TitleNoSpacer("积分银行", panel, vbox);
    Simple::ShowButton("已存积分: "+Bank::BankStore.Read(), panel, vbox);

    Simple::Button(&MyFrame::bank_store, "存储积分", panel, vbox, this);
    Simple::Button(&MyFrame::bank_get, "领取积分", panel, vbox, this);

    Simple::BackButton(&MyFrame::main_func, panel, vbox, this);
}
fn MyFrame::tongy_all(WXBTNEVT&) -> void {
    lmut vbox = Simple::Init(panel, this);

    Simple::TitleNoSpacer("通用货币", panel, vbox);
    Simple::ShowButton("通用货币: "+TongYongReal::Reader.read_str(), 
                       panel, vbox);

    Simple::Button(&MyFrame::tongy, "积分兑换", panel, vbox, this);

    Simple::BackButton(&MyFrame::mine, panel, vbox, this);
}
fn MyFrame::tongy_show(WXBTNEVT&) -> void {
    Simple::Message(
        "通用货币兑换规则: \n"
        "1000积分 1通用货币\n"
    );
}

