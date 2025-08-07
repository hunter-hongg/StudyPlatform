#include <headers.hpp>

void MyFrame::lihe(WXBTNEVT&){
    using std::filesystem::exists;
    
    MYINIT();

    MYTITLE("我的礼盒");

    std::vector<LiHe::Types> alllihe;
    if(exists(FilePathLiHe+"xianbibasic_lihe.lihe")){
        alllihe.push_back(LiHe::Types::XianBiBasic);
    }

    if(alllihe.empty()){
      auto button = new wxButton(panel, wxID_ANY, wxT("未发现任何礼盒"));
      button -> SetFont(font17);
      button -> SetForegroundColour(MyRed);
      vbox -> Add(button,FLAG_CENTER);
    } else {
      for(const auto& i : alllihe){
        wxBoxSizer *hbox;
        wxButton *buttoninner1, *buttonuse1;
        switch(i){
        case LiHe::Types::XianBiBasic:
          hbox = new wxBoxSizer(wxHORIZONTAL);
          buttoninner1 = new wxButton(panel, wxID_ANY, wxT("礼盒 - 仙币基础礼盒"));
          buttoninner1 -> SetForegroundColour(MyBlue);
          buttoninner1 -> SetFont(font17);
          hbox -> Add(buttoninner1, FLAG_CENTER);
          buttonuse1 = new wxButton(panel, wxID_ANY, wxT("使用礼盒"));
          if(LiHe::IsUsed::XianBiBasic.CheckOk()){
            buttonuse1 -> Bind(wxEVT_BUTTON, [=](WXBTNEVT& evt){
              
            });
          } else {
            buttoninner1 -> SetForegroundColour(MyOrange);
            buttonuse1 -> SetLabel(wxT("已使用"));
          }
          buttonuse1 -> SetFont(font17);
          buttonuse1 -> SetForegroundColour(MyGrey);
          hbox -> Add(buttonuse1, FLAG_CENTER);
          vbox -> Add(hbox, FLAG_CENTER);
          break;
        default:
          break;
        }
      }
    }   
    
    MYADDSPACER();

    MYLAST(&MyFrame::mine);
}
