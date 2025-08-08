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
  
  vbox -> Add(grid, FLAG_CENTER);

  MYADDSPACER();

  MYLAST(&MyFrame::xianqi);
}
