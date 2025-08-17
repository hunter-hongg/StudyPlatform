#include <headers.hpp>

void MyFrame::xianlu(WXBTNEVT&){
    MYINIT();
    
    MYTITLENS("我的仙禄");
    MYSHOW(wxString(wxT("仙禄等级："))+Xian::Lu::Ji.read_str());

    MYBUTTON(btn1, &MyFrame::xianlu_next, "仙禄升级");
    MYBUTTON(btn2, &MyFrame::xianlu_get, "领取仙禄");

    MYADDSPACER();

    MYLAST(&MyFrame::xianbi_square);
}

