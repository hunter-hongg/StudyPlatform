#include <headers.hpp>

void MyFrame::xiandan_he(WXBTNEVT&){
    MYINIT();
  
    MYTITLE("仙丹召鹤");

    MYBUTTON(btn1, &MyFrame::xiandan_he_yindan, "银丹召鹤");
    MYBUTTON(btn2, &MyFrame::xiandan_he_jindan, "金丹召鹤");
    MYBUTTON(btn3, &MyFrame::xiandan_he_shendan, "神丹召鹤");
  
    MYADDSPACER();
  
    MYLAST(&MyFrame::xiandan);
}
void MyFrame::xiandan_he_shendan(WXBTNEVT&){
    MYINIT();

    MYTITLE("神丹召鹤");

    auto btn1 = new wxButton(panel, wxID_ANY, wxT("1神丹召鹤"));
    MYSHOPBUTTON(btn1, MyRed);
    btn1 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT&){
        if(!Xian::Dan::Shen.canminus(1)){
            MYMESSAGE("神丹不足");
            return;
        }
        MYMESSAGE("召鹤成功，获得1500积分+500仙币+40金币");
        JiFenReader.addnum(1500);
        XianBiReader.addnum(500);
        JinBiReader.addnum(40);
    });
    vbox -> Add(btn1, FLAG_CENTER);

    auto btn2 = new wxButton(panel, wxID_ANY, wxT("2神丹召鹤"));
    MYSHOPBUTTON(btn2, MyRed);
    btn2 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT&){
        if(!Xian::Dan::Shen.canminus(2)){
            MYMESSAGE("神丹不足");
            return;
        }
        MYMESSAGE("召鹤成功，获得3000积分+1000仙币+85金币");
        JiFenReader.addnum(3000);
        XianBiReader.addnum(1000);
        JinBiReader.addnum(85);
    });
    vbox -> Add(btn2, FLAG_CENTER);

    auto btn3 = new wxButton(panel, wxID_ANY, wxT("3神丹召鹤"));
    MYSHOPBUTTON(btn3, MyRed);
    btn3 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT&){
        if(!Xian::Dan::Shen.canminus(3)){
            MYMESSAGE("神丹不足");
            return;
        }
        MYMESSAGE("召鹤成功，获得4600积分+1500仙币+130金币");
        JiFenReader.addnum(4600);
        XianBiReader.addnum(1500);
        JinBiReader.addnum(130);
    });
    vbox -> Add(btn3, FLAG_CENTER);

    auto btn4 = new wxButton(panel, wxID_ANY, wxT("6神丹召鹤"));
    MYSHOPBUTTON(btn4, MyRed);
    btn4 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT&){
        if(!Xian::Dan::Shen.canminus(6)){
            MYMESSAGE("神丹不足");
            return;
        }
        MYMESSAGE("召鹤成功，获得9300积分+3000仙币+270金币");
        JiFenReader.addnum(9300);
        XianBiReader.addnum(3000);
        JinBiReader.addnum(270);
    });
    vbox -> Add(btn4, FLAG_CENTER);

    MYADDSPACER();

    MYLAST(&MyFrame::xiandan_he);
}
