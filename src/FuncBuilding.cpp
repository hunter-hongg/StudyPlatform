#include "clog.h"
#include "func/simple.hpp"
#include "headers.hpp"
#include "signals.hpp"
#include "type.hpp"
#include "var.hpp"
#include <wx/event.h>

void MyFrame::ancient_bookstore(WXBTNEVT&) {
    GlobalSignal.AncientBookstoreJiaomai.connect([=]() {
        CLogger_log(Logfile, CLogger_DEBUG, "古代广场=>卖出书籍=>叫卖: 槽正确接收");
        this -> ancient_bookstore_jiaomai(EmptyEvent);
    });

    auto vbox = Simple::Init(panel, this);

    Simple::Title("卖出书籍", panel, vbox);

    auto btn1 = Simple::Button("叫卖",panel, vbox);
    btn1 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT&) {
        GlobalSignal.AncientBookstoreJiaomai.emit();
    });

    Simple::BackButton(&MyFrame::ancient_square, panel, vbox, this);
}
void MyFrame::ancient_bookstore_jiaomai(WXBTNEVT&) {

}
