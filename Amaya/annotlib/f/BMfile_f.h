/*
 *   This file was automatically generated by version 1.7 of cextract.
 *   Manual editing not recommended.
 */

#ifndef __CEXTRACT__
#ifdef __STDC__

extern char *BMContext_url ( int ref );
extern char *BMContext_tmpfile ( int ref );
extern ThotBool BMContext_tmpfileSet ( int ref,
                                       char *tmpfile );
extern ThotBool BM_Context_reference ( char *url,
                                       int *ref );
extern int BM_Context_dumpAsCharList ( char **bm_urls[] );
extern Document redland_init ( char *url,
                               char *tmpfile,
                               ThotBool init_world );
extern void redland_free ( int ref,
                           ThotBool free_world );
extern ThotBool BM_deleteItemCollection ( int ref,
                                          char *topic_url,
                                          char *item_url,
                                          ThotBool *isBlankNode,
                                          ThotBool cleanAll );
extern ThotBool BM_initializeCollection ( int ref,
                                          BookmarkP new_item );
extern ThotBool BM_addItemToCollection ( int ref,
                                         char *topic_url,
                                         char *previous_item_url,
                                         BookmarkP new_item,
                                         ThotBool addFirst );
extern ThotBool BM_generateCollection ( int ref,
                                        List *items );
extern ThotBool BM_tmpsave ( int ref );
extern ThotBool BM_save ( int ref,
                          char *filename );
extern ThotBool BM_saveOrModify ( int ref,
                                  Document doc );
extern ThotBool BM_parse ( int ref,
                           char *filename,
                           char *base );
extern ThotBool BM_addBookmark ( Document doc,
                                 int ref,
                                 BookmarkP me );
extern ThotBool BM_addTopic ( Document doc,
                              int ref,
                              BookmarkP me,
                              ThotBool generateID );
extern ThotBool BM_addSeparator ( Document doc,
                                  int ref,
                                  char *topic_url,
                                  char *previous_item_url );
extern int Model_dumpAsList ( int ref,
                              List **dump,
                              BookmarkElements bm_type );
extern ThotBool Model_dumpTopicChild ( int ref,
                                       char *parent_topic_url,
                                       List **dump );
extern int Model_dumpSeeAlso ( int ref,
                               char *resource_url,
                               char *topic_url,
                               List **dump );
extern void Model_dumpSeeAlsoAsList ( int ref,
                                      List **bm_list );
extern ThotBool Model_dumpTopicBookmarks ( int ref,
                                           List *topic_list,
                                           List **dump );
extern ThotBool Model_dumpBookmarkTopics ( int ref,
                                           BookmarkP me,
                                           List **dump );
extern ThotBool Model_dumpTopicAsList ( int ref,
                                        char *parent_topic_url,
                                        ThotBool sort,
                                        ThotBool prune,
                                        List **dump );
extern int Model_dumpSeq ( int ref,
                           List **dump );
extern char * Model_getCollectionRoot ( int ref,
                                        char *topic_url );
extern int Model_dumpCollection ( int ref,
                                  char *topic_url,
                                  ThotBool isRoot,
                                  List **dump );
extern BookmarkP BM_getItem ( int ref,
                              char *url,
                              ThotBool isTopic );
extern ThotBool BM_updateItem ( Document doc,
                                int ref,
                                BookmarkP me,
                                ThotBool isTopic );
extern ThotBool BM_deleteItem ( int ref,
                                char *item_url,
                                ThotBool isBlankIdentifier );
extern ThotBool BM_deleteItemList ( int ref,
                                    char *parent_topic,
                                    List *items );
extern ThotBool BM_deleteBookmarkTopic ( int ref,
                                         char *parent_url,
                                         char *self_url,
                                         ThotBool isBlankIdentifier );
extern ThotBool BM_deleteBookmarkItem ( int ref,
                                        char *parent_url,
                                        char *self_url,
                                        ThotBool isBlankIdentifier );
extern ThotBool BM_containsBookmarks ( int ref );
extern ThotBool BM_pasteBookmark ( int dest_ref,
                                   int src_ref,
                                   char *src_bookmark_url,
                                   char *dest_parent_url,
                                   char **new_bookmark_id );
extern ThotBool BM_pasteBookmarkColl ( int dest_ref,
                                       int src_ref,
                                       char *src_bookmark_url,
                                       char *dest_parent_url );
extern ThotBool BM_addTopicToBookmark ( int ref,
                                        char *bookmark_url,
                                        char *new_topic_url );
extern ThotBool BM_replaceTopicParent ( int ref,
                                        char *topic_url,
                                        char *new_topic_parent_url );
extern Document BM_getDocumentFromRef ( int ref );
extern Document BM_printStatements ( int ref,
                                     char *subject_url );
extern ThotBool Model_queryState ( int ref,
                                   char *subject_url,
                                   char *state_url );
extern ThotBool Model_changeState ( int ref,
                                    Document doc,
                                    char *subject_url,
                                    char *previous_state_url,
                                    char *new_state_url );

#else /* __STDC__ */

extern char *BMContext_url ( int ref );
extern char *BMContext_tmpfile ( int ref );
extern ThotBool BMContext_tmpfileSet ( int ref,
                                         char *tmpfile );
extern ThotBool BM_Context_reference ( char *url,
                                         int *ref );
extern int BM_Context_dumpAsCharList ( char **bm_urls[] );
extern Document redland_init ( char *url,
                                 char *tmpfile,
                                 ThotBool init_world );
extern void redland_free ( int ref,
                             ThotBool free_world );
extern ThotBool BM_deleteItemCollection ( int ref,
                                            char *topic_url,
                                            char *item_url,
                                            ThotBool *isBlankNode,
                                            ThotBool cleanAll );
extern ThotBool BM_initializeCollection ( int ref,
                                            BookmarkP new_item );
extern ThotBool BM_addItemToCollection ( int ref,
                                           char *topic_url,
                                           char *previous_item_url,
                                           BookmarkP new_item,
                                           ThotBool addFirst );
extern ThotBool BM_generateCollection ( int ref,
                                          List *items );
extern ThotBool BM_tmpsave ( int ref );
extern ThotBool BM_save ( int ref,
                            char *filename );
extern ThotBool BM_saveOrModify ( int ref,
                                    Document doc );
extern ThotBool BM_parse ( int ref,
                             char *filename,
                             char *base );
extern ThotBool BM_addBookmark ( Document doc,
                                   int ref,
                                   BookmarkP me );
extern ThotBool BM_addTopic ( Document doc,
                                int ref,
                                BookmarkP me,
                                ThotBool generateID );
extern ThotBool BM_addSeparator ( Document doc,
                                    int ref,
                                    char *topic_url,
                                    char *previous_item_url );
extern int Model_dumpAsList ( int ref,
                                List **dump,
                                BookmarkElements bm_type );
extern ThotBool Model_dumpTopicChild ( int ref,
                                         char *parent_topic_url,
                                         List **dump );
extern int Model_dumpSeeAlso ( int ref,
                                 char *resource_url,
                                 char *topic_url,
                                 List **dump );
extern void Model_dumpSeeAlsoAsList ( int ref,
                                        List **bm_list );
extern ThotBool Model_dumpTopicBookmarks ( int ref,
                                             List *topic_list,
                                             List **dump );
extern ThotBool Model_dumpBookmarkTopics ( int ref,
                                             BookmarkP me,
                                             List **dump );
extern ThotBool Model_dumpTopicAsList ( int ref,
                                          char *parent_topic_url,
                                          ThotBool sort,
                                          ThotBool prune,
                                          List **dump );
extern int Model_dumpSeq ( int ref,
                             List **dump );
extern char * Model_getCollectionRoot ( int ref,
                                          char *topic_url );
extern int Model_dumpCollection ( int ref,
                                    char *topic_url,
                                    ThotBool isRoot,
                                    List **dump );
extern BookmarkP BM_getItem ( int ref,
                                char *url,
                                ThotBool isTopic );
extern ThotBool BM_updateItem ( Document doc,
                                  int ref,
                                  BookmarkP me,
                                  ThotBool isTopic );
extern ThotBool BM_deleteItem ( int ref,
                                  char *item_url,
                                  ThotBool isBlankIdentifier );
extern ThotBool BM_deleteItemList ( int ref,
                                      char *parent_topic,
                                      List *items );
extern ThotBool BM_deleteBookmarkTopic ( int ref,
                                           char *parent_url,
                                           char *self_url,
                                           ThotBool isBlankIdentifier );
extern ThotBool BM_deleteBookmarkItem ( int ref,
                                          char *parent_url,
                                          char *self_url,
                                          ThotBool isBlankIdentifier );
extern ThotBool BM_containsBookmarks ( int ref );
extern ThotBool BM_pasteBookmark ( int dest_ref,
                                     int src_ref,
                                     char *src_bookmark_url,
                                     char *dest_parent_url,
                                     char **new_bookmark_id );
extern ThotBool BM_pasteBookmarkColl ( int dest_ref,
                                         int src_ref,
                                         char *src_bookmark_url,
                                         char *dest_parent_url );
extern ThotBool BM_addTopicToBookmark ( int ref,
                                          char *bookmark_url,
                                          char *new_topic_url );
extern ThotBool BM_replaceTopicParent ( int ref,
                                          char *topic_url,
                                          char *new_topic_parent_url );
extern Document BM_getDocumentFromRef ( int ref );
extern Document BM_printStatements ( int ref,
                                       char *subject_url );
extern ThotBool Model_queryState ( int ref,
                                     char *subject_url,
                                     char *state_url );
extern ThotBool Model_changeState ( int ref,
                                      Document doc,
                                      char *subject_url,
                                      char *previous_state_url,
                                      char *new_state_url );

#endif /* __STDC__ */
#endif /* __CEXTRACT__ */
