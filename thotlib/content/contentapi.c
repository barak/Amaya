/*
 *
 *  (c) COPYRIGHT INRIA, 1996-2007
 *  Please first read the full copyright statement in file COPYRIGHT.
 *
 */

/*
 * Content API routines
 *
 * Authors: V. Quint (INRIA)
 *          I. Vatton (INRIA) - Polylines
 *
 */
#include "thot_gui.h"
#include "thot_sys.h"
#include "constmedia.h"
#include "typemedia.h"
#include "picture.h"
#include "application.h"
#include "document.h"
#include "tree.h"
#include "view.h"
#include "selection.h"
#include "language.h"
#include "fileaccess.h"
#include "content.h"
#include "frame.h"
#include "typecorr.h"
#include "ustring.h"

#undef THOT_EXPORT
/*#define THOT_EXPORT*/
#define THOT_EXPORT extern	/* to avoid redefinitions */
#include "edit_tv.h"
#include "select_tv.h"
#ifndef NODISPLAY
#include "frame_tv.h"
#endif

#include "abspictures_f.h"
#include "attributes_f.h"
#include "boxselection_f.h"
#include "buildboxes_f.h"
#include "changeabsbox_f.h"
#include "changepresent_f.h"
#include "content_f.h"
#include "exceptions_f.h"
#include "font_f.h"
#include "geom_f.h"
#include "memory_f.h"
#include "structselect_f.h"
#include "thotmsg_f.h"
#include "tree_f.h"
#include "units_f.h"
#include "viewapi_f.h"
#include "writepivot_f.h"

#ifdef _GL
#include "animbox_f.h"
#include "glgradient_f.h"
#define ALLOC_POINTS 100
#endif /* _GL */


/*----------------------------------------------------------------------
  InsertText   inserts the string "content" in the element 
  pEl (which must be of type text), at the position
  "position". If "document" is null, we have not to consider
  the selection nor the redisplay
  ----------------------------------------------------------------------*/
static void InsertText (PtrElement pEl, int position, unsigned char *content,
                        Document document)
{
  PtrTextBuffer       pBuf, newBuf;
#ifndef NODISPLAY
  PtrDocument         selDoc;
  PtrElement          firstSelection, lastSelection;
  int                 firstChar, lastChar;
  ThotBool            selOk, changeSelection = FALSE;
#endif /* NODISPLAY */
  int                 length, delta, lengthBefore;
  PtrElement          pElAsc;

  length = strlen ((char *)content);
  if (length > 0)
    {
      /* corrects the parameter position */
      if (position > pEl->ElTextLength)
        position = pEl->ElTextLength;

      /* looks for the buffer pBuf where the insertion has to be done */
      pBuf = pEl->ElText;
      lengthBefore = 0;
      while (pBuf->BuNext && lengthBefore + pBuf->BuLength < position)
        {
          lengthBefore += pBuf->BuLength;
          pBuf = pBuf->BuNext;
        }
      /* Length of the remaining of the buffer */
      lengthBefore = - lengthBefore + position;
      if (lengthBefore == 0)
        /* one insert before the first character of the element */
        {
          if (pBuf->BuLength != 0)
            {
              /* one add a buffer before the existing buffers */
              GetTextBuffer (&newBuf);
              if (position)
                {
                  /* chain a new buffer between two buffers */
                  newBuf->BuNext = pBuf;
                  newBuf->BuPrevious = pBuf->BuPrevious;
                  pBuf->BuPrevious->BuNext = newBuf;
                  pBuf->BuPrevious = newBuf;
                }
              else
                {
                  /* chain a new buffer as the first buffer */
                  newBuf->BuNext = pEl->ElText;
                  newBuf->BuPrevious = NULL;
                  if (newBuf->BuNext)
                    newBuf->BuNext->BuPrevious = newBuf;
                  pEl->ElText = newBuf;
                }
              pBuf = newBuf;
            }
        }
      else if (lengthBefore < pBuf->BuLength)
        {
          /* creates a buffer for the second part of the text */
          newBuf = NewTextBuffer (pBuf);
          ustrcpy (newBuf->BuContent, pBuf->BuContent + lengthBefore);
          newBuf->BuLength = pBuf->BuLength - lengthBefore;
        }
      pBuf->BuContent[lengthBefore] = EOS;
      pBuf->BuLength = lengthBefore;
      length = CopyMBs2Buffer (content, pBuf, lengthBefore, length);
      delta = length;
      pEl->ElTextLength += length;
      pEl->ElVolume += length;

#ifndef NODISPLAY
      if (document > 0)
        {
          /* modifies the selection if the element belongs to it */
          selOk = GetCurrentSelection (&selDoc, &firstSelection, &lastSelection, &firstChar, &lastChar);
          changeSelection = FALSE;
          if (selOk && selDoc == LoadedDocument[document - 1] &&
              (pEl == firstSelection || pEl == lastSelection))
            /* The selection starts and/or stops in the element */
            /* First, we abort the selection */
            {
              TtaSelectElement (document, NULL);
              changeSelection = TRUE;
              if (lastChar > 1)
                lastChar -= 1;
              if (pEl == firstSelection)
                /* The element is at the begenning of the selection */
                {
                  if (firstChar > position)
                    firstChar += length;
                }
              if (pEl == lastSelection &&
                  /* The element is at the end of the selection */
                  position < lastChar)
                lastChar += length;
            }
          RedisplayLeaf (pEl, document, delta);
          /* Sets up a new selection if the element is within it */
          if (changeSelection)
            {
              if (firstChar > 0)
                if (lastSelection == firstSelection)
                  TtaSelectString (document, (Element) firstSelection,
                                   firstChar, lastChar);
                else
                  TtaSelectString (document, (Element) firstSelection,
                                   firstChar, 0);
              else
                TtaSelectElement (document, (Element) firstSelection);
              if (lastSelection != firstSelection)
                TtaExtendSelection (document, (Element) lastSelection,
                                    lastChar);
            }
        }
#endif /* NODISPLAY */
      /* Updates the volumes of ancestors */
      pElAsc = pEl->ElParent;
      while (pElAsc != NULL)
        {
          pElAsc->ElVolume += delta;
          pElAsc = pElAsc->ElParent;
        }
    }
}

/*----------------------------------------------------------------------
  SetContent
  ----------------------------------------------------------------------*/
static void SetContent (Element element, unsigned char *content,
                        Language language, Document document)
{
  PtrTextBuffer       pBuf, pNextBuff;
  PtrElement          pEl;
  ThotPictInfo       *image;
  int                 length, delta = 0, i;
  int                 max;
#ifndef NODISPLAY
  PtrDocument         selDoc;
  PtrElement          firstSelection, lastSelection;
  int                 firstChar, lastChar;
  ThotBool            selOk, changeSelection;
#endif /* NODISPLAY */

  UserErrorCode = 0;
  pEl = NULL;
  if (element == NULL)
    TtaError (ERR_invalid_parameter);
  else if (!((PtrElement) element)->ElTerminal)
    TtaError (ERR_invalid_element_type);
  else if (((PtrElement) element)->ElLeafType != LtText &&
           ((PtrElement) element)->ElLeafType != LtPicture)
    TtaError (ERR_invalid_element_type);
  else if (document < 1 || document > MAX_DOCUMENTS)
    TtaError (ERR_invalid_document_parameter);
  else if (LoadedDocument[document - 1] == NULL)
    TtaError (ERR_invalid_document_parameter);
  else
    {
      /* parameter document is correct */
      pEl = (PtrElement) element;
      if (pEl->ElLeafType == LtText)
        pEl->ElLanguage = language;
      
      /* store the contents of the element */
      if (content)
        {
          max = strlen ((char *)content);
          pBuf = pEl->ElText;
          if (pBuf == NULL)
            {
              GetTextBuffer (&pEl->ElText);
              pBuf = pEl->ElText;
            }
          if (pBuf && max > 0)
            length = CopyMBs2Buffer (content, pBuf, 0, max);
          else
            length = 0;
        }
      else
        length = 0;

      delta = length - pEl->ElTextLength;
      pEl->ElTextLength = length;
      pEl->ElVolume = length;

      /* Point to the first buffer to be released */
      pBuf = pEl->ElText;
      if (length == 0)
        /* keep the first buffer, even if it's empty */
        {
          pBuf = pEl->ElText;
          if (pBuf)
            pBuf = pBuf->BuNext;	  
        }
      else
        {
          i = 0;
          while (pBuf && i < length)
            {
              i += pBuf->BuLength;
              pBuf = pBuf->BuNext;
            }
        }
      /* Release extra buffers */
      while (pBuf)
        {
          pNextBuff = pBuf->BuNext;
#ifdef NODISPLAY
          FreeTextBuffer (pBuf);
#else /* NODISPLAY */
          DeleteBuffer (pBuf, ActiveFrame);
#endif /* NODISPLAY */
          pBuf = pNextBuff;
        }

      if (pEl->ElLeafType == LtPicture && pEl->ElPictInfo)
        {
          /* Releases the  pixmap */
          image = (ThotPictInfo *)pEl->ElPictInfo;
          CleanPictInfo (image);
          /* the new image may be in a different format */
          image->PicType = -1;
          /* change the filename of the image */
          TtaFreeMemory (image->PicFileName);
          image->PicFileName = (char *)TtaStrdup ((char *)content);
        }

#ifndef NODISPLAY
      /* modifies the selection if the element is within it */
      selOk = GetCurrentSelection (&selDoc, &firstSelection,
                                   &lastSelection, &firstChar,
                                   &lastChar);
      changeSelection = FALSE;
      if (selOk && selDoc == LoadedDocument[document - 1] &&
          AbsBoxSelectedAttr == NULL)
        {
          if (pEl == firstSelection)
            /* The selection starts in the element */
            {
              TtaSelectElement (document, NULL);
              changeSelection = TRUE;
              if (firstChar > length + 1)
                /* Selection begins beyond the new length */
                firstChar = length + 1;
            }
          if (pEl == lastSelection)
            /* The selection ends in the element */
            {
              if (!changeSelection)
                TtaSelectElement (document, NULL);
              changeSelection = TRUE;
              if (lastChar > length + 1)
                /* Selection ends beyond the new length */
                lastChar = length + 1;
            }
        }
      RedisplayLeaf (pEl, document, delta);
      /* Sets up a new selection if the element is within it */
      if (changeSelection)
        {
          if (firstChar == 0)
            TtaSelectElement (document, (Element) firstSelection);
          else
            {
              if (lastSelection == firstSelection)
                TtaSelectString (document, (Element) firstSelection,
                                 firstChar, lastChar);
              else
                TtaSelectString (document, (Element) firstSelection,
                                 firstChar, 0);
            }
          if (lastSelection != firstSelection)
            TtaExtendSelection (document, (Element) lastSelection,
                                lastChar);
        }
#endif /* NODISPLAY */
      /* Updates the volumes of the ancestors */
      pEl = pEl->ElParent;
      while (pEl != NULL)
        {
          pEl->ElVolume += delta;
          pEl = pEl->ElParent;
        }
    }
}

/*----------------------------------------------------------------------
  TtaSetTextContent

  Changes the content of a Text basic element. The full content (if any) is
  deleted and replaced by the new one.
  This function can also be used for changing the content (the file name)
  of a Picture basic element.
  Parameters:
  element: the Text element to be modified.
  content: new content for that element coded in ISO-Latin or UTF-8.
  language: language of that Text element.
  document: the document containing that element.
  ----------------------------------------------------------------------*/
void TtaSetTextContent (Element element, unsigned char *content,
                        Language language, Document document)
{
  SetContent (element, content, language, document);
}

/*----------------------------------------------------------------------
  TtaSetPictureContent

  N.B. For the moment, this function is identical to TtaSetTextContent,
  except that we also give a MIME type. It should evolve with time.
  Changes the content of a Text basic element. The full content (if any) is
  deleted and replaced by the new one.
  This function can also be used for changing the content (the file name)
  of a Picture basic element.
  Parameters:
  element: the Text element to be modified.
  content: new content for that element coded in ISO-Latin or UTF-8..
  language: language of that Text element.
  document: the document containing that element.
  mime_type: MIME tpye of the picture
  ----------------------------------------------------------------------*/
void TtaSetPictureContent (Element element, unsigned char *content,
                           Language language, Document document, char *mime_type)
{
  SetContent (element, content, language, document);
#ifndef NODISPLAY
  /* @@ Probably create the pictinfo el here and add the mime type. 
     Redisplayleaf is doing so further down */
#endif /* NODISPLAY */
}


/*----------------------------------------------------------------------
  TtaAppendTextContent

  Appends a character string at the end of a Text basic element.
  Parameters:
  element: the Text element to be modified.
  content: the character string to be appended.
  document: the document containing that element.
  ----------------------------------------------------------------------*/
void TtaAppendTextContent (Element element, unsigned char *content,
                           Document document)
{
  UserErrorCode = 0;
  if (element == NULL)
    TtaError (ERR_invalid_parameter);
  else if (!((PtrElement) element)->ElTerminal)
    TtaError (ERR_invalid_element_type);
  else if (((PtrElement) element)->ElLeafType != LtText &&
           ((PtrElement) element)->ElLeafType != LtPicture)
    TtaError (ERR_invalid_element_type);
  else
    /* verifies the parameter document */
    if (document < 1 || document > MAX_DOCUMENTS)
      TtaError (ERR_invalid_document_parameter);
    else if (LoadedDocument[document - 1] == NULL)
      TtaError (ERR_invalid_document_parameter);
    else
      /* parameter document is correct */
      InsertText ((PtrElement) element, ((PtrElement) element)->ElTextLength,
                  content, document);
}


/*----------------------------------------------------------------------
  TtaHasFinalSpace

  Returns TRUE if the text element ends with a space or a NEWLINE
  Parameters:
  element: the Text element to be modified.
  document: the document containing that element.
  ----------------------------------------------------------------------*/
ThotBool TtaHasFinalSpace (Element element, Document document)
{
  PtrElement          pEl;
  PtrTextBuffer       pBuf;

  UserErrorCode = 0;
  pEl = (PtrElement) element;
  /* check parameters */
  if (document < 1 || document > MAX_DOCUMENTS || element == NULL)
    TtaError (ERR_invalid_document_parameter);
  else if (LoadedDocument[document - 1] == NULL)
    TtaError (ERR_invalid_document_parameter);
  else if (pEl->ElTerminal && pEl->ElLeafType == LtText)
    {
      /* go to the last buffer */
      pBuf = pEl->ElText;
      while (pBuf->BuNext)
        pBuf = pBuf->BuNext;
      if (pBuf->BuContent[pBuf->BuLength - 1] == SPACE ||
          pBuf->BuContent[pBuf->BuLength - 1] == EOL)
        /* there is almost one space at the end of the text element */
        return TRUE;
    }
  return FALSE;
}


/*----------------------------------------------------------------------
  TtaRemoveInitialSpaces

  Removes spaces and NEWLINE at the beginning of the text element
  Parameters:
  element: the Text element to be modified.
  document: the document containing that element.
  ----------------------------------------------------------------------*/
void TtaRemoveInitialSpaces (Element element, Document document)
{
  PtrElement          pEl, pElAsc;
  PtrTextBuffer       pBuf, pNext;
  int                 i, l, delta;
  ThotBool            still;

  UserErrorCode = 0;
  pEl = (PtrElement) element;
  /* check parameters */
  if (document < 1 || document > MAX_DOCUMENTS || element == NULL)
    TtaError (ERR_invalid_document_parameter);
  else if (LoadedDocument[document - 1] == NULL)
    TtaError (ERR_invalid_document_parameter);
  else if (pEl->ElTerminal && pEl->ElLeafType == LtText)
    {
      pBuf = pEl->ElText;
      delta = 0;
      still = (pBuf != NULL);
      while (still)
        {
          /* there is almost one space at the end of the text element */
          i = 0;
          while (i <= pBuf->BuLength - 1 &&
                 (pBuf->BuContent[i] == SPACE || pBuf->BuContent[i] == EOL))
            {
              i++;
              delta++;
            }
          still = (i == pBuf->BuLength);
          if (still)
            {
              /* remove the last buffer */
              pNext = pBuf->BuNext;
              if (pNext)
                {
                  pNext->BuPrevious = NULL;
#ifdef NODISPLAY
                  FreeTextBuffer (pBuf);
#else /* NODISPLAY */
                  DeleteBuffer (pBuf, ActiveFrame);
#endif /* NODISPLAY */
                  pBuf = pNext;
                }
              else
                /* stop if there is no next buffer */ 
                still = FALSE;
            }
          else if ( i > 0)
            {
              /* erase initial spaces */
              l = pBuf->BuLength - delta;
              for (i = 0; i < l; i++)
                pBuf->BuContent[i] = pBuf->BuContent[delta + i];
              pBuf->BuContent[i] = EOS;
              pBuf->BuLength = l;
            }
        }

      if (delta)
        {
          if (delta == pEl->ElVolume)
            /* empty TEXT element */
            TtaDeleteTree (element, document);
          else
            {
              pEl->ElTextLength -= delta;
              /* Updates the volume of the element and its ancestors */
              pElAsc = pEl;
              while (pElAsc)
                {
                  pElAsc->ElVolume -= delta;
                  pElAsc = pElAsc->ElParent;
                }
#ifndef NODISPLAY
              /* Redisplays the element */
              RedisplayLeaf (pEl, document, -delta);
#endif /* NODISPLAY */
            }
        }
    }
}


/*----------------------------------------------------------------------
  TtaRemoveFinalSpaces

  Removes spaces and NEWLINE at the end of the text element if the
  parameter all is TRUE, only the last CR/EOL if the parameter is FALSE.
  Parameters:
  element: the Text element to be modified.
  document: the document containing that element.
  all: when TRUE removes all spaces, when FALSE only the last CR/EOL.
  ----------------------------------------------------------------------*/
void TtaRemoveFinalSpaces (Element element, Document document,
                           ThotBool all)
{
  PtrElement          pEl, pElAsc;
  PtrTextBuffer       pBuf, pPrev;
  int                 i, delta, last;
  ThotBool            still;

  UserErrorCode = 0;
  pEl = (PtrElement) element;
  /* check parameters */
  if (document < 1 || document > MAX_DOCUMENTS || element == NULL)
    TtaError (ERR_invalid_document_parameter);
  else if (LoadedDocument[document - 1] == NULL)
    TtaError (ERR_invalid_document_parameter);
  else if (pEl->ElTerminal && pEl->ElLeafType == LtText)
    {
      pBuf = pEl->ElText;
      pPrev = NULL;
      delta = 0;
      /* go to the last buffer */
      while (pBuf && pBuf->BuNext)
        pBuf = pBuf->BuNext;
      still = (pBuf != NULL);
      if (!all)
        {
          i = pBuf->BuLength - 1;
          if (pBuf->BuContent[i] == __CR__ || pBuf->BuContent[i] == EOL)
            {
              delta++;
              pBuf->BuContent[i] = EOS;
              pBuf->BuLength = i;
            }
        }
      else
        {
          while (still)
            {
              pPrev = pBuf->BuPrevious;
              if (pPrev)
                last = pPrev->BuLength - 1;
              else
                last = 0;
              i = pBuf->BuLength - 1;
              /* there is almost one space at the end of the text element ? */
              while (i >= 0 &&
                     (pBuf->BuContent[i] == SPACE ||
                      pBuf->BuContent[i] == __CR__ || pBuf->BuContent[i] == EOL) &&
                     // keep the last space
                     ((i > 0 &&
                       (pBuf->BuContent[i-1] == SPACE ||
                        pBuf->BuContent[i-1] == __CR__ || pBuf->BuContent[i-1] == EOL)) ||
                      (i == 0 && pPrev &&
                       (pPrev->BuContent[last] == SPACE ||
                        pPrev->BuContent[last] == __CR__ || pPrev->BuContent[last] == EOL))))
                {
                  i--;
                  delta++;
                }
              still = (i < 0);
              if (still)
                {
                  /* remove the last buffer */
                  if (pPrev)
                    {
                      pPrev->BuNext = NULL;
#ifdef NODISPLAY
                      FreeTextBuffer (pBuf);
#else /* NODISPLAY */
                      DeleteBuffer (pBuf, ActiveFrame);
#endif /* NODISPLAY */
                      pBuf = pPrev;
                    }
                  else
                    /* stop if there is no previous buffer */ 
                    still = FALSE;
                }
              else if ( pBuf->BuLength != i + 1)
                {
                  pBuf->BuContent[i + 1] = EOS;
                  pBuf->BuLength = i + 1;
                }
            }
        }
      
      if (delta)
        {
          if (delta == pEl->ElVolume)
            /* empty TEXT element */
            TtaDeleteTree (element, document);
          else
            {
              pEl->ElTextLength -= delta;
              /* Updates the volume of the element and its ancestors */
              pElAsc = pEl;
              while (pElAsc)
                {
                  pElAsc->ElVolume -= delta;
                  pElAsc = pElAsc->ElParent;
                }
#ifndef NODISPLAY
              /* Redisplays the element */
              RedisplayLeaf (pEl, document, -delta);
#endif /* NODISPLAY */
            }
        }
    }
}

/*----------------------------------------------------------------------
  TtaInsertTextContent

  Inserts a character string in a text basic element.
  Parameters:
  element: the Text element to be modified.
  position: rank of the character after which the new string must
  be inserted. 0 for inserting before the first character.
  content: the character string to be inserted.
  document: the document containing the text element.
  ----------------------------------------------------------------------*/
void TtaInsertTextContent (Element element, int position, unsigned char *content,
                           Document document)
{
  UserErrorCode = 0;
  if (element == NULL)
    TtaError (ERR_invalid_parameter);
  else if (!((PtrElement) element)->ElTerminal)
    TtaError (ERR_invalid_element_type);
  else if (((PtrElement) element)->ElLeafType != LtText &&
           ((PtrElement) element)->ElLeafType != LtPicture)
    TtaError (ERR_invalid_element_type);
  else
    /* verifies the parameter document */
    if (document < 1 || document > MAX_DOCUMENTS)
      TtaError (ERR_invalid_document_parameter);
    else if (LoadedDocument[document - 1] == NULL)
      TtaError (ERR_invalid_document_parameter);
    else
      /* parameter document is correct */
      InsertText ((PtrElement) element, position, content, document);
}

/*----------------------------------------------------------------------
  TtaDeleteTextContent

  Deletes a character string in a text basic element.
  Parameters:
  element: the Text element to be modified.
  position: rank of the first character to be deleted.
  length: length of the character string to be deleted.
  document: the document containing the text element.
  ----------------------------------------------------------------------*/
void TtaDeleteTextContent (Element element, int position, int length,
                           Document document)
{
  PtrTextBuffer       pBufFirst, pBufLast, pBufNext;
  STRING              dest, source;
  PtrElement          pElAsc, pEl;
#ifndef NODISPLAY
  PtrDocument         selDoc;
  PtrElement          firstSelection, lastSelection;
  int                 firstChar, lastChar;
  ThotBool            selOk, changeSelection;
#endif /* NODISPLAY */
  int                 delta, lengthBefore, firstDeleted;
  int                 lastDeleted, l, i;

  UserErrorCode = 0;
  pEl = (PtrElement) element;
  if (element == NULL)
    TtaError (ERR_invalid_parameter);
  else if (!pEl->ElTerminal)
    TtaError (ERR_invalid_element_type);
  else if (pEl->ElLeafType != LtText &&
           pEl->ElLeafType != LtPicture)
    TtaError (ERR_invalid_element_type);
  else if (document < 1 || document > MAX_DOCUMENTS)
    TtaError (ERR_invalid_document_parameter);
  else if (LoadedDocument[document - 1] == NULL)
    TtaError (ERR_invalid_document_parameter);
  else if (length < 0 || position <= 0 || position > pEl->ElTextLength)
    TtaError (ERR_invalid_parameter);
  else if (length > 0)
    {
      /* verifies that the parameter length is not too big */
      if (position + length > pEl->ElTextLength + 1)
        length = pEl->ElTextLength - position + 1;
#ifndef NODISPLAY
      /* modifies the selection if the element belongs to it */
      selOk = GetCurrentSelection (&selDoc, &firstSelection, &lastSelection,
                                   &firstChar, &lastChar);
      changeSelection = FALSE;
      if (selOk && selDoc == LoadedDocument[document - 1] &&
          (pEl == firstSelection || pEl == lastSelection))
        /* The selection starts and/or stops in the element */
        /* First, we abort the selection */
        {
          TtaSelectElement (document, NULL);
          changeSelection = TRUE;
          if (lastChar > 1)
            lastChar -= 1;
          if (pEl == firstSelection)
            /* The element is at the beginning of the selection */
            {
              if (firstChar > position)
                {
                  firstChar -= length;
                  if (firstChar < position)
                    firstChar = position;
                }
            }
          if (pEl == lastSelection)
            /* The element is at the end of the selection */
            {
              if (position < lastChar)
                {
                  lastChar -= length;
                  if (lastChar < position)
                    lastChar = position;
                }
            }
        }
#endif /* NODISPLAY */
      delta = length;
      pEl->ElTextLength -= delta;
      pEl->ElVolume -= delta;
      /* Looks for the buffer where the string to be suppressed starts*/
      pBufFirst = pEl->ElText;
      lengthBefore = 0;
      while (pBufFirst->BuNext != NULL &&
             lengthBefore + pBufFirst->BuLength < position)
        {
          lengthBefore += pBufFirst->BuLength;
          pBufFirst = pBufFirst->BuNext;
        }
      /* Length of the buffer containing the beginning of the string to be
         suppress */
      firstDeleted = position - lengthBefore;
      /* Looks for the buffer pBufLast containing the end of the string to
         be suppressed and releases the intermediate buffers. The buffers
         containing the begenning of the string to be suppressed and its
         end are not released */
      pBufLast = pBufFirst;
      lastDeleted = firstDeleted + length - 1;
      while (pBufLast->BuNext != NULL &&
             lastDeleted > pBufLast->BuLength)
        {
          lastDeleted -= pBufLast->BuLength;
          if (pBufLast != pBufFirst)
            /* This is not the buffer containing the begenning of the 
               tring. It is released */
            {
              pBufNext = pBufLast->BuNext;
              pBufLast->BuPrevious->BuNext = pBufLast->BuNext;
              if (pBufLast->BuNext != NULL)
                pBufLast->BuNext->BuPrevious = pBufLast->BuPrevious;
#ifdef NODISPLAY
              FreeTextBuffer (pBufLast);
#else /* NODISPLAY */
              DeleteBuffer (pBufLast, ActiveFrame);
#endif /* NODISPLAY */
              pBufLast = pBufNext;
            }
          else
            pBufLast = pBufLast->BuNext;
        }
      /* The text following the string to suppress is moved on the right */
      if (pBufFirst == pBufLast)
        /* The whole string to suppress is in the same buffer */
        /* The text following the string to be suppressed is moved at 
           the position of the begenning of the string to suppress */
        {
          dest = &pBufFirst->BuContent[firstDeleted - 1];
          l = length;
        }
      else
        /* The begenning and the and of the string to be suppressed are
           in different buffers. The text of the first buffer is troncated
           and the text remaining in the other buffer is moved at the
           begenning of the buffer */
        {
          pBufFirst->BuContent[firstDeleted - 1] = EOS;
          pBufFirst->BuLength = firstDeleted - 1;
          dest = pBufLast->BuContent;
          l = lastDeleted;
        }
      /* The text following the part to be suppresses is moved */
      source = &pBufLast->BuContent[lastDeleted];
      i = 0;
      while (source[i] != EOS)
        {
          dest[i] = source[i];
          i++;
        }
      dest[i] = EOS;
      pBufLast->BuLength -= l;
      /* If the buffers of the begening and the end of the suppresses string
         are empty, they are released. A buffer is kept for the element */
      if (pBufFirst->BuLength == 0 &&
          (pBufFirst->BuPrevious || pBufFirst->BuNext))
        /* If the buffer of the begenning is empty, it is released */
        {
          if (pBufFirst->BuPrevious)
            pBufFirst->BuPrevious->BuNext = pBufFirst->BuNext;
          else
            pEl->ElText = pBufFirst->BuNext;
          if (pBufFirst->BuNext)
            pBufFirst->BuNext->BuPrevious = pBufFirst->BuPrevious;
#ifdef NODISPLAY
          FreeTextBuffer (pBufFirst);
#else /* NODISPLAY */
          DeleteBuffer (pBufFirst, ActiveFrame);
#endif /* NODISPLAY */
        }
      if (pBufFirst != pBufLast && pBufLast->BuLength == 0 &&
          (pBufLast->BuPrevious || pBufLast->BuNext))
        /* The buffer of the end is empty. It is released */
        {
          if (pBufLast->BuPrevious)
            pBufLast->BuPrevious->BuNext = pBufLast->BuNext;
          else
            pEl->ElText = pBufLast->BuNext;
          if (pBufLast->BuNext)
            pBufLast->BuNext->BuPrevious = pBufLast->BuPrevious;
#ifdef NODISPLAY
          FreeTextBuffer (pBufLast);
#else /* NODISPLAY */
          DeleteBuffer (pBufLast, ActiveFrame);
#endif /* NODISPLAY */
        }
      /* Updates the volumes of the ancestors */
      pElAsc = pEl->ElParent;
      while (pElAsc)
        {
          pElAsc->ElVolume -= delta;
          pElAsc = pElAsc->ElParent;
        }
#ifndef NODISPLAY
      /* Redisplays the element */
      RedisplayLeaf (pEl, document, -delta);
      /* Sets up a new selection if the element belongs to it */
      if (changeSelection)
        {
          if (firstChar > 0)
            {
              if (lastSelection == firstSelection)
                TtaSelectString (document, (Element) firstSelection,
                                 firstChar, lastChar);
              else
                TtaSelectString (document, (Element) firstSelection,
                                 firstChar, 0);
            }
          else
            TtaSelectElement (document, (Element) firstSelection);
          if (lastSelection != firstSelection)
            TtaExtendSelection (document, (Element) lastSelection,
                                lastChar);
        }
#endif /* NODISPLAY */
    }
}

/*----------------------------------------------------------------------
  TtaSplitText

  Divides a text element into two elements.
  Parameters:
  element: the text element to be divided. A new text element containing
  the second part of the text is created as the next sibling.
  position: rank of the character before which the element must be cut.
  document: the document to which the element belongs.
  ----------------------------------------------------------------------*/
void TtaSplitText (Element element, int position, Document document)
{
  PtrElement	secondPart, pNextEl;

  UserErrorCode = 0;
  if (element == NULL)
    TtaError (ERR_invalid_parameter);
  else if (!((PtrElement) element)->ElTerminal)
    TtaError (ERR_invalid_element_type);
  else if (((PtrElement) element)->ElLeafType != LtText)
    TtaError (ERR_invalid_element_type);
  else if (document < 1 || document > MAX_DOCUMENTS)
    TtaError (ERR_invalid_document_parameter);
  else if (LoadedDocument[document - 1] == NULL)
    TtaError (ERR_invalid_document_parameter);
  else if (position < 1 || position >
           ((PtrElement) element)->ElTextLength)
    TtaError (ERR_invalid_parameter);
  else
    {
      pNextEl = ((PtrElement) element)->ElNext;
      SplitTextElement ((PtrElement) element, position,
                        LoadedDocument[document - 1], FALSE, &secondPart,
                        FALSE);
#ifndef NODISPLAY
      RedisplaySplittedText ((PtrElement) element, position, secondPart,
                             pNextEl, document);
#endif
    }
}


/*----------------------------------------------------------------------
  TtaMergeText

  Merges two text elements.
  Parameters:
  element: the first text element. Merging occurs only if
  the next sibling is a text element with the same attributes.
  document: the document to which the text element belongs.
  Return value:
  TRUE if merging has been done.
  ----------------------------------------------------------------------*/
ThotBool TtaMergeText (Element element, Document document)
{
  ThotBool            ok = FALSE;
#ifndef NODISPLAY
  PtrElement          FreeElement;
  PtrElement          pEl2, pEl;

  UserErrorCode = 0;
  if (element == NULL)
    TtaError (ERR_invalid_parameter);
  else if (!((PtrElement) element)->ElTerminal)
    TtaError (ERR_invalid_element_type);
  else if (((PtrElement) element)->ElLeafType != LtText)
    TtaError (ERR_invalid_element_type);
  else if (document < 1 || document > MAX_DOCUMENTS)
    TtaError (ERR_invalid_document_parameter);
  else if (LoadedDocument[document - 1] == NULL)
    TtaError (ERR_invalid_document_parameter);
  else
    /* parameter document is correct */
    {
      pEl = (PtrElement) element;
      pEl2 = pEl->ElNext;
      if (pEl->ElStructSchema->SsRule->SrElem[pEl->ElTypeNumber - 1]->SrConstruct != CsConstant &&
          pEl2 && pEl2->ElTerminal && pEl2->ElLeafType == LtText &&
          pEl2->ElLanguage == pEl->ElLanguage &&
          pEl2->ElStructSchema->SsRule->SrElem[pEl2->ElTypeNumber - 1]->SrConstruct != CsConstant)
        if (SameAttributes (pEl, pEl2) &&
            pEl->ElSource == NULL && pEl2->ElSource == NULL &&
            BothHaveNoSpecRules (pEl, pEl2))
          {
            /* destroy the second element of the text */
            DestroyAbsBoxes (pEl2, LoadedDocument[document - 1], FALSE);
            ok = MergeTextElements (pEl,
                                    &FreeElement, LoadedDocument[document - 1],
                                    FALSE, FALSE);
            RedisplayMergedText (pEl, document);
            if (FreeElement != NULL)
              DeleteElement (&FreeElement, LoadedDocument[document - 1]);
          }
    }
#endif
  return ok;
}


/*----------------------------------------------------------------------
  TtaSetGraphicsShape

  Changes the shape of a Graphics or Symbol basic element.
  Parameters:
  element: the element to be changed. This element must
  be a basic element of type Graphics or Symbol.
  shape: new shape for that element.
  document: the document containing that element.
  ----------------------------------------------------------------------*/
void TtaSetGraphicsShape (Element element, char shape, Document document)
{
  int                 delta;
  ThotBool            polyline;
  PtrElement          pElAsc, pEl;

  UserErrorCode = 0;
  if (element == NULL)
    TtaError (ERR_invalid_parameter);
  else if (!((PtrElement) element)->ElTerminal)
    TtaError (ERR_invalid_element_type);
  else if (((PtrElement) element)->ElLeafType != LtSymbol &&
           ((PtrElement) element)->ElLeafType != LtGraphics &&
           ((PtrElement) element)->ElLeafType != LtPolyLine)
    TtaError (ERR_invalid_element_type);
  else
    {
      /* verifies the parameter document */
      if (document < 1 || document > MAX_DOCUMENTS)
        TtaError (ERR_invalid_document_parameter);
      else if (LoadedDocument[document - 1] == NULL)
        TtaError (ERR_invalid_document_parameter);
      else
        /* parameter document is correct */
        {
          delta = 0;
          pEl = (PtrElement) element;
          if (pEl->ElLeafType == LtSymbol)
            {
              if (pEl->ElGraph == EOS && shape != EOS)
                delta = 1;
              else if (pEl->ElGraph != EOS && shape == EOS)
                delta = -1;
              pEl->ElWideChar = 0;
            }
          else
            {
              polyline = (shape == 'S' || shape == 'U' || shape == 'N' ||
                          shape == 'M' || shape == 'B' || shape == 'A' ||
                          shape == 'F' || shape == 'D' || shape == 'p' ||
                          shape == 's' || shape == 'w' || shape == 'x' ||
                          shape == 'y' || shape == 'z');
              if (polyline && pEl->ElLeafType == LtGraphics)
                /* changing simple graphic --> polyline */
                {
                  pEl->ElLeafType = LtPolyLine;
                  GetTextBuffer (&pEl->ElPolyLineBuffer);
                  pEl->ElNPoints = 1;
                  pEl->ElText->BuLength = 1;
                  pEl->ElText->BuPoints[0].XCoord = 0;
                  pEl->ElText->BuPoints[0].YCoord = 0;
                }
              else if (!polyline && pEl->ElLeafType == LtPolyLine)
                /* changing polyline --> simple graphic */
                {
                  delta = -pEl->ElNPoints;
                  if (shape != EOS)
                    delta++;
                  ClearText (pEl->ElPolyLineBuffer);
                  FreeTextBuffer (pEl->ElPolyLineBuffer);
                  pEl->ElLeafType = LtGraphics;
                }
              else if (pEl->ElLeafType == LtGraphics)
                {
                  if (pEl->ElGraph == EOS && shape != EOS)
                    delta = 1;
                  else if (pEl->ElGraph != EOS && shape == EOS)
                    delta = -1;
                }
            }
          if (pEl->ElLeafType == LtPolyLine)
            pEl->ElPolyLineType = shape;
          else
            pEl->ElGraph = shape;
          /* Updates the volumes of ancestors */
          if (delta > 0)
            {
              pElAsc = (PtrElement) element;
              while (pElAsc != NULL)
                {
                  pElAsc->ElVolume += delta;
                  pElAsc = pElAsc->ElParent;
                }
            }
#ifndef NODISPLAY
          RedisplayLeaf ((PtrElement) element, document, delta);
#endif
        }
    }
}

/*----------------------------------------------------------------------
  TtaSetSymbolCode

  Changes the wide char code associated with a Symbol basic element.
  Parameters:
  element: the element to be changed. This element must
  be a basic element of type Symbol whose shape is '?'
  code: wide char code
  document: the document containing that element.
  ----------------------------------------------------------------------*/
void TtaSetSymbolCode (Element element, wchar_t code, Document document)
{
  UserErrorCode = 0;
  if (element == NULL)
    TtaError (ERR_invalid_parameter);
  else if (!((PtrElement) element)->ElTerminal)
    TtaError (ERR_invalid_element_type);
  else if (((PtrElement) element)->ElLeafType != LtSymbol)
    TtaError (ERR_invalid_element_type);
  else if (((PtrElement) element)->ElGraph != '?')
    TtaError (ERR_invalid_element_type);
  else if (document < 1 || document > MAX_DOCUMENTS)
    TtaError (ERR_invalid_document_parameter);
  else if (LoadedDocument[document - 1] == NULL)
    TtaError (ERR_invalid_document_parameter);
  else
    /* parameter document is correct */
    ((PtrElement) element)->ElWideChar = code;
}

/*----------------------------------------------------------------------
  ----------------------------------------------------------------------*/
static ThotBool PolylineOK (Element element, Document document)
{
  ThotBool            ok;

  ok = FALSE;
  UserErrorCode = 0;
  if (element == NULL)
    TtaError (ERR_invalid_parameter);
  else if (!((PtrElement) element)->ElTerminal)
    TtaError (ERR_invalid_element_type);
  else if (((PtrElement) element)->ElLeafType != LtPolyLine)
    TtaError (ERR_invalid_element_type);
  else if (document < 1 || document > MAX_DOCUMENTS)
    TtaError (ERR_invalid_document_parameter);
  else if (LoadedDocument[document - 1] == NULL)
    TtaError (ERR_invalid_document_parameter);
  else
    /* parameter document is correct */
    ok = TRUE;
  return ok;
}


/*----------------------------------------------------------------------
  TtaAddPointInPolyline

  Adds a new point in a Polyline basic element.
  Parameters:
  element: the element to be changed. This element must
  be a basic element of type Polyline.
  document: the document containing the polyline element.
  rank: rank of the new point to be inserted. If rank is greater
  than the actual number of points, the new point is appended.
  rank must be strictly positive.
  x, y: coordinate of the new point, in millipoints, relatively to
  the upper left corner of the box. x and y
  must be positive or null.
  unit: UnPixel or UnPoint.
  ----------------------------------------------------------------------*/
void TtaAddPointInPolyline (Element element, int rank, TypeUnit unit,
                            int x, int y, Document document)
{
  PtrTextBuffer       firstBuffer;
  PtrElement          pEl;

  if (PolylineOK (element, document))
    {
      /* Cannot found why this two test
         were here, as it works for me */
      if (rank <= 0)/* || x < 0 || y < 0)*/
        TtaError (ERR_invalid_parameter);
      else if (unit != UnPoint && unit != UnPixel)
        TtaError (ERR_invalid_parameter);
      else
        {
          firstBuffer = ((PtrElement) element)->ElPolyLineBuffer;
          /* adds the point to the polyline */
          AddPointInPolyline (firstBuffer, rank, x, y);
          ((PtrElement) element)->ElNPoints++;
          /* Updates the volumes of ancestors */
          pEl = ((PtrElement) element)->ElParent;
          while (pEl != NULL)
            {
              pEl->ElVolume++;
              pEl = pEl->ElParent;
            }
#ifndef NODISPLAY
          RedisplayLeaf ((PtrElement) element, document, 1);
#endif
        }
    }
}

/*----------------------------------------------------------------------
  TtaDeletePointInPolyline

  Deletes a point in a Polyline basic element.
  Parameters:
  element: the element to be changed. This element must
  be a basic element of type Polyline.
  rank: rank of the point to be deleted. If rank is greater
  than the actual number of points, the last point is deleted.
  rank must be strictly positive.
  document: the document containing the polyline element.
  ----------------------------------------------------------------------*/
void TtaDeletePointInPolyline (Element element, int rank, Document document)
{
  PtrElement          pEl;

  if (PolylineOK (element, document))
    {
      if (rank <= 0)
        TtaError (ERR_invalid_parameter);
      else
        {
          /* Suppresses the point from the polyline */
          DeletePointInPolyline (&(((PtrElement) element)->ElPolyLineBuffer), rank);
          /* There is a point less in the element */
          ((PtrElement) element)->ElNPoints--;
          /* Updates the volumes of ancestors */
          pEl = ((PtrElement) element)->ElParent;
          while (pEl != NULL)
            {
              pEl->ElVolume--;
              pEl = pEl->ElParent;
            }
#ifndef NODISPLAY
          RedisplayLeaf ((PtrElement) element, document, -1);
#endif
        }
    }
}


/*----------------------------------------------------------------------
  TtaModifyPointInPolyline

  Changes the coordinates of a point in a Polyline basic element.
  Parameters:
  element: the element to be changed. This element must
  be a basic element of type Polyline.
  rank: rank of the point to be modified. If rank is greater
  than the actual number of points, the last point is changed.
  rank must be strictly positive.
  x, y: new coordinates of the point, in millipoints, relatively to
  the upper left corner of the enclosing rectangle. x and y
  must be positive or null.
  document: the document containing the polyline element.
  unit: UnPixel or UnPoint.
  ----------------------------------------------------------------------*/
void TtaModifyPointInPolyline (Element element, int rank, TypeUnit unit,
                               int x, int y, Document document)
{
  if (PolylineOK (element, document))
    {
      if (rank <= 0 || x < 0 || y < 0)
        TtaError (ERR_invalid_parameter);
      else if (unit != UnPoint && unit != UnPixel)
        TtaError (ERR_invalid_parameter);
      else
        {
          ModifyPointInPolyline (((PtrElement) element)->ElPolyLineBuffer,
                                 rank, x, y);
#ifndef NODISPLAY
          RedisplayLeaf ((PtrElement) element, document, 0);
#endif
        }
    }
}


/*----------------------------------------------------------------------
  TtaChangeLimitOfPolyline

  Changes the coordinates of the lower left corner of the box containing
  a Polyline basic element.
  Parameters:
  element: the element to be changed. This element must
  be a basic element of type Polyline.
  unit: UnPixel or UnPoint.
  x, y: new coordinates of the lower left corner, in millipoints,
  relatively to the upper left corner of the box. x and y
  must be positive or null and the box must contain all
  points of the polyline.
  document: the document containing the polyline element.
  ----------------------------------------------------------------------*/
void TtaChangeLimitOfPolyline (Element element, TypeUnit unit, int x, int y,
                               Document document)
{
  PtrTextBuffer       firstBuffer;
  PtrTextBuffer       pBuff;
  int                 rank;

  if (PolylineOK (element, document))
    {
      if (x < 0 || y < 0) 
        TtaError (ERR_invalid_parameter); 
      else if (unit != UnPoint && unit != UnPixel)
        TtaError (ERR_invalid_parameter);
      else
        {
          firstBuffer = ((PtrElement) element)->ElPolyLineBuffer;
          /* verifies that the new point coordinates are greatest than all
             the coordinates of the other points of the polyline */
          rank = 1;
          pBuff = firstBuffer;
          while (pBuff != NULL)
            {
              while (rank < pBuff->BuLength)
                {
                  if (x < pBuff->BuPoints[rank].XCoord)
                    x = pBuff->BuPoints[rank].XCoord;
                  if (y < pBuff->BuPoints[rank].YCoord)
                    y = pBuff->BuPoints[rank].YCoord;
                  rank++;
                }
              rank = 0;
              pBuff = pBuff->BuNext;
            }
          if (x != firstBuffer->BuPoints[0].XCoord ||
              y != firstBuffer->BuPoints[0].YCoord)
            {
              /* Updates the coordinates of the new boundary point */
              firstBuffer->BuPoints[0].XCoord = x;
              firstBuffer->BuPoints[0].YCoord = y;
#ifndef NODISPLAY
              RedisplayLeaf ((PtrElement) element, document, 0);
#endif
            }
        }
    }
}

/*----------------------------------------------------------------------
  TtaTransformCurveIntoPath

  Transform a polyline element into a path and return the SVG
  representation of that path.
  Parameters:
  el: the element to be transformed
  Return value:
  the SVG path expression
  ---------------------------------------------------------------------- */
char *TtaTransformCurveIntoPath (Element el)
{
  char           *path = NULL;
#ifndef NODISPLAY
  C_points       *ctrlPoints;
  PtrBox          pBox;
  PtrAbstractBox  pAb;
  PtrElement      pEl;
  PtrTextBuffer   adBuff, adNextBuff;
  int             nbPoints, i, j, len;
  ThotBool        closed;

  pEl = (PtrElement) el;
  if (pEl->ElLeafType != LtPolyLine)
    return (NULL);
  if (pEl->ElPolyLineType != 'B' &&        /* open Bezier */
      pEl->ElPolyLineType != 's')          /* closed Bezier */
    return (NULL);
  adBuff = pEl->ElPolyLineBuffer;
  nbPoints = pEl->ElNPoints;
  closed = (pEl->ElPolyLineType == 's');
  pAb = pEl->ElAbstractBox[0];
  pBox = pAb->AbBox;

  if (pBox->BxPictInfo)
    {
      ctrlPoints = (C_points *) pBox->BxPictInfo;
      path = (char *)TtaGetMemory (nbPoints * 40);
      sprintf (path, "M %d,%d", adBuff->BuPoints[1].XCoord,
               adBuff->BuPoints[1].YCoord);
      len = strlen (path);
      j = 1;
      for (i = 1; i < nbPoints - 1; i++)
        {
          j++;
          if (j >= adBuff->BuLength &&  adBuff->BuNext != NULL)
            {
              adBuff = adBuff->BuNext;
              j = 0;
            }
          sprintf (&path[len], " C %d,%d %d,%d %d,%d",
                   (int) ctrlPoints[i].rx, (int) ctrlPoints[i].ry,
                   (int) ctrlPoints[i+1].lx, (int) ctrlPoints[i+1].ly,
                   adBuff->BuPoints[j].XCoord, adBuff->BuPoints[j].YCoord);
          len = strlen (path);
        }
      if (closed)
        {
          adBuff = pEl->ElPolyLineBuffer;
          sprintf (&path[len], " C %d,%d %d,%d %d,%d",
                   (int) ctrlPoints[i].rx, (int) ctrlPoints[i].ry,
                   (int) ctrlPoints[1].lx, (int) ctrlPoints[1].ly,
                   adBuff->BuPoints[1].XCoord, adBuff->BuPoints[1].YCoord);
          len = strlen (path);
          sprintf (&path[len], " Z");
        }
    }

  adBuff = pEl->ElPolyLineBuffer;
  while (adBuff)
    {
      adNextBuff = adBuff->BuNext;
      free (adBuff);
      adBuff = adNextBuff;
    }

  if (pBox->BxPictInfo != NULL)
    free (pBox->BxPictInfo);

  pEl->ElLeafType = LtPath;
  pEl->ElFirstPathSeg = NULL;

  pAb->AbLeafType = LtPath;
  pAb->AbFirstPathSeg = NULL;

  pBox->BxFirstPathSeg = NULL;

#endif
  return (path);
}

/*----------------------------------------------------------------------
  TtaNewPathSegLine

  Creates a new path segment of type line.
  Parameters:
  xstart: absolute X coordinate for the start point of the path segment
  ystart: absolute X coordinate for the start point of the path segment
  xend:   absolute Y coordinate for the end point of the path segment
  yend:   absolute Y coordinate for the end point of the path segment
  newSubpath: this segment starts a new subpath
  Return value:
  the created path segment.
  ---------------------------------------------------------------------- */
PathSegment  TtaNewPathSegLine (int xstart, int ystart, int xend, int yend,
                                ThotBool newSubpath)
{
  PtrPathSeg       pPa;

  UserErrorCode = 0;
  GetPathSeg (&pPa);
  pPa->PaShape = PtLine;
  pPa->PaNewSubpath = newSubpath;
  pPa->XStart = xstart;
  pPa->YStart = ystart;
  pPa->XEnd = xend;
  pPa->YEnd = yend;
  return ((PathSegment) pPa);
}

/*----------------------------------------------------------------------
  TtaNewPathSegCubic

  Creates a new path segment of type cubic Bezier curve.
  Parameters:
  xstart: absolute X coordinate for the start point of the path segment
  ystart: absolute X coordinate for the start point of the path segment
  xend:   absolute Y coordinate for the end point of the path segment
  yend:   absolute Y coordinate for the end point of the path segment
  xctrl1: absolute X coordinate for the first control point
  yctrl1: absolute Y coordinate for the first control point
  xctrl2: absolute X coordinate for the second control point
  yctrl2: absolute Y coordinate for the second control point
  newSubpath: this segment starts a new subpath
  Return value:
  the created path segment.
  ---------------------------------------------------------------------- */
PathSegment TtaNewPathSegCubic (int xstart, int ystart, int xend, int yend,
                                int xctrl1, int yctrl1, int xctrl2, int yctrl2,
                                ThotBool newSubpath)
{
  PtrPathSeg       pPa;

  UserErrorCode = 0;
  GetPathSeg (&pPa);
  pPa->PaShape = PtCubicBezier;
  pPa->PaNewSubpath = newSubpath;
  pPa->XStart = xstart;
  pPa->YStart = ystart;
  pPa->XEnd = xend;
  pPa->YEnd = yend;
  pPa->XCtrlStart = xctrl1;
  pPa->YCtrlStart = yctrl1;
  pPa->XCtrlEnd = xctrl2;
  pPa->YCtrlEnd = yctrl2;
  return ((PathSegment) pPa);
}

/*----------------------------------------------------------------------
  TtaNewPathSegQuadratic

  Creates a new path segment of type quadratic Bezier curve.
  Parameters:
  xstart: absolute X coordinate for the start point of the path segment
  ystart: absolute X coordinate for the start point of the path segment
  xend:   absolute Y coordinate for the end point of the path segment
  yend:   absolute Y coordinate for the end point of the path segment
  xctrl:  absolute X coordinate for the control point
  yctrl:  absolute Y coordinate for the control point
  newSubpath: this segment starts a new subpath
  Return value:
  the created path segment.
  ---------------------------------------------------------------------- */
PathSegment TtaNewPathSegQuadratic (int xstart, int ystart, int xend, int yend,
                                    int xctrl, int yctrl, ThotBool newSubpath)
{
  PtrPathSeg       pPa;

  UserErrorCode = 0;
  GetPathSeg (&pPa);
  pPa->PaShape = PtQuadraticBezier;
  pPa->PaNewSubpath = newSubpath;
  pPa->XStart = xstart;
  pPa->YStart = ystart;
  pPa->XEnd = xend;
  pPa->YEnd = yend;
  pPa->XCtrlStart = xctrl;
  pPa->YCtrlStart = yctrl;
  pPa->XCtrlEnd = xctrl;
  pPa->YCtrlEnd = yctrl;
  return ((PathSegment) pPa);
}

/*----------------------------------------------------------------------
  TtaNewPathSegArc

  Creates a new path segment of type elliptical arc.
  Parameters:
  xstart:  absolute X coordinate for the start point of the path segment
  ystart:  absolute X coordinate for the start point of the path segment
  xend:    absolute Y coordinate for the end point of the path segment
  yend:    absolute Y coordinate for the end point of the path segment
  xradius: x-axis radius for the ellipse
  yradius: y-axis radius for the ellipse
  angle:   rotation angle in degrees for the ellipse's x-axis relative to
  the x-axis
  largearc:value for the large-arc-flag parameter
  sweep:   value for the sweep-flag parameter
  newSubpath: this segment starts a new subpath
  Return value:
  the created path segment.
  ---------------------------------------------------------------------- */
PathSegment TtaNewPathSegArc (int xstart, int ystart, int xend, int yend,
                              int xradius, int yradius, int angle,
                              ThotBool largearc, ThotBool sweep,
                              ThotBool newSubpath)
{
  PtrPathSeg       pPa;

  UserErrorCode = 0;
  GetPathSeg (&pPa);
  pPa->PaShape = PtEllipticalArc;
  pPa->PaNewSubpath = newSubpath;
  pPa->XStart = xstart;
  pPa->YStart = ystart;
  pPa->XEnd = xend;
  pPa->YEnd = yend;
  pPa->XRadius = xradius;
  pPa->YRadius = yradius;
  pPa->XAxisRotation = angle;
  pPa->LargeArc = largearc;
  pPa->Sweep = sweep;
  return ((PathSegment) pPa);
}

/*----------------------------------------------------------------------
  TtaAppendPathSeg

  Appends a path segment at the end of a Graphics basic element

  Parameters:
  element: the Graphics element to be modified.
  segment: the path segment to be appended.
  document: the document containing the element.
  ----------------------------------------------------------------------*/
void TtaAppendPathSeg (Element element, PathSegment segment, Document document)
{
  PtrPathSeg       pPa, pPrevPa;
  PtrElement       pElAsc;

  UserErrorCode = 0;
  if (element == NULL)
    TtaError (ERR_invalid_parameter);
  else if (!((PtrElement) element)->ElTerminal)
    TtaError (ERR_invalid_element_type);
  else if (((PtrElement) element)->ElLeafType != LtPath &&
           ((PtrElement) element)->ElLeafType != LtGraphics)
    TtaError (ERR_invalid_element_type);
  else
    /* verifies the parameter document */
    if (document < 1 || document > MAX_DOCUMENTS)
      TtaError (ERR_invalid_document_parameter);
    else if (LoadedDocument[document - 1] == NULL)
      TtaError (ERR_invalid_document_parameter);
    else
      /* parameter document is correct */
      {
        if (((PtrElement) element)->ElLeafType == LtGraphics)
          {
            if (((PtrElement) element)->ElGraph == EOS)
              {
                ((PtrElement) element)->ElLeafType = LtPath;
                ((PtrElement) element)->ElFirstPathSeg = NULL;
              }
            else
              {
                TtaError (ERR_invalid_element_type);
                element = NULL;
              }
          }
        if (element && segment)
          {
            pPa = ((PtrElement) element)->ElFirstPathSeg;
            pPrevPa = NULL;
            while (pPa)
              {
                pPrevPa = pPa;
                pPa = pPa->PaNext;
              }
            if (pPrevPa == NULL)
              ((PtrElement) element)->ElFirstPathSeg = (PtrPathSeg) segment;
            else
              {
                pPrevPa->PaNext = (PtrPathSeg) segment;
                ((PtrPathSeg) segment)->PaPrevious = pPrevPa;
              }
            /* Updates the volumes of ancestors */
            pElAsc = (PtrElement) element;
            while (pElAsc != NULL)
              {
                pElAsc->ElVolume++;
                pElAsc = pElAsc->ElParent;
              }
#ifndef NODISPLAY
            RedisplayLeaf ((PtrElement) element, document, 1);
#endif
          }
      }
}


#ifndef NODISPLAY
#ifdef _GL
/*----------------------------------------------------------------------
  ---------------------------------------------------------------------- */
static RgbaDef *NewRgbaDef (Element el)
{
  RgbaDef *seek;
 
  seek = (RgbaDef *)TtaGetMemory (sizeof (RgbaDef));
  seek->el = el;
  seek->next = NULL;

  return seek;
}

/*----------------------------------------------------------------------
  ---------------------------------------------------------------------- */
static GradDef *NewGradDef ()
{
  GradDef *grad;
 
  grad = (GradDef *)TtaGetMemory (sizeof (GradDef));
  grad->x1 = 0;
  grad->x2 = 0;
  grad->y1 = 0;
  grad->y2 = 0;
  grad->next = NULL;
  
  return grad;
}

/*----------------------------------------------------------------------
  ---------------------------------------------------------------------- */
static GradDef *GetGradientRef (PtrElement father)
{  
  GradDef *grad;
  
  if (father->ElGradient == NULL)
    father->ElGradient = NewGradDef ();
  grad = (GradDef *) father->ElGradient;
  return grad;
}

/*----------------------------------------------------------------------
  ---------------------------------------------------------------------- */
static RgbaDef *GetStopRef (Element el, PtrElement father)
{
  RgbaDef *previous = NULL;
  RgbaDef *seek;
  GradDef *grad;

  if (father->ElGradient == NULL)
    father->ElGradient = NewGradDef ();
  grad = (GradDef *) father->ElGradient;
  
  seek = grad->next;
  while (seek)
    {
      if (seek->el == el)
        return seek;
      previous = seek;
      seek = seek->next;
    }
  seek = NewRgbaDef (el);
  if (previous)
    previous->next = seek;
  else
    grad->next = seek;
  
  return seek;
}
#endif /*_GL*/


/*----------------------------------------------------------------------
  ---------------------------------------------------------------------- */
void AddStopColor (Element el, PtrElement Father, 
                   unsigned short red, unsigned short green, unsigned short blue)
{
#ifdef _GL
  RgbaDef *stop_grad;
  
  stop_grad = GetStopRef (el, Father);
  stop_grad->r = red;
  stop_grad->g = green;
  stop_grad->b = blue;
  stop_grad->a = 255;
#endif /* _GL */
}

void AddOffset (Element el, PtrElement Father, float offset)
{
#ifdef _GL
  RgbaDef *Stop;
  
  Stop = GetStopRef (el, Father);
  Stop->length = offset;
#endif /* _GL */
}

/*----------------------------------------------------------------------
  TtaSetLinearx1Gradient
  ----------------------------------------------------------------------*/
void TtaSetLinearx1Gradient (int value, Element el)
{
#ifdef _GL
  GradDef *grad;
  
  grad = GetGradientRef ((PtrElement) TtaGetParent (el));
  grad->x1 = value;
#endif /* _GL */
}

/*----------------------------------------------------------------------
  TtaSetLineary1Gradient
  ----------------------------------------------------------------------*/
void TtaSetLineary1Gradient (int value, Element el)
{
#ifdef _GL
  GradDef *grad;
  
  grad = GetGradientRef ((PtrElement) TtaGetParent (el));
  grad->y1 = value;
#endif /* _GL */
}

/*----------------------------------------------------------------------
  TtaSetLinearx2Gradient
  ----------------------------------------------------------------------*/
void TtaSetLinearx2Gradient (int value, Element el)
{
#ifdef _GL
  GradDef *grad;
  
  grad = GetGradientRef ((PtrElement) TtaGetParent (el));
  grad->x2 = value;
#endif /* _GL */
}

/*----------------------------------------------------------------------
  TtaSetLineary2Gradient
  ----------------------------------------------------------------------*/
void TtaSetLineary2Gradient (int value, Element el)
{
#ifdef _GL
  GradDef *grad;
  
  grad = GetGradientRef ((PtrElement) TtaGetParent (el));
  grad->y2 = value;
#endif /* _GL */
}

/*----------------------------------------------------------------------
  TtaSetStopColorGradient
  ----------------------------------------------------------------------*/
void TtaSetStopColorGradient (unsigned short red, unsigned short green,
                              unsigned short blue, Element el)
{
#ifdef _GL
  AddStopColor (el, (PtrElement) (TtaGetParent(TtaGetParent(el))), red, green, blue);  
#endif /* _GL */
}

/*----------------------------------------------------------------------
  TtaSetStopOffsetColorGradient
  ----------------------------------------------------------------------*/
void TtaSetStopOffsetColorGradient (float offset, Element el)
{
#ifdef _GL
  AddOffset (el, (PtrElement)(TtaGetParent(TtaGetParent (el))),
             offset);  
#endif /* _GL */
}



/*----------------------------------------------------------------------
  TtaAppendTransform

  Appends a Transform at the end of a Graphics basic element
  Parameters:
  element: the Graphics element to be modified.
  transform: the transformation info to be appended.
  document: the document containing the element.
  ----------------------------------------------------------------------*/
void TtaAppendTransform (Element element, void *transform, 
                         Document document)
{
  PtrTransform       pPa, pPrevPa;
     
  UserErrorCode = 0;
  if (element == NULL)
    TtaError (ERR_invalid_parameter);
  else
    /* verifies the parameter document */
    if (document < 1 || document > MAX_DOCUMENTS)
      TtaError (ERR_invalid_document_parameter);
    else if (LoadedDocument[document - 1] == NULL)
      TtaError (ERR_invalid_document_parameter);
    else
      /* parameter document is correct */
      {
        if (element && transform)
          {
            pPa = ((PtrElement) element)->ElTransform;
            pPrevPa = NULL;
            while (pPa)
              {
                pPrevPa = pPa;
                pPa = pPa->Next;
              }
            if (pPrevPa == NULL)
              ((PtrElement) element)->ElTransform = (PtrTransform) transform;
            else
              pPrevPa->Next = (PtrTransform) transform;
          }
      }
}


/*----------------------------------------------------------------------
  TransformAddition
  Add A transformation to one already existing
  Parameters:
  Trans1: the Graphics element to be modified.
  Trans2: the new transform .
  ----------------------------------------------------------------------*/
static void TransformAddition (PtrTransform Trans1, PtrTransform Trans2)
{
  switch (Trans2->TransType)
    {
    case PtElBoxTranslate:
    case PtElScale:
    case PtElTranslate:
      Trans1->XScale += Trans2->XScale;
      Trans1->YScale += Trans2->YScale;
      break;
    case PtElRotate:
      Trans1->TrAngle += Trans2->TrAngle;	  
      Trans1->XRotate += Trans2->XRotate;	  
      Trans1->YRotate += Trans2->YRotate;	  
      break;
    case PtElMatrix:
      Trans1->AMatrix += Trans2->AMatrix;
      Trans1->BMatrix += Trans2->BMatrix;
      Trans1->CMatrix += Trans2->CMatrix;
      Trans1->DMatrix += Trans2->DMatrix;
      Trans1->EMatrix += Trans2->EMatrix;
      Trans1->FMatrix += Trans2->FMatrix;
      break;
    case PtElSkewX:
    case PtElSkewY: 
      Trans1->TrFactor = Trans2->TrFactor;	  
      break;
    case PtElViewBox:
      Trans1->VbXTranslate += Trans2->VbXTranslate;
      Trans1->VbYTranslate += Trans2->VbYTranslate;
      Trans1->VbWidth += Trans2->VbWidth;
      Trans1->VbHeight += Trans2->VbHeight;
      break;
    default:
      break;
    }
}
/*----------------------------------------------------------------------
  TtaAddTransform

  Insert or Add a Transform at the beginning of a Graphics basic element
  if a transformation of the same type exists in the list, it is replaced
  with old_value + delta

  Parameters:
  element: the Graphics element to be modified.
  transform: the transformation to be inserted.
  document: the document containing the element.
  ----------------------------------------------------------------------*/
void TtaAddTransform (Element element, void *transform, 
                      Document document)
{
  PtrTransform       pPa, pPrevPa;
     
  UserErrorCode = 0;
  if (element == NULL)
    TtaError (ERR_invalid_parameter);
  else
    /* verifies the parameter document */
    if (document < 1 || document > MAX_DOCUMENTS)
      TtaError (ERR_invalid_document_parameter);
    else if (LoadedDocument[document - 1] == NULL)
      TtaError (ERR_invalid_document_parameter);
    else
      /* parameter document is correct */
      {
        if (element && transform)
          {
            pPa = ((PtrElement) element)->ElTransform;
            pPrevPa = NULL;
            while (pPa)
              {
                if (pPa->TransType == ((PtrTransform)transform)->TransType)
                  {
                    TransformAddition (pPa, (Transform*)transform);
                    TtaFreeMemory (transform);
                    return;
                  }	       
                pPrevPa = pPa;
                pPa = pPa->Next;
              }

            if (pPrevPa == NULL)
              ((PtrElement) element)->ElTransform = (PtrTransform) transform;
            else
              pPrevPa->Next = (PtrTransform) transform;

          }
      }
}

/*----------------------------------------------------------------------
  TtaInsertTransform

  Insert a Transform at the beginning of a Graphics basic element
  Parameters:
  element: the Graphics element to be modified.
  transform: the Transformation to be inserted.
  document: the document containing the element.
  ----------------------------------------------------------------------*/
void TtaInsertTransform (Element element, void *transform, 
                         Document document)
{
  PtrTransform       pPa;
     
  UserErrorCode = 0;
  if (element == NULL)
    TtaError (ERR_invalid_parameter);
  else
    /* verifies the parameter document */
    if (document < 1 || document > MAX_DOCUMENTS)
      TtaError (ERR_invalid_document_parameter);
    else if (LoadedDocument[document - 1] == NULL)
      TtaError (ERR_invalid_document_parameter);
    else
      /* parameter document is correct */
      {
        if (element && transform)
          {
            pPa = ((PtrElement) element)->ElTransform;
            ((PtrTransform) transform)->Next = pPa;
            ((PtrElement) element)->ElTransform = (PtrTransform) transform;
          }
      }
}

/*----------------------------------------------------------------------
  TtaSetElCoordinateSystem : make this element the start of a new
  coordinate system
  ----------------------------------------------------------------------*/
void TtaSetElCoordinateSystem (Element element)
{
  ((PtrElement)element)->ElSystemOrigin = TRUE;
}

/*----------------------------------------------------------------------
  TtaAppendAnim
  ----------------------------------------------------------------------*/
void TtaAppendAnim (Element element, void *anim)
{
  Animated_Element *a_list;
  
  if (((PtrElement)element)->ElParent)
    { 
      if (((PtrElement)element)->ElParent->ElAnimation)
        {
          a_list = (Animated_Element *)((PtrElement)element)->ElParent->ElAnimation;
          while (a_list->next)
            a_list = a_list->next;
          a_list->next = (Animated_Element *)anim;
        }
      else
        ((PtrElement)element)->ElParent->ElAnimation = anim; 
    }
}

/*----------------------------------------------------------------------
  TtaNewAnimPath
  create a new path segment defining the animation position

  Parameters:
  anim_seg: the animation path to be modified.
  doc: the path segment to be appended.
  ----------------------------------------------------------------------*/
void *TtaNewAnimPath (Document doc)
{
#ifdef _GL
  AnimPath *anim_seg;
  
  anim_seg = (AnimPath *)TtaGetMemory (sizeof (AnimPath));
  memset (anim_seg, 0, sizeof (AnimPath));
  return ((void *) anim_seg);
#else /* _GL */
  return NULL;
#endif /* _GL */
}

/*----------------------------------------------------------------------
  TtaAppendPathSegToAnim

  Appends a path segment at the end of an animation

  Parameters:
  animation: the animation to be modified.
  segment: the path segment to be appended.
  ----------------------------------------------------------------------*/
void TtaAppendPathSegToAnim (void *anim, PathSegment segment, Document doc)
{
#ifdef _GL
  PtrPathSeg       pPa, pPrevPa;

  if (anim)
    {
      pPa = ((AnimPath *) anim)->FirstPathSeg;
      pPrevPa = NULL;
      while (pPa)
        {
          pPrevPa = pPa;
          pPa = pPa->PaNext;
        }
      if (pPrevPa == NULL)
        ((AnimPath *) anim)->FirstPathSeg = (PtrPathSeg) segment;
      else
        {
          pPrevPa->PaNext = (PtrPathSeg) segment;
          ((PtrPathSeg) segment)->PaPrevious = pPrevPa;
        }
    }
  else
#endif /* _GL */
    FreePathSeg ((PtrPathSeg)segment);
}
/*----------------------------------------------------------------------
  TtaAnimPathAddPoint
  ----------------------------------------------------------------------*/
void TtaAnimPathAddPoint (void *anim, float x, float y)
{
#ifdef _GL
  ThotPoint  *points, *tmp;
  AnimPath *path;
  int size;

  if (anim)
    {
      path = (AnimPath *) anim;
      if (path->Path == NULL ||
          path->npoints == 0 ||
          path->npoints >= path->maxpoints)
        {
          /*realloc*/
          size = path->maxpoints + ALLOC_POINTS;
          if ((tmp = (ThotPoint*)realloc(path->Path, size * sizeof(ThotPoint))) ==0)
            return;
          else
            {
              /* la reallocation a reussi */
              path->Path = tmp;
              path->maxpoints = size;
            }
        }
      points = path->Path;
      points[path->npoints].x = x;
      points[path->npoints].y = y;
      path->npoints++;
    }
#endif /* _GL */
}
/*----------------------------------------------------------------------
  TtaAddAnimMotionPath
  ----------------------------------------------------------------------*/
void TtaAddAnimMotionPath (void *info, void *anim)
{    
#ifdef _GL
  ((Animated_Element *) anim)->from = info;
  populate_path_proportion ((Animated_Element *) anim);
#endif /* _GL */
}
/*----------------------------------------------------------------------
  TtaAddAnimMotionFromTo
  ----------------------------------------------------------------------*/
void TtaAddAnimMotionFromTo (void *info, void *anim)
{    
#ifdef _GL
  ((Animated_Element *) anim)->from = info;
  populate_fromto_proportion (anim);  
#endif /* _GL */ 
}
/*----------------------------------------------------------------------
  TtaAddAnimMotionValues
  ----------------------------------------------------------------------*/
void TtaAddAnimMotionValues (void *info, void *anim)
{    
#ifdef _GL
  ((Animated_Element *) anim)->from = info;
  populate_values_proportion (anim);  
#endif /* _GL */  
}
/*----------------------------------------------------------------------
  TtaSetAnimTypetoTransform
  ----------------------------------------------------------------------*/
void TtaSetAnimTypetoMotion (void *anim)
{
  ((Animated_Element *) anim)->AnimType = Motion;
}
/*----------------------------------------------------------------------
  TtaSetAnimTypetoTransform
  ----------------------------------------------------------------------*/
void TtaSetAnimTypetoTransform (void *anim)
{
  ((Animated_Element *) anim)->AnimType = Transformation;
}

/*----------------------------------------------------------------------
  TtaSetAnimTypetoAnimate
  ----------------------------------------------------------------------*/
void TtaSetAnimTypetoAnimate (void *anim)
{
  ((Animated_Element *) anim)->AnimType = Animate;
}

/*----------------------------------------------------------------------
  TtaSetAnimTypetoColor
  ----------------------------------------------------------------------*/
void TtaSetAnimTypetoColor (void *anim)
{
  ((Animated_Element *) anim)->AnimType = Color;
}

/*----------------------------------------------------------------------
  TtaSetAnimTypetoSet
  ----------------------------------------------------------------------*/
void TtaSetAnimTypetoSet (void *anim)
{
  ((Animated_Element *) anim)->AnimType = Set;
}

/*----------------------------------------------------------------------
  TtaSetAnimReplace : If anim replace the precedent transformation
  concering this attribute
  ----------------------------------------------------------------------*/
void TtaSetAnimReplace (void *anim, ThotBool is_replace)
{    
  ((Animated_Element *) anim)->replace = is_replace;
}
/*----------------------------------------------------------------------
  TtaAddAnimFrom
  ----------------------------------------------------------------------*/
void TtaAddAnimFrom (void *info, void *anim)
{    
  ((Animated_Element *) anim)->from = info;
}

/*----------------------------------------------------------------------
  TtaAddAnimFreeze
  ----------------------------------------------------------------------*/
void TtaAddAnimFreeze (void *anim)
{
  ((Animated_Element *) anim)->Fill = Freeze;
}

/*----------------------------------------------------------------------
  TtaAddAnimFillRemove
  ----------------------------------------------------------------------*/
void TtaAddAnimRemove (void *anim)
{      
  ((Animated_Element *) anim)->Fill = Otherfill;
}
/*----------------------------------------------------------------------
  TtaAddAnimRepeatCount
  ----------------------------------------------------------------------*/
void TtaAddAnimRepeatCount (int repeat, void *anim)
{
  ((Animated_Element *) anim)->repeatCount = repeat;
}

/*----------------------------------------------------------------------
  TtaAddAnimTo
  ----------------------------------------------------------------------*/
void TtaAddAnimTo (void *info, void *anim)
{    
  ((Animated_Element *) anim)->to = info;
}

/*----------------------------------------------------------------------
  TtaAddAnimTo
  ----------------------------------------------------------------------*/
void TtaAddAnimAttrName (void *info, void *anim)
{    
  ((Animated_Element *) anim)->AttrName = (char *)info;
}

/*----------------------------------------------------------------------
  TtaSetAnimationTime
  ----------------------------------------------------------------------*/
void TtaSetAnimationTime (void *anim_info, double start, double duration)
{    
  ((Animated_Element *) anim_info)->duration = duration;
  ((Animated_Element *) anim_info)->start = start;
}
#endif /* NODISPLAY */
/*----------------------------------------------------------------------
  TtaCopyPage

  Copies the page element source into the page element destination.
  Both page elements must be in an abstract tree.
  Parameters:
  destination: identifier of the page element to be modified.
  source : identifier of the source page element.
  ----------------------------------------------------------------------*/
void TtaCopyPage (Element destination, Element source)
{
  PtrElement          pS, pD;

  UserErrorCode = 0;
  pS = (PtrElement) source;
  pD = (PtrElement) destination;
  if (destination == NULL || source == NULL)
    TtaError (ERR_invalid_parameter);
  else if (!pD->ElTerminal || pD->ElLeafType != LtPageColBreak)
    TtaError (ERR_invalid_parameter);
  else if (!pS->ElTerminal ||
           pS->ElLeafType != LtPageColBreak)
    TtaError (ERR_invalid_parameter);
  else
    {
      pD->ElPageType = pS->ElPageType;
      pD->ElPageNumber = pS->ElPageNumber;
      pD->ElViewPSchema = pS->ElViewPSchema;
    }
}

/*----------------------------------------------------------------------
  GetImageDesc

  Returns a pointer to the  PictInfo structure that's associated with
  element. Returns NULL if element doesn't have such structure.
  ----------------------------------------------------------------------*/
static ThotPictInfo *GetImageDesc (Element element)
{
  PtrAbstractBox   pAb;
  PtrElement       pEl = (PtrElement) element;
  ThotPictInfo    *imageDesc;
  int              view;
  ThotBool         found;

  UserErrorCode = 0;
  imageDesc = NULL;

  if (pEl == NULL)
    TtaError (ERR_invalid_parameter);

  if (TypeHasException (ExcIsImg, pEl->ElTypeNumber, pEl->ElStructSchema))
    pEl = pEl->ElFirstChild;

  if (pEl == NULL)
    TtaError (ERR_invalid_parameter);
  else if (!pEl->ElTerminal)
    {
      view = 0;
      pAb = NULL;
      found = FALSE;
      do
        {
          pAb = pEl->ElAbstractBox[view];
          if (pAb != NULL)
            {
              while (pAb->AbPresentationBox)
                pAb = pAb->AbNext;
              /* the background exists or will exist soon */
              found = (pAb->AbPictBackground != NULL || pAb->AbAspectChange);
              if (found)
                imageDesc = (ThotPictInfo *) pAb->AbPictBackground;
              else
                {
                  found = (pAb->AbPictListStyle != NULL || pAb->AbAspectChange);
                  if (found)
                    imageDesc = (ThotPictInfo *) pAb->AbPictListStyle;
                }
            }
          view++;
        }
      while (!found && view < MAX_VIEW_DOC);

      if (!found)
        TtaError (ERR_invalid_element_type);
    }
  else if (pEl->ElTerminal && pEl->ElLeafType != LtPicture)
    TtaError (ERR_invalid_element_type);
  else
    imageDesc = (ThotPictInfo *) (pEl->ElPictInfo);
  return imageDesc;
}

/*----------------------------------------------------------------------
  TtaGivePictureSize
  Returns the original width and height of the picture.
  Parameter:
  element: the element of interest. This element must be a picture
  Return value:
  width and height of the image
  ----------------------------------------------------------------------*/
void TtaGivePictureSize (Element element, int *width, int *height)
{
  ThotPictInfo    *imageDesc;

  *width = *height = 0;
  imageDesc = GetImageDesc (element);
  if (imageDesc)
    {
      *width = imageDesc->PicWidth;
      *height = imageDesc->PicHeight;
    }
}

/*----------------------------------------------------------------------
  TtaGetPictureType
  Returns the type of Picture element.
  Parameter:
  element: the element of interest. This element must be a Picture or have
  a background image.
  Return value:
  PicType: type of the element.
  ----------------------------------------------------------------------*/
PicType TtaGetPictureType (Element element)
{
  PicType          pictType;
  ThotPictInfo    *imageDesc;
  int              typeImage;

  pictType = unknown_type;
  imageDesc = GetImageDesc (element);
  if (imageDesc)
    {
      typeImage = imageDesc->PicType;
      if (typeImage != unknown_type && typeImage != -1)
        pictType = (PicType) typeImage;
    }
  return pictType;
}

/*----------------------------------------------------------------------
  TtaSetPictureType
  Sets the type of a Picture element.
  Parameter:
  mime_type: mime type of an image.
  ----------------------------------------------------------------------*/
void TtaSetPictureType (Element element, char *mime_type)
{
  PicType          typeImage;
  ThotPictInfo    *imageDesc;

  if (!element || !mime_type || *mime_type == EOS)
    return;

  imageDesc = GetImageDesc (element);
  if (imageDesc)
    {
      if (!strcmp (mime_type, "image/x-bitmap"))
        typeImage = xbm_type;
      else if (!strcmp (mime_type, "application/postscript"))
        typeImage = eps_type;
      else if (!strcmp (mime_type, "image/x-xpixmap"))
        typeImage = eps_type;
      else if (!strcmp (mime_type, "image/gif"))
        typeImage = gif_type;
      else if (!strcmp (mime_type, "image/jpeg"))
        typeImage = jpeg_type;
      else if (!strcmp (mime_type, "image/png"))
        typeImage = png_type;
      else if (!strcmp (mime_type, "image/svg") ||
               !strcmp (mime_type, "image/svg+xml") ||
               !strcmp (mime_type, "application/svg+xml"))
        typeImage = svg_type;
      else if (!strcmp (mime_type, "text/html") ||
               !strcmp (mime_type, "application/xhtml+xml"))
        typeImage = html_type;
      else if (!strcmp (mime_type, "text/mml") ||
               !strcmp (mime_type, "application/mathml+xml"))
        typeImage = mathml_type;
      else 
        typeImage = unknown_type;
      imageDesc->PicType = typeImage;
    }
}


/*----------------------------------------------------------------------
  TtaGiveBufferContent

  Returns the content of a Text basic element as a string of CHAR_T
  characters.
  Parameters:
  element: the element of interest. This element must be a basic
  element of type Text.
  buffer: the buffer that will contain the returned string. This buffer
  must be at least of size length.
  The length corresponds to the buffer length.
  length: the maximum length of the string to be returned. Must be strictly
  positive.
  Return parameter:
  buffer: (the buffer contains the substring).
  language: language of the text.
  ----------------------------------------------------------------------*/
void TtaGiveBufferContent (Element element, CHAR_T *buffer, int length,
                           Language *language)
{
  PtrTextBuffer       pBuf;
  PtrElement          pEl;
  int                 len, l;

  UserErrorCode = 0;
  pEl = (PtrElement) element;
  if (pEl)
    *language = pEl->ElLanguage;
  else
    *language = TtaGetDefaultLanguage ();

  if (element == NULL)
    TtaError (ERR_invalid_parameter);
  else if (!pEl->ElTerminal)
    TtaError (ERR_invalid_element_type);
  else if (pEl->ElLeafType != LtText && pEl->ElLeafType != LtPicture)
    TtaError (ERR_invalid_element_type);
  else
    {
      len = 0;
      pBuf = pEl->ElText;
      while (pBuf != NULL && len < length - 1)
        {
          l = 0;
          if (length < len + pBuf->BuLength + 1)
            l = length - len;
          else
            l = pBuf->BuLength + 1;
          ustrncpy (&buffer[len], pBuf->BuContent, l);
          len = len + (l - 1);
          pBuf = pBuf->BuNext;
        }
    }
}

/*----------------------------------------------------------------------
  TtaSetBufferContent

  Changes the content of a Text basic element. The full content (if any) is
  deleted and replaced by the new one.
  Parameters:
  element: the Text element to be modified.
  content: new content for that element coded as a string of CHAR_T
  characters.
  language: language of that Text element.
  document: the document containing that element.
  ----------------------------------------------------------------------*/
void TtaSetBufferContent (Element element, CHAR_T *content,
                          Language language, Document document)
{
  PtrElement    pEl;
  PtrTextBuffer pBuf, prevBuf;
  int           remaining, length, delta, bulen, i;

  UserErrorCode = 0;
  pEl = NULL;
  if (element == NULL)
    TtaError (ERR_invalid_parameter);
  else if (!((PtrElement) element)->ElTerminal)
    TtaError (ERR_invalid_element_type);
  else if (((PtrElement) element)->ElLeafType != LtText)
    TtaError (ERR_invalid_element_type);
  else if (document < 1 || document > MAX_DOCUMENTS)
    TtaError (ERR_invalid_document_parameter);
  else if (LoadedDocument[document - 1] == NULL)
    TtaError (ERR_invalid_document_parameter);
  else
    {
      /* parameter document is correct */
      pEl = (PtrElement) element;
      pEl->ElLanguage = language;
      
      /* store the contents of the element */
      pBuf = pEl->ElText;
      if (content)
        length = ustrlen (content);
      else
        length = 0;
      if (length == 0)
        /* the new content of the element is null */
        {
          if (pBuf)
            {
              pBuf->BuContent[0] = EOS;
              pBuf->BuLength = 0;
              prevBuf = pBuf;
              pBuf = pBuf->BuNext;
            }
        }
      else
        {
          prevBuf = NULL;
          remaining = length;
          i = 0;
          while (remaining > 0)
            {
              if (!pBuf)
                /* create and initialize a new buffer */
                {
                  GetTextBuffer (&pBuf);
                  pBuf->BuNext = NULL;
                  if (prevBuf)
                    prevBuf->BuNext = pBuf;
                  else
                    pEl->ElText = pBuf;
                }
              if (remaining >= THOT_MAX_CHAR)
                /* the remaining length is longer than a single buffer */
                bulen = THOT_MAX_CHAR - 1;
              else
                bulen = remaining;
              ustrncpy (pBuf->BuContent, &content[i], bulen);
              i += bulen;
              pBuf->BuContent[bulen] = EOS;
              pBuf->BuLength = bulen;
              remaining -= bulen;
              prevBuf = pBuf;
              pBuf = pBuf->BuNext;
            }
        }

      /* free the remaining buffers, if any */
      if (pBuf && prevBuf)
        {
          prevBuf->BuNext = NULL;
          while (pBuf)
            {
              prevBuf = pBuf;
              pBuf = pBuf->BuNext;
              FreeTextBuffer (prevBuf);
            }
        }

      delta = length - pEl->ElTextLength;
      pEl->ElTextLength = length;
      pEl->ElVolume = length;

#ifndef NODISPLAY
      RedisplayLeaf (pEl, document, delta);
#endif /* NODISPLAY */

      /* Updates the volume of ancestors */
      if (delta != 0)
        {
          pEl = pEl->ElParent;
          while (pEl != NULL)
            {
              pEl->ElVolume += delta;
              pEl = pEl->ElParent;
            }
        }
    }
}


/*----------------------------------------------------------------------
  TtaGetFirstBufferContent

  Returns the first CHAR_T character of the string.
  Parameters:
  element: the element of interest. This element must be a basic
  element of type Text.
  Return parameter:
  buffer: the first character.
  ----------------------------------------------------------------------*/
CHAR_T TtaGetFirstBufferContent (Element element)
{
  PtrTextBuffer       pBuf;
  PtrElement          pEl;

  UserErrorCode = 0;
  pEl = (PtrElement) element;
  if (pEl == NULL)
    TtaError (ERR_invalid_parameter);
  else if (!pEl->ElTerminal)
    TtaError (ERR_invalid_element_type);
  else if (pEl->ElLeafType != LtText && pEl->ElLeafType != LtPicture)
    TtaError (ERR_invalid_element_type);
  else
    {
      pBuf = pEl->ElText;
      return pBuf->BuContent[0];
    }
  return EOS;
}


/*----------------------------------------------------------------------
  TtaGetLastBufferContent

  Returns the last CHAR_T character of the string.
  Parameters:
  element: the element of interest. This element must be a basic
  element of type Text.
  Return parameter:
  buffer: the last character.
  ----------------------------------------------------------------------*/
CHAR_T TtaGetLastBufferContent (Element element)
{
  PtrTextBuffer       pBuf;
  PtrElement          pEl;
  int                 length;

  UserErrorCode = 0;
  pEl = (PtrElement) element;
  if (pEl == NULL)
    TtaError (ERR_invalid_parameter);
  else if (!pEl->ElTerminal)
    TtaError (ERR_invalid_element_type);
  else if (pEl->ElLeafType != LtText && pEl->ElLeafType != LtPicture)
    TtaError (ERR_invalid_element_type);
  else
    {
      length = pEl->ElVolume - 1;
      pBuf = pEl->ElText;
      while (pBuf && pBuf->BuLength < length)
        {
          length -= pBuf->BuLength;
          pBuf = pBuf->BuNext;
        }
      if (pBuf)
        return pBuf->BuContent[length];
    }
  return EOS;
}


/*----------------------------------------------------------------------
  TtaGiveSubString

  Returns a substring from a Text basic element.
  Parameters:
  element: the element of interest. This element must be a basic
  element of type Text.
  buffer: the buffer that will contain the substring. This buffer
  must be at least of size length.
  In _I18N_ mode the length corresponds to the UTF-8 string.
  position: the rank of the first character of the substring.
  length: the length of the substring. Must be strictly positive.
  Return parameter:
  buffer: (the buffer contains the substring).
  In _I18N_ mode returns a UTF-8 string.
  ----------------------------------------------------------------------*/
void TtaGiveSubString (Element element, unsigned char *buffer, int position,
                       int length)
{
  PtrTextBuffer       pBuf;
  PtrElement          pEl;

  UserErrorCode = 0;
  pEl = (PtrElement) element;
  if (element == NULL)
    TtaError (ERR_invalid_parameter);
  else if (position < 1 || length < 1)
    TtaError (ERR_invalid_parameter);
  else if (!pEl->ElTerminal)
    TtaError (ERR_invalid_element_type);
  else if (pEl->ElLeafType != LtText &&
           pEl->ElLeafType != LtPicture)
    TtaError (ERR_invalid_element_type);
  else
    {
      pBuf = pEl->ElText;
      position--;
      /* skip previous buffers */
      while (pBuf && pBuf->BuLength <= position)
        {
          position -= pBuf->BuLength;
          pBuf = pBuf->BuNext;
        }
      /* copying into the buffer */
      length = CopyBuffer2MBs (pBuf, position, buffer, length);
    }
}

/*----------------------------------------------------------------------
  TtaGetGraphicsShape

  Returns the content of a Graphics or Symbol basic element.
  Parameter:
  element: the element of interest. This element must be a basic
  element of type Graphics or Symbol.
  Return value:
  a single character representing the shape of the graphics element or
  symbol contained in the element.
  ----------------------------------------------------------------------*/
char TtaGetGraphicsShape (Element element)
{
  PtrElement          pEl;
  char                content;

  UserErrorCode = 0;
  pEl = (PtrElement) element;
  content = EOS;
  if (element == NULL)
    TtaError (ERR_invalid_parameter);
  else if (!pEl->ElTerminal)
    TtaError (ERR_invalid_element_type);
  else if (pEl->ElLeafType != LtSymbol &&
           pEl->ElLeafType != LtGraphics &&
           pEl->ElLeafType != LtPolyLine)
    TtaError (ERR_invalid_element_type);
  else if (pEl->ElLeafType == LtPolyLine)
    content = pEl->ElPolyLineType;
  else
    content = pEl->ElGraph;
  return content;
}

/*----------------------------------------------------------------------
  TtaGetPolylineLength

  Returns the number of points in a Polyline basic element.
  Parameter:
  element: the Polyline element. This element must
  be a basic element of type Polyline.
  ----------------------------------------------------------------------*/
int TtaGetPolylineLength (Element element)
{
  UserErrorCode = 0;
  if (element == NULL)
    TtaError (ERR_invalid_parameter);
  else if (!((PtrElement) element)->ElTerminal)
    TtaError (ERR_invalid_element_type);
  else if (((PtrElement) element)->ElLeafType != LtPolyLine)
    TtaError (ERR_invalid_element_type);
  else
    /* one ignore the boundary point limite, considered in ElNPoints */
    return ((PtrElement) element)->ElNPoints - 1;
  return (0);
}

/*----------------------------------------------------------------------
  TtaGivePolylinePoint

  Returns the coordinates of a point in a Polyline basic element.

  Parameters:
  element: the Polyline element. This element must
  be a basic element of type Polyline.
  rank: rank of the point in the PloyLine. If rank is greater
  than the actual number of points, an error is raised.
  rank must be strictly positive.
  unit: UnPixel or UnPoint.

  Return values:
  x, y: coordinates of the point, in unit, relatively to
  the upper left corner of the enclosing rectangle.

  ----------------------------------------------------------------------*/
void TtaGivePolylinePoint (Element element, int rank, TypeUnit unit,
                           int *x, int *y)
{
  PtrTextBuffer       pBuff;

  UserErrorCode = 0;
  *x = 0;
  *y = 0;
  if (element == NULL)
    TtaError (ERR_invalid_parameter);
  else if (!((PtrElement) element)->ElTerminal)
    TtaError (ERR_invalid_element_type);
  else if (((PtrElement) element)->ElLeafType != LtPolyLine)
    TtaError (ERR_invalid_element_type);
  else if (unit != UnPoint && unit != UnPixel)
    TtaError (ERR_invalid_parameter);
  else
    {
      /* Looking for the buffer containing the point which rank is: rank */
      pBuff = ((PtrElement) element)->ElPolyLineBuffer;
      while (rank >= pBuff->BuLength && pBuff->BuNext != NULL)
        {
          rank -= pBuff->BuLength;
          pBuff = pBuff->BuNext;
        }
      if (rank > pBuff->BuLength)
        TtaError (ERR_invalid_parameter);
      else
        {
          *x = pBuff->BuPoints[rank].XCoord;
          *y = pBuff->BuPoints[rank].YCoord;
        }
    }
}


/*----------------------------------------------------------------------
  TtaGetPageNumber
  Returns the page number of a Page basic element.
  Parameter:
  pageElement: the page element.
  Return value:
  page number of that page element.
  ----------------------------------------------------------------------*/
int TtaGetPageNumber (Element pageElement)
{
  int                 pageNumber;

  UserErrorCode = 0;
  pageNumber = 0;
  if (pageElement == NULL)
    TtaError (ERR_invalid_parameter);
  else if (!((PtrElement) pageElement)->ElTerminal)
    TtaError (ERR_invalid_element_type);
  else if (((PtrElement) pageElement)->ElLeafType != LtPageColBreak)
    TtaError (ERR_invalid_element_type);
  else
    pageNumber = ((PtrElement) pageElement)->ElPageNumber;
  return pageNumber;
}

/*----------------------------------------------------------------------
  TtaGetPageView
  Returns the view corresponding to a Page basic element.
  Parameter:
  pageElement: the page element.
  Return value:
  view of that page.
  ----------------------------------------------------------------------*/
int TtaGetPageView (Element pageElement)
{
  int                 pageView;

  UserErrorCode = 0;
  pageView = 0;
  if (pageElement == NULL)
    TtaError (ERR_invalid_parameter);
  else if (!((PtrElement) pageElement)->ElTerminal)
    TtaError (ERR_invalid_element_type);
  else if (((PtrElement) pageElement)->ElLeafType != LtPageColBreak)
    TtaError (ERR_invalid_element_type);
  else
    pageView = ((PtrElement) pageElement)->ElViewPSchema;
  return pageView;
}

