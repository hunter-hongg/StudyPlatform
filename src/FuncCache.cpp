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
    Simple::ShowButton("已存积分: "+Bank::BankStore.read_str(), panel, vbox);

    Simple::Button(&MyFrame::bank_store, "存储积分", panel, vbox, this);
    Simple::Button(&MyFrame::bank_get, "领取积分", panel, vbox, this);
    Simple::Button(&MyFrame::bank_juan, "积分捐献", panel, vbox, this);

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
void MyFrame::ancient_shop_bianli_all(WXBTNEVT&) {
    wxBoxSizer* vbox = Simple::Init(panel, this);

    Simple::Title("便利店铺", panel, vbox);

    auto btn1 = Simple::Button(&MyFrame::ancient_shop_bianli, "货币便利店铺", panel, vbox, this);
    btn1 -> SetForegroundColour(MyDarkRed);

    auto btn2 = Simple::Button(&MyFrame::ancient_shop_bianli_book, "书籍便利店铺", panel, vbox, this);
    btn2 -> SetForegroundColour(MyDarkRed);

    Simple::BackButton(&MyFrame::ancient_shopa, panel, vbox, this);

    CLogger_log(Logfile, CLogger_DEBUG, "便利店铺=>总界面: 正常启动");
}
void MyFrame::bank_juan(WXBTNEVT&) {
    auto ShowString = boost::format("捐献券: %d");
    auto ShowStringF = (ShowString % (Bank::BankJuanQuan.read_int()));

    auto vbox = Simple::Init(panel, this);

    Simple::TitleNoSpacer("积分捐献", panel, vbox);
    Simple::ShowButton(ShowStringF.str(), panel, vbox);

    Simple::Button(&MyFrame::bank_juan_juan, "捐献积分", panel, vbox, this);

    Simple::BackButton(&MyFrame::bank_square, panel, vbox, this);

    CLogger_log(Logfile, CLogger_DEBUG, "积分银行=>捐献积分: 正常启动");
}
