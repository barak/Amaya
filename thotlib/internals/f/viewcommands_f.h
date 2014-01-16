/*
 *   This file was automatically generated by version 1.7 of cextract.
 *   Manual editing not recommended.
 */

#ifndef __CEXTRACT__
#ifdef __STDC__

extern void CloseDocument ( PtrDocument pDoc );
extern int CreateWindowWithTitle ( PtrDocument pDoc,
                                   int view,
                                   Name viewName,
                                   int *vol,
                                   int X,
                                   int Y,
                                   int width,
                                   int height );
extern void ImportDocument ( Name SSchemaName,
                             PathBuffer directory,
                             Name fileName );
extern void CloseAllViewsDoc ( PtrDocument pDoc );
extern void TtaChangeNaturePresentSchema ( Document document,
                                           SSchema natureSSchema,
                                           char *newPresentation );
extern void TtcChangePresentation ( Document document,
                                    View view );

#else /* __STDC__ */

extern void CloseDocument (/* PtrDocument pDoc */);
extern int CreateWindowWithTitle (/* PtrDocument pDoc,
                                     int view,
                                     Name viewName,
                                     int *vol,
                                     int X,
                                     int Y,
                                     int width,
                                     int height */);
extern void ImportDocument (/* Name SSchemaName,
                               PathBuffer directory,
                               Name fileName */);
extern void CloseAllViewsDoc (/* PtrDocument pDoc */);
extern void TtaChangeNaturePresentSchema (/* Document document,
                                             SSchema natureSSchema,
                                             char *newPresentation */);
extern void TtcChangePresentation (/* Document document,
                                      View view */);

#endif /* __STDC__ */
#endif /* __CEXTRACT__ */
