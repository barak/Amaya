/*
 *   This file was automatically generated by version 1.7 of cextract.
 *   Manual editing not recommended.
 */

#ifndef __CEXTRACT__
#ifdef __STDC__

extern DLList ElemList_Create ( void );
extern ElemListElement ElemListElement_CreateLanguageElement ( int level,
                                                               ElementType type,
                                                               const char* comment,
                                                               Element refElem );
extern ElemListElement ElemListElement_CreateBaseType ( int level,
                                                        const char* name,
                                                        const char* comment,
                                                        Element refElem );
extern ElemListElement ElemListElement_CreateComponent ( int level,
                                                         const char* name,
                                                         const void* declaration,
                                                         const char* comment,
                                                         Element refElem );
extern void ElemListElement_Destroy ( ElemListElement elem );
extern const char* ElemListElement_GetName ( ElemListElement elem );
extern int ElemListElement_Compare ( ElemListElement elem1,
                                     ElemListElement elem2 );

#else /* __STDC__ */

extern DLList ElemList_Create ( void );
extern ElemListElement ElemListElement_CreateLanguageElement ( int level,
                                                                 ElementType type,
                                                                 const char* comment,
                                                                 Element refElem );
extern ElemListElement ElemListElement_CreateBaseType ( int level,
                                                          const char* name,
                                                          const char* comment,
                                                          Element refElem );
extern ElemListElement ElemListElement_CreateComponent ( int level,
                                                           const char* name,
                                                           const void* declaration,
                                                           const char* comment,
                                                           Element refElem );
extern void ElemListElement_Destroy ( ElemListElement elem );
extern const char* ElemListElement_GetName ( ElemListElement elem );
extern int ElemListElement_Compare ( ElemListElement elem1,
                                       ElemListElement elem2 );

#endif /* __STDC__ */
#endif /* __CEXTRACT__ */
