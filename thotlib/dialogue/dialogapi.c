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
 * Dialogue API routines
 *
 * Author: I. Vatton (INRIA)
 *         R. Guetari (W3C/INRIA): Windows NT/95 routines
 *
 */

#include "thot_gui.h"
#include "thot_sys.h"
#include "constmedia.h"
#include "typemedia.h"
#include "copyright.xbm"
#include "dialog.h"

#include "application.h"
#include "interface.h"
#include "appdialogue.h"
#include "appli_f.h"
#include "message.h"

#ifdef _WINDOWS
#include "winsys.h"
#endif /* _WINDOWS */

#define THOT_EXPORT extern
#include "thotcolor_tv.h"
#include "frame_tv.h"
#include "font_tv.h"

/* Catalogues structures */
#define CAT_INT        0
#define CAT_TEXT       1
#define CAT_FORM       2
#define CAT_MENU       3
#define CAT_POPUP      4
#define CAT_FMENU      5
#define CAT_SHEET      6
#define CAT_SELECT     7
#define CAT_TMENU      8
#define CAT_LABEL      9
#define CAT_DIALOG    10
#define CAT_PULL      11
#define CAT_ICON      12

#define MAX_CAT       20
#define C_NUMBER      15
#define INTEGER_DATA   1
#define STRING_DATA    2
#define MAX_TXTMSG   120
#define MAX_ARGS      20

struct E_List
  {
     struct E_List      *E_Next;	         /* CsList d'entrees suivante         */
     char                E_Free[C_NUMBER];	 /* Disponibilite des entrees         */
     char                E_Type[C_NUMBER];	 /* CsList des types des entrees      */
     ThotWidget          E_ThotWidget[C_NUMBER]; /* ThotWidgets associes aux entrees  */
  };

struct Cat_Context
  {
     int                 Cat_Ref;	         /* CsReference appli du catalogue    */
     unsigned char       Cat_Type;	         /* Type du catalogue                 */
     unsigned char       Cat_Button;	         /* Le bouton qui active              */
     union {
	 int             Catu_Data;	         /* Valeur de retour                  */
	 ThotWidget	 Catu_XtWParent;
     } Cat_Union1;
     union {
	 int             Catu_in_lines;	         /* Orientation des formulaires       */
	 ThotWidget	 Catu_SelectLabel;
     } Cat_Union2;
     ThotWidget          Cat_Widget;	         /* Le widget associe au catalogue    */
     ThotWidget          Cat_Title;	         /* Le widget du titre                */
     struct Cat_Context *Cat_PtParent;	         /* Adresse du catalogue pere         */
     int                 Cat_EntryParent;	 /* Entree du menu parent             */
     boolean             Cat_React;	         /* Indicateur reaction immediate     */
     boolean             Cat_SelectList;	 /* Indicateur selecteur = liste      */
     struct E_List      *Cat_Entries;	         /* CsList des entrees d'un menu      */
                                                 /* ou widget de saisie de texte      */
  };

/* Redefiniton de champs de catalogues dans certains cas */
#define Cat_ListLength  Cat_Union1.Catu_Data
#define Cat_FormPack    Cat_Union1.Catu_Data
#define Cat_Data	Cat_Union1.Catu_Data
#define Cat_XtWParent   Cat_Union1.Catu_XtWParent
#define Cat_in_lines	Cat_Union2.Catu_in_lines
#define Cat_SelectLabel Cat_Union2.Catu_SelectLabel

struct Cat_List
  {
     struct Cat_List    *Cat_Next;
     struct Cat_Context  Cat_Table[MAX_CAT];
  };

#undef THOT_EXPORT
#define THOT_EXPORT extern
#include "frame_tv.h"
#include "appdialogue_tv.h"

/* Declarations des options de dialogue */
boolean             WithMessages = TRUE;

#ifdef _WINDOWS
static HFONT        formFONT;
#else  /* _WINDOWS */
static XmFontList   formFONT;
#endif /* !_WINDOWS */

static char         Confirm_string[40];
static char         Cancel_string[40];
static char         Done_string[40];
static int          FirstFreeRef;	/* First free reference */

/* Declarations des variables globales */
static struct Cat_List*    PtrCatalogue;	/* Le pointeur su les catalogues  */
static int                 NbOccCat;
static int                 NbLibCat;
static struct E_List*      PtrFreeE_List;
static int                 NbOccE_List;
static int                 NbLibE_List;

static int                 CurrentWait;
static int                 ShowReturn;
static int                 ShowX, ShowY;
static struct Cat_Context* ShowCat = NULL;

#ifndef _WINDOWS
static ThotAppContext Def_AppCont;
static Display*       GDp;
#endif

#ifdef _WINDOWS
LPCTSTR iconID = "IDI_APPICON";
static  OPENFILENAME OpenFileName;
static  int cyValue = 10;

static HWND   currentParent;
#endif /* _WINDOWS */

static ThotTranslations TextTranslations;
static ThotWidget       MainShell;

#include "appdialogue_f.h"
#include "memory_f.h"
#include "thotmsg_f.h"

#ifdef _WINDOWS
typedef struct struct_winerror {
        WORD  errNo;
        char* errstr;
};

struct struct_winerror win_errtab[] = {
#include "winerrdata.c"
};

#define NB_WIN_ERROR (sizeof(win_errtab) / sizeof(struct struct_winerror))

/*****************************
 * MS-Windows Specific part. *
 *****************************/
#define MAX_FRAMECAT 50
typedef struct FrCatalogue {
        struct Cat_Context*  Cat_Table[MAX_FRAMECAT] ;
} FrCatalogue ;


FrCatalogue FrameCatList [MAX_FRAME + 1] ;

extern int       ReturnOption;
extern Document  opDoc;
extern Element   opOption [200];

#ifdef __STDC__
LRESULT CALLBACK WndProc        (HWND, UINT, WPARAM, LPARAM) ;
LRESULT CALLBACK ClientWndProc  (HWND, UINT, WPARAM, LPARAM) ;
LRESULT CALLBACK ThotDlgProc    (HWND, UINT, WPARAM, LPARAM) ;
LRESULT CALLBACK TxtZoneWndProc (HWND, UINT, WPARAM, LPARAM) ;
#else  /* !__STDC__ */
LRESULT CALLBACK WndProc        () ;
LRESULT CALLBACK ClientWndProc  () ;
LRESULT CALLBACK ThotDlgProc    () ;
LRESULT CALLBACK TxtZoneWndProc () ;
#endif /* __STDC__ */

/* following variables are declared as extern in frame_tv.h */
HINSTANCE           hInstance = 0;
char*               tszAppName;
int                 nAmayaShow;
DWORD               WinLastError;
ThotWindow          WinToolBar[MAX_FRAME + 2];
HMENU               WinMenus[MAX_FRAME + 2];	/* MS-Windows associated menus */
HFONT               WIN_DefaultFont;
HWND                hwndAmaya;
ThotWindow          WinStatusBar[MAX_FRAME + 2];
HWND                WIN_Main_Wd;

COLORREF            WIN_Black_Color;	/* Text color                  */
COLORREF            WIN_White_Color;	/* Background color            */
COLORREF            WIN_Scroll_Color;	/* Captions color              */
COLORREF            WIN_Button_Color;	/* Button colors               */
COLORREF            WIN_Select_Color;	/* Selection colors            */
COLORREF            WIN_BgMenu_Color;	/* Menus colors                */
COLORREF            WIN_Box_Color;	/* Active boxes color          */
COLORREF            WIN_RO_Color;	/* Read Only color             */
COLORREF            WIN_InactiveB_Color;	/* Disabeled buttons color     */
HFONT               WIN_DefaultFont;
HFONT               WIN_FontMenu = 0;
HBITMAP             WIN_LastBitmap = 0;
HFONT               WIN_LastFont = 0;
int                 WIN_ActifFen;	/* Number of active document frame  */
int                 WIN_DesFen;	/* selected ViewFrame               */
int                 WIN_DesX;	/* Position X of the selection      */
int                 WIN_DesY;	/* Position Y of the selection      */
int                 WIN_DesReturn;	/* Selection indicator              */
unsigned char*      WIN_buffer;	/* Buffer for exchanges with Window */
int                 WIN_Lgbuffer;
extern char         docToOpen [256];
extern HMENU        currentMenu;
extern int          currentFrame;
#ifdef  APPFILENAMEFILTER
#       undef  APPFILENAMEFILTER
#endif  /* APPFILENAMEFILTER */

#define APPFILENAMEFILTER   "HTML Files (*.html)\0*.html\0HTML Files (*.htm)\0*.htm\0Image files (*.gif)\0*.gif\0Image files (*.jpg)\0*.jpg\0Image files (*.png)\0*.png\0Image files (*.bmp)\0*.bmp\0All files (*.*)\0*.*\0"


void terminate__Fv (void) {
}

typedef struct WIN_Form {
        HWND Buttons [10]; /* Dialog Button      */
        int  x  [10];      /* Initial x position */
        int  cx [10];      /* Button width       */
} WIN_Form ;

static int      bIndex   = 0;
static int      bAbsBase = 60 ;
static WIN_Form formulary ;
static BYTE     fVirt;
static char     key;

#define TAB     '\t'
#define SPACE   ' '
#endif /* _WINDOWS */

/*----------------------------------------------------------------------
   GetFrameNumber :  returns the Thot window number associated to an         
   X-Window window.                                            
  ----------------------------------------------------------------------*/
#ifdef __STDC__
int GetFrameNumber (ThotWindow win)
#else  /* !__STDC__ */
int GetFrameNumber (win)
ThotWindow win;
#endif /* __STDC__ */
{
   int frame;

   for (frame = 0; frame <= MAX_FRAME; frame++)
       if (FrRef[frame] == win)
	  return (frame);

   fprintf (stderr, "Could not get X-Window number for %X\n", (unsigned int)win);
   return (-1);
}

#ifdef _WINDOWS
/*----------------------------------------------------------------------
  ----------------------------------------------------------------------*/
#ifdef __STDC__
BOOL parseAccelerator (char* accelerator)
#else  /* !__STDC */
BOOL parseAccelerator (accelrator)
char* accelerator;
#endif /* __STDC__ */
{
   char*   pc;
   char*   pw;
   char    word [1024];

   fVirt = FNOINVERT;
   if (!accelerator || accelerator [0] == EOS)
      return FALSE;

   pw = &word [0];
   pc = accelerator;
   while (*pc) {
         while (*pc == SPACE || *pc == TAB)
               pc++;
         while ((*pc >= 'A' && *pc <= 'Z') || (*pc >= 'a' && *pc <= 'z'))
               *pw++ = *pc++;
         *pw = EOS;

         if (!strcmp (word, "Ctrl")) 
            return FALSE;
         else if (!strcmp (word, "Alt"))
              fVirt |= FALT;
         else if (!strcmp (word, "Shift"))
              fVirt |= FSHIFT;

         while (*pc == SPACE || *pc == TAB)			  
               pc++;

         if (*pc++ != '+')
            return FALSE;
         else {
              pw = &word [0];
              while ((*pc >= 'A' && *pc <= 'Z') || (*pc >= 'a' && *pc <= 'z') || (*pc >= '0' && *pc <= '9'))
                    *pw++ = *pc++;
              *pw = EOS;

              while (*pc == SPACE || *pc == TAB)			  
                    pc++;

              if (*pc == '+') {
                 if (!strcmp (word, "Ctrl")) 
                    return FALSE;
                 else if (!strcmp (word, "Alt"))
                      fVirt |= FALT;
                 else if (!strcmp (word, "Shift"))
                      fVirt |= FSHIFT;

                 while (*pc == SPACE || *pc == TAB)			  
                       pc++;

                 if (*pc++ != '+')
                    return FALSE;

                 while (*pc == SPACE || *pc == TAB)			  
                       pc++;

                 pw = &word [0];
                 while ((*pc >= 'A' && *pc <= 'Z') || (*pc >= 'a' && *pc <= 'z') || (*pc >= '0' && *pc <= '9'))
                       *pw++ = *pc++;
                 *pw = EOS;
              }	
              if (!strcmp (word, "F1")) {
                 fVirt |= FVIRTKEY;
                 key = VK_F1;
              } else if (!strcmp (word, "F2")) {
                     fVirt |= FVIRTKEY;
                     key = VK_F2;
              } else if (!strcmp (word, "F3")) {
                     fVirt |= FVIRTKEY;
                     key = VK_F3;
              } else if (!strcmp (word, "F4")) {
                     fVirt |= FVIRTKEY;
                     key = VK_F4;
              } else if (!strcmp (word, "F5")) {
                     fVirt |= FVIRTKEY;
                     key = VK_F5;
              } else if (!strcmp (word, "F6")) {
                     fVirt |= FVIRTKEY;
                     key = VK_F6;
			  } else if (!strcmp (word, "F7")) {
                     fVirt |= FVIRTKEY;
                     key = VK_F7;
              } else if (!strcmp (word, "F8")) {
                     fVirt |= FVIRTKEY;
                     key = VK_F8;
              } else if (!strcmp (word, "F9")) {
                     fVirt |= FVIRTKEY;
                     key = VK_F9;
              } else if (!strcmp (word, "F10")) {
                     fVirt |= FVIRTKEY;
                     key = VK_F10;
              } else if (!strcmp (word, "F11")) {
                     fVirt |= FVIRTKEY;
                     key = VK_F11;
              } else if (!strcmp (word, "F12")) {
                     fVirt |= FVIRTKEY;
                     key = VK_F12;
              } else if (!strcmp (word, "F13")) {
                     fVirt |= FVIRTKEY;
                     key = VK_F13;
              } else if (!strcmp (word, "F14")) {
                     fVirt |= FVIRTKEY;
                     key = VK_F14;
              } else if (!strcmp (word, "F15")) {
                     fVirt |= FVIRTKEY;
                     key = VK_F15;
              } else if (!strcmp (word, "F16")) {
                     fVirt |= FVIRTKEY;
                     key = VK_F16;
              } else if (strlen (word) == 1)
                     key = word [0];
              else
                  return FALSE;
         }
         while (*pc) 
               pc++;
   }
   return TRUE;
}

/*----------------------------------------------------------------------
  ----------------------------------------------------------------------*/
#ifdef __STDC__
void addAccelerator (int frame, BYTE fVirt, char key, int cmd)
#else  /* __STDC__ */
void addAccelerator (fVirt, key, cmd)
BYTE fVirt; 
char key;
int  cmd;
#endif /* __STDC__ */
{
   ACCEL* pAccelData = NULL;
   ACCEL* pCurAccel  = NULL;
   HANDLE hAccelData = NULL;
   int    nNumAccel  = 1;

   int  i     = 0;
   BOOL found = FALSE;

   /* If accelerator table exists, get the number of items. */
   if (hAccel [frame])
      nNumAccel = CopyAcceleratorTable (hAccel [frame], NULL, 0) + 1;

   /* Allocate an array of ACCEL structures. */
   hAccelData = GlobalAlloc (GHND, sizeof (ACCEL) * nNumAccel);
   if (hAccelData)
      pAccelData = (ACCEL*) GlobalLock (hAccelData);

   /* If an accelerator table exists, copy the items into the newly allocated array. */

   if (hAccel [frame] && pAccelData) {
      CopyAcceleratorTable (hAccel [frame], pAccelData, nNumAccel - 1);

      DestroyAcceleratorTable (hAccel [frame]);
      hAccel [frame] = NULL;
   }

   /* Add the new menu option and accelerator key */
   if (pAccelData) {
      /* Get a pointer to the new accelerator key in the array. */
      pCurAccel = (ACCEL*) (pAccelData + nNumAccel - 1);

      /* Set up a new accelerator for the the new menu option. */
      pCurAccel->fVirt = fVirt;
      pCurAccel->cmd   = cmd;
      pCurAccel->key   = (WORD) key;

      /* Create the new accelerator table. */
      hAccel [frame] = CreateAcceleratorTable (pAccelData, nNumAccel);

      GlobalUnlock (hAccelData);

   if (hAccelData)
      GlobalFree (hAccelData);

   }
}
/*----------------------------------------------------------------------
  ----------------------------------------------------------------------*/
#ifdef __STDC__
static boolean isOnlyBlank (CONST char* text)
#else  /* __STDC__ */
static boolean isOnlyBlank (text)
CONST char* text;
#endif /* __STDC__ */
{
    char *pText = text;
    while (pText && *pText == ' ')
	  pText++;
    if (*pText == EOS)
       return TRUE;
    return FALSE;
}

/*----------------------------------------------------------------------
  ----------------------------------------------------------------------*/
#ifdef __STDC__
BOOL RegisterWin95 (CONST WNDCLASS* lpwc)
#else  /* !__STDC__ */
BOOL RegisterWin95 (lpwc)
CONST WNDCLASS lpwc ;
#endif /* __STDC__ */
{
   WNDCLASSEX wcex;

   wcex.style         = lpwc->style;
   wcex.lpfnWndProc   = lpwc->lpfnWndProc;
   wcex.cbClsExtra    = lpwc->cbClsExtra;
   wcex.cbWndExtra    = lpwc->cbWndExtra;
   wcex.hInstance     = lpwc->hInstance;
   wcex.hIcon         = lpwc->hIcon;
   wcex.hCursor       = lpwc->hCursor;
   wcex.hbrBackground = lpwc->hbrBackground;
   wcex.lpszMenuName  = lpwc->lpszMenuName;
   wcex.lpszClassName = lpwc->lpszClassName;

   /* Added elements for Windows 95. */
   wcex.cbSize = sizeof(WNDCLASSEX);
   wcex.hIconSm  = LoadIcon (hInstance, IDI_APPLICATION) ;
   return RegisterClassEx( &wcex );
}

/*----------------------------------------------------------------------
   GetMainFrameNumber :  returns the Thot window number associated to an     
   MS-Windows window.                                          
  ----------------------------------------------------------------------*/
#ifdef __STDC__
int GetMainFrameNumber  (ThotWindow win)
#else  /* !__STDC__ */
int GetMainFrameNumber (win)
ThotWindow win ;
#endif /* __STDC__ */
{
   int frame;

   for (frame = 0; frame <= MAX_FRAME; frame++)
       if (FrMainRef[frame] == win)
	  return (frame);

#  ifdef AMAYA_DEBUG
   fprintf (stderr, "Could not get MS-Windows number for %X\n", win);
#  endif /* AMAYA_DEBUG */
   return -1;
}

/*----------------------------------------------------------------------
   GetMenuParentNumber :  returns the Thot window number associated to a     
   given menu.                                          
  ----------------------------------------------------------------------*/
#ifdef __STDC__
int GetMenuParentNumber (ThotWidget menu)
#else  /* !__STDC__ */
int GetMenuParentNumber (win)
ThotWindow win ;
#endif /* __STDC__ */
{
   int     menuIndex;
   int     frameIndex = 0;
   int     frame      = -1;
   boolean found      = FALSE;
  
   while (frameIndex <= MAX_FRAME && !found) {
         menuIndex = 0;
         while (menuIndex < MAX_MENU && !found) 
	     if (FrameTable[frameIndex].WdMenus[menuIndex] == menu) {
                frame = frameIndex ;
                found = TRUE ;
             } else 
                  menuIndex++ ;
         if (!found)
            frameIndex++ ;
   }
   return frame ;
}

/*----------------------------------------------------------------------
   GetVScrollParentNumber :  returns the Thot window number associated to a     
   given menu.                                          
  ----------------------------------------------------------------------*/
#ifdef __STDC__
int GetVScrollParentNumber (ThotWidget vScroll)
#else  /* !__STDC__ */
int GetVScrollParentNumber (vScroll)
ThotWindow vScroll ;
#endif /* __STDC__ */
{
   int     frame = 0;
  
   while (frame < MAX_FRAME) {
         if (FrameTable[frame].WdScrollV == vScroll)
            return frame ;
         frame++ ;
   }
   return -1;
}

/*----------------------------------------------------------------------
   GetHScrollParentNumber :  returns the Thot window number associated to a     
   given menu.                                          
  ----------------------------------------------------------------------*/
#ifdef __STDC__
int GetHScrollParentNumber (ThotWidget hScroll)
#else  /* !__STDC__ */
int GetHScrollParentNumber (hScroll)
ThotWindow hScroll ;
#endif /* __STDC__ */
{
   int     frame = 0;
  
   while (frame < MAX_FRAME) {
         if (FrameTable[frame].WdScrollH == hScroll)
            return frame ;
         frame++ ;
   }
   return -1;
}

ThotWindow WIN_curWin = (ThotWindow)(-1);

/*----------------------------------------------------------------------
   WIN_GetDeviceContext :  select a Device Context for a given       
   thot window.                                                
  ----------------------------------------------------------------------*/
#ifdef __STDC__
HMENU WIN_GetMenu (int frame)
#else  /* !__STDC__ */
HMENU WIN_GetMenu (int frame)
#endif /* __STDC__ */
{
    return (GetMenu (FrMainRef [frame]));
}
/*----------------------------------------------------------------------
   WIN_GetDeviceContext :  select a Device Context for a given       
   thot window.                                                
  ----------------------------------------------------------------------*/
#ifdef __STDC__
void WIN_GetDeviceContext (int frame)
#else  /* !__STDC__ */
void WIN_GetDeviceContext (frame)
int frame;
#endif /* __STDC__ */
{
#  ifdef _WIN_PRINT
   WIN_curWin = NULL;
   TtDisplay = GetDC (WIN_curWin);
#  else  /* !_WIN_PRINT */
   if (frame == -1) {
      if (TtDisplay != 0)
         return;
      for (frame = 0; frame <= MAX_FRAME; frame++)
	  if (FrRef[frame] != 0)
	     break;
   }
   if ((frame < 0) || (frame > MAX_FRAME)) {
      TtDisplay = GetDC (NULL);
      return;
   }
   
   if (FrRef[frame] == 0)
      return;

   /* if the correct Device Context is already selected, returns. */
   if ((WIN_curWin == FrRef[frame]) && (TtDisplay != 0))
      return;

   /* release the previous Device Context. */
   if (TtDisplay)
      ReleaseDC (WIN_curWin, TtDisplay);

   WIN_curWin = (ThotWindow) (-1);
   TtDisplay = 0;

   /* load the new Context. */
   TtDisplay = GetDC (FrRef[frame]);
   if (TtDisplay != 0)
      WIN_curWin = FrRef[frame];
#  endif /* !_WIN_PRINT */
}

/*----------------------------------------------------------------------
   WIN_ReleaseDeviceContext :  unselect the Device Context           
  ----------------------------------------------------------------------*/
#ifdef __STDC__
void WIN_ReleaseDeviceContext (void)
#else  /* !__STDC__ */
void WIN_ReleaseDeviceContext ()
#endif /* __STDC__ */
{
   /* release the previous Device Context. */
   /* if ((TtDisplay != 0) && (WIN_curWin != (ThotWindow) (-1))) */
   if (TtDisplay != 0)
      ReleaseDC (WIN_curWin, TtDisplay);

   WIN_curWin = (ThotWindow) (-1);
   TtDisplay = 0;
}



/*----------------------------------------------------------------------
  ----------------------------------------------------------------------*/
#ifdef __STDC__
void WIN_AddFrameCatalogue (ThotWidget parent, struct Cat_Context* catalogue)
#else  /* !__STDC__ */
void WIN_AddFrameCatalogue (parent, catalogue)
ThotWidget          parent; 
struct Cat_Context* catalogue;
#endif /* __STDC__ */
{
   int                 frameIndex;
   int                 catIndex;
   int                 twIndex;
   int                 i;
   int                 frame = GetMainFrameNumber (parent);
   boolean             found;
   struct Cat_Context* tmpCat;

   if (frame == -1) {
      frame = GetMenuParentNumber (parent) ;
   
      if (frame == - 1) {
         frameIndex = 0 ;
         found      = FALSE ;

         while (frameIndex <= MAX_FRAME && !found) {
               catIndex = 0 ;
            
               while (catIndex < MAX_FRAMECAT && !found) {
                     twIndex = 0;

                     while (twIndex < C_NUMBER && !found)
                           if (FrameCatList[frameIndex].Cat_Table[catIndex] &&
                               FrameCatList[frameIndex].Cat_Table[catIndex]->Cat_Entries->E_ThotWidget[twIndex] == parent) {
			      
                              found = TRUE ;
                              frame = frameIndex ;
                           } else
                                 twIndex++ ;
 
                           if (!found)
                              catIndex++ ;
               }

               if (!found)
                  frameIndex++ ;
         }
      }
   }
   
   if (frame != -1) {
      found = FALSE ;
      i = 0;
      while ((i < MAX_FRAMECAT) && (FrameCatList[frame].Cat_Table[i] != 0) && !found)
            if (FrameCatList[frame].Cat_Table[i]->Cat_Ref == catalogue->Cat_Ref) {
               found = TRUE ;
               FrameCatList[frame].Cat_Table[i] = catalogue ;
            } else if (FrameCatList[frame].Cat_Table[i]->Cat_Ref > catalogue->Cat_Ref) {
                   tmpCat = FrameCatList[frame].Cat_Table[i] ;
                   do {
                       FrameCatList[frame].Cat_Table[i] = catalogue ;
                       catalogue = tmpCat ;
                       i++ ;
                       tmpCat = FrameCatList[frame].Cat_Table[i];
                   } while (tmpCat) ;
                   FrameCatList[frame].Cat_Table[i] = catalogue;
                   found = TRUE ;
            } else
                  i++ ;

      if (i < MAX_FRAMECAT && !found) 
         FrameCatList[frame].Cat_Table[i] = catalogue ;
   }
}

/*----------------------------------------------------------------------
CleanFrameCatList
  ----------------------------------------------------------------------*/
#ifdef __SIDC__
void CleanFrameCatList (int frame) 
#else  /* __STDC__ */
void CleanFrameCatList (frame) 
int frame;
#endif /* __STDC__ */
{
	int catIndex;
	for (catIndex = 0; catIndex < MAX_FRAMECAT; catIndex++)
		FrameCatList [frame].Cat_Table[catIndex] = NULL;
}


/*----------------------------------------------------------------------
   WinLookupCatEntry Lookup the Catalogue table for an entry          
   corresponding to an existing Window.                    
  ----------------------------------------------------------------------*/
#ifdef __STDC__
static struct Cat_Context *WinLookupCatEntry (ThotWidget win, int ref)
#else  /* !__STDC__ */
static struct Cat_Context *WinLookupCatEntry (win, ref)
ThotWidget win;
int        ref;
#endif /* __STDC__ */
{
   register int        icat = 1;
   boolean             found = FALSE;
   int                 frame = GetMainFrameNumber (win) ;
   int                 best = -1;
   /* struct Cat_Context* catval;*/
   struct Cat_Context* catalogue;

   if (frame == -1)
      return NULL;

   catalogue = FrameCatList[frame].Cat_Table [0];
   while (icat < MAX_FRAMECAT) {
         if (catalogue && catalogue->Cat_Ref == ref)
            return catalogue ;
         if (catalogue && FrameCatList[frame].Cat_Table [icat] &&
             (FrameCatList[frame].Cat_Table[icat]->Cat_Ref > ref) && (catalogue->Cat_Ref <= ref))
            return catalogue ;
		 if (FrameCatList[frame].Cat_Table [icat] != NULL)
            catalogue = FrameCatList[frame].Cat_Table [icat];
         icat++ ;
   }
   if (catalogue->Cat_Ref <= ref)
	  return catalogue ;

   return NULL ;
}

/*----------------------------------------------------------------------
   WinErrorBox :  Pops-up a message box when an MS-Window error      
   occured.                                                    
  ----------------------------------------------------------------------*/
#ifdef __STDC__
void WinErrorBox (HWND hWnd)
#else  /* !__STDC__ */
void WinErrorBox (hWnd)
HWND hWnd;
#endif /* __STDC__ */
{
   int                 msg;
   char                str[200];

   WinLastError = GetLastError ();
   if (WinLastError == 0)
      return;

   for (msg = 0; msg < NB_WIN_ERROR; msg++)
       if (win_errtab[msg].errNo == WinLastError)
	  break;

   if (msg >= NB_WIN_ERROR)
      sprintf (str, "Error %d : not registered\n", WinLastError);
   else
       sprintf (str, "Error %d : %s\n", WinLastError, win_errtab[msg].errstr);
#  ifdef AMAYA_DEBUG
   printf (stderr, str);
#  endif /* AMAYA_DEBUG */
   MessageBox (hWnd, str, tszAppName, MB_OK);
}

/*----------------------------------------------------------------------
  ----------------------------------------------------------------------*/
#ifdef __STDC__
int makeArgcArgv (HINSTANCE hInst, char*** pArgv, char* commandLine)
#else  /* __STDC__ */
int makeArgcArgv (hInst, pArgv, commandLine)
HINSTANCE hInst; 
char***   pArgv; 
char*     commandLine;
#endif /* __STDC__ */
{
    int          argc;
    static char* argv[20];
    static char  argv0[256];
    char*        ptr     = commandLine;
    char         lookFor = 0;

    enum {
	nowAt_start, 
	nowAt_text
    } nowAt;

    *pArgv = argv;
    argc   = 0;
    GetModuleFileName (hInst, argv0, sizeof (argv0));
    argv[argc++] = argv0;
    for (nowAt = nowAt_start;;) {
        if (!*ptr) 
           return (argc);
	
        if (lookFor) {
           if (*ptr == lookFor) {
	      nowAt = nowAt_start;
	      lookFor = 0;
	      *ptr = 0;   /* remove the quote */
	   } else if (nowAt == nowAt_start) {
	        argv[argc++] = ptr;
                nowAt = nowAt_text;
	   }
	   ptr++;
	   continue;
        }
        if (*ptr == ' ' || *ptr == '\t') {
           *ptr = 0;
	   ptr++;
	   nowAt = nowAt_start;
	   continue;
        }
        if ((*ptr == '\'' || *ptr == '\"' || *ptr == '`') && nowAt == nowAt_start) {
           lookFor = *ptr;
	   nowAt = nowAt_start;
	   ptr++;
	   continue;
        }
        if (nowAt == nowAt_start) {
           argv[argc++] = ptr;
	   nowAt = nowAt_text;
        }
        ptr++;
    }
}

#ifndef _WIN_PRINT
/*----------------------------------------------------------------------
   WinMain
  ----------------------------------------------------------------------*/
#ifdef __STDC__
BOOL PASCAL WinMain (HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR lpCommand, int nShow)
#else  /* !__STDC__ */
BOOL PASCAL WinMain (hInst, hPrevInst, lpCommand, nShow)
HINSTANCE hInst; 
HINSTANCE hPrevInst; 
LPSTR     lpCommand; 
int       nShow;
#endif /* __STDC__ */
{ 
   int    argc ;
   char** argv;

   hInstance  = hInst;
   nAmayaShow = nShow;
   tszAppName = "Amaya";

   argc = makeArgcArgv (hInst, &argv, lpCommand);
   main (argc, argv);
   return (TRUE);
}
#endif /* _WIN_PRINT */
#endif /* _WINDOWS */

/*----------------------------------------------------------------------
   Procedure de retour par defaut.                                    
  ----------------------------------------------------------------------*/
#ifdef __STDC__
static void         CallbackError (int ref, int typedata, char *data)

#else  /* __STDC__ */
static void         CallbackError (ref, typedata, data)
int                 ref;
int                 typedata;
char               *data;

#endif /* __STDC__ */
{
   printf ("Toolkit error : No callback procedure ...\n");
}

static void         (*CallbackDialogue) () = CallbackError;

/*----------------------------------------------------------------------
   NewCatList Creates a new catalogue list.                           
  ----------------------------------------------------------------------*/
static struct Cat_List *NewCatList ()
{
   register int        i;
   struct Cat_List    *adlist;

   adlist = (struct Cat_List *) TtaGetMemory (sizeof (struct Cat_List));

   adlist->Cat_Next = NULL;

   /* Updates thenumber of available and free catalogues */
   NbLibCat += MAX_CAT;
   for (i = 0; i < MAX_CAT; i++)
     {
       adlist->Cat_Table[i].Cat_Widget = 0;
       adlist->Cat_Table[i].Cat_Entries = NULL;
     }
   return (adlist);
}


/*----------------------------------------------------------------------
   NewEList: creates a new block of elements.                         
  ----------------------------------------------------------------------*/
static struct E_List *NewEList ()
{
   register int        i;
   struct E_List      *adbloc;

   /* verifies if there is a free block */
   if (PtrFreeE_List == NULL)
      adbloc = (struct E_List *) TtaGetMemory (sizeof (struct E_List));
   else
     {
	adbloc = PtrFreeE_List;
	PtrFreeE_List = adbloc->E_Next;
	NbLibE_List--;
     }

   /* Updates the number of blocks of allocated E_List */
   NbOccE_List++;
   adbloc->E_Next = NULL;
   for (i = 0; i < C_NUMBER; i++)
     adbloc->E_ThotWidget[i] = 0;
 
   return (adbloc);
}


/*----------------------------------------------------------------------
   FreeEList: Releases all blocks of elements.                        
  ----------------------------------------------------------------------*/
#ifdef __STDC__
static void         FreeEList (struct E_List *adbloc)
#else  /* __STDC__ */
static void         FreeEList (adbloc)
struct E_List      *adbloc;
#endif /* __STDC__ */
{
   struct E_List      *cebloc;

   cebloc = adbloc;
   while (cebloc != NULL)
     {
	NbLibE_List++;
	if (cebloc->E_Next == NULL)
	  {
	     cebloc->E_Next = PtrFreeE_List;
	     PtrFreeE_List = adbloc;
	     cebloc = NULL;
	  }
	else
	   cebloc = cebloc->E_Next;
     }
}


/*----------------------------------------------------------------------
   Callback for closing a menu                                        
  ----------------------------------------------------------------------*/
#ifdef __STDC__
static void         UnmapMenu (ThotWidget w, struct Cat_Context *catalogue, caddr_t call_d)
#else  /* __STDC__ */
static void         UnmapMenu (w, catalogue, call_d)
ThotWidget          w;
struct Cat_Context *catalogue;
caddr_t             call_d;
#endif /* __STDC__ */
{
   struct Cat_Context *icatal;

   /* Une attende est peut etre debloquee */
   icatal = catalogue;
   while (icatal->Cat_PtParent != NULL)
      icatal = icatal->Cat_PtParent;

   if ((icatal == ShowCat) && (ShowReturn == 1))
      ShowReturn = 0;
}


/*----------------------------------------------------------------------
   Callback for a menu button                                         
  ----------------------------------------------------------------------*/
#ifdef __STDC__
static void         CallMenu (ThotWidget w, struct Cat_Context *catalogue, caddr_t call_d)
#else  /* __STDC__ */
static void         CallMenu (w, catalogue, call_d)
ThotWidget          w;
struct Cat_Context *catalogue;
caddr_t             call_d;
#endif /* __STDC__ */
{
   register int        i;
   register int        index;
   register int        entry;
   struct E_List      *adbloc;
   struct Cat_Context *icatal;

   /* Une attende est peut etre debloquee */
   icatal = catalogue;
   while (icatal->Cat_PtParent != NULL)
      icatal = icatal->Cat_PtParent;

   if ((icatal == ShowCat) && (ShowReturn == 1))
      ShowReturn = 0;

   /* A menu entry is selected */
   if (catalogue->Cat_Widget != 0)
      if ((int) catalogue->Cat_Widget == -1)
	/*** back to a simple button ***/
	(*CallbackDialogue) (catalogue->Cat_Ref, INTEGER_DATA, 0);
      else
	{
	   adbloc = catalogue->Cat_Entries;
	   entry = -1;
	   index = 0;
	   i = 2;		/* decalage de 2 pour le widget titre */
	   while ((entry == -1) && (adbloc != NULL))
	     {
		while ((entry == -1) && (i < C_NUMBER))
		  {
		     if (adbloc->E_ThotWidget[i] == w)
			entry = index;
		     i++;
		     index++;
		  }
		/* Passe au bloc suivant */
		adbloc = adbloc->E_Next;
		i = 0;
	     }

	   /*** Retour de l'entree du menu choisie vers l'application ***/
	   (*CallbackDialogue) (catalogue->Cat_Ref, INTEGER_DATA, entry);
	}
}


/*----------------------------------------------------------------------
   Callback pour un bouton du sous-menu de formulaire                 
  ----------------------------------------------------------------------*/
#ifdef __STDC__
static void         CallRadio (ThotWidget w, struct Cat_Context *catalogue, caddr_t call_d)
#else  /* __STDC__ */
static void         CallRadio (w, catalogue, call_d)
ThotWidget          w;
struct Cat_Context *catalogue;
caddr_t             call_d;
#endif /* __STDC__ */
{
   register int        i;
   register int        index;
   register int        entry;
   struct E_List      *adbloc;

   /* Enregistre la selection d'un toggle button */
   if (catalogue->Cat_Widget != 0)
     {
	adbloc = catalogue->Cat_Entries;
	entry = -1;
	index = 0;
	i = 2;			/* decalage de 2 pour le widget titre */
	while ((entry == -1) && (adbloc != NULL))
	  {
	     while ((entry == -1) && (i < C_NUMBER))
	       {
		  if (adbloc->E_ThotWidget[i] == w)
		     entry = index;
		  i++;
		  index++;
	       }
	     /* Passe au bloc suivant */
	     adbloc = adbloc->E_Next;
	     i = 0;
	  }

	/*** Sauve la valeur de la derniere selection ***/
	catalogue->Cat_Data = entry;
	/* retourne la valeur si le menu est reactif */
	if (catalogue->Cat_React)
	   (*CallbackDialogue) (catalogue->Cat_Ref, INTEGER_DATA, entry);
     }
}


/*----------------------------------------------------------------------
   Callback pour un bouton du toggle-menu                             
  ----------------------------------------------------------------------*/
#ifdef __STDC__
static void         CallToggle (ThotWidget w, struct Cat_Context *catalogue, caddr_t call_d)
#else  /* __STDC__ */
static void         CallToggle (w, catalogue, call_d)
ThotWidget          w;
struct Cat_Context *catalogue;
caddr_t             call_d;
#endif /* __STDC__ */
{
   register int        i;
   int                 entry;
   int                 ent;
   int                 max;
   struct E_List      *adbloc;

   /* Enregistre la selection d'un toggle button */
   if (catalogue->Cat_Widget != 0)
     {
	adbloc = catalogue->Cat_Entries;
	entry = -1;
	ent = 0;
	max = catalogue->Cat_Data;	/* nombre d'entrees definies */
	i = 2;			/* decalage de 2 pour le widget titre */
	while (entry == -1 && adbloc != NULL && ent <= max)
	  {
	     while (entry == -1 && i < C_NUMBER && ent <= max)
	       {
		  if (adbloc->E_ThotWidget[i] == w)
		    {
		       entry = 0;
		       /* Bascule la valeur du bouton correspondant a l'entree */
		       adbloc->E_Free[i] = 'Y';

		       /* signale que l'entree est basculee si le menu est reactif */
		       if (catalogue->Cat_React)
			  (*CallbackDialogue) (catalogue->Cat_Ref, INTEGER_DATA, ent);
		    }
		  i++;
		  ent++;
	       }
	     /* Passe au bloc suivant */
	     adbloc = adbloc->E_Next;
	     i = 0;
	  }			/*while */
     }				/*if */
}				/*CallToggle */


/*----------------------------------------------------------------------
   ReturnTogglevalues retourne les entre'es bascule'es du             
   toggle-menu catalogue.                                             
  ----------------------------------------------------------------------*/
#ifdef __STDC__
static void         ReturnTogglevalues (struct Cat_Context *catalogue)
#else  /* __STDC__ */
static void         ReturnTogglevalues (catalogue)
struct Cat_Context *catalogue;
#endif /* __STDC__ */
{
   register int        i;
   register int        index;
   int                 ent;
   int                 max;
   struct E_List      *adbloc;

   /* Enregistre la selection d'un toggle button */
   if (catalogue->Cat_Widget != 0)
     {
	adbloc = catalogue->Cat_Entries;
	index = 0;
	ent = 0;
	max = catalogue->Cat_Data;	/* nombre d'entrees definies */
	i = 2;			/* decalage de 2 pour le widget titre */
	while (adbloc != NULL)
	  {
	     while (i < C_NUMBER && ent < max)
	       {
		 /*** Retour les entrees selectionnees vers l'application ***/
		  if (adbloc->E_Free[i] == 'Y')
		    {
		       (*CallbackDialogue) (catalogue->Cat_Ref, INTEGER_DATA, index);
		       adbloc->E_Free[i] = 'N';
		    }
		  i++;
		  ent++;
		  index++;
	       }
	     /* Passe au bloc suivant */
	     adbloc = adbloc->E_Next;
	     i = 0;
	  }
     }
}


/*----------------------------------------------------------------------
   Callback d'initialisation d'un formulaire.                         
  ----------------------------------------------------------------------*/
#ifdef __STDC__
static void         INITform (ThotWidget w, struct Cat_Context *parentCatalogue, caddr_t call_d)

#else  /* __STDC__ */
static void         INITform (w, parentCatalogue, call_d)
ThotWidget          w;
struct Cat_Context *parentCatalogue;
caddr_t             call_d;

#endif /* __STDC__ */
{
   register int        n;
   int                 ent;
   struct E_List      *adbloc;
#  ifndef _WINDOWS
   Arg                 args[MAX_ARGS];
#  endif /* _WINDOWS */
   struct Cat_Context *catalogue;

   /* Affiche le formulaire */
   if (parentCatalogue->Cat_Widget != 0)
     {
        /*** Allume les sous-widgets du formulaire ***/
	adbloc = parentCatalogue->Cat_Entries;
	/* Le premier bloc contient les boutons de la feuille de saisie */
	adbloc = adbloc->E_Next;

	ent = 1;
	while (adbloc->E_ThotWidget[ent] != 0)
	  {
	     /* Il faut sauter les widgets des RowColumns */
	     if (adbloc->E_Free[ent] == 'N')
	       {
		  catalogue = (struct Cat_Context *) adbloc->E_ThotWidget[ent];
#                 ifndef _WINDOWS
		  if (catalogue->Cat_Widget != 0)
		     XtManageChild (catalogue->Cat_Widget);
#                 else  /* _WINDOWS */
                  ShowWindow (catalogue->Cat_Widget, SW_SHOWNORMAL);
		  UpdateWindow (catalogue->Cat_Widget);
#                 endif /* _WINDOWS */
	       }

	     /* Faut-il passer au bloc suivant ? */
	     ent++;
	     if (ent >= C_NUMBER)
	       {
		  ent = 0;
		  if (adbloc->E_Next == NULL)
		     break;
		  else
		     adbloc = adbloc->E_Next;
	       }
	  }			/*while */

	/*** Positionne le formulaire a la position courante du show ***/
	n = 0;
	w = parentCatalogue->Cat_Widget;
	n = 0;
#       ifndef _WINDOWS
	XtSetArg (args[n], XmNx, (Position) ShowX);
	n++;
	XtSetArg (args[n], XmNy, (Position) ShowY);
	n++;
	XtSetValues (XtParent (w), args, n);

	XtManageChild (w);
	XtManageChild (XtParent (w));
#       else  /* _WINDOWS */
        ShowWindow (w, SW_SHOWNORMAL);
        UpdateWindow (w);
        ShowWindow (GetParent (w), SW_SHOWNORMAL);
        UpdateWindow (GetParent (w));
#       endif /* _WINDOWS */
     }
}


/*----------------------------------------------------------------------
   Callback d'initialisation d'un formulaire avec positionnement.     
  ----------------------------------------------------------------------*/
#ifdef __STDC__
static void         INITetPOSform (ThotWidget w, struct Cat_Context *parentCatalogue, caddr_t call_d)

#else  /* __STDC__ */
static void         INITetPOSform (w, parentCatalogue, call_d)
ThotWidget          w;
struct Cat_Context *parentCatalogue;
caddr_t             call_d;

#endif /* __STDC__ */
{
   TtaSetDialoguePosition ();
   INITform (w, parentCatalogue, call_d);
}


/*----------------------------------------------------------------------
   Destruction de feuillet.                                           
  ----------------------------------------------------------------------*/
#ifdef __STDC__
static void         formKill (ThotWidget w, struct Cat_Context *parentCatalogue, caddr_t call_d)

#else  /* __STDC__ */
static void         formKill (w, parentCatalogue, call_d)
ThotWidget          w;
struct Cat_Context *parentCatalogue;
caddr_t             call_d;

#endif /* __STDC__ */
{
   /* Le widget est detruit */
   TtaDestroyDialogue (parentCatalogue->Cat_Ref);
}


/*----------------------------------------------------------------------
   Callback de feuillet.                                              
  ----------------------------------------------------------------------*/
#ifndef _WINDOWS
#ifdef __STDC__
static void         CallSheet (ThotWidget w, struct Cat_Context *parentCatalogue, caddr_t call_d)

#else  /* __STDC__ */
static void         CallSheet (w, parentCatalogue, call_d)
ThotWidget          w;
struct Cat_Context *parentCatalogue;
caddr_t             call_d;

#endif /* __STDC__ */
{
   register int        n;
   int                 i;
   int                 ent;
   int                 entry;
   char                text[100];
   char               *ptr;
   Arg                 args[MAX_ARGS];
   XmStringTable       strings;
   struct E_List      *adbloc;
   struct Cat_Context *catalogue;
   ThotWidget          wtext;

   /* On a selectionne une entree du menu */
   if (parentCatalogue->Cat_Widget != 0)
     {
	adbloc = parentCatalogue->Cat_Entries;
	entry = -1;
	i = 0;
	while ((entry == -1) && (i < C_NUMBER))
	  {
	     if (adbloc->E_ThotWidget[i] == w)
		entry = i;
	     i++;
	  }			/*while */

	/* Si la feuille de dialogue est detruite cela force l'abandon */
	if (entry == -1)
	   if (parentCatalogue->Cat_Type == CAT_SHEET)
	      entry = 0;
	   else
	      return;

	/*** Retour vers l'application ***/
	/*** Eteins les sous-widgets du feuillet si on quitte ***/
	/*** Recupere les retours des sous-catalogues         ***/
	adbloc = adbloc->E_Next;
	ent = 1;
	while (adbloc->E_ThotWidget[ent] != 0)
	  {
	     /* Il faut sauter les widgets des RowColumns */
	     if (adbloc->E_Free[ent] == 'N')
	       {
		  catalogue = (struct Cat_Context *) adbloc->E_ThotWidget[ent];
		  if (catalogue->Cat_Widget != 0)
		    {
		       if (entry == 0)
			  XtUnmanageChild (catalogue->Cat_Widget);

		       /* Sinon il faut retourner la valeur du sous-catalogue */
		       else
			 {
			    if (catalogue->Cat_React)
			       ;	/* La valeur est deja transmise */
/*________________________________________________ Un sous-menu __*/
			    else if (catalogue->Cat_Type == CAT_FMENU)
			      {
				 i = catalogue->Cat_Data;
				 (*CallbackDialogue) (catalogue->Cat_Ref, INTEGER_DATA, i);
			      }
/*______________________________________________ Un toggle-menu __*/
			    else if (catalogue->Cat_Type == CAT_TMENU)
			       ReturnTogglevalues (catalogue);
/*______________________________ Une feuille de saisie d'entier __*/
			    else if (catalogue->Cat_Type == CAT_INT)
			      {
				 strncpy (text, XmTextGetString (catalogue->Cat_Entries->E_ThotWidget[1]), 10);

				 text[10] = EOS;
				 if (text[0] != EOS)
				    sscanf (text, "%d", &i);
				 else
				    i = 0;
				 (*CallbackDialogue) (catalogue->Cat_Ref, INTEGER_DATA, i);
			      }
/*______________________________ Une feuille de saisie de texte __*/
			    else if (catalogue->Cat_Type == CAT_TEXT)
			      {
				 (*CallbackDialogue) (catalogue->Cat_Ref, STRING_DATA,
						      XmTextGetString ((ThotWidget) catalogue->Cat_Entries));
			      }
/*_______________________________________________ Un selecteur __*/
			    else if (catalogue->Cat_Type == CAT_SELECT)
			      {
				 if (catalogue->Cat_SelectList)
				   {
				      text[0] = EOS;
				      n = 0;
				      XtSetArg (args[n], XmNselectedItems, &strings);
				      n++;
				      XtGetValues ((ThotWidget) catalogue->Cat_Entries, args, n);
				      ptr = text;
				      if (strings != NULL)
					 XmStringGetLtoR (strings[0], XmSTRING_DEFAULT_CHARSET, &ptr);
				      (*CallbackDialogue) (catalogue->Cat_Ref, STRING_DATA, ptr);
				   }
				 else
				   {
				      wtext = XmSelectionBoxGetChild ((ThotWidget) catalogue->Cat_Entries, XmDIALOG_TEXT);
				      /* Retourne la valeur dans tous les cas */
				      (*CallbackDialogue) (catalogue->Cat_Ref, STRING_DATA, XmTextGetString (wtext));
				   }
			      }
			 }
		    }
	       }

	     /* Faut-il passer au bloc suivant ? */
	     ent++;
	     if (ent >= C_NUMBER)
	       {
		  ent = 0;
		  if (adbloc->E_Next == NULL)
		     break;
		  else
		     adbloc = adbloc->E_Next;
	       }
	  }			/*while */

	/*** On fait disparaitre le formulaire ***/
	if (entry == 0 || parentCatalogue->Cat_Type == CAT_DIALOG || parentCatalogue->Cat_Type == CAT_FORM)
	  {
	     XtUnmanageChild (parentCatalogue->Cat_Widget);
	     XtUnmanageChild (XtParent (parentCatalogue->Cat_Widget));

	     /* Si on en a fini avec la feuille de dialogue */
	     catalogue = parentCatalogue;
	     while (catalogue->Cat_PtParent != NULL)
		catalogue = catalogue->Cat_PtParent;

	     if ((catalogue == ShowCat) && (ShowReturn == 1))
		ShowReturn = 0;
	  }

	(*CallbackDialogue) (parentCatalogue->Cat_Ref, INTEGER_DATA, entry);
     }
}


/*----------------------------------------------------------------------
   Callback de saisie de valeur.                                      
  ----------------------------------------------------------------------*/
#ifdef __STDC__
static void         CallValueSet (ThotWidget w, struct Cat_Context *catalogue, caddr_t call_d)
#else  /* __STDC__ */
static void         CallValueSet (w, catalogue, call_d)
ThotWidget          w;
struct Cat_Context *catalogue;
caddr_t             call_d;

#endif /* __STDC__ */
{
   int                 val, val1;
   char                text[11];
   ThotWidget          wtext;

   /* Indication de valeur */
   if (catalogue->Cat_Widget != 0)
      if (catalogue->Cat_Type == CAT_INT)
	{
	   catalogue->Cat_Data = 0;
	   wtext = catalogue->Cat_Entries->E_ThotWidget[1];

	   strncpy (text, XmTextGetString (wtext), 10);
	   text[10] = EOS;
	   if (text[0] != EOS)
	     {
		if ((text[0] == '-') && (text[1] == EOS))
		   /* cas ou le caractere - a ete tape, on met val a 0 */
		   val = 0;
		else
		   sscanf (text, "%d", &val);

		/* Est-ce une valeur valide ? */
		if (val < (int) catalogue->Cat_Entries->E_ThotWidget[2])
		   val1 = (int) catalogue->Cat_Entries->E_ThotWidget[2];
		else if (val > (int) catalogue->Cat_Entries->E_ThotWidget[3])
		   val1 = (int) catalogue->Cat_Entries->E_ThotWidget[3];
		else
		   val1 = val;	/* valeur inchangee */

		/* Est-ce qu'il faut changer le contenu du widget ? */
		if (val != val1)
		  {
		     sprintf (text, "%d", val1);
		     /* Desactive la procedure de Callback */
		     XtRemoveCallback (wtext, XmNvalueChangedCallback, (XtCallbackProc) CallValueSet, catalogue);

		     XmTextSetString (wtext, text);
		     val = strlen (text);
		     XmTextSetSelection (wtext, val, val, 500);

		     /* Reactive la procedure de Callback */
		     XtAddCallback (wtext, XmNvalueChangedCallback, (XtCallbackProc) CallValueSet, catalogue);
		  }

		/* retourne la valeur saisie si la feuille de saisie est reactive */
		if (catalogue->Cat_React)
		   (*CallbackDialogue) (catalogue->Cat_Ref, INTEGER_DATA, val);

	     }
	}
}


/*----------------------------------------------------------------------
   Callback de selection dans une liste.                              
  ----------------------------------------------------------------------*/
#ifdef __STDC__
static void         CallList (ThotWidget w, struct Cat_Context *catalogue, XmListCallbackStruct * infos)
#else  /* __STDC__ */
static void         CallList (w, catalogue, infos)
ThotWidget          w;
struct Cat_Context *catalogue;
XmListCallbackStruct *infos;

#endif /* __STDC__ */

{
   char               *text;
   boolean             ok;

   if (catalogue->Cat_Widget != 0)
      if (catalogue->Cat_Type == CAT_SELECT)
	{
	   ok = XmStringGetLtoR (infos->item, XmSTRING_DEFAULT_CHARSET, &text);
	   /* retourne l'entree choisie */
	   if (ok && text != NULL)
	      if (text[0] != EOS && text[0] != ' ')
		 (*CallbackDialogue) (catalogue->Cat_Ref, STRING_DATA, text);
	}
}


/*----------------------------------------------------------------------
   Callback de saisie de texte.                                       
  ----------------------------------------------------------------------*/
#ifdef __STDC__
static void         CallTextChange (ThotWidget w, struct Cat_Context *catalogue, caddr_t call_d)

#else  /* __STDC__ */
static void         CallTextChange (w, catalogue, call_d)
ThotWidget          w;
struct Cat_Context *catalogue;
caddr_t             call_d;

#endif /* __STDC__ */

{
   ThotWidget          wtext;

   if (catalogue->Cat_Widget != 0)
      if (catalogue->Cat_Type == CAT_TEXT)
	 /* retourne la valeur saisie si la feuille de saisie est reactive */
	 (*CallbackDialogue) (catalogue->Cat_Ref, STRING_DATA,
		     XmTextGetString ((ThotWidget) catalogue->Cat_Entries));
      else if (catalogue->Cat_Type == CAT_SELECT)
	{
	   wtext = XmSelectionBoxGetChild ((ThotWidget) catalogue->Cat_Entries, XmDIALOG_TEXT);
	   /* retourne la valeur saisie si la feuille de saisie est reactive */
	   (*CallbackDialogue) (catalogue->Cat_Ref, STRING_DATA, XmTextGetString (wtext));
	}
}


/*----------------------------------------------------------------------
   Callback pour un bouton du label de selecteur                      
  ----------------------------------------------------------------------*/
#ifdef __STDC__
static void         CallLabel (ThotWidget w, struct Cat_Context *catalogue, caddr_t call_d)

#else  /* __STDC__ */
static void         CallLabel (w, catalogue, call_d)
ThotWidget          w;
struct Cat_Context *catalogue;
caddr_t             call_d;

#endif /* __STDC__ */
{
   Arg                 args[MAX_ARGS];
   XmString            text;
   char               *str;

   if (catalogue->Cat_Widget != 0)
     {
	/* Recupere le texte du label */
	XtSetArg (args[0], XmNlabelString, &text);
	XtGetValues (w, args, 1);
	/* Initialise le champ texte */
	XtSetArg (args[0], XmNtextString, text);

	if (catalogue->Cat_SelectList)
	  {
	     /* retourne la valeur du label */
	     XmStringGetLtoR (text, XmSTRING_DEFAULT_CHARSET, &str);
	     (*CallbackDialogue) (catalogue->Cat_Ref, STRING_DATA, str);
	  }
	else
	   XtSetValues ((ThotWidget) catalogue->Cat_Entries, args, 1);
     }
}
#endif /* _WINDOWS */

/*----------------------------------------------------------------------
   warning handler                                                    
  ----------------------------------------------------------------------*/
void                MyWarningHandler ()
{
}


/*----------------------------------------------------------------------
   TtaInitDialogue

   Initialise la connexion au serveur X  et le contexte du dialogue.

   Parameters:
   server: nom du serveur X.
   textOK: texte affiche' dans les boutons de confirmation des formulaires.
   textRAZ: texte affiche' dans les boutons d'abandon des formulaires.
   X-Specific stuff :
   app_context: contient au retour l'identification du contexte d'application.
   display:  contient au retour l'identification de l'e'cran.
  ----------------------------------------------------------------------*/
#ifdef _WINDOWS
#ifdef __STDC__
BOOL             WIN_TtaInitDialogue (char *server, char *txtOK, char *txtRAZ, char *txtDone)
#else  /* !__STDC__ */
BOOL             WIN_TtaInitDialogue (server, txtOK, txtRAZ, txtDone)
char* server; 
char* txtOK; 
char* txtRAZ; 
char* txtDone;
#endif /* __STDC__ */
#else  /* _WINDOWS */
#ifdef __STDC__
void                TtaInitDialogue (char *server, char *txtOK, char *txtRAZ, char *txtDone, ThotAppContext * app_context, Display ** Dp)

#else  /* __STDC__ */
void                TtaInitDialogue (server, txtOK, txtRAZ, txtDone, app_context, Dp)
char               *server;
char               *txtOK;
char               *txtRAZ;
char               *txtDone;
ThotAppContext     *app_context;
Display           **Dp;

#endif /* __STDC__ */
#endif /* _WINDOWS */
{
#  ifndef _WINDOWS
   int                 n;
#  endif /* !_WINDOWS */

#  ifdef _WINDOWS
#  ifndef _WIN_PRINT
   RootShell.style         = 0;
   RootShell.lpfnWndProc   = WndProc ;
   RootShell.cbClsExtra    = 0 ;
   RootShell.cbWndExtra    = 0 ;
   RootShell.hInstance     = hInstance ;
   RootShell.hIcon         = LoadIcon (hInstance, iconID) ;
   RootShell.hCursor       = LoadCursor (NULL, IDC_ARROW) ;
   RootShell.hbrBackground = (HBRUSH) GetStockObject (LTGRAY_BRUSH) ;
   RootShell.lpszMenuName  = "AmayaMain" ;
   RootShell.lpszClassName = tszAppName;
   RootShell.cbSize        = sizeof(WNDCLASSEX);
   RootShell.hIconSm       = LoadIcon (hInstance, iconID) ;

   if (!RegisterClassEx (&RootShell))
      return (FALSE);

   RootShell.style         = CS_DBLCLKS ;
   RootShell.lpfnWndProc   = ClientWndProc ;
   RootShell.cbClsExtra    = 0 ;
   RootShell.cbWndExtra    = 0 ;
   RootShell.hInstance     = hInstance ;
   RootShell.hIcon         = LoadIcon (hInstance, iconID) ;
   RootShell.hCursor       = LoadCursor (NULL, IDC_ARROW) ;
   RootShell.hbrBackground = (HBRUSH) (COLOR_WINDOW + 1) ;
   RootShell.lpszClassName = "ClientWndProc" ;
   RootShell.lpszMenuName  = NULL ;
   RootShell.cbSize        = sizeof(WNDCLASSEX);
   RootShell.hIconSm       = LoadIcon (hInstance, iconID) ;

   if (!RegisterClassEx (&RootShell))
      return (FALSE);

   RootShell.style         = 0 ;
   RootShell.lpfnWndProc   = ThotDlgProc ;
   RootShell.cbClsExtra    = 0 ;
   RootShell.cbWndExtra    = 0 ;
   RootShell.hInstance     = hInstance ;
   RootShell.hIcon         = LoadIcon (hInstance, iconID) ;
   RootShell.hCursor       = LoadCursor (NULL, IDC_ARROW) ;
   RootShell.lpszClassName = "WNDIALOGBOX" ;
   RootShell.lpszMenuName  = NULL ;
   RootShell.hbrBackground = (HBRUSH) GetStockObject (LTGRAY_BRUSH) ;
   RootShell.cbSize        = sizeof(WNDCLASSEX);
   RootShell.hIconSm       = LoadIcon (hInstance, iconID) ;
   
   if (!RegisterClassEx (&RootShell))
      return (FALSE);
#  endif /* !_WIN_PRINT */
#  endif /* _WINDOWS */

#  ifndef _WINDOWS
   /* Ouverture de l'application pour le serveur X-ThotWindow */
   RootShell = 0;
   XtToolkitInitialize ();
   n = 0;
   Def_AppCont = XtCreateApplicationContext ();
   GDp = XtOpenDisplay (Def_AppCont, server, "appli", "Dialogue", NULL, 0, &n, NULL);
   if (!GDp)
      /* Connexion au serveur X impossible */
      return;
   *app_context = Def_AppCont;
   *Dp = GDp;
   RootShell = XtAppCreateShell ("", "Dialogue", applicationShellWidgetClass, GDp, NULL, 0);

   /* redirige le handler de warnings vers une fonction vide pour eviter */
   /* les delires de motif */
   XtAppSetWarningHandler (*app_context, MyWarningHandler);

   /* Initialisation des options de dialogue */
   DefaultFont = XmFontListCreate (XLoadQueryFont (GDp, "fixed"), XmSTRING_DEFAULT_CHARSET);
   formFONT = XmFontListCreate (XLoadQueryFont (GDp, "fixed"), XmSTRING_DEFAULT_CHARSET);

#  endif /* _WINDOWS */

   if (txtOK == NULL)
      strcpy (Confirm_string, "Confirm");
   else if (strlen (txtOK) <= 80)
      strcpy (Confirm_string, txtOK);

   if (txtRAZ == NULL)
      strcpy (Cancel_string, "Cancel");
   else if (strlen (txtRAZ) <= 80)
      strcpy (Cancel_string, txtRAZ);

   if (!txtDone)
      strcpy (Done_string, "Done");
   else if (strlen (txtDone) <= 80)
      strcpy (Done_string, txtDone);


   CurrentWait = 0;
   ShowReturn = 0;
   ShowX = 100;
   ShowY = 100;

   /* Initialisation des catalogues */
   NbOccCat = 0;
   NbLibCat = 0;
   PtrCatalogue = NewCatList ();
   NbOccE_List = 0;
   NbLibE_List = 0;
   PtrFreeE_List = NULL;

   /* Initialisation des couleurs et des translations */
#  ifndef _WINDOWS
   TextTranslations = NULL;
#  endif /* _WINDOWS */
   MainShell = 0;
   /* Pas encore de reference attribuee */
   FirstFreeRef = 0;
#  ifdef _WINDOWS
   return TRUE;
#  endif /* _WINDOWS */
}

/*----------------------------------------------------------------------
   TtaInitDialogueTranslations initialise les translations du         
   dialogue. Ce sont tous les racoursis claviers.                     
  ----------------------------------------------------------------------*/
#ifdef __STDC__
void                TtaInitDialogueTranslations (ThotTranslations translations)
#else  /* __STDC__ */
void                TtaInitDialogueTranslations (translations)
ThotTranslations      translations;

#endif /* __STDC__ */
{
   TextTranslations = translations;
}


/*----------------------------------------------------------------------
   TtaChangeDialogueFonts change les polices de caracteres du dialogue.
  ----------------------------------------------------------------------*/
#ifdef __STDC__
void                TtaChangeDialogueFonts (char *menufont, char *formfont)
#else  /* __STDC__ */
void                TtaChangeDialogueFonts (menufont, formfont)
char               *menufont;
char               *formfont;
#endif /* __STDC__ */
{
#  ifdef _WINDOWS
   /* see code/chap04/ezfont.c */
#  endif
#  ifndef _WINDOWS
   if (menufont != NULL)
      DefaultFont = XmFontListCreate (XLoadQueryFont (GDp, menufont), XmSTRING_DEFAULT_CHARSET);
   if (menufont != NULL)
      formFONT = XmFontListCreate (XLoadQueryFont (GDp, formfont), XmSTRING_DEFAULT_CHARSET);
#  endif /* _WINDOWS */
}


/*----------------------------------------------------------------------
   TtaGetReferencesBase re'serve number re'fe'rences pour          
   l'application a` partir de la base courante.            
   La fonction retourne la base courante.                  
  ----------------------------------------------------------------------*/
#ifdef __STDC__
int                 TtaGetReferencesBase (int number)
#else  /* __STDC__ */
int                 TtaGetReferencesBase (number)
int                 number;

#endif /* __STDC__ */
{
   int                 base;

   base = FirstFreeRef;
   if (number > 0)
      FirstFreeRef += number;
   return (base);
}


/*----------------------------------------------------------------------
   TtaInitDialogueWindow Cre'ation et initialisation de la fenetree^tre    
   principale d'une application.                           
  ----------------------------------------------------------------------*/
#ifdef __STDC__
void                TtaInitDialogueWindow (char *name, char *geometry, Pixmap logo, Pixmap icon, int number, char *textmenu)
#else  /* __STDC__ */
void                TtaInitDialogueWindow (name, geometry, logo, icon, number, textmenu)
char               *name;
char               *geometry;
Pixmap              logo;
Pixmap              icon;
int                 number;
char               *textmenu;

#endif /* __STDC__ */
{
#ifndef _WINDOWS
   Arg                 args[10];
   ThotWidget          frame;
   int                 index;
   ThotWidget          row, row1;
   ThotWidget          w;
   ThotWidget          Main_Wd;
   int                 k;
   ThotWidget          menu_bar;
   ThotWindow          wind;
#endif /* !_WINDOWS */

   int                 n;
   char               *value;

#  ifndef _WINDOWS
   Pixmap              lthot;
#  endif /* _WINDOWS */

   FrRef[0] = 0;
#  ifdef _WINDOWS
   FrMainRef[0] = 0;
#  endif /* _WINDOWS */
   FrameTable[0].WdStatus = 0;
   MainShell = 0;
   FrameTable[0].WdFrame = 0;	/* widget frame */
   n = 0;
   value = TtaGetEnvString ("Geometry");

#  ifndef _WINDOWS
   if (value != NULL)
     {
	XtSetArg (args[n], XmNgeometry, value);
	n++;
     }
   else if (geometry != NULL)
     {
	XtSetArg (args[n], XmNgeometry, geometry);
	n++;
     }
#  endif /* _WINDOWS */

   if (number == 0 && logo == 0 && !WithMessages)
      return;

#  ifndef _WINDOWS
   /* Icone de la fenetre d'application */
   XtSetArg (args[n], XmNiconPixmap, icon);
   n++;
   XtSetArg (args[n], XmNmwmDecorations, MWM_DECOR_MENU);
   n++;
   MainShell = XtCreatePopupShell (name, applicationShellWidgetClass, RootShell, args, n);
   if (!MainShell)
      /* La frame de dialogue ne peut etre ouverte */
      TtaError (ERR_cannot_open_main_window);
   else
     {
	/* Creation la fenetre appli */
	n = 0;
	XtSetArg (args[n], XmNbackground, Button_Color);
	n++;
	XtSetArg (args[n], XmNspacing, 0);
	n++;
	Main_Wd = XmCreateMainWindow (MainShell, "Thot", args, n);
	XtManageChild (Main_Wd);

	if (number > 0)
	  {
	    /*** La barre des menus ***/
	     n = 0;
	     XtSetArg (args[n], XmNbackground, BgMenu_Color);
	     n++;
	     XtSetArg (args[n], XmNspacing, 0);
	     n++;
	     menu_bar = XmCreateMenuBar (Main_Wd, "Barre_menu", args, n);
	     XtManageChild (menu_bar);

	     /*** Creation des menus ***/
	     n = 0;
	     XtSetArg (args[n], XmNbackground, BgMenu_Color);
	     n++;
	     XtSetArg (args[n], XmNforeground, Black_Color);
	     n++;
	     XtSetArg (args[n], XmNfontList, DefaultFont);
	     n++;
	     XtSetArg (args[n], XmNborderWidth, 0);
	     n++;

	     /* Creation des boutons du menu */
	     index = 0;
	     for (k = 0; k < number; k++)
	       {
		  w = XmCreateCascadeButton (menu_bar, &textmenu[index], args, n);
		  XtManageChild (w);
		  FrameTable[0].WdMenus[k] = w;
		  index += strlen (&textmenu[index]) + 1;
	       }
	  }
	else
	   menu_bar = 0;
	frame = 0;
	n = 0;
	XtSetArg (args[n], XmNbackground, BgMenu_Color);
	n++;
	XtSetArg (args[n], XmNmarginWidth, 0);
	n++;
	XtSetArg (args[n], XmNmarginHeight, 0);
	n++;
	frame = XmCreateFrame (Main_Wd, "Frame", args, n);
	XtManageChild (frame);

	/*** Creation de la zone messages ***/
	if (WithMessages || logo != 0)
	  {

	     /* Un row-column pour afficher le logo a gauche des messages */
	     n = 0;
	     XtSetArg (args[n], XmNbackground, BgMenu_Color);
	     n++;
	     XtSetArg (args[n], XmNorientation, XmHORIZONTAL);
	     n++;
	     XtSetArg (args[n], XmNmarginWidth, 0);
	     n++;
	     XtSetArg (args[n], XmNmarginHeight, 0);
	     n++;
	     XtSetArg (args[n], XmNadjustLast, TRUE);
	     n++;
	     row = XmCreateRowColumn (frame, "", args, n);
	     XtManageChild (row);
	     /* Un row-column pour afficher le logo et copyright */
	     n = 0;
	     XtSetArg (args[n], XmNbackground, BgMenu_Color);
	     n++;
	     XtSetArg (args[n], XmNorientation, XmHORIZONTAL);
	     n++;
	     XtSetArg (args[n], XmNmarginWidth, 0);
	     n++;
	     XtSetArg (args[n], XmNmarginHeight, 0);
	     n++;
	     XtSetArg (args[n], XmNorientation, XmVERTICAL);
	     n++;
	     /*XtSetArg(args[n], XmNadjustLast, FALSE); n++; */
	     XtSetArg (args[n], XmNentryAlignment, XmALIGNMENT_CENTER);
	     n++;
	     row1 = XmCreateRowColumn (row, "", args, n);
	     XtManageChild (row1);

	     /* Traitement du logo de l'application */
	     if (logo != 0)
	       {
		  n = 0;
		  XtSetArg (args[n], XmNbackground, BgMenu_Color);
		  n++;
		  XtSetArg (args[n], XmNforeground, Black_Color);
		  n++;
		  XtSetArg (args[n], XmNlabelType, XmPIXMAP);
		  n++;
		  XtSetArg (args[n], XmNlabelPixmap, logo);
		  n++;
		  w = XmCreateLabel (row1, "Logo", args, n);
		  XtManageChild (w);
	       }

	     /* Recuperation de la couleur de trace */
	     n = 0;
	     XtSetArg (args[n], XmNbackground, BgMenu_Color);
	     n++;
	     XtSetArg (args[n], XmNforeground, Black_Color);
	     n++;
	     wind = RootWindow (GDp, DefaultScreen (GDp));
	     lthot = XCreatePixmapFromBitmapData (GDp, wind,
			  copyright_bits, copyright_width, copyright_height,
						  Black_Color, BgMenu_Color,
						  DefaultDepth (GDp, 0));
	     XtSetArg (args[n], XmNlabelType, XmPIXMAP);
	     n++;
	     XtSetArg (args[n], XmNlabelPixmap, lthot);
	     n++;
	     w = XmCreateLabel (row1, "Logo", args, n);
	     XtManageChild (w);

	     if (WithMessages)
	       {
		  /* Le scrolled text */
		  n = 0;
		  XtSetArg (args[n], XmNeditMode, XmMULTI_LINE_EDIT);
		  n++;
		  XtSetArg (args[n], XmNeditable, FALSE);
		  n++;
		  XtSetArg (args[n], XmNrows, 3);
		  n++;
		  XtSetArg (args[n], XmNcolumns, 50);
		  n++;
		  XtSetArg (args[n], XmNbackground, White_Color);
		  n++;
		  XtSetArg (args[n], XmNfontList, DefaultFont);
		  n++;
		  FrameTable[0].WdStatus = XmCreateScrolledText (row, "Thot_MSG", args, n);
		  XtManageChild (FrameTable[0].WdStatus);
		  XmTextSetAddMode (FrameTable[0].WdStatus, TRUE);
	       }
	  }

	/*** Creation d'un frame pour attacher le dialogue ***/
	n = 0;
	XtSetArg (args[n], XmNmarginWidth, 0);
	n++;
	XtSetArg (args[n], XmNmarginHeight, 0);
	n++;
	XtSetArg (args[n], XmNbackground, BgMenu_Color);
	n++;
	w = XmCreateFrame (Main_Wd, "Frame", args, n);
	XtManageChild (w);
	FrameTable[0].WdFrame = Main_Wd;	/* widget frame */

	/*** Realisation de la fenetre de dialogue ***/
	if (menu_bar != 0 || frame != 0)
	   XmMainWindowSetAreas (Main_Wd, menu_bar, w, NULL, NULL, frame);
	XtPopup (MainShell, XtGrabNonexclusive);
	FrRef[0] = XtWindowOfObject (w);
     }
#  endif /* _WINDOWS */
}

#ifndef _WINDOWS
/*----------------------------------------------------------------------
  ----------------------------------------------------------------------*/
#ifdef __STDC__
static void         ConfirmMessage (Widget w, Widget MsgBox, caddr_t call_d)
#else  /* __STDC__ */
static void         ConfirmMessage (w, MsgBox, call_d)
Widget              w;
Widget              MsgBox;
caddr_t             call_d;

#endif /* __STDC__ */
{
   XtPopdown (MsgBox);
}
#endif /* !_WINDOWS */

#ifndef _WIN_PRINT
/*----------------------------------------------------------------------
   DisplayConfirmMessage displays the given message (text).        
  ----------------------------------------------------------------------*/
#ifdef __STDC__
void                DisplayConfirmMessage (char *text)
#else  /* __STDC__ */
void                DisplayConfirmMessage (text)
char               *text;

#endif /* __STDC__ */
{
#  ifndef _WINDOWS
   XmString            title_string, OK_string;
   Arg                 args[MAX_ARGS];
   ThotWidget          row, w;
   ThotWidget          msgbox;
   int                 n;

   /* get current position */
   TtaSetDialoguePosition ();

   /* Create the window message */
   title_string = XmStringCreateSimple (text);
   OK_string = XmStringCreateSimple (Confirm_string);
   n = 0;
   XtSetArg (args[n], XmNx, (Position) ShowX);
   n++;
   XtSetArg (args[n], XmNy, (Position) ShowY);
   n++;
   XtSetArg (args[n], XmNallowShellResize, TRUE);
   n++;
   XtSetArg (args[n], XmNuseAsyncGeometry, TRUE);
   n++;
   msgbox = XtCreatePopupShell (Confirm_string, applicationShellWidgetClass,
				RootShell, args, n);
   n = 0;
   XtSetArg (args[n], XmNbackground, BgMenu_Color);
   n++;
   XtSetArg (args[n], XmNborderColor, Button_Color);
   n++;
   XtSetArg (args[n], XmNfontList, DefaultFont);
   n++;
   XtSetArg (args[n], XmNdialogTitle, OK_string);
   n++;
   XtSetArg (args[n], XmNautoUnmanage, FALSE);
   n++;
   XtSetArg (args[n], XmNmarginWidth, 0);
   n++;
   XtSetArg (args[n], XmNmarginHeight, 0);
   n++;
   XtSetArg (args[n], XmNspacing, 0);
   n++;
   w = XmCreateBulletinBoard (msgbox, "Dialogue", args, n);
   XtManageChild (w);

/*** Create a Row-Column to add the label and OK button ***/
   n = 0;
   XtSetArg (args[n], XmNbackground, BgMenu_Color);
   n++;
   XtSetArg (args[n], XmNborderColor, Button_Color);
   n++;
   XtSetArg (args[n], XmNadjustLast, FALSE);
   n++;
   XtSetArg (args[n], XmNmarginWidth, 0);
   n++;
   XtSetArg (args[n], XmNmarginHeight, 0);
   n++;
   XtSetArg (args[n], XmNspacing, 0);
   n++;
   XtSetArg (args[n], XmNpacking, XmPACK_TIGHT);
   n++;
   XtSetArg (args[n], XmNorientation, XmVERTICAL);
   n++;
   XtSetArg (args[n], XmNresizeHeight, TRUE);
   n++;
   row = XmCreateRowColumn (w, "Dialogue", args, n);
   XtManageChild (row);

   /* the label */
   n = 0;
   XtSetArg (args[n], XmNborderColor, Button_Color);
   n++;
   XtSetArg (args[n], XmNfontList, DefaultFont);
   n++;
   XtSetArg (args[n], XmNbackground, BgMenu_Color);
   n++;
   XtSetArg (args[n], XmNforeground, Black_Color);
   n++;
   XtSetArg (args[n], XmNlabelString, title_string);
   n++;
   w = XmCreateLabel (row, "Thot_MSG", args, n);
   XtManageChild (w);

   /*** Create the Row-Column that includes OK button ***/
   n = 0;
   XtSetArg (args[n], XmNborderColor, Button_Color);
   n++;
   XtSetArg (args[n], XmNfontList, DefaultFont);
   n++;
   XtSetArg (args[n], XmNbackground, BgMenu_Color);
   n++;
   XtSetArg (args[n], XmNorientation, XmHORIZONTAL);
   n++;
   XtSetArg (args[n], XmNmarginWidth, 100);
   n++;
   XtSetArg (args[n], XmNmarginHeight, 0);
   n++;
   row = XmCreateRowColumn (row, "Dialogue", args, n);
   XtManageChild (row);

   /*** Create the OK button ***/
   n = 0;
   XtSetArg (args[n], XmNbackground, Button_Color);
   n++;
   XtSetArg (args[n], XmNforeground, Black_Color);
   n++;
   XtSetArg (args[n], XmNbottomShadowColor, BgMenu_Color);
   n++;
   XtSetArg (args[n], XmNfontList, DefaultFont);
   n++;
   w = XmCreatePushButton (row, Confirm_string, args, n);
   XtManageChild (w);
   XtAddCallback (w, XmNactivateCallback, (XtCallbackProc) ConfirmMessage, msgbox);

   /* display the message */
   XtPopup (msgbox, XtGrabNonexclusive);

   XmStringFree (title_string);
   XmStringFree (OK_string);
#  endif /* _WINDOWS */
}

/*----------------------------------------------------------------------
   DisplayMessage display the given messge (text) in main window   
   according to is msgType.		                
   - INFO : bellow the previous message.                   
   - OVERHEAD : instead of the previous message.           
  ----------------------------------------------------------------------*/
#ifdef __STDC__
void                DisplayMessage (char *text, int msgType)
#else  /* __STDC__ */
void                DisplayMessage (text, msgType)
char               *text;
int                 msgType;

#endif /* __STDC__ */
{
#  ifndef _WINDOWS
   int                 lg;
   int                 n;
   char                buff[500 + 1];
   char               *pointer;

   /* Is the initialisation done ? */
   lg = strlen (text);
   if (MainShell != 0 && WithMessages && lg > 0)
     {
	/* take current messages */
	strncpy (buff, XmTextGetString (FrameTable[0].WdStatus), 500);
	n = strlen (buff);

	if (msgType == INFO)
	  {
	     /* is it necessary to suppress one or more messages ? */
	     if (n + lg + 1 >= 500)
	       {
		  /* suppress messages */
		  /* kill until we have 50 free characters */
		  while (n + lg + 1 >= 450)
		    {
		       /* search next New Line */
		       pointer = strchr (buff, '\n');
		       if (pointer == NULL)
			  n = 0;
		       else
			 {
			    strcpy (buff, &pointer[1]);
			    n = strlen (buff);
			 }
		    }

		  /* add message */
		  if (n > 0)
		     strcpy (&buff[n++], "\n");
		  strncpy (&buff[n], text, 500 - n);
		  lg += n;

		  /* copy text */
		  XmTextSetString (FrameTable[0].WdStatus, buff);
	       }
	     else
	       {
		  /* enough space, just add new message at the end */
		  strcpy (buff, "\n");
		  strcat (buff, text);
		  XmTextInsert (FrameTable[0].WdStatus, n, buff);
		  lg += n;
	       }
	     /* select the message end to force scroll down */
	     XmTextSetSelection (FrameTable[0].WdStatus, lg, lg, 500);
	  }
	else if (msgType == OVERHEAD)
	  {
	     /* search last New Line */
	     while (buff[n] != '\n' && n >= 0)
		n--;
	     /* replace last message by the new one */
	     XmTextReplace (FrameTable[0].WdStatus, n + 1, strlen (buff), text);
	  }
	XFlush (GDp);
     }
#  endif /* _WINDOWS */
}
#endif /* _WIN_PRINT */

/*----------------------------------------------------------------------
   DefineCallbackDialog de'finit la proce'dure de traitement des      
   retoursde catalogues dans l'application.                           
  ----------------------------------------------------------------------*/
#ifdef __STDC__
void                TtaDefineDialogueCallback (void (*procedure) ())
#else  /* __STDC__ */
void                TtaDefineDialogueCallback (procedure)
void                (*procedure) ();

#endif /* __STDC__ */
{
   CallbackDialogue = procedure;
}



/*----------------------------------------------------------------------
   ClearChildren nettoie tous les catalalogues fils du catalogue.     
  ----------------------------------------------------------------------*/
#ifdef __STDC__
static void         ClearChildren (struct Cat_Context *parentCatalogue)
#else  /* __STDC__ */
static void         ClearChildren (parentCatalogue)
struct Cat_Context *parentCatalogue;

#endif /* __STDC__ */
{
   register int        icat;
   struct Cat_Context *catalogue;
   struct Cat_List    *adlist;

   /* Tous les sous-menus ou sous-formulaires sont detruits par MOTIF */
   /* Recherche les catalogues qui sont les fils de parentCatalogue         */
   adlist = PtrCatalogue;
   while (adlist != NULL)
     {
	icat = 0;
	while (icat < MAX_CAT)
	  {
	     catalogue = &adlist->Cat_Table[icat];
	     if ((catalogue->Cat_Widget != 0)
		 && (catalogue->Cat_PtParent == parentCatalogue))
	       {
		  /* Libere les blocs des entrees */
		  if ((catalogue->Cat_Type != CAT_TEXT)
		      && (catalogue->Cat_Type != CAT_SELECT)
		      && (catalogue->Cat_Type != CAT_LABEL))
		    {
		       FreeEList (catalogue->Cat_Entries);
		       catalogue->Cat_Entries = NULL;
		    }		/*if */

		  /* Libere le catalogue */
		  catalogue->Cat_Widget = 0;
		  NbLibCat++;
		  NbOccCat--;

		  if ((catalogue->Cat_Type == CAT_POPUP)
		      || (catalogue->Cat_Type == CAT_PULL)
		      || (catalogue->Cat_Type == CAT_MENU)
		      || (catalogue->Cat_Type == CAT_FORM)
		      || (catalogue->Cat_Type == CAT_SHEET)
		      || (catalogue->Cat_Type == CAT_DIALOG))
		     ClearChildren (catalogue);
	       }		/*if */
	     icat++;
	  }			/*while */
	/* On passe au bloc suivant */
	adlist = adlist->Cat_Next;
     }				/*while */
}				/*ClearChildren */

/*----------------------------------------------------------------------
   CatEntry recherche si le catalogue de'signe' par sa re'fe'rence   
   existe de'ja` ou une entre'e libre dans la table des catalogues.   
   Retourne l'adresse du catalogue cre'e' ou NULL.                    
  ----------------------------------------------------------------------*/
#ifdef __STDC__
static struct Cat_Context *CatEntry (int ref)
#else  /* __STDC__ */
static struct Cat_Context *CatEntry (ref)
int                 ref;

#endif /* __STDC__ */
{
   register int        icat;
   struct Cat_Context *catlib;
   struct Cat_Context *catval;
   struct Cat_Context *catalogue;
   struct Cat_List    *adlist;

   /* Si la reference depasse la borne declaree */
   if (ref >= FirstFreeRef)
      return (NULL);

   /* Une entree de catalogue libre */
   catlib = NULL;
   /* L'entree qui porte la reference */
   catval = NULL;

   /* Parcours toutes les entrees existantes */
   adlist = PtrCatalogue;
   while (adlist != NULL && catval == NULL)
     {
	icat = 0;
	while (icat < MAX_CAT && catval == NULL)
	  {
	     catalogue = &adlist->Cat_Table[icat];
	     /*===============> C'est la premiere entree libre */
	     if (catalogue->Cat_Widget == 0)
	       {
		  if (catlib == NULL)
		     catlib = catalogue;
	       }
	     /*===============> Le catalogue existe deja */
	     else if (catalogue->Cat_Ref == ref)
		catval = catalogue;

	     icat++;
	  }

	/* On passe au bloc suivant */
	if (adlist->Cat_Next == NULL && catval == NULL && catlib == NULL)
	  {
	     /* Cree une nouvelle liste de catalogues */
	     adlist->Cat_Next = NewCatList ();
	  }
	adlist = adlist->Cat_Next;
     }

   /* Si le catalogue n'existe pas encore */
   if (catval == NULL && catlib != NULL)
     {
	catlib->Cat_PtParent = NULL;
	NbOccCat++;
	NbLibCat--;
	return (catlib);
     }
   else
      return (catval);
}

#ifdef _WINDOWS
/*----------------------------------------------------------------------
  WIN_ListOpenDirectory
  ----------------------------------------------------------------------*/
#ifdef __STDC__
void WIN_ListOpenDirectory (HWND parent, char* fileName)
#else  /* __STDC__ */
void WIN_ListOpenDirectory (parent, fileName)
HWND parent;
char* fileName;
#endif /* __STDC__ */
{

 	TCHAR szFilter[] = APPFILENAMEFILTER;
	TCHAR szFileName[256];

    OpenFileName.lStructSize       = sizeof (OPENFILENAME); 
    OpenFileName.hwndOwner         = parent; 
    OpenFileName.hInstance         = hInstance ; 
    OpenFileName.lpstrFilter       = (LPSTR) szFilter; 
    OpenFileName.lpstrCustomFilter = (LPTSTR) NULL; 
    OpenFileName.nMaxCustFilter    = 0L; 
    OpenFileName.nFilterIndex      = 1L; 
    OpenFileName.lpstrFile         = (LPSTR) szFileName; 
    OpenFileName.nMaxFile          = 256; 
    OpenFileName.lpstrInitialDir   = NULL; 
    OpenFileName.lpstrTitle        = TEXT ("Open a File"); 
    OpenFileName.nFileOffset       = 0; 
    OpenFileName.nFileExtension    = 0; 
    OpenFileName.lpstrDefExt       = TEXT ("*.html"); 
    OpenFileName.lCustData         = 0; 
    OpenFileName.Flags             = OFN_SHOWHELP | OFN_HIDEREADONLY; 
 
    if (GetOpenFileName (&OpenFileName)) {
	   strcpy (fileName, OpenFileName.lpstrFile);
	}

}

/*----------------------------------------------------------------------
  WIN_ListSaveDirectory
  ----------------------------------------------------------------------*/
#ifdef __STDC__
void WIN_ListSaveDirectory (int parentRef, char* fileName)
#else  /* __STDC__ */
void WIN_ListSaveDirectory (parentRef, fileName)
int   parentRef; 
char* fileName; 
#endif /* __STDC__ */
{

    struct Cat_Context* parentCatalogue = CatEntry (parentRef);
 	TCHAR               szFilter[] = APPFILENAMEFILTER;
	TCHAR               szFileName[256];
	TCHAR               szFileTitle[256];

	szFileName[0] = EOS;

    OpenFileName.lStructSize       = sizeof (OPENFILENAME); 
    OpenFileName.hwndOwner         = parentCatalogue->Cat_Widget; 
    OpenFileName.lpstrFilter       = (LPSTR) szFilter;
    OpenFileName.lpstrFile         = (LPSTR) szFileName; 
    OpenFileName.nMaxFile          = sizeof (szFileName); 
    OpenFileName.lpstrFileTitle    = szFileTitle; 
	OpenFileName.lpstrTitle        = TEXT ("Save File as"); 
    OpenFileName.nMaxFileTitle     = sizeof (szFileTitle); 
    OpenFileName.lpstrInitialDir   = NULL; 
    OpenFileName.Flags             = OFN_SHOWHELP | OFN_OVERWRITEPROMPT | OFN_HIDEREADONLY ;

    if (GetSaveFileName (&OpenFileName)) { 
	   strcpy (fileName, OpenFileName.lpstrFile);
    } 
}
#endif /* _WINDOWS */


/*----------------------------------------------------------------------
   DestContenuMenu de'truit les entre'es du catalogue de'signe' par   
   son index.                                                         
   Retourne un code d'erreur.                                         
  ----------------------------------------------------------------------*/
#ifdef __STDC__
static int          DestContenuMenu (struct Cat_Context *catalogue)

#else  /* __STDC__ */
static int          DestContenuMenu (catalogue)
struct Cat_Context *catalogue;

#endif /* __STDC__ */
{
   register int        ent;
   struct E_List      *adbloc;
   ThotWidget          w;

   if (catalogue == NULL)
      return (1);
   else if (catalogue->Cat_Widget == 0)
      return (1);
   else
     {
	if (catalogue->Cat_Type == CAT_LABEL)
	  {
	     /* Recupere le widget parent du widget detruit */
#            ifndef _WINDOWS
	     w = XtParent (catalogue->Cat_Widget);
	     XtDestroyWidget (catalogue->Cat_Widget);
#            else  /* _WINDOWS */
	     w = GetParent (catalogue->Cat_Widget);
	     DestroyWindow (w);
#            endif /* _WINDOWS */
	     catalogue->Cat_Widget = 0;
	  }
	else
	  {
	     /* Ce sont des menus */
	     adbloc = catalogue->Cat_Entries;
	     /* On saute les entrees 0 et 1 */
	     ent = 2;
	     w = 0;
	     if (adbloc != NULL)
		/* Liberation de toutes les entrees du menu */
		while (adbloc->E_ThotWidget[ent] != 0)
		  {
		     /* Recuperation du widget parent en sautant le widget titre */
#                    ifdef _WINDOWS
		     if (w == 0 && ent != 0)
			w = GetParent (adbloc->E_ThotWidget[ent]);

		     DestroyWindow (adbloc->E_ThotWidget[ent]);
#                    else  /* _WINDOWS */
		     if (w == 0 && ent != 0)
			w = XtParent (adbloc->E_ThotWidget[ent]);

		     /* Libere les widgets */
		     XtUnmanageChild (adbloc->E_ThotWidget[ent]);
		     XtDestroyWidget (adbloc->E_ThotWidget[ent]);
#                    endif /* _WINDOWS */
		     adbloc->E_ThotWidget[ent] = (ThotWidget) 0;

		     /* Faut-il changer de bloc d'entrees ? */
		     ent++;
		     if (ent >= C_NUMBER)
		       {
			  if (adbloc->E_Next != NULL)
			     adbloc = adbloc->E_Next;
			  ent = 0;
		       }	/*if */
		  }		/*while */

	     /* Note que tous les fils sont detruits par MOTIF */
	     if ((catalogue->Cat_Type == CAT_POPUP)
		 || (catalogue->Cat_Type == CAT_PULL)
		 || (catalogue->Cat_Type == CAT_MENU))
		ClearChildren (catalogue);

	     /* Libere les blocs des entrees */
	     adbloc = catalogue->Cat_Entries->E_Next;
	     FreeEList (adbloc);
	     catalogue->Cat_Entries->E_Next = NULL;
	  }			/*else */

	/* On memorise le widget parent des entrees a recreer */
	catalogue->Cat_XtWParent = w;
	return (0);
     }
}


/*----------------------------------------------------------------------
   TtaNewPulldown cre'e un pull-down menu :                           
   Le parame`tre ref donne la re'fe'rence pour l'application.         
   Le parame`tre parent identifie le widget pe`re du pull-down menu.  
   Le parame`tre title donne le titre du catalogue.                   
   Le parame`tre number indique le nombre d'entre'es dans le menu.    
   Le parame`tre text contient la liste des intitule's du catalogue.  
   Chaque intitule' commence par un caracte`re qui donne le type de   
   l'entre'e et se termine par un caracte`re de fin de chai^ne \0.    
   S'il n'est pas nul, le parame`tre ] donne les acce'le'rateurs  
   des entre'es du menu.                                              
   Retourne un code d'erreur.                                         
  ----------------------------------------------------------------------*/
#ifdef __STDC__
void                TtaNewPulldown (int ref, ThotWidget parent, char *title, int number, char *text, char *equiv)
#else  /* __STDC__ */
void                TtaNewPulldown (ref, parent, title, number, text, equiv)
int                 ref;
ThotWidget          parent;
char               *title;
int                 number;
char               *text;
char               *equiv;

#endif /* __STDC__ */
{
   register int        count;
   register int        index;
   register int        ent;
   int                 eindex;
   register int        i;
   int                 n;
   boolean             rebuilded;
   struct Cat_Context *catalogue;
   struct E_List      *adbloc;

   ThotWidget          menu;
   ThotWidget          w;
   char                heading[200];

#  ifdef _WINDOWS
   struct Cat_Context *copyCat;
   char                menu_item [1024];
   char                equiv_item [255];
#  endif /* _WINDOWS */

#  ifndef _WINDOWS
   Arg                 args[MAX_ARGS];
   XmString            title_string;
#  endif

#  ifdef _WINDOWS
   equiv_item[0] = 0;
#  endif /* _WINDOWS */

   if (ref == 0)
     {
	TtaError (ERR_invalid_reference);
	return;
     }
   catalogue = CatEntry (ref);

#  ifndef _WINDOWS
   title_string = 0;
#  endif /* _WINDOWS */

   if (catalogue == NULL)
      TtaError (ERR_cannot_create_dialogue);
   else
     {
	/* Est-ce que le catalogue existe deja ? */
	rebuilded = FALSE;
	if (catalogue->Cat_Widget != 0)
	  {
	     if (catalogue->Cat_Type == CAT_PULL)
	       {
		  DestContenuMenu (catalogue);	/* Modification du catalogue */
		  rebuilded = TRUE;
	       }
	     else
		TtaDestroyDialogue (ref);
	  }			/*if */

#       ifndef _WINDOWS
	/* Cree le menu correspondant */
	n = 0;
	XtSetArg (args[n], XmNbackground, BgMenu_Color);
	n++;
	XtSetArg (args[n], XmNborderColor, Button_Color);
	n++;
#       endif /* _WINDOWS */
	if (parent == 0)
	  {
	     TtaError (ERR_invalid_parent_dialogue);
	     return;
	  }
	else if (number == 0)
	   menu = (ThotWidget) - 1;	/* pas de pull-down */
	else if (!rebuilded)
	  {
#            ifdef _WINDOWS
	     menu = parent;
#            else  /* _WINDOWS */
	     menu = XmCreatePulldownMenu (XtParent (parent), "Dialogue", args, n);
#            endif /* _WINDOWS */
	  }
	else
	  {
	     menu = catalogue->Cat_Widget;
	  }

	catalogue->Cat_Ref = ref;
	catalogue->Cat_Type = CAT_PULL;
	catalogue->Cat_Button = 'L';
	catalogue->Cat_Data = -1;

	catalogue->Cat_Widget = (ThotWidget) menu;
	adbloc = catalogue->Cat_Entries;
	if (number == 0)
	  {
	     /* c'est un bouton et non un pull-down */
	     catalogue->Cat_Data = 1;
	     if (parent != 0)
	       {
#                 ifndef _WINDOWS
		  XtManageChild (parent);
		  XtAddCallback (parent, XmNcascadingCallback, (XtCallbackProc) CallMenu, catalogue);
#                 else  /* _WINDOWS */
                  copyCat = catalogue ;
                  WIN_AddFrameCatalogue (parent, copyCat) ;
                  /* WIN_AddFrameCatalogue (parent, catalogue) ; */
#                 endif /* _WINDOWS */
	       }
#          ifdef _WINDOWS
           else	if (currentParent != 0)
			   copyCat = catalogue;
               WIN_AddFrameCatalogue (currentParent, copyCat) ;
#          endif /* _WINDOWS */
	     return;
	  }

	/*** Cree le titre du menu ***/
	if (title != NULL)
	  {
#            ifndef _WINDOWS
	     n = 0;
	     title_string = XmStringCreateSimple (title);
	     XtSetArg (args[n], XmNlabelString, title_string);
	     n++;
#            endif /* _WINDOWS */
	     if (!rebuilded)
	       {
		  adbloc = NewEList ();
		  catalogue->Cat_Entries = adbloc;
#                 ifndef _WINDOWS
		  XtSetArg (args[n], XmNfontList, DefaultFont);
		  n++;
		  XtSetArg (args[n], XmNbackground, BgMenu_Color);
		  n++;
		  XtSetArg (args[n], XmNborderColor, Button_Color);
		  n++;
		  w = XmCreateLabel (menu, "Dialogue", args, n);
		  XtManageChild (w);
		  adbloc->E_ThotWidget[0] = w;
#                 else  /* _WINDOWS */
		  adbloc->E_ThotWidget[0] = (ThotWidget) 0;
#                 endif /* _WINDOWS */
		  n = 0;
#                 ifndef _WINDOWS
		  XtSetArg (args[n], XmNmarginHeight, 0);
		  n++;
		  XtSetArg (args[n], XmNspacing, 0);
		  n++;
		  XtSetArg (args[n], XmNbackground, Button_Color);
		  n++;
		  XtSetArg (args[n], XmNseparatorType, XmSHADOW_ETCHED_OUT);
		  n++;
		  w = XmCreateSeparator (menu, "Dialogue", args, n);
		  XtManageChild (w);
		  adbloc->E_ThotWidget[1] = w;
#                 else  /* _WINDOWS */
		  adbloc->E_ThotWidget[1] = (ThotWidget) 0;
#                 endif /* _WINDOWS */
	       }
#            ifndef _WINDOWS
	     else if (adbloc->E_ThotWidget[0] != 0)
		XtSetValues (adbloc->E_ThotWidget[0], args, n);
	     if (!title_string)
		XmStringFree (title_string);
#            endif /* _WINDOWS */
	  }
	else if (!rebuilded)
	  {
	     adbloc = NewEList ();
	     catalogue->Cat_Entries = adbloc;
	  }

#       ifndef _WINDOWS
	/* Cree les differentes entrees du menu */
	n = 0;
	XtSetArg (args[n], XmNfontList, DefaultFont);
	n++;
	XtSetArg (args[n], XmNmarginWidth, 0);
	n++;
	XtSetArg (args[n], XmNmarginHeight, 0);
	n++;
	XtSetArg (args[n], XmNbackground, BgMenu_Color);
	n++;
	XtSetArg (args[n], XmNforeground, Black_Color);
	n++;
	XtSetArg (args[n], XmNborderColor, Button_Color);
	n++;
#       endif /* _WINDOWS */
	if (equiv != NULL)
	   n++;
	i = 0;
	index = 0;
	eindex = 0;
	ent = 2;

	if (text != NULL)
	   while (i < number)
	     {
		count = strlen (&text[index]);	/* Longueur de l'intitule */
		/* S'il n'y a plus d'intitule -> on arrete */
		if (count == 0)
		  {
		     i = number;
		     TtaError (ERR_invalid_parameter);
		     return;
		  }
		else
		  {

		     /* Faut-il changer de bloc d'entrees ? */
		     if (ent >= C_NUMBER)
		       {
			  adbloc->E_Next = NewEList ();
			  adbloc = adbloc->E_Next;
			  ent = 0;
		       }

		     /* Recupere le type de l'entree */
		     adbloc->E_Type[ent] = text[index];
		     adbloc->E_Free[ent] = 'Y';

		     /* Note l'accelerateur */
		     if (equiv != NULL)
		       {
#                         ifdef _WINDOWS
                          if (&equiv[eindex] != EOS) {
                             if (parseAccelerator (&equiv[eindex]))
                                addAccelerator (currentFrame, fVirt, key, ref + i);
                             sprintf (equiv_item, "%s", &equiv[eindex]); 
                          }
                          eindex += strlen (&equiv[eindex]) + 1;
#                         else  /* !_WINDOWS */
			  title_string = XmStringCreate (&equiv[eindex], XmSTRING_DEFAULT_CHARSET);
			  eindex += strlen (&equiv[eindex]) + 1;
			  XtSetArg (args[n - 1], XmNacceleratorText, title_string);
#                         endif /* _WINDOWS */
		       }

		     if (text[index] == 'B')
		       /*__________________________________________ Creation d'un bouton __*/
		       {
#                         ifdef _WINDOWS
              if (equiv_item && equiv_item [0] != 0) {
                 sprintf (menu_item, "%s\t%s", &text[index + 1], equiv_item); 
                 AppendMenu (menu, MF_STRING | MF_UNCHECKED, ref + i, menu_item);
                 equiv_item[0] = 0;
              } else 
                   AppendMenu (menu, MF_STRING | MF_UNCHECKED, ref + i, &text[index + 1]);
			  adbloc->E_ThotWidget[ent] = (ThotWidget) i;
                          copyCat = catalogue;
                          WIN_AddFrameCatalogue (parent, copyCat) ;
#                         else  /* _WINDOWS */
			  w = XmCreatePushButton (menu, &text[index + 1], args, n);
			  XtManageChild (w);
			  adbloc->E_ThotWidget[ent] = w;
			  XtAddCallback (w, XmNactivateCallback, (XtCallbackProc) CallMenu, catalogue);
#                         endif /* _WINDOWS */
		       }
		     else if (text[index] == 'T')
		       /*__________________________________________ Creation d'un toggle __*/
		       {
			  /* un toggle a faux */
#                         ifdef _WINDOWS
              if (equiv_item && equiv_item [0] != 0) {
                 sprintf (menu_item, "%s\t%s", &text[index + 1], equiv_item);
                 equiv_item [0] = 0;
              } else
                   sprintf (menu_item, "%s", &text[index + 1]);

              AppendMenu (menu, MF_STRING | MF_UNCHECKED, ref + i, menu_item);

			  adbloc->E_ThotWidget[ent] = (ThotWidget) i;
                          copyCat = catalogue;
                          WIN_AddFrameCatalogue (parent, copyCat) ;
#                         else  /* _WINDOWS */
			  XtSetArg (args[n], XmNvisibleWhenOff, TRUE);
			  XtSetArg (args[n + 1], XmNselectColor, White_Color);
			  w = XmCreateToggleButton (menu, &text[index + 1], args, n + 2);
			  XtManageChild (w);
			  adbloc->E_ThotWidget[ent] = w;
			  XtAddCallback (w, XmNvalueChangedCallback, (XtCallbackProc) CallMenu, catalogue);
#                         endif /* _WINDOWS */
		       }
		     else if (text[index] == 'M')
		       /*_______________________________________ Creation d'un sous-menu __*/
		       {
			  /* En attendant le sous-menu on cree un bouton */
#                         ifdef _WINDOWS
                          w = (HMENU) CreateMenu ();
                          if (equiv_item && equiv_item [0] != 0) {
                             sprintf (menu_item, "%s\t%s", &text[index + 1], equiv_item); 
                             AppendMenu (menu, MF_POPUP, (UINT) w, menu_item);
                             equiv_item [0] = 0;
                          } else 
                               AppendMenu (menu, MF_POPUP, (UINT) w, &text[index + 1]);
                          adbloc->E_ThotWidget[ent] = w;
						  /* *** T O    V E R I F Y *** */
                          copyCat = catalogue;
                          WIN_AddFrameCatalogue (parent, copyCat) ;
						  /* *** T O    V E R I F Y  *** */
#                         else  /* _WINDOWS */
			  w = XmCreateCascadeButton (menu, &text[index + 1], args, n);
			  adbloc->E_ThotWidget[ent] = w;
#                         endif /* _WINDOWS */
		       }
		     else if (text[index] == 'F')
		       /*_________________________________ Creation d'un sous-formulaire __*/
		       {
			  strcpy (heading, &text[index + 1]);
			  strcat (heading, "...");
#                         ifdef _WINDOWS
			  w = (HMENU) CreateMenu ();
			  AppendMenu (menu, MF_POPUP, (UINT) w, (LPCTSTR) (&heading));
			  adbloc->E_ThotWidget[ent] = (ThotWidget) w;
#                         else  /* _WINDOWS */
			  w = XmCreatePushButton (menu, heading, args, n);
			  XtManageChild (w);
			  adbloc->E_ThotWidget[ent] = w;
#                         endif /* _WINDOWS */
		       }
		     else if (text[index] == 'S')
		       /*_________________________________ Creation d'un separateur __*/
		       {
#                         ifdef _WINDOWS
			  AppendMenu (menu, MF_SEPARATOR, 0, NULL);
			  adbloc->E_ThotWidget[ent] = (ThotWidget) 0;
#                         else  /* _WINDOWS */
			  XtSetArg (args[n], XmNseparatorType, XmSINGLE_DASHED_LINE);
			  w = XmCreateSeparator (menu, "Dialogue", args, n + 1);
			  XtManageChild (w);
			  adbloc->E_ThotWidget[ent] = w;
#                         endif /* _WINDOWS */
		       }
		     else
		       /*____________________________________ Une erreur de construction __*/
		       {
			  TtaDestroyDialogue (ref);
			  /* Type d'entree non defini */
			  TtaError (ERR_invalid_parameter);
			  return;
		       }

#                    ifndef _WINDOWS
		     /* liberation de la string */
		     if (equiv != NULL && !title_string)
			XmStringFree (title_string);
#                    endif /* _WINDOWS */
		     i++;
		     ent++;
		     index += count + 1;
		  }
	     }

	/* Attache le pull-down menu au widget passe en parametre */
	if (parent != 0 && !rebuilded)
	  {
#            ifndef _WINDOWS
	     n = 0;
	     XtSetArg (args[n], XmNsubMenuId, menu);
	     n++;
	     XtSetValues (parent, args, n);
	     XtManageChild (parent);
#            endif /* _WINDOWS */
	  }
     }

}


/*----------------------------------------------------------------------
   TtaSetPulldownOff suspend le pulldown                           
  ----------------------------------------------------------------------*/
#ifdef _WINDOWS
#ifdef __STDC__
void                WIN_TtaSetPulldownOff (int ref, ThotWidget parent, HWND owner)
#else  /* __STDC__ */
void                WIN_TtaSetPulldownOff (ref, parent, owner)
int                 ref;
ThotWidget          parent;
HWND                owner;
#endif /* __STDC__ */
#else  /* !_WINDOWS */
#ifdef __STDC__
void                TtaSetPulldownOff (int ref, ThotWidget parent)
#else  /* __STDC__ */
void                TtaSetPulldownOff (ref, parent)
int                 ref;
ThotWidget          parent;
#endif /* __STDC__ */
#endif /* _WINDOWS */
{
   struct Cat_Context *catalogue;

#  ifndef _WINDOWS
   Arg                 args[MAX_ARGS];
#  else  /* _WINDOWS */
   int frame;
#  endif /* _WINDOWS */

   if (ref == 0)
      TtaError (ERR_invalid_reference);
   else if (parent == 0)
      TtaError (ERR_invalid_parent_dialogue);
   else
     {
	catalogue = CatEntry (ref);
	if (catalogue == NULL)
	   TtaError (ERR_invalid_reference);
#   ifndef _WINDOWS
	else if (catalogue->Cat_Widget != 0)
	  {
             XtSetArg (args[0], XmNsubMenuId, NULL);
             XtSetValues (parent, args, 1);
             XtManageChild (parent);
	  }
#   else  /* _WINDOWS */
	frame = GetMainFrameNumber (owner);
    EnableMenuItem (WinMenus[frame], parent, MF_GRAYED);
	DrawMenuBar (FrMainRef[frame]); 
#            endif /* _WINDOWS */
     }
}

/*----------------------------------------------------------------------
   TtaSetPulldownOn reactive le pulldown                           
  ----------------------------------------------------------------------*/
#ifdef _WINDOWS
#ifdef __STDC__
void                WIN_TtaSetPulldownOn (int ref, ThotWidget parent, HWND owner)
#else  /* __STDC__ */
void                WIN_TtaSetPulldownOn (ref, parent, owner)
int                 ref;
ThotWidget          parent;
HWND                owner;
#endif /* __STDC__ */
#else  /* !_WINDOWS */
#ifdef __STDC__
void                TtaSetPulldownOn (int ref, ThotWidget parent)
#else  /* __STDC__ */
void                TtaSetPulldownOn (ref, parent)
int                 ref;
ThotWidget          parent;
#endif /* __STDC__ */
#endif /* _WINDOWS */
{
   struct Cat_Context *catalogue;
   ThotWidget          menu;

#  ifndef _WINDOWS
   Arg                 args[MAX_ARGS];
#  else  /* _WINDOWS */
   int frame;
#  endif /* _WINDOWS */

   if (ref == 0)
      TtaError (ERR_invalid_reference);
   else if (parent == 0)
      TtaError (ERR_invalid_parent_dialogue);
   else
     {
	catalogue = CatEntry (ref);
	if (catalogue == NULL)
	   TtaError (ERR_invalid_reference);
	else if (catalogue->Cat_Widget != 0)
	  {
	     menu = catalogue->Cat_Widget;
#            ifndef _WINDOWS
             XtSetArg (args[0], XmNsubMenuId, menu);
             XtSetValues (parent, args, 1);
             XtManageChild (parent);
#            else  /* _WINDOWS */
			 frame = GetMainFrameNumber (owner);
             EnableMenuItem (WinMenus[frame], parent, MF_ENABLED);
			 DrawMenuBar (FrMainRef[frame]); 
#            endif /* _WINDOWS */
	  }
     }
}

/*----------------------------------------------------------------------
   TtaNewPopup cre'e un pop-up menu :                                 
   Le parame`tre ref donne la re'fe'rence pour l'application.         
   Le parame`tre title donne le titre du catalogue.                   
   Le parame`tre number indique le nombre d'entre'es dans le menu.    
   Le parame`tre text contient la liste des intitule's du catalogue.  
   Chaque intitule' commence par un caracte`re qui donne le type de   
   l'entre'e et se termine par un caracte`re de fin de chai^ne \0.    
   S'il n'est pas nul, le parame`tre equiv donne les acce'le'rateurs  
   des entre'es du menu.                                              
   Le parame`tre button indique le bouton de la souris qui active le  
   menu : 'L' pour left, 'M' pour middle et 'R' pour right.           
  ----------------------------------------------------------------------*/
#ifdef __STDC__
void                TtaNewPopup (int ref, ThotWidget parent, char *title, int number, char *text, char *equiv, char button)
#else  /* __STDC__ */
void                TtaNewPopup (ref, parent, title, number, text, equiv, button)
int                 ref;
ThotWidget          parent;
char               *title;
int                 number;
char               *text;
char               *equiv;
char                button;

#endif /* __STDC__ */
{
   register int        count;
   register int        index;
   register int        ent;
   register int        i;
   int                 eindex;
   boolean             rebuilded;
   struct Cat_Context *catalogue;
   struct E_List      *adbloc;
   char                heading[200];

#  ifdef _WINDOWS
   HMENU               menu;
   int                 nbOldItems, ndx;
   struct Cat_Context *copyCat;
#  else  /* _WINDOWS */
   Arg                 args[MAX_ARGS];
   ThotWidget          menu;
   XmString            title_string;
   ThotWidget          w;
   int                 n;
#  endif /* !_WINDOWS */

   if (ref == 0)
     {
	TtaError (ERR_invalid_reference);
	return;
     }
   catalogue = CatEntry (ref);
#  ifdef _WINDOWS
#  ifdef AMAYA_DEBUG
   fprintf (stderr, "TtaNewPopup(ref %d, parent %X, title %s, number %d,\n text %s, equiv %s, button %d)\n",
	    ref, parent, title, number, text, equiv, button);
   fprintf (stderr, "catalogue : %X\n", catalogue);
#  endif AMAYA_DEBUG
#  else  /* _WINDOWS */
   title_string = 0;
#  endif /* !_WINDOWS */
   menu = 0;
   if (catalogue == NULL)
      TtaError (ERR_cannot_create_dialogue);
   else
     {
	/* Est-ce que le catalogue existe deja ? */
	rebuilded = FALSE;
	if (catalogue->Cat_Widget != 0)
	  {
	     if (catalogue->Cat_Type == CAT_POPUP)
	       {
		 /* Modification du catalogue */
		  DestContenuMenu (catalogue);
		  rebuilded = TRUE;
	       }
	     else
		TtaDestroyDialogue (ref);
	  }

	if (!rebuilded)
	  {
	     /* Creation du Popup Shell pour contenir le menu */
#            ifdef _WINDOWS
         menu = parent;
#            else  /* _WINDOWS */
	     n = 0;
	     /*XtSetArg(args[n], XmNallowShellResize, TRUE); n++; */
	     XtSetArg (args[n], XmNheight, (Dimension) 10);
	     n++;
	     XtSetArg (args[n], XmNwidth, (Dimension) 10);
	     n++;
	     menu = XtCreatePopupShell ("Dialogue", xmMenuShellWidgetClass, RootShell, args, n);
#            endif /* !_WINDOWS */
	  }

	/* Cree le menu correspondant */
#       ifndef _WINDOWS
	if (button == 'R')
	   XtSetArg (args[0], XmNwhichButton, Button3);
	else if (button == 'M')
	   XtSetArg (args[0], XmNwhichButton, Button2);
	else
	  {
	     button = 'L';
	     XtSetArg (args[0], XmNwhichButton, Button1);
	  }
#       endif /* !_WINDOWS */

	if (!rebuilded)
	  {
#            ifndef _WINDOWS
	     n = 1;
	     XtSetArg (args[n], XmNmarginWidth, 0);
	     n++;
	     XtSetArg (args[n], XmNmarginHeight, 0);
	     n++;
	     XtSetArg (args[n], XmNspacing, 0);
	     n++;
	     XtSetArg (args[n], XmNbackground, BgMenu_Color);
	     n++;
	     XtSetArg (args[n], XmNborderColor, Button_Color);
	     n++;
	     XtSetArg (args[n], XmNrowColumnType, XmMENU_POPUP);
	     n++;
	     menu = XmCreateRowColumn (menu, "Dialogue", args, n);
	     XtAddCallback (XtParent (menu), XmNpopdownCallback, (XtCallbackProc) UnmapMenu, catalogue);
#            else  /* _WINDOWS */
		 menu = CreatePopupMenu ();
#            endif /* !_WINDOWS */
	     catalogue->Cat_Widget = menu;
	     catalogue->Cat_Ref = ref;
	     catalogue->Cat_Type = CAT_POPUP;
	     catalogue->Cat_Button = button;
	     /* Initialisation de la liste des widgets fils */
	     adbloc = NewEList ();
	     catalogue->Cat_Entries = adbloc;
	  }
	else
	  {
	     /* Mise a jour du menu existant */
	     menu = catalogue->Cat_Widget;
	     adbloc = catalogue->Cat_Entries;
	     /* Si on a change de bouton on met a jour le widget avec args[0] */
	     if (catalogue->Cat_Button != (unsigned char) button)
	       {
#                 ifndef _WINDOWS
		  XtSetValues (menu, args, 1);
#                 endif /* !_WINDOWS */
		  catalogue->Cat_Button = button;
	       }
	     else
		button = catalogue->Cat_Button;
	  }

	catalogue->Cat_Data = -1;

#   ifdef _WINDOWS
    if (currentParent != 0) {
       copyCat = catalogue;
       WIN_AddFrameCatalogue (currentParent, copyCat) ;
    }
#   endif /* _WINDOWS */

/*** Cree le titre du menu ***/
	if (title != NULL)
	  {
#            ifndef _WINDOWS
	     n = 0;
	     title_string = XmStringCreateSimple (title);
	     XtSetArg (args[n], XmNlabelString, title_string);
	     n++;
#            endif /* !_WINDOWS */
	     if (!rebuilded)
	       {
#                 ifdef _WINDOWS
		  adbloc->E_ThotWidget[0] = (ThotWidget) 0;
		  adbloc->E_ThotWidget[1] = (ThotWidget) 0;
#                 else  /* _WINDOWS */
		  XtSetArg (args[n], XmNfontList, DefaultFont);
		  n++;
		  XtSetArg (args[n], XmNmarginHeight, 0);
		  n++;
		  XtSetArg (args[n], XmNbackground, BgMenu_Color);
		  n++;
		  XtSetArg (args[n], XmNforeground, Black_Color);
		  n++;
		  XtSetArg (args[n], XmNborderColor, Button_Color);
		  n++;
		  w = XmCreateLabel (menu, "Dialogue", args, n);
		  XtManageChild (w);
		  adbloc->E_ThotWidget[0] = w;
		  n = 0;
		  XtSetArg (args[n], XmNbackground, Button_Color);
		  n++;
		  XtSetArg (args[n], XmNseparatorType, XmSHADOW_ETCHED_OUT);
		  n++;
		  w = XmCreateSeparator (menu, "Dialogue", args, n);
		  XtManageChild (w);
		  adbloc->E_ThotWidget[1] = w;
#                 endif /* !_WINDOWS */
	       }
#            ifndef _WINDOWS
	     else if (adbloc->E_ThotWidget[0] != 0)
		XtSetValues (adbloc->E_ThotWidget[0], args, n);
	     XmStringFree (title_string);
#            endif /* !_WINDOWS */
	  }

	/* Cree les differentes entrees du menu */
#       ifndef _WINDOWS
	n = 0;
	XtSetArg (args[n], XmNfontList, DefaultFont);
	n++;
	XtSetArg (args[n], XmNmarginWidth, 0);
	n++;
	XtSetArg (args[n], XmNmarginHeight, 0);
	n++;
	XtSetArg (args[n], XmNbackground, BgMenu_Color);
	n++;
	XtSetArg (args[n], XmNforeground, Black_Color);
	n++;
	XtSetArg (args[n], XmNborderColor, Button_Color);
	n++;
	if (equiv != NULL)
	   n++;
#       endif /* !_WINDOWS */
#   ifdef _WINDOWS
    nbOldItems = GetMenuItemCount (menu);
    for (ndx = 0; ndx < nbOldItems; ndx ++)
        RemoveMenu (menu, ref + ndx, MF_BYCOMMAND) ;
#   endif /* _WINDOWS */

	i = 0;
	index = 0;
	eindex = 0;
	ent = 2;

	if (text != NULL)
	   while (i < number)
	     {
		count = strlen (&text[index]);	/* Longueur de l'intitule */
		/* S'il n'y a plus d'intitule -> on arrete */
		if (count == 0)
		  {
		     i = number;
		     TtaError (ERR_invalid_parameter);
		     return;
		  }
		else
		  {

		     /* Faut-il changer de bloc d'entrees ? */
		     if (ent >= C_NUMBER)
		       {
			  adbloc->E_Next = NewEList ();
			  adbloc = adbloc->E_Next;
			  ent = 0;
		       }	/*if */

		     /* Recupere le type de l'entree */
		     adbloc->E_Type[ent] = text[index];
		     adbloc->E_Free[ent] = 'Y';

		     /* Note l'accelerateur */
		     if (equiv != NULL)
		       {
#                         ifdef _WINDOWS
                          if (&equiv[eindex] != EOS) {
                             if (parseAccelerator (&equiv[eindex]))
                                addAccelerator (1, fVirt, key, ref + i);
                          }
                          eindex += strlen (&equiv[eindex]) + 1;
#                         else  /* !_WINDOWS */
			  title_string = XmStringCreate (&equiv[eindex], XmSTRING_DEFAULT_CHARSET);
			  eindex += strlen (&equiv[eindex]) + 1;
			  XtSetArg (args[n - 1], XmNacceleratorText, title_string);
#                         endif /* !_WINDOWS */
		       }

		     if (text[index] == 'B')
		       /*__________________________________________ Creation d'un bouton __*/
		       {
#                         ifdef _WINDOWS
			  AppendMenu (menu, MF_STRING, ref + i, &text[index + 1]);
			  adbloc->E_ThotWidget[ent] = (ThotWidget) i;
#                         else  /* _WINDOWS */
			  w = XmCreatePushButton (menu, &text[index + 1], args, n);
			  XtManageChild (w);
			  adbloc->E_ThotWidget[ent] = w;
			  XtAddCallback (w, XmNactivateCallback, (XtCallbackProc) CallMenu, catalogue);
#                         endif /* !_WINDOWS */
		       }
		     else if (text[index] == 'T')
		       /*__________________________________________ Creation d'un toggle __*/
		       {
#                         ifdef _WINDOWS
			  AppendMenu (menu, MF_STRING | MF_CHECKED, ref + i, &text[index + 1]);
			  adbloc->E_ThotWidget[ent] = (ThotWidget) i;
#                         else  /* _WINDOWS */
			  XtSetArg (args[n], XmNvisibleWhenOff, TRUE);
			  XtSetArg (args[n + 1], XmNselectColor, White_Color);
			  w = XmCreateToggleButton (menu, &text[index + 1], args, n + 2);
			  XtManageChild (w);
			  adbloc->E_ThotWidget[ent] = w;
			  XtAddCallback (w, XmNvalueChangedCallback, (XtCallbackProc) CallMenu, catalogue);
#                         endif /* !_WINDOWS */
		       }
		     else if (text[index] == 'M')
		       /*_______________________________________ Creation d'un sous-menu __*/
		       {
			  /* En attendant le sous-menu on cree un bouton */
#                         ifdef _WINDOWS
			  AppendMenu (menu, MF_STRING, ref + i, &text[index + 1]);
			  adbloc->E_ThotWidget[ent] = (ThotWidget) i;
#                         else  /* _WINDOWS */
			  w = XmCreateCascadeButton (menu, &text[index + 1], args, n);
			  adbloc->E_ThotWidget[ent] = w;
#                         endif /* !_WINDOWS */
		       }
		     else if (text[index] == 'F')
		       /*_________________________________ Creation d'un sous-formulaire __*/
		       {
			  strcpy (heading, &text[index + 1]);
			  strcat (heading, "...");
#                         ifdef _WINDOWS
			  AppendMenu (menu, MF_STRING, (UINT) (ref + i), (LPCTSTR) (&heading));
			  adbloc->E_ThotWidget[ent] = (ThotWidget) i;
#                         else  /* _WINDOWS */
			  w = XmCreatePushButton (menu, heading, args, n);
			  XtManageChild (w);
			  adbloc->E_ThotWidget[ent] = w;
#                         endif /* !_WINDOWS */
		       }
		     else if (text[index] == 'S')
		       /*_________________________________ Creation d'un separateur __*/
		       {
#                         ifdef _WINDOWS
			  AppendMenu (menu, MF_SEPARATOR, 0, NULL);
			  adbloc->E_ThotWidget[ent] = (ThotWidget) i;
#                         else  /* _WINDOWS */
			  XtSetArg (args[n], XmNseparatorType, XmSINGLE_DASHED_LINE);
			  w = XmCreateSeparator (menu, "Dialogue", args, n + 1);
			  XtManageChild (w);
			  adbloc->E_ThotWidget[ent] = w;
#                         endif /* !_WINDOWS */
		       }
		     else
		       /*____________________________________ Une erreur de construction __*/
		       {
			  TtaDestroyDialogue (ref);
			  TtaError (ERR_invalid_parameter);	/* Type d'entree non defini */
			  return;
		       }

#                    ifndef _WINDOWS
		     /* liberation de la string */
		     if (equiv != NULL)
			XmStringFree (title_string);
#                    endif /* !_WINDOWS */

		     i++;
		     ent++;
		     index += count + 1;
		  }		/*else */
	     }

     }

}


/*----------------------------------------------------------------------
   AddInFormulary recherche une entree libre dans le formulaire  
   et cre'e e'ventuellement un nouveau bloc d'entre'es et un nouveau  
   Row-Column.                                                        
   Retourne :                                                         
   + index -> le nume'ro d'entre'e sur l'ensemble des blocs.          
   + entry -> l'index dans le bloc des entre'es concerne'.            
   + adbloc -> le bloc des entre'es concerne'.                        
  ----------------------------------------------------------------------*/
#ifdef __STDC__
static ThotWidget   AddInFormulary (struct Cat_Context *catalogue, int *index, int *entry, struct E_List **adbloc)
#else  /* __STDC__ */
static ThotWidget   AddInFormulary (catalogue, index, entry, adbloc)
struct Cat_Context *catalogue;
int                *index;
int                *entry;
struct E_List     **adbloc;

#endif /* __STDC__ */
{
   ThotWidget          row;
   ThotWidget          w;

#  ifndef _WINDOWS
   Arg                 args[MAX_ARGS];
   int                 n;
#  endif /* _WINDOWS */

   /* Il faut sauter la 1ere entree allouee a un Row-Column */
   *entry = 1;
   *index = 1;
   /* Le 1er bloc sert aux boutons du feuillet */
   *adbloc = catalogue->Cat_Entries->E_Next;

   /* Recupere le Row-Column racine du formulaire */
   w = (*adbloc)->E_ThotWidget[0];
#  ifdef _WINDOWS
   row = GetParent (w);
#  else  /* _WINDOWS */
   row = XtParent (w);
#  endif /* !_WINDOWS */

   /*** Recherche une entree libre dans le formulaire ***/
   while ((*adbloc)->E_ThotWidget[*entry] != 0)
     {
	/* Est-ce un widget de Row-Column (n fois le facteur de blocage) ? */
	if (*index % catalogue->Cat_FormPack == 0)
	   w = (*adbloc)->E_ThotWidget[*entry];

	(*entry)++;
	(*index)++;
	if (*entry >= C_NUMBER)
	  {
	     /* Il faut changer de bloc et enventuellement en creer un */
	     if ((*adbloc)->E_Next == NULL)
		(*adbloc)->E_Next = NewEList ();
	     *adbloc = (*adbloc)->E_Next;
	     *entry = 0;
	  }
     }

   /* Faut-il ajouter un nouveau Row-Column ? */
   if (*index % catalogue->Cat_FormPack == 0)
     {
#       ifdef _WINDOWS
#       else  /* _WINDOWS */
	n = 0;
	XtSetArg (args[n], XmNadjustLast, FALSE);
	n++;
	if (catalogue->Cat_in_lines)
	  {
	   XtSetArg (args[n], XmNorientation, XmHORIZONTAL);
	   n++;
	   XtSetArg (args[n], XmNrightAttachment, XmATTACH_FORM);
	   n++;
	  }
	else
	  {
	   XtSetArg (args[n], XmNorientation, XmVERTICAL);
	   n++;
	   XtSetArg (args[n], XmNbottomAttachment, XmATTACH_FORM);
	   n++;
	  }
	XtSetArg (args[n], XmNbackground, BgMenu_Color);
	n++;
	XtSetArg (args[n], XmNborderColor, Button_Color);
	n++;
	w = XmCreateRowColumn (row, "Dialogue", args, n);
	XtManageChild (w);
#       endif /* _WINDOWS */
	(*adbloc)->E_ThotWidget[*entry] = w;
	(*adbloc)->E_Free[*entry] = 'X';

	(*index)++;
	(*entry)++;
	if (*entry >= C_NUMBER)
	  {
	     /* Il faut changer de bloc et enventuellement en creer un */
	     if ((*adbloc)->E_Next == NULL)
		(*adbloc)->E_Next = NewEList ();
	     *adbloc = (*adbloc)->E_Next;
	     *entry = 0;
	  }
     }				/*if */

   /* il faut mettre a jour l'index */
   *index += C_NUMBER;
   return (w);
}


/*----------------------------------------------------------------------
   TtaNewIconMenu cre'e un sous-menu :                                        
   Le parame`tre ref donne la re'fe'rence pour l'application.         
   Le parame`tre ref_parent identifie le formulaire pe`re.            
   Le parametre entry de'signe l'entre'e correspondante dans le menu  
   pe`re. Le parame`tre title donne le titre du catalogue.            
   Le parame`tre number indique le nombre d'entre'es dans le menu.    
   Le parame`tre icons contient la liste des icones du catalogue.     
   Tout changement de se'lection dans le sous-menu est imme'diatement 
   signale' a` l'application.                                         
  ----------------------------------------------------------------------*/
#ifdef __STDC__
void                TtaNewIconMenu (int ref, int ref_parent, int entry, char *title, int number, Pixmap * icons, boolean horizontal)
#else  /* __STDC__ */
void                TtaNewIconMenu (ref, ref_parent, entry, title, number, icons, horizontal)
int                 ref;
int                 ref_parent;
int                 entry;
char               *title;
int                 number;
Pixmap             *icons;
boolean             horizontal;

#endif /* __STDC__ */
{
#  ifndef _WINDOWS
   int                 i;
   int                 ent;
   int                 n;
   struct Cat_Context *catalogue;
   struct Cat_Context *parentCatalogue;
   struct E_List      *adbloc;
   Arg                 args[MAX_ARGS];
   ThotWidget          menu;
   ThotWidget          w;
   ThotWidget          row;
   XmString            title_string;

   if (ref == 0)
     {
	TtaError (ERR_invalid_reference);
	return;
     }

   catalogue = CatEntry (ref);
   menu = 0;
   if (catalogue == NULL)
      TtaError (ERR_cannot_create_dialogue);
   else if (catalogue->Cat_Widget != 0)
      TtaError (ERR_invalid_reference);
   else
     {
	catalogue->Cat_React = TRUE;
	title_string = 0;
	parentCatalogue = CatEntry (ref_parent);
	/*__________________________________ Le catalogue parent n'existe pas __*/
	if (parentCatalogue == NULL)
	  {
	     TtaError (ERR_invalid_parent_dialogue);
	     return;
	  }
	else if (parentCatalogue->Cat_Widget == 0)
	  {
	     TtaError (ERR_invalid_parent_dialogue);
	     return;
	  }
	/*_________________________________________ Sous-menu d'un formulaire __*/
	else if (parentCatalogue->Cat_Type == CAT_FORM
		 || parentCatalogue->Cat_Type == CAT_SHEET
		 || parentCatalogue->Cat_Type == CAT_DIALOG)
	  {
	     w = AddInFormulary (parentCatalogue, &i, &ent, &adbloc);

	     /*** Cree un sous-menu d'un formulaire ***/
	     n = 0;
	     XtSetArg (args[n], XmNbackground, BgMenu_Color);
	     n++;
	     XtSetArg (args[n], XmNborderColor, Button_Color);
	     n++;
	     XtSetArg (args[n], XmNmarginWidth, 0);
	     n++;
	     XtSetArg (args[n], XmNmarginHeight, 0);
	     n++;
	     XtSetArg (args[n], XmNspacing, 0);
	     n++;
	     menu = XmCreateRowColumn (w, "Dialogue", args, n);

	     catalogue->Cat_Ref = ref;
	     catalogue->Cat_Type = CAT_FMENU;
	     catalogue->Cat_Data = -1;
	     catalogue->Cat_Widget = menu;
	     catalogue->Cat_PtParent = parentCatalogue;
	     adbloc->E_ThotWidget[ent] = (ThotWidget) (catalogue);
	     adbloc->E_Free[ent] = 'N';
	     catalogue->Cat_EntryParent = i;
	     adbloc = NewEList ();
	     catalogue->Cat_Entries = adbloc;
	  }

	/*** Cree le titre du sous-menu ***/
	if (title != NULL)
	  {
	     n = 0;
	     title_string = XmStringCreateSimple (title);
	     XtSetArg (args[n], XmNlabelString, title_string);
	     n++;
	     XtSetArg (args[n], XmNfontList, DefaultFont);
	     n++;
	     XtSetArg (args[n], XmNmarginHeight, 0);
	     n++;
	     XtSetArg (args[n], XmNbackground, BgMenu_Color);
	     n++;
	     XtSetArg (args[n], XmNforeground, Black_Color);
	     n++;
	     XtSetArg (args[n], XmNborderColor, Button_Color);
	     n++;
	     w = XmCreateLabel (menu, "Dialogue", args, n);
	     XtManageChild (w);
	     adbloc->E_ThotWidget[0] = w;
	     n = 0;
	     XtSetArg (args[n], XmNbackground, Button_Color);
	     n++;
	     XtSetArg (args[n], XmNseparatorType, XmSHADOW_ETCHED_OUT);
	     n++;
	     w = XmCreateSeparator (menu, "Dialogue", args, n);
	     XtManageChild (w);
	     adbloc->E_ThotWidget[1] = w;
	     XmStringFree (title_string);
	  }

	/* Cree un Row-Column d'icone dans le Row-Column du formulaire */
	n = 0;
	XtSetArg (args[n], XmNmarginWidth, 0);
	n++;
	XtSetArg (args[n], XmNmarginHeight, 0);
	n++;
	XtSetArg (args[n], XmNspacing, 0);
	n++;
	XtSetArg (args[n], XmNrowColumnType, XmMENU_BAR);
	n++;
	XtSetArg (args[n], XmNbackground, BgMenu_Color);
	n++;
	XtSetArg (args[n], XmNborderColor, Button_Color);
	n++;
	if (horizontal)
	   XtSetArg (args[n], XmNorientation, XmHORIZONTAL);
	else
	   XtSetArg (args[n], XmNorientation, XmVERTICAL);
	n++;
	row = XmCreateRowColumn (menu, "Dialogue", args, n);
	XtManageChild (row);

	/*** Cree les differentes entrees du sous-menu ***/
	n = 0;
	XtSetArg (args[n], XmNfontList, DefaultFont);
	n++;
	XtSetArg (args[n], XmNmarginWidth, 0);
	n++;
	XtSetArg (args[n], XmNmarginHeight, 0);
	n++;
	XtSetArg (args[n], XmNbackground, BgMenu_Color);
	n++;
	XtSetArg (args[n], XmNborderColor, Button_Color);
	n++;
	XtSetArg (args[n], XmNlabelType, XmPIXMAP);
	n++;
	i = 0;
	ent = 2;
	while (i < number)
	  {
	     /* Faut-il changer de bloc d'entrees ? */
	     if (ent >= C_NUMBER)
	       {
		  adbloc->E_Next = NewEList ();
		  adbloc = adbloc->E_Next;
		  ent = 0;
	       }

	     /* On ne traite que des entrees de type bouton */
	     adbloc->E_Type[ent] = 'B';
	     adbloc->E_Free[ent] = 'Y';
	     XtSetArg (args[n], XmNlabelPixmap, icons[i]);
	     w = XmCreateCascadeButton (row, "dialogue", args, n + 1);
	     XtManageChild (w);
	     adbloc->E_ThotWidget[ent] = w;
	     XtAddCallback (w, XmNactivateCallback, (XtCallbackProc) CallRadio, catalogue);
	     i++;
	     ent++;
	  }
     }
#  endif /* _WINDOWS */
}

/*----------------------------------------------------------------------
   TtaNewSubmenu cre'e un sous-menu :                                 
   Le parame`tre ref donne la re'fe'rence pour l'application.         
   Le parame`tre ref_parent identifie le formulaire pe`re.            
   Le parametre entry de'signe l'entre'e correspondante dans le menu  
   pe`re. Le parame`tre title donne le titre du catalogue.            
   Le parame`tre number indique le nombre d'entre'es dans le menu.    
   Le parame`tre text contient la liste des intitule's du catalogue.  
   Chaque intitule' commence par un caracte`re qui donne le type de   
   l'entre'e et se termine par un caracte`re de fin de chai^ne \0.    
   S'il n'est pas nul, le parame`tre equiv donne les acce'le'rateurs  
   des entre'es du menu.                                              
   Quand le parame`tre react est vrai, tout changement de se'lection  
   dans le sous-menu est imme'diatement signale' a` l'application.    
  ----------------------------------------------------------------------*/
#ifdef __STDC__
void                TtaNewSubmenu (int ref, int ref_parent, int entry, char *title, int number, char *text, char *equiv, boolean react)
#else  /* __STDC__ */
void                TtaNewSubmenu (ref, ref_parent, entry, title, number, text, equiv, react)
int                 ref;
int                 ref_parent;
int                 entry;
char               *title;
int                 number;
char               *text;
char               *equiv;
boolean             react;

#endif /* __STDC__ */
{
   register int        count;
   register int        index;
   int                 eindex;
   int                 i;
   int                 ent;
   int                 n;
   boolean             rebuilded;
   struct Cat_Context *catalogue;
   struct Cat_Context *parentCatalogue;
   struct E_List      *adbloc;

#  ifndef _WINDOWS
   Arg                 args[MAX_ARGS];
   XmString            title_string;
   ThotWidget          menu;
   char                heading[200];
#  endif /* !_WINDOWS */

   ThotWidget          w;
   ThotWidget          row;
   char                button;

#  ifdef _WINDOWS
   HMENU               menu;
   char               *title_string;
   char                equiv_item [255];
   char                menu_item [1024];
   struct Cat_Context *copyCat;

   equiv_item[0] = 0;
#  endif

   if (ref == 0)
     {
	TtaError (ERR_invalid_reference);
	return;
     }

   catalogue = CatEntry (ref);
   if (catalogue == NULL)
      TtaError (ERR_cannot_create_dialogue);
   else
     {
	catalogue->Cat_React = react;
	title_string = 0;

	/* Faut-il detruire le catalogue precedent ? */
	rebuilded = FALSE;
	if (catalogue->Cat_Widget != 0)
	   if (catalogue->Cat_Type == CAT_MENU
	       || catalogue->Cat_Type == CAT_FMENU)
	     {
		DestContenuMenu (catalogue);	/* Modification du catalogue */
		rebuilded = TRUE;
	     }
	   else
	      /* Modification du catalogue */
	      TtaDestroyDialogue (ref);

	/*======================================> Recherche le catalogue parent */
	parentCatalogue = CatEntry (ref_parent);
	/*__________________________________ Le catalogue parent n'existe pas __*/
	if (parentCatalogue == NULL)
	  {
	     TtaError (ERR_invalid_parent_dialogue);
	     return;
	  }
	else if (parentCatalogue->Cat_Widget == 0)
	  {
	     TtaError (ERR_invalid_parent_dialogue);
	     return;
	  }
	/*_________________________________________ Sous-menu d'un formulaire __*/
	else if (parentCatalogue->Cat_Type == CAT_FORM
		 || parentCatalogue->Cat_Type == CAT_SHEET
		 || parentCatalogue->Cat_Type == CAT_DIALOG)
	  {
	     if (!rebuilded)
	       {
		  w = AddInFormulary (parentCatalogue, &i, &ent, &adbloc);

#                 ifdef _WINDOWS
                  menu = w ;
#                 else  /* _WINDOWS */
		  /*** Cree un sous-menu d'un formulaire ***/
		  n = 0;
		  XtSetArg (args[n], XmNbackground, BgMenu_Color);
		  n++;
		  XtSetArg (args[n], XmNborderColor, Button_Color);
		  n++;
		  XtSetArg (args[n], XmNmarginWidth, 0);
		  n++;
		  XtSetArg (args[n], XmNmarginHeight, 0);
		  n++;
		  XtSetArg (args[n], XmNspacing, 0);
		  n++;
		  menu = XmCreateRowColumn (w, "Dialogue", args, n);
#                 endif /* !_WINDOWS */

		  catalogue->Cat_Ref = ref;
		  catalogue->Cat_Type = CAT_FMENU;
		  catalogue->Cat_Data = -1;
		  catalogue->Cat_Widget = menu;
		  catalogue->Cat_PtParent = parentCatalogue;
		  adbloc->E_ThotWidget[ent] = (ThotWidget) (catalogue);
		  adbloc->E_Free[ent] = 'N';
		  catalogue->Cat_EntryParent = i;
		  adbloc = NewEList ();
		  catalogue->Cat_Entries = adbloc;
	       }
	     else
	       {
		  /* Sinon on recupere le widget du menu */
		  menu = catalogue->Cat_Widget;
		  adbloc = catalogue->Cat_Entries;
	       }

	     /*** Cree le titre du sous-menu ***/
	     if (title != NULL)
	       {
#                 ifdef _WINDOWS
#                 else  /* _WINDOWS */
		  n = 0;
		  title_string = XmStringCreateSimple (title);
		  XtSetArg (args[n], XmNlabelString, title_string);
		  n++;
#                 endif /* !_WINDOWS */
		  if (!rebuilded)
		    {
#                      ifdef _WINDOWS
#                      else  /* _WINDOWS */
		       XtSetArg (args[n], XmNfontList, DefaultFont);
		       n++;
		       XtSetArg (args[n], XmNmarginHeight, 0);
		       n++;
		       XtSetArg (args[n], XmNbackground, BgMenu_Color);
		       n++;
		       XtSetArg (args[n], XmNforeground, Black_Color);
		       n++;
		       XtSetArg (args[n], XmNborderColor, Button_Color);
		       n++;
		       w = XmCreateLabel (menu, "Dialogue", args, n);
		       XtManageChild (w);
#                      endif /* !_WINDOWS */
		       adbloc->E_ThotWidget[0] = w;
#                      ifdef _WINDOWS
#                      else  /* _WINDOWS */
		       n = 0;
		       XtSetArg (args[n], XmNbackground, Button_Color);
		       n++;
		       XtSetArg (args[n], XmNseparatorType, XmSHADOW_ETCHED_OUT);
		       n++;
		       w = XmCreateSeparator (menu, "Dialogue", args, n);
		       XtManageChild (w);
#                      endif /* !_WINDOWS */
		       adbloc->E_ThotWidget[1] = w;
		    }
#                 ifdef _WINDOWS
#                 else  /* _WINDOWS */
		  else if (adbloc->E_ThotWidget[0] != 0)
		     XtSetValues (adbloc->E_ThotWidget[0], args, n);

		  XmStringFree (title_string);
#                 endif /* !_WINDOWS */
	       }

	     if (!rebuilded)
	       {
#                 ifdef _WINDOWS
#                 else  /* _WINDOWS */
		  /* Cree un Row-Column de Radio dans le Row-Column du formulaire */
		  n = 0;
		  XtSetArg (args[n], XmNradioAlwaysOne, TRUE);
		  n++;
		  XtSetArg (args[n], XmNradioBehavior, TRUE);
		  n++;
		  XtSetArg (args[n], XmNmarginWidth, 0);
		  n++;
		  XtSetArg (args[n], XmNmarginHeight, 0);
		  n++;
		  XtSetArg (args[n], XmNspacing, 0);
		  n++;
		  XtSetArg (args[n], XmNbackground, BgMenu_Color);
		  n++;
		  XtSetArg (args[n], XmNborderColor, Button_Color);
		  n++;
		  row = XmCreateRowColumn (menu, "Dialogue", args, n);
		  XtManageChild (row);
#                 endif /* !_WINDOWS */
	       }
	     else
		/* Sinon on recupere le widget parent des entrees */
		row = catalogue->Cat_XtWParent;

#            ifndef _WINDOWS
	     /*** Cree les differentes entrees du sous-menu ***/
	     n = 0;
	     XtSetArg (args[n], XmNindicatorType, XmONE_OF_MANY);
	     n++;
	     XtSetArg (args[n], XmNfontList, DefaultFont);
	     n++;
	     XtSetArg (args[n], XmNmarginWidth, 0);
	     n++;
	     XtSetArg (args[n], XmNmarginHeight, 0);
	     n++;
	     XtSetArg (args[n], XmNbackground, BgMenu_Color);
	     n++;
	     XtSetArg (args[n], XmNforeground, Black_Color);
	     n++;
	     XtSetArg (args[n], XmNborderColor, Button_Color);
	     n++;
#            endif /* !_WINDOWS */
	     if (equiv != NULL)
		n++;
	     i = 0;
	     index = 0;
	     eindex = 0;
	     ent = 2;
	     while (i < number)
	       {
		  count = strlen (&text[index]);	/* Longueur de l'intitule */
		  /* S'il n'y a plus d'intitule -> on arrete */
		  if (count == 0)
		     i = number;
		  else
		    {
		       /* Faut-il changer de bloc d'entrees ? */
		       if (ent >= C_NUMBER)
			 {
			    adbloc->E_Next = NewEList ();
			    adbloc = adbloc->E_Next;
			    ent = 0;
			 }	/*if */

		       /* On ne traite que des entrees de type bouton */
		       adbloc->E_Type[ent] = 'B';
		       adbloc->E_Free[ent] = 'Y';

		       /* Note l'accelerateur */
		       if (equiv != NULL)
			 {
#                           ifdef _WINDOWS
                            if (&equiv[eindex] != EOS) {
                               if (parseAccelerator (&equiv[eindex]))
                                  addAccelerator (1, fVirt, key, ref);
                            }
                            eindex += strlen (&equiv[eindex]) + 1;
#                           else  /* _WINDOWS */
			    title_string = XmStringCreate (&equiv[eindex], XmSTRING_DEFAULT_CHARSET);
			    XtSetArg (args[n + 1], XmNacceleratorText, title_string);
			    eindex += strlen (&equiv[eindex]) + 1;
#                           endif /* !_WINDOWS */
			 }
#                      ifdef _WINDOWS
                       copyCat = catalogue;
                       WIN_AddFrameCatalogue (w, copyCat) ;
#                      else  /* _WINDOWS */
		       w = XmCreateToggleButton (row, &text[index + 1], args, n);
		       XtManageChild (w);
		       XtAddCallback (w, XmNarmCallback, (XtCallbackProc) CallRadio, catalogue);
#                      endif /* !_WINDOWS */
		       adbloc->E_ThotWidget[ent] = w;

		       /* liberation de la string */
#                      ifndef _WINDOWS
		       if (equiv != NULL)
			  XmStringFree (title_string);
#                      endif /* !_WINDOWS */
		       i++;
		       index += count + 1;
		       ent++;
		    }		/*else */
	       }		/*while */

	  }
	/*_______________________________________________ Sous-menu d'un menu __*/
	else
	  {
	     if (parentCatalogue->Cat_Type == CAT_POPUP
		 || parentCatalogue->Cat_Type == CAT_PULL
		 || parentCatalogue->Cat_Type == CAT_MENU)
	       {

		  /* Faut-il reconstruire entierement le menu */
		  if (!rebuilded)
		    {
		      /*=========> Recherche l'entree du menu parent corespondante */
		       adbloc = parentCatalogue->Cat_Entries;
		       ent = entry + 2;		/* decalage de 2 pour le widget titre */
		       while (ent >= C_NUMBER)
			 {
			    if (adbloc->E_Next == NULL)
			      {
				 TtaError (ERR_invalid_parent_dialogue);
				 return;
			      }
			    else
			       adbloc = adbloc->E_Next;
			    ent -= C_NUMBER;
			 }	/*while */

		       if ((adbloc->E_Type[ent] == 'M') && (adbloc->E_Free[ent] == 'Y'))
			 {
			    /* Cree un sous-menu d'un menu */
			    w = parentCatalogue->Cat_Widget;
#                           ifdef _WINDOWS
#                           else  /* _WINDOWS */
			    n = 0;
			    XtSetArg (args[n], XmNbackground, BgMenu_Color);
			    n++;
			    XtSetArg (args[n], XmNborderColor, Button_Color);
			    n++;
			    button = parentCatalogue->Cat_Button;
			    if (button == 'R')
			       XtSetArg (args[n], XmNwhichButton, Button3);
			    else if (button == 'M')
			       XtSetArg (args[n], XmNwhichButton, Button2);
			    else
			       XtSetArg (args[n], XmNwhichButton, Button1);
			    n++;
			    XtSetArg (args[n], XmNmarginWidth, 0);
			    n++;
			    XtSetArg (args[n], XmNmarginHeight, 0);
			    n++;
			    XtSetArg (args[n], XmNspacing, 0);
			    n++;
			    menu = XmCreatePulldownMenu (w, "Dialogue", args, n);
			    /*XtManageChild(menu); */
#                           endif /* !_WINDOWS */

			    catalogue->Cat_Ref = ref;
			    catalogue->Cat_Type = CAT_MENU;
			    catalogue->Cat_Button = button;
			    catalogue->Cat_Data = -1;
			    catalogue->Cat_Widget = menu;
			    catalogue->Cat_PtParent = parentCatalogue;
			    /* Memorise l'entree decalee de 2 pour le widget titre */
			    catalogue->Cat_EntryParent = entry + 2;

			    /*** Relie le sous-menu au bouton du menu ***/
			    w = adbloc->E_ThotWidget[ent];
			    n = 0;
#                           ifdef _WINDOWS
#                           else  /* _WINDOWS */
			    XtSetArg (args[n], XmNsubMenuId, menu);
			    n++;
			    XtSetValues (w, args, n);
			    XtManageChild (w);
			    XtManageChild (menu);
#                           endif /* !_WINDOWS */
			    adbloc->E_Free[ent] = 'N';

			    adbloc = NewEList ();
			    catalogue->Cat_Entries = adbloc;
			 }
		       else
			 {
			    TtaError (ERR_invalid_parameter);
			    return;
			 }
		    }
		  else
		    {
		       /* On recupere le widget du menu */
		       menu = catalogue->Cat_Widget;
		       adbloc = catalogue->Cat_Entries;
		    }
	       }
	     /*____________________________________________ Sous-menu non valide __*/
	     else
	       {
		  TtaError (ERR_invalid_parameter);
		  return;
	       }

/*** Cree le titre du sous-menu ***/
	     if (title != NULL)
	       {
		  n = 0;
#                 ifndef _WINDOWS
		  title_string = XmStringCreateSimple (title);
		  XtSetArg (args[n], XmNlabelString, title_string);
		  n++;
#                 endif /* !_WINDOWS */
		  if (!rebuilded)
		    {
#                      ifdef _WINDOWS
#                      else  /* _WINDOWS */
		       XtSetArg (args[n], XmNfontList, DefaultFont);
		       n++;
		       XtSetArg (args[n], XmNmarginHeight, 0);
		       n++;
		       XtSetArg (args[n], XmNbackground, BgMenu_Color);
		       n++;
		       XtSetArg (args[n], XmNforeground, Black_Color);
		       n++;
		       XtSetArg (args[n], XmNborderColor, Button_Color);
		       n++;
		       w = XmCreateLabel (menu, "Dialogue", args, n);
		       XtManageChild (w);
#                      endif /* !_WINDOWS */
		       adbloc->E_ThotWidget[0] = w;
		       n = 0;
#                      ifdef _WINDOWS
#                      else  /* _WINDOWS */
		       XtSetArg (args[n], XmNbackground, Button_Color);
		       n++;
		       XtSetArg (args[n], XmNseparatorType, XmSHADOW_ETCHED_OUT);
		       n++;
		       w = XmCreateSeparator (menu, "Dialogue", args, n);
		       XtManageChild (w);
#                      endif /* !_WINDOWS */
		       adbloc->E_ThotWidget[1] = w;
		    }
#                 ifdef _WINDOWS
#                 else  /* _WINDOWS */
		  else if (adbloc->E_ThotWidget[0] != 0)
		     XtSetValues (adbloc->E_ThotWidget[0], args, n);
		  XmStringFree (title_string);
#                 endif /* !_WINDOWS */
	       }

	     /* Cree les differentes entrees du sous-menu */
#            ifndef _WINDOWS
	     n = 0;
	     XtSetArg (args[n], XmNfontList, DefaultFont);
	     n++;
	     XtSetArg (args[n], XmNmarginWidth, 0);
	     n++;
	     XtSetArg (args[n], XmNmarginHeight, 0);
	     n++;
	     XtSetArg (args[n], XmNbackground, BgMenu_Color);
	     n++;
	     XtSetArg (args[n], XmNforeground, Black_Color);
	     n++;
	     XtSetArg (args[n], XmNborderColor, Button_Color);
	     n++;
#            endif /* !_WINDOWS */
	     if (equiv != NULL)
		n++;
	     i = 0;
	     index = 0;
	     eindex = 0;
	     ent = 2;
	     while (i < number)
	       {
		  count = strlen (&text[index]);	/* Longueur de l'intitule */
		  /* S'il n'y a plus d'intitule -> on arrete */
		  if (count == 0)
		    {
		       i = number;
		       TtaError (ERR_invalid_parameter);
		       return;
		    }
		  else
		    {

		       /* Faut-il changer de bloc d'entrees ? */
		       if (ent >= C_NUMBER)
			 {
			    adbloc->E_Next = NewEList ();
			    adbloc = adbloc->E_Next;
			    ent = 0;
			 }	/*if */

		       /* Recupere le type de l'entree */
		       adbloc->E_Type[ent] = text[index];
		       adbloc->E_Free[ent] = 'Y';

		       /* Note l'accelerateur */
		       if (equiv != NULL)
			 {
#                           ifdef _WINDOWS
                            if (&equiv[eindex] != EOS) {
                               if (parseAccelerator (&equiv[eindex]))
                                  addAccelerator (currentFrame, fVirt, key, ref + i);
                               sprintf (equiv_item, "%s", &equiv[eindex]);
                            }
                            eindex += strlen (&equiv[eindex]) + 1;
#                           else  /* !_WINDOWS */
			    title_string = XmStringCreate (&equiv[eindex], XmSTRING_DEFAULT_CHARSET);
			    eindex += strlen (&equiv[eindex]) + 1;
			    XtSetArg (args[n - 1], XmNacceleratorText, title_string);
#                           endif /* !_WINDOWS */
			 }

		       if (text[index] == 'B')
			 /*________________________________________ Creation d'un bouton __*/
			 {
#                           ifdef _WINDOWS
                            if (equiv_item && equiv_item[0] != 0) {
                               sprintf (menu_item, "%s\t%s", &text[index + 1], equiv_item);
                               AppendMenu (w, MF_STRING, ref + i, menu_item);
                               equiv_item [0] = 0;
                            } else 
                                 AppendMenu (w, MF_STRING, ref + i, &text[index + 1]);
			    adbloc->E_ThotWidget[ent] = (ThotWidget) i;
                            copyCat = catalogue;
                            WIN_AddFrameCatalogue (currentMenu, copyCat) ;
#                           else  /* _WINDOWS */
			    w = XmCreatePushButton (menu, &text[index + 1], args, n);
			    XtManageChild (w);
			    adbloc->E_ThotWidget[ent] = w;
			    XtAddCallback (w, XmNactivateCallback, (XtCallbackProc) CallMenu, catalogue);
#                           endif /* !_WINDOWS */
			 }
		       else if (text[index] == 'T')
			 /*________________________________________ Creation d'un toggle __*/
			 {
#                           ifdef _WINDOWS
                            if (equiv_item && equiv_item[0] != 0) {
                               sprintf (menu_item, "%s\t%s", &text[index + 1], equiv_item);
                               AppendMenu (w, MF_STRING | MF_UNCHECKED, ref + i, menu_item);
                               equiv_item [0] = 0;
                            } else 
                                 AppendMenu (w, MF_STRING | MF_UNCHECKED, ref + i, &text[index + 1]);
                            adbloc->E_ThotWidget[ent] = (ThotWidget) i;
                            copyCat = catalogue;
                            WIN_AddFrameCatalogue (currentMenu, copyCat) ;
#                           else  /* _WINDOWS */
			    /* un toggle a faux */
			    XtSetArg (args[n], XmNvisibleWhenOff, TRUE);
			    XtSetArg (args[n + 1], XmNselectColor, White_Color);
			    w = XmCreateToggleButton (menu, &text[index + 1], args, n + 2);
			    XtManageChild (w);
			    adbloc->E_ThotWidget[ent] = w;
			    XtAddCallback (w, XmNvalueChangedCallback, (XtCallbackProc) CallMenu, catalogue);
#                           endif /* !_WINDOWS */
			 }
		       else if (text[index] == 'M')
			 /*________________________________________ Appel d'un sous-menu __*/
			 {
#                           ifdef _WINDOWS
#                           else  /* _WINDOWS */
			    w = XmCreateCascadeButton (menu, &text[index + 1], args, n);
			    adbloc->E_ThotWidget[ent] = w;
#                           endif /* !_WINDOWS */
			 }
		       else if (text[index] == 'F')
			 /*__________________________________ Appel d'un sous-formulaire __*/
			 {
#                           ifdef _WINDOWS
#                           else  /* _WINDOWS */
			    strcpy (heading, &text[index + 1]);
			    strcat (heading, "...");
			    w = XmCreatePushButton (menu, heading, args, n);
			    XtManageChild (w);
			    adbloc->E_ThotWidget[ent] = w;
#                           endif /* !_WINDOWS */
			 }
		       else if (text[index] == 'S')
			 /*_________________________________ Creation d'un separateur __*/
			 {
#                           ifdef _WINDOWS
#                           else  /* _WINDOWS */
			    XtSetArg (args[n], XmNseparatorType, XmSINGLE_DASHED_LINE);
			    w = XmCreateSeparator (menu, "Dialogue", args, n + 1);
			    XtManageChild (w);
			    adbloc->E_ThotWidget[ent] = w;
#                           endif /* !_WINDOWS */
			 }
		       else
			 /*__________________________________ Une erreur de construction __*/
			 {
			    TtaDestroyDialogue (ref);
			    TtaError (ERR_invalid_parameter);	/* Type d'entree non defini */
			    return;
			 }

		       /* liberation de la string */
#                      ifndef _WINDOWS
		       if (equiv != NULL)
			  XmStringFree (title_string);
#                      endif /* !_WINDOWS */
		       i++;
		       index += count + 1;
		       ent++;
		    }
	       }		/*while */

	  }
     }
}


/*----------------------------------------------------------------------
   TtaSetMenuForm fixe la selection dans un sous-menu de formulaire : 
   Le parame`tre ref donne la re'fe'rence du catalogue.               
   Le parame`tre val de'signe l'entre'e se'lectionne'e.               
  ----------------------------------------------------------------------*/
#ifdef __STDC__
void                TtaSetMenuForm (int ref, int val)
#else  /* __STDC__ */
void                TtaSetMenuForm (ref, val)
int                 ref;
int                 val;

#endif /* __STDC__ */
{
#  ifndef _WINDOWS
   register int        i, n;
   register int        ent;
   boolean             visible;
   struct E_List      *adbloc;
   Arg                 args[MAX_ARGS];
#  endif /* !_WINDOWS */
   struct Cat_Context *catalogue;

   catalogue = CatEntry (ref);
   if (catalogue == NULL)
      TtaError (ERR_invalid_reference);
   else if (catalogue->Cat_Widget == 0)
      TtaError (ERR_invalid_reference);
   else
     {
	/* Si ce n'est pas un sous-menu de formulaire */
	if (catalogue->Cat_Type != CAT_FMENU)
	  {
	     TtaError (ERR_invalid_reference);
	     return;
	  }

	/* Est-ce que le sous-menu est actuellement affiche */
#       ifndef _WINDOWS
	if (XtIsManaged (catalogue->Cat_Widget))
	   visible = TRUE;
	else
	  {
	     visible = FALSE;
	     XtManageChild (catalogue->Cat_Widget);
	  }

	/* Positionnement de la valeur de chaque entree */
	adbloc = catalogue->Cat_Entries;
	ent = 0;
	i = 2;			/* decalage de 2 pour le widget titre */
	while (adbloc != NULL)
	  {
	     while (i < C_NUMBER)
	       {
		  if (adbloc->E_ThotWidget[i] == 0)
		     i = C_NUMBER;
		  else if (ent == val)
		    {
		       n = 0;
		       XtSetArg (args[n], XmNset, TRUE);
		       n++;
		       XtSetValues (adbloc->E_ThotWidget[i], args, n);
		    }
		  else
		    {
		       n = 0;
		       XtSetArg (args[n], XmNset, FALSE);
		       n++;
		       XtSetValues (adbloc->E_ThotWidget[i], args, n);
		    }
		  i++;
		  ent++;
	       }
	     /* Passe au bloc suivant */
	     adbloc = adbloc->E_Next;
	     i = 0;
	  }			/*while */

	if (!visible)
	   XtUnmanageChild (catalogue->Cat_Widget);
#       endif /* _WINDOWS */
	/* La selection de l'utilisateur est desactivee */
	catalogue->Cat_Data = val;
     }
}


/*----------------------------------------------------------------------
   TtaNewToggleMenu cre'e un sous-menu a` choix multiples :           
   Le parame`tre ref donne la re'fe'rence pour l'application.         
   Le parame`tre ref_parent identifie le formulaire pe`re.            
   Le parame`tre title donne le titre du catalogue.                   
   Le parame`tre number indique le nombre d'entre'es dans le menu.    
   Le parame`tre text contient la liste des intitule's du catalogue.  
   Chaque intitule' commence par un caracte`re qui donne le type de   
   l'entre'e et se termine par un caracte`re de fin de chai^ne \0.    
   S'il n'est pas nul, le parame`tre equiv donne les acce'le'rateurs  
   des entre'es du menu.                                              
   Quand le parame`tre react est vrai, tout changement de se'lection  
   dans le sous-menu est imme'diatement signale' a` l'application.    
  ----------------------------------------------------------------------*/
#ifdef __STDC__
void                TtaNewToggleMenu (int ref, int ref_parent, char *title, int number, char *text, char *equiv, boolean react)
#else  /* __STDC__ */
void                TtaNewToggleMenu (ref, ref_parent, title, number, text, equiv, react)
int                 ref;
int                 ref_parent;
char               *title;
int                 number;
char               *text;
char               *equiv;
boolean             react;

#endif /* __STDC__ */
{
#  ifndef _WINDOWS
   register int        count;
   register int        index;
   int                 eindex;
   int                 i;
   int                 ent;
   int                 n;
   boolean             rebuilded;
   struct Cat_Context *catalogue;
   struct Cat_Context *parentCatalogue;
   struct E_List      *adbloc;
   Arg                 args[MAX_ARGS];
   ThotWidget          menu;
   ThotWidget          w;
   ThotWidget          row;
   XmString            title_string;

   if (ref == 0)
     {
	TtaError (ERR_invalid_reference);
	return;
     }

   catalogue = CatEntry (ref);
   if (catalogue == NULL)
      TtaError (ERR_cannot_create_dialogue);
   else
     {
	catalogue->Cat_React = react;
	title_string = 0;

	/* Faut-il detruire le catalogue precedent ? */
	rebuilded = FALSE;
	if (catalogue->Cat_Widget != 0)
	   if (catalogue->Cat_Type == CAT_TMENU)
	     {
		DestContenuMenu (catalogue);	/* Modification du catalogue */
		rebuilded = TRUE;
	     }
	   else
	      /* Modification du catalogue */
	      TtaDestroyDialogue (ref);

	/*======================================> Recherche le catalogue parent */
	if (!rebuilded)
	   parentCatalogue = CatEntry (ref_parent);
	else
	   parentCatalogue = catalogue->Cat_PtParent;

	/*__________________________________ Le catalogue parent n'existe pas __*/
	if (parentCatalogue == NULL)
	   TtaError (ERR_invalid_parent_dialogue);
	else if (parentCatalogue->Cat_Widget == 0)
	   TtaError (ERR_invalid_parent_dialogue);
	/*_________________________________________ Sous-menu d'un formulaire __*/
	else if (parentCatalogue->Cat_Type == CAT_FORM
		 || parentCatalogue->Cat_Type == CAT_SHEET
		 || parentCatalogue->Cat_Type == CAT_DIALOG)
	  {
	     if (!rebuilded)
	       {
		  w = AddInFormulary (parentCatalogue, &i, &ent, &adbloc);

		  /* Cree un sous-menu d'un formulaire */
		  n = 0;
		  XtSetArg (args[n], XmNbackground, BgMenu_Color);
		  n++;
		  XtSetArg (args[n], XmNborderColor, Button_Color);
		  n++;
		  XtSetArg (args[n], XmNmarginWidth, 0);
		  n++;
		  XtSetArg (args[n], XmNmarginHeight, 0);
		  n++;
		  XtSetArg (args[n], XmNspacing, 0);
		  n++;
		  menu = XmCreateRowColumn (w, "Dialogue", args, n);

		  catalogue->Cat_Ref = ref;
		  catalogue->Cat_Type = CAT_TMENU;
		  catalogue->Cat_Widget = menu;
		  catalogue->Cat_PtParent = parentCatalogue;
		  adbloc->E_ThotWidget[ent] = (ThotWidget) catalogue;
		  adbloc->E_Free[ent] = 'N';
		  catalogue->Cat_EntryParent = i;
		  /* prepare le nouveau catalogue */
		  adbloc = NewEList ();
		  catalogue->Cat_Entries = adbloc;
	       }
	     else
	       {
		  menu = catalogue->Cat_Widget;
		  adbloc = catalogue->Cat_Entries;
	       }

	     /*** Cree le titre du sous-menu ***/
	     if (title != NULL)
	       {
		  n = 0;
		  title_string = XmStringCreateSimple (title);
		  XtSetArg (args[n], XmNlabelString, title_string);
		  n++;
		  if (!rebuilded)
		    {
		       XtSetArg (args[n], XmNfontList, DefaultFont);
		       n++;
		       XtSetArg (args[n], XmNmarginHeight, 0);
		       n++;
		       XtSetArg (args[n], XmNbackground, BgMenu_Color);
		       n++;
		       XtSetArg (args[n], XmNforeground, Black_Color);
		       n++;
		       XtSetArg (args[n], XmNborderColor, Button_Color);
		       n++;
		       w = XmCreateLabel (menu, "Dialogue", args, n);
		       XtManageChild (w);
		       adbloc->E_ThotWidget[0] = w;
		       n = 0;
		       XtSetArg (args[n], XmNbackground, Button_Color);
		       n++;
		       XtSetArg (args[n], XmNseparatorType, XmSHADOW_ETCHED_OUT);
		       n++;
		       w = XmCreateSeparator (menu, "Dialogue", args, n);
		       XtManageChild (w);
		       adbloc->E_ThotWidget[1] = w;
		    }
		  else if (adbloc->E_ThotWidget[0] != 0)
		     XtSetValues (adbloc->E_ThotWidget[0], args, n);
		  XmStringFree (title_string);
	       }

	     if (!rebuilded)
	       {
		  /* Cree un Row-Column de Toggle dans le Row-Column du formulaire */
		  n = 0;
		  XtSetArg (args[n], XmNradioAlwaysOne, FALSE);
		  n++;
		  XtSetArg (args[n], XmNmarginWidth, 0);
		  n++;
		  XtSetArg (args[n], XmNmarginHeight, 0);
		  n++;
		  XtSetArg (args[n], XmNspacing, 0);
		  n++;
		  XtSetArg (args[n], XmNbackground, BgMenu_Color);
		  n++;
		  XtSetArg (args[n], XmNborderColor, Button_Color);
		  n++;
		  row = XmCreateRowColumn (menu, "Dialogue", args, n);
		  XtManageChild (row);
	       }
	     else
		/* Sinon on recupere le widget parent des entrees */
		row = catalogue->Cat_XtWParent;

	     /* note le nombre d'entrees du toggle */
	     catalogue->Cat_Data = number;	/* recouvre Cat_XtWParent */

	     /* Cree les differentes entrees du sous-menu */
	     n = 0;
	     XtSetArg (args[n], XmNindicatorType, XmN_OF_MANY);
	     n++;
	     XtSetArg (args[n], XmNfontList, DefaultFont);
	     n++;
	     XtSetArg (args[n], XmNmarginWidth, 0);
	     n++;
	     XtSetArg (args[n], XmNmarginHeight, 0);
	     n++;
	     XtSetArg (args[n], XmNbackground, BgMenu_Color);
	     n++;
	     XtSetArg (args[n], XmNforeground, Black_Color);
	     n++;
	     XtSetArg (args[n], XmNborderColor, Button_Color);
	     n++;
	     if (equiv != NULL)
	       {
		  XtSetArg (args[n + 1], XmNacceleratorText, title_string);
		  n++;
	       }
	     i = 0;
	     index = 0;
	     eindex = 0;
	     ent = 2;		/* decalage de 2 pour le widget titre */
	     while (i < number)
	       {
		  count = strlen (&text[index]);	/* Longueur de l'intitule */
		  /* S'il n'y a plus d'intitule -> on arrete */
		  if (count == 0)
		    {
		       number = i;

		       /* note le nombre d'entrees du toggle */
		       catalogue->Cat_Data = number;
		       TtaError (ERR_invalid_parameter);
		       return;
		    }
		  else
		    {

		       /* Faut-il changer de bloc d'entrees ? */
		       if (ent >= C_NUMBER)
			 {
			    adbloc->E_Next = NewEList ();
			    adbloc = adbloc->E_Next;
			    ent = 0;
			 }

		       /* E_Free est utilise pour marquer les entrees selectionnes */
		       /* Intialement les entrees sont non selectionnees */
		       adbloc->E_Free[ent] = 'N';

		       /* Note l'accelerateur */
		       if (equiv != NULL)
			 {
			    title_string = XmStringCreate (&equiv[eindex], XmSTRING_DEFAULT_CHARSET);
			    eindex += strlen (&equiv[eindex]) + 1;
			 }
		       /* On accepte toggles, boutons et separateurs */
		       if (text[index] == 'B' || text[index] == 'T')
			 /*________________________________________ Creation d'un bouton __*/
			 {
			   adbloc->E_Type[ent] = 'B';
			   w = XmCreateToggleButton (row, &text[index + 1], args, n);
		       
			   XtManageChild (w);
			   adbloc->E_ThotWidget[ent] = w;
			   XtAddCallback (w, XmNarmCallback, (XtCallbackProc) CallToggle, catalogue);
			 }
		       else if (text[index] == 'S')
			 /*_________________________________ Creation d'un separateur __*/
			 {
			    XtSetArg (args[n], XmNseparatorType, XmSINGLE_DASHED_LINE);
			    w = XmCreateSeparator (row, "Dialogue", args, n+1);
			    XtManageChild (w);
			    adbloc->E_ThotWidget[ent] = w;
			 }
		       /* liberation de la string */
		       if (equiv != NULL)
			  XmStringFree (title_string);
		       i++;
		       index += count + 1;
		       ent++;
		    }
	       }
	  }
	else
	   TtaError (ERR_invalid_parameter);
     }
#  endif /* _WINDOWS */
}


/*----------------------------------------------------------------------
   TtaSetToggleMenu fixe la selection dans un toggle-menu :           
   Le parame`tre ref donne la re'fe'rence du catalogue.               
   Le parame`tre val de'signe l'entre'e se'lectionne'e (-1 pour       
   toutes les entre'es). Le parame`tre on indique que le bouton       
   correspondant doit e^tre allume' (on positif) ou e'teint (on nul). 
  ----------------------------------------------------------------------*/
#ifdef _WINDOWS 
#ifdef __STDC__
void                WIN_TtaSetToggleMenu (int ref, int val, boolean on, HWND owner)
#else  /* __STDC__ */
void                WIN_TtaSetToggleMenu (ref, val, on, owner)
int                 ref;
int                 val;
boolean             on;
HWND                owner;
#endif /* __STDC__ */
#else  /* !_WINDOWS */
#ifdef __STDC__
void                TtaSetToggleMenu (int ref, int val, boolean on)
#else  /* __STDC__ */
void                TtaSetToggleMenu (ref, val, on)
int                 ref;
int                 val;
boolean             on;

#endif /* __STDC__ */
#endif /* _WINDOWS */
{
#  ifdef _WINDOWS 
   HMENU hMenu = GetMenu (owner);
   if (on)
      CheckMenuItem (hMenu, ref + val, MF_CHECKED); 
   else 
       CheckMenuItem (hMenu, ref + val, MF_UNCHECKED); 
#  else  /* !_WINDOWS  */
   ThotWidget          w;
   Arg                 args[MAX_ARGS];
   register int        i, n;
   register int        ent;
   boolean             visible;
   struct E_List      *adbloc;
   struct Cat_Context *catalogue;

   catalogue = CatEntry (ref);
   if (catalogue == NULL)
      TtaError (ERR_invalid_reference);
   else if (catalogue->Cat_Widget == 0)
      TtaError (ERR_invalid_reference);
   else
     {
	/* Si ce n'est pas un menu sous-menu */
	if (catalogue->Cat_Type != CAT_TMENU
	    && catalogue->Cat_Type != CAT_MENU
	    && catalogue->Cat_Type != CAT_PULL
	    && catalogue->Cat_Type != CAT_POPUP)
	  {
	     TtaError (ERR_invalid_reference);
	     return;
	  }
	else if (catalogue->Cat_Type == CAT_TMENU && val > catalogue->Cat_Data)
	  {
	     /* ce n'est pas une entree du toggle */
	     TtaError (ERR_invalid_reference);
	     return;
	  }
	/* Est-ce que le sous-menu est actuellement affiche */
	else if (XtIsManaged (catalogue->Cat_Widget))
	   visible = TRUE;
	else
	  {
	     visible = FALSE;
	     XtManageChild (catalogue->Cat_Widget);
	  }

	/* Positionnement de la valeur de chaque entree */
	adbloc = catalogue->Cat_Entries;
	ent = 0;
	i = 2;			/* decalage de 2 pour le widget titre */
	while (adbloc != NULL)
	  {
	     while (i < C_NUMBER)
	       {
		  /* S'il n'y a pas de bouton  */
		  if (adbloc->E_ThotWidget[i] == 0)
		     i = C_NUMBER;
		  /* C'est une entree qu'il faut initialiser */
		  else if ((ent == val) || (val == -1))
		    {
		       if (catalogue->Cat_Type != CAT_TMENU && adbloc->E_Type[i] != 'T')
			 {
			    /* ce n'est pas une entree du toggle */
			    TtaError (ERR_invalid_reference);
			    return;
			 }
		       else
			 {
			    w = adbloc->E_ThotWidget[i];
			    /* retire les callbacks */
			    if (catalogue->Cat_Type == CAT_TMENU)
			       XtRemoveCallback (w, XmNarmCallback, (XtCallbackProc) CallToggle, catalogue);
			    else
			       XtRemoveCallback (w, XmNvalueChangedCallback, (XtCallbackProc) CallMenu, catalogue);
			    if (on)
			       /* Bouton allume */
			      {
				 n = 0;
				 XtSetArg (args[n], XmNset, TRUE);
				 n++;
				 XtSetValues (w, args, n);
			      }
			    else
			       /* Etat initial du bouton : eteint */
			      {
				 n = 0;
				 XtSetArg (args[n], XmNset, FALSE);
				 n++;
				 XtSetValues (w, args, n);
			      }

			    /* retablit les callbacks */
			    if (catalogue->Cat_Type == CAT_TMENU)
			       XtAddCallback (w, XmNarmCallback, (XtCallbackProc) CallToggle, catalogue);
			    else
			       XtAddCallback (w, XmNvalueChangedCallback, (XtCallbackProc) CallMenu, catalogue);
			 }
		       adbloc->E_Free[i] = 'N';		/* La valeur est la valeur initiale */
		    }
		  /* Sinon l'entree garde son etat precedent  */
		  i++;
		  ent++;
	       }		/*while */
	     /* Passe au bloc suivant */
	     adbloc = adbloc->E_Next;
	     i = 0;
	  }			/*while */

	if (!visible)
	   XtUnmanageChild (catalogue->Cat_Widget);
     }
#  endif /* _WINDOWS */
}


/*----------------------------------------------------------------------
   TtaChangeMenuEntry modifie l'intitule' texte de l`entre'e entry    
   du menu de'signe' par sa re'fe'rence ref.                          
  ----------------------------------------------------------------------*/
#ifdef __STDC__
void                TtaChangeMenuEntry (int ref, int entry, char *text)
#else  /* __STDC__ */
void                TtaChangeMenuEntry (ref, entry, text)
int                 ref;
int                 entry;
char               *text;

#endif /* __STDC__ */
{
   ThotWidget          w;
   struct Cat_Context *catalogue;
   struct E_List      *adbloc;
   int                 ent;

#  ifndef _WINDOWS
   int                 n;
   Arg                 args[MAX_ARGS];
   XmString            title_string;
#  endif /* _WINDOWS */

   if (ref == 0)
     {
	TtaError (ERR_invalid_reference);
	return;
     }

   catalogue = CatEntry (ref);
   if (catalogue == NULL)
      TtaError (ERR_invalid_reference);
   /* Est-ce qu'il s'agit bien d'un menu ou d'un sous-menu ? */
   else if (catalogue->Cat_Widget == 0
	    || (catalogue->Cat_Type != CAT_MENU
		&& catalogue->Cat_Type != CAT_POPUP
		&& catalogue->Cat_Type != CAT_PULL
		&& catalogue->Cat_Type != CAT_TMENU
		&& catalogue->Cat_Type != CAT_FMENU))
      TtaError (ERR_invalid_reference);
   else
     {
	/* Recherche l'entree dans le menu ou sous-menu */
	adbloc = catalogue->Cat_Entries;
	ent = entry + 2;	/* decalage de 2 pour le widget titre */
	while (ent >= C_NUMBER)
	  {
	     if (adbloc->E_Next == NULL)
	       {
		  TtaError (ERR_invalid_parameter);
		  return;
	       }
	     else
		adbloc = adbloc->E_Next;
	     ent -= C_NUMBER;
	  }			/*while */

	if (adbloc->E_ThotWidget[ent] == 0)
	   TtaError (ERR_invalid_parameter);
	else
	  {
	     w = adbloc->E_ThotWidget[ent];
#            ifndef _WINDOWS
	     title_string = XmStringCreateSimple (text);
	     n = 0;
	     XtSetArg (args[n], XmNlabelString, title_string);
	     n++;
	     XtSetValues (w, args, n);
	     XtManageChild (w);
	     XmStringFree (title_string);
#            endif /* _WINDOWS */
	  }
     }
}


/*----------------------------------------------------------------------
   TtaRedrawMenuEntry modifie la couleur et/ou la police de l'entre'e 
   entry du menu de'signe' par sa re'fe'rence ref.                    
  ----------------------------------------------------------------------*/
#ifdef __STDC__
void                TtaRedrawMenuEntry (int ref, int entry, char *fontname, Pixel color, int activate)
#else  /* __STDC__ */
void                TtaRedrawMenuEntry (ref, entry, fontname, color, activate)
int                 ref;
int                 entry;
char               *fontname;
Pixel               color;
int                 activate;

#endif /* __STDC__ */
{
   ThotWidget          w;
   struct Cat_Context *catalogue;
   struct E_List      *adbloc;
   int                 ent;

#  ifndef _WINDOWS
   int                 n;
   Arg                 args[MAX_ARGS];
   XmFontList          font;
#  endif /* _WINDOWS */

   if (ref == 0)
     {
	TtaError (ERR_invalid_reference);
	return;
     }

   catalogue = CatEntry (ref);
   if (catalogue == NULL)
      TtaError (ERR_invalid_reference);

   /* Est-ce qu'il s'agit bien d'un menu ou d'un sous-menu ? */
   else if (catalogue->Cat_Widget == 0
	    || (catalogue->Cat_Type != CAT_MENU
		&& catalogue->Cat_Type != CAT_POPUP
		&& catalogue->Cat_Type != CAT_PULL
		&& catalogue->Cat_Type != CAT_TMENU
		&& catalogue->Cat_Type != CAT_FMENU))
      TtaError (ERR_invalid_parameter);
   else
     {
	/* Recherche l'entree dans le menu ou sous-menu */
	adbloc = catalogue->Cat_Entries;
	ent = entry + 2;	/* decalage de 2 pour le widget titre */
	while (ent >= C_NUMBER)
	  {
	     if (adbloc->E_Next == NULL)
	       {
		  TtaError (ERR_invalid_parameter);
		  return;
	       }
	     else
		adbloc = adbloc->E_Next;
	     ent -= C_NUMBER;
	  }			/*while */

	if (adbloc->E_ThotWidget[ent] == 0)
	   TtaError (ERR_invalid_parameter);
	else
	  {
	     w = adbloc->E_ThotWidget[ent];
#        ifndef _WINDOWS
	     /* Recupere si necessaire la couleur par defaut */
	     n = 0;
	     /* Faut-il changer la police de caracteres ? */
	     if (fontname != NULL)
            font = XmFontListCreate (XLoadQueryFont (GDp, fontname), XmSTRING_DEFAULT_CHARSET);
	     else
            font = DefaultFont;
	     XtSetArg (args[n], XmNfontList, font);
	     n++;

	     if (color != -1)
	       {
		  /* La couleur imposee par l'application */
		  XtSetArg (args[n], XmNforeground, color);
		  n++;
	       }
	     else
	       {
		  /* La couleur par defaut */
		  XtSetArg (args[n], XmNforeground, Black_Color);
		  n++;
	       }

	     /* Faut-il activer ou desactiver le Callback */
	     if (activate != -1)
		if (catalogue->Cat_Type == CAT_POPUP
		    || catalogue->Cat_Type == CAT_PULL
		    || catalogue->Cat_Type == CAT_MENU)
		  {
		     XtRemoveCallback (w, XmNactivateCallback, (XtCallbackProc) CallMenu, catalogue);
		     if (activate)
			XtAddCallback (w, XmNactivateCallback, (XtCallbackProc) CallMenu, catalogue);
		  }
		else
		   /*CAT_FMENU et CAT_TMENU */ if (activate)
		  {
		     XtSetArg (args[n], XmNsensitive, TRUE);
		     n++;
		  }
		else
		  {
		     XtSetArg (args[n], XmNsensitive, FALSE);
		     n++;
		  }

	     XtSetValues (w, args, n);
	     XtManageChild (w);

	     if (fontname != NULL)
		XmFontListFree (font);
#            endif /* _WINDOWS */
	  }
     }
}


/*----------------------------------------------------------------------
   DestForm de'truit un formulaire ou une feuille de saisie:          
   Le parame`tre ref donne la re'fe'rence du catalogue.               
  ----------------------------------------------------------------------*/
#ifdef __STDC__
static int          DestForm (int ref)
#else  /* __STDC__ */
static int          DestForm (ref)
int                 ref;

#endif /* __STDC__ */
{
   register int        entry;
   ThotWidget          w;
   struct Cat_Context *catalogue;
   struct Cat_Context *parentCatalogue;
   struct E_List      *adbloc;

   catalogue = CatEntry (ref);
   if (catalogue == NULL)
      return (1);
   else if (catalogue->Cat_Widget == 0)
      return (1);
   else
     {
       /*=====================> Detruit une feuille de saisie ou un formulaire*/
	if ((catalogue->Cat_Type != CAT_INT)
	    && (catalogue->Cat_Type != CAT_TEXT)
	    && (catalogue->Cat_Type != CAT_FORM)
	    && (catalogue->Cat_Type != CAT_SELECT)
	    && (catalogue->Cat_Type != CAT_SHEET)
	    && (catalogue->Cat_Type != CAT_DIALOG))
	   return (1);		/* Ce n'est pas le cas : On ne fait rien */
	else
	  {
	     /* Il faut liberer l'entree du menu pere qui le reference */
	     parentCatalogue = catalogue->Cat_PtParent;
	     entry = catalogue->Cat_EntryParent;
	     catalogue->Cat_PtParent = NULL;
	     catalogue->Cat_EntryParent = 0;

	     if (parentCatalogue != NULL)
	       {
		  /* Recherche l'entree du menu qui lui correspond */
		  adbloc = parentCatalogue->Cat_Entries;
		  while (entry >= C_NUMBER)
		    {
		       entry -= C_NUMBER;
		       if (adbloc->E_Next == NULL)
			  entry = -1;
		       else
			  adbloc = adbloc->E_Next;
		    }		/*while */

		  if (entry >= 0)
		    {
		       if ((parentCatalogue->Cat_Type == CAT_FORM)
			   || (parentCatalogue->Cat_Type == CAT_SHEET)
			   || (parentCatalogue->Cat_Type == CAT_DIALOG))
			 /*__________________________________________ Dans un formulaire __*/
			 {
#                           ifndef _WINDOWS
			    XtUnmanageChild (catalogue->Cat_Widget);
#                           endif /* _WINDOWS */
			    adbloc->E_ThotWidget[entry] = (ThotWidget) 0;
			    adbloc->E_Free[entry] = 'Y';
			 }
		       else if ((parentCatalogue->Cat_Type == CAT_POPUP)
				|| (parentCatalogue->Cat_Type == CAT_PULL)
				|| (parentCatalogue->Cat_Type == CAT_MENU))
			 /*________________________________ Formulaire attache a un menu __*/
			 {
			    if ((adbloc->E_Type[entry] == 'F')
				&& (adbloc->E_Free[entry] == 'N'))
			      {
				 /* Detache le formulaire du bouton du menu */
				 w = adbloc->E_ThotWidget[entry];
#                                ifndef _WINDOWS
				 XtRemoveCallback (w, XmNactivateCallback, (XtCallbackProc) INITetPOSform, catalogue);
#                                endif /* _WINDOWS */
				 adbloc->E_Free[entry] = 'Y';
			      }
			 }
		    }
	       }

	     /* Libere le bloc des entrees alloue */
	     if ((catalogue->Cat_Type == CAT_FORM)
		 || (catalogue->Cat_Type == CAT_INT)
		 || (catalogue->Cat_Type == CAT_SHEET)
		 || (catalogue->Cat_Type == CAT_DIALOG))
	       {
		  FreeEList (catalogue->Cat_Entries);
		  catalogue->Cat_Entries = NULL;
		  /* Note que tous les fils sont detruits */
		  if (catalogue->Cat_Type != CAT_INT)
		     ClearChildren (catalogue);
	       }

#            ifndef _WINDOWS
	     XtDestroyWidget (catalogue->Cat_Widget);
#            endif /* _WINDOWS */
	     /* Libere le catalogue */
	     catalogue->Cat_Widget = 0;
	     NbLibCat++;
	     NbOccCat--;
	     return (0);
	  }
     }
}


/*----------------------------------------------------------------------
   TtaUnmapDialogue desactive le dialogue s'il est actif.             
  ----------------------------------------------------------------------*/
#ifdef __STDC__
void                TtaUnmapDialogue (int ref)

#else  /* __STDC__ */
void                TtaUnmapDialogue (ref)
int                 ref;

#endif /* __STDC__ */
{
   struct Cat_Context *catalogue;

   if (ref == 0)
     {
	TtaError (ERR_invalid_reference);
	return;
     }

   catalogue = CatEntry (ref);
   if (catalogue == NULL)
      return;
   else if (catalogue->Cat_Widget == 0)
      return;
#  ifndef _WINDOWS
   else if (XtIsManaged (catalogue->Cat_Widget))
     {
	/* Traitement particulier des formulaires */
	if (catalogue->Cat_Type == CAT_FORM
	    || catalogue->Cat_Type == CAT_SHEET
	    || catalogue->Cat_Type == CAT_DIALOG)
	   XtUnmanageChild (XtParent (catalogue->Cat_Widget));
	XtUnmanageChild (catalogue->Cat_Widget);
     }
#  endif /* _WINDOWS */

   /* Si le catalogue correspond au dernier TtaShowDialogue */
   if (ShowCat != NULL)
      if (ref == ShowCat->Cat_Ref)
	{
	   /* Debloque eventuellement une attente active sur le catalogue */
	   ShowCat = NULL;
	   ShowReturn = 0;
	}
}


/*----------------------------------------------------------------------
   TtaDestroyDialogue de'truit le catalogue de'signe' par ref.                
  ----------------------------------------------------------------------*/
#ifdef __STDC__
void                TtaDestroyDialogue (int ref)
#else  /* __STDC__ */
void                TtaDestroyDialogue (ref)
int                 ref;

#endif /* __STDC__ */
{
   register int        entry;
   ThotWidget          w;
   struct E_List      *adbloc;
   struct Cat_Context *catalogue;
   struct Cat_Context *parentCatalogue;
   int                 n;

#  ifndef _WINDOWS
   Arg                 args[MAX_ARGS];
#  endif /* _WINDOWS */

   if (ref == 0)
     {
	TtaError (ERR_invalid_reference);
	return;
     }

   catalogue = CatEntry (ref);
   if (catalogue == NULL)
      return;
   else if (catalogue->Cat_Widget == 0)
      return;
   else
     {
	TtaUnmapDialogue (ref);
	/*===============================================> Detruit un sous-menu */
	if ((catalogue->Cat_Type == CAT_MENU)
	    || (catalogue->Cat_Type == CAT_TMENU)
	    || (catalogue->Cat_Type == CAT_FMENU))
	  {
	     /* Il faut liberer l'entree du menu pere qui le reference */
	     parentCatalogue = catalogue->Cat_PtParent;
	     entry = catalogue->Cat_EntryParent;
	     catalogue->Cat_PtParent = NULL;
	     catalogue->Cat_EntryParent = 0;

	     if (parentCatalogue != NULL)
	       {
		  /* Recherche l'entree du menu qui lui correspond */
		  adbloc = parentCatalogue->Cat_Entries;
		  while (entry >= C_NUMBER)
		    {
		       entry -= C_NUMBER;
		       if (adbloc->E_Next == NULL)
			  entry = -1;
		       else
			  adbloc = adbloc->E_Next;
		    }		/*while */

		  if (entry >= 0)
		    {
		       if (catalogue->Cat_Type == CAT_FMENU
			   || catalogue->Cat_Type == CAT_TMENU)
			 /*___________________________________ Sous-menu d'un formulaire __*/
			 {
			    /* Libere l'entree du sous-menu dans le formulaire */
			    adbloc->E_ThotWidget[entry] = (ThotWidget) 0;
			    adbloc->E_Free[entry] = 'Y';

			 }
		       else
			 /*_________________________________________ Sous-menu d'un menu __*/
			 {
			    if ((adbloc->E_Type[entry] == 'M')
				&& (adbloc->E_Free[entry] == 'N'))
			      {
/*** Delie le sous-menu du bouton du menu ***/
				 w = adbloc->E_ThotWidget[entry];
				 n = 0;
#                                ifndef _WINDOWS
				 XtSetArg (args[n], XmNsubMenuId, 0);
				 n++;
				 XtSetValues (w, args, n);
				 XtManageChild (w);
#                                endif /* _WINDOWS */
				 adbloc->E_Free[entry] = 'Y';
			      }
			 }
		    }		/*if entry */
	       }
	  }
	/*=================================================> Un autre catalogue */
	else if ((catalogue->Cat_Type != CAT_POPUP)
		 && (catalogue->Cat_Type != CAT_PULL)
		 && (catalogue->Cat_Type != CAT_LABEL))
	  {
	     /* C'est surement une destruction de formulaire */
	     if (DestForm (ref) != 0)
		TtaError (ERR_invalid_reference);
	     return;
	  }

	/* Note que tous les fils sont detruits */
	if ((catalogue->Cat_Type == CAT_POPUP)
	    || (catalogue->Cat_Type == CAT_PULL)
	    || (catalogue->Cat_Type == CAT_MENU))
	   ClearChildren (catalogue);

	/* Libere les blocs des entrees */
	FreeEList (catalogue->Cat_Entries);
	catalogue->Cat_Entries = NULL;

#       ifndef _WINDOWS
	if (catalogue->Cat_Type != CAT_PULL)
	   XtDestroyWidget (catalogue->Cat_Widget);
#       endif /* _WINDOWS */
	/* Libere le catalogue */
	catalogue->Cat_Widget = 0;
	NbLibCat++;
	NbOccCat--;
     }
}


/*----------------------------------------------------------------------
   TtaChangeFormTitle change le titre d'un formulaire ou d'une feuille        
   de dialogue :                                                   
   Le parame`tre ref donne la re'fe'rence du catalogue.               
   Le parame'tre title donne le titre du catalogue.                   
  ----------------------------------------------------------------------*/
#ifdef __STDC__
void                TtaChangeFormTitle (int ref, char *title)
#else  /* __STDC__ */
void                TtaChangeFormTitle (ref, title)
int                 ref;
char               *title;

#endif /* __STDC__ */
{
   struct Cat_Context *catalogue;

#  ifndef _WINDOWS
   int                 n;
   Arg                 args[MAX_ARGS];
   XmString            title_string;
#  endif /* _WINDOWS */

   if (ref == 0)
     {
	TtaError (ERR_invalid_reference);
	return;
     }

   catalogue = CatEntry (ref);
   if (catalogue == NULL)
      TtaError (ERR_invalid_reference);
   /* Est-ce que le catalogue existe deja ? */
   else if (catalogue->Cat_Widget == 0)
      TtaError (ERR_invalid_reference);
   else
     {
#       ifndef _WINDOWS
	title_string = XmStringCreateSimple (title);
	n = 0;
	XtSetArg (args[n], XmNdialogTitle, title_string);
	n++;
	XtSetValues (catalogue->Cat_Widget, args, n);
#       endif /* _WINDOWS */
     }
}


/*----------------------------------------------------------------------
  NewSheet
  ----------------------------------------------------------------------*/
#ifdef __STDC__
static void         NewSheet (int ref, ThotWidget parent, char *title, int number, char *text, boolean horizontal, int package, char button, int dbutton, int cattype)
#else  /* __STDC__ */
static void         NewSheet (ref, parent, title, number, text, horizontal, package, button, dbutton, cattype)
int                 ref;
ThotWidget          parent;
char               *title;
int                 number;
char               *text;
boolean             horizontal;
int                 package;
char                button;
int                 dbutton;
int                 cattype;

#endif /* __STDC__ */
{
   int                 ent;
   int                 n;
   int                 index;
   int                 count;
   struct Cat_Context* catalogue;
   struct E_List*      adbloc;
   ThotWidget          form;
   ThotWidget          w;
   char*               ptr = NULL;

#  ifdef _WINDOWS
   struct Cat_Context* copyCat;
   int                 strSize;
   int                 charWidth;
   TEXTMETRIC          tm;
   WIN_GetDeviceContext (-1);
   GetTextMetrics (TtDisplay, &tm);
   charWidth = tm.tmAveCharWidth;
#  else /* _WINDOWS */
   Arg                 args[MAX_ARGS];
   Arg                 argform[1];
   XmString            title_string;
   ThotWidget          row;
#  endif /* _WINDOWS */

#  ifdef _WINDOWS
   cyValue = 10;
#  endif /* _WINDOWS */
   if (ref == 0)
     {
	TtaError (ERR_invalid_reference);
	return;
     }

   catalogue = CatEntry (ref);
   if (catalogue == NULL)
      TtaError (ERR_cannot_create_dialogue);
   else
     {

	/* Est-ce que le catalogue existe deja ? */
	if (catalogue->Cat_Widget != 0)
	   TtaDestroyDialogue (ref);	/* Reconstruction du catalogue */

	/* Recherche le widget parent */
	if (MainShell == 0 && parent == 0)
	  {
	     TtaError (ERR_invalid_parent_dialogue);
	     return;
	  }
	/*________________________________________________ Feuillet principal __*/
	else
	  {
	     /* Il n'y a pas de menu parent */
	     catalogue->Cat_PtParent = NULL;
	     catalogue->Cat_EntryParent = 0;
	  }			/*else */

	/* Cree la fenetre du formulaire */
	if (parent != 0)
	   w = parent;
	else
	   w = MainShell;
	n = 0;
#       ifndef _WINDOWS
	XtSetArg (args[n], XmNfontList, DefaultFont);
	n++;
	/*XtSetArg(args[n], XmNallowShellResize, TRUE); n++; */
	form = XtCreateWidget (title, topLevelShellWidgetClass, w, args, n);
	XtAddCallback (form, XmNdestroyCallback, (XtCallbackProc) formKill, catalogue);
#       endif /* !_WINDOWS */

#       ifndef _WINDOWS
/*** Cree le formulaire dans sa frame ***/
	title_string = XmStringCreateSimple (title);
	XtSetArg (args[n], XmNdialogTitle, title_string);
	n++;
	XtSetArg (args[n], XmNautoUnmanage, FALSE);
	n++;
	XtSetArg (args[n], XmNdefaultPosition, FALSE);
	n++;
	XtSetArg (args[n], XmNbackground, BgMenu_Color);
	n++;
	XtSetArg (args[n], XmNborderColor, Button_Color);
	n++;
	form = XmCreateBulletinBoard (form, "", args, n);
	XtAddCallback (XtParent (form), XmNpopdownCallback, (XtCallbackProc) CallSheet, catalogue);

	XmStringFree (title_string);
#       endif /* _WINDOWS */
	catalogue->Cat_Ref = ref;
	catalogue->Cat_Type = cattype;
	catalogue->Cat_Button = button;
	catalogue->Cat_FormPack = package + 1;
	catalogue->Cat_Widget = form;

	/* Cree le contenu initial du feuillet */
	adbloc = NewEList ();	/* Un bloc supplementaire pour les boutons */
	catalogue->Cat_Entries = adbloc;
	adbloc->E_Next = NewEList ();
	adbloc = adbloc->E_Next;

#       ifndef _WINDOWS
	/*** Cree un Row-Column pour mettre les boutons QUIT/... ***/
	/*** en dessous des sous-menus et sous-formulaires.    ***/
	n = 0;
	XtSetArg (args[n], XmNadjustLast, FALSE);
	n++;
	XtSetArg (args[n], XmNmarginWidth, 0);
	n++;
	XtSetArg (args[n], XmNmarginHeight, 0);
	n++;
	XtSetArg (args[n], XmNspacing, 0);
	n++;
	XtSetArg (args[n], XmNbackground, BgMenu_Color);
	n++;
	XtSetArg (args[n], XmNborderColor, Button_Color);
	n++;
	row = XmCreateRowColumn (form, "Dialogue", args, n);
	XtManageChild (row);

	/*** Cree un Row-Column pour contenir les lignes ou colonnes ***/
	/*** de sous-menus et sous-formulaires.                      ***/
	n = 0;
	XtSetArg (args[n], XmNadjustLast, FALSE);
	n++;
	XtSetArg (args[n], XmNmarginWidth, 0);
	n++;
	XtSetArg (args[n], XmNmarginHeight, 0);
	n++;
	XtSetArg (args[n], XmNspacing, 2);
	n++;
	if (horizontal)
	   XtSetArg (args[n], XmNorientation, XmVERTICAL);
	else
	   XtSetArg (args[n], XmNorientation, XmHORIZONTAL);
	n++;
	XtSetArg (args[n], XmNbackground, BgMenu_Color);
	n++;
	XtSetArg (args[n], XmNborderColor, Button_Color);
	n++;
	w = XmCreateRowColumn (row, "Dialogue", args, n);
	XtManageChild (w);

	/*** Cree un 1er Row-Column pour contenir les sous-menus/formulaires ***/
	n = 0;
	XtSetArg (args[n], XmNadjustLast, FALSE);
	n++;
	catalogue->Cat_in_lines = (int) horizontal;
	if (horizontal)
	   XtSetArg (args[n], XmNorientation, XmHORIZONTAL);
	else
	   XtSetArg (args[n], XmNorientation, XmVERTICAL);
	n++;
	XtSetArg (args[n], XmNbackground, BgMenu_Color);
	n++;
	XtSetArg (args[n], XmNborderColor, Button_Color);
	n++;
	w = XmCreateRowColumn (w, "Dialogue", args, n);
	XtManageChild (w);
	adbloc->E_ThotWidget[0] = w;
	adbloc->E_Free[0] = 'X';

	if (number < 0)
	   /* il n'y a pas de boutons a engendrer */
	   return;

	/*** Cree un Row-Column pour contenir les boutons QUIT/... ***/
	n = 0;
	XtSetArg (args[n], XmNadjustLast, FALSE);
	n++;
	XtSetArg (args[n], XmNorientation, XmHORIZONTAL);
	n++;
	XtSetArg (args[n], XmNpacking, XmPACK_TIGHT/*XmPACK_COLUMN*/);
	n++;
	XtSetArg (args[n], XmNbackground, BgMenu_Color);
	n++;
	XtSetArg (args[n], XmNforeground, Black_Color);
	n++;
	XtSetArg (args[n], XmNspacing, 5);
	n++;
	XtSetArg (args[n], XmNnumColumns, /*(number + 4) / 4*/number);
	n++;
	row = XmCreateRowColumn (row, "Dialogue", args, n);
	XtManageChild (row);

	/*** Cree les boutons ***/
	n = 0;
	XtSetArg (args[n], XmNfontList, formFONT);
	n++;
	XtSetArg (args[n], XmNbackground, Button_Color);
	n++;
	XtSetArg (args[n], XmNforeground, Black_Color);
	n++;
#       endif /* !_WINDOWS */
	adbloc = catalogue->Cat_Entries;

	if (cattype == CAT_SHEET)
	   ent = 1;
	else if (cattype == CAT_FORM)
	  {
	    /*** Cree le bouton de confirmation du formulaire ***/
	     ent = 1;
#            ifndef _WINDOWS 
	     w = XmCreatePushButton (row, Confirm_string, args, n);
	     XtManageChild (w);
	     XtAddCallback (w, XmNactivateCallback, (XtCallbackProc) CallSheet, catalogue);
	     /* Definit le bouton de confirmation comme bouton par defaut */
	     XtSetArg (argform[0], XmNdefaultButton, w);
	     XtSetValues (form, argform, 1);
	     adbloc->E_ThotWidget[1] = w;
	     /* Definit le bouton de confirmation comme bouton par defaut */
	     XtSetArg (argform[0], XmNdefaultButton, w);
	     XtSetValues (form, argform, 1);
#            else  /* _WINDOWS */
             strSize = strlen (Confirm_string) * charWidth + 20;
             formulary.Buttons[bIndex] = CreateWindow ("BUTTON", Confirm_string, 
                                                       WS_CHILD | BS_PUSHBUTTON | WS_VISIBLE,
                                                       bAbsBase, 300, strSize, 20, parent, 
                                                       (HMENU) IDCANCEL, hInstance, NULL) ;
             bAbsBase += (strSize + 20);
             bIndex++ ;
	     adbloc->E_ThotWidget[1] = (ThotWidget) IDCANCEL;
#            endif /* _WINDOWS */
	  }
	else
	   ent = 0;

	/*** Cree les autres boutons du feuillet ***/
	index = 0;
	while (ent < C_NUMBER && ent <= number && text != NULL)
	  {
	     count = strlen (&text[index]);	/* Longueur de l'intitule */
	     /* S'il n'y a plus d'intitule -> on arrete */
	     if (count == 0)
		ent = number;
	     else
	       {
		  if (ent == 0)
		     /* Le premier bouton remplace le bouton QUIT */
		     ptr = &text[index];
		  else
		    {
#                      ifndef _WINDOWS
		       w = XmCreatePushButton (row, &text[index], args, n);
		       XtManageChild (w);
		       XtAddCallback (w, XmNactivateCallback, (XtCallbackProc) CallSheet, catalogue);
		       adbloc->E_ThotWidget[ent] = w;
#                      else  /* _WINDOWS */
                       strSize = strlen (&text[index]) * charWidth + 10;
                       formulary.Buttons[bIndex] = CreateWindow ("BUTTON", &text[index], 
                                                                 WS_CHILD | BS_PUSHBUTTON | WS_VISIBLE,
                                                                 bAbsBase, 300, strSize, 20, parent, 
                                                                 ref + bIndex, hInstance, NULL) ;
                       bAbsBase += (strSize + 10);
                       bIndex++ ;
	               adbloc->E_ThotWidget[ent] = (ThotWidget) bIndex;
#                      endif /* _WINDOWS */
		    }
#                 ifndef _WINDOWS
		  /* Definit le bouton de confirmation comme bouton par defaut */
		  if (index == 0)
		     XtSetArg (argform[0], XmNdefaultButton, w);
		  XtSetValues (form, argform, 1);
#                 endif  /* !_WINDOWS */
	       }
	     index += count + 1;
	     ent++;
	  }

	if (cattype == CAT_SHEET || cattype == CAT_FORM)
	  /*** Cree le bouton QUIT ***/
	   switch (dbutton)
		 {
		    case D_CANCEL:
#                      ifndef _WINDOWS
		       w = XmCreatePushButton (row, Cancel_string, args, n);
#                      else  /* _WINDOWS */
                       strSize = strlen (Cancel_string) * charWidth + 10;
                       formulary.Buttons[bIndex] = CreateWindow ("BUTTON", Cancel_string, 
                                                                 WS_CHILD | BS_PUSHBUTTON | WS_VISIBLE,
                                                                 bAbsBase, 300, strSize, 20, parent, 
                                                                 (HMENU) IDCANCEL, hInstance, NULL) ;
	               adbloc->E_ThotWidget[ent] = (ThotWidget) IDCANCEL;
                       bAbsBase += (strSize + 10);
#                      endif /* _WINDOWS */
		       break;
		    case D_DONE:
#                      ifndef _WINDOWS
		       w = XmCreatePushButton (row, Done_string, args, n);
#                      else  /* _WINDOWS */
                       strSize = strlen (Done_string) * charWidth + 10;
                       formulary.Buttons[bIndex] = CreateWindow ("BUTTON", Done_string, 
                                                                 WS_CHILD | BS_PUSHBUTTON | WS_VISIBLE,
                                                                 bAbsBase, 300, strSize, 20, parent, 
                                                                 (HMENU) IDCANCEL, hInstance, NULL) ;
	               adbloc->E_ThotWidget[ent] = (ThotWidget) IDCANCEL;
                       bAbsBase += (strSize + 10);
#                      endif /* _WINDOWS */
		       break;
		 }
	else
#          ifndef _WINDOWS
	   w = XmCreatePushButton (row, ptr, args, n);
#          else  /* _WINDOWS */
	  {
             strSize = strlen (ptr) * charWidth + 10;
             formulary.Buttons[bIndex] = CreateWindow ("BUTTON", ptr, 
                                                       WS_CHILD | BS_PUSHBUTTON | WS_VISIBLE,
                                                       bAbsBase, 300, strSize, 20, parent, 
                                                       (HMENU) (ref + bIndex), hInstance, NULL) ;
             bAbsBase += (strSize + 10);
	     adbloc->E_ThotWidget[ent] = (ThotWidget) bIndex;
	  } 
          bIndex++ ;
#          endif /* _WINDOWS */

#       ifndef _WINDOWS
	XtManageChild (w);
	XtAddCallback (w, XmNactivateCallback, (XtCallbackProc) CallSheet, catalogue);
#       endif /* !_WINDOWS */
	/* Range le bouton dans le 1er bloc de widgets */
	adbloc->E_ThotWidget[0] = w;
#       ifdef _WINDOWS
        form = CreateWindow ("WNDIALOGBOX", title, DS_MODALFRAME | WS_POPUP | 
                             WS_VISIBLE | WS_CAPTION | WS_SYSMENU,
	  		     CW_USEDEFAULT, CW_USEDEFAULT, bAbsBase + 20, 400,
			     w, 0, hInstance, 0); 

#   ifdef AMAYA_DEBUG
	fprintf (stderr, "Created ComboBox %X\n", form);
#   endif /* AMAYA_DEBUG */

        catalogue->Cat_Widget = form;
        copyCat = catalogue;
        WIN_AddFrameCatalogue (parent, copyCat) ;
        bIndex   =  0;
        bAbsBase = 60;
#       endif /* _WINDOWS */
     }
}

#ifdef _WINDOWS
#ifndef _WIN_PRINT
 /*----------------------------------------------------------------------
   Callback pour un bouton du menu                                    
  ----------------------------------------------------------------------*/
#ifdef __STDC__
void WIN_ThotCallBack (HWND hWnd, WPARAM wParam, LPARAM lParam)
#else  /* !__STDC__ */
void WIN_ThotCallBack (hWnd, wParam, lParam)
HWND   hWnd; 
WPARAM wParam; 
LPARAM lParam;
#endif /* __STDC__ */
{
   BOOL    modified;
   Element el;
   struct Cat_Context* catalogue;
   int                 no = 0;
   int                 frame = GetMainFrameNumber (hWnd);

#  ifdef AMAYA_DEBUG
   fprintf (stderr, "Got WIN_ThotCallBack(%X, %X(%d:%d), %X(%d))\n",
	    hWnd, wParam, HIWORD (wParam), LOWORD (wParam), lParam, lParam);
#  endif /* AMAYA_DEBUG */

   if (frame != - 1) {
      currentParent = FrMainRef [frame];
      catalogue = WinLookupCatEntry (hWnd, LOWORD (wParam));
      if (catalogue != NULL)
         no = LOWORD (wParam) - catalogue->Cat_Ref;

      if (catalogue == NULL)
         return;

     switch (catalogue->Cat_Type) {
             case CAT_PULL:
             case CAT_MENU:
             case CAT_POPUP:
                  CallMenu (no, catalogue, NULL);
                  if (ReturnOption >= 0) {
                     el = opOption[ReturnOption];
                     modified = TtaIsDocumentModified (opDoc);
                     OnlyOneOptionSelected (el, opDoc, FALSE);
                     if (!modified)
                        TtaSetDocumentUnmodified (opDoc);
				  }
                  break;

             case CAT_TMENU:
                  CallToggle (no, catalogue, NULL);
                  break;

             case CAT_SHEET:
             case CAT_FMENU:
                  CallRadio (no, catalogue, NULL);
				  break;

             default:
#                   ifdef AMAYA_DEBUG
                    fprintf (stderr, "unknown Cat_Type %d\n", catalogue->Cat_Type);
#                   endif /* AMAYA_DEBUG */
	                break;
     }
   }

}

/*-----------------------------------------------------------------------
 ThotDlgProc
 ------------------------------------------------------------------------*/
#ifdef __STDC__
LRESULT CALLBACK ThotDlgProc (HWND hwnDlg, UINT msg, WPARAM wParam, LPARAM lParam)
#else  /* !__STDC__ */
LRESULT CALLBACK ThotDlgProc (hwnDlg, msg, wParam, lParam)
HWND   hwndParent; 
UINT   msg; 
WPARAM wParam; 
LPARAM lParam;
#endif /* __STDC__ */
{
    int        ndx ;
    
    switch (msg) {
           case WM_CREATE: {
	        for (ndx = 0; ndx < bIndex; ndx ++) {
                    SetParent (formulary.Buttons[ndx], hwnDlg);
                    ShowWindow (formulary.Buttons[ndx], SW_SHOW);
		}
                return 0;
	   }
           case WM_COMMAND:
	        switch (LOWORD (wParam)) {
                       case IDCANCEL: DestroyWindow (hwnDlg);
                                      return 0;
		       default:       WIN_ThotCallBack (GetParent (hwnDlg), wParam , lParam);
                                      return 0;
		}
           default: return (DefWindowProc (hwnDlg, msg, wParam, lParam)) ;
    }
}
#endif /* _WIN_PRINT */
#endif /* _WINDOWS */


/*----------------------------------------------------------------------
   TtaNewForm cre'e un formulaire :                                   
   Le parame`tre ref donne la reference et parent le ThotWidget pe're 
   Si parent est nul, le menu est attache a la fenetre MainWindow.          
   Le parame'tre title donne le titre du catalogue.            
   Le parame`tre horizontal indique que le formulaire est compose' en 
   lignes (TRUE) ou en colonnes (FALSE).                              
   Le parame`tre package donne le facteur de blocage du formulaire    
   (nombre d'entre'es par ligne ou par colonne).                      
   Le parame'tre button indique le bouton de la souris qui active le  
   menu : 'L' pour left, 'M' pour middle et 'R' pour right.           
  ----------------------------------------------------------------------*/
#ifdef __STDC__
void                TtaNewForm (int ref, ThotWidget parent, char *title, boolean horizontal, int package, char button, int dbutton)
#else  /* __STDC__ */
void                TtaNewForm (ref, parent, title, horizontal, package, button, dbutton)
int                 ref;
ThotWidget          parent;
char               *title;
boolean             horizontal;
int                 package;
char                button;
int                 dbutton;

#endif /* __STDC__ */
{
   NewSheet (ref, parent, title, 0, NULL, horizontal, package, button, dbutton, CAT_FORM);
}


/*----------------------------------------------------------------------
   TtaNewSheet cre'e un feuillet de commande :                        
   Le parame`tre ref donne la reference et parent le ThotWidget pe're 
   Si parent est nul, le menu est attache a la fenetre MainWindow.          
   Le parame`tre title donne le titre du catalogue.            
   Le parame`tre number indique le nombre de boutons ajoute's au      
   bouton 'QUIT' mis par de'faut.                                     
   Le parame`tre text contient la liste des intitule's des boutons    
   ajoute's au bouton 'QUIT'.                                         
   Chaque intitule' se termine par le caracte`re de fin de chai^ne \0.
   Le parame`tre horizontal indique que le formulaire est compose' en 
   lignes (TRUE) ou en colonnes (FALSE).                              
   Le parame`tre package donne le facteur de blocage du formulaire    
   (nombre d'entre'es par ligne ou par colonne).                      
   Le parame`tre button indique le bouton de la souris qui active le  
   menu : 'L' pour left, 'M' pour middle et 'R' pour right.           
  ----------------------------------------------------------------------*/
#ifdef __STDC__
void                TtaNewSheet (int ref, ThotWidget parent, char *title, int number, char *text, boolean horizontal, int package, char button, int dbutton)
#else  /* __STDC__ */
void                TtaNewSheet (ref, parent, title, number, text, horizontal, package, button, dbutton)
int                 ref;
ThotWidget          parent;
char               *title;
int                 number;
char               *text;
boolean             horizontal;
int                 package;
char                button;
int                 dbutton;

#endif /* __STDC__ */
{
   NewSheet (ref, parent, title, number, text, horizontal, package, button, dbutton, CAT_SHEET);
}


/*----------------------------------------------------------------------
   TtaNewDialogSheet cre'e un feuillet de dialogue :                  
   Le parame`tre ref donne la reference et parent le ThotWidget pe're 
   Si parent est nul, le menu est attache a la fenetre MainWindow.          
   Le parame`tre title donne le titre du catalogue.            
   Le parame`tre number indique le nombre de boutons ajoute's au      
   bouton 'QUIT' mis par de'faut.                                     
   Le parame`tre text contient la liste des intitule's des boutons    
   ajoute's au bouton 'QUIT'.                                         
   Chaque intitule' se termine par le caracte`re de fin de chai^ne \0.
   Le parame`tre horizontal indique que le formulaire est compose' en 
   lignes (TRUE) ou en colonnes (FALSE).                              
   Le parame`tre package donne le facteur de blocage du formulaire    
   (nombre d'entre'es par ligne ou par colonne).                      
   Le parame`tre button indique le bouton de la souris qui active le  
   menu : 'L' pour left, 'M' pour middle et 'R' pour right.           
  ----------------------------------------------------------------------*/
#ifdef __STDC__
void                TtaNewDialogSheet (int ref, ThotWidget parent, char *title, int number, char *text, boolean horizontal, int package, char button)

#else  /* __STDC__ */
void                TtaNewDialogSheet (ref, parent, title, number, text, horizontal, package, button)
int                 ref;
ThotWidget          parent;
char               *title;
int                 number;
char               *text;
boolean             horizontal;
int                 package;
char                button;

#endif /* __STDC__ */
{
   NewSheet (ref, parent, title, number - 1, text, horizontal, package, button, D_DONE, CAT_DIALOG);
}


/*----------------------------------------------------------------------
   TtaAttachForm attache le catalogue au formulaire ou au feuillet    
   dont il de'pend. Les catalogues sont cre'e's attache's.            
  ----------------------------------------------------------------------*/
#ifdef __STDC__
void                TtaAttachForm (int ref)
#else  /* __STDC__ */
void                TtaAttachForm (ref)
int                 ref;

#endif /* __STDC__ */
{
   int                 entry;
   struct E_List      *adbloc;
   struct Cat_Context *catalogue;
   struct Cat_Context *parentCatalogue;

   if (ref == 0)
     {
	TtaError (ERR_invalid_reference);
	return;
     }

   catalogue = CatEntry (ref);
   if (catalogue == NULL)
      TtaError (ERR_invalid_reference);
   else if (catalogue->Cat_Widget == 0)
      TtaError (ERR_invalid_reference);
   else if ((catalogue->Cat_Type != CAT_FMENU)
	    && (catalogue->Cat_Type != CAT_TMENU)
	    && (catalogue->Cat_Type != CAT_TEXT)
	    && (catalogue->Cat_Type != CAT_LABEL)
	    && (catalogue->Cat_Type != CAT_INT)
	    && (catalogue->Cat_Type != CAT_SELECT))
      TtaError (ERR_invalid_reference);
   else
     {
	/* Attache le catalogue au formulaire designe */
	parentCatalogue = catalogue->Cat_PtParent;
	if (parentCatalogue == NULL)
	  {
	     TtaError (ERR_invalid_parent_dialogue);
	     return;
	  }

	/* Recherche l'entree du menu qui lui correspond */
	adbloc = parentCatalogue->Cat_Entries;
	entry = catalogue->Cat_EntryParent;

	/* Saute au bloc qui contient l'entree recherchee */
	while (entry >= C_NUMBER)
	  {
	     if (adbloc->E_Next == NULL)
	       {
		  TtaError (ERR_invalid_parameter);
		  return;
	       }
	     else
		adbloc = adbloc->E_Next;
	     entry -= C_NUMBER;
	  }

	if (adbloc->E_Free[entry] == 'Y')
	  {
	     /* marque que le sous-menu est attache */
	     adbloc->E_Free[entry] = 'N';
	     /* affiche le widget sur l'ecran */
#            ifndef _WINDOWS
	     if (XtIsManaged (parentCatalogue->Cat_Widget))
		XtManageChild (catalogue->Cat_Widget);
#            endif /* _WINDOWS */
	  }
     }
}


/*----------------------------------------------------------------------
   TtaDetachForm detache le catalogue au formulaire ou au feuillet    
   dont il de'pend. Les catalogues sont cre'e's attache's.            
  ----------------------------------------------------------------------*/
#ifdef __STDC__
void                TtaDetachForm (int ref)
#else  /* __STDC__ */
void                TtaDetachForm (ref)
int                 ref;

#endif /* __STDC__ */
{
   int                 entry;
   struct E_List      *adbloc;
   struct Cat_Context *catalogue;
   struct Cat_Context *parentCatalogue;

   if (ref == 0)
     {
	TtaError (ERR_invalid_reference);
	return;
     }

   catalogue = CatEntry (ref);
   if (catalogue == NULL)
      TtaError (ERR_invalid_reference);
   else if (catalogue->Cat_Widget == 0)
      TtaError (ERR_invalid_reference);
   else if ((catalogue->Cat_Type != CAT_FMENU)
	    && (catalogue->Cat_Type != CAT_TMENU)
	    && (catalogue->Cat_Type != CAT_TEXT)
	    && (catalogue->Cat_Type != CAT_LABEL)
	    && (catalogue->Cat_Type != CAT_INT)
	    && (catalogue->Cat_Type != CAT_SELECT))
      TtaError (ERR_invalid_reference);
   else
     {
	/* Detache le catalogue du formulaire designe */
	parentCatalogue = catalogue->Cat_PtParent;
	if (parentCatalogue == NULL)
	  {
	     TtaError (ERR_invalid_parent_dialogue);
	     return;
	  }

	/* Recherche l'entree du menu qui lui correspond */
	adbloc = parentCatalogue->Cat_Entries;
	entry = catalogue->Cat_EntryParent;

	/* Saute au bloc qui contient l'entree recherchee */
	while (entry >= C_NUMBER)
	  {
	     if (adbloc->E_Next == NULL)
	       {
		  TtaError (ERR_invalid_parameter);
		  return;
	       }
	     else
		adbloc = adbloc->E_Next;
	     entry -= C_NUMBER;
	  }

	if (adbloc->E_Free[entry] == 'N')
	  {
	     /* marque que le sous-menu est detache */
	     adbloc->E_Free[entry] = 'Y';
	     /* retire le widget de l'ecran */
#            ifndef _WINDOWS
	     if (XtIsManaged (catalogue->Cat_Widget))
		XtUnmanageChild (catalogue->Cat_Widget);
#            endif /* _WINDOWS */
	  }

     }
}


/*----------------------------------------------------------------------
   TtaNewSelector cre'e un se'lecteur dans un formulaire :            
   Le parame`tre ref donne la re'fe'rence pour l'application.         
   Le parame`tre title donne le titre du catalogue.                   
   Le parame`tre number donne le nombre d'intitule's.                 
   Le parame`tre text contient la liste des intitule's.               
   Le parame`tre height donne le nombre d'intitule's visibles a` la   
   fois (hauteur de la fenetree^tre de visualisation).                        
   Le parame`tre label ajoute un choix supple'mentaire a` la liste    
   des choix possibles. Ce choix est affiche' se'pare'ment et donc    
   mis en e'vidence.                                                  
   Le parame`tre withText indique s'il faut creer une zone texte.     
   Quand le parame`tre react est vrai, tout changement de se'lection  
   dans le se'lecteur est imme'diatement signale' a` l'application.   
  ----------------------------------------------------------------------*/
#ifdef __STDC__
void                TtaNewSelector (int ref, int ref_parent, char *title, int number, char *text, int height, char *label, boolean withText, boolean react)
#else  /* __STDC__ */
void                TtaNewSelector (ref, ref_parent, title, number, text, height, label, withText, react)
int                 ref;
int                 ref_parent;
char               *title;
int                 number;
char               *text;
int                 height;
char               *label;
boolean             withText;
boolean             react;

#endif /* __STDC__ */
{
   struct Cat_Context *catalogue;
   struct Cat_Context *parentCatalogue;

#  ifndef _WINDOWS
   Arg                 args[MAX_ARGS];
   ThotWidget          wt;
   int                 ent;
   int                 index;
   int                 i;
   int                 n;
   ThotWidget          row;
   ThotWidget          w;
   struct E_List      *adbloc;
   XmString            title_string;
   XmString           *item;
#  endif /* _WINDOWS */

   boolean             rebuilded;

   if (ref == 0)
     {
	TtaError (ERR_invalid_reference);
	return;
     }

   catalogue = CatEntry (ref);
   rebuilded = FALSE;
   if (catalogue == NULL)
     {
	TtaError (ERR_invalid_reference);
	return;
     }

   /* Faut-il detruire le catalogue precedent ? */
   else if (catalogue->Cat_Widget != 0)
     {
	/* Si c'est une mise a jour du selecteur */
	if (catalogue->Cat_Type == CAT_SELECT && (withText != catalogue->Cat_SelectList))
	   rebuilded = TRUE;
	else
	   TtaDestroyDialogue (ref);	/* Modification du catalogue */
     }

   /*______________________________ Regarde si le catalogue parent existe __*/
   if (!rebuilded)
     {
	parentCatalogue = CatEntry (ref_parent);
	if (parentCatalogue == NULL)
	  {
	     TtaError (ERR_invalid_parent_dialogue);
	     return;
	  }
	else if (parentCatalogue->Cat_Widget == 0)
	  {
	     TtaError (ERR_invalid_parent_dialogue);
	     return;
	  }
	else if ((parentCatalogue->Cat_Type != CAT_FORM)
		 && (parentCatalogue->Cat_Type != CAT_SHEET)
		 && (parentCatalogue->Cat_Type != CAT_DIALOG))
	  {
	     TtaError (ERR_invalid_parent_dialogue);
	     return;
	  }
	catalogue->Cat_PtParent = parentCatalogue;
     }
   else
      parentCatalogue = catalogue->Cat_PtParent;

   /* Avec ou sans zone texte */
   catalogue->Cat_SelectList = !withText;
   catalogue->Cat_React = react;

#  ifndef _WINDOWS
   if (number == 0)
     {
	/* Cree un selecteur avec une entree a blanc */
	item = (XmString *) TtaGetMemory (sizeof (XmString) * 2);
	item[0] = XmStringCreateLtoR (" ", XmSTRING_DEFAULT_CHARSET);
	number = 1;
     }
   else
     {
	/* Cree les differentes entrees du selecteur */
	item = (XmString *) TtaGetMemory (sizeof (XmString) * (number + 1));
	i = 0;
	index = 0;
	while (i < number && text[index] != EOS)
	  {
	     item[i++] = XmStringCreateLtoR (&text[index], XmSTRING_DEFAULT_CHARSET);
	     index += strlen (&text[index]) + 1;	/* Longueur de l'intitule */
	  }
	number = i;
     }
   item[number] = NULL;

   /* Faut-il simplement mettre a jour le selecteur ? */
   if (rebuilded)
     {

	/* On met a jour le titre du selecteur */
	if (catalogue->Cat_Title != 0 && title != NULL)
	  {
	     n = 0;
	     title_string = XmStringCreateSimple (title);
	     XtSetArg (args[n], XmNlabelString, title_string);
	     n++;
	     XtSetValues (catalogue->Cat_Title, args, n);
	     XtManageChild (catalogue->Cat_Title);
	     XmStringFree (title_string);
	  }

	/* On met a jour le label attache au selecteur */
	if (catalogue->Cat_SelectLabel != 0 && label != NULL)
	  {
	     n = 0;
	     title_string = XmStringCreateSimple (label);
	     XtSetArg (args[n], XmNlabelString, title_string);
	     n++;
	     XtSetValues (catalogue->Cat_SelectLabel, args, n);
	     XtManageChild (catalogue->Cat_SelectLabel);
	     XmStringFree (title_string);
	  }

	/* On met a jour le selecteur (catalogue->Cat_Entries) */
	catalogue->Cat_ListLength = number;
	n = 0;
	w = (ThotWidget) catalogue->Cat_Entries;
	if (catalogue->Cat_SelectList)
	  {
	     /* Une simple liste */
	     XtSetArg (args[n], XmNitems, item);
	     n++;
	     XtSetArg (args[n], XmNitemCount, number);
	     n++;

	     /* Detruit l'ancienne liste */
	     XmListDeleteAllItems (w);
	     /* Remplace par la nouvelle liste */
	     XtSetValues (w, args, n);
	  }
	else
	  {
	     /* Un selecteur */
	     XtSetArg (args[n], XmNlistItems, item);
	     n++;
	     XtSetArg (args[n], XmNlistItemCount, number);
	     n++;
	     /*XtSetArg(args[n], XmNlistVisibleItemCount, height); n++; */
	     title_string = XmStringCreateSimple ("");
	     XtSetArg (args[n], XmNselectionLabelString, title_string);
	     n++;

	     /* Detruit l'ancienne liste */
	     wt = XmSelectionBoxGetChild (w, XmDIALOG_LIST);
	     XmListDeleteAllItems (wt);
	     /* Remplace par la nouvelle liste */
	     XtSetValues (w, args, n);
	     XmStringFree (title_string);
	  }
	XtManageChild (w);
     }
   else
     {
       /*_______________________________________ C'est un nouveau formulaire __*/
	w = AddInFormulary (parentCatalogue, &i, &ent, &adbloc);

	/* Cree un sous-menu d'un formulaire */
	/*** Cree un Row-Column dans le Row-Column du formulaire ***/
	n = 0;
	XtSetArg (args[n], XmNbackground, BgMenu_Color);
	n++;
	XtSetArg (args[n], XmNborderColor, Button_Color);
	n++;
	XtSetArg (args[n], XmNmarginWidth, 0);
	n++;
	XtSetArg (args[n], XmNmarginHeight, 0);
	n++;
	XtSetArg (args[n], XmNspacing, 0);
	n++;
	row = XmCreateRowColumn (w, "Dialogue", args, n);

	catalogue->Cat_Ref = ref;
	catalogue->Cat_Type = CAT_SELECT;
	catalogue->Cat_ListLength = number;
	catalogue->Cat_Widget = row;
	adbloc->E_ThotWidget[ent] = (ThotWidget) catalogue;
	adbloc->E_Free[ent] = 'N';
	catalogue->Cat_EntryParent = i;
	catalogue->Cat_Title = 0;

	/*** Cree le titre du selecteur ***/
	if (title != NULL)
	  {
	     n = 0;
	     title_string = XmStringCreateSimple (title);
	     XtSetArg (args[n], XmNfontList, DefaultFont);
	     n++;
	     XtSetArg (args[n], XmNlabelString, title_string);
	     n++;
	     XtSetArg (args[n], XmNmarginHeight, 0);
	     n++;
	     XtSetArg (args[n], XmNbackground, BgMenu_Color);
	     n++;
	     XtSetArg (args[n], XmNforeground, Black_Color);
	     n++;
	     XtSetArg (args[n], XmNborderColor, Button_Color);
	     n++;
	     w = XmCreateLabel (row, "Dialogue", args, n);
	     XtManageChild (w);
	     catalogue->Cat_Title = w;
	     XmStringFree (title_string);
	  }

	/*** Cree le label attache au selecteur ***/
	if (label != NULL)
	  {
	     n = 0;
	     XtSetArg (args[n], XmNfontList, DefaultFont);
	     n++;
	     XtSetArg (args[n], XmNbackground, BgMenu_Color);
	     n++;
	     XtSetArg (args[n], XmNforeground, Black_Color);
	     n++;
	     XtSetArg (args[n], XmNborderColor, Button_Color);
	     n++;
	     w = XmCreatePushButton (row, label, args, n);
	     XtManageChild (w);
	     catalogue->Cat_SelectLabel = w;
	     XtAddCallback (w, XmNactivateCallback, (XtCallbackProc) CallLabel, catalogue);
	  }
	else
	   catalogue->Cat_SelectLabel = 0;

	n = 0;
	XtSetArg (args[n], XmNmarginWidth, 0);
	n++;
	XtSetArg (args[n], XmNmarginHeight, 0);
	n++;
	XtSetArg (args[n], XmNspacing, 0);
	n++;
	XtSetArg (args[n], XmNbackground, BgMenu_Color);
	n++;
	XtSetArg (args[n], XmNforeground, Black_Color);
	n++;
	XtSetArg (args[n], XmNborderColor, Button_Color);
	n++;
	XtSetArg (args[n], XmNfontList, DefaultFont);
	n++;
	if (catalogue->Cat_SelectList)
	  {
	     /* Une simple liste */
	     XtSetArg (args[n], XmNselectionPolicy, XmSINGLE_SELECT);
	     n++;
	     XtSetArg (args[n], XmNlistSizePolicy, XmVARIABLE);
	     n++;
	     XtSetArg (args[n], XmNitems, item);
	     n++;
	     XtSetArg (args[n], XmNitemCount, number);
	     n++;
	     XtSetArg (args[n], XmNvisibleItemCount, height);
	     n++;
	     w = XmCreateScrolledList (row, title, args, n);
	     XtManageChild (w);
	     /* Si le selecteur est reactif */
	     if (react)
		XtAddCallback (w, XmNsingleSelectionCallback, (XtCallbackProc) CallList, catalogue);
	  }
	else
	  {
	     /* Un selecteur */
	     XtSetArg (args[n], XmNlistItems, item);
	     n++;
	     XtSetArg (args[n], XmNlistItemCount, number);
	     n++;
	     XtSetArg (args[n], XmNlistVisibleItemCount, height);
	     n++;
	     XtSetArg (args[n], XmNdialogType, XmDIALOG_COMMAND);
	     n++;
	     if (TextTranslations != NULL)
	       {
		  XtSetArg (args[n], XmNtextTranslations, TextTranslations);
		  n++;
	       }
	     title_string = XmStringCreateSimple ("");
	     XtSetArg (args[n], XmNselectionLabelString, title_string);
	     n++;
	     w = XmCreateSelectionBox (row, title, args, n);
	     XtManageChild (w);
	     XmStringFree (title_string);

	     /* Controle la couleur des widgets fils */
	     n = 0;
	     XtSetArg (args[n], XmNbackground, BgMenu_Color);
	     n++;
	     XtSetArg (args[n], XmNforeground, Black_Color);
	     n++;
	     XtSetArg (args[n], XmNborderColor, Button_Color);
	     n++;
	     XtSetArg (args[n], XmNfontList, DefaultFont);
	     n++;
	     XtSetArg (args[n], XmNtroughColor, Button_Color);
	     n++;
	     wt = XmSelectionBoxGetChild (w, XmDIALOG_LIST);
	     XtSetValues (wt, args, n);
	     wt = XmSelectionBoxGetChild (w, XmDIALOG_TEXT);
	     XtSetValues (wt, args, n - 1);
	     /* Si le selecteur est reactif */
	     if (react)
		XtAddCallback (wt, XmNvalueChangedCallback, (XtCallbackProc) CallTextChange, catalogue);
	  }

	/* Conserve le widget du selecteur dans l'entree Cat_Entries */
	catalogue->Cat_Entries = (struct E_List *) w;
     }

   /* Libere les XmString allouees */
   i = 0;
   while (item[i] != NULL)
     {
	XmStringFree (item[i]);
	i++;
     }
   TtaFreeMemory ( item);
#  endif /* _WINDOWS */
}


/*----------------------------------------------------------------------
   TtaActiveSelector rend actif le  se'lecteur.                       
  ----------------------------------------------------------------------*/
#ifdef __STDC__
void                TtaActiveSelector (int ref)
#else  /* __STDC__ */
void                TtaActiveSelector (ref)
int                 ref;

#endif /* __STDC__ */
{
   ThotWidget          w;
   struct Cat_Context *catalogue;

#  ifndef _WINDOWS
   Arg                 args[MAX_ARGS];
#  endif /* _WINDOWS */

   catalogue = CatEntry (ref);
   if (catalogue == NULL)
      TtaError (ERR_invalid_reference);
   else if (catalogue->Cat_Widget == 0)
      TtaError (ERR_invalid_reference);
   else if (catalogue->Cat_Type != CAT_SELECT)
      TtaError (ERR_invalid_reference);
   else
     {
	/* Recupere le widget du selecteur */
	w = (ThotWidget) catalogue->Cat_Entries;
#       ifndef _WINDOWS
	XtSetArg (args[0], XmNsensitive, TRUE);
	XtSetValues (w, args, 1);
	XtManageChild (w);
#       endif /* _WINDOWS */
     }
}


/*----------------------------------------------------------------------
   TtaDesactiveSelector rend non actif le  se'lecteur.                        
  ----------------------------------------------------------------------*/
#ifdef __STDC__
void                TtaDesactiveSelector (int ref)
#else  /* __STDC__ */
void                TtaDesactiveSelector (ref)
int                 ref;

#endif /* __STDC__ */
{
   ThotWidget          w;
   struct Cat_Context *catalogue;

#  ifndef _WINDOWS
   Arg                 args[MAX_ARGS];
#  endif /* _WINDOWS */


   catalogue = CatEntry (ref);
   if (catalogue == NULL)
      TtaError (ERR_invalid_reference);
   else if (catalogue->Cat_Widget == 0)
      TtaError (ERR_invalid_reference);
   else if (catalogue->Cat_Type != CAT_SELECT)
      TtaError (ERR_invalid_reference);
   else
     {
	/* Recupere le widget du selecteur */
	w = (ThotWidget) catalogue->Cat_Entries;
#       ifndef _WINDOWS
	XtSetArg (args[0], XmNsensitive, FALSE);
	XtSetValues (w, args, 1);
	XtManageChild (w);
#       endif /* _WINDOWS */
     }
}


/*----------------------------------------------------------------------
   TtaSetSelector initialise l'entre'e et/ou le texte du se'lecteur : 
   Le parame`tre ref donne la re'fe'rence du catalogue.               
   Le parame`tre entry positif ou nul donne l'index de l'entre'e      
   se'lectionne'e.                                                    
   Le parame`tre text donne le texte si entry vaut -1.                
  ----------------------------------------------------------------------*/
#ifdef __STDC__
void                TtaSetSelector (int ref, int entry, char *text)
#else  /* __STDC__ */
void                TtaSetSelector (ref, entry, text)
int                 ref;
int                 entry;
char               *text;

#endif /* __STDC__ */
{
#  ifndef _WINDOWS
   ThotWidget          w;
#  endif /* !_WINDOWS */
   ThotWidget          wt;
   ThotWidget          select;
   struct Cat_Context *catalogue;

   catalogue = CatEntry (ref);
   wt = 0;
   if (catalogue == NULL)
      TtaError (ERR_invalid_reference);
   else if (catalogue->Cat_Widget != 0)
     {
	/* Recupere le widget du selecteur */
	select = (ThotWidget) catalogue->Cat_Entries;
	if (catalogue->Cat_Type != CAT_SELECT)
	  {
	     TtaError (ERR_invalid_reference);
	     return;
	  }

#       ifndef _WINDOWS
	if (!catalogue->Cat_SelectList)
	  {
	     wt = XmSelectionBoxGetChild (select, XmDIALOG_TEXT);
	     /* Si le selecteur est reactif */
	     if (catalogue->Cat_React)
		XtRemoveCallback (wt, XmNvalueChangedCallback, (XtCallbackProc) CallTextChange, catalogue);
	  }
	else if (catalogue->Cat_React)
	   XtRemoveCallback (select, XmNsingleSelectionCallback, (XtCallbackProc) CallList, catalogue);

	if (entry >= 0 && entry < catalogue->Cat_ListLength)
	  {
	     /* Initialise l'entree de la liste */
	     if (catalogue->Cat_SelectList)
		XmListSelectPos (select, entry + 1, TRUE);
	     else
	       {
		  w = XmSelectionBoxGetChild (select, XmDIALOG_LIST);
		  XmListSelectPos (w, entry + 1, TRUE);
	       }
	  }
	else if (catalogue->Cat_SelectList)
	   XmListDeselectAllItems (select);
	else
	  {
	     /* Initialise le champ texte */
	     if (catalogue->Cat_ListLength != 0)
	       {
		  /* Deselectionne dans la liste */
		  w = XmSelectionBoxGetChild (select, XmDIALOG_LIST);
		  XmListDeselectAllItems (w);
	       }

	     XmTextSetString (wt, text);
      /*----------------------------------------------------------------------
   lg = strlen(text);
   XmTextSetSelection(wt, lg, lg, 500);
  ----------------------------------------------------------------------*/
	  }

	/* Si le selecteur est reactif */
	if (catalogue->Cat_React)
	   if (catalogue->Cat_SelectList)
	      XtAddCallback (select, XmNsingleSelectionCallback, (XtCallbackProc) CallList, catalogue);
	   else
	      XtAddCallback (wt, XmNvalueChangedCallback, (XtCallbackProc) CallTextChange, catalogue);
#       endif /* _WINDOWS */
     }
}

/*----------------------------------------------------------------------
   TtaNewLabel cre'e un intitule' constant dans un formulaire :       
   Le parame`tre ref donne la re'fe'rence du catalogue.               
   Le parame`tre text donne l'intitule'.                              
  ----------------------------------------------------------------------*/
#ifdef __STDC__
void                TtaNewLabel (int ref, int ref_parent, char *text)
#else  /* __STDC__ */
void                TtaNewLabel (ref, ref_parent, text)
int                 ref;
int                 ref_parent;
char               *text;

#endif /* __STDC__ */
{
#  ifndef _WINDOWS
   Arg                 args[MAX_ARGS];
   XmString            title_string;
   int                 n;
#  else  /* _WINDOWS */
   HDC         hdc ;
   RECT        rect ;
   PAINTSTRUCT ps ;
#  endif /* _WINDOWS */
   int                 i;
   int                 ent;
   int                 rebuilded;
   struct E_List      *adbloc;
   ThotWidget          w;
   struct Cat_Context *catalogue;
   struct Cat_Context *parentCatalogue;

   if (ref == 0)
     {
	TtaError (ERR_invalid_reference);
	return;
     }
#  ifndef _WINDOWS
   title_string = 0;
#  endif /* _WINDOWS */
   catalogue = CatEntry (ref);
   rebuilded = 0;
   if (catalogue == NULL)
      TtaError (ERR_cannot_create_dialogue);
   else if (catalogue->Cat_Widget != 0 && catalogue->Cat_Type == CAT_LABEL)
     {
	/* Modification du catalogue */
	w = catalogue->Cat_Widget;
	/* Regarde si le widget est affiche */
#       ifndef _WINDOWS
	if (XtIsManaged (w))
#       else  /* _WINDOWS */
        if (IsWindowVisible (w))
#       endif /* WINDOWS */
	   rebuilded = 2;
	else
	   rebuilded = 1;
#       ifndef _WINDOWS
	n = 0;
	title_string = XmStringCreateSimple (text);
	XtSetArg (args[n], XmNlabelString, title_string);
	n++;
	XtSetValues (w, args, n);
#       else   /* _WINDOWS */
        hdc = BeginPaint (w, &ps);
        GetClientRect (w, &rect);
        DrawText (hdc, text, -1, &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
        EndPaint (w, &ps);
#       endif 
	/* Faut-il reafficher le widget ? */
	if (rebuilded == 2)
#          ifndef _WINDOWS
	   XtManageChild (w);
#          else  /* _WINDOWS */
           UpdateWindow (w);
#          endif /* _WINDOWS */   
     }
   else
     {
	if (catalogue->Cat_Widget != 0)
	   /* Le catalogue est a reconstruire completement */
	   TtaDestroyDialogue (ref);

/*======================================> Recherche le catalogue parent */
	parentCatalogue = CatEntry (ref_parent);
/*__________________________________ Le catalogue parent n'existe pas __*/
	if (parentCatalogue == NULL)
	  {
	     TtaError (ERR_invalid_parent_dialogue);
	     return;
	  }
	else if (parentCatalogue->Cat_Widget == 0)
	  {
	     TtaError (ERR_invalid_parent_dialogue);
	     return;
	  }
/*_________________________________________ Sous-menu d'un formulaire __*/
	else if ((parentCatalogue->Cat_Type != CAT_FORM)
		 && (parentCatalogue->Cat_Type != CAT_SHEET)
		 && (parentCatalogue->Cat_Type != CAT_DIALOG))
	  {
	     TtaError (ERR_invalid_parent_dialogue);
	     return;
	  }
	else if (text == NULL)
	  {
	     TtaError (ERR_invalid_parameter);
	     return;
	  }

	/* Recupere le widget parent */
	w = AddInFormulary (parentCatalogue, &i, &ent, &adbloc);

/*** Cree l'intitule ***/
#       ifndef _WINDOWS
	n = 0;
	title_string = XmStringCreateSimple (text);
	XtSetArg (args[n], XmNfontList, DefaultFont);
	n++;
	XtSetArg (args[n], XmNlabelString, title_string);
	n++;
	XtSetArg (args[n], XmNbackground, BgMenu_Color);
	n++;
	XtSetArg (args[n], XmNforeground, Black_Color);
	n++;
	XtSetArg (args[n], XmNborderColor, Button_Color);
	n++;
	w = XmCreateLabel (w, "Dialogue", args, n);
#       else  /* _WINDOWS */
	if (!isOnlyBlank (text)) {
	   w = CreateWindow ("STATIC", text, WS_CHILD | WS_VISIBLE | SS_LEFT, 10, cyValue, 100, 30, 
			     parentCatalogue->Cat_Widget, (HMENU) ref, hInstance, NULL);
	   cyValue += 40;
	}
#       endif /* _WINDOWS */

	catalogue->Cat_Widget = w;
	catalogue->Cat_Ref = ref;
	catalogue->Cat_Type = CAT_LABEL;
	catalogue->Cat_PtParent = parentCatalogue;
	adbloc->E_ThotWidget[ent] = (ThotWidget) (catalogue);
	adbloc->E_Free[ent] = 'N';
	catalogue->Cat_EntryParent = i;
	catalogue->Cat_Entries = NULL;
     }
#  ifndef _WINDOWS
   XmStringFree (title_string);
#  endif /* _WINDOWS */
}

/*----------------------------------------------------------------------
   TtaNewTextForm cre'e une feuille de saisie de texte :              
   Le parame`tre ref donne la re'fe'rence pour l'application.         
   Le parame`tre title donne le titre du catalogue.                   
   Les parame`tres width et height indiquent la taille en caracte`ree 
   de la feuille de saisie de texte.                                  
   Quand le parame`tre react est vrai, tout changement dans la        
   feuille de saisie est imme'diatement signale' a` l'application.    
  ----------------------------------------------------------------------*/
#ifdef __STDC__
void                TtaNewTextForm (int ref, int ref_parent, char *title, int width, int height, boolean react)
#else  /* __STDC__ */
void                TtaNewTextForm (ref, ref_parent, title, width, height, react)
int                 ref;
int                 ref_parent;
char               *title;
int                 width;
int                 height;
boolean             react;

#endif /* __STDC__ */
{
   int                 ent;
   int                 i;
   struct Cat_Context *catalogue;
   struct Cat_Context *parentCatalogue;
   struct E_List      *adbloc;
   ThotWidget          w;
   ThotWidget          row;
#  ifndef _WINDOWS
   Arg                 args[MAX_ARGS];
   XmString            title_string;
   int                 n;
#  endif  /* !_WINDOWS */

   if (ref == 0)
     {
	TtaError (ERR_invalid_reference);
	return;
     }

   catalogue = CatEntry (ref);
   if (catalogue == NULL)
      TtaError (ERR_cannot_create_dialogue);
   else
     {
	catalogue->Cat_React = react;

	/* Faut-il detruire le catalogue precedent ? */
	if (catalogue->Cat_Widget != 0)
	   DestForm (ref);	/* Modification du catalogue */

	/*======================================> Recherche le catalogue parent */
	parentCatalogue = CatEntry (ref_parent);
	/*__________________________________ Le catalogue parent n'existe pas __*/
	if (parentCatalogue == NULL)
	  {
	     TtaError (ERR_invalid_parent_dialogue);
	     return;
	  }
	else if (parentCatalogue->Cat_Widget == 0)
	  {
	     TtaError (ERR_invalid_parent_dialogue);
	     return;
	  }
	/*_______________________ Le catalogue parent n'est pas un formulaire __*/
	else if ((parentCatalogue->Cat_Type != CAT_FORM)
		 && (parentCatalogue->Cat_Type != CAT_SHEET)
		 && (parentCatalogue->Cat_Type != CAT_DIALOG))
	  {
	     TtaError (ERR_invalid_parent_dialogue);
	     return;
	  }
	/*_____________________________________________________________ Sinon __*/
	else
	  {
	     /* Cree a l'interieur Row-Column du formulaire */
	     row = AddInFormulary (parentCatalogue, &i, &ent, &adbloc);
#            ifndef _WINDOWS
	     row = AddInFormulary (parentCatalogue, &i, &ent, &adbloc);
	     n = 0;
	     XtSetArg (args[n], XmNbackground, BgMenu_Color);
	     n++;
	     XtSetArg (args[n], XmNborderColor, Button_Color);
	     n++;
	     XtSetArg (args[n], XmNmarginWidth, 0);
	     n++;
	     XtSetArg (args[n], XmNmarginHeight, 0);
	     n++;
	     XtSetArg (args[n], XmNspacing, 0);
	     n++;
	     row = XmCreateRowColumn (row, "Dialogue", args, n);

	     /*** Cree le titre du sous-menu ***/
	     if (title != NULL)
	       {
		  n = 0;
		  title_string = XmStringCreateSimple (title);
		  XtSetArg (args[n], XmNfontList, DefaultFont);
		  n++;
		  XtSetArg (args[n], XmNlabelString, title_string);
		  n++;
		  XtSetArg (args[n], XmNmarginWidth, 0);
		  n++;
		  XtSetArg (args[n], XmNmarginHeight, 0);
		  n++;
		  XtSetArg (args[n], XmNbackground, BgMenu_Color);
		  n++;
		  XtSetArg (args[n], XmNforeground, Black_Color);
		  n++;
		  XtSetArg (args[n], XmNborderColor, Button_Color);
		  n++;
		  w = XmCreateLabel (row, "Dialogue", args, n);
		  XtManageChild (w);
		  XmStringFree (title_string);
	       }		/*if */

	     /* Cree une feuille de saisie de texte */
	     n = 0;
	     if (width == 0)
		XtSetArg (args[n], XmNcolumns, 10);
	     else
		XtSetArg (args[n], XmNcolumns, width);
	     n++;

	     XtSetArg (args[n], XmNbackground, White_Color);
	     n++;
	     XtSetArg (args[n], XmNforeground, Black_Color);
	     n++;
	     XtSetArg (args[n], XmNborderColor, Button_Color);
	     n++;
	     XtSetArg (args[n], XmNtroughColor, Button_Color);
	     n++;
	     XtSetArg (args[n], XmNfontList, DefaultFont);
	     n++;
	     if (TextTranslations != NULL)
		XtSetArg (args[n], XmNtranslations, TextTranslations);
	     n++;
#            endif /* !_WINDOWS */

	     if (height < 2)
	       {
#                 ifndef _WINDOWS 
		  XtSetArg (args[n], XmNeditMode, XmSINGLE_LINE_EDIT);
		  n++;
		  /*XtSetArg(args[n], XmNscrollVertical, FALSE); n++; */
		  w = XmCreateText (row, "Dialogue", args, n);
#                 else  /* _WINDOWS */
		  w = CreateWindow ("EDIT", "", WS_CHILD | WS_VISIBLE | ES_LEFT | WS_BORDER, 
				    10, cyValue, 200, 30, parentCatalogue->Cat_Widget, (HMENU) ref, hInstance, NULL);
		  cyValue += 40;
#                 endif /* _WINDOWS */
	       }
	     else
	       {
#                 ifndef _WINDOWS 
		  XtSetArg (args[n], XmNeditMode, XmMULTI_LINE_EDIT);
		  n++;
		  XtSetArg (args[n], XmNrows, (short) height);
		  n++;
		  w = XmCreateScrolledText (row, "Dialogue", args, n);
#                 else  /* _WINDOWS */
		  /* Create a multi-line edit windows *
		   * TODO TODO TODO TODO TODO TODO    */
#                 endif /* !_WINDOWS */
	       }
#            ifndef _WINDOWS 
	     XtManageChild (w);
	     /* Si la feuille de saisie est reactive */
	     if (react)
		XtAddCallback (w, XmNvalueChangedCallback, (XtCallbackProc) CallTextChange, catalogue);
#            else  /* _WINDOWS */
	     ShowWindow (w, SW_SHOWNORMAL);
	     UpdateWindow (w);
#            endif /* _WINDOWS */
	     catalogue->Cat_Ref = ref;
	     catalogue->Cat_Type = CAT_TEXT;
	     /* L'entree Cat_Entries contient le numero du widget texte */
	     catalogue->Cat_Entries = (struct E_List *) w;
#            ifndef _WINDOWS
	     catalogue->Cat_Widget = row;
#            else  /* _WINDOWS */
	     catalogue->Cat_Widget = w;
#            endif /* _WINDOWS */
	     catalogue->Cat_PtParent = parentCatalogue;
	     adbloc->E_ThotWidget[ent] = (ThotWidget) catalogue;
	     adbloc->E_Free[ent] = 'N';
	     catalogue->Cat_EntryParent = i;
	  }
     }
}


/*----------------------------------------------------------------------
   TtaSetTextForm initialise une feuille de saisie de texte :         
   Le parame`tre ref donne la re'fe'rence du catalogue.               
   Le parame`tre text donne la valeur initiale.                       
  ----------------------------------------------------------------------*/
#ifdef __STDC__
void                TtaSetTextForm (int ref, char *text)
#else  /* __STDC__ */
void                TtaSetTextForm (ref, text)
int                 ref;
char               *text;

#endif /* __STDC__ */
{
#  ifndef _WINDOWS
   int                 lg;
#  endif  /* !_WINDOWS */
   struct Cat_Context *catalogue;
   ThotWidget          w;

   catalogue = CatEntry (ref);
   if (catalogue == NULL)
      TtaError (ERR_invalid_reference);
   else if (catalogue->Cat_Widget == 0)
      TtaError (ERR_invalid_reference);
   else if (text == NULL)
      TtaError (ERR_invalid_reference);
   else if (catalogue->Cat_Type != CAT_TEXT)
      TtaError (ERR_invalid_reference);
   else
     {
	w = (ThotWidget) catalogue->Cat_Entries;
	/* Si la feuille de saisie est reactive */
#       ifndef _WINDOWS
	if (catalogue->Cat_React)
	   XtRemoveCallback (w, XmNvalueChangedCallback, (XtCallbackProc) CallTextChange, catalogue);

	XmTextSetString (w, text);
	lg = strlen (text);
	XmTextSetSelection (w, lg, lg, 500);

	/* Si la feuille de saisie est reactive */
	if (catalogue->Cat_React)
	   XtAddCallback (w, XmNvalueChangedCallback, (XtCallbackProc) CallTextChange, catalogue);
#       else  /* _WINDOWS */
	SetWindowText (w, text) ;
#       endif /* _WINDOWS */
     }
}


/*----------------------------------------------------------------------
   TtaNewNumberForm cre'e une feuille de saisie de nombre :           
   Le parame`tre ref donne la re'fe'rence pour l'application.         
   Le parame`tre ref_parent identifie le formulaire pe`re.            
   Le parame`tre title donne le titre du catalogue.                   
   Les parame`tres min et max fixent les bornes valides du nombre.    
   Quand le parame`tre react est vrai, tout changement dans           
   la feuille de saisie est imme'diatement signale' a` l'application. 
  ----------------------------------------------------------------------*/
#ifdef __STDC__
void                TtaNewNumberForm (int ref, int ref_parent, char *title, int min, int max, boolean react)
#else  /* __STDC__ */
void                TtaNewNumberForm (ref, ref_parent, title, min, max, react)
int                 ref;
int                 ref_parent;
char               *title;
int                 min;
int                 max;
boolean             react;

#endif /* __STDC__ */
{
#  ifndef _WINDOWS
   int                 ent;
   int                 n;
   int                 i;
   struct Cat_Context *catalogue;
   struct Cat_Context *parentCatalogue;
   struct E_List      *adbloc;
   Arg                 args[MAX_ARGS];
   ThotWidget          w;
   ThotWidget          row;
   XmString            title_string;
   char                bounds[100];

   if (ref == 0)
     {
	TtaError (ERR_invalid_reference);
	return;
     }

   catalogue = CatEntry (ref);
   if (catalogue == NULL)
      TtaError (ERR_cannot_create_dialogue);
   else
     {
	catalogue->Cat_React = react;

	/* Faut-il detruire le catalogue precedent ? */
	if (catalogue->Cat_Widget != 0)
	   DestForm (ref);	/* Modification du catalogue */

	/*======================================> Recherche le catalogue parent */
	parentCatalogue = CatEntry (ref_parent);
	/*__________________________________ Le catalogue parent n'existe pas __*/
	if (parentCatalogue == NULL)
	  {
	     TtaError (ERR_invalid_parent_dialogue);
	     return;
	  }
	else if (parentCatalogue->Cat_Widget == 0)
	  {
	     TtaError (ERR_invalid_parent_dialogue);
	     return;
	  }
	/*_______________________ Le catalogue parent n'est pas un formulaire __*/
	else if ((parentCatalogue->Cat_Type != CAT_FORM)
		 && (parentCatalogue->Cat_Type != CAT_SHEET)
		 && (parentCatalogue->Cat_Type != CAT_DIALOG))
	  {
	     TtaError (ERR_invalid_parent_dialogue);
	     return;
	  }
	/*_____________________________________________________________ Sinon __*/
	else
	  {
	     row = AddInFormulary (parentCatalogue, &i, &ent, &adbloc);

	     /* Cree a l'interieur Row-Column du formulaire */
	     n = 0;
	     XtSetArg (args[n], XmNbackground, BgMenu_Color);
	     n++;
	     XtSetArg (args[n], XmNborderColor, Button_Color);
	     n++;
	     /*XtSetArg(args[n], XmNpacking, XmPACK_NONE); n++; */
	     XtSetArg (args[n], XmNadjustLast, FALSE);
	     n++;
	     XtSetArg (args[n], XmNmarginWidth, 0);
	     n++;
	     XtSetArg (args[n], XmNmarginHeight, 0);
	     n++;
	     XtSetArg (args[n], XmNspacing, 0);
	     n++;
	     row = XmCreateRowColumn (row, "Dialogue", args, n);
	     catalogue->Cat_Widget = row;
	     catalogue->Cat_PtParent = parentCatalogue;
	     adbloc->E_ThotWidget[ent] = (ThotWidget) catalogue;
	     adbloc->E_Free[ent] = 'N';
	     catalogue->Cat_EntryParent = i;
	     catalogue->Cat_Ref = ref;
	     catalogue->Cat_Type = CAT_INT;

	     /* Alloue un bloc pour ranger les widgets scale et texte */
	     adbloc = NewEList ();
	     catalogue->Cat_Entries = adbloc;

	     /*** Cree le titre du sous-menu ***/
	     if (title != NULL)
	       {
		  n = 0;
		  title_string = XmStringCreateSimple (title);
		  XtSetArg (args[n], XmNlabelString, title_string);
		  n++;
		  XtSetArg (args[n], XmNfontList, DefaultFont);
		  n++;
		  XtSetArg (args[n], XmNmarginWidth, 0);
		  n++;
		  XtSetArg (args[n], XmNmarginHeight, 0);
		  n++;
		  XtSetArg (args[n], XmNbackground, BgMenu_Color);
		  n++;
		  XtSetArg (args[n], XmNforeground, Black_Color);
		  n++;
		  XtSetArg (args[n], XmNborderColor, Button_Color);
		  n++;
		  XtSetArg (args[n], XmNadjustLast, FALSE);
		  n++;
		  w = XmCreateLabel (row, "Dialogue", args, n);
		  XtManageChild (w);
		  n = 0;
		  XtSetArg (args[n], XmNbackground, Button_Color);
		  n++;
		  XtSetArg (args[n], XmNseparatorType, XmSHADOW_ETCHED_OUT);
		  n++;
		  w = XmCreateSeparator (row, "Dialogue", args, n);
		  XtManageChild (w);
		  XmStringFree (title_string);
	       }		/*if */

	     /* Cree une feuille de saisie d'un nombre */
	     if (min < max)
	       {
		  /* Note les bornes de l'echelle */
		  sprintf (bounds, "%d", min);
		  strcat (&bounds[strlen (bounds)], "..");
		  sprintf (&bounds[strlen (bounds)], "%d", max);
		  catalogue->Cat_Entries->E_ThotWidget[2] = (ThotWidget) min;
		  catalogue->Cat_Entries->E_ThotWidget[3] = (ThotWidget) max;
		  ent = max;
	       }
	     else
	       {
		  /* Note les bornes de l'echelle */
		  sprintf (bounds, "%d", max);
		  strcat (&bounds[strlen (bounds)], "..");
		  sprintf (&bounds[strlen (bounds)], "%d", min);
		  catalogue->Cat_Entries->E_ThotWidget[2] = (ThotWidget) max;
		  catalogue->Cat_Entries->E_ThotWidget[3] = (ThotWidget) min;
		  ent = min;
	       }
	     title_string = XmStringCreateSimple (bounds);
	     XtSetArg (args[n], XmNfontList, DefaultFont);
	     n++;
	     XtSetArg (args[n], XmNlabelString, title_string);
	     n++;
	     XtSetArg (args[n], XmNbackground, BgMenu_Color);
	     n++;
	     XtSetArg (args[n], XmNforeground, Black_Color);
	     n++;
	     XtSetArg (args[n], XmNborderColor, Button_Color);
	     n++;
	     w = XmCreateLabel (row, "Dialogue", args, n);
	     XtManageChild (w);
	     XmStringFree (title_string);

	     /* Cree une feuille de saisie annexe */
	     n = 0;
	     XtSetArg (args[n], XmNeditMode, XmSINGLE_LINE_EDIT);
	     n++;
	     XtSetArg (args[n], XmNbackground, White_Color);
	     n++;
	     sprintf (bounds, "%d", min);
	     XtSetArg (args[n], XmNvalue, bounds);
	     n++;
	     if (min < 0)
		i = 1;
	     else
		i = 0;
	     do
	       {
		  ent = ent / 10;
		  i++;
	       }
	     while (ent > 0);
	     XtSetArg (args[n], XmNcolumns, i);
	     n++;
	     XtSetArg (args[n], XmNmaxLength, i + 1);
	     n++;
	     XtSetArg (args[n], XmNfontList, DefaultFont);
	     n++;
	     w = XmCreateText (row, "Dialogue", args, n);
	     XtManageChild (w);
	     XtAddCallback (w, XmNvalueChangedCallback, (XtCallbackProc) CallValueSet, catalogue);
	     catalogue->Cat_Entries->E_ThotWidget[1] = w;
	  }
     }
#  endif /* _WINDOWS */
}


/*----------------------------------------------------------------------
   TtaSetNumberForm fixe le contenu de la feuille de saisie de texte :        
   Le parame`tre ref donne la re'fe'rence du catalogue.               
   Le parame`tre val donne la valeur initiale.                        
  ----------------------------------------------------------------------*/
#ifdef __STDC__
void                TtaSetNumberForm (int ref, int val)
#else  /* __STDC__ */
void                TtaSetNumberForm (ref, val)
int                 ref;
int                 val;

#endif /* __STDC__ */
{
#  ifndef _WINDOWS 
   char                text[10];
   int                 lg;
#  endif /* !_WINDOWS */
   ThotWidget          wtext;
   struct Cat_Context *catalogue;

   catalogue = CatEntry (ref);
   if (catalogue == NULL)
      TtaError (ERR_invalid_reference);
   else if (catalogue->Cat_Widget == 0)
      TtaError (ERR_invalid_reference);
   else
     {
	if (catalogue->Cat_Type != CAT_INT)
	  {
	     TtaError (ERR_invalid_reference);
	     return;
	  }

	/* Est-ce une valeur valide ? */
	if ((val < (int) catalogue->Cat_Entries->E_ThotWidget[2])
	    || (val > (int) catalogue->Cat_Entries->E_ThotWidget[3]))
	  {
	     TtaError (ERR_invalid_reference);
	     return;
	  }

	wtext = catalogue->Cat_Entries->E_ThotWidget[1];

	/* Desactive la procedure de Callback */
#       ifndef _WINDOWS
	XtRemoveCallback (wtext, XmNvalueChangedCallback, (XtCallbackProc) CallValueSet, catalogue);

	sprintf (text, "%d", val);
	XmTextSetString (wtext, text);
	lg = strlen (text);
	XmTextSetSelection (wtext, lg, lg, 500);

	/* Reactive la procedure de Callback */
	XtAddCallback (wtext, XmNvalueChangedCallback, (XtCallbackProc) CallValueSet, catalogue);
#       endif /* _WINDOWS */
     }
}


/*----------------------------------------------------------------------
   TtaSetDialoguePosition me'morise la position actuelle de la souris 
   comme position d'affichage des TtaShowDialogue().               
  ----------------------------------------------------------------------*/
void                TtaSetDialoguePosition ()
{
#  ifndef _WINDOWS
   ThotWindow          wdum;
   int                 xdum;
   int                 ydum;

   /* Enregistre la position courante du curseur pour les futurs show */
   wdum = RootWindow (GDp, DefaultScreen (GDp));
   XQueryPointer (GDp, wdum, &wdum, &wdum, &xdum, &ydum, &ShowX, &ShowY, &xdum);
#  endif /* _WINDOWS */
}


/*----------------------------------------------------------------------
   TtaShowDialogue active le catalogue de'signe.                      
  ----------------------------------------------------------------------*/
#ifdef __STDC__
void                TtaShowDialogue (int ref, boolean remanent)
#else  /* __STDC__ */
void                TtaShowDialogue (ref, remanent)
int                 ref;
boolean             remanent;

#endif /* __STDC__ */
{
   int                 n;
#  ifndef _WINDOWS
   Arg                 args[MAX_ARGS];
#  else  /* _WINDOWS */
   POINT               curPoint;
#  endif /* _WINDOWS */

   ThotWidget          w;
   struct Cat_Context *catalogue;

   if (ref == 0)
     {
	TtaError (ERR_invalid_reference);
	return;
     }

   catalogue = CatEntry (ref);
   if (catalogue == NULL)
     {
	TtaError (ERR_invalid_reference);
	return;
     }
   else
      w = catalogue->Cat_Widget;

   if (w == 0)
     {
	TtaError (ERR_invalid_reference);
	return;
     }
#  ifndef _WINDOWS
   else if (XtIsManaged (w))
      XMapRaised (GDp, XtWindowOfObject (XtParent (w)));
#  endif /* _WINDOWS */
   /*===========> Active un pop-up menu */
   else if (catalogue->Cat_Type == CAT_POPUP || catalogue->Cat_Type == CAT_PULL)
     {
	/* Faut-il invalider un TtaShowDialogue precedent */
	TtaAbortShowDialogue ();

	/* Memorise qu'un retour sur le catalogue est attendu et */
	/* qu'il peut etre aborte' si et seulement s'il n'est pas remanent */
	if (!remanent)
	  {
	     ShowReturn = 1;
	     ShowCat = catalogue;
	  }

	/*** Positionne le pop-up a la position courante du show ***/
	n = 0;
#       ifndef _WINDOWS
	XtSetArg (args[n], XmNx, (Position) ShowX);
	n++;
	XtSetArg (args[n], XmNy, (Position) ShowY);
	n++;
	XtSetValues (w, args, n);
	XtManageChild (w);
#       else  /* _WINDOWS */
	if (catalogue->Cat_Type == CAT_POPUP) {
       GetCursorPos (&curPoint);
	   if (!TrackPopupMenu (w,  TPM_LEFTALIGN, curPoint.x, curPoint.y, 0, currentParent, NULL))
		   WinErrorBox (WIN_Main_Wd);
	} else {
          ShowWindow (w, SW_SHOWNORMAL);
          UpdateWindow (w);
    }
#       endif /* _WINDOWS */
     }
   /*===========> Active un formulaire */
   else if (((catalogue->Cat_Type == CAT_FORM)
	     || (catalogue->Cat_Type == CAT_SHEET)
	     || (catalogue->Cat_Type == CAT_DIALOG))
	    && (catalogue->Cat_PtParent == NULL))
     {
	/* Faut-il invalider un TtaShowDialogue precedent */
	TtaAbortShowDialogue ();

	/* Memorise qu'un retour sur le catalogue est attendu et */
	/* qu'il peut etre aborter si et seulement s'il n'est pas remanent */
	if (!remanent)
	  {
	     ShowReturn = 1;
	     ShowCat = catalogue;
	  }

	/* Pour les feuilles de dialogue force le bouton par defaut */
	if (catalogue->Cat_Type == CAT_SHEET
	    || catalogue->Cat_Type == CAT_DIALOG
	    || catalogue->Cat_Type == CAT_FORM)
	  {
#            ifndef _WINDOWS
	     XtSetArg (args[0], XmNdefaultButton, catalogue->Cat_Entries->E_ThotWidget[1]);
	     XtSetValues (w, args, 1);
#            endif /* _WINDOWS */
	  }
	INITform (w, catalogue, NULL);
     }
   else
      TtaError (ERR_invalid_reference);
}


/*----------------------------------------------------------------------
   TtaWaitShowDialogue attends le retour du catalogue affiche par     
   TtaShowDialogue.                                                   
  ----------------------------------------------------------------------*/
void                TtaWaitShowDialogue ()
{
#  ifndef _WINDOWS
   ThotEvent              event;

   /* Un TtaWaitShowDialogue en cours */
   CurrentWait = 1;

   while (ShowReturn == 1)
     {
	TtaFetchOneEvent (&event);
	TtaHandleOneEvent (&event);
     }

   /* Fin de l'attente */
   CurrentWait = 0;
#  endif /* _WINDOWS */
}


/*----------------------------------------------------------------------
   TtaTestWaitShowDialogue retourne Vrai (1) si un TtaWaitShowDialogue        
   est en cours, sinon Faux (0).                                      
  ----------------------------------------------------------------------*/
boolean             TtaTestWaitShowDialogue ()
{
   return (CurrentWait);
}


/*----------------------------------------------------------------------
   TtaAbortShowDialogue abandonne le TtaShowDialogue.                 
  ----------------------------------------------------------------------*/
void                TtaAbortShowDialogue ()
{

   if (ShowReturn == 1)
     {
	/* Debloque l'attente courante */
	ShowReturn = 0;

	/* Invalide le menu ou formulaire courant */
	if (ShowCat != NULL)
	  {
	     if (ShowCat->Cat_Widget != 0)
	       {
#                 ifndef _WINDOWS
		  if (XtIsManaged (ShowCat->Cat_Widget))
		    {
		       /* Traitement particulier des formulaires */
		       if (ShowCat->Cat_Type == CAT_FORM
			   || ShowCat->Cat_Type == CAT_SHEET
			   || ShowCat->Cat_Type == CAT_DIALOG)
			 {
			    XtUnmanageChild (XtParent (ShowCat->Cat_Widget));
			    CallSheet (None, ShowCat, NULL);
			 }
		       else
			  XtUnmanageChild (ShowCat->Cat_Widget);
		    }
#                 endif /* _WINDOWS */
	       }

	  }
     }
}
