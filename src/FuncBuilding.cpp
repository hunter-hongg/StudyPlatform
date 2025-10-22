#include <headers.hpp>

void MyFrame::acz_win(){
    int p1 = getrnd(20, 40); // 中级兵
    int p2 = getrnd(5, 10); // 高级兵
    int p3 = getrnd(0, 3); // 神级兵
    Simple::Message("恭喜你，这次出征大获全胜");
    Simple::Message("胜不骄，败不馁");
    Simple::Message(
        "此战结果：\n"
        "黄金+20两\n"
        "中级兵+"+TOSTR(p1)+"\n"
        "高级兵+"+TOSTR(p2)+"\n"
        "神级兵+"+TOSTR(p3)+"\n"
    );
}
void MyFrame::acz_lose(){
    Simple::Message("很遗憾，这次出征以失利告终");
    Simple::Message("胜败乃兵家常事");
    Simple::Message(
        "此战结果：\n"
    );
}
