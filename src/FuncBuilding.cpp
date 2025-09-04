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
    
    Simple::BackButton(&MyFrame::ancient_wuguan_1, panel, vbox, this);
}
void MyFrame::ancient_wubingli_get(WXBTNEVT&)
{
    auto vbox = Simple::Init(panel, this);

    Simple::Title("具体兵力查看", panel, vbox);

    auto grid = new wxGridSizer(3,3,4,4);

    std::vector<FilePassword> v({
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

    for(const auto& i: v){
        auto btn = new wxButton(panel, wxID_ANY, wxString::FromUTF8(vt[vti]));
        btn -> SetForegroundColour(MyDarkBlue);
        btn -> SetFont(font17);
        grid -> Add(btn, FLAG_CENTER);
        vti++;
    }

    vbox -> Add(grid, FLAG_CENTER);

    Simple::BackButton(&MyFrame::ancient_wuguan_bingli, panel, vbox, this);
}
