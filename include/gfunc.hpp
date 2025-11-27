#pragma once
#include <optional>
#include <vector>
#include <string>
#include <global.hpp>
#include <func/simple.hpp>
#include <clibs/ancient/ChuZheng.hpp>

namespace gfunc {
static std::string WuGuanChuZhengTrans(WuGuanChuZheng::Choices t) {
    using namespace WuGuanChuZheng;
    switch(t) {
    case Choices::JinGong:
        return "进攻敌方";
        break;
    case Choices::XiuZheng:
        return "休整兵马";
        break;
    case Choices::FangShou:
        return "防御敌军";
        break;
    default:
        return "趁其不备";
        break;
    }
}
static std::vector<int> WuGuanChuZhengFunc(WuGuanChuZheng::Choices cho,
        int bingls, int binglo) {
    using namespace WuGuanChuZheng;
    using Global::AncientWuGuanChuZhengReal::usr_cho;
    usr_cho.push_back(cho);
    Choices ComputerChoice = GetChoice(binglo, bingls, usr_cho);
    Choices UserChoice = cho;
    Simple::Message(
        "你的选择: "+WuGuanChuZhengTrans(UserChoice)+"\n"+
        "电脑选择: "+WuGuanChuZhengTrans(ComputerChoice)
    );
    std::vector<int> res = GetResult(UserChoice, ComputerChoice);
    Simple::Message(
        "你的兵力增加 ("+TOSTR(res[0])+")\n"+
        "电脑兵力增加 ("+TOSTR(res[1])+")"
    );
    using Global::AncientWuGuanChuZhengReal::bingl_sf_now;
    using Global::AncientWuGuanChuZhengReal::bingl_ot_now;
    bingl_sf_now += res[0];
    bingl_ot_now += res[1];
    return res;
}
static std::string AncientBookTrans(int BookType) {
    switch(BookType) {
    case 1:
        return "普通书籍";
        break;
    case 2:
        return "珍贵书籍";
        break;
    case 3:
        return "典藏书籍";
        break;
    default:
        return "未知书籍";
    }
}
}
