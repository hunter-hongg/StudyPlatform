#include <functional>
#include <var.hpp>
#include <type.hpp>

namespace lambda {
static auto xianlu_get_need = [](){
    int now = Files::Xian::Lu::Ji.read_int();
    if(now <= 0) {
        return 0;
    } else if (now <= 20) {
        return 50 + now * 40;
    } else if (now <= 40) {
        return 70 + now * 50;
    } else {
        return 70 + 40 * 50; // 待扩展 
    }
};
static auto anc_wu_bingli_get = [](){
    using namespace AncientVar::WuGuan;
    return 
        LiLiang::Xin.read_int() * BingLi::Xin.read_int() +    
        LiLiang::PuTong.read_int() * BingLi::PuTong.read_int() +    
        LiLiang::ChuJi.read_int() * BingLi::ChuJi.read_int() +    
        LiLiang::ZhongJi.read_int() * BingLi::ZhongJi.read_int() +    
        LiLiang::GaoJi.read_int() * BingLi::GaoJi.read_int() +    
        LiLiang::JingRui.read_int() * BingLi::JingRui.read_int() +    
        LiLiang::WangPai.read_int() * BingLi::WangPai.read_int() +    
        LiLiang::ShenJi.read_int() * BingLi::ShenJi.read_int();    
}
}
