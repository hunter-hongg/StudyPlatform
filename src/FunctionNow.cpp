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

  vbox -> Add(grid, FLAG_CENTER);

  MYADDSPACER();

  MYLAST(&MyFrame::xianji);
}

