#include <headers.hpp>

void MyFrame::ancient_wuguan(WXBTNEVT&){
    MYINIT();

    MYTITLE("我的官位");

    MYBUTTON(btn0, &MyFrame::ancient_wuguan_zhaomu, "征召士兵");

    MYEND(&MyFrame::ancient_guan);
}
void MyFrame::ancient_wuguan_zhaomu(WXBTNEVT&){
    MYINIT();

    MYTITLE("征召士兵");

    auto btn1 = new wxButton(panel, wxID_ANY, wxT("10白银\n1普通兵"));
    MYSHOPBUTTON(btn1, MyYellow);
    btn1 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT&){
        if(!AncientVar::BaiYinReader.canminus(10)){
            MYMESSAGE("白银不足");
            return;
        }
        AncientVar::WuGuan::LiLiang::PuTong.addnum(1);
        MYMESSAGE("征召成功");
    });
    vbox -> Add(btn1, FLAG_CENTER);

    MYEND(&MyFrame::ancient_wuguan);
}
