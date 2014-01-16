#ifdef _WX

#include "wx/wx.h"
#include "wx/xrc/xmlres.h"              // XRC XML resouces

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
#include "paneltypes_wx.h"
#include "colors_f.h"
#include "containers.h"
#include "inites_f.h"
#include "presentmenu_f.h"

#include "Elemlist.h"

#include "AmayaXMLPanel.h"
#include "AmayaNormalWindow.h"
#include "AmayaFloatingPanel.h"
#include "AmayaSubPanelManager.h"

IMPLEMENT_DYNAMIC_CLASS(AmayaXMLPanel, AmayaSubPanel)

/*----------------------------------------------------------------------
 *       Class:  AmayaXMLPanel
 *      Method:  AmayaXMLPanel
 * Description:  construct a panel (bookmarks, elements, attributes, colors ...)
  -----------------------------------------------------------------------*/
AmayaXMLPanel::AmayaXMLPanel( wxWindow * p_parent_window, AmayaNormalWindow * p_parent_nwindow )
  : AmayaSubPanel( p_parent_window, p_parent_nwindow, _T("wxID_PANEL_XML") )
    ,m_XMLRef(0)
    ,m_fnCallback(NULL)
{
  // setup labels
  RefreshToolTips();
  m_pTitleText->SetLabel(TtaConvMessageToWX(TtaGetMessage(LIB, TMSG_EL_TYPE)));

  m_pXMLList = XRCCTRL(*m_pPanelContentDetach,"wxID_LIST_XML",wxListBox);

  // register myself to the manager, so I will be avertised that another panel is floating ...
  m_pManager->RegisterSubPanel( this );
  // Do not refresh
  //RefreshXMLPanel();
}

/*----------------------------------------------------------------------
 *       Class:  AmayaXMLPanel
 *      Method:  ~AmayaXMLPanel
 * Description:  destructor
  -----------------------------------------------------------------------*/
AmayaXMLPanel::~AmayaXMLPanel()
{  
  // unregister myself to the manager, so nothing should be asked to me in future
  m_pManager->UnregisterSubPanel( this );
}

/*----------------------------------------------------------------------
 *       Class:  AmayaXMLPanel
 *      Method:  GetPanelType
 * Description:  
  -----------------------------------------------------------------------*/
int AmayaXMLPanel::GetPanelType()
{
  return WXAMAYA_PANEL_XML;
}

/*----------------------------------------------------------------------
 *       Class:  AmayaXMLPanel
 *      Method:  RefreshToolTips
 * Description:  reassign the tooltips values
  -----------------------------------------------------------------------*/
void AmayaXMLPanel::RefreshToolTips()
{  
  //  XRCCTRL(*m_pPanelContentDetach,"wxID_LIST_XML",wxListBox)->SetToolTip(TtaConvMessageToWX(TtaGetMessage(LIB,TMSG_SEL)));
  XRCCTRL(*m_pPanelContentDetach,"wxID_REFRESH",wxBitmapButton)->SetToolTip(TtaConvMessageToWX(TtaGetMessage(LIB,TMSG_REFRESH)));
  XRCCTRL(*m_pPanelContentDetach,"wxID_APPLY",wxBitmapButton)->SetToolTip(TtaConvMessageToWX(TtaGetMessage(LIB,TMSG_APPLY)));
}

/*----------------------------------------------------------------------
 *       Class:  AmayaXMLPanel
 *      Method:  SendDataToPanel
 * Description:  refresh the button widgets of the frame's panel
  -----------------------------------------------------------------------*/
void AmayaXMLPanel::SendDataToPanel( AmayaParams& p )
{
  int nb_el = (int)p.param1;
  m_fnCallback = (void*) p.param3;
  
  if(nb_el==-1){
    DLList list = (DLList) p.param2;
    DLList reflist = DLList_GetRefList(list, (Container_CompareFunction)ElemListElement_Compare);
    ForwardIterator iter = DLList_GetForwardIterator(reflist);
    ContainerNode node;
    ElemListElement elem;

    m_pXMLList->Clear();    
    node = ForwardIterator_GetFirst(iter);
    while(node)
    {
      elem = (ElemListElement)node->elem;
      
// TODO removed code because not showing other than DefinedComponent
//      wxString str = TtaConvMessageToWX(ElemListElement_GetName(elem));
//      if(elem->typeClass==LanguageElement)
//      {
//        str.Prepend(TtaConvMessageToWX( TtaGetSSchemaName(elem->elem.element.type.ElSSchema)) + wxT(":"));
//      }
//      if(elem->comment)
//      {
//        str.append(wxT(" (") + TtaConvMessageToWX( elem->comment) + wxT(")"));
//      }
//      m_pXMLList->Append( str , (void*)elem);

      if(elem && elem->typeClass==DefinedComponent)
      {
        wxString str = TtaConvMessageToWX(ElemListElement_GetName(elem));
        if(elem->comment)
        {
          str.append(wxT(" (") + TtaConvMessageToWX( elem->comment) + wxT(")"));
        }
        m_pXMLList->Append( str , (void*)elem);
      }

      node = ForwardIterator_GetNext(iter);
    }
    
    TtaFreeMemory(iter);
    DLList_Destroy(reflist);
    
  }
}

/*----------------------------------------------------------------------
 *       Class:  AmayaXMLPanel
 *      Method:  DoUpdate
 * Description:  force a refresh when the user expand or detach this panel
  -----------------------------------------------------------------------*/
void AmayaXMLPanel::DoUpdate()
{
//  AmayaSubPanel::DoUpdate();
//
//  // refresh the liste when the panel is expanded or detached.
//  Document doc;
//  View view;
//  TtaGetActiveView( &doc, &view );
//  if (doc > 0)
//    TtaRefreshElementMenu( doc, view );
}

/*----------------------------------------------------------------------
 *       Class:  AmayaXMLPanel
 *      Method:  IsActive
 * Description:  
  -----------------------------------------------------------------------*/
bool AmayaXMLPanel::IsActive()
{
  return AmayaSubPanel::IsActive();
}

/*----------------------------------------------------------------------
 *       Class:  AmayaXMLPanel
 *      Method:  OnApply
 * Description:  
  -----------------------------------------------------------------------*/
void AmayaXMLPanel::OnApply( wxCommandEvent& event )
{
  ElemListElement elem = NULL;
  
  ThotCallback(m_XMLRef, INTEGER_DATA, (char*) 1);
  
  if(m_pXMLList && m_pXMLList->GetSelection()!=wxNOT_FOUND)
  {
    elem = (ElemListElement)m_pXMLList->GetClientData(m_pXMLList->GetSelection());
    if(elem){
      printf("must insert : %s !\n", ElemListElement_GetName(elem));
      if(m_fnCallback)
        ((ElemListElement_DoInsertElementFunction)m_fnCallback)(elem);
    }
  }
}

/*----------------------------------------------------------------------
 *       Class:  AmayaXMLPanel
 *      Method:  OnSelected
 * Description:  
  -----------------------------------------------------------------------*/
void AmayaXMLPanel::OnSelected( wxCommandEvent& event )
{
  wxString s_selected = XRCCTRL(*this, "wxID_LIST_XML", wxListBox)->GetStringSelection();
  
  // allocate a temporary buffer
  char buffer[512];
  wxASSERT( s_selected.Len() < 512 );
  strcpy( buffer, (const char*)s_selected.mb_str(wxConvUTF8) );
  
  // call the callback : send the selected string 
  ThotCallback(m_XMLRef+1, STRING_DATA, buffer);
}



/*----------------------------------------------------------------------
 *       Class:  AmayaXMLPanel
 *      Method:  OnRefresh
 * Description:  refresh the panel from current selection
  -----------------------------------------------------------------------*/
void AmayaXMLPanel::OnRefresh( wxCommandEvent& event )
{
  RefreshXMLPanel();
}

/*----------------------------------------------------------------------
 *       Class:  AmayaXMLPanel
 *      Method:  RefreshXMLPanel
 * Description:  refresh the panel from current selection
  -----------------------------------------------------------------------*/
void AmayaXMLPanel::RefreshXMLPanel()
{
  Document doc;
  View view;
  TtaGetActiveView( &doc, &view );
  if (doc > 0)
    TtaRefreshElementMenu (doc, view);
}

/*----------------------------------------------------------------------
 *  this is where the event table is declared
 *  the callbacks are assigned to an event type
 *----------------------------------------------------------------------*/
BEGIN_EVENT_TABLE(AmayaXMLPanel, AmayaSubPanel)
  EVT_BUTTON( XRCID("wxID_APPLY"), AmayaXMLPanel::OnApply )
  EVT_BUTTON( XRCID("wxID_REFRESH"), AmayaXMLPanel::OnRefresh )
  EVT_LISTBOX( XRCID("wxID_LIST_XML"), AmayaXMLPanel::OnSelected ) 
  EVT_LISTBOX_DCLICK( XRCID("wxID_LIST_XML"), AmayaXMLPanel::OnApply )
END_EVENT_TABLE()

#endif /* #ifdef _WX */
