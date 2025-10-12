#pragma once 
#include <vector>
#include <string>
#include <global.hpp>
#include <func/simple.hpp>
#include <clibs/ancient/ChuZheng.hpp>

namespace gfunc {
static std::string WuGuanChuZhengTrans(WuGuanChuZheng::Choices t){
    using namespace WuGuanChuZheng;
    switch(t) {
        case Choices::JinGong: return "进攻敌方"; break; 
        case Choices::XiuZheng: return "修整兵马"; break; 
        case Choices::FangShou: return "防御敌军"; break;
        default: return "趁其不备"; break; 
    }
}
static std::vector<int> WuGuanChuZhengFunc(WuGuanChuZheng::Choices cho, 
                                    int bingls, int binglo){
    using namespace WuGuanChuZheng;
    Choices ComputerChoice = GetChoice(binglo, bingls);
    Choices UserChoice = cho;
    Simple::Message(
        "你的选择: "+WuGuanChuZhengTrans(UserChoice)+"\n"+
        "电脑选择: "+WuGuanChuZhengTrans(ComputerChoice)
    );
}
}
