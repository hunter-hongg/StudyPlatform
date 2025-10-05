#include <headers.hpp>

fn MyFrame::bank_square(WXBTNEVT&) -> void {
    lmut vbox = Simple::Init(panel, this);

    Simple::TitleNoSpacer("积分银行", panel, vbox);
    Simple::ShowButton("已存积分: "+Bank::BankStore.Read(), panel, vbox);

    Simple::Button(&MyFrame::bank_store, "存储积分", panel, vbox, this);
    Simple::Button(&MyFrame::bank_get, "领取积分", panel, vbox, this);

    Simple::BackButton(&MyFrame::main_func, panel, vbox, this);
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

