#include <headers.hpp>

void MyFrame::ancient_wuguan(WXBTNEVT&)
{
    auto vbox = Simple::Init(panel, this);

    MYTITLE("我的官位");

    Simple::Button(&MyFrame::ancient_wuguan_zhaomu, "征召士兵", panel, vbox, this);
    Simple::Button(&MyFrame::ancient_wuguan_show, "查看兵力", panel, vbox, this);

    MYEND(&MyFrame::ancient_guan);
}
void MyFrame::ancient_wuguan_zhaomu(WXBTNEVT&){
    MYINIT();

    MYTITLE("征召士兵");

    auto grid = new wxGridSizer(3,3,5,5);

    auto btn0 = new wxButton(panel, wxID_ANY, wxT("1两白银\n1新兵"));
    MYSHOPBUTTON(btn0, MyYellow);
    btn0 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT&){
        if(!AncientVar::BaiYinReader.canminus(1)){
            MYMESSAGE("白银不足");
            return;
        }
        AncientVar::WuGuan::LiLiang::Xin.addnum(1);
        MYMESSAGE("征召成功");
    });
    grid -> Add(btn0, FLAG_CENTER);

    auto btn1 = new wxButton(panel, wxID_ANY, wxT("10两白银\n1普通兵"));
    MYSHOPBUTTON(btn1, MyYellow);
    btn1 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT&){
        if(!AncientVar::BaiYinReader.canminus(10)){
            MYMESSAGE("白银不足");
            return;
        }
        AncientVar::WuGuan::LiLiang::PuTong.addnum(1);
        MYMESSAGE("征召成功");
    });
    grid -> Add(btn1, FLAG_CENTER);

    auto btn2 = new wxButton(panel, wxID_ANY, wxT("30两白银\n1初级兵"));
    MYSHOPBUTTON(btn2, MyYellow);
    btn2 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT&){
        if(!AncientVar::BaiYinReader.canminus(30)){
            MYMESSAGE("白银不足");
            return;
        }
        AncientVar::WuGuan::LiLiang::ChuJi.addnum(1);
        MYMESSAGE("征召成功");
    });
    grid -> Add(btn2, FLAG_CENTER);

    auto btn3 = new wxButton(panel, wxID_ANY, wxT("60两白银\n1中级兵"));
    MYSHOPBUTTON(btn3, MyYellow);
    btn3 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT&){
        if(!AncientVar::BaiYinReader.canminus(60)){
            MYMESSAGE("白银不足");
            return;
        }
        AncientVar::WuGuan::LiLiang::ZhongJi.addnum(1);
        MYMESSAGE("征召成功");
    });
    grid -> Add(btn3, FLAG_CENTER);

    auto btn4 = new wxButton(panel, wxID_ANY, wxT("150两白银\n1高级兵"));
    MYSHOPBUTTON(btn4, MyYellow);
    btn4 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT&){
        if(!AncientVar::BaiYinReader.canminus(150)){
            MYMESSAGE("白银不足");
            return;
        }
        AncientVar::WuGuan::LiLiang::GaoJi.addnum(1);
        MYMESSAGE("征召成功");
    });
    grid -> Add(btn4, FLAG_CENTER);

    vbox -> Add(grid, FLAG_CENTER);

    MYEND(&MyFrame::ancient_wuguan);
}

