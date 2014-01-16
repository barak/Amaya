#ifdef _WX

#ifndef __AMAYAWINDOW_H__
#define __AMAYAWINDOW_H__

#include "wx/wx.h"
#include "wx/frame.h"
#include "wx/tooltip.h"
#include "wx/fontmap.h"
#include "wx/strconv.h"
#include "wx/wfstream.h"
#include "wx/menu.h"
#include "wx/splitter.h"

class AmayaPanel;
class AmayaPage;
class AmayaFrame;
class AmayaNotebook;
class AmayaCParam;
class AmayaURLBar;
class AmayaToolBar;
class AmayaPanel;
class AmayaStatusBar;

#include "windowtypes_wx.h"

/*
 * =====================================================================================
 *        Class:  AmayaWindow
 * 
 *  Description:  - AmayaWindow is the top container
 *                  + A window can contains several documents.
 *                  + Each document is placed into a page.
 *                  + A page is a "tab" placed in
 *                  a "notebook" widget.
 *                  + A page can be splited in 2 parts, each parts
 *                  represent a document's view (AmayaFrame).
 *                  + A frame is a OpenGL canvas with its own
 *                  scrollbars.
 * 
 * +[AmayaWindow]-----------------------------------------+
 * |+----------------------------------------------------+|
 * || MenuBar                                            ||
 * |+----------------------------------------------------+|
 * |+----------------------------------------------------+|
 * || ToolBar                                            ||
 * |+----------------------------------------------------+|
 * |+[AmayaPanel]--+ +[AmayaNoteBook]-------------------+ |
 * ||              | |+-----------+                     | |
 * ||              | ||[AmayaPage]+--------------------+| |
 * ||              | ||+------------------------------+|| |
 * ||              | |||[AmayaFrame]                  ||| |
 * ||              | |||                              ||| |
 * ||              | |||                              ||| |
 * ||              | |||  (view container)     'Top'  ||| |
 * ||              | |||---------SplitBar-------------||| |
 * ||              | |||[AmayaFrame]          'Bottom'||| |
 * ||              | |||                              ||| |
 * ||              | |||                              ||| |
 * ||              | ||+------------------------------+|| |
 * ||              | |+--------------------------------+| |
 * |+--------------+ +----------------------------------+ |
 * |+----------------------------------------------------+|
 * || StatusBar                                          ||
 * |+----------------------------------------------------+|
 * +------------------------------------------------------+
 *       Author:  Stephane GULLY
 *      Created:  12/10/2003 04:45:34 PM CET
 *     Revision:  none
 * =====================================================================================
 */
class AmayaWindow : public wxFrame
{
 public:
//  friend class AmayaApp;
  DECLARE_DYNAMIC_CLASS(AmayaWindow)

  AmayaWindow ( int             window_id = -1
                ,wxWindow *     frame = NULL
                ,const wxPoint& pos  = wxDefaultPosition
                ,const wxSize&  size = wxDefaultSize
                ,int kind = WXAMAYAWINDOW_UNKNOWN
                ,long style = wxDEFAULT_FRAME_STYLE | wxWANTS_CHARS | wxTAB_TRAVERSAL
                );
  virtual ~AmayaWindow();
  
  static void   DoAmayaAction( int command, int doc, int view );
  
  void          SetMenuBar( wxMenuBar * p_menu_bar );
  bool          IsClosing();
  int		        GetWindowId() { return m_WindowId; }
  void          SetWindowId( int window_id ) { m_WindowId = window_id; }
  int           GetKind() const { return m_Kind; }
  static int    GetActiveWindowId() { return m_ActiveWindowId; }
  static AmayaWindow * GetActiveWindow();

  virtual void         CleanUp();
  virtual AmayaPage *  GetActivePage() const;
  virtual AmayaFrame * GetActiveFrame() const;

  virtual void ToggleFullScreen();

  virtual void DoClose( bool & veto );

  // --------------------------------------------- //
  // WXAMAYAWINDOW_NORMAL interface
  virtual AmayaPanel * GetAmayaPanel() const;
  virtual bool IsPanelOpened();
  virtual void ClosePanel();
  virtual void OpenPanel();
  virtual void RefreshShowPanelToggleMenu();

  virtual AmayaPage *    CreatePage( bool attach = false, int position = 0 );
  virtual bool           AttachPage( int position, AmayaPage * p_page );
  virtual bool           DetachPage( int position );
  virtual bool           ClosePage( int position );
  virtual AmayaPage *    GetPage( int position ) const;
  virtual int            GetPageCount() const;

  virtual AmayaToolBar * GetAmayaToolBar();
  virtual AmayaStatusBar * GetAmayaStatusBar();

  // url bar control
  virtual wxString GetURL();
  virtual void     SetURL ( const wxString & new_url );
  virtual void     AppendURL ( const wxString & new_url );
  virtual void     EmptyURLBar();

  // --------------------------------------------- //
  // WXAMAYAWINDOW_SIMPLE interface
  virtual bool         AttachFrame( AmayaFrame * p_frame );
  virtual AmayaFrame * DetachFrame();

 public:
  //  bool CheckUnicodeKey( wxKeyEvent& event );
  //  bool CheckSpecialKey( wxKeyEvent& event );
  //  bool CheckShortcutKey( wxKeyEvent& event );
  //  bool IsSpecialKey( int wx_keycode );

 public:
  void OnChar( wxKeyEvent& event );
  
 protected:
  DECLARE_EVENT_TABLE()
  void OnClose( wxCloseEvent& event );
  void OnSize( wxSizeEvent& event );
  void OnIdle( wxIdleEvent& event );
  void OnActivate( wxActivateEvent & event );
  void OnAmayaAction( wxCommandEvent& event );

 protected:
  int               m_Kind;               // window kind
  int               m_WindowId;           // amaya window id
  bool              m_IsClosing;
  bool              m_ShouldCleanUp;
  static int        m_ActiveWindowId;
  int               m_ActiveFrameId;
  bool              m_MustCheckFocusIsNotLost;
  wxMenuBar *       m_pMenuBar;
};

#endif // __AMAYAWINDOW_H__

#endif /* #ifdef _WX */
