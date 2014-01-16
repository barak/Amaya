/*
 *   This file was automatically generated by version 1.7 of cextract.
 *   Manual editing not recommended.
 */

#ifndef __CEXTRACT__
#ifdef __STDC__

extern char *TtaSkipBlanks ( char *ptr );
extern ThotBool TtaIsBlank ( const char *ptr );
extern ThotBool TtaGetEnvInt ( const char *name,
                               int *value );
extern ThotBool TtaGetEnvBoolean ( const char *name,
                                   ThotBool *value );
extern char *TtaGetEnvString ( const char *name );
extern void TtaClearEnvString ( const char *name );
extern void TtaSetEnvInt ( const char *name,
                           int value,
                           int overwrite );
extern void TtaSetEnvBoolean ( const char *name,
                               ThotBool value,
                               int overwrite );
extern void TtaSetEnvString ( const char *name,
                              char *value,
                              int overwrite );
extern void TtaSetDefEnvString ( const char *name,
                                 char *value,
                                 int overwrite );
extern ThotBool TtaGetDefEnvInt ( const char *name,
                                  int *value );
extern ThotBool TtaGetDefEnvBoolean ( const char *name,
                                      ThotBool *value );
extern char *TtaGetDefEnvString ( const char *name );
extern void TtaSaveAppRegistry ( void );
extern void TtaInitializeAppRegistry ( char *appArgv0 );
extern void TtaFreeAppRegistry ( void );
extern int SearchFile ( char *fileName,
                        int dir,
                        char *fullName );

#else /* __STDC__ */

extern char *TtaSkipBlanks ( char *ptr );
extern ThotBool TtaIsBlank ( const char *ptr );
extern ThotBool TtaGetEnvInt ( const char *name,
                                 int *value );
extern ThotBool TtaGetEnvBoolean ( const char *name,
                                     ThotBool *value );
extern char *TtaGetEnvString ( const char *name );
extern void TtaClearEnvString ( const char *name );
extern void TtaSetEnvInt ( const char *name,
                             int value,
                             int overwrite );
extern void TtaSetEnvBoolean ( const char *name,
                                 ThotBool value,
                                 int overwrite );
extern void TtaSetEnvString ( const char *name,
                                char *value,
                                int overwrite );
extern void TtaSetDefEnvString ( const char *name,
                                   char *value,
                                   int overwrite );
extern ThotBool TtaGetDefEnvInt ( const char *name,
                                    int *value );
extern ThotBool TtaGetDefEnvBoolean ( const char *name,
                                        ThotBool *value );
extern char *TtaGetDefEnvString ( const char *name );
extern void TtaSaveAppRegistry ( void );
extern void TtaInitializeAppRegistry ( char *appArgv0 );
extern void TtaFreeAppRegistry ( void );
extern int SearchFile ( char *fileName,
                          int dir,
                          char *fullName );

#endif /* __STDC__ */
#endif /* __CEXTRACT__ */
