#include <functional>
#include <var.hpp>
#include <type.hpp>

namespace lambda {
auto xianlu_get_need = [=](){
    int now = Xian::Lu::Ji.read_int();
    if(now <= 0) {
        return 0;
    } else if (now <= 20) {
        return 50 + now * 40;
    } else if (now <= 40) {
        return 70 + now * 50;
    } else {
        return 70 + 40 * 50; // 待扩展 
    }
}
}
