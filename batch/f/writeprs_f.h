/*
 *   This file was automatically generated by version 1.7 of cextract.
 *   Manual editing not recommended.
 */

#ifndef __CEXTRACT__
#ifdef __STDC__

extern void WritePRuleType ( PRuleType ruleType );
extern void WritePresCondition ( PresCondition cond );
extern void WriteVariableType ( VariableType typ );
extern void WriteContentType ( ContentType typ );
extern void WritePRules ( PtrPRule pPRule );
extern boolean WritePresentationSchema ( Name fileName,
                                         PtrPSchema pPSch,
                                         PtrSSchema pSS );

#else /* __STDC__ */

extern void WritePRuleType (/* PRuleType ruleType */);
extern void WritePresCondition (/* PresCondition cond */);
extern void WriteVariableType (/* VariableType typ */);
extern void WriteContentType (/* ContentType typ */);
extern void WritePRules (/* PtrPRule pPRule */);
extern boolean WritePresentationSchema (/* Name fileName,
                                           PtrPSchema pPSch,
                                           PtrSSchema pSS */);

#endif /* __STDC__ */
#endif /* __CEXTRACT__ */
