#include <headers.hpp>

void MyFrame::ancient_wuguan_chuzheng(WXBTNEVT&)
{
    auto vbox = Simple::Init(panel, this);

    Simple::TitleNoSpacer("领兵出征", panel, vbox);
    Simple::ShowButton(
        "我的兵力："+TOSTR(lambda::anc_wu_bingli_get()), panel, vbox);
    
    Simple::BackButton(&MyFrame::ancient_wuguan_1, panel, vbox, this);
}
void MyFrame::ancient_wuguan_bingli(WXBTNEVT&)
{
    auto vbox = Simple::Init(panel, this);

    Simple::TitleNoSpacer("查看兵力", panel, vbox);
    Simple::ShowButton(
        "我的兵力："+TOSTR(lambda::anc_wu_bingli_get()), panel, vbox);

    Simple::Button(&MyFrame::ancient_wubingli_get, "具体兵力", panel, vbox, this);
    Simple::Button(&MyFrame::ancient_wubingli_plus, "增强兵力", panel, vbox, this);
    
    Simple::BackButton(&MyFrame::ancient_wuguan_1, panel, vbox, this);
}

