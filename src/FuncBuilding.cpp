#include <headers.hpp>

void MyFrame::ancient_wuguan_1(WXBTNEVT&)
{
    auto vbox = Simple::Init(panel, this);

    Simple::Title("我的士兵", panel, vbox);

    Simple::Button(&MyFrame::ancient_wuguan_zhaomu, "征召士兵", panel, vbox, this);
    Simple::Button(&MyFrame::ancient_wuguan_show, "查看士兵", panel, vbox, this);
    Simple::Button(&MyFrame::ancient_wuguan_bingli, "查看兵力", panel, vbox, this);
    Simple::Button(&MyFrame::ancient_wuguan_chuzheng, "领兵出征", panel, vbox, this);

    Simple::BackButton(&MyFrame::ancient_wuguan, panel, vbox, this);
}
void MyFrame::ancient_wuguan_chuzheng(WXBTNEVT&)
{
    auto vbox = Simple::Init(panel, this);

    Simple::Title("领兵出征", panel, vbox);
    
    Simple::BackButton(&MyFrame::ancient_wuguan_1, panel, vbox, this);
}
