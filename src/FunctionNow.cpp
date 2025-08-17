#include <headers.hpp>

void MyFrame::xianbi_square_1(WXBTNEVT&){
    MYINIT();

    MYTITLE("我的物品");

    MYBUTTON(btn2,&MyFrame::xianqi,"我的仙器");
    MYBUTTON(btn3,&MyFrame::xianji,"我的仙籍");
    MYBUTTON(btn4,&MyFrame::xiandan,"我的仙丹");

    MYADDSPACER();

    MYLAST(&MyFrame::xianbi_square);
}
void MyFrame::xianbi_square_2(WXBTNEVT&){
    MYINIT();

    MYTITLE("我的能力");

    MYBUTTON(btn1,&MyFrame::fali,"我的法力");

    MYADDSPACER();

    MYLAST(&MyFrame::xianbi_square);
}
void MyFrame::xianbi_square_3(WXBTNEVT&){
    MYINIT();

    MYTITLE("我的待遇");

    MYBUTTON(btn4,&MyFrame::xianlu, "我的仙禄");

    MYADDSPACER();

    MYLAST(&MyFrame::xianbi_square);
}
