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
    glViewport(0, 0, (GLint)GetSize().x, (GLint)GetSize().y);

    glBegin(GL_POLYGON);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2f(0.1, 0.1);
    glVertex2f(-0.1, 0.1);
    glVertex2f(-0.1, -0.1);
    glVertex2f(0.1, -0.1);
    glEnd();

    // using a little of glut
    glColor4f(0,0,1,1);

    glPushMatrix();
    glutWireTeapot(0.4);
    glPopMatrix();

    glFlush();
    SwapBuffers();
}
