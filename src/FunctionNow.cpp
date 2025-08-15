#include <headers.hpp>

void MyFrame::xianlu(WXBTNEVT&){
    MYINIT();
    
    MYTITLENS("我的仙禄");
    MYSHOW(wxString(wxT("仙禄等级："))+Xian::Lu::Ji.read_str());

    MYBUTTON(btn1, &MyFrame::xianlu_next, "仙禄升级");

    MYADDSPACER();

    MYLAST(&MyFrame::xianbi_square);
}
void MyFrame::xianlu_next(WXBTNEVT&){
}
