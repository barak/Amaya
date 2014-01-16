/*
 *   This file was automatically generated by version 1.7 of cextract.
 *   Manual editing not recommended.
 */

#ifndef __CEXTRACT__
#ifdef __STDC__

extern void ShowMessage ( const char* message,
                          const char* title );
extern void ParseStyleDlgValues ( void *style_widget,
                                  char *cssRule );
extern void DisplayStyleValue ( const char *property,
                                const char *start_value,
                                char *end_value );
extern ThotBool CreateSelectOperatorDlgWX ( int ref,
                                            ThotWindow parent );
extern ThotBool CreateSelectFenceAttributesDlgWX ( int ref,
                                                   ThotWindow parent );
extern ThotBool CreateSelectIntegralDlgWX ( int ref,
                                            ThotWindow parent );
extern ThotBool CreateInitConfirmDlgWX ( int ref,
                                         ThotWindow parent,
                                         char *title,
                                         char *extrabutton,
                                         char *confirmbutton,
                                         const char *label,
                                         const char *label2,
                                         const char *label3 );
extern ThotBool CreateOpenDocDlgWX ( int ref,
                                     ThotWindow parent,
                                     const char *title,
                                     const char *urlList,
                                     const char *urlToOpen,
                                     DocumentType doc_type,
                                     int doc,
                                     ThotBool newfile );
extern ThotBool CreateImageDlgWX ( int ref,
                                   ThotWindow parent,
                                   const char *title,
                                   const char *urlToOpen,
                                   const char *alt,
                                   ThotBool isSvg );
extern ThotBool CreateObjectDlgWX ( int ref,
                                    ThotWindow parent,
                                    const char *title,
                                    const char *urlToOpen,
                                    const char *type );
extern ThotBool CreateMetaDlgWX ( int ref,
                                  ThotWindow parent );
extern ThotBool CreateTitleDlgWX ( int ref,
                                   ThotWindow parent,
                                   char *doc_title );
extern ThotBool CreateMakeIdDlgWX ( int ref,
                                    ThotWindow parent );
extern ThotBool CreateSearchDlgWX ( int ref,
                                    ThotWindow parent,
                                    char* caption,
                                    char* searched,
                                    char* replace,
                                    ThotBool withReplace,
                                    ThotBool anycase,
                                    ThotBool searchAfter );
extern ThotBool CreatePrintDlgWX ( int ref,
                                   ThotWindow parent,
                                   char* printer_file,
                                   char* ps_file,
                                   int paper_format,
                                   int orientation,
                                   int disposition,
                                   int paper_print,
                                   ThotBool manual_feed,
                                   ThotBool with_toc,
                                   ThotBool with_links,
                                   ThotBool with_url,
                                   ThotBool ignore_css );
extern ThotBool CreateSaveAsDlgWX ( int ref,
                                    ThotWindow parent,
                                    char* pathname,
                                    int doc,
                                    ThotBool saveImgs,
                                    ThotBool saveRes,
                                    ThotBool checkTemplate );
extern ThotBool CreateSaveObject ( int ref,
                                   ThotWindow parent,
                                   char* objectname );
extern ThotBool CreateAuthentDlgWX ( int ref,
                                     ThotWindow parent,
                                     char *auth_realm,
                                     char *server,
                                     char *name,
                                     char *pwd );
extern ThotBool CreateCSSDlgWX ( int ref,
                                 int subref,
                                 ThotWindow parent,
                                 char *title,
                                 int nb_item,
                                 char *items );
extern void ShowNonSelListDlgWX ( ThotWindow parent,
                                  char *title,
                                  char* label,
                                  char *button,
                                  void* strings );
extern ThotBool CreateListDlgWX ( int ref,
                                  int subref,
                                  ThotWindow parent,
                                  char *title,
                                  int nb_item,
                                  char *items );
extern ThotBool CreateCheckedListDlgWX ( int ref,
                                         ThotWindow parent,
                                         char *title,
                                         int nb_item,
                                         char *items,
                                         ThotBool *checks );
extern ThotBool CreateDocInfoDlgWX ( int ref,
                                     ThotWindow parent,
                                     int doc );
extern ThotBool CreateHRefDlgWX ( int ref,
                                  ThotWindow parent,
                                  const char *url_list,
                                  const char *HRefValue,
                                  Document doc,
                                  int doc_type );
extern ThotBool CreateTextDlgWX ( int ref,
                                  int subref,
                                  ThotWindow parent,
                                  const char *title,
                                  const char *label,
                                  const char *value );
extern ThotBool CreateCreateTableDlgWX ( int ref,
                                         ThotWindow parent,
                                         int def_cols,
                                         int def_rows,
                                         int def_border );
extern ThotBool CreatePreferenceDlgWX ( int ref,
                                        ThotWindow parent,
                                        const char *url_list,
                                        const char *rdfa_list );
extern ThotBool CreateSpellCheckDlgWX ( int ref,
                                        int base,
                                        ThotWindow parent,
                                        int checkingArea );
extern ThotBool CreateStyleDlgWX ( int ref,
                                   ThotWindow parent );
extern ThotBool CreateListEditDlgWX ( int ref,
                                      ThotWindow parent,
                                      const char *title,
                                      const char * list_title,
                                      int nb_item,
                                      const char *items,
                                      const char *selected_item );
extern ThotBool CreateEnumListDlgWX ( int ref,
                                      int subref,
                                      ThotWindow parent,
                                      const char *title,
                                      const char *label,
                                      int nb_item,
                                      const char *items,
                                      int selection );
extern ThotBool CreateNumDlgWX ( int ref,
                                 int subref,
                                 ThotWindow parent,
                                 const char *title,
                                 const char *label,
                                 int value );
extern ThotBool CreateFontDlgWX ( ThotWindow parent,
                                  const char *title,
                                  int* family,
                                  int* size );
extern void* CreateListNSDlgWX ( int ref,
                                 ThotWindow parent,
                                 int nb_item,
                                 const char *items,
                                 const char *rdfa_list );
extern void UpdateListNSDlgWX ( int nb_item,
                                const char *items,
                                void * p_dlg );
extern void QueryStringFromUser ( const char *label,
                                  const char *title,
                                  char* res,
                                  int sz );
extern ThotBool QueryTitleAndDescFromUser ( char* title,
                                            int titleSz,
                                            char* desc,
                                            int descSz );
extern ThotBool QueryNewUseFromUser ( const char* proposed,
                                      char** label,
                                      char**types,
                                      ThotBool* option );
extern ThotBool QueryUnionFromUser ( const char* proposed,
                                     const char* checked,
                                     char** label,
                                     char**types,
                                     ThotBool newUnion );
extern ThotBool QueryUseFromUser ( const char* proposed,
                                   const char* checked,
                                   char* label,
                                   int labelsz,
                                   char**types,
                                   ThotBool* option );

#else /* __STDC__ */

extern void ShowMessage ( const char* message,
                            const char* title );
extern void ParseStyleDlgValues ( void *style_widget,
                                    char *cssRule );
extern void DisplayStyleValue ( const char *property,
                                  const char *start_value,
                                  char *end_value );
extern ThotBool CreateSelectOperatorDlgWX ( int ref,
                                              ThotWindow parent );
extern ThotBool CreateSelectFenceAttributesDlgWX ( int ref,
                                                     ThotWindow parent );
extern ThotBool CreateSelectIntegralDlgWX ( int ref,
                                              ThotWindow parent );
extern ThotBool CreateInitConfirmDlgWX ( int ref,
                                           ThotWindow parent,
                                           char *title,
                                           char *extrabutton,
                                           char *confirmbutton,
                                           const char *label,
                                           const char *label2,
                                           const char *label3 );
extern ThotBool CreateOpenDocDlgWX ( int ref,
                                       ThotWindow parent,
                                       const char *title,
                                       const char *urlList,
                                       const char *urlToOpen,
                                       DocumentType doc_type,
                                       int doc,
                                       ThotBool newfile );
extern ThotBool CreateImageDlgWX ( int ref,
                                     ThotWindow parent,
                                     const char *title,
                                     const char *urlToOpen,
                                     const char *alt,
                                     ThotBool isSvg );
extern ThotBool CreateObjectDlgWX ( int ref,
                                      ThotWindow parent,
                                      const char *title,
                                      const char *urlToOpen,
                                      const char *type );
extern ThotBool CreateMetaDlgWX ( int ref,
                                    ThotWindow parent );
extern ThotBool CreateTitleDlgWX ( int ref,
                                     ThotWindow parent,
                                     char *doc_title );
extern ThotBool CreateMakeIdDlgWX ( int ref,
                                      ThotWindow parent );
extern ThotBool CreateSearchDlgWX ( int ref,
                                      ThotWindow parent,
                                      char* caption,
                                      char* searched,
                                      char* replace,
                                      ThotBool withReplace,
                                      ThotBool anycase,
                                      ThotBool searchAfter );
extern ThotBool CreatePrintDlgWX ( int ref,
                                     ThotWindow parent,
                                     char* printer_file,
                                     char* ps_file,
                                     int paper_format,
                                     int orientation,
                                     int disposition,
                                     int paper_print,
                                     ThotBool manual_feed,
                                     ThotBool with_toc,
                                     ThotBool with_links,
                                     ThotBool with_url,
                                     ThotBool ignore_css );
extern ThotBool CreateSaveAsDlgWX ( int ref,
                                      ThotWindow parent,
                                      char* pathname,
                                      int doc,
                                      ThotBool saveImgs,
                                      ThotBool saveRes,
                                      ThotBool checkTemplate );
extern ThotBool CreateSaveObject ( int ref,
                                     ThotWindow parent,
                                     char* objectname );
extern ThotBool CreateAuthentDlgWX ( int ref,
                                       ThotWindow parent,
                                       char *auth_realm,
                                       char *server,
                                       char *name,
                                       char *pwd );
extern ThotBool CreateCSSDlgWX ( int ref,
                                   int subref,
                                   ThotWindow parent,
                                   char *title,
                                   int nb_item,
                                   char *items );
extern void ShowNonSelListDlgWX ( ThotWindow parent,
                                    char *title,
                                    char* label,
                                    char *button,
                                    void* strings );
extern ThotBool CreateListDlgWX ( int ref,
                                    int subref,
                                    ThotWindow parent,
                                    char *title,
                                    int nb_item,
                                    char *items );
extern ThotBool CreateCheckedListDlgWX ( int ref,
                                           ThotWindow parent,
                                           char *title,
                                           int nb_item,
                                           char *items,
                                           ThotBool *checks );
extern ThotBool CreateDocInfoDlgWX ( int ref,
                                       ThotWindow parent,
                                       int doc );
extern ThotBool CreateHRefDlgWX ( int ref,
                                    ThotWindow parent,
                                    const char *url_list,
                                    const char *HRefValue,
                                    Document doc,
                                    int doc_type );
extern ThotBool CreateTextDlgWX ( int ref,
                                    int subref,
                                    ThotWindow parent,
                                    const char *title,
                                    const char *label,
                                    const char *value );
extern ThotBool CreateCreateTableDlgWX ( int ref,
                                           ThotWindow parent,
                                           int def_cols,
                                           int def_rows,
                                           int def_border );
extern ThotBool CreatePreferenceDlgWX ( int ref,
                                          ThotWindow parent,
                                          const char *url_list,
                                          const char *rdfa_list );
extern ThotBool CreateSpellCheckDlgWX ( int ref,
                                          int base,
                                          ThotWindow parent,
                                          int checkingArea );
extern ThotBool CreateStyleDlgWX ( int ref,
                                     ThotWindow parent );
extern ThotBool CreateListEditDlgWX ( int ref,
                                        ThotWindow parent,
                                        const char *title,
                                        const char * list_title,
                                        int nb_item,
                                        const char *items,
                                        const char *selected_item );
extern ThotBool CreateEnumListDlgWX ( int ref,
                                        int subref,
                                        ThotWindow parent,
                                        const char *title,
                                        const char *label,
                                        int nb_item,
                                        const char *items,
                                        int selection );
extern ThotBool CreateNumDlgWX ( int ref,
                                   int subref,
                                   ThotWindow parent,
                                   const char *title,
                                   const char *label,
                                   int value );
extern ThotBool CreateFontDlgWX ( ThotWindow parent,
                                    const char *title,
                                    int* family,
                                    int* size );
extern void* CreateListNSDlgWX ( int ref,
                                   ThotWindow parent,
                                   int nb_item,
                                   const char *items,
                                   const char *rdfa_list );
extern void UpdateListNSDlgWX ( int nb_item,
                                  const char *items,
                                  void * p_dlg );
extern void QueryStringFromUser ( const char *label,
                                    const char *title,
                                    char* res,
                                    int sz );
extern ThotBool QueryTitleAndDescFromUser ( char* title,
                                              int titleSz,
                                              char* desc,
                                              int descSz );
extern ThotBool QueryNewUseFromUser ( const char* proposed,
                                        char** label,
                                        char**types,
                                        ThotBool* option );
extern ThotBool QueryUnionFromUser ( const char* proposed,
                                       const char* checked,
                                       char** label,
                                       char**types,
                                       ThotBool newUnion );
extern ThotBool QueryUseFromUser ( const char* proposed,
                                     const char* checked,
                                     char* label,
                                     int labelsz,
                                     char**types,
                                     ThotBool* option );

#endif /* __STDC__ */
#endif /* __CEXTRACT__ */
