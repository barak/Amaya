/*
 *   This file was automatically generated by version 1.7 of cextract.
 *   Manual editing not recommended.
 */

#ifndef __CEXTRACT__
#ifdef __STDC__

extern ContainerElement ContainerNode_GetElement ( ContainerNode node );
extern void Container_DeleteElement ( Container container,
                                      ContainerNode node );
extern void Container_DeleteNode ( Container container,
                                   ContainerNode node );
extern ForwardIterator ForwardIterator_Create ( Container container,
                                                ForwardIterator_GetFirstFunction getFirst,
                                                ForwardIterator_GetNextFunction getNext );
extern ContainerNode ForwardIterator_GetFirst ( ForwardIterator iter );
extern ContainerNode ForwardIterator_GetNext ( ForwardIterator iter );
extern DLList DLList_Create ( void );
extern void DLList_Empty ( DLList list );
extern void DLList_Destroy ( DLList list );
extern ThotBool DLList_IsEmpty ( DLList list );
extern DLListNode DLList_Append ( DLList list,
                                  ContainerElement elem );
extern DLListNode DLList_Prepend ( DLList list,
                                   ContainerElement elem );
extern DLListNode DLList_InsertAfter ( DLList list,
                                       DLListNode before,
                                       ContainerElement elem );
extern DLListNode DLList_InsertBefore ( DLList list,
                                        DLListNode after,
                                        ContainerElement elem );
extern ContainerElement DLList_RemoveElement ( DLList list,
                                               DLListNode node );
extern void DLList_DestroyElement ( DLList list,
                                    DLListNode node );
extern ForwardIterator DLList_GetForwardIterator ( DLList list );
extern void DLList_Swap ( DLList list,
                          DLListNode node1,
                          DLListNode node2 );
extern void DLList_Sort ( DLList list,
                          Container_CompareFunction compare );
extern DLList DLList_GetRefList ( DLList srcList,
                                  Container_CompareFunction compare );
extern DLList DLList_GetRefListFromIterator ( ForwardIterator iter,
                                              Container_CompareFunction compare );
extern HashMap HashMap_Create ( Container_DestroyElementFunction destroy,
                                HashMap_HashFunction hash,
                                int nbNodes );
extern void HashMap_Empty ( HashMap map );
extern void HashMap_Destroy ( HashMap map );
extern ThotBool HashMap_IsEmpty ( HashMap map );
extern ContainerElement HashMap_Set ( HashMap map,
                                      HashMapKey key,
                                      ContainerElement elem );
extern HashMapNode HashMap_Find ( HashMap map,
                                  HashMapKey key );
extern ContainerElement HashMap_Get ( HashMap map,
                                      HashMapKey key );
extern ContainerElement HashMap_Remove ( HashMap map,
                                         HashMapKey key );
extern void HashMap_DestroyElement ( HashMap map,
                                     HashMapKey key );
extern ForwardIterator HashMap_GetForwardIterator ( HashMap map );
extern HashMap PointerHashMap_Create ( Container_DestroyElementFunction destroy,
                                       int nbNodes );
extern HashMap StringHashMap_Create ( Container_DestroyElementFunction destroy,
                                      ThotBool keyIsStored,
                                      int nbNodes );
extern HashMap KeywordHashMap_Create ( Container_DestroyElementFunction destroy,
                                       ThotBool keyIsStored,
                                       int nbNodes );

#else /* __STDC__ */

extern ContainerElement ContainerNode_GetElement ( ContainerNode node );
extern void Container_DeleteElement ( Container container,
                                        ContainerNode node );
extern void Container_DeleteNode ( Container container,
                                     ContainerNode node );
extern ForwardIterator ForwardIterator_Create ( Container container,
                                                  ForwardIterator_GetFirstFunction getFirst,
                                                  ForwardIterator_GetNextFunction getNext );
extern ContainerNode ForwardIterator_GetFirst ( ForwardIterator iter );
extern ContainerNode ForwardIterator_GetNext ( ForwardIterator iter );
extern DLList DLList_Create ( void );
extern void DLList_Empty ( DLList list );
extern void DLList_Destroy ( DLList list );
extern ThotBool DLList_IsEmpty ( DLList list );
extern DLListNode DLList_Append ( DLList list,
                                    ContainerElement elem );
extern DLListNode DLList_Prepend ( DLList list,
                                     ContainerElement elem );
extern DLListNode DLList_InsertAfter ( DLList list,
                                         DLListNode before,
                                         ContainerElement elem );
extern DLListNode DLList_InsertBefore ( DLList list,
                                          DLListNode after,
                                          ContainerElement elem );
extern ContainerElement DLList_RemoveElement ( DLList list,
                                                 DLListNode node );
extern void DLList_DestroyElement ( DLList list,
                                      DLListNode node );
extern ForwardIterator DLList_GetForwardIterator ( DLList list );
extern void DLList_Swap ( DLList list,
                            DLListNode node1,
                            DLListNode node2 );
extern void DLList_Sort ( DLList list,
                            Container_CompareFunction compare );
extern DLList DLList_GetRefList ( DLList srcList,
                                    Container_CompareFunction compare );
extern DLList DLList_GetRefListFromIterator ( ForwardIterator iter,
                                                Container_CompareFunction compare );
extern HashMap HashMap_Create ( Container_DestroyElementFunction destroy,
                                  HashMap_HashFunction hash,
                                  int nbNodes );
extern void HashMap_Empty ( HashMap map );
extern void HashMap_Destroy ( HashMap map );
extern ThotBool HashMap_IsEmpty ( HashMap map );
extern ContainerElement HashMap_Set ( HashMap map,
                                        HashMapKey key,
                                        ContainerElement elem );
extern HashMapNode HashMap_Find ( HashMap map,
                                    HashMapKey key );
extern ContainerElement HashMap_Get ( HashMap map,
                                        HashMapKey key );
extern ContainerElement HashMap_Remove ( HashMap map,
                                           HashMapKey key );
extern void HashMap_DestroyElement ( HashMap map,
                                       HashMapKey key );
extern ForwardIterator HashMap_GetForwardIterator ( HashMap map );
extern HashMap PointerHashMap_Create ( Container_DestroyElementFunction destroy,
                                         int nbNodes );
extern HashMap StringHashMap_Create ( Container_DestroyElementFunction destroy,
                                        ThotBool keyIsStored,
                                        int nbNodes );
extern HashMap KeywordHashMap_Create ( Container_DestroyElementFunction destroy,
                                         ThotBool keyIsStored,
                                         int nbNodes );

#endif /* __STDC__ */
#endif /* __CEXTRACT__ */
