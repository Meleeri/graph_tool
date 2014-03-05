#ifndef GTCANVAS_H
#define GTCANVAS_H

#include <wx/glcanvas.h>

class GTCanvas: public wxGLCanvas {
public:
    GTCanvas(wxWindow *parent, const wxSize& size);
    ~GTCanvas();
    void OnPaint(wxPaintEvent& WXUNUSED(event));
    void Render();
private:
    wxGLContext *m_GLContext;
};

#endif