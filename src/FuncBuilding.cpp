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

    Simple::BackButton(&MyFrame::bank_square, panel, vbox, this);
}
