#include "clog.h"
#include "ffi/zig/BookShelf/BookShelfMacro.hpp"
#include "func/simple.hpp"
#include "global.hpp"
#include "macro.hpp"
#include "var.hpp"
#include <markdowntoolmain.hpp>
#include <headers.hpp>
#include <signals.hpp>
#include <rust/AncientBookstoreJiaomai.hpp>
#include <rust/BankJuanUseJiFenUse.hpp>

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
        if(!AncientVar::TongBiReader.canminus(5)) {
            Simple::MessageErr("铜钱不足");
            Global::AncientBookstoreJiaomai::times = 0;
            this -> ancient_bookstore(EmptyEvent);
            return;
        }
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
                // Simple::Message(TOSTR(NowBook));
                if(NowBook < 1) {
                    Simple::MessageErr("书籍不足");
                    Global::AncientBookstoreJiaomai::times = 0;
                    this -> ancient_bookstore(EmptyEvent);
                    return;
                }
                else {
                    switch(BookType) {
                    case 1:
                        BookShelfFiles_WriteLevel1(BookShelf::Reader, -1);
                        break;
                    case 2:
                        BookShelfFiles_WriteLevel2(BookShelf::Reader, -1);
                        break;
                    case 3:
                        BookShelfFiles_WriteLevel3(BookShelf::Reader, -1);
                        break;
                    default:
                        Global::AncientBookstoreJiaomai::times = 0;
                        this -> ancient_bookstore(EmptyEvent);
                        return;
                    }
                    AncientVar::BaiYinReader.addnum(BaiYin);
                    Simple::Message("书籍卖出成功");
                    CLogger_log(Logfile, CLogger_DEBUG, "古代广场=>书籍叫卖: 卖出成功 退出");
                    Global::AncientBookstoreJiaomai::times = 0;
                    this -> ancient_bookstore(EmptyEvent);
                    return;
                }
            } else {
                CLogger_log(Logfile, CLogger_DEBUG, "古代广场=>书籍叫卖: 叫卖成功 被拒绝 退出");
                Global::AncientBookstoreJiaomai::times = 0;
                this -> ancient_bookstore(EmptyEvent);
                return;
            }
        }
    });
    GlobalSignal.BankJuanUseJiFen.connect([=]() {
        CLogger_log(Logfile, CLogger_DEBUG, "积分银行=>积分捐献=>领取奖励=>积分奖励: 槽正确接收");
        this -> bank_juan_use_jifen(EmptyEvent);
    });
    GlobalSignal.BankJuanUseJiFenUse.connect([=](int nd) {
        int Jxq_now = Bank::BankJuanQuan.read_int();
        int Jxq_need = nd;
        int Result = BankJuanUseJiFenUseGetJiFen(Jxq_now, Jxq_need);
        if(Result < 0 ) {
            Simple::Message("兑换积分失败");
            return;
        }
        Bank::BankJuanQuan.minusnum_if(Jxq_need);
        JiFenReader.addnum(Result);
        Simple::Message("兑换积分成功\n此次兑换"+TOSTR(Result)+"积分");
        CLogger_log(Logfile, CLogger_DEBUG, "积分银行=>捐献积分=>领取奖励: 兑换成功");
    });
    GlobalSignal.AncientBookstoreChaoLuAll.connect([=]() {
        CLogger_log(Logfile, CLogger_DEBUG, "古代广场=>书籍使用=>抄录新书: 正确触发槽");
        this -> ancient_bookstore_chaolu(EmptyEvent);
    });
    GlobalSignal.ToolsMdManagerStart.connect([=]() {
        auto frame = new MarkdownToolMainFrame("学习平台 - 笔记管理", wxDefaultPosition, wxSize(600, 600));
    });
}
