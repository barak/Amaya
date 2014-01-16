/*
 *
 *  (c) COPYRIGHT INRIA, 1996.
 *  Please first read the full copyright statement in file COPYRIGHT.
 *
 */
 
/*
 * Messages and printing management.
 */

#include "thot_sys.h"
#include "libmsg.h"
#include "message.h"
#include "constmenu.h"
#include "constmedia.h"
#include "typemedia.h"
#include "language.h"
#include "constmenu.h"
#include "document.h"
#include "dialog.h"
#include "appdialogue.h"
#include "frame.h"
#include "fileaccess.h"
#include "application.h"
#include "print.h"

#undef THOT_EXPORT
#define THOT_EXPORT extern
#include "platform_tv.h"
#include "edit_tv.h"
#include "appdialogue_tv.h"
#include "frame_tv.h"

#include "appli_f.h"
#include "actions_f.h"
#include "applicationapi_f.h"
#include "attrmenu_f.h"
#include "tree_f.h"
#include "browser_f.h"
#include "search_f.h"
#include "searchmenu_f.h"
#include "textcommands_f.h"
#include "config_f.h"
#include "structcreation_f.h"
#include "creationmenu_f.h"
#include "dialogapi_f.h"
#include "views_f.h"
#include "viewapi_f.h"
#include "viewapi_f.h"
#include "thotmsg_f.h"
#include "viewcommands_f.h"
#include "exceptions_f.h"
#include "structmodif_f.h"
#include "presentmenu_f.h"
#include "printmenu_f.h"
#include "structselect_f.h"
#include "selectmenu_f.h"
#include "memory_f.h"
#include "registry_f.h"
#include "docs_f.h"
#include "print_tv.h"

#ifdef _WINDOWS
#ifdef _WIN_PRINT
#include "thotprinter_f.h"
#endif /* _WIN_PRINT */
#endif /* _WINDOWS */

static char         Orientation[MAX_NAME_LENGTH];
static Func         pFuncExportPrintDoc = NULL;
static int          defPaperPrint;
static int          defManualFeed;
static int          defFirstPage;
static int          defLastPage;
static int          defNbCopies;
static int          defReduction;
static int          defPagesPerSheet;
static int          defPaginate;
static int          defPageSize;
static Name         PresSchema;

#ifdef _WINDOWS
#include "win_f.h"

#ifdef __STDC__
extern void PrintDoc (HWND, int, char**, HDC, BOOL, int, char*, char*, HINSTANCE, BOOL);
#else  /* __STDC__ */
extern void PrintDoc ();
#endif /* __STDC__ */

extern int  currentFrame;
extern BOOL buttonCommand;
#endif /* _WINDOWS */


/*----------------------------------------------------------------------
  Print: interface to the Print program.
  ----------------------------------------------------------------------*/
#ifdef __STDC__
static void         Print (char *name, char *dir, char *thotSch, char *thotDoc, char *realName, char *output, int firstPage, int lastPage, int nCopies, int hShift, int vShift, int userOrientation, int reduction, int nbPagesPerSheet, int suppFrame, int manualFeed, int blackAndWhite, int repaginate, char *viewsToPrint, Document document)
#else  /* __STDC__ */
static void         Print (name, dir, thotSch, thotDoc, realName, output, firstPage, lastPage, nCopies, hShift, vShift, userOrientation, reduction, nbPagesPerSheet, suppFrame, manualFeed, blackAndWhite, repaginate, viewsToPrint, document)
char               *name;
char               *dir;
char               *thotSch;
char               *thotDoc;
char               *realName;
char               *output;
int                 firstPage;
int                 lastPage;
int                 nCopies;
int                 hShift;
int                 vShift;
int                 userOrientation;
int                 reduction;
int                 nbPagesPerSheet;
int                 suppFrame;
int                 manualFeed;
int                 blackAndWhite;
int                 repaginate;
char               *viewsToPrint;
Document            document;
#endif /* __STDC__ */
{ 
#  ifdef _WINDOWS
   int                     printArgc = 0;
   char*                   printArgv [100];
   DWORD                   dwNeeded, dwReturned;
   static LPPRINTER_INFO_5 pInfo5;
#  else  /* !_WINDOWS */
   char             cmd[1024];
   int              res;
#  endif /* _WINDOWS */
   int              i, j;
   int              frame;

   /* initialize the print command */

#  ifndef _WINDOWS
   sprintf (cmd, "%s/print", BinariesDirectory);
#  endif /* !_WINDOWS */

   if ((thotSch != NULL) && (thotSch[0] != EOS))
     {
#      ifdef _WINDOWS
	   printArgv [printArgc] = (char*) TtaGetMemory (5);
	   strcpy (printArgv [printArgc], "-sch");
	   printArgc++;
	   printArgv [printArgc] = (char*) TtaGetMemory (strlen (thotSch) + 1);
	   strcpy (printArgv [printArgc], thotSch);
	   printArgc++;
#      else  /* !_WINDOWS */
       strcat (cmd, " -sch ");
       strcat (cmd, thotSch);
#      endif /* _WINDOWS */
     };

   if ((thotDoc != NULL) && (thotDoc[0] != EOS))
     {
#      ifdef _WINDOWS
	   printArgv [printArgc] = (char*) TtaGetMemory (5);
	   strcpy (printArgv [printArgc], "-doc");
	   printArgc++;
	   printArgv [printArgc] = (char*) TtaGetMemory (strlen (thotDoc) + 1);
	   strcpy (printArgv [printArgc], thotDoc);
	   printArgc++;
#      else  /* _WINDOWS */
       strcat (cmd, " -doc ");
       strcat (cmd, thotDoc);
#      endif /* _WINDOWS */
     };

   /* transmit the server name */
   if (servername && servername[0] != EOS)
     { 
#      ifdef _WINDOWS
	   printArgv [printArgc] = (char*) TtaGetMemory (9);
	   strcpy (printArgv [printArgc], "-display");
	   printArgc++;
	   printArgv [printArgc] = (char*) TtaGetMemory (strlen (servername) + 1);
	   strcpy (printArgv [printArgc], servername);
	   printArgc++;
#      else  /* _WINDOWS */
       strcat (cmd, " -display ");
       strcat (cmd, servername);
#      endif /* _WINDOWS */
     }

   /* transmit the document name */
   if (realName)
     { 
#      ifdef _WINDOWS
	   printArgv [printArgc] = (char*) TtaGetMemory (6);
	   strcpy (printArgv [printArgc], "-name");
	   printArgc++;
	   printArgv [printArgc] = (char*) TtaGetMemory (strlen (realName) + 1);
	   strcpy (printArgv [printArgc], realName);
	   printArgc++;
#      else  /* _WINDOWS */
       strcat (cmd, " -name ");
       strcat (cmd, realName);
#      endif /* _WINDOWS */
     }

   /* transmit the orientation (default value is portrait) */
   if (userOrientation != 0)
#      ifdef _WINDOWS
   {
	   printArgv [printArgc] = (char*) TtaGetMemory (11);
       strcpy (printArgv [printArgc], "-landscape");
	   printArgc++;
   }
#      else  /* _WINDOWS */
       strcat (cmd, " -landscape");
#      endif /* _WINDOWS */

   /* transmit the output command */
   if (PaperPrint)
#      ifdef _WINDOWS
   {
	   printArgv [printArgc] = (char*) TtaGetMemory (5);
       strcpy (printArgv [printArgc], "-out");
	   printArgc++;
   }
#      else  /* _WINDOWS */
       strcat (cmd, " -out \"");
#      endif /* _WINDOWS */
   else
#      ifdef _WINDOWS
   {
	   printArgv [printArgc] = (char*) TtaGetMemory (4);
       strcpy (printArgv [printArgc], "-ps");
	   printArgc++;
   }
#      else  /* _WINDOWS */
       strcat (cmd, " -ps \"");
#      endif /* _WINDOWS */

   if (output[0] != EOS)
#      ifdef _WINDOWS
   {
	   printArgv [printArgc] = (char*) TtaGetMemory (strlen (output) + 1);
       strcpy (printArgv [printArgc], output);
	   printArgc++;
   }
#      else  /* _WINDOWS */
       strcat (cmd, output);
#      endif /* _WINDOWS */
   else
#      ifdef _WINDOWS
   {
	   printArgv [printArgc] = (char*) TtaGetMemory (3);
       strcpy (printArgv [printArgc], "lp");
	   printArgc++;
   }
#      else  /* _WINDOWS */
       strcat (cmd, "lp");
   strcat (cmd, "\" ");
#      endif /* _WINDOWS */

   /* transmit visualization of empty boxes (default no) */
   if (suppFrame == 0)
#      ifdef _WINDOWS
   {
	   printArgv [printArgc] = (char*) TtaGetMemory (10);
       strcpy (printArgv [printArgc], "-emptybox");
	   printArgc++;
   }
#      else  /* _WINDOWS */
       strcat (cmd, " -emptybox");
#      endif /* _WINDOWS */

   /* transmit black/white output (default no) */
   if (blackAndWhite != 0)
#      ifdef _WINDOWS
   {
	   printArgv [printArgc] = (char*) TtaGetMemory (4);
       strcpy (printArgv [printArgc], "-bw");
	   printArgc++;
   }
#      else  /* _WINDOWS */
       strcat (cmd, " -bw");
#      endif /* _WINDOWS */

   /* transmit manualfeed (default no) */
   if (manualFeed != 0)
#      ifdef _WINDOWS
   {
	   printArgv [printArgc] = (char*) TtaGetMemory (12);
       strcpy (printArgv [printArgc], "-manualfeed");
	   printArgc++;
   }
#      else  /* _WINDOWS */
       strcat (cmd, " -manualfeed");
#      endif /* _WINDOWS */

   /* transmit repaginate (default no) */
   if (repaginate != 0)
#      ifdef _WINDOWS
   {
	   printArgv [printArgc] = (char*) TtaGetMemory (10);
       strcpy (printArgv [printArgc], "-paginate");
	   printArgc++;
   }
#      else  /* _WINDOWS */
       strcat (cmd, " -paginate");
#      endif /* _WINDOWS */

   /* transmit page format */
#  ifdef _WINDOWS
   printArgv [printArgc] = (char*) TtaGetMemory (strlen (PageSize) + 3);
   sprintf (printArgv [printArgc], "-P%s", PageSize);
   printArgc++;
#  else  /* _WINDOWS */
   strcat (cmd, " -P");
   strcat (cmd, PageSize);
#  endif /* _WINDOWS */

   /* transmit window id */
#  ifndef _WINDOWS 
   i = strlen (cmd);
#  endif /* _WINDOWS */
   if (FrRef[0] != 0)
#     ifdef _WINDOWS
   {
      printArgv [printArgc] = (char*) TtaGetMemory (20);
      sprintf (printArgv [printArgc], "-w%ld", FrRef[0]);
      printArgc++;
   }
#     else  /* _WINDOWS */
      sprintf (&cmd[i], " -w%ld", FrRef[0]);
#     endif /* _WINDOWS */
   else
     {
	frame = 1;
	while (frame <= MAX_FRAME && FrameTable[frame].FrDoc != document)
	  frame++;
	if (frame <= MAX_FRAME)
#     ifdef _WINDOWS
	{
      printArgv [printArgc] = (char*) TtaGetMemory (20);
      sprintf (printArgv [printArgc], "-w%ld", FrRef[frame]);
      printArgc++;
	}
#     else  /* _WINDOWS */
	  sprintf (&cmd[i], " -w%ld", FrRef[frame]);
#     endif /* _WINDOWS */
	else
#     ifdef _WINDOWS
	{
      printArgv [printArgc] = (char*) TtaGetMemory (20);
      sprintf (printArgv [printArgc], "-w%ld", FrRef[0]);
      printArgc++;
	}
#     else  /* _WINDOWS */
	  sprintf (&cmd[i], " -w%ld", FrRef[0]);
#     endif /* _WINDOWS */
     }

   /* transmit values */
#  ifdef _WINDOWS
   printArgv [printArgc] = (char*) TtaGetMemory (6);
   strcpy (printArgv [printArgc], "-npps");
   printArgc++;
   printArgv [printArgc] = (char*) TtaGetMemory (5);
   sprintf (printArgv [printArgc], "%d", nbPagesPerSheet);
   printArgc++;
   printArgv [printArgc] = (char*) TtaGetMemory (7);
   sprintf (printArgv [printArgc], "-F%d", firstPage);
   printArgc++;
   printArgv [printArgc] = (char*) TtaGetMemory (7);
   sprintf (printArgv [printArgc], "-L%d", lastPage);
   printArgc++;
   printArgv [printArgc] = (char*) TtaGetMemory (8);
   sprintf (printArgv [printArgc], "-#%d", nCopies);
   printArgc++;
   printArgv [printArgc] = (char*) TtaGetMemory (7);
   sprintf (printArgv [printArgc], "-H%d", hShift);
   printArgc++;
   printArgv [printArgc] = (char*) TtaGetMemory (7);
   sprintf (printArgv [printArgc], "-V%d", vShift);
   printArgc++;
   printArgv [printArgc] = (char*) TtaGetMemory (7);
   sprintf (printArgv [printArgc], "-%%%d", reduction);
   printArgc++;
#  else  /* _WINDOWS */
   i = strlen (cmd);
   sprintf (&cmd[i], " -npps %d -F%d -L%d -#%d -H%d -V%d -%%%d ", nbPagesPerSheet, firstPage, lastPage, nCopies, hShift, vShift, reduction);
#  endif /* _WINDOWS */

   /* insert the flag -v before each view name */
   i = 0;
#  ifndef _WINDOWS
   j = strlen (cmd);
#  endif /* _WINDOWS */
   /* skip leading spaces */ 
   while(viewsToPrint[i] == ' ')
     i++;
   /* insert the first flag */
   if(viewsToPrint[i] != EOS)
     {
#      ifdef _WINDOWS
       printArgv [printArgc] = (char*) TtaGetMemory (3);
       strcpy (printArgv [printArgc], "-v");
       printArgc++;
#      else  /* _WINDOWS */
       cmd[j++] = '-';
       cmd[j++] = 'v';
       cmd[j++] = ' ';
#      endif /* _WINDOWS */
     }
   /* process from the first view name */

#  ifdef _WINDOWS
   printArgv [printArgc] = (char*) TtaGetMemory (50);
   j = 0;
#  endif /* _WINDOWS */

   while(viewsToPrint[i] != EOS)
     {
        /* copy the character */
#       ifdef _WINDOWS
        if (viewsToPrint[i] != ' ')
           printArgv [printArgc][j++] = viewsToPrint[i];
#       else /* _WINDOWS */
        cmd[j++] = viewsToPrint[i];
#       endif /* _WINDOWS */
        /* is it a space? */
        if(viewsToPrint[i] == ' ')
          {
#           ifdef _WINDOWS
            printArgv [printArgc][j++] = EOS;
			printArgc++;
#           endif /* _WINDOWS */
            /* skip multiple spaces */
            while(viewsToPrint[i+1] == ' ')
              i++;
            /* if it is not the end, insert the flag */
            if(viewsToPrint[i+1] != EOS)
              {
#               ifdef _WINDOWS
                printArgv [printArgc] = (char*) TtaGetMemory (3);
                strcpy (printArgv [printArgc], "-v");
                printArgc++;
                printArgv [printArgc] = (char*) TtaGetMemory (50);
                j = 0;
#               else  /* _WINDOWS */
                cmd[j++] = '-';
                cmd[j++] = 'v';
                cmd[j++] = ' ';
#               endif /* _WINDOWS */
              }
          }
        /* process next char */
        i++;
      }      

   /* transmit the path or source file */
#  ifdef _WINDOWS 
   printArgv [printArgc] = (char*) TtaGetMemory (11);
   strcpy (printArgv [printArgc], "-removedir");
   printArgc++;
   printArgv [printArgc] = (char*) TtaGetMemory (strlen (dir) + strlen (name) + 6);
   sprintf  (printArgv [printArgc], "%s\\%s.PIV", dir, name);
   printArgc++;
   WIN_ReleaseDeviceContext ();
   if (buttonCommand && TtPrinterDC == 0) {
       EnumPrinters (PRINTER_ENUM_LOCAL, NULL, 5, (LPBYTE) "", 0, &dwNeeded, &dwReturned) ;

       // Alloue de l�espace pour le tableau PRINTER_INFO_5
       if (pInfo5)
          HeapFree (GetProcessHeap (), 0, pInfo5) ;

       pInfo5 = (LPPRINTER_INFO_5) HeapAlloc (GetProcessHeap (), HEAP_NO_SERIALIZE, dwNeeded);

       // Enfin, remplit le tableau PRINTER_INFO_5
       if (!pInfo5 || !EnumPrinters (PRINTER_ENUM_LOCAL, NULL, 5, (LPBYTE) pInfo5, dwNeeded, &dwNeeded, &dwReturned))
          MessageBox (FrRef[currentFrame], "No printer available !", NULL, MB_ICONSTOP);      
       else 
           TtPrinterDC = CreateDC (NULL, pInfo5->pPrinterName,  NULL, NULL);
   }

   PrintDoc (FrRef [currentFrame], printArgc, printArgv, TtPrinterDC, TtIsTrueColor, TtWDepth, name, dir, hInstance, buttonCommand);
   if (!IsWindowEnabled (FrRef[currentFrame]))
      EnableWindow (FrRef[currentFrame], TRUE);
   SetFocus (FrRef[currentFrame]);
   for (i = 0; i < printArgc; i++)
       TtaFreeMemory (printArgv [i]);
   if (TtPrinterDC) {
      DeleteDC (TtPrinterDC);
	  TtPrinterDC = (HDC) 0;
   }
#  else /* !_WINDOWS */
   cmd[j] = EOS;
   i = strlen (cmd);

   sprintf (&cmd[i], " -removedir %s/%s.PIV &", dir, name);
   res = system (cmd);
   if (res == -1)
      TtaDisplaySimpleMessage (CONFIRM, LIB, TMSG_ERROR_PS_TRANSLATION);
#  endif /* _WINDOWS */
}


/*----------------------------------------------------------------------
   InitPrintParameters
   initializes the printing parameters.
  ----------------------------------------------------------------------*/
#ifdef __STDC__
void        InitPrintParameters (Document document)
#else  /* __STDC__ */
void        InitPrintParameters (document)
Document document;
#endif /* __STDC__ */
{
   PtrDocument pDoc;
   char               *ptr;
   int                 lg;

   if (document == 0)
     pDoc = 0;
   else
     pDoc = LoadedDocument[document - 1];

   if (ThotLocalActions[T_rprint] == NULL)
     {
       /* Connect printing actions */
       TteConnectAction (T_rprint, (Proc) CallbackPrintmenu);
       /* read DEFAULTPRINTER variable */
       ptr = TtaGetEnvString ("THOTPRINT");
       if (ptr == NULL)
	 strcpy (pPrinter, "");
       else
	 strcpy (pPrinter, ptr);
       PSdir[0] = EOS;
       PrintingDoc = 0;
       defPaperPrint = TRUE;
       defManualFeed = FALSE;
       defFirstPage = 0;
       defLastPage = 999;
       defNbCopies = 1;
       defReduction = 100;
       defPagesPerSheet = 1;
       defPageSize= PP_A4;
       defPaginate = TRUE;
       PresSchema[0] = EOS;
     }

   if (document != PrintingDoc || document == 0)
     {
       /* we are changing the current printed document */
       PrintingDoc = document;
       PaperPrint = defPaperPrint;
       ManualFeed = defManualFeed;
       FirstPage = defFirstPage;
       LastPage = defLastPage;
       NbCopies = defNbCopies;
       Reduction = defReduction;
       PagesPerSheet = defPagesPerSheet;
       Paginate = defPaginate;
       if (defPageSize == PP_A4)
         strcpy(PageSize,"A4");
       else
         strcpy(PageSize,"US");
       if (pDoc != NULL)
	 {
	   if (pDoc->DocDirectory[0] == DIR_SEP)
	     sprintf (PSdir, "%s/%s.ps", pDoc->DocDirectory, pDoc->DocDName);
	   else
	     {
	       ptr = NULL;
	       ptr = TtaGetEnvString ("TMPDIR");
	       if (ptr != NULL && TtaCheckDirectory (ptr))
		 {
		   strcpy(PSdir,ptr);
		   lg = strlen(PSdir);
		   if (PSdir[lg - 1] == DIR_SEP)
		     PSdir[--lg] = EOS;
		 }
	       else
		 {
#                  ifdef _WINDOWS
		   strcpy (PSdir,"C:\\TEMP");
#                  else  /* !_WINDOWS */
		   strcpy (PSdir,"/tmp");
#                  endif /* !_WINDOWS */
		   lg = strlen (PSdir);
		 }
	       sprintf (&PSdir[lg], "/%s.ps", pDoc->DocDName);
	     }
	 }
     }
}

/*----------------------------------------------------------------------
   TtcPrint standard handler for the Print action.  
   Calls TtaPrint to print the current view.
   ----------------------------------------------------------------------*/  
#ifdef __STDC__
void                TtcPrint (Document document, View view)
#else  /* __STDC__ */
void                TtcPrint (document, view)
Document            document;
View                view;

#endif /* __STDC__ */
{
   PathBuffer          viewsToPrint;

   strcpy (viewsToPrint, TtaGetViewName (document, view));
   strcat (viewsToPrint, " ");
   TtaPrint (document, viewsToPrint);
}

/*----------------------------------------------------------------------
   TtaPrint
   interface to the multiview print command.
  ----------------------------------------------------------------------*/
#ifdef __STDC__
void                TtaPrint (Document document, char* viewNames)
#else  /* __STDC__ */
void                TtaPrint (document, viewNames)
Document            document;
char               *viewNames;

#endif /* __STDC__ */
{
   PtrDocument         pDoc;
   PathBuffer          dirName,tmpDirName;
   Name                docName,tmpDocName;
   Name                savePres, newPres;
   ThotPid             pid = ThotPid_get ();
   char               *dirString;
   int                 orientation, lg;
   boolean	       docReadOnly;
   boolean             ok;
#  ifndef _WINDOWS 
   char                cmd[100];
#  endif /* _WINDOWS */

   pDoc = LoadedDocument[document - 1];
   /* prepares the execution of the print command */
   strcpy (savePres, pDoc->DocSSchema->SsDefaultPSchema);
   if (PresSchema[0] != EOS)
     strcpy (newPres, PresSchema);
   else
     ConfigGetPSchemaForPageSize (pDoc->DocSSchema, PageSize, newPres);
     
   if (newPres[0] != EOS)
      strcpy (pDoc->DocSSchema->SsDefaultPSchema, newPres);
   if (ThotLocalActions[T_rextprint]!=NULL && 
       strcmp(pDoc->DocSSchema->SsDefaultPSchema, savePres))
     {
       TtaDisplayMessage(INFO, TtaGetMessage(LIB,TMSG_CHANGE_PSCH), newPres);
     }
   /* recupere le repertoire tmp du registry */
   dirString = NULL;
   dirString = TtaGetEnvString("TMPDIR");
   if (dirString != NULL) 
     { 
       if (!TtaCheckDirectory(dirString))
         {
           TtaDisplayMessage(INFO, TtaGetMessage(LIB,TMSG_MISSING_DIR), dirString);
           return;
         }
       strcpy (tmpDirName, dirString);
       lg = strlen(tmpDirName);
       if (tmpDirName[lg - 1] == DIR_SEP)
         tmpDirName[--lg] = EOS;
     }
   else
     {
#      ifdef _WINDOWS
       strcpy (tmpDirName,"C:\\TEMP");
       lg = 7;
#      else /* !_WINDOWS */
       strcpy (tmpDirName,"/tmp");
       lg = 4;
#      endif /* _WINDOWS */
     }

   sprintf (tmpDocName, "Thot%ld", (long) pid + numOfJobs);
   strcpy(&tmpDirName[lg], DIR_STR);
   strcat(&tmpDirName[lg], tmpDocName);
#ifdef DEBUG
   fprintf (stderr,"printmenu : temp dir %s \n",tmpDirName);
#endif
#  ifdef _WINDOWS
   mkdir (tmpDirName);
#  else /* !_WINDOWS */
   sprintf (cmd, "/bin/mkdir %s\n", tmpDirName);
   system (cmd);
   sprintf (cmd, "chmod +rwx '%s'\n", tmpDirName);
   system (cmd);
#  endif /* _WINDOWS */
   numOfJobs++;

   strncpy (dirName, pDoc->DocDirectory, MAX_PATH);
   strncpy (docName, pDoc->DocDName, MAX_NAME_LENGTH);
   if (pFuncExportPrintDoc !=NULL)
     /* a export procedure is defined */
       ok = (*pFuncExportPrintDoc)(document, tmpDocName, tmpDirName);
   else
     /* standard export */
     {
       docReadOnly = pDoc->DocReadOnly;

       strcpy (pDoc->DocDirectory, tmpDirName);
       strcpy (pDoc->DocDName, tmpDocName);
       pDoc->DocReadOnly = FALSE;

       ok = WriteDocument (pDoc, 5);

       pDoc->DocReadOnly = docReadOnly;
       strncpy (pDoc->DocDirectory, dirName, MAX_PATH);
       strncpy (pDoc->DocDName, docName, MAX_NAME_LENGTH);
     }

   /* searches the paper orientation for the presentation scheme */
   ConfigGetPresentationOption(pDoc->DocSSchema, "orientation", Orientation);
   if (!strcmp (Orientation, "Landscape"))
     orientation = 1;
   else
     orientation = 0;

   /* restores the presentation scheme */
   strcpy (pDoc->DocSSchema->SsDefaultPSchema, savePres);

   /* make an automatic backup */
   if (ok)
     {
	if (PaperPrint)
	   Print (tmpDocName,
		  tmpDirName,
		  pDoc->DocSchemasPath,
		  DocumentPath,
		  docName, pPrinter,
		  FirstPage, LastPage, NbCopies, 
		  0, 0, orientation,
		  Reduction, PagesPerSheet, TRUE,
		  (int) ManualFeed, 0,
		  Paginate,
		  viewNames,
		  document);
	else if (PSdir[0] != EOS)
	     Print (tmpDocName,
		  tmpDirName,
		  pDoc->DocSchemasPath,
		  DocumentPath,
		  docName, PSdir,
		  FirstPage, LastPage, NbCopies,
		  0, 0, orientation,
		  Reduction, PagesPerSheet, TRUE,
		  (int) ManualFeed, 0,
		  Paginate,
		  viewNames,
		  document);
     }
   /* restores the presentation scheme */
   strcpy (pDoc->DocSSchema->SsDefaultPSchema, savePres);
}

/*----------------------------------------------------------------------
  TtaSetPrintExportFunc: Sets a non-standard document export function for printing
  ----------------------------------------------------------------------*/
#ifdef __STDC__
void TtaSetPrintExportFunc (Func exportFunc)
#else /* __STDC__ */
void TtaSetPrintExportFunc (exportFunc)
Func exportFunc;
#endif /*__STDC__ */
{
  pFuncExportPrintDoc = exportFunc;
}

/*----------------------------------------------------------------------
  TtaSetPrintParameter: Sets a print parameter
  ----------------------------------------------------------------------*/
#ifdef __STDC__
void TtaSetPrintParameter (PrintParameter parameter, int value)
#else /* __STDC__ */
void TtaSetPrintParameter (parameter, value)
PrintParameter parameter;
int value;
#endif /*__STDC__ */
{
   if (ThotLocalActions[T_rprint] == NULL)
     /* force the initialization of printing parameters */
     InitPrintParameters (0);

   switch (parameter)
     {
     case PP_FirstPage:
       if (value <0 || value >999)
          TtaError(ERR_invalid_parameter);
       else
	 FirstPage = value;
       break;
     case PP_LastPage:
       if (value <0 || value >999)
	 TtaError(ERR_invalid_parameter);
       else
	 LastPage = value;
       break;
     case PP_Scale:
       if (value <0 || value >999)
	 TtaError(ERR_invalid_parameter);
       else
	 Reduction = value;
       break;
     case PP_NumberCopies:
       if (value <0 || value >999)
	 TtaError(ERR_invalid_parameter);
       else
	 NbCopies = value;
       break;
     case PP_Paginate:
       if (value == PP_ON)
	 Paginate = TRUE;
       else if (value == PP_OFF)
	 Paginate = FALSE;
       else
	 TtaError(ERR_invalid_parameter);
       break;
     case PP_ManualFeed:
       if(value == PP_ON)
	 ManualFeed = TRUE;
       else if (value == PP_OFF)
	 ManualFeed = FALSE;
       else
	 TtaError(ERR_invalid_parameter);
       break;
     case PP_PagesPerSheet:
       if (value != 1 || value != 2 || value != 4)
	 TtaError(ERR_invalid_parameter);
       else
	 PagesPerSheet = value;
       break;
     case PP_PaperSize:
       if (value == PP_A4)
	 strcpy (PageSize, "A4");
       else if (value == PP_US)
	 strcpy (PageSize, "US");
       else
	 TtaError(ERR_invalid_parameter);
       break;
     case PP_Destination:
       if (value == PP_PRINTER)
	 PaperPrint = TRUE;
       else if (value == PP_PS)
	 PaperPrint = FALSE;
       else
	 TtaError(ERR_invalid_parameter);
       break;
      default:
       TtaError(ERR_invalid_parameter);
     }
}


/*----------------------------------------------------------------------
  TtaGetPrintParameter: returns a print parameter
  ----------------------------------------------------------------------*/
#ifdef __STDC__
int TtaGetPrintParameter (PrintParameter parameter)
#else /* __STDC__ */
int TtaGetPrintParameter (parameter)
PrintParameter parameter;
int value;
#endif /*__STDC__ */
{
  switch (parameter)
    {
    case PP_FirstPage:
      return (FirstPage);
      break;
    case PP_LastPage:
      return (LastPage);
      break;
    case PP_Scale:
      return (Reduction);
      break;
    case PP_NumberCopies:
      return (NbCopies);
      break;
    case PP_Paginate:
      if (Paginate)
	return (PP_ON);
      else
	return (PP_ON);
      break;
    case PP_ManualFeed:
      if (ManualFeed)
	return (PP_ON);
      else
	return (PP_ON);
      break;
    case PP_PagesPerSheet:
      return (PagesPerSheet);
      break;
    case PP_PaperSize:
      if (!strcmp (PageSize, "A4"))
	return (PP_A4);
      else
	return (PP_US);
      break;
    case PP_Destination:
      if (PaperPrint)
	return (PP_ON);
      else
	return (PP_ON);
      break;
    default:
      TtaError(ERR_invalid_parameter);
      return (0);
    }
}


/*----------------------------------------------------------------------
  TtaSetPrintCommand sets the print command.
  ----------------------------------------------------------------------*/
#ifdef __STDC__
void                TtaSetPrintCommand (char *command)
#else  /* __STDC__ */
void                TtaSetPrintCommand (command)
char *command;
#endif /* __STDC__ */
{
  strcpy (pPrinter, command);
}


/*----------------------------------------------------------------------
  TtaGetPrintCommand returns the print command.
  ----------------------------------------------------------------------*/
#ifdef __STDC__
void                TtaGetPrintCommand (char *command)
#else  /* __STDC__ */
void                TtaGetPrintCommand (command)
char *command;
#endif /* __STDC__ */
{
  if (command == NULL)
    TtaError(ERR_invalid_parameter);
  else
    strcpy (command, pPrinter);
}


/*----------------------------------------------------------------------
  TtaSetPrintSchema fixes the printing schema.
  ----------------------------------------------------------------------*/
#ifdef __STDC__
void                TtaSetPrintSchema (char *name)
#else  /* __STDC__ */
void                TtaSetPrintSchema (name)
char *name;
#endif /* __STDC__ */
{
  if (strlen(name) >= MAX_NAME_LENGTH)
    TtaError(ERR_invalid_parameter);
  else
    strcpy (PresSchema, name);
}


/*----------------------------------------------------------------------
  TtaSetPrintCommand sets the path of ps file.
  ----------------------------------------------------------------------*/
#ifdef __STDC__
void                TtaSetPsFile (char *path)
#else  /* __STDC__ */
void                TtaSetPsFile (path)
char *command;
#endif /* __STDC__ */
{
  strcpy (PSdir, path);
}


/*----------------------------------------------------------------------
  TtaGetPsFile returns the path of ps file.
  ----------------------------------------------------------------------*/
#ifdef __STDC__
void                TtaGetPsFile (char *path)
#else  /* __STDC__ */
void                TtaGetPsFile (/*char *path*/)
char *path;
#endif /* __STDC__ */
{
  if (path == NULL)
    TtaError(ERR_invalid_parameter);
  else
    strcpy (path, PSdir);
}


/*----------------------------------------------------------------------
  CallbackPrintmenu
  callback associated to the PrintSetup form 
  ----------------------------------------------------------------------*/
#ifdef __STDC__
void                CallbackPrintmenu (int ref, int val, char *txt)
#else  /* __STDC__ */
void                CallbackPrintmenu (ref, val, txt)
int                 ref;
int                 val;
char               *txt;

#endif /* __STDC__ */
{
  PtrDocument         pDoc;

  if (PrintingDoc != 0)
    {
      pDoc = LoadedDocument[PrintingDoc - 1];

    if (pDoc->DocSSchema != NULL)
      /* the document to be printed still exists */
      switch (ref)
	{
	case NumMenuSupport:
	  /* paper print/save PostScript submenu */
	  switch (val)
	    {
	    case 0:
	      if (!NewPaperPrint)
		{
		  NewPaperPrint = TRUE;
		  TtaSetTextForm (NumZonePrinterName, pPrinter);
		}
	      break;
	    case 1:
	      if (NewPaperPrint)
		{
		  NewPaperPrint = FALSE;
		  TtaSetTextForm (NumZonePrinterName, PSdir);
		}
	      break;
	    }
	  break;
	case NumMenuPaperFormat:
	  /* page size submenu */
	  switch (val)
	    {
	    case 0:
	      strcpy (PageSize, "A4");
	      break;
	    case 1:
	      strcpy (PageSize, "US");
	      break;
	    }
	  break;
	case NumMenuOptions:
	  switch (val)
	    {
	    case 0:
	      /* Manual feed option */
	      ManualFeed = !ManualFeed;
	      break;
	    case 1:
	      /* Repagination option */
	      Paginate = !Paginate;
	      break;
	    }
	  break;
	case NumZonePrinterName:
	  if (txt[0] != EOS)
	    if (NewPaperPrint)
	      /* text capture zone for the printer name */
	      strncpy (pPrinter, txt, MAX_PATH);
	    else
	      /* text capture zone for the name of the PostScript file */
	      strncpy (PSdir, txt, MAX_PATH);
	  break;
	case NumFormPrint:
	  /* Print form option */
	  TtaDestroyDialogue (NumFormPrint);
	  switch (val)
	    {
	    case 1:
	      /* confirms the paper print option */
	      /* the other options are not taken into account without this
		 confirmation */
	      PaperPrint = NewPaperPrint;
	      if(ThotLocalActions[T_rextprint]!=NULL)
		(*ThotLocalActions[T_rextprint])(ref, val, txt);
	      break;
	    default:
	      break;
	    }
	  break;
	default:
	  if(ThotLocalActions[T_rextprint]!=NULL)
	    (*ThotLocalActions[T_rextprint])(ref, val, txt);
	  break;
	}
    }
}

/*----------------------------------------------------------------------
   TtcPrintSetup
   standard handler for a PrintSetup action.
   Prepares and displays a form.
  ----------------------------------------------------------------------*/
#ifdef __STDC__
void                TtcPrintSetup (Document document, View view)
#else  /* __STDC__ */
void                TtcPrintSetup (document, view)
Document            document;
View                view;

#endif /* __STDC__ */
{
   int              i;
   char             bufMenu[MAX_TXT_LEN];

   if (document == 0)
     return;

   /* Print form */
   InitPrintParameters (document);
   TtaNewSheet (NumFormPrint, TtaGetViewFrame (document, view), 
		TtaGetMessage (LIB, TMSG_LIB_PRINT),
	   1, TtaGetMessage (LIB, TMSG_LIB_CONFIRM), FALSE, 2, 'L', D_CANCEL);
   i = 0;
   sprintf (&bufMenu[i], "%s%s", "B", TtaGetMessage (LIB, TMSG_MANUAL_FEED));
   TtaNewToggleMenu (NumMenuOptions, NumFormPrint,
		TtaGetMessage (LIB, TMSG_OPTIONS), 1, bufMenu, NULL, FALSE);
   if (ManualFeed)
#     ifndef _WINDOWS
      TtaSetToggleMenu (NumMenuOptions, 0, TRUE);
#     endif /* _WINDOWS */

   /* Paper format submenu */
   i = 0;
   sprintf (&bufMenu[i], "%s%s", "B", TtaGetMessage (LIB, TMSG_A4));
   i += strlen (&bufMenu[i]) + 1;
   sprintf (&bufMenu[i], "%s%s", "B", TtaGetMessage (LIB, TMSG_US));
   TtaNewSubmenu (NumMenuPaperFormat, NumFormPrint, 0,
	     TtaGetMessage (LIB, TMSG_PAPER_SIZE), 2, bufMenu, NULL, FALSE);
   if (!strcmp (PageSize, "US"))
      TtaSetMenuForm (NumMenuPaperFormat, 1);
   else
      TtaSetMenuForm (NumMenuPaperFormat, 0);

   /* Print to paper/ Print to file submenu */
   i = 0;
   sprintf (&bufMenu[i], "%s%s", "B", TtaGetMessage (LIB, TMSG_PRINTER));
   i += strlen (&bufMenu[i]) + 1;
   sprintf (&bufMenu[i], "%s%s", "B", TtaGetMessage (LIB, TMSG_PS_FILE));
   TtaNewSubmenu (NumMenuSupport, NumFormPrint, 0,
                  TtaGetMessage (LIB, TMSG_OUTPUT), 2, bufMenu, NULL, TRUE);
   /* text capture zone for the printer name */
   TtaNewTextForm (NumZonePrinterName, NumFormPrint, NULL, 30, 1, FALSE);

   /* initialization of the PaperPrint selector */
   NewPaperPrint = PaperPrint;
   if (PaperPrint)
     {
	TtaSetMenuForm (NumMenuSupport, 0);
	TtaSetTextForm (NumZonePrinterName, pPrinter);
     }
   else
     {
	TtaSetMenuForm (NumMenuSupport, 1);
	TtaSetTextForm (NumZonePrinterName, PSdir);
     }

   /* activates the Print form */
   TtaShowDialogue (NumFormPrint, FALSE);

}

