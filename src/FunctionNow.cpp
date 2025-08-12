#include <headers.hpp>

void MyFrame::xiandan_he(WXBTNEVT&){
    MYINIT();
  
    MYTITLE("仙丹召鹤");

    MYBUTTON(btn1, &MyFrame::xiandan_he_yindan, "银丹召鹤");
    MYBUTTON(btn2, &MyFrame::xiandan_he_jindan, "金丹召鹤");
  
    MYADDSPACER();
  
    MYLAST(&MyFrame::xiandan);
}
void MyFrame::xiandan_he_jindan(WXBTNEVT&){
  MYINIT();

  MYTITLE("金丹召鹤");

  auto btn1 = new wxButton(panel, wxID_ANY, wxT("1金丹召鹤"));
  MYSHOPBUTTON(btn1, MyDarkOrange);
  btn1 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT&){
    if ( !Xian::Dan::Jin.canminus(1) ) {
      MYMESSAGE("金丹不足");
      return;
    }
    int luck = getrnd(0,100);
    if(luck < 40) {
      MYMESSAGE("召鹤成功，获得1000积分+50金币");
      JiFenReader.addnum(1000);
      JinBiReader.addnum(50);
    } else {
      MYMESSAGE("召鹤成功，获得900积分+40金币");
      JiFenReader.addnum(900);
      JinBiReader.addnum(40);
    }
  });
  vbox -> Add(btn1, FLAG_CENTER);

  auto btn2 = new wxButton(panel, wxID_ANY, wxT("3金丹召鹤"));
  MYSHOPBUTTON(btn2, MyDarkOrange);
  btn2 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT&){
    if ( !Xian::Dan::Jin.canminus(3) ) {
      MYMESSAGE("金丹不足");
      return;
    }
    int luck = getrnd(0,100);
    if(luck < 60) {
      MYMESSAGE("召鹤成功，获得1100积分+80金币");
      JiFenReader.addnum(1100);
      JinBiReader.addnum(80);
    } else {
      MYMESSAGE("召鹤成功，获得1000积分+60金币");
      JiFenReader.addnum(1000);
      JinBiReader.addnum(60);
    }
  });
  vbox -> Add(btn2, FLAG_CENTER);

  auto btn3 = new wxButton(panel, wxID_ANY, wxT("5金丹召鹤"));
  MYSHOPBUTTON(btn3, MyDarkOrange);
  btn3 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT&){
    if ( !Xian::Dan::Jin.canminus(5) ) {
      MYMESSAGE("金丹不足");
      return;
    }
    int luck = getrnd(0,100);
    MYMESSAGE("召鹤成功，获得1300积分+100金币");
    JiFenReader.addnum(1300);
    JinBiReader.addnum(100);
  });
  vbox -> Add(btn3, FLAG_CENTER);

  auto btn4 = new wxButton(panel, wxID_ANY, wxT("10金丹召鹤"));
  MYSHOPBUTTON(btn4, MyDarkOrange);
  btn4 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT&){
    if ( !Xian::Dan::Jin.canminus(10) ) {
      MYMESSAGE("金丹不足");
      return;
    }
    int luck = getrnd(0,100);
    MYMESSAGE("召鹤成功，获得2700积分+220金币");
    JiFenReader.addnum(2700);
    JinBiReader.addnum(220);
  });
  vbox -> Add(btn4, FLAG_CENTER);

  MYADDSPACER();

  MYLAST(&MyFrame::xiandan_he);
}
