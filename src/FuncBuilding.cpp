#include "func/simple.hpp"
#include "headers.hpp"
#include "type.hpp"
#include <string>
#include <wx/event.h>
#include <wx/gtk/stattext.h>
#include <wx/wx.h>

void MyFrame::tools_all(WXBTNEVT&) {
    auto vbox = Simple::Init(panel, this);

    Simple::Title("各类工具", panel, vbox);

    Simple::BackButton(&MyFrame::main_func, panel, vbox, this);
}
void MyFrame::settings_all(WXBTNEVT&) {

}
