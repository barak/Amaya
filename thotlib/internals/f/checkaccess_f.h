/*
 *   This file was automatically generated by version 1.7 of cextract.
 *   Manual editing not recommended.
 */

#ifndef __CEXTRACT__
#ifdef __STDC__

extern void HierarchicalCheckHiddenAccess ( PtrElement pEl,
                                            boolean * isHidden );
extern void HierarchicalCheckReadOnlyAccess ( PtrElement pEl,
                                              boolean * isReadOnly );
extern void HierarchicalCheckInsertNearElement ( PtrElement pEl,
                                                 boolean beforeElement,
                                                 boolean * cannotInsert );
extern void TtaSetCheckAccessFunctions ( Proc checkHiddenProc,
                                         Proc checkReadOnlyProc,
                                         Proc checkInsertProc );
extern void CheckAccessLoadResources ( void );

#else /* __STDC__ */

extern void HierarchicalCheckHiddenAccess (/* PtrElement pEl,
                                              boolean * isHidden */);
extern void HierarchicalCheckReadOnlyAccess (/* PtrElement pEl,
                                                boolean * isReadOnly */);
extern void HierarchicalCheckInsertNearElement (/* PtrElement pEl,
                                                   boolean beforeElement,
                                                   boolean * cannotInsert */);
extern void TtaSetCheckAccessFunctions (/* Proc checkHiddenProc,
                                           Proc checkReadOnlyProc,
                                           Proc checkInsertProc */);
extern void CheckAccessLoadResources (/* void */);

#endif /* __STDC__ */
#endif /* __CEXTRACT__ */
