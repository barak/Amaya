/*
 *   This file was automatically generated by version 1.7 of cextract.
 *   Manual editing not recommended.
 */

#ifndef __CEXTRACT__
#ifdef __STDC__

extern void WriteShort ( int n );
extern void WriteSignedShort ( int n );
extern void WriteName ( Name n );
extern void WriteBoolean ( ThotBool b );
extern void WriteTransCondition ( TransCondition cond );
extern void WriteRelatNAscend ( RelatNAscend rel );
extern void WriteTRuleType ( TRuleType typ );
extern void WriteTOrder ( TOrder order );
extern void WriteCreatedObject ( CreatedObject obj );
extern void WriteRelativePosition ( TRelatPosition pos );
extern void WriteTCounterOp ( TCounterOp op );
extern void WriteTVarType ( TranslVarType typ );
extern void WriteCounterStyle ( CounterStyle style );
extern void WriteTRulePtr ( PtrTRule ptr );
extern void WriteTRules ( PtrTRule pTRule );
extern void WriteBlockPtr ( PtrTRuleBlock pBlock );
extern void WriteBlocks ( PtrTRuleBlock pBlock,
                          PtrSSchema pSS );
extern void WriteTRulesAttr ( int att,
                              PtrSSchema pSS,
                              PtrTSchema pTSch );
extern void WritePRuleTrans ( int pres,
                              PtrSSchema pSS,
                              PtrTSchema pTSch );
extern ThotBool WriteTranslationSchema ( Name fileName,
                                         PtrTSchema pTSch,
                                         PtrSSchema pSS );

#else /* __STDC__ */

extern void WriteShort ( int n );
extern void WriteSignedShort ( int n );
extern void WriteName ( Name n );
extern void WriteBoolean ( ThotBool b );
extern void WriteTransCondition ( TransCondition cond );
extern void WriteRelatNAscend ( RelatNAscend rel );
extern void WriteTRuleType ( TRuleType typ );
extern void WriteTOrder ( TOrder order );
extern void WriteCreatedObject ( CreatedObject obj );
extern void WriteRelativePosition ( TRelatPosition pos );
extern void WriteTCounterOp ( TCounterOp op );
extern void WriteTVarType ( TranslVarType typ );
extern void WriteCounterStyle ( CounterStyle style );
extern void WriteTRulePtr ( PtrTRule ptr );
extern void WriteTRules ( PtrTRule pTRule );
extern void WriteBlockPtr ( PtrTRuleBlock pBlock );
extern void WriteBlocks ( PtrTRuleBlock pBlock,
                            PtrSSchema pSS );
extern void WriteTRulesAttr ( int att,
                                PtrSSchema pSS,
                                PtrTSchema pTSch );
extern void WritePRuleTrans ( int pres,
                                PtrSSchema pSS,
                                PtrTSchema pTSch );
extern ThotBool WriteTranslationSchema ( Name fileName,
                                           PtrTSchema pTSch,
                                           PtrSSchema pSS );

#endif /* __STDC__ */
#endif /* __CEXTRACT__ */