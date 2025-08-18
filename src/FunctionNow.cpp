#include <headers.hpp>

void MyFrame::ancient_wuguan(WXBTNEVT&){
    MYINIT();

    MYTITLE("我的官位");

    MYBUTTON(btn0, &MyFrame::ancient_wuguan_zhaomu, "征召士兵");
    MYBUTTON(btn1, &MyFrame::ancient_wuguan_show, "查看兵力");

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

    vbox -> Add(grid, FLAG_CENTER);

    MYEND(&MyFrame::ancient_wuguan);
}
void MyFrame::ancient_wuguan_show(WXBTNEVT&){
    MYINIT();

    MYTITLE("查看兵力");

    auto grid = new wxGridSizer(3,3,5,5);

    MYSHOWNSNBM(
        wxString(wxT("新兵："))+AncientVar::WuGuan::LiLiang::Xin.read_str()+wxT("人"), 
        btn0, MyDarkRed
    );
    grid -> Add(btn0);

    MYSHOWNSNBM(
        wxString(wxT("普通兵："))+AncientVar::WuGuan::LiLiang::PuTong.read_str()+wxT("人"), 
        btn1, MyDarkRed
    );
    grid -> Add(btn1);

    MYSHOWNSNBM(
        wxString(wxT("初级兵："))+AncientVar::WuGuan::LiLiang::ChuJi.read_str()+wxT("人"), 
        btn2, MyDarkRed
    );
    grid -> Add(btn2);

    MYSHOWNSNBM(
        wxString(wxT("中级兵："))+AncientVar::WuGuan::LiLiang::ZhongJi.read_str()+wxT("人"), 
        btn3, MyDarkRed
    );
    grid -> Add(btn3);

    MYSHOWNSNBM(
        wxString(wxT("高级兵："))+AncientVar::WuGuan::LiLiang::GaoJi.read_str()+wxT("人"), 
        btn4, MyDarkRed
    );
    grid -> Add(btn4);

    MYSHOWNSNBM(
        wxString(wxT("精锐兵："))+AncientVar::WuGuan::LiLiang::JingRui.read_str()+wxT("人"), 
        btn5, MyDarkRed
    );
    grid -> Add(btn5);

    MYSHOWNSNBM(
        wxString(wxT("王牌兵："))+AncientVar::WuGuan::LiLiang::WangPai.read_str()+wxT("人"), 
        btn6, MyDarkRed
    );
    grid -> Add(btn6);

    MYSHOWNSNBM(
        wxString(wxT("神级兵："))+AncientVar::WuGuan::LiLiang::ShenJi.read_str()+wxT("人"), 
        btn7, MyDarkRed
    );
    grid -> Add(btn7);

    vbox -> Add(grid, FLAG_CENTER);

    MYEND(&MyFrame::ancient_wuguan);
}
