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

    for(auto& i: v){
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
    btn1 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT&){
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
    btn2 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT&){
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
    btn3 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT&){
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
    btn4 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT&){
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
    btn5 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT&){
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
    btn6 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT&){
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
    btn7 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT&){
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
    btn8 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT&){
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

    Simple::BackButton(&MyFrame::ancient_wuguan_bingli, panel, vbox, this);
}
