#include <headers.hpp>

void MyFrame::ancient_guan(WXBTNEVT&){
    MYINIT();

    MYTITLE("我的官职");

    MYBUTTON(btn1, &MyFrame::ancient_wenguan, "作为文官");

    MYEND(&MyFrame::ancient_square);
}
