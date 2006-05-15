/*
 *
 *  (c) COPYRIGHT INRIA, 1996-2005
 *  Please first read the full copyright statement in file COPYRIGHT.
 *
 */

/*
 * This module implements text commands.
 *
 * Authors: I. Vatton (INRIA)
 *          R. Guetari (W3C/INRIA) - Unicode and Windows version
 * Separation between structured and unstructured mode : S. Bonhomme (INRIA)
 *
 */

#ifdef _WX
#include "wx/wx.h"
#include "wx/clipbrd.h"
#endif /* _WX */

#include "thot_gui.h"
#include "thot_sys.h"
#include "libmsg.h"
#include "message.h"
#include "language.h"
#include "constmedia.h"
#include "typemedia.h"
#include "picture.h"
#include "appaction.h"
#include "appdialogue.h"

#ifdef _WX
#include "appdialogue_wx.h"
#include "message_wx.h"
#endif /* _WX */

#ifdef _GL
#include "glwindowdisplay.h"
#endif /*_GL*/


/* variables */
#undef THOT_EXPORT
#define THOT_EXPORT extern
#include "boxes_tv.h"
#include "frame_tv.h"
#include "edit_tv.h"
#include "select_tv.h"
#include "appdialogue_tv.h"

static ThotBool      RightExtended = FALSE;
static ThotBool      LeftExtended = FALSE;
static ThotBool      Retry = FALSE;
static ThotBool      Moving = FALSE;
static SearchContext WordSearchContext = {
  NULL, 0, NULL, 0, NULL, 0, TRUE, TRUE
};

/* cursor movement callback procedures for Math */
static Func     MathMoveForwardCursorFunction = NULL;
static Func     MathMoveBackwardCursorFunction = NULL;

#include "abspictures_f.h"
#include "applicationapi_f.h"
#include "appli_f.h"
#include "boxlocate_f.h"
#include "boxmoves_f.h"
#include "boxparams_f.h"
#include "boxselection_f.h"
#include "buildboxes_f.h"
#include "buildlines_f.h"
#include "callback_f.h"
#include "content_f.h"
#include "editcommands_f.h"
#include "exceptions_f.h"
#include "font_f.h"
#include "geom_f.h"
#include "hyphen_f.h"
#include "memory_f.h"
#include "picture_f.h"
#include "scroll_f.h"
#include "structmodif_f.h"
#include "structcreation_f.h"
#include "structselect_f.h"
#include "textcommands_f.h"
#include "tree_f.h"
#include "ustring_f.h"
#include "viewapi_f.h"
#include "views_f.h"
#include "windowdisplay_f.h"
#include "word_f.h"


/*----------------------------------------------------------------------
  IsTextLeaf teste si un pave est un pave de texte modifiable.     
  ----------------------------------------------------------------------*/
static ThotBool IsTextLeaf (PtrAbstractBox pave)
{
  ThotBool            result;

  if (pave == NULL)
    result = FALSE;
  else
    result = (!pave->AbPresentationBox || pave->AbCanBeModified) &&
      pave->AbLeafType == LtText;
  return result;
}


/*----------------------------------------------------------------------
  MoveInLine moves the text selection.
  The parameter frame gives the concerned frame.
  The parameter toend is TRUE when moving to the end of the line.
  The parameter extendSel is TRUE when the selection is extended.
  ----------------------------------------------------------------------*/
static void MoveInLine (int frame, ThotBool toend, ThotBool extendSel)
{
  PtrLine             pLine;
  PtrAbstractBox      pAb;
  PtrBox              pBox, ibox;
  int                 nChars;
  ViewSelection      *pViewSel;

  pViewSel = &ViewFrameTable[frame - 1].FrSelectionBegin;
  pLine = pViewSel->VsLine;
  nChars = 0;

  if (pLine == NULL)
    return;
  else if (toend)
    {
      /* get the last box in the line */
      if (pLine->LiLastPiece)
        pBox = pLine->LiLastPiece;
      else
        pBox = pLine->LiLastBox;
      ibox = pBox;
      while (ibox && ibox->BxAbstractBox->AbPresentationBox &&
             ibox != pLine->LiFirstPiece && ibox != pLine->LiFirstBox)
        /* try to select a box which is not a presentation box */
        ibox = ibox->BxPrevious;
      if (ibox && ibox != pBox)
        pBox = ibox;
      pAb = pBox->BxAbstractBox;
      if (IsTextLeaf (pAb))
        nChars = pBox->BxFirstChar + pBox->BxNChars;
    }
  else
    {
      if (pLine->LiFirstPiece)
        pBox = pLine->LiFirstPiece;
      else
        pBox = pLine->LiFirstBox;
      ibox = pBox;
      while (ibox && ibox->BxAbstractBox->AbPresentationBox &&
             ibox != pLine->LiLastPiece && ibox != pLine->LiLastBox)
        /* try to select a box which is not a presentation box */
        ibox = ibox->BxNext;
      if (ibox && ibox != pBox)
        pBox = ibox;
      pAb = pBox->BxAbstractBox;
      if (IsTextLeaf (pAb))
        nChars = pBox->BxFirstChar;
    }
  /* update the selection */
  ChangeSelection (frame, pAb, nChars, extendSel, !toend, FALSE, FALSE);
}


/*----------------------------------------------------------------------
  LocateLeafBox gets the box located at the position x+xDelta, y+yDelta.
  if the box is still the same (pFrom) the position is shifted by
  xDelta and yDelta.                     
  ----------------------------------------------------------------------*/
static void LocateLeafBox (int frame, View view, int x, int y, int xDelta,
                           int yDelta, PtrBox pFrom, ThotBool extendSel)
{
  ViewFrame          *pFrame;
  PtrBox              pBox, endBox;
  PtrTextBuffer       pBuffer;
  PtrAbstractBox      pAb;
  PtrFlow             pFlow = NULL;
  int                 index;
  int                 nbbl;
  int                 nChars, org;
  int                 h, w, doc;

  pFrame = &ViewFrameTable[frame - 1];
  if (pFrom != NULL)
    endBox = pFrom;
  else
    /* endBox = current selected box */
    endBox = pFrame->FrSelectionBegin.VsBox;

  /* skip presentation boxes */
  while (endBox->BxNext != NULL &&
         endBox->BxAbstractBox->AbPresentationBox &&
         /* constants */
         !endBox->BxAbstractBox->AbCanBeModified)
    endBox = endBox->BxNext;

  /* do we need to scroll the document */
  doc = FrameTable[frame].FrDoc;
  GetSizesFrame (frame, &w, &h);
  if (xDelta < 0 && pFrame->FrXOrg > 0 && x + xDelta < 0)
    TtcScrollLeft (doc, view);
  else if (xDelta > 0 && x + xDelta > pFrame->FrXOrg + w)
    TtcScrollRight (doc, view);
  else if (yDelta < 0 && pFrame->FrAbstractBox->AbBox->BxNext &&
           y + yDelta < pFrame->FrYOrg + pFrame->FrAbstractBox->AbBox->BxNext->BxYOrg)
    {
      /* try to select up to the top of the current displayed frame */
      do
        {
          /* scroll as long as the top of the view is not reached */
          org = endBox->BxYOrg;
          TtcLineUp (doc, view);
          /* update the new position */
          if (org != endBox->BxYOrg)
            y = y - org + endBox->BxYOrg;
        }
      while (y + yDelta < pFrame->FrYOrg &&
             /* we don't see the top of the box */
             (y < 0 ||
              /* the frame is not on the top of the concrete image */
              pFrame->FrYOrg > 0 ||
              /* we don't see the top of the document */
              pFrame->FrAbstractBox->AbTruncatedHead));
    }
  else if (yDelta > 0 && pFrame->FrAbstractBox->AbBox->BxPrevious &&
           (y + yDelta > pFrame->FrYOrg + h ||
            y + yDelta > pFrame->FrAbstractBox->AbBox->BxPrevious->BxYOrg + pFrame->FrAbstractBox->AbBox->BxPrevious->BxHeight))
    {
      /* try to select down to the bottom of the current displayed frame */
      do
        {
          /* scroll as long as the bottom of the view is not reached */
          org = endBox->BxYOrg;
          TtcLineDown (doc, view);
          /* update the new position */
          if (org != endBox->BxYOrg)
            y = y - org + endBox->BxYOrg;
        }
      while (y + yDelta > pFrame->FrYOrg + h &&
             /* we don't see the bottom of the box */
             (/* the frame is not on the top of the concrete image */
              pFrame->FrYOrg + h < pFrame->FrAbstractBox->AbBox->BxHeight ||
              /* we don't see the top of the document */
              pFrame->FrAbstractBox->AbTruncatedTail));
    }

  if ( RightExtended && yDelta < 0 &&
       (endBox->BxFirstChar + endBox->BxNChars == LastSelectedChar ||
        (endBox->BxFirstChar + endBox->BxNChars == LastSelectedElement->ElVolume + 1 &&
         LastSelectedChar == 0)) &&
       x < endBox->BxXOrg + endBox->BxH + endBox->BxLMargin + endBox->BxLBorder + endBox->BxLPadding)
    /* stay in the same box */
    pBox = endBox;
  else
    {
#ifdef _GL
      x -= pFrame->FrXOrg;
      y -= pFrame->FrYOrg;
#endif /* _GL */
      pBox = GetLeafBox (endBox, frame, &x, &y, xDelta, yDelta, &pFlow);
    }

  if (pBox)
    {
      pAb = pBox->BxAbstractBox;
      if (pAb)
        {
          if (IsTextLeaf (pAb))
            {
#ifdef _GL
              if (pBox->BxBoundinBoxComputed)
                x -= pBox->BxClipX;
              else
                x -= pBox->BxXOrg + pFrame->FrXOrg;
#else /* _GL */
              x -= pBox->BxXOrg;
#endif /* _GL */
              LocateClickedChar (pBox, extendSel, &pBuffer, &x, &index,
                                 &nChars, &nbbl);
              if (LeftExtended && nChars > 0 && nChars <= pBox->BxNChars)
                nChars--;
              nChars = pBox->BxFirstChar + nChars;
              if (extendSel && yDelta > 0 &&
                  pAb->AbElement == LastSelectedElement &&
                  LastSelectedElement &&
                  nChars <= LastSelectedChar)
                nChars = LastSelectedElement->ElVolume + 1;
            }
          else
            nChars = 0;
          /* Change the selection */
          if (extendSel)
            ChangeSelection (frame, pAb, nChars, TRUE, LeftExtended, FALSE, FALSE);
          else
            ChangeSelection (frame, pAb, nChars, FALSE, TRUE, FALSE, FALSE);
        }
    }
}

/*----------------------------------------------------------------------
  TtaSetMoveForwardCallback permet de connecter une fonction de
  l'application a la touche de deplacement du curseur vers l'avant
  ----------------------------------------------------------------------*/
void  TtaSetMoveForwardCallback (Func callbackFunc)
{
  MathMoveForwardCursorFunction = callbackFunc;
}

/*----------------------------------------------------------------------
  TtaSetMoveBackwardCallback permet de connecter une fonction de
  l'application a la touche de deplacement du curseur vers l'arriere
  ----------------------------------------------------------------------*/
void  TtaSetMoveBackwardCallback (Func callbackFunc)
{
  MathMoveBackwardCursorFunction = callbackFunc;
}

/*----------------------------------------------------------------------
  Commandes de deplacement                                           
  ----------------------------------------------------------------------*/
static void MovingCommands (int code, Document doc, View view,
                            ThotBool extendSel)
{
  PtrBox              pBox, pBoxBegin, pBoxEnd, ibox;
  PtrElement          pEl = NULL, firstEl, lastEl;
  PtrLine             pLine;
  ViewFrame          *pFrame;
  ViewSelection      *pViewSel;
  ViewSelection      *pViewSelEnd;
  CHAR_T              word[MAX_WORD_LEN];
  int                 frame, x, y, i;
  int                 xDelta, yDelta;
  int                 h, w;
  int                 indpos, xpos;
  int                 first, last;
  int                 firstC, lastC;
  ThotBool            done, top = TRUE;

  indpos = 0;
  xpos = 0;
  CloseTextInsertion ();
  frame = GetWindowNumber (doc, view);
  if (frame > 0)
    {
      pFrame = &ViewFrameTable[frame - 1];
      /* reformat the current paragraph if necessary */
      CloseParagraphInsertion (pFrame->FrAbstractBox, frame);
      pViewSel = &(pFrame->FrSelectionBegin);
      pViewSelEnd = &(pFrame->FrSelectionEnd);
      /* beginning of the selection */
      pBoxBegin = pViewSel->VsBox;
      if (pBoxBegin)
        {
          xpos = pViewSel->VsXPos;
          while (pBoxBegin &&
                 (pBoxBegin->BxType == BoGhost ||
                  pBoxBegin->BxType == BoFloatGhost) &&
                 pBoxBegin->BxAbstractBox &&
                 pBoxBegin->BxAbstractBox->AbFirstEnclosed)
            /* the real selection is on child elements */
            pBoxBegin = pBoxBegin->BxAbstractBox->AbFirstEnclosed->AbBox;
        }
      
      /* end of the selection */
      pBoxEnd = pViewSelEnd->VsBox;
      if (pBoxEnd != NULL)
        {
          while (pBoxEnd &&
                 (pBoxEnd->BxType == BoGhost ||
                  pBoxEnd->BxType == BoFloatGhost) &&
                 pBoxEnd->BxAbstractBox &&
                 pBoxEnd->BxAbstractBox->AbFirstEnclosed)
            {
              /* the real selection is on child elements */
              pBoxEnd = pBoxEnd->BxAbstractBox->AbFirstEnclosed->AbBox;
              /* take the last child into account */
              while (pBoxEnd->BxAbstractBox->AbNext != NULL)
                pBoxEnd = pBoxEnd->BxAbstractBox->AbNext->AbBox;
              while (pBoxEnd->BxAbstractBox->AbPrevious != NULL &&
                     pBoxEnd->BxAbstractBox->AbPresentationBox)
                pBoxEnd = pBoxEnd->BxAbstractBox->AbPrevious->AbBox;
            }
        }

      /* Check if boxes are visible */
      GetSizesFrame (frame, &w, &h);
      if (!RightExtended && !LeftExtended)
        {
          if (pBoxBegin &&
              (pBoxBegin->BxYOrg + pBoxBegin->BxHeight <= pFrame->FrYOrg ||
               pBoxBegin->BxYOrg >= pFrame->FrYOrg + h))
            {
              /* the element is not displayed within the window */
              top = pBoxBegin->BxYOrg + pBoxBegin->BxHeight <= pFrame->FrYOrg;
              pBoxBegin = NULL;
            }
          if (pBoxEnd != NULL &&
              (pBoxEnd->BxYOrg + pBoxEnd->BxHeight <= pFrame->FrYOrg ||
               pBoxEnd->BxYOrg >= pFrame->FrYOrg + h))
            /* the element is not displayed within the window */
            pBoxEnd = NULL;
        }
      if (pBoxBegin == NULL && pBoxEnd != NULL)
        pBoxBegin = pBoxEnd;
      else if (pBoxBegin != NULL && pBoxEnd == NULL)
        pBoxEnd = pBoxBegin;

      pBox = pBoxBegin;
      if (pBox == NULL)
        {
          if (!Retry)
            {
              /* initialize a selection and retry */
              Retry = TRUE;
              ClickX = 0;
              if (top)
                ClickY = 0;
              else
                ClickY = h;
              LocateSelectionInView (frame, 0, ClickY, 2);
              Retry = FALSE;
              return;
            }
          else
            pBox = NULL;
        }
      /* avoid to process two moving commands at the same time */
      if (Moving)
        return;
      else
        Moving = TRUE;
      if (DocSelectedAttr)
        {
          /* work within an attribute */
          firstC = FirstSelectedCharInAttr;
          lastC = LastSelectedCharInAttr;
          firstEl = NULL;
          lastEl = NULL;
        }
      else
        {
          firstC = FirstSelectedChar;
          lastC = LastSelectedChar;
          firstEl = FirstSelectedElement;
          lastEl = LastSelectedElement;
          if (firstC == lastC && firstC == 0 && firstEl == lastEl)
            lastC = firstEl->ElVolume + 1;
        }
      /* could we shrink the current extended selection */
      if (extendSel)
        {
          if (firstC == lastC &&
              firstEl == lastEl &&
              SelPosition)
            {
              RightExtended = FALSE;
              LeftExtended = FALSE;
            }
          else if (!RightExtended && !LeftExtended)
            {
              if (firstEl == FixedElement &&
                  firstC == FixedChar)
                {
                  RightExtended = TRUE;
                  LeftExtended = FALSE;
                }
              else
                {
                  RightExtended = FALSE;
                  LeftExtended = TRUE;
                }
            }
        }
      /* Check if a previous extension was closed */
      if (SelPosition)
        {
          RightExtended = FALSE;
          LeftExtended = FALSE;
        }
      /* doesn't change the current Shrink value in other cases */
      switch (code)
        {
        case 1:	/* Backward one character (<-) */
          if (pBox)
            {
              done = FALSE;
              pEl = pBox->BxAbstractBox->AbElement;
              if (pBox->BxAbstractBox->AbPresentationBox)
                /* the selection is within an attribute value */
                done = FALSE;
              else if (!strcmp(pEl->ElStructSchema->SsName, "MathML") &&
                       MathMoveBackwardCursorFunction != NULL)
                done = MathMoveBackwardCursorFunction ();
              else if (!strcmp (pEl->ElStructSchema->SsName, "SVG") &&
                       (!pEl->ElTerminal || pEl->ElLeafType != LtText))
                {
                  TtcPreviousElement (doc, view);
                  done = TRUE;
                }
              if (!done)
                {
                  if (extendSel && RightExtended)
                    {
                      /* move the right extremity */
                      pBox = pBoxEnd;
                      x = lastC;
                      xpos = pViewSelEnd->VsXPos;
                    }
                  else
                    /* move the left extremity */
                    x = firstC;
                  if (x > 1)
                    {
                      if (extendSel)
                        {
                          if (RightExtended && firstC == lastC - 1 &&
                              firstEl == lastEl)
                            {
                              /* a single insert point */
                              ChangeSelection (frame, pBox->BxAbstractBox, FixedChar,
                                               FALSE, TRUE, FALSE, FALSE);
                              RightExtended = FALSE;
                            }
                          else if (SelPosition &&
                                   firstC == lastC &&
                                   firstEl == lastEl)
                            {
                              /* select one character */
                              LeftExtended = TRUE;
                              ChangeSelection (frame, pBox->BxAbstractBox, x - 1,
                                               TRUE, LeftExtended, FALSE, FALSE);
                            }
                          else
                            /* extend the selection */
                            ChangeSelection (frame, pBox->BxAbstractBox, x - 1,
                                             TRUE, LeftExtended, FALSE, FALSE);
                        }
                      else
                        /* the x is equal to first */
                        ChangeSelection (frame, pBox->BxAbstractBox, x - 1,
                                         FALSE, TRUE, FALSE, FALSE);
                      /* show the beginning of the selection */
                      if (pBoxBegin->BxXOrg + pViewSel->VsXPos + 4 < pFrame->FrXOrg)
                        {
                          if (pFrame->FrXOrg > 0)
                            TtcScrollLeft (doc, view);
                        }
                      else if (pBoxBegin->BxXOrg + pViewSel->VsXPos > pFrame->FrXOrg + w)
                        HorizontalScroll (frame, pBoxBegin->BxXOrg + pViewSel->VsXPos - pFrame->FrXOrg - w, 0);
                    }
                  else if (pBox->BxPrevious)
                    {
                      /* a new box before will be selected */
                      ibox = pBox->BxPrevious;
                      while (ibox &&
                             (ibox->BxAbstractBox->AbPresentationBox ||
                              TypeHasException (ExcNoSelect,
                                                ibox->BxAbstractBox->AbElement->ElTypeNumber,
                                                ibox->BxAbstractBox->AbElement->ElStructSchema)))
                        ibox = ibox->BxPrevious;
                      if (ibox)
                        {
                          /* check if boxes are within the same line */
                          pLine = SearchLine (pBox, frame);
                          if (pLine && pLine == SearchLine (ibox, frame))
                            {
                              /* moving to the beginning of the current box */
#ifdef _GL
                              if (pBox->BxBoundinBoxComputed)
                                {
                                  x = pBox->BxClipX + xpos + pFrame->FrXOrg;
                                  if (pBox->BxScript == 'A' ||
                                      pBox->BxScript == 'H')
                                    x += pBox->BxClipW + 2;
                                  y = pBox->BxClipY + (pBox->BxClipH / 2) + pFrame->FrYOrg;
                                }
                              else
#endif /* _GL */
                                {
                                  x = pBox->BxXOrg + xpos;
                                  if (pBox->BxScript == 'A' ||
                                      pBox->BxScript == 'H')
                                    x += pBox->BxWidth + 2;
                                  y = pBox->BxYOrg + (pBox->BxHeight / 2);
                                }
                            }
                          else
                            {
                              /* moving to the end of the previous box */
#ifdef _GL
                              if (pBox->BxBoundinBoxComputed)
                                {
                                  x = ibox->BxClipX + pFrame->FrXOrg;
                                  if (ibox->BxScript != 'A' &&
                                      ibox->BxScript != 'H')
                                    x += ibox->BxClipW + 2;
                                  y = ibox->BxClipY + (pBox->BxClipH / 2) + pFrame->FrYOrg;
                                }
                              else
#endif /* _GL */
                                {
                                  x = ibox->BxXOrg;
                                  if (ibox->BxScript != 'A' &&
                                      ibox->BxScript != 'H')
                                    x += ibox->BxWidth + 2;
                                  y = ibox->BxYOrg + (pBox->BxHeight / 2);
                                }
                            }
                          xDelta = -2;
                          LocateLeafBox (frame, view, x, y, xDelta, 0, pBox, extendSel);
                        }
                    }
                }
            }
          /* Get the last X position */
#ifdef _GL
          if (pBoxBegin->BxBoundinBoxComputed)
            ClickX = pBoxBegin->BxClipX + pViewSel->VsXPos;
          else
#endif /* _GL */
            ClickX = pBoxBegin->BxXOrg + pViewSel->VsXPos - pFrame->FrXOrg;
          break;
	  
        case 2:	/* Forward one character (->) */
          if (pBox)
            {
              done = FALSE;
              pEl = pBox->BxAbstractBox->AbElement;
              if (pBox->BxAbstractBox->AbPresentationBox)
                /* the selection is within an attribute value */
                done = FALSE;
              else if (!strcmp(pEl->ElStructSchema->SsName, "MathML") &&
                       MathMoveForwardCursorFunction != NULL)
                done = MathMoveForwardCursorFunction ();
              else if (!strcmp (pEl->ElStructSchema->SsName, "SVG") &&
                       (!pEl->ElTerminal || pEl->ElLeafType != LtText))
                {
                  TtcNextElement (doc, view);
                  done = TRUE;
                }
              if (!done)
                {
                  if (!extendSel || !LeftExtended)
                    {
                      /* move the right extremity */
                      pBox = pBoxEnd;
                      pEl = pBox->BxAbstractBox->AbElement;
                      if ((!extendSel && pViewSelEnd->VsBox &&
                           (pViewSelEnd->VsBox->BxType == BoGhost ||
                            pViewSelEnd->VsBox->BxType == BoFloatGhost)) ||
                          (pBox->BxAbstractBox &&
                           pBox->BxAbstractBox->AbLeafType == LtCompound) ||
                          (pEl->ElStructSchema->SsRule->SrElem[pEl->ElTypeNumber - 1]->SrConstruct == CsConstant))
                        {
                          if (pBox->BxNChars)
                            x =  pBox->BxNChars;
                          else
                            x = 1;
                        }
                      else
                        x = lastC;
                    }
                  else
                    /* move the left extremity */
                    x = firstC;
                  if (x <= pBox->BxAbstractBox->AbBox->BxNChars)
                    {
                      if (extendSel)
                        {
                          if (LeftExtended && firstC == lastC - 1 &&
                              firstEl == lastEl)
                            {
                              /* a single insert point */
                              LeftExtended = FALSE;
                              ChangeSelection (frame, pBox->BxAbstractBox, FixedChar,
                                               FALSE, TRUE, FALSE, FALSE);
                            }
                          else if (SelPosition &&
                                   firstC == lastC &&
                                   firstEl == lastEl)
                            {
                              /* select one character */
                              RightExtended = TRUE;
                              ChangeSelection (frame, pBox->BxAbstractBox, x + 1,
                                               TRUE, LeftExtended, FALSE, FALSE);
                            }
                          else
                            /* extend the end of the current selection */
                            ChangeSelection (frame, pBox->BxAbstractBox, x + 1,
                                             TRUE, LeftExtended, FALSE, FALSE);
                        }
                      else
                        ChangeSelection (frame, pBox->BxAbstractBox, x + 1,
                                         FALSE, TRUE, FALSE, FALSE);
                      /* show the end of the selection */
                      if (pBoxEnd->BxXOrg + pViewSelEnd->VsXPos > pFrame->FrXOrg + w)
                        {
                          if (FrameTable[frame].FrScrollOrg + FrameTable[frame].FrScrollWidth > pFrame->FrXOrg + w)
                            TtcScrollRight (doc, view);
                        }
                      else if (pBoxEnd->BxXOrg + pViewSelEnd->VsXPos - 4 < pFrame->FrXOrg)
                        HorizontalScroll (frame, pBoxEnd->BxXOrg + pViewSelEnd->VsXPos - 4 - pFrame->FrXOrg, 0);
                    }
                  else if (pBox->BxNext)
                    {
                      /* a new box after will be selected */
                      ibox = pBox->BxNext;
                      while (ibox &&
                             (ibox->BxAbstractBox->AbPresentationBox ||
                              TypeHasException (ExcNoSelect,
                                                ibox->BxAbstractBox->AbElement->ElTypeNumber,
                                                ibox->BxAbstractBox->AbElement->ElStructSchema)))
                        ibox = ibox->BxNext;
                      if (ibox)
                        {
                          /* check if boxes are within the same line */
                          pLine = SearchLine (pBox, frame);
                          if (pLine && pLine == SearchLine (ibox, frame))
                            {
                              /* moving to the end of the current box */
#ifdef _GL
                              if (pBox->BxBoundinBoxComputed)
                                {
                                  x = pBox->BxClipX + pFrame->FrXOrg;
                                  if (pBox->BxScript != 'A' &&
                                      pBox->BxScript != 'H')
                                    x += pBox->BxClipW;
                                  else
                                    x -= 2;
                                  y = pBox->BxClipY + (pBox->BxClipH / 2) + pFrame->FrYOrg;
                                }
                              else
#endif /* _GL */
                                {
                                  x = pBox->BxXOrg;
                                  if (pBox->BxScript != 'A' &&
                                      pBox->BxScript != 'H')
                                    x += pBox->BxWidth;
                                  else
                                    x -= 2;
                                  y = pBox->BxYOrg + (pBox->BxHeight / 2);
                                }
                            }
                          else
                            {
                              /* moving to the beginning of the next box */
#ifdef _GL
                              if (pBox->BxBoundinBoxComputed)
                                {
                                  x = ibox->BxClipX + pFrame->FrXOrg;
                                  if (ibox->BxScript == 'A' ||
                                      ibox->BxScript == 'H')
                                    x += ibox->BxClipW;
                                  else
                                    x -= 2;
                                  y = ibox->BxClipY + pFrame->FrYOrg;
                                }
                              else
#endif /* _GL */
                                {
                                  x = ibox->BxXOrg;
                                  if (ibox->BxScript == 'A' ||
                                      ibox->BxScript == 'H')
                                    x += ibox->BxWidth;
                                  else
                                    x -= 2;
                                  y = ibox->BxYOrg;
                                }

                            }
                          xDelta = 2;
                          LocateLeafBox (frame, view, x, y, xDelta, 0, pBox, extendSel);
                        }
                    }
                }
            }
          /* Get the last X position */
#ifdef _GL
          if (pBoxBegin->BxBoundinBoxComputed)
            ClickX = pBoxBegin->BxClipX + pViewSel->VsXPos;
          else
#endif /* _GL */
            ClickX = pBoxBegin->BxXOrg + pViewSel->VsXPos - pFrame->FrXOrg;
          break;

        case 3:	/* End of line (^E) */
          if (AbsBoxSelectedAttr)
            {
              i = AbsBoxSelectedAttr->AbVolume + 1;
              if (extendSel)
                {
                  if (LeftExtended && FixedChar != i)
                    {
                      /* change the extension direction */
                      RightExtended = TRUE;
                      LeftExtended = FALSE;
                    }
                  ChangeSelection (frame, AbsBoxSelectedAttr, i,
                                   TRUE, LeftExtended, FALSE, FALSE);
                }
              else
                SelectStringInAttr (LoadedDocument[doc - 1], AbsBoxSelectedAttr,
                                    i, i-1, FALSE);
            }
          else
            {
              if (pBox)
                MoveInLine (frame, TRUE, extendSel);
              if (pViewSel->VsBox)
                /* Get the last X position */
#ifdef _GL
                if (pViewSel->VsBox->BxBoundinBoxComputed)
                  ClickX = pViewSel->VsBox->BxClipX + pViewSel->VsXPos;
                else
#endif /* _GL */
                  ClickX = pViewSel->VsBox->BxXOrg + pViewSel->VsXPos - pFrame->FrXOrg;
            }
          break;
	   
        case 4:	/* Beginning of line (^A) */
          if (AbsBoxSelectedAttr)
            {
              i = 1;
              if (extendSel)
                {
                  if (!LeftExtended && FixedChar != i)
                    {
                      /* change the extension direction */
                      RightExtended = FALSE;
                      LeftExtended = TRUE;
                    }
                  ChangeSelection (frame, AbsBoxSelectedAttr, i,
                                   TRUE, LeftExtended, FALSE, FALSE);
                }
              else
                SelectStringInAttr (LoadedDocument[doc - 1], AbsBoxSelectedAttr,
                                    i, i-1, FALSE);
            }
          else
            {
              if (pBox)
                MoveInLine (frame, FALSE, extendSel);
              if (pViewSel->VsBox)
                /* Get the last X position */
#ifdef _GL
                if (pViewSel->VsBox->BxBoundinBoxComputed)
                  ClickX = pViewSel->VsBox->BxClipX + pViewSel->VsXPos;
                else
#endif /* _GL */
                  ClickX = pViewSel->VsBox->BxXOrg + pViewSel->VsXPos - pFrame->FrXOrg;
            }
          break;
	   
        case 7:	/* Next line (^N) */
          if (AbsBoxSelectedAttr)
            {
              /* ignore extensions */
              extendSel = FALSE;
              LeftExtended = FALSE;
              RightExtended = FALSE;
            }
          if (pBox)
            pEl = pBox->BxAbstractBox->AbElement;
          if (pBox && !pBox->BxAbstractBox->AbPresentationBox &&
              pEl && !strcmp (pEl->ElStructSchema->SsName, "SVG") &&
              (!pEl->ElTerminal || pEl->ElLeafType != LtText))
            /* the selection is not  within an attribute value */
            TtcNextElement (doc, view);
          else if (pBox)
            {
              done = FALSE;
              pBox = pBoxEnd;
#ifdef _GL
              if (pBox->BxBoundinBoxComputed)
                {
                  if (SelPosition || RightExtended)
                    x = pViewSel->VsXPos + pBoxBegin->BxClipX + pFrame->FrXOrg;
                  else
                    x = pViewSelEnd->VsXPos + pBox->BxClipX + pFrame->FrXOrg;
                  y = pBox->BxClipY + pBox->BxClipH + pFrame->FrYOrg;
                }
              else
#endif /* _GL */
                {
                  if (SelPosition || RightExtended)
                    x = pViewSel->VsXPos + pBoxBegin->BxXOrg;
                  else
                    x = pViewSelEnd->VsXPos + pBox->BxXOrg;
                  y = pBox->BxYOrg + pBox->BxHeight;
                }
              yDelta = 10;
              /* store the end position of the selection as the new reference */
              if (extendSel && LeftExtended)
                {
                  i = pBoxEnd->BxYOrg - pBoxBegin->BxYOrg;
                  if (i < 15 /* less than 150% of yDelta */)
                    {
                      /* no more extension */
                      LeftExtended = FALSE;
                      extendSel = FALSE;
                      ChangeSelection (frame, pBox->BxAbstractBox, FixedChar,
                                       FALSE, TRUE, FALSE, FALSE);
                      done = TRUE;
                    }
                  else
                    {
                      /* just decrease the current extension */
                      pBox = pBoxBegin;
#ifdef _GL
                      if (pBox->BxBoundinBoxComputed)
                        {
                          y = pBox->BxClipY + pFrame->FrYOrg;
                          x = ClickX + pFrame->FrXOrg;;
                        }
                      else
#endif /* _GL */
                        {
                          y = pBox->BxYOrg;
                          x = ClickX + pFrame->FrXOrg;
                        }
                    }
                }
              /* there was a drag, but it's finished now */
              else if (!extendSel)
                {
                  if (!SelPosition &&
                      (pBoxBegin != pBoxEnd ||
                       !IsConstantConstructor (pBox->BxAbstractBox->AbElement)))
                    /* changing from an extension to a simple selection */
                    ClickX = x - pFrame->FrXOrg;
                  else
                    x = ClickX + pFrame->FrXOrg;
                }
              else
                RightExtended = TRUE;
              if (!done)
                LocateLeafBox (frame, view, x, y, 0, yDelta, pBox, extendSel);
            }
          break;
	   
        case 8:	/* Previous line (^P) */
          if (AbsBoxSelectedAttr)
            {
              /* ignore extensions */
              extendSel = FALSE;
              LeftExtended = FALSE;
              RightExtended = FALSE;
            }
          if (pBox)
            pEl = pBox->BxAbstractBox->AbElement;
          if (pBox && !pBox->BxAbstractBox->AbPresentationBox &&
              pEl && !strcmp (pEl->ElStructSchema->SsName, "SVG") &&
              (!pEl->ElTerminal || pEl->ElLeafType != LtText))
            TtcPreviousElement (doc, view);
          else if (pBox)
            {
              done = FALSE;
#ifdef _GL
              if (pBoxBegin->BxBoundinBoxComputed)
                {
                  y = pBoxBegin->BxClipY + pFrame->FrYOrg;
                  if (SelPosition || RightExtended)
                    x = pViewSel->VsXPos + pBoxBegin->BxClipX + pFrame->FrXOrg;
                  else
                    x = pViewSelEnd->VsXPos + pBoxEnd->BxClipX + pFrame->FrXOrg;
                }
              else
#endif /* _GL */
                {
                  y = pBoxBegin->BxYOrg;
                  if (SelPosition || RightExtended)
                    x = pViewSel->VsXPos + pBoxBegin->BxXOrg;
                  else
                    x = pViewSelEnd->VsXPos + pBoxEnd->BxXOrg;
                }
              yDelta = -10;
              if (extendSel && RightExtended)
                {
                  i = pBoxEnd->BxYOrg - pBoxBegin->BxYOrg;
                  if (i < 15 /* less than 150% of yDelta */)
                    {
                      /* no more extension */
                      RightExtended = FALSE;
                      extendSel = FALSE;
                      ChangeSelection (frame, pBox->BxAbstractBox, FixedChar,
                                       FALSE, TRUE, FALSE, FALSE);
                      done = TRUE;
                    }
                  else
                    {
                      /* just decrease the current extension */
#ifdef _GL
                      if (pBoxEnd->BxBoundinBoxComputed)
                        y = pBoxEnd->BxClipY + pFrame->FrYOrg;
                      else
#endif /* _GL */
                        y = pBoxEnd->BxYOrg;
                      pBox = pBoxEnd;
                    }
                }
              /* there was a drag, but it's finished now */
              else if (!extendSel)
                {
                  if (!SelPosition &&
                      (pBoxBegin != pBoxEnd ||
                       !IsConstantConstructor (pBox->BxAbstractBox->AbElement)))
                    /* changing from an extension to a simple selection */
                    ClickX = x - pFrame->FrXOrg;
                  else
                    /* take the original position into account */
                    x = ClickX + pFrame->FrXOrg;
                }
              else if (extendSel)
                LeftExtended = TRUE;
              if (!done)
                LocateLeafBox (frame, view, x, y, 0, yDelta, pBox, extendSel);
            }
          break;
	   
        case 9:	/* Previous word (^<-) */
          WordSearchContext.SDocument = LoadedDocument[doc - 1];
          WordSearchContext.SStartToEnd = FALSE;
          if (RightExtended)
            {
              /* shrink the current selection */
              first = lastC;
              pEl = lastEl;
            }
          else
            {
              /* extend the current selection */
              first = firstC - 1;
              pEl = firstEl;
            }
          done = SearchPreviousWord (&pEl, &first, &last, word, &WordSearchContext);
          if ((RightExtended && last >= lastC &&
               (pEl == lastEl || AbsBoxSelectedAttr)) ||
              (LeftExtended && first == firstC - 1 &&
               (pEl == firstEl || AbsBoxSelectedAttr)))
            /* It was not the beginning of the next word */
            done = SearchPreviousWord (&pEl, &first, &last, word, &WordSearchContext);
          if (AbsBoxSelectedAttr && first == 0)
            /* beginning of the string */
            first = 1;
          if (extendSel)
            {
              if (!LeftExtended && firstEl == FixedElement &&
                  (pEl == FixedElement || AbsBoxSelectedAttr) &&
                  first <= FixedChar)
                {
                  /* change the extension direction */
                  RightExtended = FALSE;
                  LeftExtended = TRUE;
                }
              if (AbsBoxSelectedAttr)
                ChangeSelection (frame, AbsBoxSelectedAttr, first,
                                 TRUE, LeftExtended, FALSE, FALSE);
              else if (pEl->ElAbstractBox[view - 1])
                ChangeSelection (frame, pEl->ElAbstractBox[view - 1], first,
                                 TRUE, LeftExtended, FALSE, FALSE);
            }
          else
            {
              if (AbsBoxSelectedAttr)
                SelectStringInAttr (LoadedDocument[doc - 1], AbsBoxSelectedAttr,
                                    first, first - 1, FALSE);
              else
                SelectString (LoadedDocument[doc - 1], pEl, first, first - 1);
              /* remove the extension direction */
              LeftExtended = FALSE;
            }
          break;

        case 10:	/* Next word (^->) */
          WordSearchContext.SDocument =  LoadedDocument[doc - 1];
          WordSearchContext.SStartToEnd = TRUE;
          if (LeftExtended)
            {
              /* shrink the current selection */
              last = firstC + 1;
              pEl = firstEl;
            }
          else
            {
              /* extend the current selection */
              if (lastEl && lastC > lastEl->ElVolume)
                {
                  /* start from the next character string */
                  lastEl = FwdSearchTypedElem (lastEl, CharString + 1, NULL, NULL);
                  lastC = 1;
                }
              last = lastC;
              pEl = lastEl;
            }
          done = SearchNextWord (&pEl, &first, &last, word, &WordSearchContext);
          if ((!LeftExtended && first == lastC &&
               (pEl == lastEl || AbsBoxSelectedAttr)) ||
              (!RightExtended && first >= firstC &&
               (pEl == firstEl || AbsBoxSelectedAttr)))
            {
              /* It was not the beginning of the next word */
              if (RightExtended)
                last++; /* move after the end of the previous word */
              done = SearchNextWord (&pEl, &first, &last, word, &WordSearchContext);
            }
          if (AbsBoxSelectedAttr && first == 0)
            /* beginning of the attribute string */
            first = 1;
          if (extendSel)
            {
              if (LeftExtended &&
                  (pEl == FixedElement || AbsBoxSelectedAttr) &&
                  first >= FixedChar)
                {
                  /* change the extension direction */
                  RightExtended = TRUE;
                  LeftExtended = FALSE;
                }
              if (AbsBoxSelectedAttr)
                ChangeSelection (frame, AbsBoxSelectedAttr, first,
                                 TRUE, LeftExtended, FALSE, FALSE);
              else if (pEl->ElAbstractBox[view - 1])
                ChangeSelection (frame, pEl->ElAbstractBox[view - 1], first,
                                 TRUE, LeftExtended, FALSE, FALSE);
            }
          else
            {
              if (AbsBoxSelectedAttr)
                SelectStringInAttr (LoadedDocument[doc - 1], AbsBoxSelectedAttr,
                                    first, first - 1, FALSE);
              else
                SelectString (LoadedDocument[doc - 1], pEl, first, first - 1);
              /* remove the extension direction */
              LeftExtended = FALSE;
            }
          break;
        }
      Moving = FALSE;
#if !defined(_WINDOWS) && !defined(_MACOS)
      if (extendSel)
        DoCopyToClipboard (doc, view, FALSE);
#endif /* _WINDOWS && _MACOS */
    }
}

/*----------------------------------------------------------------------
  ----------------------------------------------------------------------*/
void TtcPreviousChar (Document document, View view)
{
  MovingCommands (1, document, view, FALSE);
}

/*----------------------------------------------------------------------
  ----------------------------------------------------------------------*/
void TtcNextChar (Document document, View view)
{
  MovingCommands (2, document, view, FALSE);
}

/*----------------------------------------------------------------------
  ----------------------------------------------------------------------*/
void TtcPreviousLine (Document document, View view)
{
  MovingCommands (8, document, view, FALSE);
}

/*----------------------------------------------------------------------
  ----------------------------------------------------------------------*/
void TtcNextLine (Document document, View view)
{
  MovingCommands (7, document, view, FALSE);
}

/*----------------------------------------------------------------------
  ----------------------------------------------------------------------*/
void TtcStartOfLine (Document document, View view)
{
  MovingCommands (4, document, view, FALSE);
}

/*----------------------------------------------------------------------
  ----------------------------------------------------------------------*/
void TtcSelStartOfLine (Document document, View view)
{
  MovingCommands (4, document, view, TRUE);
}

/*----------------------------------------------------------------------
  ----------------------------------------------------------------------*/
void TtcEndOfLine (Document document, View view)
{
  MovingCommands (3, document, view, FALSE);
}

/*----------------------------------------------------------------------
  ----------------------------------------------------------------------*/
void TtcSelEndOfLine (Document document, View view)
{
  MovingCommands (3, document, view, TRUE);
}

/*----------------------------------------------------------------------
  ----------------------------------------------------------------------*/
void TtcPreviousSelChar (Document document, View view)
{
  MovingCommands (1, document, view, TRUE);
}

/*----------------------------------------------------------------------
  ----------------------------------------------------------------------*/
void TtcNextSelChar (Document document, View view)
{
  MovingCommands (2, document, view, TRUE);
}

/*----------------------------------------------------------------------
  ----------------------------------------------------------------------*/
void TtcPreviousSelLine (Document document, View view)
{
  MovingCommands (8, document, view, TRUE);
}

/*----------------------------------------------------------------------
  ----------------------------------------------------------------------*/
void TtcNextSelLine (Document document, View view)
{
  MovingCommands (7, document, view, TRUE);
}

/*----------------------------------------------------------------------
  ----------------------------------------------------------------------*/
void TtcPreviousWord (Document document, View view)
{
  MovingCommands (9, document, view, FALSE);
}

/*----------------------------------------------------------------------
  ----------------------------------------------------------------------*/
void TtcNextWord (Document document, View view)
{
  MovingCommands (10, document, view, FALSE);
}

/*----------------------------------------------------------------------
  ----------------------------------------------------------------------*/
void TtcPreviousSelWord (Document document, View view)
{
  MovingCommands (9, document, view, TRUE);
}

/*----------------------------------------------------------------------
  ----------------------------------------------------------------------*/
void TtcNextSelWord (Document document, View view)
{
  MovingCommands (10, document, view, TRUE);
}

/*----------------------------------------------------------------------
  CopyXClipboard insere le contenu de la selection courante dans   
  le buffer pour transmettre la selection X.             
  ----------------------------------------------------------------------*/
static int CopyXClipboard (unsigned char **buffer, View view)
{
  PtrTextBuffer       clipboard;
  PtrDocument         pDoc;
  PtrElement          pFirstEl, pLastEl;
  PtrElement          pEl;
  PtrAbstractBox      pBlock, pOldBlock;
  CHAR_T             *text;
  int                 i, max;
  int                 lg, maxLength;
  int                 firstChar, lastChar;
  int                 v, ind;
  ThotBool            inAttr;

  /* get the current view */
  v = view - 1;
  inAttr = FALSE;
  maxLength = 0;
  clipboard = NULL;
  lg = 1;
  pFirstEl = NULL;
  pLastEl = NULL;
  firstChar = 0;
  if (DocSelectedAttr)
    {
      /* Selection is within an attribute */
      pDoc = DocSelectedAttr;
      firstChar = FirstSelectedCharInAttr;
      lastChar = LastSelectedCharInAttr;
      maxLength = LastSelectedCharInAttr - FirstSelectedCharInAttr;
      inAttr = TRUE;
      clipboard = AbsBoxSelectedAttr->AbText;
    }
  else if (SelectedDocument)
    {
      /* selection within an element */
      pDoc = SelectedDocument;
      pFirstEl = FirstSelectedElement;
      pLastEl = LastSelectedElement;
      firstChar = FirstSelectedChar;
      lastChar = LastSelectedChar;
      if (!SelPosition && lastChar == 0)
        {
          /* get the content of the whole element */
          lastChar = pLastEl->ElVolume + 2;
          firstChar = 1;
        }
      if (pFirstEl->ElTypeNumber != CharString + 1)
        /* if it's an image firstChar is not significant here. Set it to 0 */
        firstChar = 1;

      /* Compute the length of the buffer */
      if (pFirstEl == pLastEl && pFirstEl->ElTerminal)
        {
          /* only one element */
          if (pFirstEl->ElLeafType == LtText)
            maxLength = lastChar - firstChar;
          else if (pFirstEl->ElLeafType == LtPicture)
            maxLength = 5;
          else if (pFirstEl->ElLeafType == LtSymbol)
            maxLength = 6;
          else
            maxLength = 7;
        }
      else
        {
          if (pFirstEl->ElTerminal)
            {
              /* volume of the first element */
              if (pFirstEl->ElLeafType == LtText)
                maxLength = pFirstEl->ElVolume - firstChar;
              else if (pFirstEl->ElLeafType == LtPicture)
                maxLength = 5;
              else if (pFirstEl->ElLeafType == LtSymbol)
                maxLength = 6;
              else
                maxLength = 7;
            }
          pEl = pFirstEl;
          while (pEl)
            {
              pEl = FwdSearch5Types (pEl, CharString + 1,
                                     tt_Picture + 1, GraphicElem + 1,
                                     Symbol + 1, CharString + 1,
                                     NULL, NULL, NULL, NULL, NULL);
              if (pEl && ElemIsBefore (pLastEl, pEl))
                /* l'element trouve' est apres l'element de fin, on */
                /* fait comme si on n'avait pas trouve' */
                pEl = NULL;

              /* On ajoute le volume de l'element */
              if (pEl)
                {
                  if (pEl->ElLeafType == LtPicture)
                    maxLength += 5;
                  else if (pEl->ElLeafType == LtSymbol)
                    maxLength += 6;
                  else if (pEl->ElLeafType == LtGraphics)
                    maxLength += 7;
                  else if (pEl == pLastEl)
                    maxLength += lastChar;
                  else
                    maxLength += pEl->ElVolume;
                  lg += 3;
                }
            }
        }
      if (pFirstEl->ElTerminal && pFirstEl->ElLeafType == LtText)
        clipboard = pFirstEl->ElText;
    }

  if (maxLength <= 0)
    /* nothing selected */
    return 0;
  /* Adding 100 characters for extra CR */
  max = maxLength + lg;
  /* Allocate a buffer with the right length */
  text = (CHAR_T *)TtaGetMemory (max * sizeof (CHAR_T));
  /* Copy the text into the buffer */
  i = 0;
  ind = firstChar - 1;
  if (clipboard)
    {
      /* The first element is a text, locate the first character */
      while (clipboard && ind > clipboard->BuLength)
        {
          ind -= clipboard->BuLength;
          clipboard = clipboard->BuNext;
        }

      /* copy the text of the first element */
      while (clipboard && i < max && maxLength)
        {
          lg = clipboard->BuLength - ind;
          if (lg > maxLength)
            lg = maxLength;
          ustrncpy (&text[i], &clipboard->BuContent[ind], lg);
          i += lg;
          ind = 0;
          maxLength -= lg;
          clipboard = clipboard->BuNext;
        }
    }
  else if (pFirstEl->ElTerminal)
    {
      if (pFirstEl->ElLeafType == LtPicture)
        {
          ustrcpy (&text[i], TEXT("<img>"));
          i += 5;
        }
      else if (pFirstEl->ElLeafType == LtSymbol)
        {
          ustrcpy (&text[i], TEXT("<symb>"));
          i += 6;
        }
      else
        {
          ustrcpy (&text[i], TEXT("<graph>"));
          i += 7;
        }
    }

  /* copy the text of following elements */
  pOldBlock = NULL;
  pEl = pFirstEl;
  while (pEl)
    {
      pEl = FwdSearch5Types (pEl, CharString + 1,
                             tt_Picture + 1, GraphicElem + 1,
                             Symbol + 1, CharString + 1,
                             NULL, NULL, NULL, NULL, NULL);
      if (pEl)
        {
          if (pEl != pLastEl && ElemIsBefore (pLastEl, pEl))
            /* it's after the last element */
            pEl = NULL;	  
          if (pEl)
            {
              pBlock = SearchEnclosingType (pEl->ElAbstractBox[v], BoBlock, BoFloatBlock);
              if (pOldBlock && pBlock != pOldBlock)
                {
                  /* Add new lines */
                  text[i++] = EOL;
                  text[i] = EOS;
                }
              /* Recopie le texte de l'element */
              pOldBlock = pBlock;
              if (pEl->ElLeafType == LtPicture)
                {
                  ustrcpy (&text[i], TEXT("<img>"));
                  i += 5;
                }
              else if (pEl->ElLeafType == LtSymbol)
                {
                  ustrcpy (&text[i], TEXT("<symb>"));
                  i += 6;
                }
              else if (pEl->ElLeafType == LtGraphics)
                {
                  ustrcpy (&text[i], TEXT("<graph>"));
                  i += 7;
                }
              else
                {
                  clipboard = pEl->ElText;
                  if (pEl == pLastEl && maxLength > lastChar)
                    maxLength = lastChar;
                  while (clipboard && i < max && maxLength)
                    {
                      lg = clipboard->BuLength;
                      if (lg > maxLength)
                        lg = maxLength;
                      /* check the validity of lg */
                      if (lg + i > max - 1)
                        lg = max - i - 1;
                      ustrncpy (&text[i], clipboard->BuContent, lg);
                      i += lg;
                      maxLength -= lg;
                      clipboard = clipboard->BuNext;
                    }
                }
            }
        }
    }
  text[i] = EOS;
  if (*buffer)
    TtaFreeMemory (*buffer);
  /* What is the encoding used by external applications ??? */
#ifdef _WINGUI
  *buffer = TtaConvertCHARToByte (text, TtaGetDefaultCharset ());
#else /* _WINGUI */
  *buffer = TtaConvertCHARToByte (text, UTF_8);
#endif /* _WINGUI */
  TtaFreeMemory (text);
  return i;
}

/*----------------------------------------------------------------------
  TtcClearClipboard
  ----------------------------------------------------------------------*/
void TtcClearClipboard ()
{
  if (Xbuffer)
    TtaFreeMemory (Xbuffer);
  Xbuffer = NULL;
  ClipboardLength = 0;
  ClipboardURI = FALSE; // no URI stored
#ifdef _WX
#endif /* _WX */
}

/*----------------------------------------------------------------------
  TtaStringToClipboard
  ----------------------------------------------------------------------*/
void TtaStringToClipboard (unsigned char *s, CHARSET encoding)
{
  int              len;

  if (s)
    {
      len = strlen ((char *)s);
      if (len)
        {
#ifdef _WX
          if (wxTheClipboard->Open())
            {
              TtcClearClipboard ();
              // Write some text to the clipboard
              ClipboardLength = len;
              if (encoding == UTF_8)
                Xbuffer = (unsigned char *)TtaStrdup ((char *)s);
              else
                Xbuffer = TtaConvertByteToMbs (s, encoding);
              
              // This data objects are held by the clipboard, 
              // so do not delete them in the app.
              wxTheClipboard->AddData( new wxTextDataObject( TtaConvMessageToWX((char *)s) ) );
              wxTheClipboard->Close();
            }
#endif /* _WX */
#ifdef _GTK
          /* Must get the selection */
          TtcClearClipboard ();
          if (encoding == UTF_8)
            {
              Xbuffer = (unsigned char *)TtaStrdup ((char *)s);
              ClipboardLength = len;
            }
          else
            {
              Xbuffer = TtaConvertByteToMbs (s, encoding);
              ClipboardLength = strlen ((char *)Xbuffer);
            }
#endif /* _GTK */
#ifdef _WINGUI
          if (encoding == UTF_8)
            Xbuffer = TtaConvertMbsToByte (s, TtaGetLocaleCharset ());
          else
            Xbuffer = TtaStrdup (s);
#endif /* _WINGUI */

          // It should be an URI
          ClipboardURI = TRUE;
        }
    }
}

/*----------------------------------------------------------------------
  DoCopyToClipboard
  ----------------------------------------------------------------------*/
void DoCopyToClipboard (Document doc, View view, ThotBool force)
{
#ifdef _WX
  // Don't change the clipboard buffer when a single click is done
  if (!SelPosition && wxTheClipboard->Open())
    {
      unsigned char *  buffer = NULL;
      int              len;
      
      /* Must get the selection */
      len = CopyXClipboard (&buffer, view);
      if (len)
        {
          TtcClearClipboard ();
          // Write some text to the clipboard
          ClipboardLength = len;
          Xbuffer = buffer;	  
          // This data objects are held by the clipboard, 
          // so do not delete them in the app.
          wxTheClipboard->AddData( new wxTextDataObject( TtaConvMessageToWX((char *)buffer) ) );
         }
      else if (force)
        {
          TtcClearClipboard ();
          // Write fixed text to the clipboard
          Xbuffer = (unsigned char *)TtaStrdup ("<internal_structure>");	  
          ClipboardLength = strlen ((char *)Xbuffer);
          // This data objects are held by the clipboard, 
          // so do not delete them in the app.
          wxTheClipboard->AddData( new wxTextDataObject( TtaConvMessageToWX((char *)buffer) ) );
        }
      wxTheClipboard->Close();
    }
#endif /* _WX */
#ifdef _GTK
  unsigned char     *buffer = NULL;
  int                len;

  /* Must get the selection */
  TtcClearClipboard ();
  len = CopyXClipboard (&buffer, view);
  if (len)
    {
      ClipboardLength = len;
      Xbuffer = buffer;
    }
#endif /* _GTK */
#ifdef _WINGUI
  /* Store the current selection */
  ClipboardURI = FALSE;
  ClipboardLength = CopyXClipboard (&Xbuffer, view);
#endif /* _WINGUI */
}

/*----------------------------------------------------------------------
  TtcCopyToClipboard
  ----------------------------------------------------------------------*/
void TtcCopyToClipboard (Document doc, View view)
{
  DoCopyToClipboard (doc, view, TRUE);
}


/*----------------------------------------------------------------------
  SelectCurrentWord
  selects the word at the current position.
  The current position is given by the current box, the current buffer
  and the index in the buffer.
  ----------------------------------------------------------------------*/
void SelectCurrentWord (int frame, PtrBox pBox, int pos, int index,
                        PtrTextBuffer pBuffer, ThotBool inClipboard)
{
  PtrTextBuffer       buffer;
  PtrDocument         pDoc;
  PtrAbstractBox      pAb;
  CHAR_T              c;
  int                 first, last;
  int                 doc, i;
  ThotBool            isSep;

  doc = FrameTable[frame].FrDoc;
  pAb = pBox->BxAbstractBox;
  if (frame >= 1 && doc > 0 && index >= 0)
    {
      /* check if a leaf box is selected */
      c = pBuffer->BuContent[index];
      if (c != SPACE && c != EOS)
        {
          /* look for the beginning of the word */
          buffer = pBuffer;
          first = pos;
          i = index;
          c = PreviousCharacter (&buffer, &i);
          isSep = IsSeparatorChar (c);
          while (first > 1 && !isSep && c != EOS)
            {
              first--;
              c = PreviousCharacter (&buffer, &i);
              isSep = IsSeparatorChar (c);
            }
          /* look for the end of the word */
          buffer = pBuffer;
          last = pos + 1;
          i = index;
          c = NextCharacter (&buffer, &i);
          isSep = IsSeparatorChar (c);
          while (!isSep && c != EOS)
            {
              last++;
              c = NextCharacter (&buffer, &i);
              isSep = IsSeparatorChar (c);
            }
          pDoc = LoadedDocument[doc - 1];
          if (pAb->AbPresentationBox && pAb->AbCanBeModified)
            /* user has clicked in the presentation box displaying an */
            /* attribute value */
            SelectStringInAttr (pDoc, pAb, first, last, TRUE);
          else
            SelectString (pDoc, pAb->AbElement, first, last);
#ifndef _WINDOWS
          if (inClipboard)
            ClipboardLength = CopyXClipboard (&Xbuffer, pAb->AbDocView);
#endif /* _WINDOWS */
        }
    }
}

/*----------------------------------------------------------------------
  TtaSelectWord selects the word around the current point in an element
  ----------------------------------------------------------------------*/
void TtaSelectWord (Element element, int pos, Document doc, View view)
{
  PtrElement       pEl = (PtrElement)element;
  PtrAbstractBox   pAb;
  PtrBox           pBox;
  PtrTextBuffer    pBuffer;
  int              v, index;
  int              frame, i;

  if (pEl->ElTerminal && pEl->ElLeafType == LtText)
    {
      /* get the abstract box of the element */
      if (view > 100)
        v = 0;
      else
        v = view - 1;
      pAb = pEl->ElAbstractBox[v];
      if (pAb && pAb->AbBox)
        {
          /* look for the box, the buffer and the index in the buffer */
          pBox = pAb->AbBox;
          i = pos;
          if (pBox->BxType == BoSplit || pBox->BxType == BoMulScript)
            {
              /* look for the right box */
              pBox = pBox->BxNexChild;
              while (pBox && pBox->BxNexChild && i >= pBox->BxNexChild->BxFirstChar)
                pBox = pBox->BxNexChild;
            }
          i -= pBox->BxFirstChar;
          /* now look for the right position in buffers */
          pBuffer = pBox->BxBuffer;
          index = pBox->BxIndChar + i;
          while (pBuffer && (index > pBuffer->BuLength))
            {
              index = index - pBuffer->BuLength;
              pBuffer = pBuffer->BuNext;
            }
          if (pBuffer)
            {
              frame = GetWindowNumber (doc, view);
              SelectCurrentWord (frame, pBox, pos, index, pBuffer, FALSE);
            }
        }
    }
}

