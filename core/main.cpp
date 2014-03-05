#include <wx/wx.h>
#include <GL/glut.h>
#include "mainframe.h"

class GTApp: public wxApp {
public:
    virtual bool OnInit();
};

IMPLEMENT_APP(GTApp)

bool GTApp::OnInit(){
    glutInit(&argc, argv);

    new MainFrame(wxT("Hello"));
    return true;
}
