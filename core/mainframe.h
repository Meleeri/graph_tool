#ifndef MAINFRAME_H
#define MAINFRAME_H

#include <wx/wx.h>
#include <wx/dirctrl.h>

#include "gtcanvas.h"

class MainFrame: public wxFrame {
public:
    MainFrame(const wxString& title);
    ~MainFrame();
private:
    wxBoxSizer *m_SizerAll;
    wxBoxSizer *m_SizerLeft;
    wxBoxSizer *m_SizerRight;

    GTCanvas *m_GTCanvas;
    wxGLContext *m_GLContext;
    wxGenericDirCtrl *m_DirTree;
};

#endif // MAINFRAME_H
