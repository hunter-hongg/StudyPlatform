#pragma once
#include "type.hpp"
#include <wx/event.h>
#include <wx/wx.h>
#include <string>
#include <markdown_sqlite.hpp>

typedef wxCommandEvent WXBTNEVT;

class MarkdownToolMainFrame : public wxFrame
{
public:
    MarkdownToolMainFrame(const wxString& title, const wxPoint& pos, const wxSize& size);
    void clean_panel();
private:
    wxPanel* panel;
    MSQLite::Database db_;

    void connect_db();

    void start_panel(WXBTNEVT&);
    void add_markdown(WXBTNEVT&);
    void search_markdown(WXBTNEVT&);
    void show_markdown(std::string);
};

