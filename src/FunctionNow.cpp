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
void MyFrame::xianlu_get(WXBTNEVT&){
    MYINIT();

    MYTITLENS("仙禄领取");
    MYSHOW(wxString(wxT("每日仙禄："))+TOSTR(lambda::xianlu_get_need())+wxT("仙币"));

    MYADDSPACER();

    MYLAST(&MyFrame::xianlu);
}
