#ifdef _WX
#include "wx/wx.h"
#include "file_filters.h"
#include "registry_wx.h"
#endif /* _WX */

#define THOT_EXPORT extern
#include "amaya.h"
#include "css.h"
#include "style.h"

#include "appdialogue_wx.h"
#include "message_wx.h"
#include "file_filters.h"
#include "init_f.h"
#include "HTMLsave_f.h"
#include "styleparser_f.h"
#include "containers.h"


#ifdef _WX
  #include "wxdialog/AuthentDlgWX.h"
  #include "wxdialog/CheckedListDlgWX.h"
  #include "wxdialog/CreateTableDlgWX.h"
  #include "wxdialog/DocInfoDlgWX.h"
  #include "wxdialog/FontDlgWX.h"
  #include "wxdialog/HRefDlgWX.h"
  #include "wxdialog/ImageDlgWX.h"
  #include "wxdialog/InitConfirmDlgWX.h"
  #include "wxdialog/ListDlgWX.h"
  #include "wxdialog/ListEditDlgWX.h"
  #include "wxdialog/MakeIdDlgWX.h"
  #include "wxdialog/ObjectDlgWX.h"
  #include "wxdialog/OpenDocDlgWX.h"
  #include "wxdialog/PreferenceDlgWX.h"
  #include "wxdialog/PrintDlgWX.h"
  #include "wxdialog/SaveAsDlgWX.h"
  #include "wxdialog/SelectFenceAttributesDlgWX.h"
  #include "wxdialog/SelectOperatorDlgWX.h"
  #include "wxdialog/SelectIntegralDlgWX.h"
  #include "wxdialog/SearchDlgWX.h"
  #include "wxdialog/SendByMailDlgWX.h"
  #include "wxdialog/SpellCheckDlgWX.h"
  #include "wxdialog/StyleDlgWX.h"
  #include "wxdialog/TitleDlgWX.h"

  #include "wx/numdlg.h"

static StyleDlgWX *Style_dlg = NULL;

#endif /* _WX */


// this global is used to remember the last filter when using a filebrowser
int g_Last_used_filter = 0;
int img_Last_used_filter = 0;
int obj_Last_used_filter = 0;
int link_Last_used_filter = 0;

/*----------------------------------------------------------------------
  ----------------------------------------------------------------------*/
void ShowMessage(const char* message, const char* title)
{
  
  wxMessageDialog messagedialog( NULL,
         TtaConvMessageToWX(message),
         TtaConvMessageToWX(title),
         (long) wxOK | wxICON_EXCLAMATION | wxSTAY_ON_TOP);
  messagedialog.ShowModal();
}


/*----------------------------------------------------------------------
  ParseStyleDlgValues: parse a CSS Style string to update the Style
  dialog
  ----------------------------------------------------------------------*/
void  ParseStyleDlgValues (void *style_widget, char *cssRule)
{
#ifdef _WX
  Document        doc;
  GenericContext  ctxt;

  Style_dlg = (StyleDlgWX *)style_widget;
  /* store the current line for eventually reported errors */
  /* create the context of the Specific presentation driver */
  ctxt = TtaGetGenericStyleContext (0);
  if (ctxt == NULL)
    return;
  ctxt->type = 0;
  ctxt->cssSpecificity = 0;
  ctxt->cssLine = 0;
  ctxt->destroy = FALSE;
  doc = TtaGetSelectedDocument();
  if (doc)
    ctxt->doc = doc;
  /* first use of the context */
  ctxt->uses = 1;
  DoDialog = TRUE; /* update the CSS dialog */
  /* Call the parser */
  ParseCSSRule (NULL, NULL, (PresentationContext) ctxt, cssRule, NULL, TRUE);
  DoDialog = FALSE;
  /* check if the context can be freed */
  ctxt->uses -= 1;
  if (ctxt->uses == 0)
    /* no image loading */
    TtaFreeMemory(ctxt);
  Style_dlg = NULL;
#endif /* _WX */
}

/*----------------------------------------------------------------------
  DisplayStyleValue: update the property in Style dialog
  ----------------------------------------------------------------------*/
void  DisplayStyleValue (const char *property, char *start_value, char *end_value)
{
#ifdef _WX
  char c = EOS;

  if (Style_dlg)
    {
      if (end_value)
        {
          c = *end_value;
          if (c != EOS)
            *end_value = EOS;
        }
      Style_dlg->SetValue (property, start_value);
      if (end_value && c != *end_value)
        *end_value = c;
    }
#endif /* _WX */
}

/*----------------------------------------------------------------------
  ----------------------------------------------------------------------*/
#ifdef _WX
wxArrayString BuildWX_URL_List( const char * url_list )
{
  /* Create the url list array */
  /* will stop on double EOS */
  wxArrayString wx_items;
  int index = 0;
  while (url_list[index] != EOS)
    {
      wx_items.Add( TtaConvMessageToWX( &url_list[index] ) );
      index += strlen (&url_list[index]) + 1; /* one entry length */
    }
  return wx_items;
}
#endif /* _WX */



/*----------------------------------------------------------------------
  CreateSelectOperatorDlgWX
  params:
    + the thotlib catalog reference
    + parent : parent window
  returns:
    + true : the dialogue has been created
    + false : error, nothing is created
  ----------------------------------------------------------------------*/
ThotBool CreateSelectOperatorDlgWX ( int ref, ThotWindow parent)
{
#ifdef _WX
  /* check if the dialog is alredy open */
  if (TtaRaiseDialogue (ref))
    return FALSE;


  SelectOperatorDlgWX * p_dlg = new SelectOperatorDlgWX(
      ref, /* thotlib catalog reference */
      parent/* parent window */);

  if ( TtaRegisterWidgetWX( ref, p_dlg ) )
      /* the dialog has been sucessfully registred */
      return TRUE;
  else
    {
      /* an error occured during registration */
      p_dlg->Destroy();
      return FALSE;
    }
#else /* _WX */
  return FALSE;
#endif /* _WX */
}

/*----------------------------------------------------------------------
  CreateSelectFenceAttributesDlgWX
  params:
    + the thotlib catalog reference
    + parent : parent window
  returns:
    + true : the dialogue has been created
    + false : error, nothing is created
  ----------------------------------------------------------------------*/
ThotBool CreateSelectFenceAttributesDlgWX ( int ref, ThotWindow parent)
{
#ifdef _WX
  /* check if the dialog is alredy open */
  if (TtaRaiseDialogue (ref))
    return FALSE;


  SelectFenceAttributesDlgWX * p_dlg = new SelectFenceAttributesDlgWX(
      ref, /* thotlib catalog reference */
      parent/* parent window */);

  if ( TtaRegisterWidgetWX( ref, p_dlg ) )
      /* the dialog has been sucessfully registred */
      return TRUE;
  else
    {
      /* an error occured during registration */
      p_dlg->Destroy();
      return FALSE;
    }
#else /* _WX */
  return FALSE;
#endif /* _WX */
}

/*----------------------------------------------------------------------
  CreateSelectIntegralDlgWX
  params:
    + the thotlib catalog reference
    + parent : parent window
  returns:
    + true : the dialogue has been created
    + false : error, nothing is created
  ----------------------------------------------------------------------*/
ThotBool CreateSelectIntegralDlgWX ( int ref, ThotWindow parent)
{
#ifdef _WX
  /* check if the dialog is alredy open */
  if (TtaRaiseDialogue (ref))
    return FALSE;


  SelectIntegralDlgWX * p_dlg = new SelectIntegralDlgWX(
      ref, /* thotlib catalog reference */
      parent/* parent window */);

  if ( TtaRegisterWidgetWX( ref, p_dlg ) )
      /* the dialog has been sucessfully registred */
      return TRUE;
  else
    {
      /* an error occured during registration */
      p_dlg->Destroy();
      return FALSE;
    }
#else /* _WX */
  return FALSE;
#endif /* _WX */
}

/*----------------------------------------------------------------------
  CreateInitConfirmDlgWX create the dialog for document changes
  (save/not save) comfirmation.
  params:
    + the thotlib catalog reference
    + parent : parent window
    + title : dialog title
    + extrabutton : if it is present there is 3 button
    + confirmbutton : 
    + label : the message to show at dialog center
  returns:
    + true : the dialogue has been created
    + false : error, nothing is created
  ----------------------------------------------------------------------*/
ThotBool CreateInitConfirmDlgWX ( int ref, ThotWindow parent,
				  char *title, char *extrabutton, char *confirmbutton,
				  char *label, char *label2, char *label3 )
{
#ifdef _WX
  /* check if the dialog is alredy open */
  if (TtaRaiseDialogue (ref))
    return FALSE;

  wxString wx_label = TtaConvMessageToWX( label );
  wxString wx_label2 = TtaConvMessageToWX( label2 );
  wxString wx_label3 = TtaConvMessageToWX( label3 );
  wxString wx_title = TtaConvMessageToWX( TtaGetMessage (LIB, TMSG_LIB_CONFIRM) );
  wxString wx_extrabutton;
  wxString wx_confirmbutton;

  if (extrabutton && extrabutton[0] != EOS)
    /* a message with 3 buttons */
    wx_extrabutton = TtaConvMessageToWX( extrabutton );
  else
    /* just 2 buttons */
    wx_extrabutton = TtaConvMessageToWX( "" );

  if (confirmbutton && confirmbutton[0] != EOS)
    wx_confirmbutton = TtaConvMessageToWX( confirmbutton );
  else
    wx_confirmbutton = TtaConvMessageToWX( "" );

  InitConfirmDlgWX * p_dlg = new InitConfirmDlgWX(
      ref, /* thotlib catalog reference */
      parent, /* parent window */
      wx_title, /* title */
      wx_extrabutton,
      wx_confirmbutton,
      wx_label, wx_label2, wx_label3 ); /* message label2 */

  if ( TtaRegisterWidgetWX( ref, p_dlg ) )
      /* the dialog has been sucessfully registred */
      return TRUE;
  else
    {
      /* an error occured during registration */
      p_dlg->Destroy();
      return FALSE;
    }
#else /* _WX */
  return FALSE;
#endif /* _WX */
}

/*----------------------------------------------------------------------
  CreateOpenDocDlgWX create the dialog for openging new documents
  params:
    + parent : parent window
    + title : dialog title
    + listUrl : the url list to show in the combobox
  returns:
  ----------------------------------------------------------------------*/
ThotBool CreateOpenDocDlgWX ( int ref, ThotWindow parent, const char *title,
                              const char *urlList, const char *urlToOpen,
                              DocumentType doc_type, int doc, ThotBool newfile)
{
#ifdef _WX

  /* check if the dialog is alredy open */
  if (TtaRaiseDialogue (ref))
    return FALSE;

  wxString wx_title     = TtaConvMessageToWX( title );
  wxString wx_urlToOpen = TtaConvMessageToWX( urlToOpen );
  wxString wx_filter;
  wxString wx_profiles = _T("");

  if (doc_type == docHTML)
    {
    wx_filter = APPHTMLNAMEFILTER;
    if (newfile)
      /* create a new HTML document: activate the list of profiles */
      wx_profiles = _T("XHTML Transitional");
    }
  else if (doc_type == docMath)
    wx_filter = APPMATHNAMEFILTER;
  else if (doc_type == docSVG)
    wx_filter = APPSVGNAMEFILTER;
  else if (doc_type == docCSS)
    {
      wx_filter = APPCSSNAMEFILTER;
    }
  else if (doc_type == docImage)
    wx_filter = APPIMAGENAMEFILTER;
  else if (doc_type == docImage)
    wx_filter = APPIMAGENAMEFILTER;
  else if (doc_type == docLibrary)
    wx_filter = APPLIBRARYNAMEFILTER;
  else 
    {
      wx_filter = APPFILENAMEFILTER;
    }

  OpenDocDlgWX * p_dlg = new OpenDocDlgWX( ref, NULL/*parent*/,
                                           wx_title,
                                           BuildWX_URL_List(urlList),
                                           wx_urlToOpen,
                                           wx_filter,
                                           &g_Last_used_filter,
                                           wx_profiles, doc, newfile);

  if ( TtaRegisterWidgetWX( ref, p_dlg ) )
      /* the dialog has been sucesfully registred */
      return TRUE;
  else
    {
      /* an error occured durring registration */
      p_dlg->Destroy();
      return FALSE;
    }
#else /* _WX */
  return FALSE;
#endif /* _WX */
}


/*----------------------------------------------------------------------
  CreateImageDlgWX create the dialog for creating new image
  params:
    + parent : parent window
    + title : dialog title
    + urlToOpen : suggested url
  returns:
  ----------------------------------------------------------------------*/
ThotBool CreateImageDlgWX (int ref, ThotWindow parent, const char *title,
                           const char *urlToOpen, const char *alt)
{
#ifdef _WX
  /* check if the dialog is alredy open */
  if (TtaRaiseDialogue (ref))
    return FALSE;

  wxString wx_title   = TtaConvMessageToWX( title );
  wxString wx_urlToOpen = TtaConvMessageToWX( urlToOpen );
  wxString wx_alt = TtaConvMessageToWX( alt );
  wxString wx_filter = APPIMAGENAMEFILTER;
  ImageDlgWX * p_dlg = new ImageDlgWX( ref,
                                       parent,
                                       wx_title,
                                       wx_urlToOpen,
                                       wx_alt,
                                       wx_filter,
                                       &img_Last_used_filter
                                       );

  if ( TtaRegisterWidgetWX( ref, p_dlg ) )
    /* the dialog has been sucesfully registred */
    return TRUE;
  else
    {
      /* an error occured durring registration */
      p_dlg->Destroy();
      return FALSE;
    }
#else /* _WX */
  return FALSE;
#endif /* _WX */
}

/*----------------------------------------------------------------------
  CreateObjectDlgWX create the dialog for creating new object
  params:
    + parent : parent window
    + title : dialog title
    + urlToOpen : suggested url
  returns:
  ----------------------------------------------------------------------*/
ThotBool CreateObjectDlgWX (int ref, ThotWindow parent, const char *title,
                            const char *urlToOpen, const char *type)
{
#ifdef _WX
  /* check if the dialog is alredy open */
  if (TtaRaiseDialogue (ref))
    return FALSE;

  wxString wx_title   = TtaConvMessageToWX( title );
  wxString wx_urlToOpen = TtaConvMessageToWX( urlToOpen );
  wxString wx_type = TtaConvMessageToWX( type );
  wxString wx_filter = APPIMAGENAMEFILTER;
  ObjectDlgWX * p_dlg = new ObjectDlgWX( ref,
                                         parent,
                                         wx_title,
                                         wx_urlToOpen,
                                         wx_type,
                                         wx_filter,
                                         &obj_Last_used_filter );

  if ( TtaRegisterWidgetWX( ref, p_dlg ) )
    /* the dialog has been sucesfully registred */
    return TRUE;
  else
    {
      /* an error occured durring registration */
      p_dlg->Destroy();
      return FALSE;
    }
#else /* _WX */
  return FALSE;
#endif /* _WX */
}

/*----------------------------------------------------------------------
  CreateTitleDlgWX create the dialog to change the document title
  params:
    + doc_title : the current document title
  returns:
  ----------------------------------------------------------------------*/
ThotBool CreateTitleDlgWX (int ref, ThotWindow parent, char *doc_title)
{
#ifdef _WX
  /* check if the dialog is alredy open */
  if (TtaRaiseDialogue (ref))
    return FALSE;

  wxString wx_title     = TtaConvMessageToWX( TtaGetMessage (AMAYA, AM_CHANGE_TITLE) );
  wxString wx_doc_title = TtaConvMessageToWX( doc_title );

  TitleDlgWX * p_dlg = new TitleDlgWX( ref,
				       parent,
				       wx_title,
				       wx_doc_title );

  if ( TtaRegisterWidgetWX( ref, p_dlg ) )
      /* the dialog has been sucesfully registred */
      return TRUE;
  else
    {
      /* an error occured durring registration */
      p_dlg->Destroy();
      return FALSE;
    }
#else /* _WX */
  return FALSE;
#endif /* _WX */
}

/*----------------------------------------------------------------------
  CreateMakeIdDlgWX create the dialog to Add/Remove IDs
  returns:
  ----------------------------------------------------------------------*/
ThotBool CreateMakeIdDlgWX (int ref, ThotWindow parent)
{
#ifdef _WX
  /* check if the dialog is alredy open */
  if (TtaRaiseDialogue (ref))
    return FALSE;

  MakeIdDlgWX * p_dlg = new MakeIdDlgWX (ref, parent);
  if ( TtaRegisterWidgetWX( ref, p_dlg ) )
      /* the dialog has been sucesfully registred */
      return TRUE;
  else
    {
      /* an error occured durring registration */
      p_dlg->Destroy();
      return FALSE;
    }
#else /* _WX */
  return FALSE;
#endif /* _WX */
}

/*----------------------------------------------------------------------
  CreateSearchDlgWX create the Search dialog
  params:
    + caption : the caption (including the document title)
    + searched : the initial searched string
    + replace : the  initial replace string
  returns:
  ----------------------------------------------------------------------*/
ThotBool CreateSearchDlgWX (int ref, ThotWindow parent,  char* caption,
                            char* searched,  char* replace,
                            ThotBool withReplace, ThotBool searchAfter)
{
#ifdef _WX
  /* check if the dialog is alredy open */
  if (TtaRaiseDialogue (ref))
    return FALSE;

  wxString wx_caption = TtaConvMessageToWX( caption );
  wxString wx_searched = TtaConvMessageToWX( searched );
  wxString wx_replace = TtaConvMessageToWX( replace );

  SearchDlgWX * p_dlg = new SearchDlgWX( ref,
					 NULL,
					 wx_caption,
					 wx_searched,
					 wx_replace,
					 withReplace,
					 searchAfter );

  if ( TtaRegisterWidgetWX( ref, p_dlg ) )
    /* the dialog has been sucesfully registred */
    return TRUE;
  else
    {
      /* an error occured durring registration */
      p_dlg->Destroy();
      return FALSE;
    }
#else /* _WX */
  return FALSE;
#endif /* _WX */
}

/*----------------------------------------------------------------------
  CreatePrintDlgWX create the SearchSetupAndPrint dialog
  params:
    + ps_file : postscript file
  returns:
  ----------------------------------------------------------------------*/
ThotBool CreatePrintDlgWX (int ref, ThotWindow parent, char* printer_file,
                           char* ps_file, int paper_format, int orientation,
                           int disposition, int paper_print, ThotBool manual_feed,
                           ThotBool with_toc, ThotBool with_links,
                           ThotBool with_url, ThotBool ignore_css)
{
#ifdef _WX
  /* check if the dialog is alredy open */
  if (TtaRaiseDialogue (ref))
    return FALSE;

  wxString wx_printer_file = TtaConvMessageToWX( printer_file );
  wxString wx_ps_file = TtaConvMessageToWX( ps_file );

  PrintDlgWX * p_dlg = new PrintDlgWX( ref,
				       parent,
				       wx_printer_file,
				       wx_ps_file,
				       paper_format,
				       orientation,
				       disposition,
				       paper_print,
				       manual_feed,
				       with_toc,
				       with_links,
				       with_url,
				       ignore_css );

  if ( TtaRegisterWidgetWX( ref, p_dlg ) )
      /* the dialog has been sucesfully registred */
      return TRUE;
  else
    {
      /* an error occured durring registration */
      p_dlg->Destroy();
      return FALSE;
    }
#else /* _WX */
  return FALSE;
#endif /* _WX */
}

/*----------------------------------------------------------------------
  CreateSaveAsDlgWX create the SaveAs dialog
  params:
    + pathname : file location
  returns:
  ----------------------------------------------------------------------*/
ThotBool CreateSaveAsDlgWX (int ref, ThotWindow parent, char* pathname,
                            int doc, ThotBool saveImgs, ThotBool checkTemplate)
{
#ifdef _WX
  /* check if the dialog is alredy open */
  if (TtaRaiseDialogue (ref))
    return FALSE;

  wxString wx_pathname = TtaConvMessageToWX( pathname );
  SaveAsDlgWX * p_dlg = new SaveAsDlgWX( ref, parent, wx_pathname, doc,
                                         saveImgs, checkTemplate);

  if ( TtaRegisterWidgetWX( ref, p_dlg ) )
      /* the dialog has been sucesfully registred */
      return TRUE;
  else
    {
      /* an error occured durring registration */
      p_dlg->Destroy();
      return FALSE;
    }
#else /* _WX */
  return FALSE;
#endif /* _WX */
}

/*----------------------------------------------------------------------
  CreateSaveObject create the SaveAs dialog
  params:
    + pathname : file location
  returns:
  ----------------------------------------------------------------------*/
ThotBool CreateSaveObject (int ref, ThotWindow parent, char* objectname)
{
#ifdef _WX
#ifdef _MACOS
  wxString homedir = TtaGetHomeDir();
  strcpy (SavePath, (const char *)homedir.mb_str(wxConvUTF8));
  strcat (SavePath, "/Desktop/");
  if (TtaCheckMakeDirectory (SavePath, TRUE))
    {
      strcat (SavePath, objectname);
      DoSaveObjectAs ();
      SavingObject = 0;
      return FALSE;
    }
  #endif /* _MACOS */
  // Create a generic filedialog
  wxString      wx_filter = APPFILENAMEFILTER;
  wxFileDialog *p_dlg = new wxFileDialog (
                                          parent,
                                          TtaConvMessageToWX( TtaGetMessage (AMAYA, AM_OBJECT_LOCATION) ),
                                          _T(""),
                                          TtaConvMessageToWX( objectname ),
                                          wx_filter,
                                          wxSAVE | wxCHANGE_DIR /* remember the last directory used. */
                                          );

  // do not force the directory, let wxWidgets choose for the current one
  // p_dlg->SetDirectory(wxGetHomeDir());
  if (p_dlg->ShowModal() == wxID_OK)
    {
      wxString url = p_dlg->GetPath();
      // allocate a temporary buffer to copy the 'const char *' url buffer 
      strncpy( SavePath, (const char*)url.mb_str(wxConvUTF8), MAX_LENGTH-1);
      SavePath[MAX_LENGTH-1] = EOS;
      // destroy the dlg before calling thotcallback because it's a child of this
      // dialog and thotcallback will delete the dialog...
      // so if I do not delete it manualy here it will be deleted twice
      p_dlg->Destroy();
      // create or load the new document
      ThotCallback (ref, INTEGER_DATA, (char*)1);
    }
  else
    {
      p_dlg->Destroy();
      ThotCallback (ref, INTEGER_DATA, (char*)0);
    }
  return TRUE;
#else /* _WX */
  return FALSE;
#endif /* _WX */
}

/*----------------------------------------------------------------------
  CreateAuthentDlgWX create the Authentification dialog
  params:
    + pathname : file location
  returns:
  ----------------------------------------------------------------------*/
ThotBool CreateAuthentDlgWX (int ref, ThotWindow parent,
                             char *auth_realm, char *server,
			     char *name, char *pwd)
{
#ifdef _WX
  /* check if the dialog is alredy open */
  if (TtaRaiseDialogue (ref))
    return FALSE;

  AuthentDlgWX * p_dlg = new AuthentDlgWX( ref,
					   parent,
					   auth_realm, server,
					   name, pwd);
  if ( TtaRegisterWidgetWX( ref, p_dlg ) )
      /* the dialog has been sucesfully registred */
      return TRUE;
  else
    {
      /* an error occured durring registration */
      p_dlg->Destroy();
      return FALSE;
    }
#else /* _WX */
  return FALSE;
#endif /* _WX */
}

/*----------------------------------------------------------------------
  CreateCSSDlgWX creates the open/enable/disable.. css files
  params:
  returns:
  ----------------------------------------------------------------------*/
ThotBool CreateCSSDlgWX (int ref, int subref, ThotWindow parent, char *title,
                         int nb_item, char *items)
{
#ifdef _WX
  wxArrayString wx_items;
  wxString      wx_title  = TtaConvMessageToWX( title );
  
  /* build the css filename list */
  int i = 0;
  int index = 0;
  while (i < nb_item && items[index] != EOS)
    {
      wx_items.Add( TtaConvMessageToWX( &items[index] ) );
      index += strlen (&items[index]) + 1; /* one entry length */
      i++;
    }

  if ( nb_item <= 0 )
    {
      ShowMessage(TtaGetMessage(AMAYA, AM_NO_CSS), title);
      return FALSE;
    }

  /* check if the dialog is alredy open */
  if (TtaRaiseDialogue (ref))
    return FALSE;

  /* create the dialog */
  ListDlgWX * p_dlg = new ListDlgWX( ref, subref, parent,
				     wx_title,
				     wx_items );

  if ( TtaRegisterWidgetWX( ref, p_dlg ) )
      /* the dialog has been sucesfully registred */
      return TRUE;
  else
    {
      /* an error occured durring registration */
      p_dlg->Destroy();
      return FALSE;
    }
#else /* _WX */
  return FALSE;
#endif /* _WX */  
}



/*----------------------------------------------------------------------
  ShowNonSelListDlgWX
  ----------------------------------------------------------------------*/
void ShowNonSelListDlgWX (ThotWindow parent, char *title, char* label, 
                          char *button, void* strings)
{
#ifdef _WX
  wxString      wx_title  = TtaConvMessageToWX( title );
  wxString      wx_label  = TtaConvMessageToWX( label );
  wxString      wx_button = TtaConvMessageToWX( button );
  wxArrayString wx_items;
  
  ForwardIterator  iter = DLList_GetForwardIterator((DLList)strings);
  DLListNode       node;
  const char*      str;
  
  ITERATOR_FOREACH(iter, DLListNode, node)
    {
      str = (const char*)node->elem;
      if(str)
        wx_items.Add(TtaConvMessageToWX(str));
    }
  TtaFreeMemory(iter);

  NonSelListDlgWX dlg(parent, wx_title, wx_label, wx_items, wx_button);
  dlg.ShowModal();
#endif /* _WX */  
}




/*----------------------------------------------------------------------
  CreateListDlgWX proposes 
  params:
  returns:
  ----------------------------------------------------------------------*/
ThotBool CreateListDlgWX (int ref, int subref, ThotWindow parent, char *title,
                          int nb_item, char *items)
{
#ifdef _WX
  wxString      wx_title = TtaConvMessageToWX( title );
  wxArrayString wx_items;
  
  /* build the css filename list */
  int i = 0;
  int index = 0;
  while (i < nb_item && items[index] != EOS)
    {
      wx_items.Add( TtaConvMessageToWX( &items[index] ) );
      index += strlen (&items[index]) + 1; /* one entry length */
      i++;
    }

  if ( nb_item <= 0 )
    {
      ShowMessage(TtaGetMessage(AMAYA, AM_NO_CSS), title);
      return FALSE;
    }

  /* check if the dialog is alredy open */
  if (TtaRaiseDialogue (ref))
    return FALSE;

  /* create the dialog */
  ListDlgWX * p_dlg = new ListDlgWX( ref, subref, parent,
				     wx_title,
				     wx_items );

  if ( TtaRegisterWidgetWX( ref, p_dlg ) )
      /* the dialog has been sucesfully registred */
      return TRUE;
  else
    {
      /* an error occured durring registration */
      p_dlg->Destroy();
      return FALSE;
    }
#else /* _WX */
  return FALSE;
#endif /* _WX */  
}

/*----------------------------------------------------------------------
  CreateCheckedListDlgWX creates the open/enable/disable.. css files
  params:
  returns:
  ----------------------------------------------------------------------*/
ThotBool CreateCheckedListDlgWX (int ref, ThotWindow parent, char *title,
                                 int nb_item, char *items, ThotBool *checks)
{
#ifdef _WX
  wxString      wx_title = TtaConvMessageToWX( title );
  wxArrayString wx_items;
  
  /* build the css filename list */
  int i = 0;
  int index = 0;
  while (i < nb_item && items[index] != EOS)
    {
      wx_items.Add( TtaConvMessageToWX( &items[index] ) );
      index += strlen (&items[index]) + 1; /* one entry length */
      i++;
    }

  if ( nb_item )
    {
      /* check if the dialog is alredy open */
      if (TtaRaiseDialogue (ref))
	return FALSE;

      /* create the dialog */
      CheckedListDlgWX * p_dlg = new CheckedListDlgWX( ref,
						       parent,
						       wx_title,
						       nb_item,
						       wx_items,
						       (bool *)checks);
      
      if ( TtaRegisterWidgetWX( ref, p_dlg ) )
	/* the dialog has been sucesfully registred */
	return TRUE;
      else
	/* an error occured durring registration */
	p_dlg->Destroy();
    }
  return FALSE;
#else /* _WX */
  return FALSE;
#endif /* _WX */  
}

/*----------------------------------------------------------------------
  CreateDocInfoDlgWX create the Documnent Infos dialog
  ----------------------------------------------------------------------*/
ThotBool CreateDocInfoDlgWX (int ref, ThotWindow parent, int doc)
{
#ifdef _WX
  /* check if the dialog is alredy open */
  if (TtaRaiseDialogue (ref))
    return FALSE;

  DocInfoDlgWX * p_dlg = new DocInfoDlgWX( ref,
					   parent,
					   doc );
  if ( TtaRegisterWidgetWX( ref, p_dlg ) )
      /* the dialog has been sucesfully registred */
      return TRUE;
  else
    {
      /* an error occured durring registration */
      p_dlg->Destroy();
      return FALSE;
    }
#else /* _WX */
  return FALSE;
#endif /* _WX */
}

/*-----------------------------------------------------------------------
 CreateHRefDlgWX
 Used to :
  - Add CSS file
  - Create/Modify a link
  - Add Javascript file
 ------------------------------------------------------------------------*/
ThotBool CreateHRefDlgWX (int ref, ThotWindow parent,
                          const char *url_list, const char *HRefValue,
                          Document doc, int doc_type)
{
#ifdef _WX
  wxString wx_title      = TtaConvMessageToWX( TtaGetMessage (AMAYA, AM_LINK) );
  wxString wx_init_value = TtaConvMessageToWX( HRefValue );
  wxString wx_filter;
  if (doc_type == docCSS)
    wx_filter = APPCSSNAMEFILTER;
  else if (doc_type == docJavascript)
    wx_filter = APPJAVASCRIPTNAMEFILTER;
  else
    wx_filter = APPFILENAMEFILTER;

  wxArrayString wx_items = BuildWX_URL_List(url_list);

  /* check if the dialog is already open */
  if (TtaRaiseDialogue (ref))
    return FALSE;

  HRefDlgWX * p_dlg = new HRefDlgWX( ref,
                                     parent,
                                     wx_title,
                                     wx_items,
                                     wx_init_value,
                                     wx_filter,
                                     &link_Last_used_filter,
                                     doc);

  if ( TtaRegisterWidgetWX( ref, p_dlg ) )
    /* the dialog has been sucesfully registred */
    return TRUE;
  else
    {
      /* an error occured durring registration */
      p_dlg->Destroy();
      return FALSE;
    }
#else /* _WX */
  return FALSE;
#endif /* _WX */
}

/*----------------------------------------------------------------------
  ImageDlgWX create the dialog for enter a text (generic)
  params:
    + parent : parent window
    + title : dialog title
    + value : init value
  returns:
  ----------------------------------------------------------------------*/
static char Buffer[512];
ThotBool CreateTextDlgWX (int ref, int subref, ThotWindow parent,
                          const char *title, const char *label,
                          const char *value)
{
  wxString wx_title   = TtaConvMessageToWX( title );
  wxString wx_label   = TtaConvMessageToWX( label );
  wxString wx_value = TtaConvMessageToWX( value );

  
  wxTextEntryDialog dlg(parent, wx_label, wx_title, wx_value);
  if(dlg.ShowModal()==wxID_OK)
    {
      wx_value = dlg.GetValue();
      wxASSERT( wx_value.Len() < 512 );
      strcpy( Buffer, (const char*)wx_value.mb_str(wxConvUTF8) );
      ThotCallback (subref, STRING_DATA, (char *)Buffer);
      ThotCallback (ref, INTEGER_DATA, (char*)1);
    }

  return TRUE;
}

/*-----------------------------------------------------------------------
 CreateCreateTableDlgWX
 params: nb of cols, nb of rows, border attribute
 ------------------------------------------------------------------------*/
ThotBool CreateCreateTableDlgWX (int ref, ThotWindow parent,
                                 int def_cols, int def_rows, int def_border)
{
#ifdef _WX

  /* check if the dialog is alredy open */
  if (TtaRaiseDialogue (ref))
    return FALSE;

  wxString wx_title = TtaConvMessageToWX( TtaGetMessage (LIB, TMSG_BUTTON_TABLE) );
  CreateTableDlgWX * p_dlg = new CreateTableDlgWX( ref,
						   parent,
						   def_cols,
						   def_rows,
						   def_border,
						   wx_title );
  if ( TtaRegisterWidgetWX( ref, p_dlg ) )
      /* the dialog has been sucesfully registred */
      return TRUE;
  else
    {
      /* an error occured durring registration */
      p_dlg->Destroy();
      return FALSE;
    }
#else /* _WX */
  return FALSE;
#endif /* _WX */
}

/*-----------------------------------------------------------------------
 CreatePreferenceDlgWX
 Used to :
  - Change Amaya configuration options
 ------------------------------------------------------------------------*/
ThotBool CreatePreferenceDlgWX (int ref, ThotWindow parent,
                                const char *url_list)
{
#ifdef _WX

  /* check if the dialog is alredy open */
  if (TtaRaiseDialogue (ref))
    return FALSE;

  wxArrayString wx_items = BuildWX_URL_List(url_list);
  PreferenceDlgWX * p_dlg = new PreferenceDlgWX( ref,
						 parent,
						 wx_items);
  if ( TtaRegisterWidgetWX( ref, p_dlg ) )
      /* the dialog has been sucesfully registred */
      return TRUE;
  else
    {
      /* an error occured durring registration */
      p_dlg->Destroy();
      return FALSE;
    }
#else /* _WX */
  return FALSE;
#endif /* _WX */
}

/*-----------------------------------------------------------------------
 CreateSpellCheckDlgWX
 Used to :
  - Create the Spell Checker Amaya dialog
 ------------------------------------------------------------------------*/
ThotBool CreateSpellCheckDlgWX (int ref, int base, ThotWindow parent,
                                int checkingArea)
{
#ifdef _WX
  /* check if the dialog is alredy open */
  if (TtaRaiseDialogue (ref))
    return FALSE;

  SpellCheckDlgWX * p_dlg = new SpellCheckDlgWX( ref, base, parent,
						 checkingArea);
  if ( TtaRegisterWidgetWX( ref, p_dlg ) )
      /* the dialog has been sucesfully registred */
      return TRUE;
  else
    {
      /* an error occured durring registration */
      p_dlg->Destroy();
      return FALSE;
    }
#else /* _WX */
  return FALSE;
#endif /* _WX */
}

/*-----------------------------------------------------------------------
 CreateStyleDlgWX
 Used to :
  - Create the Style Amaya dialog
 ------------------------------------------------------------------------*/
ThotBool CreateStyleDlgWX (int ref, ThotWindow parent)
{
#ifdef _WX
  /* check if the dialog is alredy open */
  if (TtaRaiseDialogue (ref))
    return FALSE;

  StyleDlgWX * p_dlg = new StyleDlgWX( ref, parent);
  if ( TtaRegisterWidgetWX( ref, p_dlg ) )
      /* the dialog has been sucesfully registred */
      return TRUE;
  else
    {
      /* an error occured durring registration */
      p_dlg->Destroy();
      return FALSE;
    }
#else /* _WX */
  return FALSE;
#endif /* _WX */
}

/*----------------------------------------------------------------------
  CreateListEditDlgWX proposes (generic way)
  params:
  returns:
  ----------------------------------------------------------------------*/
ThotBool CreateListEditDlgWX (int ref, ThotWindow parent,
                              const char *title, const char * list_title,
                              int nb_item, const char *items, const char *selected_item)
{
#ifdef _WX
  wxString      wx_title         = TtaConvMessageToWX( title );
  wxString      wx_selected_item = TtaConvMessageToWX( selected_item );
  wxString      wx_list_title    = TtaConvMessageToWX( list_title );
  wxArrayString wx_items;
  
  /* convert the (char *) list to wxArrayString */
  int i = 0;
  int index = 0;
  while (i < nb_item && items[index] != EOS)
    {
      wx_items.Add( TtaConvMessageToWX( &items[index] ) );
      index += strlen (&items[index]) + 1; /* one entry length */
      i++;
    }

  /* check if the dialog is alredy open */
  if (TtaRaiseDialogue (ref))
    return FALSE;

  /* create the dialog */
  ListEditDlgWX * p_dlg = new ListEditDlgWX( ref, parent,
					     wx_title,
					     wx_list_title,
					     wx_items,
					     wx_selected_item );

  if ( TtaRegisterWidgetWX( ref, p_dlg ) )
      /* the dialog has been sucesfully registred */
      return TRUE;
  else
    {
      /* an error occured durring registration */
      p_dlg->Destroy();
      return FALSE;
    }
#else /* _WX */
  return FALSE;
#endif /* _WX */  
}

/*----------------------------------------------------------------------
  CreateEnumListDlgWX is a generic enum list
  params:
  returns:
  ----------------------------------------------------------------------*/
ThotBool CreateEnumListDlgWX (int ref, int subref, ThotWindow parent,
                              const char *title, const char *label,
                              int nb_item, const char *items,
                              int selection)
{
  wxString      wx_title = TtaConvMessageToWX( title );
  wxString      wx_label = TtaConvMessageToWX( label );
  wxArrayString wx_items;
  
  /* build the enum list strings */
  int i = 0;
  int index = 0;
  while (i < nb_item && items[index] != EOS)
    {
      wx_items.Add( TtaConvMessageToWX( &items[index] ) );
      index += strlen (&items[index]) + 1; /* one entry length */
      i++;
    }

  if ( nb_item <= 0 )
    {
      /* TODO: change the message when there is no items, should never occured */
      ShowMessage(TtaGetMessage(AMAYA, AM_NO_CSS), title);
      return FALSE;
    }  

  wxSingleChoiceDialog dlg(parent, wx_label, wx_title, wx_items);
  dlg.SetSelection(selection);
  if(dlg.ShowModal()==wxID_OK)
    {
      int id = dlg.GetSelection();
      if(id!=wxNOT_FOUND)
        {
          ThotCallback (subref, INTEGER_DATA, (char*)id);
          ThotCallback (ref, INTEGER_DATA, (char*)1);
        }
    }
  return TRUE;
}

/*----------------------------------------------------------------------
  CreateNumDlgWX is a generic numeric dialog
  params:
  returns:
  ----------------------------------------------------------------------*/
ThotBool CreateNumDlgWX (int ref, int subref, ThotWindow parent,
                         const char *title, const char *label, int value)
{
  wxString      wx_title = TtaConvMessageToWX( title );
  wxString      wx_label = TtaConvMessageToWX( label );
  
  value = wxGetNumberFromUser(wx_label, wxT(""), wx_title, value, 0, 100, parent);
  
  if(value==wxNOT_FOUND)
    {
      if (ref == MathsDialogue + FormMaths)
        ThotCallback (ref, INTEGER_DATA, (char*)0);
    }
  else
    {
      if (ref == MathsDialogue + FormMaths)
          ThotCallback (ref, INTEGER_DATA, (char*)value);
      else
        {
          ThotCallback (subref, INTEGER_DATA, (char *)value);
          ThotCallback (ref, INTEGER_DATA, (char*)1);
        }
    }
  
  TtaRedirectFocus ();
  return TRUE;
}


/*----------------------------------------------------------------------
  CreateFontDlgWX
  ----------------------------------------------------------------------*/
ThotBool CreateFontDlgWX(ThotWindow parent, const char *title, int* family,
			 int* size)
{
  if (family && size)
    {
      wxString wx_title = TtaConvMessageToWX(title);
      FontDlgWX dlg (parent, wx_title);
      // manage the return of the modal dialog
      if (*family > 0)
        dlg.SetFontFamily(*family-1);
      if(*size > 0)
        dlg.SetFontSize(*size);
      if (dlg.ShowModal()==wxID_OK)
        {
          *family = dlg.GetFontFamily();
          *size = dlg.GetFontSize();
          return TRUE;
        }
    }
  return FALSE;
}

/*----------------------------------------------------------------------
  QueryStringFromUser
  ----------------------------------------------------------------------*/
void QueryStringFromUser(const char *label, const char *title, char* res, int sz)
{
  wxString str = wxGetTextFromUser(TtaConvMessageToWX(label), TtaConvMessageToWX(title));
  strncpy(res, (const char*)str.mb_str(wxConvUTF8), sz);
}
