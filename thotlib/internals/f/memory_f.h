/*
 *   This file was automatically generated by version 1.7 of cextract.
 *   Manual editing not recommended.
 */

#ifndef __CEXTRACT__
#ifdef __STDC__

extern void *TtaGetMemory ( unsigned int n );
extern void TtaFreeMemory ( void* ptr );
extern char *TtaStrdup ( char *str );
extern void *TtaRealloc ( void *ptr,
                          unsigned int n );
extern void InitEditorMemory ( void );
extern void GetTextBuffer ( PtrTextBuffer * pBT );
extern void FreeTextBuffer ( PtrTextBuffer pBT );
extern void GetElement ( PtrElement * pEl );
extern void FreeElement ( PtrElement pEl );
extern void GetAttribute ( PtrAttribute * pAttr );
extern void FreeAttribute ( PtrAttribute pAttr );
extern void GetReferredDescr ( PtrReferredDescr * pDR );
extern void FreeReferredDescr ( PtrReferredDescr pDR );
extern void GetDescCopy ( PtrCopyDescr * pDC );
extern void FreeDescCopy ( PtrCopyDescr pDC );
extern void GetExternalDoc ( PtrExternalDoc * pDE );
extern void FreeExternalDoc ( PtrExternalDoc pDE );
extern void GetReference ( PtrReference * pRef );
extern void FreeReference ( PtrReference pRef );
extern void GetOutputRef ( PtrOutReference * pRS );
extern void FreeOutputRef ( PtrOutReference pRS );
extern void GetChangedReferredEl ( PtrChangedReferredEl * pER );
extern void FreeChangedReferredEl ( PtrChangedReferredEl pER );
extern void GetInputRef ( PtrEnteringReferences * pRE );
extern void FreeInputRef ( PtrEnteringReferences pRE );
extern void GetFileRefChng ( PtrReferenceChange * pFRC );
extern void FreeFileRefChng ( PtrReferenceChange pFRC );
extern void GetAbstractBox ( PtrAbstractBox *pAb );
extern void FreeAbstractBox ( PtrAbstractBox pAb );
extern void GetDocument ( PtrDocument * pDoc );
extern void FreeDocument ( PtrDocument pDoc );
extern void GetAttributePres ( AttributePres **pAP,
                               int n );
extern void FreeAttributePres ( AttributePres *pAP );
extern void GetSchPres ( PtrPSchema * pSP );
extern void FreeSchPres ( PtrPSchema pSP );
extern void GetHandleSchPres ( PtrHandlePSchema * pHSP );
extern void FreeHandleSchPres ( PtrHandlePSchema pHSP );
extern void GetTRule ( PtrTRule *pR );
extern void FreeTRule ( PtrTRule pR );
extern void GetSchTra ( PtrTSchema *pST );
extern void FreeSchTra ( PtrTSchema pST );
extern void GetExternalBlock ( PtrExtensBlock * pBE );
extern void FreeExternalBlock ( PtrExtensBlock pBE );
extern void GetSchStruct ( PtrSSchema * pSS );
extern void FreeSchStruc ( PtrSSchema pSS );
extern void GetPresentRule ( PtrPRule * pRP );
extern void FreePresentRule ( PtrPRule pRP );
extern void GetPresentRuleCond ( PtrCondition * pCond );
extern void FreePresentRuleCond ( PtrCondition pCond );
extern void GetDifferedRule ( PtrDelayedPRule * pRR );
extern void FreeDifferedRule ( PtrDelayedPRule pRR );
extern void InitKernelMemory ( void );
extern void GetPosBlock ( PtrPosRelations * pBlock );
extern void FreePosBlock ( PtrPosRelations * pBlock );
extern void GetDimBlock ( PtrDimRelations * pBlock );
extern void FreeDimBlock ( PtrDimRelations * pBlock );
extern PtrBox GetBox ( PtrAbstractBox pAb );
extern PtrBox FreeBox ( PtrBox pBox );
extern void GetLine ( PtrLine * pLine );
extern void FreeLine ( PtrLine pLine );
extern void GetSearchContext ( PtrSearchContext * pSearch );
extern void FreeSearchContext ( PtrSearchContext * pSearch );
extern void FreeStringInDict ( PtrDict pDict );
extern int GetStringInDict ( PtrDict * pDict,
                             boolean readonly );
extern void GetDictionary ( PtrDict * pDict );
extern void FreeDictionary ( PtrDict pDict );

#else /* __STDC__ */

extern void *TtaGetMemory (/* unsigned int n */);
extern void TtaFreeMemory (/* void* ptr */);
extern char *TtaStrdup (/* char *str */);
extern void *TtaRealloc (/* void *ptr,
                            unsigned int n */);
extern void InitEditorMemory (/* void */);
extern void GetTextBuffer (/* PtrTextBuffer * pBT */);
extern void FreeTextBuffer (/* PtrTextBuffer pBT */);
extern void GetElement (/* PtrElement * pEl */);
extern void FreeElement (/* PtrElement pEl */);
extern void GetAttribute (/* PtrAttribute * pAttr */);
extern void FreeAttribute (/* PtrAttribute pAttr */);
extern void GetReferredDescr (/* PtrReferredDescr * pDR */);
extern void FreeReferredDescr (/* PtrReferredDescr pDR */);
extern void GetDescCopy (/* PtrCopyDescr * pDC */);
extern void FreeDescCopy (/* PtrCopyDescr pDC */);
extern void GetExternalDoc (/* PtrExternalDoc * pDE */);
extern void FreeExternalDoc (/* PtrExternalDoc pDE */);
extern void GetReference (/* PtrReference * pRef */);
extern void FreeReference (/* PtrReference pRef */);
extern void GetOutputRef (/* PtrOutReference * pRS */);
extern void FreeOutputRef (/* PtrOutReference pRS */);
extern void GetChangedReferredEl (/* PtrChangedReferredEl * pER */);
extern void FreeChangedReferredEl (/* PtrChangedReferredEl pER */);
extern void GetInputRef (/* PtrEnteringReferences * pRE */);
extern void FreeInputRef (/* PtrEnteringReferences pRE */);
extern void GetFileRefChng (/* PtrReferenceChange * pFRC */);
extern void FreeFileRefChng (/* PtrReferenceChange pFRC */);
extern void GetAbstractBox (/* PtrAbstractBox *pAb */);
extern void FreeAbstractBox (/* PtrAbstractBox pAb */);
extern void GetDocument (/* PtrDocument * pDoc */);
extern void FreeDocument (/* PtrDocument pDoc */);
extern void GetAttributePres (/* AttributePres **pAP,
                                 int n */);
extern void FreeAttributePres (/* AttributePres *pAP */);
extern void GetSchPres (/* PtrPSchema * pSP */);
extern void FreeSchPres (/* PtrPSchema pSP */);
extern void GetHandleSchPres (/* PtrHandlePSchema * pHSP */);
extern void FreeHandleSchPres (/* PtrHandlePSchema pHSP */);
extern void GetTRule (/* PtrTRule *pR */);
extern void FreeTRule (/* PtrTRule pR */);
extern void GetSchTra (/* PtrTSchema *pST */);
extern void FreeSchTra (/* PtrTSchema pST */);
extern void GetExternalBlock (/* PtrExtensBlock * pBE */);
extern void FreeExternalBlock (/* PtrExtensBlock pBE */);
extern void GetSchStruct (/* PtrSSchema * pSS */);
extern void FreeSchStruc (/* PtrSSchema pSS */);
extern void GetPresentRule (/* PtrPRule * pRP */);
extern void FreePresentRule (/* PtrPRule pRP */);
extern void GetPresentRuleCond (/* PtrCondition * pCond */);
extern void FreePresentRuleCond (/* PtrCondition pCond */);
extern void GetDifferedRule (/* PtrDelayedPRule * pRR */);
extern void FreeDifferedRule (/* PtrDelayedPRule pRR */);
extern void InitKernelMemory (/* void */);
extern void GetPosBlock (/* PtrPosRelations * pBlock */);
extern void FreePosBlock (/* PtrPosRelations * pBlock */);
extern void GetDimBlock (/* PtrDimRelations * pBlock */);
extern void FreeDimBlock (/* PtrDimRelations * pBlock */);
extern PtrBox GetBox (/* PtrAbstractBox pAb */);
extern PtrBox FreeBox (/* PtrBox pBox */);
extern void GetLine (/* PtrLine * pLine */);
extern void FreeLine (/* PtrLine pLine */);
extern void GetSearchContext (/* PtrSearchContext * pSearch */);
extern void FreeSearchContext (/* PtrSearchContext * pSearch */);
extern void FreeStringInDict (/* PtrDict pDict */);
extern int GetStringInDict (/* PtrDict * pDict,
                               boolean readonly */);
extern void GetDictionary (/* PtrDict * pDict */);
extern void FreeDictionary (/* PtrDict pDict */);

#endif /* __STDC__ */
#endif /* __CEXTRACT__ */
