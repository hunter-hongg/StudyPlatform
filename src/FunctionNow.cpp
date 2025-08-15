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
    MYINIT();

    MYTITLE("仙禄升级");

    auto getneed = [=](int dj){
        return 1500 + dj * 100;
    };

    MYSHOWNSNCM(wxString(wxT("需要仙币："))+TOSTR(getneed(Xian::Lu::Ji.read_int())), btn1);
    btn1 -> SetForegroundColour(MyDarkBlue);
    
    auto callback = [=](WXBTNEVT& evt){
        int need = getneed(Xian::Lu::Ji.read_int());
        if(!Files::XianBiReader.canminus(need)){
            MYMESSAGE("仙币不足");
            return;
        }
        Xian::Lu::Ji.addnum(1);
        MYMESSAGE("升级成功");
        this -> xianlu_next(evt);
    };
    MYBUTTONLAMBDA(btn2, callback, "升级仙禄");

    MYADDSPACER();

    MYLAST(&MyFrame::xianlu);
}
