#ifdef _WX

#include "wx/wx.h"
#include "wx/tglbtn.h"
#include "wx/string.h"
#include "wx/spinctrl.h"
#include "wx/splitter.h"


#include "thot_gui.h"
#include "thot_sys.h"
#include "constmedia.h"
#include "typemedia.h"
#include "appdialogue.h"
#include "dialog.h"
#include "selection.h"
#include "application.h"
#include "dialog.h"
#include "document.h"
#include "message.h"
#include "libmsg.h"
#include "frame.h"
#include "registry_wx.h"
#include "thot_key.h"
#include "logdebug.h"

#undef THOT_EXPORT
#define THOT_EXPORT extern
#include "edit_tv.h"
#include "font_tv.h"
#include "frame_tv.h"
#include "appdialogue_tv.h"
#include "font_f.h"
#include "appli_f.h"
#include "profiles_f.h"
#include "appdialogue_f.h"
#include "boxparams_f.h"
#include "dialogapi_f.h"
#include "callback_f.h"
#include "AmayaParams.h"
#include "appdialogue_wx_f.h"
#include "appdialogue_wx.h"
#include "input_f.h"

#include "AmayaWindow.h"
#include "AmayaPanel.h"
#include "AmayaNotebook.h"
#include "AmayaPage.h"
#include "AmayaFrame.h"
#include "AmayaCallback.h"
#include "AmayaToolBar.h"
#include "AmayaStatusBar.h"
#include "AmayaPanel.h"
#include "AmayaApp.h"
#include "AmayaLogDebug.h"

IMPLEMENT_DYNAMIC_CLASS(AmayaWindow, wxFrame)

  /* contains the last activated window id. */
  int AmayaWindow::m_ActiveWindowId = -1;

DECLARE_EVENT_TYPE(wxEVT_AMAYA_ACTION_EVENT, -1)
  DEFINE_EVENT_TYPE(wxEVT_AMAYA_ACTION_EVENT)

/*----------------------------------------------------------------------
 *       Class:  AmayaWindow
 *      Method:  AmayaWindow
 * Description:  create a new AmayaWindow
  -----------------------------------------------------------------------*/
AmayaWindow::AmayaWindow (  int window_id
                              ,wxWindow *p_parent_window
                              ,const wxPoint &pos
                              ,const wxSize &size
                              ,int kind
                              ,long style
                              ) : 
    wxFrame( wxDynamicCast(p_parent_window, wxWindow),
             -1, _T(""), pos, size, style ),
    m_Kind( kind ),
    m_WindowId( window_id ),
    m_ActiveFrameId( 0 ),
    m_MustCheckFocusIsNotLost( false ),
    m_pMenuBar(NULL)
{
  TTALOGDEBUG_1( TTA_LOG_DIALOG,  _T("AmayaWindow::AmayaWindow: window_id=%d"), m_WindowId );
  SetIcon( AmayaApp::GetAppIcon() );

#ifdef __WXDEBUG__
  AmayaLogDebug * p_logdebug = AmayaApp::GetAmayaLogDebug( wxDynamicCast(this,wxWindow) );
  wxPoint win_position = GetPosition();
  wxSize  win_size = GetSize();
  p_logdebug->SetPosition(wxPoint(win_position.x+win_size.GetWidth()+10,win_position.y));
  p_logdebug->Show();
#endif /* __WXDEBUG__ */
}

/*----------------------------------------------------------------------
 *       Class:  AmayaWindow
 *      Method:  ~AmayaWindow
 * Description:  destructor
  -----------------------------------------------------------------------*/
AmayaWindow::~AmayaWindow()
{
  TTALOGDEBUG_1( TTA_LOG_DIALOG, _T("AmayaWindow::~AmayaWindow: window_id=%d"), m_WindowId );
  // empty the current window entry
  memset(&WindowTable[m_WindowId], 0, sizeof(Window_Ctl));

#ifdef __WXDEBUG__
  AmayaApp::DestroyAmayaLogDebug();
#endif /* __WXDEBUG__ */
}

/*----------------------------------------------------------------------
 *       Class:  AmayaWindow
 *      Method:  CreatePage
 * Description:  create a new AmayaPage, the notebook will be the parent page
 *               it's possible to attach automaticaly this page to the window or not
  -----------------------------------------------------------------------*/
AmayaPage * AmayaWindow::CreatePage( bool attach, int position )
{
  return NULL;
}

/*----------------------------------------------------------------------
 *       Class:  AmayaWindow
 *      Method:  AttachPage
 * Description:  really attach a page to the current window
  -----------------------------------------------------------------------*/
bool AmayaWindow::AttachPage( int position, AmayaPage * p_page )
{
  return false;
}

/*----------------------------------------------------------------------
 *       Class:  AmayaWindow
 *      Method:  DetachPage
 * Description:  
  -----------------------------------------------------------------------*/
bool AmayaWindow::DetachPage( int position )
{
  return false;
}

/*----------------------------------------------------------------------
 *       Class:  AmayaWindow
 *      Method:  ClosePage
 * Description:  ferme une page
  -----------------------------------------------------------------------*/
bool AmayaWindow::ClosePage( int position )
{
  return false;
}

/*----------------------------------------------------------------------
 *       Class:  AmayaWindow
 *      Method:  CloseAllButPage
 * Description:  ferme toutes les pages sauf une
  -----------------------------------------------------------------------*/
bool AmayaWindow::CloseAllButPage( int position )
{
  return false;
}

/*----------------------------------------------------------------------
 *       Class:  AmayaWindow
 *      Method:  GetPage
 * Description:  search the page at given position
  -----------------------------------------------------------------------*/
AmayaPage * AmayaWindow::GetPage( int position ) const
{
  return NULL;
}

/*----------------------------------------------------------------------
 *       Class:  AmayaWindow
 *      Method:  GetPage
 * Description:  how many page into the window
  -----------------------------------------------------------------------*/
int AmayaWindow::GetPageCount() const
{
  return 0;
}

/*----------------------------------------------------------------------
 *       Class:  AmayaWindow
 *      Method:  GetActiveWindow
 * Description:  return the current selected window
  -----------------------------------------------------------------------*/
AmayaWindow * AmayaWindow::GetActiveWindow()
{
  return TtaGetWindowFromId(m_ActiveWindowId);
}

/*----------------------------------------------------------------------
 *       Class:  AmayaWindow
 *      Method:  GetActivePage
 * Description:  return the current selected page
  -----------------------------------------------------------------------*/
AmayaPage * AmayaWindow::GetActivePage() const
{
  TTALOGDEBUG_0( TTA_LOG_DIALOG, _T("AmayaWindow::GetActivePage") );
  return NULL;
}

/*----------------------------------------------------------------------
 *       Class:  AmayaWindow
 *      Method:  GetActiveFrame
 * Description:  return the current selected frame
  -----------------------------------------------------------------------*/
AmayaFrame * AmayaWindow::GetActiveFrame() const
{
  TTALOGDEBUG_0( TTA_LOG_DIALOG, _T("AmayaWindow::GetActiveFrame") );
  return NULL;
}

/*----------------------------------------------------------------------
 *       Class:  AmayaWindow
 *      Method:  SetURL
 * Description:  set the current url value
  -----------------------------------------------------------------------*/
void AmayaWindow::SetURL ( const wxString & new_url )
{
}

/*----------------------------------------------------------------------
 *       Class:  AmayaWindow
 *      Method:  GetURL
 * Description:  get the current url value
  -----------------------------------------------------------------------*/
wxString AmayaWindow::GetURL( )
{
  return wxString(_T(""));
}

/*----------------------------------------------------------------------
 *       Class:  AmayaWindow
 *      Method:  AppendURL
 * Description:  TODO
  -----------------------------------------------------------------------*/
void AmayaWindow::AppendURL ( const wxString & new_url )
{
  return;
}

/*----------------------------------------------------------------------
 *       Class:  AmayaWindow
 *      Method:  EmptyURLBar
 * Description:  remove all items in the url bar
  -----------------------------------------------------------------------*/
void AmayaWindow::EmptyURLBar()
{
  return;
}

/*----------------------------------------------------------------------
 *       Class:  AmayaWindow
 *      Method:  SetMenuBar
 * Description:  override the wxFrame::SetMenuBar methode to remember the menubar for fullscreen mode
  -----------------------------------------------------------------------*/
void AmayaWindow::SetMenuBar( wxMenuBar * p_menu_bar )
{
  m_pMenuBar = p_menu_bar;
  wxFrame::SetMenuBar(p_menu_bar);
}


/*----------------------------------------------------------------------
 *       Class:  AmayaWindow
 *      Method:  OnSize
 * Description:  the window is resized, we must recalculate by hand the new urlbar size
 *               (wxWidgets is not able to do that itself ...)
  -----------------------------------------------------------------------*/
void AmayaWindow::OnSize( wxSizeEvent& event )
{
  TTALOGDEBUG_2( TTA_LOG_DIALOG, _T("AmayaWindow::OnSize - ")+
                 wxString(_T(" w=%d h=%d")),
                 event.GetSize().GetWidth(),
                 event.GetSize().GetHeight() );

  // save the new window size
  WindowTable[GetWindowId()].FrWidth  = event.GetSize().GetWidth();
  WindowTable[GetWindowId()].FrHeight = event.GetSize().GetHeight();

  event.Skip();
}

/*----------------------------------------------------------------------
 *       Class:  AmayaWindow
 *      Method:  GetAmayaToolBar
 * Description:  return the current toolbar
  -----------------------------------------------------------------------*/
AmayaToolBar * AmayaWindow::GetAmayaToolBar()
{
  return NULL;
}

/*----------------------------------------------------------------------
 *       Class:  AmayaWindow
 *      Method:  GetAmayaStatusBar
 * Description:  
  -----------------------------------------------------------------------*/
AmayaStatusBar * AmayaWindow::GetAmayaStatusBar()
{
  return NULL;
}

/*----------------------------------------------------------------------
 *       Class:  AmayaWindow
 *      Method:  AttachFrame
 * Description:  for a SIMPLE window type, attach directly a frame to the window
  -----------------------------------------------------------------------*/
bool AmayaWindow::AttachFrame( AmayaFrame * p_frame )
{
  return false;
}

/*----------------------------------------------------------------------
 *       Class:  AmayaWindow
 *      Method:  DetachFrame
 * Description:  for a SIMPLE window type, detach directly a frame from the window
  -----------------------------------------------------------------------*/
AmayaFrame * AmayaWindow::DetachFrame()
{
  return NULL;
}

/*----------------------------------------------------------------------
 *       Class:  AmayaWindow
 *      Method:  CleanUp
 * Description:  check that there is no empty pages
  -----------------------------------------------------------------------*/
void AmayaWindow::CleanUp()
{
}

/*----------------------------------------------------------------------
 *       Class:  AmayaWindow
 *      Method:  OnIdle
 * Description:  not used
  -----------------------------------------------------------------------*/
void AmayaWindow::OnIdle( wxIdleEvent& event )
{
  // this flag is used to process on idle time the possible lost focus
  // it can not be procced in OnActivate callback because the wxWindow::FindFocus is allways NULL (bug)
  if (m_MustCheckFocusIsNotLost)
    {
      wxWindow *       p_win_focus         = wxWindow::FindFocus();
      if (p_win_focus)
        TTALOGDEBUG_1( TTA_LOG_FOCUS, _T("AmayaWindow::OnIdle - focus = %s"), p_win_focus->GetClassInfo()->GetClassName())
          else
            {
              TTALOGDEBUG_0( TTA_LOG_FOCUS, _T("AmayaWindow::OnIdle - no focus"));
#ifndef _MACOS
              TtaRedirectFocus();
#else /* _MACOS */
              TtaCheckLostFocus();
#endif /* _MACOS */
            }
      m_MustCheckFocusIsNotLost = false;
    }

  event.Skip();
}


/*----------------------------------------------------------------------
 *       Class:  AmayaWindow
 *      Method:  OnActivate
 * Description:  this is used to keep udated a internal window_id to know what is the
 *               last activated window.
 *               activated = highlighted
  -----------------------------------------------------------------------*/
void AmayaWindow::OnActivate( wxActivateEvent & event )
{  
  if (event.GetActive())
    {
      TTALOGDEBUG_1( TTA_LOG_FOCUS, _T("AmayaWindow::OnActivate - window_id=%d"), m_WindowId );

      // update the active-window indicator to be able to know the last active window everytime
      m_ActiveWindowId = GetWindowId();

      // update internal thotlib global var : ActiveFrame
      // this is necessary because when a window is closed, the active frame must be updated
      AmayaFrame * p_frame = GetActiveFrame();
      if (p_frame)
        ChangeSelFrame(p_frame->GetFrameId());

      // just chek on idle time if the focus is lost 
      m_MustCheckFocusIsNotLost = true;
    }

  event.Skip();
}

/*----------------------------------------------------------------------
 *       Class:  AmayaWindow
 *      Method:  GetAmayaPanel
 * Description:  return the window's panel (exist only on AmayaNormalWindow)
  -----------------------------------------------------------------------*/
AmayaPanel * AmayaWindow::GetAmayaPanel() const
{
  return NULL;
}

/*----------------------------------------------------------------------
 *       Class:  AmayaWindow
 *      Method:  ClosePanel
 * Description:  close the side panel
  -----------------------------------------------------------------------*/
void AmayaWindow::ClosePanel()
{
}

/*----------------------------------------------------------------------
 *       Class:  AmayaWindow
 *      Method:  OpenPanel
 * Description:  open the side panel
  -----------------------------------------------------------------------*/
void AmayaWindow::OpenPanel()
{
}

/*----------------------------------------------------------------------
 *       Class:  AmayaWindow
 *      Method:  IsPanelOpened
 * Description:  returns true if the side panel is opened
  -----------------------------------------------------------------------*/
bool AmayaWindow::IsPanelOpened()
{
  return false;
}

/*----------------------------------------------------------------------
 *       Class:  AmayaWindow
 *      Method:  RefreshShowPanelToggleMenu
 * Description:  is called to toggle on/off the "Show/Hide panel" menu item depeding on
 *               the panel showing state.
 *               Only used by AmayaNormalWindow
  -----------------------------------------------------------------------*/
void AmayaWindow::RefreshShowPanelToggleMenu()
{
}

/*----------------------------------------------------------------------
 *       Class:  AmayaWindow
 *      Method:  ToggleFullScreen
 * Description:  switch on/off fullscreen state
  -----------------------------------------------------------------------*/
void AmayaWindow::ToggleFullScreen()
{
  // SG: on gtk (maybe on other plateforms) it should be possible to hide the notebook tabs
  //     but it require to contribute to wxwidgets (submit a patch)
  //     it's possible with this function gtk_notebook_set_show_tabs()
  //     (http://developer.gnome.org/doc/API/2.0/gtk/GtkNotebook.html#gtk-notebook-set-show-tabs)
  if (IsFullScreen())
    {
      wxFrame::SetMenuBar(m_pMenuBar);
      if (GetStatusBar())
        GetStatusBar()->Show();
      if (GetAmayaToolBar())
        GetAmayaToolBar()->Show();
      ShowFullScreen(false);
    }
  else
    {
      wxFrame::SetMenuBar(NULL);
      if (GetStatusBar())
        GetStatusBar()->Hide();
      if (GetAmayaToolBar())
        GetAmayaToolBar()->Hide();
      ShowFullScreen(true);
    }
}

/*----------------------------------------------------------------------
 *       Class:  AmayaWindow
 *      Method:  OnChar
 * Description:  manage keyboard events comming from somewhere in this window
  -----------------------------------------------------------------------*/
void AmayaWindow::OnChar(wxKeyEvent& event)
{
  TTALOGDEBUG_0( TTA_LOG_KEYINPUT, _T("AmayaWindow::OnChar key=")+wxString(event.GetUnicodeKey()) );
  if (!TtaHandleUnicodeKey(event))
    if (!TtaHandleSpecialKey(event))
      if (!TtaHandleShortcutKey(event))
        event.Skip();
}

/*----------------------------------------------------------------------
 *       Class:  AmayaWindow
 *      Method:  DnAmayaAction
 * Description:  will add the wanted action on the window's eventhandler stack,
 *               this event will be treated durring next idle event (see wxWidgets doc)
 *               Using a differed action will prevent Amaya to
 *               delete widgets when it should not be.
  -----------------------------------------------------------------------*/
void AmayaWindow::DoAmayaAction( int command, int doc, int view )
{
  int frame_id = GetWindowNumber(doc, view);
  int window_id = TtaGetFrameWindowParentId(frame_id);
  AmayaWindow * p_window = TtaGetWindowFromId(window_id);
  if (p_window)
    {
      // create the event
      wxCommandEvent evt( wxEVT_AMAYA_ACTION_EVENT, command );
      // Give it some contents
      evt.SetExtraLong( doc );
      evt.SetInt( view );
      /* post the event on the window's event hander */
      wxPostEvent( p_window, evt );
    }
}

/*----------------------------------------------------------------------
 *       Class:  AmayaWindow
 *      Method:  OnAmayaAction
 * Description:  catch a previously generated event by DoAmayaAction
 *               it will really execute the action
  -----------------------------------------------------------------------*/
void AmayaWindow::OnAmayaAction( wxCommandEvent& event )
{
  TTALOGDEBUG_0( TTA_LOG_DIALOG, _T("AmayaWindow::OnAmayaAction : text=")+event.GetString() );
  
  int action_id = event.GetId();
  int doc       = event.GetExtraLong();
  int view      = event.GetInt();  
  TtaExecuteMenuActionFromActionId(action_id, doc, view, FALSE);
}

/*----------------------------------------------------------------------
 *  this is where the event table is declared
 *  the callbacks are assigned to an event type
 *----------------------------------------------------------------------*/
BEGIN_EVENT_TABLE(AmayaWindow, wxFrame)
  EVT_SIZE(      AmayaWindow::OnSize )
  EVT_IDLE(      AmayaWindow::OnIdle ) // Process a wxEVT_IDLE event  
  EVT_ACTIVATE(  AmayaWindow::OnActivate )
#if !defined (_WINDOWS) &&  !defined (_MACOS)
  EVT_CHAR_HOOK( AmayaWindow::OnChar )
#else /* !_WINDOWS  && ! MACOS */
  //  EVT_CHAR( AmayaWindow::OnChar )
#endif /* !_WINDOWS  && ! MACOS */
  EVT_COMMAND(-1, wxEVT_AMAYA_ACTION_EVENT, AmayaWindow::OnAmayaAction)
  END_EVENT_TABLE()

#endif /* #ifdef _WX */
