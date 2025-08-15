#include <headers.hpp>

void MyFrame::xianlu(WXBTNEVT&){
    MYINIT();
    
    MYTITLENS("我的仙禄");
    MYSHOW(wxString(wxT("仙禄等级："))+Xian::Lu::Ji.read_str());

    MYADDSPACER();

    MYLAST(&MyFrame::xianbi_square);
}
