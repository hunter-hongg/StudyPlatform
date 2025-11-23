#include "func/simple.hpp"
#include "headers.hpp"
#include "mine/MyColour.h"
#include "type.hpp"
#include "var.hpp"
#include <boost/format/format_fwd.hpp>
#include <boost/format.hpp>
#include <wx/sizer.h>

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

    auto vbox = Simple::Init(panel, this);

    Simple::TitleNoSpacer("捐献积分", panel, vbox);
    Simple::ShowButton(/* ShowString % (Bank::BankJuanQuan.read_int()) */"", panel, vbox);

    Simple::BackButton(&MyFrame::bank_square, panel, vbox, this);

    CLogger_log(Logfile, CLogger_DEBUG, "积分银行=>捐献积分: 正常启动");
}
