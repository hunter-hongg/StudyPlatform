#include <headers.hpp>

fn MyFrame::bank_square(WXBTNEVT&) -> void {
    lmut vbox = Simple::Init(panel, this);

    Simple::TitleNoSpacer("积分银行", panel, vbox);
    Simple::ShowButton("已存积分: "+Bank::BankStore.Read(), panel, vbox);

    Simple::Button(&MyFrame::bank_store, "存储积分", panel, vbox, this);

    Simple::BackButton(&MyFrame::main_func, panel, vbox, this);
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
