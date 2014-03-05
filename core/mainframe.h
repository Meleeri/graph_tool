#ifndef MAINFRAME_H
#define MAINFRAME_H

#include <wx/wx.h>
#include <wx/dirctrl.h>
#include <wx/glcanvas.h>

class MainFrame: public wxFrame {
public:
    MainFrame(const wxString& title);
    ~MainFrame();

    int InitGL();
private:
    wxBoxSizer *m_SizerAll;
    wxBoxSizer *m_SizerLeft;
    wxBoxSizer *m_SizerRight;

    wxGLCanvas *m_GLCanvas;
    wxGLContext *m_GLContext;
    wxGenericDirCtrl *m_DirTree;
};

#endif // MAINFRAME_H
