#include <headers.hpp>

void MyFrame::acz_lose() {
    int p1 = getrnd(20, 100); // 中级兵
    int p2 = getrnd(10, 40); // 高级兵
    int p3 = getrnd(10, 40); // 神级兵
    Simple::Message("很遗憾，这次出征以失利告终");
    Simple::Message("胜败乃兵家常事");
    Simple::Message(
        "此战结果：\n"
        "黄金-70两\n"
        "中级兵-"+TOSTR(p1)+"\n"
        "高级兵-"+TOSTR(p2)+"\n"
        "神级兵-"+TOSTR(p3)+"\n"
    );
    if(AncientVar::HuangJinReader.high(70)) {
        AncientVar::HuangJinReader.minusnum(70);
    }
}
