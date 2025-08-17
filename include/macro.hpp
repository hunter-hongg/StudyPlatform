#pragma once
#include <utils/cast.hpp>
#include <type.hpp>
#include <mine/MyColour.h>
static void emptything() {;}
#define MYINIT() \
                this->clean_panel(); \
                auto vbox = new wxBoxSizer(wxVERTICAL); \
                emptything()
#define MYADDSPACER() \
                vbox -> AddStretchSpacer(); \
                emptything()
#define MYUSE() \
                panel -> SetSizer(vbox); \
                panel -> Layout(); \
                emptything()
#define MYBUTTON(name,function,show) \
                auto name = new wxButton(panel,wxID_ANY,wxT(show)); \
                name -> SetFont(font17); \
                name -> Bind(wxEVT_BUTTON,function,this); \
                vbox -> Add(name,FLAG_CENTER); \
                emptything()
#define MYBUTTONLAMBDA(name,function,show) \
                auto name = new wxButton(panel,wxID_ANY,wxT(show)); \
                name -> SetFont(font17); \
                name -> Bind(wxEVT_BUTTON,function); \
                vbox -> Add(name,FLAG_CENTER); \
                emptything()
#define MYTITLE(titlea) \
                auto title = new wxStaticText(panel,wxID_ANY,wxT(titlea)); \
                title -> SetFont(font25); \
                vbox -> Add(title,FLAG_CENTER); \
                vbox -> AddStretchSpacer(); \
                emptything()
#define MYBACK(function,usethis) \
                auto back_button = new wxButton(panel,wxID_ANY,wxT("返回")); \
                back_button -> SetFont(font15); \
                back_button -> Bind(wxEVT_BUTTON,function,this); \
                vbox -> Add(back_button, FLAG_RIGHT); \
                vbox -> AddStretchSpacer(); \
                emptything()
#define MYLAST(function) \
                auto back_button = new wxButton(panel,wxID_ANY,wxT("返回")); \
                back_button -> SetFont(font15); \
                back_button -> Bind(wxEVT_BUTTON,function,this); \
                vbox -> Add(back_button, FLAG_RIGHT); \
                vbox -> AddStretchSpacer(); \
                panel -> SetSizer(vbox); \
                panel -> Layout(); \
                emptything()
#define MYEND(function) \
                vbox -> AddStretchSpacer();
                auto back_button = new wxButton(panel,wxID_ANY,wxT("返回")); \
                back_button -> SetFont(font15); \
                back_button -> Bind(wxEVT_BUTTON,function,this); \
                vbox -> Add(back_button, FLAG_RIGHT); \
                vbox -> AddStretchSpacer(); \
                panel -> SetSizer(vbox); \
                panel -> Layout(); \
                emptything()
#define MYBACKTOMAIN() \
                auto back_button = new wxButton(panel,wxID_ANY,wxT("返回")); \
                back_button -> SetFont(font15); \
                back_button -> Bind(wxEVT_BUTTON,[this](WXBTNEVT& evt){ \
                    this->start(); \
                }); \
                vbox -> Add(back_button, FLAG_RIGHT); \
                vbox -> AddStretchSpacer(); \
                emptything()
#define MYMESSAGE(message) \
                wxMessageBox(wxT(message)); \
                emptything()
#define MYSTRMESSAGE(message) \
                wxMessageBox(message); \
                emptything()
#define TOSTR(a) lexical_cast<std::string>(a)
#define MYSHOW(thing) \
                auto show = new wxButton(panel,wxID_ANY,thing); \
                show->SetFont(font15); \
                show->SetForegroundColour(MyBlue); \
                vbox->Add(show,FLAG_CENTER); \
                vbox->AddStretchSpacer(); \
                emptything()
#define MYTITLENS(titlea) \
                auto title = new wxStaticText(panel,wxID_ANY,wxT(titlea)); \
                title -> SetFont(font25); \
                vbox -> Add(title,FLAG_CENTER); \
                emptything()
#define MYSHOWNSNCM(thing,varname) \
                auto varname = new wxButton(panel,wxID_ANY,thing); \
                varname->SetFont(font15); \
                vbox->Add(varname,FLAG_CENTER); \
                emptything()
#define MYSHOWNSNCNBM(thing,varname) \
                auto varname = new wxButton(panel,wxID_ANY,thing); \
                varname->SetFont(font15); \
                emptything()
#define MYSHOWNSNBM(thing,varname,colour) \
                auto varname = new wxButton(panel,wxID_ANY,thing); \
                varname->SetFont(font15); \
                varname->SetForegroundColour(colour); \
                emptything()
#define MYSHOPBUTTON(button,color) \
                button -> SetForegroundColour(color); \
                button -> SetFont(font17); \
                emptything()
#define oldblock
#define membervar(type)
#define interim
