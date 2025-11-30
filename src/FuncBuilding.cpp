#include "func/simple.hpp"
#include "headers.hpp"
#include "signals.hpp"
#include "type.hpp"
#include "var.hpp"
#include <string>
#include <wx/event.h>
#include <wx/gtk/stattext.h>
#include <wx/wx.h>

void MyFrame::bank_juan_use(WXBTNEVT&) {
    auto sfs = ShowFmt;
    auto sfsa = sfs % "捐献券" % Bank::BankJuanQuan.read_int();

    auto vbox = Simple::Init(panel, this);

    Simple::TitleNoSpacer("领取奖励", panel, vbox);
    Simple::ShowButton(sfsa.str(), panel, vbox);

    auto btn1 = Simple::Button("积分奖励", panel, vbox);
    btn1 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT&){
        GlobalSignal.BankJuanUseJiFen.emit();
    });

    Simple::BackButton(&MyFrame::bank_juan, panel, vbox, this);
}
