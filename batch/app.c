/*
 *
 *  (c) COPYRIGHT INRIA, 1996.
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
 * Compiler of language A.
 *
 * Author: I. Vatton (INRIA)
 *
 */

#include "thot_sys.h"
#include "compilmsg.h"
#include "appmsg.h"
#include "message.h"
#include "appdef.h"
#include "constgrm.h"
#include "constmedia.h"
#include "typemedia.h"
#include "typegrm.h"
#include "fileaccess.h"
#include "app.h"
#include "modif.h"
#include "menuaction.h"
#include "registry.h"
#include "fileaccess.h"
#include "thotdir.h"

#include "parser_f.h"
#include "compilmsg_f.h"
#include "callbackinit_f.h"
#include "platform_f.h"
#include "memory_f.h"
#include "message_f.h"
#include "readstr_f.h"
#include "fileaccess_f.h"
#include "writeapp_f.h"

#define THOT_EXPORT
#include "platform_tv.h"
#include "analsynt_tv.h"
#include "compil_tv.h"
#undef THOT_EXPORT
#define THOT_EXPORT extern
#include "appevents_tv.h"

THOT_EXPORT int          LineNum;
THOT_EXPORT PtrEventsSet pAppli;
THOT_EXPORT PtrSSchema   pSSchema;
extern int          IncNbIdent;

int                 LineNum;	/* lines counter in source file */
static Name         fileName;
PtrSSchema          pSSchema;
PtrEventsSet        pAppli;
/* Pointer to the list of application schemas linked with EDITOR.A */
PtrAppName          SchemasUsed = NULL;
/* Pointer to the list of menu names effectively used */
PtrAppName          MenusUsed = NULL;
/* Pointer to the list of item names effectively used */
PtrAppName          ItemsUsed = NULL;
/* Pointer to the list of action names effectively used */
PtrAppName          ActionsUsed = NULL;
/* Pointer to the list of menus displayed in the main application frame */
PtrAppMenu          MainWindowMenus = NULL;
/* Pointer to the list of menus displayed in standard document frames */
PtrAppMenu          DocWindowMenus = NULL;
/* Pointer to the list of menus displayed in specific document frames */
PtrAppDocType       DocTypeMenus = NULL;

static boolean      FirstInPair = False;/* keyword "First" found             */
static boolean      SecondInPair = False;/* keyword "Second" found           */
static int          typeNum;
static int          attrNum;
static int          curEvent;		/* the current event                 */
static char        *eventAction;	/* the action linked with the event  */
static boolean      PreEvent;
static boolean      DefaultSection;	/* within the section DEFAULT        */
static boolean      ElementsSection;	/* within the section ELEMENTS       */
static boolean      AttributesSection;	/* within the section ATTRIBUTES     */
static boolean      MenusSection;	/* within the section MENUS          */
static PtrAppMenu  *MenuList;
static int          ViewNumber;
static char         MenuName[100];
static char         SubmenuName[100];
static char         ItemName[100];
static char         ItemType;		/* 'B' = Button,    'T' = Toggle,    */

				     	/* 'S' = Separator, 'D' = Dynamic.   */
static char         ActionName[100];

/* the list RegisteredAppEvents have to be conform to the type enum APPevent
   defined into appaction.h */
char               *RegisteredAppEvents[] =
{
   "AttrMenu",
   "AttrCreate",
   "AttrModify",
   "AttrRead",
   "AttrSave",
   "AttrExport",
   "AttrDelete",
   "ElemMenu",
   "ElemNew",
   "ElemRead",
   "ElemSave",
   "ElemExport",
   "ElemDelete",
   "ElemSelect",
   "ElemExtendSelect",
   "ElemActivate",
   "ElemSetReference",
   "ElemInclude",
   "ElemFetchInclude",
   "ElemCopy",
   "ElemPaste",
   "ElemChange",
   "ElemMove",
   "ElemTextModify",
   "ElemGraphModify",
   "ElemTransform",
   "ElemMouseOver",
   "ElemMouseOut",
   "PRuleCreate",
   "PRuleModify",
   "PRuleDelete",
   "DocOpen",
   "DocTmpOpen",
   "DocCreate",
   "DocClose",
   "DocSave",
   "DocExport",
   "DocNatPresent",
   "ViewOpen",
   "ViewClose",
   "ViewResize",
   "ViewScroll",
   "Init",
   "Exit"
};

/*----------------------------------------------------------------------
   MenuActionList adds into the list ActionsUsed actions        
   used by the new set of menus pointed by firstMenu.   
   If actions already exist in the list, they are not added.
   In the same way this function adds menu names used in the set into the
   list MenusUsed and item names into the list ItemsUsed.
  ----------------------------------------------------------------------*/
#ifdef __STDC__
static void         MenuActionList (PtrAppMenu firstMenu)

#else  /* __STDC__ */
static void         MenuActionList (firstMenu)
PtrAppMenu          firstMenu;

#endif /* __STDC__ */

{
   PtrAppName          curAction, prevAction;
   PtrAppName          curMenu, prevMenu;
   PtrAppName          curItem, prevItem;
   PtrAppMenu          menu;
   PtrAppMenuItem      item, menuitem;
   boolean             found;

   menu = firstMenu;
   /* check the new set of menus */
   while (menu != NULL)
     {
	/* look at if the menu name is already in the list MenusUsed */
	curMenu = MenusUsed;
	found = False;
	prevMenu = NULL;
	while (!found && curMenu != NULL)
	  {
	     if (curMenu->AppNameValue != NULL &&
		 strcmp (curMenu->AppNameValue, menu->AppMenuName) == 0)
		/* the menu name is already in the list */
		found = True;
	     else
	       {
		  prevMenu = curMenu;
		  /* next menu name in the list MenusUsed */
		  curMenu = curMenu->AppNextName;
	       }
	  }
	if (!found)
	   /* the menu name is a new name, add it into the list */
	  {
	     curMenu = (PtrAppName) TtaGetMemory (sizeof (AppName));
	     if (menu->AppMenuName == NULL)
		curMenu->AppNameValue = NULL;
	     else
		curMenu->AppNameValue = TtaStrdup (menu->AppMenuName);
	     curMenu->AppNextName = NULL;
	     if (prevMenu == NULL)
		MenusUsed = curMenu;
	     else
		prevMenu->AppNextName = curMenu;
	  }

	/* check the list of item names of the new menu and its submenus */
	item = menu->AppMenuItems;
	menuitem = NULL;
	while (item != NULL)
	  {
	     /* skip menu separators */
	     if (item->AppItemType != 'S')
	       {
		  /* look at if the item name is already in the list ItemsUsed */
		  curItem = ItemsUsed;
		  found = False;
		  prevItem = NULL;
		  while (!found && curItem != NULL)
		    {
		       if (curItem->AppNameValue != NULL && item->AppItemName != NULL &&
			   strcmp (curItem->AppNameValue, item->AppItemName) == 0)
			  /* the item name is already in the list */
			  found = True;
		       else
			 {
			    prevItem = curItem;
			    /* passe au nom suivant de la liste */
			    curItem = curItem->AppNextName;
			 }
		    }
		  if (!found)
		     /* le nom de l'item n'est pas in the list, on l'y met */
		    {
		       curItem = (PtrAppName) TtaGetMemory (sizeof (AppName));
		       curItem->AppNameValue = TtaStrdup (item->AppItemName);
		       curItem->AppNextName = NULL;
		       if (prevItem == NULL)
			  ItemsUsed = curItem;
		       else
			  prevItem->AppNextName = curItem;
		    }
	       }
	     if (item->AppItemActionName != NULL)
		/* cet item a une action definie */
	       {
		  /* cherche si l'action de l'item est in the list des actions */
		  curAction = ActionsUsed;
		  found = False;
		  prevAction = NULL;
		  while (!found && curAction != NULL)
		    {
		       if (curAction->AppNameValue != NULL &&
			   strcmp (curAction->AppNameValue, item->AppItemActionName) == 0)
			  /* l'action de l'item est in the list */
			  found = True;
		       else
			 {
			    prevAction = curAction;
			    /* passe a l'action suivante de la liste */
			    curAction = curAction->AppNextName;
			 }
		    }
		  if (!found)
		     /* l'action de l'item n'est pas in the list, on l'y met */
		    {
		       curAction = (PtrAppName) TtaGetMemory (sizeof (AppName));
		       curAction->AppNameValue = TtaStrdup (item->AppItemActionName);
		       curAction->AppStandardName = item->AppStandardAction;
		       curAction->AppNextName = NULL;
		       if (prevAction == NULL)
			  ActionsUsed = curAction;
		       else
			  prevAction->AppNextName = curAction;
		    }
	       }

	     if (item->AppSubMenu != NULL)
	       {
		  /* initialise le traitement les items du sous-menu */
		  menuitem = item;
		  item = item->AppSubMenu;
	       }
	     else
	       {
		  /* passe a l'item suivant */
		  item = item->AppNextItem;
		  if (menuitem != NULL && item == NULL)
		    {
		       /* reprend le traitement les items du menu */
		       item = menuitem->AppNextItem;
		       menuitem = NULL;
		    }
	       }
	  }
	/* passe au menu suivant */
	menu = menu->AppNextMenu;
     }
}

/*----------------------------------------------------------------------
   MakeMenusAndActionList construit la liste des noms de toutes    
   les actions effectivement utiles, la liste de tous les noms de  
   menus effectivement utiles et de tous les noms d'item utiles.   
  ----------------------------------------------------------------------*/
static void         MakeMenusAndActionList ()
{
   PtrAppDocType       menusDoc;

   /* cherche les actions, les menus et les items de la fenetre principale */
   MenuActionList (MainWindowMenus);
   /* cherche les actions, les menus et les items des frames document
      normales */
   MenuActionList (DocWindowMenus);
   /* cherche les actions les menus et les items des frames document de type
      particulier */
   menusDoc = DocTypeMenus;
   while (menusDoc != NULL)
     {
	MenuActionList (menusDoc->AppDocTypeMenus);
	menusDoc = menusDoc->AppNextDocType;
     }
}

/*----------------------------------------------------------------------
   RegisteredEvent checks whether eventName is in the list of      
   registered events and returns True if yes, and the rank of the  
   event in the list (rank).                                       
  ----------------------------------------------------------------------*/
#ifdef __STDC__
static boolean      RegisteredEvent (char *eventName, int *rank)
#else  /* __STDC__ */
static boolean      RegisteredEvent (eventName, rank)
char               *eventName;
int                *rank;

#endif /* __STDC__ */
{
   int                 evtNum, evt;
   boolean             found;

   /* cherche le nom de l'evenement dans la table */
   evtNum = sizeof (RegisteredAppEvents) / sizeof (char *);

   found = False;
   for (evt = 0; evt < evtNum && !found; (evt)++)
      if (strcmp (eventName, RegisteredAppEvents[evt]) == 0)
	{
	   found = True;
	   *rank = evt;
	}
   return found;
}

/*----------------------------------------------------------------------
   ConstructAbstractSchStruct                                      
  ----------------------------------------------------------------------*/
static PtrSSchema   ConstructAbstractSchStruct ()
{
   PtrSSchema          pSS;

   pSS = (PtrSSchema) TtaGetMemory (sizeof (StructSchema));
   pSS->SsCode = 0;

   /* initialise les types de base */
   strcpy (pSS->SsRule[CharString].SrName, "TEXT_UNIT");
   strcpy (pSS->SsRule[GraphicElem].SrName, "GRAPHICS_UNIT");
   strcpy (pSS->SsRule[Symbol].SrName, "SYMBOL_UNIT");
   strcpy (pSS->SsRule[Picture].SrName, "PICTURE_UNIT");
   strcpy (pSS->SsRule[Refer].SrName, "REFERENCE_UNIT");
   strcpy (pSS->SsRule[PageBreak].SrName, "PAGE_BREAK");
   pSS->SsNRules = MAX_BASIC_TYPE - 1;
   pSS->SsNAttributes = 0;
   return pSS;
}

/*----------------------------------------------------------------------
   NewMenuComplete                                                 
  ----------------------------------------------------------------------*/
static void         NewMenuComplete ()
{
   PtrAppMenu          Menu, NewMenu, CurMenu;
   PtrAppMenuItem      Item, NewItem, SubMenu;
   boolean             found;

   /* les variables MenuList, MenuName, SubmenuName, ItemName, ItemType */
   /* et ActionName sont a jour. */

   /* On cherche d'abord le menu */
   if (MenuList != NULL)
      CurMenu = *MenuList;
   else
      CurMenu = NULL;
   Menu = NULL;
   while (Menu == NULL && CurMenu != NULL)
      if (CurMenu->AppMenuName != NULL &&
	  strcmp (MenuName, CurMenu->AppMenuName) == 0)
	 Menu = CurMenu;
      else
	 CurMenu = CurMenu->AppNextMenu;

   if (Menu == NULL)
      /* creation d'un nouveau menu */
     {
	NewMenu = (PtrAppMenu) TtaGetMemory (sizeof (AppMenu));
	NewMenu->AppMenuName = TtaStrdup (MenuName);
	NewMenu->AppMenuView = ViewNumber;	/* la vue concenee */
	NewMenu->AppMenuItems = NULL;
	NewMenu->AppNextMenu = NULL;
	if (*MenuList == NULL)
	   /* il n'y a pas encore de menus in the list */
	   *MenuList = NewMenu;
	else
	  {
	     /* ajoute le nouveau menu en fin de la liste des menus */
	     Menu = *MenuList;
	     while (Menu->AppNextMenu != NULL)
		Menu = Menu->AppNextMenu;
	     Menu->AppNextMenu = NewMenu;
	  }
	Menu = NewMenu;
     }

   SubMenu = NULL;
   Item = NULL;
   if (SubmenuName[0] != '\0')
      /* il y a un sous-menu. On cherche son entree dans le menu */
     {
	found = False;
	Item = Menu->AppMenuItems;
	while (Item != NULL && !found)
	   if (Item->AppItemName != NULL &&
	       strcmp (Item->AppItemName, SubmenuName) == 0)
	      found = True;
	   else
	      Item = Item->AppNextItem;
	if (!found)
	   /* cet item n'existe pas, on le met */
	  {
	     /* cree un nouvel item  */
	     NewItem = (PtrAppMenuItem) TtaGetMemory (sizeof (AppMenuItem));
	     NewItem->AppItemName = TtaStrdup (SubmenuName);
	     NewItem->AppItemActionName = NULL;
	     NewItem->AppSubMenu = NULL;
	     NewItem->AppItemType = ' ';
	     NewItem->AppStandardAction = False;
	     NewItem->AppNextItem = NULL;
	     /* chaine le nouvel item en fin de liste d'items du menu */
	     if (Menu->AppMenuItems == NULL)
		Menu->AppMenuItems = NewItem;
	     else
	       {
		  /* cherche le dernier item du menu */
		  Item = Menu->AppMenuItems;
		  while (Item->AppNextItem != NULL)
		     Item = Item->AppNextItem;
		  Item->AppNextItem = NewItem;
	       }
	     Item = NewItem;
	  }
	SubMenu = Item;
     }

   if (ItemName[0] != '\0' || ItemType == 'S')
     {
	if (SubMenu != NULL)
	   Item = SubMenu->AppSubMenu;
	else
	   Item = Menu->AppMenuItems;
	/* Cherche si cet item est deja dans le menu, sauf si c'est un */
	/* separateur: on peut avoir plusieurs separateurs dans le meme menu */
	found = False;
	if (ItemType != 'S')
	   while (Item != NULL && !found)
	      if (Item->AppItemName != NULL &&
		  strcmp (Item->AppItemName, ItemName) == 0)
		 found = True;
	      else
		 Item = Item->AppNextItem;
	if (found)
	   CompilerMessage (1, APP, FATAL, APP_ITEM_ALREADY_EXISTS, inputLine,
			  LineNum);
	else
	   /* cet item n'existe pas, on le met */
	  {
	     /* cree un nouvel item  */
	     NewItem = (PtrAppMenuItem) TtaGetMemory (sizeof (AppMenuItem));
	     if (ItemName[0] == '\0')
		NewItem->AppItemName = NULL;
	     else
		NewItem->AppItemName = TtaStrdup (ItemName);
	     NewItem->AppItemActionName = NULL;
	     NewItem->AppSubMenu = NULL;
	     NewItem->AppItemType = ItemType;
	     NewItem->AppStandardAction = False;
	     NewItem->AppNextItem = NULL;
	     if (SubMenu == NULL)
		/* chaine le nouvel item en fin de liste d'items du menu */
		if (Menu->AppMenuItems == NULL)
		   Menu->AppMenuItems = NewItem;
		else
		  {
		     /* cherche le dernier item du menu */
		     Item = Menu->AppMenuItems;
		     while (Item->AppNextItem != NULL)
			Item = Item->AppNextItem;
		     Item->AppNextItem = NewItem;
		  }
	     else
		/* chaine le nouvel item en fin de liste */
	     if (SubMenu->AppSubMenu == NULL)
		SubMenu->AppSubMenu = NewItem;
	     else
	       {
		  Item = SubMenu->AppSubMenu;
		  while (Item->AppNextItem != NULL)
		     Item = Item->AppNextItem;
		  Item->AppNextItem = NewItem;
	       }
	     /* on met l'action, sauf si c'est un separateur ou un */
	     /* sous-menu dynamique */
	     if (ActionName[0] != '\0')
	       {
		  NewItem->AppItemActionName = TtaStrdup (ActionName);
		  /* Il faut tester s'il s'agit d'une action standard */
		  NewItem->AppStandardAction = (strncmp (ActionName, "Ttc", 3) == 0);
	       }
	  }
     }
}


/*----------------------------------------------------------------------
   InitMenu                                                        
  ----------------------------------------------------------------------*/
static void         InitMenu ()
{
   ViewNumber = 0;
   MenuName[0] = '\0';
   SubmenuName[0] = '\0';
   ItemName[0] = '\0';
   ItemType = ' ';
   ActionName[0] = '\0';
}


/*----------------------------------------------------------------------
   ProcessShortKeyWord traite un mot-cle court.                    
  ----------------------------------------------------------------------*/
#ifdef __STDC__
static void         ProcessShortKeyWord (int x, SyntacticCode r, SyntacticCode pr)

#else  /* __STDC__ */
static void         ProcessShortKeyWord (x, r, pr)
int                 x;
SyntacticCode       r;
SyntacticCode       pr;

#endif /* __STDC__ */
{
   int                 typeId;

   switch (x)
	 {
	       /* traitement selon le code du mot-cle court */
	    case CHR_59:
	       /*  ;  */
	       switch (r)
		     {
			case RULE_EvtAction:
			   if (DefaultSection)
			      typeId = 0;
			   else if (ElementsSection)
			      typeId = typeNum;
			   else if (AttributesSection)
			      typeId = attrNum;
			   else
			      typeId = 0;
			   TteAddActionEvent (pAppli, typeId, curEvent, PreEvent, eventAction);
			   curEvent = 0;
			   PreEvent = True;
			   eventAction = NULL;
			   break;
			case RULE_NewMenu:
			   NewMenuComplete ();
			   InitMenu ();
			   break;
			default:
			   break;
		     }
	       break;
	    case CHR_44:
	       /*  ,  */
	       break;

	    case CHR_46:
	       /* .  */
	       break;

	    case CHR_58:
	       /* :  */
	       if (r == RULE_Menus)
		  InitMenu ();
	       break;

	    default:
	       break;
	 }
}


/*----------------------------------------------------------------------
   ProcessLongKeyWord traite un mot-cle long.                      
  ----------------------------------------------------------------------*/
#ifdef __STDC__
static void         ProcessLongKeyWord (int x, SyntacticCode r, indLine wi)

#else  /* __STDC__ */
static void         ProcessLongKeyWord (x, r, wi)
int                 x;
SyntacticCode       r;
indLine             wi;

#endif /* __STDC__ */

{
   switch (x)
	 {
	       /* traitement selon le code du mot-cle */
	    case KWD_APPLICATION:
	       /* initialisation */
	       DefaultSection = False;
	       ElementsSection = False;
	       AttributesSection = False;
	       MenusSection = False;
	       break;

	    case KWD_USES:
	       /* le mot-cle' USES */
	       if (strcmp (fileName, "EDITOR") != 0)
		  /* ce n'est pas EDITOR.A qu'on compile, refus */
		  CompilerMessage (wi, APP, FATAL, FORBIDDEN_OUTSIDE_EDITOR_I,
				 inputLine, LineNum);
	       else
		  SchemasUsed = NULL;
	       break;

	    case KWD_DEFAULT:
	       DefaultSection = True;
	       break;

	    case KWD_ELEMENTS:
	       ElementsSection = True;
	       DefaultSection = False;
	       break;

	    case KWD_ATTRIBUTES:
	       AttributesSection = True;
	       DefaultSection = False;
	       ElementsSection = False;
	       break;

	    case KWD_MENUS:
	       /* debut de la section MENUS */
	       DefaultSection = False;	/* la section DEFAULT est donc finie */
	       ElementsSection = False;
	       AttributesSection = False;
	       MenusSection = True;
	       if (strcmp (fileName, "EDITOR") != 0)
		  /* ce n'est pas EDITOR.A qu'on compile, refus */
		  CompilerMessage (wi, APP, FATAL, FORBIDDEN_OUTSIDE_EDITOR_I,
				 inputLine, LineNum);
	       break;

	    case KWD_BEGIN:
	       if (r == RULE_MenuList)
		  InitMenu ();
	       break;

	    case KWD_END:
	       break;

	    case KWD_Post:
	       if (curEvent == TteAttrMenu)
		  CompilerMessage (wi, APP, FATAL, ONLY_IF_PRE_ALLOWED, inputLine,
				 LineNum);
	       PreEvent = False;
	       break;

	    case KWD_Pre:
	       PreEvent = True;
	       break;

	    case KWD_First:
	       FirstInPair = True;
	       break;

	    case KWD_Second:
	       SecondInPair = True;
	       break;

	    case KWD_Main:
	       MenuList = &MainWindowMenus;
	       break;

	    case KWD_Window:
	       break;

	    case KWD_Document:
	       MenuList = &DocWindowMenus;
	       break;

	    case KWD_Windows:
	       break;

	    case KWD_Separator:
	       ItemType = 'S';
	       ItemName[0] = '\0';
	       ActionName[0] = '\0';
	       break;

	    case KWD_Button:
	       ItemType = 'B';
	       break;

	    case KWD_Toggle:
	       ItemType = 'T';
	       break;

	    case KWD_Dynamic:
	       ItemType = 'D';
	       ActionName[0] = '\0';
	       break;

	    default:
	       break;
	 }
}

/*----------------------------------------------------------------------
   ProcessName processes a name.                                      
  ----------------------------------------------------------------------*/
#ifdef __STDC__
static void         ProcessName (SyntacticCode r, SyntacticCode pr, indLine wl, indLine wi)
#else  /* __STDC__ */
static void         ProcessName (r, pr, wl, wi)
SyntacticCode       r;
SyntacticCode       pr;
indLine             wl;
indLine             wi;

#endif /* __STDC__ */
{
   int                 i;
   Name                name;
   PtrAppDocType       docType, newDocType;
   PtrAppName          schUsed, newSchUsed;

   if (wl > MAX_NAME_LENGTH - 1)
      CompilerMessage (wi, COMPIL, FATAL, INVALID_WORD_SIZE, inputLine, LineNum);
   else
     {
	strncpy (name, &inputLine[wi - 1], wl);
	name[wl] = '\0';
     }
   switch (r)
	 {
	       /* r = numero de la regle ou apparait le nom */

	    case RULE_ElemIdent:
	       typeNum = 0;
	       if (pr == RULE_AppliModel)
		 {
		    if (strcmp (fileName, "EDITOR") == 0)
		      {
			 /* construct an abstract schemas structure */
			 pSSchema = ConstructAbstractSchStruct ();
			 /* acquiert un schema */
			 pAppli = TteNewEventsSet (pSSchema->SsCode, fileName);
			 /* Pointer to the list of schemas menus descriptors */
			 DocTypeMenus = NULL;
		      }
		    else
		      {
			 /* TypeName est ici le nom de la structure generique */
			 /* => on lit le schema de structure compile' */
			 pSSchema = (PtrSSchema) TtaGetMemory (sizeof (StructSchema));
			 if (!ReadStructureSchema (name, pSSchema))
			    CompilerMessage (wi, APP, FATAL, APP_STRUCT_SCHEM_NOT_FOUND,
					   inputLine, LineNum);
			 else if (strcmp (name, pSSchema->SsName) != 0)
			    CompilerMessage (wi, APP, FATAL,
					   UNMATCHING_STRUCT_SCHEME,
					   inputLine, LineNum);
			 else
			    /* acquiert un schema */
			    pAppli = TteNewEventsSet (pSSchema->SsCode, fileName);
		      }
		 }
	       else
		 {
		    /* is it an Element? */
		    if (pr == RULE_ElemActions)
		      {
			 i = 0;
			 while (strcmp (name, pSSchema->SsRule[i].SrName) != 0
				&& i < pSSchema->SsNRules)
			    i++;
			 if (i < pSSchema->SsNRules)
			   {
			      if (pSSchema->SsRule[i].SrConstruct == CsPairedElement)
				 /* c'est un element CsPairedElement */
				 if (!SecondInPair && !FirstInPair)
				    /* le nom du type n'etait pas precede' de First ou Second */
				    CompilerMessage (wi, APP, FATAL, MISSING_FIRST_SECOND,
						   inputLine, LineNum);
				 else
				   {
				      if (SecondInPair)
					 /* il s'agit du type suivant */
					 i++;
				   }
			      else
				 /* ce n'est pas un element CsPairedElement */
			      if (SecondInPair || FirstInPair)
				 /* le nom du type etait precede' de First ou Second */
				 CompilerMessage (wi, APP, FATAL, NOT_A_PAIR, inputLine,
						LineNum);
			      typeNum = i + 1;
			   }
			 else
			   {
			      if (strcmp (fileName, "EDITOR") == 0)
				{
				   strcpy (pSSchema->SsRule[i].SrName, name);
				   pSSchema->SsNRules++;
				   typeNum = i + 1;
				}
			      else
				 CompilerMessage (wi, APP, FATAL, UNKNOWN_TYPE_APP,
						inputLine, LineNum);
			   }
			 FirstInPair = False;
			 SecondInPair = False;
		      }
		 }
	       break;

	    case RULE_DocumentType:
	       if (pr == RULE_SchemaList)
		  /* un nom de type de document dans l'instruction USES */
		 {
		    /* acquiert un descripteur de schema A utilise' */
		    newSchUsed = (PtrAppName) TtaGetMemory (sizeof (AppName));
		    /* met le nom du schema A utilise' dans le descripteur */
		    newSchUsed->AppNameValue = TtaStrdup (name);
		    newSchUsed->AppStandardName = False;
		    /* chaine ce nouveau descripteur en fin de liste */
		    newSchUsed->AppNextName = NULL;
		    if (SchemasUsed == NULL)
		       /* la chaine etait vide */
		       SchemasUsed = newSchUsed;
		    else
		      {
			 schUsed = SchemasUsed;
			 while (schUsed->AppNextName != NULL)
			    schUsed = schUsed->AppNextName;
			 schUsed->AppNextName = newSchUsed;
		      }
		 }
	       else if (pr == RULE_Menus)
		  /* un type de document pour lequel on veut definir les boutons */
		  /* et menus des frames */
		 {
		    /* ajoute un type de document */
		    /* alloue un descripteur de type de document */
		    newDocType = (PtrAppDocType) TtaGetMemory (sizeof (AppDocType));
		    /* initialise ce descripteur */
		    newDocType->AppDocTypeName = TtaStrdup (name);
		    newDocType->AppDocTypeMenus = NULL;
		    newDocType->AppNextDocType = NULL;
		    if (DocTypeMenus == NULL)
		       DocTypeMenus = newDocType;
		    else
		      {
			 docType = DocTypeMenus;
			 while (docType->AppNextDocType != NULL)
			    docType = docType->AppNextDocType;
			 docType->AppNextDocType = newDocType;
		      }
		    newDocType->AppDocTypeMenus = NULL;
		    MenuList = &(newDocType->AppDocTypeMenus);
		 }
	       break;

	    case RULE_EvtIdent:
	       /* Le nom de l'evenement */
	       PreEvent = True;
	       /* cherche si l'evenement est dans la table des evenements definis */
	       if (!RegisteredEvent (name, &curEvent))
		  /* il n'y est pas, erreur */
		  CompilerMessage (wi, APP, FATAL, UNKNOWN_MESSAGE, inputLine, LineNum);
	       else if (!DefaultSection)
		 {
		    /* on n'est pas dans la section DEFAULT du schema A */
		    /* on n'accepte pas les evenements pour les documents, pour les */
		    /* vues, ni pour l'application */
		    if (curEvent >= TteDocOpen)
		       CompilerMessage (wi, APP, FATAL, NOT_IN_DEFAULT, inputLine,
				      LineNum);
		 }
	       else
		 {
		    if (curEvent >= TteInit)
		       /* c'est un evenement pour l'application */
		      {
			 if (strcmp (fileName, "EDITOR") != 0)
			    /* ce n'est pas EDITOR.A qu'on compile, refus */
			    CompilerMessage (wi, APP, FATAL, FORBIDDEN_OUTSIDE_EDITOR_I, inputLine,
					   LineNum);
		      }
		    else if (AttributesSection)
		      {
			 if (curEvent > TteAttrDelete)
			    CompilerMessage (wi, APP, FATAL, FORBIDDEN_FOR_AN_ATTR,
					   inputLine, LineNum);
		      }
		    else if (ElementsSection)
		      {
			 if (curEvent <= TteAttrDelete)
			    CompilerMessage (wi, APP, FATAL, FORBIDDEN_FOR_AN_ELEM,
					   inputLine, LineNum);
		      }
		 }
	       break;

	    case RULE_ActionIdent:
	       if (pr == RULE_ItemAction)
		  /* action associee a un item de menu */
		  strcpy (ActionName, name);
	       else if (pr == RULE_EvtAction)
		 {
		    /* action associee a un evenement */
		    eventAction = TtaStrdup (name);
		    TteAddAction (eventAction, 0);
		 }
	       break;

	    case RULE_AttrIdent:
	       attrNum = 0;
	       if (strcmp (fileName, "EDITOR") == 0 && pSSchema == NULL)
		 {
		    pSSchema = ConstructAbstractSchStruct ();
		    pAppli = TteNewEventsSet (pSSchema->SsCode, fileName);
		 }
	       if (pr == RULE_AttrActions)
		 {
		    i = 1;
		    while (strcmp (name, pSSchema->SsAttribute[i - 1].AttrOrigName) != 0
			   && i <= pSSchema->SsNAttributes)
		       i++;
		    if (i <= pSSchema->SsNAttributes)
		       attrNum = i;
		    else
		      {
			 if (strcmp (fileName, "EDITOR") == 0)
			   {
			      /* the file .A is a EDITOR.A */
			      strcpy (pSSchema->SsAttribute[i - 1].AttrOrigName, name);
			      pSSchema->SsNAttributes = pSSchema->SsNAttributes + 1;
			      attrNum = i;
			   }
			 else
			    CompilerMessage (wi, APP, FATAL, UNKNOWN_ATTR_APP, inputLine, LineNum);
		      }
		 }
	       break;

	    case RULE_MenuIdent:
	       /* un nom de menu */
	       strcpy (MenuName, name);
	       SubmenuName[0] = '\0';
	       ItemName[0] = '\0';
	       ItemType = ' ';
	       ActionName[0] = '\0';
	       break;

	    case RULE_SubmenuIdent:
	       /* un nom de sous-menu dans une definition de menu */
	       strcpy (SubmenuName, name);
	       break;

	    case RULE_ItemIdent:
	       /* un nom d'item de menu dans une definition de menu */
	       strcpy (ItemName, name);
	       break;

	    default:
	       break;
	 }
}

/*----------------------------------------------------------------------
   ProcessInteger genere un nombre.                                    
  ----------------------------------------------------------------------*/
#ifdef __STDC__
static void         ProcessInteger (SyntacticCode r, indLine wl, indLine wi)
#else  /* __STDC__ */
static void         ProcessInteger (r, wl, wi)
SyntacticCode       r;
indLine             wl;
indLine             wi;

#endif /* __STDC__ */
{
   int                 n;

   n = AsciiToInt (wi, wl);
   switch (r)
	 {
	       /* r = numero de la regle ou apparait le nombre */
	    case RULE_ViewNum:
	       ViewNumber = n;
	       break;
	    default:
	       break;
	 }
}


/*----------------------------------------------------------------------
   ProcessToken traite le mot commencant a` la position wi dans la 
   ligne courante, de longueur wl et de code grammatical c.
   Si c'est un identif. r est le numero de la regle dans   
   laquelle apparait ce mot, pr est le numero de la regle  
   precedente, celle qui a appele la regle r.              
  ----------------------------------------------------------------------*/
#ifdef __STDC__
static void         ProcessToken (indLine wi, indLine wl, SyntacticCode c, SyntacticCode r, SyntacticCode pr)
#else  /* __STDC__ */
static void         ProcessToken (wi, wl, c, r, pr)
indLine             wi;
indLine             wl;
SyntacticCode       c;
SyntacticCode       r;
SyntacticCode       pr;

#endif /* __STDC__ */
{
   if (c < 1000)
     {
	/* symbole intermediaire de la grammaire, erreur */
	CompilerMessage (wi, APP, FATAL, INTERMEDIATE_SYMBOL, inputLine,
		       LineNum);
     }
   else if (c < 1100)
      /* mot-cle court */
      ProcessShortKeyWord (c, r, pr);
   else if (c < 2000)
      /* mot-cle long */
      ProcessLongKeyWord (c, r, wi);
   else
      /* type de base */
      switch (c)
	    {
	       case 3001:
		  /* un nom */
		  ProcessName (r, pr, wl, wi);
		  break;
	       case 3002:
		  /* un nombre */
		  ProcessInteger (r, wl, wi);
		  break;
	    }
}


/*----------------------------------------------------------------------
   WriteChar write a single character.                            
  ----------------------------------------------------------------------*/

#ifdef __STDC__
static void         WriteChar (FILE * Hfile, unsigned char ch)

#else  /* __STDC__ */
static void         WriteChar (Hfile, ch)
FILE               *Hfile;
unsigned char       ch;

#endif /* __STDC__ */

{
   int                 code;

   if (ch < ' ' || ch > '~')
      /* non ASCII character. Replace it by an ASCII character or its octal code */
     {
	code = (int) ch;
	switch (code)
	      {
		 case 224:
		 case 225:
		 case 226:
		 case 227:
		 case 228:
		 case 229:
		    fprintf (Hfile, "a");
		    break;
		 case 230:
		    fprintf (Hfile, "ae");
		    break;
		 case 231:
		    fprintf (Hfile, "c");
		    break;
		 case 232:
		 case 233:
		 case 234:
		 case 235:
		    fprintf (Hfile, "e");
		    break;
		 case 236:
		 case 237:
		 case 238:
		 case 239:
		    fprintf (Hfile, "i");
		    break;
		 case 160:
		    fprintf (Hfile, "_");
		    break;
		 case 241:
		    fprintf (Hfile, "n");
		    break;
		 case 242:
		 case 243:
		 case 244:
		 case 245:
		 case 246:
		 case 248:
		    fprintf (Hfile, "o");
		    break;
		 case 247:
		    fprintf (Hfile, "oe");
		    break;
		 case 249:
		 case 250:
		 case 251:
		 case 252:
		    fprintf (Hfile, "u");
		    break;
		 case 253:
		    fprintf (Hfile, "y");
		    break;
		 default:
		    fprintf (Hfile, "_%o", code);
		    break;
	      }
     }
   else
      /* printable character. Write it as is */
      fprintf (Hfile, "%c", ch);
}

/*----------------------------------------------------------------------
   WriteName                                                       
  ----------------------------------------------------------------------*/

#ifdef __STDC__
static void         WriteName (FILE * Hfile, Name n)

#else  /* __STDC__ */
static void         WriteName (Hfile, n)
FILE               *Hfile;
Name                n;

#endif /* __STDC__ */

{
   int                 i;

   i = 0;
   while (n[i] != '\0')
     {
	WriteChar (Hfile, n[i]);
	i++;
     }
}

/*----------------------------------------------------------------------
   WriteRuleName                                                   
  ----------------------------------------------------------------------*/

#ifdef __STDC__
static void         WriteRuleName (FILE * Hfile, int r)

#else  /* __STDC__ */
static void         WriteRuleName (Hfile, r)
FILE               *Hfile;
int                 r;

#endif /* __STDC__ */

{
   if (pSSchema->SsRule[r].SrName[0] == '\0')
      fprintf (Hfile, "ID%d", r+1);
   else
      WriteName (Hfile, pSSchema->SsRule[r].SrName);
}

/*----------------------------------------------------------------------
   WriteAttribute                                                  
  ----------------------------------------------------------------------*/

#ifdef __STDC__
static void         WriteAttribute (FILE * Hfile, int a)

#else  /* __STDC__ */
static void         WriteAttribute (Hfile, a)
FILE               *Hfile;
int                 a;

#endif /* __STDC__ */

{
   int                 j;
   TtAttribute        *pAttr;

   pAttr = &pSSchema->SsAttribute[a];
   if (pAttr->AttrGlobal)
      return;			/* AttrGlobal means "attribute written" */
   fprintf (Hfile, "#define ");
   WriteName (Hfile, pSSchema->SsName);
   fprintf (Hfile, "_ATTR_");
   WriteName (Hfile, pAttr->AttrName);
   fprintf (Hfile, " %d\n", a + 1);
   if (pAttr->AttrType == AtEnumAttr)
      for (j = 0; j < pAttr->AttrNEnumValues; j++)
	{
	   fprintf (Hfile, "#define ");
	   WriteName (Hfile, pSSchema->SsName);
	   fprintf (Hfile, "_ATTR_");
	   WriteName (Hfile, pAttr->AttrName);
	   fprintf (Hfile, "_VAL_");
	   WriteName (Hfile, pAttr->AttrEnumValue[j]);
	   fprintf (Hfile, " %d\n", j + 1);
	}
   pAttr->AttrGlobal = True;
}

/*----------------------------------------------------------------------
   WriteBasicElements                                              
  ----------------------------------------------------------------------*/

#ifdef __STDC__
static void         WriteBasicElements (FILE * Hfile)

#else  /* __STDC__ */
static void         WriteBasicElements (Hfile)
FILE               *Hfile;

#endif /* __STDC__ */

{
   int                 r;

   fprintf (Hfile, "#define ");
   WriteName (Hfile, pSSchema->SsName);
   r = CharString;
   fprintf (Hfile, "_EL_");
   WriteRuleName (Hfile, r);
   fprintf (Hfile, " %d\n", r+1);

   fprintf (Hfile, "#define ");
   WriteName (Hfile, pSSchema->SsName);
   r = GraphicElem;
   fprintf (Hfile, "_EL_");
   WriteRuleName (Hfile, r);
   fprintf (Hfile, " %d\n", r+1);

   fprintf (Hfile, "#define ");
   WriteName (Hfile, pSSchema->SsName);
   r = Symbol;
   fprintf (Hfile, "_EL_");
   WriteRuleName (Hfile, r);
   fprintf (Hfile, " %d\n", r+1);

   fprintf (Hfile, "#define ");
   WriteName (Hfile, pSSchema->SsName);
   r = Picture;
   fprintf (Hfile, "_EL_");
   WriteRuleName (Hfile, r);
   fprintf (Hfile, " %d\n", r+1);

   fprintf (Hfile, "#define ");
   WriteName (Hfile, pSSchema->SsName);
   r = PageBreak;
   fprintf (Hfile, "_EL_");
   WriteRuleName (Hfile, r);
   fprintf (Hfile, " %d\n", r+1);
}

/*----------------------------------------------------------------------
   WriteRule                                                       
   si pExtensRule est non nul, il s'agit d'une regle d'extension  
  ----------------------------------------------------------------------*/

#ifdef __STDC__
static void         WriteRule (FILE * Hfile, int r, SRule * pExtensRule)

#else  /* __STDC__ */
static void         WriteRule (Hfile, r, pExtensRule)
FILE               *Hfile;
int                 r;
SRule              *pExtensRule;

#endif /* __STDC__ */

{
   int                 i;
   SRule              *pRule;

   if (pExtensRule != NULL)
      pRule = pExtensRule;
   else
      pRule = &pSSchema->SsRule[r];
   if (pRule->SrConstruct != CsNatureSchema &&
       !(pRule->SrConstruct == CsPairedElement && !pRule->SrFirstOfPair))
     {
	fprintf (Hfile, "#define ");
	WriteName (Hfile, pSSchema->SsName);
	if (pExtensRule == NULL)
	  {
	     fprintf (Hfile, "_EL_");
	     WriteRuleName (Hfile, r);
	  }
	else
	  {
	     fprintf (Hfile, "_EXT_");
	     if (pRule->SrName[0] == '\0')
		fprintf (Hfile, "Root");
	     else
		WriteName (Hfile, pRule->SrName);
	  }
	fprintf (Hfile, " %d\n", r+1);

	if (pRule->SrNLocalAttrs > 0)
	   for (i = 0; i < pRule->SrNLocalAttrs; i++)
	      WriteAttribute (Hfile, pRule->SrLocalAttr[i] - 1);
     }
}

/*----------------------------------------------------------------------
   WriteDefineFile                                                 
  ----------------------------------------------------------------------*/
#ifdef __STDC__
static void         WriteDefineFile (char *fname)

#else  /* __STDC__ */
static void         WriteDefineFile (fname)
char               *fname;

#endif /* __STDC__ */

{
   boolean             firstLocalAttribute;
   boolean             first;
   int                 firstRule;
   int                 i;
   int                 rule;
   SRule              *pRule;
   Name                HFileName;
   FILE               *Hfile;

   sprintf (HFileName, "%s.h", fname);
   Hfile = fopen (HFileName, "w");
   if (Hfile != NULL)
     {
        fprintf (Hfile, "/* File generated by app - do not edit! */\n");
        fprintf (Hfile, "/* #################################### */\n");
	fprintf (Hfile, "/* Types and attributes for the document type %s */\n", pSSchema->SsName);
	/* write global attributes */
	if (pSSchema->SsNAttributes > 0 && pSSchema->SsAttribute[0].AttrGlobal)
	   fprintf (Hfile, "\n/* Global attributes */\n");

	for (i = 0; i < pSSchema->SsNAttributes; i++)
	   if (pSSchema->SsAttribute[i].AttrGlobal)
	     {
		pSSchema->SsAttribute[i].AttrGlobal = False;
		/* tell WriteAttribute that it should write attribute values */
		WriteAttribute (Hfile, i);
		pSSchema->SsAttribute[i].AttrGlobal = True;
	     }
	/* write local attributes */
	firstLocalAttribute = True;
	for (i = 0; i < pSSchema->SsNAttributes; i++)
	   if (!pSSchema->SsAttribute[i].AttrGlobal)
	     {
		if (firstLocalAttribute)
		  {
		     fprintf (Hfile, "\n/* Local attributes */\n");
		     firstLocalAttribute = False;
		  }
		WriteAttribute (Hfile, i);
	     }
	/* write Thot basic types */
	fprintf (Hfile, "\n/* Basic elements */\n");
	WriteBasicElements (Hfile);

	/* write constants */
	rule = MAX_BASIC_TYPE;
	if (pSSchema->SsRule[rule].SrConstruct == CsConstant)
	  {
	     fprintf (Hfile, "\n/* Constants */\n");
	     while (pSSchema->SsRule[rule].SrConstruct == CsConstant)
		WriteRule (Hfile, rule++, NULL);
	  }
	firstRule = rule;
	/* write parameters */
	first = True;
	for (rule = firstRule; rule < pSSchema->SsNRules; rule++)
	   if (pSSchema->SsRule[rule].SrParamElem)
	     {
		if (first)
		  {
		     fprintf (Hfile, "\n/* Parameters */\n");
		     first = False;
		  }
		WriteRule (Hfile, rule, NULL);
	     }
	/* write rules */
	if (pSSchema->SsNRules >= firstRule)
	   fprintf (Hfile, "\n/* Elements */\n");
	for (rule = firstRule; rule < pSSchema->SsNRules; rule++)
	  {
	     pRule = &pSSchema->SsRule[rule];
	     /* skip parameters, associated elements, */
	     /* Extern and Included elements and units */
	     if (!pRule->SrParamElem &&
		 !pRule->SrAssocElem &&
		 !pRule->SrRefImportedDoc &&
		 !pRule->SrUnitElem)
		/* ignore lists added for associated elements */
		if (pRule->SrConstruct != CsList)
		   WriteRule (Hfile, rule, NULL);
		else if (!pSSchema->SsRule[pRule->SrListItem - 1].SrAssocElem)
		   WriteRule (Hfile, rule, NULL);
	  }
	/* write extension rules */
	if (pSSchema->SsExtension && pSSchema->SsNExtensRules > 0)
	  {
	     fprintf (Hfile, "\n/* Extension rules */\n");
	     for (rule = 0; rule < pSSchema->SsNExtensRules; rule++)
	       {
		  pRule = &pSSchema->SsExtensBlock->EbExtensRule[rule];
		  WriteRule (Hfile, rule, pRule);
	       }
	  }
	/* write associated elements */
	first = True;
	for (rule = firstRule; rule < pSSchema->SsNRules; rule++)
	   if (pSSchema->SsRule[rule].SrAssocElem)
	     {
		if (first)
		  {
		     fprintf (Hfile, "\n/* Associated elements */\n");
		     first = False;
		  }
		WriteRule (Hfile, rule, NULL);
	     }
	if (!first)
	   /* there is at least one associated element. Write LIST rules added */
	   /* for associated elements */
	  {
	     for (rule = firstRule; rule < pSSchema->SsNRules; rule++)
	       {
		  pRule = &pSSchema->SsRule[rule];
		  if (pRule->SrConstruct == CsList)
		     if (pSSchema->SsRule[pRule->SrListItem - 1].SrAssocElem)
			WriteRule (Hfile, rule, NULL);
	       }
	  }
	/* write exported elements */
	first = True;
	for (rule = firstRule; rule < pSSchema->SsNRules; rule++)
	   if (pSSchema->SsRule[rule].SrUnitElem)
	     {
		if (first)
		  {
		     fprintf (Hfile, "\n/* Units */\n");
		     first = False;
		  }
		WriteRule (Hfile, rule, NULL);
	     }

	first = True;
	for (rule = firstRule; rule < pSSchema->SsNRules; rule++)
	   if (pSSchema->SsRule[rule].SrConstruct == CsNatureSchema)
	     {
		if (first)
		  {
		     fprintf (Hfile, "\n/* Imported natures */\n");
		     first = False;
		  }
		fprintf (Hfile, "#define ");
		WriteName (Hfile, pSSchema->SsName);
		fprintf (Hfile, "_EL_");
		WriteRuleName (Hfile, rule);
		fprintf (Hfile, " %d\n", rule+1);
	     }
     }
}

/*----------------------------------------------------------------------
   Main pour le compilateur A.                                     
  ----------------------------------------------------------------------*/
#ifdef __STDC__
void                main (int argc, char **argv)
#else  /* __STDC__ */
void                main (argc, argv)
int                 argc;
char              **argv;

#endif /* __STDC__ */
{
   FILE               *filedesc;
   boolean             fileOK;
   char                buffer[200], cmd[800];
   char               *pwd, *ptr;
   Name                srceFileName;
   int                 i;
   int                 wi;	/* position du debut du mot courant dans la ligne */
   int                 wl;	/* longueur du mot courant */
   SyntacticType       wn;	/* SyntacticType du mot courant */
   SyntRuleNum         r;	/* numero de regle */
   SyntRuleNum         pr;	/* numero de la regle precedente */
   SyntacticCode       c;	/* code grammatical du mot trouve */
   int                 idNum;	/* indice dans Identifier du mot trouve, si */
   int                 nb;
   int                 param;

   TtaInitializeAppRegistry (argv[0]);
   /* no external action declared at that time */
   ActionList = NULL;
   APP = TtaGetMessageTable ("appdialogue", MSG_MAX_APP);
   COMPIL = TtaGetMessageTable ("compildialogue", COMP_MSG_MAX);
   error = False;
   /* initialize the parser */
   InitParser ();
   InitSyntax ("APP.GRM");
   if (!error)
     {
        /* prepare the cpp command */
	strcpy (cmd, "cpp ");
        param = 1;
	while (param < argc && argv[param][0] == '-')
	  {
	    /* keep cpp params */
	    strcat (cmd, argv[param]);
	    strcat (cmd, " ");
	    param++;
	  }
	/* keep the name of the schema to be compile */
	if (param >= argc)
	  {
	     TtaDisplaySimpleMessage (FATAL, APP, FILE_NOT_FOUND);
	     exit (1);
	  }
	else
	  {
	     /* get the name of the file to be compiled */
	     strncpy (srceFileName, argv[param], MAX_NAME_LENGTH - 1);
	     srceFileName[MAX_NAME_LENGTH - 1] = '\0';
	     param++;
	     strcpy (fileName, srceFileName);
	     /* check if the name contains a suffix */
	     ptr = strrchr(fileName, '.');
	     nb = strlen (srceFileName);
	     if (!ptr)
	       /* there is no suffix */
	       strcat (srceFileName, ".A");
	     else if (strcmp(ptr, ".A"))
	       {
		 /* it's not the valid suffix */
		 TtaDisplayMessage (FATAL, TtaGetMessage(APP, INVALID_FILE), srceFileName);
		 exit (1);
	       }
	     else
	       {
		 /* it's the valid suffix, cut the srcFileName here */
		 ptr[0] = '\0';
		 nb -= 2; /* length without the suffix */
	       }

	     /* add the suffix .SCH in srceFileName */
	     strcat (fileName, ".SCH");
	     
	     /* does the file to compile exist */
	     if (TtaFileExist (srceFileName) == 0)
	       TtaDisplaySimpleMessage (FATAL, APP, FILE_NOT_FOUND);
	     else
	       {
		 /* provide the real source file */
		 TtaFileUnlink (fileName);
		 pwd = TtaGetEnvString ("PWD");
		 i = strlen (cmd);
		 if (pwd != NULL)
		   sprintf (&cmd[i], "-I%s -C %s > %s", pwd, srceFileName, fileName);
		 else
		   sprintf (&cmd[i], "-C %s > %s", srceFileName, fileName);
		 i = system (cmd);
		 if (i == -1)
		   {
		     /* cpp is not available, copy directely the file */
		     TtaDisplaySimpleMessage (INFO, APP, APP_CPP_NOT_FOUND);
		     TtaFileCopy (srceFileName, fileName);
		   }

		 /* open the resulting file */
		 filedesc = TtaReadOpen (fileName);
		 /* ouvre le fichier a compiler */
		 if (filedesc == 0)
		   TtaDisplaySimpleMessage (FATAL, APP, FILE_NOT_FOUND);
		 else
		   {
		     /* suppress the suffix ".SCH" */
		     srceFileName[nb] = '\0';
		     fileName[nb] = '\0';
		     /* le fichier a compiler est ouvert */
		     NIdentifiers = 0;
		     /* table des identificateurs vide */
		     LineNum = 0;
		     /* encore aucune ligne lue */
		     pSSchema = NULL;
		     /* pas (encore) de schema de structure */
		     fileOK = True;
		     /* lit tout le fichier et fait l'analyse */
		     while (fileOK && !error)
		       /* lit une ligne */
		       {
			 i = 0;
			 do
			   fileOK = TtaReadByte (filedesc, &inputLine[i++]);
			 while (i < LINE_LENGTH && inputLine[i - 1] != '\n' && fileOK);
			 /* marque la fin reelle de la ligne */
			 inputLine[i - 1] = '\0';
			 /* incremente le compteur de lignes lues */
			 LineNum++;
			 if (i >= LINE_LENGTH)
			   /* ligne trop longue */
			   CompilerMessage (1, APP, FATAL, MAX_LINE_SIZE_EXCEEDED, inputLine, LineNum);
			 else if (inputLine[0] == '#')
			   /* cette ligne contient une directive du preprocesseur cpp */
			   {
			     sscanf (inputLine, "# %d %s", &LineNum, buffer);
			     LineNum--;
			   }
			 else
			   /* traduit tous les caracteres de la ligne */
			   {
			     OctalToChar ();
			     /* analyse la ligne */
			     wi = 1;
			     wl = 0;
			     /* analyse tous les mots de la ligne courante */
			     do
			       {
				 i = wi + wl;
				 GetNextToken (i, &wi, &wl, &wn);
				 /* mot suivant */
				 if (wi > 0)
				   /* on a trouve un mot */
				   {
				     AnalyzeToken (wi, wl, wn, &c, &r, &idNum, &pr);
				     /* on analyse le mot */
				     if (!error)
				       /* on le traite */
				       ProcessToken (wi, wl, c, r, pr);
				   }
			       }
			     while (wi != 0 && !error);
			     /* il n'y a plus de mots a analyser dans la ligne */
			   }
		       }
		     /* fin du fichier */
		     if (!error)
		       ParserEnd ();
		     /* fin d'analyse */
		     if (!error)
		       {
			 MakeMenusAndActionList ();
			 /* ecrit le schema compile' dans le fichier de sortie     */
			 /* le directory des schemas est le directory courant      */
			 SchemaPath[0] = '\0';
			 strcpy (srceFileName, fileName);
			 GenerateApplication (srceFileName, pAppli);
			 strcpy (srceFileName, fileName);
			 if (strcmp (srceFileName, "EDITOR") != 0)
			   WriteDefineFile (srceFileName);
		       }
		   }
	       }
	  }
     }
   TtaSaveAppRegistry ();
   exit (0);
}
