#include "func/simple.hpp"
#include "headers.hpp"
#include "signals.hpp"
#include "type.hpp"
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
