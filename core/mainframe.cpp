#define GLEW_STATIC

#include "mainframe.h"

using namespace std;


MainFrame::MainFrame(const wxString &title):
    wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(800, 500))
{
	wxBoxSizer *m_SizerAll = new wxBoxSizer(wxHORIZONTAL);

    wxBoxSizer *m_SizerLeft = new wxBoxSizer(wxVERTICAL);
    m_DirTree = new wxGenericDirCtrl(this, wxID_ANY, wxDirDialogDefaultFolderStr, wxDefaultPosition, wxSize(100, 500), 128L, wxEmptyString, 0, wxTreeCtrlNameStr);
    m_SizerLeft->Add(m_DirTree, 1, wxEXPAND, 0);

    wxBoxSizer *m_SizerRight = new wxBoxSizer(wxVERTICAL);
    m_GTCanvas = new GTCanvas(this, wxSize(500, 500));
    m_SizerRight->Add(m_GTCanvas, 1, wxEXPAND, 0);

	m_SizerAll->Add(m_SizerLeft, 1, wxEXPAND, 0);
    m_SizerAll->Add(m_SizerRight, 4, wxEXPAND, 0);

	m_SizerAll->SetSizeHints(this);
    SetSizer(m_SizerAll);

    Centre();
    Show(true);
}

MainFrame::~MainFrame(){
    delete m_DirTree;
    delete m_GTCanvas;
}




