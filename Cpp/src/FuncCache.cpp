#include "func/simple.hpp"
#include "signals.hpp"
#include "type.hpp"
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
    Simple::Button(&MyFrame::bank_juan_use, "领取奖励", panel, vbox, this);

    Simple::BackButton(&MyFrame::bank_square, panel, vbox, this);

    CLogger_log(Logfile, CLogger_DEBUG, "积分银行=>捐献积分: 正常启动");
}
void MyFrame::ancient_bookstore(WXBTNEVT&) {
    auto vbox = Simple::Init(panel, this);

    Simple::Title("书籍使用", panel, vbox);

    auto btn1 = Simple::Button("叫卖书籍",panel, vbox);
    btn1 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT&) {
        GlobalSignal.AncientBookstoreJiaomai.emit();
    });

    auto btn2 = Simple::Button("抄录新书", panel, vbox);
    btn2 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT&) {
        GlobalSignal.AncientBookstoreChaoLuAll.emit();
    });

    Simple::BackButton(&MyFrame::ancient_square, panel, vbox, this);
}
void MyFrame::bank_juan_use(WXBTNEVT&) {
    auto sfs = ShowFmt;
    auto sfsa = sfs % "捐献券" % Bank::BankJuanQuan.read_int();

    auto vbox = Simple::Init(panel, this);

    Simple::TitleNoSpacer("领取奖励", panel, vbox);
    Simple::ShowButton(sfsa.str(), panel, vbox);

    auto btn1 = Simple::Button("积分奖励", panel, vbox);
    btn1 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT&) {
        GlobalSignal.BankJuanUseJiFen.emit();
    });

    Simple::BackButton(&MyFrame::bank_juan, panel, vbox, this);
}
void MyFrame::ancient_bookstore_chaolu(WXBTNEVT&) {
    auto vbox = Simple::Init(panel, this);

    Simple::Title("抄录书籍", panel, vbox);
    // Simple::ShowButton("", panel, vbox);

    Simple::Button(&MyFrame::ancient_bookstore_chaolu_start, "开始抄录", panel, vbox, this);

    Simple::BackButton(&MyFrame::ancient_bookstore, panel, vbox, this);
}
void MyFrame::ancient_bookstore_chaolu_start(WXBTNEVT&) {
    auto vbox = Simple::Init(panel, this);

    Simple::Title("开始抄录", panel, vbox);

    Simple::BackButton(&MyFrame::ancient_bookstore_chaolu, panel, vbox, this);
}

