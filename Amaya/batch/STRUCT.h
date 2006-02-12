/* Definitions for compiler of language STRUCT */

/*  SHORT KEY-WORDS  */

#define CHR_59 	1001
#define CHR_61 	1002
#define CHR_40 	1003
#define CHR_41 	1004
#define CHR_44 	1005
#define CHR_33 	1006
#define CHR_43 	1007
#define CHR_45 	1008
#define CHR_91 	1009
#define CHR_46 	1010
#define CHR_93 	1011
#define CHR_63 	1012
#define CHR_42 	1013
#define CHR_58 	1014

/*  LONG KEY-WORDS  */

#define KWD_STRUCTURE 	1101
#define KWD_EXTENSION 	1102
#define KWD_DEFPRES 	1103
#define KWD_ATTR 	1104
#define KWD_CONST 	1105
#define KWD_STRUCT 	1106
#define KWD_EXTENS 	1107
#define KWD_UNITS 	1108
#define KWD_EXPORT 	1109
#define KWD_EXCEPT 	1110
#define KWD_END 	1111
#define KWD_INTEGER 	1112
#define KWD_TEXT 	1113
#define KWD_REFERENCE 	1114
#define KWD_ANY 	1115
#define KWD_First 	1116
#define KWD_Second 	1117
#define KWD_GRAPHICS 	1118
#define KWD_SYMBOL 	1119
#define KWD_PICTURE 	1120
#define KWD_UNIT 	1121
#define KWD_NATURE 	1122
#define KWD_WITH 	1123
#define KWD_EXTERN 	1124
#define KWD_INCLUDED 	1125
#define KWD_LIST 	1126
#define KWD_OF 	1127
#define KWD_BEGIN 	1128
#define KWD_AGGREGATE 	1129
#define KWD_CASE 	1130
#define KWD_CONSTANT 	1131
#define KWD_PAIR 	1132
#define KWD_Nothing 	1133
#define KWD_NoCut 	1134
#define KWD_CanCut 	1135
#define KWD_NoCreate 	1136
#define KWD_NoReplicate 	1137
#define KWD_NoHMove 	1138
#define KWD_NoVMove 	1139
#define KWD_NoMove 	1140
#define KWD_NoHResize 	1141
#define KWD_NoVResize 	1142
#define KWD_NoResize 	1143
#define KWD_MoveResize 	1144
#define KWD_NewWidth 	1145
#define KWD_NewHeight 	1146
#define KWD_NewPercentWidth 	1147
#define KWD_NewHPos 	1148
#define KWD_NewVPos 	1149
#define KWD_Invisible 	1150
#define KWD_Hidden 	1151
#define KWD_PageBreak 	1152
#define KWD_PageBreakAllowed 	1153
#define KWD_PageBreakPlace 	1154
#define KWD_PageBreakRepetition 	1155
#define KWD_PageBreakRepBefore 	1156
#define KWD_NoPaginate 	1157
#define KWD_NoSpellCheck 	1158
#define KWD_ActiveRef 	1159
#define KWD_NoSelect 	1160
#define KWD_HighlightChildren 	1161
#define KWD_ExtendedSelection 	1162
#define KWD_SelectParent 	1163
#define KWD_ClickableSurface 	1164
#define KWD_ParagraphBreak 	1165
#define KWD_IsBreak 	1166
#define KWD_ReturnCreateNL 	1167
#define KWD_ReturnCreateWithin 	1168
#define KWD_NoBreakByReturn 	1169
#define KWD_ImportLine 	1170
#define KWD_ImportParagraph 	1171
#define KWD_GraphCreation 	1172
#define KWD_IsDraw 	1173
#define KWD_IsGroup 	1174
#define KWD_EmptyGraphic 	1175
#define KWD_IsTable 	1176
#define KWD_IsRow 	1177
#define KWD_IsColHead 	1178
#define KWD_IsCell 	1179
#define KWD_IsCaption 	1180
#define KWD_ColRef 	1181
#define KWD_ColSpan 	1182
#define KWD_RowSpan 	1183
#define KWD_CssBackground 	1184
#define KWD_CssClass 	1185
#define KWD_CssId 	1186
#define KWD_CssPseudoClass 	1187
#define KWD_NoShowBox 	1188
#define KWD_SetWindowBackground 	1189
#define KWD_Shadow 	1190
#define KWD_EventAttr 	1191
#define KWD_SpacePreserve 	1192
#define KWD_IsPlaceholder 	1193
#define KWD_StartCounter 	1194
#define KWD_SetCounter 	1195
#define KWD_MarkupPreserve 	1196
#define KWD_Root 	1197

/*  RULES  */

#define RULE_StructModel 	   1
#define RULE_ElemName 	   2
#define RULE_PresentName 	   3
#define RULE_AttrList 	   4
#define RULE_ConstList 	   5
#define RULE_RuleList 	   6
#define RULE_ExtensList 	   7
#define RULE_ExpList 	   8
#define RULE_ExceptList 	   9
#define RULE_Attribute 	  10
#define RULE_AttrName 	  11
#define RULE_AttrType 	  12
#define RULE_TypeRef 	  13
#define RULE_ValueList 	  14
#define RULE_FirstSec 	  15
#define RULE_ExtStruct 	  16
#define RULE_AttrValue 	  17
#define RULE_Const 	  18
#define RULE_ConstName 	  19
#define RULE_ConstValue 	  20
#define RULE_BasicType 	  21
#define RULE_Rule 	  22
#define RULE_LocAttrList 	  23
#define RULE_DefWith 	  24
#define RULE_LocalAttr 	  25
#define RULE_Definition 	  26
#define RULE_InclList 	  27
#define RULE_ExclList 	  28
#define RULE_FixedAttrList 	  29
#define RULE_InclElem 	  30
#define RULE_ExclElem 	  31
#define RULE_Constr 	  32
#define RULE_Element 	  33
#define RULE_ExtOrDef 	  34
#define RULE_min 	  35
#define RULE_max 	  36
#define RULE_OptDefList 	  37
#define RULE_DefList 	  38
#define RULE_OptDefWith 	  39
#define RULE_Integer 	  40
#define RULE_FixedAttr 	  41
#define RULE_FixModValue 	  42
#define RULE_FixedValue 	  43
#define RULE_NumValue 	  44
#define RULE_StrValue 	  45
#define RULE_Export 	  46
#define RULE_Content 	  47
#define RULE_Except 	  48
#define RULE_ExceptType 	  49
#define RULE_ExValList 	  50
#define RULE_ExceptVal 	  51
#define RULE_ExceptNum 	  52
#define RULE_Extens 	  53
#define RULE_RootOrElem 	  54
