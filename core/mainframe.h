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
    void OnExit(wxCommandEvent &event);

    GTCanvas *m_GTCanvas;
    wxGenericDirCtrl *m_DirTree;

};

#endif // MAINFRAME_H
