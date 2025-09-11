#include <headers.hpp>

void MyFrame::ancient_wuguan(WXBTNEVT&)
{
    auto vbox = Simple::Init(panel, this);

    Simple::TitleNoSpacer("我的官位", panel, vbox);
    Simple::ShowButton(
        "我的类别：武官\n我的品级："+AncientVar::WuGuan::Pin::Get.ReadStr(),
        panel, vbox
    );

    Simple::Button(&MyFrame::ancient_wuguan_1, "我的士兵", panel, vbox, this);

    Simple::BackButton(&MyFrame::ancient_guan, panel, vbox, this);
}
void MyFrame::ancient_wuguan_1(WXBTNEVT&)
{
    auto vbox = Simple::Init(panel, this);

    Simple::Title("我的士兵", panel, vbox);

    Simple::Button(&MyFrame::ancient_wuguan_zhaomu, "征召士兵", panel, vbox, this);
    Simple::Button(&MyFrame::ancient_wuguan_show, "查看士兵", panel, vbox, this);
    Simple::Button(&MyFrame::ancient_wubingli_plus, "增强兵力", panel, vbox, this);
    Simple::Button(&MyFrame::ancient_wuguan_chuzheng, 
                   "领兵出征", panel, vbox, this);

    Simple::BackButton(&MyFrame::ancient_wuguan, panel, vbox, this);
}

