/////////////////////////////////////////////////////////////////////////////
// Name:        src/msw/glcanvas.cpp
// Purpose:     wxGLCanvas, for using OpenGL with wxWidgets under MS Windows
// Author:      Julian Smart
// Modified by:
// Created:     04/01/98
// RCS-ID:      $Id: glcanvas.cpp,v 1.1.1.1 2005/07/06 09:30:54 gully Exp $
// Copyright:   (c) Julian Smart
// Licence:     wxWindows licence
/////////////////////////////////////////////////////////////////////////////

#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
#pragma implementation "glcanvas.h"
#endif

#include "wx/wxprec.h"

#if defined(__BORLANDC__)
#pragma hdrstop
#endif

#if wxUSE_GLCANVAS

#ifndef WX_PRECOMP
    #include "wx/frame.h"
    #include "wx/settings.h"
    #include "wx/intl.h"
    #include "wx/log.h"
    #include "wx/app.h"
#endif

#include "wx/module.h"

#include "wx/msw/private.h"

// DLL options compatibility check:
#include "wx/build.h"
WX_CHECK_BUILD_OPTIONS("wxGL")

#include "wx/glcanvas.h"

#if GL_EXT_vertex_array
    #define WXUNUSED_WITHOUT_GL_EXT_vertex_array(name) name
#else
    #define WXUNUSED_WITHOUT_GL_EXT_vertex_array(name) WXUNUSED(name)
#endif

/*
  The following two compiler directives are specific to the Microsoft Visual
  C++ family of compilers

  Fundementally what they do is instruct the linker to use these two libraries
  for the resolution of symbols. In essence, this is the equivalent of adding
  these two libraries to either the Makefile or project file.

  This is NOT a recommended technique, and certainly is unlikely to be used
  anywhere else in wxWidgets given it is so specific to not only wxMSW, but
  also the VC compiler. However, in the case of opengl support, it's an
  applicable technique as opengl is optional in setup.h This code (wrapped by
  wxUSE_GLCANVAS), now allows opengl support to be added purely by modifying
  setup.h rather than by having to modify either the project or DSP fle.

  See MSDN for further information on the exact usage of these commands.
*/
#ifdef _MSC_VER
#  pragma comment( lib, "opengl32" )
#  pragma comment( lib, "glu32" )
#endif


static const wxChar *wxGLCanvasClassName = wxT("wxGLCanvasClass");
static const wxChar *wxGLCanvasClassNameNoRedraw = wxT("wxGLCanvasClassNR");

LRESULT WXDLLEXPORT APIENTRY _EXPORT wxWndProc(HWND hWnd, UINT message,
                                   WPARAM wParam, LPARAM lParam);

// ----------------------------------------------------------------------------
// wxGLModule is responsible for unregistering wxGLCanvasClass Windows class
// ----------------------------------------------------------------------------

class wxGLModule : public wxModule
{
public:
    bool OnInit() { return true; }
    void OnExit() { UnregisterClasses(); }

    // register the GL classes if not done yet, return true if ok, false if
    // registration failed
    static bool RegisterClasses();

    // unregister the classes, done automatically on program termination
    static void UnregisterClasses();

private:
    // wxGLCanvas is only used from the main thread so this is MT-ok
    static bool ms_registeredGLClasses;

    DECLARE_DYNAMIC_CLASS(wxGLModule)
};

IMPLEMENT_DYNAMIC_CLASS(wxGLModule, wxModule)

bool wxGLModule::ms_registeredGLClasses = false;

/* static */
bool wxGLModule::RegisterClasses()
{
    if (ms_registeredGLClasses)
        return true;

    // We have to register a special window class because we need the CS_OWNDC
    // style for GLCanvas.

  /*
  From Angel Popov <jumpo@bitex.com>

  Here are two snips from a dicussion in the OpenGL Gamedev list that explains
  how this problem can be fixed:

  "There are 5 common DCs available in Win95. These are aquired when you call
  GetDC or GetDCEx from a window that does _not_ have the OWNDC flag.
  OWNDC flagged windows do not get their DC from the common DC pool, the issue
  is they require 800 bytes each from the limited 64Kb local heap for GDI."

  "The deal is, if you hold onto one of the 5 shared DC's too long (as GL apps
  do), Win95 will actually "steal" it from you.  MakeCurrent fails,
  apparently, because Windows re-assigns the HDC to a different window.  The
  only way to prevent this, the only reliable means, is to set CS_OWNDC."
  */

    WNDCLASS wndclass;

    // the fields which are common to all classes
    wndclass.lpfnWndProc   = (WNDPROC)wxWndProc;
    wndclass.cbClsExtra    = 0;
    wndclass.cbWndExtra    = sizeof( DWORD ); // VZ: what is this DWORD used for?
    wndclass.hInstance     = wxhInstance;
    wndclass.hIcon         = (HICON) NULL;
    wndclass.hCursor       = ::LoadCursor((HINSTANCE)NULL, IDC_ARROW);
    wndclass.lpszMenuName  = NULL;

    // Register the GLCanvas class name
    wndclass.hbrBackground = (HBRUSH)NULL;
    wndclass.lpszClassName = wxGLCanvasClassName;
    wndclass.style         = CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS | CS_OWNDC;

    if ( !::RegisterClass(&wndclass) )
    {
        wxLogLastError(wxT("RegisterClass(wxGLCanvasClass)"));
        return false;
    }

    // Register the GLCanvas class name for windows which don't do full repaint
    // on resize
    wndclass.lpszClassName = wxGLCanvasClassNameNoRedraw;
    wndclass.style        &= ~(CS_HREDRAW | CS_VREDRAW);

    if ( !::RegisterClass(&wndclass) )
    {
        wxLogLastError(wxT("RegisterClass(wxGLCanvasClassNameNoRedraw)"));

        ::UnregisterClass(wxGLCanvasClassName, wxhInstance);

        return false;
    }

    ms_registeredGLClasses = true;

    return true;
}

/* static */
void wxGLModule::UnregisterClasses()
{
    // we need to unregister the classes in case we're in a DLL which is
    // unloaded and then loaded again because if we don't, the registration is
    // going to fail in wxGLCanvas::Create() the next time we're loaded
    if ( ms_registeredGLClasses )
    {
        ::UnregisterClass(wxGLCanvasClassName, wxhInstance);
        ::UnregisterClass(wxGLCanvasClassNameNoRedraw, wxhInstance);

        ms_registeredGLClasses = false;
    }
}

/*
 * GLContext implementation
 */

wxGLContext::wxGLContext(bool WXUNUSED(isRGB), wxGLCanvas *win, const wxPalette& WXUNUSED(palette))
{
  m_window = win;

  m_hDC = win->GetHDC();

  m_glContext = wglCreateContext((HDC) m_hDC);
  wxCHECK_RET( m_glContext, wxT("Couldn't create OpenGL context") );

  wglMakeCurrent((HDC) m_hDC, m_glContext);
}

wxGLContext::wxGLContext(
               bool WXUNUSED(isRGB), wxGLCanvas *win,
               const wxPalette& WXUNUSED(palette),
               const wxGLContext *other  /* for sharing display lists */
             )
{
  m_window = win;

  m_hDC = win->GetHDC();

  m_glContext = wglCreateContext((HDC) m_hDC);
  wxCHECK_RET( m_glContext, wxT("Couldn't create OpenGL context") );

  if( other != 0 )
    wglShareLists( other->m_glContext, m_glContext );

  wglMakeCurrent((HDC) m_hDC, m_glContext);
}

wxGLContext::~wxGLContext()
{
  if (m_glContext)
  {
    wglMakeCurrent(NULL, NULL);
    wglDeleteContext(m_glContext);
  }
}

void wxGLContext::SwapBuffers()
{
  if (m_glContext)
  {
    wglMakeCurrent((HDC) m_hDC, m_glContext);
    ::SwapBuffers((HDC) m_hDC);    //blits the backbuffer into DC
  }
}

void wxGLContext::SetCurrent()
{
  if (m_glContext)
  {
    wglMakeCurrent((HDC) m_hDC, m_glContext);
  }
}

void wxGLContext::SetColour(const wxChar *colour)
{
    wxColour col = wxTheColourDatabase->Find(colour);
    if (col.Ok())
    {
        float r = (float)(col.Red()/256.0);
        float g = (float)(col.Green()/256.0);
        float b = (float)(col.Blue()/256.0);
        glColor3f( r, g, b);
    }
}


/*
 * wxGLCanvas implementation
 */

IMPLEMENT_CLASS(wxGLCanvas, wxWindow)

BEGIN_EVENT_TABLE(wxGLCanvas, wxWindow)
    EVT_SIZE(wxGLCanvas::OnSize)
    EVT_PALETTE_CHANGED(wxGLCanvas::OnPaletteChanged)
    EVT_QUERY_NEW_PALETTE(wxGLCanvas::OnQueryNewPalette)
END_EVENT_TABLE()

wxGLCanvas::wxGLCanvas(wxWindow *parent, wxWindowID id,
    const wxPoint& pos, const wxSize& size, long style, const wxString& name,
    int *attribList, const wxPalette& palette) : wxWindow()
{
  m_glContext = (wxGLContext*) NULL;

  bool ret = Create(parent, id, pos, size, style, name);

  if ( ret )
  {
    SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_3DFACE));
  }

  m_hDC = (WXHDC) ::GetDC((HWND) GetHWND());

  SetupPixelFormat(attribList);
  SetupPalette(palette);

  m_glContext = new wxGLContext(true, this, palette);
}

wxGLCanvas::wxGLCanvas( wxWindow *parent,
              const wxGLContext *shared, wxWindowID id,
              const wxPoint& pos, const wxSize& size, long style, const wxString& name,
              int *attribList, const wxPalette& palette )
  : wxWindow()
{
  m_glContext = (wxGLContext*) NULL;

  bool ret = Create(parent, id, pos, size, style, name);

  if ( ret )
  {
    SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_3DFACE));
  }

  m_hDC = (WXHDC) ::GetDC((HWND) GetHWND());

  SetupPixelFormat(attribList);
  SetupPalette(palette);

  m_glContext = new wxGLContext(true, this, palette, shared );
}

// Not very useful for wxMSW, but this is to be wxGTK compliant

wxGLCanvas::wxGLCanvas( wxWindow *parent, const wxGLCanvas *shared, wxWindowID id,
                        const wxPoint& pos, const wxSize& size, long style, const wxString& name,
                        int *attribList, const wxPalette& palette ):
  wxWindow()
{
  m_glContext = (wxGLContext*) NULL;

  bool ret = Create(parent, id, pos, size, style, name);

  if ( ret )
  {
    SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_3DFACE));
  }

  m_hDC = (WXHDC) ::GetDC((HWND) GetHWND());

  SetupPixelFormat(attribList);
  SetupPalette(palette);

  wxGLContext *sharedContext=0;
  if (shared) sharedContext=shared->GetContext();
  m_glContext = new wxGLContext(true, this, palette, sharedContext );
}

wxGLCanvas::~wxGLCanvas()
{
  delete m_glContext;

  ::ReleaseDC((HWND) GetHWND(), (HDC) m_hDC);
}

// Replaces wxWindow::Create functionality, since we need to use a different
// window class
bool wxGLCanvas::Create(wxWindow *parent,
                        wxWindowID id,
                        const wxPoint& pos,
                        const wxSize& size,
                        long style,
                        const wxString& name)
{
    wxCHECK_MSG( parent, false, wxT("can't create wxWindow without parent") );

    if ( !wxGLModule::RegisterClasses() )
    {
        wxLogError(_("Failed to register OpenGL window class."));

        return false;
    }

    if ( !CreateBase(parent, id, pos, size, style, wxDefaultValidator, name) )
        return false;

    parent->AddChild(this);

    DWORD msflags = 0;

    /*
       A general rule with OpenGL and Win32 is that any window that will have a
       HGLRC built for it must have two flags:  WS_CLIPCHILDREN & WS_CLIPSIBLINGS.
       You can find references about this within the knowledge base and most OpenGL
       books that contain the wgl function descriptions.
     */

    WXDWORD exStyle = 0;
    msflags |= WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN;
    msflags |= MSWGetStyle(style, & exStyle) ;

    return MSWCreate(wxGLCanvasClassName, NULL, pos, size, msflags, exStyle);
}

// The following code uses a gamer's heuristics to choose a suitable pixel format
// c.f. http://www.wischik.com/lu/programmer/wingl.html#accelerated
//  bpp   -> -1 don't care. (or a positive integer)
//  depth -> -1 don't care. (or a positive integer)
//  dbl   -> we want double-buffering. (or -1 for 'don't care', or 0 for 'none')
//  acc   -> we want acceleration. (or -1 or 0)
static int ChoosePixelFormatEx( HDC hdc,
                                int *p_bpp,
                                int *p_depth,
                                int *p_dbl,
                                int *p_acc,
                                PIXELFORMATDESCRIPTOR *p_pfd )
{
    int wbpp;
    if (p_bpp == NULL)
        wbpp = -1;
    else
        wbpp = *p_bpp;
    int wdepth;
    if (p_depth == NULL)
        wdepth = 16;
    else
        wdepth = *p_depth;
    int wdbl;
    if (p_dbl == NULL)
        wdbl = -1;
    else 
        wdbl = *p_dbl;
    int wacc;
    if (p_acc == NULL)
        wacc = 1;
    else
        wacc = *p_acc;
  
    // get total numbers of available pfd
    PIXELFORMATDESCRIPTOR pfd;
    ZeroMemory(&pfd, sizeof(pfd));
    pfd.nSize = sizeof(pfd);
    pfd.nVersion = 1;
    int num = DescribePixelFormat(hdc, 1, sizeof(pfd), &pfd);
    if (num == 0)
        return 0;
  
    // loop on available pfd and search for the best one
    unsigned int maxqual = 0; int maxindex = 0;
    int max_bpp = 0, max_depth = 0, max_dbl = 0, max_acc = 0;
    PIXELFORMATDESCRIPTOR max_pfd;
    ZeroMemory(&max_pfd, sizeof(max_pfd));
    for (int i = 1; i <= num; i++)
    {
        ZeroMemory(&pfd, sizeof(pfd));
        pfd.nSize = sizeof(pfd);
        pfd.nVersion = 1;
        DescribePixelFormat(hdc, i, sizeof(pfd), &pfd);
        int bpp = pfd.cColorBits;
        int depth = pfd.cDepthBits;
        bool pal = (pfd.iPixelType == PFD_TYPE_COLORINDEX);
        bool mcd = ((pfd.dwFlags & PFD_GENERIC_FORMAT) && (pfd.dwFlags & PFD_GENERIC_ACCELERATED));
        bool soft = ((pfd.dwFlags & PFD_GENERIC_FORMAT) && !(pfd.dwFlags & PFD_GENERIC_ACCELERATED));
        bool icd = (!(pfd.dwFlags & PFD_GENERIC_FORMAT) && !(pfd.dwFlags & PFD_GENERIC_ACCELERATED));
        bool opengl = (pfd.dwFlags & PFD_SUPPORT_OPENGL) != 0;
        bool window = (pfd.dwFlags & PFD_DRAW_TO_WINDOW) != 0;
        bool bitmap = (pfd.dwFlags & PFD_DRAW_TO_BITMAP) != 0;
        bool dbuff = (pfd.dwFlags & PFD_DOUBLEBUFFER) != 0;
        // calculate the heuristic
        unsigned int q = 0;
        if (opengl && window) q=q+0x8000;
        if (wdepth==-1 || (wdepth>0 && depth>0)) q=q+0x4000;
        if (wdbl==-1 || (wdbl==0 && !dbuff) || (wdbl==1 && dbuff)) q=q+0x2000;
        if (wacc==-1 || (wacc==0 && soft) || (wacc==1 && (mcd || icd))) q=q+0x1000;
        if (mcd || icd) q=q+0x0040; if (icd) q=q+0x0002;
        if (wbpp==-1 || (wbpp==bpp)) q=q+0x0800;
        if (bpp>=16) q=q+0x0020; if (bpp==16) q=q+0x0008;
        if (wdepth==-1 || (wdepth==depth)) q=q+0x0400;
        if (depth>=16) q=q+0x0010; if (depth==16) q=q+0x0004;
        if (!pal) q=q+0x0080;
        if (bitmap) q=q+0x0001;
        if ( q > maxqual )
        {
            // this pixelformat is a best one, remember it
            maxqual = q;
            maxindex = i;
            max_bpp = bpp;
            max_depth = depth;
            max_dbl = dbuff ? 1 : 0;
            max_acc = soft ? 0 : 1;
            max_pfd = pfd;
        }
    }

    // pfd found ?
    if (maxindex == 0)
        return maxindex;
    // ok store the parameters
    if (p_bpp != NULL)
        *p_bpp = max_bpp;
    if (p_depth != NULL)
        *p_depth = max_depth;
    if (p_dbl != NULL)
        *p_dbl = max_dbl;
    if (p_acc != NULL)
        *p_acc = max_acc;
    if (p_pfd != NULL)
        *p_pfd = max_pfd;

    // return the pixelformat value
    return maxindex;
}

static void AdjustPixelFormatAttributes( int *p_bpp,
                                         int *p_depth,
                                         int *p_dbl,
                                         int *p_acc,
                                         int *attribList)
{
    if (attribList)
    {
        *p_dbl = 0; // disabled by default

        int arg = 0;
    while( (attribList[arg]!=0) )
    {
      switch( attribList[arg++] )
      {
        case WX_GL_RGBA:
          break;
        case WX_GL_BUFFER_SIZE:
                *p_bpp = (BYTE)attribList[arg++];
          break;
        case WX_GL_LEVEL:
          arg++;
          break;
        case WX_GL_DOUBLEBUFFER:
                *p_dbl = 1;
          break;
        case WX_GL_STEREO:
          break;
        case WX_GL_AUX_BUFFERS:
                arg++;
          break;
        case WX_GL_MIN_RED:
                arg++;
          break;
        case WX_GL_MIN_GREEN:
                arg++;
          break;
        case WX_GL_MIN_BLUE:
                arg++;
          break;
        case WX_GL_MIN_ALPHA:
                arg++;
          break;
        case WX_GL_DEPTH_SIZE:
                *p_depth = attribList[arg++];
          break;
        case WX_GL_STENCIL_SIZE:
                arg++;
          break;
        case WX_GL_MIN_ACCUM_RED:
                arg++;
          break;
        case WX_GL_MIN_ACCUM_GREEN:
                arg++;
          break;
        case WX_GL_MIN_ACCUM_BLUE:
                arg++;
          break;
        case WX_GL_MIN_ACCUM_ALPHA:
                arg++;
          break;
              case WX_GL_NOT_ACCELERATED:
                *p_acc = 0;
        default:
          break;
      }
    }
  }
}


void wxGLCanvas::SetupPixelFormat(int *attribList) // (HDC hDC)
{
  /* setup default values */
  int bpp = -1;   /* prefered color depth: don't care */
  int depth = -1; /* depth buffer: don't care */
  int dbl = 1;    /* support double-buffering (or -1 for 'don't care', or 0 for 'none') */
  int acc = 1;    /* we want acceleration. (or -1 or 0) */

  /* adjust pixel format parameters depending on the user's attribute list */
  AdjustPixelFormatAttributes( &bpp, &depth, &dbl, &acc, attribList);

  /* choose the best pixel format matching the given parameters */
  PIXELFORMATDESCRIPTOR pfd;
  int pixelFormat = ChoosePixelFormatEx((HDC) m_hDC, &bpp, &depth, &dbl, &acc, &pfd);

  if (pixelFormat == 0)
  {
    wxLogLastError(_T("ChoosePixelFormat"));
  }
  else
  {
    if ( !::SetPixelFormat((HDC) m_hDC, pixelFormat, &pfd) )
    {
      wxLogLastError(_T("SetPixelFormat"));
    }
  }
}

void wxGLCanvas::SetupPalette(const wxPalette& palette)
{
    int pixelFormat = GetPixelFormat((HDC) m_hDC);
    PIXELFORMATDESCRIPTOR pfd;

    DescribePixelFormat((HDC) m_hDC, pixelFormat, sizeof(PIXELFORMATDESCRIPTOR), &pfd);

    if (pfd.dwFlags & PFD_NEED_PALETTE)
    {
    }
    else
    {
      return;
    }

    m_palette = palette;

    if ( !m_palette.Ok() )
    {
        m_palette = CreateDefaultPalette();
    }

    if (m_palette.Ok())
    {
        ::SelectPalette((HDC) m_hDC, (HPALETTE) m_palette.GetHPALETTE(), FALSE);
        ::RealizePalette((HDC) m_hDC);
    }
}

wxPalette wxGLCanvas::CreateDefaultPalette()
{
    PIXELFORMATDESCRIPTOR pfd;
    int paletteSize;
    int pixelFormat = GetPixelFormat((HDC) m_hDC);

    DescribePixelFormat((HDC) m_hDC, pixelFormat, sizeof(PIXELFORMATDESCRIPTOR), &pfd);

    paletteSize = 1 << pfd.cColorBits;

    LOGPALETTE* pPal =
     (LOGPALETTE*) malloc(sizeof(LOGPALETTE) + paletteSize * sizeof(PALETTEENTRY));
    pPal->palVersion = 0x300;
    pPal->palNumEntries = (WORD)paletteSize;

    /* build a simple RGB color palette */
    {
    int redMask = (1 << pfd.cRedBits) - 1;
    int greenMask = (1 << pfd.cGreenBits) - 1;
    int blueMask = (1 << pfd.cBlueBits) - 1;
    int i;

    for (i=0; i<paletteSize; ++i) {
        pPal->palPalEntry[i].peRed =
            (BYTE)((((i >> pfd.cRedShift) & redMask) * 255) / redMask);
        pPal->palPalEntry[i].peGreen =
            (BYTE)((((i >> pfd.cGreenShift) & greenMask) * 255) / greenMask);
        pPal->palPalEntry[i].peBlue =
            (BYTE)((((i >> pfd.cBlueShift) & blueMask) * 255) / blueMask);
        pPal->palPalEntry[i].peFlags = 0;
    }
    }

    HPALETTE hPalette = CreatePalette(pPal);
    free(pPal);

    wxPalette palette;
    palette.SetHPALETTE((WXHPALETTE) hPalette);

    return palette;
}

void wxGLCanvas::SwapBuffers()
{
  if (m_glContext)
    m_glContext->SwapBuffers();
}

void wxGLCanvas::OnSize(wxSizeEvent& WXUNUSED(event))
{
}

void wxGLCanvas::SetCurrent()
{
  // although on MSW it works even if the window is still hidden, it doesn't
  // under wxGTK and documentation mentions that SetCurrent() can only be
  // called for a shown window, so check it
  wxASSERT_MSG( GetParent()->IsShown(),
                    _T("can't make hidden GL canvas current") );

  if (m_glContext)
  {
    m_glContext->SetCurrent();
  }
}

void wxGLCanvas::SetColour(const wxChar *colour)
{
  if (m_glContext)
    m_glContext->SetColour(colour);
}

// TODO: Have to have this called by parent frame (?)
// So we need wxFrame to call OnQueryNewPalette for all children...
void wxGLCanvas::OnQueryNewPalette(wxQueryNewPaletteEvent& event)
{
  /* realize palette if this is the current window */
  if ( GetPalette()->Ok() ) {
    ::UnrealizeObject((HPALETTE) GetPalette()->GetHPALETTE());
    ::SelectPalette((HDC) GetHDC(), (HPALETTE) GetPalette()->GetHPALETTE(), FALSE);
    ::RealizePalette((HDC) GetHDC());
    Refresh();
    event.SetPaletteRealized(true);
  }
  else
    event.SetPaletteRealized(false);
}

// I think this doesn't have to be propagated to child windows.
void wxGLCanvas::OnPaletteChanged(wxPaletteChangedEvent& event)
{
  /* realize palette if this is *not* the current window */
  if ( GetPalette() &&
       GetPalette()->Ok() && (this != event.GetChangedWindow()) )
  {
    ::UnrealizeObject((HPALETTE) GetPalette()->GetHPALETTE());
    ::SelectPalette((HDC) GetHDC(), (HPALETTE) GetPalette()->GetHPALETTE(), FALSE);
    ::RealizePalette((HDC) GetHDC());
    Refresh();
  }
}

/* Give extensions proper function names. */

/* EXT_vertex_array */
void glArrayElementEXT(GLint WXUNUSED(i))
{
}

void glColorPointerEXT(GLint WXUNUSED(size), GLenum WXUNUSED(type), GLsizei WXUNUSED(stride), GLsizei WXUNUSED(count), const GLvoid *WXUNUSED(pointer))
{
}

void glDrawArraysEXT(GLenum  WXUNUSED_WITHOUT_GL_EXT_vertex_array(mode),
                     GLint   WXUNUSED_WITHOUT_GL_EXT_vertex_array(first),
                     GLsizei WXUNUSED_WITHOUT_GL_EXT_vertex_array(count))
{
#ifdef GL_EXT_vertex_array
    static PFNGLDRAWARRAYSEXTPROC proc = 0;

    if ( !proc )
    {
        proc = (PFNGLDRAWARRAYSEXTPROC) wglGetProcAddress("glDrawArraysEXT");
    }

    if ( proc )
        (* proc) (mode, first, count);
#endif
}

void glEdgeFlagPointerEXT(GLsizei WXUNUSED(stride), GLsizei WXUNUSED(count), const GLboolean *WXUNUSED(pointer))
{
}

void glGetPointervEXT(GLenum WXUNUSED(pname), GLvoid* *WXUNUSED(params))
{
}

void glIndexPointerEXT(GLenum WXUNUSED(type), GLsizei WXUNUSED(stride), GLsizei WXUNUSED(count), const GLvoid *WXUNUSED(pointer))
{
}

void glNormalPointerEXT(GLenum        WXUNUSED_WITHOUT_GL_EXT_vertex_array(type),
                        GLsizei       WXUNUSED_WITHOUT_GL_EXT_vertex_array(stride),
                        GLsizei       WXUNUSED_WITHOUT_GL_EXT_vertex_array(count),
                        const GLvoid *WXUNUSED_WITHOUT_GL_EXT_vertex_array(pointer))
{
#ifdef GL_EXT_vertex_array
  static PFNGLNORMALPOINTEREXTPROC proc = 0;

  if ( !proc )
  {
    proc = (PFNGLNORMALPOINTEREXTPROC) wglGetProcAddress("glNormalPointerEXT");
  }

  if ( proc )
    (* proc) (type, stride, count, pointer);
#endif
}

void glTexCoordPointerEXT(GLint WXUNUSED(size), GLenum WXUNUSED(type), GLsizei WXUNUSED(stride), GLsizei WXUNUSED(count), const GLvoid *WXUNUSED(pointer))
{
}

void glVertexPointerEXT(GLint         WXUNUSED_WITHOUT_GL_EXT_vertex_array(size),
                        GLenum        WXUNUSED_WITHOUT_GL_EXT_vertex_array(type),
                        GLsizei       WXUNUSED_WITHOUT_GL_EXT_vertex_array(stride),
                        GLsizei       WXUNUSED_WITHOUT_GL_EXT_vertex_array(count),
                        const GLvoid *WXUNUSED_WITHOUT_GL_EXT_vertex_array(pointer))
{
#ifdef GL_EXT_vertex_array
  static PFNGLVERTEXPOINTEREXTPROC proc = 0;

  if ( !proc )
  {
    proc = (PFNGLVERTEXPOINTEREXTPROC) wglGetProcAddress("glVertexPointerEXT");
  }
  if ( proc )
    (* proc) (size, type, stride, count, pointer);
#endif
}

/* EXT_color_subtable */
void glColorSubtableEXT(GLenum WXUNUSED(target), GLsizei WXUNUSED(start), GLsizei WXUNUSED(count), GLenum WXUNUSED(format), GLenum WXUNUSED(type), const GLvoid *WXUNUSED(table))
{
}

/* EXT_color_table */
void glColorTableEXT(GLenum WXUNUSED(target), GLenum WXUNUSED(internalformat), GLsizei WXUNUSED(width), GLenum WXUNUSED(format), GLenum WXUNUSED(type), const GLvoid *WXUNUSED(table))
{
}

void glCopyColorTableEXT(GLenum WXUNUSED(target), GLenum WXUNUSED(internalformat), GLint WXUNUSED(x), GLint WXUNUSED(y), GLsizei WXUNUSED(width))
{
}

void glGetColorTableEXT(GLenum WXUNUSED(target), GLenum WXUNUSED(format), GLenum WXUNUSED(type), GLvoid *WXUNUSED(table))
{
}

void glGetColorTableParamaterfvEXT(GLenum WXUNUSED(target), GLenum WXUNUSED(pname), GLfloat *WXUNUSED(params))
{
}

void glGetColorTavleParameterivEXT(GLenum WXUNUSED(target), GLenum WXUNUSED(pname), GLint *WXUNUSED(params))
{
}

/* SGI_compiled_vertex_array */
void glLockArraysSGI(GLint WXUNUSED(first), GLsizei WXUNUSED(count))
{
}

void glUnlockArraysSGI()
{
}


/* SGI_cull_vertex */
void glCullParameterdvSGI(GLenum WXUNUSED(pname), GLdouble* WXUNUSED(params))
{
}

void glCullParameterfvSGI(GLenum WXUNUSED(pname), GLfloat* WXUNUSED(params))
{
}

/* SGI_index_func */
void glIndexFuncSGI(GLenum WXUNUSED(func), GLclampf WXUNUSED(ref))
{
}

/* SGI_index_material */
void glIndexMaterialSGI(GLenum WXUNUSED(face), GLenum WXUNUSED(mode))
{
}

/* WIN_swap_hint */
void glAddSwapHintRectWin(GLint WXUNUSED(x), GLint WXUNUSED(y), GLsizei WXUNUSED(width), GLsizei WXUNUSED(height))
{
}


//---------------------------------------------------------------------------
// wxGLApp
//---------------------------------------------------------------------------

IMPLEMENT_CLASS(wxGLApp, wxApp)

bool wxGLApp::InitGLVisual(int *attribList)
{
  /* setup default values */
  int bpp = -1;   /* prefered color depth: don't care */
  int depth = -1; /* depth buffer: don't care */
  int dbl = 1;    /* support double-buffering (or -1 for 'don't care', or 0 for 'none') */
  int acc = 1;    /* we want acceleration. (or -1 or 0) */

  /* adjust pixel format parameters depending on the user's attribute list */
  AdjustPixelFormatAttributes( &bpp, &depth, &dbl, &acc, attribList);

  /* choose the best pixel format matching the given parameters */
  PIXELFORMATDESCRIPTOR pfd;
  int pixelFormat = ChoosePixelFormatEx(ScreenHDC(), &bpp, &depth, &dbl, &acc, &pfd);

  if (pixelFormat == 0) {
    wxLogError(_("Failed to initialize OpenGL"));
    return false;
  }

  return true;
}

wxGLApp::~wxGLApp()
{
}

#endif
    // wxUSE_GLCANVAS