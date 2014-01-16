#ifdef _WX

#include "wx/wx.h"
#include "wx/xrc/xmlres.h"              // XRC XML resouces
#include "wx/string.h"
#include "wx/arrstr.h"

#include "AmayaApp.h"
#include "HRefDlgWX.h"

#define THOT_EXPORT extern
#include "amaya.h"
#include "appdialogue_wx.h"
#include "message_wx.h"

//-----------------------------------------------------------------------------
// Event table: connect the events to the handler functions to process them
//-----------------------------------------------------------------------------
BEGIN_EVENT_TABLE(HRefDlgWX, AmayaDialog)
  EVT_BUTTON(     XRCID("wxID_OK"),           HRefDlgWX::OnOk )
  EVT_BUTTON(     XRCID("wxID_BROWSE"),       HRefDlgWX::OnBrowse )
  EVT_BUTTON(     XRCID("wxID_CLICK"),        HRefDlgWX::OnClick )
  EVT_BUTTON(     XRCID("wxID_CLEAR"),        HRefDlgWX::OnClear )
  EVT_BUTTON(     XRCID("wxID_CANCEL"),       HRefDlgWX::OnCancel )
  EVT_TEXT_ENTER( XRCID("wxID_COMBOBOX"),     HRefDlgWX::OnOk )
END_EVENT_TABLE()

/*----------------------------------------------------------------------
  HRefDlgWX create the dialog used to 
    - Add CSS file
    - Create/Modify a link
  params:
    + parent : parent window
    + title : dialog title
    + ...
  returns:
  ----------------------------------------------------------------------*/
HRefDlgWX::HRefDlgWX( int ref,
		      wxWindow* parent,
		      const wxString & title,
		      const wxArrayString & url_list,
		      const wxString & wx_init_value,		     
		      const wxString & filter ) :
  AmayaDialog( parent, ref ),
  m_Filter(filter)
{
  wxXmlResource::Get()->LoadDialog(this, parent, wxT("HRefDlgWX"));

  // update dialog labels with given ones
  SetTitle( title );
  XRCCTRL(*this, "wxID_LABEL",  wxStaticText)->SetLabel( TtaConvMessageToWX( TtaGetMessage(AMAYA,AM_LOCATION) ));
  XRCCTRL(*this, "wxID_OK",     wxButton)->SetLabel( TtaConvMessageToWX( TtaGetMessage(LIB,TMSG_LIB_CONFIRM) ));
  XRCCTRL(*this, "wxID_BROWSE", wxButton)->SetLabel( TtaConvMessageToWX( TtaGetMessage(AMAYA,AM_BROWSE) ));
  XRCCTRL(*this, "wxID_CLICK",  wxButton)->SetLabel( TtaConvMessageToWX( TtaGetMessage(AMAYA,AM_CLICK) ));
  XRCCTRL(*this, "wxID_CLEAR",  wxButton)->SetLabel( TtaConvMessageToWX( TtaGetMessage(AMAYA,AM_CLEAR) ));
  XRCCTRL(*this, "wxID_CANCEL", wxButton)->SetLabel( TtaConvMessageToWX( TtaGetMessage(LIB,TMSG_CANCEL) ));

  // fill the combobox with url list
  XRCCTRL(*this, "wxID_COMBOBOX",     wxComboBox)->Append(url_list);
  // initialize it
  XRCCTRL(*this, "wxID_COMBOBOX",     wxComboBox)->SetValue(wx_init_value);

  // give focus to ...
  //  XRCCTRL(*this, "wxID_COMBOBOX",     wxComboBox)->SetFocus();
  
  SetAutoLayout( TRUE );
}

/*----------------------------------------------------------------------
  Destructor.
  ----------------------------------------------------------------------*/
HRefDlgWX::~HRefDlgWX()
{
  /* do not call this one because it cancel the link creation */
  /*  ThotCallback (m_Ref, INTEGER_DATA, (char*) 0);*/
}

/*----------------------------------------------------------------------
  OnOk called when the user validates his selection
  params:
  returns:
  ----------------------------------------------------------------------*/
void HRefDlgWX::OnOk( wxCommandEvent& event )
{
  // get the combobox current url
  wxString url = XRCCTRL(*this, "wxID_COMBOBOX", wxComboBox)->GetValue( );

  // allocate a temporary buffer to copy the 'const char *' url buffer 
  char buffer[512];
  wxASSERT( url.Len() < 512 );
  strcpy( buffer, (const char*)url.mb_str(wxConvUTF8) );

  // give the new url to amaya (to do url completion)
  ThotCallback (BaseDialog + AttrHREFText, STRING_DATA, (char *)buffer);
  // create or load the new document
  ThotCallback (m_Ref, INTEGER_DATA, (char*)1);
}

/*----------------------------------------------------------------------
  OnBrowse called when the user wants to search for a local file
  params:
  returns:
  ----------------------------------------------------------------------*/
void HRefDlgWX::OnBrowse( wxCommandEvent& event )
{
  // Create a generic filedialog
  wxFileDialog * p_dlg = new wxFileDialog
    (
     this,
     TtaConvMessageToWX( TtaGetMessage (AMAYA, AM_OPEN_URL) ),
     _T(""),
     _T(""), 
     m_Filter,
     wxOPEN | wxCHANGE_DIR /* wxCHANGE_DIR -> remember the last directory used. */
     );

  // do not force the directory, let wxWidgets choose for the current one
  //  p_dlg->SetDirectory(wxGetHomeDir());
  
  if (p_dlg->ShowModal() == wxID_OK)
    {
      XRCCTRL(*this, "wxID_COMBOBOX",     wxComboBox)->SetValue( p_dlg->GetPath() );
      // destroy the dlg before calling thotcallback because it's a child of this
      // dialog and thotcallback will delete the dialog...
      // so if I do not delete it manualy here it will be deleted twice
      p_dlg->Destroy();
      // simulate the confirm command
      OnOk( event );
    }
  else
    {
      p_dlg->Destroy();
    }
}

/*----------------------------------------------------------------------
  OnCancel called when the user clicks on cancel button
  params:
  returns:
  ----------------------------------------------------------------------*/
void HRefDlgWX::OnCancel( wxCommandEvent& event )
{
  // this callback is called into AmayaDialog::OnClose
  // usefull to cancel the link creation process
  //  ThotCallback (m_Ref, INTEGER_DATA, (char*) 0);
  Close();
}

/*----------------------------------------------------------------------
  OnClick called when the user clicks on click button : wants to click a document
  params:
  returns:
  ----------------------------------------------------------------------*/
void HRefDlgWX::OnClick( wxCommandEvent& event )
{
  ThotCallback (m_Ref, INTEGER_DATA, (char*) 3);
}

/*----------------------------------------------------------------------
  OnClear called when the user clicks on clear button
  params:
  returns:
  ----------------------------------------------------------------------*/
void HRefDlgWX::OnClear( wxCommandEvent& event )
{
  ThotCallback (m_Ref, INTEGER_DATA, (char*) 4);
  XRCCTRL(*this, "wxID_COMBOBOX", wxComboBox)->SetValue( _T("") );
}

#endif /* _WX */
