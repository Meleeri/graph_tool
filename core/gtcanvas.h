#ifndef GTCANVAS_H
#define GTCANVAS_H

#include <wx/wx.h>
#include <wx/glcanvas.h>

class GTCanvas: public wxGLCanvas {
public:
    GTCanvas(wxWindow *parent, const wxSize& size);
    ~GTCanvas();
    void OnPaint(wxPaintEvent& event);
    int Render();
private:
};

#endif