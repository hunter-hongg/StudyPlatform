#include "func/simple.hpp"
#include "headers.hpp"
#include "var.hpp"

void MyFrame::ancient_shop_bianli(WXBTNEVT&) {
    wxBoxSizer* vbox = Simple::Init(panel, this);

    Simple::Title("便利店铺", panel, vbox);

    wxGridSizer* grid = new wxGridSizer(3, 3, 4, 4);

    auto btn1 = Simple::ShopButton("兑换白银", panel, MyOrange);
    btn1 -> Bind(wxEVT_BUTTON, &MyFrame::ancient_shop_bianli_baiyin, this);
    grid -> Add(btn1, FLAG_CENTER);

    auto btn2 = Simple::ShopButton("兑换黄金", panel, MyOrange);
    btn2 -> Bind(wxEVT_BUTTON, &MyFrame::ancient_shop_bianli_huangjin, this);
    grid -> Add(btn2, FLAG_CENTER);

    auto btn3 = Simple::ShopButton("兑换铜钱", panel, MyOrange);
    btn3 -> Bind(wxEVT_BUTTON, &MyFrame::ancient_shop_bianli_tongbi, this);
    grid -> Add(btn3, FLAG_CENTER);

    vbox -> Add(grid, FLAG_CENTER);

    Simple::BackButton(&MyFrame::ancient_shopa, panel, vbox, this);
}
void MyFrame::ancient_shop_bianli_tongbi(WXBTNEVT&) {
    wxBoxSizer* vbox = Simple::Init(panel, this);

    Simple::Title("兑换铜钱", panel, vbox);

    auto label = new wxStaticText(panel, wxID_ANY, wxT("请输入需要兑换多少铜钱"));
    label->SetFont(font17);
    vbox -> Add(label, FLAG_LEFT);

    auto ReadTo = new wxTextCtrl(panel, wxID_ANY, wxT("请输入..."));
    ReadTo -> SetFont(font15);
    vbox -> Add(ReadTo, FLAG_LEFT);

    auto Submit = new wxButton(panel, wxID_ANY, wxT("兑换"));
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
            return;
        }
        if(t % 100 != 0) {
            Simple::MessageErr("铜钱需要以100个为单位");
            return;
        }
        int need = t/100;
        if(!AncientVar::HuangJinReader.canminus(need)) {
            Simple::Message("黄金不足");
            return;
        } else {
            AncientVar::TongBiReader.addnum(t);
            Simple::Message("兑换成功");
        }
    });
    vbox -> Add(Submit, FLAG_LEFT);

    Simple::BackButton(&MyFrame::ancient_shop_bianli, panel, vbox, this);
}

