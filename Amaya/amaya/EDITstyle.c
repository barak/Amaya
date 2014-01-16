/*
 *
 *  (c) COPYRIGHT INRIA and W3C, 1996-2005
 *  Please first read the full copyright statement in file COPYRIGHT.
 *
 */

/*
 *
 * Authors: I. Vatton
 *
 */

#ifdef _WX
#include "wx/wx.h"
#endif /* _WX */
#include "constmenu.h"

#define THOT_EXPORT extern
#include "amaya.h"
#include "css.h"
#include "undo.h"
#include "MathML.h"
#ifdef _SVG
#include "SVG.h"
#endif
#include "fetchHTMLname.h"

#include "AHTURLTools_f.h"
#include "HTMLedit_f.h"
#include "HTMLimage_f.h"
#include "HTMLpresentation_f.h"
#include "UIcss_f.h"
#include "css_f.h"
#include "fetchHTMLname_f.h"
#include "fetchXMLname_f.h"
#include "html2thot_f.h"
#include "init_f.h"
#include "styleparser_f.h"
#ifdef _WINGUI
#include "wininclude.h"
#else /* _WINGUI */
#include "appdialogue_wx.h"
#endif /* _WINGUI */

#ifdef _WX
#include "wxdialogapi_f.h"
#include "paneltypes_wx.h"
#endif /* _WX */


static char         ListBuffer[MAX_CSS_LENGTH];
static char        *OldBuffer;
static int          NbClass = 0;
static char         CurrentClass[80];
static Element      ClassReference;
static Document     DocReference;
static Document	    ApplyClassDoc;


/*----------------------------------------------------------------------
  RemoveElementStyle cleans all the presentation rules of a given element.
  The parameter removeSpan is True when the span has to be removed.
  ----------------------------------------------------------------------*/
static void RemoveElementStyle (Element el, Document doc, ThotBool removeSpan)
{
  ElementType		elType;
  Attribute            attr;
  AttributeType        attrType;
  Element		firstChild, lastChild;
  char                *name;

  if (el == NULL)
    return;
  elType = TtaGetElementType (el);
  /* if it's a MathML element, remove the style attribute defined in the
     MathML DTD */
  name = TtaGetSSchemaName (elType.ElSSchema);
  if (!strcmp (name, "MathML"))
    {
      attrType.AttrSSchema = elType.ElSSchema;
      attrType.AttrTypeNum = MathML_ATTR_style_;
    }
  else
#ifdef _SVG
    /* if it's a SVG element, remove the style attribute defined in the
       SVG DTD */
    if (!strcmp (name, "SVG"))
      {
        attrType.AttrSSchema = elType.ElSSchema;
        attrType.AttrTypeNum = SVG_ATTR_style_;
      }
    else
#endif
      /* remove the style attribute defined in the HTML DTD */
      {
        attrType.AttrSSchema = TtaGetSSchema ("HTML", doc);
        attrType.AttrTypeNum = HTML_ATTR_Style_;
      }
  attr = TtaGetAttribute (el, attrType);
  if (attr != NULL)
    {
      TtaRegisterAttributeDelete (attr, el, doc);
      TtaRemoveAttribute (el, attr, doc);
      if (removeSpan)
        DeleteSpanIfNoAttr (el, doc, &firstChild, &lastChild);
      TtaSetDocumentModified (doc);
    }

  /* remove all the specific presentation rules applied to the element */
  TtaCleanElementPresentation (el, doc);
}


/*----------------------------------------------------------------------
  UpdateCSSBackgroundImage searches strings url() or url("") within
  the styleString and make it relative to the newpath.
  oldpath = old document path
  newpath = new document path
  imgpath = new image directory
  If the image is not moved, the imgpath has to be NULL else the new
  image url is obtained by concatenation of imgpath and the image name.
  Returns NULL or a new allocated styleString.
  ----------------------------------------------------------------------*/
char *UpdateCSSBackgroundImage (char *oldpath, char *newpath,
                                char *imgpath, char *styleString)
{
  char               *b, *e, *ptr, *oldptr, *sString;
  char                old_url[MAX_LENGTH];
  char                tempname[MAX_LENGTH];
  char                imgname[MAX_LENGTH];
  char               *new_url;
  int                 len;

  ptr = NULL;
  sString = styleString;
  b = strstr (sString, "url");
  while (b != NULL)
    {
      /* we need to compare this url with the new doc path */
      b += 3;
      b = SkipBlanksAndComments (b);
      if (*b == '(')
        {
          b++;
          b = SkipBlanksAndComments (b);
          /*** Caution: Strings can either be written with double quotes or
               with single quotes. Only double quotes are handled here.
               Escaped quotes are not handled. See function SkipQuotedString */
          if (*b == '"')
            {
              /* search the url end */
              b++;
              e = b;
              while (*e != EOS && *e != '"')
                e++;
            }
          else
            {
              /* search the url end */
              e = b;
              while (*e != EOS && *e != ')')
                e++;
            }
          if (*e != EOS)
            {
              len = (int)(e - b);
              strncpy (old_url, b, len);
              old_url[len] = EOS;
              /* get the old full image name */
              NormalizeURL (old_url, 0, tempname, imgname, oldpath);
              /* build the new full image name */
              if (imgpath != NULL)
                NormalizeURL (imgname, 0, tempname, imgname, imgpath);
              new_url = MakeRelativeURL (tempname, newpath);
	      
              /* generate the new style string */
              if (ptr != NULL)
                {
                  oldptr = ptr;
                  len = - len + strlen (oldptr) + strlen (new_url) + 1;
                  ptr = (char *)TtaGetMemory (len);	  
                  len = (int)(b - oldptr);
                  strncpy (ptr, oldptr, len);
                  sString = &ptr[len];
                  /* new name */
                  strcpy (sString, new_url);
                  /* following text */
                  strcat (sString, e);
                  TtaFreeMemory (oldptr);
                }
              else
                {
                  len = - len + strlen (styleString) + strlen (new_url) + 1;
                  ptr = (char *)TtaGetMemory (len);
                  len = (int)(b - styleString);
                  strncpy (ptr, styleString, len);
                  sString = &ptr[len];
                  /* new name */
                  strcpy (sString, new_url);
                  /* following text */
                  strcat (sString, e);
                }
              TtaFreeMemory (new_url);
            }
          else
            sString = b;
        }
      else
        sString = b;
      /* next background-image */
      b = strstr (sString, "url"); 
    }
  return (ptr);
}

/*----------------------------------------------------------------------
  UpdateStyleDelete : a style attribute will be deleted.            
  remove the existing style presentation.                      
  ----------------------------------------------------------------------*/
ThotBool UpdateStyleDelete (NotifyAttribute * event)
{
  ElementType         elType;
  Element             el;
  char               *style = NULL;
  int                 len;

  len = TtaGetTextAttributeLength (event->attribute);
  if ((len < 0) || (len > 10000))
    /* error */
    return FALSE;
  if (len == 0)
    /* empty Style attribute */
    return FALSE;
  else
    {
      /* parse the content of the style attribute and remove the corresponding
         presentation rules from the element */
      style = (char *)TtaGetMemory (len + 2);
      if (!style)
        return FALSE;
      TtaGiveTextAttributeValue (event->attribute, style, &len);
      style[len] = EOS;
      el = event->element;
      ParseHTMLSpecificStyle (el, style, event->document, 200, TRUE);
      /* if it's the body element and the style attribute contains some
         background properties, the corresponding presentation rules have
         to be removed to the (parent) <html> element */
      elType = TtaGetElementType (el);
      if (elType.ElTypeNum == HTML_EL_BODY &&
          strcmp (TtaGetSSchemaName (elType.ElSSchema), "HTML") == 0)
        {
          el = TtaGetParent (el);
          ParseHTMLSpecificStyle (el, style, event->document, 200, TRUE);
        }
      TtaFreeMemory (style);
    }
  return FALSE;  /* let Thot perform normal operation */
}

/*----------------------------------------------------------------------
  ChangeStyle
  the STYLE element will be changed in the document HEAD.
  ----------------------------------------------------------------------*/
ThotBool ChangeStyle (NotifyOnTarget * event)
{
  OldBuffer = GetStyleContents (event->element);
  return FALSE;  /* let Thot perform normal operation */
}


/*----------------------------------------------------------------------
  DeleteStyle
  the STYLE element will be deleted in the document HEAD.
  ----------------------------------------------------------------------*/
ThotBool DeleteStyle (NotifyElement *event)
{
  RemoveStyle (NULL, event->document, TRUE, TRUE, event->element, CSS_DOCUMENT_STYLE);
  return FALSE;  /* let Thot perform normal operation */
}


/*----------------------------------------------------------------------
  EnableStyleElement
  the STYLE element must be reparsed.
  ----------------------------------------------------------------------*/
void EnableStyleElement (Document doc, Element el)
{
  ElementType	      elType;
  CSSInfoPtr          css = NULL;
  PInfoPtr            pInfo;
  DisplayMode         dispMode;
  char               *name;
  char               *buffer;
  ThotBool            loadcss;

  /* check if we have to load CSS */
  TtaGetEnvBoolean ("LOAD_CSS", &loadcss);
  if (!loadcss)
    return;

  if (el)
    {
      elType = TtaGetElementType (el);
      name = TtaGetSSchemaName (elType.ElSSchema);
      if ((!strcmp (name, "HTML") && elType.ElTypeNum == HTML_EL_STYLE_)
#ifdef _SVG
          /* if it's a SVG document, remove the style defined in the SVG DTD */
          || (!strcmp (name, "SVG") && elType.ElTypeNum == SVG_EL_style__)
#endif
          )
        {
          /* get the style element in the document head */
          buffer = GetStyleContents (el);
          css = SearchCSS (doc, NULL, el, &pInfo);
          if (pInfo)
            pInfo->PiEnabled = TRUE;
          dispMode = TtaGetDisplayMode (doc);
          if (dispMode != NoComputedDisplay)
            TtaSetDisplayMode (doc, NoComputedDisplay);
          ReadCSSRules (doc, NULL, buffer, NULL, TtaGetElementLineNumber (el),
                        FALSE, el);
          /* Restore the display mode */
          if (dispMode != NoComputedDisplay)
            TtaSetDisplayMode (doc, dispMode);
          TtaFreeMemory (buffer);
        }
    }
}

/*----------------------------------------------------------------------
  DeleteStyleElement
  the STYLE element will be deleted in the document HEAD.
  ----------------------------------------------------------------------*/
void DeleteStyleElement (Document doc, Element el)
{
  ElementType		elType;
  char                 *name;

  if (el)
    {
      /* get the style element in the document head */
      elType = TtaGetElementType (el);
      name = TtaGetSSchemaName (elType.ElSSchema);
      if ((!strcmp (name, "HTML") && elType.ElTypeNum == HTML_EL_STYLE_)
#ifdef _SVG
          /* if it's a SVG document, remove the style defined in the SVG DTD */
          || (!strcmp (name, "SVG") && elType.ElTypeNum == SVG_EL_style__)
#endif
          )
        {
          RemoveStyle (NULL, doc, TRUE, TRUE, el, CSS_DOCUMENT_STYLE);
          TtaOpenUndoSequence (doc, NULL, NULL, 0, 0);
          TtaRegisterElementDelete (el, doc);
          TtaDeleteTree (el, doc);
          TtaCloseUndoSequence (doc);
        }
    }
}


/*----------------------------------------------------------------------
  StyleChanged
  A STYLE element has been changed in the HEAD
  ----------------------------------------------------------------------*/
void StyleChanged (NotifyOnTarget *event)
{
  DisplayMode         dispMode;
  char               *buffer, *ptr1, *ptr2;
  char               *pEnd, *nEnd;
  char                c;
  int                 i, j;
  int                 previousEnd, nextEnd;
  int                 braces;

  /* get the new content of the style element */
  buffer = GetStyleContents (event->element);
  /* compare both strings */
  i = 0;
  ptr1 = buffer;
  previousEnd = i;
  pEnd = ptr1;
  braces = 0;
  dispMode = TtaGetDisplayMode (event->document);
  if (OldBuffer == NULL)
    {
      if (buffer)
        {
          TtaSetDisplayMode (event->document, DeferredDisplay);
          /* This is a brand new style element */
          ApplyCSSRules (event->element, buffer, event->document, FALSE);
          TtaSetDisplayMode (event->document, dispMode);
        }
    }
  else
    {
      if (buffer == NULL)
        {
          TtaSetDisplayMode (event->document, DeferredDisplay);
          /* the style element has been cleared. Remove the style made by the
             previous content */
          ApplyCSSRules (event->element, OldBuffer, event->document, TRUE);
          TtaSetDisplayMode (event->document, dispMode);
        }
      else
        {
          if (strstr (OldBuffer, "float") || strstr (buffer, "float"))
            TtaSetDisplayMode (event->document, NoComputedDisplay);
          else
            TtaSetDisplayMode (event->document, DeferredDisplay);
          /* handle only differences */
          while (OldBuffer[i] == *ptr1 && *ptr1 != EOS)
            {
              if (i > 0 && OldBuffer[i-1] == '{')
                braces++;
              if (i > 0 &&
                  (OldBuffer[i-1] == '}' ||
                   ((OldBuffer[i-1] == ';' || OldBuffer[i-1] == '>') &&
                    braces == 0)))
                {
                  if (OldBuffer[i-1] == '}')
                    braces--;
                  previousEnd = i;
                  pEnd = ptr1;
                }
              i++;
              ptr1++;
            }

          /* now ptr1 and OldBuffer[i] point to different strings */
          if (*ptr1 != EOS)
            {
              ptr2 = ptr1 + strlen (ptr1);
              j = i + strlen (&OldBuffer[i]);
              nextEnd = j;
              nEnd = ptr2;
              braces = 0;
              while (OldBuffer[j] == *ptr2 && ptr2 != ptr1)
                {
                  if (j > i && OldBuffer[j-1] == '{')
                    braces++;
                  if (j > i &&
                      (OldBuffer[j-1] == '}' ||
                       ((OldBuffer[j-1] == '@' || OldBuffer[j-1] == '<') &&
                        braces == 0)))
                    {
                      if (OldBuffer[j-1] == '}')
                        braces--;
                      nextEnd = j;
                      nEnd = ptr2;
                    }
                  j--;
                  ptr2--;
                }
              if (ptr1 != ptr2)
                {
                  /* take complete CSS rules */
                  OldBuffer[nextEnd] = EOS;
                  *nEnd = EOS;

                  /* remove previous rules */
                  ptr1 = &OldBuffer[previousEnd];
                  ptr2 = ptr1;
                  do
                    {
                      while (*ptr2 != '}' && *ptr2 != EOS)
                        ptr2++;
                      if (*ptr2 != EOS)
                        ptr2++;
                      /* cut here */
                      c = *ptr2;
                      *ptr2 = EOS;
                      ApplyCSSRules (event->element, ptr1, event->document,
                                     TRUE);
                      /**** update image contexts
                            url1 = GetCSSBackgroundURL (ptr1);
                            if (url1 != NUL)
                            {
                            sprintf (path, "%s%s%d%s", TempFileDirectory, DIR_STR,
                            event->document, DIR_STR, url1);
                            pImage = SearchLoadedImage (path, event->document);
                            }
                      ***/
                      *ptr2 = c;
                      ptr1 = ptr2;
                    }
                  while (*ptr2 != EOS);

                  /* add new rules */
                  ptr1 = pEnd;
                  ptr2 = ptr1;
                  do
                    {
                      while (*ptr2 != '}' && *ptr2 != EOS)
                        ptr2++;
                      if (*ptr2 != EOS)
                        ptr2++;
                      /* cut here */
                      c = *ptr2;
                      *ptr2 = EOS;
                      ApplyCSSRules (event->element, ptr1, event->document,
                                     FALSE);
                      *ptr2 = c;
                      ptr1 = ptr2;
                    }
                  while (*ptr2 != EOS);
                }
            }
          /* reset the display mode */
          TtaSetDisplayMode (event->document, dispMode);
        }
      TtaFreeMemory (OldBuffer);
      OldBuffer = NULL;
    }
  TtaFreeMemory (buffer);
}


/*----------------------------------------------------------------------
  UpdateStylePost : attribute Style has been updated or created.  
  reflect the new style presentation.                          
  ----------------------------------------------------------------------*/
void UpdateStylePost (NotifyAttribute * event)
{
  Document            doc;
  Element             el, oldParent, newParent;
  char               *style = NULL;
  int                 len;

  el = event->element;
  doc = event->document;

  len = TtaGetTextAttributeLength (event->attribute);
  if ((len < 0) || (len > 10000))
    return;
  if (len > 0)
    {
      /* parse and apply the new style content */
      style = (char *)TtaGetMemory (len + 2);
      if (style == NULL)
        return;
      TtaGiveTextAttributeValue (event->attribute, style, &len);
      style[len] = EOS;
      /* create a Span element if it's a TEXT leaf */
      oldParent = TtaGetParent (el);
      AttrToSpan (el, event->attribute, doc);
      newParent = TtaGetParent (el);
      if (newParent != oldParent)
        {
          /* a new SPAN element has been created. Generate the PRules
             for the SPAN element */
          el = newParent;
          TtaSetElementLineNumber (el, TtaGetElementLineNumber (oldParent));
        }
      ParseHTMLSpecificStyle (el, style, doc, 200, FALSE);
      if (CSSErrorsFound)
        {
          /* the CSS parser detected an error */
          TtaWriteClose (ErrFile);
          ErrFile = NULL;
          TtaSetItemOn (doc, 1, File, BShowLogFile);
          CSSErrorsFound = FALSE;
          InitInfo ("", TtaGetMessage (AMAYA, AM_CSS_ERROR));
        }
      else
        TtaSetItemOff (doc, 1, File, BShowLogFile);
      TtaFreeMemory (style);
    }
}

/*----------------------------------------------------------------------
  DoApplyClass
  Put a class attribute on all selected elements
  ----------------------------------------------------------------------*/
static void DoApplyClass (Document doc)
{
  Element             firstSelectedEl, lastSelectedEl, el;
  Element             next, firstChild, lastChild;
  ElementType	        elType, lastType;
  Attribute           attr;
  AttributeType       attrType;
  char               *a_class = CurrentClass, *s;
  int		              firstSelectedChar, lastSelectedChar, i, lg;
  DisplayMode         dispMode;

  if (!a_class)
    return;

  /* remove any leading dot in a class definition. */
  if (*a_class == '.')
    a_class++;
  if (*a_class == EOS)
    return;

  /* work with the current selected document */
  doc = TtaGetSelectedDocument ();
  if (doc == 0)
    {
      TtaDisplaySimpleMessage (CONFIRM, AMAYA, AM_NO_INSERT_POINT);
      return;
    }
  if (DocumentTypes[doc] == docSource || DocumentTypes[doc] == docText ||
      DocumentTypes[doc] == docCSS)
    return;
  TtaGiveFirstSelectedElement (doc, &firstSelectedEl, &firstSelectedChar, &i);
  if (TtaIsReadOnly (firstSelectedEl))
    {
      /* the selected element is read-only */
      TtaDisplaySimpleMessage (CONFIRM, AMAYA, AM_READONLY);
      return;
    }

  if (strcmp (CurrentClass, "(no_class)") &&
      !IsImplicitClassName (CurrentClass, doc))
    GenerateInlineElement (HTML_EL_Span, HTML_ATTR_Class, a_class);
  else
    {
      /* remove class attributes */
      TtaGiveLastSelectedElement (doc, &lastSelectedEl, &i, &lastSelectedChar);
      elType = TtaGetElementType (firstSelectedEl);
      lastType = TtaGetElementType (lastSelectedEl);
      if (elType.ElTypeNum == HTML_EL_TEXT_UNIT && firstSelectedChar > 1)
        // no class attribute
        return;
      lg = TtaGetElementVolume (lastSelectedEl);
      if (lastType.ElTypeNum == HTML_EL_TEXT_UNIT &&
          (lastSelectedChar == 0 || lastSelectedChar > lg))
        return;
      if (TtaIsLeaf (elType))
        firstSelectedEl = TtaGetParent (firstSelectedEl);
       if (TtaIsLeaf (lastType))
        lastSelectedEl = TtaGetParent (lastSelectedEl);

      TtaClearViewSelections ();
      /* stop displaying changes that will be made in the document */
      dispMode = TtaGetDisplayMode (doc);
      if (dispMode == DisplayImmediately)
        TtaSetDisplayMode (doc, DeferredDisplay);
      TtaUnselect (doc);
      TtaOpenUndoSequence (doc, firstSelectedEl, lastSelectedEl, 0, 0);

      /* process all selected elements */
      el = firstSelectedEl;
      while (el)
        {
          /* The current element may be deleted by DeleteSpanIfNoAttr. So, get
             first the next element to be processed */
          if (el == lastSelectedEl)
            next = NULL;
          else
            {
              next = el;
              TtaGiveNextElement (doc, &next, lastSelectedEl);
            }
          
          elType = TtaGetElementType (el);
          s = TtaGetSSchemaName (elType.ElSSchema);
          /* remove the current class attribute */
          attrType.AttrSSchema = elType.ElSSchema;
          if (!strcmp (s, "MathML"))
            attrType.AttrTypeNum = MathML_ATTR_class;
#ifdef _SVG
          else if (!strcmp (s, "SVG"))
            attrType.AttrTypeNum = SVG_ATTR_class;
#endif
          else
            {
              attrType.AttrSSchema = TtaGetSSchema ("HTML", doc);
              attrType.AttrTypeNum = HTML_ATTR_Class;
            }
          /* set the Class attribute of the element */
          attr = TtaGetAttribute (el, attrType);
          if (attr)
            {
              TtaRegisterAttributeDelete (attr, el, doc);
              TtaRemoveAttribute (el, attr, doc);
              TtaSetDocumentModified (doc);
            }
          DeleteSpanIfNoAttr (el, doc, &firstChild, &lastChild);
          if (firstChild)
            {
              if (el == firstSelectedEl)
                firstSelectedEl = firstChild;
              if (el == lastSelectedEl)
                lastSelectedEl = lastChild;
            }
          /* jump to the next element */
          el = next;
        }
      
      TtaCloseUndoSequence (doc);
      /* ask Thot to display changes made in the document */
      TtaSetDisplayMode (doc, dispMode);
      TtaSelectElement (doc, firstSelectedEl);
      if (lastSelectedEl != firstSelectedEl)
        TtaExtendSelection (doc, lastSelectedEl, 0);
    }
}

/*----------------------------------------------------------------------
  SpecificSettingsToCSS :  Callback for ApplyAllSpecificSettings,
  enrich the CSS string.
  ----------------------------------------------------------------------*/
static void SpecificSettingsToCSS (Element el, Document doc,
                                   PresentationSetting settings, void *param)
{
  LoadedImageDesc    *imgInfo;
  char               *css_rules = (char *)param;
  char                string[150];
  char               *ptr;

  string[0] = EOS;
  if (settings->type == PRBackgroundPicture)
    {
      /* transform absolute URL into relative URL */
      imgInfo = SearchLoadedImage ((char *)settings->value.pointer, 0);
      if (imgInfo != NULL)
        ptr = MakeRelativeURL (imgInfo->originalName, DocumentURLs[doc]);
      else
        ptr = MakeRelativeURL ((char *)settings->value.pointer, DocumentURLs[doc]);
      settings->value.pointer = ptr;
      TtaPToCss (settings, string, sizeof(string), el);
      TtaFreeMemory (ptr);
    }
  else
    TtaPToCss (settings, string, sizeof(string), el);

  if (string[0] != EOS && *css_rules != EOS)
    strcat (css_rules, "; ");
  if (string[0] != EOS)
    strcat (css_rules, string);
}


/*----------------------------------------------------------------------
  SetStyleString returns a string corresponding to the CSS
  description of the presentation attribute applied to an element.
  ----------------------------------------------------------------------*/
void SetStyleString (Document doc, Element el, PRule presRule)
{
  char               *buf;
  int                 len;
  int                 first, last;
#define STYLELEN 1000

  if (DocumentTypes[doc] == docCSS && el)
    {
      buf = (char *)TtaGetMemory (STYLELEN);
      buf[0] = EOS;
      TtaApplyAllSpecificSettings (el, doc, SpecificSettingsToCSS, &buf[0]);
      TtaRemovePRule (el,  presRule, doc);
      if (buf[0] != EOS)
        strcat (buf, "; ");
      len = strlen (buf);
      if (len)
        {
          // not necessary to open the undo sequence
          TtaGiveFirstSelectedElement (doc, &el, &first, &last);
          TtaRegisterElementReplace (el, doc);
          if (TtaIsSelectionEmpty ())
            {
              /* insert a new text */
              if (TtaGetElementVolume (el) == 0)
                TtaSetTextContent (el, (unsigned char *)buf, Latin_Script, doc);
              else
                {
                  TtaInsertTextContent (el, first, (unsigned char *)buf, doc);
                  len += first;
                }
            }
          else
            /* replace the current text */
            TtaSetTextContent (el, (unsigned char *)buf, Latin_Script, doc);
          TtaSelectString (doc, el, len, len-1);
        }
      TtaFreeMemory (buf);
    }
}

/*----------------------------------------------------------------------
  GetHTMLStyleString : return a string corresponding to the CSS
  description of the presentation attribute applied to an element.
  For stupid reasons, if the target element is HTML or BODY,
  one returns the concatenation of both element style strings.
  ----------------------------------------------------------------------*/
void GetHTMLStyleString (Element el, Document doc, char *buf, int *len)
{
  ElementType        elType;
  char              *name;

  if (buf == NULL || len == NULL || *len <= 0)
    return;

  /*
   * this will transform all the Specific Settings associated to
   * the element to one CSS string.
   */
  buf[0] = EOS;
  TtaApplyAllSpecificSettings (el, doc, SpecificSettingsToCSS, &buf[0]);
  *len = strlen (buf);

  /* BODY / HTML elements specific handling */
  elType = TtaGetElementType (el);
  name = TtaGetSSchemaName (elType.ElSSchema);
  if (strcmp(name, "HTML") == 0)
    {
      if (elType.ElTypeNum == HTML_EL_Document)
        {
          elType.ElTypeNum = HTML_EL_BODY;
          el = TtaSearchTypedElement (elType, SearchForward, el);
          if (!el)
            return;
          if (*len > 0)
            strcat(buf, ";");
          *len = strlen (buf);
          TtaApplyAllSpecificSettings (el, doc, SpecificSettingsToCSS,
                                       &buf[*len]);
          *len = strlen (buf);
        }
      else if (elType.ElTypeNum == HTML_EL_BODY ||
               elType.ElTypeNum == HTML_EL_HTML)
        {
          el = TtaGetMainRoot (doc);
          if (!el)
            return;
          if (*len > 0)
            strcat(buf, ";");
          *len = strlen (buf);
          TtaApplyAllSpecificSettings (el, doc, SpecificSettingsToCSS,
                                       &buf[*len]);
          *len = strlen (buf);
        }
    }
}

/*----------------------------------------------------------------------
  HTMLSetBackgroundImage:
  repeat = repeat value
  image = url of background image
  generate is TRUE when the style attribute must be generated.
  ----------------------------------------------------------------------*/
void HTMLSetBackgroundImage (Document doc, Element el, int repeat,
                             int specificity, char *image, ThotBool generate)
{
  Attribute           attr;
  AttributeType       attrType;
  ElementType         elType;
  char               *schName, *ptr;
  char                txt[400];
  int                 len;

  /* First remove a previous value */
  HTMLResetBackgroundImage (doc, el);
  if (el && generate)
    /* update the style attribute */
    SetStyleAttribute (doc, el);
  sprintf (txt, "background-image: url(%s); background-repeat: ", image);
  if (repeat == REPEAT)
    strcat (txt, "repeat");
  else if (repeat == XREPEAT)
    strcat (txt, "repeat-x");
  else if (repeat == YREPEAT)
    strcat (txt, "repeat-y");
  else
    strcat (txt, "no-repeat");
  ParseHTMLSpecificStyle (el, txt, doc, 0, FALSE);
  if (el && generate)
    {
      elType = TtaGetElementType (el);
      attrType.AttrSSchema = elType.ElSSchema;
      schName = TtaGetSSchemaName (elType.ElSSchema);
      if (strcmp (schName, "MathML") == 0)
        attrType.AttrTypeNum = MathML_ATTR_style_;
      else if (!strcmp (schName, "HTML"))
        /* it's a HTML document */
        attrType.AttrTypeNum = HTML_ATTR_Style_;
#ifdef _SVG
      else if (!strcmp (schName, "SVG"))
        /* it's a SVG document */
        attrType.AttrTypeNum = SVG_ATTR_style_;
#endif /* _SVG */
      else
        return;
      attr = TtaGetAttribute (el, attrType);
      if (attr)
        {
          /* concatenate the old value and the new text */
          len = TtaGetTextAttributeLength (attr) + 1;
          ptr = (char *)TtaGetMemory (len + strlen (txt));
          TtaGiveTextAttributeValue (attr, ptr, &len);
          strcat (ptr, txt);
          TtaRegisterAttributeReplace (attr, el, doc);
          TtaSetAttributeText (attr, ptr, el, doc);
          TtaFreeMemory (ptr);
        }
      else
        {
          /* set the new text */
          attr = TtaNewAttribute (attrType);
          TtaAttachAttribute (el, attr, doc);
          TtaSetAttributeText (attr, txt, el, doc);
          TtaRegisterAttributeCreate (attr, el, doc);
        }
    }
}

/*----------------------------------------------------------------------
  UpdateClass
  Change or create a class attribute to reflect the Style attribute
  of the selected element.
  ----------------------------------------------------------------------*/
static void UpdateClass (Document doc)
{
  DisplayMode         dispMode;
  Attribute           attr;
  AttributeType       attrType;
  Element             el, root, child, title, head, line, prev, styleEl;
  ElementType         elType, selType;
  char               *stylestring;
  char               *text;
  char               *a_class;
  char               *schName;
  int                 len, base, i;
  Language            lang;
  ThotBool            found, empty, insertNewLine, ok;

  elType = TtaGetElementType (ClassReference);
  GIType (CurrentClass, &selType, doc);
  if (selType.ElTypeNum != elType.ElTypeNum && selType.ElTypeNum != 0)
    {
      ok = FALSE;
      if (!strcmp (TtaGetSSchemaName (elType.ElSSchema), "HTML"))
        {
          if (selType.ElTypeNum == HTML_EL_Input)
            /* the user has chosen element imput */
            {
              if (elType.ElTypeNum == HTML_EL_Text_Input ||
                  elType.ElTypeNum == HTML_EL_Password_Input ||
                  elType.ElTypeNum == HTML_EL_File_Input ||
                  elType.ElTypeNum == HTML_EL_Checkbox_Input ||
                  elType.ElTypeNum == HTML_EL_Radio_Input ||
                  elType.ElTypeNum == HTML_EL_Submit_Input ||
                  elType.ElTypeNum == HTML_EL_Reset_Input ||
                  elType.ElTypeNum == HTML_EL_Button_Input)
                /* the selected element is a variant of the imput element. */
                ok = TRUE;
            }
          else if (selType.ElTypeNum == HTML_EL_ruby)
            /* the user has chosen element ruby */
            {
              if (elType.ElTypeNum == HTML_EL_simple_ruby ||
                  elType.ElTypeNum == HTML_EL_complex_ruby)
                /* the selected element is a variant of the ruby element. */
                ok = TRUE;
            }
        }
      if (!ok)
        /* it's an invalid element type */
        {
          TtaSetStatus (doc, 1, TtaGetMessage (AMAYA, AM_INVALID_TYPE), NULL);
          return;
        }
    }

  /* locate the style element in the document head */
  root = TtaGetMainRoot (doc);
  elType = TtaGetElementType (root);
  schName = TtaGetSSchemaName (elType.ElSSchema);
  head = NULL;
  if (!strcmp (schName, "HTML"))
    /* it's a HTML document */
    {
      elType.ElTypeNum = HTML_EL_HEAD;
      head = TtaSearchTypedElement (elType, SearchForward, root);
      elType.ElTypeNum = HTML_EL_STYLE_;
      attrType.AttrSSchema = elType.ElSSchema;
      attrType.AttrTypeNum = HTML_ATTR_Notation;
    }
#ifdef _SVG
  else if (!strcmp (schName, "SVG"))
    /* it's a SVG document */
    {
      elType.ElTypeNum = SVG_EL_SVG;
      head = TtaSearchTypedElement (elType, SearchForward, root);
      elType.ElTypeNum = SVG_EL_style__;
      attrType.AttrSSchema = elType.ElSSchema;
      attrType.AttrTypeNum = SVG_ATTR_type;
    }
#endif /* _SVG */
  el = head;
  found = FALSE;
  while (!found && el)
    {
      /* is there any style element? */
      el = TtaSearchTypedElementInTree (elType, SearchForward, head, el);
      if (el)
        {
          /* does this style element have an attribute type="text/css" ? */
          attr = TtaGetAttribute (el, attrType);
          if (attr)
            {
              len = TtaGetTextAttributeLength (attr);
              a_class = (char *)TtaGetMemory (len + 1);
              TtaGiveTextAttributeValue (attr, a_class, &len);
              found = (!strcmp (a_class, "text/css"));
              TtaFreeMemory (a_class);
            }
        }
    }
  if (!found && head)
    /* the STYLE element doesn't exist. Create it */
    {
      el = TtaNewTree (doc, elType, "");
      if (strcmp (schName, "HTML"))
        title = NULL;
      else
        {
          /* It's a HTML document. Insert the new style element after the
             title if it exists */
          elType.ElTypeNum = HTML_EL_TITLE;
          title = TtaSearchTypedElementInTree (elType, SearchForward, head,
                                               head);
        }
      
      /* do not check mandatory attributes */
      TtaSetStructureChecking (FALSE, doc);
      if (title)
        TtaInsertSibling (el, title, FALSE, doc);
      else
        TtaInsertFirstChild (&el, head, doc);
      TtaSetStructureChecking (TRUE, doc);
      attr = TtaNewAttribute (attrType);
      TtaAttachAttribute (el, attr, doc);
      TtaSetAttributeText (attr, "text/css", el, doc);
    }

  if (!el)
    /* there is no STYLE element and no way to create one */
    return;

  styleEl = el;
  /* check whether it's an element type or a class name */
  /* get the current style attribute */
  elType = TtaGetElementType (ClassReference);
  schName = TtaGetSSchemaName (elType.ElSSchema);
  if (strcmp (schName, "MathML") == 0)
    {
      attrType.AttrSSchema = elType.ElSSchema;
      attrType.AttrTypeNum = MathML_ATTR_style_;
    }
#ifdef _SVG
  else if (strcmp (schName, "SVG") == 0)
    {
      attrType.AttrSSchema = elType.ElSSchema;
      attrType.AttrTypeNum = SVG_ATTR_style_;
    }
#endif /* _SVG */
  else
    {
      attrType.AttrSSchema = TtaGetSSchema ("HTML", doc);
      attrType.AttrTypeNum = HTML_ATTR_Style_;
    }
  attr = TtaGetAttribute (ClassReference, attrType);
  base = strlen (CurrentClass) + 2;
  if (attr)
    len = TtaGetTextAttributeLength (attr) + base + 3;
  else
    len = base + 3;
  /* create a string containing the new CSS definition. */
  stylestring = (char *)TtaGetMemory (len);
  stylestring[0] = EOS;
  if (selType.ElTypeNum == 0)
    {
      /* it's not an element type */
      if (CurrentClass[0] != '.' && CurrentClass[0] != '#')
        {
          /* it's an invalid class name, insert a dot */
          strcat (stylestring, ".");
          base++;
        }
    }
  strcat (stylestring, CurrentClass);
  strcat (stylestring, " {");
  if (attr)
    {
      len = len - base;
      TtaGiveTextAttributeValue (attr, &stylestring[base], &len);
    }
  strcat (stylestring, "}");

  TtaOpenUndoSequence (doc, ClassReference, ClassReference, 0, 0);

  /* create the class attribute */
  if (selType.ElTypeNum == 0)
    {
      a_class = &CurrentClass[0];
      if (*a_class == '.')
        a_class++;
      if (!strcmp (TtaGetSSchemaName (elType.ElSSchema), "MathML"))
        {
          attrType.AttrSSchema = elType.ElSSchema;
          attrType.AttrTypeNum = MathML_ATTR_class;
        }
      else
#ifdef _SVG
        if (!strcmp (TtaGetSSchemaName (elType.ElSSchema), "SVG"))
          {
            attrType.AttrSSchema = elType.ElSSchema;
            attrType.AttrTypeNum = SVG_ATTR_class;
          }
        else
#endif
          {
            attrType.AttrSSchema = TtaGetSSchema ("HTML", doc);
            attrType.AttrTypeNum = HTML_ATTR_Class;
          }
      attr = TtaGetAttribute (ClassReference, attrType);
      if (!attr)
        {
          attr = TtaNewAttribute (attrType);
          TtaAttachAttribute (ClassReference, attr, doc);
          TtaSetAttributeText (attr, a_class, ClassReference, doc);
          TtaRegisterAttributeCreate (attr, ClassReference, doc);
        }
      else
        {
          TtaRegisterAttributeReplace (attr, ClassReference, doc);
          TtaSetAttributeText (attr, a_class, ClassReference, doc);
        }
      TtaSetDocumentModified (doc);
    }

  /* remove the Style attribute */
  RemoveElementStyle (ClassReference, doc, FALSE);

  insertNewLine = FALSE;
  child = TtaGetLastChild (el);
  if (child == NULL)
    {
      /* there is no TEXT element within the STYLE element. We create it now */
      elType.ElTypeNum = HTML_EL_TEXT_UNIT;
      child = TtaNewTree (doc, elType, "");
      TtaInsertFirstChild (&child, el, doc);
      /* remember the element to be registered in the Undo queue */
      el = child;
      found = FALSE;
    }
  else
    {
      elType = TtaGetElementType (child);
      if (elType.ElTypeNum == HTML_EL_TEXT_UNIT)
        /* if the last child of the STYLE element is an empty text leaf,
           skip it */
        {
          len = TtaGetTextLength (child) + 1;
          text = (char *)TtaGetMemory (len);
          TtaGiveTextContent (child, (unsigned char *)text, &len, &lang);
          empty = TRUE;
          insertNewLine = TRUE;
          for (i = len - 1; i >= 0 && empty; i--)
            {
              empty = text[i] <= SPACE;
              if ((int) text[i] == EOL || (int) text[i] == __CR__)
                insertNewLine = FALSE;
            }
          TtaFreeMemory (text);
          if (empty)
            {
              prev = child;
              TtaPreviousSibling (&prev);
              if (prev)
                {
                  child = prev;
                  elType = TtaGetElementType (child);
                }
            }
        }
      if (!strcmp (schName, "HTML") && elType.ElTypeNum != HTML_EL_TEXT_UNIT)
        {
          if (elType.ElTypeNum != HTML_EL_Comment_)
            /* the last child of the STYLE element is neither a text leaf nor
               a comment. Don't do anything */
            child = NULL;
          else
            /* the last child of the STYLE element is a comment */
            /* insert the new style rule within the Comment_line */
            {
              line = TtaGetLastChild (child);
              if (line)
                /* there is already a Comment_line */
                {
                  child = TtaGetLastChild (line);
                  len = TtaGetTextLength (child) + 1;
                  text = (char *)TtaGetMemory (len);
                  TtaGiveTextContent (child, (unsigned char *)text, &len, &lang);
                  empty = TRUE;
                  insertNewLine = TRUE;
                  for (i = len - 1; i >= 0 && empty; i--)
                    {
                      empty = text[i] <= SPACE;
                      if ((int) text[i] == EOL || (int) text[i] == __CR__)
                        insertNewLine = FALSE;
                    }
                  TtaFreeMemory (text);
                }
              else
                /* create a Comment_line within the Comment */
                {
                  elType.ElTypeNum = HTML_EL_Comment_line;
                  line = TtaNewTree (doc, elType, "");
                  TtaInsertFirstChild (&line, child, doc);
                  child = TtaGetLastChild (line);
                  insertNewLine = FALSE;
                  /* remember the element to register in the undo queue */
                  found = FALSE;
                  el = line;
                }
            }
        }
    }

  if (child)
    {
      if (found)
        /* Register the previous value of the STYLE element in the Undo queue */
        TtaRegisterElementReplace (child, doc);
      /* update the STYLE element */
      len = TtaGetTextLength (child);
      if (insertNewLine)
        {
          TtaInsertTextContent (child, len, (unsigned char *)"\n", doc);
          len++;
        }
      TtaInsertTextContent (child, len, (unsigned char *)stylestring, doc);

      /* parse and apply this new CSS to the current document */
      dispMode = TtaGetDisplayMode (doc);
      TtaSetDisplayMode (doc, NoComputedDisplay);
      ReadCSSRules (doc, NULL, stylestring, NULL,
                    TtaGetElementLineNumber (child), TRUE, styleEl);
      TtaSetDisplayMode (doc, dispMode);
    }
  /* free the stylestring now */
  TtaFreeMemory (stylestring);
  stylestring = NULL;
  
  if (!found && el)
    /* Register the created STYLE or child element in the Undo queue */
    TtaRegisterElementCreate (el, doc);
  TtaCloseUndoSequence (doc);
}

/*----------------------------------------------------------------------
  PutClassName adds the class names into the buffer buff if they are
  not already there.
  Class names are contained in attribute attr or in parameter className.
  ----------------------------------------------------------------------*/
static void PutClassName (Attribute attr, char *className, char *buf,
                          int *index, int *free, int *nb)
{
  int		         len, cur, i, k;
  unsigned char  selector[200];
  char          *ptr, *name, c;
  ThotBool       found, previous;

  if (attr)
    {
      len = 198;
      TtaGiveTextAttributeValue (attr, (char *)selector, &len);
      selector[len+1] = EOS;
      /* get the first name contained in the attribute */
      ptr = (char *)selector;
      ptr = TtaSkipBlanks (ptr);
    }
  else
    ptr = className;

  while (ptr && *ptr != EOS)
    {
      name = ptr;
      /* look for the end of the current name */
      while (*ptr > ' ' && *ptr != EOS)
        ptr++;
      c = *ptr;
      *ptr = EOS;
      /* compare that name with all class names already known */
      cur = 0;
      found = FALSE;
      previous = FALSE;
      for (i = 0; i < *nb && !found && !previous; i++)
        {
          if (buf[cur] == '.')
            cur++;
          len = strlen (&buf[cur]) + 1;
          found = !strcmp (name, &buf[cur]);
          previous = (cur != 0 && name[0] < buf[cur]);
          if (!found && !previous && cur != 0)
            {
              k = 0;
              while (name[k] == buf[cur+k])
                k++;
              previous = (name[k] < buf[cur+ k]);
            }
          if (!previous)
            cur += len;
        }

      if (!found)
        /* this class name is not known, append it */
        {
          len = strlen (name);
          len++; /* add the \0 */
          if (len > *free)
            return;
          if (previous && i > 1 && i  <= *nb)
            {
              // move the tail of the current list
              cur--;
              len++;
              for (k = *index; k >= cur; k--)
                buf[k+len] = buf[k];
            /* add this new class name with a dot at the current position */
              buf[cur++] = '.';
              strcpy (&buf[cur], name);
            }
          else
            {
            /* add this new class name with a dot at the end */
              buf[(*index)++] = '.';
              strcpy (&buf[*index], name);
            }
          *free -= len;
          *index += len;
          (*nb)++;
        }
      /* skip spaces after the name that has just been processed */
      if (c != EOS)
        {
          *ptr = c; // restore the character
          ptr++;
          ptr = TtaSkipBlanks (ptr);
        }
      /* and process the next name, if any */
    }
}

/*----------------------------------------------------------------------
  BuildClassList
  Build the whole list of class names after the first name.
  ----------------------------------------------------------------------*/
static int BuildClassList (Document doc, char *buf, int size, char *first)
{
  Element             el;
  Attribute           attr;
  AttributeType       attrType;
  CSSInfoPtr          css;
  int                 free;
  int                 len, nb;
  int                 index;

  /* add the first element if specified */
  memset (buf, 0, size);
  nb = 0;
  index = 0;
  free = size;
  if (first)
    {
      strcpy (&buf[index], first);
      len = strlen (first);
      len++;
      free -= len;
      index += len;
      nb++;
    }
  if (DocumentTypes[doc] == docHTML)
    {
      /* looks for the class attribute defined in the HTML DTD */
      attrType.AttrSSchema = TtaGetSSchema ("HTML", doc);
      if (attrType.AttrSSchema)
        {
          /* this document contains HTML elements */
          attrType.AttrTypeNum = HTML_ATTR_Class;
          el = TtaGetMainRoot (doc);
          while (el)
            {
              TtaSearchAttribute (attrType, SearchForward, el, &el, &attr);
              if (attr)
                PutClassName (attr, NULL, buf, &index, &free, &nb);
            }
        }
    }

  if (DocumentTypes[doc] == docMath ||
      (DocumentTypes[doc] == docHTML &&
       DocumentMeta[doc] && DocumentMeta[doc]->compound))
    {
      /* looks for the class attribute defined in the MathML DTD */
      attrType.AttrSSchema = TtaGetSSchema ("MathML", doc);
      if (attrType.AttrSSchema)
        /* there are some MathML elements in this document */
        {
          attrType.AttrTypeNum = MathML_ATTR_class;
          el = TtaGetMainRoot (doc);
          while (el)
            {
              TtaSearchAttribute (attrType, SearchForward, el, &el, &attr);
              if (attr)
                PutClassName (attr, NULL, buf, &index, &free, &nb);
            }
        }
    }

#ifdef _SVG
 if (DocumentTypes[doc] == docSVG ||
      (DocumentTypes[doc] == docHTML &&
       DocumentMeta[doc] && DocumentMeta[doc]->compound))
    {
      /* looks for the class attribute defined in the SVG DTD */
      attrType.AttrSSchema = TtaGetSSchema ("SVG", doc);
      if (attrType.AttrSSchema)
        /* there are some SVG elements in this document */
        {
          attrType.AttrTypeNum = SVG_ATTR_class;
          el = TtaGetMainRoot (doc);
          while (el)
            {
              TtaSearchAttribute (attrType, SearchForward, el, &el, &attr);
              if (attr)
                PutClassName (attr, NULL, buf, &index, &free, &nb);
            }
        }
    }
#endif /* _SVG */

  /* look for all class names that are used in the STYLE element and in
     all style sheets currently associated with the document */
  css = CSSList;
  while (css)
    {
      if (css->class_list && css->infos [doc])
        {
          //printf ("%s\n LIST=\n", css->class_list, ListBuffer);
          PutClassName (NULL, css->class_list, buf, &index, &free, &nb);
        }
      css = css->NextCSS;
    }
  return (nb);
}
	    
/*----------------------------------------------------------------------
  CreateClass
  creates a class from the Style attribute of the selected element
  ----------------------------------------------------------------------*/
void CreateClass (Document doc, View view)
{
  Attribute           attr;
  AttributeType       attrType;
  Element             last_elem;
  ElementType         elType;
  char                a_class[50];
  char               *elHtmlName;
  char               *schName;
  int                 len, i, j;
  int                 firstSelectedChar, lastSelectedChar;

  if (!TtaGetDocumentAccessMode (doc))
    /* the document is in ReadOnly mode */
    return;

  DocReference = doc;
  CurrentClass[0] = 0;
  ClassReference = NULL;
  TtaGiveFirstSelectedElement (doc, &ClassReference,
                               &firstSelectedChar, &lastSelectedChar);
  TtaGiveLastSelectedElement (doc, &last_elem, &i, &j);
  
  /* one can only define a style from one element at a time. */
  if (last_elem != ClassReference)
    return;
  if (ClassReference == NULL)
    return;
  /* if the selected element is read-only, do nothing */
  if (TtaIsReadOnly (ClassReference))
    return;

  /* if only a part of an element is selected, select the parent instead */
  elType = TtaGetElementType (ClassReference);
  if (elType.ElTypeNum == HTML_EL_TEXT_UNIT ||
      elType.ElTypeNum == HTML_EL_GRAPHICS_UNIT)
    {
      ClassReference = TtaGetParent (ClassReference);
      elType = TtaGetElementType (ClassReference);
    }
  if (elType.ElSSchema)
    {
      schName = TtaGetSSchemaName (elType.ElSSchema);
      if (strcmp (schName, "HTML") &&
          strcmp (schName, "SVG") &&
          strcmp (schName, "MathML"))
        /* no class attribute for that element. Do nothing */
        return;
      /* check if the element has a style attribute */
      attrType.AttrSSchema = elType.ElSSchema;
      if (strcmp (schName, "MathML") == 0)
        attrType.AttrTypeNum = MathML_ATTR_style_;
#ifdef _SVG
      else if (strcmp (schName, "SVG") == 0)
        attrType.AttrTypeNum = SVG_ATTR_style_;
#endif
      else
        attrType.AttrTypeNum = HTML_ATTR_Style_;
      attr = TtaGetAttribute (ClassReference, attrType);
      if (attr == NULL)
        /* no attribute style */
        return;

      /* update the class name selector. */
      elHtmlName =  GetXMLElementName (elType, doc);
      if (elHtmlName[0] == '?')
        InitConfirm (doc, 1, TtaGetMessage (LIB, TMSG_SEL_CLASS));
      else
        {
#ifdef _GTK
          TtaNewForm (BaseDialog + ClassForm, TtaGetViewFrame (doc, 1), 
                      TtaGetMessage (AMAYA, AM_DEF_CLASS), FALSE, 2, 'L', D_DONE);
#endif /* _GTK */
          NbClass = BuildClassList (doc, ListBuffer, MAX_CSS_LENGTH, elHtmlName);
#ifdef _GTK
          TtaNewSelector (BaseDialog + ClassSelect, BaseDialog + ClassForm,
                          TtaGetMessage (LIB, TMSG_SEL_CLASS),
                          NbClass, ListBuffer, 5, NULL, TRUE, FALSE);
#endif /* _GTK */
  
          /* preselect the entry corresponding to the class of the element. */
          if (!strcmp (schName, "MathML"))
            attrType.AttrTypeNum = MathML_ATTR_class;
#ifdef _SVG
          else if (!strcmp (schName, "SVG"))
            attrType.AttrTypeNum = SVG_ATTR_class;
#endif /* _SVG */
          else
            attrType.AttrTypeNum = HTML_ATTR_Class;
          attr = TtaGetAttribute (ClassReference, attrType);
          if (attr)
            {
              len = 50;
              TtaGiveTextAttributeValue (attr, a_class, &len);
#ifdef _GTK
              TtaSetSelector (BaseDialog + ClassSelect, -1, a_class);
#endif /* _GTK */
              strcpy (CurrentClass, a_class);
            }
          else
            {
#ifdef _GTK
              TtaSetSelector (BaseDialog + ClassSelect, 0, NULL);
#endif /* _GTK */
              strcpy (CurrentClass, elHtmlName);
            }
  
#ifdef _WX
          CreateListEditDlgWX( BaseDialog+ClassForm,
                               TtaGetViewFrame(doc, 1),
                               TtaGetMessage(AMAYA, AM_DEF_CLASS),
                               TtaGetMessage(LIB, TMSG_SEL_CLASS),
                               NbClass,
                               ListBuffer,
                               CurrentClass );
#endif /* _WX */

          /* pop-up the dialogue box. */
#if defined(_GTK) | defined(_WX)
          TtaShowDialogue (BaseDialog + ClassForm, TRUE);
#endif  /* defined(_GTK) | defined(_WX) */

#ifdef _WINGUI
          CreateRuleDlgWindow (TtaGetViewFrame (doc, 1), NbClass, ListBuffer);
#endif /* _WINGUI */
        }
    }
}

/*----------------------------------------------------------------------
  ApplyClass
  Initialize and activate the Apply Class dialogue box.
  ----------------------------------------------------------------------*/
void ApplyClass (Document doc, View view)
{
  Attribute           attr = NULL;
  AttributeType       attrType;
  Element             el, ancestor;
  ElementType	        elType;
#ifdef _WX
  char                a_class_with_dot[51];
#endif /* _WX */
  char                a_class[50], *name;
  int                 len;
  int                 firstSelectedChar, lastSelectedChar;
#ifdef _GTK
  char                bufMenu[MAX_TXT_LEN];
#endif /* _GTK */

  TtaGiveFirstSelectedElement (doc, &el, &firstSelectedChar, &lastSelectedChar);
  if (el)
    {
      /* if the selected element is read-only, do nothing */
      if (TtaIsReadOnly (el))
        return;
    }
  else
    el = TtaGetRootElement (doc);

  elType = TtaGetElementType (el);
  CurrentClass[0] = EOS;
  ApplyClassDoc = doc;
  name =  TtaGetSSchemaName (elType.ElSSchema);
  if ((strcmp (name, "HTML") && strcmp (name, "MathML") && strcmp (name, "SVG")) ||
      !TtaGetDocumentAccessMode (doc))
    {
#ifdef _WX 
      AmayaParams p;
      p.param1 = 0;
      p.param2 = NULL;
      p.param3 = NULL;
      p.param4 = (void*)(BaseDialog+AClassForm); /* the dialog reference used to call the right callback in thotlib */
      TtaSendDataToPanel( WXAMAYA_PANEL_APPLYCLASS, p );
#endif /* _WX */
      return;
    }

  /* updating the class name selector. */
#ifdef _GTK
  strcpy (bufMenu, TtaGetMessage (LIB, TMSG_APPLY));
  TtaNewSheet (BaseDialog + AClassForm, TtaGetViewFrame (doc, 1), 
               TtaGetMessage (LIB, TMSG_APPLY_CLASS), 1,
               bufMenu, FALSE, 2, 'L', D_DONE);
#endif /* _GTK */
  NbClass = BuildClassList (doc, ListBuffer, MAX_CSS_LENGTH, "(no_class)");
#ifdef _GTK
  TtaNewSelector (BaseDialog + AClassSelect, BaseDialog + AClassForm,
                  TtaGetMessage (LIB, TMSG_SEL_CLASS),
                  NbClass, ListBuffer, 5, NULL, FALSE, TRUE);
#endif /* _GTK */

  if (el)
    {
      /* preselect the entry corresponding to the class of the first selected
         element. */
      if (!strcmp (TtaGetSSchemaName (elType.ElSSchema), "MathML"))
        {
          attrType.AttrSSchema = elType.ElSSchema;
          attrType.AttrTypeNum = MathML_ATTR_class;
        }
#ifdef _SVG
      else if (!strcmp (TtaGetSSchemaName (elType.ElSSchema), "SVG"))
        {
          attrType.AttrSSchema = elType.ElSSchema;
          attrType.AttrTypeNum = SVG_ATTR_class;
        }
#endif /* _SVG */
      else
        {
          attrType.AttrSSchema = TtaGetSSchema ("HTML", doc);
          attrType.AttrTypeNum = HTML_ATTR_Class;
        }
      ancestor = el;
      do
        {
          attr = TtaGetAttribute (ancestor, attrType);
          if (!attr)
            ancestor = TtaGetParent (ancestor);
        }
      while (!attr && ancestor);
    }

  if (attr)
    {
      len = 50;
      TtaGiveTextAttributeValue (attr, a_class, &len);
#ifdef _GTK
      TtaSetSelector (BaseDialog + AClassSelect, -1, a_class);
#endif /* _GTK */
#ifdef _WX
      a_class_with_dot[0] = EOS;
      strcat(a_class_with_dot, ".");
      strcat(a_class_with_dot, a_class);      
      strcpy (CurrentClass, a_class_with_dot);
#else /* _WX */
      strcpy (CurrentClass, a_class);
#endif /* _WX */
    }
  else
    {
#ifdef _GTK
      TtaSetSelector (BaseDialog + AClassSelect, 0, NULL);
#endif /* _GTK */
      strcpy (CurrentClass, "(no_class)");
    }

  /* pop-up the dialogue box. */
#ifdef _GTK
  TtaShowDialogue (BaseDialog + AClassForm, TRUE);
#endif /* _GTK */

#ifdef _WINGUI
  CreateApplyClassDlgWindow (TtaGetViewFrame (doc, 1), NbClass, ListBuffer);
#endif /* _WINGUI */

#ifdef _WX  
  AmayaParams p;
  p.param1 = NbClass;
  p.param2 = (void*)ListBuffer;
  p.param3 = (void*)CurrentClass;
  p.param4 = (void*)(BaseDialog+AClassForm); /* the dialog reference used to call the right callback in thotlib */
  TtaSendDataToPanel( WXAMAYA_PANEL_APPLYCLASS, p );
#endif /* _WX */
}

/*----------------------------------------------------------------------
  DoLeftAlign
  Apply left-align style
  ----------------------------------------------------------------------*/
void DoLeftAlign (Document doc, View view)
{
  ThotCallback (NumMenuAlignment, INTEGER_DATA, (char*) 0);
  ThotCallback (NumFormPresFormat, INTEGER_DATA, (char*) 1); /* Apply */
}

/*----------------------------------------------------------------------
  DoRightAlign
  Apply right-align style
  ----------------------------------------------------------------------*/
void DoRightAlign (Document doc, View view)
{
  ThotCallback (NumMenuAlignment, INTEGER_DATA, (char*) 1);
  ThotCallback (NumFormPresFormat, INTEGER_DATA, (char*) 1); /* Apply */
}

/*----------------------------------------------------------------------
  DoCenter
  Apply center style
  ----------------------------------------------------------------------*/
void DoCenter (Document doc, View view)
{
  ThotCallback (NumMenuAlignment, INTEGER_DATA, (char*) 2);
  ThotCallback (NumFormPresFormat, INTEGER_DATA, (char*) 1); /* Apply */
}

/*----------------------------------------------------------------------
  DoJustify
  Apply justify style
  ----------------------------------------------------------------------*/
void DoJustify (Document doc, View view)
{
  ThotCallback (NumMenuAlignment, INTEGER_DATA, (char*) 3);
  ThotCallback (NumFormPresFormat, INTEGER_DATA, (char*) 1); /* Apply */
}

/*----------------------------------------------------------------------
  StyleCallbackDialogue : procedure for style dialogue events        
  ----------------------------------------------------------------------*/
void StyleCallbackDialogue (int ref, int typedata, char  *data)
{
  long int          val;

  val = (long int) data;
#ifdef DEBUG_CLASS_INTERF
  if (typedata == INTEGER_DATA)
    fprintf (stderr, "StyleCallbackDialogue(%d,%d) \n", ref, (int) data);
  else if (typedata == STRING_DATA)
    fprintf (stderr, "StyleCallbackDialogue(%d,\"%s\") \n", ref, (char*) data);
#endif

  switch (ref - BaseDialog)
    {
    case ClassForm:
      if (val == 1)
        UpdateClass (DocReference);
      TtaDestroyDialogue (BaseDialog + ClassForm);
      break;
    case ClassSelect:
      strcpy (CurrentClass, data);
      break;
    case AClassSelect:
      strcpy (CurrentClass, data);
      break;
    case AClassForm:
      if (val == 1)
        DoApplyClass (ApplyClassDoc);
      else
        TtaDestroyDialogue (BaseDialog + AClassForm);
      break;
    default:
      break;
    }
}
