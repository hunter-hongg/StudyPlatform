#include "clog.h"
#include "ffi/zig/BookShelf/BookShelf.h"
#include "ffi/zig/BookShelf/BookShelfMacro.hpp"
#include "func/simple.hpp"
#include "global.hpp"
#include "macro.hpp"
#include "var.hpp"
#include <headers.hpp>
#include <signals.hpp>
#include <rust/AncientBookstoreJiaomai.hpp>

void MyFrame::signals_init() {
    GlobalSignal.AncientBookstoreJiaomai.connect([=]() {
        CLogger_log(Logfile, CLogger_DEBUG, "古代广场=>卖出书籍=>叫卖: 槽正确接收");
        this -> ancient_bookstore_jiaomai(EmptyEvent);
    });
    GlobalSignal.AncientBookstoreJiaomaiPushed.connect([=]() {
        CLogger_log(Logfile, CLogger_DEBUG, "古代广场=>书籍叫卖: 叫卖中");
        if(Global::AncientBookstoreJiaomai::times == 0) {
            Global::AncientBookstoreJiaomai::PushStart = std::chrono::steady_clock::now();
        }
        Global::AncientBookstoreJiaomai::times++;
        if(Global::AncientBookstoreJiaomai::times == 20) {
            GlobalSignal.AncientBookstoreJiaomaiPushedDone.emit();
        }
    });
    GlobalSignal.AncientBookstoreJiaomaiPushedDone.connect([=]() {
        Global::AncientBookstoreJiaomai::PushEnd = std::chrono::steady_clock::now();
        auto duration_time = Global::AncientBookstoreJiaomai::PushEnd - Global::AncientBookstoreJiaomai::PushStart;
        auto duration_time_ms = std::chrono::duration_cast<std::chrono::milliseconds>(duration_time);
        auto duration_time_ms_real = duration_time_ms.count();
        int BaiYin = AncientBookstoreJiaomaiGetRes(duration_time_ms_real);
        int BookType = AncientBookstoreJiaomaiGetBookType(BaiYin);
        std::string BookTypeS = gfunc::AncientBookTrans(BookType);
        if(BaiYin == 0) {
            Simple::Message("速度过慢，叫卖失败");
            CLogger_log(Logfile, CLogger_DEBUG, "古代广场=>书籍叫卖: 叫卖失败 退出");
            Global::AncientBookstoreJiaomai::times = 0;
            this -> ancient_bookstore(EmptyEvent);
            return;
        }
        else {
            auto y_or_n = Simple::MessageQues("叫卖成功\n"
                                              "购买书籍: "+BookTypeS+"\n"
                                              "购买价格: "+TOSTR(BaiYin)+"两白银");
            if(y_or_n) {
                CLogger_log(Logfile, CLogger_DEBUG, "古代广场=>书籍叫卖: 叫卖成功 继续");
                BookShelfResult_Get(BookShelf::Reader);
                int NowBook;
                switch(BookType) {
                case 1:
                    NowBook = Level1;
                    break;
                case 2:
                    NowBook = Level2;
                    break;
                case 3:
                    NowBook = Level3;
                    break;
                default:
                    NowBook = 0;
                    break;
                }
                Simple::Message(TOSTR(NowBook));
            } else {
                CLogger_log(Logfile, CLogger_DEBUG, "古代广场=>书籍叫卖: 叫卖成功 被拒绝 退出");
                Global::AncientBookstoreJiaomai::times = 0;
                this -> ancient_bookstore(EmptyEvent);
                return;
            }
        }
    });
}
