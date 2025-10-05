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

