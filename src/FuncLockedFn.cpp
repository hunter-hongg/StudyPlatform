#include <headers.hpp>

void MyFrame::ancient_wuguan_zhaomu(WXBTNEVT&){
    auto vbox = Simple::Init(panel, this);

    Simple::Title("征召士兵", panel, vbox);

    auto grid = new wxGridSizer(3,3,5,5);

    auto btn0 = Simple::ShopButton("1两白银\n1新兵", panel, MyYellow);
    btn0 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT&){
        if(!AncientVar::BaiYinReader.canminus(1)){
            Simple::Message("白银不足");
            return;
        }
        AncientVar::WuGuan::LiLiang::Xin.addnum(1);
        Simple::Message("征召成功");
    });
    grid -> Add(btn0, FLAG_CENTER);

    auto btn1 = Simple::ShopButton("10两白银\n1普通兵", panel, MyYellow);
    btn1 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT&){
        if(!AncientVar::BaiYinReader.canminus(10)){
            Simple::Message("白银不足");
            return;
        }
        AncientVar::WuGuan::LiLiang::PuTong.addnum(1);
        Simple::Message("征召成功");
    });
    grid -> Add(btn1, FLAG_CENTER);

    auto btn2 = Simple::ShopButton("30两白银\n1初级兵", panel, MyYellow);
    btn2 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT&){
        if(!AncientVar::BaiYinReader.canminus(30)){
            Simple::Message("白银不足");
            return;
        }
        AncientVar::WuGuan::LiLiang::ChuJi.addnum(1);
        Simple::Message("征召成功");
    });
    grid -> Add(btn2, FLAG_CENTER);

    auto btn3 = Simple::ShopButton("60两白银\n1中级兵", panel, MyYellow);
    btn3 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT&){
        if(!AncientVar::BaiYinReader.canminus(60)){
            Simple::Message("白银不足");
            return;
        }
        AncientVar::WuGuan::LiLiang::ZhongJi.addnum(1);
        Simple::Message("征召成功");
    });
    grid -> Add(btn3, FLAG_CENTER);

    auto btn4 = Simple::ShopButton("150两白银\n1高级兵", panel, MyYellow);
    btn4 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT&){
        if(!AncientVar::BaiYinReader.canminus(150)){
            Simple::Message("白银不足");
            return;
        }
        AncientVar::WuGuan::LiLiang::GaoJi.addnum(1);
        Simple::Message("征召成功");
    });
    grid -> Add(btn4, FLAG_CENTER);

    auto btn5 = Simple::ShopButton("350两白银\n1精锐兵", panel, MyYellow);
    btn5 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT&){
        if(!AncientVar::BaiYinReader.canminus(350)){
            Simple::Message("白银不足");
            return;
        }
        AncientVar::WuGuan::LiLiang::JingRui.addnum(1);
        Simple::Message("征召成功");
    });
    grid -> Add(btn5, FLAG_CENTER);

    auto btn6 = Simple::ShopButton("750两白银\n1王牌兵", panel, MyYellow);
    btn6 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT&){
        if(!AncientVar::BaiYinReader.canminus(750)){
            Simple::Message("白银不足");
            return;
        }
        AncientVar::WuGuan::LiLiang::WangPai.addnum(1);
        Simple::Message("征召成功");
    });
    grid -> Add(btn6, FLAG_CENTER);

    auto btn7 = Simple::ShopButton("2000两白银\n2神级兵", panel, MyYellow);
    btn7 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT&){
        if(!AncientVar::BaiYinReader.canminus(2000)){
            Simple::Message("白银不足");
            return;
        }
        AncientVar::WuGuan::LiLiang::ShenJi.addnum(2);
        Simple::Message("征召成功");
    });
    grid -> Add(btn7, FLAG_CENTER);

    vbox -> Add(grid, FLAG_CENTER);

    Simple::BackButton(&MyFrame::ancient_wuguan_1, panel, vbox, this);
}
fn MyFrame::bank_store(WXBTNEVT&) -> void {
    lmut vbox = Simple::Init(panel, this);

    Simple::TitleNoSpacer("存储积分",panel, vbox);
    Simple::ShowButton(
        "当前积分："+JiFenReader.read_str()+"\n"+
        "已存积分："+Bank::BankStore.Read(), 
        panel, vbox
    );
 
    auto button_fuzhu1 = new wxButton(panel, wxID_ANY, 
                                      wxT("请输入存储积分数："));
    button_fuzhu1 -> SetForegroundColour(MyBlue);
    button_fuzhu1 -> SetFont(font15);
    vbox -> Add(button_fuzhu1, FLAG_LEFT);

    auto reader = new wxTextCtrl(panel, wxID_ANY, wxT("请输入..."));
    reader -> SetFont(font15);
    vbox -> Add(reader, FLAG_LEFT);

    auto button_submit = new wxButton(panel, wxID_ANY, 
                                      wxT("存储"));
    button_submit -> SetFont(font15);
    button_submit -> Bind(wxEVT_BUTTON, [=](WXBTNEVT&){
        std::string raw = reader -> GetValue().ToStdString();
        int used;
        try {
            used = std::stoi(raw);
        } catch (...) {
            used = 0;
        }
        bool ans = Simple::MessageQues("你将要存储"+TOSTR(used)+"积分");
        if ( ! ans ) { return ; }
        if ( used <= 0 ) {
            Simple:: MessageErr(
                "无法存储0积分及以下"
            );
            return;
        }
        if ( JiFenReader.read_int() < used ) {
            Simple::MessageErr(
                "积分不足"
            );
            return;
        }
        lmut t = BigInt(Bank::BankStore.Read());
        t.Add(BigInt(used));
        Bank::BankStore.Write(t.toString());
        JiFenReader.minusnum(used);
        this -> bank_store(EmptyEvent);
    });
    vbox -> Add(button_submit, FLAG_LEFT);

    Simple::BackButton(&MyFrame::bank_square, panel, vbox, this);
} 
fn MyFrame::bank_get(WXBTNEVT&) -> void {
    lmut vbox = Simple::Init(panel, this);

    Simple::TitleNoSpacer("领取积分",panel, vbox);
    Simple::ShowButton(
        "当前积分："+JiFenReader.read_str()+"\n"+
        "已存积分："+Bank::BankStore.Read(), 
        panel, vbox
    );
 
    auto button_fuzhu1 = new wxButton(panel, wxID_ANY, 
                                      wxT("请输入领取积分数："));
    button_fuzhu1 -> SetForegroundColour(MyBlue);
    button_fuzhu1 -> SetFont(font15);
    vbox -> Add(button_fuzhu1, FLAG_LEFT);

    auto reader = new wxTextCtrl(panel, wxID_ANY, wxT("请输入..."));
    reader -> SetFont(font15);
    vbox -> Add(reader, FLAG_LEFT);

    auto button_submit = new wxButton(panel, wxID_ANY, 
                                      wxT("领取"));
    button_submit -> SetFont(font15);
    button_submit -> Bind(wxEVT_BUTTON, [=](WXBTNEVT&){
        std::string raw = reader -> GetValue().ToStdString();
        cgstdOption::Option<int> used;
        try {
            used = cgstdOption::Option(std::stoi(raw));
        } catch (...) {
            used = cgstdOption::Option<int>();
        }
        bool ans = Simple::MessageQues("你将要领取"+TOSTR(
            used.unwrap_or(0)
        )+"积分");
        if ( ! ans ) { return ; }
        if ( used.is_none() ) {
            Simple:: MessageErr(
                "无法领取积分"
            );
            return;
        }
        cgstdOption::Option<int> bstr;
        try {
            bstr = cgstdOption::Option(std::stoi(Bank::BankStore.Read()));
        } catch (...) {
            bstr = cgstdOption::Option<int>();
        }
        if ( bstr.is_none() ) {
            Simple::MessageErr (
                "读入失败"
            );
            return;
        }
        if ( bstr.unwrap() < used.unwrap() ) {
            Simple::MessageErr(
                "积分不足"
            );
            return;
        }
        lmut t = BigInt(bstr.unwrap() - used.unwrap());
        Bank::BankStore.Write(t.toString());
        JiFenReader.addnum(used.unwrap());
        this -> bank_get(EmptyEvent);
    });
    vbox -> Add(button_submit, FLAG_LEFT);

    Simple::BackButton(&MyFrame::bank_square, panel, vbox, this);
} 
fn MyFrame::tongy(WXBTNEVT&) -> void {
    lmut vbox = Simple::Init(panel, this);

    Simple::TitleNoSpacer("通用货币", panel, vbox);
    Simple::ShowButton(
        "通用货币: "+TongYongReal::Reader.read_str()+"\n"+
        "当前积分: "+JiFenReader.read_str()
        , panel, vbox);

    auto button_fuzhu1 = new wxButton(panel, wxID_ANY, 
                                      wxT("请输入兑换通用货币数："));
    button_fuzhu1 -> SetForegroundColour(MyBlue);
    button_fuzhu1 -> SetFont(font15);
    vbox -> Add(button_fuzhu1, FLAG_LEFT);

    auto reader = new wxTextCtrl(panel, wxID_ANY, wxT("请输入..."));
    reader -> SetFont(font15);
    vbox -> Add(reader, FLAG_LEFT);

    auto button_submit = new wxButton(panel, wxID_ANY, 
                                      wxT("兑换"));
    button_submit -> SetFont(font15);
    button_submit -> Bind(wxEVT_BUTTON, [=](WXBTNEVT&){
        std::string raw = reader -> GetValue().ToStdString();
        cgstdOption::Option<int> used;
        try {
            used = cgstdOption::Option(std::stoi(raw));
        } catch (...) {
            used = cgstdOption::Option<int>();
        }
        bool ans = Simple::MessageQues("你将要兑换"+TOSTR(
            used.unwrap_or(0)
        )+"通用货币");
        if ( ! ans ) { return ; }
        if ( used.is_none() ) {
            Simple:: MessageErr(
                "无法兑换通用货币"
            );
            return;
        }
        int bstr = JiFenReader.read_int();
        if ( bstr/1000 < used.unwrap() ) {
            Simple::MessageErr(
                "积分不足"
            );
            return;
        }
        JiFenReader.minusnum((used.unwrap())*1000);
        TongYongReal::Reader.addnum(used.unwrap());
        this -> tongy(EmptyEvent);
    });
    vbox -> Add(button_submit, FLAG_LEFT);

    Simple::BackButton(&MyFrame::tongy_all, panel, vbox, this);
}
void MyFrame::CallBack1(WXBTNEVT&){
    Simple::Message("临阵脱逃，绝不可行！\n死战到底，宁死不屈！");
}
