#ifdef _WX
#include "wx/wx.h"

#include "thot_gui.h"
#include "thot_sys.h"
#include "constmedia.h"
#include "typemedia.h"
#include "frame.h"
#include "registry.h"
#include "appdialogue.h"
#include "message.h"
#include "dialogapi.h"
#include "application.h"
#include "appdialogue_wx.h"
#include "windowtypes_wx.h"
#include "registry_wx.h"
#include "logdebug.h"
#include "selection.h"

#include "callback_f.h"
#include "exceptions_f.h"
#include "structschema_f.h"
#include "structselect_f.h"

#include "appdialogue_wx_f.h"
#include "message_wx.h"
#include "AmayaPathControl.h"


#include <wx/tooltip.h>
#include <wx/listimpl.cpp>
WX_DEFINE_LIST(AmayaPathControlItemList);


/*------------------------------------------------------------------------------
  ----------------------------------------------------------------------------*/
AmayaPathControl::AmayaPathControl(wxWindow* parent, wxWindowID id,
                            const wxPoint& pos, const wxSize& size, long style):
wxControl(parent, id, pos, size, style),
m_focused(NULL),
m_height(0)
{
}

/*----------------------------------------------------------------------
  -----------------------------------------------------------------------*/
AmayaPathControl::~AmayaPathControl()
{
}

/*----------------------------------------------------------------------
  -----------------------------------------------------------------------*/
void AmayaPathControl::SetSelection(Element elem)
{
  wxClientDC          dc(this);
  PtrElement          pEl = (PtrElement)elem;
  PtrAttribute        pAttr;
  ElementType         elType;
  wxString            name;
  wxRect              rect;
  int                 length;
  char               *buffer = NULL;
  bool                xtiger, file = false;
  
  m_items.DeleteContents(true);
  m_items.clear();
  m_focused = NULL;
  m_height = 0;
  while (pEl)
    {  
      /** @see BuildSelectionMessage () */
      if (pEl->ElParent &&
          !HiddenType(pEl) &&
          (!pEl->ElTerminal ||
           (pEl->ElLeafType != LtText && pEl->ElLeafType != LtPicture)))
        {
          buffer = NULL;
          xtiger = (pEl->ElStructSchema && pEl->ElStructSchema->SsName &&
                    !strcmp (pEl->ElStructSchema->SsName, "Template"));
          if (xtiger)
            {
              // replace the element name byt the attribute value
              pAttr = GetAttrElementWithException (ExcGiveName, pEl);
              if (pAttr)
                {
                  length = TtaGetTextAttributeLength ((Attribute)pAttr);
                  buffer = (char *)TtaGetMemory (length + 1);
                  /* copy the NAME attribute into TargetName */
                  TtaGiveTextAttributeValue ((Attribute)pAttr, buffer, &length);
                }
            }
          else
            {
              // display the line number
              file = (pEl->ElStructSchema && pEl->ElStructSchema->SsName &&
                      !strcmp (pEl->ElStructSchema->SsName, "TextFile"));
              if (file)
                {
                  buffer = (char *)TtaGetMemory (20);
                  sprintf (buffer, "Line: %d", pEl->ElLineNb);
                }
            }
          if (buffer)
            {
              // replace the element name by the attribute value
              name = TtaConvMessageToWX(buffer);
              TtaFreeMemory (buffer);
              buffer = NULL;
            }
          else
            {
              elType = TtaGetElementType(Element(pEl));
              name = TtaConvMessageToWX(TtaGetElementTypeName(elType));
            }
          dc.GetTextExtent(name, &rect.width, &rect.height);
          AmayaPathControlItem* item = new AmayaPathControlItem;
          item->label = name;
          item->elem = Element(pEl);
          item->rect = rect;
          item->isXTiger = xtiger;
           m_items.Append(item);
          if (rect.height > m_height)
            m_height = rect.height;
        }
      if (file)
        // don't display the hierarchy
        pEl = NULL;
      else
        pEl = pEl->ElParent;
    }
  Refresh();
}  

/*----------------------------------------------------------------------
  -----------------------------------------------------------------------*/
void AmayaPathControl::OnDraw(wxPaintEvent& event)
{
  PreCalcPositions();
  
  wxPaintDC dc(this);
  wxSize sz = GetClientSize();
  
  static wxString sep = wxT("/"); 
  wxSize szSep;
  dc.GetTextExtent(sep, &szSep.x, &szSep.y);
  szSep.x += 4;
  static wxString dots = wxT("..."); 
  wxSize szDots;
  dc.GetTextExtent(dots, &szDots.x, &szDots.y);
  szDots.x += 4;
  
  int x = 0;
  bool bIsFirst = true;
  int y = (sz.y-m_height)/2;
  wxAmayaPathControlItemListNode *node = m_items.GetLast();
  while (node)
    {
      if (node->GetData()->rect.x >= 0)
        {
          if (!bIsFirst)
            {
              dc.DrawText(sep, x+2, y);
              x += szSep.x;
            }
          else
            bIsFirst = false;
          node->GetData()->Draw(dc, node->GetData() == m_focused);
          x += node->GetData()->rect.width;
        }
      else if (bIsFirst)
        {
          // display "..."
          dc.DrawText(dots, x+2, y);
          x = szDots.x;
          bIsFirst = false;
        }

      node = node->GetPrevious();
    }
}

/*----------------------------------------------------------------------
  -----------------------------------------------------------------------*/
void AmayaPathControl::PreCalcPositions()
{
  wxClientDC dc(this);
  wxSize sz = GetClientSize();
  int y = (sz.y-m_height)/2, x, dx;

  static wxString sep = wxT("/"); 
  wxSize szSep;
  dc.GetTextExtent(sep, &szSep.x, &szSep.y);
  szSep.x += 4;
  static wxString dots = wxT("..."); 
  wxSize szDots;
  dc.GetTextExtent(dots, &szDots.x, &szDots.y);
  szDots.x += 4;

  int cx = 0;
  wxAmayaPathControlItemListNode *node;
  node = m_items.GetLast();
  while (node)
    {
      // compute the initial position for each node
      node->GetData()->rect.x = cx;
      node->GetData()->rect.y = y;
      cx += node->GetData()->rect.width + szSep.x;    
      node = node->GetPrevious();
    }

  if (cx > sz.x)
    {
      // replace some nodes by ...
      dx = cx - sz.x + szDots.x;
      x = szDots.x;
      node = m_items.GetLast();
      while (node)
        {
          cx = node->GetData()->rect.x - dx;
          if (cx < szDots.x)
            // this node is not displayed
            node->GetData()->rect.x = cx - szDots.x;
          else
            {
              // adding p '/' before
              x += szSep.x;
              node->GetData()->rect.x = x;
              x += node->GetData()->rect.width;
            }
          node = node->GetPrevious();
        }
    }
}

/*----------------------------------------------------------------------
  -----------------------------------------------------------------------*/
void AmayaPathControlItem::Draw(wxDC& dc, bool isFocused)
{
  if (rect.x >= 0)
  {
    if (isFocused)
    {
      wxColour col = dc.GetTextForeground();
      dc.SetTextForeground(wxColour(255, 0, 0));
      dc.DrawText(label, rect.x, rect.y);
      dc.SetTextForeground(col);
    }
    else if (isXTiger)
    {
      wxColour col = dc.GetTextForeground();
      dc.SetTextForeground(wxColour(25, 142, 25));
      dc.DrawText(label, rect.x, rect.y);
      dc.SetTextForeground(col);
    }
    else
    {
      dc.DrawText(label, rect.x, rect.y);      
    }
  }
}


/*----------------------------------------------------------------------
  -----------------------------------------------------------------------*/
void AmayaPathControl::OnSize(wxSizeEvent& event)
{
  Refresh();
  event.Skip();
}

/*----------------------------------------------------------------------
  -----------------------------------------------------------------------*/
void AmayaPathControl::OnMouseMove(wxMouseEvent& event)
{
  wxPoint pos = event.GetPosition();
  if (!m_focused || pos.x < m_focused->rect.x ||
	  pos.x > m_focused->rect.x+m_focused->rect.width)
  {
    m_focused = NULL;
    
    wxAmayaPathControlItemListNode *node = m_items.GetLast();
    while(node!=NULL)
    {
      if(node->GetData()->rect.x >= 0)
      {
        if(pos.x >= node->GetData()->rect.x &&
			pos.x <= node->GetData()->rect.x+node->GetData()->rect.width)
        {
          m_focused = node->GetData();
          Refresh();
          return;
        }
      }
      node = node->GetPrevious();
    }
    Refresh();
  }
}

/*----------------------------------------------------------------------
  -----------------------------------------------------------------------*/
void AmayaPathControl::OnMouseEnter(wxMouseEvent& WXUNUSED(event))
{
}

/*----------------------------------------------------------------------
  -----------------------------------------------------------------------*/
void AmayaPathControl::OnMouseLeave(wxMouseEvent& WXUNUSED(event))
{
  m_focused = NULL;
  Refresh();
}

extern void SynchronizeAppliedStyle (NotifyElement *event);
/*----------------------------------------------------------------------
  -----------------------------------------------------------------------*/
void AmayaPathControl::OnMouseLeftUp(wxMouseEvent& event)
{
  NotifyElement       notifyEl;
  Document            doc;
  PtrElement          pEl;
  wxPoint             pos = event.GetPosition();
  wxAmayaPathControlItemListNode *node = m_items.GetLast();

  while (node)
    {
      if (node->GetData()->rect.x >= 0)
        {
          pEl = (PtrElement)node->GetData()->elem;
          if (pos.x >= node->GetData()->rect.x &&
             pos.x <= node->GetData()->rect.x+node->GetData()->rect.width)
            {
              doc = TtaGetDocument(node->GetData()->elem);
              if (doc)
                {
                  TtaSelectElementWithoutPath (doc, node->GetData()->elem);
                  TtaRedirectFocus ();
                  /* WARNING: just update applied style */
                  notifyEl.event = TteElemSelect;
                  notifyEl.document = doc;
                  notifyEl.element = (Element)pEl;
                  notifyEl.info = 0; /* not sent by undo */
                  notifyEl.elementType.ElTypeNum = pEl->ElTypeNumber;
                  notifyEl.elementType.ElSSchema = (SSchema) (pEl->ElStructSchema);
                  notifyEl.position = 0;
                  SynchronizeAppliedStyle (&notifyEl);
                  return;
                }
            }
        }
      node = node->GetPrevious();
    }  
  TtaRedirectFocus ();
}


/*----------------------------------------------------------------------
  -----------------------------------------------------------------------*/
BEGIN_EVENT_TABLE(AmayaPathControl, wxControl)
  EVT_PAINT(AmayaPathControl::OnDraw)
  EVT_SIZE(AmayaPathControl::OnSize)
  EVT_ENTER_WINDOW(AmayaPathControl::OnMouseEnter)
  EVT_LEAVE_WINDOW(AmayaPathControl::OnMouseLeave)
  EVT_MOTION(AmayaPathControl::OnMouseMove)
  EVT_LEFT_UP(AmayaPathControl::OnMouseLeftUp)
END_EVENT_TABLE()

#endif /* _WX */
