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
   Edition functions == file, view, import, and export menus
 *
 * Authors: I. Vatton (INRIA)
 *          N. Layaida (INRIA) - New picture formats
 *
 */

#include "thot_sys.h"
#include "constmenu.h"
#include "constmedia.h"
#include "typemedia.h"
#include "app.h"
#include "appdialogue.h"
#include "tree.h"
#include "libmsg.h"
#include "message.h"
#include "dialog.h"
#include "application.h"
#include "document.h"

#include "picture.h"
#undef THOT_EXPORT
#define THOT_EXPORT extern
#define _MENU_IMAGE_FRAME	1
#define _ZONE_DIR_IMAGE		2
#define _IMAGE_FORM		3
#define _ZONE_IMAGE_FILE	4
#define _IMAGE_SEL		5
#define _MENU_IMAGE_TYPE	6
#define MAX_IMAGE_MENU		7
extern PathBuffer   DocumentPath;
extern PathBuffer   SchemaPath;
extern char        *FileExtension[];

#undef THOT_EXPORT
#define THOT_EXPORT static

static int          IndexTypeImage, IndexPresImage, BaseDlgImage;
static boolean      RedisplayPicture;
static char         ImageName[100] = "";
static char         DirectoryImage[MAX_PATH] = "";

#include "browser_f.h"
#include "fileaccess_f.h"
#include "picture_f.h"
#include "actions_f.h"
#include "savedoc_f.h"

/*----------------------------------------------------------------------
   CheckPresImage
   validates or invalidates the presentation type according to the
   image type.
  ----------------------------------------------------------------------*/
#ifdef __STDC__
static void         CheckPresImage (int indexType)
#else  /* __STDC__ */
static void         CheckPresImage (indexType)
int                 indexType;
#endif /* __STDC__ */
{
  if (indexType == XBM_FORMAT || indexType == XPM_FORMAT)
    {
      /* Strech not allowed */
      UnsetEntryMenu (BaseDlgImage + _MENU_IMAGE_FRAME, (int)ReScale);
      TtaRedrawMenuEntry (BaseDlgImage + _MENU_IMAGE_FRAME, (int)FillFrame, NULL, -1, 1);
      TtaRedrawMenuEntry (BaseDlgImage + _MENU_IMAGE_FRAME, (int)XRepeat, NULL, -1, 1);
      TtaRedrawMenuEntry (BaseDlgImage + _MENU_IMAGE_FRAME, (int)YRepeat, NULL, -1, 1);
      if (IndexPresImage == (int) ReScale)
	IndexPresImage = (int) RealSize;
    }
  else if (indexType == EPS_FORMAT)
    {
      /* Any repeat not allowed */
      TtaRedrawMenuEntry (BaseDlgImage + _MENU_IMAGE_FRAME, (int)ReScale, NULL, -1, 1);
      UnsetEntryMenu (BaseDlgImage + _MENU_IMAGE_FRAME, (int)FillFrame);
      UnsetEntryMenu (BaseDlgImage + _MENU_IMAGE_FRAME, (int)XRepeat);
      UnsetEntryMenu (BaseDlgImage + _MENU_IMAGE_FRAME, (int)YRepeat);
      if (IndexPresImage == (int) FillFrame ||
	  IndexPresImage == (int) XRepeat ||
	  IndexPresImage == (int) YRepeat)
	IndexPresImage = (int) ReScale;
    }
  else
    {
      /* All presentation allowed */
      TtaRedrawMenuEntry (BaseDlgImage + _MENU_IMAGE_FRAME, (int)ReScale, NULL, -1, 1);
      TtaRedrawMenuEntry (BaseDlgImage + _MENU_IMAGE_FRAME, (int)FillFrame, NULL, -1, 1);
      TtaRedrawMenuEntry (BaseDlgImage + _MENU_IMAGE_FRAME, (int)XRepeat, NULL, -1, 1);
      TtaRedrawMenuEntry (BaseDlgImage + _MENU_IMAGE_FRAME, (int)YRepeat, NULL, -1, 1);
    }
  /* set the selected presentation of default one */
  TtaSetMenuForm (BaseDlgImage + _MENU_IMAGE_FRAME, IndexPresImage);
}

/*----------------------------------------------------------------------
   InitPathImage
   inits the images paths.
  ----------------------------------------------------------------------*/
static void         InitPathImage ()
{
   char                bufDir[MAX_PATH * 2];
   int                 i, j;
   int                 nb;
   int                 max;

   /* remplace ':' par EOS pour le formulaire de saisie des images */
   nb = 1;
   max = MAX_PATH * 2;
   j = 0;
   /* paths des schemas */
   for (i = 0; i < MAX_PATH && SchemaPath[i] != EOS; i++)
      if (SchemaPath[i] == PATH_SEP)
	{
	   if (bufDir[j - 1] != EOS)
	     {
		bufDir[j++] = EOS;
		nb++;
	     }
	}
      else
	 bufDir[j++] = SchemaPath[i];

   if (j < max)
      bufDir[j++] = EOS;
   else
      bufDir[j - 1] = EOS;

   /* paths des documents */
   nb++;
   for (i = 0; i < MAX_PATH && DocumentPath[i] != EOS; i++)
      if (DocumentPath[i] == PATH_SEP)
	{
	   if (bufDir[j - 1] != EOS)
	     {
		bufDir[j++] = EOS;
		nb++;
	     }
	}
      else
	 bufDir[j++] = DocumentPath[i];

   if (j < max)
      bufDir[j] = EOS;
   else
      bufDir[j - 1] = EOS;
   TtaNewSelector (BaseDlgImage + _ZONE_DIR_IMAGE, BaseDlgImage + _IMAGE_FORM, "Dossiers documents",
		   nb, bufDir, 9, NULL, FALSE, TRUE);
}


/*----------------------------------------------------------------------
   CallbackPictureMenu
   records the return values of the Picture form.
  ----------------------------------------------------------------------*/
#ifdef __STDC__
void                CallbackPictureMenu (int ref, int typeData, char *txt)

#else  /* __STDC__ */
void                CallbackPictureMenu (ref, typeData, txt)
int                 ref;
int                 typeData;
char               *txt;

#endif /* __STDC__ */
{
   PathBuffer          completeName;
   int                 i, val;
   char                URL_DIR_SEP;

   if (typeData == STRING_DATA && txt && strchr (txt, '/'))
     URL_DIR_SEP = '/';
   else 
     URL_DIR_SEP = DIR_SEP;

   val = (int) txt;
   switch (ref - BaseDlgImage)
     {
     case _ZONE_IMAGE_FILE:
       if (TtaCheckDirectory (txt) && txt[strlen (txt) - 1] != URL_DIR_SEP)
	 {
	   strcpy (DirectoryImage, txt);
	   ImageName[0] = EOS;
	 }
       else
	 {
	   /* conserve le nom du document a ouvrir */
	   TtaExtractName (txt, DirectoryImage, ImageName);
	   if (ImageName[0] == EOS && !TtaCheckDirectory (DirectoryImage))
	     {
	       /* Le texte correspond au nom de l'image sans directory */
	       strncpy (ImageName, DirectoryImage, 100);
	       DirectoryImage[0] = EOS;
	     }
	 }
       
       if (TtaCheckDirectory (DirectoryImage))
	 {
	   /* Est-ce un nouveau directory qui contient des documents */
	   if (!TtaIsInDocumentPath (DirectoryImage))
	     if (TtaIsSuffixFileIn (DirectoryImage, FileExtension[IndexTypeImage]))
	       {
		 /* il faut ajouter le directory au path */
		 i = strlen (DocumentPath);
		 if (i + strlen (DirectoryImage) + 2 < MAX_PATH)
		   {
		     strcat (DocumentPath, PATH_STR);
		     strcat (DocumentPath, DirectoryImage);
		     InitPathImage ();
		     TtaListDirectory (DirectoryImage, BaseDlgImage + _IMAGE_FORM, NULL, -1,
				       FileExtension[IndexTypeImage], TtaGetMessage (LIB, TMSG_FILES), BaseDlgImage + _IMAGE_SEL);
		   }
	       }
	 }
       break;
     case _IMAGE_SEL:
       if (DirectoryImage[0] == EOS)
	 {
	   /* compose le path complet du fichier pivot */
	   strncpy (DirectoryImage, DocumentPath, MAX_PATH);
	   /* recheche indirectement le directory */
	   MakeCompleteName (txt, "", DirectoryImage, completeName, &i);
	   /* separe directory et nom */
	   TtaExtractName (completeName, DirectoryImage, ImageName);
	 }
       else
	 {
	   strcpy (completeName, DirectoryImage);
	   strcat (completeName, "/");
	   strcat (completeName, txt);
	   strcpy (ImageName, txt);
	 }
       TtaSetTextForm (BaseDlgImage + _ZONE_IMAGE_FILE, completeName);
       break;
     case _MENU_IMAGE_TYPE:
       if (val != IndexTypeImage)
	 {
	   IndexTypeImage = val;
	   if (TtaCheckDirectory (DirectoryImage))
	     {
	       /* Est-ce un nouveau directory qui contient des documents */
	       if (!TtaIsInDocumentPath (DirectoryImage))
		 if (TtaIsSuffixFileIn (DirectoryImage, FileExtension[IndexTypeImage]))
		   {
		     /* il faut ajouter le directory au path */
		     i = strlen (DocumentPath);
		     if (i + strlen (DirectoryImage) + 2 < MAX_PATH)
		       {
			 strcat (DocumentPath, ":");
			 strcat (DocumentPath, DirectoryImage);
			 InitPathImage ();
		       }
		   }
	     }
	   TtaListDirectory (DirectoryImage, BaseDlgImage + _IMAGE_FORM, NULL, -1,
			     FileExtension[IndexTypeImage], TtaGetMessage (LIB, TMSG_FILES), BaseDlgImage + _IMAGE_SEL);
	   CheckPresImage (val);
	 }
       break;
     case _MENU_IMAGE_FRAME:
       if (val != IndexPresImage)
	 {
	   IndexPresImage = val;
	   /* Faut-il mettre a jour la liste des fichiers */
	   if (DirectoryImage[0] != EOS)
	     TtaListDirectory (DirectoryImage, BaseDlgImage + _IMAGE_FORM, NULL, -1,
			       FileExtension[IndexTypeImage], TtaGetMessage (LIB, TMSG_FILES), BaseDlgImage + _IMAGE_SEL);
	 }
       break;
     case _ZONE_DIR_IMAGE:
       strcpy (DirectoryImage, txt);
       TtaSetTextForm (BaseDlgImage + _ZONE_IMAGE_FILE, DirectoryImage);
       TtaListDirectory (DirectoryImage, BaseDlgImage + _IMAGE_FORM, NULL, -1,
			 FileExtension[IndexTypeImage], TtaGetMessage (LIB, TMSG_FILES), BaseDlgImage + _IMAGE_SEL);
       break;
     case _IMAGE_FORM:
       if (val == 1)
	 /* Edition realisee */
	 RedisplayPicture = TRUE;
       TtaDestroyDialogue (BaseDlgImage + _IMAGE_FORM);
       break;
     default:
       break;
     }
}


/*----------------------------------------------------------------------
  BuildPictureMenu
  This menu is called whenever an image is modified.
  ----------------------------------------------------------------------*/
#ifdef __STDC__
void                BuildPictureMenu (char *name, boolean * result, int *typim, int *pres, PtrBox pBox)
#else  /* __STDC__ */
void                BuildPictureMenu (name, result, typim, pres, pBox)
char               *name;
boolean            *result;
int                *typim;
int                *pres;
int                *pres;
PtrBox              pBox;
#endif /* __STDC__ */
{
   int                 i, indx;
   char                bufTypeImage[MAX_TXT_LEN];
   char               *source;
   int                 imageTypeCount, length;
   char                bufMenu[MAX_TXT_LEN];
   PictInfo           *image;

   IndexTypeImage = GetPictTypeIndex (*typim);
   IndexPresImage = GetPictPresIndex (*pres);
   strcpy (ImageName, name);
   DirectoryImage[0] = EOS;
   RedisplayPicture = FALSE;

   TtaNewForm (BaseDlgImage + _IMAGE_FORM,  0, TtaGetMessage (LIB, TMSG_PICTURE), TRUE, 2, 'L', D_CANCEL);
   InitPathImage ();

   /* liste des fichiers existants */
   TtaListDirectory (DirectoryImage, BaseDlgImage + _IMAGE_FORM, NULL, -1, "", TtaGetMessage (LIB, TMSG_FILES), BaseDlgImage + _IMAGE_SEL);

   /* sous-menu des types d'image du formulaire Picture */
   indx = 0;
   GetPictHandlersList (&imageTypeCount, bufTypeImage);
   /* ajoute un 'B' au debut de chaque entree du menu construit */
   source = &bufTypeImage[0];
   for (i = 1; i <= imageTypeCount; i++)
     {
	bufMenu[indx] = 'B';
	indx++;
	length = strlen (source) + 1;
	if (indx + length < MAX_TXT_LEN)
	  {
	     strcpy ((bufMenu) + indx, source);
	     indx += length;
	  }
	source += length;
     }
   TtaNewSubmenu (BaseDlgImage + _MENU_IMAGE_TYPE, BaseDlgImage + _IMAGE_FORM, 0, TtaGetMessage (LIB, TMSG_PICT_TYPE),
		  imageTypeCount, bufMenu, NULL, TRUE);

   /* sous-menu cadrage du formulaire Picture */
   indx = 0;
   sprintf (&bufMenu[indx], "%s%s", "B", TtaGetMessage (LIB, TMSG_REALSIZE));
   indx += strlen (&bufMenu[indx]) + 1;
   sprintf (&bufMenu[indx], "%s%s", "B", TtaGetMessage (LIB, TMSG_RESCALE));
   indx += strlen (&bufMenu[indx]) + 1;
   sprintf (&bufMenu[indx], "%s%s", "B", TtaGetMessage (LIB, TMSG_FILLFRAME));
   indx += strlen (&bufMenu[indx]) + 1;
   sprintf (&bufMenu[indx], "%s%s", "B", TtaGetMessage (LIB, TMSG_XREPEAT));
   indx += strlen (&bufMenu[indx]) + 1;
   sprintf (&bufMenu[indx], "%s%s", "B", TtaGetMessage (LIB, TMSG_YREPEAT));
   TtaNewSubmenu (BaseDlgImage + _MENU_IMAGE_FRAME, BaseDlgImage + _IMAGE_FORM, 0,
		  TtaGetMessage (LIB, TMSG_PICT_PRES), 5, bufMenu, NULL, FALSE);

   /* zone de saisie du nom du fichier image */
   TtaNewTextForm (BaseDlgImage + _ZONE_IMAGE_FILE, BaseDlgImage + _IMAGE_FORM,
		   TtaGetMessage (LIB, TMSG_PICT_FILE), 50, 1, TRUE);

   TtaSetSelector (BaseDlgImage + _ZONE_DIR_IMAGE, -1, "");
   TtaSetTextForm (BaseDlgImage + _ZONE_IMAGE_FILE, name);
   TtaSetMenuForm (BaseDlgImage + _MENU_IMAGE_TYPE, IndexTypeImage);
   TtaSetMenuForm (BaseDlgImage + _MENU_IMAGE_FRAME, IndexPresImage);
   CheckPresImage (IndexTypeImage);
   /* active le formulaire */
   TtaShowDialogue (BaseDlgImage + _IMAGE_FORM, FALSE);
   /* attend le retour du formulaire */
   TtaWaitShowDialogue ();
   if (ImageName[0] == EOS)
      RedisplayPicture = FALSE;

   if (RedisplayPicture)
     {
	strcpy (name, ImageName);
	*typim = GetPictureType (IndexTypeImage);
	*pres = (PictureScaling) (IndexPresImage);
	image = (PictInfo *) pBox->BxPictInfo;
	strcpy (image->PicFileName, name);
	image->PicPresent = (PictureScaling) *pres;
	image->PicType = *typim;
     }
   *result = RedisplayPicture;
}
/*----------------------------------------------------------------------
  ImageMenuLoadResources
  ----------------------------------------------------------------------*/
void                ImageMenuLoadResources ()

{
   BaseDlgImage = TtaSetCallback (CallbackPictureMenu, MAX_IMAGE_MENU);
   if (BaseDlgImage != 0)
      TteConnectAction (T_imagemenu, (Proc) BuildPictureMenu);
}
