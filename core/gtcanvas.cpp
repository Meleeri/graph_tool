#define FREEGLUT_STATIC
#include <GL/glut.h>

#include <wx/wx.h>

#include "gtcanvas.h"

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

void GTCanvas::Render(){
    wxPaintDC dc(this);
    SetCurrent(*m_GLContext);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glBegin(GL_QUADS);
    glNormal3f(0.0f, 0.0f, 1.0f);
    glVertex3f(0.5f, 0.5f, 0.5f); glVertex3f(-0.5f, 0.5f, 0.5f);
    glVertex3f(-0.5f, -0.5f, 0.5f); glVertex3f(0.5f, -0.5f, 0.5f);

    glNormal3f(0.0f, 0.0f, -1.0f);
    glVertex3f(-0.5f, -0.5f, -0.5f); glVertex3f(-0.5f, 0.5f, -0.5f);
    glVertex3f(0.5f, 0.5f, -0.5f); glVertex3f(0.5f, -0.5f, -0.5f);

    glNormal3f(0.0f, 1.0f, 0.0f);
    glVertex3f(0.5f, 0.5f, 0.5f); glVertex3f(0.5f, 0.5f, -0.5f);
    glVertex3f(-0.5f, 0.5f, -0.5f); glVertex3f(-0.5f, 0.5f, 0.5f);

    glNormal3f(0.0f, -1.0f, 0.0f);
    glVertex3f(-0.5f, -0.5f, -0.5f); glVertex3f(0.5f, -0.5f, -0.5f);
    glVertex3f(0.5f, -0.5f, 0.5f); glVertex3f(-0.5f, -0.5f, 0.5f);

    glNormal3f(1.0f, 0.0f, 0.0f);
    glVertex3f(0.5f, 0.5f, 0.5f); glVertex3f(0.5f, -0.5f, -0.5f);
    glVertex3f(0.5f, -0.5f, -0.5f); glVertex3f(0.5f, 0.5f, -0.5f);

    glNormal3f(-1.0f, 0.0f, 0.0f);
    glVertex3f(-0.5f, -0.5f, -0.5f); glVertex3f(-0.5f, -0.5f, 0.5f);
    glVertex3f(-0.5f, 0.5f, 0.5f); glVertex3f(-0.5f, 0.5f, -0.5f);
    glEnd();
    glFlush();
    SwapBuffers();
}