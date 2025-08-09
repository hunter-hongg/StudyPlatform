#include <headers.hpp>

void MyFrame::xianji_liandan(WXBTNEVT&){
  MYINIT();

  MYTITLE("仙籍炼丹");

  auto grid = new wxGridSizer(2,3,4,4);

  auto btn1 = new wxButton(panel,wxID_ANY,wxT("10仙籍+2银丹\n1金丹"));
  MYSHOPBUTTON(btn1, MyOrange);
  btn1 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT&){
  });
  grid -> Add(btn1, FLAG_CENTER);

  vbox -> Add(grid, FLAG_CENTER);

  MYADDSPACER();

  MYLAST(&MyFrame::xianji);
}

