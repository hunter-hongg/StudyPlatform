#pragma once
#include <wx/wx.h>
#include <type.hpp>
#include <mine/MyFonts.h>
#include <mine/MyFlags.h>
#include <mine/MyColour.h>
#define fn auto
namespace Simple{
  // ------------------------------------------------------------------------------
  template<typename T>
  static fn Button(void(T::*fptr)(WXBTNEVT&), std::string value,
                   wxPanel* panel, wxBoxSizer* vbox, T* self) -> wxButton* {
    auto btn = new wxButton(panel, wxID_ANY, wxString::FromUTF8(value));
    btn -> SetFont(font17); 
    btn -> Bind(wxEVT_BUTTON,fptr,self); 
    vbox -> Add(btn,FLAG_CENTER);
    return btn;
  }
  static fn ShowButton(std::string showt, wxPanel* panel,
                       wxBoxSizer* vbox) -> wxButton* {
    auto show = new wxButton(panel,wxID_ANY,wxString::FromUTF8(showt)); 
    show->SetFont(font15); 
    show->SetForegroundColour(MyBlue); 
    vbox->Add(show,FLAG_CENTER); 
    vbox->AddStretchSpacer();
    return show;
  }
  static fn ShopButton(std::string value, wxPanel* panel,
                       wxColour colour ) -> wxButton* {
    auto btn = new wxButton(panel, wxID_ANY, wxString::FromUTF8(value));
    btn -> SetForegroundColour(colour);
    btn -> SetFont(font17);
    return btn;
  }
  template<typename T>
  static fn BackButton(void(T::*fptr)(WXBTNEVT&), wxPanel* panel,
                       wxBoxSizer* vbox, T* self) -> void {
    vbox -> AddStretchSpacer(); 
    auto back_button = new wxButton(panel,wxID_ANY,wxT("返回")); 
    back_button -> SetFont(font15); 
    back_button -> Bind(wxEVT_BUTTON,fptr,self); 
    vbox -> Add(back_button, FLAG_RIGHT); 
    vbox -> AddStretchSpacer(); 
    panel -> SetSizer(vbox); 
    panel -> Layout();
  }
  // ---------------------------------------------------------------------------------
  template<typename T>
  static fn Init(wxPanel* panel, T* self) -> wxBoxSizer* {
    self->clean_panel(); 
    return new wxBoxSizer(wxVERTICAL); 
  }
  static fn Title(std::string titlea, wxPanel* panel,
                  wxBoxSizer* vbox) -> void {
    auto title = new wxStaticText(panel,wxID_ANY,wxString::FromUTF8(titlea)); 
    title -> SetFont(font25);
    vbox -> Add(title,FLAG_CENTER); 
    vbox -> AddStretchSpacer();
  }
  static fn TitleNoSpacer(std::string titlea, wxPanel* panel,
                  wxBoxSizer* vbox) -> void {
    auto title = new wxStaticText(panel,wxID_ANY,wxString::FromUTF8(titlea)); 
    title -> SetFont(font25);
    vbox -> Add(title,FLAG_CENTER);
  }
  // -------------------------------------------------------------------------------
  static fn Message(std::string msg) -> void {
    wxMessageBox(wxString::FromUTF8(msg));
  }
}
    
