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

    MYADDSPACER();

    MYLAST(&MyFrame::xiandan_he);
}
