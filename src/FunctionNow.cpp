#include <headers.hpp>

void MyFrame::ancient_guan(WXBTNEVT&){
    MYINIT();

    MYTITLE("我的官职");

    MYBUTTON(btn0, &MyFrame::ancient_wenguan, "作为文官");
    MYBUTTON(btn1, &MyFrame::ancient_wuguan, "作为武官");

    MYEND(&MyFrame::ancient_square);
}
void MyFrame::ancient_wuguan(WXBTNEVT&){
    MYINIT();

    MYTITLE("我的官位");

    MYEND(&MyFrame::ancient_guan);
}
