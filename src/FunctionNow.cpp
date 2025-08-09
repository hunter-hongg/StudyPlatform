#include <headers.hpp>

void MyFrame::xianji_liandan(WXBTNEVT&){
  MYINIT();

  MYTITLE("仙籍炼丹");

  auto grid = new wxGridSizer(2,3,4,4);

  auto btn1 = new wxButton(panel,wxID_ANY,wxT("10仙籍+2银丹\n1金丹"));
  MYSHOPBUTTON(btn1, MyOrange);
  btn1 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT&){
    if(!XianJi::Reader.high(10)){
      MYMESSAGE("仙籍不足");
      return;
    }
    if(!Xian::Dan::Yin.high(2)){
      MYMESSAGE("银丹不足");
      return;
    }
    XianJi::Reader.minusnum(10);
    Xian::Dan::Yin.minusnum(2);
    Xian::Dan::Jin.addnum(1);
    MYMESSAGE("炼制成功");
  });
  grid -> Add(btn1, FLAG_CENTER);

  auto btn2 = new wxButton(panel,wxID_ANY,wxT("20仙籍+4银丹\n2金丹"));
  MYSHOPBUTTON(btn2, MyOrange);
  btn2 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT&){
    if(!XianJi::Reader.high(20)){
      MYMESSAGE("仙籍不足");
      return;
    }
    if(!Xian::Dan::Yin.high(4)){
      MYMESSAGE("银丹不足");
      return;
    }
    XianJi::Reader.minusnum(20);
    Xian::Dan::Yin.minusnum(4);
    Xian::Dan::Jin.addnum(2);
    MYMESSAGE("炼制成功");
  });
  grid -> Add(btn2, FLAG_CENTER);

  auto btn3 = new wxButton(panel,wxID_ANY,wxT("35仙籍+8银丹\n4金丹"));
  MYSHOPBUTTON(btn3, MyOrange);
  btn3 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT&){
    if(!XianJi::Reader.high(35)){
      MYMESSAGE("仙籍不足");
      return;
    }
    if(!Xian::Dan::Yin.high(8)){
      MYMESSAGE("银丹不足");
      return;
    }
    XianJi::Reader.minusnum(35);
    Xian::Dan::Yin.minusnum(8);
    Xian::Dan::Jin.addnum(4);
    MYMESSAGE("炼制成功");
  });
  grid -> Add(btn3, FLAG_CENTER);

  auto btn4 = new wxButton(panel,wxID_ANY,wxT("60仙籍+16银丹\n8金丹"));
  MYSHOPBUTTON(btn4, MyOrange);
  btn4 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT&){
    if(!XianJi::Reader.high(60)){
      MYMESSAGE("仙籍不足");
      return;
    }
    if(!Xian::Dan::Yin.high(16)){
      MYMESSAGE("银丹不足");
      return;
    }
    XianJi::Reader.minusnum(60);
    Xian::Dan::Yin.minusnum(16);
    Xian::Dan::Jin.addnum(8);
    MYMESSAGE("炼制成功");
  });
  grid -> Add(btn4, FLAG_CENTER);

  auto btn5 = new wxButton(panel,wxID_ANY,wxT("20仙籍+2金丹\n1神丹"));
  MYSHOPBUTTON(btn5, MyOrange);
  btn5 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT&){
    if(!XianJi::Reader.high(20)){
      MYMESSAGE("仙籍不足");
      return;
    }
    if(!Xian::Dan::Jin.high(2)){
      MYMESSAGE("金丹不足");
      return;
    }
    XianJi::Reader.minusnum(20);
    Xian::Dan::Jin.minusnum(2);
    Xian::Dan::Shen.addnum(1);
    MYMESSAGE("炼制成功");
  });
  grid -> Add(btn5, FLAG_CENTER);

  vbox -> Add(grid, FLAG_CENTER);

  MYADDSPACER();

  MYLAST(&MyFrame::xianji);
}

