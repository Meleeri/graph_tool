#include <wx/wx.h>
#include "mainframe.h"

class GTApp: public wxApp {
public:
    virtual bool OnInit();
};

IMPLEMENT_APP(GTApp)

bool GTApp::OnInit(){
    MainFrame *mainframe = new MainFrame(wxT("Hello"));

    mainframe->Show(true);
    mainframe->InitGL();
    return true;
}
