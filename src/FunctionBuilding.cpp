#include <headers.hpp>

void MyFrame::xianqi_liandan(WXBTNEVT&){
  MYINIT();

  MYTITLE("仙器炼丹");

  auto grid = new wxGridSizer(3,3,4,4);

  auto btn1 = new wxButton(panel,wxID_ANY,wxT("10仙器法力+2普通丹\n1碧丹"));
  MYSHOPBUTTON(btn1, MyDarkOrange);
  btn1 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT&){
    if(!XianQiFaLiReader.high(10)){
      MYMESSAGE("仙器法力不足");
      return;
    }
    if(!Xian::Dan::PuTong.high(2)){
      MYMESSAGE("普通丹不足");
      return;
    }
    XianQiFaLiReader.minusnum(10);
    Xian::Dan::PuTong.minusnum(2);
    Xian::Dan::Bi.addnum(1);
    MYMESSAGE("炼制成功");
  });
  grid -> Add(btn1, FLAG_CENTER);
  
  auto btn2 = new wxButton(panel,wxID_ANY,wxT("15仙器法力+2碧丹\n1青丹"));
  MYSHOPBUTTON(btn2, MyDarkOrange);
  btn2 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT&){
    if(!XianQiFaLiReader.high(15)){
      MYMESSAGE("仙器法力不足");
      return;
    }
    if(!Xian::Dan::Bi.high(2)){
      MYMESSAGE("碧丹不足");
      return;
    }
    XianQiFaLiReader.minusnum(15);
    Xian::Dan::Bi.minusnum(2);
    Xian::Dan::Qing.addnum(1);
    MYMESSAGE("炼制成功");
  });
  grid -> Add(btn2, FLAG_CENTER);

  auto btn3 = new wxButton(panel,wxID_ANY,wxT("20仙器法力+2青丹\n1紫丹"));
  MYSHOPBUTTON(btn3, MyDarkOrange);
  btn3 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT&){
    if(!XianQiFaLiReader.high(20)){
      MYMESSAGE("仙器法力不足");
      return;
    }
    if(!Xian::Dan::Qing.high(2)){
      MYMESSAGE("青丹不足");
      return;
    }
    XianQiFaLiReader.minusnum(20);
    Xian::Dan::Qing.minusnum(2);
    Xian::Dan::Zi.addnum(1);
    MYMESSAGE("炼制成功");
  });
  grid -> Add(btn3, FLAG_CENTER);
  
  auto btn4 = new wxButton(panel,wxID_ANY,wxT("25仙器法力+2紫丹\n1五色丹"));
  MYSHOPBUTTON(btn4, MyDarkOrange);
  btn4 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT&){
    if(!XianQiFaLiReader.high(25)){
      MYMESSAGE("仙器法力不足");
      return;
    }
    if(!Xian::Dan::Zi.high(2)){
      MYMESSAGE("紫丹不足");
      return;
    }
    XianQiFaLiReader.minusnum(25);
    Xian::Dan::Zi.minusnum(2);
    Xian::Dan::WuSe.addnum(1);
    MYMESSAGE("炼制成功");
  });
  grid -> Add(btn4, FLAG_CENTER);

  auto btn5 = new wxButton(panel,wxID_ANY,wxT("30仙器法力+2五色丹\n1银丹"));
  MYSHOPBUTTON(btn5, MyDarkOrange);
  btn5 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT&){
    if(!XianQiFaLiReader.high(30)){
      MYMESSAGE("仙器法力不足");
      return;
    }
    if(!Xian::Dan::WuSe.high(2)){
      MYMESSAGE("五色丹不足");
      return;
    }
    XianQiFaLiReader.minusnum(30);
    Xian::Dan::WuSe.minusnum(2);
    Xian::Dan::Yin.addnum(1);
    MYMESSAGE("炼制成功");
  });
  grid -> Add(btn5, FLAG_CENTER);  
  
  vbox -> Add(grid, FLAG_CENTER);

  MYADDSPACER();

  MYLAST(&MyFrame::xianqi);
}
