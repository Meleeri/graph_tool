#ifndef MAINFRAME_H
#define MAINFRAME_H

#include <wx/wx.h>
#include <wx/dirctrl.h>
#include "gtcanvas.h"

#define MAINFRAME_MENU_COUNT 2

class MainFrame: public wxFrame {
public:
    MainFrame(const wxString& title);
    ~MainFrame();
private:
    void OnExit(wxCommandEvent &event);

    wxString m_MenuTitles[MAINFRAME_MENU_COUNT] = {
      "File",
      "About"
    };

    GTCanvas *m_GTCanvas;
    wxGenericDirCtrl *m_DirTree;

};

#endif // MAINFRAME_H
