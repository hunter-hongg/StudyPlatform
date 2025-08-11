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
    });
    vbox -> Add(btn1, FLAG_CENTER);

    MYADDSPACER();

    MYLAST(&MyFrame::xiandan_he);
}
