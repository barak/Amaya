#ifdef _WX

#include "wx/wx.h"
#include "wx/xrc/xmlres.h"              // XRC XML resouces
#include "wx/string.h"

#include "AmayaApp.h"
#include "OpenDocDlgWX.h"

#define THOT_EXPORT extern
#include "amaya.h"
#include "appdialogue_wx.h"
#include "message_wx.h"
#include "thot_sys.h"
static int      Waiting = 0;
static int      MyRef = 0;
static ThotBool Mandatory_title = FALSE;
static char    *compound_string;

//-----------------------------------------------------------------------------
// Event table: connect the events to the handler functions to process them
//-----------------------------------------------------------------------------
BEGIN_EVENT_TABLE(OpenDocDlgWX, AmayaDialog)
  EVT_BUTTON(     XRCID("wxID_OK"),              OpenDocDlgWX::OnOpenButton )
  EVT_BUTTON(     XRCID("wxID_CLEAR"),           OpenDocDlgWX::OnClearButton )
  EVT_BUTTON(     XRCID("wxID_CANCEL"),          OpenDocDlgWX::OnCancelButton )
  EVT_BUTTON(     XRCID("wxID_BUTTON_DIR"),      OpenDocDlgWX::OnDirButton )
  EVT_BUTTON(     XRCID("wxID_BUTTON_FILENAME"), OpenDocDlgWX::OnFilenameButton )
  EVT_TEXT_ENTER( XRCID("wxID_COMBOBOX"),        OpenDocDlgWX::OnOpenButton )
  EVT_COMBOBOX( XRCID("wxID_COMBOBOX"),          OpenDocDlgWX::OnURLSelected )
  EVT_TEXT_ENTER( XRCID("wxID_DIR"),             OpenDocDlgWX::OnOpenButton )
  EVT_COMBOBOX( XRCID("wxID_PROFILE"),           OpenDocDlgWX::OnProfileSelected )

  EVT_TEXT( XRCID("wxID_DIR"),      OpenDocDlgWX::OnText_Dir )
  EVT_TEXT( XRCID("wxID_COMBOBOX"), OpenDocDlgWX::OnText_Combobox )
END_EVENT_TABLE()

/*----------------------------------------------------------------------
  OpenDocDlgWX create the dialog used to select a new document
  notice: the combobox is not filled in the constructor, it's filled in wxdialogapi.c
  params:
    + parent : parent window
    + title : dialog title
    + docName : ??? not used
  returns:
  ----------------------------------------------------------------------*/
OpenDocDlgWX::OpenDocDlgWX( int ref, wxWindow* parent, const wxString & title,
                            const wxString & docName, const wxArrayString & urlList,
                            const wxString & urlToOpen, const wxString & filter,
                            int * p_last_used_filter, const wxString & profiles,
                            int newfile) :
  AmayaDialog( parent, ref )
  ,m_Filter(filter)
  ,m_LockUpdateFlag(false)
  ,m_pLastUsedFilter(p_last_used_filter)
{
  char   *s;

  wxXmlResource::Get()->LoadDialog(this, parent, wxT("OpenDocDlgWX"));
  // waiting for a return
  Waiting = 1;
  MyRef = ref;
  compound_string = TtaGetMessage(AMAYA,AM_COMPOUND_DOCUMENT);

  // update dialog labels with given ones
  SetTitle( title );
  XRCCTRL(*this, "wxID_OK", wxButton)->SetLabel( TtaConvMessageToWX( TtaGetMessage(AMAYA,AM_OPEN_URL) ));
  XRCCTRL(*this, "wxID_CLEAR", wxButton)->SetLabel( TtaConvMessageToWX( TtaGetMessage(AMAYA,AM_CLEAR) ));
  XRCCTRL(*this, "wxID_CANCEL", wxButton)->SetLabel( TtaConvMessageToWX( TtaGetMessage(LIB,TMSG_CANCEL) ));
  XRCCTRL(*this, "wxID_RADIOBOX", wxRadioBox)->SetString(0, TtaConvMessageToWX(TtaGetMessage(AMAYA,AM_REPLACECURRENT)));
  XRCCTRL(*this, "wxID_RADIOBOX", wxRadioBox)->SetString(1, TtaConvMessageToWX(TtaGetMessage(AMAYA,AM_INNEWTAB)));
  XRCCTRL(*this, "wxID_RADIOBOX", wxRadioBox)->SetString(2, TtaConvMessageToWX(TtaGetMessage(AMAYA,AM_INNEWWINDOW)));
  XRCCTRL(*this, "wxID_BUTTON_FILENAME", wxBitmapButton)->SetToolTip(TtaConvMessageToWX(TtaGetMessage(AMAYA,AM_BROWSE)));

  if (newfile)
    {
      // New HTML document
      XRCCTRL(*this, "wxID_LABEL_DIR", wxStaticText)->SetLabel(TtaConvMessageToWX(TtaGetMessage(AMAYA,AM_DIRECTORY)));
      XRCCTRL(*this, "wxID_BUTTON_DIR", wxBitmapButton)->SetToolTip(TtaConvMessageToWX(TtaGetMessage(LIB,TMSG_SEL)));

      // document charset
      XRCCTRL(*this, "wxID_CHARSET", wxStaticText)->SetLabel( TtaConvMessageToWX(TtaGetMessage(AMAYA, AM_DOCINFO_CHARSET)) );
      s = TtaGetEnvString ("DOCUMENT_CHARSET");
      if (s && s[0] != EOS)
        XRCCTRL(*this, "wxID_CHOICE_CHARSET", wxChoice)->SetStringSelection(TtaConvMessageToWX(s));
      else
        XRCCTRL(*this, "wxID_CHOICE_CHARSET", wxChoice)->SetStringSelection( TtaConvMessageToWX("iso-8859-1") );
      if (profiles.IsEmpty())
        {
          // not a new HTML document
          Mandatory_title = FALSE;
          XRCCTRL(*this, "wxID_LABEL_TITLE", wxStaticText)->Hide();
          XRCCTRL(*this, "wxID_TITLE", wxTextCtrl)->Hide();
          XRCCTRL(*this, "wxID_PROFILE", wxComboBox)->Hide();
          XRCCTRL(*this, "wxID_PROFILE_LABEL", wxStaticText)->Hide();
          XRCCTRL(*this, "wxID_ERROR", wxStaticText)->Hide();
          GetSizer()->SetSizeHints( this );
        }
      else
        {
          // document title
          Mandatory_title = TRUE;
          XRCCTRL(*this, "wxID_LABEL_TITLE", wxStaticText)->SetLabel(TtaConvMessageToWX(TtaGetMessage(AMAYA, AM_BM_TITLE)));
          XRCCTRL(*this, "wxID_TITLE", wxTextCtrl)->SetValue(TtaConvMessageToWX(""));
          XRCCTRL(*this, "wxID_ERROR", wxStaticText)->SetLabel( TtaConvMessageToWX(""));
          // Get the last selected profile
          XRCCTRL(*this, "wxID_PROFILE_LABEL", wxStaticText)->SetLabel(TtaConvMessageToWX(TtaGetMessage(AMAYA,AM_XML_PROFILE)));
          s = TtaGetEnvString ("XHTML_Profile");
          XRCCTRL(*this, "wxID_PROFILE", wxComboBox)->Append(TtaConvMessageToWX(compound_string));
          if (s && s[0] != EOS)
            XRCCTRL(*this, "wxID_PROFILE", wxComboBox)->SetValue(TtaConvMessageToWX(s));
          else
            XRCCTRL(*this, "wxID_PROFILE", wxComboBox)->SetValue( profiles );
        }
    }
  else
    {
      // Not a new HTML document
      Mandatory_title = FALSE;
      XRCCTRL(*this, "wxID_LABEL_DIR", wxStaticText)->Hide();
      XRCCTRL(*this, "wxID_DIR", wxTextCtrl)->Hide();
      XRCCTRL(*this, "wxID_BUTTON_DIR", wxBitmapButton)->Hide();
      XRCCTRL(*this, "wxID_LABEL_TITLE", wxStaticText)->Hide();
      XRCCTRL(*this, "wxID_TITLE", wxTextCtrl)->Hide();
      XRCCTRL(*this, "wxID_CHARSET", wxStaticText)->Hide();
      XRCCTRL(*this, "wxID_CHOICE_CHARSET", wxChoice)->Hide();
      XRCCTRL(*this, "wxID_PROFILE", wxComboBox)->Hide();
      XRCCTRL(*this, "wxID_PROFILE_LABEL", wxStaticText)->Hide();
      XRCCTRL(*this, "wxID_ERROR", wxStaticText)->Hide();
      GetSizer()->SetSizeHints( this );
    }

  // get the default NEW_LOCATION value : in new tab
  int where_to_open_doc;
  TtaGetEnvInt("NEW_LOCATION", &where_to_open_doc);
  XRCCTRL(*this, "wxID_RADIOBOX", wxRadioBox)->SetSelection(where_to_open_doc);

  // setup combobox values
  XRCCTRL(*this, "wxID_COMBOBOX", wxComboBox)->Append( urlList );
  XRCCTRL(*this, "wxID_COMBOBOX", wxComboBox)->SetValue( urlToOpen );
#if defined(_WINDOW) || defined(_MACOS)
  // select the string
  XRCCTRL(*this, "wxID_COMBOBOX", wxComboBox)->SetSelection(0, -1);
#else /* _WINDOW || _MACOS */
  // set te cursor to the end
  XRCCTRL(*this, "wxID_COMBOBOX", wxComboBox)->SetInsertionPointEnd();
  #endif /* _WINDOW || _MACOS */
  UpdateDirFromString( urlToOpen );

  // dir separator
  wxChar dir_sep = DIR_SEP;
  m_DirSep = wxString(dir_sep);

  Fit();
  Refresh();
  SetAutoLayout( TRUE );
}

/*----------------------------------------------------------------------
  Destructor. (Empty, as I don't need anything special done when destructing).
  ----------------------------------------------------------------------*/
OpenDocDlgWX::~OpenDocDlgWX()
{
  /* when the dialog is destroyed, It's important to cleanup context */
  if (Waiting)
    // no return done
    ThotCallback (MyRef, INTEGER_DATA, (char*) 0);
  else
    // clean up the dialog context
    TtaDestroyDialogue (MyRef);
}

/*----------------------------------------------------------------------
  OnDirButton called when the user want to change the folder
  params:
  returns:
  ----------------------------------------------------------------------*/
void OpenDocDlgWX::OnDirButton( wxCommandEvent& event )
{
  // Create a generic filedialog
  wxDirDialog * p_dlg = new wxDirDialog(this);
  //  p_dlg->SetStyle(p_dlg->GetStyle() | wxDD_NEW_DIR_BUTTON);
  p_dlg->SetPath(XRCCTRL(*this, "wxID_DIR", wxTextCtrl)->GetValue());
  if (p_dlg->ShowModal() == wxID_OK)
    {
      XRCCTRL(*this, "wxID_DIR", wxTextCtrl)->SetValue( p_dlg->GetPath() );
      p_dlg->Destroy();
    }
  else
    p_dlg->Destroy();
}

/*----------------------------------------------------------------------
  OnFilenameButton called when the user want to change the filename
  to an existing one with the filebrowser
  params:
  returns:
  ----------------------------------------------------------------------*/
void OpenDocDlgWX::OnFilenameButton( wxCommandEvent& event )
{

  // Create a generic filedialog
  wxFileDialog * p_dlg = new wxFileDialog
    (this,
     TtaConvMessageToWX( TtaGetMessage (AMAYA, AM_OPEN_URL) ),
     _T(""),
     _T(""),
     m_Filter,
     wxOPEN | wxCHANGE_DIR /* remember last directory */);

  // get the combobox current url
  wxString url = XRCCTRL(*this, "wxID_COMBOBOX", wxComboBox)->GetValue( );
  if (url.StartsWith(_T("http")) ||
      url.StartsWith(TtaConvMessageToWX((TtaGetEnvString ("THOTDIR")))))
    p_dlg->SetDirectory(wxGetHomeDir());
  else
    p_dlg->SetPath(url);
  p_dlg->SetFilterIndex(*m_pLastUsedFilter);

  if (p_dlg->ShowModal() == wxID_OK)
    {
      *m_pLastUsedFilter = p_dlg->GetFilterIndex();
      XRCCTRL(*this, "wxID_COMBOBOX", wxComboBox)->SetValue( p_dlg->GetPath() );
      XRCCTRL(*this, "wxID_COMBOBOX", wxComboBox)->SetInsertionPointEnd();
      UpdateDirFromString( p_dlg->GetPath() );
      p_dlg->Destroy();
    }
  else
    p_dlg->Destroy();
}

/*----------------------------------------------------------------------
  UpdateComboboxFromDirAndFilename
  params:
  returns:
  ----------------------------------------------------------------------*/
void OpenDocDlgWX::UpdateComboboxFromDirAndFilename()
{
  if (!m_LockUpdateFlag)
    {
      wxString full_path = XRCCTRL(*this, "wxID_COMBOBOX", wxComboBox)->GetValue();
      int end_slash_pos = full_path.Find(DIR_SEP, true);
      m_LockUpdateFlag = true;
      wxString dir_value = XRCCTRL(*this, "wxID_DIR", wxTextCtrl)->GetValue();
      wxString filename_value = full_path.SubString(end_slash_pos+1, full_path.Length());
#ifdef _WINDOWS
      if (dir_value.IsEmpty())
        dir_value = _T("C:\\");
#endif /* _WINDOWS */
      if (dir_value.Last() != m_DirSep)
        dir_value += m_DirSep;
      XRCCTRL(*this, "wxID_COMBOBOX", wxComboBox)->SetValue( dir_value + filename_value );
      XRCCTRL(*this, "wxID_COMBOBOX", wxComboBox)->SetInsertionPointEnd();
      m_LockUpdateFlag = false;
    }
}

/*----------------------------------------------------------------------
  UpdateDirFromString
  params:
  returns:
  ----------------------------------------------------------------------*/
void OpenDocDlgWX::UpdateDirFromString( const wxString & full_path )
{
  if (!m_LockUpdateFlag)
    {
      m_LockUpdateFlag = true;
      if (!full_path.StartsWith(_T("http")))
        {
          int end_slash_pos = full_path.Find(DIR_SEP, true);
          wxString dir_value = full_path.SubString(0, end_slash_pos);
          XRCCTRL(*this, "wxID_DIR", wxTextCtrl)->SetValue(dir_value);
        }
      else
        XRCCTRL(*this, "wxID_DIR", wxTextCtrl)->Clear();
      m_LockUpdateFlag = false;
    }
}


/*----------------------------------------------------------------------
  OnOpenButton called when the user validate his selection
  params:
  returns:
  ----------------------------------------------------------------------*/
void OpenDocDlgWX::OnOpenButton( wxCommandEvent& event )
{
  wxString        value, title;
  char            buffer[MAX_LENGTH];
  int             where_id;

  if (!Waiting)
    // no return done
    return;

  // get the selected charset
  value = XRCCTRL(*this, "wxID_CHOICE_CHARSET", wxChoice)->GetStringSelection();
  strcpy (buffer, (const char*)value.mb_str(wxConvUTF8));
  TtaSetEnvString ("DOCUMENT_CHARSET", buffer, TRUE);

  // get the combobox current url
  value = XRCCTRL(*this, "wxID_COMBOBOX", wxComboBox)->GetValue( );
  // Get the document title
  if (Mandatory_title)
    {
      // get the document title
      title = XRCCTRL(*this, "wxID_TITLE", wxTextCtrl)->GetValue( );
      if (title.Len() == 0)
        {
          if (Waiting == 1)
            {
              // request the title
              XRCCTRL(*this, "wxID_ERROR", wxStaticText)->SetLabel( TtaConvMessageToWX(TtaGetMessage (AMAYA, AM_MISSING_TITLE)));
              Waiting = 2;
              return;
            }
          else
            {
              // use default title
              int end_slash_pos = value.Find(DIR_SEP, true);
              m_LockUpdateFlag = true;
              title = value.SubString(end_slash_pos+1, value.Length());
              m_LockUpdateFlag = false;
              strncpy( buffer, (const char*)title.mb_str(wxConvUTF8), MAX_LENGTH - 1);
              buffer[MAX_LENGTH - 1] = EOS;
              ThotCallback (BaseDialog + TitleText,  STRING_DATA, (char *)buffer);
            }
        }
      else
        {
          strncpy( buffer, (const char*)title.mb_str(wxConvUTF8), MAX_LENGTH - 1);
          buffer[MAX_LENGTH - 1] = EOS;
          ThotCallback (BaseDialog + TitleText,  STRING_DATA, (char *)buffer);
        }
    }

  // give the new url to amaya (to do url completion)
  strncpy (buffer, (const char*)value.mb_str(wxConvUTF8), MAX_LENGTH - 1);
  buffer[MAX_LENGTH - 1] = EOS;
  ThotCallback (BaseDialog + URLName,  STRING_DATA, (char *)buffer );

  // get the "where to open" indicator
  where_id = XRCCTRL(*this, "wxID_RADIOBOX", wxRadioBox)->GetSelection();
  ThotCallback (BaseDialog + OpenLocation , INTEGER_DATA, (char*)where_id);

  // get the combobox profile
  value = XRCCTRL(*this, "wxID_PROFILE", wxComboBox)->GetValue( );
  if (!value.IsEmpty())
    {
      strcpy( buffer, (const char*)value.mb_str(wxConvUTF8) );
      // give the profile to amaya
      TtaSetEnvString ("XHTML_Profile", buffer, TRUE);
      ThotCallback (BaseDialog + DocInfoDocType,  STRING_DATA, (char *)buffer );
    }

  // return done
  Waiting = 0;
  // create or load the new document
  ThotCallback (MyRef, INTEGER_DATA, (char*)1);

  /* The dialogue is no longer destroyed in the callback to prevent a crash on Mac */
  TtaDestroyDialogue (MyRef);
}

/*----------------------------------------------------------------------
  OnClearButton called when the user wants to clear each fields
  params:
  returns:
  ----------------------------------------------------------------------*/
void OpenDocDlgWX::OnClearButton( wxCommandEvent& event )
{
  XRCCTRL(*this, "wxID_COMBOBOX", wxComboBox)->SetValue(_T(""));
  XRCCTRL(*this, "wxID_DIR", wxTextCtrl)->Clear();
}

/*----------------------------------------------------------------------
  OnCancelButton called when the user click on cancel button
  params:
  returns:
  ----------------------------------------------------------------------*/
void OpenDocDlgWX::OnCancelButton( wxCommandEvent& event )
{
  // return done
  Waiting = 0;
  ThotCallback (MyRef, INTEGER_DATA, (char*) 0);
}

/*----------------------------------------------------------------------
  Class:  OpenDocDlgWX
  Method:  OnURLSelected
  Description:  update the filename and dir fields
  ----------------------------------------------------------------------*/
void OpenDocDlgWX::OnURLSelected( wxCommandEvent& event )
{
#ifndef _WINDOWS
  XRCCTRL(*this, "wxID_COMBOBOX", wxComboBox)->SetInsertionPointEnd();
#endif /* _WINDOWS */
}

/*----------------------------------------------------------------------
  Class:  OpenDocDlgWX
  Method:  OnProfileSelected
  Description:  select the profile
  ----------------------------------------------------------------------*/
void OpenDocDlgWX::OnProfileSelected( wxCommandEvent& event )
{
  wxString     url;
  char         buffer[MAX_LENGTH], suffix[MAX_LENGTH];
  ThotBool     iscompound;

  wxString value = XRCCTRL(*this, "wxID_PROFILE", wxComboBox)->GetValue( );
  if (!value.IsEmpty())
    {
      strcpy (buffer, (const char*)value.mb_str(wxConvUTF8));
      iscompound = !strcmp (buffer, compound_string);
      url = XRCCTRL(*this, "wxID_COMBOBOX", wxComboBox)->GetValue( );
      // check the suffix
      strncpy( buffer, (const char*)url.mb_str(wxConvUTF8), MAX_LENGTH - 1);
      buffer[MAX_LENGTH - 1] = EOS;
      TtaExtractSuffix (buffer, suffix);
      if (iscompound)
        {
          if (strcmp (suffix, "xml"))
            {
              strcat (buffer, ".xml");
              XRCCTRL(*this, "wxID_COMBOBOX", wxComboBox)->SetValue(TtaConvMessageToWX(buffer));
            }
          
          // check the charset
          XRCCTRL(*this, "wxID_CHOICE_CHARSET", wxChoice)->SetStringSelection(TtaConvMessageToWX("utf-8"));
        }
      else if (!strcmp (suffix, "xml"))
        {
          strcat (buffer, ".html");
          XRCCTRL(*this, "wxID_COMBOBOX", wxComboBox)->SetValue(TtaConvMessageToWX(buffer));
        }

    }
}


/*----------------------------------------------------------------------
  Class:  OpenDocDlgWX
  Method:  OnText_Dir
  Description:  update the dir
  ----------------------------------------------------------------------*/
void OpenDocDlgWX::OnText_Dir( wxCommandEvent& event )
{
  UpdateComboboxFromDirAndFilename();
  event.Skip();
}

/*----------------------------------------------------------------------
  Class:  OpenDocDlgWX
  Method:  OnText_Combobox
  Description: select an URL
  ----------------------------------------------------------------------*/
void OpenDocDlgWX::OnText_Combobox( wxCommandEvent& event )
{
  UpdateDirFromString( XRCCTRL(*this, "wxID_COMBOBOX", wxComboBox)->GetValue() );
  event.Skip();
}

#endif /* _WX */
