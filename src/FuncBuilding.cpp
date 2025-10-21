#include <headers.hpp>

void MyFrame::acz_win(){
    Simple::Message("恭喜你，这次出征大获全胜");
    Simple::Message("胜不骄，败不馁");
    Simple::Message(
        "此战结果：\n"
    );
}
void MyFrame::acz_lose(){
    Simple::Message("很遗憾，这次出征以失利告终");
    Simple::Message("胜败乃兵家常事");
    Simple::Message(
        "此战结果：\n"
    );
}
