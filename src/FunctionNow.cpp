#include <headers.hpp>

void MyFrame::xiandan_he(WXBTNEVT&){
    MYINIT();
  
    MYTITLE("仙丹召鹤");

    MYBUTTON(btn1, &MyFrame::xiandan_he_yindan, "银丹召鹤");
  
    MYADDSPACER();
  
    MYLAST(&MyFrame::xiandan);
}
void MyFrame::xiandan_he_yindan(WXBTNEVT&){
    MYINIT();

    MYTITLE("银丹召鹤");

    auto btn1 = new wxButton(panel,wxID_ANY,wxT("1银丹召鹤"));
    MYSHOPBUTTON(btn1, MyDarkBlue);
    btn1 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT& ){
        if(!Xian::Dan::Yin.canminus(1)){
            MYMESSAGE("银丹不足");
            return;
        }
        int luck = getrnd(0,100);
        if(luck < 20){
            MYMESSAGE("召鹤成功，获得650积分+80金币");
            JiFenReader.addnum(650);
            JinBiReader.addnum(80);
        } else {
            MYMESSAGE("召鹤成功，获得500积分+50金币");
            JiFenReader.addnum(500);
            JinBiReader.addnum(50);
        }
    });
    vbox -> Add(btn1, FLAG_CENTER);

    auto btn2 = new wxButton(panel,wxID_ANY,wxT("3银丹召鹤"));
    MYSHOPBUTTON(btn2, MyDarkBlue);
    btn2 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT& ){
        if(!Xian::Dan::Yin.canminus(3)){
            MYMESSAGE("银丹不足");
            return;
        }
        int luck = getrnd(0,100);
        if(luck < 40){
            MYMESSAGE("召鹤成功，获得700积分+90金币");
            JiFenReader.addnum(700);
            JinBiReader.addnum(90);
        } else {
            MYMESSAGE("召鹤成功，获得550积分+55金币");
            JiFenReader.addnum(550);
            JinBiReader.addnum(55);
        }
    });
    vbox -> Add(btn2, FLAG_CENTER);

    auto btn3 = new wxButton(panel,wxID_ANY,wxT("5银丹召鹤"));
    MYSHOPBUTTON(btn3, MyDarkBlue);
    btn3 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT& ){
        if(!Xian::Dan::Yin.canminus(5)){
            MYMESSAGE("银丹不足");
            return;
        }
        int luck = getrnd(0,100);
        if(luck < 70){
            MYMESSAGE("召鹤成功，获得750积分+100金币");
            JiFenReader.addnum(750);
            JinBiReader.addnum(100);
        } else {
            MYMESSAGE("召鹤成功，获得600积分+60金币");
            JiFenReader.addnum(600);
            JinBiReader.addnum(60);
        }
    });
    vbox -> Add(btn3, FLAG_CENTER);

    MYADDSPACER();

    MYLAST(&MyFrame::xiandan_he);
}
