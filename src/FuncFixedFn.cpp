#include <headers.hpp>

void MyFrame::ancient_wubingli_get(WXBTNEVT&)
{
    auto vbox = Simple::Init(panel, this);

    Simple::Title("具体兵力查看", panel, vbox);

    auto grid = new wxGridSizer(3,3,4,4);

    std::vector<PasswordFile> v({
        AncientVar::WuGuan::BingLi::Xin,
        AncientVar::WuGuan::BingLi::PuTong,
        AncientVar::WuGuan::BingLi::ChuJi,
        AncientVar::WuGuan::BingLi::ZhongJi,
        AncientVar::WuGuan::BingLi::GaoJi,
        AncientVar::WuGuan::BingLi::JingRui,
        AncientVar::WuGuan::BingLi::WangPai,
        AncientVar::WuGuan::BingLi::ShenJi,
    });
    std::vector<std::string> vt({
        "新兵兵力: ",
        "普通兵兵力: ",
        "初级兵兵力: ",
        "中级兵兵力: ",
        "高级兵兵力: ",
        "精锐兵兵力: ",
        "王牌兵兵力: ",
        "神级兵兵力: ",
    });
    int vti = 0;

    for(auto& i: v) {
        auto btn = new wxButton(panel, wxID_ANY, wxString::FromUTF8(vt[vti]+i.read_str()));
        btn -> SetForegroundColour(MyOrange);
        btn -> SetFont(font17);
        grid -> Add(btn, FLAG_CENTER);
        vti++;
    }

    vbox -> Add(grid, FLAG_CENTER);

    Simple::BackButton(&MyFrame::ancient_wuguan_bingli, panel, vbox, this);
}
void MyFrame::ancient_wubingli_plus(WXBTNEVT& evt)
{
    auto vbox = Simple::Init(panel, this);

    Simple::Title("增强兵力", panel, vbox);

    auto grid = new wxGridSizer(3,3,4,4);

    auto btn1 = Simple::ShopButton(
                    "新兵兵力 "+AncientVar::WuGuan::BingLi::Xin.read_str(),
                    panel, MyRed
                );
    btn1 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT&) {
        int need = lambda::anc_wu_bingp_need(
                       AncientVar::WuGuan::BingLi::Xin.read_int(),
                       AncientVar::WuGuan::BingLi::XinMin
                   );
        if ( wxMessageBox(
                    wxString::FromUTF8(std::string("需要黄金")+TOSTR(need)+"两"),
                    "info", wxYES_NO | wxICON_QUESTION
                ) == wxYES ) {
            if ( ! AncientVar::HuangJinReader.canminus(need) ) {
                Simple::Message("黄金不足");
                return;
            }
            AncientVar::WuGuan::BingLi::Xin.addnum(5);
            Simple::Message("增强兵力成功");
            this -> ancient_wubingli_plus(EmptyEvent);
        }
    });
    grid -> Add(btn1, FLAG_CENTER);

    auto btn2 = Simple::ShopButton(
                    "普通兵兵力 "+AncientVar::WuGuan::BingLi::PuTong.read_str(),
                    panel, MyRed
                );
    btn2 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT&) {
        int need = lambda::anc_wu_bingp_need(
                       AncientVar::WuGuan::BingLi::PuTong.read_int(),
                       AncientVar::WuGuan::BingLi::PuTongMin
                   );
        if ( wxMessageBox(
                    wxString::FromUTF8(std::string("需要黄金")+TOSTR(need)+"两"),
                    "info", wxYES_NO | wxICON_QUESTION
                ) == wxYES ) {
            if ( ! AncientVar::HuangJinReader.canminus(need) ) {
                Simple::Message("黄金不足");
                return;
            }
            AncientVar::WuGuan::BingLi::PuTong.addnum(5);
            Simple::Message("增强兵力成功");
            this -> ancient_wubingli_plus(EmptyEvent);
        }
    });
    grid -> Add(btn2, FLAG_CENTER);

    auto btn3 = Simple::ShopButton(
                    "初级兵兵力 "+AncientVar::WuGuan::BingLi::ChuJi.read_str(),
                    panel, MyRed
                );
    btn3 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT&) {
        int need = lambda::anc_wu_bingp_need(
                       AncientVar::WuGuan::BingLi::ChuJi.read_int(),
                       AncientVar::WuGuan::BingLi::ChuJiMin
                   );
        if ( wxMessageBox(
                    wxString::FromUTF8(std::string("需要黄金")+TOSTR(need)+"两"),
                    "info", wxYES_NO | wxICON_QUESTION
                ) == wxYES ) {
            if ( ! AncientVar::HuangJinReader.canminus(need) ) {
                Simple::Message("黄金不足");
                return;
            }
            AncientVar::WuGuan::BingLi::ChuJi.addnum(5);
            Simple::Message("增强兵力成功");
            this -> ancient_wubingli_plus(EmptyEvent);
        }
    });
    grid -> Add(btn3, FLAG_CENTER);

    auto btn4 = Simple::ShopButton(
                    "中级兵兵力 "+AncientVar::WuGuan::BingLi::ZhongJi.read_str(),
                    panel, MyRed
                );
    btn4 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT&) {
        int need = lambda::anc_wu_bingp_need(
                       AncientVar::WuGuan::BingLi::ZhongJi.read_int(),
                       AncientVar::WuGuan::BingLi::ZhongJiMin
                   );
        if ( wxMessageBox(
                    wxString::FromUTF8(std::string("需要黄金")+TOSTR(need)+"两"),
                    "info", wxYES_NO | wxICON_QUESTION
                ) == wxYES ) {
            if ( ! AncientVar::HuangJinReader.canminus(need) ) {
                Simple::Message("黄金不足");
                return;
            }
            AncientVar::WuGuan::BingLi::ZhongJi.addnum(5);
            Simple::Message("增强兵力成功");
            this -> ancient_wubingli_plus(EmptyEvent);
        }
    });
    grid -> Add(btn4, FLAG_CENTER);

    auto btn5 = Simple::ShopButton(
                    "高级兵兵力 "+AncientVar::WuGuan::BingLi::GaoJi.read_str(),
                    panel, MyRed
                );
    btn5 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT&) {
        int need = lambda::anc_wu_bingp_need(
                       AncientVar::WuGuan::BingLi::GaoJi.read_int(),
                       AncientVar::WuGuan::BingLi::GaoJiMin
                   );
        if ( wxMessageBox(
                    wxString::FromUTF8(std::string("需要黄金")+TOSTR(need)+"两"),
                    "info", wxYES_NO | wxICON_QUESTION
                ) == wxYES ) {
            if ( ! AncientVar::HuangJinReader.canminus(need) ) {
                Simple::Message("黄金不足");
                return;
            }
            AncientVar::WuGuan::BingLi::GaoJi.addnum(5);
            Simple::Message("增强兵力成功");
            this -> ancient_wubingli_plus(EmptyEvent);
        }
    });
    grid -> Add(btn5, FLAG_CENTER);

    auto btn6 = Simple::ShopButton(
                    "精锐兵兵力 "+AncientVar::WuGuan::BingLi::JingRui.read_str(),
                    panel, MyRed
                );
    btn6 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT&) {
        int need = lambda::anc_wu_bingp_need(
                       AncientVar::WuGuan::BingLi::JingRui.read_int(),
                       AncientVar::WuGuan::BingLi::JingRuiMin
                   );
        if ( wxMessageBox(
                    wxString::FromUTF8(std::string("需要黄金")+TOSTR(need)+"两"),
                    "info", wxYES_NO | wxICON_QUESTION
                ) == wxYES ) {
            if ( ! AncientVar::HuangJinReader.canminus(need) ) {
                Simple::Message("黄金不足");
                return;
            }
            AncientVar::WuGuan::BingLi::JingRui.addnum(5);
            Simple::Message("增强兵力成功");
            this -> ancient_wubingli_plus(EmptyEvent);
        }
    });
    grid -> Add(btn6, FLAG_CENTER);

    auto btn7 = Simple::ShopButton(
                    "王牌兵兵力 "+AncientVar::WuGuan::BingLi::WangPai.read_str(),
                    panel, MyRed
                );
    btn7 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT&) {
        int need = lambda::anc_wu_bingp_need(
                       AncientVar::WuGuan::BingLi::WangPai.read_int(),
                       AncientVar::WuGuan::BingLi::WangPaiMin
                   );
        if ( wxMessageBox(
                    wxString::FromUTF8(std::string("需要黄金")+TOSTR(need)+"两"),
                    "info", wxYES_NO | wxICON_QUESTION
                ) == wxYES ) {
            if ( ! AncientVar::HuangJinReader.canminus(need) ) {
                Simple::Message("黄金不足");
                return;
            }
            AncientVar::WuGuan::BingLi::WangPai.addnum(5);
            Simple::Message("增强兵力成功");
            this -> ancient_wubingli_plus(EmptyEvent);
        }
    });
    grid -> Add(btn7, FLAG_CENTER);

    auto btn8 = Simple::ShopButton(
                    "神级兵兵力 "+AncientVar::WuGuan::BingLi::ShenJi.read_str(),
                    panel, MyRed
                );
    btn8 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT&) {
        int need = lambda::anc_wu_bingp_need(
                       AncientVar::WuGuan::BingLi::ShenJi.read_int(),
                       AncientVar::WuGuan::BingLi::ShenJiMin
                   );
        if ( wxMessageBox(
                    wxString::FromUTF8(std::string("需要黄金")+TOSTR(need)+"两"),
                    "info", wxYES_NO | wxICON_QUESTION
                ) == wxYES ) {
            if ( ! AncientVar::HuangJinReader.canminus(need) ) {
                Simple::Message("黄金不足");
                return;
            }
            AncientVar::WuGuan::BingLi::ShenJi.addnum(5);
            Simple::Message("增强兵力成功");
            this -> ancient_wubingli_plus(EmptyEvent);
        }
    });
    grid -> Add(btn8, FLAG_CENTER);

    vbox -> Add(grid, FLAG_CENTER);

    Simple::BackButton(&MyFrame::ancient_wuguan_1, panel, vbox, this);
}
void MyFrame::CallBack1(WXBTNEVT&) {
    Simple::Message("临阵脱逃，绝不可行！\n死战到底，宁死不屈！");
}
void MyFrame::ancient_shop_bianli_baiyin(WXBTNEVT&) {
    wxBoxSizer* vbox = Simple::Init(panel, this);

    Simple::Title("兑换白银", panel, vbox);

    auto label = new wxStaticText(panel, wxID_ANY, wxT("请输入需要兑换多少白银"));
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
        int need = t*10;
        if(!AncientVar::TongBiReader.canminus(need)) {
            Simple::Message("铜钱不足");
            return;
        } else {
            AncientVar::BaiYinReader.addnum(t);
            Simple::Message("兑换成功");
        }
    });
    vbox -> Add(Submit, FLAG_LEFT);

    Simple::BackButton(&MyFrame::ancient_shop_bianli, panel, vbox, this);
}
void MyFrame::ancient_shop_bianli_huangjin(WXBTNEVT&) {
    wxBoxSizer* vbox = Simple::Init(panel, this);

    Simple::Title("兑换黄金", panel, vbox);

    auto label = new wxStaticText(panel, wxID_ANY, wxT("请输入需要兑换多少黄金"));
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
        int need = t*10;
        if(!AncientVar::BaiYinReader.canminus(need)) {
            Simple::Message("白银不足");
            return;
        } else {
            AncientVar::HuangJinReader.addnum(t);
            Simple::Message("兑换成功");
        }
    });
    vbox -> Add(Submit, FLAG_LEFT);

    Simple::BackButton(&MyFrame::ancient_shop_bianli, panel, vbox, this);
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
void MyFrame::ancient_shop_bianli(WXBTNEVT&) {
    wxBoxSizer* vbox = Simple::Init(panel, this);

    Simple::Title("货币便利店铺", panel, vbox);

    wxGridSizer* grid = new wxGridSizer(3, 1, 4, 4);

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

    Simple::BackButton(&MyFrame::ancient_shop_bianli_all, panel, vbox, this);
}
void MyFrame::ancient_shop_bianli_book_simple(WXBTNEVT&) {
    CLogger_log(Logfile, CLogger_DEBUG, "便利商店=>书籍商店=>普通书籍: 正常启动");

    wxBoxSizer* vbox = Simple::Init(panel, this);

    Simple::Title("购买普通书籍", panel, vbox);

    auto label = new wxStaticText(panel, wxID_ANY, wxT("请输入需要购买多少普通书籍"));
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
            CLogger_log(Logfile, CLogger_WARNING, "便利商店=>书籍商店=>普通书籍: 输入格式错误");
            return;
        }
        int need = t*10;
        if(!AncientVar::BaiYinReader.canminus(need)) {
            Simple::Message("白银不足");
            return;
        } else {
            BookShelfFiles_WriteLevel1(BookShelf::Reader, t);
            Simple::Message("购买成功");
        }
    });
    vbox -> Add(Submit, FLAG_LEFT);

    Simple::BackButton(&MyFrame::ancient_shop_bianli_book, panel, vbox, this);
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

    auto btn3 = Simple::ShopButton("购买典藏书籍", panel, MyOrange);
    btn3 -> Bind(wxEVT_BUTTON, &MyFrame::ancient_shop_bianli_book_diancang, this);
    grid -> Add(btn3, FLAG_CENTER);

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
void MyFrame::ancient_shop_bianli_book_diancang(WXBTNEVT&) {
    CLogger_log(Logfile, CLogger_DEBUG, "便利商店=>书籍商店=>典藏书籍: 正常启动");

    wxBoxSizer* vbox = Simple::Init(panel, this);

    Simple::Title("购买典藏书籍", panel, vbox);

    auto label = new wxStaticText(panel, wxID_ANY, wxT("请输入需要购买多少典藏书籍"));
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
            CLogger_log(Logfile, CLogger_WARNING, "便利商店=>书籍商店=>典藏书籍: 输入格式错误");
            return;
        }
        int need = t*50;
        if(!AncientVar::BaiYinReader.canminus(need)) {
            Simple::Message("白银不足");
            return;
        } else {
            BookShelfFiles_WriteLevel3(BookShelf::Reader, t);
            Simple::Message("购买成功");
            CLogger_log(Logfile, CLogger_DEBUG, "便利商店=>书籍商店=>典藏书籍: 购买成功");
        }
    });
    vbox -> Add(Submit, FLAG_LEFT);

    Simple::BackButton(&MyFrame::ancient_shop_bianli_book, panel, vbox, this);
}

