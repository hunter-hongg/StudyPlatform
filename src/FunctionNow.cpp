#include <headers.hpp>

void MyFrame::xianlu(WXBTNEVT&){
    MYINIT();
    
    MYTITLE("我的仙禄");

    MYADDSPACER();

    MYLAST(&MyFrame::xianbi_square);
}
