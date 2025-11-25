#include "clog.h"
#include "ffi/rust/Rand/RandCpp.hpp"
#include "func/simple.hpp"
#include "headers.hpp"
#include "mine/MyColour.h"
#include "mine/MyFlags.h"
#include "type.hpp"
#include "var.hpp"
#include <boost/format/format_fwd.hpp>
#include <boost/format.hpp>
#include <string>
#include <wx/event.h>
#include <wx/gtk/stattext.h>
#include <wx/sizer.h>
#include <wx/wx.h>

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
void MyFrame::bank_juan_juan(WXBTNEVT&) {
    auto sfs = ShowFmtStr;
    auto ShowString = sfs % "当前存储" % (Bank::BankStore.read_str());
    auto sfs2 = ShowFmtStr;
    auto ShowStringF2 = sfs2 % "捐献券" % (Bank::BankJuanQuan.read_str());

    auto vbox = Simple::Init(panel, this);

    Simple::TitleNoSpacer("捐献积分", panel, vbox);
    auto SButton = Simple::ShowButton(ShowString.str()+"\n"+ShowStringF2.str(), panel, vbox);

    auto Tip1 = new wxStaticText(panel, wxID_ANY, wxT("请输入捐献积分数"));
    Tip1 -> SetFont(font17);
    vbox -> Add(Tip1, FLAG_LEFT);

    auto TextRead = new wxTextCtrl(panel, wxID_ANY, wxT("请输入..."));
    TextRead->SetFont(font17);
    vbox -> Add(TextRead, FLAG_LEFT);

    auto Submit = Simple::BasicButton("捐献", panel);
    Submit -> Bind(wxEVT_BUTTON, [=](WXBTNEVT&) {
        std::string read_raw = TextRead->GetValue().ToStdString();
        int read_real = 0;
        try {
            read_real = std::stoi(read_raw);
        }
        catch(...) {
            read_real = 0;
        }
        if(read_real <= 0 )
        {
            Simple::MessageErr("输入格式错误");
            return;
        }
        if(!Bank::BankStore.canminus(read_real))
        {
            Simple::MessageErr("储蓄积分不足");
            return;
        }
        Simple::Message("捐献成功");
        int get_basic = (read_real / 200) + 1;
        int get_real = get_basic + getrnd(-3, 3);
        if(get_real <= 1 ) get_real = 1;
        Simple::Message("恭喜获得"+ std::to_string(get_real)+"张捐献券");
        Bank::BankJuanQuan.addnum(get_real);
        this -> bank_juan_juan(EmptyEvent);
    });
    vbox -> Add(Submit, FLAG_LEFT);

    Simple::BackButton(&MyFrame::bank_juan, panel, vbox, this);

    CLogger_log(Logfile, CLogger_DEBUG, "积分银行=>捐献积分=>捐献积分: 正常启动");
}

