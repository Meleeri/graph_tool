#define GLEW_STATIC

#include "mainframe.h"

using namespace std;


MainFrame::MainFrame(const wxString &title):
    wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(800, 500)),
    m_DirTree(new wxGenericDirCtrl(this, wxID_ANY, wxDirDialogDefaultFolderStr, wxDefaultPosition, wxSize(100, 500), 128L, wxEmptyString, 0, wxTreeCtrlNameStr)),
    m_GTCanvas(new GTCanvas(this, wxSize(500, 500)))
{
    wxMenu *menus[MAINFRAME_MENU_COUNT];
    for (int i = 0; i < MAINFRAME_MENU_COUNT; ++ i){
        menus[i] = new wxMenu;
    }
    menus[0]->Append(wxID_EXIT, wxT("Exit"));

    menus[0]->Bind(wxEVT_COMMAND_MENU_SELECTED, &MainFrame::OnExit, this, wxID_EXIT);

    wxMenuBar *menuBar = new wxMenuBar(MAINFRAME_MENU_COUNT, menus, m_MenuTitles);
    SetMenuBar(menuBar);


    wxBoxSizer *sizerAll = new wxBoxSizer(wxHORIZONTAL);

    wxBoxSizer *sizerLeft = new wxBoxSizer(wxVERTICAL);
    sizerLeft->Add(m_DirTree, 1, wxEXPAND, 0);

    wxBoxSizer *sizerRight = new wxBoxSizer(wxVERTICAL);
    sizerRight->Add(m_GTCanvas, 1, wxEXPAND, 0);

    sizerAll->Add(sizerLeft, 1, wxEXPAND, 0);
    sizerAll->Add(sizerRight, 4, wxEXPAND, 0);

    sizerAll->SetSizeHints(this);
    SetSizer(sizerAll);

    Centre();
    Show(true);
}

void MainFrame::OnExit(wxCommandEvent &event){
   wxMessageBox(wxT("Hello!"));
   exit(0);
}

MainFrame::~MainFrame(){
    delete m_DirTree;
    delete m_GTCanvas;
}




