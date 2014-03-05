#include <wx/wx.h>
#include "mainframe.h"

class GTApp: public wxApp {
public:
    virtual bool OnInit();
};

IMPLEMENT_APP(GTApp)

bool GTApp::OnInit(){
    new MainFrame(wxT("Hello"));
    return true;
}