/*
 *   This file was automatically generated by version 1.7 of cextract.
 *   Manual editing not recommended.
 */

#ifndef __CEXTRACT__
#ifdef __STDC__

extern struct Cat_Context *CatEntry ( int ref );
extern ThotWidget CatWidget ( int ref );
extern ThotWidget TtaCatWidget ( int ref );
extern void MyWarningHandler ( char *s );
extern void TtaInitDialogue ( char *server,
                              ThotAppContext *app_context );
extern void InitDialogueFont ( void );
extern int TtaGetReferencesBase ( int number );
extern void DisplayConfirmMessage ( const char *text );
extern void DisplayMessage ( char *text,
                             int msgType );
extern int DestContenuMenu ( struct Cat_Context *catalogue );
extern void TtaNewPulldown ( int ref,
                             ThotMenu parent,
                             char *title,
                             int number,
                             char *text,
                             char* equiv,
                             int max_length );
extern void TtaNewPopup ( int ref,
                          ThotWidget parent,
                          char *title,
                          int number,
                          char *text,
                          char *equiv,
                          char button );
extern void TtaNewScrollPopup ( int ref,
                                ThotWidget parent,
                                char *title,
                                int number,
                                char *text,
                                char *equiv,
                                ThotBool multipleOptions,
                                char button );
extern void TtaNewIconMenu ( int ref,
                             int ref_parent,
                             int entry,
                             char *title,
                             int number,
                             ThotIcon * icons,
                             ThotBool horizontal );
extern void TtaNewSubmenu ( int ref,
                            int ref_parent,
                            int entry,
                            char *title,
                            int number,
                            char *text,
                            char* equiv,
                            int max_length,
                            ThotBool react );
extern void TtaSetMenuForm ( int ref,
                             int val );
extern void TtaNewToggleMenu ( int ref,
                               int ref_parent,
                               char *title,
                               int number,
                               char *text,
                               char *equiv,
                               ThotBool react );
extern void TtaChangeMenuEntry ( int ref,
                                 int entry,
                                 char *text );
extern void TtaRedrawMenuEntry ( int ref,
                                 int entry,
                                 char *fontname,
                                 ThotColor color,
                                 int activate );
extern ThotBool TtaRaiseDialogue ( int ref );
extern void TtaUnmapDialogue ( int ref );
extern void TtaDestroyDialogue ( int ref );
extern void TtaChangeFormTitle ( int ref,
                                 char *title );
extern void TtaSetDefaultButton ( int ref,
                                  int button );
extern void TtaNewForm ( int ref,
                         ThotWidget parent,
                         char *title,
                         ThotBool horizontal,
                         int package,
                         char button,
                         int dbutton );
extern void TtaNewSheet ( int ref,
                          ThotWidget parent,
                          char *title,
                          int number,
                          char *text,
                          ThotBool horizontal,
                          int package,
                          char button,
                          int dbutton );
extern void TtaNewDialogSheet ( int ref,
                                ThotWidget parent,
                                char *title,
                                int number,
                                char *text,
                                ThotBool horizontal,
                                int package,
                                char button );
extern void TtaAttachForm ( int ref );
extern void TtaDetachForm ( int ref );
extern void TtaNewSizedSelector ( int ref,
                                  int ref_parent,
                                  char *title,
                                  int number,
                                  char *text,
                                  int width,
                                  int height,
                                  char *label,
                                  ThotBool withText,
                                  ThotBool react );
extern void TtaNewSelector ( int ref,
                             int ref_parent,
                             char *title,
                             int number,
                             char *text,
                             int height,
                             char *label,
                             ThotBool withText,
                             ThotBool react );
extern void TtaActiveSelector ( int ref );
extern void TtaDesactiveSelector ( int ref );
extern void TtaSetSelector ( int ref,
                             int entry,
                             const char *text );
extern void TtaNewLabel ( int ref,
                          int ref_parent,
                          const char *text );
extern void TtaNewPaddedLabel ( int ref,
                                int ref_parent,
                                char *text,
                                int padding );
extern void TtaNewTextForm ( int ref,
                             int ref_parent,
                             char *title,
                             int width,
                             int height,
                             ThotBool react );
extern void TtaNewPwdForm ( int ref,
                            int ref_parent,
                            char *title,
                            int width,
                            int height,
                            ThotBool react );
extern void TtaSetTextForm ( int ref,
                             char *text );
extern void TtaNewNumberForm ( int ref,
                               int ref_parent,
                               char *title,
                               int min,
                               int max,
                               ThotBool react );
extern void TtaSetNumberForm ( int ref,
                               int val );
extern ThotWidget TtaClearTree ( ThotWidget tree );
extern ThotWidget TtaAddTreeItem ( ThotWidget tree,
                                   ThotWidget parent,
                                   ThotWidget sibling,
                                   char *item_label,
                                   ThotBool selected,
                                   ThotBool expanded,
                                   void *user_data );
extern ThotWidget TtaNewTreeForm ( int ref,
                                   int ref_parent,
                                   char *label,
                                   ThotBool multiple,
                                   void *callback );
extern void TtaInitComboBox ( ThotWidget w,
                              int nb_items,
                              char *item_labels[] );
extern ThotWidget TtaNewComboBox ( int ref,
                                   int ref_parent,
                                   char *label,
                                   ThotBool react );
extern void TtaAbortShowDialogue ( void );
extern void TtaSetDialoguePosition ( void );
extern void TtaShowDialogue ( int ref,
                              ThotBool remanent );
extern void TtaWaitShowProcDialogue ( void );
extern void TtaWaitShowDialogue ( void );
extern ThotBool TtaTestWaitShowDialogue ( void );
extern void TtaFreeAllCatalogs ( void );

#else /* __STDC__ */

extern struct Cat_Context *CatEntry ( int ref );
extern ThotWidget CatWidget ( int ref );
extern ThotWidget TtaCatWidget ( int ref );
extern void MyWarningHandler ( char *s );
extern void TtaInitDialogue ( char *server,
                                ThotAppContext *app_context );
extern void InitDialogueFont ( void );
extern int TtaGetReferencesBase ( int number );
extern void DisplayConfirmMessage ( const char *text );
extern void DisplayMessage ( char *text,
                               int msgType );
extern int DestContenuMenu ( struct Cat_Context *catalogue );
extern void TtaNewPulldown ( int ref,
                               ThotMenu parent,
                               char *title,
                               int number,
                               char *text,
                               char* equiv,
                               int max_length );
extern void TtaNewPopup ( int ref,
                            ThotWidget parent,
                            char *title,
                            int number,
                            char *text,
                            char *equiv,
                            char button );
extern void TtaNewScrollPopup ( int ref,
                                  ThotWidget parent,
                                  char *title,
                                  int number,
                                  char *text,
                                  char *equiv,
                                  ThotBool multipleOptions,
                                  char button );
extern void TtaNewIconMenu ( int ref,
                               int ref_parent,
                               int entry,
                               char *title,
                               int number,
                               ThotIcon * icons,
                               ThotBool horizontal );
extern void TtaNewSubmenu ( int ref,
                              int ref_parent,
                              int entry,
                              char *title,
                              int number,
                              char *text,
                              char* equiv,
                              int max_length,
                              ThotBool react );
extern void TtaSetMenuForm ( int ref,
                               int val );
extern void TtaNewToggleMenu ( int ref,
                                 int ref_parent,
                                 char *title,
                                 int number,
                                 char *text,
                                 char *equiv,
                                 ThotBool react );
extern void TtaChangeMenuEntry ( int ref,
                                   int entry,
                                   char *text );
extern void TtaRedrawMenuEntry ( int ref,
                                   int entry,
                                   char *fontname,
                                   ThotColor color,
                                   int activate );
extern ThotBool TtaRaiseDialogue ( int ref );
extern void TtaUnmapDialogue ( int ref );
extern void TtaDestroyDialogue ( int ref );
extern void TtaChangeFormTitle ( int ref,
                                   char *title );
extern void TtaSetDefaultButton ( int ref,
                                    int button );
extern void TtaNewForm ( int ref,
                           ThotWidget parent,
                           char *title,
                           ThotBool horizontal,
                           int package,
                           char button,
                           int dbutton );
extern void TtaNewSheet ( int ref,
                            ThotWidget parent,
                            char *title,
                            int number,
                            char *text,
                            ThotBool horizontal,
                            int package,
                            char button,
                            int dbutton );
extern void TtaNewDialogSheet ( int ref,
                                  ThotWidget parent,
                                  char *title,
                                  int number,
                                  char *text,
                                  ThotBool horizontal,
                                  int package,
                                  char button );
extern void TtaAttachForm ( int ref );
extern void TtaDetachForm ( int ref );
extern void TtaNewSizedSelector ( int ref,
                                    int ref_parent,
                                    char *title,
                                    int number,
                                    char *text,
                                    int width,
                                    int height,
                                    char *label,
                                    ThotBool withText,
                                    ThotBool react );
extern void TtaNewSelector ( int ref,
                               int ref_parent,
                               char *title,
                               int number,
                               char *text,
                               int height,
                               char *label,
                               ThotBool withText,
                               ThotBool react );
extern void TtaActiveSelector ( int ref );
extern void TtaDesactiveSelector ( int ref );
extern void TtaSetSelector ( int ref,
                               int entry,
                               const char *text );
extern void TtaNewLabel ( int ref,
                            int ref_parent,
                            const char *text );
extern void TtaNewPaddedLabel ( int ref,
                                  int ref_parent,
                                  char *text,
                                  int padding );
extern void TtaNewTextForm ( int ref,
                               int ref_parent,
                               char *title,
                               int width,
                               int height,
                               ThotBool react );
extern void TtaNewPwdForm ( int ref,
                              int ref_parent,
                              char *title,
                              int width,
                              int height,
                              ThotBool react );
extern void TtaSetTextForm ( int ref,
                               char *text );
extern void TtaNewNumberForm ( int ref,
                                 int ref_parent,
                                 char *title,
                                 int min,
                                 int max,
                                 ThotBool react );
extern void TtaSetNumberForm ( int ref,
                                 int val );
extern ThotWidget TtaClearTree ( ThotWidget tree );
extern ThotWidget TtaAddTreeItem ( ThotWidget tree,
                                     ThotWidget parent,
                                     ThotWidget sibling,
                                     char *item_label,
                                     ThotBool selected,
                                     ThotBool expanded,
                                     void *user_data );
extern ThotWidget TtaNewTreeForm ( int ref,
                                     int ref_parent,
                                     char *label,
                                     ThotBool multiple,
                                     void *callback );
extern void TtaInitComboBox ( ThotWidget w,
                                int nb_items,
                                char *item_labels[] );
extern ThotWidget TtaNewComboBox ( int ref,
                                     int ref_parent,
                                     char *label,
                                     ThotBool react );
extern void TtaAbortShowDialogue ( void );
extern void TtaSetDialoguePosition ( void );
extern void TtaShowDialogue ( int ref,
                                ThotBool remanent );
extern void TtaWaitShowProcDialogue ( void );
extern void TtaWaitShowDialogue ( void );
extern ThotBool TtaTestWaitShowDialogue ( void );
extern void TtaFreeAllCatalogs ( void );

#endif /* __STDC__ */
#endif /* __CEXTRACT__ */
