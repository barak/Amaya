#ifdef _WX

#ifndef __AMAYAXHTMLPANEL_H__
#define __AMAYAXHTMLPANEL_H__

#include "wx/wx.h"
#include "AmayaSubPanel.h"

class AmayaNormalWindow;

/*
 *  Description:  - AmayaXHTMLPanel is a specific sub-panel
 *       Author:  Stephane GULLY
 *      Created:  13/09/2004 04:45:34 PM CET
 *     Revision:  none
*/

class AmayaXHTMLPanel : public AmayaSubPanel
{
public:
  DECLARE_DYNAMIC_CLASS(AmayaXHTMLPanel)

  AmayaXHTMLPanel( wxWindow * p_parent_window = NULL
		   ,AmayaNormalWindow * p_parent_nwindow = NULL );
  virtual ~AmayaXHTMLPanel();

  virtual bool IsActive();
  virtual int GetPanelType();
  //void RefreshCheckButtonState( bool * p_checked_array );
  void RefreshToolTips();

 protected:
  virtual void SendDataToPanel( AmayaParams& params );
  virtual void DoUpdate();

 protected:
  DECLARE_EVENT_TABLE()
  void OnButton( wxCommandEvent& event );

  wxColour m_OffColour;
  wxColour m_OnColour;

  wxBitmap m_Bitmap_StrongOn;
  wxBitmap m_Bitmap_EmphOn;
  wxBitmap m_Bitmap_CodeOn;
  wxBitmap m_Bitmap_InsOn;
  wxBitmap m_Bitmap_DelOn;
  wxBitmap m_Bitmap_SupOn;
  wxBitmap m_Bitmap_SubOn;
  wxBitmap m_Bitmap_StrongOff;
  wxBitmap m_Bitmap_EmphOff;
  wxBitmap m_Bitmap_CodeOff;
  wxBitmap m_Bitmap_InsOff;
  wxBitmap m_Bitmap_DelOff;
  wxBitmap m_Bitmap_SupOff;
  wxBitmap m_Bitmap_SubOff;
};

#endif // __AMAYAXHTMLPANEL_H__

#endif /* #ifdef _WX */
