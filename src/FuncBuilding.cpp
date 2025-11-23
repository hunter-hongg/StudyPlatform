#include "clog.h"
#include "func/simple.hpp"
#include "headers.hpp"
#include "mine/MyColour.h"
#include "type.hpp"
#include "var.hpp"
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
void MyFrame::ancient_shop_bianli_book(WXBTNEVT&) {
    wxBoxSizer* vbox = Simple::Init(panel, this);

    Simple::Title("书籍便利店铺", panel, vbox);

    wxGridSizer* grid = new wxGridSizer(3, 1, 4, 4);

    auto btn1 = Simple::ShopButton("购买普通书籍", panel, MyOrange);
    btn1 -> Bind(wxEVT_BUTTON, &MyFrame::ancient_shop_bianli_book_simple, this);
    grid -> Add(btn1, FLAG_CENTER);

    auto btn2 = Simple::ShopButton("购买珍贵书籍", panel, MyOrange);
    btn2 -> Bind(wxEVT_BUTTON, &MyFrame::ancient_shop_bianli_book_zhengui, this);
    grid -> Add(btn2, FLAG_CENTER);

    // auto btn2 = Simple::ShopButton("兑换黄金", panel, MyOrange);
    // btn2 -> Bind(wxEVT_BUTTON, &MyFrame::ancient_shop_bianli_huangjin, this);
    // grid -> Add(btn2, FLAG_CENTER);
    //
    // auto btn3 = Simple::ShopButton("兑换铜钱", panel, MyOrange);
    // btn3 -> Bind(wxEVT_BUTTON, &MyFrame::ancient_shop_bianli_tongbi, this);
    // grid -> Add(btn3, FLAG_CENTER);

    vbox -> Add(grid, FLAG_CENTER);

    Simple::BackButton(&MyFrame::ancient_shop_bianli_all, panel, vbox, this);
}
void MyFrame::ancient_shop_bianli_book_zhengui(WXBTNEVT&) {
    CLogger_log(Logfile, CLogger_DEBUG, "便利商店=>书籍商店=>珍贵书籍: 正常启动");

    wxBoxSizer* vbox = Simple::Init(panel, this);

    Simple::Title("购买珍贵书籍", panel, vbox);

    auto label = new wxStaticText(panel, wxID_ANY, wxT("请输入需要购买多少珍贵书籍"));
    label->SetFont(font17);
    vbox -> Add(label, FLAG_LEFT);

    auto ReadTo = new wxTextCtrl(panel, wxID_ANY, wxT("请输入..."));
    ReadTo -> SetFont(font15);
    vbox -> Add(ReadTo, FLAG_LEFT);

    auto Submit = new wxButton(panel, wxID_ANY, wxT("购买"));
    Submit -> SetFont(font17);
    Submit -> Bind(wxEVT_BUTTON, [=](WXBTNEVT&) {
        std::string ans = (ReadTo -> GetValue()).ToStdString();
        int t = -1;
        try {
            t = std::stoi(ans);
        } catch(...) {
            t = -1;
        }
        if(t <= 0) {
            Simple::MessageErr("输入格式错误");
            CLogger_log(Logfile, CLogger_WARNING, "便利商店=>书籍商店=>珍贵书籍: 输入格式错误");
            return;
        }
        int need = t*25;
        if(!AncientVar::BaiYinReader.canminus(need)) {
            Simple::Message("白银不足");
            return;
        } else {
            BookShelfFiles_WriteLevel2(BookShelf::Reader, t);
            Simple::Message("购买成功");
            CLogger_log(Logfile, CLogger_DEBUG, "便利商店=>书籍商店=>珍贵书籍: 购买成功");
        }
    });
    vbox -> Add(Submit, FLAG_LEFT);

    Simple::BackButton(&MyFrame::ancient_shop_bianli_book, panel, vbox, this);
}
