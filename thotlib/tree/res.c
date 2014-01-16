#include "thot_gui.h"
#include "thot_sys.h"
#include "tree.h"
#include "application.h"
#include "content.h"
#include "view.h"
#include "selection.h"
#include "conststr.h"
#include "typestr.h"
#define THOT_EXPORT 
#include "constres.h"
#include "resmatch_f.h"
#include "resgen_f.h"


#define NBSYMB 15

char IndexSymols[] = {'%', /* pre couplage */
		      'T', /* text */
		      'G', /* graphics */
		      'S', /* symbol */
		      'R', /* reference */
		      'P', /* picture */
		      '2', /* pair */
		      'U', /* unit */
		      'C', /* constant */
		      '{', /* aggregate */ 
		      '[', /* choice */
		      '(', /* list */
		      'N', /* nature */
		      'E', /* extension */
		      '@', /* recursive */
		      '*', /* source root (fictive) */
		      '\0'};

static StrUnitDesc *ListUnitDesc = NULL;
static TypeTree BuildStack[MAXDEPTH];
static int BuildStackTop;
/*----------------------------------------------------------------------
  RestCompSymbols
  ----------------------------------------------------------------------*/
#ifdef __STDC__
static int RestCompSymbols(char s1, char s2)
#else  /* __STDC__ */
static int RestCompSymbols(char s1, char s2)
char s1;
char s2;
#endif  /* __STDC__ */
{
  boolean found = FALSE;
  int i = 0;

  if (s1 == s2)
    return 2;
  while (!found && i < NBSYMB)
    {
      found = (IndexSymols[i] == s1 || IndexSymols[i] == s2);
      if (!found) 
	i++;
    }
  if (IndexSymols[i] == s1)
    return 1;
  else
    return 0;
}


/*----------------------------------------------------------------------
  RestIsBefore : compare les empreintes de first et second selon l'ordre
  defini par IndexSymbols
  retourne 1 si first est avant second, 0 s'il est apres 2 si les deux 
  sont egaux.
  ----------------------------------------------------------------------*/
#ifdef __STDC__
static int RestIsBefore (TypeTree first, TypeTree second) 
#else  /* __STDC__ */
static int RestIsBefore (first, second) 
TypeTree first;
TypeTree second;
#endif  /* __STDC__ */
{
  TypeTree fChild, sChild;

  fChild = RestNextEffNode (first, NULL);
  sChild = RestNextEffNode (second, NULL);
  if (fChild != NULL && sChild != NULL)
    {
      if (fChild->TDepth > sChild->TDepth)
	return 0;
      if (fChild->TDepth < sChild->TDepth)
	return 1;
    }
  while (fChild!=NULL && sChild != NULL && 
	 fChild->TPrintSymb == sChild->TPrintSymb)
    {
      fChild = RestNextEffNode (first, fChild);
      sChild = RestNextEffNode (second, sChild);
    }
  if (fChild == NULL && sChild == NULL)
    return 2;
  if (fChild == NULL)
    return 1;
  if (sChild == NULL)
    return 0;
  return (RestCompSymbols(fChild->TPrintSymb, sChild->TPrintSymb));
} 


/*----------------------------------------------------------------------
  RestInsertNode
  insere le noeud child dans l'arbre de types comme fils de parent
  ----------------------------------------------------------------------*/
#ifdef __STDC__
void RestInsertNode (TypeTree child, TypeTree parent) 
#else  /* __STDC__ */
void RestInsertNode (child, parent) 
TypeTree child;
TypeTree parent;
#endif  /* __STDC__ */
{
  TypeTree sibling, last;
  boolean found;
  
  last = NULL;
  sibling = parent->TChild;
  if (sibling == NULL)
    {
      parent->TChild = child;
      child->TNext = child->TPrevious = NULL;
      child->TParent = parent;
    }
  else
    {
      found = FALSE;
      while (!found && sibling != NULL)
	{
	  found = (RestIsBefore (child, sibling) == 1);
	  if (!found)
	    {
	      last = sibling;
	      sibling = sibling->TNext;
	    }
	}
      if (last == NULL)
	/* insertion en tete */
	parent->TChild = child;
      else
	last->TNext = child;
      if (sibling != NULL)
	sibling->TPrevious = child;
      child->TNext = sibling;
      child->TPrevious = last;
      child->TParent = parent;
    }
  if (parent->TDepth <= child->TDepth)
    parent->TDepth = child->TDepth + 1;
}

/*----------------------------------------------------------------------
  RestReorderChild
  detache et re-insere le noeud child dans l'arbre de types 
  ----------------------------------------------------------------------*/
#ifdef __STDC__
void RestReorderChild (TypeTree child) 
#else  /* __STDC__ */
void RestReorderChild (child) 
TypeTree child;
#endif  /* __STDC__ */
{
  TypeTree parent;
  
  if (child != NULL && child->TParent != NULL)
    {
      parent = child->TParent;
      if (child->TPrevious == NULL)
	parent->TChild = child->TNext;
      else 
	child->TPrevious->TNext = child->TNext;
      if (child->TNext != NULL)
	child->TNext->TPrevious = child->TPrevious;
      RestInsertNode (child, parent);
    }
}
/*----------------------------------------------------------------------
  RestNewTypeNode
  alloue un noeud d'arbre de types.
  ----------------------------------------------------------------------*/
#ifdef __STDC__
static TypeTree RestNewTypeNode(ElementType elemType)
#else  /* __STDC__ */
static TypeTree RestNewTypeNode(elemType)
ElementType elemType;
#endif  /* __STDC__ */
{
  TypeTree theTree = NULL;

  theTree = (TypeTree)TtaGetMemory(sizeof(StrTypeTree));
  theTree->TId = (RContext->CIdCount)++;
  theTree->TParent = NULL;
  theTree->TChild = NULL;
  theTree->TPrevious = NULL;
  theTree->TNext = NULL;
  theTree->TRecursive = NULL;
  theTree->TRecursApplied = FALSE;
  theTree->TEffective = TRUE;
  theTree->TPrintSymb = ' ';
  theTree->TypeNum = elemType.ElTypeNum;
  theTree->TDepth = 0;
  return theTree;
}
/*----------------------------------------------------------------------
  RestSearchPreCouple
  recherche si typeNode est compatible avec un précouplage
  ----------------------------------------------------------------------*/
#ifdef __STDC__
static void RestSearchPreCouple (TypeTree typeNode, boolean isSource) 
#else  /* __STDC__ */
static void RestSearchPreCouple (typeNode, isSource) 
TypeTree typeNode;
boolean isSource;
#endif  /* __STDC__ */
{
  
}

/*----------------------------------------------------------------------
  RecBuildTypeTree
  construit l'arbre des types du type elemType
  ----------------------------------------------------------------------*/
#ifdef __STDC__
static TypeTree RecBuildTypeTree (ElementType elemType, boolean isSource) 
#else  /* __STDC__ */
static TypeTree RecBuildTypeTree (elemType, isSource) 
ElementType elemType;
boolean isSource;
#endif  /* __STDC__ */
{
  TypeTree theTree = NULL;
  TypeTree newNode;
  SRule *strRule;
  ElementType childType;
  int i;

  if (elemType.ElTypeNum != 0 &&
      elemType.ElSSchema != NULL)
    {
      /* verifie que le type n'existe pas dans les ascendants (noeud recursifs) */
      for (i = BuildStackTop; i >= 0 && theTree == NULL; i--)
	{
	  newNode = BuildStack[i];
	  if(newNode->TypeNum == elemType.ElTypeNum)
	    {
	      theTree = RestNewTypeNode(elemType);
	      theTree->TRecursive = newNode;
	      theTree->TPrintSymb = '@';
	    }
	}
      
      /* construit un noeud */
      if (theTree == NULL)
	{
	  strRule = &(((PtrSSchema)(elemType.ElSSchema))->SsRule[(elemType.ElTypeNum) - 1]);
	  childType.ElSSchema = elemType.ElSSchema;
	  if (strRule->SrConstruct == CsIdentity)
	    {
	      /* c'est une identite, on ne cree pas de noeud */
	      childType.ElTypeNum = (strRule->SrIdentRule);
	      theTree = RecBuildTypeTree (childType, isSource);
	      theTree->TypeNum = elemType.ElTypeNum;
	    }
	  else
	    {
	      /* creation d'un noeud */
	      theTree = RestNewTypeNode (elemType);
	    
	      BuildStack[++BuildStackTop] = theTree;
	      switch (strRule->SrConstruct)
		{
		case CsList:
		  theTree->TPrintSymb = '(';
		  childType.ElTypeNum = strRule->SrListItem;
		  newNode = RecBuildTypeTree (childType, isSource);
		  RestInsertNode (newNode, theTree);
		  break;
		case CsChoice:
		  if (strRule->SrNChoices > 0)
		    { /* it's a choice */
		      theTree->TPrintSymb = '[';
		      for (i = 0; i < strRule->SrNChoices; i++)
			{
			  childType.ElTypeNum = strRule->SrChoice[i];
			  newNode = RecBuildTypeTree (childType, isSource);
			  RestInsertNode (newNode, theTree);
			}
		    }
		  else if (strRule->SrNChoices == 0)
		    { /* it'a a unit*/
		      theTree->TPrintSymb = 'U';
		    }
		  else if (strRule->SrNChoices == -1)
		    {
		      theTree->TPrintSymb = 'N';
		    }
		  break;
		case CsAggregate:
		case CsUnorderedAggregate:
		  theTree->TPrintSymb = '{';
		  if (strRule->SrNComponents > 0)
		    {
		      for (i = 0; i < strRule->SrNComponents; i++)
			{
			  childType.ElTypeNum = strRule->SrComponent[i];
			  newNode = RecBuildTypeTree (childType, isSource);
			  RestInsertNode (newNode, theTree);
			}
		    }
		  break;
		case CsConstant:
		  theTree->TPrintSymb = 'C';
		  break;
		case CsReference:
		  theTree->TPrintSymb = 'R';
		  break;
		case CsBasicElement:
		  switch (elemType.ElTypeNum)
		    {
		    case 1:
		      theTree->TPrintSymb = 'T';
		      break;
		    case 2:
		      theTree->TPrintSymb = 'G';
		      break;
		    case 4:
		      theTree->TPrintSymb = 'S';
		      break;
		    case 5:
		      theTree->TPrintSymb = 'R';
		      break;
		    case 6:
		      theTree->TPrintSymb = 'P';
		      break;
		    }
		  break;
		case CsNatureSchema:
		  theTree->TPrintSymb = 'N';
		  break;
		case CsPairedElement:
		  theTree->TPrintSymb = '2';
		  break;
		case CsExtensionRule:
		  theTree->TPrintSymb = 'E';
		  break;
		default : break;
		}
	      BuildStack[BuildStackTop--] = NULL;
	    } 
	}
      RestSearchPreCouple (theTree, isSource);
    }
  return theTree;
}

/*----------------------------------------------------------------------  
  GetTypeTree
  retourne un pointeur sur le noeud de l'arbre de type du schema 
  correspondant au type d'element elemType 
  ----------------------------------------------------------------------*/
#ifdef __STDC__
static TypeTree GetTypeTree(ElementType elemType, boolean isSource)
#else  /* __STDC__ */
static TypeTree GetTypeTree(elemType, isSource)
ElementType elemType;
boolean isSource;
#endif  /* __STDC__ */
{
  BuildStackTop = -1; 
  return RecBuildTypeTree (elemType, isSource); 
}


/*----------------------------------------------------------------------
  FindTypeInTree
  retourne un pointeur sur le noeud de type typeNum de l'arbre de types 
  typeTree - profondeur d'abord
  ----------------------------------------------------------------------*/
#ifdef __STDC__
static TypeTree FindTypeInTree (int typeNum, TypeTree tree)
#else  /* __STDC__ */
static TypeTree FindTypeInTree (typeNum, tree)
int typeNum;
TypeTree tree;
#endif  /* __STDC__ */

{
  TypeTree child, res;
  
  if (tree == NULL || tree->TypeNum == typeNum)
    return tree;
  child = tree->TChild;
  res = NULL;
  while (res == NULL && child != NULL)
    {
      res = FindTypeInTree (typeNum, child);
      child = child->TNext;
    }
  return res;
}


/*----------------------------------------------------------------------  
  GetElemSourceTree
  retourne un pointeur sur le noeud de l'arbre de type des elements source
  ----------------------------------------------------------------------*/
static TypeTree GetElemSourceTree()
{
  int i,j;
  TypeTree theTree, child;
  ElementType elType;
  ElementType tabTypes[50];
  int nbTypes;  
 
  theTree = (TypeTree)TtaGetMemory(sizeof(StrTypeTree));
  theTree->TParent = NULL;
  theTree->TChild = NULL;
  theTree->TPrevious = NULL;
  theTree->TNext = NULL;
  theTree->TRecursive = NULL;
  theTree->TRecursApplied = FALSE;
  theTree->TEffective = FALSE;
  theTree->TPrintSymb = '*';
  theTree->TId = (RContext->CIdCount)++;
  theTree->TypeNum = 0;
  theTree->TDepth = 0;
  nbTypes = 0;
  
  for (j = 0; j < RContext->CNbOldElems; j++)
    {
      elType = TtaGetElementType (RContext->COldElems[j]);
      i = 0;
      while (i < nbTypes && !TtaSameTypes(tabTypes[i], elType)) 
	i++;
      if (i == nbTypes)
	{
	  child = GetTypeTree (elType, TRUE);
	  RestInsertNode (child, theTree);
	  tabTypes[nbTypes++] = elType;
	}  
    }
  if (nbTypes == 1)
    {
      child =  theTree->TChild;
      TtaFreeMemory (theTree);
      return child;
    }
  else
    return theTree; 
}


/*----------------------------------------------------------------------  
  RestFreeTree
  libere un arbre de types
  ----------------------------------------------------------------------*/
#ifdef __STDC__
void RestFreeTree(TypeTree tree)
#else  /* __STDC__ */
void RestFreeTree(tree)
TypeTree tree;
#endif  /* __STDC__ */
{
  TypeTree child, nextchild;
  if (tree != NULL)
    {
      child = tree->TChild;
      while (child != NULL)
        {
          nextchild = child->TNext;
          RestFreeTree(child);
          child = nextchild;
        }
      TtaFreeMemory((char *)tree);
    }
}
/*----------------------------------------------------------------------  
  GetUDescSymb
  retourne le symbole correspondant au noeud unite tree ('U' si aucune
  information n'est presente pour ce noeud).
  ----------------------------------------------------------------------*/
#ifdef __STDC__
static char GetUDescSymb (TypeTree tree)
#else  /* __STDC__ */
static char GetUDescSymb (tree)
TypeTree tree;
#endif  /* __STDC__ */	
{
  StrUnitDesc *ptrDesc;

  ptrDesc = ListUnitDesc;
  while (ptrDesc != NULL && ptrDesc->Tree != tree)
    ptrDesc = ptrDesc->Next;
  if (ptrDesc == NULL)
    return 'U';
  else
    return IndexSymols[ptrDesc->TypeNumber - 1];
}

/*----------------------------------------------------------------------  
  AddUnitDescriptor 
  ajoute une entree, si elle n'existe pas deja, dans la liste des 
  descripteurs d'unites effective
  retire l'entree si elle existe deja et n'est pas instanciee avec le
  type de base donne
  ----------------------------------------------------------------------*/
#ifdef __STDC__
static void AddUnitDescriptor (TypeTree tree, ElementType elType)
#else  /* __STDC__ */
static void AddUnitDescriptor (tree, elType)
TypeTree tree;
ElementType elType;
#endif  /* __STDC__ */
{
  StrUnitDesc *ptrDesc, *previous;
  
  
  ptrDesc = ListUnitDesc;
  previous = NULL;
  while (ptrDesc != NULL && ptrDesc->Tree != tree)
    {
      previous = ptrDesc;
      ptrDesc = ptrDesc->Next;
    }
  if (ptrDesc == NULL)
    {
      ptrDesc = (StrUnitDesc *) TtaGetMemory (sizeof (StrUnitDesc));
      ptrDesc->Tree = tree;
      ptrDesc->TypeNumber = elType.ElTypeNum;
      ptrDesc->Next = ListUnitDesc;
      ListUnitDesc = ptrDesc;
    }
  else
    if (ptrDesc->TypeNumber != elType.ElTypeNum) 
      {
	if (previous != NULL)
	  previous->Next =  ptrDesc->Next;
	else
	  ListUnitDesc = ptrDesc->Next;
	TtaFreeMemory ((char *)ptrDesc);
      }
}

/*----------------------------------------------------------------------  
  RestRecPrintType
  ----------------------------------------------------------------------*/
#ifdef __STDC__
static void RestRecPrintType(TypeTree theTree, char *buffer, TypeTree *nodes, int *indice, PrintMethod method)
#else  /* __STDC__ */
static void RestRecPrintType(theTree, buffer, nodes, indice, method)
TypeTree theTree;
char *buffer;
TypeTree *nodes;
int *indice;
PrintMethod method;
#endif  /* __STDC__ */
{
  TypeTree child, markedTree;

  if (theTree->TRecursApplied)
    {/* on est deja passe par ce noeud */
      if (theTree->TEffective)
	{ 
	  nodes[*indice] = theTree;
	  buffer[(*indice)++] = '@';
	}
    }
  else
    {
      child = theTree->TChild; 
      /* saute les noeuds non effectifs */
      /* while (effect && child != NULL && !child->TEffective) 
      	child = child->Next;*/
      if (child == NULL && theTree->TPrintSymb != '@')
	{
	  if (theTree->TEffective)
	    {
	      nodes[*indice] = theTree;
	      if (theTree->TPrintSymb == 'U')
		buffer[(*indice)++] = GetUDescSymb (theTree);
	      else
		buffer[(*indice)++] = theTree->TPrintSymb;
	    }
	}
      else
	{
	  markedTree = theTree;
	  if (theTree->TPrintSymb == '@')
	    {/* noeud recursif */
	      theTree = theTree->TRecursive;
	      if (theTree->TRecursApplied)
		{
		  if (markedTree->TEffective)
		    {/* la recursion a deja ete appliquee */
		      nodes[*indice] = markedTree;
		      buffer[(*indice)++] = '@';
		    }
		  child = NULL;
		  markedTree = NULL;
		}
	      else
		{ 
		  child = theTree->TChild;
		  /* saute les noeuds non effectifs */
		  /*while (effect && child != NULL && !child->TEffective) 
		    child = child->Next;*/
		}
	    }
	  if (markedTree != NULL)
	    {/* si on est sur un non non recursif ou sur une premiere recursion */
	      theTree->TRecursApplied = TRUE;
	      if (theTree->TEffective)
		{
		  nodes[*indice] = markedTree;
		  buffer[(*indice)++] = theTree->TPrintSymb;
		}
	      while (child !=NULL)
		{
		  RestRecPrintType (child, buffer, nodes, indice, method);
		  child = child->TNext; 
		  /* while (effect && child != NULL && !child->TEffective)
		    child = child->Next;*/
		}
	      if (theTree->TEffective)
		{
		  nodes[*indice] = markedTree;
		  if(theTree->TPrintSymb == '[')
		    buffer[(*indice)++] = ']';
		  if(theTree->TPrintSymb == '{')
		    buffer[(*indice)++] = '}';
		  if(theTree->TPrintSymb == '(')
		    buffer[(*indice)++] = ')';
		}
	      theTree->TRecursApplied = FALSE;
	    }
	}
    }
}


/*----------------------------------------------------------------------  
  RestPrintType
  Cree l'empreinte de l'arbre de types de restruct->SourceType,
  dans restruct->GPrint (generique) ou restruct->EPrint
  empreinte effective
  si effective est vrai cree l'empreinte des types effectifs 
  ----------------------------------------------------------------------*/
#ifdef __STDC__
void RestPrintType(void *restruct, int bufsize, boolean isSource)
#else  /* __STDC__ */
void RestPrintType(restruct, bufsize, isSource)
void *restruct;
int bufsize;
boolean isSource;
#endif  /* __STDC__ */
{
  int indice;
  TypeTree childTree;
  SourcePrint srcInfo;
  Restruct dstInfo;
  
  indice = 0;
  if (isSource)
    {
      srcInfo = ((SourcePrint)restruct);
      if (srcInfo->STree->TPrintSymb == '*')
	{
	  childTree = srcInfo->STree->TChild;
	  while (childTree != NULL)
	    {
	      RestRecPrintType(childTree,
			       srcInfo->SPrint, 
			       srcInfo->SNodes, 
			       &indice, 
			       srcInfo->SPrintMethod);
	      childTree = childTree->TNext;
	    }
	}
      else			       
	RestRecPrintType (srcInfo->STree, 
			  srcInfo->SPrint, 
			  srcInfo->SNodes, 
			  &indice, 
			  srcInfo->SPrintMethod);
      srcInfo->SPrint[indice] = '\0';
    }
  else
    {
      dstInfo = ((Restruct)restruct);
      RestRecPrintType (dstInfo->RDestTree,
			dstInfo->RDestPrint,
			dstInfo->RDestNodes,
			&indice,
			PM_GENERIC);
      dstInfo->RDestPrint[indice] = '\0';
    }
}     
  
/*----------------------------------------------------------------------  
  RestCompatible
  renvoie vrai si elem est une instance de tree
  ----------------------------------------------------------------------*/
#ifdef __STDC__
static boolean RestCompatible (ElementType elType, TypeTree tree)
#else  /* __STDC__ */
static boolean RestCompatible (elType, tree)
ElementType elType;
TypeTree tree;
#endif  /* __STDC__ */
{
  boolean result = FALSE;

  switch (tree->TPrintSymb)
    {
    case 'N' :
      /* vrai si elem est racine d'une nature*/
      result = (elType.ElTypeNum == 8) ;
      break;
    case 'U' :
      result = TtaIsLeaf (elType);
      break;
    case '@':
      result = RestCompatible (elType, tree->TRecursive);
      break;
    default :
      if (TtaIsLeaf (elType))
	{
	  if ((tree->TPrintSymb == 'T' && elType.ElTypeNum == 1)
	      ||(tree->TPrintSymb == 'G' && elType.ElTypeNum == 2)
	      ||(tree->TPrintSymb == 'S' && elType.ElTypeNum == 3)
	      ||(tree->TPrintSymb == 'P' && elType.ElTypeNum == 4))
	    result = TRUE;
	}
      else
	result = (elType.ElTypeNum == tree->TypeNum);
      break;
    }
  return result;
}



/*----------------------------------------------------------------------  
  RecInstanciateType : marque les noeuds de tree comme effectifs s'il
  sonts representes dans l'instance elem.
  ----------------------------------------------------------------------*/
#ifdef __STDC__
static boolean RecInstanciateType(TypeTree tree, Element elem, PrintMethod method)
#else  /* __STDC__ */
static boolean RecInstanciateType(tree, elem, method)
TypeTree tree;
Element elem;
PrintMethod method;
#endif  /* __STDC__ */
{
  ElementType elType, childType;
  boolean result, found, alone;
  Element elemChild = NULL;
  TypeTree treeChild, treeChild2;

  if (tree == NULL || elem == NULL)
    return FALSE;
  elType = TtaGetElementType (elem);
  if (!RestCompatible(elType, tree))
    return FALSE;
  result = FALSE;
  if (TtaGetConstructOfType (elType) == ConstructIdentity 
      && tree->TChild == NULL 
      && tree->TPrintSymb != '@')
    {
      elem = TtaGetFirstChild (elem);
      if (elem == NULL)
	return FALSE;
      elType = TtaGetElementType (elem);
      if (!RestCompatible(elType, tree))
	return FALSE;
    }
  if (TtaIsLeaf (elType) || tree->TPrintSymb == 'N')
    /* cas d'une feuille */
    {
      if (tree->TPrintSymb == 'U')
	AddUnitDescriptor (tree, elType);
      result = TRUE;
    }
  else
    {
      elemChild = TtaGetFirstChild (elem);
      alone = (TtaGetLastChild (elem) == elemChild);
      /* parcours les fils de elem */
      while (elemChild != NULL)
	{
	  childType = TtaGetElementType (elemChild);
	  if (tree->TPrintSymb == '@')
	    treeChild = tree->TRecursive->TChild;
	  else
	    treeChild = tree->TChild;
	  found = FALSE;
	  treeChild2 = NULL;
	  while (!found && treeChild!=NULL)
	    {
	      found = RestCompatible(childType, treeChild);
	      if (!found && treeChild->TPrintSymb == '[')
		{/* si le type est un choix, ses fils ne sont pas instancies */
		  /* on parcours les petit fils aussi */
		  treeChild2 = treeChild->TChild;
		  while (!found && treeChild2!=NULL)
		    {
		      found = RestCompatible(childType, treeChild2);
		      if (!found)
			treeChild2 = treeChild2->TNext;
		    }
		}
	      if (!found)
		treeChild = treeChild->TNext;
	    }
	  if (found)
	    {/* on a trouve le noeud de type de elemChild, on l'instancie */
	      if (treeChild2 == NULL)
		result = RecInstanciateType (treeChild, elemChild, method) || result;
	      else
		/* cas du choix : on instancie aussi le fils du choix */
		if (RecInstanciateType (treeChild2, elemChild, method))
		  {
		    if (!((method & PM_WTHTCHOICE) && treeChild->TPrintSymb == '['))
		      treeChild->TEffective = TRUE;
		    result = TRUE;
		  }
	      if (result)
		RestReorderChild (treeChild);
	    }
	  TtaNextSibling (&elemChild);
	}
    }
  if (result && 
      !((method & PM_WTHTLIST) && tree->TPrintSymb == '(' && alone) &&
      !((method & PM_WTHTCHOICE) && tree->TPrintSymb == '[')) 
								     
    /* au moins un des fils est completement instancie' */
    /* (existence d'une feuille; on instancie elem */
    tree->TEffective = TRUE;
  return result;
}

/*----------------------------------------------------------------------  
  RestUnmarkEffective
  ----------------------------------------------------------------------*/
#ifdef __STDC__
static void RestUnmarkEffective (TypeTree tree)
#else  /* __STDC__ */
static void RestUnmarkEffective (tree)
TypeTree tree;
#endif  /* __STDC__ */
{
  TypeTree child;
  StrUnitDesc *ptrDesc;

  if (tree != NULL)
    {
      if (tree->TPrintSymb != '*')
	tree->TEffective = FALSE;
      child = tree->TChild;
      while (child != NULL)
	{
	  RestUnmarkEffective (child);
	  child = child->TNext;
	}
    }
  ptrDesc = ListUnitDesc;
  while (ptrDesc != NULL)
    {
      ListUnitDesc = ptrDesc->Next;
      TtaFreeMemory((char *)ptrDesc);
      ptrDesc = ListUnitDesc;
    }
  ListUnitDesc = NULL;
}

/*----------------------------------------------------------------------  
  RestInstanciateType : instanciation de l'arbre des types 
  ----------------------------------------------------------------------*/
#ifdef __STDC__
static boolean RestInstanciateType(SourcePrint sourcePrint, PrintMethod method)
#else  /* __STDC__ */
static boolean RestInstanciateType(sourcePrint, method)
Restruct restruct;
Element elem;
PrintMethod method;
#endif  /* __STDC__ */
{
  boolean ok = TRUE;
  int i;

  RestUnmarkEffective (sourcePrint->STree);
  /* instanciation de l'arbre de type source */
  for (i = 0; ok &&  i < RContext->CNbOldElems; i++)
    {
      ok = RecInstanciateType (sourcePrint->STree, RContext->COldElems[i], method);
    }

 
  return ok;
}


/*----------------------------------------------------------------------  
  RestGetSourcePrint
  ----------------------------------------------------------------------*/
#ifdef __STDC__
static SourcePrint RestGetSourcePrint (PrintMethod method)
#else  /* __STDC__ */
static SourcePrint RestGetSourcePrint (method)
PrintMethod method;
#endif  /* __STDC__ */
{
  SourcePrint sPrint;
  boolean found = FALSE;
  int i;

  sPrint = RContext->CListSourcePrints;
  if (sPrint == NULL)
    {
      RContext->CListSourcePrints = TtaGetMemory (sizeof(StrSourcePrint));
      sPrint = RContext->CListSourcePrints;
      sPrint->SNext = NULL;
      sPrint->STree = NULL;
      found = TRUE;
    }
  else
    while (!found && sPrint != NULL)
      {
	found = (sPrint->SPrintMethod == method);
	if (!found)
	  if (sPrint->SNext == NULL)
	    {
	      sPrint->SNext = TtaGetMemory (sizeof(StrSourcePrint));
	      sPrint = sPrint->SNext;
	      sPrint->SNext = NULL;
	      sPrint->STree = NULL;
	      found = TRUE;
	    }
	  else
	    sPrint = sPrint->SNext;
      }
  if (found)
    {
      if (sPrint->STree == NULL)
	{
	  for (i = 0; i< SIZEPRINT; i++)
	    {
	      sPrint->SNodes[i] = NULL;
	      sPrint->SPrint[i] = '\0';
	    }
	  sPrint->SPrintMethod = method;
	  sPrint->STree = GetElemSourceTree ();
	  if (method & PM_EFFECTIF)
	    RestInstanciateType (sPrint, method);
	  RestPrintType ((void *)sPrint, SIZEPRINT, TRUE);
	}
      return sPrint;
    }
  else
    return NULL;
}


/*----------------------------------------------------------------------  
  RestNewRestruct
  ----------------------------------------------------------------------*/
#ifdef __STDC__
Restruct RestNewRestruct (ElementType typeDest)
#else  /* __STDC__ */
Restruct RestNewRestruct (typeDest)
ElementType typeDest;
#endif  /* __STDC__ */
{
  Restruct restruct;
  int i;
  
  restruct = (Restruct)TtaGetMemory (sizeof (StrRestruct));
  restruct->RDestType = typeDest;
  restruct->RRelation = NONE;
  restruct->RNext = NULL;
  for (i = 0; i<SIZEPRINT; i++)
    {
      restruct->RDestPrint[i] = '\0';
      restruct->RDestNodes[i] = 
      restruct->RCoupledNodes[i] = NULL;
    }
  restruct->RDestTree = GetTypeTree (typeDest, FALSE);
  RestPrintType (restruct, SIZEPRINT, FALSE);
  return restruct;
}

/*----------------------------------------------------------------------  
  RestInitMatch : initialisation du contexte de transformation
  ----------------------------------------------------------------------*/
#ifdef __STDC__
boolean RestInitMatch (Element elemFirst, Element elemLast)
#else  /* __STDC__ */
boolean RestInitMatch (elemFirst, elemLast)
Element elemFirst;
Element elemLast;
#endif  /* __STDC__ */
{
  Element ptrElem;
  ElementType elType;
  Restruct lREff2,lREff;
  SourcePrint lSP, lSP2;
  boolean ok = TRUE;

  if (RContext == NULL)
    {
      RContext = TtaGetMemory(sizeof(StrRestContext));
    }
  else
    { 
      /* efface les couplages  */
      lREff = RContext->CListRestruct;
      while (lREff != NULL)
	{
	  lREff2 = lREff;
	  lREff = lREff->RNext;
	  RestFreeTree (lREff2->RDestTree);
	  TtaFreeMemory (lREff2);
	}
      /* efface les empreintes source */
      lSP = RContext->CListSourcePrints;
      while (lSP != NULL)
	{
	  lSP2 = lSP;
	  lSP = lSP->SNext;
	  RestFreeTree (lSP2->STree);
	  TtaFreeMemory (lSP2);
	}
    }
  RContext->CListRestruct = NULL;
  RContext->CListSourcePrints = NULL;
  RContext->CIdCount = 0;
  ptrElem = elemFirst;
  RContext->CNbOldElems = 0;
  RContext->CSrcSchema = NULL;
  do
    {  
      elType = TtaGetElementType (ptrElem);
      if (RContext->CSrcSchema == NULL)
	RContext->CSrcSchema = elType.ElSSchema;
      if (! TtaSameSSchemas(RContext->CSrcSchema, elType.ElSSchema))
	{  
	  ok = FALSE;
	  ptrElem = NULL;
	  RContext->CNbOldElems = 0;
	}
      else
	{
	  RContext->COldElems[(RContext->CNbOldElems)++] = ptrElem;
	  TtaNextSibling(&ptrElem);
	}
    }
  while (ptrElem != NULL && 
	 RContext->COldElems[(RContext->CNbOldElems) - 1] != elemLast);
  if (ok)
    {
      RContext->CIdCount = 0;
      RContext->CPrintMethod[0] = PM_GENERIC;
      RContext->CPrintMethod[1] = PM_EFFECTIF;
      /* RContext->CPrintMethod[2] = PM_EFFECTIF | PM_PUREEFF;*/
      RContext->CPrintMethod[2] = PM_EFFECTIF | PM_WTHTLIST;
      /* RContext->CPrintMethod[4] = PM_EFFECTIF | PM_PUREEFF | PM_WTHTCHOICE;*/
      RContext->CPrintMethod[3] = PM_EFFECTIF | PM_WTHTCHOICE;
      /* RContext->CPrintMethod[6] = PM_EFFECTIF | PM_PUREEFF | PM_WTHTLIST; */
      RContext->CPrintMethod[4] = PM_EFFECTIF | PM_WTHTCHOICE | PM_WTHTLIST;
      /* RContext->CPrintMethod[8] = PM_EFFECTIF | PM_PUREEFF | PM_WTHTCHOICE | PM_WTHTLIST; */
      RContext->CNbPrintMethod = 5;
    }
  return ok;
}

/*----------------------------------------------------------------------  
  RestMatchElements
  ----------------------------------------------------------------------*/
#ifdef __STDC__
boolean RestMatchElements(Element elemFirst, Element elemLast, SSchema strSch, int typeNum)
#else  /* __STDC__ */
boolean RestMatchElements(elemFirst, elemLast, strSch, typeNum)
Element elemFirst;
Element elemLast;
SSchema strSch;
int typeNum;
#endif  /* __STDC__ */
{
  ElementType elType;
  Restruct restCour;
  Restruct pListRestruct;
  int i;
  SourcePrint sourcePrint;
  boolean result;

#ifdef DEBUG
  char msgbuf[100];
  
  printf("\n**********\n");
#endif

  result = FALSE;
  /* if source elements have changed : init matching context */
  if (elemFirst != RContext->COldElems[0] ||
      elemLast  != RContext->COldElems[(RContext->CNbOldElems) - 1])
    RestInitMatch (elemFirst, elemLast);
  
  elType.ElTypeNum = typeNum;
  elType.ElSSchema = strSch;

#ifdef DEBUG
  /* allocation et calcul de l'empreinte destination */
  restCour = RestNewRestruct(elType);
  strcpy (msgbuf,  TtaGetElementTypeName(restCour->RDestType));
  printf("Destin : %s  -  %s\n",msgbuf,restCour->RDestPrint);  
  strcpy (msgbuf,  TtaGetElementTypeName(TtaGetElementType(elemFirst)));
  TtaFreeMemory (restCour);
#endif

  restCour = NULL;
  pListRestruct = RContext->CListRestruct;
  if (pListRestruct != NULL)
    while (pListRestruct->RNext != NULL)
      pListRestruct = pListRestruct->RNext;

#ifdef DEBUG
  strcpy (msgbuf,  TtaGetElementTypeName(elType));
  printf("Source : %s\n", msgbuf);
#endif
  /* boucle sur les methodes tant qu'on n'a pas trouve de solution */
  for (i=0; /*restCour->RRelation == NONE &&*/ i < RContext->CNbPrintMethod; i++)
    {
      restCour = RestNewRestruct(elType);
      /* instancie et calcule l'empreinte source */
      sourcePrint = RestGetSourcePrint (RContext->CPrintMethod[i]);
      if (sourcePrint != NULL)
	{
	  restCour->RSrcPrint = sourcePrint;
#ifdef DEBUG
	  printf("Source : %s\n",  restCour->RSrcPrint->SPrint);
#endif
	  /* compare les empreintes */
	  RestMatchPrints (restCour);
	}

      if (restCour->RRelation != NONE)
	{ /* un couplage a ete trouve */
	  if (pListRestruct != NULL)
	    pListRestruct->RNext = restCour;
	  else
	    RContext->CListRestruct = restCour;
	  pListRestruct = restCour;
	  result = TRUE;
#ifdef DEBUG
	  switch (restCour->RRelation)
	    {
	    case EQUIVALENCE:
	      strcpy (msgbuf, "Equiv");
	      break;
	    case FACTOR:
	      strcpy (msgbuf, "Facteur");
	      break;
	    case CLUSTER:
	      strcpy (msgbuf, "Massif");
	      break;
	    default: 
	      break;
	    }
	  printf("%s - ", msgbuf);
	  printf("methode : %c \n", restCour->RSrcPrint->SPrintMethod + 48); 
	  
#endif /* DEBUG */
	}
      else
	{
#ifdef DEBUG
	  printf ("Echec\n");
#endif
	  TtaFreeMemory (restCour);
	}
    }
  return result; 
}

/*----------------------------------------------------------------------  
  RestChangeType
  applique une transformation automatique pour changer sur place 
  le type d'un element 
  ----------------------------------------------------------------------*/
#ifdef __STDC__
boolean RestChangeType(Element elem, Document doc, int dstTypeNum, SSchema dstSch)
#else  /* __STDC__ */
boolean RestChangeType(elem, doc, dstTypeNum, dstSch)
Element elem;
Document doc;
int dstTypeNum;
SSchema dstSch;
#endif  /* __STDC__ */
{
  boolean found = FALSE;
  Restruct RestCour;
  ElementType destType; 

  destType.ElTypeNum = dstTypeNum;
  destType.ElSSchema = dstSch;
  if (RContext->CNbOldElems != 1 || elem != RContext->COldElems[0])
    {
      /* l'instance source a change : regenere et recompare les empreintes */
      RestInitMatch (elem, elem);
      found = !RestMatchElements (elem, elem, dstSch, dstTypeNum);
    }
  else
    {
      /* recherche dans les couplages existants */
      RestCour = RContext->CListRestruct;
      while (!found && RestCour != NULL)
	{
	  found = TtaSameTypes (RestCour->RDestType, destType);
	  if (!found)
	    RestCour = RestCour->RNext;
	} 
    }

  if (found)
    /* applique la transformation */
    return RestChangeOnPlace (doc, RestCour);
  else
    return FALSE;
}



  

