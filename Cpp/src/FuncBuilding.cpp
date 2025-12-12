#include "func/simple.hpp"
#include "headers.hpp"
#include "signals.hpp"
#include "type.hpp"
#include <string>
#include <wx/event.h>
#include <wx/gtk/stattext.h>
#include <wx/sizer.h>
#include <wx/wx.h>

void MyFrame::tools_all(WXBTNEVT&) {
    auto vbox = Simple::Init(panel, this);

    Simple::Title("各类工具", panel, vbox);

    auto btn_mdmanage = Simple::Button("笔记管理", panel, vbox);
    btn_mdmanage -> Bind(wxEVT_BUTTON, [=, this](WXBTNEVT&) {
        GlobalSignal.ToolsMdManagerStart.emit();
    });

    Simple::BackButton(&MyFrame::main_func, panel, vbox, this);
}
void MyFrame::settings_all(WXBTNEVT&) {
    auto vbox = Simple::Init(panel, this);

}
