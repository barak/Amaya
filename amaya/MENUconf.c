/*
 *
 *  (c) COPYRIGHT INRIA and W3C, 1999-2008
 *  Please first read the full copyright statement in file COPYRIGHT.
 *
 */
 
/*
 * MENUconf.c: This module contains all the functions used to handle
 * the configuration menus in Amaya. Each configuration menu (set of options)
 * is associated with the following (let's suppose it's the Network men): 
 * - a menu definition in MENUconf.h
 * - a set of static variables that correspond to the menu options
 * - an initialization function for displaying the menu (NetworkConfMenu).
 *   This function should be exported via f/MENUconf_f.h
 * - a callback function to handle the interaction with the user and the
 *   update of the static variables (NetworkCallbackdialogue)
 * - a function to refresh the menu whenever the static variables change
 *   (RefreshNetworkMenu)
 * - a function to download the current values of the environment variables
 *   into the above static variables (GetNetworkConf) (the environment
 *   variables that describe the menu options)
 * - a function to write the value of the static variables to the 
 *   corresponding environment variables (SetNetworkConf)
 * - a function to download the default values of the environment variables
 *   (GetDefaulNetworkConf)
 *
 * In addition, each menu should be initialized in the InitConfMenu
 * function.
 *
 * Authors: J. Kahan
 * Contributors: I. Vatton colors selection, browsing menu and access keys
 *
 * To do: remove the CACHE_RESTART option from some options, once we write
 * the code that should take it into account.
 */

/* Included headerfiles */

#ifdef _WX
#include "wx/wx.h"
#endif /* _WX */

#define THOT_EXPORT extern
#include "amaya.h"
#include "MENUconf.h"
#include "MENUconf_f.h"
#include "print.h"
#include "fileaccess.h"
#include "HTMLhistory_f.h"
#ifdef _WX
#include "wxdialogapi_f.h"
#endif /* _WX */

#ifdef DAV
#define WEBDAV_EXPORT extern
#include "davlib.h"
#include "davlibUI_f.h"
#endif /* DAV */


#ifdef TEMPLATES
#include "templates.h"
#include "containers.h"
#include "Elemlist.h"
#include "templates_f.h"
#endif  /* TEMPLATES */

/* ======> Preference dialog (contains eache sub dialog into tabs) */
#ifdef _WX
/* Preference dialog (contains eache sub dialog into tabs) */
static int PreferenceBase;
#endif /* _WX */


/* ============> Cache menu options */
static int        CacheBase;
static int        CacheStatus;
static Prop_Cache GProp_Cache;

/* ============> Proxy menu options */
static int        ProxyBase;
static int        ProxyStatus;
static Prop_Proxy GProp_Proxy;

/* ============> General menu options */
static int          GeneralBase;
static Prop_General GProp_General;
#define DEF_SAVE_INTVL 10	/* number of typed characters triggering 
                             automatic saving */

/* ============> Browse menu options */
static int         BrowseBase;
static Prop_Browse GProp_Browse;
#ifndef _WX
static int         CurrentScreen;
#endif /* _WX */
static int         InitOpeningLocation;
static ThotBool    InitLoadImages;
static ThotBool    InitLoadObjects;
static ThotBool    InitLoadCss;
static ThotBool    InitBgImages;
static char        InitScreen[MAX_LENGTH];
#ifndef _WX
static char       *ScreensTxt[]={
  "handheld", "print", "projection", "screen", "tty", "tv"
};
#endif /* _WX */

/* ============> Publish menu options */
static int          PublishBase;
static Prop_Publish GProp_Publish;
static int          SafePutStatus;
static int          CurrentCharset;
static char         NewCharset[MAX_LENGTH];
static char        *CharsetTxt[]={
  "us-ascii", "iso-8859-1", "utf-8"
};

/* ============> Color menu options */
static int        ColorBase;
static Prop_Color GProp_Color;
/* this one should be exported from the thotlib */
extern char  *ColorName (int num);

/* ============> Geometry menu options */
static int      GeometryBase;
static Document GeometryDoc = 0;
static ThotBool S_Geometry = TRUE;
/* common local variables */
static char    s[MAX_LENGTH]; /* general purpose buffer */

/* ============> Annotation menu option */
#ifdef ANNOTATIONS
int      AnnotBase;
static Prop_Annot  GProp_Annot;

#include "annotlib.h"
#include "ANNOTevent_f.h"
#endif /* ANNOTATIONS */

/* ============> WebDAV menu option */
#ifdef DAV
int       DAVBase;
Prop_DAV  GProp_DAV;
#endif /* DAV */

/* ============> Templates menu option */
#ifdef TEMPLATES
int            TemplatesBase;
Prop_Templates GProp_Templates;
#endif /* TEMPLATES */

/* ============> Emails menu option */
int            EmailsBase;
Prop_Emails GProp_Emails;

/* ============> Passwords menu option */
int            PasswordsBase;
Prop_Passwords GProp_Passwords;


#include "HTMLsave_f.h"
#include "init_f.h"
#include "query_f.h"

/*-----------------------------------------------------------------------
  _GetSysUserName
  Gives ptr the value of the system's user name. 
  If succesful, returns TRUE, FALSE otherwise.
  -----------------------------------------------------------------------*/
static ThotBool _GetSysUserName (char *username)
{
#ifdef _WX
  /* TODO : a valider sous UNIX : OK */
  wxString loginname = wxGetUserId();
  if ( !loginname.IsEmpty() )
    {
      sprintf(username,"%s", (const char*)loginname.mb_str(*wxConvCurrent));
      return TRUE;
    }
  else
    {
      return FALSE;
    }
#endif /* _WX */
  return TRUE;
}

/*----------------------------------------------------------------------
  GetEnvString: front end to TtaGetEnvString. If the variable name doesn't
  exist, it sets the value to an empty ("") string
  ----------------------------------------------------------------------*/
static void  GetEnvString (char *name, char  *value)
{
  char   *ptr;

  ptr = TtaGetEnvString (name);
  if (ptr)
    {
      strncpy (value, ptr, MAX_LENGTH);
      value[MAX_LENGTH-1] = EOS;
    }
  else
    value[0] = EOS;
}

/*----------------------------------------------------------------------
  InitAmayaDefEnv
  Initializes the default Amaya options which are not setup by thot.ini file.
  This protects us against a crash due to a user's erasing that file.
  ----------------------------------------------------------------------*/
void InitAmayaDefEnv (void)
{
  char        *ptr;
  char         username[MAX_LENGTH];
  ThotBool     annot_rautoload, annot_rautoload_rst;

  /* browsing editing options */
  ptr = TtaGetEnvString ("THOTDIR");
  if (ptr != NULL)
    {
      strcpy (GProp_General.HomePage, ptr);
      strcat (GProp_General.HomePage, AMAYA_PAGE);
    }
  else
    GProp_General.HomePage[0]  = EOS;
  TtaSetDefEnvString ("HOME_PAGE", GProp_General.HomePage, FALSE);
  GProp_General.HomePage[0] = EOS;
  TtaSetDefEnvString ("EXPORT_CRLF", "no", FALSE);
  TtaSetDefEnvString ("PASTE_LINE_BY_LINE", "yes", FALSE);
  TtaSetDefEnvString ("ENABLE_BG_IMAGES", "yes", FALSE);
  TtaSetDefEnvString ("LOAD_IMAGES", "yes", FALSE);
  TtaSetDefEnvString ("LOAD_OBJECTS", "yes", FALSE);
  TtaSetDefEnvString ("LOAD_CSS", "yes", FALSE);
  TtaSetDefEnvString ("VERIFY_PUBLISH", "no", FALSE);
  TtaSetDefEnvString ("DEFAULTNAME", "Overview.html", FALSE);
  TtaSetDefEnvString ("FontMenuSize", "12", FALSE);
  TtaSetDefEnvString ("ENABLE_DOUBLECLICK", "yes", FALSE);
  /* @@@ */
  TtaGetEnvBoolean ("ENABLE_DOUBLECLICK", &GProp_Browse.DoubleClick);
  /* @@@ */
  TtaSetDefEnvString ("SCREEN_TYPE", "screen", FALSE);
  TtaSetDefEnvString ("THOTPRINT", "lpr", FALSE);
  /* network configuration */
  TtaSetDefEnvString ("ENABLE_XHTML_MIMETYPE", "no", FALSE);
  TtaSetDefEnvString ("SAFE_PUT_REDIRECT", "", FALSE);
  TtaSetDefEnvString ("ENABLE_LOST_UPDATE_CHECK", "no", FALSE);
  TtaSetDefEnvString ("ENABLE_PIPELINING", "yes", FALSE);
  TtaSetDefEnvString ("NET_EVENT_TIMEOUT", "60000", FALSE);
  TtaSetDefEnvString ("PERSIST_CX_TIMEOUT", "60", FALSE);
  TtaSetDefEnvString ("DNS_TIMEOUT", "1800", FALSE);
  TtaSetDefEnvString ("MAX_SOCKET", "32", FALSE);
  TtaSetDefEnvString ("ENABLE_MDA", "yes", FALSE);
  TtaSetDefEnvString ("HTTP_PROXY", "", FALSE);
  TtaSetDefEnvString ("PROXYDOMAIN", "", FALSE);
  TtaSetDefEnvString ("PROXYDOMAIN_IS_ONLYPROXY", "no", FALSE);
  TtaSetDefEnvString ("MAX_CACHE_ENTRY_SIZE", "3", FALSE);
  TtaSetDefEnvString ("CACHE_SIZE", "10", FALSE);
#ifdef _MACOS
  ptr = TtaGetEnvString ("HOME");
  if (ptr)
  {
    sprintf (s, "%s%cLibrary%cCaches", ptr, DIR_SEP, DIR_SEP);
    if (TtaDirExists (s)) 
    {
      sprintf (s, "%s%cLibrary%cCaches%clibwww-cache", ptr, DIR_SEP, DIR_SEP, DIR_SEP);
      TtaSetDefEnvString ("CACHE_DIR", s, FALSE);
    }
    else
      TtaSetDefEnvString ("CACHE_DIR", "", FALSE);
  }
  else
    TtaSetDefEnvString ("CACHE_DIR", "", FALSE);
  TtaSetDefEnvString ("ENABLE_CACHE", "yes", FALSE);
#else /* _MACOS */
  if (TempFileDirectory)
    {
      sprintf (s, "%s%clibwww-cache", TempFileDirectory, DIR_SEP);
      TtaSetDefEnvString ("CACHE_DIR", s, FALSE);
      TtaSetDefEnvString ("ENABLE_CACHE", "yes", FALSE);
    }
  else
    {
      TtaSetDefEnvString ("CACHE_DIR", "", FALSE);
      TtaSetDefEnvString ("ENABLE_CACHE", "yes", FALSE);
    }
#endif /* _MACOS */
  TtaSetDefEnvString ("CACHE_PROTECTED_DOCS", "yes", FALSE);
  TtaSetDefEnvString ("CACHE_DISCONNECTED_MODE", "no", FALSE);
  TtaSetDefEnvString ("CACHE_EXPIRE_IGNORE", "no", FALSE);

  /* annotations */
#ifdef ANNOTATIONS
  TtaSetDefEnvString ("ANNOT_POST_SERVER", "", FALSE);
  TtaSetDefEnvString ("ANNOT_SERVERS", "localhost", FALSE);
  TtaSetDefEnvString ("ANNOT_LAUTOLOAD", "no", FALSE);
  TtaSetDefEnvString ("ANNOT_RAUTOLOAD", "no", FALSE);
  TtaSetDefEnvString ("ANNOT_RAUTOLOAD_RST", "yes", FALSE);
  TtaSetEnvString ("ANNOT_MAIN_INDEX", "annot.index", FALSE);
  /* set up the default annotation user name */
  if (!_GetSysUserName (username))
    username[0] = EOS;
  // set the user name
  TtaSetDefEnvString ("ANNOT_USER", username, FALSE);

  /* reset remote annotations autoload ?*/
  TtaGetEnvBoolean ("ANNOT_RAUTOLOAD_RST", &annot_rautoload_rst);
  TtaGetEnvBoolean ("ANNOT_RAUTOLOAD", &annot_rautoload);
  if (annot_rautoload_rst && annot_rautoload)
    TtaSetEnvBoolean ("ANNOT_RAUTOLOAD", FALSE, TRUE);
#endif /* ANNOTATIONS */

  /* Emails */
  TtaSetDefEnvString ("EMAILS_SMTP_SERVER", "", FALSE);
  TtaSetDefEnvString ("EMAILS_SMTP_PORT", "25", FALSE);
  TtaSetDefEnvString ("EMAILS_FROM_ADDRESS", "", FALSE);
  TtaSetDefEnvString ("EMAILS_LAST_RCPT", "", FALSE);

  /* Passwords */
  TtaSetEnvBoolean ("SAVE_PASSWORDS", TRUE, FALSE);
  
  /* appearance */

  /* Tool panel layout. */
  TtaSetEnvBoolean("ADVANCE_USER_INTERFACE", FALSE, FALSE);
  TtaSetDefEnvString ("TOOLPANEL_LAYOUT", "RIGHT", FALSE);
}

/*----------------------------------------------------------------------
  GetDefEnvToggleBoolean: front end to TtaGetDefEnvBoolean. It takes
  care of switching the toggle button according to the status of the
  variable.
  ----------------------------------------------------------------------*/
static void GetDefEnvToggle (char *name, ThotBool *value, int ref, int entry)
{
  ThotBool old = *value;

  TtaGetDefEnvBoolean (name, value);
  if (*value != old)
    {
      /* change the toggle button state */
#ifdef _GTK
      TtaSetToggleMenu (ref, entry, *value);
#endif /* _GTK */
    }
}

/*----------------------------------------------------------------------
  GetDefEnvString: front end to TtaGetDefEnvString. If the variable name 
  doesn't exist, it sets the value to an empty ("") string
  ----------------------------------------------------------------------*/
static void GetDefEnvString (char *name, char  *value)
{
  char  *ptr;

  ptr = TtaGetDefEnvString (name);
  if (ptr)
    {
      strncpy (value, ptr, MAX_LENGTH);
      value[MAX_LENGTH-1] = EOS;
    }
  else
    value[0] = EOS;
}

/*----------------------------------------------------------------------
  NormalizeDirName
  verifies if dirname finishes with end_path. If this is so, it returns FALSE
  Otherwise, adds end_path to dirname and returns TRUE.
  end_path should begin with a DIR_SEP char 
  ----------------------------------------------------------------------*/
static int NormalizeDirName (char *dirname, const char *end_path)
{
  int           result = 0;
  char         *ptr;
  char         *dir_sep = NULL;

  if (dirname[0] != EOS)
    {
      /* if dirname ends in DIR_SEP, we remove it */
      if (dirname[strlen (dirname) -1] == DIR_SEP)
        {
          dir_sep = strrchr (dirname, DIR_SEP);
          *dir_sep = EOS;
          result = 1;
        }
      ptr = strstr (dirname, end_path);
      if (ptr)
        {
          if (strcasecmp (ptr, end_path))
            /* end_path missing, add it to the parent dir */
            {
              strcat (dirname, end_path);
              result = 1;
            }
        }
      else
        /* no DIR_SEP, so we add the end_path */
        {
          strcat (dirname, end_path);
          result = 1;
        }
    }
  else
    /* empty dirname! */
    result = 1;
  
  return result;
}


/*----------------------------------------------------------------------
  CleanDirSep
  Removes double DIR_SEP strings in a name. Returns TRUE if such
  operation was done.
  ----------------------------------------------------------------------*/
int CleanDirSep (char  *name)
{
  int result = 0;
  int s, d;

  /* remove all double DIR_SEP */
  s = 0;
  d = 0;
  while (name[d] != EOS)
    {
      if (name[d] == DIR_SEP && name[d + 1] == DIR_SEP)
        {
          result = 1;
          d++;
          continue;
        }
      name[s] = name[d];
      s++;
      d++;
    }
  name[s] = EOS;

  return (result);
}

/*----------------------------------------------------------------------
  CleanFirstLastSpace
  Removes the first and last space in a name. Returns TRUE if such
  operation was done.
  Returns 1 if it made any change, 0 otherwise (not boolean).
  ----------------------------------------------------------------------*/
int CleanFirstLastSpace (char  *name)
{
  int result = 0;
  int l, d;

  if (!name ||  *name == EOS)
    return (0);

  /* start by removing the ending spaces */
  l = strlen (name) - 1;
  while (l > 0 && name[l] == ' ')
    l--;
  if (name[l+1] == ' ')
    {
      result = 1;
      name[l+1] = EOS;
    }

  /* now remove the leading spaces */
  l = 0;
  while (name[l] == ' ' && name[l] != EOS)
    l++;
  if (l > 0)
    {
      result = 1;
      d = 0;
      while (name[l] != EOS)
        {
          name[d] = name[l];
          d++;
          l++;
        }
      name[d] = name[l];
    }

  return (result);
}

/*----------------------------------------------------------------------
  RemoveLastDirSep
  Removes the last char of name if it is a DIR_SEP. Return TRUE if it
  does this operation.
  ----------------------------------------------------------------------*/
static int RemoveLastDirSep (char  *name)
{
  int result;
  int last_char;

  result = 0;
  if (name) 
    { 
      last_char = strlen (name) - 1;
      if (name[last_char] == DIR_SEP)
        {
          name[last_char] = EOS;
          result = 1;
        }
    }

  return result;
}


/*********************
 ** Cache configuration menu
 ***********************/
/*----------------------------------------------------------------------
  GetCacheConf
  Makes a copy of the current registry cache values
  ----------------------------------------------------------------------*/
static void GetCacheConf (void)
{
  TtaGetEnvBoolean ("ENABLE_CACHE", &(GProp_Cache.EnableCache));
  TtaGetEnvBoolean ("CACHE_PROTECTED_DOCS", &(GProp_Cache.CacheProtectedDocs));
  TtaGetEnvBoolean ("CACHE_DISCONNECTED_MODE", &(GProp_Cache.CacheDisconnectMode));
  TtaGetEnvBoolean ("CACHE_EXPIRE_IGNORE", &(GProp_Cache.CacheExpireIgnore));
  GetEnvString ("CACHE_DIR", &(GProp_Cache.CacheDirectory[0]));
  TtaGetEnvInt ("CACHE_SIZE", &(GProp_Cache.CacheSize));
  TtaGetEnvInt ("MAX_CACHE_ENTRY_SIZE", &( GProp_Cache.MaxCacheFile));
}

/*----------------------------------------------------------------------
  ValidateCacheConf
  Validates the entries in the Cache nonf menu. If there's an invalid
  entry, we then use the default value. We need this because
  the Windows interface isn't rich enough to do it (e.g., negative numbers
  in the integer entries)
  ----------------------------------------------------------------------*/
static void ValidateCacheConf (void)
{
  int change;

  /* validate the cache dir */
  change = 0;
  change += CleanFirstLastSpace (GProp_Cache.CacheDirectory);
  change += CleanDirSep (GProp_Cache.CacheDirectory);
  /* remove the last DIR_SEP, if we have it */
  change += RemoveLastDirSep (GProp_Cache.CacheDirectory);
  if (GProp_Cache.CacheDirectory[0] == EOS)
    {
      GetDefEnvString ("CACHE_DIR", &(GProp_Cache.CacheDirectory[0]));
      change = 1;
    }

  /* what we do is add a DIR_STRlibwww-cache */
  /* remove the last DIR_SEP, if we have it (twice, to 
     protect against a bad "user" default value */
  change += RemoveLastDirSep (GProp_Cache.CacheDirectory);
  /* n.b., this variable may be empty */

#ifdef _WINDOWS
  change += NormalizeDirName (GProp_Cache.CacheDirectory, "\\libwww-cache");
#else /* _WINDOWS */
  change += NormalizeDirName (GProp_Cache.CacheDirectory, "/libwww-cache");
#endif /* _WINDOWS */

  if (change)
  TtaSetTextForm (CacheBase + mCacheDirectory, GProp_Cache.CacheDirectory);
}

/*----------------------------------------------------------------------
  SetCacheConf
  Updates the registry cache values
  ----------------------------------------------------------------------*/
static void SetCacheConf (void)
{
  TtaSetEnvBoolean ("ENABLE_CACHE", GProp_Cache.EnableCache, TRUE);
  TtaSetEnvBoolean ("CACHE_PROTECTED_DOCS", GProp_Cache.CacheProtectedDocs, TRUE);
  TtaSetEnvBoolean ("CACHE_DISCONNECTED_MODE", GProp_Cache.CacheDisconnectMode, TRUE);
  TtaSetEnvBoolean ("CACHE_EXPIRE_IGNORE", GProp_Cache.CacheExpireIgnore, TRUE);
  TtaSetEnvString ("CACHE_DIR", GProp_Cache.CacheDirectory, TRUE);
  TtaSetEnvInt ("CACHE_SIZE", GProp_Cache.CacheSize, TRUE);
  TtaSetEnvInt ("MAX_CACHE_ENTRY_SIZE",  GProp_Cache.MaxCacheFile, TRUE);

  TtaSaveAppRegistry ();
}

/*----------------------------------------------------------------------
  GetDefaultCacheConf
  Updates the registry cache values and calls the cache functions
  to take into acocunt the changes
  ----------------------------------------------------------------------*/
static void GetDefaultCacheConf ()
{
  /* read the default values */
  GetDefEnvToggle ("ENABLE_CACHE", &(GProp_Cache.EnableCache),
                   CacheBase + mCacheOptions, 0);
  GetDefEnvToggle ("CACHE_PROTECTED_DOCS", &(GProp_Cache.CacheProtectedDocs),
                   CacheBase + mCacheOptions, 1);
  GetDefEnvToggle ("CACHE_DISCONNECTED_MODE", &(GProp_Cache.CacheDisconnectMode),
                   CacheBase + mCacheOptions, 2);
  GetDefEnvToggle ("CACHE_EXPIRE_IGNORE", &(GProp_Cache.CacheExpireIgnore),
                   CacheBase + mCacheOptions, 3);
  GetDefEnvString ("CACHE_DIR", &(GProp_Cache.CacheDirectory[0]));
  TtaGetDefEnvInt ("CACHE_SIZE", &(GProp_Cache.CacheSize));
  TtaGetDefEnvInt ("MAX_CACHE_ENTRY_SIZE", &( GProp_Cache.MaxCacheFile));
}


/*----------------------------------------------------------------------
  CacheCallbackDialog
  callback of the cache configuration menu
  ----------------------------------------------------------------------*/
static void CacheCallbackDialog (int ref, int typedata, char *data)
{
  long int            val;

  if (ref == -1)
    {
      /* removes the cache conf menu */
      TtaDestroyDialogue (CacheBase + CacheMenu);
    }
  else
    {
      /* has the user changed the options? */
      val = (long int) data;
      switch (ref - CacheBase)
        {
        case CacheMenu:
          switch (val) 
            {
            case 0:
              TtaDestroyDialogue (ref);
              break;
            case 1:
              ValidateCacheConf ();
              SetCacheConf ();
              /* force the cache restart because this is a long task to write the code to know if a widget status has changed or not */
              CacheStatus |= AMAYA_CACHE_RESTART;
              libwww_updateNetworkConf (CacheStatus);
              /* reset the status flag */
              CacheStatus = 0;
              break;
            case 2:
              GetDefaultCacheConf ();
              /* always signal this as modified */
              CacheStatus |= AMAYA_CACHE_RESTART;
              break;
            case 3:
              /* @@ docid isn't used! */
              StopAllRequests (1);
              libwww_CleanCache ();
              break;
            default:
              break;
            }
          break;
#ifdef IV
        case mCacheOptions:
          switch (val) 
            {
            case 0:
              CacheStatus |= AMAYA_CACHE_RESTART;
              GProp_Cache.EnableCache = !(GProp_Cache.EnableCache);
              break;
            case 1:
              CacheStatus |= AMAYA_CACHE_RESTART;
              GProp_Cache.CacheProtectedDocs = !(GProp_Cache.CacheProtectedDocs);
              break;
            case 2:
              CacheStatus |= AMAYA_CACHE_RESTART;
              GProp_Cache.CacheDisconnectMode = !(GProp_Cache.CacheDisconnectMode);
              break;
            case 3:
              CacheStatus |= AMAYA_CACHE_RESTART;
              GProp_Cache.CacheExpireIgnore = !(GProp_Cache.CacheExpireIgnore);
              break;
            default:
              break;
            }
          break;
        case mCacheDirectory:
          CacheStatus |= AMAYA_CACHE_RESTART;
          if (data)
            strcpy (GProp_Cache.CacheDirectory, data);
          else
            GProp_Cache.CacheDirectory[0] = EOS;
          break;
        case mCacheSize:
          CacheStatus |= AMAYA_CACHE_RESTART;
          GProp_Cache.CacheSize = val;
          break;
        case mMaxCacheFile:
          CacheStatus |= AMAYA_CACHE_RESTART;
          GProp_Cache.MaxCacheFile = val;
          break;
#endif
        default:
          break;
        }
    }
}

/*----------------------------------------------------------------------
  CacheConfMenu
  Build and display the Conf Menu dialog box and prepare for input.
  ----------------------------------------------------------------------*/
void CacheConfMenu (Document document, View view)
{
  int              i;

  /* Create the dialogue form */
  i = 0;
  strcpy (&s[i], TtaGetMessage (AMAYA, AM_APPLY_BUTTON));
  i += strlen (&s[i]) + 1;
  strcpy (&s[i], TtaGetMessage (AMAYA, AM_DEFAULT_BUTTON));
  i += strlen (&s[i]) + 1;
  strcpy (&s[i], TtaGetMessage (AMAYA, AM_FLUSH_CACHE_BUTTON));
  TtaNewSheet (CacheBase + CacheMenu, 
               TtaGetViewFrame (document, view),
               TtaGetMessage (AMAYA, AM_CACHE_MENU),
               3, s, FALSE, 6, 'L', D_DONE);

  sprintf (s, "B%s%cB%s%cB%s%cB%s",
           TtaGetMessage (AMAYA, AM_ENABLE_CACHE), EOS, 
           TtaGetMessage (AMAYA, AM_CACHE_PROT_DOCS), EOS,
           TtaGetMessage (AMAYA, AM_DISCONNECTED_MODE), EOS,
           TtaGetMessage (AMAYA, AM_IGNORE_EXPIRES));
  TtaNewToggleMenu (CacheBase + mCacheOptions,
                    CacheBase + CacheMenu,
                    NULL,
                    4,
                    s,
                    NULL,
                    TRUE);
  TtaNewTextForm (CacheBase + mCacheDirectory,
                  CacheBase + CacheMenu,
                  TtaGetMessage (AMAYA, AM_CACHE_DIR),
                  40,
                  1,
                  TRUE);
  TtaNewNumberForm (CacheBase + mCacheSize,
                    CacheBase + CacheMenu,
                    TtaGetMessage (AMAYA, AM_CACHE_SIZE),
                    1,
                    100,
                    TRUE);
  TtaNewNumberForm (CacheBase + mMaxCacheFile,
                    CacheBase + CacheMenu,
                    TtaGetMessage (AMAYA, AM_CACHE_ENTRY_SIZE),
                    1,
                    5,
                    TRUE);

  /* reset the modified flag */
  CacheStatus = 0;
  /* load and display the current values */
  GetCacheConf ();
  /* display the menu */
  TtaSetDialoguePosition ();
  TtaShowDialogue (CacheBase + CacheMenu, TRUE);
}


/*********************
 ** Proxy configuration menu
 ***********************/
/*----------------------------------------------------------------------
  GetProxyConf
  Makes a copy of the current registry proxy values
  ----------------------------------------------------------------------*/
static void GetProxyConf (void)
{
  GetEnvString ("HTTP_PROXY", &(GProp_Proxy.HttpProxy[0]));
  GetEnvString ("PROXYDOMAIN", &(GProp_Proxy.ProxyDomain[0]));
  TtaGetEnvBoolean ("PROXYDOMAIN_IS_ONLYPROXY",
                    &(GProp_Proxy.ProxyDomainIsOnlyProxy));
}

/*----------------------------------------------------------------------
  SetProxyConf
  Updates the registry proxy values
  ----------------------------------------------------------------------*/
static void SetProxyConf (void)
{
  TtaSetEnvString ("HTTP_PROXY", GProp_Proxy.HttpProxy, TRUE);
  TtaSetEnvString ("PROXYDOMAIN", GProp_Proxy.ProxyDomain, TRUE);
  TtaSetEnvBoolean ("PROXYDOMAIN_IS_ONLYPROXY",
                    GProp_Proxy.ProxyDomainIsOnlyProxy, TRUE);

  TtaSaveAppRegistry ();
}

/*----------------------------------------------------------------------
  GetDefaultProxyConf
  Updates the registry proxy values and calls the proxy functions
  to take into acocunt the changes
  ----------------------------------------------------------------------*/
static void GetDefaultProxyConf ()
{
  /* read the default values */
  GetDefEnvString ("HTTP_PROXY", &(GProp_Proxy.HttpProxy[0]));
  GetDefEnvString ("PROXYDOMAIN", &(GProp_Proxy.ProxyDomain[0]));
  TtaGetDefEnvBoolean ("PROXYDOMAIN_IS_ONLYPROXY",
                       &(GProp_Proxy.ProxyDomainIsOnlyProxy));
}

/*----------------------------------------------------------------------
  RefreshProxyMenu
  Displays the current registry values in the menu
  ----------------------------------------------------------------------*/
static void RefreshProxyMenu ()
{
  /* set the menu entries to the current values */
  TtaSetTextForm (ProxyBase + mHttpProxy, GProp_Proxy.HttpProxy);
  TtaSetTextForm (ProxyBase + mProxyDomain, GProp_Proxy.ProxyDomain);
  TtaSetMenuForm (ProxyBase + mToggleProxy,GProp_Proxy. ProxyDomainIsOnlyProxy);
}


/*----------------------------------------------------------------------
  ProxyCallbackDialog
  callback of the proxy configuration menu
  ----------------------------------------------------------------------*/
static void ProxyCallbackDialog (int ref, int typedata, char *data)
{
  long int            val;

  if (ref == -1)
    {
      /* removes the proxy conf menu */
      TtaDestroyDialogue (ProxyBase + ProxyMenu);
    }
  else
    {
      /* has the user changed the options? */
      val = (long int) data;
      switch (ref - ProxyBase)
        {
        case ProxyMenu:
          switch (val) 
            {
            case 0:
              TtaDestroyDialogue (ref);
              break;
            case 1:
              SetProxyConf ();
              libwww_updateNetworkConf (ProxyStatus);
              /* reset the status flag */
              ProxyStatus = 0;
              break;
            case 2:
              GetDefaultProxyConf ();
              RefreshProxyMenu ();
              /* always signal this as modified */
              ProxyStatus |= AMAYA_PROXY_RESTART;
              break;
            default:
              break;
            }
          break;
#ifdef IV
        case mHttpProxy:
          ProxyStatus |= AMAYA_PROXY_RESTART;
          if (data)
            strcpy (GProp_Proxy.HttpProxy, data);
          else
            GProp_Proxy.HttpProxy[0] = EOS;
          break;

        case mProxyDomain:
          ProxyStatus |= AMAYA_PROXY_RESTART;
          if (data)
            strcpy (GProp_Proxy.ProxyDomain, data);
          else
            GProp_Proxy.ProxyDomain[0] = EOS;
          break;

        case mToggleProxy:
          ProxyStatus |= AMAYA_PROXY_RESTART;
          switch (val) 
            {
            case 0:
              GProp_Proxy.ProxyDomainIsOnlyProxy = FALSE;
              break;
            case 1:
              GProp_Proxy.ProxyDomainIsOnlyProxy = TRUE;
              break;
            }
          break;
#endif
        default:
          break;
        }
    }
}


/*----------------------------------------------------------------------
  ProxyConfMenu
  Build and display the Conf Menu dialog box and prepare for input.
  ----------------------------------------------------------------------*/
void         ProxyConfMenu (Document document, View view)
{
  int              i;

  /* Create the dialogue form */
  i = 0;
  strcpy (&s[i], TtaGetMessage (AMAYA, AM_APPLY_BUTTON));
  i += strlen (&s[i]) + 1;
  strcpy (&s[i], TtaGetMessage (AMAYA, AM_DEFAULT_BUTTON));

  TtaNewSheet (ProxyBase + ProxyMenu, 
               TtaGetViewFrame (document, view),
               TtaGetMessage (AMAYA, AM_PROXY_MENU),
               2, s, FALSE, 6, 'L', D_DONE);

  TtaNewTextForm (ProxyBase + mHttpProxy,
                  ProxyBase + ProxyMenu,
                  TtaGetMessage (AMAYA, AM_HTTP_PROXY),
                  20,
                  1,
                  TRUE);
  TtaNewTextForm (ProxyBase + mProxyDomain,
                  ProxyBase + ProxyMenu,
                  TtaGetMessage (AMAYA, AM_PROXY_DOMAIN),
                  20,
                  1,
                  TRUE);
  TtaNewLabel (GeneralBase + mProxyDomainInfo, ProxyBase + ProxyMenu,
               TtaGetMessage (AMAYA, AM_PROXY_DOMAIN_INFO));
  sprintf (s, "T%s%cT%s", 
           TtaGetMessage (AMAYA, AM_DONT_PROXY_DOMAIN), EOS,
           TtaGetMessage (AMAYA, AM_ONLY_PROXY_DOMAIN));
  TtaNewSubmenu (ProxyBase + mToggleProxy,
                 ProxyBase + ProxyMenu,
                 0,
                 NULL,
                 2,
                 s,
                 NULL,
                 0 /* no maxlength */,
                 TRUE);

  /* reset the modified flag */
  ProxyStatus = 0;
  /* load and display the current values */
  GetProxyConf ();
  RefreshProxyMenu ();
  /* display the menu */
  TtaSetDialoguePosition ();
  TtaShowDialogue (ProxyBase + ProxyMenu, TRUE);
}


/**********************
 ** General configuration menu
 ***********************/
/*----------------------------------------------------------------------
  GetGeneralConf
  Makes a copy of the current registry General values
  ----------------------------------------------------------------------*/
void GetGeneralConf (void)
{
  char       ptr[MAX_LENGTH];
  int        oldzoom;
  ThotBool   aui = FALSE;

  TtaGetEnvInt ("FontZoom", &(GProp_General.Zoom));
  if (GProp_General.Zoom == 0)
    {
      TtaGetEnvInt ("ZOOM", &oldzoom);
      if (oldzoom == 0)
        GProp_General.Zoom = 100;
      else
        /* old model */
        GProp_General.Zoom = 100 + (oldzoom * 10);
    }
  TtaGetEnvBoolean ("XML_EDIT_MODE", &(GProp_General.XMLEdit));
  TtaGetEnvBoolean ("PASTE_LINE_BY_LINE", &(GProp_General.PasteLineByLine));
  TtaGetEnvInt ("AUTO_SAVE", &AutoSave_Interval);
  GProp_General.S_AutoSave = (AutoSave_Interval > 0);
  TtaGetEnvBoolean ("SHOW_BUTTONS", &(GProp_General.S_Buttons));
  TtaGetEnvBoolean ("SHOW_ADDRESS", &(GProp_General.S_Address));
  TtaGetEnvBoolean ("FONT_ALIASING", &(GProp_General.S_NoAliasing));
  TtaGetEnvBoolean ("ISO_DATE", &(GProp_General.S_DATE));
  TtaGetEnvBoolean ("SHOW_TARGET", &(GProp_General.S_Targets));
  TtaGetEnvBoolean ("INSERT_NBSP", &(GProp_General.S_NBSP));
  TtaGetEnvBoolean ("SHOW_SEQUENCES", &(GProp_General.S_Shortcuts));
  TtaGetEnvBoolean ("SHOW_CONFIRM_CLOSE_TAB", &(GProp_General.WarnCTab));
  TtaGetEnvBoolean ("TIP_OF_THE_DAY_STARTUP", &(GProp_General.ShowTipsStartup));
  GetEnvString ("HOME_PAGE", &(GProp_General.HomePage[0]));
  GetEnvString ("LANG", &(GProp_General.DialogueLang[0]));
  GetEnvString ("ACCESSKEY_MOD", ptr);
  if (!strcmp (ptr, "Alt"))
    GProp_General.AccesskeyMod = 0;
  else if (!strcmp (ptr, "Ctrl"))
    GProp_General.AccesskeyMod = 1;
  else
    GProp_General.AccesskeyMod = 2;
  TtaGetEnvInt ("FontMenuSize", &(GProp_General.FontMenuSize));
  
  /* User interface : */
  TtaGetEnvBoolean("ADVANCE_USER_INTERFACE", &aui);
  if(aui)
      GProp_General.ToolPanelLayout = 2;
  else
    {
      GetEnvString ("TOOLPANEL_LAYOUT", ptr);
      if (!strcmp (ptr, "LEFT"))
        GProp_General.ToolPanelLayout = 0;
      else /* Default = RIGHT (queried by palette)*/
        GProp_General.ToolPanelLayout = 1;
    }
}

/*----------------------------------------------------------------------
  ValidateGeneralConf
  Validates the entries in the General conf menu. If there's an invalid
  entry, we then use the default value. We need this because
  the Windows interface isn't rich enough to do it (e.g., negative numbers
  in the integer entries)
  ----------------------------------------------------------------------*/
void ValidateGeneralConf (void)
{
  int         change;
  char        lang[3];
  char       *ptr;

  /* validate the dialogue language */
  change = 0;
  ptr = TtaGetEnvString ("THOTDIR");
  if (strcmp (GProp_General.DialogueLang, "en-US"))
    {
      change++;
      GProp_General.DialogueLang[2] = EOS;
    }
  strncpy (lang, GProp_General.DialogueLang, 2);
  lang[2] = EOS;
  sprintf (s, "%s%cconfig%c%s-amayamsg", ptr, DIR_SEP, DIR_SEP, lang);
  if (!TtaFileExist (s))
    {
      GetDefEnvString ("LANG", &(GProp_General.DialogueLang[0]));
      change++;
    }
  if (change)
    TtaSetTextForm (GeneralBase + mDialogueLang, GProp_General.DialogueLang);
}

/*----------------------------------------------------------------------
  RecalibrateZoom
  Moves the Zoom setting on all documents to the specified value
  ----------------------------------------------------------------------*/
static void RecalibrateZoom ()
{
  int               zoom;
  int               doc, view;

  /* recalibrate the zoom settings in all the active documents and
     active views */
  for (doc = 1; doc < DocumentTableLength; doc++)
    {
      if (DocumentURLs[doc])
        {
          /* calculate the new zoom for each open view*/
          for (view = 1; view < AMAYA_MAX_VIEW_DOC; view++)
            if (TtaIsViewOpen (doc, view))
              {
                zoom = TtaGetZoom (doc, view);
                TtaSetZoom (doc, view, zoom);
              }
        }
    }
}

/*----------------------------------------------------------------------
  UpdateShowTargets
  Sets the show targets on all documents
  ----------------------------------------------------------------------*/
static void UpdateShowTargets ()
{
  int               visibility;
  int               doc;

  /* recalibrate settings in all the active documents and
     active views */
  for (doc = 1; doc < DocumentTableLength; doc++)
    {
      if (DocumentURLs[doc])
        {
          visibility = TtaGetSensibility (doc, 1);
          if ((visibility == 5 && GProp_General.S_Targets) ||
              (visibility == 4 && !(GProp_General.S_Targets)))
            /* change the status of the document */
            ShowTargets (doc, 1);
        }
    }
}

/*----------------------------------------------------------------------
  SetGeneralConf
  Updates the registry General values and calls the General functions
  to take into account the changes
  ----------------------------------------------------------------------*/
void SetGeneralConf (void)
{
  int         oldVal;
  ThotBool    old;

  TtaGetEnvInt ("FontZoom", &oldVal);
  if (oldVal != GProp_General.Zoom)
    {
      TtaSetEnvInt ("FontZoom", GProp_General.Zoom, TRUE);
      TtaSetFontZoom (GProp_General.Zoom);
      /* recalibrate the zoom settings in all the active documents */
      RecalibrateZoom ();
    }
  TtaSetEnvBoolean ("XML_EDIT_MODE", GProp_General.XMLEdit, TRUE);
  TtaSetEnvBoolean ("PASTE_LINE_BY_LINE", GProp_General.PasteLineByLine, TRUE);
  TtaSetEnvBoolean ("SHOW_CONFIRM_CLOSE_TAB", GProp_General.WarnCTab, TRUE);
  TtaSetEnvBoolean ("TIP_OF_THE_DAY_STARTUP", GProp_General.ShowTipsStartup, TRUE);
  /* wx use its own callbacks and use only the boolean value : S_AutoSave */
  if (GProp_General.S_AutoSave)
    AutoSave_Interval = DEF_SAVE_INTVL;
  else
    AutoSave_Interval = 0;
  TtaGetEnvInt ("AUTO_SAVE", &oldVal);
  if (oldVal != AutoSave_Interval)
    {
      TtaSetEnvInt ("AUTO_SAVE", AutoSave_Interval, TRUE);
      TtaSetDocumentBackUpInterval (AutoSave_Interval);
      GProp_General.S_AutoSave = (AutoSave_Interval > 0);
    }
  /* handling show buttons, address, targets and section numbering */
  TtaGetEnvBoolean ("SHOW_TARGET", &old);
  TtaSetEnvBoolean ("SHOW_TARGET", GProp_General.S_Targets, TRUE);
  if (old != GProp_General.S_Targets)
    UpdateShowTargets ();

  TtaSetEnvBoolean ("SHOW_SEQUENCES", GProp_General.S_Shortcuts, TRUE);

  TtaSetEnvBoolean ("FONT_ALIASING", GProp_General.S_NoAliasing, TRUE);
  TtaSetEnvBoolean ("ISO_DATE", GProp_General.S_DATE, TRUE);

  /* Insert NBSP */
  TtaSetEnvBoolean ("INSERT_NBSP", GProp_General.S_NBSP, TRUE);

  TtaSetEnvString ("HOME_PAGE", GProp_General.HomePage, TRUE);
  TtaSetEnvString ("LANG", GProp_General.DialogueLang, TRUE);
  if (GProp_General.AccesskeyMod == 0)
    TtaSetEnvString ("ACCESSKEY_MOD", "Alt", TRUE);
  else if (GProp_General.AccesskeyMod == 1)
    TtaSetEnvString ("ACCESSKEY_MOD", "Ctrl", TRUE);
  else
    TtaSetEnvString ("ACCESSKEY_MOD", "None", TRUE);
#ifndef _WX
  TtaSetEnvInt ("FontMenuSize", GProp_General.FontMenuSize, TRUE);
#endif /* _WX */

  if(GProp_General.ToolPanelLayout==2)
    TtaSetEnvBoolean("ADVANCE_USER_INTERFACE", TRUE, TRUE);
  else
    {
      TtaSetEnvBoolean("ADVANCE_USER_INTERFACE", FALSE, TRUE);
      if(GProp_General.ToolPanelLayout==0)
        TtaSetEnvString ("TOOLPANEL_LAYOUT", "LEFT", TRUE);
      else
        TtaSetEnvString ("TOOLPANEL_LAYOUT", "RIGHT", TRUE);
    }

  TtaUpdateToolPanelLayout();
  TtaSaveAppRegistry ();
}

/*----------------------------------------------------------------------
  GetDefaultGeneralConf
  Loads the default registry General values
  ----------------------------------------------------------------------*/
void GetDefaultGeneralConf ()
{
  ThotBool   aui = FALSE;
  char       ptr[MAX_LENGTH];

  TtaGetDefEnvInt ("FontZoom", &(GProp_General.Zoom));
  if (GProp_General.Zoom == 0)
    GProp_General.Zoom = 100;
  GetDefEnvToggle ("XML_EDIT_MODE", &(GProp_General.XMLEdit), 
                   GeneralBase + mToggleGeneral, 0);
  GetDefEnvToggle ("PASTE_LINE_BY_LINE", &(GProp_General.PasteLineByLine), 
                   GeneralBase + mToggleGeneral, 0);
  TtaGetDefEnvInt ("AUTO_SAVE", &AutoSave_Interval);
  GProp_General.S_AutoSave = (AutoSave_Interval > 0);
  GetDefEnvToggle ("AUTO_SAVE", &(GProp_General.S_AutoSave),
                   GeneralBase + mToggleGeneral, 1);
  GetDefEnvToggle ("INSERT_NBSP", &(GProp_General.S_NBSP),
                   GeneralBase + mToggleGeneral, 2);
  GetDefEnvToggle ("SHOW_BUTTONS", &(GProp_General.S_Buttons),
                   GeneralBase + mToggleGeneral, 3);
  GetDefEnvToggle ("SHOW_ADDRESS", &(GProp_General.S_Address),
                   GeneralBase + mToggleGeneral, 4);
  GetDefEnvToggle ("SHOW_TARGET", &(GProp_General.S_Targets),
                   GeneralBase + mToggleGeneral, 5);
  GetDefEnvToggle ("ISO_DATE", &(GProp_General.S_DATE),
                   GeneralBase + mToggleGeneral, 6);
  GetDefEnvToggle ("FONT_ALIASING", &(GProp_General.S_NoAliasing),
                   GeneralBase + mToggleGeneral, 7);
#ifdef _MACOS
  GProp_General.S_Shortcuts = FALSE;
#else /* _MACOS */
  GProp_General.S_Shortcuts = TRUE;
#endif /* _MACOS */
  TtaGetDefEnvBoolean ("SHOW_CONFIRM_CLOSE_TAB", &(GProp_General.WarnCTab));
  TtaGetDefEnvBoolean ("TIP_OF_THE_DAY_STARTUP", &(GProp_General.ShowTipsStartup));
  
  GetDefEnvString ("HOME_PAGE", &(GProp_General.HomePage[0]));
  GetDefEnvString ("LANG", &(GProp_General.DialogueLang[0]));
  GetDefEnvString ("ACCESSKEY_MOD", ptr);
  if (!strcmp (ptr, "Alt"))
    GProp_General.AccesskeyMod = 0;
  else if (!strcmp (ptr, "Ctrl"))
    GProp_General.AccesskeyMod = 1;
  else
    GProp_General.AccesskeyMod = 2;
  TtaGetDefEnvInt ("FontMenuSize", &(GProp_General.FontMenuSize));
  
  TtaGetDefEnvBoolean("ADVANCE_USER_INTERFACE", &aui);
  if(aui)
    GProp_General.ToolPanelLayout = 2;
  else
    {
      GetDefEnvString ("TOOLPANEL_LAYOUT", ptr);
      if (!strcmp (ptr, "LEFT"))
        GProp_General.ToolPanelLayout = 0;
      else /* Default = RIGHT (queried by palette)*/
        GProp_General.ToolPanelLayout = 1;
    }
}


/*----------------------------------------------------------------------
  callback of the general menu
  ----------------------------------------------------------------------*/
static void GeneralCallbackDialog (int ref, int typedata, char *data)
{
  long int            val;

  if (ref == -1)
    {
      /* removes the network conf menu */
      TtaDestroyDialogue (GeneralBase + GeneralMenu);
    }
  else
    {
      /* has the user changed the options? */
      val = (long int) data;
      switch (ref - GeneralBase)
        {
        case GeneralMenu:
          switch (val) 
            {
            case 0:
              TtaDestroyDialogue (ref);
              break;
            case 1:
              ValidateGeneralConf ();
              SetGeneralConf ();
              break;
            case 2:
              GetDefaultGeneralConf ();
              break;
            default:
              break;
            }
          break;
#ifdef IV
        case mZoom:
          GProp_General.Zoom = val;
          break;

        case mHomePage:
          if (data)
            strcpy (GProp_General.HomePage, data);
          else
            GProp_General.HomePage[0] = EOS;
          break;

        case mToggleGeneral:
          switch (val) 
            {
            case 0:
              GProp_General.PasteLineByLine = !(GProp_General.PasteLineByLine);
              break;
            case 1:
              GProp_General.S_AutoSave = !(GProp_General.S_AutoSave);
              if (GProp_General.S_AutoSave)
                AutoSave_Interval = DEF_SAVE_INTVL;
              else
                AutoSave_Interval = 0;	      
              break;
            case 2:
              GProp_General.S_NBSP = !(GProp_General.S_NBSP);
              break;
            case 3:
              GProp_General.S_Buttons = !(GProp_General.S_Buttons);
              break;
            case 4:
              GProp_General.S_Address = !(GProp_General.S_Address);
              break;
            case 5:
              GProp_General.S_Targets = !(GProp_General.S_Targets);
              break;
            case 6:
              GProp_General.S_DATE = !(GProp_General.S_DATE);
              break;
            case 7:
              GProp_General.S_NoAliasing = !(GProp_General.S_NoAliasing);
              break;
            case 8:
              GProp_General.S_Shortcuts = !(GProp_General.S_Shortcuts);
              break;
            }
          break;

        case mDialogueLang:
          if (data)
            strcpy (GProp_General.DialogueLang, data);
          else
            GProp_General.DialogueLang[0] = EOS;
          break;
	  
        case mGeneralAccessKey:
          GProp_General.AccesskeyMod = val;
          break;

        case mToolPanelLayout:
          GProp_General.ToolPanelLayout = val;
          break;
#endif
        default:
          break;
        }
    }
}

/*----------------------------------------------------------------------
  GeneralConfMenu
  Build and display the Browsing Editing conf Menu dialog box and prepare 
  for input.
  ----------------------------------------------------------------------*/
void GeneralConfMenu (Document document, View view)
{
  PreferenceMenu( document, view );
}

/**********************
 ** Publishing menu
 ***********************/
/*----------------------------------------------------------------------
  GetPublishConf
  Makes a copy of the current registry Publish values
  ----------------------------------------------------------------------*/
static void GetPublishConf (void)
{
  TtaGetEnvBoolean ("ENABLE_XHTML_MIMETYPE", &(GProp_Publish.UseXHTMLMimeType));
  TtaGetEnvBoolean ("ENABLE_LOST_UPDATE_CHECK", &(GProp_Publish.LostUpdateCheck));
  TtaGetEnvBoolean ("VERIFY_PUBLISH", &(GProp_Publish.VerifyPublish));
  TtaGetEnvBoolean ("EXPORT_CRLF", &(GProp_Publish.ExportCRLF));
  TtaGetEnvBoolean ("GENERATE_MATHPI", &(GProp_Publish.GenerateMathPI));
  TtaGetEnvInt ("EXPORT_LENGTH", &(GProp_Publish.ExportLength));
  GetEnvString ("DEFAULTNAME", &(GProp_Publish.DefaultName[0]));
  GetEnvString ("SAFE_PUT_REDIRECT", &(GProp_Publish.SafePutRedirect[0]));
  GetEnvString ("DOCUMENT_CHARSET", &(GProp_Publish.CharsetType[0]));
}

/*----------------------------------------------------------------------
  SetPublishConf
  Updates the registry Publish values and calls the Publish functions
  to take into account the changes
  ----------------------------------------------------------------------*/
static void SetPublishConf (void)
{
  TtaSetEnvBoolean ("ENABLE_XHTML_MIMETYPE", GProp_Publish.UseXHTMLMimeType, TRUE);
  TtaSetEnvBoolean ("ENABLE_LOST_UPDATE_CHECK", GProp_Publish.LostUpdateCheck, TRUE);
  TtaSetEnvBoolean ("VERIFY_PUBLISH", GProp_Publish.VerifyPublish, TRUE);
  TtaSetEnvBoolean ("EXPORT_CRLF", GProp_Publish.ExportCRLF, TRUE);
  TtaSetEnvBoolean ("GENERATE_MATHPI", GProp_Publish.GenerateMathPI, TRUE);
  TtaSetEnvInt ("EXPORT_LENGTH", GProp_Publish.ExportLength, TRUE);
  TtaSetEnvString ("DEFAULTNAME", GProp_Publish.DefaultName, TRUE);
  TtaSetEnvString ("SAFE_PUT_REDIRECT", GProp_Publish.SafePutRedirect, TRUE);
  TtaSetEnvString ("DOCUMENT_CHARSET", GProp_Publish.CharsetType, TRUE);

  TtaSaveAppRegistry ();
}

/*----------------------------------------------------------------------
  GetDefaultPublishConf
  Loads the default registry Publish values
  ----------------------------------------------------------------------*/
static void GetDefaultPublishConf ()
{
  GetDefEnvToggle ("ENABLE_XHTML_MIMETYPE", &(GProp_Publish.UseXHTMLMimeType), 
                   PublishBase + mTogglePublish, 0);
  GProp_Publish.LostUpdateCheck = FALSE;
  GProp_Publish.VerifyPublish = FALSE;
  GetDefEnvToggle ("EXPORT_CRLF", &(GProp_Publish.ExportCRLF),
                   PublishBase + mTogglePublish, 3);
  GProp_Publish.GenerateMathPI = FALSE;
  TtaSetEnvBoolean ("GENERATE_MATHPI", GProp_Publish.GenerateMathPI, TRUE);
  GProp_Publish.LostUpdateCheck = FALSE;
  TtaSetEnvBoolean ("ENABLE_LOST_UPDATE_CHECK", GProp_Publish.LostUpdateCheck, TRUE);
  TtaGetDefEnvInt ("EXPORT_LENGTH", &(GProp_Publish.ExportLength));
  GetDefEnvString ("DEFAULTNAME", &(GProp_Publish.DefaultName[0]));
  GetDefEnvString ("SAFE_PUT_REDIRECT", &(GProp_Publish.SafePutRedirect[0]));
  GetDefEnvString ("DOCUMENT_CHARSET", &(GProp_Publish.CharsetType[0]));
}


/*----------------------------------------------------------------------
  BuildCharsetSelector
  builds the list allowing to select a default charset (for unix)
  ----------------------------------------------------------------------*/
static void BuildCharsetSelector (void)
{
  int         i, i_default;
  int         nbcharset = sizeof(CharsetTxt) / sizeof(char *);
  int         indx, length;
  char       *entry;
  char        BufMenu[MAX_LENGTH];

  /* recopy the propositions  */
  i_default = -1;
  indx = 0;
  CurrentCharset = -1;
  for (i = 0; i < nbcharset; i++)
    {
      entry = CharsetTxt[i];
      /* keep in mind the current selected entry */
      if (GProp_Publish.CharsetType && !strcasecmp (GProp_Publish.CharsetType, entry))
        CurrentCharset = i;
      if (!strcasecmp (entry, "iso-8859-1"))
        i_default = i;
      length = strlen (entry) + 1;
      if (length + indx < MAX_LENGTH)  
        {
          strcpy (&BufMenu[indx], entry);
          indx += length;
        }
    }

  /* Set the default charset to utf-8 if it doesn't exist */
  if (CurrentCharset == -1)
    CurrentCharset = i_default;

  /* Fill in the charset form  */
  TtaNewSizedSelector (PublishBase + mCharsetSelector, PublishBase + PublishMenu,
                       TtaGetMessage (AMAYA, AM_DEFAULT_CHARSET), nbcharset,
                       ((i < 2) ? (char *)"" : BufMenu), 3, 2, NULL, FALSE, FALSE);
  if (nbcharset)
    TtaSetSelector (PublishBase + mCharsetSelector, CurrentCharset, NULL);
  strcpy (NewCharset, GProp_Publish.CharsetType);
}

/*----------------------------------------------------------------------
  callback of the Publishing menu
  ----------------------------------------------------------------------*/
static void PublishCallbackDialog (int ref, int typedata, char *data)
{
  long int            val;

  if (ref == -1)
    {
      /* removes the network conf menu */
      TtaDestroyDialogue (PublishBase + PublishMenu);
    }
  else
    {
      /* has the user changed the options? */
      val = (long int) data;
      switch (ref - PublishBase)
        {
        case PublishMenu:
          switch (val) 
            {
            case 0:
              TtaDestroyDialogue (ref);
              break;
            case 1:
              strcpy (NewCharset, GProp_Publish.CharsetType);
              /* force SafePut refresh */
              SafePutStatus |= AMAYA_SAFEPUT_RESTART;
              strcpy (GProp_Publish.CharsetType, NewCharset);
              SetPublishConf ();
              libwww_updateNetworkConf (SafePutStatus);
              /* reset the status flag */
              SafePutStatus = 0;
              break;
            case 2:
              GetDefaultPublishConf ();
              BuildCharsetSelector ();
              /* always signal this as modified */
              SafePutStatus |= AMAYA_SAFEPUT_RESTART;
              break;
            default:
              break;
            }
          break;
#ifdef IV
        case mTogglePublish:
          switch (val) 
            {
            case 0:
              GProp_Publish.UseXHTMLMimeType = !(GProp_Publish.UseXHTMLMimeType);
              break;
            case 1:
              GProp_Publish.LostUpdateCheck = !(GProp_Publish.LostUpdateCheck);
              break;
            case 2:
              GProp_Publish.VerifyPublish = !(GProp_Publish.VerifyPublish);
              break;
            }
          break;

        case mExportLength:
          GProp_Publish.ExportLength = val;
          break;

        case mDefaultName:
          if (data)
            strcpy (GProp_Publish.DefaultName, data);
          else
            GProp_Publish.DefaultName[0] = EOS;
          break;

        case mSafePutRedirect:
          if (data)
            strcpy (GProp_Publish.SafePutRedirect, data);
          else
            GProp_Publish.SafePutRedirect[0] = EOS;
          SafePutStatus |= AMAYA_SAFEPUT_RESTART;
          break;

        case mCharsetSelector:
          /* Get the desired charset from the item number */
          strcpy (NewCharset, data);
          break;
#endif  
        default:
          break;
        }
    }
}

/*----------------------------------------------------------------------
  PublishConfMenu
  Build and display the Browsing Editing conf Menu dialog box and prepare 
  for input.
  ----------------------------------------------------------------------*/
void PublishConfMenu (Document document, View view)
{
  int              i;

  /* Create the dialogue form */
  i = 0;
  strcpy (&s[i], TtaGetMessage (AMAYA, AM_APPLY_BUTTON));
  i += strlen (&s[i]) + 1;
  strcpy (&s[i], TtaGetMessage (AMAYA, AM_DEFAULT_BUTTON));

  TtaNewSheet (PublishBase + PublishMenu, 
               TtaGetViewFrame (document, view),
               TtaGetMessage (AMAYA, AM_PUBLISH_MENU),
               2, s, FALSE, 11, 'L', D_DONE);
  sprintf (s, "B%s%cB%s%cB%s", 
           TtaGetMessage (AMAYA, AM_USE_XHTML_MIMETYPE), EOS,
           TtaGetMessage (AMAYA, AM_USE_ETAGS), EOS, 
           TtaGetMessage (AMAYA, AM_VERIFY_PUT));
  /* load the current values */
  GetPublishConf ();
  /* Build the charset selector */
  BuildCharsetSelector ();
  TtaNewToggleMenu (PublishBase + mTogglePublish,
                    PublishBase + PublishMenu,
                    NULL,
                    3,
                    s,
                    NULL,
                    FALSE);
  TtaNewTextForm (PublishBase + mDefaultName,
                  PublishBase + PublishMenu,
                  TtaGetMessage (AMAYA, AM_DEFAULT_NAME),
                  20,
                  1,
                  FALSE);
  TtaNewTextForm (PublishBase + mSafePutRedirect,
                  PublishBase + PublishMenu,
                  TtaGetMessage (AMAYA, AM_SAFE_PUT_REDIRECT),
                  20,
                  1,
                  FALSE);
  /* reset the modified flag */
  SafePutStatus = 0;

  /* display the menu */
  TtaSetDialoguePosition ();
  TtaShowDialogue (PublishBase + PublishMenu, TRUE);
}

/**********************
 ** Emails Menu
 **********************/

/*----------------------------------------------------------------------
  GetEmailsConf
  Makes a copy of the current registry emails values
  ----------------------------------------------------------------------*/
void GetEmailsConf (void)
{
  GetEnvString ("EMAILS_SMTP_SERVER", &(GProp_Emails.serverAddress[0]));
    TtaGetEnvInt ("EMAILS_SMTP_PORT", &(GProp_Emails.serverPort));
    GetEnvString ("EMAILS_FROM_ADDRESS", &(GProp_Emails.fromAddress[0]));
}

/*----------------------------------------------------------------------
  SetEmailsConf
  Updates the registry Emails values and calls the General functions
  to take into account the changes
  ----------------------------------------------------------------------*/
void SetEmailsConf (void)
{
  TtaSetEnvInt ("EMAILS_SMTP_PORT", GProp_Emails.serverPort, TRUE);
  TtaSetEnvString ("EMAILS_SMTP_SERVER", GProp_Emails.serverAddress, TRUE);
  TtaSetEnvString ("EMAILS_FROM_ADDRESS", GProp_Emails.fromAddress, TRUE);
  TtaSaveAppRegistry ();
}

/*----------------------------------------------------------------------
  GetDefaultEmailsConf
  Gets the registry default emails values.
  ----------------------------------------------------------------------*/
void GetDefaultEmailsConf ()
{
  TtaGetDefEnvInt ("EMAILS_SMTP_PORT", &(GProp_Emails.serverPort));
  GetDefEnvString ("EMAILS_SMTP_SERVER", &(GProp_Emails.serverAddress[0]));
  GetDefEnvString ("EMAILS_FROM_ADDRESS", &(GProp_Emails.fromAddress[0]));
}

/*----------------------------------------------------------------------
  EmailsCallbackDialog
  callback of the emails configuration menu
  ----------------------------------------------------------------------*/
static void EmailsCallbackDialog (int ref, int typedata, char *data)
{
  intptr_t  val;
  if (ref==-1)
    {
    }
  else
    {
      val = (intptr_t) data;
      switch (ref - EmailsBase)
        {
        case EmailsMenu:
          switch (val)
            {
            case 0: /* CANCEL */
              TtaDestroyDialogue (ref);
              break;
            case 1: /* OK */
              SetEmailsConf();
              //TtaDestroyDialogue (ref);
              break;
            case 2: /* DEFAULT */
              //GetDefaultEmailsConf();
              break;
            default:
              break;
            }
          break;
        default:
          break;
        }
    }
}


/**********************
 ** Browse menu
 ***********************/
/*----------------------------------------------------------------------
  GetBrowseConf
  Makes a copy of the current registry Browse values
  ----------------------------------------------------------------------*/
void GetBrowseConf (void)
{
  TtaGetEnvInt ("NEW_LOCATION", &(GProp_Browse.OpeningLocation));
  TtaGetEnvBoolean ("LOAD_IMAGES", &(GProp_Browse.LoadImages));
  TtaGetEnvBoolean ("LOAD_OBJECTS", &(GProp_Browse.LoadObjects));
  TtaGetEnvBoolean ("ENABLE_BG_IMAGES", &(GProp_Browse.BgImages));
  TtaGetEnvBoolean ("LOAD_CSS", &(GProp_Browse.LoadCss));
  TtaGetEnvBoolean ("ENABLE_DOUBLECLICK", &(GProp_Browse.DoubleClick));
  TtaGetEnvBoolean ("CHECK_READ_IDS", &(GProp_Browse.WarnIDs));
  GetEnvString ("SCREEN_TYPE", &(GProp_Browse.ScreenType[0]));
  if (GProp_Browse.ScreenType[0] == EOS)
    // no current selection
    strcpy (GProp_Browse.ScreenType, "screen");
  TtaGetEnvInt ("DOUBLECLICKDELAY", &(GProp_Browse.DoubleClickDelay));
  GetEnvString ("ACCEPT_LANGUAGES", &(GProp_Browse.LanNeg[0]));
  TtaGetEnvInt ("MAX_URL_LIST", &(GProp_Browse.MaxURL));
}

/*----------------------------------------------------------------------
  SetBrowseConf
  Updates the registry Browse values and calls the Browse functions
  to take into account the changes
  ----------------------------------------------------------------------*/
void SetBrowseConf (void)
{
  TtaSetEnvInt ("NEW_LOCATION", GProp_Browse.OpeningLocation, TRUE);
  TtaSetEnvBoolean ("LOAD_IMAGES", GProp_Browse.LoadImages, TRUE);
  TtaSetEnvBoolean ("LOAD_OBJECTS", GProp_Browse.LoadObjects, TRUE);
  TtaSetEnvBoolean ("ENABLE_BG_IMAGES", GProp_Browse.BgImages, TRUE);
  TtaSetEnvBoolean ("LOAD_CSS", GProp_Browse.LoadCss, TRUE);
  TtaSetEnvBoolean ("ENABLE_DOUBLECLICK", GProp_Browse.DoubleClick, TRUE);
  /* @@@ */
  TtaGetEnvBoolean ("ENABLE_DOUBLECLICK", &(GProp_Browse.DoubleClick));
  /* @@@ */
  TtaSetEnvBoolean ("CHECK_READ_IDS", GProp_Browse.WarnIDs, TRUE);
  TtaSetEnvString ("SCREEN_TYPE", GProp_Browse.ScreenType, TRUE);
  TtaSetEnvString ("ACCEPT_LANGUAGES", GProp_Browse.LanNeg, TRUE);
  /* change the current settings */
  libwww_updateNetworkConf (AMAYA_LANNEG_RESTART);
  TtaSetEnvInt ("MAX_URL_LIST", GProp_Browse.MaxURL, TRUE);
  TtaSaveAppRegistry ();
}

/*----------------------------------------------------------------------
  ApplyConfigurationChanges
  Updates displayed documents according to current changes.
  ----------------------------------------------------------------------*/
void ApplyConfigurationChanges (void)
{
  DisplayMode       dispMode;
  int               doc;
  
  for (doc = 1; doc < MAX_DOCUMENTS; doc++)
    {
      if (DocumentURLs[doc] &&
          (DocumentTypes[doc] == docHTML ||
           DocumentTypes[doc] == docSVG ||
           DocumentTypes[doc] == docMath))
        {
          dispMode = TtaGetDisplayMode (doc);
          TtaSetDisplayMode (doc, NoComputedDisplay);
          RedisplayDoc (doc);
          TtaSetDisplayMode (doc, dispMode);
        }
    }
}

/*----------------------------------------------------------------------
  GetDefaultBrowseConf
  Loads the default registry Browse values
  ----------------------------------------------------------------------*/
void GetDefaultBrowseConf ()
{
  GetDefEnvToggle ("LOAD_IMAGES", &(GProp_Browse.LoadImages),
                   BrowseBase + mToggleBrowse, 0);
  GetDefEnvToggle ("LOAD_OBJECTS", &(GProp_Browse.LoadObjects),
                   BrowseBase + mToggleBrowse, 1);
  GetDefEnvToggle ("ENABLE_BG_IMAGES", &(GProp_Browse.BgImages),
                   BrowseBase + mToggleBrowse, 2);
  GetDefEnvToggle ("LOAD_CSS", &(GProp_Browse.LoadCss),
                   BrowseBase + mToggleBrowse, 3);
  GetDefEnvToggle ("ENABLE_DOUBLECLICK", &(GProp_Browse.DoubleClick),
                   BrowseBase + mToggleBrowse, 4);
  GetDefEnvString ("SCREEN_TYPE", &(GProp_Browse.ScreenType[0]));
  TtaGetDefEnvInt ("DOUBLECLICKDELAY", &(GProp_Browse.DoubleClickDelay));
  GetDefEnvString ("ACCEPT_LANGUAGES", &(GProp_Browse.LanNeg[0]));
  TtaGetDefEnvBoolean ("CHECK_READ_IDS", &(GProp_Browse.WarnIDs));
  GProp_Browse.OpeningLocation = 1;
  TtaGetDefEnvInt ("MAX_URL_LIST", &(GProp_Browse.MaxURL));
}


/*----------------------------------------------------------------------
  callback of the Browsing menu
  ----------------------------------------------------------------------*/
static void BrowseCallbackDialog (int ref, int typedata, char *data)
{
  long int          val;

  if (ref == -1)
    /* removes the network conf menu */
    TtaDestroyDialogue (BrowseBase + BrowseMenu);
  else
    {
      /* has the user changed the options? */
      val = (long int) data;
      switch (ref - BrowseBase)
        {
        case BrowseMenu:
          switch (val) 
            {

            case 0:
              TtaDestroyDialogue (ref);
              break;

            case 1:
              if (strcmp (GProp_Browse.ScreenType, InitScreen) ||
                  InitOpeningLocation != GProp_Browse.OpeningLocation ||
                  InitLoadImages != GProp_Browse.LoadImages ||
                  InitLoadObjects != GProp_Browse.LoadObjects ||
                  InitBgImages != GProp_Browse.BgImages ||
                  InitLoadCss != GProp_Browse.LoadCss )
                {
                  /* there is almost a change */
                  if (strcmp (GProp_Browse.ScreenType, InitScreen) ||
                      InitLoadImages != GProp_Browse.LoadImages ||
                      InitLoadObjects != GProp_Browse.LoadObjects ||
                      InitBgImages != GProp_Browse.BgImages ||
                      InitLoadCss != GProp_Browse.LoadCss)
                    {
                      /* redisplay documents after these changes */
                      strcpy (InitScreen, GProp_Browse.ScreenType);
                      TtaSetEnvString ("SCREEN_TYPE", InitScreen, TRUE);
                      SetBrowseConf ();
                      ApplyConfigurationChanges ();
                    }
                  else
                    SetBrowseConf ();
                  InitOpeningLocation = GProp_Browse.OpeningLocation;
                  InitLoadImages = GProp_Browse.LoadImages;
                  InitLoadObjects = GProp_Browse.LoadObjects;
                  InitBgImages = GProp_Browse.BgImages;
                  InitLoadCss = GProp_Browse.LoadCss;
                }
              else
                SetBrowseConf ();
              break;

            case 2:
              GetDefaultBrowseConf ();
              break;

            case 3:
              ClearURLList();
              break;

            default:
              break;
            }
          break;
#ifdef IV
        case mToggleBrowse:
          switch (val) 
            {
            case 0:
              GProp_Browse.LoadImages = !(GProp_Browse.LoadImages);
              break;
            case 1:
              GProp_Browse.LoadObjects = !(GProp_Browse.LoadObjects);
              break;
            case 2:
              GProp_Browse.BgImages = !(GProp_Browse.BgImages);
              break;
            case 3:
              GProp_Browse.LoadCss = !(GProp_Browse.LoadCss);
              break;
            case 4:
              GProp_Browse.DoubleClick = !(GProp_Browse.DoubleClick);
              break;
            }
          break;
        case mScreenSelector:
          /* Get the desired screen type from the item number */
          strcpy (GProp_Browse.ScreenType, data);
          break;

        case mLanNeg:
          if (data)
            strcpy (GProp_Browse.LanNeg, data);
          else
            GProp_Browse.LanNeg[0] = EOS;
          break;
#endif
        default:
          break;
        }
    }
}

/*----------------------------------------------------------------------
  BrowseConfMenu
  Build and display the Browsing Editing conf Menu dialog box and prepare 
  for input.
  ----------------------------------------------------------------------*/
void BrowseConfMenu (Document document, View view)
{
  /* reset the modified flag */
  SafePutStatus = 0;
  /* load the current values */
  GetBrowseConf ();
  /* keep initial values to detect an change */
  InitOpeningLocation = GProp_Browse.OpeningLocation;
  InitLoadImages = GProp_Browse.LoadImages;
  InitLoadObjects = GProp_Browse.LoadObjects;
  InitBgImages = GProp_Browse.BgImages;
  InitLoadCss = GProp_Browse.LoadCss;
  strcpy (InitScreen, GProp_Browse.ScreenType);
}


/**********************
 ** Color Menu
 **********************/
/*----------------------------------------------------------------------
  GetColorConf
  Makes a copy of the current registry color values
  ----------------------------------------------------------------------*/
static void GetColorConf (void)
{
  GetEnvString ("ForegroundColor", &(GProp_Color.FgColor[0]));
  GetEnvString ("BackgroundColor", &(GProp_Color.BgColor[0]));
  GetEnvString ("BgSelectColor", &(GProp_Color.BgSelColor[0]));
  GetEnvString ("FgSelectColor", &(GProp_Color.FgSelColor[0]));
  GetEnvString ("MenuFgColor", &(GProp_Color.MenuFgColor[0]));
  GetEnvString ("MenuBgColor", &(GProp_Color.MenuBgColor[0]));
}

/*----------------------------------------------------------------------
  GetDefaultColorConf
  Makes a copy of the default registry color values
  ----------------------------------------------------------------------*/
static void GetDefaultColorConf (void)
{
  GetDefEnvString ("ForegroundColor", &(GProp_Color.FgColor[0]));
  GetDefEnvString ("BackgroundColor", &(GProp_Color.BgColor[0]));
  GetDefEnvString ("BgSelectColor", &(GProp_Color.BgSelColor[0]));
  GetDefEnvString ("FgSelectColor", &(GProp_Color.FgSelColor[0]));
  GetDefEnvString ("MenuFgColor", &(GProp_Color.MenuFgColor[0]));
  GetDefEnvString ("MenuBgColor", &(GProp_Color.MenuBgColor[0]));
}

/*----------------------------------------------------------------------
  SetColorConf
  Updates the registry Color values
  ----------------------------------------------------------------------*/
static void SetColorConf (void)
{
  TtaSetEnvString ("ForegroundColor", GProp_Color.FgColor, TRUE);
  TtaSetEnvString ("BackgroundColor", GProp_Color.BgColor, TRUE);
  TtaSetEnvString ("BgSelectColor", GProp_Color.BgSelColor, TRUE);
  TtaSetEnvString ("FgSelectColor", GProp_Color.FgSelColor, TRUE);
  TtaSetEnvString ("MenuFgColor", GProp_Color.MenuFgColor, TRUE);
  TtaSetEnvString ("MenuBgColor", GProp_Color.MenuBgColor, TRUE);
  TtaSaveAppRegistry ();
  /* change the current settings */
  TtaUpdateEditorColors ();
}

/*----------------------------------------------------------------------
  RefreshColorMenu
  Displays the current registry values in the menu
  ----------------------------------------------------------------------*/
static void RefreshColorMenu ()
{
  TtaSetTextForm (ColorBase + mFgColor, GProp_Color.FgColor);
  TtaSetTextForm (ColorBase + mBgColor, GProp_Color.BgColor);
  TtaSetTextForm (ColorBase + mBgSelColor, GProp_Color.BgSelColor);
  TtaSetTextForm (ColorBase + mFgSelColor, GProp_Color.FgSelColor);
  TtaSetTextForm (ColorBase + mMenuFgColor, GProp_Color.MenuFgColor);
  TtaSetTextForm (ColorBase + mMenuBgColor, GProp_Color.MenuBgColor);
}

/*----------------------------------------------------------------------
  callback of the color configuration menu
  ----------------------------------------------------------------------*/
static void ColorCallbackDialog (int ref, int typedata, char *data)
{
  intptr_t val;

  if (ref == -1)
    {
      /* removes the color conf menu */
      TtaDestroyDialogue (ColorBase + ColorMenu);
    }
  else
    {
      /* has the user changed the options? */
      val = (intptr_t) data;
      switch (ref - ColorBase)
        {
        case ColorMenu:
          switch (val) 
            {
            case 0:
              TtaDestroyDialogue (ref);
              break;
            case 1:
              SetColorConf ();
              break;
            case 2:
              GetDefaultColorConf ();
              RefreshColorMenu ();
              break;
            default:
              break;
            }
          break;
#ifdef IV  
        case mFgColor:
          if (data)
            strcpy (GProp_Color.FgColor, data);
          else
            GProp_Color.FgColor[0] = EOS;
          break;
        case mBgColor:
          if (data)
            strcpy (GProp_Color.BgColor, data);
          else
            GProp_Color.BgColor[0] = EOS;
          break;
        case mBgSelColor:
          if (data)
            strcpy (GProp_Color.BgSelColor, data);
          else
            GProp_Color.BgSelColor[0] = EOS;
          break;
        case mFgSelColor:
          if (data)
            strcpy (GProp_Color.FgSelColor, data);
          else
            GProp_Color.FgSelColor[0] = EOS;
          break;
        case mMenuFgColor:
          if (data)
            strcpy (GProp_Color.MenuFgColor, data);
          else
            GProp_Color.MenuFgColor[0] = EOS;
          break;
        case mMenuBgColor:
          if (data)
            strcpy (GProp_Color.MenuBgColor, data);
          else
            GProp_Color.MenuBgColor[0] = EOS;
          break;
#endif
        default:
          break;
        }
    }
}

/*----------------------------------------------------------------------
  ColorConfMenu
  Build and display the Conf Menu dialog box and prepare for input.
  ----------------------------------------------------------------------*/
void         ColorConfMenu (Document document, View view)
{
  int              i;

  /* Create the dialogue form */
  i = 0;
  strcpy (&s[i], TtaGetMessage (AMAYA, AM_APPLY_BUTTON));
  i += strlen (&s[i]) + 1;
  strcpy (&s[i], TtaGetMessage (AMAYA, AM_DEFAULT_BUTTON));

  TtaNewSheet (ColorBase + ColorMenu, 
               TtaGetViewFrame (document, view),
               TtaGetMessage (LIB, TMSG_COLORS),
               2, s, TRUE, 2, 'L', D_DONE);
  /* first col */
  TtaNewTextForm (ColorBase + mFgColor,
                  ColorBase + ColorMenu,
                  TtaGetMessage (AMAYA, AM_DOC_FG_COLOR),
                  25,
                  1,
                  FALSE);   
  TtaNewTextForm (ColorBase + mBgColor,
                  ColorBase + ColorMenu,
                  TtaGetMessage (AMAYA, AM_DOC_BG_COLOR),
                  25,
                  1,
                  FALSE);   
  /* second col */
  TtaNewTextForm (ColorBase + mFgSelColor,
                  ColorBase + ColorMenu,
                  TtaGetMessage (AMAYA, AM_FG_SEL_COLOR),
                  25,
                  1,
                  FALSE);   
  TtaNewTextForm (ColorBase + mBgSelColor,
                  ColorBase + ColorMenu,
                  TtaGetMessage (AMAYA, AM_BG_SEL_COLOR),
                  25,
                  1,
                  FALSE);   
  /* third col */
  TtaNewTextForm (ColorBase + mMenuFgColor,
                  ColorBase + ColorMenu,
                  TtaGetMessage (AMAYA, AM_MENU_FG_COLOR),
                  25,
                  1,
                  FALSE);   
  TtaNewTextForm (ColorBase + mMenuBgColor,
                  ColorBase + ColorMenu,
                  TtaGetMessage (AMAYA, AM_MENU_BG_COLOR),
                  25,
                  1,
                  FALSE);

  TtaNewLabel (ColorBase + mColorEmpty1, ColorBase + ColorMenu,
               TtaGetMessage (AMAYA, AM_GEOMETRY_CHANGE));
 
  /* load and display the current values */
  GetColorConf ();
  RefreshColorMenu ();
  /* display the menu */
  TtaSetDialoguePosition ();
  TtaShowDialogue (ColorBase + ColorMenu, TRUE);
}


/**********************
 ** Geometry Menu
 **********************/
/*----------------------------------------------------------------------
  RestoreDefEnvGeom
  Restores the default integer geometry values that are stored in a 
  registry entry under the form "x y w h"
  ----------------------------------------------------------------------*/
static void RestoreDefEnvGeom (char *env_var, Document doc)
{
  /* in order to read the default values from HTML.conf, we erase the 
     registry entry */
  TtaClearEnvString (env_var);
}

/*----------------------------------------------------------------------
  SetEnvGeom
  Gets the current geometry for a view and saves it in the registry
  using the format "x y w h"
  ----------------------------------------------------------------------*/
static void SetEnvGeom (const char *view_name, Document doc)
{
  int x, y, w, h;
  int view;
  
#ifdef _WX
  view = 1;
#else /* _WX */
  if (strcmp (view_name, "Annot_Formatted_view") &&
      strcmp (view_name, "Source_view") &&
      strcmp (view_name, "Topics_Formatted_view"))
    {
      view = TtaGetViewFromName (doc, (char *)view_name);
      if (view == 0 || !TtaIsViewOpen (doc, view))
        return;
    }
  else
    /* takes the current size and position of the main view */
    view = 1;
#endif /* _WX */
  
  /* get current geometry */
  if (!TtaGetViewMaximized(doc, view))
    {
      TtaSetEnvBoolean("WINDOW_MAXIMIZED", FALSE, TRUE);
      if (!TtaGetViewIconized(doc, view) && !TtaGetViewFullscreen(doc, view))
        {
          // do not save the window size if the window is maximized, iconized or fullscreen
          // because this is a separated state
          TtaGetViewXYWH (doc, view, &x, &y, &w, &h);
          sprintf(s, "%d %d %d %d", x, y, w, h);
          TtaSetEnvString((char *)view_name, s, TRUE);
        }
    }
  else
    TtaSetEnvBoolean("WINDOW_MAXIMIZED", TRUE, TRUE);      
}

/*----------------------------------------------------------------------
  RestoreDefaultGeometryConf
  Makes a copy of the default registry geometry values
  ----------------------------------------------------------------------*/
static void RestoreDefaultGeometryConf (void)
{
  int   doc;

  // restore default save geometry on exit
  GetDefEnvToggle ("SAVE_GEOMETRY", &S_Geometry,
                   GeometryBase + mToggleGeom, 0);
  for (doc = 1; doc < DocumentTableLength; doc++)
    if (DocumentURLs[doc] != NULL &&
        DocumentTypes[doc] != docSource &&
        DocumentTypes[doc] != docLog && 
        DocumentTypes[doc] != docLibrary )
      {
        if (DocumentTypes[doc] == docAnnot)
          RestoreDefEnvGeom ("Annot_Formatted_view", doc);
        else if (DocumentTypes[doc] == docBookmark)
          RestoreDefEnvGeom ("Topics_Formatted_view", doc);
        else
          {
#ifdef _WX
            RestoreDefEnvGeom ("Wx_Window", doc);
#else /* _WX */
            RestoreDefEnvGeom ("Formatted_view", doc);
            RestoreDefEnvGeom ("Structure_view", doc);
            RestoreDefEnvGeom ("Alternate_view", doc);
            RestoreDefEnvGeom ("Links_view", doc);
            RestoreDefEnvGeom ("Table_of_contents", doc);
            if (DocumentSource[doc])
              RestoreDefEnvGeom ("Source_view", DocumentSource[doc]);
#endif /* _WX */
          }
      }
  /* save the options */
  TtaSaveAppRegistry ();
}

/*----------------------------------------------------------------------
  SetEnvCurrentGeometry stores the current doc geometry in the registry
  ----------------------------------------------------------------------*/
static void SetEnvCurrentGeometry (int doc, const char * view_name)
{
  /* only do the processing if the document exists */
  if (doc &&
      DocumentURLs[doc] != NULL &&
      DocumentTypes[doc] != docSource &&
      DocumentTypes[doc] != docLog && 
      DocumentTypes[doc] != docLibrary)
    {
      if (!view_name)
        {
          if (DocumentTypes[doc] == docAnnot)
            SetEnvGeom ("Annot_Formatted_view", doc);
          else if (DocumentTypes[doc] == docBookmark)
            SetEnvGeom ("Topics_Formatted_view", doc);
          else if (DocumentMeta[doc]->method == CE_HELP)
            SetEnvGeom ("Help_Formatted_view", doc);
          else
            SetEnvGeom ("Wx_Window", doc);
        }
      else
        SetEnvGeom (view_name, doc);
    }
}

/*----------------------------------------------------------------------
  SetGeometryConf
  Updates the registry Geometry values and redraws the windows
  ----------------------------------------------------------------------*/
void SetGeometryConf ( int document, const char * view_name )
{
  /* read the current values and save them into the registry */
  SetEnvCurrentGeometry (document, view_name);

  /* save the options */
  TtaSaveAppRegistry ();
}

/*----------------------------------------------------------------------
  GeometryCallbackDialog
  callback of the geometry configuration menu
  ----------------------------------------------------------------------*/
static void GeometryCallbackDialog (int ref, int typedata, char *data)
{
  long int val;

  TtaDestroyDialogue (GeometryBase + GeometryMenu);
  if (ref == -1)
    {
      /* removes the geometry conf menu */
      GeometryDoc = 0;
    }
  else
    {
      /* has the user changed the options? */
      val = (long int) data;
      switch (ref - GeometryBase)
        {
        case GeometryMenu:
          switch (val) 
            {
            case 0:
              GeometryDoc = 0;
              break;
            case 1:
              SetGeometryConf ( GeometryDoc, NULL );
              break;
            case 2:
              RestoreDefaultGeometryConf ();
              break;
            default:
              break;
            }
          break;
#ifdef IV
        case mToggleGeom:
          S_Geometry = !S_Geometry;
          /* view geometry on exit */
          TtaSetEnvBoolean ("SAVE_GEOMETRY", S_Geometry, TRUE);
          TtaSaveAppRegistry ();
          break;
#endif
        default:
          break;
        }
    }
}


/*********************
 ** Annotations configuration menu
 ***********************/

#ifdef ANNOTATIONS
/*----------------------------------------------------------------------
  GetAnnotConf
  Makes a copy of the current registry annotation values
  ----------------------------------------------------------------------*/
static void GetAnnotConf (void)
{
#ifdef _WX
  unsigned char *ptr, *val;

  val = (unsigned char *)TtaGetEnvString ("ANNOT_USER");
  ptr = TtaConvertByteToMbs (val, TtaGetLocaleCharset ());
  if (ptr)
    {
      strncpy (GProp_Annot.AnnotUser, (char *)ptr, MAX_LENGTH);
      GProp_Annot.AnnotUser[MAX_LENGTH-1] = EOS;
    }
  else
    GProp_Annot.AnnotUser[0] = EOS;
  TtaFreeMemory (ptr);
#else /* _WX */
  GetEnvString ("ANNOT_USER", GProp_Annot.AnnotUser);
#endif /* _WX */
  GetEnvString ("ANNOT_POST_SERVER", &(GProp_Annot.AnnotPostServer[0]));
  GetEnvString ("ANNOT_SERVERS", &(GProp_Annot.AnnotServers[0]));
  TtaGetEnvBoolean ("ANNOT_LAUTOLOAD", &(GProp_Annot.AnnotLAutoLoad));
  TtaGetEnvBoolean ("ANNOT_RAUTOLOAD", &(GProp_Annot.AnnotRAutoLoad));
  TtaGetEnvBoolean ("ANNOT_RAUTOLOAD_RST", &(GProp_Annot.AnnotRAutoLoadRst));
}

/*----------------------------------------------------------------------
  SetAnnotConf
  Updates the registry annotation values
  ----------------------------------------------------------------------*/
static void SetAnnotConf (void)
{
#ifdef _WX
  unsigned char *ptr;

  ptr = TtaConvertMbsToByte ((unsigned char *)GProp_Annot.AnnotUser,
                             TtaGetLocaleCharset ());
  TtaSetEnvString ("ANNOT_USER", (char *)ptr, TRUE);
  TtaFreeMemory (ptr);
#else /* _WX */
  TtaSetEnvString ("ANNOT_USER", GProp_Annot.AnnotUser, TRUE);
#endif /* _WX */
  TtaSetEnvString ("ANNOT_POST_SERVER", GProp_Annot.AnnotPostServer, TRUE);
  TtaSetEnvString ("ANNOT_SERVERS", GProp_Annot.AnnotServers, TRUE);
  TtaSetEnvBoolean ("ANNOT_LAUTOLOAD", GProp_Annot.AnnotLAutoLoad, TRUE);
  TtaSetEnvBoolean ("ANNOT_RAUTOLOAD", GProp_Annot.AnnotRAutoLoad, TRUE);
  TtaSetEnvBoolean ("ANNOT_RAUTOLOAD_RST", GProp_Annot.AnnotRAutoLoadRst, TRUE);

  TtaSaveAppRegistry ();

  /* and restart the annotlib */
  /* @@ we could make this finer granularity, and more elegant  */
  StopAllRequests (1);
  ANNOT_FreeConf ();
  ANNOT_Init ();
}

/*----------------------------------------------------------------------
  GetDefaultAnnotConf
  Gets the registry default annotation values.
  ----------------------------------------------------------------------*/
static void GetDefaultAnnotConf ()
{
  /* read the default values */
  unsigned char *ptr, *val;

  val = (unsigned char *)TtaGetEnvString ("ANNOT_USER");
  ptr = TtaConvertByteToMbs (val, TtaGetLocaleCharset ());
  if (ptr)
    {
      strncpy (GProp_Annot.AnnotUser, (char *)ptr, MAX_LENGTH);
      GProp_Annot.AnnotUser[MAX_LENGTH-1] = EOS;
    }
  else
    GProp_Annot.AnnotUser[0] = EOS;
  TtaFreeMemory (ptr);
  GetDefEnvString ("ANNOT_POST_SERVER", &(GProp_Annot.AnnotPostServer[0]));
  GetDefEnvString ("ANNOT_SERVERS", &(GProp_Annot.AnnotServers[0]));
  TtaGetDefEnvBoolean ("ANNOT_LAUTOLOAD", &(GProp_Annot.AnnotLAutoLoad));
  TtaGetDefEnvBoolean ("ANNOT_RAUTOLOAD", &(GProp_Annot.AnnotRAutoLoad));
  TtaGetDefEnvBoolean ("ANNOT_RAUTOLOAD_RST", &(GProp_Annot.AnnotRAutoLoadRst));
}


/*----------------------------------------------------------------------
  AnnotCallbackDialog
  callback of the annotation configuration menu
  ----------------------------------------------------------------------*/
static void AnnotCallbackDialog (int ref, int typedata, char *data)
{
  long int                 val;

  if (ref == -1)
    {
      /* removes the annot conf menu */
      TtaDestroyDialogue (AnnotBase + AnnotMenu);
    }
  else
    {
      /* has the user changed the options? */
      val = (long int) data;
      switch (ref - AnnotBase)
        {
        case AnnotMenu:
          switch (val) 
            {
            case 0:
              TtaDestroyDialogue (ref);
              break;
            case 1:
              SetAnnotConf ();
              break;
            case 2:
              GetDefaultAnnotConf ();
              break;
            default:
              break;
            }
          break;
#ifdef IV
        case mAnnotUser:
          if (data)
            strcpy (GProp_Annot.AnnotUser, data);
          else
            GProp_Annot.AnnotUser[0] = EOS;
          break;

        case mAnnotPostServer:
          if (data)
            strcpy (GProp_Annot.AnnotPostServer, data);
          else
            GProp_Annot.AnnotPostServer[0] = EOS;
          break;

        case mAnnotServers:
          if (data)
            strcpy (GProp_Annot.AnnotServers, data);
          else
            GProp_Annot.AnnotServers[0] = EOS;
          break;

        case mToggleAnnot:
          switch (val) 
            {
            case 0:
              GProp_Annot.AnnotLAutoLoad = !(GProp_Annot.AnnotLAutoLoad);
              break;
            case 1:
              GProp_Annot.AnnotRAutoLoad = !(GProp_Annot.AnnotRAutoLoad);
              break;
            case 2:
              GProp_Annot.AnnotRAutoLoadRst = !(GProp_Annot.AnnotRAutoLoadRst);
              break;
            }
          break;
#endif
        default:
          break;
        }
    }
}
#endif /* ANNOTATIONS */

/*----------------------------------------------------------------------
  AnnotConfMenu
  Build and display the Conf Menu dialog box and prepare for input.
  ----------------------------------------------------------------------*/
void         AnnotConfMenu (Document document, View view)
{
#ifdef ANNOTATIONS
  /* load and display the current values */
  GetAnnotConf ();
#endif /* ANNOTATIONS */
}

/**********************
 ** Templates Menu
 **********************/
/*----------------------------------------------------------------------
  UpdateShowTemplates
  Sets the show templates on all documents
  ----------------------------------------------------------------------*/
static void UpdateShowTemplates ()
{
#ifdef TODO
  int               doc;
  DisplayMode     dispMode;
  for (doc = 1; doc < DocumentTableLength; doc++)
    {
      /* Change the Display Mode to take into account the new presentation */
      if (IsTemplateInstanceDocument (doc))
        {
          LoadInstanceOfTemplate(doc);
          dispMode = TtaGetDisplayMode (doc);
          if (dispMode != NoComputedDisplay)
            {
              TtaSetDisplayMode (doc, NoComputedDisplay);
              TtaSetDisplayMode (doc, dispMode);
            }
        }
    }
#endif //TODO
}


/*----------------------------------------------------------------------
  GetTemplateConf
  Makes a copy of the current registry templates values
  ----------------------------------------------------------------------*/
void GetTemplatesConf (void)
{
#ifdef TEMPLATES
  TtaGetEnvBoolean ("SHOW_TEMPLATES", &(GProp_Templates.S_Templates));  
  GetTemplateRepositoryList(&(GProp_Templates.FirstPath));
#endif /* TEMPLATES */
}

/*----------------------------------------------------------------------
  SetTemplatesConf
  Updates the registry Templates values and calls the General functions
  to take into account the changes
  ----------------------------------------------------------------------*/
void SetTemplatesConf (void)
{
#ifdef TEMPLATES
  ThotBool    old;
  TtaGetEnvBoolean ("SHOW_TEMPLATES", &old);
  TtaSetEnvBoolean ("SHOW_TEMPLATES", GProp_Templates.S_Templates, TRUE);
  if (old != GProp_Templates.S_Templates)
    UpdateShowTemplates ();
  TtaSaveAppRegistry ();
  //SetTemplateRepositoryList((const Prop_Templates_Path**)&(GProp_Templates.FirstPath));
#endif /* TEMPLATES */
}

#ifdef TEMPLATES
/*----------------------------------------------------------------------
  GetDefaultTemplatesConf
  Gets the registry default templates values.
  ----------------------------------------------------------------------*/
void GetDefaultTemplatesConf ()
{
  /* read the default values */
  TtaGetDefEnvBoolean ("SHOW_TEMPLATES", &(GProp_Templates.S_Templates));
  GetTemplateRepositoryList(&(GProp_Templates.FirstPath));
}

/*----------------------------------------------------------------------
  TemplatesCallbackDialog
  callback of the templates configuration menu
  ----------------------------------------------------------------------*/
static void TemplatesCallbackDialog (int ref, int typedata, char *data)
{
  intptr_t  val;
  if (ref==-1)
    {
    }
  else
    {
      val = (intptr_t) data;
      switch (ref - TemplatesBase)
        {
        case TemplatesMenu:
          switch (val)
            {
            case 0: /* CANCEL */
              TtaDestroyDialogue (ref);
              break;
            case 1: /* OK */
              SetTemplatesConf();
              //TtaDestroyDialogue (ref);
              break;
            case 2: /* DEFAULT */
              GetDefaultTemplatesConf();
              break;
            default:
              break;
            }
          break;
        default:
          break;
        }
    }
}
#endif /* TEMPLATES */


/**********************
 ** Passwords Menu
 **********************/
/*----------------------------------------------------------------------
  UpdateShowPasswords
  ----------------------------------------------------------------------*/
static void UpdateShowPasswords ()
{
}

/*----------------------------------------------------------------------
  GetPasswordsConf
  Makes a copy of the current registry passwords values
  ----------------------------------------------------------------------*/
void GetPasswordsConf (void)
{
  TtaGetEnvBoolean ("SAVE_PASSWORDS", &(GProp_Passwords.S_Passwords));  
}

/*----------------------------------------------------------------------
  SetPasswordsConf
  Updates the registry Passwords values and calls the General functions
  to take into account the changes
  ----------------------------------------------------------------------*/
void SetPasswordsConf (void)
{
  ThotBool    old;
  TtaGetEnvBoolean ("SAVE_PASSWORDS", &old);
  TtaSetEnvBoolean ("SAVE_PASSWORDS", GProp_Passwords.S_Passwords, TRUE);
  if (old != GProp_Passwords.S_Passwords)
    UpdateShowPasswords ();
  TtaSaveAppRegistry ();
}

/*----------------------------------------------------------------------
  GetDefaultPasswordsConf
  Gets the registry default passwords values.
  ----------------------------------------------------------------------*/
void GetDefaultPasswordsConf ()
{
  /* read the default values */
  GProp_Passwords.S_Passwords = TRUE;
  TtaSetEnvBoolean ("SAVE_PASSWORDS", GProp_Passwords.S_Passwords, TRUE);
}

/*----------------------------------------------------------------------
  PasswordsCallbackDialog
  callback of the passwords configuration menu
  ----------------------------------------------------------------------*/
static void PasswordsCallbackDialog (int ref, int typedata, char *data)
{
  intptr_t  val;

  if (ref==-1)
    {
    }
  else
    {
      val = (intptr_t) data;
      switch (ref - PasswordsBase)
        {
        case PasswordsMenu:
          switch (val)
            {
            case 0: /* CANCEL */
              TtaDestroyDialogue (ref);
              break;
            case 1: /* OK */
              SetPasswordsConf();
              //TtaDestroyDialogue (ref);
              break;
            case 2: /* DEFAULT */
              GetDefaultPasswordsConf();
              break;
            case 3:
              /* flush the password table */
	      CleanPasswordTable();
              break;
            default:
              break;
            }
          break;
        default:
          break;
        }
    }
}

/*----------------------------------------------------------------------
  Returns a tab dialog reference (used into PreferenceDlgWX callbacks)
  ----------------------------------------------------------------------*/
int GetPrefGeneralBase()
{
  return GeneralBase;
}

/*----------------------------------------------------------------------
  Returns a tab dialog reference (used into PreferenceDlgWX callbacks)
  ----------------------------------------------------------------------*/
int GetPrefBrowseBase()
{
  return BrowseBase;
}

/*----------------------------------------------------------------------
  Returns a tab dialog reference (used into PreferenceDlgWX callbacks)
  ----------------------------------------------------------------------*/
int GetPrefCacheBase()
{
  return CacheBase;
}

/*----------------------------------------------------------------------
  Returns a tab dialog reference (used into PreferenceDlgWX callbacks)
  ----------------------------------------------------------------------*/
int GetPrefProxyBase()
{
  return ProxyBase;
}

/*----------------------------------------------------------------------
  Returns a tab dialog reference (used into PreferenceDlgWX callbacks)
  ----------------------------------------------------------------------*/
int GetPrefPublishBase()
{
  return PublishBase;
}

/*----------------------------------------------------------------------
  Returns a tab dialog reference (used into PreferenceDlgWX callbacks)
  ----------------------------------------------------------------------*/
int GetPrefColorBase()
{
  return ColorBase;
}

/*----------------------------------------------------------------------
  Returns a tab dialog reference (used into PreferenceDlgWX callbacks)
  ----------------------------------------------------------------------*/
int GetPrefGeometryBase()
{
  return GeometryBase;
}

/*----------------------------------------------------------------------
  Returns a tab dialog reference (used into PreferenceDlgWX callbacks)
  ----------------------------------------------------------------------*/
int GetPrefAnnotBase()
{
#ifdef ANNOTATIONS
  return AnnotBase;
#else /* ANNOTATIONS */
  return 0;
#endif /* ANNOTATIONS */
}

/*----------------------------------------------------------------------
  Returns a tab dialog reference (used into PreferenceDlgWX callbacks)
  ----------------------------------------------------------------------*/
int GetPrefDAVBase()
{
#ifdef DAV
  return DAVBase;
#else /* DAV */
  return 0;
#endif /* DAV */
}

/*----------------------------------------------------------------------
  Returns a tab dialog reference (used into PreferenceDlgWX callbacks)
  ----------------------------------------------------------------------*/
int GetPrefTemplatesBase()
{
#ifdef TEMPLATES
  return TemplatesBase;
#else /* TEMPLATES */
  return 0;
#endif /* TEMPLATES */
}

/*----------------------------------------------------------------------
  Returns a tab dialog reference (used into PreferenceDlgWX callbacks)
  ----------------------------------------------------------------------*/
int GetPrefEmailsBase()
{
  return EmailsBase;
}

/*----------------------------------------------------------------------
  Returns a tab dialog reference (used into PreferenceDlgWX callbacks)
  ----------------------------------------------------------------------*/
int GetPrefPasswordsBase()
{
  return PasswordsBase;
}


/*----------------------------------------------------------------------
  Use to set the Amaya global variables (General preferences)
  ----------------------------------------------------------------------*/
void SetProp_General( const Prop_General * prop )
{
#ifdef _WX
  GProp_General = *prop;
#endif /* _WX */
}

/*----------------------------------------------------------------------
  Use to get the Amaya global variables (General preferences)
  ----------------------------------------------------------------------*/
Prop_General GetProp_General()
{
  return GProp_General;
}

/*----------------------------------------------------------------------
  Use to set the Amaya global variables (Browse preferences)
  ----------------------------------------------------------------------*/
void SetProp_Browse( const Prop_Browse * prop )
{
  GProp_Browse = *prop;
}

/*----------------------------------------------------------------------
  Use to get the Amaya global variables (Browse preferences)
  ----------------------------------------------------------------------*/
Prop_Browse GetProp_Browse()
{
  return GProp_Browse;
}
 
/*----------------------------------------------------------------------
  Use to set the Amaya global variables (Publish preferences)
  ----------------------------------------------------------------------*/
void SetProp_Publish( const Prop_Publish * prop )
{
  GProp_Publish = *prop;
}

/*----------------------------------------------------------------------
  Use to get the Amaya global variables (Publish preferences)
  ----------------------------------------------------------------------*/
Prop_Publish GetProp_Publish()
{
  return GProp_Publish;
}

/*----------------------------------------------------------------------
  Use to set the Amaya global variables (Cache preferences)
  ----------------------------------------------------------------------*/
void SetProp_Cache( const Prop_Cache * prop )
{
  GProp_Cache = *prop;
}

/*----------------------------------------------------------------------
  Use to get the Amaya global variables (Cache preferences)
  ----------------------------------------------------------------------*/
Prop_Cache GetProp_Cache()
{
  return GProp_Cache;
}

/*----------------------------------------------------------------------
  Use to set the Amaya global variables (Proxy preferences)
  ----------------------------------------------------------------------*/
void SetProp_Proxy( const Prop_Proxy * prop )
{
  GProp_Proxy = *prop;
}

/*----------------------------------------------------------------------
  Use to get the Amaya global variables (Proxy preferences)
  ----------------------------------------------------------------------*/
Prop_Proxy GetProp_Proxy()
{
  return GProp_Proxy;
}

/*----------------------------------------------------------------------
  Use to set the Amaya global variables (Color preferences)
  ----------------------------------------------------------------------*/
void SetProp_Color( const Prop_Color * prop )
{
  GProp_Color = *prop;
}

/*----------------------------------------------------------------------
  Use to get the Amaya global variables (Color preferences)
  ----------------------------------------------------------------------*/
Prop_Color GetProp_Color()
{
  return GProp_Color;
}

/*----------------------------------------------------------------------
  Use to set the Amaya global variables (Geometry preferences)
  ----------------------------------------------------------------------*/
void SetProp_Geometry( ThotBool prop )
{
  S_Geometry = prop;
  TtaSetEnvBoolean ("SAVE_GEOMETRY", S_Geometry, TRUE);
}

/*----------------------------------------------------------------------
  Use to get the Amaya global variables (Geometry preferences)
  ----------------------------------------------------------------------*/
ThotBool GetProp_Geometry()
{
  TtaGetEnvBoolean ("SAVE_GEOMETRY", &S_Geometry);
  return S_Geometry;
}

/*----------------------------------------------------------------------
  Use to set the Amaya global variables (Annotations preferences)
  ----------------------------------------------------------------------*/
void SetProp_Annot( const Prop_Annot * prop )
{
#ifdef ANNOTATIONS
  GProp_Annot = *prop;
#endif /* ANNOTATIONS */
}

/*----------------------------------------------------------------------
  Use to get the Amaya global variables (Annotations preferences)
  ----------------------------------------------------------------------*/
Prop_Annot GetProp_Annot()
{
#ifdef ANNOTATIONS
  return GProp_Annot;
#endif /* ANNOTATIONS */
}

/*----------------------------------------------------------------------
  Use to set the Amaya global variables (WebDAV preferences)
  ----------------------------------------------------------------------*/
void SetProp_DAV( const Prop_DAV * prop )
{
#ifdef DAV
  GProp_DAV = *prop;
#endif /* DAV */
}

/*----------------------------------------------------------------------
  Use to get the Amaya global variables (WebDAV preferences)
  ----------------------------------------------------------------------*/
Prop_DAV GetProp_DAV()
{
#ifdef DAV
  return GProp_DAV;
#endif /* DAV */
}


/*----------------------------------------------------------------------
  Use to set the Amaya global variables (Templates preferences)
  ----------------------------------------------------------------------*/
void SetProp_Templates( const Prop_Templates * prop )
{
#ifdef TEMPLATES
  GProp_Templates = *prop;
#endif /* TEMPLATES */
}

/*----------------------------------------------------------------------
  Use to get the Amaya global variables (Templates preferences)
  ----------------------------------------------------------------------*/
Prop_Templates GetProp_Templates()
{
#ifdef TEMPLATES
  return GProp_Templates;
#endif /* TEMPLATES */
}


/*----------------------------------------------------------------------
  Use to set the Amaya global variables (Emails preferences)
  ----------------------------------------------------------------------*/
void SetProp_Emails( const Prop_Emails * prop )
{
  GProp_Emails = *prop;
}

/*----------------------------------------------------------------------
  Use to get the Amaya global variables (Emails preferences)
  ----------------------------------------------------------------------*/
Prop_Emails GetProp_Emails()
{
  return GProp_Emails;
}


/*----------------------------------------------------------------------
  Use to set the Amaya global variables (Passwords preferences)
  ----------------------------------------------------------------------*/
void SetProp_Passwords( const Prop_Passwords * prop )
{
  GProp_Passwords = *prop;
}

/*----------------------------------------------------------------------
  Use to get the Amaya global variables (Passwords preferences)
  ----------------------------------------------------------------------*/
Prop_Passwords GetProp_Passwords()
{
  return GProp_Passwords;
}


/*----------------------------------------------------------------------
  PreferenceMenu
  Build and display the preference dialog
  ----------------------------------------------------------------------*/
void PreferenceMenu (Document document, View view)
{
  /* ---> General Tab */
  GetGeneralConf (); /* load the current values => General tab */
  
  /* ---> Browse Tab */
  SafePutStatus = 0; /* reset the modified flag */
  GetBrowseConf (); /* load the current values => Browse tab */
  /* keep initial values to detect an change */
  InitOpeningLocation = GProp_Browse.OpeningLocation;
  InitLoadImages = GProp_Browse.LoadImages;
  InitLoadObjects = GProp_Browse. LoadObjects;
  InitBgImages = GProp_Browse.BgImages;
  InitLoadCss = GProp_Browse.LoadCss;
  strcpy (InitScreen, GProp_Browse.ScreenType);

  /* ---> Publish Tab */
  GetPublishConf ();
  SafePutStatus = 0;  /* reset the modified flag */

  /* ---> Cache Tab */
  CacheStatus = 0; /* reset the modified flag */
  GetCacheConf (); /* load and display the current values */
  
  /* ---> Proxy Tab */
  ProxyStatus = 0; /* reset the modified flag */
  GetProxyConf (); /* load and display the current values */

  /* ---> Color Tab */   
  GetColorConf (); /* load and display the current values */

  /* ---> Geometry Tab */   
  GeometryDoc = document;

#ifdef ANNOTATIONS
  /* ---> Annot Tab */
  GetAnnotConf ();
#endif /* ANNOTATIONS */
#ifdef DAV
  /* ---> WebDAV Tab */
  GetDAVConf ();
#endif /* DAV */
#ifdef TEMPLATES
  /* ---> Templates Tab */
  GetTemplatesConf ();
#endif /* TEMPLATES */

  GetEmailsConf();
  /* ---> Passwords Tab */
  GetPasswordsConf ();

  ThotBool created = CreatePreferenceDlgWX ( PreferenceBase,
                                             TtaGetViewFrame (document, view),
                                             URL_list );
  if (created)
    {
      TtaSetDialoguePosition ();
      TtaShowDialogue (PreferenceBase, TRUE);
    }
}

/*----------------------------------------------------------------------
  callback of the preference dialog
  ----------------------------------------------------------------------*/
static void PreferenceCallbackDialog (int ref, int typedata, char *data)
{
  intptr_t val;

  if (ref == -1)
    TtaDestroyDialogue (PreferenceBase);
  else
    {
      /* has the user changed the options? */
      val = (intptr_t) data;
      switch (ref - PreferenceBase)
        {
        case 0:
          switch (val) 
            {
            case 0: /* CANCEL */
              TtaDestroyDialogue (ref);
              break;
            case 1: /* OK */
            case 2: /* DEFAULT */
            default:
              break;
            }
          break;
        default:
          break;
        }
    }
}

/*----------------------------------------------------------------------
  InitConfMenu: initialisation, called during Amaya initialisation
  ----------------------------------------------------------------------*/
void InitConfMenu (void)
{
  InitAmayaDefEnv ();
  /* create a new dialog reference for Preferences */
  PreferenceBase = TtaSetCallback( (Proc)PreferenceCallbackDialog, 1 );
  
#ifdef TEMPLATES  
  TemplatesBase = TtaSetCallback( (Proc)TemplatesCallbackDialog, MAX_TEMPLATEMENU_DLG );
#endif /* TEMPLATES */  
  PasswordsBase = TtaSetCallback( (Proc)PasswordsCallbackDialog, MAX_PASSWORDMENU_DLG );
  CacheBase = TtaSetCallback ((Proc)CacheCallbackDialog, MAX_CACHEMENU_DLG);
  ProxyBase = TtaSetCallback ((Proc)ProxyCallbackDialog, MAX_PROXYMENU_DLG);
  GeneralBase = TtaSetCallback ((Proc)GeneralCallbackDialog, MAX_GENERALMENU_DLG);
  BrowseBase = TtaSetCallback ((Proc)BrowseCallbackDialog, MAX_BROWSEMENU_DLG);
  PublishBase = TtaSetCallback ((Proc)PublishCallbackDialog, MAX_PUBLISHMENU_DLG);
  ColorBase = TtaSetCallback ((Proc)ColorCallbackDialog,
                              MAX_COLORMENU_DLG);
  GeometryBase = TtaSetCallback ((Proc)GeometryCallbackDialog,
                                 MAX_GEOMETRYMENU_DLG);
#ifdef ANNOTATIONS
  AnnotBase = TtaSetCallback ((Proc)AnnotCallbackDialog, MAX_ANNOTMENU_DLG);
#endif /* ANNOTATIONS */
#ifdef DAV
  InitDAVPreferences ();
#endif /* DAV */
  EmailsBase = TtaSetCallback( (Proc)EmailsCallbackDialog, MAX_EMAILSMENU_DLG );
}
