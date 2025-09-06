#include <headers.hpp>

void MyFrame::ancient_wuguan_chuzheng(WXBTNEVT&)
{
    auto vbox = Simple::Init(panel, this);

    Simple::Title("领兵出征", panel, vbox);
    
    Simple::BackButton(&MyFrame::ancient_wuguan_1, panel, vbox, this);
}
void MyFrame::ancient_wuguan_bingli(WXBTNEVT&)
{
    auto vbox = Simple::Init(panel, this);

    Simple::TitleNoSpacer("查看兵力", panel, vbox);
    Simple::ShowButton("我的兵力："+TOSTR(lambda::anc_wu_bingli_get()), panel, vbox);

    Simple::Button(&MyFrame::ancient_wubingli_get, "具体兵力", panel, vbox, this);
    Simple::Button(&MyFrame::ancient_wubingli_plus, "增强兵力", panel, vbox, this);
    
    Simple::BackButton(&MyFrame::ancient_wuguan_1, panel, vbox, this);
}
void MyFrame::ancient_wubingli_plus(WXBTNEVT&)
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
        }
    });
    grid -> Add(btn1, FLAG_CENTER);

    vbox -> Add(grid, FLAG_CENTER);

    Simple::BackButton(&MyFrame::ancient_wuguan_bingli, panel, vbox, this);
}
