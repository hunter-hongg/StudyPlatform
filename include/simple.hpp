#pragma once
#include <wx/wx.h>
#include <type.hpp>
#include <mine/MyFonts.h>
#include <mine/MyFlags.h>
#define fn auto
namespace Simple{
  template<typename T>
  static fn Button(void(T::*fptr)(WXBTNEVT&), std::string value,
                   wxPanel* panel, wxBoxSizer* vbox, T* self) -> wxButton* {
    auto btn = new wxButton(panel, wxID_ANY, wxString::FromUTF8(value));
    btn -> SetFont(font17); 
    btn -> Bind(wxEVT_BUTTON,fptr,self); 
    vbox -> Add(btn,FLAG_CENTER);
    return btn;
  }
  static fn ShopButton(std::string value, wxPanel* panel,
                       wxColour colour ) -> wxButton* {
    auto btn = new wxButton(panel, wxID_ANY, wxString::FromUTF8(value));
    btn -> SetForegroundColour(colour);
    btn -> SetFont(font17);
    return btn;
  }
  template<typename T>
  static fn Init(wxPanel* panel, T* self) -> wxBoxSizer* {
    self->clean_panel(); 
    return new wxBoxSizer(wxVERTICAL); 
  }
}
    
