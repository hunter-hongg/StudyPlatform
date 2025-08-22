#include <headers.hpp>

void MyFrame::ancient_wuguan(WXBTNEVT&)
{
    auto vbox = Simple::Init(panel, this);

    Simple::TitleNoSpacer("我的官位", panel, vbox);
    Simple::ShowButton(
        "我的类别：武官\n我的品级：",
        panel, vbox
    );

    Simple::Button(&MyFrame::ancient_wuguan_zhaomu, "征召士兵", panel, vbox, this);
    Simple::Button(&MyFrame::ancient_wuguan_show, "查看兵力", panel, vbox, this);

    Simple::BackButton(&MyFrame::ancient_guan, panel, vbox, this);
}


