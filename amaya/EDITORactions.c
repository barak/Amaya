/*
 *
 *  (c) COPYRIGHT INRIA and W3C, 1996-2005
 *  Please first read the full copyright statement in file COPYRIGHT.
 *
 */

/*
 * Menu bar functions of Amaya application.
 *
 * Author: I. Vatton
 *
 */

/* Included headerfiles */
#define THOT_EXPORT extern

#ifdef _WX
#include "wx/wx.h"
#endif /* _WX */

#include "amaya.h"
#include "css.h"
#include "undo.h"
#include "document.h"
#include "MENUconf.h"

#ifdef ANNOTATIONS
#include "annotlib.h"
#include "ANNOTevent_f.h"
#include "ANNOTmenu_f.h"
#endif /* ANNOTATIONS */

#ifdef BOOKMARKS
#include "BMevent_f.h"
#endif /* BOOKMARKS */

#ifdef _WINGUI
#include "wininclude.h"
#endif /* _WINGUI */

#include "css_f.h"
#include "html2thot_f.h"
#include "init_f.h"
#include "query_f.h"
#include "AHTURLTools_f.h"
#include "EDITORactions_f.h"
#include "EDITimage_f.h"
#include "fetchXMLname_f.h"
#include "HTMLactions_f.h"
#include "HTMLedit_f.h"
#include "HTMLhistory_f.h"
#include "HTMLsave_f.h"
#include "HTMLtable_f.h"
#include "MathMLbuilder_f.h"
#include "MENUconf_f.h"
#include "styleparser_f.h"
#include "UIcss_f.h"
#include "SVGbuilder_f.h"
#include "SVGedit_f.h"
#include "XHTMLbuilder_f.h"
#include "wxdialogapi_f.h"

#ifdef _WX
#include "wxdialogapi_f.h"
#include "appdialogue_wx.h"
#endif /* _WX */

#ifdef DAV
#define WEBDAV_EXPORT extern
#include "davlib_f.h"
#endif /* DAV */
#include "libmanag_f.h"


/*----------------------------------------------------------------------
  NewXHTML: Create a new XHTML document
  ----------------------------------------------------------------------*/
void NewXHTML (Document document, View view)
{
  OpenNew (document, view, docHTML, 0);
}

/*----------------------------------------------------------------------
  NewXHTMLBasic: Create a new Basic XHTML document
  ----------------------------------------------------------------------*/
void NewXHTMLBasic (Document document, View view)
{
  OpenNew (document, view, docHTML, L_Basic);
}

/*----------------------------------------------------------------------
  NewXHTMLStrict: Create a new Strict XHTML document
  ----------------------------------------------------------------------*/
void NewXHTMLStrict (Document document, View view)
{
  OpenNew (document, view, docHTML, L_Strict);
}

/*----------------------------------------------------------------------
  NewXHTML11: Create a new XHTML1.1 document
  ----------------------------------------------------------------------*/
void NewXHTML11 (Document document, View view)
{
  OpenNew (document, view, docHTML, L_Xhtml11);
}

/*----------------------------------------------------------------------
  NewXHTMLTransitional: Create a new Transitional XHTML document
  ----------------------------------------------------------------------*/
void NewXHTMLTransitional (Document document, View view)
{
  OpenNew (document, view, docHTML, L_Transitional);
}

/*----------------------------------------------------------------------
  NewMathML: Create a new MathML document
  ----------------------------------------------------------------------*/
void NewMathML (Document document, View view)
{
  OpenNew (document, view, docMath, L_MathML);
}

/*----------------------------------------------------------------------
  NewSVG: Create a new XHTML document
  ----------------------------------------------------------------------*/
void NewSVG (Document document, View view)
{
  OpenNew (document, view, docSVG, L_Other);
}

/*----------------------------------------------------------------------
  NewCss: Create a new CSS stylesheet
  ----------------------------------------------------------------------*/
void NewCss (Document document, View view)
{
  OpenNew (document, view, docCSS, L_Other);
}

/*--------------------------------------------------------------------------
  CreateDoctype creates a doctype declaration
  The parameter doctype points to the current DOCTYPE or NULL.
  Parameters useMathML and useSVG determine the XHTML 1.1 profile.
  --------------------------------------------------------------------------*/
void CreateDoctype (Document doc, Element doctype, int profile,
                    ThotBool useMathML, ThotBool useSVG)
{
  ElementType     elType, lineType, piType;
  Element         docEl, doctypeLine, text, child, prev;
  Language        language;
  char		  buffer[400], *name;
  
  /* Don't check the Thot abstract tree against the structure schema. */
  TtaSetStructureChecking (FALSE, doc);
  
  /* We use the Latin_Script language to avoid */
  /* the spell_chekcer to check the doctype */
  language = Latin_Script;
  docEl = TtaGetMainRoot (doc);
  elType = TtaGetElementType (docEl);
  lineType.ElSSchema = elType.ElSSchema;
  piType.ElSSchema = elType.ElSSchema;
  name = TtaGetSSchemaName (elType.ElSSchema);
  /* Add the new doctype */
  if (profile == L_Basic || profile == L_Strict ||
      profile == L_Xhtml11 || profile == L_Transitional)
    {
      elType.ElTypeNum = HTML_EL_DOCTYPE;
      lineType.ElTypeNum = HTML_EL_DOCTYPE_line;
      piType.ElTypeNum = HTML_EL_XMLPI;
    }
#ifdef _SVG
  else if (profile == L_SVG) 
    {
      elType.ElTypeNum = SVG_EL_DOCTYPE;
      lineType.ElTypeNum = SVG_EL_DOCTYPE_line;
      piType.ElTypeNum = HTML_EL_XMLPI;
    }
#endif /* _SVG */
  else if (profile == L_MathML) 
    {
      elType.ElTypeNum = MathML_EL_DOCTYPE;
      lineType.ElTypeNum = MathML_EL_DOCTYPE_line;
      piType.ElTypeNum = MathML_EL_XMLPI;
    }

  if (doctype == NULL)
    {
      /* no DOCTYPE already declared */
      doctype = TtaNewElement (doc, elType);
      /* skip PI */
      child = TtaGetFirstChild (docEl);
      if (child == NULL)
        TtaInsertFirstChild (&doctype, docEl, doc);
      else
        while (child)
          {
            elType = TtaGetElementType (child);
            if (piType.ElTypeNum == elType.ElTypeNum &&
                piType.ElSSchema == elType.ElSSchema)
              {
                /* it's a PI */
                prev = child;
                TtaNextSibling (&child);
                if (child == NULL)
                  TtaInsertSibling (doctype, prev, FALSE, doc);
              }
            else
              {
                /* insert before this child */
                TtaInsertSibling (doctype, child, TRUE, doc);
                child = NULL;
              }
          }
      /* Make the DOCTYPE element read-only */
      TtaSetAccessRight (doctype, ReadOnly, doc);
    }
  else
    {
      doctypeLine = TtaGetFirstChild (doctype);
      while (doctypeLine)
        {
          TtaDeleteTree (doctypeLine, doc);
          doctypeLine = TtaGetFirstChild (doctype);
        }
    }
  /* Create the first DOCTYPE_line element */
  elType.ElTypeNum = lineType.ElTypeNum;
  doctypeLine = TtaNewElement (doc, elType);
  TtaInsertFirstChild (&doctypeLine, doctype, doc);
  elType.ElTypeNum = 1;
  text = TtaNewElement (doc, elType);
  if (text != NULL)
    {
      TtaInsertFirstChild (&text, doctypeLine, doc);
      if (profile == L_Basic)
        TtaSetTextContent (text, (unsigned char*)DOCTYPE1_XHTML10_BASIC, language, doc);
      else if (profile == L_Strict && DocumentMeta[doc]->xmlformat)
        TtaSetTextContent (text, (unsigned char*)DOCTYPE1_XHTML10_STRICT, language, doc);
      else if (profile == L_Strict && !DocumentMeta[doc]->xmlformat)
        TtaSetTextContent (text, (unsigned char*)DOCTYPE1_HTML_STRICT, language, doc);
      else if (profile == L_Xhtml11 && useMathML && !useSVG)
        {
          strcpy (buffer, DOCTYPE1_XHTML11_PLUS_MATHML);
          TtaSetTextContent (text, (unsigned char*)buffer, language, doc);
        }
      else if (profile == L_Xhtml11 && useSVG)
        {
          if (useMathML)
            {
              strcpy (buffer, DOCTYPE1_XHTML11_PLUS_MATHML_PLUS_SVG);
              TtaSetTextContent (text, (unsigned char*)buffer, language, doc);
            }
          else
            TtaSetTextContent (text, (unsigned char*)DOCTYPE1_XHTML11_PLUS_MATHML_PLUS_SVG,
                               language, doc);
        }
      else if (profile == L_Xhtml11)
        TtaSetTextContent (text, (unsigned char*)DOCTYPE1_XHTML11, language, doc);
      else if (profile == L_Transitional && DocumentMeta[doc]->xmlformat)
        TtaSetTextContent (text, (unsigned char*)DOCTYPE1_XHTML10_TRANSITIONAL, language, doc);
      else if (profile == L_Transitional && !DocumentMeta[doc]->xmlformat)
        TtaSetTextContent (text, (unsigned char*)DOCTYPE1_HTML_TRANSITIONAL, language, doc);
      else if (profile == L_MathML)
        TtaSetTextContent (text, (unsigned char*)DOCTYPE1_MATHML20, language, doc);
      else if (profile == L_SVG)
        TtaSetTextContent (text, (unsigned char*)DOCTYPE1_SVG10, language, doc);
    }
  
  /* Create the second DOCTYPE_line element */
  elType.ElTypeNum = lineType.ElTypeNum;
  doctypeLine = TtaNewElement (doc, elType);
  child = TtaGetLastChild (doctype);
  TtaInsertSibling (doctypeLine, child, FALSE, doc);
  elType.ElTypeNum = 1;
  text = TtaNewElement (doc, elType);
  if (text != NULL)
    {
      TtaInsertFirstChild (&text, doctypeLine, doc);
      if (profile == L_Basic)
        TtaSetTextContent (text, (unsigned char*)DOCTYPE2_XHTML10_BASIC, language, doc);
      else if (profile == L_Strict && DocumentMeta[doc]->xmlformat)
        TtaSetTextContent (text, (unsigned char*)DOCTYPE2_XHTML10_STRICT, language, doc);
      else if (profile == L_Strict && !DocumentMeta[doc]->xmlformat)
        TtaSetTextContent (text, (unsigned char*)DOCTYPE2_HTML_STRICT, language, doc);
      else if (profile == L_Xhtml11 && useMathML && !useSVG)
        TtaSetTextContent (text, (unsigned char*)DOCTYPE2_XHTML11_PLUS_MATHML, language, doc);
      else if (profile == L_Xhtml11 && useSVG)
        TtaSetTextContent (text, (unsigned char*)DOCTYPE2_XHTML11_PLUS_MATHML_PLUS_SVG, language,
                           doc);
      else if (profile == L_Xhtml11)
        TtaSetTextContent (text, (unsigned char*)DOCTYPE2_XHTML11, language, doc);
      else if (profile == L_Transitional && DocumentMeta[doc]->xmlformat)
        TtaSetTextContent (text, (unsigned char*)DOCTYPE2_XHTML10_TRANSITIONAL, language, doc);
      else if (profile == L_Transitional && !DocumentMeta[doc]->xmlformat)
        TtaSetTextContent (text, (unsigned char*)DOCTYPE2_HTML_TRANSITIONAL, language, doc);
      else if (profile == L_MathML)
        TtaSetTextContent (text, (unsigned char*)DOCTYPE2_MATHML20, language, doc);
      else if (profile == L_SVG)
        TtaSetTextContent (text, (unsigned char*)DOCTYPE2_SVG10, language, doc);
    }
  TtaSetStructureChecking (TRUE, doc);
  return;
}

/*----------------------------------------------------------------------
  InitializeNewDoc builds the initial contents of a new document
  When the parameter doc is 0 the function creates a new document window.
  The url is coded with the default charset.
  ----------------------------------------------------------------------*/
void InitializeNewDoc (char *url, int docType, Document doc, int profile,
                       ThotBool isXML)
{
  ElementType          elType;
  Element              docEl, root, title, text, el, head, child, meta, body;
  Element              doctype;
  AttributeType        attrType;
  Attribute            attr;
  Language             language;
  char                *pathname, *documentname;
  char                *s;
  char                 tempfile[MAX_LENGTH];
  char                *charsetName;
  CHARSET              charset;
  ThotBool             xhtml_mimetype;

  if (!IsW3Path (url) && TtaFileExist (url))
    {
      s = (char *)TtaGetMemory (strlen (url) +
                                strlen (TtaGetMessage (AMAYA, AM_OVERWRITE_CHECK)) + 2);
      sprintf (s, TtaGetMessage (AMAYA, AM_OVERWRITE_CHECK), url);
      InitConfirm (0, 0, s);
      TtaFreeMemory (s);
      if (!UserAnswer)
        return;
    }

  pathname = (char *)TtaGetMemory (MAX_LENGTH);
  documentname = (char *)TtaGetMemory (MAX_LENGTH);
  NormalizeURL (url, 0, pathname, documentname, NULL);
  if (doc == 0 || DontReplaceOldDoc)
    {
      doc = InitDocAndView (doc,
                            !DontReplaceOldDoc /* replaceOldDoc */,
                            InNewWindow /* inNewWindow */,
                            documentname, (DocumentType)docType, 0, FALSE, profile,
                            CE_ABSOLUTE);
      InitDocHistory (doc);
      DontReplaceOldDoc = FALSE;
    }
  else
    {
      /* record the current position in the history */
      AddDocHistory (doc, DocumentURLs[doc], 
                     DocumentMeta[doc]->initial_url,
                     DocumentMeta[doc]->form_data,
                     DocumentMeta[doc]->method);
      doc = InitDocAndView (doc,
                            !DontReplaceOldDoc /* replaceOldDoc */,
                            InNewWindow /* inNewWindow */,
                            documentname, (DocumentType)docType, 0, FALSE, profile,
                            CE_ABSOLUTE);
    }
  TtaFreeMemory (documentname);
  TtaFreeMemory (pathname);

  /* save the document name into the document table */
  s = TtaStrdup (url);
  DocumentURLs[doc] = s;
  AddURLInCombobox (url, NULL, TRUE);
  TtaSetTextZone (doc, 1, URL_list);
  DocumentMeta[doc] = DocumentMetaDataAlloc ();
  DocumentMeta[doc]->form_data = NULL;
  DocumentMeta[doc]->initial_url = NULL;
  DocumentMeta[doc]->method = CE_ABSOLUTE;
  DocumentMeta[doc]->xmlformat = FALSE;
  DocumentMeta[doc]->compound = FALSE;
  DocumentSource[doc] = 0;

  /* store the document profile */
  TtaSetDocumentProfile (doc, profile);

  ResetStop (doc);
  language = TtaGetDefaultLanguage ();
  docEl = TtaGetMainRoot (doc);
  /* Set the document charset */
  charsetName = TtaGetEnvString ("DOCUMENT_CHARSET");
  charset = TtaGetCharset (charsetName);
  if (charset != UNDEFINED_CHARSET)
    {
      TtaSetDocumentCharset (doc, charset, FALSE);
      DocumentMeta[doc]->charset = TtaStrdup (charsetName);
    }
  else
    {
      TtaSetDocumentCharset (doc, ISO_8859_1, FALSE);
      DocumentMeta[doc]->charset = TtaStrdup ("iso-8859-1");
    }

  elType = TtaGetElementType (docEl);
  attrType.AttrSSchema = elType.ElSSchema;

  if (docType == docHTML)
    {
      /*-------------  New XHTML document ------------*/
      /* force the XML parsing */
      DocumentMeta[doc]->xmlformat = isXML;
      DocumentMeta[doc]->compound = FALSE;
      TtaGetEnvBoolean ("ENABLE_XHTML_MIMETYPE", &xhtml_mimetype);
      if (xhtml_mimetype)
        DocumentMeta[doc]->content_type = TtaStrdup (AM_XHTML_MIME_TYPE);
      else
        DocumentMeta[doc]->content_type = TtaStrdup ("text/html");

      /* create the DOCTYPE element corresponding to the document's profile */
      elType.ElTypeNum = HTML_EL_DOCTYPE;
      doctype = TtaSearchTypedElement (elType, SearchInTree, docEl);
      if (profile != L_Other)
        CreateDoctype (doc, doctype, profile, FALSE, FALSE);
      else if (doctype)
        TtaDeleteTree (doctype, doc);
      
      /* Load user's style sheet */
      LoadUserStyleSheet (doc);

      /* Set the namespace declaration */
      elType.ElTypeNum = HTML_EL_HTML;
      root = TtaSearchTypedElement (elType, SearchInTree, docEl);
      TtaSetUriSSchema (elType.ElSSchema, XHTML_URI);
      TtaSetANamespaceDeclaration (doc, root, NULL, XHTML_URI);

      /* attach an attribute PrintURL to the root element */
      attrType.AttrTypeNum = HTML_ATTR_PrintURL;
      attr = TtaNewAttribute (attrType);
      TtaAttachAttribute (root, attr, doc);

      /* create a default title if there is no content in the TITLE element */
      elType.ElTypeNum = HTML_EL_TITLE;
      title = TtaSearchTypedElement (elType, SearchInTree, root);
      text = TtaGetFirstChild (title);
      if (TtaGetTextLength (text) == 0)
        {
          if (Answer_text[0] == EOS)
            TtaSetTextContent (text, (unsigned char*)"No title", language, doc);
          else
            TtaSetTextContent (text, (unsigned char*)Answer_text, language, doc);
        }
      UpdateTitle (title, doc);

      elType.ElTypeNum = HTML_EL_HEAD;
      head = TtaSearchTypedElement (elType, SearchInTree, root);

      /* create a Document_URL element as the first child of HEAD */
      elType.ElTypeNum = HTML_EL_Document_URL;
      el = TtaSearchTypedElement (elType, SearchInTree, head);
      if (el == NULL)
        {
          /* there is no Document_URL element, create one */
          el = TtaNewElement (doc, elType);
          TtaInsertFirstChild (&el, head, doc);
        }
      /* prevent the user from editing this element */
      TtaSetAccessRight (el, ReadOnly, doc);
      /* element Document_URL already exists */
      text = TtaGetFirstChild (el);
      if (text == NULL)
        {
          elType.ElTypeNum = HTML_EL_TEXT_UNIT;
          text = TtaNewElement (doc, elType);
          TtaInsertFirstChild (&text, el, doc);
        }
      if (url != NULL && text != NULL)
        TtaSetTextContent (text, (unsigned char*)url, language, doc);

      /* create a META element in the HEAD with name="generator" */
      /* and content="Amaya" */
      child = TtaGetLastChild (head);
      elType.ElTypeNum = HTML_EL_META;
      meta = TtaNewElement (doc, elType);
      attrType.AttrTypeNum = HTML_ATTR_meta_name;
      attr = TtaNewAttribute (attrType);
      TtaAttachAttribute (meta, attr, doc);
      TtaSetAttributeText (attr, "generator", meta, doc);
      attrType.AttrTypeNum = HTML_ATTR_meta_content;
      attr = TtaNewAttribute (attrType);
      TtaAttachAttribute (meta, attr, doc);
      strcpy (tempfile, "Amaya");
      strcat (tempfile, " ");
      strcat (tempfile, TtaGetAppVersion());
      strcat (tempfile, ", see http://www.w3.org/Amaya/");
      TtaSetAttributeText (attr, tempfile, meta, doc);
      TtaInsertSibling (meta, child, FALSE, doc);

      /* create a BODY element if there is not */
      elType.ElTypeNum = HTML_EL_BODY;
      body = TtaSearchTypedElement (elType, SearchInTree, root);
      if (!body)
        {
          body = TtaNewTree (doc, elType, "");
          TtaInsertSibling (body, head, FALSE, doc);
        }

      /* Search the first element in the BODY to set initial selection */
      elType.ElTypeNum = HTML_EL_Element;
      el = TtaSearchTypedElement (elType, SearchInTree, body);
      /* set the initial selection */
      TtaSelectElement (doc, el);
      if (SelectionDoc != 0)
        UpdateContextSensitiveMenus (SelectionDoc);
      SelectionDoc = doc;
      UpdateContextSensitiveMenus (doc);
      /* Activate show areas */
      if (MapAreas[doc])
        ChangeAttrOnRoot (doc, HTML_ATTR_ShowAreas);
    }
  else if (docType == docMath)
    {
      /*-------------  New MathML document ------------*/
      /* Set the IntDisplaystyle attribute */
      elType.ElTypeNum = MathML_EL_MathML;
      root = TtaSearchTypedElement (elType, SearchInTree, docEl);
      if (root)
        SetDisplaystyleMathElement (root, doc);

      /* create the MathML DOCTYPE element */
      elType.ElTypeNum = MathML_EL_DOCTYPE;
      doctype = TtaSearchTypedElement (elType, SearchInTree, docEl);
      CreateDoctype (doc, doctype, L_MathML, FALSE, FALSE);

      /* Set the namespace declaration */
      root = TtaGetRootElement (doc);
      TtaSetUriSSchema (elType.ElSSchema, MathML_URI);
      TtaSetANamespaceDeclaration (doc, root, NULL, MathML_URI);

      /* force the XML parsing */
      DocumentMeta[doc]->xmlformat = TRUE;
      DocumentMeta[doc]->compound = FALSE;
      /* Search the first Construct to set the initial selection */
      elType.ElTypeNum = MathML_EL_Construct;
      el = TtaSearchTypedElement (elType, SearchInTree, docEl);
      /* set the initial selection */
      TtaSelectElement (doc, el);
      if (SelectionDoc != 0)
        UpdateContextSensitiveMenus (SelectionDoc);
      SelectionDoc = doc;
      UpdateContextSensitiveMenus (doc);
    }
  else if (docType == docSVG)
    {
      /*-------------  New SVG document ------------*/
      /* create the SVG DOCTYPE element */
      elType.ElTypeNum = SVG_EL_DOCTYPE;
      doctype = TtaSearchTypedElement (elType, SearchInTree, docEl);
      CreateDoctype (doc, doctype, L_SVG, FALSE, FALSE);

      /* Set the namespace declaration */
      root = TtaGetRootElement (doc);
      TtaSetUriSSchema (elType.ElSSchema, SVG_URI);
      TtaSetANamespaceDeclaration (doc, root, NULL, SVG_URI);

      /* Set the version attribute */
      elType.ElTypeNum = SVG_EL_SVG;
      root = TtaSearchTypedElement (elType, SearchInTree, docEl);
      if (root)
        {
          attrType.AttrTypeNum = SVG_ATTR_version;
          attr = TtaNewAttribute (attrType);
          TtaAttachAttribute (root, attr, doc);
          TtaSetAttributeText (attr, SVG_VERSION, root, doc);

          /* create a default title if there is no title element */
          elType.ElTypeNum = SVG_EL_title;
          title = TtaSearchTypedElement (elType, SearchInTree, root);
          if (!title)
            {
              title = TtaNewTree (doc, elType, "");
              TtaInsertFirstChild (&title, root, doc);
            }
          text = TtaGetFirstChild (title);
          if (text && TtaGetTextLength (text) == 0)
            TtaSetTextContent (text, (unsigned char*)"No title", language,doc);
          UpdateTitle (title, doc);
        }

      /* force the XML parsing */
      DocumentMeta[doc]->xmlformat = TRUE;
      DocumentMeta[doc]->compound = FALSE;
      /* Search the last element to set the initial selection */
      el = TtaGetLastLeaf (docEl);
      /* set the initial selection */
      TtaSelectElement (doc, el);
      if (SelectionDoc != 0)
        UpdateContextSensitiveMenus (SelectionDoc);
      SelectionDoc = doc;
      UpdateContextSensitiveMenus (doc);
    }
  else
    {
      /*-------------  Other documents ------------*/
      elType.ElTypeNum = TextFile_EL_TextFile;
      root = TtaSearchTypedElement (elType, SearchInTree, docEl);

      if (docType == docCSS)
        {
          /* add the attribute Source */
          attrType.AttrTypeNum = TextFile_ATTR_Source;
          attr = TtaGetAttribute (root, attrType);
          if (attr == 0)
            {
              attr = TtaNewAttribute (attrType);
              TtaAttachAttribute (root, attr, doc);
            }
        }

      /* attach the default attribute PrintURL to the root element */
      attrType.AttrTypeNum = TextFile_ATTR_PrintURL;
      attr = TtaNewAttribute (attrType);
      TtaAttachAttribute (root, attr, doc);
      /* insert the Document_URL element */
      el = TtaGetFirstChild (root);
      if (el == NULL)
        {
          elType.ElTypeNum = TextFile_EL_Document_URL;
          el = TtaNewTree (doc, elType, "");
          TtaInsertFirstChild (&el, root, doc);
        }
      /* prevent the user from editing this element */
      TtaSetAccessRight (el, ReadOnly, doc);
      el = TtaGetFirstChild (el);     
      TtaSetTextContent (el, (unsigned char*)url, language, doc);

      body = TtaGetLastChild (root);
      /* get the line */
      el = TtaGetLastChild (body);
      /* and the empty text within this line */
      el = TtaGetLastChild (el);
      /* set the initial selection */
      TtaSelectElement (doc, el);
      SelectionDoc = doc;
    }

  /* Update the Doctype menu */
  UpdateDoctypeMenu (doc);
  /* the document should be saved */
  TtaSetDocumentUnmodified (doc);
  UpdateEditorMenus (doc);
}

/*----------------------------------------------------------------------
  NotFoundDoc builds the 404 error document
  When the parameter doc is 0 the function creates a new document window.
  The url is coded with the default charset.
  ----------------------------------------------------------------------*/
void NotFoundDoc (char *url, Document doc)
{
  ElementType          elType;
  Element              docEl, root, title, text, el, head, child, meta, body;
  Element              doctype;
  AttributeType        attrType;
  Attribute            attr;
  Language             language;
  char                *pathname, *documentname;
  char                *s;
  char                 tempfile[MAX_LENGTH];
  char                *charsetName;
  CHARSET              charset;
  ThotBool             xhtml_mimetype;

  pathname = (char *)TtaGetMemory (MAX_LENGTH);
  documentname = (char *)TtaGetMemory (MAX_LENGTH);
  NormalizeURL (url, 0, pathname, documentname, NULL);
  if (doc == 0 || DontReplaceOldDoc)
    {
      doc = InitDocAndView (doc,
                            !DontReplaceOldDoc /* replaceOldDoc */,
                            InNewWindow /* inNewWindow */,
                            documentname, docHTML, 0, FALSE, L_Strict,
                            CE_ABSOLUTE);
      InitDocHistory (doc);
      DontReplaceOldDoc = FALSE;
    }
  else
    {
      /* record the current position in the history */
      AddDocHistory (doc, DocumentURLs[doc], 
                     DocumentMeta[doc]->initial_url,
                     DocumentMeta[doc]->form_data,
                     DocumentMeta[doc]->method);
      doc = InitDocAndView (doc,
                            !DontReplaceOldDoc /* replaceOldDoc */,
                            InNewWindow /* inNewWindow */,
                            documentname, docHTML, 0, FALSE, L_Strict,
                            CE_ABSOLUTE);
    }
  TtaFreeMemory (documentname);
  TtaFreeMemory (pathname);

  /* save the document name into the document table */
  s = TtaStrdup (url);
  DocumentURLs[doc] = s;
  AddURLInCombobox (url, NULL, FALSE);
  TtaSetTextZone (doc, 1, URL_list);
  DocumentMeta[doc] = DocumentMetaDataAlloc ();
  DocumentMeta[doc]->form_data = NULL;
  DocumentMeta[doc]->initial_url = NULL;
  DocumentMeta[doc]->method = CE_ABSOLUTE;
  DocumentMeta[doc]->xmlformat = FALSE;
  DocumentMeta[doc]->compound = FALSE;
  DocumentSource[doc] = 0;

  /* store the document profile */
  TtaSetDocumentProfile (doc, L_Strict);
  ResetStop (doc);
  language = TtaGetDefaultLanguage ();
  docEl = TtaGetMainRoot (doc);
  /* Set the document charset */
  charsetName = TtaGetEnvString ("DOCUMENT_CHARSET");
  charset = TtaGetCharset (charsetName);
  if (charset != UNDEFINED_CHARSET)
    {
      TtaSetDocumentCharset (doc, charset, FALSE);
      DocumentMeta[doc]->charset = TtaStrdup (charsetName);
    }
  else
    {
      TtaSetDocumentCharset (doc, ISO_8859_1, FALSE);
      DocumentMeta[doc]->charset = TtaStrdup ("iso-8859-1");
    }

  elType = TtaGetElementType (docEl);
  attrType.AttrSSchema = elType.ElSSchema;

  /*-------------  New XHTML document ------------*/
  /* force the XML parsing */
  DocumentMeta[doc]->xmlformat = TRUE;
  DocumentMeta[doc]->compound = FALSE;
  TtaGetEnvBoolean ("ENABLE_XHTML_MIMETYPE", &xhtml_mimetype);
  if (xhtml_mimetype)
    DocumentMeta[doc]->content_type = TtaStrdup (AM_XHTML_MIME_TYPE);
  else
    DocumentMeta[doc]->content_type = TtaStrdup ("text/html");

  /* create the DOCTYPE element corresponding to the document's profile */
  elType.ElTypeNum = HTML_EL_DOCTYPE;
  doctype = TtaSearchTypedElement (elType, SearchInTree, docEl);
  if (doctype)
    TtaDeleteTree (doctype, doc);
  /* Load user's style sheet */
  LoadUserStyleSheet (doc);

  /* Set the namespace declaration */
  elType.ElTypeNum = HTML_EL_HTML;
  root = TtaSearchTypedElement (elType, SearchInTree, docEl);
  TtaSetUriSSchema (elType.ElSSchema, XHTML_URI);
  TtaSetANamespaceDeclaration (doc, root, NULL, XHTML_URI);

  /* attach an attribute PrintURL to the root element */
  attrType.AttrTypeNum = HTML_ATTR_PrintURL;
  attr = TtaNewAttribute (attrType);
  TtaAttachAttribute (root, attr, doc);

  s = (char *)TtaConvertByteToMbs ((unsigned char *)TtaGetMessage (LIB, TMSG_NOT_FOUND),
                                   TtaGetDefaultCharset ());
  /* create a default title if there is no content in the TITLE element */
  elType.ElTypeNum = HTML_EL_TITLE;
  title = TtaSearchTypedElement (elType, SearchInTree, root);
  text = TtaGetFirstChild (title);
  if (text && TtaGetTextLength (text) == 0)
    TtaSetTextContent (text, (unsigned char*)s, language, doc);
  UpdateTitle (title, doc);

  elType.ElTypeNum = HTML_EL_HEAD;
  head = TtaSearchTypedElement (elType, SearchInTree, root);

  /* create a Document_URL element as the first child of HEAD */
  elType.ElTypeNum = HTML_EL_Document_URL;
  el = TtaSearchTypedElement (elType, SearchInTree, head);
  if (el == NULL)
    {
      /* there is no Document_URL element, create one */
      el = TtaNewElement (doc, elType);
      TtaInsertFirstChild (&el, head, doc);
    }
  /* prevent the user from editing this element */
  TtaSetAccessRight (el, ReadOnly, doc);
  /* element Document_URL already exists */
  text = TtaGetFirstChild (el);
  if (text == NULL)
    {
      elType.ElTypeNum = HTML_EL_TEXT_UNIT;
      text = TtaNewElement (doc, elType);
      TtaInsertFirstChild (&text, el, doc);
    }
  if (url && text)
    TtaSetTextContent (text, (unsigned char*)url, language, doc);

  /* create a META element in the HEAD with name="generator" */
  /* and content="Amaya" */
  child = TtaGetLastChild (head);
  elType.ElTypeNum = HTML_EL_META;
  meta = TtaNewElement (doc, elType);
  attrType.AttrTypeNum = HTML_ATTR_meta_name;
  attr = TtaNewAttribute (attrType);
  TtaAttachAttribute (meta, attr, doc);
  TtaSetAttributeText (attr, "generator", meta, doc);
  attrType.AttrTypeNum = HTML_ATTR_meta_content;
  attr = TtaNewAttribute (attrType);
  TtaAttachAttribute (meta, attr, doc);
  strcpy (tempfile, TtaGetAppName());
  strcat (tempfile, " ");
  strcat (tempfile, TtaGetAppVersion());
  strcat (tempfile, ", see http://www.w3.org/Amaya/");
  TtaSetAttributeText (attr, tempfile, meta, doc);
  TtaInsertSibling (meta, child, FALSE, doc);

  /* create a BODY element if there is not */
  elType.ElTypeNum = HTML_EL_BODY;
  body = TtaSearchTypedElement (elType, SearchInTree, root);
  if (!body)
    {
      body = TtaNewTree (doc, elType, "");
      TtaInsertSibling (body, head, FALSE, doc);
    }

  /* Search the first element in the BODY to set initial selection */
  elType.ElTypeNum = HTML_EL_Element;
  el = TtaSearchTypedElement (elType, SearchInTree, body);
  /* Create a H1 */
  elType.ElTypeNum = HTML_EL_H1;
  child = TtaNewElement (doc, elType);
  TtaInsertSibling (child, el, TRUE, doc);
  /* Create a text */
  elType.ElTypeNum = HTML_EL_TEXT_UNIT;
  text = TtaNewElement (doc, elType);
  TtaSetTextContent (text, (unsigned char*)s, language, doc);
  TtaInsertFirstChild (&text, child, doc);
  /* Create a paragraph */
  elType.ElTypeNum = HTML_EL_Paragraph;
  child = TtaNewElement (doc, elType);
  TtaInsertSibling (child, el, TRUE, doc);
  /* Create a text */
  TtaFreeMemory (s);
  s = (char *)TtaConvertByteToMbs ((unsigned char *)TtaGetMessage (AMAYA, AM_CANNOT_LOAD),
                                   TtaGetDefaultCharset ());
  elType.ElTypeNum = HTML_EL_TEXT_UNIT;
  text = TtaNewElement (doc, elType);
  if (s)
    {
      pathname = (char *)TtaGetMemory (strlen (s) + strlen (url) + 1);
      sprintf (pathname, s, url);
      TtaSetTextContent (text, (unsigned char*)pathname, language, doc);
      TtaFreeMemory (pathname);
      TtaFreeMemory (s);
    }
  TtaInsertFirstChild (&text, child, doc);
      
  /* set the initial selection */
  UpdateContextSensitiveMenus (doc);
  /* Activate show areas */
  if (MapAreas[doc])
    ChangeAttrOnRoot (doc, HTML_ATTR_ShowAreas);

  /* Update the Doctype menu */
  UpdateDoctypeMenu (doc);
  /* the document should be saved */
  TtaSetDocumentUnmodified (doc);
  UpdateEditorMenus (doc);
  TtaSetAccessRight (root, ReadOnly, doc);
}

/*--------------------------------------------------------------------------
  CreateOrChangeDoctype
  Create or change the doctype of a document
  --------------------------------------------------------------------------*/
static void CreateOrChangeDoctype (Document doc, View view, int new_doctype,
                                   ThotBool xmlDoctype,
                                   ThotBool useMathML, ThotBool useSVG)
{
  char           *tempdoc = NULL; 
  char            documentname[MAX_LENGTH];
  char            tempdir[MAX_LENGTH];
  int             oldprofile;
  ThotBool        ok = FALSE, error = FALSE;
  
  /* The document has to be parsed with the new doctype */
  tempdoc = GetLocalPath (doc, DocumentURLs[doc]);
  if (TtaIsDocumentUpdated (doc) || !TtaFileExist (tempdoc) ||
      (!DocumentMeta[doc]->xmlformat && xmlDoctype))
    {
      /* save the current state of the document */
      if (DocumentTypes[doc] == docLibrary || DocumentTypes[doc] == docHTML)
        {
          if (TtaGetDocumentProfile (doc) == L_Xhtml11 || TtaGetDocumentProfile (doc) == L_Basic)
            TtaExportDocumentWithNewLineNumbers (doc, tempdoc, "HTMLT11");
          else if (DocumentMeta[doc]->xmlformat || xmlDoctype)
            TtaExportDocumentWithNewLineNumbers (doc, tempdoc, "HTMLTX");
          else
            TtaExportDocumentWithNewLineNumbers (doc, tempdoc, "HTMLT");
        }
      else if (DocumentTypes[doc] == docSVG)
        TtaExportDocumentWithNewLineNumbers (doc, tempdoc, "SVGT");
      else if (DocumentTypes[doc] == docMath)
        TtaExportDocumentWithNewLineNumbers (doc, tempdoc, "MathMLT");
      else
        TtaExportDocumentWithNewLineNumbers (doc, tempdoc, NULL);
    }

  /* Parse the document with the new doctype */
  TtaExtractName (tempdoc, tempdir, documentname);
  /* change the document profile */
  oldprofile = TtaGetDocumentProfile (doc);
  ok = ParseWithNewDoctype (doc, tempdoc, tempdir, documentname, new_doctype,
                            &error, xmlDoctype, useMathML, useSVG);

  if (ok)
    {
      /* Update the Doctype menu */
      UpdateDoctypeMenu (doc);
      /* Notify the document as modified */
      TtaSetDocumentModified (doc);
      /* Reparse the document to remove the errors */
      if (error)
        {
          RestartParser (doc, tempdoc, tempdir, documentname, FALSE, FALSE);
          TtaSetDocumentModified (doc);
        }
      TtaSetDocumentUnupdated (doc);
    }
  else
    /* restore the document profile */
    TtaSetDocumentProfile (doc, oldprofile);

  TtaFreeMemory (tempdoc);
}

/*--------------------------------------------------------------------------
  RemoveDoctype
  Remove the doctype declaration
  --------------------------------------------------------------------------*/
void RemoveDoctype (Document document, View view)
{

  ElementType     elType;
  Element         docEl, doctype;
  char           *s;

  docEl = TtaGetMainRoot (document);
  elType = TtaGetElementType (docEl);

  /* Search the doctype declaration according to the main schema */
  s = TtaGetSSchemaName (elType.ElSSchema);
  if (strcmp (s, "HTML") == 0)
    elType.ElTypeNum = HTML_EL_DOCTYPE;
  else if (strcmp (s, "SVG") == 0)
    elType.ElTypeNum = SVG_EL_DOCTYPE;
  else if (strcmp (s, "MathML") == 0)
    elType.ElTypeNum = MathML_EL_DOCTYPE;
  else
    elType.ElTypeNum = XML_EL_doctype;
  doctype = TtaSearchTypedElement (elType, SearchInTree, docEl);

  /* remove the existing doctype */
  if (doctype != NULL)
    {
      TtaDeleteTree (doctype, document);
      TtaSetDocumentProfile (document, L_Other);
      UpdateDoctypeMenu (document);
      TtaSetDocumentModified (document);
    }
  /* Synchronize the document */
  Synchronize (document, view);
}

/*--------------------------------------------------------------------------
  AddDoctype
  Add the doctype declaration
  --------------------------------------------------------------------------*/
void AddDoctype (Document document, View view)
{

  DocumentType    docType;
  int             profile;
  ThotBool	      useMathML, useSVG;
 
  HasNatures (document, &useMathML, &useSVG);
  profile =  L_Other;
  docType = DocumentTypes[document];
  if (docType == docHTML)
    {
      if (useMathML || useSVG)
        profile = L_Xhtml11;
      else
        profile = L_Transitional;
    }
  else if (docType == docMath)
    profile = L_MathML;
  else if (docType == docSVG)
    profile = L_SVG;

  CreateOrChangeDoctype (document, view, profile, DocumentMeta[document]->xmlformat,
                         useMathML, useSVG);
  UpdateEditorMenus (document);
}

/*--------------------------------------------------------------------------
  CreateDoctypeXhtml11
  Create or change the doctype for a XHTML 1.1 document
  --------------------------------------------------------------------------*/
void CreateDoctypeXhtml11 (Document document, View view)
{
  ThotBool	  useMathML, useSVG;
 
  HasNatures (document, &useMathML, &useSVG);
  CreateOrChangeDoctype (document, view, L_Xhtml11, TRUE, useMathML, useSVG);
  UpdateEditorMenus (document);
}

/*--------------------------------------------------------------------------
  CreateDoctypeXhtmlTransitional
  Create or change the doctype for a XHTML Transitional document
  --------------------------------------------------------------------------*/
void CreateDoctypeXhtmlTransitional (Document document, View view)
{
  ThotBool	  useMathML, useSVG;
 
  HasNatures (document, &useMathML, &useSVG);
  CreateOrChangeDoctype (document, view, L_Transitional, TRUE, useMathML, useSVG);
  UpdateEditorMenus (document);
}

/*--------------------------------------------------------------------------
  CreateDoctypeXhtmlStrict
  Create or change the doctype for a XHTML 1.0 Strict document
  --------------------------------------------------------------------------*/
void CreateDoctypeXhtmlStrict (Document document, View view)
{
  ThotBool	  useMathML, useSVG;
 
  HasNatures (document, &useMathML, &useSVG);
  CreateOrChangeDoctype (document, view, L_Strict, TRUE, useMathML, useSVG);
  UpdateEditorMenus (document);
}

/*--------------------------------------------------------------------------
  CreateDoctypeXhtmlBasic
  Create or change the doctype for a XHTML 1.0 Basic document
  --------------------------------------------------------------------------*/
void CreateDoctypeXhtmlBasic (Document document, View view)
{
  ThotBool	  useMathML, useSVG;
 
  HasNatures (document, &useMathML, &useSVG);
  CreateOrChangeDoctype (document, view, L_Basic, TRUE, useMathML, useSVG);
  UpdateEditorMenus (document);
}

/*--------------------------------------------------------------------------
  CreateDoctypeHtmlTransitional
  Create or change the doctype for a HTML Transitional document
  --------------------------------------------------------------------------*/
void CreateDoctypeHtmlTransitional (Document document, View view)
{
  CreateOrChangeDoctype (document, view, L_Transitional, FALSE, FALSE, FALSE);
  UpdateEditorMenus (document);
}

/*--------------------------------------------------------------------------
  CreateDoctypeHtmlStrict
  Create or change the doctype for a HTML Strict document
  --------------------------------------------------------------------------*/
void CreateDoctypeHtmlStrict (Document document, View view)
{
  CreateOrChangeDoctype (document, view, L_Strict, FALSE, FALSE, FALSE);
  UpdateEditorMenus (document);
}

/*--------------------------------------------------------------------------
  CreateDoctypeMathML
  Create or change the doctype for a MathML document
  --------------------------------------------------------------------------*/
void CreateDoctypeMathML (Document document, View view)
{
  CreateOrChangeDoctype (document, view, L_MathML, TRUE, FALSE, FALSE);
}

/*--------------------------------------------------------------------------
  CreateDoctypeSVG
  Create or change the doctype for a SVG Basic document
  --------------------------------------------------------------------------*/
void CreateDoctypeSVG (Document document, View view)
{
  ThotBool	  useMathML, useSVG;
 
  HasNatures (document, &useMathML, &useSVG);
  CreateOrChangeDoctype (document, view, L_SVG, TRUE, useMathML, useSVG);
}

/*----------------------------------------------------------------------
  ----------------------------------------------------------------------*/
void PasteBuffer (Document document, View view)
{
#ifdef BOOKMARKS
  if (DocumentTypes[document] == docBookmark)
    BM_PasteHandler (document, view); /* bookmarks make their own cut and paste */
  else
#endif /* BOOKMARKS */
    TtcPaste (document, view);
}

/*----------------------------------------------------------------------
  ----------------------------------------------------------------------*/
void SpellCheck (Document document, View view)
{
  Element             docEl, el, body;
  ElementType         elType;
  int                 firstchar, lastchar;

  docEl = TtaGetMainRoot (document);
  elType = TtaGetElementType (docEl);
  if (strcmp(TtaGetSSchemaName (elType.ElSSchema), "HTML") == 0)
    {
      elType.ElTypeNum = HTML_EL_BODY;
      body = TtaSearchTypedElement (elType, SearchInTree, docEl);
      if (body == NULL)
        return;
      /* get the current selection */
      TtaGiveFirstSelectedElement (document, &el, &firstchar, &lastchar);
      if (el == NULL)
        {
          /* no current selection in the document */
          /* select the first character in the body */
          elType.ElTypeNum = HTML_EL_TEXT_UNIT;
          el = TtaSearchTypedElement (elType, SearchInTree, body);
          if (el != NULL)
            TtaSelectString (document, el, 1, 0);
        }
    }
  TtcSpellCheck (document, view);
}

/*----------------------------------------------------------------------
  CreateBreak
  ----------------------------------------------------------------------*/
void CreateBreak (Document document, View view)
{
  ElementType         elType;
  Element             el, br, parent;
  int                 firstChar, lastChar;

  TtaGiveLastSelectedElement (document, &el, &firstChar, &lastChar);
  if (el == NULL)
    return;
  elType = TtaGetElementType (el);
  if (strcmp(TtaGetSSchemaName (elType.ElSSchema), "HTML") != 0)
    /* not within HTML element */
    return;

  elType.ElTypeNum = HTML_EL_BR;
  TtaCreateElement (elType, document);
  TtaGiveLastSelectedElement (document, &el, &firstChar, &lastChar);
  br = el;
  TtaNextSibling (&el);
  if (el == NULL)
    {
      /* Insert a text element after the BR */
      elType.ElTypeNum = HTML_EL_TEXT_UNIT;
      el = TtaNewElement (document, elType);
      TtaInsertSibling (el, br, FALSE, document);
      /* move the selection */
      TtaSelectString (document, el, 1, 0);
    }
  else
    {
      /* move the selection */
      parent = el;
      while (el != NULL && !TtaIsLeaf (TtaGetElementType (el)))
        {
          parent = el;
          el = TtaGetFirstChild (parent);
        }
      if (el == NULL)
        TtaSelectElement (document, parent);
      else
        {
          elType = TtaGetElementType (el);
          if (elType.ElTypeNum == HTML_EL_TEXT_UNIT)
            TtaSelectString (document, el, 1, 0);
          else
            TtaSelectString (document, el, 0, 0);
        }
    }
}

/*----------------------------------------------------------------------
  InsertWithinHead moves the insertion point into the document Head to
  insert the element type.
  Return TRUE if it succeeds.
  ----------------------------------------------------------------------*/
static Element InsertWithinHead (Document document, View view, int elementT)
{
  ElementType         elType;
  Element             el, firstSel, lastSel, head, parent, new_, title;
  SSchema             docSchema;
  int                 j, firstChar, lastChar;
  ThotBool            before;

  docSchema = TtaGetDocumentSSchema (document);
  if (strcmp(TtaGetSSchemaName (docSchema), "HTML") != 0)
    /* not within an HTML document */
    return (NULL);
  else
    {
      elType.ElSSchema = docSchema;
      elType.ElTypeNum = HTML_EL_HEAD;
      el = TtaGetMainRoot (document);
      head = TtaSearchTypedElement (elType, SearchForward, el);
       
      /* give current position */
      TtaGiveFirstSelectedElement (document, &firstSel, &firstChar, &j);
      TtaGiveLastSelectedElement (document, &lastSel, &j, &lastChar);
      el = firstSel;
      if (firstSel == NULL || firstSel == head ||
          !TtaIsAncestor (firstSel, head))
        {
          /* the current selection is not within the head */
          el = TtaGetLastChild (head);
          /* insert after the last element in the head */
          before = FALSE;
        }
      else
        {
          /* the current selection is within the head */
          parent = TtaGetParent (el);
          /* does the selection precede the title? */
          elType = TtaGetElementType (el);
          if (elType.ElTypeNum == HTML_EL_TITLE)
            /* the title is selected, insert after it */
            before = FALSE;
          else
            {
              elType.ElTypeNum = HTML_EL_TITLE;
              title = TtaSearchTypedElement (elType, SearchForward, el);
              if (title != NULL)
                {
                  /* insert after the title */
                  before = FALSE;
                  el = title;
                }
              else
                {
                  /* insert before the current element */
                  before = TRUE;
                  while (parent != head)
                    {
                      el = parent;
                      /* insert after the parent element */
                      before = FALSE;
                      parent = TtaGetParent (el);
                    }
                }
            }
        }
      /* now insert the new element after el */
      elType.ElTypeNum = elementT;
      if (elementT == HTML_EL_BASE)
        /* the element to be created is BASE */
        {
          /* return if this element already exists */
          if (TtaSearchTypedElement (elType, SearchInTree, head))
            return (NULL);
        }
      new_ = TtaNewTree (document, elType, "");
      TtaInsertSibling (new_, el, before, document);
      if (elementT != HTML_EL_SCRIPT_)
        {
          /* register this element in the editing history */
          TtaOpenUndoSequence (document, firstSel, lastSel, firstChar,
                               lastChar);
          TtaRegisterElementCreate (new_, document);
          TtaCloseUndoSequence (document);
        }
      return (new_);
    }
}

/*----------------------------------------------------------------------
  ----------------------------------------------------------------------*/
void CreateBase (Document document, View view)
{
  Element             el;

  el = InsertWithinHead (document, view, HTML_EL_BASE);
  if (el)
    TtaSelectElement (document, el);
#ifdef _WX
  TtaRedirectFocus();
#endif /* _WX */
}

/*----------------------------------------------------------------------
  ----------------------------------------------------------------------*/
void CreateMeta (Document document, View view)
{
  Element             el;

  el = InsertWithinHead (document, view, HTML_EL_META);
  if (el)
    TtaSelectElement (document, el);
#ifdef _WX
  TtaRedirectFocus();
#endif /* _WX */
}

/*----------------------------------------------------------------------
  ----------------------------------------------------------------------*/
void CreateLinkInHead (Document document, View view)
{
  Element             el;

  el = InsertWithinHead (document, view, HTML_EL_LINK); 
  if (el)
    {
      /* The link element is a new created one */
      UseLastTarget = FALSE;
      IsNewAnchor = TRUE;
      /* Select a new destination */
      SelectDestination (document, el, FALSE, FALSE);
    }
#ifdef _WX
  //TtaRedirectFocus();
#endif /* _WX */
}

/*----------------------------------------------------------------------
  ----------------------------------------------------------------------*/
void CreateStyle (Document document, View view)
{
  Element             el, child;
  ElementType         elType;
  AttributeType       attrType;
  Attribute           attr;

  /* Don't check the Thot abstract tree against the structure schema. */
  TtaSetStructureChecking (FALSE, document);
  el = InsertWithinHead (document, view, HTML_EL_STYLE_);
  TtaSetStructureChecking (TRUE, document);
  if (el)
    {
      /* create an attribute type="text/css" */
      elType = TtaGetElementType (el);
      attrType.AttrSSchema = elType.ElSSchema;
      attrType.AttrTypeNum = HTML_ATTR_Notation;
      attr = TtaNewAttribute (attrType);
      TtaAttachAttribute (el, attr, document);
      TtaSetAttributeText (attr, "text/css", el, document);
      child = TtaGetFirstChild (el);
      if (child)
        TtaSelectElement (document, child);
      else
        TtaSelectElement (document, el);
    }
#ifdef _WX
  TtaRedirectFocus();
#endif /* _WX */
}


/*----------------------------------------------------------------------
  ----------------------------------------------------------------------*/
void CreateComment (Document doc, View view)
{
  Element             el, parent = NULL;
  ElementType         elType;
  char               *s;
  int                 first, last;

  TtaGiveFirstSelectedElement (doc, &el, &first, &last);
  if (el)
    {
      /* get the structure schema of the parent element */
      parent = TtaGetParent (el);
      if (parent)
        el = parent;
      elType = TtaGetElementType (el);
    }
  else
    elType.ElSSchema = TtaGetDocumentSSchema (doc);
  s = TtaGetSSchemaName (elType.ElSSchema);
  if (!strcmp (s, "MathML"))
    elType.ElTypeNum = MathML_EL_XMLcomment;
#ifdef _SVG
  else if (!strcmp (s, "SVG"))
    elType.ElTypeNum = SVG_EL_XMLcomment;
#endif /* _SVG */
  else
    elType.ElTypeNum = HTML_EL_Comment_;
  TtaInsertElement (elType, doc);
#ifdef _WX
  TtaRedirectFocus();
#endif /* _WX */
}

/*----------------------------------------------------------------------
  ----------------------------------------------------------------------*/
void CreateDate (Document doc, View view)
{
  Element             el, parent = NULL, comment, child, text;
  ElementType         elType, elTypeText;
  char               *s;
  char                tm[500];
  int                 first, last;

  if (!TtaGetDocumentAccessMode (doc))
    /* the document is in ReadOnly mode */
    return;
  TtaGiveFirstSelectedElement (doc, &el, &first, &last);
  if (el == NULL)
    /* no selection */
    TtaDisplaySimpleMessage (CONFIRM, AMAYA, AM_NO_INSERT_POINT);
  else if (TtaIsReadOnly (el))
    /* no selection */
    TtaDisplaySimpleMessage (CONFIRM, LIB, TMSG_EL_RO);
  else
    {
      elType = TtaGetElementType (el);
      s = TtaGetSSchemaName (elType.ElSSchema);
      if (!strcmp (s, "HTML"))
        elType.ElTypeNum = HTML_EL_Comment_;
#ifdef _SVG
      else if (!strcmp (s, "SVG"))
        elType.ElTypeNum = SVG_EL_XMLcomment;
#endif /* _SVG */
#ifdef XML_GENERIC
      else if (!strcmp (s, "XML"))
        elType.ElTypeNum = XML_EL_xmlcomment;
#endif /* XML_GENERIC */
      else
        {
          /* look for an HTML parent element */
          parent = TtaGetParent (el);
          el = NULL;
          while (parent)
            {
              elType = TtaGetElementType (parent);
              if (strcmp (TtaGetSSchemaName (elType.ElSSchema), "HTML"))
                {
                  el = parent;
                  parent = NULL;
                  elType.ElTypeNum = HTML_EL_Comment_;
                }
              else
                parent = TtaGetParent (parent);
            }
        }
    }

  if (el)
    {
      TtaOpenUndoSequence (doc, NULL, NULL, 0, 0);
      /* insert the text element */
      elTypeText.ElSSchema = elType.ElSSchema;
      elTypeText.ElTypeNum = HTML_EL_TEXT_UNIT;
      TtaInsertElement (elTypeText, doc);
      TtaGiveFirstSelectedElement (doc, &el, &first, &last);
      TtaGetTime (tm, UTF_8);
      TtaSetTextContent (el, (unsigned char*)tm, UTF_8, doc);
      TtaExtendUndoSequence (doc);

      /* insert the first comment */
      comment = TtaNewTree (doc, elType, "");
      TtaInsertSibling (comment, el, TRUE, doc);
      child = text = comment;
      while (child)
        {
          text = child;
          child = TtaGetFirstChild (text);
        }
      TtaSetTextContent (text, (unsigned char*)"$date=", UTF_8, doc);
      TtaRegisterElementCreate (comment, doc);
      text = TtaNewTree (doc, elTypeText, "");
      TtaInsertSibling (text, comment, TRUE, doc);
      TtaSetTextContent (text, (unsigned char*)" ", UTF_8, doc);
      TtaRegisterElementCreate (text, doc);

      /* insert the last comment */
      comment = TtaNewTree (doc, elType, "");
      TtaInsertSibling (comment, el, FALSE, doc);
      child = text = comment;
      while (child)
        {
          text = child;
          child = TtaGetFirstChild (text);
        }
      TtaSetTextContent (text, (unsigned char*)"$", UTF_8, doc);
      TtaRegisterElementCreate (comment, doc);
      text = TtaNewTree (doc, elTypeText, "");
      TtaInsertSibling (text, comment, FALSE, doc);
      TtaSetTextContent (text, (unsigned char*)" ", UTF_8, doc);
      TtaRegisterElementCreate (text, doc);
      TtaCloseUndoSequence (doc);
      TtaSelectElement (doc, el);
    }
}

/*----------------------------------------------------------------------
  CreateScript
  ----------------------------------------------------------------------*/
void CreateScript (Document doc, View view)
{
  SSchema             docSchema;
  ElementType         elType, headType;
  Element             el, child, parent = NULL;
  char               *s;
  int                 i, j;
  ThotBool            generateCDATA;

  /* test if we have to insert a script in the document head */
  TtaGiveFirstSelectedElement (doc, &el, &i, &j);
  docSchema = TtaGetDocumentSSchema (doc);
  if (el)
    {
      elType = TtaGetElementType (el);
      s = TtaGetSSchemaName (elType.ElSSchema);
      if (strcmp (s, "HTML") || elType.ElTypeNum != HTML_EL_HEAD)
        {
          headType.ElSSchema = elType.ElSSchema;
          headType.ElTypeNum = HTML_EL_HEAD;
          parent = TtaGetTypedAncestor (el, headType);
          if (parent)
            {
              el = parent;
              elType.ElTypeNum = HTML_EL_HEAD;
            }
          else
            {
              /* within a head 
                 get the structure schema of the parent element */
              parent = TtaGetParent (el);
              if (parent)
                el = parent;
              elType = TtaGetElementType (el);
              s = TtaGetSSchemaName (elType.ElSSchema);
            }
        }
    }
  else
    {
      elType.ElSSchema = docSchema;
      elType.ElTypeNum = 0;
      s = NULL;
    }
  
  TtaOpenUndoSequence (doc, NULL, NULL, 0, 0);
  if (s == NULL || strcmp (s, "HTML") || elType.ElTypeNum == HTML_EL_HEAD)
    {
      /* cannot insert at the current position */
      if (!strcmp (TtaGetSSchemaName (docSchema), "HTML"))
        /* insert within the head of this HTML document */
        el = InsertWithinHead (doc, view, HTML_EL_SCRIPT_);
      else
        el = NULL;
    }
  else
    {
      /* create Script in the body if we are within an HTML document
         and within an HTML element */
      elType.ElTypeNum = HTML_EL_SCRIPT_;
      TtaInsertElement (elType, doc);
      TtaGiveFirstSelectedElement (doc, &el, &i, &j);
    }

  if (el)
    {
      TtaGetEnvBoolean ("GENERATE_CDATA", &generateCDATA);
      if (DocumentMeta[doc] && DocumentMeta[doc]->xmlformat &&
          generateCDATA)
        /* insert a cdata within */
        elType.ElTypeNum = HTML_EL_CDATA;
      else
        /* insert a comment within */
        elType.ElTypeNum = HTML_EL_Comment_;
      child = TtaNewTree (doc, elType, "");
      elType = TtaGetElementType (el);
      if (TtaIsLeaf (elType))
        {
          TtaInsertSibling (child, el, TRUE, doc);
          TtaDeleteTree (el, doc);
        }
      else
        TtaInsertFirstChild (&child, el, doc);
      /* register new created elements */
      TtaRegisterElementCreate (el, doc);
      TtaCloseUndoSequence (doc);
      while (child)
        {
          el = child;
          child = TtaGetFirstChild (el);
        }
      if (child)
        TtaSelectElement (doc, child);
      else
        TtaSelectElement (doc, el);
    }
  TtaCloseUndoSequence (doc);
#ifdef _WX
  TtaRedirectFocus();
#endif /* _WX */
}

/*----------------------------------------------------------------------
  HTMLelementAllowed
  ----------------------------------------------------------------------*/
ThotBool HTMLelementAllowed (Document doc)
{
  ElementType         elType;
  Element             el, ancestor, sibling;
  char               *s;
  int                 firstChar, lastChar;

  if (!TtaGetDocumentAccessMode (doc))
    /* the document is in ReadOnly mode */
    return FALSE;

  TtaGiveFirstSelectedElement (doc, &el, &firstChar, &lastChar);
  if (el == NULL)
    {
      /* no selection */
      TtaDisplaySimpleMessage (CONFIRM, AMAYA, AM_NO_INSERT_POINT);
      return FALSE;
    }
  
  elType = TtaGetElementType (el);
  s = TtaGetSSchemaName (elType.ElSSchema);
  if (strcmp (s, "HTML") == 0)
    /* within an HTML element */
    return TRUE;
#ifdef _SVG
  else if (strcmp (s, "SVG") == 0)
    {
      CreateGraphicElement (9);
      return TRUE;
    }
#endif /* _SVG */
  else
    /* not within an HTML element */
    {
      /* if the selection is at the beginning or at the end of an equation
         or a drawing, TtaCreateElement will create the new HTML element right
         before or after the MathML or Graphics object. */
      if (!TtaIsSelectionEmpty())
        return FALSE;
      
      if (firstChar <= 1)
        /* selection starts at the beginning of an element */
        {
          sibling = el;
          ancestor = el;
          TtaPreviousSibling (&sibling);
          while (sibling == NULL && ancestor != NULL)
            {
              ancestor = TtaGetParent (ancestor);
              if (ancestor)
                {
                  elType = TtaGetElementType (ancestor);
                  if (!strcmp (TtaGetSSchemaName (elType.ElSSchema), "HTML"))
                    /* this is an HTML element */
                    return TRUE;
                  sibling = ancestor;
                  TtaPreviousSibling (&sibling);
                }
            }
        }
     
      if ((lastChar == 0 && firstChar == 0) ||
          lastChar >=  TtaGetElementVolume (el))
        /* selection is at the end of an element */
        {
          sibling = el;
          ancestor = el;
          TtaNextSibling (&sibling);
          while (sibling == NULL && ancestor != NULL)
            {
              ancestor = TtaGetParent (ancestor);
              if (ancestor)
                {
                  elType = TtaGetElementType (ancestor);
                  if (!strcmp (TtaGetSSchemaName (elType.ElSSchema), "HTML"))
                    /* this is an HTML element */
                    return TRUE;
                  sibling = ancestor;
                  TtaNextSibling (&sibling);
                }
            }
        }
      return FALSE;
    }
}

/*----------------------------------------------------------------------
  CreateHTMLelement
  ----------------------------------------------------------------------*/
void CreateHTMLelement (int typeNum, Document document)
{
  ElementType         elType;

  if (HTMLelementAllowed (document))
    {
      TtaSetDisplayMode (document, SuspendDisplay);
      elType.ElSSchema = TtaGetSSchema ("HTML", document);
      elType.ElTypeNum = typeNum;
      TtaCreateElement (elType, document);
      TtaSetDisplayMode (document, DisplayImmediately);
    }
}

/*----------------------------------------------------------------------
  CreateParagraph
  ----------------------------------------------------------------------*/
void CreateParagraph (Document document, View view)
{
  CreateHTMLelement (HTML_EL_Paragraph, document);
}

/*----------------------------------------------------------------------
  CreateHeading1
  ----------------------------------------------------------------------*/
void CreateHeading1 (Document document, View view)
{
  CreateHTMLelement (HTML_EL_H1, document);
}

/*----------------------------------------------------------------------
  CreateHeading2
  ----------------------------------------------------------------------*/
void CreateHeading2 (Document document, View view)
{
  CreateHTMLelement (HTML_EL_H2, document);
}

/*----------------------------------------------------------------------
  CreateHeading3
  ----------------------------------------------------------------------*/
void CreateHeading3 (Document document, View view)
{
  CreateHTMLelement (HTML_EL_H3, document);
}

/*----------------------------------------------------------------------
  CreateHeading4
  ----------------------------------------------------------------------*/
void CreateHeading4 (Document document, View view)
{
  CreateHTMLelement (HTML_EL_H4, document);
}

/*----------------------------------------------------------------------
  CreateHeading5
  ----------------------------------------------------------------------*/
void CreateHeading5 (Document document, View view)
{
  CreateHTMLelement (HTML_EL_H5, document);
}

/*----------------------------------------------------------------------
  CreateHeading6
  ----------------------------------------------------------------------*/
void CreateHeading6 (Document document, View view)
{
  CreateHTMLelement (HTML_EL_H6, document);
}

/*----------------------------------------------------------------------
  CreateAreaMap
  ----------------------------------------------------------------------*/
void CreateMap (Document doc, View view)
{
  ElementType    elType;
  Element        el, div, map, p;
  int            i, j;
  ThotBool       oldStructureChecking;

  CreateHTMLelement (HTML_EL_Division, doc);
  TtaExtendUndoSequence (doc);
  TtaGiveFirstSelectedElement (doc, &el, &i, &j);
  oldStructureChecking = TtaGetStructureChecking (doc);
  TtaSetStructureChecking (FALSE, doc);
  elType = TtaGetElementType (el);
  elType.ElTypeNum = HTML_EL_map;
  div = TtaGetParent (el);
  map = TtaNewElement (doc, elType);
  TtaInsertFirstChild (&map, div, doc);
  TtaDeleteTree (el, doc);
  // generate the id and or name attribute
  CreateTargetAnchor (doc, map, FALSE, TRUE);
  // generate a division
  elType.ElTypeNum = HTML_EL_Division;
  div = TtaNewElement (doc, elType);
  TtaInsertFirstChild (&div, map, doc);
  elType.ElTypeNum = HTML_EL_Pseudo_paragraph;
  p =  TtaNewElement (doc, elType);
  TtaInsertFirstChild (&p, div, doc);
  elType.ElTypeNum = HTML_EL_TEXT_UNIT;
  el =  TtaNewElement (doc, elType);
  TtaInsertFirstChild (&el, p, doc);
  TtaRegisterElementCreate (map, doc);
  TtaSelectElement (doc, el);
  TtaSetStructureChecking (oldStructureChecking, doc);
  // it should include a link
  CreateOrChangeLink (doc, view);
}

/*----------------------------------------------------------------------
  CreateList
  ----------------------------------------------------------------------*/
void CreateList (Document document, View view)
{
  CreateHTMLelement (HTML_EL_Unnumbered_List, document);
}

/*----------------------------------------------------------------------
  CreateNumberedList
  ----------------------------------------------------------------------*/
void CreateNumberedList (Document document, View view)
{
  CreateHTMLelement (HTML_EL_Numbered_List, document);
}

/*----------------------------------------------------------------------
  CreateDefinitionList
  ----------------------------------------------------------------------*/
void CreateDefinitionList (Document document, View view)
{
  CreateHTMLelement (HTML_EL_Definition_List, document);
}

/*----------------------------------------------------------------------
  CreateDefinitionTerm
  ----------------------------------------------------------------------*/
void CreateDefinitionTerm (Document document, View view)
{
  CreateHTMLelement (HTML_EL_Term, document);
}

/*----------------------------------------------------------------------
  CreateDefinitionDef
  ----------------------------------------------------------------------*/
void CreateDefinitionDef (Document document, View view)
{
  CreateHTMLelement (HTML_EL_Definition, document);
}

/*----------------------------------------------------------------------
  CreateHorizontalRule
  ----------------------------------------------------------------------*/
void CreateHorizontalRule (Document document, View view)
{
  CreateHTMLelement (HTML_EL_Horizontal_Rule, document);
}

/*----------------------------------------------------------------------
  CreateBlockQuote
  ----------------------------------------------------------------------*/
void CreateBlockQuote (Document document, View view)
{
  CreateHTMLelement (HTML_EL_Block_Quote, document);
}

/*----------------------------------------------------------------------
  CreatePreformatted
  ----------------------------------------------------------------------*/
void CreatePreformatted (Document document, View view)
{
  CreateHTMLelement (HTML_EL_Preformatted, document);
}

/*----------------------------------------------------------------------
  CreateRuby
  Create a ruby element.
  If the current selection is simply a caret, create an empty simple ruby at
  that position.
  If some text/elements are selected, create a simple ruby element at that
  position and move the selected elements within the rb element.
  ----------------------------------------------------------------------*/
void CreateRuby (Document document, View view)
{
  ElementType   elType;
  Element       el, selEl, rbEl, rubyEl, firstEl, lastEl, nextEl, prevEl;
  int           i, j, lg, firstSelectedChar, lastSelectedChar, min, max;
  Language      lang;
  CHAR_T        *buffer;
  ThotBool      error;
  DisplayMode   dispMode;
  ThotBool      oldStructureChecking;

  if (HTMLelementAllowed (document))
    {
      elType.ElSSchema = TtaGetSSchema ("HTML", document);
      elType.ElTypeNum = HTML_EL_complex_ruby;
      /* if we are already within a ruby element, return immediately */
      TtaGiveFirstSelectedElement (document, &firstEl, &firstSelectedChar, &j);
      if (TtaGetTypedAncestor (firstEl, elType))
        return;
      elType.ElTypeNum = HTML_EL_simple_ruby;
      if (TtaGetTypedAncestor (firstEl, elType))
        return;
      /* stop displaying changes that will be made */
      dispMode = TtaGetDisplayMode (document);
      if (dispMode == DisplayImmediately)
        TtaSetDisplayMode (document, DeferredDisplay);
      selEl = NULL;
      rbEl = NULL;
      rubyEl = NULL;
      if (TtaIsSelectionEmpty())
        /* selection is simply a caret */
        {
          /* create a simple_ruby element at the current position */
          TtaCreateElement (elType, document);
          /* get the rb element that has just been created within the ruby */
          TtaGiveFirstSelectedElement (document, &el, &i, &j);
          if (el)
            {
              selEl = el; /* empty leaf within the rb element */
              rbEl = TtaGetParent (el);
              /* get the CHOICE element that follows the rb element and
                 delete it */
              el = rbEl;
              TtaNextSibling (&el);
              if (el)
                TtaDeleteTree (el, document);
              rubyEl = TtaGetParent (rbEl);
            }
        }
      else if (IsCharacterLevelElement (firstEl))
        /* there are some elements/text selected. Make it the content
           of the rb element */
        {
          TtaGiveLastSelectedElement(document, &lastEl, &i, &lastSelectedChar);
          if (TtaGetParent (firstEl) == TtaGetParent (lastEl))
            /* all selected elements are siblings */
            {
              /* check if there are some ruby elements within the selected
                 elements */
              error = FALSE;
              el = firstEl;
              while (el && !error)
                {
                  elType = TtaGetElementType (el);
                  if ((elType.ElTypeNum == HTML_EL_simple_ruby ||
                       elType.ElTypeNum == HTML_EL_complex_ruby) &&
                      !strcmp(TtaGetSSchemaName (elType.ElSSchema), "HTML"))
                    /* it's a ruby element. Error */
                    error = TRUE;
                  else
                    {
                      elType.ElSSchema = TtaGetSSchema ("HTML", document);
                      elType.ElTypeNum = HTML_EL_simple_ruby;
                      if (TtaSearchTypedElement (elType, SearchInTree, el))
                        error = TRUE;
                      else
                        {
                          elType.ElTypeNum = HTML_EL_complex_ruby;
                          if (TtaSearchTypedElement (elType, SearchInTree, el))
                            error = TRUE;
                        }
                    }
                  TtaGiveNextElement (document, &el, lastEl);
                }
              if (!error)
                {
                  TtaUnselect (document);
                  /* split the last element if it's a character string */
                  elType = TtaGetElementType (lastEl);
                  if (elType.ElTypeNum == HTML_EL_TEXT_UNIT)
                    /* it's a text element */
                    {
                      lg = TtaGetElementVolume (lastEl);
                      if (lastSelectedChar <= lg && lastSelectedChar > 1)
                        /* the last selected element is only partly selected.
                           Split it */
                        {
                          /* exclude trailing spaces from the selection */
                          if (lg > 0)
                            {
                              lg++;
                              buffer = (CHAR_T*)TtaGetMemory (lg * sizeof(CHAR_T));
                              TtaGiveBufferContent (lastEl, buffer, lg, &lang);
                              if (lastEl == firstEl)
                                min = firstSelectedChar;
                              else
                                min = 1;
                              while (lastSelectedChar > min &&
                                     buffer[lastSelectedChar - 2] == SPACE)
                                lastSelectedChar--;
                              TtaFreeMemory (buffer);
                            }
                          TtaSplitText (lastEl, lastSelectedChar, document);
                        }
                    }
                  /* process the first selected element */
                  elType = TtaGetElementType (firstEl);
                  if (elType.ElTypeNum == HTML_EL_TEXT_UNIT)
                    /* it's a text element */
                    if (firstSelectedChar > 1)
                      /* that element is only partly selected. Split it */
                      {
                        el = firstEl;
                        lg = TtaGetElementVolume (firstEl);
                        /* exclude leading spaces from the selection */
                        if (lg > 0)
                          {
                            lg++;
                            buffer = (CHAR_T*)TtaGetMemory (lg * sizeof(CHAR_T));
                            TtaGiveBufferContent (firstEl, buffer, lg, &lang);
                            if (lastEl == firstEl)
                              max = lastSelectedChar;
                            else
                              max = lg;
                            while (firstSelectedChar < max &&
                                   buffer[firstSelectedChar - 1] == SPACE)
                              firstSelectedChar++;
                            TtaFreeMemory (buffer);
                          }
                        if (firstSelectedChar <= lg)
                          {
                            TtaSplitText (firstEl, firstSelectedChar,document);
                            TtaNextSibling (&firstEl);
                          }
                        if (lastEl == el)
                          /* we have to change the end of selection because the
                             last selected element was split */
                          lastEl = firstEl;
                      }
                  /* create a ruby element with a rb element and moves all
                     selected elements within the new rb element */
                  TtaOpenUndoSequence (document, firstEl, lastEl, 0, 0);
                  elType.ElTypeNum = HTML_EL_simple_ruby;
                  rubyEl = TtaNewElement (document, elType);
                  TtaInsertSibling (rubyEl, firstEl, TRUE, document);
                  elType.ElTypeNum = HTML_EL_rb;
                  rbEl = TtaNewElement (document, elType);
                  TtaInsertFirstChild (&rbEl, rubyEl, document);
                  TtaRegisterElementCreate (rubyEl, document);
                  el = firstEl;
                  prevEl = NULL;
                  while (el)
                    {
                      if (el == lastEl)
                        nextEl = NULL;
                      else
                        {
                          nextEl = el;
                          TtaGiveNextElement (document, &nextEl, lastEl);
                        }
                      TtaRegisterElementDelete (el, document);
                      TtaRemoveTree (el, document);
                      if (!prevEl)
                        TtaInsertFirstChild  (&el, rbEl, document);
                      else
                        TtaInsertSibling (el, prevEl, FALSE, document);
                      prevEl = el;
                      TtaRegisterElementCreate (el, document);
                      el = nextEl;
                    }
                  TtaCloseUndoSequence (document);
                }
            }
        }
      if (rbEl)
        /* a rb element has been created. create the other elements within
           the new ruby element */
        {
          /* create a first rp element after the rb element */
          oldStructureChecking = TtaGetStructureChecking (document);
          TtaSetStructureChecking (FALSE, document);
          elType.ElTypeNum = HTML_EL_rp;
          el = TtaNewTree (document, elType, "");
          TtaInsertSibling (el, rbEl, FALSE, document);
          prevEl = el;
          el = TtaGetFirstChild (el);
          TtaSetTextContent (el, (unsigned char*)"(", TtaGetDefaultLanguage (), document);
          /* create a rt element after the first rp element */
          elType.ElTypeNum = HTML_EL_rt;
          el = TtaNewTree (document, elType, "");
          TtaInsertSibling (el, prevEl, FALSE, document);
          if (!selEl)
            /* nothing to be selected. Select the first leaf within the
               new rt element */
            selEl = TtaGetFirstChild (el);
          prevEl = el;
          /* create a second rp element after the rt element */
          elType.ElTypeNum = HTML_EL_rp;
          el = TtaNewTree (document, elType, "");
          TtaInsertSibling (el, prevEl, FALSE, document);
          el = TtaGetFirstChild (el);
          TtaSetTextContent (el, (unsigned char*)")", TtaGetDefaultLanguage (), document);
          TtaSetStructureChecking (oldStructureChecking, document);
          /* create a text element after the ruby element, to allow the
             user to add some more text after the ruby */
          el = rubyEl;
          TtaNextSibling (&el);
          if (!el)
            {
              elType.ElTypeNum = HTML_EL_TEXT_UNIT;
              el = TtaNewElement (document, elType);
              TtaInsertSibling (el, rubyEl, FALSE, document);
            }
        }
      /* ask Thot to display changes made in the document */
      TtaSetDisplayMode (document, dispMode);
      /* update the selection */
      if (selEl)
        TtaSelectElement (document, selEl);
    }
}

/*----------------------------------------------------------------------
  CreateAddress
  ----------------------------------------------------------------------*/
void CreateAddress (Document document, View view)
{
  CreateHTMLelement (HTML_EL_Address, document);
}

/*----------------------------------------------------------------------
  DoTableCreation 
  ----------------------------------------------------------------------*/
void DoTableCreation (Document document)
{
  ElementType         elType;
  Element             el, new_, caption, cell, row;
  AttributeType       attrType;
  Attribute           attr;
  int                 firstChar, i;

  /* get the new Table element */
  TtaSetDisplayMode (document, SuspendDisplay);
  TtaLockTableFormatting ();
  elType.ElSSchema = TtaGetSSchema ("HTML", document);
  elType.ElTypeNum = HTML_EL_Table_;
  TtaCreateElement (elType, document);
  TtaGiveFirstSelectedElement (document, &el, &firstChar, &i);
  elType.ElTypeNum = HTML_EL_CAPTION;
  caption = TtaNewTree (document, elType, "");
  TtaInsertFirstChild (&caption, el, document);
  //TtaSelectElement (document, TtaGetFirstLeaf (caption));
  /* close the undo sequence if it's still open */
  TtaCloseUndoSequence (document);
  if (el != NULL)
    {
      attrType.AttrSSchema = elType.ElSSchema;
      attrType.AttrTypeNum = HTML_ATTR_Border;
      attr = TtaGetAttribute (el, attrType);
      if (TtaGetDocumentProfile(document) == L_Basic)
        {
          /* remove the Border attribute */
          if (attr != NULL)
            TtaRemoveAttribute (el, attr, document);
#ifdef IV
          char stylebuff[50];
          ThotBool loadcss;
          /* generate a border style */
          attrType.AttrTypeNum = HTML_ATTR_Style_;
          attr = TtaNewAttribute (attrType);
          sprintf (stylebuff, "border: solid %dpx", TBorder);
          TtaSetAttributeText (attr, stylebuff, el, document);	       
          //TtaAttachAttribute (el, attr, document);
          /* check if we have to load CSS */
          TtaGetEnvBoolean ("LOAD_CSS", &loadcss);
          if (loadcss)
            ParseHTMLSpecificStyle (el, stylebuff, document, 200, FALSE);
#endif /* IV */
        }
      else if (attr && TBorder == 0)
        /* the table has a Border attribute but the user don't want
           any border. Remove the attribute */
        TtaRemoveAttribute (el, attr, document);
      else
        {
          if (attr == NULL)
            /* the Table has no Border attribute, create one */
            {
              attr = TtaNewAttribute (attrType);
              TtaAttachAttribute (el, attr, document);
            }
          TtaSetAttributeValue (attr, TBorder, el, document);
        }
      
      elType.ElTypeNum = HTML_EL_Table_cell;
      cell = TtaSearchTypedElement (elType, SearchInTree, el);
      elType.ElTypeNum = HTML_EL_Data_cell;
      if (cell == NULL)
        /* look for a data cell */
        cell = TtaSearchTypedElement (elType, SearchInTree, el);
      else
        /* replace the cell element by a data cell */
        TtaChangeTypeOfElement (cell, document, HTML_EL_Data_cell);
      TtaSelectElement (document, TtaGetFirstLeaf (cell));

      while (NumberCols > 1)
        {
          new_ = TtaNewTree (document, elType, "");
          TtaInsertSibling (new_, cell, FALSE, document);
          NumberCols--;
        }
      
      if (NumberRows > 1)
        {
          elType.ElTypeNum = HTML_EL_Table_row;
          row = TtaSearchTypedElement (elType, SearchInTree, el);
          while (NumberRows > 1)
            {
              new_ = TtaNewElement (document, elType);
              TtaInsertSibling (new_, row, FALSE, document);
              NumberRows--;
            }
        } 
      CheckAllRows (el, document, FALSE, FALSE);
    }
  TtaUnlockTableFormatting ();
  TtaSetDisplayMode (document, DisplayImmediately);
  UpdateContextSensitiveMenus (document);
}

/*----------------------------------------------------------------------
  CreateTable
  ----------------------------------------------------------------------*/
void CreateTable (Document document, View view)
{
  ElementType         elType;

  if (!HTMLelementAllowed (document))
    return;
  elType.ElSSchema = TtaGetSSchema ("HTML", document);
  if (elType.ElSSchema)
    {
      /* check the selection */
      if (TtaIsSelectionEmpty ())
        /* selection empty.  Display the Table dialogue box */
        {
          NumberRows = 2;
          NumberCols = 2;
          TBorder = 1;
#ifdef _WINGUI
          CreateTableDlgWindow (NumberCols, NumberRows, TBorder);
#endif  /* _WINGUI */
#ifdef _WX
          ThotBool created;
          created = CreateCreateTableDlgWX (BaseDialog + TableForm,
                                            TtaGetViewFrame (document, view),
                                            NumberCols, NumberRows, TBorder);
          if (created)
            {
              TtaShowDialogue (BaseDialog + TableForm, FALSE);
              /* wait for an answer */
              TtaWaitShowDialogue ();
            }
#endif /* _WX */
#ifdef _GTK
          TtaNewForm (BaseDialog + TableForm, TtaGetViewFrame (document, 1),
                      TtaGetMessage (LIB, TMSG_BUTTON_TABLE), TRUE, 1, 'L', D_CANCEL);
          TtaNewNumberForm (BaseDialog + TableCols, BaseDialog + TableForm,
                            TtaGetMessage (AMAYA, AM_COLS), 1, 50, TRUE);
          TtaNewNumberForm (BaseDialog + TableRows, BaseDialog + TableForm,
                            TtaGetMessage (AMAYA, AM_ROWS), 1, 200, TRUE);
          TtaNewNumberForm (BaseDialog + TableBorder, BaseDialog + TableForm,
                            TtaGetMessage (AMAYA, AM_BORDER), 0, 50, TRUE);
          TtaSetNumberForm (BaseDialog + TableCols, NumberCols);
          TtaSetNumberForm (BaseDialog + TableRows, NumberRows);
          TtaSetNumberForm (BaseDialog + TableBorder, TBorder);
          TtaSetDialoguePosition ();
          TtaShowDialogue (BaseDialog + TableForm, FALSE);
          /* wait for an answer */
          TtaWaitShowDialogue ();
#endif /* _GTK */

          if (!UserAnswer)
            return;
        }
      else
        TBorder = 1;
      /* create the table or 
         try to transform the current selection if the selection is not empty */
      DoTableCreation (document);
    }
}

/*----------------------------------------------------------------------
  CreateCaption
  If the selection is a position anywhere within a table, create an empty
  caption element in this table and set the selection in this new caption.
  If the caption element already exists, just select it.
  ----------------------------------------------------------------------*/
void CreateCaption (Document document, View view)
{
  ElementType         elType;
  Element             el, caption;
  int                 i, j;

  TtaGiveFirstSelectedElement (document, &el, &i, &j);
  if (el)
    /* there is a current selection */
    {
      elType = TtaGetElementType (el);
      if (!strcmp(TtaGetSSchemaName (elType.ElSSchema), "HTML"))
        /* the selected element is an HTML element */
        {
          caption = NULL;
          /* is the selection within a table */
          if (elType.ElTypeNum != HTML_EL_Table_ && TtaIsSelectionEmpty ())
            {
              /* get the enclosing table element */
              elType.ElTypeNum = HTML_EL_Table_;
              el = TtaGetTypedAncestor (el, elType);
              if (el == NULL)
                /* we are not in a table. Stop */
                return;
              else
                {
                  /* is there already a caption element in this table? */
                  elType.ElTypeNum = HTML_EL_CAPTION;
                  caption =  TtaSearchTypedElement (elType, SearchInTree, el);
                  if (caption)
                    /* there is a caption. Put the selection in it */
                    TtaSelectElement (document, TtaGetFirstLeaf (caption));
                  else
                    /* no caption yet. Select the first child of the table
                       tp create a caption element there */
                    {
                      el = TtaGetFirstChild (el);
                      TtaSelectElement (document, el);
                    }
                }
            }
          if (!caption)
            /* no caption yet. Create one */
            {
              elType.ElTypeNum = HTML_EL_CAPTION;
              TtaCreateElement (elType, document);
            }
        }
    }
  else
    TtaDisplaySimpleMessage (CONFIRM, AMAYA, AM_NO_INSERT_POINT);
}

/*----------------------------------------------------------------------
  CreateColgroup
  ----------------------------------------------------------------------*/
void CreateColgroup (Document document, View view)
{
  ElementType         elType;
  Element             el, child;
  int                 i, j;

  TtaGiveFirstSelectedElement (document, &el, &i, &j);
  if (el != NULL)
    {
      elType = TtaGetElementType (el);
      if (!strcmp(TtaGetSSchemaName (elType.ElSSchema), "HTML"))
        {
          /* it's an HTML element */
          if (elType.ElTypeNum == HTML_EL_COLGROUP ||
              elType.ElTypeNum == HTML_EL_COL)
            {
              /* insert after the curent element */
              child = el;
              /* create the Colgroup element */
              elType.ElTypeNum = HTML_EL_COLGROUP;
              el = TtaNewTree (document, elType, "");
              TtaInsertSibling (el, child, FALSE, document);
              /* update the selection */
              child = TtaGetFirstChild (el);
              if (child == NULL)
                TtaSelectElement (document, el);
              else
                TtaSelectElement (document, child);
            }
          else
            {
              if (elType.ElTypeNum != HTML_EL_Table_)
                {
                  /* move the selection after the CAPTION */
                  elType.ElTypeNum = HTML_EL_Table_;
                  el = TtaGetTypedAncestor (el, elType);
                }
              if (el != NULL)
                {
                  /* skip the CAPTION */
                  child = TtaGetFirstChild (el);
                  elType = TtaGetElementType (child);
                  if (elType.ElTypeNum == HTML_EL_CAPTION)
                    {
                      TtaNextSibling (&child);
                      elType = TtaGetElementType (child);
                    }
                  if (elType.ElTypeNum == HTML_EL_Cols)
                    /* select the first COL or COLGROUP */
                    child = TtaGetFirstChild (child);
                  /* move the selection if there is no extension */
                  if (TtaIsSelectionEmpty ())
                    TtaSelectElement (document, child);
                  /* create the COLGROUP element */
                  elType.ElTypeNum = HTML_EL_COLGROUP;
                  TtaCreateElement (elType, document);
                  TtaGiveFirstSelectedElement (document, &el, &i, &j);
                  /* create a COL element within */
                  elType.ElTypeNum = HTML_EL_COL;
                  child = TtaNewTree (document, elType, "");
                  TtaInsertFirstChild (&child, el, document);
                  /* update the selection */
                  TtaSelectElement (document, child);
                }
            }
        }
    }
  else
    TtaDisplaySimpleMessage (CONFIRM, AMAYA, AM_NO_INSERT_POINT);
}

/*----------------------------------------------------------------------
  CreateCol
  ----------------------------------------------------------------------*/
void CreateCol (Document document, View view)
{
  ElementType         elType;
  Element             el, child;
  int                 i, j;

  TtaGiveFirstSelectedElement (document, &el, &i, &j);
  if (el != NULL)
    {
      elType = TtaGetElementType (el);
      if (!strcmp(TtaGetSSchemaName (elType.ElSSchema), "HTML"))
        {
          /* it's an HTML element */
          if (elType.ElTypeNum == HTML_EL_COLGROUP)
            {
              /* insert within the curent element */
              /* create the Colgroup element */
              elType.ElTypeNum = HTML_EL_COL;
              child = TtaNewTree (document, elType, "");
              TtaInsertFirstChild (&child, el, document);
              /* update the selection */
              TtaSelectElement (document, child);
            }
          if (elType.ElTypeNum == HTML_EL_COL)
            {
              /* insert after the curent element */
              child = el;
              /* create the COL element */
              elType.ElTypeNum = HTML_EL_COL;
              el = TtaNewTree (document, elType, "");
              TtaInsertSibling (el, child, FALSE, document);
              /* update the selection */
              TtaSelectElement (document, el);
            }
          else
            {
              if (elType.ElTypeNum != HTML_EL_Table_)
                {
                  /* move the selection after the CAPTION */
                  elType.ElTypeNum = HTML_EL_Table_;
                  el = TtaGetTypedAncestor (el, elType);
                }
              if (el != NULL)
                {
                  /* skip the CAPTION */
                  child = TtaGetFirstChild (el);
                  elType = TtaGetElementType (child);
                  if (elType.ElTypeNum == HTML_EL_CAPTION)
                    {
                      TtaNextSibling (&child);
                      elType = TtaGetElementType (child);
                    }
                  if (elType.ElTypeNum == HTML_EL_Cols)
                    {
                      /* select the first COL */
                      child = TtaGetFirstChild (child);
                      elType = TtaGetElementType (child);
                      if (elType.ElTypeNum == HTML_EL_COLGROUP)
                        child = TtaGetFirstChild (child);
                    }
                  /* move the selection if there is no extension */
                  if (TtaIsSelectionEmpty ())
                    TtaSelectElement (document, child);
                  /* create the COL element */
                  elType.ElTypeNum = HTML_EL_COL;
                  TtaCreateElement (elType, document);
                }
            }
        }
    }
  else
    TtaDisplaySimpleMessage (CONFIRM, AMAYA, AM_NO_INSERT_POINT);
}

/*----------------------------------------------------------------------
  FirstDescendantOfTypes
  Return the first descendant of element el that is of type (ss, type1)
  or (ss, type2)
  ----------------------------------------------------------------------*/
static Element FirstDescendantOfTypes (Element el, SSchema ss, int type1,
                                       int type2)
{
  Element             desc, result;
  ElementType         elType;

  result = NULL;
  desc = TtaGetFirstChild (el);
  while (!result && desc)
    {
      elType = TtaGetElementType (desc);
      if (elType.ElSSchema == ss &&
          (elType.ElTypeNum == type1 || elType.ElTypeNum == type2))
        result = desc;
      else
        {
          result = FirstDescendantOfTypes (desc, ss, type1, type2);
          while (!result && desc)
            {
              TtaNextSibling (&desc);
              result = FirstDescendantOfTypes (desc, ss, type1, type2);
            }
        }
    }
  return result;
}

/*----------------------------------------------------------------------
  LastDescendantOfTypes
  Return the last descendant of element el that is of type (ss, type1)
  or (ss, type2)
  ----------------------------------------------------------------------*/
static Element LastDescendantOfTypes (Element el, SSchema ss, int type1,
                                       int type2)
{
  Element             desc, result;
  ElementType         elType;

  result = NULL;
  desc = TtaGetLastChild (el);
  while (!result && desc)
    {
      elType = TtaGetElementType (desc);
      if (elType.ElSSchema == ss &&
          (elType.ElTypeNum == type1 || elType.ElTypeNum == type2))
        result = desc;
      else
        {
          result = LastDescendantOfTypes (desc, ss, type1, type2);
          while (!result && desc)
            {
              TtaPreviousSibling (&desc);
              result = LastDescendantOfTypes (desc, ss, type1, type2);
            }
        }
    }
  return result;
}

/*----------------------------------------------------------------------
  ChangeOneCell
  if element el is a cell of type other, change it to typeCell
  ----------------------------------------------------------------------*/
static void ChangeOneCell (Document doc, Element el, SSchema HTMLSSchema,
                           int other, int typeCell, ThotBool *open)
{
  ElementType         elType;

  elType = TtaGetElementType (el);
  if (elType.ElSSchema == HTMLSSchema && elType.ElTypeNum == other)
    {
      /* change the type of this cell */
      TtaChangeTypeOfElement (el, doc, typeCell);
      /* open the undo sequence if it is not already open */
      if (!*open)
        {
          TtaOpenUndoSequence (doc, NULL, NULL, 0, 0);
          *open = TRUE;
        }
      /* register the change in the undo sequence */
      TtaRegisterElementTypeChange (el, other, doc);
    }
}

/*----------------------------------------------------------------------
  ChangeCell
  transform all cells in the current selection into typeCell (which is
  either th or td)
  ----------------------------------------------------------------------*/
static void ChangeCell (Document doc, View view, int typeCell)
{
  Element             el, last, firstSel, lastSel, ancestor, cell, row, body;
  ElementType         elType;
  SSchema	            HTMLSSchema;
  int                 firstchar, lastchar, other;
  ThotBool            open = FALSE;

  if (typeCell == HTML_EL_Heading_cell)
    other = HTML_EL_Data_cell;
  else
    other = HTML_EL_Heading_cell;

  if (!TtaGetDocumentAccessMode (doc))
    /* the document is in ReadOnly mode */
    return;
  /* get the first selected element */
  TtaGiveFirstSelectedElement (doc, &firstSel, &firstchar, &lastchar);
  if (firstSel != NULL)
    {
      if (TtaIsReadOnly (firstSel))
        /* the selected element is read-only */
        return;

      TtaGiveLastSelectedElement (doc, &lastSel, &firstchar, &lastchar);
      HTMLSSchema = TtaGetSSchema ("HTML", doc);
      el = firstSel;
      elType = TtaGetElementType (el);

      if (elType.ElSSchema != HTMLSSchema || 
          (elType.ElTypeNum != typeCell && elType.ElTypeNum != other))
        /* the first selected element is not a table cell */
        {
          /* check if there is a cell among its ancestors */
          elType.ElSSchema = HTMLSSchema;
          elType.ElTypeNum = other;
          ancestor = TtaGetTypedAncestor (el, elType);
          if (!ancestor)
            {
              elType.ElTypeNum = typeCell;
              ancestor = TtaGetTypedAncestor (el, elType);
            }
          if (ancestor)
            /* a cell ancestor was found. Start from that element */
            el = ancestor;
          else
            /* no cell ancestor */
            {
              elType = TtaGetElementType (el);
              if (elType.ElSSchema == HTMLSSchema &&
                  (elType.ElTypeNum == HTML_EL_Table_ ||
                   elType.ElTypeNum == HTML_EL_thead ||
                   elType.ElTypeNum == HTML_EL_tbody ||
                   elType.ElTypeNum == HTML_EL_tfoot))
                /* we are in an ascendant of a cell. Get the first descendant
                   cell */
                el = FirstDescendantOfTypes (el, HTMLSSchema, typeCell, other);
            } 
        }
      last = lastSel;
      elType = TtaGetElementType (last);
      if (elType.ElSSchema != HTMLSSchema || 
          (elType.ElTypeNum != typeCell && elType.ElTypeNum != other))
        /* the last selected element is not a table cell */
        {
          /* check if there is a cell among its ancestors */
          elType.ElSSchema = HTMLSSchema;
          elType.ElTypeNum = other;
          ancestor = TtaGetTypedAncestor (last, elType);
          if (!ancestor)
            {
              elType.ElTypeNum = typeCell;
              ancestor = TtaGetTypedAncestor (last, elType);
            }
          if (ancestor)
            /* a cell ancestor was found. Start from that element */
            last = ancestor;
          else
            /* no cell ancestor */
            {
              elType = TtaGetElementType (last);
              if (elType.ElSSchema == HTMLSSchema &&
                  (elType.ElTypeNum == HTML_EL_Table_ ||
                   elType.ElTypeNum == HTML_EL_thead ||
                   elType.ElTypeNum == HTML_EL_tbody ||
                   elType.ElTypeNum == HTML_EL_tfoot))
                /* we are in an ascendant of a cell. Get the last descendant
                   cell */
                last = LastDescendantOfTypes (last, HTMLSSchema, typeCell,
                                              other);
            } 
        }

      while (el)
        {
          elType = TtaGetElementType (el);
          if (elType.ElSSchema == HTMLSSchema && elType.ElTypeNum == other)
            /* it's a cell, change its type */
            ChangeOneCell (doc, el, HTMLSSchema, other, typeCell, &open);
          else if (elType.ElSSchema == HTMLSSchema && 
                   elType.ElTypeNum == HTML_EL_Table_row)
            /* it's a row, change the type of all included cells */
            {
              cell = TtaGetFirstChild (el);
              while (cell)
                {
                  ChangeOneCell (doc, cell, HTMLSSchema, other, typeCell,
                                 &open);
                  TtaNextSibling (&cell);
                }
            }
          else if (elType.ElSSchema == HTMLSSchema && 
                   (elType.ElTypeNum == HTML_EL_thead ||
                    elType.ElTypeNum == HTML_EL_tbody ||
                    elType.ElTypeNum == HTML_EL_tfoot))
            /* it's a thead, tbody or tfoot, change the type of all included
               cells */
            {
              row = TtaGetFirstChild (el);
              while (row)
                {
                  cell = TtaGetFirstChild (row);
                  while (cell)
                    {
                      ChangeOneCell (doc, cell, HTMLSSchema, other, typeCell,
                                     &open);
                      TtaNextSibling (&cell);
                    }
                  TtaNextSibling (&row);
                }
            }
          else if (elType.ElSSchema == HTMLSSchema && 
                   elType.ElTypeNum == HTML_EL_Table_body)
            /* it's a Table_body, change the type of all included cells */
            {
              body = TtaGetFirstChild (el);
              while (body)
                {
                  row = TtaGetFirstChild (body);
                  while (row)
                    {
                      cell = TtaGetFirstChild (row);
                      while (cell)
                        {
                          ChangeOneCell (doc, cell, HTMLSSchema, other, typeCell,
                                         &open);
                          TtaNextSibling (&cell);
                        }
                      TtaNextSibling (&row);
                    }
                  TtaNextSibling (&body);
                }
            }

          if (el == last)
            el = NULL;
          else
            TtaGiveNextElement (doc, &el, last);
        }
      if (open)
        TtaCloseUndoSequence (doc);
    }
  else
    TtaDisplaySimpleMessage (CONFIRM, AMAYA, AM_NO_INSERT_POINT);
}

/*----------------------------------------------------------------------
  ChangeToDataCell
  ----------------------------------------------------------------------*/
void ChangeToDataCell (Document doc, View view)
{
  ChangeCell (doc, view, HTML_EL_Data_cell);
}

/*----------------------------------------------------------------------
  ChangeToHeadingCell
  ----------------------------------------------------------------------*/
void ChangeToHeadingCell (Document doc, View view)
{
  ChangeCell (doc, view, HTML_EL_Heading_cell);
}

/*----------------------------------------------------------------------
  GetEnclosingCell
  Return the table cell element that contains the beginning of the
  current selection in document doc.
  ----------------------------------------------------------------------*/
static Element GetEnclosingCell (Document doc)
{
  Element             el, firstSel, lastSel;
  ElementType         elType;
  char               *s;
  int                 firstchar, lastchar, i;

  el = NULL;
  /* get the first selected element */
  TtaGiveFirstSelectedElement (doc, &firstSel, &firstchar, &i);
  if (firstSel)
    {
      el = firstSel;
      elType = TtaGetElementType (el);
      s = TtaGetSSchemaName (elType.ElSSchema);
      while (el &&
             (strcmp (s, "MathML") ||
              elType.ElTypeNum != MathML_EL_MTD) &&
             (strcmp (s, "HTML") ||
              (elType.ElTypeNum != HTML_EL_Data_cell &&
               elType.ElTypeNum != HTML_EL_Heading_cell)))
        {
          el = TtaGetParent (el);
          if (el)
            {
              elType = TtaGetElementType (el);
              s = TtaGetSSchemaName (elType.ElSSchema);
            }
        }
      if (el)
        {
          TtaGiveLastSelectedElement (doc, &lastSel, &i, &lastchar);
          TtaOpenUndoSequence (doc, firstSel, lastSel, firstchar, lastchar);
        }
    }
  return el;
}

/*----------------------------------------------------------------------
  CellVertExtend
  Merge the cell that contains the selection with the next cell in the
  same column.
  ----------------------------------------------------------------------*/
void CellVertExtend (Document doc, View view)
{
  Element       cell, nextCell, colhead, row;
  ElementType   elType;
  Attribute     attr;
  AttributeType attrType;
  int           span, nextSpan, newSpan, i;
  ThotBool      inMath;

  cell = GetEnclosingCell (doc);
  if (cell)
    {
      elType = TtaGetElementType (cell);
      inMath = !TtaSameSSchemas (elType.ElSSchema, 
                                 TtaGetSSchema ("HTML", doc));
      /* get the column of the cell */
      attrType.AttrSSchema = elType.ElSSchema;
      if (inMath)
        attrType.AttrTypeNum = MathML_ATTR_MRef_column;
      else
        attrType.AttrTypeNum = HTML_ATTR_Ref_column;
      attr = TtaGetAttribute (cell, attrType);
      nextCell = NULL;
      if (attr)
        /* the cell has an attribute Ref_column */
        {
          TtaGiveReferenceAttributeValue (attr, &colhead);
          if (colhead)
            {
              /* get the rowspan of the cell */
              if (inMath)
                attrType.AttrTypeNum = MathML_ATTR_rowspan_;
              else
                attrType.AttrTypeNum = HTML_ATTR_rowspan_;
              attr = TtaGetAttribute (cell, attrType);
              if (!attr)
                span = 1;
              else
                {
                  span = TtaGetAttributeValue (attr);
                  if (span < 0)
                    span = 1;
                }
              /* if spanning is 0 (infinite), stop */
              if (span != 0)
                {
                  /* get the next row after the cell */
                  row = TtaGetParent (cell);
                  for (i = 1; i <= span && row; i++)
                    row = GetSiblingRow (row, FALSE, inMath);
                  if (row)
                    /* check if there is a cell in that row, in the same
                       column. Another cell could span horizontally and
                       make the merger impossible */
                    nextCell = GetCellFromColumnHead (row, colhead, inMath);
                }
            }
        }
      
      if (nextCell)
        /* we can extend the cell */
        {
          if (inMath)
            attrType.AttrTypeNum = MathML_ATTR_rowspan_;
          else
            attrType.AttrTypeNum = HTML_ATTR_rowspan_;

          attr = TtaGetAttribute (nextCell, attrType);
          if (attr)
            {
              nextSpan = TtaGetAttributeValue (attr);
              if (nextSpan < 0)
                nextSpan = 1;
            }
          else
            nextSpan = 1;

          attr = TtaGetAttribute (cell, attrType);
          if (attr)
            {
              span = TtaGetAttributeValue (attr);
              if (span < 1)
                span = 1;
            }
          else
            span = 1;
          if (nextSpan == 0)
            /* "infinite" spanning */
            newSpan = 0;
          else
            newSpan = span + nextSpan;
          /* merge the following cell(s) with the current cell */
          ChangeRowspan (cell, span, &newSpan, doc);
          /* set and register the new value of attribute rowspan */
          if (!attr)
            {
              if (newSpan != 1)
                {
                  attr = TtaNewAttribute (attrType);
                  TtaAttachAttribute (cell, attr, doc);
                  TtaSetAttributeValue (attr, newSpan, cell, doc);
                  TtaRegisterAttributeCreate (attr, cell, doc);
                }
            }
          else
            {
              if (newSpan == 1)
                {
                  TtaRegisterAttributeDelete (attr, cell, doc);
                  TtaRemoveAttribute (cell, attr, doc);
                }
              else
                {
                  TtaRegisterAttributeReplace (attr, cell, doc);
                  TtaSetAttributeValue (attr, newSpan, cell, doc);
                }
            }
          SetRowExt (cell, newSpan, doc, inMath);
          TtaCloseUndoSequence (doc);
          TtaSetDocumentModified (doc);
        }
    }
}

/*----------------------------------------------------------------------
  CellHorizExtend
  Merge the cell that contains the selection with the next cell in the
  same row.
  ----------------------------------------------------------------------*/
void CellHorizExtend (Document doc, View view)
{
  Element       cell, row, nextCell, colhead;
  ElementType   elType;
  Attribute     attr, colspanAttr;
  AttributeType attrType, colspanType;
  int           span, nextSpan, newSpan, i;
  ThotBool      inMath;

  cell = GetEnclosingCell (doc);
  if (cell)
    {
      elType = TtaGetElementType (cell);
      inMath = !TtaSameSSchemas (elType.ElSSchema,
                                 TtaGetSSchema ("HTML", doc));
      /* get the column of the cell */
      attrType.AttrSSchema = elType.ElSSchema;
      colspanType.AttrSSchema = elType.ElSSchema;
      if (inMath)
        {
          colspanType.AttrTypeNum = MathML_ATTR_columnspan;
          attrType.AttrTypeNum = MathML_ATTR_MRef_column;
        }
      else
        {
          colspanType.AttrTypeNum = HTML_ATTR_colspan_;
          attrType.AttrTypeNum = HTML_ATTR_Ref_column;
        }
      /* get the colspan of the cell */
      colspanAttr = TtaGetAttribute (cell, colspanType);
      if (!colspanAttr)
        span = 1;
      else
        {
          span = TtaGetAttributeValue (colspanAttr);
          if (span < 0)
            span = 1;
        }
      /* get the next cell */
      attr = TtaGetAttribute (cell, attrType);
      nextCell = NULL;
      if (attr)
        /* the cell has an attribute Ref_column */
        {
          TtaGiveReferenceAttributeValue (attr, &colhead);
          if (colhead)
            {
              /* if spanning is 0 (infinite), stop */
              if (span != 0)
                {
                  /* get the next column after the cell */
                  for (i = 1; i <= span && colhead; i++)
                    TtaNextSibling (&colhead);
                  if (colhead)
                    /* check if there is a cell in that column, in the same
                       row. Another cell could span horizontally and make the
                       merger impossible */
                    {
                      row = TtaGetParent (cell);
                      nextCell = GetCellFromColumnHead (row, colhead, inMath);
                    }
                }
            }
        }

      if (nextCell)
        /* we can extend the cell */
        {
          attr = TtaGetAttribute (nextCell, colspanType);
          if (attr)
            {
              nextSpan = TtaGetAttributeValue (attr);
              if (nextSpan < 0)
                nextSpan = 1;
            }
          else
            nextSpan = 1;

          if (nextSpan == 0)
            /* "infinite" spanning */
            newSpan = 0;
          else
            newSpan = span + nextSpan;
          /* merge the following cell(s) with the current cell */
          ChangeColspan (cell, span, &newSpan, doc);
          SetColExt (cell, newSpan, doc, inMath, FALSE);
          /* we set and register the new value of attribute colspan after
             cells have actually merged. That way, when undoing the command,
             merged cells will be recreated and linked to their column with
             the right (old) value of the attribute */
          if (!colspanAttr)
            {
              if (newSpan != 1)
                {
                  colspanAttr = TtaNewAttribute (colspanType);
                  TtaAttachAttribute (cell, colspanAttr, doc);
                  TtaSetAttributeValue (colspanAttr, newSpan, cell, doc);
                  TtaRegisterAttributeCreate (colspanAttr, cell, doc);
                }
            }
          else
            {
              if (newSpan == 1)
                {
                  TtaRegisterAttributeDelete (colspanAttr, cell, doc);
                  TtaRemoveAttribute (cell, colspanAttr, doc);
                }
              else
                {
                  TtaRegisterAttributeReplace (colspanAttr, cell, doc);
                  TtaSetAttributeValue (colspanAttr, newSpan, cell, doc);
                }
            }
          TtaCloseUndoSequence (doc);
          TtaSetDocumentModified (doc);
        }
    }
}

/*----------------------------------------------------------------------
  CellVertShrink
  ----------------------------------------------------------------------*/
void CellVertShrink (Document doc, View view)
{
  Element       cell;
  ElementType   elType;
  Attribute     attr;
  AttributeType attrType;
  int           span, newSpan;
  ThotBool      inMath;

  cell = GetEnclosingCell (doc);
  if (cell)
    {
      elType = TtaGetElementType (cell);
      inMath = !TtaSameSSchemas (elType.ElSSchema,
                                 TtaGetSSchema ("HTML", doc));
      attrType.AttrSSchema = elType.ElSSchema;
      if (inMath)
        attrType.AttrTypeNum = MathML_ATTR_rowspan_;
      else
        attrType.AttrTypeNum = HTML_ATTR_rowspan_;
      attr = TtaGetAttribute (cell, attrType);
      if (attr)
        {
          span = TtaGetAttributeValue (attr);
          if (span == 0)
            span = GetActualRowspan (cell, inMath);
          if (span >= 2)
            {
              newSpan = span - 1;
              if (newSpan == 1)
                {
                  TtaRegisterAttributeDelete (attr, cell, doc);
                  TtaRemoveAttribute (cell, attr, doc);
                }
              else
                {
                  TtaRegisterAttributeReplace (attr, cell, doc);
                  TtaSetAttributeValue (attr, newSpan, cell, doc);
                }
              ChangeRowspan (cell, span, &newSpan, doc);
              SetRowExt (cell, newSpan, doc, inMath);
              TtaCloseUndoSequence (doc);
              TtaSetDocumentModified (doc);
            }
        }
    }
}

/*----------------------------------------------------------------------
  CellHorizShrink
  ----------------------------------------------------------------------*/
void CellHorizShrink (Document doc, View view)
{
  Element       cell;
  ElementType   elType;
  Attribute     attr;
  AttributeType attrType;
  int           span, newSpan;
  ThotBool      inMath;

  cell = GetEnclosingCell (doc);
  if (cell)
    {
      elType = TtaGetElementType (cell);
      inMath = !TtaSameSSchemas (elType.ElSSchema,
                                 TtaGetSSchema ("HTML", doc));
      attrType.AttrSSchema = elType.ElSSchema;
      if (inMath)
        attrType.AttrTypeNum = MathML_ATTR_columnspan;
      else
        attrType.AttrTypeNum = HTML_ATTR_colspan_;
      attr = TtaGetAttribute (cell, attrType);
      if (attr)
        {
          span = TtaGetAttributeValue (attr);
          if (span == 0)
            span = GetActualColspan (cell, inMath);
          if (span >= 2)
            {
              newSpan = span - 1;
              if (newSpan == 1)
                {
                  TtaRegisterAttributeDelete (attr, cell, doc);
                  TtaRemoveAttribute (cell, attr, doc);
                }
              else
                {
                  TtaRegisterAttributeReplace (attr, cell, doc);
                  TtaSetAttributeValue (attr, newSpan, cell, doc);
                }
              ChangeColspan (cell, span, &newSpan, doc);
              SetColExt (cell, newSpan, doc, inMath, FALSE);
              TtaCloseUndoSequence (doc);
              TtaSetDocumentModified (doc);
            }
        }
    }
}

/*----------------------------------------------------------------------
  GetEnclosingRow
  Return the table row element that contains the beginning of the
  current selection in document doc.
  ----------------------------------------------------------------------*/
static Element GetEnclosingRow (Document doc)
{
  Element             el;
  ElementType         elType;
  char               *s;
  int                 firstchar, lastchar;

  /* get the first selected element */
  TtaGiveFirstSelectedElement (doc, &el, &firstchar, &lastchar);
  if (el)
    {
      elType = TtaGetElementType (el);
      s = TtaGetSSchemaName (elType.ElSSchema);
      while (el &&
             (strcmp (s, "HTML") ||
              elType.ElTypeNum != HTML_EL_Table_row) &&
             (strcmp (s, "MathML") ||
              (elType.ElTypeNum != MathML_EL_MTR &&
               elType.ElTypeNum != MathML_EL_MLABELEDTR)))
        {
          el = TtaGetParent (el);
          if (el)
            {
              elType = TtaGetElementType (el);
              s = TtaGetSSchemaName (elType.ElSSchema);
            }
        }
    }
  return el;
}

/*----------------------------------------------------------------------
  SelectRow
  ----------------------------------------------------------------------*/
void SelectRow (Document doc, View view)
{
  Element     el;

  el = GetEnclosingRow (doc);
  if (el)
    TtaSelectElement (doc, el);
}

/*----------------------------------------------------------------------
  CreateRow
  ----------------------------------------------------------------------*/
static void CreateRow (Document doc, View view, ThotBool before)
{
  Element             el, elNew;
  ElementType         elType;
  NotifyElement       event;
  DisplayMode         dispMode;

  el = GetEnclosingRow (doc);
  if (el)
    {
      dispMode = TtaGetDisplayMode (doc);
      if (dispMode == DisplayImmediately)
        TtaSetDisplayMode (doc, DeferredDisplay);
      elType = TtaGetElementType (el);
      TtaOpenUndoSequence (doc, NULL, NULL, 0, 0);
      elNew = TtaNewElement (doc, elType);
      TtaInsertSibling (elNew, el, before, doc);
      event.element = elNew;
      event.document = doc;
      RowCreated (&event);
      TtaRegisterElementCreate (elNew, doc);
      TtaCloseUndoSequence (doc);
      TtaSelectElement (doc, TtaGetFirstLeaf (elNew));
      TtaSetDisplayMode (doc, dispMode);
      TtaSetDocumentModified (doc);
    }
}

/*----------------------------------------------------------------------
  CreateRowBefore
  ----------------------------------------------------------------------*/
void CreateRowBefore (Document doc, View view)
{
  CreateRow (doc, view, TRUE);
}

/*----------------------------------------------------------------------
  CreateRowAfter
  ----------------------------------------------------------------------*/
void CreateRowAfter (Document doc, View view)
{
  CreateRow (doc, view, FALSE);
}

/*----------------------------------------------------------------------
  SelectColumn
  ----------------------------------------------------------------------*/
void SelectColumn (Document doc, View view)
{
  Element             el;
  int                 firstchar, lastchar;

  /* get the first selected element */
  TtaGiveFirstSelectedElement (doc, &el, &firstchar, &lastchar);
  TtaSelectEnclosingColumn (el);
}

/*----------------------------------------------------------------------
  CreateColumn
  ----------------------------------------------------------------------*/
static void CreateColumn (Document doc, View view, ThotBool before)
{
  Element             cell, elNew, col;
  ElementType         elType;
  Attribute           attr;
  AttributeType       attrType;
  DisplayMode         dispMode;
  ThotBool            inMath;

  /* get the enclosing cell */
  cell = GetEnclosingCell (doc);
  if (cell)
    {
      elType = TtaGetElementType (cell);
      inMath = !strcmp (TtaGetSSchemaName (elType.ElSSchema), "MathML");  
      /* get the colspan value of the element */
      attrType.AttrSSchema = elType.ElSSchema;
      col = NULL;
      if (!before)
        {
          if (inMath)
            attrType.AttrTypeNum = MathML_ATTR_MColExt;
          else
            attrType.AttrTypeNum = HTML_ATTR_ColExt;
          attr = TtaGetAttribute (cell, attrType);
          if (attr)
            TtaGiveReferenceAttributeValue (attr, &col);
        }
      if (col == NULL)
        col = TtaGetColumn (cell);
      if (col)
        {
          dispMode = TtaGetDisplayMode (doc);
          if (dispMode == DisplayImmediately)
            TtaSetDisplayMode (doc, DeferredDisplay);
	  
          /* Create the column */
          elNew = NewColumnHead (col, before, FALSE, NULL, doc, inMath, TRUE);
          TtaSetDisplayMode (doc, dispMode);
          TtaSetDocumentModified (doc);
        }
      TtaCloseUndoSequence (doc);
    }
}

/*----------------------------------------------------------------------
  CreateColumnBefore
  ----------------------------------------------------------------------*/
void CreateColumnBefore (Document doc, View view)
{
  CreateColumn (doc, view, TRUE);
}

/*----------------------------------------------------------------------
  CreateColumnAfter
  ----------------------------------------------------------------------*/
void CreateColumnAfter (Document doc, View view)
{
  CreateColumn (doc, view, FALSE);
}

/*----------------------------------------------------------------------
  PasteBefore
  ----------------------------------------------------------------------*/
void PasteBefore (Document doc, View view)
{
  Element             cell, el, child;
  ElementType         elType;

  /* get the enclosing cell */
  cell = GetEnclosingCell (doc);
  if (cell)
    {
      /* move the selection at the beginning of the cell */
      child = cell;
      while (child)
        {
          el = child;
          child = TtaGetFirstChild (el);
        }
      elType = TtaGetElementType (el);
      if (elType.ElTypeNum == HTML_EL_TEXT_UNIT)
        TtaSelectString (doc, el, 1, 0);
      else
        TtaSelectElement (doc, el);
      TtcPaste (doc, view);
      TtaCloseUndoSequence (doc);
    }
}

/*----------------------------------------------------------------------
  PasteAfter
  ----------------------------------------------------------------------*/
void PasteAfter (Document doc, View view)
{
  Element             cell, el, child;
  ElementType         elType;
  int                 len;

  /* get the enclosing cell */
  cell = GetEnclosingCell (doc);
  if (cell)
    {
      /* move the selection at the end of the cell */
      child = cell;
      while (child)
        {
          el = child;
          child = TtaGetLastChild (el);
        }
      elType = TtaGetElementType (el);
      if (elType.ElTypeNum == HTML_EL_TEXT_UNIT)
        {
          len = TtaGetElementVolume (el);
          TtaSelectString (doc, el, len, len-1);
        }
      else
        TtaSelectElement (doc, el);
      TtcPaste (doc, view);
      TtaCloseUndoSequence (doc);
    }
}

/*----------------------------------------------------------------------
  IsBeforeRow returns the enclosing tbody and TRUE if the new element
  must be inserted before.
  Parameters head or foot is TRUE when the iserted element is a THead of
  a Tfoot.
  ----------------------------------------------------------------------*/
static Element BeginningOrEndOfTBody (Element cell, Document doc,
                                      ThotBool head, ThotBool foot,
                                      ThotBool *before)
{
  Element             tbody;
  ElementType         elType;

  tbody = NULL;
  if (cell)
    {
      elType = TtaGetElementType (cell);
      if (strcmp(TtaGetSSchemaName (elType.ElSSchema), "HTML"))
        /* not an HTML Cell */
        return NULL;
      /* get the enclosing tbody */
      tbody = cell;
      do
        {
          tbody = TtaGetParent (tbody);
          if (tbody)
            elType = TtaGetElementType (tbody);
        }
      while (tbody &&
             (strcmp (TtaGetSSchemaName (elType.ElSSchema), "HTML") ||
              elType.ElTypeNum != HTML_EL_tbody));

      if (tbody == NULL)
        return NULL;
      if (head)
        {
          /* look for the first tbody */
          tbody = TtaGetParent (tbody);
          *before = TRUE;
        }
      else if (foot)
        {
          /* look for the last tbody */
          tbody = TtaGetParent (tbody);
          *before = FALSE;
        }
      else
        {
          do
            {
              TtaPreviousSibling (&cell);
              if (cell)
                elType = TtaGetElementType (cell);
            }
          while (cell &&
                 (strcmp (TtaGetSSchemaName (elType.ElSSchema), "HTML") ||
                  (elType.ElTypeNum != HTML_EL_Data_cell &&
                   elType.ElTypeNum != HTML_EL_Heading_cell)));
          *before = (cell == NULL);
        }
      return tbody;
    }
  else
    return NULL;
}
 
/*----------------------------------------------------------------------
  CreateTHead
  ----------------------------------------------------------------------*/
void CreateTHead (Document doc, View view)
{
  Element             cell, el, elNew, row;
  ElementType         elType;
  DisplayMode         dispMode;
  NotifyElement       event;
  ThotBool            before;

  cell = GetEnclosingCell (doc);
  if (cell)
    {
      el = BeginningOrEndOfTBody (cell, doc, TRUE, FALSE, &before);
      if (el)
        {
          dispMode = TtaGetDisplayMode (doc);
          if (dispMode == DisplayImmediately)
            TtaSetDisplayMode (doc, DeferredDisplay);
          /* generate a thead and its row */
          elType = TtaGetElementType (el);
          elType.ElTypeNum = HTML_EL_thead;
          elNew = TtaNewElement (doc, elType);
          elType.ElTypeNum = HTML_EL_Table_row;
          row = TtaNewElement (doc, elType);
          TtaInsertSibling (elNew, el, before, doc);
          TtaInsertFirstChild (&row, elNew, doc);
          event.element = row;
          event.document = doc;
          RowCreated (&event);
          TtaRegisterElementCreate (elNew, doc);
          TtaSelectElement (doc, TtaGetFirstLeaf (row));
          TtaSetDisplayMode (doc, dispMode);
        }
      TtaCloseUndoSequence (doc);
      TtaSetDocumentModified (doc);
    }
}

/*----------------------------------------------------------------------
  CreateTBody
  ----------------------------------------------------------------------*/
void CreateTBody (Document doc, View view)
{
  Element             cell, el, elNew, row;
  ElementType         elType;
  DisplayMode         dispMode;
  NotifyElement       event;
  ThotBool            before;

  cell = GetEnclosingCell (doc);
  if (cell)
    {
      el = BeginningOrEndOfTBody (cell, doc, FALSE, FALSE, &before);
      if (el)
        {
          dispMode = TtaGetDisplayMode (doc);
          if (dispMode == DisplayImmediately)
            TtaSetDisplayMode (doc, DeferredDisplay);
          /* generate a tbody and its row */
          elType = TtaGetElementType (el);
          elType.ElTypeNum = HTML_EL_tbody;
          elNew = TtaNewElement (doc, elType);
          elType.ElTypeNum = HTML_EL_Table_row;
          row = TtaNewElement (doc, elType);
          TtaInsertSibling (elNew, el, before, doc);
          TtaInsertFirstChild (&row, elNew, doc);
          event.element = row;
          event.document = doc;
          RowCreated (&event);
          TtaRegisterElementCreate (elNew, doc);
          TtaSelectElement (doc, TtaGetFirstLeaf (row));
          TtaSetDisplayMode (doc, dispMode);
        }
      TtaCloseUndoSequence (doc);
      TtaSetDocumentModified (doc);
    }
}

/*----------------------------------------------------------------------
  CreateTFoot
  ----------------------------------------------------------------------*/
void CreateTFoot (Document doc, View view)
{
  Element             cell, el, elNew, row;
  ElementType         elType;
  DisplayMode         dispMode;
  NotifyElement       event;
  ThotBool            before;

  cell = GetEnclosingCell (doc);
  if (cell)
    {
      el = BeginningOrEndOfTBody (cell, doc, FALSE, TRUE, &before);
      if (el)
        {
          dispMode = TtaGetDisplayMode (doc);
          if (dispMode == DisplayImmediately)
            TtaSetDisplayMode (doc, DeferredDisplay);
          /* generate a tfoot and its row */
          elType = TtaGetElementType (el);
          elType.ElTypeNum = HTML_EL_tfoot;
          elNew = TtaNewElement (doc, elType);
          elType.ElTypeNum = HTML_EL_Table_row;
          row = TtaNewElement (doc, elType);
          TtaInsertSibling (elNew, el, before, doc);
          TtaInsertFirstChild (&row, elNew, doc);
          event.element = row;
          event.document = doc;
          RowCreated (&event);
          TtaRegisterElementCreate (elNew, doc);
          TtaSelectElement (doc, TtaGetFirstLeaf (row));
          TtaSetDisplayMode (doc, dispMode);
        }
      TtaCloseUndoSequence (doc);
      TtaSetDocumentModified (doc);
    }
}

/*----------------------------------------------------------------------
  GetEnclosingForm creates if necessary and returns the	
  enclosing form element.				
  ----------------------------------------------------------------------*/
Element GetEnclosingForm (Document document, View view)
{
  Element             el;
  ElementType         elType;
  int                 firstchar, lastchar;

  /* get the first selected element */
  TtaGiveFirstSelectedElement (document, &el, &firstchar, &lastchar);
  if (el)
    {
      /* there is a selection */
      elType = TtaGetElementType (el);
      while (strcmp(TtaGetSSchemaName (elType.ElSSchema), "HTML") != 0
             && elType.ElTypeNum != HTML_EL_BODY
             && elType.ElTypeNum != HTML_EL_Form)
        {
          el = TtaGetParent (el);
          if (el == NULL)
            return (el);
          elType = TtaGetElementType (el);
        }
      if (elType.ElTypeNum != HTML_EL_Form)
        {
          /* it is not already a form */
          elType.ElTypeNum = HTML_EL_Form;
          TtaInsertElement (elType, document);
          TtaGiveFirstSelectedElement (document, &el, &firstchar, &lastchar);
        }
    }
  return (el);
}

/*----------------------------------------------------------------------
  PrepareFormControl 
  
  Return the selected element and make sure there is at least a space
  character before the insertion point.
  withinP is TRUE if the current selection is within a paragraph or
  a pseudo-paragraph, or Hi.
  ----------------------------------------------------------------------*/
static Element PrepareFormControl (Document doc, ThotBool *withinP)
{
  ElementType         elType;
  Element             el, parent;
  int                 firstchar, lastchar;
  int                 len;

  /* get the first selected element */
  TtaGiveFirstSelectedElement (doc, &el, &firstchar, &lastchar);
  *withinP = FALSE;
  if (el)
    /* some element is selected */
    {
      /* check whether the selected element is within a P element */
      parent = el;
      while (parent && !IsBlockElement (parent))
        parent = TtaGetParent (parent);
      *withinP =  (parent != NULL);
      if (*withinP)
        {
          elType = TtaGetElementType (el);
          if (elType.ElTypeNum == HTML_EL_Basic_Set ||
              elType.ElTypeNum == HTML_EL_Basic_Elem)
            /* the selected element is an undefined element. Make it
               a text leaf */
            {
              elType.ElTypeNum = HTML_EL_TEXT_UNIT;
              parent = el;
              el = TtaNewElement (doc, elType);
              TtaInsertFirstChild (&el, parent, doc);
            }
          if (elType.ElTypeNum == HTML_EL_TEXT_UNIT)
            /* the selected element is a text leaf */
            {
              /* add a space if necessary */
              len = TtaGetTextLength (el);
              if (len == 0)
                {
                  TtaSetTextContent (el, (unsigned char*)" ",
                                     TtaGetDefaultLanguage (), doc);
                  /* set a caret after the new space */
                  TtaSelectString (doc, el, 2, 1);
                }
	       
            }
        }
    }
  return (el);
}

/*----------------------------------------------------------------------
  CreateForm
  Create a <form> element.
  ----------------------------------------------------------------------*/
void CreateForm (Document doc, View view)
{
  Element           el;
  int               firstchar, lastchar;
  ElementType       elType;
  ThotBool          oldStructureChecking;

  /* get the first selected element */
  TtaGiveFirstSelectedElement (doc, &el, &firstchar, &lastchar);
  if (el == NULL)
    /* no selection */
    TtaDisplaySimpleMessage (CONFIRM, AMAYA, AM_NO_INSERT_POINT);
  else
    /* there is some selection */
    {
      elType = TtaGetElementType (el);
      elType.ElTypeNum = HTML_EL_Form;
      if (!strcmp(TtaGetSSchemaName (elType.ElSSchema), "HTML"))
        /* the selection is within some HTML document or fragment */
        {
          /* create the form element */
          oldStructureChecking = TtaGetStructureChecking (doc);
          if (!oldStructureChecking)
            TtaSetStructureChecking (TRUE, doc);
          elType.ElTypeNum = HTML_EL_Form;
          TtaCreateElement (elType, doc);
          if (!oldStructureChecking)
            TtaSetStructureChecking (FALSE, doc);
        }
    }
}

/*----------------------------------------------------------------------
  CreateInputElement insert an input element:
  - within an existing paragraph generates input + text
  - in other case generates a paragraph including text + input + text
  ----------------------------------------------------------------------*/
static void CreateInputElement (Document doc, View view, int elInput)
{
  ElementType         elType;
  AttributeType       attrType;
  Element             el, input, parent;
  Attribute           attr;
  int                 firstchar, lastchar;
  ThotBool            withinP, oldStructureChecking;

  /* create the form if necessary */
  el = PrepareFormControl (doc, &withinP);
  if (el == NULL)
    /* no selection */
    TtaDisplaySimpleMessage (CONFIRM, AMAYA, AM_NO_INSERT_POINT);
  else
    {
      /* the element can be created */
      elType = TtaGetElementType (el);
      if (!withinP)
        {
          /* create the pseudo paragraph element */
          elType.ElTypeNum = HTML_EL_Pseudo_paragraph;
          TtaInsertElement (elType, doc);
          TtaGiveFirstSelectedElement (doc, &parent, &firstchar, &lastchar);
          /* check if the pseudo paragraph should becomes a paragraph */
          CheckPseudoParagraph (parent, doc);
          /* create the input element */
          elType.ElTypeNum = elInput;
          input = TtaNewTree (doc, elType, "");
          if (elInput == HTML_EL_Text_Area)
            AddRowsColumns (input, doc);
          TtaInsertFirstChild (&input, parent, doc);	   
          /* Insert a text element before */
          elType.ElTypeNum = HTML_EL_TEXT_UNIT;
          el = TtaNewElement (doc, elType);
          TtaInsertSibling (el, input, TRUE, doc);
        }
      else
        {
          /* create the input element */
          elType.ElTypeNum = elInput;
          oldStructureChecking = TtaGetStructureChecking (doc);
          if (elInput == HTML_EL_Text_Area)
            TtaSetStructureChecking (FALSE, doc);
          TtaInsertElement (elType, doc);
          TtaGiveFirstSelectedElement (doc, &input, &firstchar, &lastchar);
          if (input)
            {
              elType = TtaGetElementType (input);
              while (input && elType.ElTypeNum != elInput)
                {
                  input = TtaGetParent (input);
                  elType = TtaGetElementType (input);
                }
              if (input && (elInput == HTML_EL_Text_Area) && (elType.ElTypeNum == elInput))
                AddRowsColumns (input, doc);
              if (elInput == HTML_EL_Text_Area)
                TtaSetStructureChecking (oldStructureChecking, doc);
              /* add a text before if needed */
              elType.ElTypeNum = HTML_EL_TEXT_UNIT;
              el = input;
              TtaPreviousSibling (&el);
              if (el == NULL)
                {
                  el = TtaNewElement (doc, elType);
                  TtaInsertSibling (el, input, TRUE, doc);
                }
            }
        }
      /* Insert a text element after */
      if (input)
        {
          el = input;
          TtaNextSibling (&el);
          if (el == NULL)
            {
              el = TtaNewElement (doc, elType);
              TtaInsertSibling (el, input, FALSE, doc);
              if (elInput == HTML_EL_Text_Input ||
                  elInput == HTML_EL_Password_Input ||
                  elInput == HTML_EL_File_Input)
                /* set the default size if there is no size attribute */
                {
                  attrType.AttrSSchema = elType.ElSSchema;
                  attrType.AttrTypeNum = HTML_ATTR_IntAreaSize;
                  attr = TtaGetAttribute (input, attrType);
                  if (!attr)
                    CreateAttrIntAreaSize (20, input, doc);
                }
              /* if it's not a HTML_EL_BUTTON_ or a SELECT
                 select the following text element */
              if (elInput != HTML_EL_BUTTON_ &&
                  elInput != HTML_EL_Option_Menu)
                TtaSelectElement (doc, el);
            }
        }
    }
}

/*----------------------------------------------------------------------
  CreateFieldset
  ----------------------------------------------------------------------*/
void CreateFieldset (Document document, View view)
{
  CreateHTMLelement (HTML_EL_FIELDSET, document);
}

/*----------------------------------------------------------------------
  CreateToggle
  ----------------------------------------------------------------------*/
void CreateToggle (Document doc, View view)
{
  CreateInputElement (doc, view, HTML_EL_Checkbox_Input);
}

/*----------------------------------------------------------------------
  CreateRadio
  ----------------------------------------------------------------------*/
void CreateRadio (Document doc, View view)
{
  CreateInputElement (doc, view, HTML_EL_Radio_Input);
}

/*----------------------------------------------------------------------
  UpdateAttrSelected
  ----------------------------------------------------------------------*/
void UpdateAttrSelected (NotifyAttribute * event)
{
  OnlyOneOptionSelected (event->element, event->document, FALSE);
}

/*----------------------------------------------------------------------
  AttrSelectedDeleted
  ----------------------------------------------------------------------*/
void AttrSelectedDeleted (NotifyAttribute * event)
{
  Element	menu;

  menu = TtaGetParent (event->element);
  OnlyOneOptionSelected (menu, event->document, FALSE);
}

/*----------------------------------------------------------------------
  DeleteAttrSelected
  ----------------------------------------------------------------------*/
ThotBool DeleteAttrSelected (NotifyAttribute * event)
{
  return TRUE;			/* refuse to delete this attribute */
}

/*----------------------------------------------------------------------
  CreateOption
  ----------------------------------------------------------------------*/
void CreateOption (Document doc, View view)
{
  ElementType         elType;
  Element             el, new_;
  int                 firstchar, lastchar;

  /* create the form if necessary */
  CreateInputElement (doc, view, HTML_EL_Option_Menu);
  TtaGiveFirstSelectedElement (doc, &el, &firstchar, &lastchar);
  if (el != NULL)
    {
      /* create the option */
      elType = TtaGetElementType (el);
      elType.ElTypeNum = HTML_EL_Option;
      new_ = TtaNewTree (doc, elType, "");
      TtaInsertFirstChild (&new_, el, doc);
      OnlyOneOptionSelected (new_, doc, FALSE);
      /* Select the text element within the option */
      el = TtaGetFirstChild (new_);
      TtaSelectElement (doc, el);
      TtaSelectView (doc, TtaGetViewFromName (doc, "Structure_view"));
    }
}

/*----------------------------------------------------------------------
  CreateOptGroup
  ----------------------------------------------------------------------*/
void CreateOptGroup (Document document, View view)
{
  CreateHTMLelement (HTML_EL_OptGroup, document);
}

/*----------------------------------------------------------------------
  CreateTextInput
  ----------------------------------------------------------------------*/
void CreateTextInput (Document doc, View view)
{
  CreateInputElement (doc, view, HTML_EL_Text_Input);
}

/*----------------------------------------------------------------------
  CreatePasswordInput
  ----------------------------------------------------------------------*/
void CreatePasswordInput (Document doc, View view)
{
  CreateInputElement (doc, view, HTML_EL_Password_Input);
}

/*----------------------------------------------------------------------
  CreateTextArea
  ----------------------------------------------------------------------*/
void CreateTextArea (Document doc, View view)
{
  CreateInputElement (doc, view, HTML_EL_Text_Area);
}


/*----------------------------------------------------------------------
  CreateImageInput
  ----------------------------------------------------------------------*/
void CreateImageInput (Document doc, View view)
{
  AttributeType       attrType;
  Attribute           attr;
  ElementType         elType;
  Element             el;
  char               *value;
  int                 length;
  int                 firstchar, lastchar;
  ThotBool            withinP, newAttr;

  /* create the form if necessary */
  el = PrepareFormControl (doc, &withinP);
  if (el != NULL)
    {
      /* the element can be created */
      elType = TtaGetElementType (el);
      if (!withinP)
        {
          /* create the paragraph element */
          elType.ElTypeNum = HTML_EL_Paragraph;
          TtaInsertElement (elType, doc);
          TtaExtendUndoSequence (doc);
        }
      AddNewImage (doc, view, TRUE);
      TtaGiveFirstSelectedElement (doc, &el, &firstchar, &lastchar);
      if (el)
        {
          elType = TtaGetElementType (el);
          if (elType.ElTypeNum == HTML_EL_PICTURE_UNIT)
            {
              // select the enclosing input
              el = TtaGetParent (el);
              elType = TtaGetElementType (el);
            }
          if (elType.ElTypeNum == HTML_EL_Image_Input)
            /* the img element was created */
            {
              TtaExtendUndoSequence (doc);
              /* use the ALT value to generate the attribute NAME */
              attrType.AttrSSchema = elType.ElSSchema;
              attrType.AttrTypeNum = HTML_ATTR_ALT;
              attr = TtaGetAttribute (el, attrType);
              if (attr)
                {
                  length = TtaGetTextAttributeLength (attr) + 10;
                  value = (char *)TtaGetMemory (length);
                  TtaGiveTextAttributeValue (attr, value, &length);
                  attrType.AttrTypeNum = HTML_ATTR_NAME;
                  attr = TtaGetAttribute (el, attrType);
                  if (attr == NULL)
                    {
                      newAttr = TRUE;
                      attr = TtaNewAttribute (attrType);
                      TtaAttachAttribute (el, attr, doc);
                    }
                  else
                    newAttr = FALSE;
                  TtaSetAttributeText (attr, value, el, doc);
                  if (newAttr)
                    TtaRegisterAttributeCreate (attr, el, doc);
                  else
                    TtaRegisterAttributeReplace (attr, el, doc);
                  TtaFreeMemory (value);
                  /* Check attribute NAME or ID in order to make sure that its
                     value unique in the document */
                  MakeUniqueName (el, doc, TRUE, FALSE);
                }
              TtaCloseUndoSequence (doc);
            }
        }
    }
}

/*----------------------------------------------------------------------
  CreateFileInput
  ----------------------------------------------------------------------*/
void CreateFileInput (Document doc, View view)
{
  CreateInputElement (doc, view, HTML_EL_File_Input);
}

/*----------------------------------------------------------------------
  CreateHiddenInput
  ----------------------------------------------------------------------*/
void CreateHiddenInput (Document doc, View view)
{
  CreateInputElement (doc, view, HTML_EL_Hidden_Input);
}

/*----------------------------------------------------------------------
  CreateLabel
  ----------------------------------------------------------------------*/
void  CreateLabel (Document doc, View view)
{
  CreateHTMLelement (HTML_EL_LABEL, doc);
}

/*----------------------------------------------------------------------
  CreatePushButton
  ----------------------------------------------------------------------*/
void  CreatePushButton (Document doc, View view)
{
  CreateInputElement (doc, view, HTML_EL_BUTTON_);
}

/*----------------------------------------------------------------------
  CreateSubmit
  ----------------------------------------------------------------------*/
void  CreateSubmit (Document doc, View view)
{
  CreateInputElement (doc, view, HTML_EL_Submit_Input);
}

/*----------------------------------------------------------------------
  CreateReset
  ----------------------------------------------------------------------*/
void  CreateReset (Document doc, View view)
{
  CreateInputElement (doc, view, HTML_EL_Reset_Input);
}

/*----------------------------------------------------------------------
  CreateDivision
  ----------------------------------------------------------------------*/
void  CreateDivision (Document document, View view)
{
  CreateHTMLelement (HTML_EL_Division, document);
}

/*----------------------------------------------------------------------
  CreateNOSCRIPT
  ----------------------------------------------------------------------*/
void  CreateNOSCRIPT (Document document, View view)
{
  CreateHTMLelement (HTML_EL_NOSCRIPT, document);
}

/*----------------------------------------------------------------------
  CreateIFrame
  ----------------------------------------------------------------------*/
void  CreateIFrame (Document document, View view)
{
  ElementType         elType;
  Element             el, child;
  Attribute           attr;
  AttributeType       attrType;
  int                 firstchar, lastchar;

  if (HTMLelementAllowed (document))
    {
      /* Don't check mandatory attributes */
      TtaSetStructureChecking (FALSE, document);
      elType.ElSSchema = TtaGetSSchema ("HTML", document);
      elType.ElTypeNum = HTML_EL_IFRAME;
      TtaInsertElement (elType, document);
      /* Check the Thot abstract tree against the structure schema. */
      TtaSetStructureChecking (TRUE, document);

      /* get the first selected element, i.e. the Object element */
      TtaGiveFirstSelectedElement (document, &el, &firstchar, &lastchar);
      
      elType = TtaGetElementType (el);
      while (el != NULL &&
             elType.ElTypeNum != HTML_EL_IFRAME)
        {
          el = TtaGetParent (el);
          elType = TtaGetElementType (el);
        }
      
      if (el == NULL)
        return;

      TtaExtendUndoSequence (document);
      /* copy SRC attribute */
      attrType.AttrSSchema = elType.ElSSchema;
      attrType.AttrTypeNum = HTML_ATTR_FrameSrc;
      attr = TtaGetAttribute (el, attrType);
      if (attr == NULL)
        {
           attr = TtaNewAttribute (attrType);
           TtaAttachAttribute (el, attr, document);
           TtaSetAttributeText (attr, "source.html", el, document);
           TtaRegisterAttributeCreate (attr, el, document);
         }
      /* now create a child element */
      child = TtaGetLastChild (el);
      if (child == NULL)
        {
          elType.ElTypeNum = HTML_EL_Iframe_Content;
          child = TtaNewElement (document, elType);
          TtaInsertFirstChild (&child, el, document);
          TtaRegisterElementCreate (child, document);
        }
      elType.ElTypeNum = HTML_EL_Pseudo_paragraph;
      el = TtaNewElement (document, elType);
      TtaInsertFirstChild (&el, child, document);
      TtaRegisterElementCreate (el, document);
      elType.ElTypeNum = HTML_EL_TEXT_UNIT;
      child = TtaNewElement (document, elType);
      TtaInsertFirstChild (&child, el, document);
      TtaSelectElement (document, child);
      TtaRegisterElementCreate (child, document);
      TtaCloseUndoSequence (document);
  }
}

/*----------------------------------------------------------------------
  CreateParameter
  ----------------------------------------------------------------------*/
void  CreateParameter (Document document, View view)
{
  CreateHTMLelement (HTML_EL_Parameter, document);
}

/*----------------------------------------------------------------------
  CreateOrChangeLink
  If current selection is within an anchor, change that link, otherwise
  create a link.
  ----------------------------------------------------------------------*/
void  CreateOrChangeLink (Document doc, View view)
{
  Element             el;
  ElementType         elType;
  Attribute           attr;
  char               *s;
  int                 firstSelectedChar, i;

  if (!TtaGetDocumentAccessMode (doc))
    /* the document is in ReadOnly mode */
    return;

  UseLastTarget = FALSE;
  TtaGiveFirstSelectedElement (doc, &el, &firstSelectedChar, &i);
  if (TtaIsReadOnly (el))
    /* the selected element is read-only */
    return;

  if (el != NULL)
    {
      /* Look if there is an enclosing anchor element */
      el = SearchAnchor (doc, el, &attr, TRUE);
      if (el)
        {
          elType = TtaGetElementType (el);
          s = TtaGetSSchemaName (elType.ElSSchema);
          if ((elType.ElTypeNum != HTML_EL_Anchor || strcmp (s, "HTML"))
#ifdef _SVG
              && (elType.ElTypeNum != SVG_EL_a || strcmp (s, "SVG"))
#endif /* _SVG */
              )
            /* it's not an anchor */
            el = NULL;
        }
      if (el == NULL)
        {
          /* The link element is a new created one */
          IsNewAnchor = TRUE;
          /* no anchor element, create a new link */
          CreateAnchor (doc, view, TRUE);
        }
      else
        {
          /* The link element already exists */
          IsNewAnchor = FALSE;
          /* There is an anchor. Just select a new destination */
          SelectDestination (doc, el, TRUE, FALSE);
        }
    }
  else
    TtaDisplaySimpleMessage (CONFIRM, AMAYA, AM_NO_INSERT_POINT);
}

/*----------------------------------------------------------------------
  DoDeleteAnchor
  Delete the surrounding anchor.
  noCallback is TRUE when it's not a callback action
  ----------------------------------------------------------------------*/
void DoDeleteAnchor (Document doc, View view, ThotBool noCallback)
{
  Element             firstSelectedElement, lastSelectedElement;
  Element             anchor, child, next, previous;
  ElementType         elType;
  DisplayMode         dispMode;
  int                 firstSelectedChar, lastSelectedChar, i;

  if (!TtaGetDocumentAccessMode (doc))
    /* the document is in ReadOnly mode */
    return;

  if (noCallback)
    {
      /* get the first selected element */
      TtaGiveFirstSelectedElement (doc, &firstSelectedElement,
                                   &firstSelectedChar, &lastSelectedChar);
      if (firstSelectedElement == NULL)
        {
          /* no selection. Do nothing */
          TtaDisplaySimpleMessage (CONFIRM, AMAYA, AM_NO_INSERT_POINT);
          return;
        }
      if (TtaIsReadOnly (firstSelectedElement))
        /* the selected element is read-only */
        return;

      elType = TtaGetElementType (firstSelectedElement);
      if (strcmp(TtaGetSSchemaName (elType.ElSSchema), "HTML") != 0)
        /* the first selected element is not an HTML element. Do nothing */
        return;

      TtaGiveLastSelectedElement (doc, &lastSelectedElement, &i, 
                                  &lastSelectedChar);
      TtaOpenUndoSequence (doc, firstSelectedElement, lastSelectedElement,
                           firstSelectedChar, lastSelectedChar);
      anchor = firstSelectedElement;
    }
  else
    {
      anchor = AttrHREFelement;
      firstSelectedElement = lastSelectedElement = anchor;
      elType = TtaGetElementType (anchor);
      firstSelectedChar = 0;
    }

  if (elType.ElTypeNum == HTML_EL_Anchor)
    /* the first selected element is an anchor */
    {
      /* prepare the elements to be selected later */
      firstSelectedElement = TtaGetFirstChild (anchor);
      lastSelectedElement = TtaGetLastChild (anchor);
      firstSelectedChar = 0;
      lastSelectedChar = 0;
    }
  else if (elType.ElTypeNum == HTML_EL_AREA)
    {
      /* prepare the elements to be selected later */
      firstSelectedElement = NULL;
      lastSelectedElement = NULL;
      firstSelectedChar = 0;
      lastSelectedChar = 0;
    }
  else if (elType.ElTypeNum == HTML_EL_Cite)
    {
      anchor = NULL;
      SetOnOffCite (doc, 1);
      return;
    }
  else if (elType.ElTypeNum != HTML_EL_LINK)
    {
      /* search the surrounding Anchor element */
      elType.ElTypeNum = HTML_EL_Anchor;
      anchor = TtaGetTypedAncestor (firstSelectedElement, elType);
    }

  if (anchor)
    {
      /* ask Thot to stop displaying changes made in the document */
      dispMode = TtaGetDisplayMode (doc);
      if (dispMode == DisplayImmediately)
        TtaSetDisplayMode (doc, DeferredDisplay);
      TtaUnselect (doc);
      TtaRegisterElementDelete (anchor, doc);
      /* move all chidren of element anchor as sibling of the anchor */
      child = TtaGetFirstChild (anchor);
      previous = anchor;
      while (child != NULL)
        {
          next = child;
          TtaNextSibling (&next);
          TtaRemoveTree (child, doc);
          TtaInsertSibling (child, previous, FALSE, doc);
          TtaRegisterElementCreate (child, doc);
          previous = child;
          child = next;
        }
      /* prepare the next selection */
      if (firstSelectedElement == NULL)
        firstSelectedElement = TtaGetPredecessor (anchor);
      if (firstSelectedElement == NULL)
        firstSelectedElement = TtaGetSuccessor (anchor);
      if (firstSelectedElement == NULL)
        firstSelectedElement = TtaGetParent (anchor);
      /* delete the anchor element itself */
      TtaDeleteTree (anchor, doc);
      /* ask Thot to display changes made in the document */
      TtaSetDisplayMode (doc, dispMode);
    }

  if (noCallback)
    {
      TtaCloseUndoSequence (doc);
      TtaSetDocumentModified (doc);
    }

  /* set the selection */
  if (firstSelectedChar > 1)
    {
      if (firstSelectedElement == lastSelectedElement)
        i = lastSelectedChar;
      else
        i = TtaGetElementVolume (firstSelectedElement);
      TtaSelectString (doc, firstSelectedElement, firstSelectedChar, i);
    }
  else
    TtaSelectElement (doc, firstSelectedElement);
  if (firstSelectedElement != lastSelectedElement)
    TtaExtendSelection (doc, lastSelectedElement, lastSelectedChar);
}

/*----------------------------------------------------------------------
  DeleteAnchor
  Delete the surrounding anchor.                    
  ----------------------------------------------------------------------*/
void DeleteAnchor (Document doc, View view)
{
  DoDeleteAnchor (doc, view, TRUE);
}

/*----------------------------------------------------------------------
  CleanCache
  A frontend to the CleanCache function, called thru an Amaya menu
  ----------------------------------------------------------------------*/
void FlushCache (Document doc, View view)
{
  StopAllRequests (doc);
  libwww_CleanCache ();
}

/*----------------------------------------------------------------------
  ConfigAmaya
  A frontend to all Amaya configurations
  ----------------------------------------------------------------------*/
void ConfigAmaya (Document doc, View view)
{
  GeneralConfMenu (doc, view);
}

/*----------------------------------------------------------------------
  ConfigColor
  A frontend to the Color configuration menu
  ----------------------------------------------------------------------*/
void ConfigColor (Document doc, View view)
{
  ColorConfMenu (doc, view);
}

/*----------------------------------------------------------------------
  ConfigGeometry
  A frontend to the Geometry configuration menu
  ----------------------------------------------------------------------*/
void ConfigGeometry (Document doc, View view)
{
  GeometryConfMenu (doc, view);
}

/*----------------------------------------------------------------------
  ConfigGeneral
  A frontend to the Browsing Editing configuration menu
  ----------------------------------------------------------------------*/
void ConfigGeneral (Document doc, View view)
{
  GeneralConfMenu (doc, view);
}

/*----------------------------------------------------------------------
  ConfigBrowse
  A frontend to the Browsing Editing configuration menu
  ----------------------------------------------------------------------*/
void ConfigBrowse (Document doc, View view)
{
  BrowseConfMenu (doc, view);
}

/*----------------------------------------------------------------------
  ConfigPublish
  A frontend to the Browsing Editing configuration menu
  ----------------------------------------------------------------------*/
void ConfigPublish (Document doc, View view)
{
  PublishConfMenu (doc, view);
}

/*----------------------------------------------------------------------
  ConfigCache
  A frontend to the cache configuration menu
  ----------------------------------------------------------------------*/
void ConfigCache (Document doc, View view)
{
  CacheConfMenu (doc, view);
}

/*----------------------------------------------------------------------
  ConfigProxy
  A frontend to the proxy configuration menu
  ----------------------------------------------------------------------*/
void ConfigProxy (Document doc, View view)
{
  ProxyConfMenu (doc, view);
}


/*----------------------------------------------------------------------
  SaveOptions
  Saves the user modified configuration options
  ----------------------------------------------------------------------*/
void SaveOptions (Document doc, View view)
{
  TtaSaveAppRegistry ();
}

/*----------------------------------------------------------------------
  ConfigAnnot
  A frontend to the Templates configuration menu
  ----------------------------------------------------------------------*/
void ConfigAnnot (Document doc, View view)
{
#ifdef ANNOTATIONS
  AnnotConfMenu (doc, view);
#endif /* ANNOTATIONS */
}

/*----------------------------------------------------------------------
  AnnotateDocument
  Frontend to the function that creates an annotation
  ----------------------------------------------------------------------*/
void AnnotateDocument (Document doc, View view)
{
#ifdef ANNOTATIONS
  ANNOT_Create (doc, view, ANNOT_useDocRoot);
#endif /* ANNOTATIONS */
}

/*----------------------------------------------------------------------
  AnnotateDocument
  Frontend to the function that creates an annotation
  ----------------------------------------------------------------------*/
void AnnotateSelection (Document doc, View view)
{
#ifdef ANNOTATIONS
  ANNOT_Create (doc, view, ANNOT_useSelection);
#endif /* ANNOTATIONS */
}

/*----------------------------------------------------------------------
  LoadAnnotations
  Frontend to the function that loads the annotations related to a document
  ----------------------------------------------------------------------*/
void LoadAnnotations (Document doc, View view)
{
#ifdef ANNOTATIONS
  ANNOT_Load (doc, view);
#endif /* ANNOTATIONS */
}

/*----------------------------------------------------------------------
  PostAnnotation
  Frontend to the function that posts an annotation to the server
  ----------------------------------------------------------------------*/
void PostAnnotation (Document doc, View view)
{
#ifdef ANNOTATIONS
  ANNOT_Post (doc, view);
#endif /* ANNOTATIONS */
}

/*----------------------------------------------------------------------
  DeleteAnnotation
  Frontend to the function that posts an annotation to the server
  ----------------------------------------------------------------------*/
void DeleteAnnotation (Document doc, View view)
{
#ifdef ANNOTATIONS
  ANNOT_Delete (doc, view);
#endif /* ANNOTATIONS */
}

/*----------------------------------------------------------------------
  FilterAnnot
  Show/Hide the annotations
  ----------------------------------------------------------------------*/
void FilterAnnot (Document document, View view)
{
#ifdef ANNOTATIONS
  AnnotFilter (document, view);
#endif /* ANNOTATIONS */
}

/*----------------------------------------------------------------------
  MoveAnnotationXPtr
  Move an annotation to the value stored in the XPointer
  ----------------------------------------------------------------------*/
void  MoveAnnotationXPtr (Document document, View view)
{
#ifdef ANNOTATIONS
  ANNOT_Move (document, view, FALSE);
#endif /* ANNOTATIONS */
}

/*----------------------------------------------------------------------
  MoveAnnotationSel
  Move an annotation in a document to the current selection
  ----------------------------------------------------------------------*/
void  MoveAnnotationSel (Document document, View view)
{
#ifdef ANNOTATIONS
  ANNOT_Move (document, view, TRUE);
#endif /* ANNOTATIONS */
}

/*----------------------------------------------------------------------
  Show/Hide the annotations
  ----------------------------------------------------------------------*/
void ReplyToAnnotation (Document document, View view)
{
#ifdef ANNOTATIONS
  /* for testing threading on the selection */
  ANNOT_Create (document, view, (AnnotMode)(ANNOT_useDocRoot | ANNOT_isReplyTo));
#endif /* ANNOTATIONS */
}

/*----------------------------------------------------------------------
  CustomQuery the annotations base
  ----------------------------------------------------------------------*/
void CustomQuery (Document document, View view)
{
#ifdef ANNOTATIONS
  CustomQueryMenuInit (document, view);
#endif /* ANNOTATIONS */
}

/*----------------------------------------------------------------------
  BookmarkFile
  Bookmarks a file
  ----------------------------------------------------------------------*/
void BookmarkFile (Document document, View view)
{
#ifdef BOOKMARKS
  BM_CreateBM (document, view);
#endif /* BOOKMARKS */
}

/*----------------------------------------------------------------------
  EditTopics
  Edit Bookmark Topics
  ----------------------------------------------------------------------*/
void EditTopics (Document document, View view)
{
#ifdef BOOKMARKS
  BM_CreateTopic (document, view);
#endif /* BOOKMARKS */
}

/*----------------------------------------------------------------------
  AddSeparator
  Edit Bookmark Topics
  ----------------------------------------------------------------------*/
void AddSeparator (Document document, View view)
{
#ifdef BOOKMARKS
  BM_CreateSeparator (document, view);
#endif /* BOOKMARKS */
}

/*----------------------------------------------------------------------
  ViewBookmarks
  Opens the Amaya bookmarks window
  ----------------------------------------------------------------------*/
void ViewBookmarks (Document document, View view)
{
#ifdef BOOKMARKS
  BM_ViewBookmarks (0, 0, FALSE);
#endif /* BOOKMARKS */
}

/*----------------------------------------------------------------------
  MoveItem
  Moves a previously copied bookmark item in the bookmark view
  ----------------------------------------------------------------------*/
void MoveItem (Document document, View view)
{
#ifdef BOOKMARKS
  BM_MoveHandler (document, view);
#endif /* BOOKMARKS */
}

/*------------ Begin: WebDAV Modifications by Manuele Kirsch -----------*/
/* Note: There is no #include "davlib.h" in this file to prevent
 *       circular references between the header files.
 */        


/*----------------------------------------------------------------------
  LockDocument
  Lock document using WebDAV protocol
  ----------------------------------------------------------------------*/
void LockDocument (Document document, View view)
{
#ifdef DAV
  DAVLockDocument (document,view);
#endif /* DAV */
}


/*----------------------------------------------------------------------
  UnlockDocument
  Unlock document using WebDAV protocol
  ----------------------------------------------------------------------*/
void UnlockDocument (Document document, View view)
{
#ifdef DAV 
  DAVUnlockDocument (document,view);
#endif /* DAV */
}


/*----------------------------------------------------------------------
  PropDocument
  Get the document properties using WebDAV protocol
  ----------------------------------------------------------------------*/
void PropDocument (Document document, View view)
{
#ifdef DAV
  DAVProfindDocument (document,view);
#endif /* DAV */
}


/*----------------------------------------------------------------------
  CopyLockInformation
  Get the lock information of the document 
  ----------------------------------------------------------------------*/
void CopyLockInformation (Document document, View view)
{
#ifdef DAV
  DAVCopyLockInfo (document,view);
#endif /* DAV */
}


/*----------------------------------------------------------------------
  DAVConfigure 
  A Configure dialogue for the WebDAV user's preferences.
  ----------------------------------------------------------------------*/
void CooperationConfig (Document document, View view) 
{
#ifdef DAV
  DAVPreferences (document,view);
#endif /* DAV */
}



/*----------------------------------------------------------------------
  LockIndicator
  A toggle that indicates whether the document is locked.
  ----------------------------------------------------------------------*/
void LockIndicator (Document document, View view) 
{
#ifdef DAV
  DAVLockIndicator (document,view);
#endif /* DAV */

}


/*------------ End: WebDAV Modifications by Manuele Kirsch -----------*/
