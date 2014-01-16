/*
 *
 *  (c) COPYRIGHT INRIA and W3C, 1996-2007
 *  Please first read the full copyright statement in file COPYRIGHT.
 *
 */

/*
 * Amaya editing functions called form Thot and declared in HTML.A
 * These functions concern Image elements.
 *
 * Author: I. Vatton
 *         R. Guetari Unicode and Windows version.
 *
 */

#ifdef _WX
#include "wx/wx.h"
#endif /* _WX */
 
/* Included headerfiles */
#define THOT_EXPORT extern
#include "amaya.h"
#include "css.h"
#include "SVG.h"

static Document   ImgDocument;
static int        RepeatValue;
static ThotBool   CreateNewImage;

#include "AHTURLTools_f.h"
#include "HTMLactions_f.h"
#include "HTMLedit_f.h"
#include "EDITimage_f.h"
#include "EDITORactions_f.h"
#include "EDITstyle_f.h"
#include "HTMLimage_f.h"
#include "HTMLpresentation_f.h"
#include "init_f.h"
#include "html2thot_f.h"
#include "styleparser_f.h"
#include "XHTMLbuilder_f.h"

#ifdef _WX
#include "wxdialogapi_f.h"
#include "message_wx.h"
#endif /* _WX */

#ifdef _WINGUI
#include "wininclude.h"
#endif /* _WINGUI */

static int RefFormImage = 0;


/*----------------------------------------------------------------------
  DeleteMap                                              
  ----------------------------------------------------------------------*/
ThotBool DeleteMap (NotifyElement * event)
{
  Element             image;
  ElementType	       elType;
  AttributeType       attrType;
  Attribute           attr;

  /* Search the refered image */
  elType = TtaGetElementType (event->element);
  attrType.AttrSSchema = elType.ElSSchema;
  attrType.AttrTypeNum = HTML_ATTR_Ref_IMG;
  attr = TtaGetAttribute (event->element, attrType);
  image = NULL;
  if (attr != NULL)
    {
      /* Search the IMAGE element associated with the MAP */
      TtaGiveReferenceAttributeValue (attr, &image);

      /* remove the attribute USEMAP of the image */
      attrType.AttrTypeNum = HTML_ATTR_USEMAP;
      attr = TtaGetAttribute (image, attrType);
      if (attr != NULL)
        TtaRemoveAttribute (image, attr, event->document);
    }
  return FALSE;		/* let Thot perform normal operation */
}

/*----------------------------------------------------------------------
  CallbackImage
  Handle callbacks from the "Picture" and "Background image" forms.
  ----------------------------------------------------------------------*/
void CallbackImage (int ref, int typedata, char *data)
{
  Document           document;
  Element            el, parent;
  Element            first, last;
  ElementType	       elType, parentType;
  LoadedImageDesc    *desc;
  char               tempfile[MAX_LENGTH];
  char               tempname[MAX_LENGTH];
  char              *name;
  int                i, c1, cN;
  long int           val;
  ThotBool           change, isHTML;

  isHTML = FALSE;
  val = (long int) data;
  switch (ref - BaseImage)
    {
    case FormAlt:
      if (val == 1 && ImgAlt[0] == EOS)
        strcpy (ImgAlt, "Alt");
      TtaDestroyDialogue (ref);
      break;
    case FormImage:
    case FormObject:
    case FormBackground:
      if (val == 2)
        { 
          /* Clear button */
          LastURLImage[0] = EOS;
#ifdef _GTK
          TtaSetTextForm (BaseImage + ImageURL, LastURLImage);
#endif /* _GTK */
        }
      else if (val == 3)
        {
          /* Filter button */
          /* reinitialize directories and document lists */
          TtaListDirectory (DirectoryImage, ref,
                            TtaGetMessage (LIB, TMSG_DOC_DIR),
                            BaseImage + ImageDir,
                            ImgFilter,
                            TtaGetMessage (AMAYA, AM_FILES),
                            BaseImage + ImageSel);
        }
      else if (val == 0)
        /* Cancel button */ 
        { 
          LastURLImage[0] = EOS;
          TtaDestroyDialogue (ref);
          ImgDocument = 0;
        }
#ifdef _GTK
      else if (ref == BaseImage + FormImage && ImgAlt[0] == EOS)
        {
          /* IMG element without ALT attribute: error message */
          TtaNewLabel (BaseImage + ImageLabel4, RefFormImage,
                       TtaGetMessage (AMAYA, AM_ALT_MISSING));
        }
#endif /* _GTK */
      else
        {
          TtaDestroyDialogue (ref);
          /* inclusion of an image is managed by ComputeSRCattribute */
          if (ref == BaseImage + FormBackground && ImgDocument != 0)
            {
              /* save ImgDocument because operation can be too long */
              document = ImgDocument;
              /* get the first and last selected element */
              TtaGiveFirstSelectedElement (document, &first, &c1, &i);
              TtaGiveLastSelectedElement (document, &last, &i, &cN);
              TtaOpenUndoSequence (document, first, last, c1, cN);
              el = NULL;
              if (first)
                {
                  el = first;
                  elType = TtaGetElementType (el);
                  name = TtaGetSSchemaName (elType.ElSSchema);
                  isHTML = !strcmp (name, "HTML");
                  if (isHTML && elType.ElTypeNum == HTML_EL_HTML)
                    {
                      elType.ElTypeNum = HTML_EL_BODY;
                      el = TtaSearchTypedElement (elType, SearchInTree, el);
                    }
                  /* style is not allowed in Head section */
                  last = el;
                  if (isHTML)
                    {
                      if (elType.ElTypeNum == HTML_EL_HEAD)
                        parent = el;
                      else
                        {
                          parentType.ElSSchema = elType.ElSSchema;
                          parentType.ElTypeNum = HTML_EL_HEAD;
                          parent = TtaGetTypedAncestor (el, parentType);
                        } 
                      if (parent == NULL)
                        { 
                          /* style is not allowed in MAP */
                          if (elType.ElTypeNum == HTML_EL_MAP)
                            parent = el;
                          else
                            {
                              parentType.ElTypeNum = HTML_EL_MAP;
                              parent = TtaGetTypedAncestor (el, parentType);
                            }
                        }
                      if (parent == NULL)
                        {
                          elType = TtaGetElementType (last);
                          if (elType.ElTypeNum == HTML_EL_MAP)
                            parent = el;
                          else
                            {
                              parentType.ElTypeNum = HTML_EL_MAP;
                              parent = TtaGetTypedAncestor (el, parentType);
                            }
                        }  
                      if (parent)
                        el = NULL;
                    }
                }
              if (el == NULL)
                TtaSetStatus (document, 1,
                              TtaGetMessage(AMAYA, AM_BG_IMAGE_NOT_ALLOWED),
                              NULL);
              else
                {
                  if (RepeatValue == 0)
                    i = REPEAT;
                  else if (RepeatValue == 1)
                    i = XREPEAT;
                  else if (RepeatValue == 2)
                    i = YREPEAT;
                  else
                    i = SCALE;

                  if (IsHTTPPath (DocumentURLs[document]) &&
                      !IsHTTPPath (LastURLImage) &&
                      TtaFileExist (LastURLImage))
                    {
                      /* load a local image into a remote document copy image
                         file into the temporary directory of the document */
                      TtaExtractName (LastURLImage, tempfile, tempname);
                      NormalizeURL (tempname, document, tempfile, tempname,NULL);
                      AddLoadedImage (tempname, tempfile, document, &desc);
                      if (desc)
                        {
                          desc->status = IMAGE_MODIFIED;
                          TtaFileCopy (LastURLImage, desc->localName);
                          desc->tempfile = TtaStrdup (desc->localName);
                        }
                    }

                  do
                    {
                      elType = TtaGetElementType (el);
                      /* if the PRule is on a text string or picture, move it to
                         the enclosing element */
                      if (elType.ElTypeNum == HTML_EL_TEXT_UNIT ||
                          elType.ElTypeNum == HTML_EL_PICTURE_UNIT)
                        {
                          el = TtaGetParent (el);
                          if (TtaIsAncestor (last, el))
                            last = el;
                          elType = TtaGetElementType (el);
                        } 
                      /* if the PRule is on a Pseudo-Paragraph, move it to the
                         enclosing element */
                      if (isHTML && elType.ElTypeNum == HTML_EL_Pseudo_paragraph)
                        {
                          el = TtaGetParent (el);
                          if (TtaIsAncestor (last, el))
                            last = el;
                        } 
                      if (LastURLImage[0] == EOS)
                        HTMLResetBackgroundImage (document, el);
                      else if (IsHTTPPath (DocumentURLs[document]) &&
                               !IsHTTPPath (LastURLImage))
                        HTMLSetBackgroundImage (document, el, i, 200, tempname, TRUE);
                      else
                        HTMLSetBackgroundImage (document, el, i, 200, LastURLImage,
                                                TRUE);
                      if (last == NULL || el == last)
                        el = NULL;
                      else
                        TtaGiveNextSelectedElement (document, &el, &c1, &cN);
                    } while (el);
                } 
              TtaCloseUndoSequence (document);
              TtaSetDocumentModified (document);
            }
        }
      break;
    case RepeatImage:
      RepeatValue = val;
      break;
    case ImageFilter: /* Filter value */
      if (strlen(data) <= NAME_LENGTH)
        strcpy (ImgFilter, data);
#ifdef _GTK
      else
        TtaSetTextForm (BaseImage + ImageFilter, ImgFilter);
#endif /* _GTK */
      break;
    case ImageURL:
      if (data == NULL)
        break;
      if (IsW3Path (data)) 
        {
          /* save the URL name */
          strcpy (LastURLImage, data);
          ImageName[0] = EOS;
        } 
      else 
        {
          change = NormalizeFile (data, LastURLImage, AM_CONV_NONE);
          if (TtaCheckDirectory (LastURLImage)) 
            {
              strcpy (DirectoryImage, LastURLImage);
              ImageName[0] = EOS;
              LastURLImage[0] = EOS;
            } 
          else
            TtaExtractName (LastURLImage, DirectoryImage, ImageName);
        }
      break;
    case ImageAlt:
      strncpy (ImgAlt, data, MAX_LENGTH - 1);
      ImgAlt[MAX_LENGTH - 1] = EOS;
      break;
    case ImageDir:
      if (!strcmp (data, ".."))
        {
          /* suppress last directory */
          strcpy (tempname, DirectoryImage);
          TtaExtractName (tempname, DirectoryImage, tempfile);
        }
      else
        {
          strcat (DirectoryImage, DIR_STR);
          strcat (DirectoryImage, data);
        }
#ifdef _GTK
      TtaSetTextForm (BaseImage + ImageURL, DirectoryImage);
#endif /* _GTK */
      TtaListDirectory (DirectoryImage, RefFormImage,
                        TtaGetMessage (LIB, TMSG_DOC_DIR), 
                        BaseImage + ImageDir, ImgFilter,
                        TtaGetMessage (AMAYA, AM_FILES), BaseImage + ImageSel);
      ImageName[0] = EOS;
      break;
    case ImageSel:
      if (DirectoryImage[0] == EOS)
        /* set path on current directory */
        getcwd (DirectoryImage, MAX_LENGTH);
      /* construct the image full name */
      strcpy (LastURLImage, DirectoryImage);
      val = strlen (LastURLImage) - 1;
      if (LastURLImage[val] != DIR_SEP)
        strcat (LastURLImage, DIR_STR);
      strcat (LastURLImage, data);
#ifdef _GTK
      TtaSetTextForm (BaseImage + ImageURL, LastURLImage);
#endif /* _GTK */
      break;
    default:
      break;
    } 
}

/*----------------------------------------------------------------------
  ----------------------------------------------------------------------*/
void InitImage (void)
{
  BaseImage = TtaSetCallback ((Proc)CallbackImage, IMAGE_MAX_REF);
  RepeatValue = 0;
  LastURLImage[0] = EOS;
  strcpy (ImgFilter, "*.*");
  /* set path on current directory */
  strcpy (DirectoryImage, DirectoryName);
}

/*----------------------------------------------------------------------
  GetAlt gets the Alt value for an Area                            
  ----------------------------------------------------------------------*/
static void GetAlt (Document document, View view)
{
  ImgAlt[0] = EOS;
#ifdef _GTK
  TtaNewForm (BaseImage + FormAlt, TtaGetViewFrame (document, view),
              TtaGetMessage (AMAYA, AM_ALT),
              TRUE, 1, 'L', D_DONE);
  TtaNewTextForm (BaseImage + ImageAlt, BaseImage + FormAlt,
                  TtaGetMessage (AMAYA, AM_ALT), 50, 1, TRUE);
  TtaNewLabel (BaseImage + ImageLabel4, BaseImage + FormAlt,
               TtaGetMessage (AMAYA, AM_ALT_MISSING));
  TtaSetDialoguePosition ();
  TtaShowDialogue (BaseImage + FormAlt, FALSE);
  TtaWaitShowDialogue ();
  TtaDestroyDialogue (BaseImage + FormAlt);   
#endif /* _GTK */
#ifdef _WX
  CreateTextDlgWX ( BaseImage + FormAlt, BaseImage + ImageAlt,
                    TtaGetViewFrame (document, view),
                    TtaGetMessage (AMAYA, AM_ALT),
                    TtaGetMessage (AMAYA, AM_ALT_MISSING),
                    "");
  TtaShowDialogue (BaseImage + FormAlt, FALSE);
  TtaWaitShowDialogue ();
  TtaDestroyDialogue (BaseImage + FormAlt);   
#endif  /* _WX */
#ifdef _WINGUI
  CreateAltDlgWindow ();
#endif /* _WINGUI */
}
 
/*----------------------------------------------------------------------
  CreateAreaMap
  create an area in a map. shape indicates the shape of the area to be
  created:
  'R': rectangle
  'a': circle
  'p': polygon
  ----------------------------------------------------------------------*/
static void CreateAreaMap (Document doc, View view, char *shape)
{
  Element             el, map, parent, image, child, div;
  Element             newMap, newElem;
  ElementType         elType, parentType;
  AttributeType       attrType;
  Attribute           attr, attrRef, attrShape, attrRefimg, newuseMap;
  char                *url;
#ifndef _WX
  char                *utf8value;
#endif /* _WX */
  int                 length, w, h;
  int                 firstchar, lastchar;
  int                 docModified, profile;
  DisplayMode         dispMode;
  ThotBool            oldStructureChecking;
  ThotBool            lock = TRUE;

  /* get the first selected element */
  TtaGiveFirstSelectedElement (doc, &el, &firstchar, &lastchar);
  if (el == NULL)
    {
      /* no selection. Nothing to do */
      TtaDisplaySimpleMessage (CONFIRM, AMAYA, AM_NO_INSERT_POINT);
      return;
    }
  div = NULL;
  elType = TtaGetElementType (el);
  if (strcmp(TtaGetSSchemaName (elType.ElSSchema), "HTML"))
    /* not within an HTML element. Nothing to do */
    return;
  if (elType.ElTypeNum == HTML_EL_PICTURE_UNIT)
    {
      // look for the enclosing IMG
      parent = TtaGetParent (el);
      parentType = TtaGetElementType (parent);
      if (strcmp(TtaGetSSchemaName (parentType.ElSSchema), "HTML") ||
          parentType.ElTypeNum != HTML_EL_IMG)
        return;
      el = parent;
    }
  /* first force the display of areas */
  if (!MapAreas[doc])
    ShowMapAreas (doc, view);

  docModified = TtaIsDocumentModified (doc);
  /* ask Thot to stop displaying changes made in the document */
  dispMode = TtaGetDisplayMode (doc);
  TtaOpenUndoSequence (doc, el, el, 0, 0);
  newElem = NULL;
  attrRefimg = NULL;
  newuseMap = NULL;
  newMap = NULL;

  /* lock the table formatting */
  TtaGiveTableFormattingLock (&lock);
  if (!lock)
    /* table formatting is not loked, lock it now */
    TtaLockTableFormatting ();

  oldStructureChecking = TtaGetStructureChecking (doc);
  /* Avoid generation of popup dialog for mandatory attributes */
  TtaSetStructureChecking (FALSE, doc);
  if (elType.ElTypeNum == HTML_EL_PICTURE_UNIT ||
      elType.ElTypeNum == HTML_EL_IMG)
    /* an image is selected. Create an area for it */
    {
      url = (char *)TtaGetMemory (MAX_LENGTH);
      image = el;
      /* Search the USEMAP attribute */
      attrType.AttrSSchema = elType.ElSSchema;
      attrType.AttrTypeNum = HTML_ATTR_USEMAP;
      attr = TtaGetAttribute (image, attrType);
      map = NULL;
      if (attr != NULL)
        {
          /* Search the MAP element associated with IMG element */
          length = TtaGetTextAttributeLength (attr) + 1;
          if (length > MAX_LENGTH)
            length = MAX_LENGTH;
          TtaGiveTextAttributeValue (attr, url, &length);
          map = SearchNAMEattribute (doc, &url[1], NULL, NULL);
        }
      if (map == NULL)
        {
          /* create the MAP element */
          elType.ElTypeNum = HTML_EL_MAP;
          map = TtaNewElement (doc, elType);
          newMap = map;
          newElem = map;
          parent = image;
          do
            {
              el = parent;
              parent = TtaGetParent (el);
              if (parent)
                elType = TtaGetElementType (parent);
            }
          while (parent && elType.ElTypeNum != HTML_EL_BODY &&
                 elType.ElTypeNum != HTML_EL_Division );
          // create a division
          elType.ElTypeNum = HTML_EL_Division;
          div = TtaNewElement (doc, elType);
          TtaInsertSibling (div, el, FALSE, doc);
          TtaInsertFirstChild (&map, div, doc);
          CreateTargetAnchor (doc, map, FALSE, FALSE);
          attrType.AttrTypeNum = HTML_ATTR_NAME;
          attr = TtaGetAttribute (map, attrType);
          if (attr == NULL)
            {
              attrType.AttrTypeNum = HTML_ATTR_ID;
              attr = TtaGetAttribute (map, attrType);
            }
          /* create the USEMAP attribute for the image */
          length = TtaGetTextAttributeLength (attr) + 2;
          if (length > MAX_LENGTH)
            length = MAX_LENGTH;
          profile = TtaGetDocumentProfile (doc);
          if (profile == L_Xhtml11)
            {
              url[0] = EOS;
              TtaGiveTextAttributeValue (attr, &url[0], &length);
            }
          else
            {
              url[0] = '#';
              TtaGiveTextAttributeValue (attr, &url[1], &length);
            }
          attrType.AttrTypeNum = HTML_ATTR_USEMAP;
          attr = TtaGetAttribute (image, attrType);
          if (attr == NULL)
            {
              attr = TtaNewAttribute (attrType);
              newuseMap = attr;
              TtaAttachAttribute (image, attr, doc);
              TtaSetAttributeText (attr, url, image, doc);
              TtaRegisterAttributeCreate (attr, image, doc);
            }
          else
            {
              TtaRegisterAttributeReplace (attr, image, doc);
              TtaSetAttributeText (attr, url, image, doc);
            }
          /* create the Ref_IMG attribute */
          attrType.AttrTypeNum = HTML_ATTR_Ref_IMG;
          attrRefimg = TtaNewAttribute (attrType);
          TtaAttachAttribute (map, attrRefimg, doc);
          TtaSetAttributeReference (attrRefimg, map, doc, image);
        }
      TtaFreeMemory (url);
    }
  else
    /* the selected element is not an image */
    {
      /* is the selection within a MAP element ? */
      if (elType.ElTypeNum == HTML_EL_GRAPHICS_UNIT)
        {
          el = TtaGetParent (el);
          map = TtaGetParent (el);
        }
      else if (elType.ElTypeNum == HTML_EL_AREA)
        map = TtaGetParent (el);
      else if (elType.ElTypeNum == HTML_EL_MAP)
        map = el;
      else
        /* cannot create the AREA */
        map = NULL;
      
      if (map)
        {
          /* Search the Ref_IMG attribute */
          attrType.AttrSSchema = elType.ElSSchema;
          attrType.AttrTypeNum = HTML_ATTR_Ref_IMG;
          attr = TtaGetAttribute (map, attrType);
          image = NULL;
          if (attr)
            /* Search the IMAGE element associated with the MAP */
            TtaGiveReferenceAttributeValue (attr, &image);
        }
    }
  if (!lock)
    /* unlock table formatting */
    TtaUnlockTableFormatting ();
  /* restore the structure checking */
  TtaSetStructureChecking (oldStructureChecking, doc);

  if (map == NULL || image == NULL)
    /* Nothing to do. Just reset display mode */
    TtaSetDisplayMode (doc, dispMode);
  else
    /* Create an AREA element */
    {
      TtaSetStructureChecking (FALSE, doc);
      elType.ElTypeNum = HTML_EL_AREA;
      /* Should we ask the user to give coordinates */
      if (shape[0] == 'R' || shape[0] == 'a')
        TtaAskFirstCreation ();

      el = TtaNewTree (doc, elType, "");
      if (!newElem)
        newElem = el;
      child = TtaGetLastChild (map);
      if (child == NULL)
        TtaInsertFirstChild (&el, map, doc);
      else
        TtaInsertSibling (el, child, FALSE, doc);
      TtaSetStructureChecking (oldStructureChecking, doc);
      child = TtaGetFirstChild (el);
      /* For polygons, sets the value after the Ref_IMG attribute is
         created */
      if (shape[0] != 'p')
        TtaSetGraphicsShape (child, shape[0], doc);

      /* create the shape attribute */
      attrType.AttrTypeNum = HTML_ATTR_shape;
      attrShape = TtaGetAttribute (el, attrType);
      if (attrShape == NULL)
        {
          attrShape = TtaNewAttribute (attrType);
          TtaAttachAttribute (el, attrShape, doc);
        }
      
      /* Create the coords attribute */
      attrType.AttrTypeNum = HTML_ATTR_coords;
      attr = TtaNewAttribute (attrType);
      TtaAttachAttribute (el, attr, doc);
      
      if (shape[0] == 'R')
        TtaSetAttributeValue (attrShape, HTML_ATTR_shape_VAL_rectangle,
                              el, doc);
      else if (shape[0] == 'a')
        TtaSetAttributeValue (attrShape, HTML_ATTR_shape_VAL_circle,
                              el, doc);
      else if (shape[0] == 'p')
        {
          /* create the AreaRef_IMG attribute */
          attrType.AttrTypeNum = HTML_ATTR_AreaRef_IMG;
          attrRef = TtaNewAttribute (attrType);
          TtaAttachAttribute (el, attrRef, doc);
          TtaSetAttributeReference (attrRef, el, doc, image);
          TtaSetAttributeValue (attrShape, HTML_ATTR_shape_VAL_polygon,
                                el, doc);
          TtaGiveBoxSize (image, doc, 1, UnPixel, &w, &h);
          TtaChangeBoxSize (child, doc, 1, w, h, UnPixel);
        }

      /* ask Thot to display changes made in the document */
      TtaSetDisplayMode (doc, dispMode);
      TtaSelectElement (doc, child);
      if (shape[0] == 'p')
        {
          TtcInsertGraph (doc, 1, 'p');
          if (TtaGetElementVolume (child) < 3)
            {
              /* the polyline doesn't have enough points */
              if (newMap)
                TtaDeleteTree (newMap, doc);
              else
                TtaDeleteTree (el, doc);
              TtaCancelLastRegisteredSequence (doc);
              if (!docModified)
                TtaSetDocumentUnmodified (doc);
              TtaSelectElement (doc, image);
              return;
            }
        }
      /* Compute coords attribute */
      SetAreaCoords (doc, el, 0, image);

      /* check the attribute ALT is not allready present 
       * it should surely be allready created because of mandatory attributs auto-creation */
      attrType.AttrTypeNum = HTML_ATTR_ALT;
      attr = TtaGetAttribute (el, attrType);
      if (attr == 0)
        {
          /* create the attribute ALT */
          attrType.AttrTypeNum = HTML_ATTR_ALT;
          attr = TtaNewAttribute (attrType);
          TtaAttachAttribute (el, attr, doc);
          GetAlt (doc, view);
          if (ImgAlt[0] == EOS)
            {
              /* abandon the creation of the area */
              if (newMap)
                TtaDeleteTree (newMap, doc);
              else
                TtaDeleteTree (el, doc);
              TtaCancelLastRegisteredSequence (doc);
              if (!docModified)
                TtaSetDocumentUnmodified (doc);
              TtaSelectElement (doc, image);
              return;
            }
#ifdef _WX
          TtaSetAttributeText (attr, ImgAlt, el, doc);
#else /* _WX */
          utf8value = (char *)TtaConvertByteToMbs ((unsigned char *)ImgAlt,
                                                   TtaGetDefaultCharset ());
          TtaSetAttributeText (attr, utf8value, el, doc);
          TtaFreeMemory (utf8value);
#endif /* _WX */
        }
      ImgAlt[0] = EOS;
      /* The link element is a new created one */
      IsNewAnchor = TRUE;
      /* FrameUpdating creation of Area and selection of destination */
      SelectDestination (doc, el, FALSE, FALSE);
    }
  if (div)
    TtaRegisterElementCreate (div, doc);
  else if (newElem)
    TtaRegisterElementCreate (newElem, doc);
  /* if a map has been created, register its Ref_IMG attribute to
     avoid troubles when Undoing the command: function DeleteMap
     would delete the USEMAP attribute from the IMG otherwise.
     Undo already deletes this attribute! */
  if (attrRefimg)
    TtaRegisterAttributeCreate (attrRefimg, map, doc);
  TtaCloseUndoSequence (doc);
}

/*----------------------------------------------------------------------
  ----------------------------------------------------------------------*/
void CreateAreaRect (Document doc, View view)
{
  CreateAreaMap (doc, view, "R");
}

/*----------------------------------------------------------------------
  ----------------------------------------------------------------------*/
void CreateAreaCircle (Document doc, View view)
{
  CreateAreaMap (doc, view, "a");
}

/*----------------------------------------------------------------------
  ----------------------------------------------------------------------*/
void CreateAreaPoly (Document doc, View view)
{
  CreateAreaMap (doc, view, "p");
}

/*----------------------------------------------------------------------
  GetImageURL initializes the Picture form.
  Returns the url (encoded with the Default charset).
  Check if there is an alternate text when loading an image.
  ----------------------------------------------------------------------*/
static char *GetImageURL (Document document, View view,
                          ThotBool isObject, ThotBool isInput)
{
#if defined(_GTK) || defined(_WX)
  LoadedImageDesc   *desc;
  char               tempfile[MAX_LENGTH];
  char               s[MAX_LENGTH];
#endif /* _GTK || _WX */
#ifdef _GTK
  int                i;
#endif /* _GTK */

  if (isObject)
    RefFormImage = BaseImage + FormObject;
  else
    RefFormImage = BaseImage + FormImage;
#ifdef _WX
  if (LastURLImage[0] == EOS)
    {
      TtaExtractName (DocumentURLs[document], LastURLImage, s);
      strcat (LastURLImage, DIR_STR);
      if (isObject)
        strcat (LastURLImage, "object.svg");
      else
        strcat (LastURLImage, "img.png");
    }
#else /* _WX */
  if (LastURLImage[0] == EOS)
    {
      strcpy (LastURLImage, DirectoryImage);
      strcat (LastURLImage, DIR_STR);
      strcat (LastURLImage, ImageName);
    }
#endif /* _WX */

#ifdef _GTK
  /* Dialogue form for open URL or local */
  i = 0;
  strcpy (&s[i], TtaGetMessage (LIB, TMSG_LIB_CONFIRM));
  i += strlen (&s[i]) + 1;
  strcpy (&s[i], TtaGetMessage (AMAYA, AM_CLEAR));
  i += strlen (&s[i]) + 1;
  strcpy (&s[i], TtaGetMessage (AMAYA, AM_PARSE));
  TtaNewSheet (RefFormImage, TtaGetViewFrame (document, view),
               TtaGetMessage (LIB, TMSG_BUTTON_IMG),
               3, s, TRUE, 2, 'L', D_CANCEL);
  TtaNewTextForm (BaseImage + ImageURL, RefFormImage,
                  TtaGetMessage (LIB, TMSG_BUTTON_IMG), 50, 1, FALSE);
  TtaNewLabel (BaseImage + ImageLabel, RefFormImage, " ");
  if (isObject)
    /* not ALT attribute for objects */
    TtaNewLabel (BaseImage + ImageAlt, RefFormImage, " ");
  else
    {
      TtaNewTextForm (BaseImage + ImageAlt, RefFormImage,
                      TtaGetMessage (AMAYA, AM_ALT), 50, 1, TRUE);
    }
  TtaNewLabel (BaseImage + ImageLabel2, RefFormImage, " ");
  TtaListDirectory (DirectoryImage, RefFormImage,
                    TtaGetMessage (AMAYA, AM_IMAGES_LOCATION),
                    BaseImage + ImageDir, ImgFilter,
                    TtaGetMessage (AMAYA, AM_FILES), BaseImage + ImageSel);
  TtaSetTextForm (BaseImage + ImageURL, LastURLImage);
  TtaSetTextForm (BaseImage + ImageAlt, ImgAlt);
  TtaNewTextForm (BaseImage + ImageFilter, RefFormImage,
                  TtaGetMessage (AMAYA, AM_PARSE), 10, 1, TRUE);
  TtaSetTextForm (BaseImage + ImageFilter, ImgFilter);
  TtaNewLabel (BaseImage + ImageLabel3, RefFormImage, " ");
  TtaNewLabel (BaseImage + ImageLabel4, RefFormImage, " ");
#endif /* _GTK */

#ifdef _WX
  if (isObject)
    CreateObjectDlgWX (RefFormImage, TtaGetViewFrame (document, view),
                       TtaGetMessage (AMAYA, AM_NEWOBJECT),
                       LastURLImage, UserMimeType);
  else if (isInput)
    CreateImageDlgWX (RefFormImage, TtaGetViewFrame (document, view),
                      TtaGetMessage (THOT, BImageInput),
                      LastURLImage, ImgAlt);
  else
    CreateImageDlgWX (RefFormImage, TtaGetViewFrame (document, view),
                      TtaGetMessage (LIB, TMSG_BUTTON_IMG),
                      LastURLImage, ImgAlt);
#endif /* _WX */

#if defined(_GTK) || defined(_WX)
  TtaSetDialoguePosition ();
  TtaShowDialogue (RefFormImage, FALSE);
  TtaWaitShowDialogue ();
  if (IsHTTPPath (DocumentURLs[document]) && !IsHTTPPath (LastURLImage))
    {
      /*
        load a local image into a remote document 
        copy image file into the temporary directory of the document
      */
      TtaExtractName (LastURLImage, tempfile, s);
      if (s[0] == EOS)
        return (LastURLImage);
      else
        {
          NormalizeURL (s, document, tempfile, ImageName, NULL);
          AddLoadedImage (ImageName, tempfile, document, &desc);
          desc->status = IMAGE_MODIFIED;
          TtaFileCopy (LastURLImage, desc->localName);
          return (ImageName);
        }
    }
#endif /* _GTK || _WX */

#ifdef _WINGUI
  CreateOpenImgDlgWindow (TtaGetViewFrame (document, view), LastURLImage, -1,
                          -1, docImage, !isObject);
#endif /* _WINGUI */

  return (LastURLImage);
}


/*----------------------------------------------------------------------
  ChangeBackgroundImage
  display a form to set or change the background image
  -----------------------------------------------------------------------*/
void ChangeBackgroundImage (Document document, View view)
{
#ifndef _WX
  char           *s = (char *)TtaGetMemory (MAX_LENGTH);
#ifdef _GTK
  int             i;

  /* there is a selection */
  i = 0;
  strcpy (&s[i], TtaGetMessage (LIB, TMSG_LIB_CONFIRM));
  i += strlen (&s[i]) + 1;
  strcpy (&s[i], TtaGetMessage (AMAYA, AM_CLEAR));
  i += strlen (&s[i]) + 1;
  strcpy (&s[i], TtaGetMessage (AMAYA, AM_PARSE));
  RefFormImage = BaseImage + FormBackground;
  TtaNewSheet (RefFormImage, TtaGetViewFrame(document, view),
               TtaGetMessage (AMAYA, AM_BACKGROUND_IMAGE), 3, s, TRUE, 2,
               'L', D_CANCEL);
  TtaNewTextForm (BaseImage + ImageURL, RefFormImage,
                  TtaGetMessage (AMAYA, AM_BACKGROUND_IMAGE), 50, 1, TRUE);
  TtaNewLabel (BaseImage + ImageLabel, RefFormImage, " ");
  TtaListDirectory (DirectoryImage, RefFormImage,
                    TtaGetMessage (LIB, TMSG_DOC_DIR),
                    BaseImage + ImageDir, ImgFilter,
                    TtaGetMessage (AMAYA, AM_FILES), BaseImage + ImageSel);
  if (LastURLImage[0] != EOS)
    TtaSetTextForm (BaseImage + ImageURL, LastURLImage);
  else
    {
      strcpy (s, DirectoryImage);
      strcat (s, DIR_STR);
      strcat (s, ImageName);
      TtaSetTextForm (BaseImage + ImageURL, s);
    }

  TtaNewTextForm (BaseImage + ImageFilter, RefFormImage,
                  TtaGetMessage (AMAYA, AM_PARSE), 10, 1, TRUE);
  TtaSetTextForm (BaseImage + ImageFilter, ImgFilter);
  /* selector for repeat mode */
  i = 0;
  sprintf (&s[i], "%s%s", "B", TtaGetMessage (AMAYA, AM_REPEAT));
  i += strlen (&s[i]) + 1;
  sprintf (&s[i], "%s%s", "B", TtaGetMessage (AMAYA, AM_REPEAT_X));
  i += strlen (&s[i]) + 1;
  sprintf (&s[i], "%s%s", "B", TtaGetMessage (AMAYA, AM_REPEAT_Y));
  i += strlen (&s[i]) + 1;
  sprintf (&s[i], "%s%s", "B", TtaGetMessage (AMAYA, AM_NO_REPEAT));
  TtaNewSubmenu (BaseImage + RepeatImage, RefFormImage, 0,
                 TtaGetMessage (AMAYA, AM_REPEAT_MODE), 4, s, NULL, 0, FALSE);
  TtaSetMenuForm (BaseImage + RepeatImage, RepeatValue);
  /* save the document concerned */
  ImgDocument = document;
  TtaSetDialoguePosition ();
  TtaShowDialogue (RefFormImage, TRUE);
#endif /* _GTK */

#ifdef _WINGUI
  if (LastURLImage[0] != EOS)
    strcpy (s, LastURLImage);
  else {
    strcpy (s, DirectoryImage);
    strcat (s, DIR_STR);
    strcat (s, ImageName);
  }
  ImgDocument = document;
  CreateBackgroundImageDlgWindow (TtaGetViewFrame (document, view), s);
#endif /* _WINGUI */
  TtaFreeMemory (s);
#endif /* _WX */
}


/*----------------------------------------------------------------------
  ComputeSRCattribute generates the value of the src attribute of element
  el if it's a HTML img, or the xlink:href attribute if it's a SVG image.
  doc the document to which el belongs.
  sourceDocument is the document where the image comes from.
  attr is the src or xlink:href attribute that has to be updated.
  text is the image name (relative or not) and utf-8 encoded.
  ----------------------------------------------------------------------*/
void ComputeSRCattribute (Element el, Document doc, Document sourceDocument,
                          Attribute attr, char *text)
{
  Element            pict;
  ElementType        elType;
  LoadedImageDesc   *desc;
  Attribute          srcattr = NULL;
  AttributeType      attrType;
  char              *value, *base;
  char               pathimage[MAX_LENGTH];
  char               localname[MAX_LENGTH];
  char               imagename[MAX_LENGTH];
  ThotBool           newPict, newAttr;

  elType = TtaGetElementType (el);
  attrType.AttrSSchema = elType.ElSSchema;
  attrType.AttrTypeNum = HTML_ATTR_SRC;

  newPict = FALSE;
  newAttr =  FALSE;
  if (elType.ElTypeNum == HTML_EL_PICTURE_UNIT)
    /* it's a Thot picture element */
    pict = el;
  else
    {
      elType.ElTypeNum = HTML_EL_PICTURE_UNIT;
      pict = TtaSearchTypedElement (elType, SearchInTree, el);
      if (!pict)
        {
          /* no Thot picture element. Create one */
          pict = TtaNewTree (doc, elType, "");
          TtaInsertFirstChild (&pict, el, doc);
          newPict = TRUE;
        }
    }
  // get the src or data attribute
  srcattr = TtaGetAttribute (pict, attrType);
  if (srcattr == NULL)
    {
      newAttr = TRUE;
      srcattr = TtaNewAttribute (attrType);
      TtaAttachAttribute (pict, srcattr, doc);
    }

  /* get the absolute URL of the image */
  NormalizeURL (text, sourceDocument, pathimage, imagename, NULL);
  if (IsHTTPPath (DocumentURLs[doc]))
    {
      /* remote target document */
      if (!IsHTTPPath (pathimage))
        {
          /* loading a local image into a remote document */
          /* copy image file into the temporary directory of the document */
          TtaExtractName (pathimage, localname, imagename);
          NormalizeURL (imagename, doc, localname, imagename, NULL);
          AddLoadedImage (imagename, localname, doc, &desc);
          desc->status = IMAGE_MODIFIED;
          if (TtaFileExist (pathimage))
            /* it's a paste command */
            TtaFileCopy (pathimage, desc->localName);
          else if (LastURLImage && TtaFileExist (LastURLImage) &&
                   desc->localName && !TtaFileExist (desc->localName))
            /* it's a new inserted image */
            TtaFileCopy (LastURLImage, desc->localName);
          desc->tempfile = TtaStrdup (desc->localName);
          /* suppose that the image will be stored in the same directory */
          TtaSetAttributeText (attr, imagename, el, doc);
          // update the src of the PICTURE element
          if (srcattr)
            TtaSetAttributeText (srcattr, imagename, pict, doc);
          /* set contents of the picture element */
          TtaSetTextContent (pict, (unsigned char *)desc->tempfile, SPACE, doc);
          DisplayImage (doc, pict, desc, NULL, NULL);
        }
      else
        {
          /* load a remote image into a remote document */
          base = GetBaseURL (doc);
          value = MakeRelativeURL (pathimage, base);
          TtaSetAttributeText (attr, value, el, doc);
          // update the src of the PICTURE element
          if (srcattr)
            TtaSetAttributeText (srcattr, value, pict, doc);
          TtaFreeMemory (base);
          TtaFreeMemory (value);
          /* set stop button */
          ActiveTransfer (doc);
          FetchImage (doc, pict, NULL, 0, NULL, NULL);
          ResetStop (doc);
        }
    }
  else
    {
      /* local target document */
      NormalizeURL (text, sourceDocument, pathimage, imagename, NULL);
      if (!IsHTTPPath (pathimage))
        {
          /* load a local image into a local document */
          base = GetBaseURL (doc);
          value = MakeRelativeURL (pathimage, base);
          TtaSetAttributeText (attr, value, el, doc);
          // update the src of the PICTURE element
          if (srcattr)
            TtaSetAttributeText (srcattr, value, pict, doc);
          /* set and display the element content */
          DisplayImage (doc, pict, NULL, pathimage, NULL);
          TtaFreeMemory (base);
          TtaFreeMemory (value);
          /*TtaSetTextContent (pict, (unsigned char *)pathimage, SPACE, doc);*/
        }
      else
        {
          /* load a remote image into a local document */
          /* set stop button */
          ActiveTransfer (doc);
          TtaSetAttributeText (attr, pathimage, el, doc);
          // update the src of the PICTURE element
          if (srcattr)
            TtaSetAttributeText (srcattr, pathimage, pict, doc);
          FetchImage (doc, pict, NULL, 0, NULL, NULL);
          ResetStop (doc);
        }
    }
  if (newPict)
    ;
  else if (newAttr)
    TtaRegisterAttributeCreate (srcattr, pict, doc);
  else
    TtaRegisterAttributeReplace (srcattr, pict, doc);
}


/*----------------------------------------------------------------------
  UpdateSRCattribute  creates or updates the SRC attribute value	
  when the contents of element IMG is set.		
  ----------------------------------------------------------------------*/
void UpdateSRCattribute (NotifyOnTarget *event)
{
  AttributeType    attrType;
  Attribute        attr;
  Element          elSRC, el, child, next;
  ElementType      elType;
  Document         doc;
  DisplayMode      dispMode;
  char            *text;
  char            *utf8value;
  int              length;
  ThotBool         newAttr, isObject = FALSE, isInput = FALSE;

  el = event->element;
  doc = event->document;
  elType = TtaGetElementType (el);
  isInput = (elType.ElTypeNum == HTML_EL_Image_Input);
  isObject = (elType.ElTypeNum == HTML_EL_Object);
  attrType.AttrSSchema = elType.ElSSchema;
  /* if it's not an HTML picture (it could be an SVG image for instance),
     ignore */
  if (strcmp (TtaGetSSchemaName (elType.ElSSchema), "HTML"))
    return;
  if (elType.ElTypeNum == HTML_EL_PICTURE_UNIT)
    {
      elSRC = TtaGetParent (el);
      elType = TtaGetElementType (elSRC);
      isObject = (elType.ElTypeNum == HTML_EL_Object);
      isInput = (elType.ElTypeNum == HTML_EL_Image_Input);
      el = elSRC;
    }
  else
    elSRC = el;

  /* ask Thot to stop displaying changes made in the document */
  dispMode = TtaGetDisplayMode (doc);
  if (isObject)
    {
      /* get the current mime-type */
      attrType.AttrTypeNum = HTML_ATTR_Object_type;
      attr = TtaGetAttribute (elSRC, attrType);
      if (attr)
        {
          length = TtaGetTextAttributeLength (attr);
          utf8value = (char *)TtaGetMemory (length + 1);
          TtaGiveTextAttributeValue (attr, utf8value, &length);
          text = (char *)TtaConvertByteToMbs ((unsigned char *)utf8value,
                                              TtaGetDefaultCharset ());
          TtaFreeMemory (utf8value);
          strcpy (UserMimeType, text);
          TtaFreeMemory (text);
        }
    }
  else
    {
      /* get the current value of ALT */
      attrType.AttrTypeNum = HTML_ATTR_ALT;
      attr = TtaGetAttribute (el, attrType);
      if (attr)
        {
          length = TtaGetTextAttributeLength (attr);
          utf8value = (char *)TtaGetMemory (length + 1);
          TtaGiveTextAttributeValue (attr, utf8value, &length);
#ifdef _WX
          strcpy (ImgAlt, utf8value);
#else /* _WX */
          text = (char *)TtaConvertByteToMbs ((unsigned char *)utf8value,
                                              TtaGetDefaultCharset ());
          strcpy (ImgAlt, text);
          TtaFreeMemory (text);
#endif /* _WX */
          TtaFreeMemory (utf8value);
        }
    }

  /* Select an image name */
  text = GetImageURL (doc, 1, isObject, isInput);
  if (text == NULL || text[0] == EOS)
    /* The user has cancelled */
    {
      if (CreateNewImage)
        {
          /* We were creating a new image. Delete the empty PICTURE element */
          TtaCloseUndoSequence (doc);
          TtcUndo (doc, 1);
        }
      return;
    }

  if (isObject)
    {
      /* copy mime-type attribute */
      if (UserMimeType[0] != EOS)
        {
          attrType.AttrTypeNum = HTML_ATTR_Object_type;
          attr = TtaGetAttribute (elSRC, attrType);
          if (attr == 0)
            {
              newAttr = TRUE;
              attr = TtaNewAttribute (attrType);
              TtaAttachAttribute (elSRC, attr, doc);
            }
          else
            newAttr = FALSE;
          utf8value = (char *)TtaConvertByteToMbs ((unsigned char *)UserMimeType,
                                                   TtaGetDefaultCharset ());
          TtaSetAttributeText (attr, utf8value, elSRC, doc);
          TtaFreeMemory (utf8value);
          if (!CreateNewImage)
            {
              if (newAttr)
                TtaRegisterAttributeCreate (attr, elSRC, doc);
              else
                TtaRegisterAttributeReplace (attr, elSRC, doc);
            }
        }
      TtaSetDisplayMode (doc, NoComputedDisplay);
    }
  else
    {
      if (dispMode == DisplayImmediately)
        TtaSetDisplayMode (doc, DeferredDisplay);
      /* add the ALT attribute */
      attrType.AttrTypeNum = HTML_ATTR_ALT;
      attr = TtaGetAttribute (elSRC, attrType);
      if (attr == NULL)
        {
          newAttr = TRUE;
          attr = TtaNewAttribute (attrType);
          TtaAttachAttribute (elSRC, attr, doc);
        }
      else
        newAttr = FALSE;
      /* copy image name in ALT attribute */
      if (ImgAlt[0] != EOS)
        {
#ifdef _WX
          TtaSetAttributeText (attr, ImgAlt, elSRC, doc);
#else /* _WX */
          utf8value = (char *)TtaConvertByteToMbs ((unsigned char *)ImgAlt,
                                                   TtaGetDefaultCharset ());
          TtaSetAttributeText (attr, utf8value, elSRC, doc);
          TtaFreeMemory (utf8value);
#endif /* _WX */
        }
      if (!CreateNewImage)
        {
          if (newAttr)
            TtaRegisterAttributeCreate (attr, elSRC, doc);
          else
            TtaRegisterAttributeReplace (attr, elSRC, doc);
        }
    }

  /* search the SRC attribute */
  if (elType.ElTypeNum == HTML_EL_Object)
    attrType.AttrTypeNum = HTML_ATTR_data;
  else
    attrType.AttrTypeNum = HTML_ATTR_SRC;
  attr = TtaGetAttribute (el, attrType);
  if (attr == NULL)
    {
      newAttr = TRUE;
      attr = TtaNewAttribute (attrType);
      TtaAttachAttribute (el, attr, doc);
    }
  else
    newAttr = FALSE;
#ifdef _WX
  ComputeSRCattribute (el, doc, 0, attr, text);
#else /* _WX */
  utf8value = (char *)TtaConvertByteToMbs ((unsigned char *)text,
                                           TtaGetDefaultCharset ());
  ComputeSRCattribute (el, doc, 0, attr, utf8value);
  TtaFreeMemory (utf8value);
#endif /* _WX */

  if (!CreateNewImage)
    {
      attr = TtaGetAttribute (elSRC, attrType);
      if (attr)
        {
          // check if the attribute is still there
          if (newAttr)
            TtaRegisterAttributeCreate (attr, elSRC, doc);
          else
            TtaRegisterAttributeReplace (attr, elSRC, doc);
        }
    }
  /* generate an ALT content */
  if (isObject)
    {
      // get the Object_content
      el = TtaGetFirstChild (elSRC);
      if (el)
        child = TtaGetFirstChild (el);
      else
        child = NULL;
      elType = TtaGetElementType (child);
      if (child && elType.ElSSchema &&
          !strcmp (TtaGetSSchemaName (elType.ElSSchema), "SVG"))
        {
#ifdef _SVG
          AttributeType wType, hType;
          Attribute     wAttr, hAttr;

          // check if the SVG has a width attribute
          wType.AttrSSchema = elType.ElSSchema;
          wType.AttrTypeNum = SVG_ATTR_width_;
          wAttr = TtaGetAttribute (child, wType);
          if (wAttr)
            {
              length = TtaGetTextAttributeLength (wAttr);
              text = (char *)TtaGetMemory (length + 1);
              TtaGiveTextAttributeValue (wAttr, text, &length);
              if (strstr (text, "%"))
                // a width attribute should be generated
                wAttr = NULL;
              TtaFreeMemory (text);
            }
          if (wAttr == NULL)
            {
              // attach a width to the object
              elType = TtaGetElementType (elSRC);
              wType.AttrSSchema = elType.ElSSchema;
              wType.AttrTypeNum = HTML_ATTR_Width__;
              attr = TtaNewAttribute (wType);
              TtaAttachAttribute (elSRC, attr, doc);
              TtaSetAttributeText (attr, "50", elSRC, doc);
            }
          // check if the SVG has a width attribute
          hType.AttrSSchema = elType.ElSSchema;
          hType.AttrTypeNum = SVG_ATTR_height_;
          hAttr = TtaGetAttribute (child, hType);
          if (hAttr)
            {
              length = TtaGetTextAttributeLength (hAttr);
              text = (char *)TtaGetMemory (length + 1);
              TtaGiveTextAttributeValue (hAttr, text, &length);
              if (strstr (text, "%"))
                // a width attribute should be generated
                hAttr = NULL;
              TtaFreeMemory (text);
            }
          if (hAttr == NULL)
            {
              // attach a width to the object
              elType = TtaGetElementType (elSRC);
              hType.AttrSSchema = elType.ElSSchema;
              hType.AttrTypeNum = HTML_ATTR_Height_;
              attr = TtaNewAttribute (hType);
              TtaAttachAttribute (elSRC, attr, doc);
              TtaSetAttributeText (attr, "50", elSRC, doc);
            }
          if (hAttr == NULL)
            {
              if (wAttr == NULL)
                {
                  // update but not redisplay
                  CreateAttrWidthPercentPxl ("50", elSRC, doc, 0);
                  CreateAttrHeightPercentPxl ("50", elSRC, doc, -1);
                }
              else if (wAttr == NULL)
                // update and redisplay
                CreateAttrHeightPercentPxl ("50", elSRC, doc, 0);
              TtaSelectElement (doc, elSRC);
            }
#endif /* _SVG */
        }
      if (ImgAlt[0] != EOS && el)
        {
          // generate the Alternate text
          next = el;
          elType = TtaGetElementType (el);
          TtaNextSibling (&next);
          if (next)
            // there is an Object_Content
            el = TtaGetFirstChild (next);
          else
            {
              // create the Object_Content
              elType.ElTypeNum = HTML_EL_Object_Content;
              next = TtaNewElement (doc, elType);
              TtaInsertSibling (el, next, FALSE, doc);
              el = next;
              elType.ElTypeNum = HTML_EL_ElemOrParam;
              next = TtaNewElement (doc, elType);
              TtaInsertFirstChild (&next, el, doc);
              el = next;
            }

          // insert a pseudo paragraph
          elType.ElTypeNum = HTML_EL_Pseudo_paragraph;
          next = TtaNewElement (doc, elType);
          TtaInsertFirstChild (&next, el, doc);
          // insert the alternate text
          elType.ElTypeNum = HTML_EL_TEXT_UNIT;
          child = TtaNewElement (doc, elType);
          TtaInsertFirstChild (&child, next, doc);
          TtaSetTextContent (child, (unsigned char*)ImgAlt,
                             TtaGetDefaultCharset (), doc);
        }
    }
  /* ask Thot to display changes made in the document */
  TtaSetDisplayMode (doc, dispMode);
}


/*----------------------------------------------------------------------
  SvgImageCreated
  The user is creating an SVG image. Ask for the mandatory attributes
  and associate them with the new image.
  ----------------------------------------------------------------------*/
void SvgImageCreated (NotifyElement *event)
{
  AttributeType      attrType;
  Attribute          attr;
  ElementType        elType;
  Element            el, desc, leaf;
  Document           doc;
#ifndef _WX
  char              *utf8value;
#endif /* _WX */
  char              *text;
  char              *pathimage;
  char              *imagename;

  el = event->element;
  doc = event->document;
  /* display the Image form and get the user feedback */
  text = GetImageURL (doc, 1, FALSE, FALSE);
  if (text == NULL || text[0] == EOS)
    {
      /* delete the empty image element */
      TtaDeleteTree (el, doc);
      return;
    }
  elType = TtaGetElementType (el);
  /* set the desc child */
  elType.ElTypeNum = SVG_EL_desc;
  desc = TtaSearchTypedElement (elType, SearchInTree, el);
  if (!desc)
    {
      desc = TtaNewTree (doc, elType, "");
      TtaInsertFirstChild (&el, desc, doc);
    }
  leaf = TtaGetFirstChild (desc);
  if (ImgAlt[0] == EOS)
    /* The user has not provided any alternate name. Copy the image name in
       the desc element */
    {
      imagename = (char *)TtaGetMemory (MAX_LENGTH);
      pathimage = (char *)TtaGetMemory (MAX_LENGTH);
      strcpy (imagename, " ");
      TtaExtractName (text, pathimage, &imagename[1]);
      strcat (imagename, " ");
      /* set the element content */
      TtaSetTextContent (leaf, (unsigned char *)imagename, SPACE, doc);
      TtaFreeMemory (pathimage);
      TtaFreeMemory (imagename);
    }
  else
    {
#ifdef _WX
      TtaSetTextContent (leaf, (unsigned char *)ImgAlt, SPACE, doc);
#else /* _WX */
      utf8value = (char *)TtaConvertByteToMbs ((unsigned char *)ImgAlt,
                                               TtaGetDefaultCharset ());
      TtaSetTextContent (leaf, (unsigned char *)utf8value, SPACE, doc);
      TtaFreeMemory (utf8value);
#endif /* _WX */
      ImgAlt[0] = EOS;
    }
  /* search the xlink:href attribute */
  attrType.AttrSSchema = elType.ElSSchema;
  attrType.AttrTypeNum = SVG_ATTR_xlink_href;
  attr = TtaGetAttribute (el, attrType);
  if (attr == 0)
    {
      attr = TtaNewAttribute (attrType);
      TtaAttachAttribute (el, attr, doc);
    }
  ComputeSRCattribute (el, doc, 0, attr, text);
}


/*----------------------------------------------------------------------
  SRCattrModified updates the contents of element IMG according   
  to the new value of attribute SRC.                      
  ----------------------------------------------------------------------*/
void  SRCattrModified (NotifyAttribute *event)
{
  Element          el, pict, child;
  ElementType      elType;
  Attribute        attr;
  Document         doc;
  int              length;
  char            *value, *buf2;
  char            *localname, *imageName;
  LoadedImageDesc *desc;

  doc = event->document;
  el = event->element;
  attr = event->attribute;
  pict = NULL;
  /* get the PICTURE_UNIT child of element el */
  elType = TtaGetElementType (el);
  if (elType.ElTypeNum == HTML_EL_PICTURE_UNIT)
    pict = el;
  else
    for (child = TtaGetFirstChild (el); child && !pict; TtaNextSibling (&child))
      {
        elType = TtaGetElementType (child);
        if (elType.ElTypeNum == HTML_EL_PICTURE_UNIT)
          pict = child;
      }
  /* get a buffer for the attribute value */
  length = MAX_LENGTH;
  value = (char *)TtaGetMemory (length);
  buf2 = (char *)TtaGetMemory (length);
  imageName = (char *)TtaGetMemory (length);
  /* copy the SRC attribute into the buffer */
  TtaGiveTextAttributeValue (attr, value, &length);
  NormalizeURL (value, doc, buf2, imageName, NULL);
  /* extract image name from full name */
  TtaExtractName (buf2, value, imageName);
  if (strlen (imageName) != 0)
    {
      if (IsHTTPPath (buf2))
        {
          /* remote image */
          localname = GetLocalPath (doc, buf2);
          /* load a remote image into a remote document */
          TtaSetTextContent (pict, (unsigned char *)localname, SPACE, doc);
          TtaFreeMemory (localname);
          ActiveTransfer (doc);
          FetchImage (doc, pict, NULL, 0, NULL, NULL);
          ResetStop (doc);
        }
      else
        {
          /* local image */
          if (IsHTTPPath (DocumentURLs[doc]))
            {
              NormalizeURL (imageName, doc, value, imageName, NULL);
              /* loading a local image into a remote document */
              AddLoadedImage (imageName, value, doc, &desc);
              desc->status = IMAGE_MODIFIED;
              TtaFileCopy (buf2, desc->localName);
              TtaSetTextContent (pict, (unsigned char *)desc->localName, SPACE, doc);
            }
          else
            /* load a local image into a local document */
            TtaSetTextContent (pict, (unsigned char *)buf2, SPACE, doc);
        }
    }
  TtaFreeMemory (value);
  TtaFreeMemory (buf2);
  TtaFreeMemory (imageName);
}

/*----------------------------------------------------------------------
  CreateObject
  ----------------------------------------------------------------------*/
void  CreateObject (Document doc, View view)
{
  ElementType         elType;

  if (HTMLelementAllowed (doc))
    {
      /* Don't check mandatory attributes */
      TtaSetStructureChecking (FALSE, doc);
      ImgAlt[0] = EOS;
      UserMimeType[0] = EOS;
      ImgDocument = doc;
      CreateNewImage = TRUE;
      elType.ElSSchema = TtaGetSSchema ("HTML", doc);
      elType.ElTypeNum = HTML_EL_Object;
      TtaInsertElement (elType, doc);
      /* Check the Thot abstract tree against the structure schema. */
      TtaSetStructureChecking (TRUE, doc);
      CreateNewImage = FALSE;
    }
}

/*----------------------------------------------------------------------
  AddNewImage
  ----------------------------------------------------------------------*/
void AddNewImage (Document doc, View view, ThotBool isInput)
{
  Element            firstSelEl, lastSelEl, parent, leaf, el;
  ElementType        elType;
  Attribute          attr;
  AttributeType      attrType;
  NotifyOnTarget     event;
  char              *name, *value;
  int                c1, i, j, cN, length, width, height, w, h;
  ThotBool           oldStructureChecking, newAttr;

  TtaGiveFirstSelectedElement (doc, &firstSelEl, &c1, &i); 
  if (firstSelEl == NULL)
    /* no selection */
    TtaDisplaySimpleMessage (CONFIRM, AMAYA, AM_NO_INSERT_POINT);
  else
    /* some element is selected */
    {
      ImgDocument = doc;
      TtaGiveLastSelectedElement (doc, &lastSelEl, &j, &cN);
      /* Get the type of the first selected element */
      elType = TtaGetElementType (firstSelEl);
      name = TtaGetSSchemaName (elType.ElSSchema);
      if (!strcmp (name, "HTML") &&
          ((!isInput && elType.ElTypeNum == HTML_EL_IMG) ||
           (isInput && elType.ElTypeNum == HTML_EL_Image_Input)) &&
          c1 == 0 && i == 0 && lastSelEl == firstSelEl)
        /* the first selected element is an HTML <img>, it is fully selected
           and only this element is selected */
        /* The user wants to replace an existing <img> */
        {
          /* get the value of the current src attribute for this image
             to initialize the image dialogue box */
          attrType.AttrSSchema = elType.ElSSchema;
          attrType.AttrTypeNum = HTML_ATTR_SRC;
          attr = TtaGetAttribute (firstSelEl, attrType);
          if (attr)
            {
              length = TtaGetTextAttributeLength (attr) + 1;
              if (length <= MAX_LENGTH)
                {
                  /* not too large URI: initialize the default URI */
                  length = MAX_LENGTH;
                  /* get a buffer for the attribute value */
                  value = (char *)TtaGetMemory (length);
                  /* copy the SRC attribute into the buffer */
                  TtaGiveTextAttributeValue (attr, value, &length);
                  name = (char *)TtaConvertMbsToByte ((unsigned char *)value,
                                                      TtaGetDefaultCharset ());
                  TtaFreeMemory (value);
                  value = name;
                  name = (char *)TtaGetMemory (MAX_LENGTH);
                  NormalizeURL (value, doc, LastURLImage, name, NULL);
                  TtaFreeMemory (value);
                  TtaFreeMemory (name);
#ifdef IV
                  if (!IsHTTPPath (LastURLImage))
                    {
                      /* extract directory and file names */
                      TtaExtractName (LastURLImage, DirectoryImage, ImageName);
                      LastURLImage[0] = EOS;
                    }
#endif
                }
            }

          /* get the value of the current ALT attribute for this image
             to initialize the image dialogue box */
          attrType.AttrTypeNum = HTML_ATTR_ALT;
          attr = TtaGetAttribute (firstSelEl, attrType);
          if (attr)
            {
              length = TtaGetTextAttributeLength (attr) + 1;
              if (length <= MAX_LENGTH)
                {
#ifdef _WX
                  TtaGiveTextAttributeValue (attr, ImgAlt, &length);
#else /* _WX */
                  /* get a buffer for the attribute value */
                  value = (char *)TtaGetMemory (length);
		              /* copy the ALT attribute into the buffer */
                  TtaGiveTextAttributeValue (attr, value, &length);
                  name = (char *)TtaConvertMbsToByte ((unsigned char *)value,
                                                      TtaGetDefaultCharset ());
                  strncpy (ImgAlt, name, MAX_LENGTH-1);
                  TtaFreeMemory (value);
                  TtaFreeMemory (name);
#endif /* _WX */
                }
            }
          /* display the image dialogue box */
          event.element = firstSelEl;
          event.document = doc;
          CreateNewImage = FALSE;
          TtaOpenUndoSequence (doc, firstSelEl, lastSelEl, c1, cN);
          UpdateSRCattribute (&event);
          TtaCloseUndoSequence(doc);
          TtaSetDocumentModified (doc);
        }
      else
        /* the user want to insert a new image */
        {
          CreateNewImage = TRUE;
          if (!strcmp (name, "SVG"))
            {
#ifdef _SVG
              elType.ElTypeNum = SVG_EL_image;
              TtaCreateElement (elType, doc);
#endif /* _SVG */
            }
          else if (!strcmp (name, "HTML"))
            {
              /* if the selected element is empty and is not supposed to
                 contain text directly, create a pseudo paragraph as a child
                 of the selected element and as a parent of the image. */
              if (firstSelEl == lastSelEl &&
                  TtaGetElementVolume (firstSelEl) == 0 &&
                  (elType.ElTypeNum == HTML_EL_Element ||
                   XhtmlCannotContainText (elType)))
                {
                  TtaOpenUndoSequence (doc, firstSelEl, lastSelEl, c1, cN);
                  if (elType.ElTypeNum == HTML_EL_Element)
                    TtaRegisterElementDelete (firstSelEl, doc);
                  elType.ElTypeNum = HTML_EL_Pseudo_paragraph;
                  parent = TtaNewTree (doc, elType, "");
                  TtaInsertFirstChild (&parent, firstSelEl, doc);
                  TtaRegisterElementCreate (parent, doc);
                  leaf = TtaGetFirstLeaf (parent);
                  TtaSelectElement (doc, leaf);
                }
              if (isInput)
                elType.ElTypeNum = HTML_EL_Image_Input;
              else
                elType.ElTypeNum = HTML_EL_IMG;
              /* do not check mandatory attributes */
              oldStructureChecking = TtaGetStructureChecking (doc);
              TtaSetStructureChecking (FALSE, doc);
              TtaCreateElement (elType, doc);

              // check if the width, height attributes must be generated
              TtaGiveFirstSelectedElement (doc, &el, &c1, &i); 
              elType = TtaGetElementType (el);
              if (elType.ElTypeNum == HTML_EL_PICTURE_UNIT)
                el = TtaGetParent (el);
              attrType.AttrSSchema = elType.ElSSchema;
              /* search informations about height and width */
              width = 0; height = 0;
              TtaGivePictureSize (el, &width, &height);
              if (width > 0 && height > 0)
                {
                  /* attach height and width attributes to the image */
                  TtaExtendUndoSequence (doc);
                  value = (char *)TtaGetMemory (50);
                  attrType.AttrTypeNum = HTML_ATTR_Width__;
                  attr = TtaGetAttribute (el, attrType);
                  if (attr == NULL)
                    {
                      newAttr = TRUE;
                      attr = TtaNewAttribute (attrType);
                      TtaAttachAttribute (el, attr, doc);
                    }
                  else
                    newAttr = FALSE;
                  // check if the image is larger than the window
                  TtaGiveWindowSize (doc, 1, UnPixel, &w, &h);
                  if (width < w)
                    sprintf (value, "%d", width);
                 else
                    strcpy (value, "100%");
                  TtaSetAttributeText (attr, value, el, doc);
                  if (newAttr)
                    TtaRegisterAttributeCreate (attr, el, doc);
                  else
                    TtaRegisterAttributeReplace (attr, el, doc);
                  if (width < w)
                    {
                      attrType.AttrTypeNum = HTML_ATTR_Height_;
                      attr = TtaGetAttribute (el, attrType);
                      if (attr == NULL)
                        {
                          newAttr = TRUE;
                          attr = TtaNewAttribute (attrType);
                          TtaAttachAttribute (el, attr, doc);
                        }
                      else
                        newAttr = FALSE;
                      sprintf (value, "%d", height);
                      TtaSetAttributeText (attr, value, el, doc);
                      if (newAttr)
                        TtaRegisterAttributeCreate (attr, el, doc);
                      else
                        TtaRegisterAttributeReplace (attr, el, doc);
                    }
                  else
                    // generate the internal attribute to apply %
                    CreateAttrWidthPercentPxl (value, el, doc, width);
                  TtaFreeMemory (value);
                  TtaCloseUndoSequence(doc);
                  TtaUpdateAttrMenu (doc);
                }
              TtaSetStructureChecking (oldStructureChecking, doc);
            }
        }
      ImgDocument = 0;
    }
}

/*----------------------------------------------------------------------
  CreateImage
  ----------------------------------------------------------------------*/
void CreateImage (Document doc, View view)
{
  ImgAlt[0] = EOS;
  AddNewImage (doc, view, FALSE);
}

/*----------------------------------------------------------------------
  AddLocalImage adds a new local image into image descriptor table   
  with the purpose of having it saved through the Net later.    
  This function copy the image in the TempFileDirectory.        
  fullname is the complete path to the local file.              
  name is the name of the local file.                           
  url is the complete URL of the distant location.              
  ----------------------------------------------------------------------*/
ThotBool AddLocalImage (char *fullname, char *name, char *url, Document doc,
                        LoadedImageDesc **desc)
{
  LoadedImageDesc    *pImage, *previous;
  char               *localname;

  *desc = NULL;
  if (!TtaFileExist (fullname))
    return (FALSE);
  else if (url == NULL || name == NULL)
    return (FALSE);
  else if (!IsHTTPPath (url))
    /* it is a local image - nothing to do */
    return (FALSE);
  else
    {
      /* It is an image loaded from the Web */
      localname = GetLocalPath (doc, url);

      pImage = ImageURLs;
      previous = NULL;
      while (pImage != NULL)
        {
          if ((pImage->document == doc) &&
              (strcmp (url, pImage->originalName) == 0))
            {
              /* image already loaded */
              *desc = pImage;
              break;
            }
          else
            {
              /* see the next descriptor */
              previous = pImage;
              pImage = pImage->nextImage;
            }
        }

      /* copy the image in place */
      TtaFileCopy (fullname, localname);
      /* add a new identifier to the list if necessary */
      if (pImage == NULL)
        {
          /* It is a new loaded image */
          pImage = (LoadedImageDesc *) TtaGetMemory (sizeof (LoadedImageDesc));
          /* clear the structure */
          memset ((void *) pImage, 0, sizeof (LoadedImageDesc));
          pImage->originalName = (char *)TtaGetMemory (strlen (url) + 1);
          strcpy (pImage->originalName, url);
          pImage->localName = TtaStrdup (localname);
          pImage->tempfile = TtaStrdup (pImage->localName);
          pImage->prevImage = previous;
          if (previous != NULL)
            previous->nextImage = pImage;
          else
            ImageURLs = pImage;
          pImage->nextImage = NULL;
          pImage->document = doc;
          pImage->elImage = NULL;
          pImage->imageType = unknown_type;
        }
      pImage->status = IMAGE_MODIFIED;
      *desc = pImage;
      TtaFreeMemory (localname);
      return (TRUE);
    }
}

/*----------------------------------------------------------------------
  MoveDocumentImages moves loaded images of the document docSrc into
  the document doc.        
  ----------------------------------------------------------------------*/
void MoveDocumentImages (Document docSrc, Document doc)
{
  LoadedImageDesc    *pImage, *previous, *next;
  ElemImage          *ctxEl, *ctxPrev;
  char               *ptr;

  pImage = ImageURLs;
  previous = NULL;
  if (doc == 0)
    return;			/* nothing to do */

  while (pImage)
    {
      next = pImage->nextImage;
      /* does the current image belong to the document ? */
      if (pImage->document == doc)
        {
          pImage->status = IMAGE_NOT_LOADED;
          /* remove the image */
          TtaFileUnlink (pImage->tempfile);
          if (!strncmp (pImage->originalName, "internal:", sizeof ("internal:") - 1)
              && IsHTTPPath (pImage->originalName + sizeof ("internal:") - 1))
            {
              /* erase the local copy of the image */
              ptr = GetLocalPath (doc, pImage->originalName);
              TtaFileUnlink (ptr);
              TtaFreeMemory (ptr);
            }
          /* free the descriptor */
          if (pImage->originalName != NULL)
            TtaFreeMemory (pImage->originalName);
          if (pImage->localName != NULL)
            TtaFreeMemory (pImage->localName);
          if (pImage->tempfile != NULL)
            TtaFreeMemory (pImage->tempfile);
          if (pImage->content_type != NULL)
            TtaFreeMemory (pImage->content_type);
          if (pImage->elImage)
            {
              ctxEl = pImage->elImage;
              pImage->elImage = NULL;
              while (ctxEl != NULL)
                {
                  ctxPrev = ctxEl;
                  ctxEl = ctxEl->nextElement;
                  TtaFreeMemory ( ctxPrev);
                }
            }
          /* set up the image descriptors link */
          if (previous != NULL)
            previous->nextImage = next;
          else
            ImageURLs = next;
          if (next != NULL)
            next->prevImage = previous;
          TtaFreeMemory ((char *) pImage);
          pImage = previous;
        }
      /* next descriptor */
      previous = pImage;
      pImage = next;
    }
}

/*----------------------------------------------------------------------
  RemoveDocumentImages removes loaded images of the document.        
  ----------------------------------------------------------------------*/
void RemoveDocumentImages (Document doc)
{
  LoadedImageDesc    *pImage, *previous, *next;
  ElemImage          *ctxEl, *ctxPrev;
  char               *ptr;

  pImage = ImageURLs;
  previous = NULL;
  while (pImage)
    {
      next = pImage->nextImage;
      /* does the current image belong to the document ? */
      if (pImage->document == doc)
        {
          pImage->status = IMAGE_NOT_LOADED;
          /* remove the image */
          TtaFileUnlink (pImage->tempfile);
          if (!strncmp (pImage->originalName, "internal:", sizeof ("internal:") - 1)
              && IsHTTPPath (pImage->originalName + sizeof ("internal:") - 1))
            {
              /* erase the local copy of the image */
              ptr = GetLocalPath (doc, pImage->originalName);
              TtaFileUnlink (ptr);
              TtaFreeMemory (ptr);
            }
          /* free the descriptor */
          if (pImage->originalName != NULL)
            TtaFreeMemory (pImage->originalName);
          if (pImage->localName != NULL)
            TtaFreeMemory (pImage->localName);
          if (pImage->tempfile != NULL)
            TtaFreeMemory (pImage->tempfile);
          if (pImage->content_type != NULL)
            TtaFreeMemory (pImage->content_type);
          if (pImage->elImage)
            {
              ctxEl = pImage->elImage;
              pImage->elImage = NULL;
              while (ctxEl != NULL)
                {
                  ctxPrev = ctxEl;
                  ctxEl = ctxEl->nextElement;
                  TtaFreeMemory ( ctxPrev);
                }
            }
          /* set up the image descriptors link */
          if (previous != NULL)
            previous->nextImage = next;
          else
            ImageURLs = next;
          if (next != NULL)
            next->prevImage = previous;
          TtaFreeMemory ((char *) pImage);
          pImage = previous;
        }
      /* next descriptor */
      previous = pImage;
      pImage = next;
    }
}
