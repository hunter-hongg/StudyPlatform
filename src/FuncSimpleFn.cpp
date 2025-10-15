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
void MyFrame::ancient_wuguan_bingli(WXBTNEVT&)
{ 
    auto vbox = Simple::Init(panel, this);

    Simple::TitleNoSpacer("查看兵力", panel, vbox);
    Simple::ShowButton(
        "我的兵力："+TOSTR(lambda::anc_wu_bingli_get()), panel, vbox);

    Simple::Button(
        &MyFrame::ancient_wubingli_get, "具体兵力", panel, vbox, this);
    Simple::Button(
        &MyFrame::ancient_wubingli_plus, "增强兵力", panel, vbox, this);
    
    Simple::BackButton(&MyFrame::ancient_wuguan_1, panel, vbox, this);
}
void MyFrame::ancient_wuguan_chuzheng_1(WXBTNEVT&){
    using Global::AncientWuGuanChuZheng::bingl_ot;
    using Global::AncientWuGuanChuZheng::bingl_sf;
    using Global::AncientWuGuanChuZhengReal::bingl_ot_now;
    using Global::AncientWuGuanChuZhengReal::bingl_sf_now;
    if ( (bingl_ot_now == -1) && (bingl_sf_now == -1) ) {
        bingl_ot_now = bingl_ot;
        bingl_sf_now = bingl_sf;
    }

    if ( ( bingl_sf < 0 ) || ( bingl_ot < 0 ) ) {
        Simple::MessageErr("运行错误");
        throw cgstdErr::RuntimeErr();
    }
        
    auto vbox = Simple::Init(panel, this);

    Simple::Title("率军出征", panel, vbox);

    Simple::Button(
        &MyFrame::empfunc,
        "对方当前兵力："+TOSTR(bingl_ot_now), 
        panel, vbox, this);
    Simple::Button(
        &MyFrame::empfunc,
        "我方当前兵力："+TOSTR(bingl_sf_now), 
        panel, vbox, this);

    auto grid = new wxGridSizer(2,2,4,4); 

    auto btn1 = new wxButton(panel, wxID_ANY, wxT("进攻敌军"));
    btn1 -> SetFont(font17);
    btn1 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT&){
        using namespace WuGuanChuZheng;
        gfunc::WuGuanChuZhengFunc(Choices::JinGong, 
                                  bingl_sf_now, bingl_ot_now);
        if ( bingl_sf_now < 0 ) {
            Simple::Message("出征结束，你输了");
            bingl_sf_now = -1;
            bingl_ot_now = -1;
            this -> ancient_wuguan_chuzheng(EmptyEvent);
        } else if ( bingl_ot_now < 0 ) {
            Simple::Message("出征结束，你赢了");
            bingl_sf_now = -1;
            bingl_ot_now = -1;
            this -> ancient_wuguan_chuzheng(EmptyEvent);
        } else {
            this -> ancient_wuguan_chuzheng_1(EmptyEvent);
        }
    });
    grid -> Add(btn1, FLAG_CENTER);

    auto btn2 = new wxButton(panel, wxID_ANY, wxT("休整兵马"));
    btn2 -> SetFont(font17);
    btn2 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT&){
        using namespace WuGuanChuZheng;
        gfunc::WuGuanChuZhengFunc(Choices::XiuZheng, 
                                  bingl_sf_now, bingl_ot_now);
        if ( bingl_sf_now < 0 ) {
            Simple::Message("出征结束，你输了");
            bingl_sf_now = -1;
            bingl_ot_now = -1;
            this -> ancient_wuguan_chuzheng(EmptyEvent);
        } else if ( bingl_ot_now < 0 ) {
            Simple::Message("出征结束，你赢了");
            bingl_sf_now = -1;
            bingl_ot_now = -1;
            this -> ancient_wuguan_chuzheng(EmptyEvent);
        } else {
            this -> ancient_wuguan_chuzheng_1(EmptyEvent);
        }
    });
    grid -> Add(btn2, FLAG_CENTER);

    auto btn3 = new wxButton(panel, wxID_ANY, wxT("防守敌军"));
    btn3 -> SetFont(font17);
    btn3 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT&){
        using namespace WuGuanChuZheng;
        gfunc::WuGuanChuZhengFunc(Choices::FangShou, 
                                  bingl_sf_now, bingl_ot_now);
        if ( bingl_sf_now < 0 ) {
            Simple::Message("出征结束，你输了");
            bingl_sf_now = -1;
            bingl_ot_now = -1;
            this -> ancient_wuguan_chuzheng(EmptyEvent);
        } else if ( bingl_ot_now < 0 ) {
            Simple::Message("出征结束，你赢了");
            bingl_sf_now = -1;
            bingl_ot_now = -1;
            this -> ancient_wuguan_chuzheng(EmptyEvent);
        } else {
            this -> ancient_wuguan_chuzheng_1(EmptyEvent);
        }
    });
    grid -> Add(btn3, FLAG_CENTER);

    auto btn4 = new wxButton(panel, wxID_ANY, wxT("趁其不备"));
    btn4 -> SetFont(font17);
    btn4 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT&){
        using namespace WuGuanChuZheng;
        gfunc::WuGuanChuZhengFunc(Choices::TouXi, 
                                  bingl_sf_now, bingl_ot_now);
        if ( bingl_sf_now < 0 ) {
            Simple::Message("出征结束，你输了");
            bingl_sf_now = -1;
            bingl_ot_now = -1;
            this -> ancient_wuguan_chuzheng(EmptyEvent);
        } else if ( bingl_ot_now < 0 ) {
            Simple::Message("出征结束，你赢了");
            bingl_sf_now = -1;
            bingl_ot_now = -1;
            this -> ancient_wuguan_chuzheng(EmptyEvent);
        } else {
            this -> ancient_wuguan_chuzheng_1(EmptyEvent);
        }
    });
    grid -> Add(btn4, FLAG_CENTER);

    vbox -> Add(grid, FLAG_CENTER);

    Simple::BackButton(&MyFrame::CallBack1, panel, vbox, this);
}

