#define GLEW_STATIC
#include <GL/glew.h>
#define FREEGLUT_STATIC
#include <GL/glut.h>

#include <wx/wx.h>

#include "gtcanvas.h"
#include "glutil.h"

GTCanvas::GTCanvas(wxWindow *window, const wxSize& size):
	wxGLCanvas(window, wxID_ANY, (const int*)0, wxDefaultPosition, size, wxFULL_REPAINT_ON_RESIZE, L"GLCanvas", wxNullPalette) 
{
    m_GLContext = new wxGLContext(this);
    Bind(wxEVT_PAINT, &GTCanvas::OnPaint, this);
}

GTCanvas::~GTCanvas(){
    delete m_GLContext;
}

void GTCanvas::OnPaint(wxPaintEvent& WXUNUSED(event)){
    Render();
}

int GTCanvas::Render(){
    wxPaintDC(this);
    if(!GetContext()){
        wxMessageBox(wxT("Initializing wxGL Failed!"));
        return -1;
	}
    SetCurrent();

    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glViewport(0, 0, (GLint)GetSize().x, (GLint)GetSize().y);
    glBegin(GL_POLYGON);
    glColor3f(1.0F, 0.0F, 0.0F);
    glVertex2f(0.1F, 0.1F);
    glVertex2f(-0.1F, 0.1F);
    glVertex2f(-0.1F, -0.1F);
    glVertex2f(0.1F, -0.1F);
    glEnd();

// using a little of glut
    glColor4f(0,0,1,1);
    glutWireTeapot(0.4);

    glPopMatrix();

    glFlush();
    SwapBuffers();
    return 0;
}