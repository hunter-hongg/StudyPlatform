#include "func/simple.hpp"
#include "headers.hpp"
#include "type.hpp"
#include <string>
#include <wx/event.h>
#include <wx/gtk/stattext.h>
#include <wx/wx.h>

void MyFrame::ancient_bookstore_chaolu(WXBTNEVT&) {
    auto vbox = Simple::Init(panel, this);

    Simple::Title("抄录书籍", panel, vbox);
    // Simple::ShowButton("", panel, vbox);

    Simple::Button(&MyFrame::ancient_bookstore_chaolu_start, "开始抄录", panel, vbox, this);

    Simple::BackButton(&MyFrame::ancient_bookstore, panel, vbox, this);
}
void MyFrame::ancient_bookstore_chaolu_start(WXBTNEVT&) {
    auto vbox = Simple::Init(panel, this);

    Simple::Title("开始抄录", panel, vbox);

    Simple::BackButton(&MyFrame::ancient_bookstore_chaolu, panel, vbox, this);
}

