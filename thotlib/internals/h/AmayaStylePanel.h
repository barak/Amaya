#ifdef _WX

#ifndef __AMAYASTYLEPANEL_H__
#define __AMAYASTYLEPANEL_H__

#include "wx/wx.h"
#include "AmayaToolPanel.h"
#include "AmayaToolBar.h"
#include "AmayaColorButton.h"

class AmayaNormalWindow;

/*
 *  Description:  - AmayaXHTMLPanel is a specific sub-panel
 *       Author:  Irene Vatton
*/
class AmayaStyleToolPanel : public AmayaToolPanel
{
  DECLARE_DYNAMIC_CLASS(AmayaStyleToolPanel)
public:
  AmayaStyleToolPanel();
  virtual ~AmayaStyleToolPanel();
  
  virtual bool Create(wxWindow* parent, wxWindowID id, const wxPoint& pos = wxDefaultPosition, 
            const wxSize& size = wxDefaultSize, long style = 0,
            const wxString& name = wxT("AmayaStyleToolPanel"), wxObject* extra=NULL);
  
  virtual wxString GetToolPanelName()const;
  virtual int      GetToolPanelType()const{return WXAMAYA_PANEL_STYLE;}
  virtual wxString GetToolPanelConfigKeyName()const{return wxT("PANEL_STYLE");}

  /** Return a default AUI config for the panel.*/
  virtual wxString GetDefaultAUIConfig();
  virtual bool GetDefaultVisibilityState()const{return true;}

  
  void SetColor(int color);
  void SetBackgroundColor(int color);
  void SetTheme(const char *theme);

  void GenerateFontColour(wxColour c);
  void GenerateBackgroundColour(wxColour c);

protected:
  // Any class wishing to process wxWindows events must use this macro
  DECLARE_EVENT_TABLE()
  
  void OnChooseFontColor(wxCommandEvent& event);
  void OnColorFontPalette( AmayaColorButtonEvent& event );

  void OnChooseBackgroundColor(wxCommandEvent& event);
  void OnColorBackgroundPalette( AmayaColorButtonEvent& event );
  void SendDataToPanel( AmayaParams& p );
  
  void OnThemeChange( wxCommandEvent& event );

  void OnChooseFontFamily(wxCommandEvent& event);
  void OnChooseFontSize(wxCommandEvent& event);
  
  AmayaBaseToolBar *m_tbar1, *m_tbar2;
  wxColourData colour_data;
};


#endif // __AMAYASTYLEPANEL_H__

#endif /* #ifdef _WX */
