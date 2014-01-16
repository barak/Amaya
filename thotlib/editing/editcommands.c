/*
 *
 *  (c) COPYRIGHT INRIA, 1996-2005
 *  Please first read the full copyright statement in file COPYRIGHT.
 *
 */

/*
 * This module handles user commands.
 *
 * Author: I. Vatton (INRIA)
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
#include "logdebug.h"

/* variables */
#undef THOT_EXPORT
#define THOT_EXPORT extern
#include "boxes_tv.h"
#include "frame_tv.h"
#include "edit_tv.h"
#include "modif_tv.h"
#include "select_tv.h"
#include "appdialogue_tv.h"

/* Thot Clipboard information */
static ThotPictInfo PictClipboard;
static LeafType     ClipboardType;
static Language     ClipboardLanguage = 0;
/* X Clipboard */
static struct _TextBuffer XClipboard;

#ifdef _GTK
static ThotBool     ClipboardToPaste = FALSE;
#endif /* _GTK */
static ThotBool     NewInsert;

#include "abspictures_f.h"
#include "actions_f.h"
#include "appdialogue_f.h"
#include "appli_f.h"
#include "applicationapi_f.h"
#include "attributes_f.h"
#include "boxmoves_f.h"
#include "boxlocate_f.h"
#include "boxparams_f.h"
#include "boxselection_f.h"
#include "buildboxes_f.h"
#include "buildlines_f.h"
#include "callback_f.h"
#include "changepresent_f.h"
#include "content_f.h"
#include "documentapi_f.h"
#include "docs_f.h"
#include "displayselect_f.h"
#include "displayview_f.h"
#include "editcommands_f.h"
#include "exceptions_f.h"
#include "font_f.h"
#include "frame_f.h"
#include "geom_f.h"
#include "input_f.h"
#include "language_f.h"
#include "memory_f.h"
#include "picture_f.h"
#include "presentationapi_f.h"
#include "registry_f.h"
#include "scroll_f.h"
#include "structcommands_f.h"
#include "structcreation_f.h"
#include "structmodif_f.h"
#include "structschema_f.h"
#include "structselect_f.h"
#include "tableH_f.h"
#include "textcommands_f.h"
#include "tree_f.h"
#include "uconvert_f.h"
#include "ustring_f.h"
#include "units_f.h"
#include "undo_f.h"
#include "unstructchange_f.h"
#include "viewapi_f.h"
#include "views_f.h"
#include "windowdisplay_f.h"

#ifdef _WINGUI 
#include "wininclude.h"
#endif /* _WINGUI */

#ifdef _GL
#include "glwindowdisplay.h"
#endif /*_GL*/
/*----------------------------------------------------------------------
  CopyString computes the width of the source text and copies it into the
  target buffer if target parameter is not NULL.
  ----------------------------------------------------------------------*/
static void CopyString (Buffer source, Buffer target, int count,
                        SpecFont font, int *sourceInd, int *targetInd,
                        int *width, int *nSpaces, int *nChars)
{
  int                 nb;
  CHAR_T              car;

  nb = 0;
  while (nb < count)
    {
      car = source[*sourceInd];
      if (target)
        /* the copy is effectively done */
        target[*targetInd] = car;
      if (car == EOS)
        /* end of string: return the real length */
        nb = count;
      else
        {
          (*sourceInd)++;
          (*targetInd)++;
          (nb)++;
          (*nChars)++;
          if (car == SPACE)
            (*nSpaces)++;
          *width += BoxCharacterWidth (car, font);
        }
    }
}

/*----------------------------------------------------------------------
  RegisterInHistory
  register element pEl and attribute pAttr in the UNDO history
  ----------------------------------------------------------------------*/
static void RegisterInHistory (PtrElement pEl, PtrAttribute pAttr, int frame,
                               int firstCharIndex, int lastCharIndex)
{
  PtrDocument         pDoc;
  int                 view;
  ThotBool            open;

  GetDocAndView (frame, &pDoc, &view);
  open = pDoc->DocEditSequence;
  if (SelPosition)
    lastCharIndex--;
  if (!open)
    OpenHistorySequence (pDoc, pEl, pEl, pAttr, firstCharIndex, lastCharIndex);
  if (pAttr == NULL)
    AddEditOpInHistory (pEl, pDoc, TRUE, TRUE);
}

/*----------------------------------------------------------------------
  APPtextModify envoie un message qui notifie qu'un texte est     
  modifie'.                                               
  ----------------------------------------------------------------------*/
static ThotBool APPtextModify (PtrElement pEl, int frame, ThotBool pre)
{
  PtrElement          pParentEl;
  ThotBool            result;
  NotifyOnTarget      notifyEl;
  PtrDocument         pDoc;
  int                 view;
  ThotBool            ok;

  GetDocAndView (frame, &pDoc, &view);
  result = FALSE;
  pParentEl = pEl;
  while (pParentEl != NULL)
    {
      notifyEl.event = TteElemTextModify;
      notifyEl.document = (Document) IdentDocument (pDoc);
      notifyEl.element = (Element) pParentEl;
      notifyEl.target = (Element) pEl;
      notifyEl.targetdocument = (Document) IdentDocument (pDoc);
      ok = CallEventType ((NotifyEvent *) & notifyEl, pre);
      result = result || ok;
      pParentEl = pParentEl->ElParent;
    }
  return result;
}

/*----------------------------------------------------------------------
  APPattrModify envoie un message qui notifie qu'un attribut est  
  modifie'.                                               
  ----------------------------------------------------------------------*/
static ThotBool APPattrModify (PtrAttribute pAttr, PtrElement pEl,
                               int frame, ThotBool pre)
{
  ThotBool            result;
  PtrDocument         pDoc;
  int                 view;
  NotifyAttribute     notifyAttr;

  GetDocAndView (frame, &pDoc, &view);
  notifyAttr.event = TteAttrModify;
  notifyAttr.document = (Document) IdentDocument (pDoc);
  notifyAttr.element = (Element) pEl;
  notifyAttr.info = 0; /* not sent by undo */
  notifyAttr.attribute = (Attribute) pAttr;
  notifyAttr.attributeType.AttrSSchema = (SSchema) (pAttr->AeAttrSSchema);
  notifyAttr.attributeType.AttrTypeNum = pAttr->AeAttrNum;
  result = CallEventAttribute (&notifyAttr, pre);
  return result;
}


/*----------------------------------------------------------------------
  GiveInsertPoint returns the position where the new character will be
  inserted:
  Parameters:
  - pAb: the current selected abstract box,
  - script: the requested script, to select the right position when the
  selection is between two different character scripts ('*'
  if there is no specific script),
  - frame: the curent frame.
  Returns:                     
  - pBox: the selected box,
  - pBuffer: the selected buffer,
  - ind: the character position within the buffer,                  
  - x: pixel shift from the start position of the box,
  - previousChars: the number of previous characters in the box.        
  ----------------------------------------------------------------------*/
static void GiveInsertPoint (PtrAbstractBox pAb, char script, int frame,
                             PtrBox *pBox, PtrTextBuffer *pBuffer, int *ind,
                             int *x, int *previousChars)
{
  ViewSelection      *pViewSel;
  PtrBox              box;
  ThotBool            ok;
  ThotBool            endOfPicture;

  /* If there is no specified abstract box, use the first selected abstract box */
  pViewSel = &ViewFrameTable[frame - 1].FrSelectionBegin;
  endOfPicture = FALSE;
  if (pAb == NULL && pViewSel->VsBox)
    pAb = pViewSel->VsBox->BxAbstractBox;

  /* no selected abstract box */
  if (pAb != NULL)
    if (pAb->AbLeafType == LtPicture && pViewSel->VsIndBox == 1)
      endOfPicture =TRUE;
  /* skip all presentation abstract boxes which cannot be edited */
  do
    {
      if (pAb)
        ok = ((pAb->AbPresentationBox && !pAb->AbCanBeModified) ||
              (pAb->AbLeafType == LtPicture && endOfPicture));
      else
        ok = FALSE;
      if (ok)
        pAb = pAb->AbNext;
    }
  while (ok);

  if (pAb == NULL)
    {
      *pBox = NULL;
      *pBuffer = NULL;
      *ind = 0;
      *x = 0;
      *previousChars = 0;
      return;
    }
  else if (pAb->AbLeafType == LtText)
    {
      box = pAb->AbBox;
      if (pViewSel->VsBox && pViewSel->VsBox->BxAbstractBox == pAb)
        {
          /* the box is already selected */
          *pBox = pViewSel->VsBox;
          *pBuffer = pViewSel->VsBuffer;
          *ind = pViewSel->VsIndBuf;
          *x = pViewSel->VsXPos;
          *previousChars = pViewSel->VsIndBox;
          if (script != ' ' && script != '*' &&
              script != pViewSel->VsBox->BxScript)
            {
              /* a specific script is requested */
              if (*previousChars == 0 && *pBox != box &&
                  *pBox != box->BxNexChild)
                {
                  /* check with the previous box child */
                  while (box &&  box->BxNexChild != *pBox)
                    box = box->BxNexChild;
                  if (box && script == box->BxScript)
                    {
                      *pBox = box;
                      if (*ind == 0)
                        {
                          *pBuffer = (*pBuffer)->BuPrevious;
                          *ind = (*pBuffer)->BuLength;
                        }
                      else
                        *ind = *ind - 1;
                      *x = box->BxW;
                      *previousChars = box->BxNChars;
                    }
                }
              else if (*pBox != box && *previousChars >= (*pBox)->BxNChars)
                {
                  /* check with the next box child */
                  box = (*pBox)->BxNexChild;
                  if (box && script == box->BxScript)
                    {
                      *pBox = box;
                      *pBuffer = box->BxBuffer;
                      *ind = box->BxIndChar;
                      *x = 0;
                      *previousChars = 0;
                    }
                }
            }
        }
      else
        {
          if (box->BxType == BoSplit || box->BxType ==BoMulScript)
            /* point to the first split box */
            *pBox = box->BxNexChild;
          else
            *pBox = box;	    
          *pBuffer = pAb->AbText;
          *ind = 0;
          *x = 0;
          *previousChars = 0;
        }
    }
  else
    {
      *pBox = pAb->AbBox;
      *pBuffer = NULL;
      *ind = 0;
      *x = 0;
      *previousChars = 0;
    }
}


/*----------------------------------------------------------------------
  CloseTextInsertionWithControl: finish the text insertion.
  The parameter toNotify is TRUE when the function can notify changes
  to the external application.
  Return TRUE when current changes are notfied.
  ----------------------------------------------------------------------*/
static ThotBool CloseTextInsertionWithControl (ThotBool toNotify)
{
  PtrElement          pEl;
  PtrBox              pBox;
  PtrBox              pSelBox;
  PtrTextBuffer       pBuffer;
  PtrTextBuffer       pbuff;
  ViewFrame          *pFrame;
  ViewSelection      *pViewSel;
  ViewSelection      *pViewSelEnd;
  int                 nChars;
  int                 i, j;
  int                 ind;
  int                 frame;
  ThotBool            notified;

  /* force the end of current shortcut sequence */
  TtaCloseShortcutSequence ();
  /* No more enclosing cell */
  LastInsertCell = NULL;
  /* current frame for the selection */
  frame = ActiveFrame;
  notified = FALSE;
  if (frame > 0)
    {
      if (TextInserting)
        {
          /* close the current insertion */
          TextInserting = FALSE;
          /* Where is the insert point (&i not used)? */
          GiveInsertPoint (NULL, '*', frame, &pSelBox, &pBuffer, &ind, &i, &j);
          if (pSelBox == NULL || pSelBox->BxAbstractBox == NULL ||
              pSelBox->BxAbstractBox->AbLeafType != LtText)
            /* no more selection */
            return (notified);
          if (pBuffer && (ind > 0 || ind >= pBuffer->BuLength))
            {
              if (pBuffer->BuLength == 0 && pSelBox->BxBuffer != pBuffer)
                /* remove the empty buffer */
                pBuffer = DeleteBuffer (pBuffer, frame);
            }
          else if (pBuffer && pBuffer->BuPrevious)
            {
              pbuff = pBuffer->BuPrevious;
              i = FULL_BUFFER - pbuff->BuLength;
              nChars = pBuffer->BuLength;
              if (pbuff->BuLength == 0 && pSelBox->BxNChars != 0)
                /* remove the empty buffer */
                pbuff = DeleteBuffer (pbuff, frame);
              else if (nChars < 50 && i >= nChars)
                {
                  /* collaps buffer contents */
                  ustrncpy (&pbuff->BuContent[pbuff->BuLength],
                            &pBuffer->BuContent[0], nChars);
                  i = pbuff->BuLength;	/* old length */
                  /* update boxes */
                  if (j == 0)
                    pBox = pSelBox;
                  else
                    /* start from the next child */
                    pBox = pSelBox->BxNexChild;
                  while (pBox && pBox->BxBuffer == pBuffer)
                    {
                      pBox->BxBuffer = pbuff;
                      pBox->BxIndChar += i;
                      pBox = pBox->BxNexChild;
                    }

                  /* free the empty buffer */
                  pBuffer = DeleteBuffer (pBuffer, frame);
                  pbuff->BuLength += nChars;
                  pbuff->BuContent[pbuff->BuLength] = EOS;
                }
            }

          /* Check if the insertion starts at the beginning of a box */
          pBox = pSelBox->BxAbstractBox->AbBox;
          if (j == 0)
            {
              if (pSelBox->BxBuffer->BuLength != 0 &&
                  pSelBox->BxIndChar > pSelBox->BxBuffer->BuLength &&
                  pSelBox->BxNChars > 0)
                {
                  /* the insertion at the end of a buffer was removed */
                  pSelBox->BxIndChar = 0;
                }
              /* update the split box */
              if (pBox->BxBuffer != pSelBox->BxBuffer &&
                  pBox->BxNexChild == pSelBox)
                pBox->BxBuffer = pBuffer;
              else if (ind == 0 && pBox->BxBuffer == pSelBox->BxBuffer)
                pBox->BxBuffer = pBuffer;
              pSelBox->BxBuffer = pBuffer;
            }
          /* update the abstract box */
          pSelBox->BxAbstractBox->AbText = pBox->BxBuffer;

          /* Quand le texte insere' se trouve dans un bloc de lignes */
          /* on reformate le bloc de ligne pour retirer les          */
          /* compressions de texte et couper eventuellement les mots */
          while (pBox)
            {
              if (pBox->BxAbstractBox == NULL)
                pBox = NULL;
              else if (pBox->BxAbstractBox->AbEnclosing &&
                       pBox->BxAbstractBox->AbEnclosing->AbBox)
                {
                  pBox = pBox->BxAbstractBox->AbEnclosing->AbBox;
                  if (pBox->BxType == BoBlock ||
                      pBox->BxType == BoFloatBlock)
                    {
                      LastInsertParagraph = pBox->BxAbstractBox;
                      LastInsertElement = LastInsertParagraph->AbElement;
                      LastInsertThotWindow = frame;
                      pBox = NULL;
                    }
                  else if (pBox->BxType != BoGhost && pBox->BxType != BoFloatGhost)
                    pBox = NULL;
                }
            }
          pFrame = &ViewFrameTable[frame - 1];
          pViewSel = &pFrame->FrSelectionBegin;
          pViewSelEnd = &pFrame->FrSelectionEnd;
          if (pSelBox->BxAbstractBox->AbPresentationBox &&
              pSelBox->BxAbstractBox->AbCreatorAttr)
            {
              /* update the selection within the attribute */
              FirstSelectedCharInAttr = pSelBox->BxFirstChar + pViewSelEnd->VsIndBox;
              LastSelectedCharInAttr = pSelBox->BxFirstChar + pViewSel->VsIndBox;
              SelPosition = (LastSelectedCharInAttr <= FirstSelectedCharInAttr);
            }
          NewContent (pSelBox->BxAbstractBox);
          /* Check if a paragraph should be reformatted after an edit */
          CloseParagraphInsertion (pSelBox->BxAbstractBox, frame);
	    
          /* update the new selection */
          if (pViewSel->VsBox && LastInsertAttr == NULL)
            {
              i = pViewSel->VsBox->BxFirstChar + pViewSel->VsIndBox;
              /* Faut-il changer l'autre extremite de la selection ? */
              pBox = pViewSelEnd->VsBox;
              if (pBox)
                {
                  if (pBox->BxAbstractBox == pViewSel->VsBox->BxAbstractBox)
                    {
                      j = pBox->BxFirstChar + pViewSelEnd->VsIndBox;
                      ChangeSelection (frame, pViewSel->VsBox->BxAbstractBox, i,
                                       FALSE, TRUE, FALSE, FALSE);
                      if (pViewSel->VsBox->BxAbstractBox != pBox->BxAbstractBox ||
                          i != j)
                        ChangeSelection (frame, pBox->BxAbstractBox, j, TRUE, TRUE,
                                         FALSE, FALSE);
                    }
                  else
                    ChangeSelection (frame, pViewSel->VsBox->BxAbstractBox, i,
                                     FALSE, TRUE, FALSE, FALSE);
                }
              else
                ChangeSelection (frame, pViewSel->VsBox->BxAbstractBox, i, FALSE,
                                 TRUE, FALSE, FALSE);
              /* Nouvelle position de reference du curseur */
              ClickX = pViewSel->VsBox->BxXOrg + pViewSel->VsXPos - pFrame->FrXOrg;
            }
	     
          if (LastInsertElText)
            {
              /* end of text insertion */
              pEl = LastInsertElText;
              LastInsertElText = NULL;
              LastInsertAttr = NULL;
              LastInsertAttrElem = NULL;
              if (toNotify)
                {
                  /* notify the change */
                  APPtextModify (pEl, frame, FALSE);
                  notified = TRUE;
                }
              if (SelectedDocument)
                CloseHistorySequence (SelectedDocument);
            }
          else if (LastInsertAttr)
            {
              /* end of attribute change */
              LastInsertAttr = NULL;
              LastInsertAttrElem = NULL;
              /* the notification was already done by NewContent */
              notified = TRUE;
              CloseHistorySequence (DocSelectedAttr);
            }
        }
    }
  return (notified);
}


/*----------------------------------------------------------------------
  SetInsert determine le point d'insertion en fonction de la      
  selection courante et de la nature attendue :           
  On verifie avant tout que le debut de la selection      
  visualisee correspond bien au debut de la selection     
  reelle (le debut de selection peut se trouver dans un   
  element de document non visualise).                     
  - Si la nature est LtReference n'importe qu'elle nature 
  terminale (texte, image, graphique symbole) est         
  autorisee.                                              
  - Si le pave est un pave compose vide, on insere dedans.
  - Si le pave correspond a la nature, on insere dedans.  
  - Si le pave precedent a la meme nature, on insere a`   
  la fin du pave.                                         
  - Sinon, on insere un pave de cette nature avant le pave
  selectionne.                                            
  Le parametre del est Vrai si on cherche a detruire un   
  caractere. Si c'est le cas et que la marque d'insertion 
  se trouve en debut d'un pave, la procedure regarde si   
  la destruction de caractere peut s'appliquer au pave    
  precedent.                                              
  ----------------------------------------------------------------------*/
static void SetInsert (PtrAbstractBox *pAb, int *frame, LeafType nat, ThotBool del)
{
  PtrAbstractBox      pSelAb, pSiblingAb;
  PtrBox              pBox;
  ViewFrame          *pFrame;
  ViewSelection      *pViewSel;
  LeafType            natureToCreate;
  int                 i;
  ThotBool            moveSelection;
  ThotBool            notified, before;
  
  *pAb = NULL;
  notified = FALSE;
  /* verifie la validite du debut de la selection */
  if (*frame > 0)
    {
      pFrame = &ViewFrameTable[*frame - 1];
      pViewSel = &pFrame->FrSelectionBegin;
      /* Si la selection porte sur des caracteres, le debut de la selection */
      /* visualisee correspond forcement au debut de la selection reelle    */
      /* Sinon il faut verifier la validite de la selection */
      if (pViewSel->VsBox == NULL || pViewSel->VsIndBox == 0)
        TtaSetFocus ();
      pBox = pViewSel->VsBox;

      /* Il faut maintenant verifier la nature demandee */
      i = 1;			/* Par defaut insere avant le 1er caractere */
      moveSelection = FALSE;
      if (nat == LtReference)
        natureToCreate = LtText;
      else
        natureToCreate = nat;
      
      if (pBox == NULL)
        *pAb = NULL;
      else
        *pAb = pBox->BxAbstractBox;

      pSelAb = *pAb;
      if (pSelAb)
        {
          /* deplace l'insertion avant le pave selectionne pour detruire */
          if (del && pViewSel->VsIndBox == 0 &&
              (pBox == pSelAb->AbBox || pBox == pSelAb->AbBox->BxNexChild))
            {
              pSelAb = pSelAb->AbPrevious;
              *pAb = NULL;
              if (pSelAb != NULL && pSelAb->AbCanBeModified &&
                  !pSelAb->AbReadOnly && pSelAb->AbLeafType == natureToCreate)
                {
                  moveSelection = TRUE;
                  notified = CloseTextInsertionWithControl (TRUE);
                  if (!notified)
                    {
                      i = pSelAb->AbVolume + 1;
                      *pAb = pSelAb;
                    }
                }
            }
          /* deplace l'insertion dans le pave de composition vide */
          else if (pSelAb->AbLeafType == LtCompound && pSelAb->AbFirstEnclosed == NULL)
            {
              *pAb = CreateALeaf (pSelAb, frame, natureToCreate, TRUE);
              moveSelection = TRUE;
            }
          else if (!pSelAb->AbCanBeModified || pSelAb->AbReadOnly ||
                   pSelAb->AbLeafType == LtCompound ||
                   (pSelAb->AbLeafType != nat && nat != LtReference &&
                    !(pSelAb->AbLeafType == LtSymbol && nat == LtText) &&
                    !(pSelAb->AbLeafType == LtPolyLine && nat == LtGraphics)))
            /* deplace l'insertion avant ou apres le pave selectionne */
            {
              moveSelection = TRUE;
              if (pViewSel->VsXPos > 0)
                {
                  /* insert after */
                  before = FALSE;
                  pSiblingAb = pSelAb->AbNext;
                }
              else
                {
                  /* insert before */
                  before = TRUE;
                  pSiblingAb = pSelAb->AbPrevious;
                }
              notified = CloseTextInsertionWithControl (TRUE);
              if (pSiblingAb == NULL)
                /* no sibling. Create a new leaf */
                *pAb = CreateALeaf (*pAb, frame, natureToCreate, before);
              else if (!pSiblingAb->AbCanBeModified || pSiblingAb->AbReadOnly||
                       natureToCreate != LtText ||
                       pSiblingAb->AbLeafType != natureToCreate)
                /* the sibling can't accept the requested content */
                *pAb = CreateALeaf (*pAb, frame, natureToCreate, before);
              else
                /* the new content will ba added to the existing sibling */
                {
                  if (before)
                    i = pSiblingAb->AbVolume + 1;
                  else
                    i = 1;
                  *pAb = pSiblingAb;
                }
            }
        }
	  
      if (notified)
        /* selection could be modified by the application re-do the work */
        SetInsert (pAb, frame, nat, del);
      else
        {
          pSelAb = *pAb;
          if (pSelAb && pSelAb->AbElement && moveSelection)
            {
              /* signale le changement de selection a l'editeur */
              if (pSelAb->AbVolume == 0)
                ChangeSelection (*frame, pSelAb, 0, FALSE, TRUE, FALSE, FALSE);
              else
                ChangeSelection (*frame, pSelAb, i, FALSE, TRUE, FALSE, FALSE);
            }
        }
    }
}


/*----------------------------------------------------------------------
  Cree un buffer apres celui donne en parametre.                  
  Met a jour les chainages et rend le pointeur sur le nouveau     
  buffer.                                                         
  ----------------------------------------------------------------------*/
static PtrTextBuffer GetNewBuffer (PtrTextBuffer pBuffer, int frame)
{
  PtrTextBuffer       pNewBuffer;
  ViewFrame          *pFrame;
  ViewSelection      *pViewSel;
  ViewSelection      *pViewSelEnd;

  GetTextBuffer (&pNewBuffer);
  pNewBuffer->BuPrevious = pBuffer;
  if (pBuffer == NULL)
    pNewBuffer->BuNext = NULL;
  else
    {
      pNewBuffer->BuNext = pBuffer->BuNext;
      pBuffer->BuNext = pNewBuffer;
      if (pNewBuffer->BuNext != NULL)
        pNewBuffer->BuNext->BuPrevious = pNewBuffer;
    }

  if (frame)
    {
      /* update selection marks */
      pFrame = &ViewFrameTable[frame - 1];
      pViewSel = &pFrame->FrSelectionBegin;
      if (pViewSel->VsBuffer == pBuffer)
        {
          if (pFrame->FrSelectionEnd.VsBuffer == pViewSel->VsBuffer)
            {
              pViewSelEnd = &pFrame->FrSelectionEnd;
              pViewSelEnd->VsBuffer = pNewBuffer;
              pViewSelEnd->VsIndBuf = pViewSelEnd->VsIndBuf - pViewSel->VsIndBuf;
            }
          pViewSel->VsBuffer = pNewBuffer;
          pViewSel->VsIndBuf = 0;
        }
    }
  return pNewBuffer;
}

/*----------------------------------------------------------------------
  Copie les caracteres de la chaine de buffers pSourceBuffer      
  a partir de startInd, jusqu'a endInd du buffer pEndBuffer       
  vers la chaine de buffers pTargetBuffer a partir de             
  targetInd si pTargetBuffer n'est pas Nil.                       
  Si pTargetBuffer vaut NULL, evalue simplement les valeurs       
  width, nSpaces et nChars. Si pEndBuffer vaut NULL endInd doit   
  valoir 0.                                                       
  Rend :                                                          
  - le pointeur sur le dernier buffer destination utilise.        
  - la largeur, le nombre de blancs et de caracteres copies.      
  ----------------------------------------------------------------------*/
static void CopyBuffers (SpecFont font, int frame, int startInd, int endInd,
                         int targetInd, PtrTextBuffer pSourceBuffer,
                         PtrTextBuffer pEndBuffer,
                         PtrTextBuffer *pTargetBuffer,
                         int *width, int *nSpaces, int *nChars)
{
  PtrTextBuffer       pBuffer;
  STRING              target;
  int                 sourceInd;
  int                 sourceLength;
  int                 targetlength;

  /* get the starting point of the copy */
  pBuffer = pSourceBuffer;
  sourceInd = startInd;
  *width = 0;
  *nChars = 0;
  *nSpaces = 0;
  while (pBuffer)
    {
      if (*pTargetBuffer == NULL)
        {
          /* we don't want to effectively copy the text */
          targetInd = 0;
          target = NULL;
        }
      else
        target = (*pTargetBuffer)->BuContent;

      if (pBuffer == pEndBuffer)
        {
          /* prevent buffer overflow */
          if (endInd > pEndBuffer->BuLength)
            sourceLength = pEndBuffer->BuLength - sourceInd;
          else
            sourceLength = endInd - sourceInd;
        }
      else
        sourceLength = pBuffer->BuLength - sourceInd;
      targetlength = FULL_BUFFER - targetInd;
      if (sourceLength <= targetlength)
        {
          /* end of source buffer */
          CopyString (pBuffer->BuContent, target, sourceLength,
                      font, &sourceInd, &targetInd, width, nSpaces,
                      nChars);
          if (pBuffer == pEndBuffer)
            pBuffer = NULL;
          else
            pBuffer = pBuffer->BuNext;
          sourceInd = 0;
        }
      else
        {
          /* end of target buffer */
          CopyString (pBuffer->BuContent, target, targetlength,
                      font, &sourceInd, &targetInd, width, nSpaces,
                      nChars);
          (*pTargetBuffer)->BuLength = FULL_BUFFER;
          (*pTargetBuffer)->BuContent[FULL_BUFFER] = EOS;
          *pTargetBuffer = GetNewBuffer (*pTargetBuffer, frame);
          targetInd = 0;
        }
    }

  if (*pTargetBuffer)
    {
      /* text was copied: update target buffer information */
      (*pTargetBuffer)->BuLength = targetInd;
      (*pTargetBuffer)->BuContent[targetInd] = EOS;
    }
}

/*----------------------------------------------------------------------
  Debute l'insertion de caracteres dans une boite de texte.      
  ----------------------------------------------------------------------*/
static void StartTextInsertion (PtrAbstractBox pAb, int frame, PtrBox pSelBox,
                                PtrTextBuffer pBuffer, int ind, int prev)
{
  PtrBox              pBox;
  PtrTextBuffer       pPreviousBuffer;
  PtrTextBuffer       pNewBuffer;
  int                 k, i;

  /* get the active frame for the selection */
  if (frame == 0)
    frame = ActiveFrame;
  if (frame > 0)
    {
      /* get the insert point (&i not used) */
      if (pAb == NULL)
        GiveInsertPoint (NULL, '*', frame, &pSelBox, &pBuffer, &ind, &i, &prev);
      TextInserting = TRUE;
      /* the split box */
      pBox = pSelBox->BxAbstractBox->AbBox;

      /* Notify the application that the content will be changed */
      if (pSelBox->BxAbstractBox->AbPresentationBox &&
          pSelBox->BxAbstractBox->AbCanBeModified)
        {
          /* it's an abstract box that displays the attribute value */
          if (LastInsertAttr != pBox->BxAbstractBox->AbCreatorAttr)
            {
              LastInsertAttr = pBox->BxAbstractBox->AbCreatorAttr;
              LastInsertAttrElem = pBox->BxAbstractBox->AbElement;
              if (!APPattrModify (LastInsertAttr, LastInsertAttrElem, frame, TRUE))
                /* register the editing operation in the history */
                RegisterInHistory (LastInsertAttrElem, LastInsertAttr, frame,
                                   FirstSelectedCharInAttr, LastSelectedCharInAttr);
            }
        }
      else if (LastInsertElText != pBox->BxAbstractBox->AbElement)
        {
          /* it's a text element */
          LastInsertElText = pBox->BxAbstractBox->AbElement;
          if (!APPtextModify (LastInsertElText, frame, TRUE))
            /* register the editing operation in the history */
            RegisterInHistory (LastInsertElText, NULL, frame,
                               FirstSelectedChar, LastSelectedChar);
        }
      else if (SelectedDocument && !SelectedDocument->DocEditSequence)
        RegisterInHistory (LastInsertElText, NULL, frame,
                           FirstSelectedChar, LastSelectedChar);

      /* Memorize  the enclosing cell */
      LastInsertCell = GetParentCell (pBox);
      /* First buffer of the abstract box */
      pNewBuffer = pSelBox->BxAbstractBox->AbText;
      /* Insertion at the beginning of the box */
      if (ind == 0 && prev == 0 && pBuffer->BuLength > 0)
        {
          /* previous buffer */
          pPreviousBuffer = pBuffer->BuPrevious;
          if (pNewBuffer == pBuffer)
            {
              /* add a buffer before */
              GetTextBuffer (&pNewBuffer);
              pNewBuffer->BuNext = pBuffer;
              pNewBuffer->BuLength = 0;
              pNewBuffer->BuContent[0] = EOS;
              if (pPreviousBuffer == NULL)
                pNewBuffer->BuPrevious = NULL;
              else
                {
                  pNewBuffer->BuPrevious = pPreviousBuffer;
                  pPreviousBuffer->BuNext = pNewBuffer;
                }
              pBuffer->BuPrevious = pNewBuffer;
              /* update the split box */
              pBox->BxBuffer = pNewBuffer;
              /* update the selected box */
              pSelBox->BxAbstractBox->AbText = pNewBuffer;
              pSelBox->BxIndChar = 0;
              pSelBox->BxBuffer = pNewBuffer;
            }
          else if (pPreviousBuffer)
            {
              /* add into the existing previous buffer */
              pSelBox->BxIndChar = pPreviousBuffer->BuLength;
              pSelBox->BxBuffer = pPreviousBuffer;
            }
        }
      else if (ind > 0 && ind < pBuffer->BuLength)
        {
          /* split the current buffer to prepare the insertion */
          pNewBuffer = pBuffer;
          pBuffer = GetNewBuffer (pBuffer, frame);
          /* move the beginning of the buffer */
          k = ustrlen (&pNewBuffer->BuContent[ind]);
          ustrncpy (&pBuffer->BuContent[0], &pNewBuffer->BuContent[ind], k);
          pBuffer->BuContent[k] = EOS;
          pBuffer->BuLength = k;
          pNewBuffer->BuContent[ind] = EOS;
          pNewBuffer->BuLength = ind;
          /* update following piece of a split box */
          pBox = pSelBox->BxNexChild;
          while (pBox)
            {
              if (pBox->BxBuffer == pNewBuffer)
                {
                  pBox->BxBuffer = pBuffer;
                  pBox->BxIndChar -= ind;
                  pBox = pBox->BxNexChild;
                }
              else
                pBox = NULL;
            }
        }
    }
}

/*----------------------------------------------------------------------
  Assure la presence d'un atome texte de la bonne langue a la      
  position indiquee (qui doit etre un atome texte).
  ----------------------------------------------------------------------*/
static void NewTextLanguage (PtrAbstractBox pAb, int charIndex, Language lang)
{
  PtrElement          pEl, pNextEl, pSecond, pNext;
  PtrDocument         pDoc;

  pEl = pAb->AbElement;
  if (pEl != NULL && pEl->ElStructSchema != NULL)
    if (pEl->ElLeafType == LtText)
      {
        pDoc = DocumentOfElement (pEl);
        if (pEl->ElTextLength > 0)
          {
            pNext = pEl->ElNext;
            SplitTextElement (pEl, charIndex, pDoc, FALSE, &pNextEl, FALSE);
            BuildAbsBoxSpliText (pEl, pNextEl, pNext, pDoc);
            if (pEl->ElTextLength > 0 && pNextEl->ElTextLength > 0)
              {
                pNext = pNextEl->ElNext;
                SplitTextElement (pNextEl, 1, pDoc, FALSE, &pSecond, FALSE);
                BuildAbsBoxSpliText (pNextEl, pSecond, pNext, pDoc);
                pEl = pNextEl;
              }
            else if (pEl->ElTextLength > 0)
              pEl = pNextEl;
            AbstractImageUpdated (pDoc);
          }
        if (pEl && pEl->ElStructSchema)
          {
            /* change la langue dans la feuille de texte */
            ChangeLanguage (pDoc, pEl, lang, TRUE);
            AbstractImageUpdated (pDoc);
            RedisplayDocViews (pDoc);
            SelectElement (pDoc, pEl, FALSE, FALSE);
          }
      }
}

/*----------------------------------------------------------------------
  Create a new element or move to previous element if the language changes
  Return TRUE if there is a notification to the application and the
  current selection could be modified.
  ----------------------------------------------------------------------*/
static ThotBool GiveAbsBoxForLanguage (int frame, PtrAbstractBox *pAb,
                                       int keyboard)
{
  PtrAbstractBox      pSelAb;
  PtrBox              pBox;
  PtrAttribute        pHeritAttr;
  PtrElement          pElAttr;  
  ViewSelection      *pViewSel;
  Language            language, plang;
  unsigned char       text[100];
  int                 index;
  ThotBool            cut;
  ThotBool            notification;

  language = 0;
  pViewSel = &ViewFrameTable[frame - 1].FrSelectionBegin;
  notification = FALSE;
  pSelAb = *pAb;
  plang = pSelAb->AbLang;
  if (keyboard == -1)
    /* l'utilisateur a saisi un caractere au clavier */
    if (plang < TtaGetFirstUserLanguage())
      /* le contenu du pave courant avait ete saisi par palette */
      /* recherche la langue dans les ancetres */
      {
        pHeritAttr = GetTypedAttrAncestor (pSelAb->AbElement->ElParent, 1,
                                           NULL, &pElAttr); 
        if (pHeritAttr != NULL && pHeritAttr->AeAttrText != NULL)
          {
            CopyBuffer2MBs (pHeritAttr->AeAttrText, 0, text, 100);
            language = TtaGetLanguageIdFromName ((char*)text);
          }
        else
          /* les ancetres n'ont pas d'attribut langue */
          language = TtaGetDefaultLanguage ();
      }
    else
      language = plang;
  else if (keyboard == 2)
    /* insert a standard character */
    if (TtaGetScript (plang) == 'L')
      language = plang;
    else
      language = TtaGetDefaultLanguage ();
  else if (keyboard == 3)
    /* insert a character from the greek palette */
    language = TtaGetLanguageIdFromScript ('G');
  else
    language = 0;

  if (pSelAb->AbLeafType == LtText)
    if (plang != language && plang != 0)
      {
        notification = CloseTextInsertionWithControl (TRUE);
        if (!notification)
          {
            /* the selection could be modified by the application */
            cut = TRUE;
            pBox = pViewSel->VsBox;
            if (pBox)
              {
                index = pBox->BxFirstChar + pViewSel->VsIndBox;
                if (index <= 1)
                  {
                    pSelAb = pSelAb->AbPrevious;
                    if (pSelAb &&
                        pSelAb->AbLeafType == LtText &&
                        pSelAb->AbLang == language &&
                        pSelAb->AbCanBeModified && !pSelAb->AbReadOnly)
                      {
                        cut = FALSE;
                        ChangeSelection (frame, pSelAb, pSelAb->AbVolume + 1,
                                         FALSE, TRUE, FALSE, FALSE);
                      }
                  }
		
                /* S'il faut couper, on appelle l'editeur */
                if (cut)
                  NewTextLanguage (*pAb, index, language);
                /* la boite peut avoir change */
                pBox = pViewSel->VsBox;
                if (pBox)
                  *pAb = pBox->BxAbstractBox;
                else
                  *pAb = NULL;
              }
          }
      }
  return (notification);
}


/*----------------------------------------------------------------------
  IsLineBreakInside returns TRUE if a line-break character is found in
  the current string.
  Parameters pBuffer and ind give the starting character of the string
  and length gives the string length.
  ----------------------------------------------------------------------*/
static ThotBool IsLineBreakInside (PtrTextBuffer pBuffer, int ind, int length)
{
  int                 c;
  int                 nChars;
  int                 i;
  int                 j;

  if (pBuffer == NULL)
    return (FALSE);
  if (ind >= pBuffer->BuLength && pBuffer->BuNext)
    {
      /* End of the current buffer -> start with the next buffer */
      pBuffer = pBuffer->BuNext;
      i = 0;
    }
  else
    i = ind;
  /* number of characters in the buffer */
  nChars = pBuffer->BuLength;
  j = 0;

  /* Recherche s'il y a un caractere de coupure forcee */
  while (i < nChars && j < length)
    {
      c = pBuffer->BuContent[i];
      if (c == BREAK_LINE || c == NEW_LINE)
        /* a break-line found */
        return (TRUE);
      /* Next character */
      i++;
      if (i == nChars && pBuffer->BuNext)
        {
          pBuffer = pBuffer->BuNext;
          i = 0;
          nChars = pBuffer->BuLength;
        }
      j++;
    }
  return (FALSE);
}


/*----------------------------------------------------------------------
  TtcInsertGraph insert a graphics                                
  ----------------------------------------------------------------------*/
void  TtcInsertGraph (Document document, View view, unsigned char c)
{
  DisplayMode         dispMode;
  int                 frame;
  ThotBool            lock = TRUE;

  if (document != 0)
    {
      /* avoid to redisplay step by step */
      dispMode = TtaGetDisplayMode (document);
      if (dispMode == DisplayImmediately)
        TtaSetDisplayMode (document, DeferredDisplay);
      /* lock tables formatting */
      TtaGiveTableFormattingLock (&lock);
      if (!lock)
        /* table formatting is not loked, lock it now */
        TtaLockTableFormatting ();

      frame = GetWindowNumber (document, view);
      InsertChar (frame, c, 1);

      if (!lock)
        /* unlock table formatting */
        TtaUnlockTableFormatting ();
      /* just manage differed enclosing rules */
      ComputeEnclosing (frame);
      if (dispMode == DisplayImmediately)
        TtaSetDisplayMode (document, dispMode);
    }
}


/*----------------------------------------------------------------------
  Termine l'insertion de caracteres dans une boite de texte       
  ----------------------------------------------------------------------*/
void CloseTextInsertion ()
{
  ThotBool withAppliControl;

  withAppliControl = CloseTextInsertionWithControl (TRUE);
}

/*----------------------------------------------------------------------
  CloseParagraphInsertion teste s'il faut reformater un paragraphe  
  suite a` une insertion.                                 
  Le dernier bloc de lignes e'dite' est reformate' de`s   
  que la se'lection sort du bloc de lignes. Le but est de 
  retirer les extensions/compressions de texte et couper  
  e'ventuellement les mots.                               
  ----------------------------------------------------------------------*/
void CloseParagraphInsertion (PtrAbstractBox pAb, int frame)
{
  PtrBox              pBox;
  PtrElement          pEl;

  if (LastInsertParagraph)
    {
      if (LastInsertParagraph->AbElement != LastInsertElement
          || LastInsertParagraph->AbBox == NULL)
        /* Ce n'est plus la peine de reformater le bloc de lignes */
        LastInsertParagraph = NULL;
      else if (LastInsertThotWindow != frame)
        {
          /* a change a priori de paragraphe */
          /* Reevalue le bloc de lignes */
          RecomputeLines (LastInsertParagraph, NULL, NULL, LastInsertThotWindow);
          /* Et l'affiche */
          RedrawFrameBottom (LastInsertThotWindow, 0, NULL);
          LastInsertParagraph = NULL;
        }
      else
        {
          /* Est-ce que la selection a quitte le dernier bloc de ligne */
          pAb = pAb->AbEnclosing;
          while (pAb)
            if (pAb == LastInsertParagraph || pAb->AbBox == NULL)
              /* n'a pas change de paragraphe */
              pAb = NULL;
            else
              {
                pBox = pAb->AbBox;
                pEl = pAb->AbElement;
                if (pBox)
                  {
                    if (pBox->BxType == BoGhost || pBox->BxType == BoFloatGhost ||
                        (pEl &&
                         TypeHasException (ExcIsImg, pEl->ElTypeNumber, pEl->ElStructSchema)))
                      pAb = pAb->AbEnclosing;
                    else
                      {
                        /* Reevalue le bloc de lignes */
                        RecomputeLines (LastInsertParagraph, NULL, NULL,
                                        LastInsertThotWindow);
                        /* Et l'affiche */
                        RedrawFrameBottom (LastInsertThotWindow, 0, NULL);
                        LastInsertParagraph = NULL;
                        pAb = NULL;
                      }
                  }
              }
        }
    }
}

/*----------------------------------------------------------------------
  insere dans la boite pBox.                                      
  ----------------------------------------------------------------------*/
static void LoadSymbol (int c, PtrLine pLine, ThotBool defaultHeight,
                        ThotBool defaultWidth, PtrBox pBox, PtrAbstractBox pAb,
                        int frame)
{
  PtrDocument         pDoc;
  int                 xDelta, yDelta;
  int                 view;
  ThotBool            open;

  GetDocAndView (frame, &pDoc, &view);
  if (pDoc == NULL)
    return;
  open = !pDoc->DocEditSequence;
  if (!APPgraphicModify (pAb->AbElement, c, frame, TRUE, open))
    {
      pAb->AbShape = c;
      if (c <= 255)
        pAb->AbElement->ElGraph = (char)c;
      else
        {
          pAb->AbElement->ElGraph = '?';
          pAb->AbElement->ElWideChar = c;
        }
      /* Dimensions du symbole */
      pAb->AbVolume = 1;
      if (defaultWidth || defaultHeight)
        GiveSymbolSize (pAb, &xDelta, &yDelta);
      
      /* met a jour la boite */
      if (defaultWidth)
        xDelta -= pBox->BxWidth;
      else
        xDelta = 0;
      
      if (defaultHeight)
        yDelta -= pBox->BxHeight;
      else
        yDelta = 0;
      
      BoxUpdate (pBox, pLine, 0, 0, xDelta, 0, yDelta, frame, FALSE);
      /* adjust the width of some symbols */
      ResizeHeight (pBox, NULL, NULL, 0, 0, 0, frame);
      APPgraphicModify (pAb->AbElement, c, frame, FALSE, open);
    }
}


/*----------------------------------------------------------------------
  Charge un graphique ou une polyline.                            
  ----------------------------------------------------------------------*/
static void LoadShape (char c, PtrLine pLine, ThotBool defaultHeight,
                       ThotBool defaultWidth, PtrBox pBox, PtrAbstractBox pAb,
                       int frame)
{
  ViewFrame          *pFrame;
  PtrTextBuffer       pBuffer;
  PtrDocument         pDoc;
  int                 xDelta, yDelta;
  int                 width, height;
  int                 x, y;
  int                 view;
  ThotBool            open;

  pFrame = &ViewFrameTable[frame - 1];
  GetDocAndView (frame, &pDoc, &view);
  if (pDoc == NULL)
    return;
  open = !pDoc->DocEditSequence;
  if (!APPgraphicModify (pAb->AbElement, (int) c, frame, TRUE, open))
    {
      /* efface la selection precedente */
      switch (c)
        {
        case 'S':	/* polyline */
        case 'U':	/* polyline with forward arrow */
        case 'N':	/* polyline with backward arrow */
        case 'M':	/* polyline with arrows at both ends */
        case 'w':	/* segment */
        case 'x':	/* segment with forward arrow */
        case 'y':	/* segment with backward arrow */
        case 'z':	/* segment with arrows at both ends */
        case 'B':	/* Beziers (ouvertes) */
        case 'A':	/* Beziers (ouvertes) flechees vers avant */
        case 'F':	/* Beziers (ouvertes) flechees vers arriere */
        case 'D':	/* Beziers (ouvertes) flechees dns les deux sens */
        case 'p':	/* polygone */
        case 's':	/* spline fermee */
          pAb->AbPolyLineShape = c;
          width = pBox->BxWidth;
          height = pBox->BxHeight;
          if (pBox->BxBuffer == NULL)
            {
              /* Changement de graphique simple a polyline */
              pAb->AbLeafType = LtPolyLine;
              pAb->AbElement->ElLeafType = LtPolyLine;
              /* creation du buffer initial pour ranger les points de la polyline */
              GetTextBuffer (&(pAb->AbPolyLineBuffer));
              pAb->AbPolyLineBuffer->BuLength = 1;
              pAb->AbPolyLineBuffer->BuPoints[0].XCoord = LogicalValue (width, UnPixel, NULL,
                                                                        ViewFrameTable[frame - 1].FrMagnification);
              pAb->AbPolyLineBuffer->BuPoints[0].YCoord = LogicalValue (height, UnPixel, NULL,
                                                                        ViewFrameTable[frame - 1].FrMagnification);
              GetTextBuffer (&(pBox->BxBuffer));
              /* initialise la dimension de la boite polyline */
              pBox->BxBuffer->BuLength = 1;
              pBox->BxBuffer->BuPoints[0].XCoord = pAb->AbPolyLineBuffer->BuPoints[0].XCoord;
              pBox->BxBuffer->BuPoints[0].YCoord = pAb->AbPolyLineBuffer->BuPoints[0].YCoord;
              pBox->BxNChars = 1;
            }
	  
          if (pBox->BxNChars == 1)
            {
              /* il faut saisir les points de la polyline */
              x = pBox->BxXOrg - pFrame->FrXOrg;
              y = pBox->BxYOrg - pFrame->FrYOrg;
              if (c == 'w' || c == 'x' || c == 'y' || c == 'z')
                pAb->AbVolume = PolyLineCreation (frame, &x, &y, pBox, 2);
              else
                pAb->AbVolume = PolyLineCreation (frame, &x, &y, pBox, 0);
              pAb->AbElement->ElNPoints = pAb->AbVolume;
              pBox->BxNChars = pAb->AbVolume;
              DisplayPointSelection (frame, pBox, 0);
#ifdef _GTK
              pBox->BxXRatio = 1;
              pBox->BxYRatio = 1;
#endif /* _GTK */
            }

          /* redisplay the whole box */
          DefBoxRegion (frame, pBox, -1, -1, -1, -1);
          break;

        default:	/* un graphique simple */
          if (pBox->BxBuffer != NULL)
            {
              /* Transformation polyline en graphique simple */
              pAb->AbLeafType = LtGraphics;
              /* libere les points de controle */
              if (pBox->BxPictInfo != NULL)
                {
                  free ((STRING) pBox->BxPictInfo);
                  pBox->BxPictInfo = NULL;
                }
              /* il faut liberer les buffers */
              pBox->BxNChars = 1;
              pBuffer = pBox->BxBuffer;
              while (pBuffer != NULL)
                {
                  pBox->BxBuffer = pBuffer->BuNext;
                  FreeTextBuffer (pBuffer);
                  pBuffer = pBox->BxBuffer;
                }
              pBuffer = pAb->AbPolyLineBuffer;
              while (pBuffer != NULL)
                {
                  pAb->AbPolyLineBuffer = pBuffer->BuNext;
                  FreeTextBuffer (pBuffer);
                  pBuffer = pAb->AbPolyLineBuffer;
                }
            }

          pAb->AbShape = c;
          pAb->AbVolume = 1;
          if (c == 'g' && pAb->AbEnclosing &&
              pAb->AbEnclosing->AbWidth.DimIsPosition)
            {
              x = pBox->BxXOrg - pFrame->FrXOrg;
              y = pBox->BxYOrg - pFrame->FrYOrg;
              LineCreation (frame, pBox, &x, &y, &xDelta, &yDelta);
              /* Update the enclosing stretchable box */
              pAb = pAb->AbEnclosing;
              NewPosition (pAb, x, 0, y, 0, frame, TRUE);
              NewDimension (pAb, xDelta, yDelta, frame, TRUE);
            }
          else
            {
              if (c == 'C')
                /* rectangle with rounded corners */
                {
                  pAb->AbRx = 0;
                  pAb->AbRy = 0;
                }
              /* Dimensions du symbole */
              GiveGraphicSize (pAb, &xDelta, &yDelta);
              /* met a jour la boite */
              if (defaultWidth)
                xDelta -= pBox->BxWidth;
              else
                xDelta = 0;
              if (defaultHeight)
                yDelta -= pBox->BxHeight;
              else
                yDelta = 0;
              BoxUpdate (pBox, pLine, 0, 0, xDelta, 0, yDelta, frame, FALSE);
            }
        }
      /* but could notify its parent */
      APPgraphicModify (pAb->AbElement, (int) c, frame, FALSE, open);
    }
}


/*----------------------------------------------------------------------
  insere dans la boite pBox.                                     
  ----------------------------------------------------------------------*/
static void LoadPictFile (PtrLine pLine, ThotBool defaultHeight,
                          ThotBool defaultWidth, PtrBox pBox, PtrAbstractBox pAb,
                          int frame)
{
  if (pAb->AbLeafType == LtPicture)
    {
      /* give access to the application image menu */
      if (!APPtextModify (pAb->AbElement, frame, TRUE))
        /* register the editing operation in the history */
        RegisterInHistory (pAb->AbElement, NULL, frame, 0, 0);	     
    }
}


/*----------------------------------------------------------------------
  ClearClipboard cleans up all allocated buffers.
  ----------------------------------------------------------------------*/
void ClearClipboard (PtrTextBuffer clipboard)
{
  PtrTextBuffer       pBuffer, pNext;

  pBuffer = clipboard;
  if (pBuffer->BuLength != 0)
    {
      pBuffer->BuLength = 0;
      pBuffer->BuContent[0] = EOS;
      pBuffer = pBuffer->BuNext;
      while (pBuffer)
        {
          pNext = pBuffer->BuNext;
          pBuffer = DeleteBuffer (pBuffer, ActiveFrame);
          pBuffer = pNext;
        }
    }
}


/*----------------------------------------------------------------------
  sauve le contenu de la se'lection donne'e en parame`tre         
  dans le registre X ou Thot.                                     
  charsDelta donne le nombre de caracte`res pre'ce'dents,         
  ind l'indice du premier caracte`re dans le buffer et pBuffer le 
  premier buffer de texte.                                        
  Retourne :                                                      
  - charsDelta le nombre de caracte`res copie's                   
  - spacesDelta le nombre de blancs copie's                       
  - xDelta la largeur de la chaine copie'e                        
  ----------------------------------------------------------------------*/
static void SaveInClipboard (int *charsDelta, int *spacesDelta, int *xDelta,
                             int ind, PtrTextBuffer pBuffer, PtrAbstractBox pAb,
                             int frame, PtrTextBuffer clipboard)
{
  PtrTextBuffer       pTargetBuffer;
  ViewFrame          *pFrame;
  ThotPictInfo       *image;
  int                 i;

  /* detruit la sauvegarde precedente */
  ClearClipboard (clipboard);
  /* sauve la selection courante */
  if (pAb != NULL)
    {
      if (pAb->AbVolume != 0)
        {
          ClipboardType = pAb->AbLeafType;
          ClipboardLanguage = TtaGetDefaultLanguage ();
          if (pAb->AbLeafType == LtSymbol || pAb->AbLeafType == LtGraphics)
            {
              clipboard->BuLength = 1;
              clipboard->BuContent[0] = pAb->AbShape;
              /* caractere trace ou symbole */
              clipboard->BuContent[1] = EOS;
            }
          else if (pAb->AbLeafType == LtPicture)
            {
              image = (ThotPictInfo *) pAb->AbPictInfo;
              i = strlen (image->PicFileName);
              /* nom du fichier image */
              CopyMBs2Buffer ((unsigned char*)image->PicFileName, clipboard, 0, i);
              CopyPictInfo ((int *) &PictClipboard, (int *) image);
            }
          else
            {
              pFrame = &ViewFrameTable[frame - 1];
              if (pAb->AbLeafType == LtText && *charsDelta < pAb->AbVolume)
                {
                  /* enable the Paste command */
                  if (FirstSavedElement == NULL &&
                      ClipboardThot.BuLength == 0)
                    /* switch the Paste entry in all documents */
                    SwitchPaste (NULL, TRUE);
		  
                  ClipboardLanguage = pAb->AbLang;
                  /* sauve le texte selectionne dans la feuille */
                  i = 0;	/* Indice de debut */
                  pTargetBuffer = &ClipboardThot;
                  CopyBuffers (pAb->AbBox->BxFont, frame, ind,
                               pFrame->FrSelectionEnd.VsIndBuf, i,
                               pBuffer, pFrame->FrSelectionEnd.VsBuffer,
                               &pTargetBuffer, xDelta, spacesDelta, charsDelta);
                }
              else
                {
                  *xDelta = 0;
                  *charsDelta = 0;
                  *spacesDelta = 0;
                }
            }
        }
    }
}


/*----------------------------------------------------------------------
  RemoveSelection deletes the contents of the current selection.
  - charsDelta le nombre de caracteres copies                     
  - spacesDelta le nombre de blancs copies                        
  - xDelta la largeur de la chaine copiee                         
  ----------------------------------------------------------------------*/
static void RemoveSelection (int charsDelta, int spacesDelta, int xDelta,
                             ThotBool defaultHeight, ThotBool defaultWidth,
                             PtrLine pLine, PtrBox pBox, PtrAbstractBox pAb,
                             int frame, ThotBool notify)
{
  PtrDocument         pDoc;
  PtrTextBuffer       pTargetBuffer;
  PtrTextBuffer       pSourceBuffer;
  ThotPictInfo       *image;
  ViewFrame          *pFrame;
  ViewSelection      *pViewSel, *pViewSelEnd;
  SpecFont             font;
  int                 sourceInd, targetInd;
  int                 length;
  int                 i;
  int                 adjust;
  int                 yDelta;
  int                 width, height;
  int                 view;
  ThotBool            open;

  font = pBox->BxFont;
  width = BoxCharacterWidth (109, font);
  height = BoxFontHeight (font, pBox->BxScript);
  if (pAb->AbVolume == 0)
    DefClip (frame, 0, 0, 0, 0);
  else
    switch (pAb->AbLeafType)
      {
      case LtText:
        pFrame = &ViewFrameTable[frame - 1];
        pViewSel = &pFrame->FrSelectionBegin;
        pViewSelEnd = &pFrame->FrSelectionEnd;
        /* Note que le texte de l'e'le'ment va changer */
        StartTextInsertion (NULL, frame, NULL, NULL, 0, 0);
        /* fusionne le premier et dernier buffer de la selection */
        /* target of the moving */
        pTargetBuffer = pViewSel->VsBuffer;
        targetInd = pViewSel->VsIndBuf;
        /* source of the moving */
        pSourceBuffer = pViewSelEnd->VsBuffer;
        sourceInd = pViewSelEnd->VsIndBuf;
        if (SelPosition)
          {
            if (sourceInd >= pSourceBuffer->BuLength - 1)
              {
                pSourceBuffer = pSourceBuffer->BuNext;
                sourceInd = 0;
              }
            else
              sourceInd++;
          }
        if (pSourceBuffer)
          {
            /* nombre de caracteres a copier */
            i = pSourceBuffer->BuLength - sourceInd;
            if (i <= 0)
              /* no moving */
              i = targetInd;
            else
              {
                length = FULL_BUFFER - targetInd;
                /* deplace en deux fois? */
                if (i > length)
                  {
                    ustrncpy (&pTargetBuffer->BuContent[targetInd],
                              &pSourceBuffer->BuContent[sourceInd], length);
                    pTargetBuffer->BuLength = FULL_BUFFER;
                    pTargetBuffer->BuContent[FULL_BUFFER] = EOS;
                    targetInd = 0;
                    sourceInd += length;
                    i -= length;
                    pTargetBuffer = pTargetBuffer->BuNext;
                  }
                ustrncpy (&pTargetBuffer->BuContent[targetInd],
                          &pSourceBuffer->BuContent[sourceInd], i);
                i += targetInd;
              }
          }
        else
          i = pViewSel->VsIndBuf;
        pTargetBuffer->BuLength = i;
        pTargetBuffer->BuContent[i] = EOS;
	
        /* Faut-il liberer le buffer 'pTargetBuffer' ? */
        if (pTargetBuffer->BuLength == 0 &&
            (charsDelta != pAb->AbVolume ||
             (charsDelta == pAb->AbVolume && pTargetBuffer->BuPrevious)))
          {
            /* Est-ce que l'on libere le premier buffer du pave ? */
            if (pTargetBuffer == pAb->AbText)
              {
                pAb->AbText = pSourceBuffer->BuNext;
                pAb->AbBox->BxBuffer = pAb->AbText;
              }

            /* Est-ce que l'on libere le premier buffer d'une boite ? */
            if (pTargetBuffer == pBox->BxBuffer)
              pBox->BxBuffer = pSourceBuffer->BuNext;
	    
            if (pTargetBuffer == pViewSel->VsBuffer)
              {
                /* the selection points to a freed buffer */
                if (pSourceBuffer && pSourceBuffer->BuNext)
                  /* move after the deleted part */
                  pViewSel->VsBuffer = pSourceBuffer->BuNext;
                else
                  {
                    /* move before */
                    pViewSel->VsBuffer = pTargetBuffer->BuPrevious;
                    if (pViewSel->VsBuffer)
                      pViewSel->VsIndBuf = pViewSel->VsBuffer->BuLength;
                  }
              }
	    
            if (pTargetBuffer == pSourceBuffer)
              pSourceBuffer = NULL;
            pTargetBuffer = DeleteBuffer (pTargetBuffer, frame);
          }
	
        /* remove empty buffers */
        while (pSourceBuffer && pSourceBuffer != pTargetBuffer)
          pSourceBuffer = DeleteBuffer (pSourceBuffer, frame);
	
        /* prepare the box update */
        if (pBox->BxSpaceWidth != 0)
          {
            /* adjusted box */
            i = BoxCharacterWidth (SPACE, font);
            adjust = xDelta + (pBox->BxSpaceWidth - i) * spacesDelta;
          }
        else
          adjust = 0;
        if (charsDelta == pAb->AbVolume)
          {
            /* the box becomes empty */
            xDelta = pAb->AbBox->BxWidth - width;
            if (pBox == pAb->AbBox && adjust != 0)
              adjust = xDelta;
            else
              adjust = 0;
            /* the whole paragraph should be recomputed */
            pViewSel->VsBox = pAb->AbBox;
          }
        else if (pViewSel->VsIndBuf >= pViewSel->VsBuffer->BuLength)
          {
            /* En fin de buffer -> on va chercher le caractere suivant */
            pSourceBuffer = pViewSel->VsBuffer->BuNext;
            /* Il peut etre vide s'il y a des blancs en fin de ligne */
            if (pSourceBuffer)
              {
                /* deplace la selection sur le debut du buffer suivant */
                pViewSel->VsBuffer = pSourceBuffer;
                pViewSel->VsIndBuf = 0;
              }
          }
	
        /* the selection points to the next character */
        pViewSelEnd->VsBox = pViewSel->VsBox;
        pViewSelEnd->VsIndBox = pViewSel->VsIndBox;
        pFrame->FrSelectOnePosition = TRUE;
        SelPosition = TRUE;
        /* box update */
        pAb->AbVolume -= charsDelta;
        BoxUpdate (pAb->AbBox, pLine, -charsDelta, -spacesDelta, -xDelta,
                   -adjust, 0, frame, FALSE);
        if (notify)
          CloseTextInsertion ();
        break;
	
      case LtPicture:
        pAb->AbVolume = 0;
        /* met a jour la boite */
        image = (ThotPictInfo *) pBox->BxPictInfo;
        if (image->PicPixmap != 0)
          {
            if (defaultWidth)
              xDelta = image->PicWArea - width;
            else
              xDelta = 0;
            if (defaultHeight)
              yDelta = image->PicHArea - height;
            else
              yDelta = 0;
            BoxUpdate (pBox, pLine, 0, 0, -xDelta, 0, -yDelta, frame, FALSE);
          }
        break;
	
      case LtSymbol:
      case LtGraphics:
        /* send an event to the application and register the change
           in the Undo queue */
        GetDocAndView (frame, &pDoc, &view);
        if (pDoc == NULL)
          return;
        open = !pDoc->DocEditSequence;
        APPgraphicModify (pBox->BxAbstractBox->AbElement,
                          (int) pAb->AbShape, frame, TRUE, open);
        if (defaultWidth)
          xDelta = pBox->BxWidth - width;
        else
          xDelta = 0;
        if (defaultHeight)
          yDelta = pBox->BxHeight - height;
        else
          yDelta = 0;
        BoxUpdate (pBox, pLine, -1, 0, -xDelta, 0, -yDelta, frame, FALSE);
        if (pAb->AbLeafType == LtGraphics && pAb->AbShape == 'C')
          {
            pAb->AbRx = 0;
            pAb->AbRy = 0;
          }
        pAb->AbVolume = 0;
        pAb->AbShape = EOS;
        APPgraphicModify (pBox->BxAbstractBox->AbElement,
                          (int) pAb->AbShape, frame, FALSE, open);
        break;
	
      default:
        break;
      }
}


/*----------------------------------------------------------------------
  detruit sans sauver le contenu de la selection courante.        
  ----------------------------------------------------------------------*/
static void DeleteSelection (ThotBool defaultHeight, ThotBool defaultWidth,
                             PtrLine pLine, PtrBox pBox, PtrAbstractBox pAb,
                             int frame, ThotBool notify)
{
  PtrTextBuffer       pTargetBuffer;
  ViewFrame          *pFrame;
  int                 start, end;
  int                 xDelta, charsDelta;
  int                 spacesDelta;

  charsDelta = 0;
  if (pAb)
    {
      if (pAb->AbLeafType == LtText)
        {
          pFrame = &ViewFrameTable[frame - 1];
          /* index of the beginning */
          pTargetBuffer = NULL;
          start = pFrame->FrSelectionBegin.VsIndBuf;
          end = pFrame->FrSelectionEnd.VsIndBuf;
          if (SelPosition)
            /* suppress the next char */
            end++;
          /* get values xDelta, spacesDelta, charsDelta */
          if (pFrame->FrSelectionBegin.VsIndBox == pAb->AbVolume)
            {
              xDelta = 0;
              spacesDelta = 0;
            }
          else
            CopyBuffers (pBox->BxFont, frame,
                         start, end, 0,
                         pFrame->FrSelectionBegin.VsBuffer,
                         pFrame->FrSelectionEnd.VsBuffer, &pTargetBuffer,
                         &xDelta, &spacesDelta, &charsDelta);
        }
    }
  /* remove the contents of the current selection */
  if (charsDelta > 0)
    RemoveSelection (charsDelta, spacesDelta, xDelta, defaultHeight,
                     defaultWidth, pLine, pBox, pAb, frame, notify);
}


/*----------------------------------------------------------------------
  insere le dernier clipboard X ou Thot sauve.                    
  - charsDelta donne le nombre de caracteres copies               
  - spacesDelta donne le nombre de blancs copies                  
  - xDelta donne la largeur de la chaine copiee                   
  ----------------------------------------------------------------------*/
static void PasteClipboard (ThotBool defaultHeight, ThotBool defaultWidth,
                            PtrLine pLine, PtrBox pBox, PtrAbstractBox pAb,
                            int frame, PtrTextBuffer clipboard)
{
  PtrTextBuffer       pBuffer;
  PtrTextBuffer       pNewBuffer;
  ViewFrame          *pFrame;
  ViewSelection      *pViewSel;
  ViewSelection      *pViewSelEnd;
  PtrTextBuffer       pCurrentBuffer;
  PtrDocument         pDoc;
  SpecFont            font;
  int                 view;
  int                 ind;
  int                 i, l;
  int                 xDelta, yDelta;
  int                 spacesDelta, charsDelta;
  int                 adjust;
  int                 height;
  int                 width;
  ThotPictInfo       *image;

  font = pBox->BxFont;
  width = 2; /* see GiveTextSize function */
  height = BoxFontHeight (font, pBox->BxScript);

  switch (pAb->AbLeafType)
    {
    case LtText:
      pFrame = &ViewFrameTable[frame - 1];
      pViewSel = &pFrame->FrSelectionBegin;
      pViewSelEnd = &pFrame->FrSelectionEnd;

      /* Coupure des buffers pour l'insertion */
      if (!TextInserting)
        StartTextInsertion (NULL, frame, NULL, NULL, 0, 0);

      /* Insertion en fin de buffer */
      if (pViewSel->VsIndBuf >= pViewSel->VsBuffer->BuLength)
        {
          /* insertion en fin de buffer courant */
          pBuffer = pViewSel->VsBuffer;
          ind = pViewSel->VsIndBuf;
          /* Pas besoin d'essayer de recoller les buffer */
          TextInserting = FALSE;
        }
      else
        {
          /* buffer debut d'insertion */
          pBuffer = pViewSel->VsBuffer;
          if ( pBuffer->BuPrevious)
            pBuffer = pBuffer->BuPrevious;
          /* index debut d'insertion */
          ind = pBuffer->BuLength;
        }

      /* Insertion des caracteres */
      pNewBuffer = pBuffer;
      CopyBuffers (font, frame, 0, 0, ind, clipboard, NULL,
                   &pNewBuffer, &xDelta, &spacesDelta,
                   &charsDelta);
      /* termine l'insertion */
      pAb->AbVolume += charsDelta;
      /* Move the selection at the end of inserted text */
      pViewSel->VsIndBox = pViewSel->VsIndBox + charsDelta;
      pViewSelEnd->VsIndBox = pViewSel->VsIndBox;
      pViewSel->VsXPos = pViewSel->VsXPos + xDelta;
      pViewSelEnd->VsXPos = pViewSel->VsXPos;
      /* last inserted buffer */
      pViewSel->VsBuffer = pNewBuffer;
      pViewSelEnd->VsBuffer = pNewBuffer;
      pViewSel->VsIndBuf = pNewBuffer->BuLength;
      pViewSelEnd->VsIndBuf = pNewBuffer->BuLength;
      pViewSelEnd->VsBox = pViewSel->VsBox;
      /* +nombre de blancs */
      pViewSel->VsNSpaces = pViewSel->VsNSpaces + spacesDelta;
      pViewSelEnd->VsNSpaces = pViewSel->VsNSpaces;
      pViewSel->VsLine = pLine;
      pViewSelEnd->VsLine = pLine;
      pFrame->FrSelectOnePosition = TRUE;
      /* the new selection is not shown */
      pFrame->FrSelectShown = FALSE;
      if (pAb->AbVolume == charsDelta)
        /* the box was empty */
        xDelta -= /*width*/pBox->BxWidth;
      if (pBox->BxSpaceWidth != 0)
        {
          /* Si la boite est adjustifiee */
          i = BoxCharacterWidth (SPACE, font);
          adjust = xDelta + (pBox->BxSpaceWidth - i) * spacesDelta;
        }
      else
        adjust = 0;

      /* Si le clipboard contient un caractere de coupure forcee */
      /* il faut demander la reevaluation de la mise en lignes  */
      if (IsLineBreakInside (pBox->BxBuffer, pBox->BxFirstChar, pBox->BxNChars + charsDelta))
        BoxUpdate (pBox, pLine, charsDelta, spacesDelta, xDelta, adjust,
                   0, frame, TRUE);
      else
        BoxUpdate (pBox, pLine, charsDelta, spacesDelta, xDelta, adjust,
                   0, frame, FALSE);
      CloseTextInsertion ();
      GetDocAndView (frame, &pDoc, &view);
      CloseHistorySequence (pDoc);
      break;
    case LtPicture:
      pCurrentBuffer = pAb->AbElement->ElText;
      /* met a jour la boite */
      image = (ThotPictInfo *) pBox->BxPictInfo;
      CopyPictInfo ((int *) image, (int *) &PictClipboard);
      i = clipboard->BuLength;
      ustrncpy (pCurrentBuffer->BuContent, clipboard->BuContent, i);
      /* Termine la chaine de caracteres */
      pCurrentBuffer->BuContent[i] = EOS;
      pCurrentBuffer->BuLength = i;
      i = 400;
      image->PicFileName = (char*)TtaGetMemory (i);
      /* i should be too short to store non ascii characters */
      l = CopyBuffer2MBs (clipboard, 0, (unsigned char*)image->PicFileName, i - 1);
      SetCursorWatch (frame);
      LoadPicture (frame, pBox, image);
      ResetCursorWatch (frame);
      if (image->PicPixmap != 0)
        {
          pAb->AbVolume = i;
          xDelta = image->PicWArea - width;
          yDelta = image->PicHArea - height;
          BoxUpdate (pBox, pLine, 0, 0, xDelta, 0, yDelta, frame, FALSE);
        }
      break;
    case LtSymbol:
      LoadSymbol (clipboard->BuContent[0], pLine, defaultHeight,
                  defaultWidth, pBox, pAb, frame);
      break;
    case LtPolyLine:
    case LtGraphics:
      LoadShape ((char)clipboard->BuContent[0], pLine, defaultHeight,
                 defaultWidth, pBox, pAb, frame);
      break;
    default:
      break;
    }
}

/*----------------------------------------------------------------------
  ContentEditing manages Cut, Paste, Copy, Remvoe, and Insert commands.
  Return TRUE if a Cut command moved the selection to a next element.
  ----------------------------------------------------------------------*/
ThotBool ContentEditing (int editType)
{
  PtrBox              pBox;
  PtrBox              pSelBox;
  PtrAbstractBox      pAb, pCell;
  PtrAbstractBox      pLastAb, pBlock;
  PtrAttribute        pAttr;
  PtrElement          pEl;
  PtrDocument         pDoc;
  AbDimension        *pPavD1;
  ViewSelection      *pViewSel;
  ViewSelection      *pViewSelEnd;
  ViewFrame          *pFrame;
  PtrTextBuffer       pBuffer;
  Propagation         savePropagate;
  PtrLine             pLine;
  NotifyAttribute     notifyAttr;
  int                 x, y;
  int                 i, j;
  int                 spacesDelta, charsDelta;
  int                 frame, doc;
  ThotBool            still, ok, textPasted;
  ThotBool            defaultWidth, defaultHeight;
  ThotBool            show, graphEdit, open, selNext = FALSE;

  pCell = NULL;
  textPasted = FALSE;
  graphEdit = FALSE;

  if (editType == TEXT_PASTE && ClipboardThot.BuLength == 0 && !NewInsert)
    {
      /* close the current text insertion */
      CloseTextInsertion ();
      /* paste a structured element */
      PasteCommand ();
    }
  /* Traitement des Commandes INSERT, CUT, TEXT_DEL, COPY */
  else
    {
      /* recupere la fenetre active pour la selection */
      frame = ActiveFrame;
      /*-- recherche le pave concerne --*/
      if (frame <= 0)
        return selNext;
      else
        {
          if (editType == TEXT_PASTE || editType == TEXT_X_PASTE)
            CloseTextInsertionWithControl (FALSE);
          else if ((editType != TEXT_DEL && editType != TEXT_SUP) ||
                   !ViewFrameTable[frame - 1].FrSelectOnePosition ||
                   (FirstSelectedElement && FirstSelectedElement->ElVolume == 0))
            /* close the current text insertion */
            CloseTextInsertion ();

          /* verifie qu'une selection courante est visualisee */
          pBox = ViewFrameTable[frame - 1].FrSelectionBegin.VsBox;
          if (pBox == NULL)
            {
              TtaSetFocus ();
              /* a pu ici changer de frame active pour la selection */
              frame = ActiveFrame;
              if (frame == 0)
                return selNext;	/* nothing to do */
              else
                {
                  pBox = ViewFrameTable[frame - 1].FrSelectionBegin.VsBox;
                  if (pBox == NULL)
                    return selNext;	/* nothing to do */
                  pAb = pBox->BxAbstractBox;
                }
            }
          else
            pAb = pBox->BxAbstractBox;
          if (pAb->AbReadOnly &&
              (editType == TEXT_INSERT || editType == TEXT_PASTE))
            /* the box to be edited is read-only */
            /* can't insert or paste within a read-only char string */
            return selNext;
          if (editType == TEXT_DEL || editType == TEXT_CUT)
            {
              if (AbsBoxSelectedAttr)
                {
                  if (AbsBoxSelectedAttr->AbReadOnly)
                    /* selection within a read-only attribute value */
                    return selNext;
                }
              else
                {
                  if (FirstSelectedElement == NULL ||
                      ElementIsReadOnly (FirstSelectedElement->ElParent))
                    /* the parent element is read-only.
                       Don't delete anything*/
                    return selNext;
                  else if (ElementIsReadOnly (FirstSelectedElement))
                    {
                      /* the parent is not read-only */
                      /* the selected element itself is read-only */
                      if (FirstSelectedElement == LastSelectedElement &&
                          FirstSelectedElement->ElTerminal &&
                          FirstSelectedElement->ElLeafType == LtText)
                        /* selection is within a single text element */
                        if (FirstSelectedChar > 1 ||
                            (LastSelectedChar > 0 &&
                             LastSelectedChar < LastSelectedElement->ElVolume))
                          /* the text element is not completely selected */
                          return selNext;
                    }
                }
            }
        }
      /*-- La commande coller concerne le mediateur --*/
      if (editType == TEXT_PASTE && !NewInsert)
        /* Il faut peut-etre deplacer la selection courante */
        SetInsert (&pAb, &frame, ClipboardType, FALSE);

      pFrame = &ViewFrameTable[frame - 1];
      doc = FrameTable[frame].FrDoc;
      pDoc = LoadedDocument[doc - 1];
      if (pDoc == NULL)
        return selNext;
      open = !pDoc->DocEditSequence;
      pViewSel = &pFrame->FrSelectionBegin;
      show = (documentDisplayMode[doc - 1] == DisplayImmediately);
      if (pBox && editType == TEXT_SUP)
        {
          /* don't remove the selection if it is at the end of the text */
          if (pAb->AbLeafType == LtText &&
              pBox == ViewFrameTable[frame - 1].FrSelectionEnd.VsBox &&
              pViewSel->VsIndBox >= pBox->BxNChars &&
              pBox->BxAbstractBox->AbVolume != 0)
            return selNext;
        }

      if (editType == TEXT_INSERT && !NewInsert)
        {
          if (pBox && pViewSel->VsIndBox != 0)
            {
              if (pAb->AbLeafType == LtPolyLine)
                {
                  /* ignore single segments (with or without arrow head(s)) */
                  if (pAb->AbPolyLineShape != 'w' &&
                      pAb->AbPolyLineShape != 'x' &&
                      pAb->AbPolyLineShape != 'y' &&
                      pAb->AbPolyLineShape != 'z')
                    /* Add a point to a polyline */
                    {
                      still = (pAb->AbPolyLineShape == 'p' || /* plygon */
                               pAb->AbPolyLineShape == 's');  /* closed curve*/
                      if (!APPgraphicModify (pAb->AbElement,
                                             pAb->AbPolyLineShape, frame, TRUE, open))
                        {
                          x = pBox->BxXOrg - pFrame->FrXOrg;
                          y = pBox->BxYOrg - pFrame->FrYOrg;
                          i = pViewSel->VsIndBox;
                          pBox->BxNChars = PolyLineExtension (frame, &x, &y,
                                                              pBox, pBox->BxNChars, i, still);
                          graphEdit = TRUE;
                          pAb->AbVolume = pBox->BxNChars;
                          if (pBox->BxPictInfo != NULL)
                            {
                              /* reevalue les points de controle */
                              free ((STRING) pBox->BxPictInfo);
                              pBox->BxPictInfo = NULL;
                            }
                        }
                    }
                  else
                    /* la commande est realisee par l'application */
                    pAb = NULL;
                }
              else
                {
                  if (ThotLocalActions[T_insertpaste] != NULL)
                    (*(Proc4)ThotLocalActions[T_insertpaste]) (
                                                               (void *)TRUE,
                                                               (void *)FALSE,
                                                               (void *)'L',
                                                               (void *)&ok);
                  else
                    ok = FALSE;
                  if (ok)
                    /* la commande est realisee par l'application */
                    pAb = NULL;
                }
            }
          else if (pAb->AbLeafType != LtPicture)
            {
              if (ThotLocalActions[T_insertpaste] != NULL)
                (*(Proc4)ThotLocalActions[T_insertpaste]) (
                                                           (void *)TRUE,
                                                           (void *)FALSE,
                                                           (void *)'L',
                                                           (void *)&ok);
              else
                ok = FALSE;
              if (ok)
                /* la commande est realisee par l'application */
                pAb = NULL;
            }
        }

      if (pAb)
        {
          pLastAb = NULL;
          /*-- Les commandes sont traitees dans l'application */
          /* si la selection ne porte que sur un pave */
          pBox = ViewFrameTable[frame - 1].FrSelectionEnd.VsBox;
          if (pBox == NULL)
            pAb = NULL;
          else
            {
              pLastAb = pBox->BxAbstractBox;
              /* saute les paves de presentation selectionnes */
              while (pLastAb != pAb && pLastAb->AbPresentationBox)
                pLastAb = pLastAb->AbPrevious;
            }
	  
          /* Recherche le point d'insertion (&i non utilise) */
          GiveInsertPoint (pAb, '*', frame, &pBox, &pBuffer, &i, &x, &charsDelta);
          if (pBox == NULL)
            {
              /* take in account another box */
              if (editType == TEXT_CUT || editType == TEXT_DEL ||
                  editType == TEXT_SUP)
                {
                  DeleteNextChar (frame, pAb->AbElement, FALSE);
                  pFrame->FrReady = TRUE;
                  return selNext;
                }
              else
                pAb = NULL;
            }
          else if (pAb)
            pAb = pBox->BxAbstractBox;
	  
          if (pAb)
            {
              if ((editType == TEXT_CUT || editType == TEXT_DEL) &&
                  pAb->AbCreatorAttr && pAb->AbVolume == 0 && SelPosition)
                {
                  /* delete on an empty attribute value removes the attribute */
                  pAttr = pAb->AbCreatorAttr;
                  pEl = pAb->AbElement;
                  notifyAttr.event = TteAttrDelete;
                  notifyAttr.document = doc;
                  notifyAttr.element = (Element) pEl;
                  notifyAttr.info = 0; /* not sent by undo */
                  notifyAttr.attribute = (Attribute) pAttr;
                  notifyAttr.attributeType.AttrSSchema = (SSchema) (pAttr->AeAttrSSchema);
                  notifyAttr.attributeType.AttrTypeNum = pAttr->AeAttrNum;
                  if (!CallEventAttribute (&notifyAttr, TRUE))
                    {
                      if (pDoc->DocEditSequence)
                        /* close the previous sequence */
                        CloseHistorySequence (pDoc);
                      OpenHistorySequence (pDoc, pEl, pEl, pAttr, 1, 0);
                      TtaRemoveAttribute ((Element) pEl, (Attribute) pAttr,
                                          doc);
                      CloseHistorySequence (pDoc);
                      SelectElement (pDoc, pEl, FALSE, FALSE);
                    }
                  notifyAttr.attribute = NULL;
                  CallEventAttribute (&notifyAttr, FALSE);
                  return selNext;
                }
              else if (FirstSelectedElement != LastSelectedElement ||
                       pAb != pLastAb)
                /* more than one element or one abstract box */
                pAb = NULL;
              else if (pAb->AbElement != FirstSelectedElement &&
                       FirstSelectedElement &&
                       (editType == TEXT_CUT || editType == TEXT_DEL ||
                        editType == TEXT_SUP || editType == TEXT_COPY))
                pAb = NULL;
              else if ((pAb->AbLeafType == LtText && editType == TEXT_INSERT)||
                       pAb->AbLeafType == LtCompound || /*le pave est compose*/
                       pAb->AbLeafType == LtPageColBreak) /* marque de page */
                pAb = NULL;
              else if ((editType == TEXT_CUT || editType == TEXT_DEL ||
                        editType == TEXT_SUP || editType == TEXT_COPY) &&
                       (pAb->AbVolume == 0 || pAb->AbLeafType == LtGraphics ||
                        pAb->AbLeafType == LtPath ||
                        pAb->AbLeafType == LtPicture))
                /* coupe ou copie un pave vide ou graphique ou une image */
                pAb = NULL;
              else if ((editType == TEXT_CUT || editType == TEXT_COPY) &&
                       pAb->AbLeafType == LtPolyLine)
                /* coupe ou copie un pave Polyline */
                pAb = NULL;
              else if (!pAb->AbCanBeModified && editType != TEXT_COPY)
                {
                  if (pViewSel->VsIndBox != 0 ||
                      pFrame->FrSelectionEnd.VsIndBox != 0) 
                    /* il n'est pas modifiable */
                    pAb = NULL;
                  else if (pAb->AbEnclosing &&
                           !pAb->AbEnclosing->AbCanBeModified)
                    /* il n'est pas modifiable */
                    pAb = NULL;
                }
              else if ((editType == TEXT_CUT || editType == TEXT_DEL) &&
                       pAb->AbLeafType == LtText &&
                       pAb->AbVolume == 1 && FirstSelectedChar < 1 &&
                       strcmp (pAb->AbPSchema->PsStructName, "TextFile") == 0)
                /* we are deleting the last character of a text leaf in a
                   text file. Do not leave an empty text leaf, but remove it
                   all together */
                pAb = NULL;
            }
        }

      if (pAb == NULL)
        {
          /* Le traitement concerne l'application */
          if ((editType == TEXT_DEL || editType == TEXT_SUP) && !NewInsert)
            {
              /* close the current text insertion */
              CloseTextInsertion ();
              selNext = CutCommand (FALSE, editType == TEXT_SUP);	/* Cut without saving */
            }
          else if (editType == TEXT_CUT || editType == TEXT_COPY)
            {
              SaveInClipboard (&charsDelta, &spacesDelta, &x, 0, NULL, pAb,
                               frame, &ClipboardThot);
              /* vide le clipboard du Mediateur */
              if (editType == TEXT_CUT && !NewInsert)
                {
                  /* close the current text insertion */
                  CloseTextInsertion ();
                  selNext = CutCommand (TRUE, FALSE);
                }
              else if (editType == TEXT_COPY && !NewInsert)
                CopyCommand ();
            }
        }
      else
        {
          /* check enclosing cell */
          pCell = GetParentCell (pBox);
          if ((editType == TEXT_DEL ||editType == TEXT_SUP) &&
              pAb->AbLeafType == LtPolyLine)
            {
              if (pViewSel->VsIndBox != 0)
                {
                  if (pBox->BxNChars > 3 &&
                      pAb->AbPolyLineShape != 'w' &&
                      pAb->AbPolyLineShape != 'x' &&
                      pAb->AbPolyLineShape != 'y' &&
                      pAb->AbPolyLineShape != 'z')
                    {
                      charsDelta = pViewSel->VsIndBox;
                      if (!APPgraphicModify (pAb->AbElement,
                                             pAb->AbPolyLineShape, frame, TRUE, open))
                        {
                          /* Destruction du point courant de la polyline */
                          DeletePointInPolyline (&(pAb->AbPolyLineBuffer),
                                                 charsDelta);
                          DeletePointInPolyline (&(pBox->BxBuffer),
                                                 charsDelta);
                          graphEdit = TRUE;
                          (pBox->BxNChars)--;
                          if (pBox->BxPictInfo != NULL)
                            {
                              /* reevalue les points de controle */
                              free ((STRING) pBox->BxPictInfo);
                              pBox->BxPictInfo = NULL;
                            }
                          (pAb->AbVolume)--;
                          if (charsDelta == pBox->BxNChars)
                            {
                              /* on vient de detruire le dernier point
                                 de la polyline */
                              if (charsDelta == 1)
                                charsDelta = 0;
                              else
                                charsDelta = 1;
                            }
                          pViewSel->VsIndBox = charsDelta;
                          /* redisplay the whole box */
                          DefBoxRegion (frame, pBox, -1, -1, -1, -1);
                        }
                    }
                }
              else
                {
                  /* Delete the whole polyline */
                  selNext = CutCommand (FALSE, FALSE);
                  pAb = NULL;	/* edit is done */
                }
            }
          else
            {
              /* regroupe ici les traitements realises par le mediateur */
              /* bloque affichage de la fenetre */
              if (editType != TEXT_COPY)
                pFrame->FrReady = FALSE;
	      
              /* Si la selection debutait sur une boite de presentation */
              /* il faut deplacer la selection sur le premier caractere */
              /* de la boite de texte (ou en fin de boite vide)         */
              if (editType != TEXT_COPY && pBox != pViewSel->VsBox)
                {
                  ClearViewSelection (frame);	/* efface la selection */
                  pViewSel->VsBox = pBox;
                  pViewSel->VsBuffer = pBuffer;
                  pViewSel->VsIndBuf = i;
                  pViewSel->VsIndBox = charsDelta;
                  pViewSel->VsXPos = 0;
                  pViewSel->VsNSpaces = 0;
                }
	      
              pLine = pFrame->FrSelectionBegin.VsLine;
              if (pBox->BxType == BoSplit)
                {
                  pSelBox = pBox->BxNexChild;
                  /* redisplay the whole box */
                  DefBoxRegion (frame, pSelBox, -1, -1, -1, -1);
                }
              else
                /* redisplay the whole box */
                DefBoxRegion (frame, pBox, -1, -1, -1, -1);
	      
              /* Est-ce que les dimensions de la boite dependent du contenu */
              pPavD1 = &pAb->AbWidth;
              if (pPavD1->DimIsPosition)
                /* Boite elastique */
                defaultWidth = FALSE;
              else if (pPavD1->DimAbRef == NULL && pPavD1->DimValue < 0)
                defaultWidth = TRUE;
              else
                defaultWidth = FALSE;
	      
              pPavD1 = &pAb->AbHeight;
              if (pPavD1->DimIsPosition)
                /* Boite elastique */
                defaultHeight = FALSE;
              else if (pPavD1->DimAbRef == NULL && pPavD1->DimValue < 0)
                defaultHeight = TRUE;
              else
                /* Dimensions d'une boite terminale vide */
                defaultHeight = FALSE;
		
              /* Traitement */
              if (editType == TEXT_INSERT && pAb->AbLeafType == LtPicture &&
                  !NewInsert)
                LoadPictFile (pLine, defaultHeight, defaultWidth, pBox, pAb,
                              frame);
              else if (editType == TEXT_CUT && !NewInsert)
                {
                  SaveInClipboard (&charsDelta, &spacesDelta, &x, i, pBuffer,
                                   pAb, frame, &ClipboardThot);
                  if (ClipboardThot.BuLength == 0)
                    {
                      DeleteNextChar (frame, pAb->AbElement, FALSE);
                      /* don't need to update the selection */
                      pFrame->FrReady = TRUE;
                      pAb = NULL;
                    }
                  else
                    RemoveSelection (charsDelta, spacesDelta, x, defaultHeight,
                                     defaultWidth, pLine, pBox, pAb, frame, TRUE);
                }
              else if ((editType == TEXT_DEL || editType == TEXT_SUP) &&
                       !NewInsert)
                if (pAb->AbVolume == 0 ||
                    pViewSel->VsIndBox + pViewSel->VsBox->BxFirstChar > pAb->AbVolume)
                  {
                    /* current selection is at the element end */
                    if (pAb->AbPresentationBox && pAb->AbCanBeModified)
                      /* do nothing */
                      DefClip (frame, 0, 0, 0, 0);		      
                    /* close the current text insertion */
                    CloseTextInsertion ();
                    DeleteNextChar (frame, pAb->AbElement, FALSE);
                    /* don't need to update the selection */
                    pFrame->FrReady = TRUE;
                    pAb = NULL;
                  }
                else
                  DeleteSelection (defaultHeight, defaultWidth, pLine, pBox,
                                   pAb, frame, FALSE/*editType != TEXT_SUP*/);
              else if (editType == TEXT_PASTE && !NewInsert)
                {
                  /* Verifie que l'script du clipboard correspond a celui
                     du pave */
                  if (ClipboardLanguage == 0)
                    ClipboardLanguage = TtaGetDefaultLanguage ();
                  if (pAb->AbLeafType != LtText &&
                      pAb->AbLang != ClipboardLanguage)
                    {
                      /* charsDelta contient le nombre de carateres qui
                         precedent dans la boite */
                      NewTextLanguage (pAb, charsDelta + pBox->BxFirstChar + 1,
                                       ClipboardLanguage);
                      pBox = pViewSel->VsBox;
                      if (pBox)
                        {
                          /* redisplay the whole box */
                          DefBoxRegion (frame, pBox, -1, -1, -1, -1);
                          pAb = pBox->BxAbstractBox;
                        }
                      else
                        pAb = NULL;
                    }

                  if (pAb != NULL)
                    {
                      PasteClipboard (defaultHeight, defaultWidth, pLine, 
                                      pBox, pAb, frame, &ClipboardThot);
                      textPasted = TRUE;
                    }
                }
              else if (editType == TEXT_COPY && !NewInsert)
                {
                  SaveInClipboard (&charsDelta, &spacesDelta, &x, i, pBuffer,
                                   pAb, frame, &ClipboardThot);
                  /* Reset the clipping */
                  DefClip (frame, 0, 0, 0, 0);
                  /* the selection is not changed */
                  pAb = NULL;
                }
              else if (editType == TEXT_X_PASTE && !NewInsert)
                {
                  PasteClipboard (defaultHeight, defaultWidth, pLine, pBox,
                                  pAb, frame, &XClipboard);
                  textPasted = TRUE;
                }
              else if (pAb->AbLeafType == LtPicture && NewInsert)
                LoadPictFile (pLine, defaultHeight, defaultWidth, pBox, pAb,
                              frame);
              else if (pAb->AbLeafType == LtSymbol && NewInsert)
                {
                  AddEditOpInHistory (pAb->AbElement, pDoc, TRUE, TRUE);
                  LoadSymbol (editType, pLine, defaultHeight,
                              defaultWidth, pBox, pAb, frame);
                  CloseHistorySequence (pDoc);
                }
              else if ((pAb->AbLeafType == LtGraphics ||
                        pAb->AbLeafType == LtPolyLine) &&
                       NewInsert)
                {
                  LoadShape ((char) editType, pLine, defaultHeight,
                             defaultWidth, pBox, pAb, frame);
                  NewContent (pAb);
                }
            }
        }
      
      if (pCell != NULL)
        {
          /* we have to propage the position to children */
          savePropagate = Propagate;
          Propagate = ToChildren;
          pBlock = SearchEnclosingType (pBox->BxAbstractBox, BoBlock, BoFloatBlock);
          if (pBlock)
            RecomputeLines (pBlock, NULL, NULL, frame);
          UpdateColumnWidth (pCell, NULL, frame);
          /* restore propagate mode */
          Propagate = savePropagate;
          /* Manage differed enclosings */
          ComputeEnclosing (frame);
        }
      
      if (pAb)
        {
          if (pAb->AbLeafType == LtGraphics)
            pAb->AbRealShape = pAb->AbShape;
          if (pAb->AbLeafType == LtGraphics ||
              pAb->AbLeafType == LtPolyLine)
            {
              /* remonte a la recherche d'un ancetre elastique */
              pLastAb = pAb;
              while (pLastAb != NULL)
                {
                  pSelBox = pLastAb->AbBox;
                  if (pSelBox->BxHorizFlex || pSelBox->BxVertFlex)
                    {
                      MirrorShape (pAb, pSelBox->BxHorizInverted,
                                   pSelBox->BxVertInverted,NewInsert);
                      /* on arrete */
                      pLastAb = NULL;
                    }
                  else
                    pLastAb = pLastAb->AbEnclosing;
                }
            }
	  
          /* reaffiche si necessaire */
          if (editType != TEXT_COPY)
            {
              pFrame->FrReady = TRUE;
              /* redisplay */
              if (show)
                still = RedrawFrameBottom (frame, 0, NULL);
            }
	  
          if (pAb->AbElement == NULL)
            /* le pave a disparu entre temps */
            return selNext;
	  
          /* signale la nouvelle selection courante */
          if ((editType == TEXT_CUT || editType == TEXT_PASTE ||
               editType == TEXT_X_PASTE || editType == TEXT_DEL ||
               editType == TEXT_SUP) && pViewSel->VsBox)
            {
              pViewSelEnd = &pFrame->FrSelectionEnd;
              i = pViewSel->VsBox->BxFirstChar + pViewSel->VsIndBox;
              j = pViewSelEnd->VsBox->BxFirstChar + pViewSelEnd->VsIndBox;
              if (editType != TEXT_SUP)
                {
                  if (pAb->AbPresentationBox && pAb->AbCreatorAttr)
                    {
                      /* update the selection within the attribute */
                      FirstSelectedCharInAttr = i;
                      LastSelectedCharInAttr = j;
                      SelPosition = (LastSelectedCharInAttr <= FirstSelectedCharInAttr);
                    }
                  NewContent (pAb);
                }
              if (pViewSel->VsBox)
                ChangeSelection (frame, pViewSel->VsBox->BxAbstractBox, i,
                               FALSE, TRUE, FALSE, FALSE);
              if (pAb->AbLeafType != LtPolyLine && j != i &&
                  pViewSelEnd->VsBox)
                ChangeSelection (frame,
                                 pViewSelEnd->VsBox->BxAbstractBox, j,
                                 TRUE, FALSE, FALSE, FALSE);
            }
          if (textPasted)
            /* send event TteElemTextModify.Post */
            APPtextModify (pAb->AbElement, frame, FALSE);
          else if (graphEdit)
            APPgraphicModify (pAb->AbElement,pAb->AbPolyLineShape, frame,
                              FALSE, open);
        }
    }
  return selNext;
}


/*----------------------------------------------------------------------
  Insere un caractere dans une boite de texte.                    
  Return TRUE if a Cut command was applied and it moved the selection
  to a next element.
  ----------------------------------------------------------------------*/
ThotBool InsertChar (int frame, CHAR_T c, int keyboard)
{
  PtrTextBuffer       pBuffer;
  PtrAbstractBox      pAb, pBlock;
  PtrBox              pBox, pSelBox, box;
  ViewSelection      *pViewSel;
  ViewSelection      *pViewSelEnd;
  ViewFrame          *pFrame;
  SpecFont            font;
  LeafType            nat;
  Propagation         savePropagate;
  int                 xx, xDelta, adjust;
  int                 spacesDelta;
  int                 topY, bottomY;
  int                 charsDelta, pix;
  int                 visib, zoom;
  int                 ind;
  int                 previousChars, previousInd, previousPos;
  char                script, oldscript;
  ThotBool            beginOfBox, toDelete;
  ThotBool            toSplit, toSplitForScript = FALSE;
  ThotBool            saveinsert, rtl, insert_nbsp;
  ThotBool            notification = FALSE;
  ThotBool            status, selprev, selNext = FALSE;

  toDelete = (c == 127);
  script  = ' ';
  /* Selon la valeur du parametre keyboard on essaie d'inserer */
  if (keyboard == 0)
    nat = LtSymbol;
  else if (keyboard == 1)
    nat = LtGraphics;
  else
    nat = LtText;
  /* recupere la selection active */
  SetInsert (&pAb, &frame, nat, toDelete);
  pBlock = NULL;
  /* Ou se trouve la marque d'insertion ? */
  if (frame > 0)
    {
      pFrame = &ViewFrameTable[frame - 1];
      pViewSel = &pFrame->FrSelectionBegin;
      pViewSelEnd = &pFrame->FrSelectionEnd;
      
      if (pAb == NULL && nat != LtText)
        return selNext;

      if (pAb == NULL)
        {
          /* detruit dans l'element precedent ou fusionne les elements */
          if (pViewSel->VsBox != 0)
            {
              pAb = pViewSel->VsBox->BxAbstractBox;
              CloseTextInsertion ();
              DeleteNextChar (frame, pAb->AbElement, TRUE);
              pFrame->FrReady = TRUE;
            }
        }
      else
        {
          /* Si la boite n'est pas visible */
          if (pAb->AbVisibility < pFrame->FrVisibility)
            {
              /* change la visibilite de la fenetre avant d'inserer */
              GetFrameParams (frame, &visib, &zoom);
              SetFrameParams (frame, pAb->AbVisibility, zoom);
              InsertChar (frame, c, keyboard);
              return selNext;
            }

          switch (pAb->AbLeafType)
            {
            case LtText:
              /* prend la boite d'script courant ou au besoin */
              /* cree un nouveau texte avec le bon script */
              if (!toDelete)
                notification = GiveAbsBoxForLanguage (frame, &pAb,
                                                      keyboard);
              else
                script = TtaGetCharacterScript (c);
              if (notification)
                /* selection could be modified by the application */
                InsertChar (frame, c, keyboard);
              else
                {
                  /* Look for the insert point */
                  GiveInsertPoint (pAb, script, frame, &pSelBox, &pBuffer,
                                   &ind, &xx, &previousChars);
                  /* keep in mind previous information about the insert point */
                  previousPos = pViewSel->VsXPos;
		  
                  /* width of the old split box */
                  if (pAb->AbUnicodeBidi == 'O')
                    rtl = (pAb->AbDirection == 'R');
                  else
                    rtl = (pSelBox->BxScript == 'A' || pSelBox->BxScript == 'H');
                  if (rtl)
                    previousPos = - previousPos + pSelBox->BxW;
                  previousInd = ind;
                  if (pAb)
                    {
                      /* keyboard ni Symbol ni Graphique */
                      /* bloque l'affichage de la fenetre */
                      pFrame->FrReady = FALSE;
		      
                      /* initialise l'insertion */
                      if (!TextInserting)
                        StartTextInsertion (pAb, frame, pSelBox,
                                            pBuffer, ind,
                                            previousChars);
                      font = pSelBox->BxFont;
		      
                      if (pBuffer == NULL)
                        return selNext;
                      /* the selection should be at the end of a buffer */
                      if (ind < pBuffer->BuLength && pBuffer->BuPrevious)
                        {
                          pBuffer = pBuffer->BuPrevious;
                          ind = pBuffer->BuLength;
                          previousInd = ind;
                        }

                      /* prepare the clipping area */
                      DefBoxRegion (frame, pSelBox, xx, xx, -1, -1);

                      /* Est-on au debut d'une boite entiere ou coupee ? */
                      pBox = pAb->AbBox->BxNexChild;
                      if ((pBox == NULL || pSelBox == pBox) &&
                          previousChars == 0)
                        beginOfBox = TRUE;
                      else
                        beginOfBox = FALSE;
		  
                      if (toDelete)
                        {
                          /* ========================== Delete */
                          if (beginOfBox)
                            {
                              /* no removable character here */
                              CloseTextInsertion ();
                              DeleteNextChar (frame, pAb->AbElement, TRUE);
                              pFrame->FrReady = TRUE;
                              return selNext;
                            }
                          else
                            {
                              if (pBuffer->BuLength == 0)
                                {
                                  if (pBuffer->BuPrevious)
                                    {
                                      /* if pBuffer = first buffer of the box? */
                                      if (pSelBox->BxBuffer == pBuffer)
                                        {
                                          /* free the current buffer */
                                          pBuffer = DeleteBuffer (pBuffer, frame);
                                          pSelBox->BxBuffer = pBuffer;
                                          if (pSelBox->BxIndChar == 0)
                                            {
                                              /* update the piece of box */
                                              pBox->BxBuffer = pBuffer;
                                              pAb->AbText = pBuffer;
                                              /* Is there an empty box before? */
                                              if (pBox->BxNexChild != pSelBox &&
                                                  pBox->BxNexChild)
                                                pBox->BxNexChild->BxBuffer = pBuffer;
                                            }
                                          else if (pSelBox->BxPrevious->BxNChars == 0)
                                            /* update the previous box */
                                            pSelBox->BxPrevious->BxBuffer = pBuffer;
                                        }
                                      else
                                        /* free the buffer */
                                        pBuffer = DeleteBuffer (pBuffer, frame);
                                    }
                                  else if (pBuffer->BuNext)
                                    {
                                      /* pBuffer = first buffer of the box */
                                      /* update the box */
                                      pSelBox->BxBuffer = pBuffer->BuNext;
                                      /* free the buffer */
                                      pBuffer = DeleteBuffer (pBuffer, frame);
                                      pBuffer = pSelBox->BxBuffer;
                                      if (pSelBox->BxFirstChar == 1)
                                        {
                                          pAb->AbText = pBuffer;
                                          if (pBox && pBox != pSelBox)
                                            {
                                              pBox->BxBuffer = pBuffer;
                                              /* Is there an empty box before? */
                                              if (pBox->BxNexChild != pSelBox &&
                                                  pBox->BxNexChild)
                                                pBox->BxNexChild->BxBuffer = pBuffer;
                                            }
                                        }
                                      else if (pSelBox->BxPrevious->BxNChars == 0)
                                        /* update the previous box */
                                        pSelBox->BxPrevious->BxBuffer = pBuffer;
                                    }
                                }
                              /* remove the character in the buffer */
                              pBuffer->BuLength--;
                              c = pBuffer->BuContent[pBuffer->BuLength];
                              pBuffer->BuContent[pBuffer->BuLength] = EOS;
			    
                              /* update the selection at the end of the buffer */
                              if (pViewSel->VsBuffer == pBuffer)
                                {
                                  pViewSel->VsIndBuf--;
                                  ind--;
                                  pViewSelEnd->VsIndBuf--;
                                }
                              if (pBuffer->BuLength == 0)
                                if (pBuffer->BuPrevious)
                                  {
                                    /* free that buffer */
                                    if (pSelBox->BxBuffer == pBuffer)
                                      {
                                        /* and update the box */
                                        pBuffer = DeleteBuffer (pBuffer, frame);
                                        pSelBox->BxBuffer = pBuffer;
                                        /* the index will be decremented */
                                        pSelBox->BxIndChar = pBuffer->BuLength + 1;
                                        if (pSelBox->BxFirstChar == 1)
                                          {
                                            pAb->AbText = pBuffer;
                                            if (pBox && pBox != pSelBox)
                                              {
                                                /* update the split box */
                                                pBox->BxBuffer = pBuffer;
                                                if (pBox->BxNexChild != pSelBox &&
                                                    pBox->BxNexChild)
                                                  /* there is an empty box before */
                                                  pBox->BxNexChild->BxBuffer = pBuffer;
                                              }
                                          }
                                        else if (pSelBox->BxPrevious->BxNChars == 0)
                                          /* update the previous box */
                                          pSelBox->BxPrevious->BxBuffer = pBuffer;
                                      }
                                    else
                                      pBuffer = DeleteBuffer (pBuffer, frame);
                                  }
			    
                              if (c == SPACE && pBuffer && pBuffer->BuLength)
                                {
                                  // A space is deleted
                                  TtaGetEnvBoolean ("INSERT_NBSP", &insert_nbsp);
                                  if (insert_nbsp &&
                                      pBuffer->BuContent[pBuffer->BuLength-1] == NBSP)
                                    {
                                      pBuffer->BuContent[pBuffer->BuLength-1] = SPACE;
                                      c = NBSP;
                                    }
                                }
                              /* Now remove the character */
                              charsDelta = -1;
                              pix = 0;
                              adjust = 0;
                              if (c == SPACE)
                                spacesDelta = -1;
                              else
                                spacesDelta = 0;
                              toSplit = FALSE;
			    
                              if (previousChars == 1 &&
                                  pSelBox->BxType == BoComplete &&
                                  pSelBox->BxNChars == 1)
                                {
                                  /* the box becomes empty */
                                  if ((pAb->AbNext || pAb->AbPrevious) &&
                                      !strcmp (pAb->AbPSchema->PsStructName, "TextFile"))
                                    {
                                      selprev = (pAb->AbPrevious != NULL);
                                       /* remove the current element if it's not
                                         the last element in the line*/
                                      FirstSelectedChar = 1;
                                      NewContent (pAb);
                                      selNext = CutCommand (FALSE, FALSE);
                                      TextInserting = FALSE;
                                      /* move the selection at the end of the
                                         previous element */
                                      if (FirstSelectedElement &&
                                          FirstSelectedChar <= FirstSelectedElement->ElVolume)
                                        {
                                          /* it doesn't point at the end of the
                                             previous text */
                                          if (selprev)
                                            TtcPreviousChar (FrameTable[frame].FrDoc,
                                                           FrameTable[frame].FrView);
                                          else if (!selNext)
                                            TtcNextChar (FrameTable[frame].FrDoc,
                                                         FrameTable[frame].FrView);
                                        }
                                      return FALSE/*selNext*/;
                                    }
                                  /* update selection marks */
                                  xDelta = BoxCharacterWidth (109, font);
                                  pViewSel->VsXPos = 0;
                                  pViewSel->VsIndBox = 0;
                                  pViewSel->VsNSpaces = 0;
                                  pViewSelEnd->VsXPos = xDelta;
                                  pViewSelEnd->VsIndBox = 0;
                                  pViewSelEnd->VsNSpaces = 0;
                                  /* prepare the box update */
                                  xDelta -= pSelBox->BxWidth;
                                  xx = 0;
                                }
                              else if (previousChars == 0 && c != SPACE)
                                {
                                  /* delete a split word or a Ctrl Return */
                                  /* recompute the paragraph */
                                  toSplit = TRUE;
                                  /* move the selection mark to the previous box */
                                  pSelBox = pSelBox->BxPrevious;

                                  if ((c == BREAK_LINE || c == NEW_LINE) &&
                                      pAb->AbBox->BxNChars == 1)
                                    {
                                      /* the box becomes empty */
                                      xDelta = BoxCharacterWidth (109, font);
                                      xx = 0;

                                      /* update selection marks */
                                      pSelBox = pAb->AbBox;
                                      pViewSel->VsXPos = 0;
                                      pViewSel->VsIndBox = 0;
                                      if (pViewSel->VsLine)
                                        pViewSel->VsLine = pViewSel->VsLine->LiPrevious;
                                      pViewSelEnd->VsBox = pSelBox;
                                      pViewSelEnd->VsLine = pViewSel->VsLine;
                                      pViewSelEnd->VsXPos = xDelta;
                                      pViewSelEnd->VsIndBox = 0;
                                      pViewSel->VsBox = pSelBox;
                                    }
                                  else
                                    {
                                      xDelta = - BoxCharacterWidth (c, font);
                                      pViewSel->VsBox = pSelBox;
                                      pViewSel->VsIndBox = pSelBox->BxNChars;
                                      if (pViewSel->VsLine)
                                        pViewSel->VsLine = pViewSel->VsLine->LiPrevious;
                                      pViewSelEnd->VsBox = pSelBox;
                                      pViewSelEnd->VsIndBox = pViewSel->VsIndBox;
                                      pViewSelEnd->VsLine = pViewSel->VsLine;
                                      xx += xDelta;
                                    }
                                  /* update the redisplayed area */
                                  DefBoxRegion (frame, pSelBox, xx, xx, -1, -1);
                                }
                              else if ((previousChars > pSelBox->BxNChars ||
                                        previousChars == 0) &&
                                       c == SPACE)
                                {
                                  /* removing a space between two boxes */
                                  /* recompute the paragraph */
                                  toSplit = TRUE;
                                  xDelta = - BoxCharacterWidth (c, font);
                                  if (previousChars == 0)
                                    {
                                      /* selection at the beginning of the box  */
                                      /* recompute from the previous box */
                                      pBox = pSelBox->BxPrevious;
                                      if (pViewSel->VsLine)
                                        pViewSel->VsLine = pViewSel->VsLine->LiPrevious;
                                      if (pBox->BxNChars == 0 &&
                                          pBox->BxFirstChar == 1)
                                        {
                                          /* the empty previous box is the first */
                                          pBox = pAb->AbBox;
                                          /*
                                            update the first position of the selected
                                            box because a space is removed before
                                          */
                                          pSelBox->BxFirstChar--;
                                          if (pBox->BxNChars == 1)
                                            /* the box becomes empty */
                                            xDelta = BoxCharacterWidth (109, font) - pBox->BxWidth;
                                        }
                                      else if (pBox->BxFirstChar == 1)
                                        {
                                          /* recompute the whole split box */
                                          pBox = pAb->AbBox;
                                          /*
                                            update the first position of the selected
                                            box because a space is removed before
                                          */
                                          pSelBox->BxFirstChar--;
                                        }
                                      pSelBox = pBox;
                                    }
                                  else
                                    {
                                      pViewSel->VsIndBox--;
                                      pViewSelEnd->VsIndBox--;
                                    }
                                  /* update the displayed area */
                                  xx += xDelta;
                                  DefBoxRegion (frame, pSelBox, xx, xx, -1, -1);
                                }
                              else
                                {
                                  /* other cases */
                                  if (c == SPACE)
                                    {
                                      xDelta = - BoxCharacterWidth (SPACE, font);
                                      adjust = - pSelBox->BxSpaceWidth;
                                      if (adjust < 0)
                                        {
                                          if (pSelBox->BxNPixels >= pViewSel->VsNSpaces)
                                            pix = -1;
                                        }
                                    }
                                  else if (c == EOS)
                                    /* null character */
                                    xDelta = 0;
                                  else
                                    xDelta = - BoxCharacterWidth (c, font);
                                  /* update the displayed area */
                                  xx += xDelta;
                                  DefBoxRegion (frame, pSelBox, xx, xx, -1, -1);
                                  /* update selection marks */
                                  if (adjust)
                                    UpdateViewSelMarks (frame, adjust + pix, spacesDelta,
                                                        charsDelta, rtl);
                                  else
                                    UpdateViewSelMarks (frame, xDelta, spacesDelta,
                                                        charsDelta, rtl);
                                }
                            }
                        }
                      else
                        {
                          /* Insert a new character */
                          charsDelta = 1;
                          pix = 0;
                          adjust = 0;
                          if (c == SPACE)
                            spacesDelta = 1;
                          else
                            spacesDelta = 0;
                          toSplit = FALSE;
                          toDelete = FALSE;
                          toSplitForScript = (pAb->AbUnicodeBidi != 'O' &&
                                              script != ' ' && script != 'D' &&
                                              pSelBox && pSelBox->BxScript != EOS &&
                                              pSelBox->BxScript != script);
			  
                          /* Si la selection debutait sur une boite de presentation */
                          /* il faut deplacer la selection sur le premier caractere */
                          /* de la boite de texte (ou en fin de boite vide)         */
                          if (pSelBox != pViewSel->VsBox)
                            {
                              pViewSel->VsBox = pSelBox;
                              pViewSel->VsBuffer = pBuffer;
                              pViewSel->VsIndBuf = ind;
                              pViewSel->VsIndBox = previousChars;
                              pViewSel->VsXPos = 0;
                              pViewSel->VsNSpaces = 0;
                            }
			  
                          /* ajoute le caractere dans la chaine des buffers */
                          if (pBuffer->BuLength == FULL_BUFFER)
                            pBuffer = GetNewBuffer (pBuffer, frame);
                          pBuffer->BuContent[pBuffer->BuLength] = c;
                          pBuffer->BuLength++;
                          pBuffer->BuContent[pBuffer->BuLength] = EOS;
                          if (pBuffer == pViewSel->VsBuffer)
                            {
                              /* Selection en fin de boite */
                              pViewSel->VsIndBuf++;
                              pViewSelEnd->VsIndBuf++;
                            }
			  
                          /* ==> La boite entiere n'est plus vide */
                          if (pSelBox->BxNChars == 0 &&
                              pSelBox->BxType == BoComplete)
                            {
                              /* Mise a jour des marques */
                              xDelta = BoxCharacterWidth (c, font);
                              pViewSel->VsXPos = xDelta;
                              pViewSel->VsIndBox = charsDelta;
                              pViewSel->VsNSpaces = spacesDelta;
                              pViewSelEnd->VsXPos = xDelta + 2;
                              pViewSelEnd->VsIndBox = charsDelta;
                              pViewSelEnd->VsNSpaces = spacesDelta;
                              /* Le caractere insere' est un Ctrl Return ? */
                              if (c == BREAK_LINE || c == NEW_LINE)
                                {
                                  /* il faut reevaluer la mise en ligne */
                                  toSplit = TRUE;
                                  xDelta = 0;
                                }

                              /* redisplay the whole box */
                              DefBoxRegion (frame, pSelBox, -1, -1, -1, -1);
			      
                              /* Prepare la mise a jour de la boite */
                              xDelta -= pSelBox->BxWidth;
                            }
                          /* ==> Insertion d'un caractere entre deux boites */
                          else if (previousChars > pSelBox->BxNChars ||
                                   /* ==> ou d'un blanc en fin de boite      */
                                   (c == SPACE &&
                                    (previousChars == pSelBox->BxNChars ||
                                     previousChars == 0)))
                            {
                              /* Prepare la mise a jour de la boite */
                              toSplit = TRUE;
                              xDelta = BoxCharacterWidth (c, font);
                              if (c == SPACE)
                                adjust = pSelBox->BxSpaceWidth;
                              if (previousChars == 0 && pSelBox->BxFirstChar == 1)
                                {
                                  /* Reevaluation of the whole split box */
                                  pSelBox = pAb->AbBox;
                                  UpdateViewSelMarks (frame, xDelta, spacesDelta,
                                                      charsDelta, rtl);
                                }
                              else if (previousChars == 0)
                                {
                                  /* Si la selection est en debut de boite  */
                                  /* on force la reevaluation du bloc de    */
                                  /* lignes a partir de la boite precedente */
                                  pSelBox = pSelBox->BxPrevious;
                                  if (pViewSel->VsLine != NULL)
                                    pViewSel->VsLine = pViewSel->VsLine->LiPrevious;
                                }
                              else
                                UpdateViewSelMarks (frame, xDelta, spacesDelta,
                                                    charsDelta, rtl);
			      
                            }
                          /* ==> Les autres cas d'insertion */
                          else
                            {
                              if (c == SPACE)
                                {
                                  xDelta = BoxCharacterWidth (SPACE, font);
                                  adjust = pSelBox->BxSpaceWidth;
                                  if (adjust > 0)
                                    if (pSelBox->BxNPixels > pViewSel->VsNSpaces)
                                      pix = 1;
                                }
                              else if (c == BREAK_LINE || c == NEW_LINE)
                                /* Ctrl Return */
                                {
                                  /* il faut reevaluer la mise en ligne */
                                  toSplit = TRUE;
                                  xDelta = BoxCharacterWidth (c, font);
                                }
                              else if (c == EOS)
                                /* Caractere Nul */
                                xDelta = 0;
                              else
                                xDelta = BoxCharacterWidth (c, font);

                              if (/*beginOfBox && */previousChars == 0)
                                {
                                  /* insert at the beginning of a box */
                                  pSelBox->BxBuffer = pBuffer;
                                  pSelBox->BxIndChar = ind;
                                  if (pSelBox->BxNChars == 0)
                                    /* the box is not empty now, get the right width */
                                    pSelBox->BxWidth = 0;
                                }
			      
                              /* Mise a jour de la selection dans la boite */
                              if (adjust)
                                UpdateViewSelMarks (frame, adjust + pix, spacesDelta,
                                                    charsDelta, rtl);
                              else
                                UpdateViewSelMarks (frame, xDelta, spacesDelta,
                                                    charsDelta, rtl);
                            }
                          xx += xDelta;
                        }
		      
                      /* Mise a jour de la boite */
                      if (IsLineBreakInside (pSelBox->BxBuffer, pSelBox->BxIndChar,
                                             pSelBox->BxNChars))
                        toSplit = TRUE;
                      /* avoid to redisplay the whole block of lines */
                      status = ReadyToDisplay;
                      /*ReadyToDisplay = FALSE;*/
                      if (pSelBox->BxNChars == 1)
                        /* remove the last character */
                        DefBoxRegion (frame, pSelBox, -1, -1, -1, -1);
                      else
                        DefBoxRegion (frame, pSelBox, xx, xx+2, -1, -1);
                      BoxUpdate (pSelBox, pViewSel->VsLine, charsDelta,
                                 spacesDelta, xDelta, adjust, 0, frame, toSplit);
                      ReadyToDisplay = status;
                      /* Mise a jour du volume du pave */
                      pAb->AbVolume += charsDelta;
                      /* check now if the script changes */
                      if  (toSplitForScript)
                        {
                          pBlock = SearchEnclosingType (pAb, BoBlock, BoFloatBlock);
                          oldscript = pSelBox->BxScript;
                          if (previousChars == 0)
                            {
                              box = pSelBox;
                              box->BxScript = script;
                            }
                          else
                            /* split before the new character */
                            box = SplitForScript (pSelBox, pAb, oldscript,
                                                  previousChars, /* char nb */
                                                  previousPos, pSelBox->BxH, /* w,h */
                                                  pViewSel->VsNSpaces, /* spaces */
                                                  previousInd, pBuffer,
                                                  frame);
                          if (box->BxNChars <= 1)
                            pBox = box;
                          /* split after the new character */
                          else
                            {
                              if (pBuffer->BuNext)
                                /* new character at the beginning of a buffer */
                                pBox = SplitForScript (box, pAb, script,
                                                       1, /* char lg */
                                                       xDelta, pSelBox->BxH, /* w,h */
                                                       0,  /* spaces */
                                                       0, pBuffer->BuNext, /* start */
                                                       frame);
                              else
                                /* new character at the beginning of a buffer */
                                pBox = SplitForScript (box, pAb, script,
                                                       1, /* char lg */
                                                       xDelta, pSelBox->BxH, /* w,h */
                                                       0, /* spaces */
                                                       previousInd + 1, pBuffer, /* start */
                                                       frame);
                              pBox->BxScript = oldscript;
                            }
                          /* update the selection position */
                          pViewSel->VsBox = box;
                          pViewSelEnd->VsBox = box;
                          if (script == 'A' || script == 'H')
                            /* reverse order */
                            pViewSel->VsXPos = 0;
                          else
                            pViewSel->VsXPos = xDelta;
                          pViewSelEnd->VsXPos = pViewSel->VsXPos + 2;
                          pViewSel->VsIndBox = previousInd + 1;
                          pViewSelEnd->VsIndBox = previousInd + 1;
                          pViewSel->VsBuffer = pBuffer;
                          pViewSelEnd->VsBuffer = pBuffer;
                          pViewSel->VsNSpaces = 0;
                          pViewSelEnd->VsNSpaces = 0;
                        }
		      
                      /* Check enclosing cell */
                      if (LastInsertCell || toSplitForScript)
                        {
                          /* we have to propage position to cell children */
                          savePropagate = Propagate;
                          Propagate = ToChildren;
                          if (!toSplitForScript)
                            pBlock = SearchEnclosingType (pAb, BoBlock, BoFloatBlock);
                          if (pBlock)
                            RecomputeLines (pBlock, NULL, NULL, frame);
                          if (LastInsertCell)
                            UpdateColumnWidth (LastInsertCell, NULL, frame);
                          /* restore propagate mode */
                          Propagate = savePropagate;
                        }

                      /* Traitement des englobements retardes */
                      ComputeEnclosing (frame);
                      /* evite le traitement de la fin d'insertion */
                      saveinsert = TextInserting;
                      TextInserting = FALSE;
		      
                      /* teste si l'on peut optimiser le reaffichage */
                      if (IsScrolled (frame, 0))
                        {
                          if (!toDelete)
                            {
                              /* largeur du rectangle d'affichage */
                              charsDelta = pFrame->FrClipXEnd - pFrame->FrClipXBegin;
                              /* largeur du caractere ajoute/detruit */
                              if (xDelta < 0)
                                xDelta = -xDelta;
                            }
                          if (pSelBox)
                            {
                              topY = pSelBox->BxYOrg;
                              bottomY = topY + pSelBox->BxHeight;
                              DefClip (frame, pFrame->FrClipXBegin, topY,
                                       pFrame->FrClipXEnd + 2, bottomY);
                            }
                          RedrawFrameBottom (frame, 0, NULL);
                        }
		      
                      /* restaure l'indicateur d'insertion */
                      TextInserting = saveinsert;
                      /* Affiche la nouvelle selection */
                      pFrame->FrReady = TRUE;
                    }
                }
              break;
              /* Saisie d'un caractere de symbole ou graphique */
            case LtSymbol:
              if (keyboard == 3)
                /* From Greek palette (Adobe Symbol font) */
                /* convert the character into its Thot symbol equivalent */
                {
                  switch ((int) c)
                    {
                    case 40:  c = '('; break; /* ( */
                    case 41:  c = ')'; break; /* ) */
                    case 45:  c = 'h'; break; /* - horizontal bar */
                    case 60:  c = '<'; break; /* pointy bracket */
                    case 62:  c = '>'; break; /* pointy bracket */
                    case 80:  c = 'P'; break; /* Pi */
                    case 83:  c = 'S'; break; /* Sigma */
                    case 91:  c = '['; break; /* [ */
                    case 93:  c = ']'; break; /* ] */
                    case 95:  c = 'h'; break; /* _ horizontal bar */
                    case 123: c = '{'; break; /* { */
                    case 124: c = '|'; break; /* | */
                    case 125: c = '}'; break; /* } */
                    case 172: c = 'L'; break; /* Left arrow */
                    case 173: c = '^'; break; /* Top arrow */
                    case 174: c = 'R'; break; /* Right arrow */
                    case 175: c = 'V'; break; /* bottom arrow */
                    case 189: c = '|'; break; /* | */
                    case 190: c = 'h'; break; /* - horizontal bar */
                    case 199: c = 'I'; break; /* Inter */
                    case 200: c = 'U'; break; /* Union */
                    case 213: c = 'P'; break; /* Pi */
                    case 214: c = 'r'; break; /* Root */
                    case 225: c = '<'; break; /* pointy bracket */
                    case 229: c = 'S'; break; /* Sigma */
                    case 241: c = '>'; break; /* pointy bracket */
                    case 242: c = 'i'; break; /* Integral */
                    default:  c = ' '; break;
                    }
                  keyboard = -1;   /* simulate keyboard input */
                }
              if (keyboard == -1 || keyboard == 0)
                /* saisie au clavier ou par la palette Math symbols */
                {
                  NewInsert = TRUE;
                  ContentEditing ((int) c);
                  NewInsert = FALSE;
                }
              break;
            case LtGraphics:
            case LtPolyLine:
              if (keyboard == 1)
                {
                  NewInsert = TRUE;
                  ContentEditing ((int) c);
                  NewInsert = FALSE;
                }
              break;
            case LtPicture:
              {
                NewInsert = TRUE;
                ContentEditing ((int) c);
                NewInsert = FALSE;
              }
              break;
            default:
              break;
            }
          SetDocumentModified (LoadedDocument[FrameTable[frame].FrDoc - 1], TRUE, 1); 
        }
    }
  return selNext;
}

/*----------------------------------------------------------------------
  PasteXCliboard reads nbytes from the buffer and calls Paste_X as
  many times as necessary with the characters read.     
  ----------------------------------------------------------------------*/
void PasteXClipboard (unsigned char *src, int nbytes, CHARSET charset)
{
  PtrTextBuffer       clipboard;
  PtrAbstractBox      pAb;
  PtrDocument         pDoc;
  PtrElement          pEl;
  DisplayMode         dispMode;
  Document            doc;
  CHAR_T             *buffer, b;
  int                 i, j;
  int                 frame, lg;
  ThotBool            lock = TRUE;

#ifdef _GTK
  if (src == NULL)
    {
      ClipboardToPaste = FALSE;
      return;
    }
  if (ClipboardToPaste)
    ClipboardToPaste = FALSE;
  else
    return;
#endif /* _GTK */

  /* check the current selection */
  if (!GetCurrentSelection (&pDoc, &pEl, &pEl, &i, &i))
    /* cannot insert */
    return;
  frame = ActiveFrame;
  SetInsert (&pAb, &frame, LtText, FALSE);
  if (pAb == NULL)
    /* invalid selection */
    return;
  /* clean up the X clipboard */
  clipboard = &XClipboard;
  ClearClipboard (clipboard);
  /* number of characters in the last buffer of the clipboard X */
  j = 0;
  /* number of characters in the whole X clipboard */
  lg = 0;
  if (src)
    {
      /* What is the encoding used by external applications ??? */
      buffer = TtaConvertByteToCHAR (src, charset);
      nbytes = ustrlen (buffer);
      doc = IdentDocument (pDoc);
      dispMode = TtaGetDisplayMode (doc);
      if (dispMode == DisplayImmediately)
        TtaSetDisplayMode (doc, DeferredDisplay);
      /* lock tables formatting */
      TtaGiveTableFormattingLock (&lock);
      if (!lock)
        /* table formatting is not loked, lock it now */
        TtaLockTableFormatting ();

      i = 0;
      while (i < nbytes)
        {
          if (j == FULL_BUFFER)
            {
              /* Allocate a new buffer */
              clipboard->BuLength = j;
              clipboard = GetNewBuffer (clipboard, ActiveFrame);
              j = 0;
            }
	  
          b = buffer[i];
          if (b == 8 || b == 12 || b == 160)
            /* BS, FF, nbsp becomes a space */
            clipboard->BuContent[j++] = SPACE;
          else if (b == EOL)
            {
              clipboard->BuContent[j++] = b;
              /* should we generate a break-line ???? */
            }
          else if (b >= 32)
            clipboard->BuContent[j++] = b;
          i++;
        }
      TtaFreeMemory (buffer);

      /* Paste the last X clipboard buffer */
      if (j > 0)
        {
          clipboard->BuLength = j;
          ContentEditing (TEXT_X_PASTE);
        }
      if (!lock)
        /* unlock table formatting */
        TtaUnlockTableFormatting ();
      if (dispMode == DisplayImmediately)
        TtaSetDisplayMode (doc, dispMode);
    }
}

#ifdef _WINGUI
/*----------------------------------------------------------------------
  PasteXClipboardW reads nchars from the buffer and calls Paste_X as
  many times as necessary with the characters read.     
  ----------------------------------------------------------------------*/
/* MJD: Not sure we need double functions here (PasteXClipboard and PasteXClipboardW);
   better to use only one (PasteXClipboard, with signature of current
   PasteXClipboardW). */
static void PasteXClipboardW (wchar_t* src, int nchars)
{
  PtrTextBuffer       clipboard;
  PtrAbstractBox      pAb;
  PtrDocument         pDoc;
  PtrElement          pEl;
  DisplayMode         dispMode;
  Document            doc;
  CHAR_T             *buffer, b;
  int                 i, j;
  int                 frame, lg;
  ThotBool            lock = TRUE;

  /* check the current selection */
  if (!GetCurrentSelection (&pDoc, &pEl, &pEl, &i, &i))
    /* cannot insert */
    return;
  frame = ActiveFrame;
  SetInsert (&pAb, &frame, LtText, FALSE);
  if (pAb == NULL)
    /* invalid selection */
    return;
  /* clean up the X clipboard */
  clipboard = &XClipboard;
  ClearClipboard (clipboard);
  /* number of characters in the last buffer of the clipboard X */
  j = 0;
  /* number of characters in the whole X clipboard */
  lg = 0;
  if (src)
    {
      buffer = src;
      doc = IdentDocument (pDoc);
      dispMode = TtaGetDisplayMode (doc);
      if (dispMode == DisplayImmediately)
        TtaSetDisplayMode (doc, DeferredDisplay);
      /* lock tables formatting */
      TtaGiveTableFormattingLock (&lock);
      if (!lock)
        /* table formatting is not loked, lock it now */
        TtaLockTableFormatting ();

      i = 0;
      while (i < nchars)
        {
          if (j == FULL_BUFFER)
            {
              /* Allocate a new buffer */
              clipboard->BuLength = j;
              clipboard = GetNewBuffer (clipboard, ActiveFrame);
              j = 0;
            }
	  
          b = buffer[i++];
          if (b == 8 || b == 12 || b == 160)
            /* BS, FF, nbsp becomes a space */
            clipboard->BuContent[j++] = SPACE;
          else if (b == EOL)
            {
              clipboard->BuContent[j++] = b;
              /* should we generate a break-line ???? */
            }
          else if (b >= 32)
            clipboard->BuContent[j++] = b;
        }

      /* Paste the last X clipboard buffer */
      if (j > 0)
        {
          clipboard->BuLength = j;
          ContentEditing (TEXT_X_PASTE);
        }
      if (!lock)
        /* unlock table formatting */
        TtaUnlockTableFormatting ();
      if (dispMode == DisplayImmediately)
        TtaSetDisplayMode (doc, dispMode);
    }
}
#endif /* _WINGUI */

/*----------------------------------------------------------------------
  TtcInsertChar insert a character
  ----------------------------------------------------------------------*/
void TtcInsertChar (Document doc, View view, CHAR_T c)
{
  ViewSelection      *pViewSel;
  DisplayMode         dispMode;
  PtrDocument         pDoc;
  PtrElement          firstEl, lastEl;
  int                 firstChar, lastChar;
  int                 frame;
  ThotBool            lock;

  if (doc != 0)
    {
      /* start the undo sequence */
      GetCurrentSelection (&pDoc, &firstEl, &lastEl, &firstChar, &lastChar);
      if (pDoc && pDoc->DocReadOnly)
        {
          //TtaDisplaySimpleMessage (CONFIRM, LIB, TMSG_EL_RO);
          return;
        }
      lock = TRUE;
      /* Check if we are changing the active frame */
      frame = GetWindowNumber (doc, view);
      if (frame != ActiveFrame)
        {
          /* yes close the previous insertion */
          CloseTextInsertion ();
          if (ActiveFrame > 0 && FrameTable[ActiveFrame].FrDoc != doc)
            return;
          else
            /* use the right frame */
            ActiveFrame = frame;
        }
      pViewSel = &ViewFrameTable[frame - 1].FrSelectionBegin;
      if (pViewSel->VsBox &&
          pViewSel->VsBox->BxAbstractBox &&
          pViewSel->VsBox->BxAbstractBox->AbReadOnly)
        {
          if (pViewSel->VsBox->BxAbstractBox->AbEnclosing->AbReadOnly)
            /* cannot insert here */
            return;
          else if (pViewSel->VsIndBox + pViewSel->VsBox->BxFirstChar > 0 &&
                   pViewSel->VsIndBox + pViewSel->VsBox->BxFirstChar < pViewSel->VsBox->BxAbstractBox->AbVolume)
            /* cannot insert here */
            return;
        }

      if (pDoc && pViewSel->VsBox)
        {
          /* avoid to redisplay step by step */
          dispMode = TtaGetDisplayMode (doc);
          if (dispMode == DisplayImmediately)
            TtaSetDisplayMode (doc, DeferredDisplay);
          if (!pDoc->DocEditSequence)
            /* there is no history sequence open yet. Open a new sequence. */
            {
              /* the history sequence will be closed at the end of the
                 insertion */
              if (AbsBoxSelectedAttr &&
                  FirstSelectedCharInAttr < LastSelectedCharInAttr)
                OpenHistorySequence (pDoc, firstEl, lastEl,
                                     AbsBoxSelectedAttr->AbCreatorAttr,
                                     FirstSelectedCharInAttr,
                                     LastSelectedCharInAttr);
              else
                OpenHistorySequence (pDoc, firstEl, lastEl, NULL, firstChar,
                                     lastChar);
            }
          /* lock tables formatting */
          TtaGiveTableFormattingLock (&lock);
          if (!lock)
            /* table formatting is not loked, lock it now */
            TtaLockTableFormatting ();

          /* in principle, the entered character should replace the current
             selection, but... */
          if (!StructSelectionMode &&
              !ViewFrameTable[frame - 1].FrSelectOnePosition &&
              (firstEl != lastEl ||
               !TypeHasException (ExcNoCut, firstEl->ElTypeNumber,
                                  firstEl->ElStructSchema) ||
               !TypeHasException (ExcIsBreak, firstEl->ElTypeNumber,
                                  firstEl->ElStructSchema)))
            /* delete the current selection */
            ContentEditing (TEXT_SUP);

          InsertChar (frame, c, -1);
          if (!lock)
            /* unlock table formatting */
            TtaUnlockTableFormatting ();

          /* just manage differed enclosing rules */
          ComputeEnclosing (frame);
          if (dispMode == DisplayImmediately)
            TtaSetDisplayMode (doc, dispMode);
        }

      // check if a CloseTextInsertion should be generated
      while (firstEl)
        {
          if (TypeHasException (ExcCheckAllChars, firstEl->ElTypeNumber, firstEl->ElStructSchema))
            {
              CloseTextInsertion ();
              firstEl = NULL;
            }
          else
            firstEl = firstEl->ElParent;
        }
    }
}

/*----------------------------------------------------------------------
  TtcCutSelection                                                    
  ----------------------------------------------------------------------*/
void TtcCutSelection (Document doc, View view)
{
  DisplayMode         dispMode;
  int                 frame;
  ThotBool            lock = TRUE;
#ifdef _WINGUI
  HANDLE              hMem   = 0;
  LPTSTR              lpData = 0;
  char               *ptrData;
  LPTSTR              pBuff;
  int                 ndx;
#endif /* _WINGUI */

  if (doc == 0)
    return;
  else if (TtaGetDocumentAccessMode(doc) == 0)
    {
      TtaDisplaySimpleMessage (CONFIRM, LIB, TMSG_EL_RO);
      return;
    }
  /* avoid to redisplay step by step */
  dispMode = TtaGetDisplayMode (doc);
  if (dispMode == DisplayImmediately)
    TtaSetDisplayMode (doc, DeferredDisplay);
  /* lock tables formatting */
  TtaGiveTableFormattingLock (&lock);
  if (!lock)
    /* table formatting is not loked, lock it now */
    TtaLockTableFormatting ();

  frame = GetWindowNumber (doc, view);
  if (frame != ActiveFrame)
    {
      /* yes close the previous insertion */
      CloseTextInsertion ();
      if (ActiveFrame > 0 && FrameTable[ActiveFrame].FrDoc != doc)
        return;
      else
        /* use the right frame */
        ActiveFrame = frame;
    }

  // set a structured copy
  DoCopyToClipboard (doc, view, TRUE, FALSE);
#ifdef _WINGUI
  if (!OpenClipboard (FrRef[frame]))
    WinErrorBox (FrRef [frame], "TtcCutSelection (1)");
  else
    {
      EmptyClipboard ();
      hMem   = GlobalAlloc (GHND, ClipboardLength + 1);
      lpData = (LPTSTR) GlobalLock (hMem);
      ptrData = lpData;
      pBuff  = (LPTSTR) Xbuffer;
      for (ndx = 0; ndx < ClipboardLength; ndx++)
        *ptrData++ = *pBuff++;
      *ptrData = 0;
       
      GlobalUnlock (hMem);
      SetClipboardData (CF_TEXT, hMem);
      /* add Unicode clipboard here (CF_UNICODETEXT) */
      CloseClipboard ();
    }
#endif /* _WINGUI */
  ContentEditing (TEXT_CUT);

  if (!lock)
    /* unlock table formatting */
    TtaUnlockTableFormatting ();
  /* just manage differed enclosing rules */
  ComputeEnclosing (frame);
  if (dispMode == DisplayImmediately)
    TtaSetDisplayMode (doc, dispMode);
}

/*----------------------------------------------------------------------
  TtcDeletePreviousChar                                           
  ----------------------------------------------------------------------*/
void TtcDeletePreviousChar (Document doc, View view)
{
  ViewSelection      *pViewSel;
  DisplayMode         dispMode;
  PtrDocument         pDoc;
  PtrElement          firstEl, lastEl;
  int                 frame;
  int                 firstChar, lastChar;
  ThotBool            delPrev, moveAfter, nextSelected;
  ThotBool            lock = TRUE;

  if (doc != 0)
    {
      if (TtaGetDocumentAccessMode(doc) == 0)
        {
          //TtaDisplaySimpleMessage (CONFIRM, LIB, TMSG_EL_RO);
          return;
        }
      frame = GetWindowNumber (doc, view);
      if (frame != ActiveFrame)
        {
          /* yes close the previous insertion */
          CloseTextInsertion ();
          if (ActiveFrame > 0 && FrameTable[ActiveFrame].FrDoc != doc)
            return;
          else
            /* use the right frame */
            ActiveFrame = frame;
          /**** work in the right document
                frame = ActiveFrame;
                doc =  FrameTable[ActiveFrame].FrDoc; ****/
        }
      delPrev = (StructSelectionMode ||
                 ViewFrameTable[frame - 1].FrSelectOnePosition);
      GetCurrentSelection (&pDoc, &firstEl, &lastEl, &firstChar,&lastChar);
      if (pDoc == NULL)
        return;
      if (!delPrev)
        {
          if (firstEl == lastEl &&
              TypeHasException (ExcIsBreak, firstEl->ElTypeNumber,
                                firstEl->ElStructSchema))
            /* a <br/> element is selected. Don't delete it, but delete the
               previous character */
            delPrev = TRUE;
        }
      pViewSel = &ViewFrameTable[frame - 1].FrSelectionBegin;
      if (delPrev)
        /* remove the current empty element even if there is an insertion
           point */
        delPrev = (firstEl->ElStructSchema &&
                   !strcmp (firstEl->ElStructSchema->SsName, "TextFile")) ||
                  (pViewSel->VsBox &&
                   pViewSel->VsBox->BxAbstractBox->AbVolume != 0);
      else
        /* remove the previous char if the selection is at the end of the
           text */
        delPrev = (pViewSel->VsBox &&
                   pViewSel->VsBox->BxAbstractBox->AbLeafType == LtText &&
                   pViewSel->VsIndBox >= pViewSel->VsBox->BxNChars);

      /* avoid to redisplay step by step */
      dispMode = TtaGetDisplayMode (doc);
      nextSelected = FALSE;
      if (dispMode == DisplayImmediately)
        TtaSetDisplayMode (doc, DeferredDisplay);
      /* lock tables formatting */
      TtaGiveTableFormattingLock (&lock);
      if (!lock)
        /* table formatting is not loked, lock it now */
        TtaLockTableFormatting ();
      
      if (delPrev)
        {
          if (pViewSel->VsBox &&
              pViewSel->VsBox->BxAbstractBox &&
              (!pViewSel->VsBox->BxAbstractBox->AbReadOnly ||
               pViewSel->VsBox->BxFirstChar + pViewSel->VsIndBox == 1))
            if (!pViewSel->VsBox->BxAbstractBox->AbPresentationBox ||
                pViewSel->VsBox->BxFirstChar + pViewSel->VsIndBox > 1)
              {
              nextSelected = InsertChar (frame, 127, -1);
              // if the selected was moved to the next character
              if (nextSelected &&
                  pViewSel->VsBox &&
                  (pViewSel->VsIndBox < pViewSel->VsBox->BxNChars ||
                   pViewSel->VsBox->BxNChars == 0))
                TtcPreviousChar (doc, view);
              }
        }
      else
        {
          /* delete the current selection instead of the previous char */
          CloseTextInsertion ();
          /* by default doesn't change the selection after the delete */
          moveAfter = FALSE;
          if (pViewSel->VsBox)
            {
              // Move after if the element will be removed and there is
              // a next element
              moveAfter = (pViewSel->VsBox->BxAbstractBox->AbLeafType != LtText ||
                           pViewSel->VsBox->BxAbstractBox->AbVolume == 0);
              nextSelected = ContentEditing (TEXT_DEL);
            }
          pViewSel = &ViewFrameTable[frame - 1].FrSelectionEnd;
          if (moveAfter && nextSelected &&
              pViewSel->VsBox &&
              (pViewSel->VsIndBox < pViewSel->VsBox->BxNChars ||
               pViewSel->VsBox->BxNChars == 0))
            TtcPreviousChar (doc, view);
          if (pDoc->DocEditSequence)
            /* close the new open undo sequence */
            CloseHistorySequence (pDoc);
        }
      
      if (!lock)
        /* unlock table formatting */
        TtaUnlockTableFormatting ();
      /* just manage differed enclosing rules */
      ComputeEnclosing (frame);

      if (dispMode == DisplayImmediately)
        TtaSetDisplayMode (doc, dispMode);
    }
}

/*----------------------------------------------------------------------
  TtcDeleteSelection                                                 
  ----------------------------------------------------------------------*/
void TtcDeleteSelection (Document doc, View view)
{
  DisplayMode         dispMode;
  int                 frame;
  ThotBool            lock = TRUE;

  if (doc == 0)
    return;
  else if (TtaGetDocumentAccessMode(doc) == 0)
    {
      TtaDisplaySimpleMessage (CONFIRM, LIB, TMSG_EL_RO);
      return;
    }
  /* avoid to redisplay step by step */
  dispMode = TtaGetDisplayMode (doc);
  if (dispMode == DisplayImmediately)
    TtaSetDisplayMode (doc, DeferredDisplay);
  /* lock tables formatting */
  TtaGiveTableFormattingLock (&lock);
  if (!lock)
    /* table formatting is not loked, lock it now */
    TtaLockTableFormatting ();
   
  ContentEditing (TEXT_DEL);
   
  if (!lock)
    /* unlock table formatting */
    TtaUnlockTableFormatting ();
  /* just manage differed enclosing rules */
  frame = GetWindowNumber (doc, view);
  ComputeEnclosing (frame);

  if (dispMode == DisplayImmediately)
    TtaSetDisplayMode (doc, dispMode);
}


/*----------------------------------------------------------------------
  TtcInclude
  ----------------------------------------------------------------------*/
void TtcInclude (Document doc, View view)
{
  DisplayMode         dispMode;
  int                 frame;
  ThotBool            lock = TRUE;
  ThotBool            ok;

  if (ThotLocalActions[T_insertpaste] != NULL && doc != 0)
    {
      if (TtaGetDocumentAccessMode(doc) == 0)
        {
          TtaDisplaySimpleMessage (CONFIRM, LIB, TMSG_EL_RO);
          return;
        }
      /* avoid to redisplay step by step */
      dispMode = TtaGetDisplayMode (doc);
      if (dispMode == DisplayImmediately)
        TtaSetDisplayMode (doc, DeferredDisplay);
      /* lock tables formatting */
      TtaGiveTableFormattingLock (&lock);
      if (!lock)
        /* table formatting is not loked, lock it now */
        TtaLockTableFormatting ();
      (*(Proc4)ThotLocalActions[T_insertpaste]) (
                                                 (void *)FALSE,
                                                 (void *)FALSE,
                                                 (void *)'L',
                                                 (void *)&ok);

      if (!lock)
        /* unlock table formatting */
        TtaUnlockTableFormatting ();
      /* just manage differed enclosing rules */
      frame = GetWindowNumber (doc, view);
      ComputeEnclosing (frame);

      if (dispMode == DisplayImmediately)
        TtaSetDisplayMode (doc, dispMode);
    }
}

/*----------------------------------------------------------------------
  TtcPasteFormBuffer pastes at the current insert position the content
  of the buffer.
  ----------------------------------------------------------------------*/
void TtaPasteFromBuffer (unsigned char *src, int length, CHARSET charset)
{
  PasteXClipboard (src, length, charset);
}

/*----------------------------------------------------------------------
  TtcPasteFromClipboard
  ----------------------------------------------------------------------*/
void TtcPasteFromClipboard (Document doc, View view)
{
#ifdef _WX 
    wxTheClipboard->UsePrimarySelection(true);
  if (!wxTheClipboard->Open())
    {
      TTALOGDEBUG_0( TTA_LOG_CLIPBOARD, _T("Can't open clipboard.") );
      return;
    }
  else
    {
      wxTextDataObject data;
      if (wxTheClipboard->GetData( data ))
        {
          wxString text = data.GetText();
          TTALOGDEBUG_0( TTA_LOG_CLIPBOARD, _T("Text pasted from the clipboard : ") + text );
	      
          int len = strlen((const char *)text.mb_str(wxConvUTF8));
          int i = ClipboardLength;
          if (i < len)
            i = len;
          char *tmp = (char*)TtaGetMemory ((len + 1) * sizeof(char));
          strcpy ((char *)tmp, (const char *)text.mb_str(wxConvUTF8));
          if (Xbuffer == NULL || len != ClipboardLength ||
              strncmp ((const char *)Xbuffer, tmp, i))
            {
              TtcClearClipboard ();
              PasteXClipboard ((unsigned char *)tmp, len, UTF_8);
            }
          else
            PasteXClipboard (Xbuffer, ClipboardLength, UTF_8);
          TtaFreeMemory (tmp);
        }
      else
        TTALOGDEBUG_0( TTA_LOG_CLIPBOARD, _T("Error getting data from the clipboard.") );

      wxTheClipboard->Close();
      TTALOGDEBUG_0( TTA_LOG_CLIPBOARD, _T("Closed the clipboard.\n") );
    }
#endif /* _WX */
#ifdef _GTK
  DisplayMode         dispMode;
  int                 frame;

  if (doc == 0)
    return;
  frame = GetWindowNumber (doc, view);
  if (frame != ActiveFrame)
    {
      if (ActiveFrame > 0 && FrameTable[ActiveFrame].FrDoc != doc)
        return;
      else
        {
          CloseTextInsertion ();
          /* use the right frame */
          ActiveFrame = frame;
        }
    }
  else
    /* close previous changes without notification */
    CloseTextInsertionWithControl (FALSE);

  /* avoid to redisplay step by step */
  dispMode = TtaGetDisplayMode (doc);
  if (dispMode == DisplayImmediately)
    TtaSetDisplayMode (doc, DeferredDisplay);
  ClipboardToPaste = TRUE;
   
  /* just manage differed enclosing rules */
  ComputeEnclosing (frame);
  if (dispMode == DisplayImmediately)
    TtaSetDisplayMode (doc, dispMode);   
#endif /* _GTK */
}


/*----------------------------------------------------------------------
  TtcInsert                                                          
  ----------------------------------------------------------------------*/
void TtcInsert (Document doc, View view)
{
  ContentEditing (TEXT_INSERT);
}


/*----------------------------------------------------------------------
  TtcCopySelection
  ----------------------------------------------------------------------*/
void TtcCopySelection (Document doc, View view)
{
  int                frame;
#ifdef _WINGUI
  HANDLE             hMem   = 0;
  char              *lpData = NULL;
  char              *pBuff;
  HWND               activeWnd;
#endif /* _WINGUI */

  if (doc == 0)
    return;
  frame = GetWindowNumber (doc, view);
  if (frame != ActiveFrame)
    {
      if (ActiveFrame > 0 && FrameTable[ActiveFrame].FrDoc != doc)
        return;
      else
        /* use the right frame */
        ActiveFrame = frame;
    }
  if (SelPosition)
    return;
#ifdef _WINGUI
  activeWnd = GetFocus ();
  if (activeWnd == FrRef [frame])
    {
      DoCopyToClipboard (doc, view, TRUE, FALSE);
      if (OpenClipboard (FrRef[frame]))
        {
          EmptyClipboard ();
          /* if the clipboard buffer is empty, don't copy anything into it */
          if (Xbuffer)
            {
              hMem   = GlobalAlloc (GHND, ClipboardLength + 1);
              lpData = GlobalLock (hMem);
              pBuff  = Xbuffer;
              lstrcpy (lpData, Xbuffer);
              GlobalUnlock (hMem);
              if (!SetClipboardData (CF_TEXT, hMem))
                WinErrorBox (NULL, "");
              CloseClipboard ();
            }
        } 
    }
#else /* _WINGUI */
  DoCopyToClipboard (doc, view, TRUE, FALSE);
#endif /* _WINGUI */
  ContentEditing (TEXT_COPY);
}


/*----------------------------------------------------------------------
  TtcPaste
  ----------------------------------------------------------------------*/
void TtcPaste (Document doc, View view)
{
  DisplayMode         dispMode;
#ifdef _WINGUI
  HANDLE              hMem;
  char               *lpData;
  int                 lpDatalength;
#endif /* _WINGUI */
  PtrDocument         pDoc;
  PtrElement          firstEl, lastEl;
  int                 firstChar, lastChar;
  int                 frame;
  ThotBool            lock = TRUE;

  if (doc > 0)
    {
      if (TtaGetDocumentAccessMode(doc) == 0)
        {
          TtaDisplaySimpleMessage (CONFIRM, LIB, TMSG_EL_RO);
          return;
        }
      frame = GetWindowNumber (doc, view);
      if (frame != ActiveFrame)
        {
          if (ActiveFrame > 0 && FrameTable[ActiveFrame].FrDoc != doc)
            return;
          else
            {
              CloseTextInsertion ();
              /* use the right frame */
              ActiveFrame = frame;
            }
        }
      else
        /* close insertion without notification */
        CloseTextInsertionWithControl (FALSE);

      /* start the undo sequence */
      GetCurrentSelection (&pDoc, &firstEl, &lastEl, &firstChar, &lastChar);
      if (pDoc)
        {
          if (pDoc->DocEditSequence)
            /* close the previous history sequence */
            CloseTextInsertionWithControl (FALSE);
          /* avoid to redisplay step by step */
          dispMode = TtaGetDisplayMode (doc);
          if (dispMode == DisplayImmediately)
            TtaSetDisplayMode (doc, DeferredDisplay);

          /* start the undo sequence */
          OpenHistorySequence (pDoc, firstEl, lastEl, NULL, firstChar, lastChar);
          /* lock tables formatting */
          TtaGiveTableFormattingLock (&lock);
          if (!lock)
            /* table formatting is not loked, lock it now */
            TtaLockTableFormatting ();
	  
          /* in principle, the paste should replace the current
             selection, but... */
          if (!StructSelectionMode &&
              !ViewFrameTable[frame - 1].FrSelectOnePosition &&
              (firstEl != lastEl ||
               !TypeHasException (ExcIsBreak, firstEl->ElTypeNumber,
                                  firstEl->ElStructSchema)))
            /* delete the current selection */
            ContentEditing (TEXT_SUP);
#ifdef _WINGUI
          OpenClipboard (FrRef [frame]);
          /* check if the clipboard comes from Amaya */
          if (hMem = GetClipboardData (CF_UNICODETEXT))
            {
              wchar_t* lpData = (wchar_t*) GlobalLock (hMem);
              char *dest;
              lpDatalength = wcslen (lpData);
              /* dest = TtaConvertWCToByte (lpData, UTF_8); */
              dest = TtaConvertWCToByte (lpData, TtaGetDefaultCharset ());
              if (Xbuffer == NULL || dest == NULL || strncmp (Xbuffer, dest, 100))
                PasteXClipboardW (lpData, lpDatalength);
              else 
                ContentEditing (TEXT_PASTE);
              TtaFreeMemory (dest);
              GlobalUnlock (hMem);
            }
          else if (hMem = GetClipboardData (CF_TEXT))
            {
              lpData = GlobalLock (hMem);
              lpDatalength = strlen (lpData);	      
              if (Xbuffer == NULL || strcmp (Xbuffer, lpData)) /****/
                PasteXClipboard (lpData, lpDatalength, TtaGetDefaultCharset ());
              else 
                ContentEditing (TEXT_PASTE);
              GlobalUnlock (hMem);
            }
          else 
            ContentEditing (TEXT_PASTE);
          CloseClipboard ();
#endif /* _WINGUI */

#ifdef _WX
          wxTheClipboard->UsePrimarySelection(false);
          if (wxTheClipboard->Open())
            {
                  wxTextDataObject data;
                  if (wxTheClipboard->GetData( data ))
                    {
                      wxString text = data.GetText();
                      TTALOGDEBUG_0( TTA_LOG_CLIPBOARD, _T("Text pasted from the clipboard : ") + text );
	      
                      int len = strlen((const char *)text.mb_str(wxConvUTF8));
                      int i = ClipboardLength;
                      if (len==0)
                      {
                         ContentEditing (TEXT_PASTE);
                      }
		      else
                      {
                        if (i < len)
                          i = len;
                        char *tmp = (char*)TtaGetMemory ((len + 1) * sizeof(char));
                        strcpy ((char *)tmp, (const char *)text.mb_str(wxConvUTF8));
                        if (Xbuffer == NULL || strncmp ((const char *)Xbuffer, tmp, i))
                          {
                            TtcClearClipboard ();
                            PasteXClipboard((unsigned char *)tmp, len, UTF_8);
                          }
                        else if (ClipboardURI)
                          PasteXClipboard(Xbuffer, ClipboardLength, UTF_8);
                        else
                          ContentEditing (TEXT_PASTE);
                        TtaFreeMemory (tmp);
                      }
                    }
                  else
                    {
                      TTALOGDEBUG_0( TTA_LOG_CLIPBOARD, _T("Error getting data from the clipboard."));
                      ContentEditing (TEXT_PASTE);
                    }
              wxTheClipboard->Close();
              TTALOGDEBUG_0( TTA_LOG_CLIPBOARD, _T("Clipboard closed."));
            }
          else
            {
              TTALOGDEBUG_0( TTA_LOG_CLIPBOARD, _T("Can't open clipboard.") );
              ContentEditing (TEXT_PASTE);
            }
#endif /* _WX */
#ifdef _GTK
          if (FirstSelectedElement == NULL && FirstSavedElement)
            {
              /* TODO: paste only the text */
            }
          else
            ContentEditing (TEXT_PASTE);
#endif /*  _GTK*/
    
          if (!lock)
            /* unlock table formatting */
            TtaUnlockTableFormatting ();
          /* just manage differed enclosing rules */
          ComputeEnclosing (frame);

          /* close the undo sequence */
          CloseHistorySequence (pDoc);
          if (dispMode == DisplayImmediately)
            TtaSetDisplayMode (doc, dispMode);
        }
    }
}

/*---------------------------------------------------------------------
  EditingLoadResources connecte les fonctions d'edition              
  ----------------------------------------------------------------------*/
void EditingLoadResources ()
{
  if (ThotLocalActions[T_clearhistory] == NULL)
    {
      /* Connecte les actions d'edition */
      TteConnectAction (T_clearhistory, (Proc) ClearHistory);
      TteConnectAction (T_attraddhistory, (Proc) AddAttrEditOpInHistory);
      MenuActionList[0].Call_Action = (Proc) TtcInsertChar;
      MenuActionList[CMD_DeletePrevChar].Call_Action = (Proc) TtcDeletePreviousChar;
      MenuActionList[CMD_DeleteSelection].Call_Action = (Proc) TtcDeleteSelection;

      MenuActionList[CMD_PasteFromClipboard].Call_Action = (Proc) TtcPasteFromClipboard;
      LastInsertCell = NULL;
      LastInsertParagraph = NULL;
      LastInsertElText = NULL;
      LastInsertAttr = NULL;
      LastInsertAttrElem = NULL;
      NewInsert = FALSE;
    }
}
