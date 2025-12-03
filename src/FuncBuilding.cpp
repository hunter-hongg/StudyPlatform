#include "func/simple.hpp"
#include "headers.hpp"
#include "signals.hpp"
#include "type.hpp"
#include "var.hpp"
#include <string>
#include <wx/event.h>
#include <wx/gtk/stattext.h>
#include <wx/wx.h>

void MyFrame::ancient_bookstore_chaolu(WXBTNEVT&) {
    auto vbox = Simple::Init(panel, this);

    Simple::Title("抄录书籍", panel, vbox);
    // Simple::ShowButton("", panel, vbox);

    Simple::BackButton(&MyFrame::ancient_bookstore, panel, vbox, this);
}
