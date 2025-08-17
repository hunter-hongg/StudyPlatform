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
