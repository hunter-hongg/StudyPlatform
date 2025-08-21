#include <headers.hpp>

void MyFrame::ancient_wuguan(WXBTNEVT&)
{
    auto vbox = Simple::Init(panel, this);

    Simple::Title("我的官位", panel, vbox);

    Simple::Button(&MyFrame::ancient_wuguan_zhaomu, "征召士兵", panel, vbox, this);
    Simple::Button(&MyFrame::ancient_wuguan_show, "查看兵力", panel, vbox, this);

    Simple::BackButton(&MyFrame::ancient_guan, panel, vbox, this);
}
void MyFrame::ancient_wuguan_zhaomu(WXBTNEVT&){
    auto vbox = Simple::Init(panel, this);

    Simple::Title("征召士兵", panel, vbox);

    auto grid = new wxGridSizer(3,3,5,5);

    auto btn0 = Simple::ShopButton("1两白银\n1新兵", panel, MyYellow);
    btn0 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT&){
        if(!AncientVar::BaiYinReader.canminus(1)){
            Simple::Message("白银不足");
            return;
        }
        AncientVar::WuGuan::LiLiang::Xin.addnum(1);
        Simple::Message("征召成功");
    });
    grid -> Add(btn0, FLAG_CENTER);

    auto btn1 = Simple::ShopButton("10两白银\n1普通兵", panel, MyYellow);
    btn1 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT&){
        if(!AncientVar::BaiYinReader.canminus(10)){
            Simple::Message("白银不足");
            return;
        }
        AncientVar::WuGuan::LiLiang::PuTong.addnum(1);
        Simple::Message("征召成功");
    });
    grid -> Add(btn1, FLAG_CENTER);

    auto btn2 = Simple::ShopButton("30两白银\n1初级兵", panel, MyYellow);
    btn2 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT&){
        if(!AncientVar::BaiYinReader.canminus(30)){
            Simple::Message("白银不足");
            return;
        }
        AncientVar::WuGuan::LiLiang::ChuJi.addnum(1);
        Simple::Message("征召成功");
    });
    grid -> Add(btn2, FLAG_CENTER);

    auto btn3 = Simple::ShopButton("60两白银\n1中级兵", panel, MyYellow);
    btn3 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT&){
        if(!AncientVar::BaiYinReader.canminus(60)){
            Simple::Message("白银不足");
            return;
        }
        AncientVar::WuGuan::LiLiang::ZhongJi.addnum(1);
        Simple::Message("征召成功");
    });
    grid -> Add(btn3, FLAG_CENTER);

    auto btn4 = Simple::ShopButton("150两白银\n1高级兵", panel, MyYellow);
    btn4 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT&){
        if(!AncientVar::BaiYinReader.canminus(150)){
            Simple::Message("白银不足");
            return;
        }
        AncientVar::WuGuan::LiLiang::GaoJi.addnum(1);
        Simple::Message("征召成功");
    });
    grid -> Add(btn4, FLAG_CENTER);

    auto btn5 = Simple::ShopButton("350两白银\n1精锐兵", panel, MyYellow);
    btn5 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT&){
        if(!AncientVar::BaiYinReader.canminus(350)){
            Simple::Message("白银不足");
            return;
        }
        AncientVar::WuGuan::LiLiang::JingRui.addnum(1);
        Simple::Message("征召成功");
    });
    grid -> Add(btn5, FLAG_CENTER);

    auto btn6 = Simple::ShopButton("750两白银\n1王牌兵", panel, MyYellow);
    btn6 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT&){
        if(!AncientVar::BaiYinReader.canminus(750)){
            Simple::Message("白银不足");
            return;
        }
        AncientVar::WuGuan::LiLiang::WangPai.addnum(1);
        Simple::Message("征召成功");
    });
    grid -> Add(btn6, FLAG_CENTER);

    auto btn7 = Simple::ShopButton("2000两白银\n2神级兵", panel, MyYellow);
    btn7 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT&){
        if(!AncientVar::BaiYinReader.canminus(2000)){
            Simple::Message("白银不足");
            return;
        }
        AncientVar::WuGuan::LiLiang::ShenJi.addnum(2);
        Simple::Message("征召成功");
    });
    grid -> Add(btn7, FLAG_CENTER);

    vbox -> Add(grid, FLAG_CENTER);

    Simple::BackButton(&MyFrame::ancient_wuguan, panel, vbox, this);
}

