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
 * Creation commands
 *
 * Author: I. Vatton (INRIA)
 *
 */
 
#include "thot_gui.h"
#include "thot_sys.h"
#include "constmenu.h"
#include "app.h"
#include "constmedia.h"
#include "typemedia.h"
#include "appdialogue.h"
#include "tree.h"
#include "libmsg.h"
#include "message.h"
#include "dialog.h"
#include "document.h"
#include "fileaccess.h"
#include "thotdir.h"

#undef THOT_EXPORT
#define THOT_EXPORT extern
#include "edit_tv.h"
#include "appdialogue_tv.h"
#include "platform_tv.h"
int                 CurrentDialog;

static char         NameDocToCreate[100] = "";
static char         ClassDocToCreate[100] = "";
static char         DirectoryDocToCreate[MAX_PATH] = "";

#include "structschema_f.h"
#include "browser_f.h"
#include "platform_f.h"
#include "appdialogue_f.h"
#include "actions_f.h"
#include "views_f.h"
#include "config_f.h"
#include "opendoc_f.h"
#include "docs_f.h"
#include "applicationapi_f.h"

/*----------------------------------------------------------------------
   CallbackConfirmMenu
   updates the confirmation menu.
  ----------------------------------------------------------------------*/
#ifdef __STDC__
void                CallbackConfirmMenu (int ref, int typeData, char *data)
#else  /* __STDC__ */
void                CallbackConfirmMenu (ref, typeData, data)
int                 ref;
int                 typeData;
char               *data;

#endif /* __STDC__ */

{
   PtrDocument         pDoc;

   if ((int) data == 0)
      /* reprends le dialogue courant */
      TtaShowDialogue (CurrentDialog, FALSE);
   else
     {
	if (ref != 0)
	   if (CurrentDialog == NumFormCreateDoc)
	     {
		/* confirme la creation */
		CreateDocument (&pDoc);		/* acquiert un contexte de document */
		if (pDoc != NULL)
		   /* cree un document dans ce contexte */
		   NewDocument (&pDoc, (PtrBuffer) ClassDocToCreate,
				NameDocToCreate, DirectoryDocToCreate);
	     }
	   else if (CurrentDialog == NumFormSaveAs)
	      if (CurrentDialog != 0)
		{		/* confirme la sauvegarde */
		   if (ThotLocalActions[T_savedoc] != NULL)
		      (*ThotLocalActions[T_savedoc]) ();
		}

	TtaDestroyDialogue (CurrentDialog);
	TtaDestroyDialogue (NumFormConfirm);
     }
}


/*----------------------------------------------------------------------
   CallbackNewDocMenu
   updates the createdoc menu
  ----------------------------------------------------------------------*/
#ifdef __STDC__
void                CallbackNewDocMenu (int ref, int typeData, char *data)
#else  /* __STDC__ */
void                CallbackNewDocMenu (ref, typeData, data)
int                 ref;
int                 typeData;
char               *data;

#endif /* __STDC__ */

{
   PathBuffer          docName;
   int                 i;
   char                BufDir[MAX_PATH];
   char                URL_DIR_SEP;

   if (typeData == STRING_DATA && data && strchr (data, '/'))
     URL_DIR_SEP = '/';
   else 
     URL_DIR_SEP = DIR_SEP;

   switch (ref)
	 {
	    case NumFormCreateDoc:
	       /* le formulaire "Creer un document" lui-meme */
	       if (NameDocToCreate[0] == '\0')
		  /* le nom par defaut */
		  strcpy (NameDocToCreate, TtaGetMessage (LIB, TMSG_NO_NAME));
	       CurrentDialog = NumFormCreateDoc;
	       if (ClassDocToCreate[0] != '\0' && ((int) data) == 1)
		 {
		    /* on a tous les parametres */
		    /* ******** verifier que le document n'esixte pas deja **** */
		    strcpy (docName, DirectoryDocToCreate);
		    strcat (docName, DIR_STR);
		    strcat (docName, NameDocToCreate);
		    strcat (docName, ".PIV");

		    if (!TtaCheckDirectory (DirectoryDocToCreate))
		       TtaDisplayMessage (INFO, TtaGetMessage (LIB, TMSG_MISSING_DIR), DirectoryDocToCreate);
		    else
		      {
			 if (TtaFileExist (docName))
			   {
			      /* demande confirmation */
			      sprintf (BufDir, TtaGetMessage (LIB, TMSG_FILE_EXIST), docName);
			      TtaNewLabel (NumLabelConfirm, NumFormConfirm, BufDir);
/*           ClassDocToCreate[0] = '\0'; */
			      TtaSetDialoguePosition ();
			      TtaShowDialogue (NumFormConfirm, FALSE);
			   }
			 else
			    /* traite la confirmation */
			 if (ThotLocalActions[T_confirmcreate] != NULL)
			    (*ThotLocalActions[T_confirmcreate]) (NumFormConfirm, 1, (char *) 1);
		      }
		 }
	       else
		  /* annulation : on detruit les dialogues */
		 {
		    if (ThotLocalActions[T_confirmcreate] != NULL)
		       (*ThotLocalActions[T_confirmcreate]) (0, 1, (char *) 1);
		 }
	       /*ClassDocToCreate[0] = '\0'; */
	       break;
	    case NumZoneDocNameToCreate:
	       /* zone de saisie du nom du document a creer */
	       if (TtaCheckDirectory (data) && data[strlen (data) - 1] != URL_DIR_SEP)
		 {
		    strcpy (DirectoryDocToCreate, data);
		    NameDocToCreate[0] = '\0';
		 }
	       else
		 {
		    /* conserve le nom du document a ouvrir */
		    TtaExtractName (data, DirectoryDocToCreate, docName);
		    if (strlen (docName) >= MAX_NAME_LENGTH)
		       docName[MAX_NAME_LENGTH - 1] = '\0';	/* limite la longueur des noms */
		    strcpy (NameDocToCreate, docName);
		 }
	       if (TtaCheckDirectory (DirectoryDocToCreate))
		 {
		    /* Est-ce un nouveau directory qui contient des documents */
		    if (!TtaIsInDocumentPath (DirectoryDocToCreate))
		       if (TtaIsSuffixFileIn (DirectoryDocToCreate, ".PIV"))
			 {
			    /* il faut ajouter le directory au path */
			    i = strlen (DocumentPath);
			    if (i + strlen (DirectoryDocToCreate) + 2 < MAX_PATH)
			      {
				 strcat (DocumentPath, PATH_STR);
				 strcat (DocumentPath, DirectoryDocToCreate);
				 BuildPathDocBuffer (BufDir, '\0', &i);
				 TtaNewSelector (NumZoneDocDirToCreate, NumFormCreateDoc, TtaGetMessage (LIB, TMSG_DOC_DIR), i, BufDir, 9, NULL, FALSE, TRUE);
			      }
			 }
		 }
	       break;
	    case NumZoneDocDirToCreate:
	       /* zone de saisie du directory ou le document doit etre cree */
	       strcpy (DirectoryDocToCreate, data);
	       strcpy (docName, DirectoryDocToCreate);
	       strcat (docName, DIR_STR);
	       strcat (docName, NameDocToCreate);
	       TtaSetTextForm (NumZoneDocNameToCreate, docName);
	       break;
	    case NumSelDocClassToCreate:
	       /* selecteur classe du document a creer */
	       strncpy (ClassDocToCreate, data, MAX_NAME_LENGTH);
	       break;
	 }
}


/*----------------------------------------------------------------------
   TtcCreateDocument
   starts the change of createdoc.
  ----------------------------------------------------------------------*/
#ifdef __STDC__
void                TtcCreateDocument (Document document, View view)

#else  /* __STDC__ */
void                TtcCreateDocument (document, view)
Document            document;
View                view;

#endif /* __STDC__ */
{
   PathBuffer          docName;
   char               *ptr;
   int                 i = 0, length, nbitem;
   int		       entry = 0;
   char                BufMenu[MAX_TXT_LEN];
   char                BufDir[MAX_PATH];
   ThotWidget	       parentWidget;

   if (ThotLocalActions[T_createdoc] == NULL)
     {
	/* Connecte les actions liees au traitement de la createdoc */
	TteConnectAction (T_createdoc, (Proc) CallbackNewDocMenu);
	TteConnectAction (T_confirmcreate, (Proc) CallbackConfirmMenu);
	TteConnectAction (T_buildpathdocbuffer, (Proc) BuildPathDocBuffer);
     }
   /* Creation du formulaire Creer document */
   /* +++++++++++++++++++++++++++++++++++++ */
   parentWidget = TtaGetViewFrame (document, view);
   TtaNewForm (NumFormCreateDoc,  parentWidget,
	       TtaGetMessage (LIB, TMSG_CREATE_DOC), TRUE, 2, 'L', D_CANCEL);
   /* zone de saisie des dossiers documents */
   BuildPathDocBuffer (BufDir, '\0', &nbitem);
   if (DirectoryDocToCreate[0]!='\0')
     entry=SearchStringInBuffer(BufDir,DirectoryDocToCreate,nbitem);
   TtaNewSelector (NumZoneDocDirToCreate, NumFormCreateDoc,
   TtaGetMessage (LIB, TMSG_DOC_DIR), nbitem, BufDir, 9, NULL, FALSE, TRUE);
   if (nbitem >= 1 && entry!= -1)
      TtaSetSelector (NumZoneDocDirToCreate, entry, NULL);
   /* nom du document a creer */
   if (DocumentPath!=NULL && (DirectoryDocToCreate[i] == '\0' || entry == -1))
     {
	ptr = strstr (DocumentPath, PATH_STR);
	if (ptr == NULL)
	   strcpy (DirectoryDocToCreate, DocumentPath);
	else
	  {
	     i = (int) ptr - (int) DocumentPath;
	     strncpy (DirectoryDocToCreate, DocumentPath, i);
	     DirectoryDocToCreate[i] = '\0';
	  }
     }
   strcpy (NameDocToCreate, TtaGetMessage (LIB, TMSG_NO_NAME));
   strcpy (docName, DirectoryDocToCreate);
   strcat (docName, DIR_STR);
   strcat (docName, NameDocToCreate);
   /* compose le selecteur des types de documents que l'utilisateur peut */
   /* creer */
   nbitem = ConfigMakeDocTypeMenu (BufMenu, &length, TRUE);
   if (nbitem > 0)
      /* le fichier Start Up definit des classes de documents */
     {
	/* calcule la hauteur de la partie menu du selecteur */
	if (nbitem < 5)
	   length = nbitem;
	else
	   length = 5;
	/* cree le selecteur */
	TtaNewSelector (NumSelDocClassToCreate, NumFormCreateDoc,
			TtaGetMessage (LIB, TMSG_DOC_TYPE), nbitem, BufMenu, length, NULL, TRUE, FALSE);
	entry = 0;
	if(ClassDocToCreate[0]!='\0')
	  entry=SearchStringInBuffer(BufMenu,ClassDocToCreate,nbitem);
	/* initialise le selecteur sur sa premiere entree */
	
	TtaSetSelector (NumSelDocClassToCreate, entry, ClassDocToCreate);
     }
   else
      /* on n'a pas cree' de selecteur, on cree une zone de saisie */
     {
       TtaNewTextForm (NumSelDocClassToCreate, NumFormCreateDoc,
		       TtaGetMessage (LIB, TMSG_DOC_TYPE), 30, 1, FALSE);
       if(ClassDocToCreate[0]!='\0')
	 TtaSetTextForm (NumSelDocClassToCreate,ClassDocToCreate);
     }
   /* zone de saisie du nom du document a creer */
   TtaNewTextForm (NumZoneDocNameToCreate, NumFormCreateDoc,
		   TtaGetMessage (LIB, TMSG_DOCUMENT_NAME), 50, 1, TRUE);
   TtaSetTextForm (NumZoneDocNameToCreate, docName);

   /* Formulaire Confirmation creation */
   /* ++++++++++++++++++++++++++++++++ */
   strcpy (BufMenu, TtaGetMessage (LIB, TMSG_RENAME));
   i = strlen (BufMenu) + 1;
   strcpy (&BufMenu[i], TtaGetMessage (LIB, TMSG_LIB_CONFIRM));
   TtaNewDialogSheet (NumFormConfirm, parentWidget, NULL, 2, BufMenu, FALSE, 1, 'L');

/* affichage du formulaire Creer document */
   TtaSetDialoguePosition ();
   TtaShowDialogue (NumFormCreateDoc, FALSE);
}











