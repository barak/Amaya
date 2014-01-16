/*
 *
 *  (c) COPYRIGHT INRIA, Grif, 1996.
 *  Please first read the full copyright statement in file COPYRIGHT.
 *
 */

/*
 * Warning:
 * This module is part of the Thot library, which was originally
 * developed in French. That's why some comments are still in
 * French, but their translation is in progress and the full module
 * will be available in English in the next release.
 * 
 */
 
/*
 * gestion des regles de presentation de l'image abstraite.
 * Ce module applique les regles de presentation aux paves.     
 *
 * Author: V. Quint (INRIA)
 *
 */

#include "thot_sys.h"

#include "constmedia.h"
#include "typemedia.h"
#include "fileaccess.h"
#include "picture.h"
#include "appdialogue.h"

#define THOT_EXPORT extern
#include "platform_tv.h"
#include "appdialogue_tv.h"

#include "tree_f.h"
#include "structcreation_f.h"
#include "createabsbox_f.h"
#include "createpages_f.h"
#include "appdialogue_f.h"
#include "viewcommands_f.h"
#include "exceptions_f.h"
#include "fileaccess_f.h"
#include "absboxes_f.h"
#include "abspictures_f.h"
#include "buildboxes_f.h"
#include "memory_f.h"
#include "structmodif_f.h"
#include "changeabsbox_f.h"
#include "boxpositions_f.h"
#include "presrules_f.h"
#include "references_f.h"
#include "schemas_f.h"
#include "boxselection_f.h"
#include "content_f.h"
#include "presvariables_f.h"
#include "font_f.h"
#include "units_f.h"

/*----------------------------------------------------------------------
   	AttrValue retourne la valeur que prend l'attribut numerique	
   		pointe' par pAttr.					
  ----------------------------------------------------------------------*/
#ifdef __STDC__
int                 AttrValue (PtrAttribute pAttr)
#else  /* __STDC__ */
int                 AttrValue (pAttr)
PtrAttribute        pAttr;

#endif /* __STDC__ */
{
   int                 ret;


   ret = 0;
   if (pAttr != NULL)
     {
	if (pAttr->AeAttrType == AtNumAttr)
	   ret = pAttr->AeAttrValue;
     }
   return ret;
}


/*----------------------------------------------------------------------
   	FollowNotPres Si pAbb pointe un pave de presentation, retourne	
   		dans pAbb le premier pave qui n'est pas un pave de	
   		presentation et qui suit le pave pAbb a l'appel.		
   		Retourne NULL si le pave n'est suivi que de paves de	
   		presentation. Si, a l'appel, pAbb est  un pave qui n'est	
   		pas un pave de presentation, alors pAbb reste inchange'.	
  ----------------------------------------------------------------------*/
#ifdef __STDC__
static void         FollowNotPres (PtrAbstractBox * pAbb)
#else  /* __STDC__ */
static void         FollowNotPres (pAbb)
PtrAbstractBox     *pAbb;

#endif /* __STDC__ */
{
   boolean             stop;


   stop = FALSE;
   do
      if (*pAbb == NULL)
	 stop = TRUE;
      else if (!(*pAbb)->AbPresentationBox)
	 stop = TRUE;
      else
	 *pAbb = (*pAbb)->AbNext;
   while (!stop);
}


/*----------------------------------------------------------------------
   	AncestorAbsBox	  rend le premier element pElAsc ascendant de pE
   			  et qui possede un pave dans la vue view
   			  retourne ce pave dans pAbb ou NULL sinon
  ----------------------------------------------------------------------*/
#ifdef __STDC__
static void         AncestorAbsBox (PtrElement pE, DocViewNumber view, PtrAbstractBox * pAbb, PtrElement * pElAsc)
#else  /* __STDC__ */
static void         AncestorAbsBox (pE, view, pAbb, pElAsc)
PtrElement          pE;
DocViewNumber       view;
PtrAbstractBox     *pAbb;
PtrElement         *pElAsc;

#endif /* __STDC__ */
{

   *pElAsc = pE;
   *pAbb = NULL;
   if ((*pElAsc)->ElParent == NULL)
      *pAbb = NULL;
   else
      while ((*pElAsc)->ElParent != NULL && *pAbb == NULL)
	{
	   *pElAsc = (*pElAsc)->ElParent;
	   *pAbb = (*pElAsc)->ElAbstractBox[view - 1];
	   if (*pAbb != NULL)
	      if ((*pAbb)->AbDead)
		 *pAbb = NULL;
	}
}



/*----------------------------------------------------------------------
   	AbsBoxInherit  rend le pointeur sur le pave correpondant a l'element	
   	qui sert de reference quand on applique la regle d'heritage	
   	pointe par pPRule a l'element pointe par pEl, dans la vue view.	
  ----------------------------------------------------------------------*/

#ifdef __STDC__
static PtrAbstractBox AbsBoxInherit (PtrPRule pPRule, PtrElement pEl, DocViewNumber view)

#else  /* __STDC__ */
static PtrAbstractBox AbsBoxInherit (pPRule, pEl, view)
PtrPRule            pPRule;
PtrElement          pEl;
DocViewNumber       view;

#endif /* __STDC__ */

{
   PtrElement          pElInherit;
   PtrAbstractBox      pAbb;

   pAbb = NULL;
   pElInherit = pEl;
   if (pEl != NULL)
      switch (pPRule->PrInheritMode)
	    {
	       case InheritParent:
		  AncestorAbsBox (pEl, view, &pAbb, &pElInherit);
		  break;
	       case InheritGrandFather:
		  AncestorAbsBox (pEl, view, &pAbb, &pElInherit);
		  if (pAbb != NULL)
		    {
		       pElInherit = pAbb->AbElement;
		       pAbb = NULL;
		       AncestorAbsBox (pElInherit, view, &pAbb, &pElInherit);
		    }
		  break;
	       case InheritPrevious:
		  while (pElInherit->ElPrevious != NULL && pAbb == NULL)
		    {
		       pElInherit = pElInherit->ElPrevious;
		       pAbb = pElInherit->ElAbstractBox[view - 1];
		       FollowNotPres (&pAbb);	/* saute les paves de presentation */
		       if (pAbb != NULL)
			  if (pAbb->AbDead)
			     pAbb = NULL;
		    }
		  if (pAbb == NULL)
		     AncestorAbsBox (pEl, view, &pAbb, &pElInherit);
		  break;
	       case InheritChild:
		  while (!pElInherit->ElTerminal && pElInherit->ElFirstChild != NULL && pAbb == NULL)
		    {
		       pElInherit = pElInherit->ElFirstChild;
		       pAbb = pElInherit->ElAbstractBox[view - 1];
		       FollowNotPres (&pAbb);	/* saute les paves de presentation */
		       if (pAbb != NULL)
			  if (pAbb->AbDead)
			     pAbb = NULL;
		    }
		  break;
	       case InheritCreator:
		  pAbb = pEl->ElAbstractBox[view - 1];
		  if (pAbb != NULL)
		    {
		       FollowNotPres (&pAbb);	/* saute les paves de presentation */
		       if (pAbb != NULL)
			  if (pAbb->AbDead)
			     pAbb = NULL;
		    }
		  break;
	    }

   FollowNotPres (&pAbb);	/* saute les paves de presentation */
   return pAbb;
}


/*----------------------------------------------------------------------
   	AbsBoxInheritImm  rend le pointeur sur le pave correspondant a	
   		l'element qui sert de reference quand on applique la	
   		regle d'heritage pointe par pPRule a l'element pointe	
   		par pEl, dans la vue view. On ne considere que l'element	
   		immediatement voisin (pere, frere, fils).		
  ----------------------------------------------------------------------*/

#ifdef __STDC__
static PtrAbstractBox AbsBoxInheritImm (PtrPRule pPRule, PtrElement pEl, DocViewNumber view)

#else  /* __STDC__ */
static PtrAbstractBox AbsBoxInheritImm (pPRule, pEl, view)
PtrPRule            pPRule;
PtrElement          pEl;
DocViewNumber       view;

#endif /* __STDC__ */

{
   PtrAbstractBox      pAbb;

   pAbb = NULL;
   if (pEl != NULL)
      switch (pPRule->PrInheritMode)
	    {
	       case InheritParent:
		  if (pEl->ElParent != NULL)
		     pAbb = pEl->ElParent->ElAbstractBox[view - 1];
		  break;
	       case InheritGrandFather:
		  if (pEl->ElParent != NULL)
		     if (pEl->ElParent->ElParent != NULL)
			pAbb = pEl->ElParent->ElParent->ElAbstractBox[view - 1];
		  break;
	       case InheritPrevious:
		  if (pEl->ElPrevious != NULL)
		     pAbb = pEl->ElPrevious->ElAbstractBox[view - 1];
		  if (pAbb == NULL)
		     if (pEl->ElParent != NULL)
			pAbb = pEl->ElParent->ElAbstractBox[view - 1];
		  break;
	       case InheritChild:
		  if (!pEl->ElTerminal)
		     if (pEl->ElFirstChild != NULL)
			pAbb = pEl->ElFirstChild->ElAbstractBox[view - 1];
		  break;
	       case InheritCreator:
		  pAbb = pEl->ElAbstractBox[view - 1];
		  if (pAbb != NULL)
		    {
		       FollowNotPres (&pAbb);	/* saute les paves de presentation */
		       if (pAbb->AbDead)
			  pAbb = NULL;
		    }
		  break;
	    }

   FollowNotPres (&pAbb);
   if (pAbb != NULL)
      if (pAbb->AbDead)
	 pAbb = NULL;
   return pAbb;
}



/*----------------------------------------------------------------------
   	CharRule evalue une regle de presentation de type caractere	
   		pour la vue view. La regle a evaluer est pointee par	
   		pPRule, et l'element auquel elle s'applique est pointe	
   		par pEl. Au result, ok indique si l'evaluation a pu	
   		etre faite. 						
  ----------------------------------------------------------------------*/

#ifdef __STDC__
static char         CharRule (PtrPRule pPRule, PtrElement pEl, DocViewNumber view, boolean * ok)

#else  /* __STDC__ */
static char         CharRule (pPRule, pEl, view, ok)
PtrPRule            pPRule;
PtrElement          pEl;
DocViewNumber       view;
boolean            *ok;

#endif /* __STDC__ */

{
   PtrAbstractBox      pAbb;
   char                val;
   PtrAbstractBox      pAbba1;

   val = ' ';
   *ok = TRUE;
   if (pPRule != NULL && pEl != NULL)
     {
	switch (pPRule->PrPresMode)
	      {
		 case PresInherit:
		    pAbb = AbsBoxInherit (pPRule, pEl, view);
		    if (pAbb == NULL)
		       *ok = FALSE;
		    else
		      {
			 pAbba1 = pAbb;
			 switch (pPRule->PrType)
			       {
				  case PtFont:
				     val = pAbba1->AbFont;
				     break;
				  case PtStyle:
				     if (pAbba1->AbHighlight == 1)
					val = 'B';
				     else if (pAbba1->AbHighlight == 2)
					val = 'I';
				     else if (pAbba1->AbHighlight == 3)		/* O : oblique */
					val = 'O';
				     else if (pAbba1->AbHighlight == 4)		/* G : gras italique */
					val = 'G';
				     else if (pAbba1->AbHighlight == 5)		/* Q : gras oblique */
					val = 'Q';
				     else
					val = 'R';
				     break;
				  case PtUnderline:
				     if (pAbba1->AbUnderline == 1)
					val = 'U';
				     else if (pAbba1->AbUnderline == 2)
					val = 'O';
				     else if (pAbba1->AbUnderline == 3)
					val = 'C';
				     else
					val = 'N';
				     break;

				  case PtThickness:
				     if (pAbba1->AbThickness == 1)
					val = 'T';
				     else
					val = 'N';
				     break;
				  case PtLineStyle:
				     val = pAbba1->AbLineStyle;
				     break;
				  default:
				     break;
			       }

		      }
		    break;
		 case PresFunction:

		    break;
		 case PresImmediate:
		    val = pPRule->PrChrValue;
		    break;
	      }
     }
   return val;
}


/*----------------------------------------------------------------------
   	AlignRule evalue une regle d'ajustement pour la vue view.	
   		La regle a evaluer est pointee par pPRule, et l'element	
   		auquel elle s'applique est pointe par pEl.		
   		Au result, ok indique si l'evaluation a pu etre faite.	
  ----------------------------------------------------------------------*/

#ifdef __STDC__
static BAlignment   AlignRule (PtrPRule pPRule, PtrElement pEl, DocViewNumber view, boolean * ok)

#else  /* __STDC__ */
static BAlignment   AlignRule (pPRule, pEl, view, ok)
PtrPRule            pPRule;
PtrElement          pEl;
DocViewNumber       view;
boolean            *ok;

#endif /* __STDC__ */

{
   PtrAbstractBox      pAbb;
   BAlignment          val;

   val = AlignLeft;
   *ok = TRUE;
   if (pPRule != NULL && pEl != NULL)
     {
	switch (pPRule->PrPresMode)
	      {
		 case PresInherit:
		    pAbb = AbsBoxInherit (pPRule, pEl, view);
		    if (pAbb == NULL)
		       *ok = FALSE;
		    else if (pPRule->PrType == PtAdjust)
		       val = pAbb->AbAdjust;
		    break;
		 case PresFunction:
		    break;
		 case PresImmediate:
		    if (pPRule->PrType == PtAdjust)
		       val = pPRule->PrAdjust;
		    break;
	      }

     }
   return val;
}



/*----------------------------------------------------------------------
   	 BoolRule evalue une regle de presentation de type booleen	
   		pour la vue view. La regle a evaluer est pointee par	
   		pPRule, et l'element auquel elle s'applique est pointe	
   		par pEl.						
   		Au result, ok indique si l'evaluation a pu etre faite.	
  ----------------------------------------------------------------------*/

#ifdef __STDC__
static boolean      BoolRule (PtrPRule pPRule, PtrElement pEl, DocViewNumber view, boolean * ok)

#else  /* __STDC__ */
static boolean      BoolRule (pPRule, pEl, view, ok)
PtrPRule            pPRule;
PtrElement          pEl;
DocViewNumber       view;
boolean            *ok;

#endif /* __STDC__ */

{
   PtrAbstractBox      pAbb;
   boolean             val;

   val = FALSE;
   *ok = TRUE;
   if (pPRule != NULL && pEl != NULL)
     {
	switch (pPRule->PrPresMode)
	      {
		 case PresInherit:
		    pAbb = AbsBoxInherit (pPRule, pEl, view);
		    if (pAbb == NULL)
		       *ok = FALSE;
		    else if (pPRule->PrType == PtJustify)
		       val = pAbb->AbJustify;
		    else if (pPRule->PrType == PtHyphenate)
		       val = pAbb->AbHyphenate;
		    break;
		 case PresFunction:
		    break;
		 case PresImmediate:
		    if (pPRule->PrType == PtJustify ||
			pPRule->PrType == PtHyphenate ||
			pPRule->PrType == PtVertOverflow ||
			pPRule->PrType == PtHorizOverflow)
		       val = pPRule->PrJustify;
		    break;
	      }

     }
   return val;
}

/*----------------------------------------------------------------------
  GetEnclosingAttr
  return the attribute of type attrNumber associated to element pEl or
  one of its ancestors. Return NULL is neither pEl nor any of its ancestor
  have such an attribute.
  ----------------------------------------------------------------------*/
#ifdef __STDC__
static PtrAttribute GetEnclosingAttr (PtrElement pEl, int attrNumber)
#else  /* __STDC__ */
static PtrAttribute GetEnclosingAttr (pEl, attrNumber)
PtrElement	pEl;
int		attrNumber;

#endif /* __STDC__ */
{
   PtrAttribute        pAttr, pA;
   PtrElement	       pAsc;

   pAttr = NULL;
   pAsc = pEl;
   if (attrNumber < 0)
      attrNumber = -attrNumber;
   while (pAttr == NULL && pAsc != NULL)
      {
      pA = pAsc->ElFirstAttr;
      while (pAttr == NULL && pA != NULL)
	 if (pA->AeAttrNum == attrNumber &&
	     pA->AeAttrSSchema == pEl->ElStructSchema)
	    pAttr = pA;
	 else
	    pA = pA->AeNext;
      pAsc = pAsc->ElParent;
      }
   return pAttr;
}


/*----------------------------------------------------------------------
   	IntegerRule evalue une regle de presentation de type entier pour
   		la vue view. La regle a evaluer est pointee par pPRule,	
   		et l'element auquel elle s'applique est pointe par pEl.	
   		Au result, ok indique si l'evaluation a pu etre faite et
   		unit indique, dans le cas de regle PtIndent, PtBreak1,	
   		PtBreak2 ou PtSize, si la valeur est exprimee en	
   		points typo, en relatif (numero de corps si PtSize),	
   		etc. Si la regle est une regle de presentation		
   		d'attribut, pAttr pointe sur le bloc d'attribut auquel	
   		la regle correspond.					
   		Fonction utilisee dans crimabs				
  ----------------------------------------------------------------------*/
#ifdef __STDC__
int                 IntegerRule (PtrPRule pPRule, PtrElement pEl, DocViewNumber view, boolean * ok, TypeUnit * unit, PtrAttribute pAttr)
#else  /* __STDC__ */
int                 IntegerRule (pPRule, pEl, view, ok, unit, pAttr)
PtrPRule            pPRule;
PtrElement          pEl;
DocViewNumber       view;
boolean            *ok;
TypeUnit           *unit;
PtrAttribute        pAttr;

#endif /* __STDC__ */
{
   PtrAbstractBox      pAbb;
   int                 val, i;
   PtrElement          pElInherit;

   val = 0;
   *ok = TRUE;
   *unit = UnRelative;
   if (pPRule != NULL && pEl != NULL)
     {
	switch (pPRule->PrPresMode)
	      {
		 case PresInherit:
		    if (pPRule->PrType == PtVisibility)
		       pAbb = AbsBoxInheritImm (pPRule, pEl, view);
		    else
		       pAbb = AbsBoxInherit (pPRule, pEl, view);
		    if (pAbb == NULL)
		       *ok = FALSE;
		    else
		      {
			 if (pPRule->PrInhAttr)
			   {
			      /* c'est la valeur d'un attribut */
			      if (pAttr == NULL)
				 pAttr = GetEnclosingAttr (pEl, pPRule->PrInhDelta);
			      if (pPRule->PrInhDelta < 0)
				 /* il faut retrancher cette valeur */
				 i = -AttrValue (pAttr);
			      else
				 /* il faut ajouter cette valeur */
				 i = AttrValue (pAttr);
			      if (pPRule->PrInhUnit == UnRelative ||
				  pPRule->PrInhUnit == UnXHeight)
				 if (pPRule->PrType == PtIndent
				     || pPRule->PrType == PtLineSpacing
				     || pPRule->PrType == PtLineWeight)
				    /* convertit en 1/10 de caractere */
				    i = 10 * i;
			   }
			 else
			    /* c'est la valeur elle meme qui est dans la regle */
			    i = pPRule->PrInhDelta;

			 switch (pPRule->PrType)
			       {
				  case PtVisibility:
				     val = pAbb->AbVisibility + i;
				     break;
				  case PtSize:
				     val = pAbb->AbSize + i;
				     *unit = pAbb->AbSizeUnit;
				     if (*unit == UnRelative)
					if (val > MAX_LOG_SIZE)
					   val = MAX_LOG_SIZE;
					else if (val < 0)
					   val = 0;
				     break;
				  case PtIndent:
				     val = pAbb->AbIndent + i;
				     *unit = pAbb->AbIndentUnit;
				     break;
				  case PtLineSpacing:
				     val = pAbb->AbLineSpacing + i;
				     *unit = pAbb->AbLineSpacingUnit;
				     break;
				  case PtDepth:
				     val = pAbb->AbDepth + i;
				     break;
				  case PtFillPattern:
				     val = pAbb->AbFillPattern;
				     break;
				  case PtBackground:
				     val = pAbb->AbBackground;
				     break;
				  case PtForeground:
				     val = pAbb->AbForeground;
				     break;
				  case PtLineWeight:
				     val = pAbb->AbLineWeight + i;
				     if (val < 0)
					val = 0;
				     *unit = pAbb->AbLineWeightUnit;
				     break;
				  default:
				     break;
			       }

			 if (pPRule->PrInhMinOrMax != 0)
			    /* il y a un minimum ou un maximum a respecter */
			   {
			      if (pPRule->PrMinMaxAttr)
				 /* c'est la valeur d'un attribut */
				{
				   if (pAttr == NULL)
				      pAttr = GetEnclosingAttr (pEl, pPRule->PrInhMinOrMax);
				   if (pPRule->PrInhMinOrMax < 0)
				      /* inverser cette valeur */
				      i = -AttrValue (pAttr);
				   else
				      i = AttrValue (pAttr);
				   if (pPRule->PrInhUnit == UnRelative ||
				       pPRule->PrInhUnit == UnXHeight)
				      if (pPRule->PrType == PtIndent ||
					  pPRule->PrType == PtLineSpacing ||
					  pPRule->PrType == PtLineWeight)
					 /* convertit en 1/10 de caractere */
					 i = 10 * i;
				}
			      else
				 /* c'est la valeur elle meme qui est dans la regle */
				 i = pPRule->PrInhMinOrMax;
			      if (pPRule->PrInhDelta >= 0)
				 /* c'est un maximum */
				 /* dans les paves, les tailles relatives sont */
				 /* exprimees dans une echelle de valeurs entre 0 et */
				 /* n-1, alors que dans les regles de presentation */
				 /* l'echelle est entre 1 et n. */
				 if (pPRule->PrType == PtSize && pAbb->AbSizeUnit == UnRelative)
				   {
				      if (val > i - 1)
					 val = i - 1;
				   }
				 else
				   {
				      if (val > i)
					 val = i;
				   }
			      else
				 /* c'est un minimum */
				 /* dans les paves, les tailles relatives sont */
				 /* exprimees dans une echelle de valeurs entre 0 et */
				 /* n-1, alors que dans les regles de presentation */
				 /* l'echelle est entre 1 et n. */
			      if (pPRule->PrType == PtSize && pAbb->AbSizeUnit == UnRelative)
				{
				   if (val < i - 1)
				      val = i - 1;
				}
			      else if (val < i)
				 val = i;
			   }
		      }
		    break;
		 case PresFunction:
		    break;
		 case PresImmediate:
		    if (pPRule->PrType == PtVisibility
			|| pPRule->PrType == PtDepth
			|| pPRule->PrType == PtFillPattern
			|| pPRule->PrType == PtBackground
			|| pPRule->PrType == PtForeground)
		       if (pPRule->PrAttrValue)
			  /* c'est la valeur d'un attribut */
			  {
			  if (pAttr == NULL)
			     pAttr = GetEnclosingAttr (pEl, pPRule->PrIntValue);
			  if (pPRule->PrIntValue < 0)
			     /* il faut inverser cette valeur */
			     val = -AttrValue (pAttr);
			  else
			     val = AttrValue (pAttr);
			  }
		       else
			  /* c'est la valeur elle meme qui est dans la regle */
			  val = pPRule->PrIntValue;

		    else if (pPRule->PrType == PtBreak1
			     || pPRule->PrType == PtBreak2
			     || pPRule->PrType == PtIndent
			     || pPRule->PrType == PtSize
			     || pPRule->PrType == PtLineSpacing
			     || pPRule->PrType == PtLineWeight)
		      {
			 if (pPRule->PrMinAttr)
			    /* c'est la valeur d'un attribut */
			   {
			      if (pAttr == NULL)
				 pAttr = GetEnclosingAttr (pEl, pPRule->PrMinValue);
			      if (pPRule->PrMinValue < 0)
				 /* il faut inverser cette valeur */
				 val = -AttrValue (pAttr);
			      else
				 val = AttrValue (pAttr);
			      if (pPRule->PrMinUnit == UnRelative
				  || pPRule->PrMinUnit == UnXHeight)
				 if (pPRule->PrType != PtSize)
				    /* convertit en 1/10 de caractere */
				    val = val * 10;
			   }
			 else
			    /* c'est la valeur elle-meme qui est dans la regle */
			    val = pPRule->PrMinValue;
			 if (pPRule->PrMinUnit == UnPercent && pPRule->PrType != PtIndent)
			   {
			      if (pPRule->PrType == PtSize)
				{
				   AncestorAbsBox (pEl, view, &pAbb, &pElInherit);
				   if (pAbb == NULL)
				      *ok = FALSE;
				   else
				     {
					val = (pAbb->AbSize * val) / 100;
					*unit = pAbb->AbSizeUnit;
				     }
				}
			      else
				{
				   /* Relative a la police courante */
				   *unit = UnRelative;
				   val = val / 10;
				}
			   }
			 else
			   {
			      *unit = pPRule->PrMinUnit;
			      if (pPRule->PrType == PtSize && pPRule->PrMinUnit == UnRelative)
				 val--;
			   }
		      }

		    if (pPRule->PrType == PtSize && *unit == UnRelative)
		      {
			 if (val > MAX_LOG_SIZE)
			    val = MAX_LOG_SIZE;
			 else if (val < 0)
			    val = 0;
		      }
		    else if (pPRule->PrType == PtLineWeight && val < 0)
		       val = 0;
		    break;
		 default:
		    break;
	      }
     }
   return val;
}

/*----------------------------------------------------------------------
   VerifyAbsBox : Teste si le pave pAb a les caracteristiques
   	numAbType (type du pave) et refKind (pave de presentation
   	ou d'element) si notType est faux ou s'il n'a pas les
	caracteristiques numAbType et refKind si notType est vrai.
   	Cela permet de determiner le pave pAb par rapport	
   	auquel le pave en cours de traitement va se positionner
  ----------------------------------------------------------------------*/
#ifdef __STDC__
static void         VerifyAbsBox (boolean * found, PtrPSchema pSP, RefKind refKind, int numAbType, boolean notType, PtrAbstractBox pAb)

#else  /* __STDC__ */
static void         VerifyAbsBox (found, pSP, refKind, numAbType, notType, pAb)
boolean            *found;
PtrPSchema          pSP;
RefKind             refKind;
int                 numAbType;
boolean             notType;
PtrAbstractBox      pAb;

#endif /* __STDC__ */

{
   PtrAttribute	    pAttr;
   boolean	    attrFound;

   if (!pAb->AbDead)
      {
      pAttr = NULL;
      if (refKind == RkAttr && pAb->AbElement != NULL)
	if (!pAb->AbPresentationBox)
	  {
	  pAttr = pAb->AbElement->ElFirstAttr;
	  attrFound = FALSE;
	  while (pAttr != NULL && !attrFound)
             if (pAttr->AeAttrSSchema->SsCode == pSP->PsStructCode &&
		 pAttr->AeAttrNum == numAbType)
                attrFound = TRUE;
             else
                pAttr = pAttr->AeNext;
	  }
      if (notType)
	/* on accepte le pave s'il est de type different de numAbType */
	{
	   if (refKind == RkElType)
	     /* un pave d'un element de structure */
	     {
	     if (numAbType == MAX_PRES_VARIABLE + 1)
		{
		/* C'est une regle Not AnyElem, on accepte la premiere */
		/* boite de presentation trouvee */
		if (pAb->AbPresentationBox)
		   *found = TRUE;
		}
	     else
		/* c'est une regle Not Type */
		if (pAb->AbTypeNum != numAbType ||
		    pAb->AbPresentationBox ||
		    pAb->AbPSchema != pSP)
		   *found = TRUE;
	     }
	   else if (refKind == RkPresBox)
	     /* un pave d'une boite de pres. */
	     {
	     if (numAbType == MAX_PRES_BOX + 1)
		{
	        /* Cas d'une regle Not AnyBox, on accepte le premier */
	        /* element trouve' */
		if (!pAb->AbPresentationBox)
	           *found = TRUE;
		}
	     else
		/* c'est une regle Not Box */
		if (pAb->AbTypeNum != numAbType ||
		    !pAb->AbPresentationBox ||
		    pAb->AbPSchema != pSP)
		   *found = TRUE;
	     }
	   else if (refKind == RkAttr)
	     /* le pave d'un element portant un attribut */
	     {
	     if (pAttr == NULL)
		*found = TRUE;
	     }
	}
      else
	{
	   if (refKind == RkElType)
	     /* un pave d'un element de structure */
	     {
	     if (numAbType == MAX_PRES_VARIABLE + 1)
		{
		/* C'est une regle AnyElem, on accepte le premier element
		   trouve' */
		if (!pAb->AbPresentationBox)
		   *found = TRUE;
		}
	     else
		/* C'est une regle Type */
		if (pAb->AbTypeNum == numAbType &&
		    !pAb->AbPresentationBox &&
		    (pAb->AbPSchema == pSP || pSP == NULL))
		   *found = TRUE;
	     }
	   else if (refKind == RkPresBox)
	     /* un pave d'une boite de presentation */
	     {
	     if (numAbType == MAX_PRES_BOX + 1)
		{
	        /* C'est une regle AnyBox, on accepte la premiere boite de */
	        /* presentation trouvee */
		if (pAb->AbPresentationBox)
	           *found = TRUE;
		}
	     else
		/* C'est une regle Box */
		if (pAb->AbTypeNum == numAbType &&
		    pAb->AbPresentationBox &&
		    (pAb->AbPSchema == pSP || pSP == NULL))
		   *found = TRUE;
	     }
	   else if (refKind == RkAttr)
	     {
	     if (pAttr != NULL)
		*found = TRUE;
	     }
	}
   }
}

/*----------------------------------------------------------------------
   	AttrCreatePresBox	retourne Vrai si l'une des regles de	
   		presentation de l'attribut pointe' par pAttr cree le	
   		pave de presentation pointe' par pAb.			
  ----------------------------------------------------------------------*/

#ifdef __STDC__
static boolean      AttrCreatePresBox (PtrAttribute pAttr, PtrAbstractBox pAb)

#else  /* __STDC__ */
static boolean      AttrCreatePresBox (pAttr, pAb)
PtrAttribute        pAttr;
PtrAbstractBox      pAb;

#endif /* __STDC__ */

{
   boolean             ret, stop;
   PtrPRule            pPRule;
   PtrPSchema          pSchP;
   PtrHandlePSchema    pHd;

   ret = FALSE;
   if (pAb->AbPresentationBox)
     {
	/* on cherchera d'abord dans le schema de presentation principal de */
	/* l'attribut */
	pSchP = pAttr->AeAttrSSchema->SsPSchema;
	pHd = NULL;
	/* on examine le schema de presentation principal, puis les schemas */
	/* additionnels */
	while (pSchP != NULL && !ret)
	  {
	     /* cherche dans ce schema de presentation le debut de la chaine */
	     /* des regles de presentation de l'attribut */
	     pPRule = AttrPresRule (pAttr, pAb->AbElement, FALSE, NULL, pSchP);
	     /* saute les regles precedant les  fonctions */
	     stop = FALSE;
	     do
		if (pPRule == NULL)
		   stop = TRUE;
		else if (pPRule->PrType > PtFunction)
		  {
		     /* pas de fonction de presentation */
		     stop = TRUE;
		     pPRule = NULL;
		  }
		else if (pPRule->PrType == PtFunction)
		   stop = TRUE;
		else
		   pPRule = pPRule->PrNextPRule;
	     while (!stop);
	     /* cherche toutes les fonctions de creation */
	     stop = FALSE;
	     do
		if (pPRule == NULL)
		   /* fin de la chaine */
		   stop = TRUE;
		else if (pPRule->PrType != PtFunction)
		   /* fin des fonctions */
		   stop = TRUE;
		else
		   /* c'est une regle fonction */
		  {
		     if (pPRule->PrPresFunction == FnCreateBefore ||
			 pPRule->PrPresFunction == FnCreateWith ||
			 pPRule->PrPresFunction == FnCreateEnclosing ||
			 pPRule->PrPresFunction == FnCreateFirst ||
			 pPRule->PrPresFunction == FnCreateAfter ||
			 pPRule->PrPresFunction == FnCreateLast)
			/* c'est une regle de creation */
		       {
			  if (!pPRule->PrElement &&
			      pPRule->PrPresBox[0] == pAb->AbTypeNum &&
			      pPRule->PrNPresBoxes == 1 &&
			      pSchP == pAb->AbPSchema)
			     /* cette regle cree notre pave, on a found' */
			    {
			       stop = TRUE;
			       ret = TRUE;
			    }
		       }
		     if (!stop)
			/* passe a la regle suivante de la chaine */
			pPRule = pPRule->PrNextPRule;
		  }
	     while (!stop);
	     if (!ret)
		/* on n'a pas encore found'. On cherche dans les schemas de */
		/* presentation additionnels */
	       {
		  if (pHd == NULL)
		     /* on n'a pas encore traite' les schemas de presentation
		        additionnels. On prend le premier schema additionnel. */
		     pHd = pAttr->AeAttrSSchema->SsFirstPSchemaExtens;
		  else
		     /* passe au schema additionnel suivant */
		     pHd = pHd->HdNextPSchema;
		  if (pHd == NULL)
		     /* il n'y a pas (ou plus) de schemas additionnels */
		     pSchP = NULL;
		  else
		     pSchP = pHd->HdPSchema;
	       }
	  }
     }
   return ret;
}

/*----------------------------------------------------------------------
   	VerifyAbsBoxDescent : Teste si le pave pAb ou un de ses		
   		descendants a les caracteristiques			
   		numAbType (type du pave) et refKind (pave de presentation
   		ou d'element) si notType est faux ou s'il n'a pas les	
   		caracteristiques numAbType et refKind si notType est vrai.
   		Cela permet de determiner le pave pAb par rapport	
   		auquel le pave en cours de traitement va se positionner	
  ----------------------------------------------------------------------*/

#ifdef __STDC__
static void         VerifyAbsBoxDescent (boolean * found, PtrPSchema pSP, RefKind refKind, int numType, boolean notType, PtrAbstractBox pAb)

#else  /* __STDC__ */
static void         VerifyAbsBoxDescent (found, pSP, refKind, numType, notType, pAb)
boolean            *found;
PtrPSchema          pSP;
RefKind		    refKind;
int                 numType;
boolean             notType;
PtrAbstractBox      pAb;

#endif /* __STDC__ */

{
   VerifyAbsBox (found, pSP, refKind, numType, notType, pAb);
   if (!(*found))
      if (pAb->AbFirstEnclosed != NULL)
	{
	   pAb = pAb->AbFirstEnclosed;
	   do
	     {
		VerifyAbsBoxDescent (found, pSP, refKind, numType, notType, pAb);
		if (!(*found))
		   pAb = pAb->AbNext;
	     }
	   while (!(*found) && pAb != NULL);
	}
}


/*----------------------------------------------------------------------
   	SearchAbsBoxRef Si notType est faux, rend un pointeur sur le pave de	
   		type numAbType et de niveau level (relativement au pave	
   		pAbb). Si notType est vrai, rend un pointeur sur le	
   		premier pave de niveau level (relativement a pAbb) qui n'est
   		pas de type numAbType.					
   		Si refKind == RkElType, le pave represente par numAbType est
   		celui d'un element de la representation interne,
		si refKind == RkPresBox, c'est une boite de presentation
		definie dans le schema de presentation pointe' par pSP.				si refKind == RkAttr, c'est un numero d'attribut.
   		Si level vaut RlReferred, on cherche parmi les paves de	
   		l'element designe' par l'attribut reference pointe'	
   		par pAttr.						
   		Au result, la fonction rend NULL si aucun pave ne	
   		correspond.						
  ----------------------------------------------------------------------*/

#ifdef __STDC__
static PtrAbstractBox SearchAbsBoxRef (boolean notType, int numAbType, PtrPSchema pSP, Level level, RefKind refKind, PtrAbstractBox pAbb, PtrAttribute pAttr)

#else  /* __STDC__ */
static PtrAbstractBox SearchAbsBoxRef (notType, numAbType, pSP, level, refKind, pAbb, pAttr)
boolean             notType;
int                 numAbType;
PtrPSchema          pSP;
Level               level;
RefKind		    refKind;
PtrAbstractBox      pAbb;
PtrAttribute        pAttr;

#endif /* __STDC__ */

{
   boolean             found;
   PtrAbstractBox      pAb;
   int                 view;
   PtrAbstractBox      pAbbMain;

   pAb = pAbb;
   if (pAb != NULL)
     {
	found = FALSE;
	switch (level)
	      {
		 case RlEnclosing:
		    do
		      {
			 pAb = pAb->AbEnclosing;
			 if (numAbType == 0)
			    found = TRUE;
			 else if (pAb != NULL)
			    VerifyAbsBox (&found, pSP, refKind, numAbType, notType, pAb);
		      }
		    while (pAb != NULL && !found);
		    break;

		 case RlSameLevel:
		    /* accede au premier pave de ce niveau */
		    if (pAb->AbEnclosing != NULL)
		       pAb = pAb->AbEnclosing->AbFirstEnclosed;
		    /* cherche en avant le pave demande' */
		    do
		       if (numAbType == 0)
			  if (pAb->AbDead)
			     pAb = pAb->AbNext;
			  else
			     found = TRUE;
		       else
			 {
			    VerifyAbsBox (&found, pSP, refKind, numAbType, notType, pAb);
			    if (!found)
			       pAb = pAb->AbNext;
			 }
		    while (pAb != NULL && !found);
		    break;

		 case RlEnclosed:
		    pAb = pAb->AbFirstEnclosed;
		    if (pAb != NULL)
		       do
			  if (numAbType == 0)
			     if (pAb->AbDead)
				pAb = pAb->AbNext;
			     else
				found = TRUE;
			  else
			    {
			       VerifyAbsBox (&found, pSP, refKind, numAbType, notType, pAb);
			       if (!found)
				  pAb = pAb->AbNext;
			    }
		       while (pAb != NULL && !found);
		    break;

		 case RlPrevious:
		    pAb = pAb->AbPrevious;
		    if (pAb != NULL)
		       do
			  if (numAbType == 0)
			     if (pAb->AbDead)
				pAb = pAb->AbPrevious;
			     else
				found = TRUE;
			  else
			    {
			       VerifyAbsBox (&found, pSP, refKind, numAbType, notType, pAb);
			       if (!found)
				  pAb = pAb->AbPrevious;
			    }
		       while (pAb != NULL && !found);
		    break;

		 case RlNext:
		    pAb = pAb->AbNext;
		    if (pAb != NULL)
		       do
			  if (numAbType == 0)
			     if (pAb->AbDead)
				pAb = pAb->AbNext;
			     else
				found = TRUE;
			  else
			    {
			       VerifyAbsBox (&found, pSP, refKind, numAbType, notType, pAb);
			       if (!found)
				  pAb = pAb->AbNext;
			    }
		       while (pAb != NULL && !found);
		    break;

		 case RlSelf:
		 case RlContainsRef:
		    break;

		 case RlRoot:
		    /* on cherche le pave racine de l'image abstraite */
		    while (pAb->AbEnclosing != NULL)
		       pAb = pAb->AbEnclosing;
		    break;

		 case RlCreator:
		    /* on cherche le pave' qui a cree' ce pave de presentation */
		    /* est-ce le pere ? */
		    if (pAb->AbEnclosing != NULL)
		       if (pAb->AbEnclosing->AbElement == pAb->AbElement)
			  if (!pAb->AbEnclosing->AbPresentationBox)
			    {
			       found = TRUE;	/* c'est bien le pere */
			       pAb = pAb->AbEnclosing;
			    }
		    if (!found)
		       /* on cherche parmi les freres */
		      {
			 /* parmi les freres suivants d'abord */
			 do
			    if (pAb->AbPresentationBox)
			       pAb = pAb->AbNext;
			    else if (pAb->AbElement == pAbb->AbElement)
			       found = TRUE;
			    else
			       pAb = NULL;
			 while (!found && pAb != NULL);
			 if (!found)
			    /* pas found', on cherche parmi les freres precedents */
			   {
			      pAb = pAbb;
			      do
				 if (pAb->AbPresentationBox)
				    pAb = pAb->AbPrevious;
				 else if (pAb->AbElement == pAbb->AbElement)
				    found = TRUE;
				 else
				    pAb = NULL;
			      while (!found && pAb != NULL);
			   }
		      }
		    if (pAb != NULL)
		       if (pAb->AbDead)
			  pAb = NULL;
		    break;

		 case RlReferred:
		    view = pAb->AbDocView;
		    if (pAttr == NULL)
		      {
			 /* cherche les attributs references de l'element */
			 pAttr = pAb->AbElement->ElFirstAttr;
			 found = FALSE;
			 while (pAttr != NULL && !found)
			   {
			      if (pAttr->AeAttrType == AtReferenceAttr)
				 /* c'est un attribut reference */
				{
				   /* cet attribut a-t-il une regle de presentation qui */
				   /* cree le pave pour lequel on travaille ? */
				   if (AttrCreatePresBox (pAttr, pAbb))
				      /* oui, c'est l'attribut cherche' */
				      found = TRUE;
				}
			      if (!found)
				 /* passe a l'attribut suivant de l'element */
				 pAttr = pAttr->AeNext;
			   }
		      }
		    pAb = NULL;
		    /* cherche le premier pave de l'element designe' par */
		    /* l'attribut */
		    if (pAttr != NULL)
		       if (pAttr->AeAttrType == AtReferenceAttr)
			  if (pAttr->AeAttrReference != NULL)
			     if (pAttr->AeAttrReference->RdReferred != NULL)
				/* les references externes ne sont pas utilisees */
				/* dans les positionnements et les dimensionnements */
				if (!pAttr->AeAttrReference->RdReferred->ReExternalRef)
				   if (pAttr->AeAttrReference->RdReferred->ReReferredElem != NULL)
				      pAb = pAttr->AeAttrReference->RdReferred->ReReferredElem->
					 ElAbstractBox[view - 1];
		    pAbbMain = NULL;
		    if (pAb != NULL)
		       /* cherche en avant le pave demande */
		       do
			  if (numAbType == 0)
			     if (pAb->AbDead)
				/* ce pave est en cours de destruction */
				if (pAb->AbNext == NULL)
				   pAb = NULL;
				else if (pAb->AbNext->AbElement == pAb->AbElement)
				   /* le pave suivant appartient au meme element,
				      on le prend en compte */
				   pAb = pAb->AbNext;
				else
				   /* on n'a pas found' de pave pour cet element */
				   pAb = NULL;
			     else
				found = TRUE;
			  else
			    {
			       VerifyAbsBox (&found, pSP, refKind, numAbType, notType, pAb);
			       if (!found)
				 {
				    if (!pAb->AbPresentationBox)
				       pAbbMain = pAb;
				    if (pAb->AbNext != NULL)
				       if (pAb->AbNext->AbElement == pAb->AbElement)
					  pAb = pAb->AbNext;
				       else
					  pAb = NULL;
				    else
				       pAb = NULL;
				 }
			    }
		       while (pAb != NULL && !found);
		    if (pAb == NULL && pAbbMain != NULL && numAbType != 0)
		       /* on cherche parmi les paves descendants du pave principal */
		      {
			 pAb = pAbbMain->AbFirstEnclosed;
			 while (pAb != NULL && !found)
			   {
			      VerifyAbsBoxDescent (&found, pSP, refKind, numAbType, notType, pAb);
			      if (!found && pAb != NULL)
				 pAb = pAb->AbNext;
			   }
		      }
		    break;

		 default:
		    break;
	      }
     }
   return pAb;
}



/*----------------------------------------------------------------------
   	GetConstantBuffer   acquiert un buffer de texte pour la constante de	
   		presentation correspondant au pave pointe par pAb.	
  ----------------------------------------------------------------------*/

#ifdef __STDC__
void                GetConstantBuffer (PtrAbstractBox pAb)

#else  /* __STDC__ */
void                GetConstantBuffer (pAb)
PtrAbstractBox      pAb;

#endif /* __STDC__ */

{
   PtrTextBuffer       pBT;


   GetTextBuffer (&pBT);
   pAb->AbText = pBT;
   if (pAb->AbLeafType == LtText)
     pAb->AbLanguage = TtaGetDefaultLanguage ();
   pAb->AbVolume = 0;
}



/*----------------------------------------------------------------------
   	UpdateFreeVol	met a jour le volume libre restant dans la vue	
   		du pave pAb, en prenant en compte le volume de ce	
   		nouveau pave feuille.					
  ----------------------------------------------------------------------*/

#ifdef __STDC__
void                UpdateFreeVol (PtrAbstractBox pAb, PtrDocument pDoc)

#else  /* __STDC__ */
void                UpdateFreeVol (pAb, pDoc)
PtrAbstractBox      pAb;
PtrDocument         pDoc;

#endif /* __STDC__ */

{


   if (!AssocView (pAb->AbElement))
      /* vue de l'arbre principal */
      pDoc->DocViewFreeVolume[pAb->AbDocView - 1] -= pAb->AbVolume;
   else
      /* vue d'elements associes */
      pDoc->DocAssocFreeVolume[pAb->AbElement->ElAssocNum - 1] -= pAb->AbVolume;
}



/*----------------------------------------------------------------------
   	FillContent met dans le pave pointe par pAb le contenu de l'element
   		feuille pointe par pEl.					
  ----------------------------------------------------------------------*/

#ifdef __STDC__
void                FillContent (PtrElement pEl, PtrAbstractBox pAb, PtrDocument pDoc)

#else  /* __STDC__ */
void                FillContent (pEl, pAb, pDoc)
PtrElement          pEl;
PtrAbstractBox      pAb;
PtrDocument         pDoc;

#endif /* __STDC__ */

{
   int                 lg, i;
   PtrTextBuffer       pBu1;
   PtrReference        pPR1;
   PtrReferredDescr    pDe1;

   if (pEl->ElHolophrast)
     {
	pAb->AbLeafType = LtText;
	GetConstantBuffer (pAb);
	pBu1 = pAb->AbText;
	CopyStringToText ("<", pBu1, &lg);
	CopyStringToText (pEl->ElStructSchema->SsRule[pEl->ElTypeNumber - 1].SrName,
			  pBu1, &i);
	lg += i;
	CopyStringToText (">", pBu1, &i);
	lg += i;
	pAb->AbVolume = lg;
	pAb->AbCanBeModified = FALSE;
	pAb->AbSensitive = TRUE;
	/* met a jour le volume libre restant dans la vue */
	UpdateFreeVol (pAb, pDoc);
     }
   else if (pEl->ElTerminal)
     {
	pAb->AbLeafType = pEl->ElLeafType;
	switch (pEl->ElLeafType)
	      {
		 case LtPicture:
		    /* saute les paves crees par FnCreateBefore */
		    /* while (pAb->AbText != NULL && pAb->AbNext != NULL)
		       pAb = pAb->AbNext; */
		    NewPictInfo (pAb, pEl->ElText->BuContent, UNKNOWN_FORMAT);
		    pAb->AbVolume = pEl->ElTextLength;
		    break;
		 case LtText:
		    /* saute les paves crees par FnCreateBefore */
		    while (pAb->AbText != NULL && pAb->AbNext != NULL)
		       pAb = pAb->AbNext;
		    /* prend le contenu de l'element correspondant */
		    pAb->AbText = pEl->ElText;
		    pAb->AbLanguage = pEl->ElLanguage;
		    pAb->AbVolume = pEl->ElTextLength;
		    break;
		 case LtPolyLine:
		    /* prend le contenu de l'element correspondant */
		    pAb->AbPolyLineBuffer = pEl->ElPolyLineBuffer;
		    pAb->AbVolume = pEl->ElNPoints;
		    pAb->AbPolyLineShape = pEl->ElPolyLineType;
		    break;
		 case LtSymbol:
		 case LtGraphics:
		    pAb->AbShape = pEl->ElGraph;
		    pAb->AbGraphAlphabet = 'G';
		    if (pAb->AbShape == '\0')
		       pAb->AbVolume = 0;
		    else
		       pAb->AbVolume = 1;
		    break;
		 case LtReference:
		    pAb->AbLeafType = LtText;
		    GetConstantBuffer (pAb);
		    pBu1 = pAb->AbText;
		    pBu1->BuContent[0] = '[';
		    lg = 2;
		    pBu1->BuContent[lg - 1] = '?';
		    /* la reference pointe sur rien */
		    if (pEl->ElReference != NULL)
		      {
			 pPR1 = pEl->ElReference;
			 if (pPR1->RdInternalRef)
			   {
			      if (pPR1->RdReferred != NULL)
				 if (!pPR1->RdReferred->ReExternalRef)
				    if (!IsASavedElement (pPR1->RdReferred->ReReferredElem))
				       /* l'element reference' n'est pas dans le */
				       /* buffer des elements coupe's */
				       pBu1->BuContent[lg - 1] = '*';
			      lg++;
			      pBu1->BuContent[lg - 1] = ']';
			   }
			 else
			   {
			      if (pPR1->RdReferred != NULL)
				 if (pPR1->RdReferred->ReExternalRef)
				    /* copie le nom du document reference' */
				   {
				      i = 1;
				      pDe1 = pPR1->RdReferred;
				      while (pDe1->ReExtDocument[i - 1] != '\0')
					{
					   pBu1->BuContent[lg - 1] = pDe1->ReExtDocument[i - 1];
					   lg++;
					   i++;
					}
				      lg--;
				   }
			      lg++;
			      if (!pPR1->RdInternalRef)
				{
				   pBu1->BuContent[0] = '<';
				   pBu1->BuContent[lg - 1] = '>';
				}
			      else
				 pBu1->BuContent[lg - 1] = ']';
			   }
		      }
		    pBu1->BuContent[lg] = '\0';
		    /* fin de la chaine de car. */
		    pBu1->BuLength = lg;
		    pAb->AbVolume = lg;
		    pAb->AbCanBeModified = FALSE;
		    break;
		 case LtPairedElem:
		    pAb->AbLeafType = LtText;
		    GetConstantBuffer (pAb);
		    pBu1 = pAb->AbText;
		    if (pEl->ElStructSchema->SsRule[pEl->ElTypeNumber - 1].SrFirstOfPair)
		      {
			 pBu1->BuContent[0] = '<';
			 pBu1->BuContent[1] = '<';
		      }
		    else
		      {
			 pBu1->BuContent[0] = '>';
			 pBu1->BuContent[1] = '>';
		      }
		    pBu1->BuContent[2] = '\0';
		    /* fin de la chaine de car. */
		    pBu1->BuLength = 2;
		    pAb->AbVolume = 2;
		    pAb->AbCanBeModified = FALSE;
		    break;
		 default:
		    break;
	      }
	/* met a jour le volume libre restant dans la vue */
	UpdateFreeVol (pAb, pDoc);
     }
}


/*----------------------------------------------------------------------
   	PageCreateRule	cherche dans la chaine de regles de presentation
   	qui commence par pPRule et qui appartient au schema de		
   	presentation pointe' par pSPR, la regle de creation qui		
   	engendre le pave pCree.						
   	Si cette regle est trouvee, retourne TRUE et TypeCreation	
   	contient le type de cette regle,				
   	Sinon, retourne FALSE.						
  ----------------------------------------------------------------------*/
#ifdef __STDC__
static boolean      PageCreateRule (PtrPRule pPRule, PtrPSchema pSPR, PtrAbstractBox pCree, FunctionType * TypeCreation)
#else  /* __STDC__ */
static boolean      PageCreateRule (pPRule, pSPR, pCree, TypeCreation)
PtrPRule            pPRule;
PtrPSchema          pSPR;
PtrAbstractBox      pCree;
FunctionType       *TypeCreation;

#endif /* __STDC__ */
{
   boolean             stop;
   boolean             result;

   result = FALSE;
   stop = FALSE;
   if (pCree != NULL)
      do
	 if (pPRule == NULL)
	    /* il n' y a plus de regles dans la chaine de regles */
	    stop = TRUE;
	 else if (pPRule->PrType > PtFunction)
	    /* il n'y a plus de regle fonction de presentation dans la chaine */
	    stop = TRUE;
	 else if (pPRule->PrType < PtFunction)
	    /* on n'a pas encore vu les Fonctions */
	    pPRule = pPRule->PrNextPRule;
	 else
	   {
	      /* la regle pPRule est une fonction de presentation */
	      if ((pPRule->PrPresFunction == FnCreateBefore
		   || pPRule->PrPresFunction == FnCreateWith
		   || pPRule->PrPresFunction == FnCreateAfter
		   || pPRule->PrPresFunction == FnCreateEnclosing
		   || pPRule->PrPresFunction == FnCreateFirst
		   || pPRule->PrPresFunction == FnCreateLast)
		  && pCree->AbTypeNum == pPRule->PrPresBox[0]
		  && pCree->AbPSchema == pSPR)
		 /* c'est une regle de creation et elle cree ce type de */
		 /* boite */
		{
		   stop = TRUE;
		   result = TRUE;
		   *TypeCreation = pPRule->PrPresFunction;
		}
	      else
		 /* passe a la regle suivante de la chaine */
		 pPRule = pPRule->PrNextPRule;
	   }
      while (!stop);
   return result;
}


/*----------------------------------------------------------------------
  TypeCreatedRule retourne le type de la regle de presentation appelee	
  par le pave pAbbCreator et qui a cree le pave pAbbCreated.	
  ----------------------------------------------------------------------*/
#ifdef __STDC__
FunctionType        TypeCreatedRule (PtrDocument pDoc, PtrAbstractBox pAbbCreator, PtrAbstractBox pAbbCreated)
#else  /* __STDC__ */
FunctionType        TypeCreatedRule (pDoc, pAbbCreator, pAbbCreated)
PtrDocument         pDoc;
PtrAbstractBox      pAbbCreator;
PtrAbstractBox      pAbbCreated;
#endif /* __STDC__ */

{
   PtrPRule            pPRuleCre;
   FunctionType        result;
   PtrPSchema          pSPR;
   PtrAttribute        pAttr;
   PtrAttribute        pA;
   boolean             ok;
   PtrPSchema          pSchP;
   PtrHandlePSchema    pHd;

   result = FnLine;
   /* cherche les regles de creation en ignorant les attributs */
   pPRuleCre = SearchRulepAb (pDoc, pAbbCreator, &pSPR, PtFunction, FnAny, FALSE, &pAttr);
   if (!PageCreateRule (pPRuleCre, pSPR, pAbbCreated, &result))
      /* on n'a pas found la regle qui cree la bonne boite */
      /* on cherche les regles de creation associees aux attributs */
      /* de l'element createur */
     {
	ok = FALSE;
	pA = pAbbCreator->AbElement->ElFirstAttr;
	while (pA != NULL && !ok)
	  {
	     pSchP = pA->AeAttrSSchema->SsPSchema;
	     pHd = NULL;
	     /* on examine le schema de presentation principal, puis les schemas */
	     /* additionnels */
	     while (pSchP != NULL && !ok)
	       {
		  /* cherche la premiere regle de presentation pour cet attribut */
		  /* dans ce schema de presentation */
		  pPRuleCre = AttrPresRule (pA, pAbbCreator->AbElement, FALSE, NULL, pSchP);
		  ok = PageCreateRule (pPRuleCre, pSchP, pAbbCreated, &result);
		  if (pHd == NULL)
		     /* on n'a pas encore traite' les schemas de presentation additionnels
		        On prend le premier schema additionnel. */
		     pHd = pA->AeAttrSSchema->SsFirstPSchemaExtens;
		  else
		     /* passe au schema additionnel suivant */
		     pHd = pHd->HdNextPSchema;
		  if (pHd == NULL)
		     /* il n'y a pas (ou plus) de schemas additionnels */
		     pSchP = NULL;
		  else
		     pSchP = pHd->HdPSchema;
	       }
	     if (!ok)
		/* passe a l'attribut suivant de l'element */
		pA = pA->AeNext;
	  }
     }
   return result;
}



/*----------------------------------------------------------------------
   	SearchPresSchema	cherche le schema de presentation a appliquer a	
   		l'element pointe par pEl. Retourne dans pSchP un	
   		pointeur sur ce schema, dans indexElType le numero de	
   		l'entree correspondant a l'element dans ce schema et	
   		dans pSchS un pointeur sur le schema de structure auquel
   		correspond le schema de presentation retourne'.		
  ----------------------------------------------------------------------*/
#ifdef __STDC__
void                SearchPresSchema (PtrElement pEl, PtrPSchema * pSchP, int *indexElType, PtrSSchema * pSchS)
#else  /* __STDC__ */
void                SearchPresSchema (pEl, pSchP, indexElType, pSchS)
PtrElement          pEl;
PtrPSchema         *pSchP;
int                *indexElType;
PtrSSchema         *pSchS;

#endif /* __STDC__ */
{
   boolean             found;
   int                 i;
   PtrSSchema          pSc1;
   SRule              *pSRule;

   if (pEl == NULL || pEl->ElStructSchema == NULL)
     {
	*pSchP = NULL;
	*pSchS = NULL;
	*indexElType = 0;
     }
   else
     {
	*pSchP = pEl->ElStructSchema->SsPSchema;
	*pSchS = pEl->ElStructSchema;
	/* premiere regle de presentation specifique a ce type d'element */
	*indexElType = pEl->ElTypeNumber;
	/* s'il s'agit de l'element racine d'une nature, on prend les regles */
	/* de presentation (s'il y en a) de la regle nature dans la structure */
	/* englobante. */
	/* on ne traite pas les marques de page */
	if (!pEl->ElTerminal || pEl->ElLeafType != LtPageColBreak)
	   if (pEl->ElParent != NULL)
	      /* il y a un englobant */
	      if (pEl->ElParent->ElStructSchema != pEl->ElStructSchema)
		 /* cherche la regle introduisant la nature dans le schema de */
		 /* structure de l'englobant. */
		{
		pSc1 = pEl->ElParent->ElStructSchema;
		if (pSc1 != NULL)
		  {
		   found = FALSE;
		   i = 0;
		   do
		     {
			i++;
			pSRule = &pSc1->SsRule[i - 1];
			if (pSRule->SrConstruct == CsNatureSchema)
			   if (pSRule->SrSSchemaNat == pEl->ElStructSchema)
			      found = TRUE;
		     }
		   while (!found && i < pSc1->SsNRules);
		   if (found)
		      if (pSc1->SsPSchema->PsElemPRule[i - 1] != NULL)
			 /* il y a des regles de presentation specifiques */
			{
			   *pSchP = pSc1->SsPSchema;
			   *indexElType = i;
			   *pSchS = pEl->ElParent->ElStructSchema;
			}
		  }
		}
     }
}

/*----------------------------------------------------------------------
   	CheckPPosUser							
  ----------------------------------------------------------------------*/
#ifdef __STDC__
static boolean      CheckPPosUser (PtrAbstractBox pAb, PtrDocument pDoc)
#else  /* __STDC__ */
static boolean      CheckPPosUser (pAb, pDoc)
PtrAbstractBox      pAb;
PtrDocument         pDoc;

#endif /* __STDC__ */
{
   int                 frame;
   boolean             result;

   if (AssocView (pAb->AbElement))
      frame = pDoc->DocAssocFrame[pAb->AbElement->ElAssocNum - 1];
   else
      frame = pDoc->DocViewFrame[pAb->AbDocView - 1];
   result = IsAbstractBoxDisplayed (pAb, frame);
   return result;
}


/*----------------------------------------------------------------------
   	ApplyPos 	applique la regle de position PR-pPRule 	
   		au pave pAbb1. 						
   		rend vrai dans appl si la regle a ete appliquee.	
  ----------------------------------------------------------------------*/
#ifdef __STDC__
static void         ApplyPos (AbPosition * PPos, PosRule positionRule, PtrPRule pPRule, PtrAttribute pAttr, PtrPSchema pSchP, PtrAbstractBox pAbb1, PtrDocument pDoc, boolean * appl)
#else  /* __STDC__ */
static void         ApplyPos (PPos, positionRule, pPRule, pAttr, pSchP, pAbb1, pDoc, appl)
AbPosition         *PPos;
PosRule             positionRule;
PtrPRule            pPRule;
PtrAttribute        pAttr;
PtrPSchema          pSchP;
PtrAbstractBox      pAbb1;
PtrDocument         pDoc;
boolean            *appl;

#endif /* __STDC__ */
{
   PtrAbstractBox      pAbbPos;
   boolean             pageBreak;
   PtrAbstractBox      pAbbParent;
   PosRule            *pPosRule;
   PtrPRule            pRSpec;
   PtrPSchema          pSchPPage;
   int                 b, PageHeaderHeight;

   *appl = FALSE;
   /* on n'a pas (encore) applique' la regle */
   pageBreak = FALSE;
   /* le pave est-il une marque de saut de page (le trait horizontal */
   /* qui separe les pages dans les images) ? Dans ce cas, il aura */
   /* une position flottante */
   if (pAbb1->AbElement->ElTerminal && pAbb1->AbElement->ElLeafType == LtPageColBreak)
      if (pAbb1->AbLeafType != LtCompound && !pAbb1->AbPresentationBox)
	 pageBreak = TRUE;
   pPosRule = &positionRule;
   if (pPosRule->PoPosDef == NoEdge || pageBreak)
      /* position flottante: regle VertPos=NULL ou HorizPos=NULL */
     {
	PPos->PosEdge = NoEdge;
	PPos->PosRefEdge = NoEdge;
	PPos->PosDistance = 0;
	PPos->PosUnit = UnRelative;
	PPos->PosAbRef = NULL;
	PPos->PosUserSpecified = FALSE;
	*appl = TRUE;
     }
   else
     {
	/* cherche le pave (pAbbPos) par rapport auquel le pave */
	/* traite' se positionne  */
	pAbbPos = NULL;
	if (pPosRule->PoRefKind == RkElType)
	   /* appelle l'exception des tableaux, au cas ou ce serait la */
	   /* regle de hauteur d'un filet vertical d'un tableau */
	   if (ThotLocalActions[T_abref] != NULL)
	      (*ThotLocalActions[T_abref]) (pAbb1, pPosRule, pPRule, &pAbbPos);
	      /* si l'exception n'a pas ete traitee, effectue un traitement
		 normal */
	if (pAbbPos == NULL)
	   pAbbPos = SearchAbsBoxRef (pPosRule->PoNotRel,
			  pPosRule->PoRefIdent, pSchP, pPosRule->PoRelation,
			  pPosRule->PoRefKind, pAbb1, pAttr);
	if (pAbbPos != NULL)
	  {
	     /* on a trouve' le pave de reference */
	     PPos->PosEdge = pPosRule->PoPosDef;
	     PPos->PosRefEdge = pPosRule->PoPosRef;
	     if (pPosRule->PoDistAttr)
		/* c'est la valeur d'un attribut */
	       {
		  if (pPosRule->PoDistance < 0)
		     /* il faut inverser cette valeur */
		     PPos->PosDistance = -AttrValue (pAttr);
		  else
		     PPos->PosDistance = AttrValue (pAttr);
		  if (pPosRule->PoDistUnit == UnRelative ||
		      pPosRule->PoDistUnit == UnXHeight)
		     /* convertit en 1/10 de caractere */
		     PPos->PosDistance = 10 * PPos->PosDistance;
	       }
	     else
		/* c'est la valeur elle meme qui est dans la regle */
		PPos->PosDistance = pPosRule->PoDistance;
	     PPos->PosUnit = pPosRule->PoDistUnit;
	     PPos->PosAbRef = pAbbPos;
	     if (FirstCreation)
		PPos->PosUserSpecified = pPosRule->PoUserSpecified;
	     else
		PPos->PosUserSpecified = FALSE;
	     if (PPos->PosUserSpecified)
		PPos->PosUserSpecified = CheckPPosUser (pAbb1, pDoc);
	     *appl = TRUE;
	     /* verifie si le pave deroge a la regle d'englobement */
	     if (pPosRule->PoRelation == RlRoot)
		if (PPos->PosAbRef != pAbb1->AbEnclosing)
		   /* ce pave deroge a la regle d'englobement */
		   if (pPRule->PrType == PtHorizPos)
		      pAbb1->AbHorizEnclosing = FALSE;
		   else if (pPRule->PrType == PtVertPos)
		      pAbb1->AbVertEnclosing = FALSE;
	     if (PPos->PosAbRef == pAbb1->AbEnclosing)
		/* le pave se positionne par rapport a l'englobant */

		if (pPRule->PrType == PtHorizPos)
		   /* position horizontale */
		   if (PPos->PosDistance < 0)
		     {
			if (PPos->PosEdge == Left && PPos->PosRefEdge ==
			    Left)
			   /* le cote gauche du pave est a gauche du */
			   /* cote gauche de l'englobant: debordement */
			   pAbb1->AbHorizEnclosing = FALSE;
		     }
		   else
		     {
			if (PPos->PosDistance > 0)
			  {
			     if (PPos->PosEdge == Right && PPos->PosRefEdge == Right)
				/* le cote droit du pave est a droite du */
				/* cote droit de l'englobant: debordement */
				pAbb1->AbHorizEnclosing = FALSE;
			  }
		     }
		else if (pPRule->PrType == PtVertPos)
		  {
#ifndef __COLPAGE__
		     /* regarde si le premier fils de l'englobant est un saut de page */
		     pAbbParent = pAbb1->AbEnclosing;
		     if (pAbbParent->AbFirstEnclosed != pAbb1
			 && !pAbbParent->AbFirstEnclosed->AbDead
		         && pAbbParent->AbFirstEnclosed->AbElement->ElTerminal
			 && pAbbParent->AbFirstEnclosed->AbElement->ElLeafType == LtPageColBreak)
		       {
			  /* positionne par rapport au saut de page */
			  PPos->PosRefEdge = Bottom;
			  PPos->PosAbRef = pAbbParent->AbFirstEnclosed;
			  /* mise a jour de la distance */
			  /* si PPos->PosDistance est en unite relative on ne fait rien */
			  /* sinon, PPos->PosDistance est decremente de la hauteur */
			  /* du haut de la boite haut de page */
			  if (PPos->PosUnit == UnPoint)
			    {
			       /* on cherche la boite page correspondant a la regle page */
			       /* portee par un des ascendants  */
			       b = GetPageBoxType (pAbbParent->AbFirstEnclosed->AbElement,
					      pAbbParent->AbFirstEnclosed->AbElement->ElViewPSchema,
					      &pSchPPage);
			       PageHeaderHeight = pSchPPage->PsPresentBox[b - 1].PbHeaderHeight;
			       /* PbHeaderHeight toujours en points typo */
			       if (PPos->PosDistance - PageHeaderHeight >= 0)
				  PPos->PosDistance = PPos->PosDistance - PageHeaderHeight;
			    }
			  PPos->PosUserSpecified = FALSE;
		       }
#endif /* __COLPAGE__ */
		     if (PPos->PosDistance < 0)
		       {
			  if (PPos->PosEdge == Top && PPos->PosRefEdge == Top)
			     /* le haut du pave est au-dessus du */
			     /* haut de l'englobant: debordement */
			     pAbb1->AbVertEnclosing = FALSE;
		       }
		     else if (PPos->PosDistance > 0)
			if (PPos->PosEdge == Bottom && PPos->PosRefEdge == Bottom)
			   /* le bas du pave est au-dessous du */
			   /* bas de l'englobant: debordement */
			   pAbb1->AbVertEnclosing = FALSE;
		  }
	  }
	else
	   /* on n'a pas found le pave de reference */
	   if (pAbb1->AbLeafType != LtCompound
	       && !(pPosRule->PoRelation == RlNext
		    || pPosRule->PoRelation == RlPrevious
		    || pPosRule->PoRelation == RlSameLevel
		    || pPosRule->PoRelation == RlCreator
		    || pPosRule->PoRelation == RlReferred))
	  {
	     /* inutile de reessayer d'appliquer la regle */
	     /* quand les paves environnants seront crees. */
	     PPos->PosEdge = pPosRule->PoPosDef;
	     PPos->PosRefEdge = pPosRule->PoPosRef;
	     PPos->PosDistance = pPosRule->PoDistance;
	     PPos->PosUnit = pPosRule->PoDistUnit;
	     PPos->PosAbRef = NULL;
	     PPos->PosUserSpecified = pPosRule->PoUserSpecified;
	     if (PPos->PosUserSpecified)
		PPos->PosUserSpecified = CheckPPosUser (pAbb1, pDoc);
	     *appl = TRUE;

	  }
	else if (pAbb1->AbEnclosing == NULL && pPosRule->PoRelation == RlEnclosing)
	   /* positionnement par rapport a la fenetre */
	  {
	     PPos->PosEdge = pPosRule->PoPosDef;
	     PPos->PosRefEdge = pPosRule->PoPosRef;
	     if (pPosRule->PoDistAttr)
		/* valeur d'un attribut */
	       {
		  if (pPosRule->PoDistance < 0)
		     /* inverser cette valeur */
		     PPos->PosDistance = -AttrValue (pAttr);
		  else
		     PPos->PosDistance = AttrValue (pAttr);
		  if (pPosRule->PoDistUnit == UnRelative ||
		      pPosRule->PoDistUnit == UnXHeight)
		     /* convertit en 1/10 de caractere */
		     PPos->PosDistance = 10 * PPos->PosDistance;
	       }
	     else
		/* c'est la valeur elle meme */
		PPos->PosDistance = pPosRule->PoDistance;
	     if (FirstCreation)
		PPos->PosUserSpecified = pPosRule->PoUserSpecified;
	     else
		PPos->PosUserSpecified = FALSE;
	     if (PPos->PosUserSpecified)
		PPos->PosUserSpecified = CheckPPosUser (pAbb1, pDoc);
	     PPos->PosUnit = pPosRule->PoDistUnit;
	     PPos->PosAbRef = NULL;
	     *appl = TRUE;
	  }
	else
	   /* on n'a pas found' le pave' de reference */
	   /* si c'est un positionnement par rapport au precedent ou au */
	   /* suivant, on positionne le pave par rapport a l'englobant */
	   if (pAbb1->AbEnclosing != NULL &&
	       (
		  (pPRule->PrType == PtVertPos && pPosRule->PoRelation == RlPrevious &&
	       pPosRule->PoPosDef == Top && pPosRule->PoPosRef == Bottom) ||
	   (pPRule->PrType == PtVertPos && pPosRule->PoRelation == RlNext &&
	    pPosRule->PoPosDef == Bottom && pPosRule->PoPosRef == Top) ||
		  (pPRule->PrType == PtHorizPos && pPosRule->PoRelation == RlPrevious &&
	       pPosRule->PoPosDef == Left && pPosRule->PoPosRef == Right) ||
	   (pPRule->PrType == PtHorizPos && pPosRule->PoRelation == RlNext &&
	    pPosRule->PoPosDef == Right && pPosRule->PoPosRef == Left)
	       )
	   )
	   /* c'est une regle de positionnement vertical en dessous du
	      precedent et on n'a pas trouve' le precedent. On remplace par
	      un positionnement en haut de l'englobant */
	  {
	     PPos->PosAbRef = pAbb1->AbEnclosing;
	     PPos->PosEdge = pPosRule->PoPosDef;
	     PPos->PosRefEdge = pPosRule->PoPosDef;
	     /* s'agit-il d'une regle de presentation specifique ? */
	     pRSpec = pAbb1->AbElement->ElFirstPRule;
	     while (pRSpec != NULL && pRSpec != pPRule)
		pRSpec = pRSpec->PrNextPRule;
	     if (pRSpec == pPRule)
		/* c'est une regle de presentation specifique */
		/* on prend le decalage en compte */
		PPos->PosDistance = pPosRule->PoDistance;
	     else
		/* c'est une regle generique */
		/* on se positionne tout contre l'englobant */
		PPos->PosDistance = 0;
	     /* on pourra reessayer d'appliquer la regle plus tard : */
	     /* le precedent existera peut etre, alors */
	     *appl = FALSE;
	     PPos->PosUnit = pPosRule->PoDistUnit;
	     if (FirstCreation)
		PPos->PosUserSpecified = pPosRule->PoUserSpecified;
	     else
		PPos->PosUserSpecified = FALSE;
	     if (PPos->PosUserSpecified)
		PPos->PosUserSpecified = CheckPPosUser (pAbb1, pDoc);
	     pAbb1->AbVertEnclosing = TRUE;
	  }
     }
}



/*----------------------------------------------------------------------
   	ApplyDim	 applique au pave pointe' par pAb la regle	
   		de dimension pointee par pPRule.			
  ----------------------------------------------------------------------*/
#ifdef __STDC__
static void         ApplyDim (AbDimension * pdimAb, PtrAbstractBox pAb, PtrPSchema pSchP, PtrAttribute pAttr, boolean * appl, PtrPRule pPRule, PtrDocument pDoc)
#else  /* __STDC__ */
static void         ApplyDim (pdimAb, pAb, pSchP, pAttr, appl, pPRule, pDoc)
AbDimension        *pdimAb;
PtrAbstractBox      pAb;
PtrPSchema          pSchP;
PtrAttribute        pAttr;
boolean            *appl;
PtrPRule            pPRule;
PtrDocument         pDoc;

#endif /* __STDC__ */
{
   PtrAbstractBox      pAbbRef;
   PtrAttribute        pA;
   boolean             stop;
   DimensionRule      *pDRule;
   int                 attrRule;

   /* on met a priori les valeurs correspondant a une dimension */
   /* egale a celle du contenu. */
   pdimAb->DimIsPosition = FALSE;
   pdimAb->DimValue = 0;
   pdimAb->DimAbRef = NULL;
   pdimAb->DimUnit = pPRule->PrDimRule.DrUnit;
   pdimAb->DimSameDimension = TRUE;
   pdimAb->DimMinimum = pPRule->PrDimRule.DrMin;
   if (FirstCreation)
      pdimAb->DimUserSpecified = pPRule->PrDimRule.DrUserSpecified;
   else
      pdimAb->DimUserSpecified = FALSE;
   if (pdimAb->DimUserSpecified)
      pdimAb->DimUserSpecified = CheckPPosUser (pAb, pDoc);

   *appl = FALSE;
   pDRule = &pPRule->PrDimRule;
   if (pDRule->DrPosition)
     {
	/* Box elastique, la dimension est definie comme une position */
	/* applique la regle */
	ApplyPos (&pdimAb->DimPosition, pDRule->DrPosRule, pPRule, pAttr, pSchP, pAb, pDoc, appl);
	/* si la regle a pu etre appliquee, le boite est reellement elastique */
	if (*appl)
	   pdimAb->DimIsPosition = TRUE;
     }
   else if (pDRule->DrAbsolute)
     {
	/* valeur absolue */
	if (pDRule->DrAttr)
	   /* c'est la valeur d'un attribut */
	  {
	     if (pDRule->DrValue < 0)
		/* il faut inverser cette valeur */
		pdimAb->DimValue = -AttrValue (pAttr);
	     else
		pdimAb->DimValue = AttrValue (pAttr);
	     if (pDRule->DrUnit == UnRelative ||
		 pDRule->DrUnit == UnXHeight)
		/* convertit en 1/10 de caractere */
		pdimAb->DimValue = 10 * pdimAb->DimValue;
	  }
	else
	   /* c'est la valeur elle meme qui est dans la regle */
	   pdimAb->DimValue = pDRule->DrValue;
	*appl = TRUE;
     }
   else if (pDRule->DrRelation == RlEnclosed)
     {
	/* dimension du contenu */
	*appl = TRUE;
	/* les valeurs mises a priori conviennent */
	pdimAb->DimValue = pDRule->DrValue;
     }
   else
     {
	/* dimensions relatives a l'englobant ou un frere */
	pdimAb->DimSameDimension = pDRule->DrSameDimens;
	/* essaie d'appliquer la regle de dimensionnement relatif */
	pAbbRef = SearchAbsBoxRef (pDRule->DrNotRelat, pDRule->DrRefIdent, pSchP,
		      pDRule->DrRelation, pDRule->DrRefKind, pAb, pAttr);
	pdimAb->DimAbRef = pAbbRef;
	if (pAbbRef == NULL && pAb->AbElement != NULL)
	   if (pAb->AbEnclosing == NULL && pDRule->DrRelation == RlEnclosing)
	      /* heritage des dimensions de la fenetre */
	     {
		if (pDRule->DrValue == 0)
		  {
		     pdimAb->DimValue = 100;
		     pdimAb->DimUnit = UnPercent;
		  }
		else
		  {
		     pdimAb->DimUnit = pDRule->DrUnit;
		     if (pDRule->DrAttr)
			/* c'est la valeur d'un attribut */
		       {
			  if (pDRule->DrValue < 0)
			     /* inverser cette valeur */
			     pdimAb->DimValue = -AttrValue (pAttr);
			  else
			     pdimAb->DimValue = AttrValue (pAttr);
			  if (pDRule->DrUnit == UnRelative ||
			      pDRule->DrUnit == UnXHeight)
			     /* convertit en 1/10 de caractere */
			     pdimAb->DimValue = 10 * pdimAb->DimValue;
		       }
		     else
			/* c'est la valeur elle meme */
			pdimAb->DimValue = pDRule->DrValue;
		  }
		*appl = TRUE;
	     }
	if (pAbbRef != NULL)
	  {
	     if (pDRule->DrAttr)
		/* c'est la valeur d'un attribut */
	       {
		  pA = pAttr;
		  attrRule = pDRule->DrValue;
		  if (pDRule->DrValue < 0)
		     attrRule = -attrRule;

		  /* l'attribut est-il celui de la regle ? */
		  if (pAttr->AeAttrNum != attrRule
		      || pAttr->AeAttrSSchema->SsPSchema != pSchP)
		     /* ce n'est pas l'attribut indique' dans la regle, */
		     /* cherche si l'elem. possede l'attribut de la regle */
		    {
		       pA = pAb->AbElement->ElFirstAttr;
		       stop = FALSE;
		       do
			  if (pA == NULL)
			     stop = TRUE;	/* dernier attribut de l'element */
			  else if (pA->AeAttrNum == attrRule
				   && pA->AeAttrSSchema->SsPSchema == pSchP)
			     stop = TRUE;	/* c'est l'attribut cherche' */
			  else
			     pA = pA->AeNext;
		       while (!stop);
		    }
		  pdimAb->DimValue = AttrValue (pA);
		  if (pDRule->DrValue < 0)
		     /* inverser cette valeur */
		     pdimAb->DimValue = -pdimAb->DimValue;
		  if (pDRule->DrUnit == UnRelative ||
		      pDRule->DrUnit == UnXHeight)
		     /* convertit en 1/10 de caractere */
		     pdimAb->DimValue = 10 * pdimAb->DimValue;
	       }
	     else
		/* c'est la valeur elle-meme */
		pdimAb->DimValue = pDRule->DrValue;
	     pdimAb->DimUnit = pDRule->DrUnit;
	     *appl = TRUE;
	  }
     }
}


#ifdef __COLPAGE__
/*----------------------------------------------------------------------
   	ApplyCol		applique une regle Column			
   	on insere l'element marque Column AVANT l'element		
   	si element racine, on insere la marque col comme premier fils	
   	si element marque page, on insere la marque col APRES.		
   	le boolean de result indique si le pave pAb a ete detruit.	
   	On ajoute une marque colonne apres l'element pour permettre	
   	de reprendre une presentation conforme a la regle qui		
   	s'appliquait avant l'element pAb->AbElement			
  ----------------------------------------------------------------------*/
#ifdef __STDC__
static boolean      ApplyCol (PtrDocument pDoc, PtrAbstractBox pAb, int viewSch, PtrPRule pPRule)
#else  /* __STDC__ */
static boolean      ApplyCol (pDoc, pAb, viewSch, pPRule)
PtrDocument         pDoc;
PtrAbstractBox      pAb;
int                 viewSch;
PtrPRule            pPRule;

#endif /* __STDC__ */
{
   PtrElement          pElCol, pEl1, pEl, pPrec;
   PtrAbstractBox      pP;
   boolean             colexiste, stop, beforepEl;
   boolean             complete;
   PtrAbstractBox      pAbbR;
   int                 frame, h, view;
   boolean             bool, destroyedAb, found;
   PtrElement          pElGrCols, pElGr1, pSuiv;

   destroyedAb = FALSE;		/* a priori pas de destruction de paves */
   if (pPRule->PrViewNum == viewSch)
      /* la regle Column concerne la vue du pave traite' */
     {
	view = pAb->AbDocView;
	pEl = pAb->AbElement;
	pElCol = NULL;
	colexiste = FALSE;
	beforepEl = FALSE;	/* il faut recreer l'image si les marques sont creees */
	/* a priori, on n'a pas a creer les paves si la */
	/* colonne existe deja (sauf si manque colgroupee */
	/* si pEl est une marque page qui n'est pas une page debut */
	/* on ignore la regle. */
	if (!(pEl->ElTerminal && pEl->ElLeafType == LtPageColBreak
	      && (pEl->ElPageType == PgUser
		  || pEl->ElPageType == PgComputed)))
	  {
	     /* creation d'un element Marque colonne debut comme frere avant pEl */
	     /* sauf si pEl est la racine (creation comme premier fils) */
	     /* ou un element Marque Page (regle Column dans une boite Page) */

	     /* tout d'abord, on verifie que la marque colonne n'existe pas deja */
	     pEl1 = NULL;
	     if (pEl->ElTerminal && pEl->ElLeafType == LtPageColBreak)
		/* on verifie que la marque colonne n'existe pas deja apres */
		pEl1 = pEl->ElNext;
	     else if (pEl->ElParent == NULL)
		/* on verifie que la marque colonne n'existe pas deja comme fils */
		pEl1 = pEl->ElFirstChild;
	     if (pEl1 != NULL)
	       {
		  while (pEl1->ElTerminal && pEl1->ElTypeNumber == PageBreak + 1
			 && (pEl1->ElViewPSchema != viewSch
			     || pEl1->ElPageType != ColBegin))
		     /* ignore les sauts de page pour les autres vues */
		     /* et les marques autres que ColBegin */
		     pEl1 = pEl1->ElNext;

		  if (pEl1 != NULL &&
		    pEl1->ElTerminal && pEl1->ElTypeNumber == PageBreak + 1)
		     /* on est sur que l'on est sur une marque ColBegin */
		     /* donc on ne cree pas une nouvelle marque */
		    {
		       pElCol = pEl1;
		       colexiste = TRUE;
		       /* code temporaire : si pas de ColGroup qui precede */
		       /* ce ColBegin, on en ajoute un pour etre conforme au */
		       /* nouveau code */
		       if (!(pElCol->ElPrevious != NULL
			&& pElCol->ElPrevious->ElTypeNumber == PageBreak + 1
			     && pElCol->ElPrevious->ElPageType == ColGroup))
			 {
			    /* si l'element ColGroup existe, on ne cree rien */
			    /* sinon, on cree l'element ColGroup */
			    pElGrCols = NewSubtree (PageBreak + 1, pEl->ElStructSchema,
			     pDoc, pEl->ElAssocNum, TRUE, TRUE, TRUE, TRUE);
			    InsertElementBefore (pElCol, pElGrCols);
			    pElGrCols->ElPageType = ColGroup;
			    pElGrCols->ElViewPSchema = viewSch;
			    pElGrCols->ElPageNumber = 0;	/* numero attribue pour les groupes */
			    /* pas besoin de recreer l'image car l'element */
			    /* colgroupees est place apres l'element marque page */
			 }
		    }
	       }		/* fin pEl1 != NULL pour pEl = marque page ou racine */

	     if (!((pEl->ElTerminal && pEl->ElLeafType == LtPageColBreak)
		   || (pEl->ElParent == NULL)))
		/* regle colonne sur un element quelconque */
		/* l'element est-il precede' par un saut de colonne identique a */
		/* celui qu'on veut creer ? */
	       {
		  pPrec = pEl;
		  while (pPrec->ElPrevious == NULL && pPrec->ElParent != NULL)
		     pPrec = pPrec->ElParent;
		  pPrec = pPrec->ElPrevious;
		  stop = pPrec == NULL;
		  while (!stop)
		     if (pPrec->ElTerminal)
		       {
			  stop = TRUE;
			  /* ignore les sauts de page pour les autres vues */
			  if (pPrec->ElTypeNumber == PageBreak + 1)
			     if (pPrec->ElViewPSchema != viewSch)
			       {
				  pPrec = pPrec->ElPrevious;
				  stop = pPrec == NULL;
			       }
		       }
		     else
		       {
			  pPrec = pPrec->ElFirstChild;
			  if (pPrec == NULL)
			     stop = TRUE;
			  else
			     while (pPrec->ElNext != NULL)
				pPrec = pPrec->ElNext;
		       }
		  if (pPrec != NULL)
		    {
		       pEl1 = pPrec;
		       if (pEl1->ElTerminal)
			  if (pEl1->ElTypeNumber == PageBreak + 1)
			     if (pEl1->ElViewPSchema == viewSch
				 && pEl1->ElPageType == ColBegin)
			       {
				  colexiste = TRUE;
				  pElCol = pEl1;
				  /* code temporaire : si pas de ColGroup qui precede */
				  /* ce ColBegin, on en ajoute un pour etre conforme au */
				  /* nouveau code */
				  if (!(pEl1->ElPrevious != NULL
					&& pEl1->ElPrevious->ElTypeNumber == PageBreak + 1
					&& pEl1->ElPrevious->ElPageType == ColGroup))
				     /* l'element ColGroup existe, on ne cree rien */
				    {
				       /* on cree l'element ColGroup */
				       pElGrCols = NewSubtree (PageBreak + 1, pEl->ElStructSchema,
							       pDoc, pEl->ElAssocNum, TRUE, TRUE, TRUE, TRUE);
				       InsertElementBefore (pElCol, pElGrCols);
				       pElGrCols->ElPageType = ColGroup;
				       pElGrCols->ElViewPSchema = viewSch;
				       pElGrCols->ElPageNumber = 0;
				       /* numero attribue pour les groupes */
				       beforepEl = TRUE;	/* pour recreer l'image */
				       /* on detruit le pave de pElCol pour */
				       /* le recreer apres pElGrCols */
				       pP = pElCol->ElAbstractBox[view - 1];
				       while (pP != NULL && pP->AbElement == pElCol)
					 {
					    SetDeadAbsBox (pP);
					    ApplyRefAbsBoxSupp (pP, &pAbbR, pDoc);
					    pP = pP->AbNext;
					 }
				    }
				  /* on ajoute une marque colonne gauche si elle */
				  /* n'existe pas deja,  pour revenir */
				  /* a l'ancienne regle apres l'element */
				  if (pEl->ElNext == NULL
				      || pEl->ElNext->ElTypeNumber != PageBreak + 1)
				    {
				       pEl1 = NewSubtree (PageBreak + 1, pEl->ElStructSchema, pDoc,
							  pEl->ElAssocNum, TRUE, TRUE, TRUE, TRUE);
				       InsertElementAfter (pEl, pEl1);
				       pEl1->ElPageType = ColComputed;
				       pEl1->ElViewPSchema = viewSch;
				       pEl1->ElPageNumber = 1;
				       /* numero attribue pour les colonnes gauche */

				       /* on cree une marque groupe de colonnes */
				       pElGr1 = NewSubtree (PageBreak + 1, pEl->ElStructSchema, pDoc,
							    pEl->ElAssocNum, TRUE, TRUE, TRUE, TRUE);
				       InsertElementAfter (pEl, pElGr1);
				       pElGr1->ElPageType = ColGroup;
				       pElGr1->ElViewPSchema = viewSch;
				       pElGr1->ElPageNumber = 0;
				       /* numero attribue pour les groupes */

				    }

			       }
		    }
	       }

	     if (!colexiste &&
		 pEl->ElStructSchema->SsRule[pEl->ElTypeNumber - 1].SrConstruct != CsChoice)
	       {
		  /* on cree une marque de colonne */
		  /* et une marque groupe de colonnes Cols */
		  pElGrCols = NewSubtree (PageBreak + 1, pEl->ElStructSchema,
			     pDoc, pEl->ElAssocNum, TRUE, TRUE, TRUE, TRUE);
		  pElCol = NewSubtree (PageBreak + 1, pEl->ElStructSchema, pDoc,
				   pEl->ElAssocNum, TRUE, TRUE, TRUE, TRUE);
		  if (pElCol != NULL)
		     /* on a cree une marque de colonne */
		    {
		       if (pEl->ElTypeNumber == PageBreak + 1)
			  /* si pEl est une PageBreak on chainepElGrCols et pElCol apres pEl */
			 {
			    InsertElementAfter (pEl, pElGrCols);
			    InsertElementAfter (pElGrCols, pElCol);
			 }
		       else if (pEl->ElParent == NULL)
			  /* si pEl est la racine, on la chaine comme fils de pEl, */
			  /* apres l'element marque page de PgBegin */
			 {
			    pEl1 = pEl->ElFirstChild;
			    if (!pEl1->ElTerminal && !(pEl1->ElLeafType == LtPageColBreak))
			       /* erreur */
			       ;
			    else
			      {
				 while (pEl1 != NULL && pEl1->ElViewPSchema != viewSch
					&& pEl1->ElPageType != PgBegin)
				    pEl1 = pEl1->ElNext;
				 if (pEl1 != NULL)
				   {
				      InsertElementAfter (pEl1, pElGrCols);
				      InsertElementAfter (pElGrCols, pElCol);
				   }
			      }
			 }
		       else
			 {
			    /* insersion avant pEl (comme pour une regle Page) */
			    beforepEl = TRUE;
			    InsertElementBefore (pEl, pElCol);
			    InsertElementBefore (pElCol, pElGrCols);
			    /* on cree une marque colonne et une marque groupe */
			    /* de colonnes apres pour revenir */
			    /* a l'ancienne regle apres l'element */
			    /* si l'element a des suivants */
			    pSuiv = pEl;
			    found = FALSE;
			    while (!found && pSuiv != NULL)
			      {
				 found = (pSuiv->ElNext != NULL);
				 if (!found)
				    pSuiv = pSuiv->ElParent;
			      }
			    if (found)
			      {
				 /* on cree une marque colonne et une marque groupe */
				 /* de colonnes apres pour revenir */
				 /* a l'ancienne regle apres l'element */
				 pEl1 = NewSubtree (PageBreak + 1, pEl->ElStructSchema, pDoc,
				   pEl->ElAssocNum, TRUE, TRUE, TRUE, TRUE);
				 pElGr1 = NewSubtree (PageBreak + 1, pEl->ElStructSchema, pDoc,
				   pEl->ElAssocNum, TRUE, TRUE, TRUE, TRUE);
				 InsertElementAfter (pEl, pElGr1);
				 InsertElementAfter (pElGr1, pEl1);
				 pEl1->ElPageType = ColComputed;
				 pEl1->ElViewPSchema = viewSch;
				 pEl1->ElPageNumber = 1;	/* premiere colonne de la serie */
				 pElGr1->ElPageType = ColGroup;
				 pElGr1->ElViewPSchema = viewSch;
				 pElGr1->ElPageNumber = 0;	/* numero attribue pour les groupes */
			      }
			 }
		       /* on initialise pElCol et pElGrCols */
		       pElCol->ElPageType = ColBegin;
		       pElCol->ElViewPSchema = viewSch;
		       pElCol->ElPageNumber = 1;	/* premiere colonne de la page */
		       pElGrCols->ElPageType = ColGroup;
		       pElGrCols->ElViewPSchema = viewSch;
		       pElGrCols->ElPageNumber = 0;	/* numero attribue pour les groupes */
		    }		/* fin pElCol != NULL */
	       }		/* fin de !colexiste */
	     if (beforepEl)
	       {
		  /* creation des paves : il faut detruire ceux de pEl */
		  /* cf. code de InsereMarque de page.c */
		  pP = pEl->ElAbstractBox[view - 1];
		  /* destruction des paves de l'element pEl */
		  if (pP != NULL)
		     destroyedAb = TRUE;	/* code result */
		  while (pP != NULL && pP->AbElement == pEl)
		    {
		       SetDeadAbsBox (pP);
		       ApplyRefAbsBoxSupp (pP, &pAbbR, pDoc);
		       pP = pP->AbNext;
		    }
		  if (AssocView (pEl))
		    {
		       pP = pDoc->DocAssocRoot[pEl->ElAssocNum - 1]->ElAbstractBox[0];
		       frame = pDoc->DocAssocFrame[pEl->ElAssocNum - 1];
		    }
		  else
		    {
		       pP = pDoc->DocRootElement->ElAbstractBox[view - 1];
		       frame = pDoc->DocViewFrame[view - 1];
		    }
		  if (!(pEl->ElAbstractBox[view - 1])->AbNew)
		     /* on previent le mediateur */
		    {
		       h = 0;
		       ChangeConcreteImage (frame, &h, pP);
		    }
		  /* on nettoie l'image abstraite des paves morts */
		  FreeDeadAbstractBoxes (pP);	/* liberation a partir de la racine car */
		  /* un pave colonne a pu etre detruit */

		  /* cree les paves de la marque de colonne et groupe de colonnes */
		  /* correspondant a la regle Column */
		  pP = AbsBoxesCreate (pElGrCols, pDoc, view, TRUE, TRUE, &complete);
		  if (pElGrCols->ElAbstractBox[view - 1] != NULL)
		     pP = AbsBoxesCreate (pElCol, pDoc, view, TRUE, TRUE, &complete);
	       }		/* fin beforepEl */

	  }			/* fin pEl marque page non debut */
     }
   return destroyedAb;
}

#endif /* __COLPAGE__ */

#ifdef __COLPAGE__
/*----------------------------------------------------------------------
   	ApplyPage 	applique une regle Page				
   	on insere l'element marque page AVANT l'element (sauf racine)	
   	le boolean de result indique si le pave pAb a ete detruit	
  ----------------------------------------------------------------------*/

#ifdef __STDC__
static boolean      ApplyPage (PtrDocument pDoc, PtrAbstractBox pAb, int viewSch, PtrPRule pPRule, FunctionType pageType)

#else  /* __STDC__ */
static boolean      ApplyPage (pDoc, pAb, viewSch, pPRule, pageType)
PtrDocument         pDoc;
PtrAbstractBox      pAb;
int                 viewSch;
PtrPRule            pPRule;
FunctionType        pageType;

#endif /* __STDC__ */

#else  /* __COLPAGE__ */
/*----------------------------------------------------------------------
   	ApplyPage 	applique une regle Page				
  ----------------------------------------------------------------------*/

#ifdef __STDC__
static void         ApplyPage (PtrDocument pDoc, PtrAbstractBox pAb, int viewSch, PtrPRule pPRule, FunctionType pageType)

#else  /* __STDC__ */
static void         ApplyPage (pDoc, pAb, viewSch, pPRule, pageType)
PtrDocument         pDoc;
PtrAbstractBox      pAb;
int                 viewSch;
PtrPRule            pPRule;
FunctionType        pageType;

#endif /* __STDC__ */
#endif /* __COLPAGE__ */

{
   PtrElement          pElPage, pEl, pElChild, pPrec;
   PtrAbstractBox      pP;
   boolean             exitingPage, stop;
   int                 counter;
   PtrPSchema          pSchP;
   PtrElement          pEl1;
   boolean             complete;

#ifdef __COLPAGE__
   PtrAbstractBox      pAbbR;
   int                 frame, h, view;
   boolean             bool, destroyedAb;

#else  /* __COLPAGE__ */
   boolean             cree;

#endif /* __COLPAGE__ */

#ifdef __COLPAGE__
   destroyedAb = FALSE;		/* a priori pas de destruction de paves */
#endif /* __COLPAGE__ */
   if (pPRule->PrViewNum == viewSch)
      /* la regle Page concerne la vue du pave traite' */
     {
#ifdef __COLPAGE__
	view = pAb->AbDocView;
#endif /* __COLPAGE__ */
	pElPage = NULL;
	exitingPage = FALSE;
	pEl = pAb->AbElement;
	/* l'element contient-il deja une marque de page de debut */
	/* d'element pour cette vue ? */
	if (!pEl->ElTerminal)
	  {
	     pElChild = pEl->ElFirstChild;
	     stop = FALSE;
	     do
		if (pElChild == NULL)
		   stop = TRUE;
		else
		  {
		     pEl1 = pElChild;
		     if (pEl1->ElTypeNumber != PageBreak + 1)
			stop = TRUE;
		     else if (pEl1->ElViewPSchema == viewSch && pEl1->ElPageType == PgBegin)
#ifdef __COLPAGE__
			/* on deplace l'element marque page devant l'element */
			if (pEl->ElParent != NULL
			    && (pEl1->ElAbstractBox[view - 1] == NULL))
			   /* sauf si pEl est racine ! */
			   /* et sauf si l'element  MP a deja un pave dans la vue */
			   /* en effet c'est dans le cas ou la construction de */
			   /* l'image se fait en arriere : la destruction des paves */
			   /* ne peut se faire si simplement. On prefere laisser */
			   /* cet element 1er fils, il sera deplace lors d'une autre */
			   /* construction de l'image */
			  {
			     DeleteElement (&pEl1);
			     stop = TRUE;
			  }
			else
			   /* pEl est la racine ou la MP a deja des paves */
			  {
			     pElPage = pEl1;
			     exitingPage = TRUE;
			     stop = TRUE;
			  }
#else  /* __COLPAGE__ */
		       {
			  pElPage = pEl1;
			  exitingPage = TRUE;
			  stop = TRUE;
		       }
#endif /* __COLPAGE__ */
		     else
			/* on saute les eventuelles marque page d'autres vues ? */
			pElChild = pEl1->ElNext;
		  }
	     while (!stop);
	  }
	if (!exitingPage)
	   /* l'element ne contient pas de marque de page en tete */
	   /* l'element est-il precede' par un saut de page identique a */
	   /* celui qu'on veut creer ? */
	  {
	     pPrec = pEl;
	     while (pPrec->ElPrevious == NULL && pPrec->ElParent != NULL)
		pPrec = pPrec->ElParent;
	     pPrec = pPrec->ElPrevious;
	     stop = pPrec == NULL;
	     while (!stop)
		if (pPrec->ElTerminal)
		  {
		     stop = TRUE;
		     /* ignore les saut de pages pour les autres vues */
		     if (pPrec->ElTypeNumber == PageBreak + 1)
#ifdef __COLPAGE__
			/* ainsi que les sauts de colonne */
			if (pPrec->ElViewPSchema != viewSch
			    || pPrec->ElPageType == ColBegin
			    || pPrec->ElPageType == ColComputed
			    || pPrec->ElPageType == ColGroup
			    || pPrec->ElPageType == ColUser)
#else  /* __COLPAGE__ */
			if (pPrec->ElViewPSchema != viewSch)
#endif /* __COLPAGE__ */
			  {
			     pPrec = pPrec->ElPrevious;
			     stop = pPrec == NULL;
			  }
		  }
		else
		  {
		     pPrec = pPrec->ElFirstChild;
		     if (pPrec == NULL)
			stop = TRUE;
		     else
			while (pPrec->ElNext != NULL)
			   pPrec = pPrec->ElNext;
		  }
	     if (pPrec != NULL)
	       {
		  pEl1 = pPrec;
		  if (pEl1->ElTerminal)
		     if (pEl1->ElTypeNumber == PageBreak + 1)
			if (pEl1->ElViewPSchema == viewSch && pEl1->ElPageType == PgBegin)
			  {
			     exitingPage = TRUE;
			     pElPage = pEl1;
			  }
	       }
	  }

	if (!exitingPage &&
	    pEl->ElStructSchema->SsRule[pEl->ElTypeNumber - 1].SrConstruct != CsChoice)
	  {
	     /* on cree une marque de page */
	     pElPage = NewSubtree (PageBreak + 1, pEl->ElStructSchema, pDoc,
				   pEl->ElAssocNum, TRUE, TRUE, TRUE, TRUE);
	     if (pElPage != NULL)
		/* on a cree une marque de page */

		/* le reste de la procedure est different entre les deux versions */
#ifdef __COLPAGE__
		/* on la chaine comme premier fils de l'element si pEl est la racine */
		if (pEl->ElParent == NULL)
		  {
		     InsertFirstChild (pEl, pElPage);
		     /* on l'initialise */
		     pEl1 = pElPage;
		     pEl1->ElPageType = PgBegin;
		     pEl1->ElViewPSchema = viewSch;
		     /* cherche le compteur de pages a appliquer */
		     counter = GetPageCounter (pElPage, pEl1->ElViewPSchema, &pSchP);
		     if (counter > 0)
			/* calcule la valeur du compteur de pages */
			pEl1->ElPageNumber = CounterVal (counter, pElPage->ElStructSchema, pSchP, pElPage,
						       pEl1->ElViewPSchema);
		     else
			/* page non numerotee */
			pEl1->ElPageNumber = 1;
		  }
		else
		   /* insersion avant pEl */
		  {
		     InsertElementBefore (pEl, pElPage);
		     /* on l'initialise */
		     pEl1 = pElPage;
		     pEl1->ElPageType = PgBegin;
		     pEl1->ElViewPSchema = viewSch;
		     /* cherche le compteur de pages a appliquer */
		     counter = GetPageCounter (pElPage, pEl1->ElViewPSchema, &pSchP);
		     if (counter > 0)
			/* calcule la valeur du compteur de pages */
			pEl1->ElPageNumber = CounterVal (counter, pElPage->ElStructSchema, pSchP, pElPage,
						       pEl1->ElViewPSchema);
		     else
			/* page non numerotee */
			pEl1->ElPageNumber = 1;
		     /* creation des paves : il faut detruire ceux de pEl */
		     /* cf. code de InsereMarque de page.c */
		     pP = pEl->ElAbstractBox[view - 1];
		     /* destruction des paves de l'element pEl */
		     destroyedAb = TRUE;	/* code result */
		     while (pP != NULL && pP->AbElement == pEl)
		       {
			  SetDeadAbsBox (pP);
			  ApplyRefAbsBoxSupp (pP, &pAbbR, pDoc);
			  pP = pP->AbNext;
		       }
		     if (!pAb->AbNew)
			/* on previent le mediateur */
		       {
			  if (AssocView (pEl))
			    {
			       pP = (pDoc->DocAssocRoot[pEl->ElAssocNum - 1])->ElAbstractBox[0];
			       frame = pDoc->DocAssocFrame[pEl->ElAssocNum - 1];
			    }
			  else
			    {
			       pP = pDoc->DocRootElement->ElAbstractBox[view - 1];
			       frame = pDoc->DocViewFrame[view - 1];
			    }
			  h = 0;
			  bool = ChangeConcreteImage (frame, &h, pP);
		       }
		     /* on nettoie l'image abstraite des paves morts */
		     FreeDeadAbstractBoxes (pAb->AbEnclosing);
		  }

	     /* TODO quand on traitera les regles recto verso */
	     /*  on verifie que la cardinalite de la page est en accord avec la
	        regle appliquee */
	     PagePleine (view, pDoc, pElPage, TRUE);
	     if (pElPage != NULL
		 && !IsViewFull (view, pDoc, pElPage))
		/* cree les paves de la marque de page */
		/* correspondant a la regle page */
		/* si la vue n'est pas pleine */
		pP = AbsBoxesCreate (pElPage, pDoc, view, TRUE, TRUE, &complete);
	     /* on met a jour les numeros des pages suivantes */
	     UpdateNumbers (NextElement (pElPage), pElPage, pDoc, TRUE);
	  }			/* fin de !exitingPage */
     }
   return destroyedAb;
}				/* fin de ApplyPage */

#else  /* __COLPAGE__ */
		/* on la chaine comme premier fils de l'element */
	       {
		  InsertFirstChild (pEl, pElPage);
		  /* on l'initialise */
		  pEl1 = pElPage;
		  pEl1->ElPageType = PgBegin;
		  pEl1->ElViewPSchema = viewSch;
		  /* cherche le compteur de pages a appliquer */
		  counter = GetPageCounter (pElPage, pEl1->ElViewPSchema, &pSchP);
		  if (counter > 0)
		     /* calcule la valeur du compteur de pages */
		     pEl1->ElPageNumber = CounterVal (counter, pElPage->ElStructSchema, pSchP, pElPage,
						      pEl1->ElViewPSchema);
		  else
		     /* page non numerotee */
		     pEl1->ElPageNumber = 1;
		  /* faut-il creer les paves de la marque de page ? */
		  cree = TRUE;	/* a priori, on les cree */
		  if (pElPage->ElNext != NULL)
		     /* la marque de page a un element suivant */
		    {
		       pP = pElPage->ElNext->ElAbstractBox[pAb->AbDocView - 1];
		       if (pP == NULL)
			  /* l'element suivant la marque de page n'a pas de pave */
			  /* dans la vue,on ne cree pas les paves de la marque page */
			  cree = FALSE;
		       else
			  /* on ne cree les paves de la marque de page que le pave */
			  /* de l'element suivant est complete en tete. */
			  cree = !pP->AbTruncatedHead;
		    }
		  if (cree)
		     /* cree les paves de la marque de page */
		     pP = AbsBoxesCreate (pElPage, pDoc, pAb->AbDocView, TRUE, TRUE, &complete);
		  /* on met a jour les numeros des pages suivantes */
		  UpdateNumbers (NextElement (pElPage), pElPage, pDoc, TRUE);
	       }
	  }

	/* TODO quand on traitera les regles recto verso */
	/* on verifie que la cardinalite de la page est en accord avec la regle
	   appliquee */
     }
}
#endif /* __COLPAGE__ */


/*----------------------------------------------------------------------
   	FindAbsBox cherche dans le sous-arbre (racine comprise)		
   		du pave pointe' par pAb un pave de presentation du type	
   		NType defini dans le schema de presentation pointe' par	
   		pSchP. Si NType=0 on cherche un pave de presentation de	
   		nom presBoxName et on ignore pSchP.				
   		Retourne Vrai si un tel pave existe, et dans ce cas pAb	
   		pointe sur le pave found'				
  ----------------------------------------------------------------------*/

#ifdef __STDC__
static boolean      FindAbsBox (int Ntype, PtrPSchema pSchP, Name presBoxName, PtrAbstractBox * pAb)

#else  /* __STDC__ */
static boolean      FindAbsBox (Ntype, pSchP, presBoxName, pAb)
int                 Ntype;
PtrPSchema          pSchP;
Name                presBoxName;
PtrAbstractBox     *pAb;

#endif /* __STDC__ */

{
   boolean             result;
   PtrAbstractBox      pAbbCur;

   result = FALSE;
   if ((*pAb)->AbPresentationBox)
      if ((*pAb)->AbLeafType == LtText)
	 if (Ntype != 0)
	    result = strcmp ((*pAb)->AbPSchema->PsPresentBox[(*pAb)->AbTypeNum - 1].PbName,
			     pSchP->PsPresentBox[Ntype - 1].PbName) == 0;
	 else
	    result = strcmp ((*pAb)->AbPSchema->PsPresentBox[(*pAb)->AbTypeNum - 1].PbName,
			     presBoxName) == 0;
   if (!result)
      if ((*pAb)->AbFirstEnclosed == NULL)
	 result = FALSE;
      else
	{
	   pAbbCur = (*pAb)->AbFirstEnclosed;
	   result = FindAbsBox (Ntype, pSchP, presBoxName, &pAbbCur);
	   while (!result && pAbbCur->AbNext != NULL)
	     {
		pAbbCur = pAbbCur->AbNext;
		result = FindAbsBox (Ntype, pSchP, presBoxName, &pAbbCur);
	     }
	   if (result)
	      *pAb = pAbbCur;
	}
   return result;
}



/*----------------------------------------------------------------------
   	SearchElCrPresBoxCopy	cherche dans le sous arbre de l'element pointe' par pEl	
   		(racine comprise) un element auquel est associee une	
   		regle de presentation creant une boite du type presBoxType	
   		definie dans le schema de presentation pointe par pSchP.
   		Si presBoxType=0, on cherche une regle creant un pave de nom	
   		presBoxName et au retour, pSchP contient un pointeur sur le	
   		schema de presentation ou est definie la boite et presBoxType	
   		contient le numero de type de cette boite.		
   		Retourne Vrai si un tel element existe et dans ce cas,	
   		pEl pointe sur l'element trouve'.			
  ----------------------------------------------------------------------*/
#ifdef __STDC__
static boolean      SearchElCrPresBoxCopy (int *presBoxType, PtrPSchema * pSchP, PtrSSchema * pSchS, Name presBoxName, PtrElement * pEl)
#else  /* __STDC__ */
static boolean      SearchElCrPresBoxCopy (presBoxType, pSchP, pSchS, presBoxName, pEl)
int                *presBoxType;
PtrPSchema         *pSchP;
PtrSSchema         *pSchS;
Name                presBoxName;
PtrElement         *pEl;
#endif /* __STDC__ */

{
   boolean             result, stop;
   PtrElement          pE1;
   PtrPSchema          pSP;
   PtrSSchema          pSS;
   PtrPRule            pPRuleCre;
   PtrAttribute        pA;
   PtrPRule            pPRule;

   result = FALSE;
   /* cherche toutes les regles de  creation de cet element */
   pPRuleCre = GlobalSearchRulepEl (*pEl, &pSP, &pSS, 0, NULL, 1, PtFunction, FnAny, FALSE, FALSE, &pA);
   stop = FALSE;
   do
      if (pPRuleCre == NULL)
	 /* il n' y a plus de regles */
	 stop = TRUE;
      else if (pPRuleCre->PrType != PtFunction)
	 /* il n'y a plus de regle fonction de presentation */
	 stop = TRUE;
      else
	{
	   /* la regle est une fonction de presentation */
	   pPRule = pPRuleCre;
	   if (pPRule->PrPresFunction == FnCreateBefore
	       || pPRule->PrPresFunction == FnCreateWith
	       || pPRule->PrPresFunction == FnCreateAfter
	       || pPRule->PrPresFunction == FnCreateFirst
	       || pPRule->PrPresFunction == FnCreateLast)
	      /* c'est une regle de creation */
	      if (*presBoxType != 0)
		{
		   result = pPRule->PrPresBox[0] == *presBoxType;
		   if (result)
		      result = strcmp (pSS->SsName, (*pSchS)->SsName) == 0;
		   /* on supprime le test sur l'egalite des schemas P et on teste uniquement */
		   /* les schemas de structure : cela permet a des chapitres de se referencer */
		   /* mutuellement meme si leur schema de presentation different legerement */
		   /* il faut que les schemas P aient les memes boites de presentation utilisees */
		   /* en copie */
		}
	      else
		 result = strcmp (pSP->PsPresentBox[pPRule->PrPresBox[0] - 1].PbName, presBoxName)
		    == 0;
	   if (result && (pSP != *pSchP))
	      /* retourne le schema de presentation et le */
	      /* numero de type de la boite creee */
	     {
		*pSchP = pSP;
		*pSchS = pSS;
		*presBoxType = pPRule->PrPresBox[0];
	     }

	   if (!result)
	      pPRuleCre = pPRule->PrNextPRule;
	}
   while (!stop && !result);
   if (!result)
      /* ce n'est pas l'element cherche', on cherche dans ses */
      /* descendants */
      if (!(*pEl)->ElTerminal && (*pEl)->ElFirstChild != NULL)
	{
	   pE1 = (*pEl)->ElFirstChild;
	   result = SearchElCrPresBoxCopy (presBoxType, pSchP, pSchS, presBoxName, &pE1);
	   while (!result && pE1->ElNext != NULL)
	     {
		pE1 = pE1->ElNext;
		result = SearchElCrPresBoxCopy (presBoxType, pSchP, pSchS, presBoxName, &pE1);
	     }
	   if (result)
	      *pEl = pE1;
	}
   return result;
}



/*----------------------------------------------------------------------
   	CopyLeaves  copie dans le pave pAb le contenu de toutes les	
   		feuilles de texte du sous-arbre de l'element pointe'	
   		par pEC							
  ----------------------------------------------------------------------*/

#ifdef __STDC__
static void         CopyLeaves (PtrElement pEC, PtrAbstractBox * pAb, PtrTextBuffer * pBuffPrec)

#else  /* __STDC__ */
static void         CopyLeaves (pEC, pAb, pBuffPrec)
PtrElement          pEC;
PtrAbstractBox     *pAb;
PtrTextBuffer      *pBuffPrec;

#endif /* __STDC__ */

{
   PtrTextBuffer       pBuffE;
   PtrAbstractBox      pAbb1;
   PtrTextBuffer       pBuffP;

   if (!pEC->ElTerminal)
      /* ce n'est pas une feuille, on traite tous les fils */
     {
	pEC = pEC->ElFirstChild;
	while (pEC != NULL)
	  {
	     CopyLeaves (pEC, pAb, pBuffPrec);
	     pEC = pEC->ElNext;
	  }
     }
   else
      /* c'est une feuille */
   if (pEC->ElLeafType == LtText)
      /* c'est une feuille de texte, on la copie */
     {
	pBuffE = pEC->ElText;
	/* pointeur sur le buffer de */
	/* l'element a copier */
	while (pBuffE != NULL)
	   /* copie les buffers de l'element */
	  {
	     pAbb1 = *pAb;
	     GetTextBuffer (&pBuffP);
	     /* acquiert un buffer pour la copie */
	     /* chaine le buffer de la copie */
	     if (*pBuffPrec == NULL)
	       {
		  pAbb1->AbText = pBuffP;
		  /* c'est le 1er buffer */
		  pAbb1->AbLanguage = pEC->ElLanguage;
	       }
	     else
	       {
		  pBuffP->BuPrevious = *pBuffPrec;
		  (*pBuffPrec)->BuNext = pBuffP;
	       }
	     strncpy (pBuffP->BuContent, pBuffE->BuContent, THOT_MAX_CHAR);
	     /* copie le contenu */
	     pBuffP->BuLength = pBuffE->BuLength;
	     /* copie la longueur */
	     pAbb1->AbVolume += pBuffP->BuLength;
	     *pBuffPrec = pBuffP;
	     pBuffE = pBuffE->BuNext;
	  }
     }
}



/*----------------------------------------------------------------------
   	SearchElInSubTree cherche dans le sous-arbre dont la racine est	
   		pointe'e par pElRoot un element de numero de type elType	
   		defini dans le schema de structure pSS, si typeName est	
   		nul, de nom de type typeName sinon.			
   		Retourne un pointeur sur l'element found' ou NULL si pas
   		found'							
  ----------------------------------------------------------------------*/


#ifdef __STDC__
static PtrElement   SearchElInSubTree (PtrElement pElRoot, int elType, PtrSSchema pSS, Name typeName)

#else  /* __STDC__ */
static PtrElement   SearchElInSubTree (pElRoot, elType, pSS, typeName)
PtrElement          pElRoot;
int                 elType;
PtrSSchema          pSS;
Name                typeName;

#endif /* __STDC__ */

{
   PtrElement          pEC, pElChild;

   pEC = NULL;			/* a priori on n'a pas found' */
   if (typeName[0] != '\0')
      /* on compare les noms de type */
     {
	if (strcmp (typeName, pElRoot->ElStructSchema->SsRule[pElRoot->ElTypeNumber - 1].SrName) == 0)
	   pEC = pElRoot;
     }
   else
      /* on compare les numero de type et code de schema de structure */
      if (pElRoot->ElTypeNumber == elType
	  && pElRoot->ElStructSchema->SsCode == pSS->SsCode)
      /* c'est l'element cherche' */
      pEC = pElRoot;
   if (pEC == NULL)
      if (!pElRoot->ElTerminal)
	{
	   /* on cherche parmi les fils de l'element */
	   pElChild = pElRoot->ElFirstChild;
	   while (pElChild != NULL && pEC == NULL)
	     {
		pEC = SearchElInSubTree (pElChild, elType, pSS, typeName);
		pElChild = pElChild->ElNext;
	     }
	}
   return pEC;
}

/*----------------------------------------------------------------------
  ----------------------------------------------------------------------*/
#ifdef __STDC__
static PtrPRule     GetRuleCopy (PtrPRule pPRule)
#else  /* __STDC__ */
static PtrPRule     GetRuleCopy (pPRule)
PtrPRule            pPRule;

#endif /* __STDC__ */
{
   boolean             found;

   found = FALSE;
   while (pPRule != NULL && !found)
     {
	if (pPRule->PrType == PtFunction)
	   if (pPRule->PrPresFunction == FnCopy)
	      found = TRUE;
	if (!found)
	  {
	     pPRule = pPRule->PrNextPRule;
	     if (pPRule != NULL)
		if (pPRule->PrType > PtFunction)
		   pPRule = NULL;
	  }
     }
   if (!found)
      pPRule = NULL;
   return pPRule;
}


/*----------------------------------------------------------------------
   	ApplyCopy applique une regle de copie.				
   		  Procedure appelee aussi dans modif.c			
  ----------------------------------------------------------------------*/
#ifdef __STDC__
void                ApplyCopy (PtrDocument pDoc, PtrPRule pPRule, PtrAbstractBox pAb, boolean withDescCopy)
#else  /* __STDC__ */
void                ApplyCopy (pDoc, pPRule, pAb, withDescCopy)
PtrDocument         pDoc;
PtrPRule            pPRule;
PtrAbstractBox      pAb;
boolean             withDescCopy;

#endif /* __STDC__ */
{
   PtrElement          pE, pElSv;
   PtrAbstractBox      pAbbCur;
   int                 view, i;
   boolean             found;
   PtrPSchema          pSchP;
   PtrSSchema          pSchS;
   PtrTextBuffer       pBuffPrec;
   int                 boxType;
   Name                boxName;
   DocumentIdentifier  IDoc;
   PtrDocument         pDocRef;
   PtrElement          pEl1;
   PtrAbstractBox      pAbb1;
   PresentationBox    *pBo1;
   PtrCopyDescr        pDC;
   PtrPRule            pPRule1;
   PtrAttribute        pAttr;
   boolean             Ref;

#ifdef __COLPAGE__
   PtrElement          pEl;

#endif /* __COLPAGE__ */

   pEl1 = pAb->AbElement;
   pE = NULL;
   Ref = FALSE;
   if (pEl1->ElStructSchema->SsRule[pEl1->ElTypeNumber - 1].SrConstruct == CsReference)
     {
	/* la regle Copy s'applique a un pave' d'un element reference */
	Ref = TRUE;
	/* cherche l'element qui est reference' */
	pE = ReferredElement (pEl1->ElReference, &IDoc, &pDocRef);
     }
   else if (pAb->AbPresentationBox)
      if (pAb->AbCreatorAttr != NULL)
	 if (pAb->AbCreatorAttr->AeAttrType == AtReferenceAttr)
	    /* la regle Copy s'applique a un pave' de presentation */
	    /* cree' par un attribut reference */
	   {
	      Ref = TRUE;
	      /* cherche l'element qui est reference' par l'attribut */
	      pE = ReferredElement (pAb->AbCreatorAttr->AeAttrReference, &IDoc, &pDocRef);
	   }
   if (Ref)
     {
	/* c'est une copie par reference */
	if (pE != NULL)
	   /* l'element qui est reference' existe, il est pointe' par pE */
	   if (pPRule->PrElement)
	      /* il faut copier le contenu d'un element structure' contenu */
	      /* dans l'element reference'. On cherche cet element */
	      pE = SearchElInSubTree (pE, pPRule->PrPresBox[0], pEl1->ElStructSchema,
				      pPRule->PrPresBoxName);
	   else
	      /* il faut copier une boite de presentation */
	      /* prend le schema de presentation qui s'applique a la reference */
	     {
		SearchPresSchema (pAb->AbElement, &pSchP, &i, &pSchS);
		if (pPRule->PrNPresBoxes == 0)
		   /* la boite de presentation a copier est definie par son nom */
		  {
		     boxType = 0;
		     strncpy (boxName, pPRule->PrPresBoxName, MAX_NAME_LENGTH);
		     /* nom de la boite a cherche */
		  }
		else
		   /* la boite de presentation est definie par son numero de type */
		   boxType = pPRule->PrPresBox[0];
		/* numero de type de la boite */
		/* cherche dans toutes les vues une boite du type de celle a */
		/* copier parmi les paves de cet element et de ses descendants */
		view = 0;
		found = FALSE;
		do
		  {
		     view++;
		     /* premier pave de l'element dans cette vue */
		     pAbbCur = pE->ElAbstractBox[view - 1];
		     if (pAbbCur != NULL)
			do
			  {
			     found = FindAbsBox (boxType, pSchP, boxName, &pAbbCur);
			     if (!found)
			       {
				  pAbbCur = pAbbCur->AbNext;
				  if (pAbbCur != NULL)
				     if (pAbbCur->AbElement != pE)
					pAbbCur = NULL;
			       }
			  }
			while (!found && pAbbCur != NULL);
		  }
		while (!found && view < MAX_VIEW_DOC);
		if (found)
		   /* on a found' le pave a copier, on le copie */
		  {
		     pAbb1 = pAb;
		     pAbb1->AbLeafType = LtText;
		     pAbb1->AbVolume = pAbbCur->AbVolume;
		     if (pAbbCur->AbText != NULL)
			*pAbb1->AbText = *pAbbCur->AbText;
		     pAbb1->AbLanguage = pAbbCur->AbLanguage;
		     pAbb1->AbCanBeModified = FALSE;
		  }
		else
		   /* on n'a pas trouve le pave a copier */
		if (!IsASavedElement (pE))
		   /* on ne fait rien si l'element reference' est dans le buffer */
		   /* de Couper-Coller */
		   /* on cherche dans le sous-arbre abstrait de l'element */
		   /* reference' un element qui cree la boite a copier */
		  {
		     /*pElSrce = pE; */
		     found = SearchElCrPresBoxCopy (&boxType, &pSchP, &pSchS, boxName, &pE);
		     if (found)
			/* on a trouve' l'element pE qui cree la boite a copier */
		       {
			  pBo1 = &pSchP->PsPresentBox[boxType - 1];
			  if (pBo1->PbContent == ContVariable)
			     /* on fait comme si le pave appartenait a l'element */
			     /* a copier */
			    {
			       pElSv = pAb->AbElement;
			       pAb->AbElement = pE;
			       found = NewVariable (pBo1->PbContVariable, pSchS, pSchP,
						    pAb, pDoc);
			       /* on retablit le pointeur correct */
			       pAb->AbElement = pElSv;
			    }
			  if (pBo1->PbContent == FreeContent)
			     /* le contenu de la boite de presentation a copier */
			     /* est lui-meme defini par une regle FnCopy */
			    {
			       /* on cherche cette regle FnCopy parmi les regles de */
			       /* presentation de la boite de presentation a copier */
			       pPRule1 = GetRuleCopy (pBo1->PbFirstPRule);
			       if (pPRule1 != NULL)
				  /* on a found' la regle FnCopy. On l'applique en */
				  /* faisant comme si le pave appartenait a l'element */
				  /* qui cree la boite de presentation a copier */
				 {
				    pElSv = pAb->AbElement;
				    pAb->AbElement = pE;
				    ApplyCopy (pDoc, pPRule1, pAb, TRUE);
				    pAb->AbElement = pElSv;
				    pE = NULL;
				 }
			    }
		       }
		  }
	     }
     }
   else
      /* ce n'est pas une copie par reference */
   if (pPRule->PrElement)
     {
	/*cherche d'abord l'element a copier a l'interieur de l'element copieur */
	pE = SearchElInSubTree (pAb->AbElement, pPRule->PrPresBox[0],
				pEl1->ElStructSchema, pPRule->PrPresBoxName);

	if (pE == NULL)
	   /* on n'a pas found' l'element a copier */
	   if (pEl1->ElTypeNumber == PageBreak + 1)
	      if (pEl1->ElPageType == PgBegin)
#ifdef __COLPAGE__
		 /* la marque de page est placee devant l'element qui porte */
		 /* la regle de creation de marque page */
		 /* sauf dans le cas ou la marque de page a ete cree par la racine */
		{
		   pEl = pEl1;
		   /* on saute les eventuelles autres marques de pages */
		   /*  (des autres vues) et marques de colonnes */
		   while (pEl != NULL
			  && pEl->ElTypeNumber == PageBreak + 1)
		      pEl = pEl->ElNext;
		   /* pEl est l'element qui a cree la marque de page */
		   /*  On cherche dans cet element */
		   if (pEl != NULL)
		      pE = SearchElInSubTree (pEl, pPRule->PrPresBox[0],
				pEl->ElStructSchema, pPRule->PrPresBoxName);
		   if (pE == NULL)
		      /* si on n'a pas found pE, c'est que c'etait une marque */
		      /* page qui avait ete genere par la racine : elle a ete */
		      /* placee comme premier fils : on applique lors le code */
		      /* de la V3 (recherche sur le pere)  */
		      pE = SearchElInSubTree (pEl1->ElParent, pPRule->PrPresBox[0],
			       pEl1->ElStructSchema, pPRule->PrPresBoxName);
		}
#else  /* __COLPAGE__ */
		 /* on travaille pour une marque de page qui est engendree par */
		 /* le debut d'un element. On cherche dans cet element */
		 pE = SearchElInSubTree (pEl1->ElParent, pPRule->PrPresBox[0],
			       pEl1->ElStructSchema, pPRule->PrPresBoxName);
#endif /* __COLPAGE__ */
	/* si on n'a pas found', on cherche en arriere l'element a copier */
	if (pE == NULL)
	   if (pPRule->PrNPresBoxes > 0)
	      /* la boite a copier est definie par son numero de type */
	      pE = BackSearchTypedElem (pAb->AbElement, pPRule->PrPresBox[0], pEl1->ElStructSchema);
/*        else */
	/* la boite a copier est definie par son nom */
	/* non implemente' */
     }
   if (pPRule->PrElement && pE != NULL)
      /* il faut copier l'element structure' pointe' par pE */
     {
	pAbb1 = pAb;
	/* initialise le pave */
	pAbb1->AbLeafType = LtText;
	pAbb1->AbCanBeModified = FALSE;
	pAbb1->AbVolume = 0;
	pBuffPrec = NULL;
	/* pas de buffer precedent */
	if (TypeHasException (1207, pAbb1->AbElement->ElTypeNumber, pAbb1->AbElement->ElStructSchema))
	  {
	     if (ThotLocalActions[T_indexcopy] != NULL)
		(*ThotLocalActions[T_indexcopy]) (pE, &pAb, &pBuffPrec);
	  }
	else
	  {
	     /* si l'element a copier est lui-meme une reference qui copie un */
	     /* autre element, c'est cet autre element qu'on copie */
	     pPRule1 = NULL;
	     if (pE->ElStructSchema->SsRule[pE->ElTypeNumber - 1].SrConstruct == CsReference)
	       {
		  pPRule1 = GlobalSearchRulepEl (pE, &pSchP, &pSchS, 0, NULL, 1, PtFunction, FnAny, FALSE, FALSE, &pAttr);
		  pPRule1 = GetRuleCopy (pPRule1);
	       }
	     if (pPRule1 == NULL)
		/* copie simplement toutes les feuilles de texte de pE */
		CopyLeaves (pE, &pAb, &pBuffPrec);
	     else
		/* applique la regle de copie transitive */
	       {
		  pElSv = pAb->AbElement;
		  pAb->AbElement = pE;
		  ApplyCopy (pDoc, pPRule1, pAb, FALSE);
		  pAb->AbElement = pElSv;
	       }
	  }
	if (withDescCopy)
	  {
	     /* ajoute a l'element copie' un descripteur d'element copie' */
	     GetDescCopy (&pDC);
	     pDC->CdCopiedAb = pAb;
	     pDC->CdCopiedElem = pE;
	     pDC->CdCopyRule = pPRule;
	     pDC->CdNext = pE->ElCopyDescr;
	     pDC->CdPrevious = NULL;
	     if (pDC->CdNext != NULL)
		pDC->CdNext->CdPrevious = pDC;
	     pE->ElCopyDescr = pDC;
	     pAbb1->AbCopyDescr = pDC;
	  }
     }
}


/*----------------------------------------------------------------------
   	ApplyRule   applique au pave pointe par pAb la regle pointee par
   		pPRule dans le schema de presentation pointe par pSchP.	
   		Si pAttr n'est pas NULL, c'est un pointeur sur le bloc	
   		attribut auquel correspond la regle a appliquer.	
   		Retourne true si la regle a ete appliquee ou ne pourra	
   		jamais etre appliquee, false si elle n'a pas pu etre	
   		appliquee mais qu'elle pourra etre appliquee quand	
   		d'autres paves seront construits.			
	   le boolean de destroyedAb indique si le pave pAb a ete detruit
  ----------------------------------------------------------------------*/
#ifdef __COLPAGE__
#ifdef __STDC__
boolean             ApplyRule (PtrPRule pPRule, PtrPSchema pSchP, PtrAbstractBox pAb, PtrDocument pDoc, PtrAttribute pAttr, boolean * destroyedAb)
#else  /* __STDC__ */
boolean             ApplyRule (pPRule, pSchP, pAb, pDoc, pAttr, destroyedAb)
PtrPRule            pPRule;
PtrPSchema          pSchP;
PtrAbstractBox      pAb;
PtrDocument         pDoc;
PtrAttribute        pAttr;
boolean            *destroyedAb;

#endif /* __STDC__ */
#else  /* __COLPAGE__ */
#ifdef __STDC__
boolean             ApplyRule (PtrPRule pPRule, PtrPSchema pSchP, PtrAbstractBox pAb, PtrDocument pDoc, PtrAttribute pAttr)
#else  /* __STDC__ */
boolean             ApplyRule (pPRule, pSchP, pAb, pDoc, pAttr)
PtrPRule            pPRule;
PtrPSchema          pSchP;
PtrAbstractBox      pAb;
PtrDocument         pDoc;
PtrAttribute        pAttr;

#endif /* __STDC__ */
#endif /* __COLPAGE__ */
{
  boolean             appl;
  TypeUnit            unit;
  AbPosition          Posit;
  char                c;
  int                 viewSch, i;
  PtrAbstractBox      pAbb1;
  PresConstant	      *pConst;
  char		       fname[MAX_PATH];
  PathBuffer	       directoryName;

#ifdef __COLPAGE__
  *destroyedAb = FALSE;
#else  /* __COLPAGE__ */
  boolean             insidePage, afterPageBreak;
  AbPosition         *pPavP1;
#endif /* __COLPAGE__ */

  appl = FALSE;
  if (pPRule != NULL && pAb != NULL)
    if (pAb->AbElement != NULL)
      {
	pAbb1 = pAb;
	viewSch = AppliedView (pAbb1->AbElement, pAttr, pDoc, pAbb1->AbDocView);
	switch (pPRule->PrType)
	  {
	  case PtWidth:
	    ApplyDim (&pAbb1->AbWidth, pAb, pSchP, pAttr, &appl, pPRule, pDoc);
	    break;
	  case PtHeight:
	    ApplyDim (&pAbb1->AbHeight, pAb, pSchP, pAttr, &appl, pPRule, pDoc);
	    /* traitement special pour le debordement vertical des cellules */
	    /* de tableau etendues verticalement */
	    if (ThotLocalActions[T_vertspan] != NULL)
	      (*ThotLocalActions[T_vertspan]) (pPRule, pAb);
	    break;
	  case PtVisibility:
	    pAbb1->AbVisibility = IntegerRule (pPRule, pAbb1->AbElement,
					       pAbb1->AbDocView, &appl, &unit, pAttr);
	    if (!appl && pAbb1->AbElement->ElParent == NULL)
	      /* Pas de regle pour la racine, on met la valeur par defaut */
	      {
		pAbb1->AbVisibility = 10;
		appl = TRUE;
	      }
	    break;
	  case PtDepth:
	    pAbb1->AbDepth = IntegerRule (pPRule, pAbb1->AbElement, pAbb1->AbDocView,
					  &appl, &unit, pAttr);
	    if (!appl && pAbb1->AbElement->ElParent == NULL)
	      /* Pas de regle pour la racine, on met la valeur par defaut */
	      {
		pAbb1->AbDepth = 0;
		appl = TRUE;
	      }
	    break;
	  case PtFillPattern:
	    pAbb1->AbFillPattern = IntegerRule (pPRule, pAbb1->AbElement,
						pAbb1->AbDocView, &appl, &unit, pAttr);
	    if (!appl && pAbb1->AbElement->ElParent == NULL)
	      /* Pas de regle pour la racine, on met la valeur par defaut */
	      {
		pAbb1->AbFillPattern = 0;
		appl = TRUE;
	      }
	    break;
	  case PtBackground:
	    pAbb1->AbBackground = IntegerRule (pPRule, pAbb1->AbElement,
					       pAbb1->AbDocView, &appl, &unit, pAttr);
	    if (!appl && pAbb1->AbElement->ElParent == NULL)
	      /* Pas de regle pour la racine, on met la valeur par defaut */
	      {
		pAbb1->AbBackground = 0;
		appl = TRUE;
	      }
	    break;
	  case PtForeground:
	    pAbb1->AbForeground = IntegerRule (pPRule, pAbb1->AbElement,
					       pAbb1->AbDocView, &appl, &unit, pAttr);
	    if (!appl && pAbb1->AbElement->ElParent == NULL)
	      /* Pas de regle pour la racine, on met la valeur par defaut */
	      {
		pAbb1->AbForeground = 1;
		appl = TRUE;
	      }
	    break;
	  case PtLineStyle:
	    pAbb1->AbLineStyle = CharRule (pPRule, pAbb1->AbElement,
					   pAbb1->AbDocView, &appl);
	    if (!appl && pAbb1->AbElement->ElParent == NULL)
	      {
		pAbb1->AbLineStyle = 'S';
		appl = TRUE;
	      }
	    break;
	  case PtFont:
	    pAbb1->AbFont = CharRule (pPRule, pAbb1->AbElement, pAbb1->AbDocView,
				      &appl);
	    if (!appl && pAbb1->AbElement->ElParent == NULL)
	      {
		pAbb1->AbFont = 'T';
		appl = TRUE;
	      }
	    if (pAbb1->AbFont >= 'a' && pAbb1->AbFont <= 'z')
	      /* on n'utilise que des majuscules pour les noms de police */
	      pAbb1->AbFont = (char) ((int) (pAbb1->AbFont) - 32);
	    break;
	  case PtAdjust:
	    pAbb1->AbAdjust = AlignRule (pPRule, pAbb1->AbElement,
					 pAbb1->AbDocView, &appl);
	    if (!appl && pAbb1->AbElement->ElParent == NULL)
	      /* Pas de regle pour la racine, on met la valeur par defaut */
	      {
		pAbb1->AbAdjust = AlignLeft;
		appl = TRUE;
	      }
	    break;
	  case PtJustify:
	    pAbb1->AbJustify = BoolRule (pPRule, pAbb1->AbElement,
					 pAbb1->AbDocView, &appl);
	    if (!appl && pAbb1->AbElement->ElParent == NULL)
	      /* Pas de regle pour la racine, on met la valeur par defaut */
	      {
		pAbb1->AbJustify = FALSE;
		appl = TRUE;
	      }
	    break;
	  case PtHyphenate:
	    pAbb1->AbHyphenate = BoolRule (pPRule, pAbb1->AbElement,
					   pAbb1->AbDocView, &appl);
	    if (!appl && pAbb1->AbElement->ElParent == NULL)
	      /* Pas de regle pour la racine, on met la valeur par defaut */
	      {
		pAbb1->AbHyphenate = FALSE;
		appl = TRUE;
	      }
	    break;
	  case PtVertOverflow:
	    pAbb1->AbVertEnclosing = !BoolRule (pPRule,
						pAbb1->AbElement,
						pAbb1->AbDocView, &appl);
	    break;
	  case PtHorizOverflow:
	    pAbb1->AbHorizEnclosing = !BoolRule (pPRule,
						 pAbb1->AbElement,
						 pAbb1->AbDocView, &appl);
	    break;
	  case PtStyle:
	    c = CharRule (pPRule, pAbb1->AbElement, pAbb1->AbDocView, &appl);
	    if (!appl && pAbb1->AbElement->ElParent == NULL)
	      /* Pas de regle pour la racine, on met la valeur par defaut */
	      {
		pAbb1->AbHighlight = 0;
		appl = TRUE;
	      }
	    else
	      switch (c)
		{
		case 'I':
		  pAbb1->AbHighlight = 2;
		  break;
		case 'B':
		  pAbb1->AbHighlight = 1;
		  break;
		case 'O':/*iso */
		  pAbb1->AbHighlight = 3;
		  break;
		case 'G':
		  pAbb1->AbHighlight = 4;
		  break;
		case 'Q':
		  pAbb1->AbHighlight = 5;
		  break;
		default:
		  pAbb1->AbHighlight = 0;
		  break;
		}
	    break;
	  case PtUnderline:
	    c = CharRule (pPRule, pAbb1->AbElement, pAbb1->AbDocView, &appl);
	    if (!appl && pAbb1->AbElement->ElParent == NULL)
	      /* Pas de regle pour la racine, on met la valeur par defaut */
	      {
		pAbb1->AbUnderline = 0;
		appl = TRUE;
	      }
	    else
	      switch (c)
		{
		case 'C':
		  pAbb1->AbUnderline = 3;
		  break;
		case 'O':
		  pAbb1->AbUnderline = 2;
		  break;
		case 'U':
		  pAbb1->AbUnderline = 1;
		  break;
		default:
		  pAbb1->AbUnderline = 0;
		  break;
		}
	    break;
	  case PtThickness:
	    c = CharRule (pPRule, pAbb1->AbElement, pAbb1->AbDocView, &appl);
	    if (!appl && pAbb1->AbElement->ElParent == NULL)
	      /* Pas de regle pour la racine, on met la valeur par defaut */
	      {
		pAbb1->AbThickness = 0;
		appl = TRUE;
	      }
	    else
	      switch (c)
		{
		case 'T':
		  pAbb1->AbThickness = 1;
		  break;
		default:
		  pAbb1->AbThickness = 0;
		  break;
		}
	    break;
	  case PtSize:
	    /* on applique la regle de taille */
	    pAbb1->AbSize = IntegerRule (pPRule, pAbb1->AbElement,
					 pAbb1->AbDocView, &appl, &unit, pAttr);
	    if (appl)
	      pAbb1->AbSizeUnit = unit;
	    else if (pAbb1->AbElement->ElParent == NULL)
	      /* c'est la racine, on met a priori la valeur par defaut */
	      {
		pAbb1->AbSize = 3;
		pAbb1->AbSizeUnit = UnRelative;
		appl = TRUE;
	      }
	    break;
	  case PtIndent:
	    pAbb1->AbIndent = IntegerRule (pPRule, pAbb1->AbElement,
					   pAbb1->AbDocView, &appl, &unit, pAttr);
	    pAbb1->AbIndentUnit = unit;
	    if (!appl && pAbb1->AbElement->ElParent == NULL)
	      /* Pas de regle pour la racine, on met la valeur par defaut */
	      {
		pAbb1->AbIndent = 0;
		appl = TRUE;
	      }
	    break;
	  case PtLineSpacing:
	    pAbb1->AbLineSpacing = IntegerRule (pPRule, pAbb1->AbElement,
						pAbb1->AbDocView, &appl, &unit, pAttr);
	    pAbb1->AbLineSpacingUnit = unit;
	    if (!appl && pAbb1->AbElement->ElParent == NULL)
	      /* Pas de regle pour la racine, on met la valeur par defaut */
	      {
		pAbb1->AbLineSpacing = 10;
		pAbb1->AbLineSpacingUnit = UnRelative;
		appl = TRUE;
	      }
	    break;
	  case PtLineWeight:
	    pAbb1->AbLineWeight = IntegerRule (pPRule, pAbb1->AbElement,
					       pAbb1->AbDocView, &appl, &unit, pAttr);
	    pAbb1->AbLineWeightUnit = unit;
	    if (!appl && pAbb1->AbElement->ElParent == NULL)
	      /* Pas de regle pour la racine, on met la valeur par defaut */
	      {
		pAbb1->AbLineWeight = 1;
		pAbb1->AbLineWeightUnit = UnPoint;
		appl = TRUE;
	      }
	    break;
	  case PtVertRef:
	    Posit = pAbb1->AbVertRef;
	    ApplyPos (&Posit, pPRule->PrPosRule, pPRule, pAttr, pSchP, pAb,
		      pDoc, &appl);
	    pAbb1->AbVertRef = Posit;
	    break;
	  case PtHorizRef:
	    Posit = pAbb1->AbHorizRef;
	    ApplyPos (&Posit, pPRule->PrPosRule, pPRule, pAttr, pSchP, pAb,
		      pDoc, &appl);
	    pAbb1->AbHorizRef = Posit;
	    break;
	  case PtVertPos:
	    /* erreur : ce n'est pas a l'editeur d'interpreter */
	    /* la mise en ligne. On supprime ce code */
#ifdef __COLPAGE__
	    /* changement complete du code */
	    /* plus de cas particulier pour les pages et colonnes */
	    /* ce n'est pas un cas particulier : on applique */
	    /* ses regles */
	    /* applique la regle de positionnement de l'element */
	    Posit = pAbb1->AbVertPos;
	    ApplyPos (&Posit, pPRule->PrPosRule, pPRule, pAttr, pSchP, pAb,
		      pDoc, &appl);
	    pAbb1->AbVertPos = Posit;
	    /* traitement special pour le debordement vertical des cellules */
	    /* de tableau etendues verticalement */
	    if (ThotLocalActions[T_vertspan] != NULL)
	      (*ThotLocalActions[T_vertspan]) (pPRule, pAb);
	    break;
#else  /* __COLPAGE__ */
	    /* Si le precedent est un separateur de page, le pave est */
	    /* positionne' en dessous de ce saut de page, sauf si le pave */
	    /* positionne' fait partie d'un separateur de page (c'est une */
	    /* boite de haut ou de bas de page qui doit etre placee par */
	    /* rapport au filet separateur) ou s'il se positionne par */
	    /* rapport a un autre element. */
	    afterPageBreak = FALSE;
	    if (pAbb1->AbPrevious != NULL)
	      /* il y a un pave precedent */
	      {
		if (!pAbb1->AbPrevious->AbDead
		    && pAbb1->AbPrevious->AbElement->
		    ElTypeNumber == PageBreak + 1
		    && pAbb1->AbElement->ElTypeNumber != PageBreak + 1)
		  if (pPRule->PrPosRule.PoRelation == RlSameLevel
		      || pPRule->PrPosRule.PoRelation == RlPrevious)
		    afterPageBreak = TRUE;
		  else
		    {
		      if (pPRule->PrPosRule.PoRelation == RlEnclosing)
			{
			  if (pAbb1->AbPrevious->AbElement->
			      ElPageType != PgBegin)
			    afterPageBreak = TRUE;
			}
		    }
	      }
	    else
	      /* il n'y a pas de pave precedent */
	      if (pAbb1->AbElement->ElPrevious != NULL)
		/* il y a un element precedent */
		if (pAbb1->AbElement->ElPrevious->ElTypeNumber == PageBreak + 1
		    && pAbb1->AbElement->ElPrevious->ElViewPSchema == viewSch
		    && pAbb1->AbElement->ElTypeNumber != PageBreak + 1)
		  /* l'element precedent est une marque de page pour la vue */
		  if (pPRule->PrPosRule.PoRelation == RlSameLevel
		      || pPRule->PrPosRule.PoRelation == RlPrevious)
		    afterPageBreak = TRUE;
	    if (afterPageBreak)
	      /* position: en dessous du pave precedent */
	      if (pAbb1->AbPrevious == NULL)
		/* le pave de la marque de page n'est pas encore cree', on */
		/* ne peut pas appliquer la regle de positionnement */
		appl = FALSE;
	      else
		{
		  pPavP1 = &pAbb1->AbVertPos;
		  pPavP1->PosEdge = Top;
		  pPavP1->PosRefEdge = Bottom;
		  pPavP1->PosDistance = 0;
		  pPavP1->PosUnit = UnPoint;
		  pPavP1->PosAbRef = pAbb1->AbPrevious;
		  pPavP1->PosUserSpecified = FALSE;
		}
	    else
	      /* s'il s'agit d'une boite page (celle qui englobe le filet */
	      /* et les hauts et pieds de page), et si elle n'est precedee */
	      /* d'aucun element, elle se positionne en haut de l'englobant. */
	      {
		insidePage = FALSE;
		if (pAbb1->AbEnclosing != NULL)
		  if (pAbb1->AbElement->ElTypeNumber == PageBreak + 1
		      && pAbb1->AbEnclosing->AbElement->
		      ElTypeNumber != PageBreak + 1
		      && pAbb1->AbElement->ElPrevious == NULL)
		    if (pAbb1->AbPrevious == NULL)
		      insidePage = TRUE;
		
		if (insidePage)
		  {
		    pPavP1 = &pAbb1->AbVertPos;
		    pPavP1->PosAbRef = pAbb1->AbEnclosing;
		    pPavP1->PosEdge = Top;
		    pPavP1->PosRefEdge = Top;
		    pPavP1->PosDistance = 0;
		    pPavP1->PosUnit = UnPoint;
		    pPavP1->PosUserSpecified = FALSE;
		  }
		else
		  /* applique la regle de positionnement de l'element */
		  {
		    Posit = pAbb1->AbVertPos;
		    ApplyPos (&Posit, pPRule->PrPosRule, pPRule, pAttr,
			      pSchP, pAb, pDoc, &appl);
		    pAbb1->AbVertPos = Posit;
		  }
	      }
	    /* traitement special pour le debordement vertical des cellules */
	    /* de tableau etendues verticalement */
	    if (ThotLocalActions[T_vertspan] != NULL)
	      (*ThotLocalActions[T_vertspan]) (pPRule, pAb);
	    break;
#endif /* __COLPAGE__ */
	  case PtHorizPos:
	    Posit = pAbb1->AbHorizPos;
	    ApplyPos (&Posit, pPRule->PrPosRule, pPRule, pAttr, pSchP,
		      pAb, pDoc, &appl);
	    pAbb1->AbHorizPos = Posit;
	    break;
	  case PtFunction:
	    switch (pPRule->PrPresFunction)
	      {
	      case FnLine:
		if (pAbb1->AbLeafType == LtCompound)
		  /* si la regle de mise en lignes est definie pour la */
		  /* vue principale, elle s'applique a toutes les vues, */
		  /* sinon, elle ne s'applique qu'a la vue pour laquelle */
		  /* elle est definie */
		  if (pPRule->PrViewNum == 1 || pPRule->PrViewNum == viewSch)
		    {
		      pAbb1->AbInLine = TRUE;		      
		      appl = TRUE;
		    }
		break;
	      case FnNoLine:
		if (pAbb1->AbLeafType == LtCompound && pPRule->PrViewNum == viewSch)
		  {
		    pAbb1->AbInLine = FALSE;
		    appl = TRUE;
		  }
		break;
	      case FnPage:
#ifdef __COLPAGE__
		if (ApplyPage (pDoc, pAb, viewSch, pPRule, pPRule->PrPresFunction))
		  {
		    *destroyedAb = TRUE;
		    appl = TRUE;
		  }
#else  /* __COLPAGE__ */
		ApplyPage (pDoc, pAb, viewSch, pPRule, pPRule->PrPresFunction);
		appl = TRUE;
#endif /* __COLPAGE__ */
		break;
	      case FnColumn:
#ifdef __COLPAGE__
		if (ApplyCol (pDoc, pAb, viewSch, pPRule))
		  {
		    *destroyedAb = TRUE;
		    appl = TRUE;
		  }
#endif /* __COLPAGE__ */
		break;
	      case FnSubColumn:
		
		break;
	      case FnCopy:
		  /* on n'applique pas la regle copie a un element holophraste' */
		if (!pAb->AbElement->ElHolophrast)
		  {
		    ApplyCopy (pDoc, pPRule, pAb, TRUE);
		    appl = TRUE;
		  }
		break;
	      case FnContentRef:
		ConstantCopy (pPRule->PrPresBox[0], pSchP, pAb);
		appl = TRUE;
		break;
	      case FnShowBox:
		if (pAbb1->AbLeafType == LtCompound && pPRule->PrViewNum == viewSch)
		  {
		    pAbb1->AbFillBox = TRUE;
		    appl = TRUE;
		  }
		break;
	      case FnBackgroundPicture:
		if (pAbb1->AbLeafType == LtCompound && pPRule->PrViewNum == viewSch)
		  {
		    if (pSchP == NULL)
		      pSchP = pDoc->DocSSchema->SsPSchema;
		    pConst = &pSchP->PsConstant[pPRule->PrPresBox[0] - 1];
		    if (pConst->PdString[0] != '\0')
		      {
# ifndef _WINDOWS
			if (pConst->PdString[0] == DIR_SEP)
# else  /* _WINDOWS */
			if (pConst->PdString[0] == DIR_SEP || (pConst->PdString[1] == ':' && pConst->PdString[2] == DIR_SEP))
# endif /* _WINDOWS */
			  /* absolute file name */
			  strncpy (fname, pConst->PdString, MAX_PATH - 1);
			else
			  /* relative file name */
			  {
			    strncpy (directoryName, SchemaPath, MAX_PATH - 1);
			    MakeCompleteName (pConst->PdString, "", directoryName, fname, &i);
			  }
			NewPictInfo (pAbb1, fname, UNKNOWN_FORMAT);
			appl = TRUE;
		      }
		  }
		break;
	      case FnPictureMode:
		if (pPRule->PrViewNum == viewSch)
		  if (pAbb1->AbElement->ElTerminal &&
		      pAbb1->AbElement->ElLeafType == LtPicture)
		    {
		      if (pAbb1->AbElement->ElPictInfo == NULL)
			NewPictInfo (pAbb1, "", UNKNOWN_FORMAT);
		      ((PictInfo *) (pAbb1->AbElement->ElPictInfo))->PicPresent = (PictureScaling)pPRule->PrPresBox[0];
		      appl = TRUE;
		    }
		  else if (pAbb1->AbPresentationBox)
		    {
		      if (pAbb1->AbPictInfo == NULL)
			NewPictInfo (pAbb1, "", UNKNOWN_FORMAT);
		      ((PictInfo *) (pAbb1->AbPictInfo))->PicPresent = (PictureScaling)pPRule->PrPresBox[0];
		      appl = TRUE;
		    }
		  else if (pAbb1->AbLeafType == LtCompound)
		    {
		      if (pAbb1->AbPictBackground == NULL)
			NewPictInfo (pAbb1, NULL, UNKNOWN_FORMAT);
		      ((PictInfo *) (pAbb1->AbPictBackground))->PicPresent = (PictureScaling)pPRule->PrPresBox[0];
		      appl = TRUE;
		    }
		break;
	      case FnNotInLine:
		if (pPRule->PrViewNum == viewSch)
		  {
		    pAbb1->AbNotInLine = TRUE;
		    appl = TRUE;
		  }
		break;
	      default:
		break;
	      }	    
	    break;
	  default:
	    break;
	  }	
      }
  return appl;
}


/*----------------------------------------------------------------------
   	SearchPresRule	Cherche si la regle de presentation specifique
   		de type ruleType concernant la vue de numero view existe
   		pour l'element pEl.
   		Retourne un pointeur sur cette regle si elle existe,
   		sinon cree une nouvelle regle de ce type, l'ajoute a la
   		chaine des regles de presentation specifiques de
   		l'element et retourne un pointeur sur la nouvelle regle.
   		Au retour, isNew indique s'il s'agit d'une regle
   		nouvellement creee ou non.
  ----------------------------------------------------------------------*/
#ifdef __STDC__
PtrPRule            SearchPresRule (PtrElement pEl, PRuleType ruleType, FunctionType funcType, boolean * isNew, PtrDocument pDoc, int view)
#else  /* __STDC__ */
PtrPRule            SearchPresRule (pEl, ruleType, funcType, isNew, pDoc, view)
PtrElement          pEl;
PRuleType           ruleType;
FunctionType	    funcType;
boolean            *isNew;
PtrDocument         pDoc;
int                 view;

#endif /* __STDC__ */
{
   PtrPRule            pResultRule;
   PtrPRule            pPRule;
   boolean	       found;

   *isNew = FALSE;
   pResultRule = NULL;
   if (pEl != NULL)
     {
	/* l'element du pave */
	if (pEl->ElFirstPRule == NULL)
	  {
	     /* cet element n'a aucune regle de presentation specifique, on */
	     /* en cree une et on la chaine a l'element */
	     GetPresentRule (&pResultRule);
	     *isNew = TRUE;
	     pEl->ElFirstPRule = pResultRule;
	  }
	else
	  {
	     /* cherche parmi les regles de presentation specifiques de
	        l'element si ce type de regle existe pour la vue
	        a laquelle appartient le pave. */
	     pPRule = pEl->ElFirstPRule;	/* premiere regle specifique de l'element */
	     while (pResultRule == NULL)
	       {
		  found = FALSE;
		  if (pPRule->PrViewNum == pDoc->DocView[view-1].DvPSchemaView)
		     if (pPRule->PrType == ruleType)
			if (ruleType == PtFunction)
			   found = (pPRule->PrPresFunction == funcType);
			else
			   found = TRUE;
		  if (found)
		     /* la regle existe deja */
		     pResultRule = pPRule;
		  else
		    if (pPRule->PrNextPRule != NULL)
		       /* passe a la regle specifique suivante de l'element */
		       pPRule = pPRule->PrNextPRule;
		    else
		      {
		       /* On a examine' toutes les regles specifiques de */
		       /* l'element, ajoute une nouvelle regle en fin de chaine */
		       GetPresentRule (&pResultRule);
		       *isNew = TRUE;
		       pPRule->PrNextPRule = pResultRule;
		      }
	       }
	  }
	if (*isNew)
	  {
	     pResultRule->PrType = ruleType;
	     if (ruleType == PtFunction)
	        {
		pResultRule->PrPresMode = PresFunction;
		pResultRule->PrPresFunction = funcType;
		pResultRule->PrPresBoxRepeat = FALSE;
		pResultRule->PrNPresBoxes = 0;
		}
	  }
     }
   return pResultRule;
}



/*----------------------------------------------------------------------
   	RedispAbsBox indique dans le contexte du document que le pave pAb	
   		est a reafficher					
  ----------------------------------------------------------------------*/

#ifdef __STDC__
void                RedispAbsBox (PtrAbstractBox pAb, PtrDocument pDoc)

#else  /* __STDC__ */
void                RedispAbsBox (pAb, pDoc)
PtrAbstractBox      pAb;
PtrDocument         pDoc;

#endif /* __STDC__ */

{


   if (!AssocView (pAb->AbElement))
      pDoc->DocViewModifiedAb[pAb->AbDocView - 1] =
	 Enclosing (pAb, pDoc->DocViewModifiedAb[pAb->AbDocView - 1]);
   else
      pDoc->DocAssocModifiedAb[pAb->AbElement->ElAssocNum - 1] =
	 Enclosing (pAb, pDoc->DocAssocModifiedAb[pAb->
						AbElement->ElAssocNum - 1]);
}



/*----------------------------------------------------------------------
   	NewDimPicture fixe les dimensions d'un pave-image  lorsque	
   		le driver d'image ne sait pas donner une dimension a	
   		cette image. C'est le cas lorsqu'on ne tient pas compte	
   		de la cropping frame  (pour le CGM, par exemple.)	
   		Cette fonction fait le meme travail que NewDimension	
   		sans reafficher le document a la fin, laissant ce	
   		travail au driver d'images.				
   		On traite le cas ou une IMAGE est dimensionnee par son	
   		contenu comme si c'etait une dimension fixe.		
  ----------------------------------------------------------------------*/
#ifdef __STDC__
void                NewDimPicture (PtrAbstractBox pAb)
#else  /* __STDC__ */
void                NewDimPicture (pAb)
PtrAbstractBox      pAb;

#endif /* __STDC__ */
{
   boolean             new, ok;
   PtrPRule            pPRuleDimH, pPRuleDimV, pR, pRStd;
   PtrPSchema          pSPR;
   PtrSSchema          pSSR;
   PtrDocument         pDoc;
   PtrElement          pEl;
   PtrAttribute        pAttr;
   int                 height, width;
   int                 frame[MAX_VIEW_DOC];
   int                 viewSch;
   PtrAbstractBox      pAbb;
   int                 viewDoc;
   boolean             stop;
   int                 view;

#ifdef __COLPAGE__
   boolean             bool;

#endif /* __COLPAGE__ */

   pPRuleDimH = NULL;
   pPRuleDimV = NULL;
   /* nettoie la table des frames a reafficher */
   for (viewDoc = 1; viewDoc <= MAX_VIEW_DOC; viewDoc++)
      frame[viewDoc - 1] = 0;
   pEl = pAb->AbElement;	/* l'element auquel correspond le pave */
   pDoc = DocumentOfElement (pEl);	/* le document auquel appartient le pave */
   view = pAb->AbDocView;	/* la vue concernee */
   viewSch = AppliedView (pEl, NULL, pDoc, view);	/* type de cette vue dans le schema P */

   /* les deltas de dimension que l'on va appliquer sont ceux 
      de la boite par defaut avec laquelle on a cree l'image */
   height = PixelToPoint (pAb->AbBox->BxHeight);
   width = PixelToPoint (pAb->AbBox->BxWidth);

   /* traite le changement de largeur */

   /* cherche d'abord la regle de dimension qui s'applique a l'element */
   pRStd = GlobalSearchRulepEl (pEl, &pSPR, &pSSR, 0, NULL, viewSch, PtWidth, FnAny, FALSE, TRUE, &pAttr);
   /* on ne s'occupe que du cas ou l'image est dimensionnee par le contenu */
   ok = FALSE;
   if (!pRStd->PrDimRule.DrPosition)
      if (pRStd->PrDimRule.DrRelation == RlEnclosed)
	 /* largeur du contenu */
	 if (pAb->AbLeafType == LtPicture)
	    ok = TRUE;

   if (ok)
     {
	/* cherche si l'element a deja une regle de largeur specifique */
	pPRuleDimH = SearchPresRule (pEl, PtWidth, 0, &new, pDoc, view);
	if (new)
	   /* on a cree' une regle de largeur pour l'element */
	  {
	     pR = pPRuleDimH->PrNextPRule;	/* on recopie la regle standard */
	     *pPRuleDimH = *pRStd;
	     pPRuleDimH->PrNextPRule = pR;
	     pPRuleDimH->PrCond = NULL;
	     pPRuleDimH->PrViewNum = viewSch;
	  }
	pPRuleDimH->PrDimRule.DrAbsolute = TRUE;
	pPRuleDimH->PrDimRule.DrSameDimens = FALSE;
	pPRuleDimH->PrDimRule.DrMin = FALSE;
	pPRuleDimH->PrDimRule.DrUnit = UnPoint;
	pPRuleDimH->PrDimRule.DrAttr = FALSE;

	/* change la longueur dans la regle specifique */
	pPRuleDimH->PrDimRule.DrValue = width;
     }

   /* traite le changement de hauteur de la boite */

   /* cherche d'abord la regle de dimension qui s'applique a l'element */
   pRStd = GlobalSearchRulepEl (pEl, &pSPR, &pSSR, 0, NULL, viewSch, PtHeight, FnAny, FALSE, TRUE, &pAttr);
   /* on ne s'occupe que du cas ou l'image est dimensionnee par le contenu */
   ok = FALSE;
   if (!pRStd->PrDimRule.DrPosition)
      if (pRStd->PrDimRule.DrRelation == RlEnclosed)
	 /* largeur du contenu */
	 if (pAb->AbLeafType == LtPicture)
	    ok = TRUE;

   if (ok)
     {
	/* cherche si l'element a deja une regle de hauteur specifique */
	pPRuleDimV = SearchPresRule (pEl, PtHeight, 0, &new, pDoc, view);
	if (new)
	   /* on a cree' une regle de hauteur pour l'element */
	  {
	     pR = pPRuleDimV->PrNextPRule;	/* on recopie la regle standard */
	     *pPRuleDimV = *pRStd;
	     pPRuleDimV->PrNextPRule = pR;
	     pPRuleDimV->PrCond = NULL;
	     pPRuleDimV->PrViewNum = viewSch;
	  }
	pPRuleDimV->PrDimRule.DrAbsolute = TRUE;
	pPRuleDimV->PrDimRule.DrSameDimens = FALSE;
	pPRuleDimV->PrDimRule.DrMin = FALSE;
	pPRuleDimV->PrDimRule.DrUnit = UnPoint;
	pPRuleDimV->PrDimRule.DrAttr = FALSE;

	/* change le parametre de la regle */
	pPRuleDimV->PrDimRule.DrValue = height;
     }

   /* applique les nouvelles regles de presentation */

   if (pPRuleDimV != NULL || pPRuleDimH != NULL)
     {
	for (viewDoc = 1; viewDoc <= MAX_VIEW_DOC; viewDoc++)
	   if (pEl->ElAbstractBox[viewDoc - 1] != NULL)
	      /* l'element traite' a un pave dans cette vue */
	      if (pDoc->DocView[viewDoc - 1].DvSSchema == pDoc->DocView[view - 1].DvSSchema &&
		  pDoc->DocView[viewDoc - 1].DvPSchemaView == pDoc->DocView[view - 1].DvPSchemaView)
		 /* c'est une vue de meme type que la vue traitee, on */
		 /* traite le pave de l'element dans cette vue */
		{
		   pAbb = pEl->ElAbstractBox[viewDoc - 1];
		   /* saute les paves de presentation */
		   stop = FALSE;
		   do
		      if (pAbb == NULL)
			 stop = TRUE;
		      else if (!pAbb->AbPresentationBox)
			 stop = TRUE;
		      else
			 pAbb = pAbb->AbNext;
		   while (!stop);

		   if (pAbb != NULL)
		     {
			/* applique la nouvelle regle specifique Horizontale */
			if (pPRuleDimH != NULL)
#ifdef __COLPAGE__
			   if (ApplyRule (pPRuleDimH, pSPR, pAbb, pDoc, pAttr, &bool))
#else  /* __COLPAGE__ */
			   if (ApplyRule (pPRuleDimH, pSPR, pAbb, pDoc, pAttr))
#endif /* __COLPAGE__ */
			      pAbb->AbWidthChange = TRUE;
			/* applique la nouvelle regle specifique Verticale */
			if (pPRuleDimV != NULL)
#ifdef __COLPAGE__
			   if (ApplyRule (pPRuleDimV, pSPR, pAbb, pDoc, pAttr, &bool))
#else  /* __COLPAGE__ */
			   if (ApplyRule (pPRuleDimV, pSPR, pAbb, pDoc, pAttr))
#endif /* __COLPAGE__ */
			      pAbb->AbHeightChange = TRUE;

			RedispAbsBox (pAbb, pDoc);	/* indique le pave a reafficherv */
			if (!AssocView (pEl))
			   frame[viewDoc - 1] = pDoc->DocViewFrame[viewDoc - 1];
			else
			   frame[viewDoc - 1] = pDoc->DocAssocFrame[pEl->ElAssocNum - 1];
		     }
		}
     }
}