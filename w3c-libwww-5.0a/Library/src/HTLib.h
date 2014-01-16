/*                                     W3C Reference Library libwww Global Libwww Information
                                GLOBAL LIBWWW INFORMATION
                                             
 */
/*
**      (c) COPYRIGHT MIT 1995.
**      Please first read the full copyright statement in the file COPYRIGH.
*/
/*

   This module contains some generic functions for getting the name and version of libwww.
   It also contains some global configuration options like if you can access the local
   file system, for example.
   
   This module is implemented by HTAccess.c, and it is a part of the W3C Reference
   Library.
   
 */
#ifndef HTLIB_H
#define HTLIB_H

#include "HTUser.h"
/*

  [IMAGE]Initializing and Terminating the Library
  
   These two functions initiates memory and settings for the Library core and cleans up
   memory kept by the core when about to exit the application. They  _must_ be used!
   
 */
extern BOOL HTLibInit (const char * AppName, const char * AppVersion);
extern BOOL HTLibTerminate (void);
/*

  Library Name and Version
  
   You can get the generic name of the Library and the version by using the following
   functions:
   
 */
extern const char * HTLib_name (void);
extern const char * HTLib_version (void);
/*

  Is the Library Initalized?
  
   Returns YES or NO
   
 */
extern BOOL HTLib_isInitialized (void);
/*

  Application Name and Version
  
   Returns the name of the application and the version number that was passed to the
   HTLibInit()function.
   
 */
extern const char * HTLib_appName (void);
extern const char * HTLib_appVersion (void);
/*

  Accessing the Local File System
  
   The Library does normally use the local file system for dumping unknown data objects,
   file cache etc. In some situations this is not desired and we can therefore turn it
   off. This mode also prevents you from being able to access other resources where you
   have to log in telnet, for example.
   
 */
extern BOOL HTLib_secure (void);
extern void HTLib_setSecure (BOOL mode);
/*

  Default User Profile
  
   The default user profile is automatically created by the libwww in order to get
   information about the _hostname_, default _email -address _etc. All request objects
   will be created with this default user profile. The application may assign individual
   user profiles to every request object or may set the default user profile.
   
 */
extern HTUserProfile * HTLib_userProfile (void);
extern BOOL HTLib_setUserProfile (HTUserProfile * up);
/*

 */
#endif /* HTLIB_H */
/*

   
   ___________________________________
   
                              @(#) $Id: HTLib.h,v 1.1.1.1 1996/10/15 13:08:41 cvs Exp $
                                                                                          
    */
