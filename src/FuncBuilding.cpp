#include "clog.h"
#include "func/simple.hpp"
#include "gfunc.hpp"
#include "global.hpp"
#include "headers.hpp"
#include "macro.hpp"
#include "mine/MyFlags.h"
#include "rust/AncientBookstoreJiaomai.hpp"
#include "signals.hpp"
#include "type.hpp"
#include "var.hpp"
#include <chrono>
#include <string>
#include <wx/event.h>
#include <wx/gtk/stattext.h>
#include <wx/wx.h>

void MyFrame::ancient_bookstore(WXBTNEVT&) {
    auto vbox = Simple::Init(panel, this);

    Simple::Title("卖出书籍", panel, vbox);

    auto btn1 = Simple::Button("叫卖",panel, vbox);
    btn1 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT&) {
        GlobalSignal.AncientBookstoreJiaomai.emit();
    });

    Simple::BackButton(&MyFrame::ancient_square, panel, vbox, this);
}
void MyFrame::ancient_bookstore_jiaomai(WXBTNEVT&) {
    Global::AncientBookstoreJiaomai::times = 0;

    auto vbox = Simple::Init(panel, this);

    Simple::Title("快速叫卖", panel, vbox);

    auto TiShi = new wxStaticText(panel, wxID_ANY, wxT("请快速点击下方按钮叫卖"));
    TiShi -> SetFont(font17);
    vbox -> Add(TiShi, FLAG_CENTER);

    auto Submit = Simple::BasicButton("快速点击我", panel);
    Submit -> SetFont(font17);
    Submit -> Bind(wxEVT_BUTTON, [=](WXBTNEVT&) {
        GlobalSignal.AncientBookstoreJiaomaiPushed.emit();
    });
    vbox -> Add(Submit, FLAG_CENTER);

    Simple::BackButton(&MyFrame::ancient_bookstore, panel, vbox, this);
}
