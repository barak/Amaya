#ifdef _WX

#include "wx/wx.h"
#include "wx/xrc/xmlres.h"              // XRC XML resouces
#include "wx/colordlg.h"
#include "wx/tglbtn.h"

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
#include "message_wx.h"
#include "paneltypes_wx.h"
#include "appdialogue_wx.h"
#include "appdialogue_wx_f.h"
#include "panel.h"
#include "registry_wx.h"

#undef THOT_EXPORT
#define THOT_EXPORT extern
#include "frame_tv.h"
#include "panel_tv.h"
#include "colors_f.h"
#include "inites_f.h"
#include "presentmenu_f.h"

#include "AmayaColorsPanel.h"
#include "AmayaNormalWindow.h"
#include "AmayaFloatingPanel.h"
#include "AmayaSubPanelManager.h"

IMPLEMENT_DYNAMIC_CLASS(AmayaColorsPanel, AmayaSubPanel)

/*----------------------------------------------------------------------
 *       Class:  AmayaColorsPanel
 *      Method:  AmayaColorsPanel
 * Description:  construct a panel (bookmarks, elements, attributes, colors ...)
  -----------------------------------------------------------------------*/
AmayaColorsPanel::AmayaColorsPanel( wxWindow * p_parent_window, AmayaNormalWindow * p_parent_nwindow )
  : AmayaSubPanel( p_parent_window, p_parent_nwindow, _T("wxID_PANEL_COLORS") )
    ,m_ThotBGColor(-1)
    ,m_ThotFGColor(-1)
{
  // setup labels
  RefreshToolTips();
  m_pTitleText->SetLabel(TtaConvMessageToWX(TtaGetMessage(LIB,TMSG_COLORS)));

  m_Bitmap_Empty = wxBitmap( TtaGetResourcePathWX(WX_RESOURCES_ICON_MISC, "empty.png" ), wxBITMAP_TYPE_PNG );
  m_Bitmap_DefaultColor = wxBitmap( TtaGetResourcePathWX(WX_RESOURCES_ICON_16X16, "default.png" ), wxBITMAP_TYPE_PNG );
  m_Color_ButtonBG = XRCCTRL(*m_pPanelContentDetach, "wxID_BUTTON_FGCOLOR", wxBitmapButton)->GetBackgroundColour();

  XRCCTRL(*this, "wxID_BUTTON_BGCOLOR", wxBitmapButton)->SetBitmapLabel(m_Bitmap_DefaultColor);
  XRCCTRL(*this, "wxID_BUTTON_FGCOLOR", wxBitmapButton)->SetBitmapLabel(m_Bitmap_DefaultColor);

  // on windows, the color selector dialog must be complete.
  m_ColourData.SetChooseFull(true);

  // register myself to the manager, so I will be avertised that another panel is floating ...
  m_pManager->RegisterSubPanel( this );
}

/*----------------------------------------------------------------------
 *       Class:  AmayaColorsPanel
 *      Method:  ~AmayaColorsPanel
 * Description:  destructor
  -----------------------------------------------------------------------*/
AmayaColorsPanel::~AmayaColorsPanel()
{  
  // unregister myself to the manager, so nothing should be asked to me in future
  m_pManager->UnregisterSubPanel( this );
}

/*----------------------------------------------------------------------
 *       Class:  AmayaColorsPanel
 *      Method:  GetPanelType
 * Description:  
  -----------------------------------------------------------------------*/
int AmayaColorsPanel::GetPanelType()
{
  return WXAMAYA_PANEL_COLORS;
}

/*----------------------------------------------------------------------
 *       Class:  AmayaColorsPanel
 *      Method:  RefreshToolTips
 * Description:  reassign the tooltips values
  -----------------------------------------------------------------------*/
void AmayaColorsPanel::RefreshToolTips()
{  
  XRCCTRL(*m_pPanelContentDetach, "wxID_BUTTON_DEFAULTCOLORS", wxBitmapButton)->SetToolTip(TtaConvMessageToWX(TtaGetMessage(LIB,TMSG_STD_COLORS)));
  XRCCTRL(*m_pPanelContentDetach, "wxID_BUTTON_SWITCHCOLORS", wxBitmapButton)->SetToolTip(TtaConvMessageToWX(TtaGetMessage(LIB,TMSG_CPCOLORSWITCH)));
  XRCCTRL(*m_pPanelContentDetach, "wxID_BUTTON_BGCOLOR", wxBitmapButton)->SetToolTip(TtaConvMessageToWX(TtaGetMessage(LIB,TMSG_CPCOLORBG)));
  XRCCTRL(*m_pPanelContentDetach, "wxID_BUTTON_FGCOLOR", wxBitmapButton)->SetToolTip(TtaConvMessageToWX(TtaGetMessage(LIB,TMSG_CPCOLORFG)));

  XRCCTRL(*m_pPanelContentDetach,"wxID_REFRESH",wxBitmapButton)->SetToolTip(TtaConvMessageToWX(TtaGetMessage(LIB,TMSG_REFRESH)));
  XRCCTRL(*m_pPanelContentDetach,"wxID_APPLY",wxBitmapButton)->SetToolTip(TtaConvMessageToWX(TtaGetMessage(LIB,TMSG_APPLY)));
}

/*----------------------------------------------------------------------
 *       Class:  AmayaColorPanel
 *      Method:  OnModifyColor
 * Description:  
  -----------------------------------------------------------------------*/
void AmayaColorsPanel::OnModifyColor( wxCommandEvent& event )
{
  ModifyColor (m_ThotFGColor, FALSE);
  ModifyColor (m_ThotBGColor, TRUE);

  /* give focus to canvas */
  TtaRedirectFocus();
}

/*----------------------------------------------------------------------
 *       Class:  AmayaColorPanel
 *      Method:  OnGetColor
 * Description:  
  -----------------------------------------------------------------------*/
void AmayaColorsPanel::OnGetColor( wxCommandEvent& event )
{
  ThotGetSelectedElementColor();
}

/*----------------------------------------------------------------------
 *       Class:  AmayaColorPanel
 *      Method:  OnDefaultColors
 * Description:  
  -----------------------------------------------------------------------*/
void AmayaColorsPanel::OnDefaultColors( wxCommandEvent& event )
{
  ThotSelectPalette (-1, -1);
}

/*----------------------------------------------------------------------
 *       Class:  AmayaColorPanel
 *      Method:  OnSwitchColors
 * Description:  
  -----------------------------------------------------------------------*/
void AmayaColorsPanel::OnSwitchColors( wxCommandEvent& event )
{
  ThotSelectPalette (m_ThotFGColor, m_ThotBGColor);
}

/*----------------------------------------------------------------------
 *       Class:  AmayaColorsPanel
 *      Method:  SendDataToPanel
 * Description:  refresh the button widgets of the frame's panel
  -----------------------------------------------------------------------*/
void AmayaColorsPanel::SendDataToPanel( AmayaParams& p )
{
  // update button background colors
  m_ThotBGColor = p.param1;
  if (m_ThotBGColor >= 0)
    {
      wxColour * p_bg_colour = ColorPixel(m_ThotBGColor);
      XRCCTRL(*m_pPanelContentDetach, "wxID_BUTTON_BGCOLOR", wxBitmapButton)->SetBackgroundColour( *p_bg_colour );
      XRCCTRL(*m_pPanelContentDetach, "wxID_BUTTON_BGCOLOR", wxBitmapButton)->SetBitmapLabel(m_Bitmap_Empty);
    }
  else
    {
      // default bg color is ? white ?
      XRCCTRL(*m_pPanelContentDetach, "wxID_BUTTON_BGCOLOR", wxBitmapButton)->SetBackgroundColour( m_Color_ButtonBG );
      XRCCTRL(*m_pPanelContentDetach, "wxID_BUTTON_BGCOLOR", wxBitmapButton)->SetBitmapLabel(m_Bitmap_DefaultColor);
    }

  m_ThotFGColor = p.param8;
  if (m_ThotFGColor >= 0)
    {
      wxColour * p_fg_colour = ColorPixel(m_ThotFGColor);
      XRCCTRL(*m_pPanelContentDetach, "wxID_BUTTON_FGCOLOR", wxBitmapButton)->SetBackgroundColour( *p_fg_colour );
      XRCCTRL(*m_pPanelContentDetach, "wxID_BUTTON_FGCOLOR", wxBitmapButton)->SetBitmapLabel(m_Bitmap_Empty);
    }
  else
    {
      // default fg color is ? black ?
      XRCCTRL(*m_pPanelContentDetach, "wxID_BUTTON_FGCOLOR", wxBitmapButton)->SetBackgroundColour( m_Color_ButtonBG );
      XRCCTRL(*m_pPanelContentDetach, "wxID_BUTTON_FGCOLOR", wxBitmapButton)->SetBitmapLabel(m_Bitmap_DefaultColor);
    }
}

/*----------------------------------------------------------------------
 *       Class:  AmayaColorsPanel
 *      Method:  DoUpdate
 * Description:  force a refresh when the user expand or detach this panel
  -----------------------------------------------------------------------*/
void AmayaColorsPanel::DoUpdate()
{
  AmayaSubPanel::DoUpdate();
  ThotUpdatePalette();
}

/*----------------------------------------------------------------------
 *       Class:  AmayaColorsPanel
 *      Method:  IsActive
 * Description:  
  -----------------------------------------------------------------------*/
bool AmayaColorsPanel::IsActive()
{
  return AmayaSubPanel::IsActive();
}

/*----------------------------------------------------------------------
 *       Class:  AmayaColorPanel
 *      Method:  OnChooseFGColor
 * Description:  
  -----------------------------------------------------------------------*/
void AmayaColorsPanel::OnChooseFGColor( wxCommandEvent& event )
{
  wxColour * p_fg_colour   = ColorPixel(m_ThotFGColor);
  wxColour   start_colour  = p_fg_colour ? *p_fg_colour : wxColour();
  int thot_col = ChooseCustomColor( start_colour );
  if (thot_col >= 0)
    ThotSelectPalette (m_ThotBGColor, thot_col);
}

/*----------------------------------------------------------------------
 *       Class:  AmayaColorPanel
 *      Method:  OnChooseBGColor
 * Description:  
  -----------------------------------------------------------------------*/
void AmayaColorsPanel::OnChooseBGColor( wxCommandEvent& event )
{
  wxColour * p_bg_colour = ColorPixel(m_ThotBGColor);
  wxColour start_colour  = p_bg_colour ? *p_bg_colour : wxColour();
  int thot_col = ChooseCustomColor( start_colour );
  if (thot_col >= 0)
    ThotSelectPalette (thot_col, m_ThotFGColor);
}

/*----------------------------------------------------------------------
 *       Class:  AmayaColorPanel
 *      Method:  ChooseCustomColor
 * Description:  
  -----------------------------------------------------------------------*/
int AmayaColorsPanel::ChooseCustomColor( const wxColour & start_colour )
{
  m_ColourData.SetColour( start_colour );

  // open the color dialog and ask user to select a color.
  wxColourDialog dialog(this, &m_ColourData);
  if (dialog.ShowModal() == wxID_OK)
  {
    m_ColourData = dialog.GetColourData();
    wxColour col = m_ColourData.GetColour();
    return TtaGetThotColor (col.Red(), col.Green(), col.Blue());
  }
  else
    return -1;
}

/*----------------------------------------------------------------------
 *  this is where the event table is declared
 *  the callbacks are assigned to an event type
 *----------------------------------------------------------------------*/
BEGIN_EVENT_TABLE(AmayaColorsPanel, AmayaSubPanel)
  EVT_BUTTON( XRCID("wxID_APPLY"), AmayaColorsPanel::OnModifyColor ) 
  EVT_BUTTON( XRCID("wxID_REFRESH"),    AmayaColorsPanel::OnGetColor ) 
  EVT_BUTTON( XRCID("wxID_BUTTON_DEFAULTCOLORS"), AmayaColorsPanel::OnDefaultColors ) 
  EVT_BUTTON( XRCID("wxID_BUTTON_SWITCHCOLORS"),  AmayaColorsPanel::OnSwitchColors ) 
  EVT_BUTTON( XRCID("wxID_BUTTON_FGCOLOR"),  AmayaColorsPanel::OnChooseFGColor ) 
  EVT_BUTTON( XRCID("wxID_BUTTON_BGCOLOR"),  AmayaColorsPanel::OnChooseBGColor ) 
END_EVENT_TABLE()

#endif /* #ifdef _WX */
