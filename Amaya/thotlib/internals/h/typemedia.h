/*
 *
 *  (c) COPYRIGHT INRIA, 1996-2005
 *  Please first read the full copyright statement in file COPYRIGHT.
 *
 */

/*
 * Type declarations for the formatter
 *
 * Authors: V. Quint, I. Vatton (INRIA)
 *
 */

#ifndef _TYPEMEDIA_H
#define _TYPEMEDIA_H

#include "typeint.h"
#include "typecorr.h"
#include "typetra.h"

typedef struct _FontSet      *SpecFont;
typedef struct _FontSet {
  SpecFont      NextFontSet;
  ThotBool      specificFont; /* TRUE when the specific font is used */
  int           FontFamily;
  int           FontHighlight;
  int           FontSize;
  unsigned int  FontMask;
  ThotFont      Font_1;
  ThotFont      Font_2;
  ThotFont      Font_3;
  ThotFont      Font_4;
  ThotFont      Font_5;
  ThotFont      Font_6;
  ThotFont      Font_7;
  ThotFont      Font_8;
  ThotFont      Font_9;
  ThotFont      Font_13;
  ThotFont      Font_15;
  ThotFont      Font_16; /* Symbol */
  ThotFont      Font_17; /* Arabic or JIS */
  ThotFont      Font_18; /* Georgian */
  ThotFont      SFont_1; /* STIX fonts */
  ThotFont      SFont_2;
  ThotFont      SFont_3;
  ThotFont      SFont_4;
  ThotFont      SFont_5;
  ThotFont      SFont_6;
  ThotFont      SFont_7;
  ThotFont      SFont_8;
  ThotFont      SFont_9;
  ThotFont      SFont_10;
  ThotFont      SFont_11;
  ThotFont      SFont_12;
  ThotFont      SFont_13;
  ThotFont      SFont_14;
  ThotFont      SFont_15;
  ThotFont      SFont_16;
  ThotFont      SFont_17;
} FontSet;

typedef unsigned char RuleSet[32];

/* List of pointers used */
typedef struct _Box *PtrBox;
typedef Buffer *PtrBuffer;
typedef struct _Line *PtrLine;

/* Type of a described box */
typedef enum
{
  BoComplete,
  BoSplit,
  BoPiece,
  BoMulScript,
  BoScript,
  BoBlock,
  BoPicture,
  BoGhost,
  BoDotted,
  BoTable,
  BoRow,
  BoColumn,
  BoCell,
  BoFloatBlock,
  BoFloatGhost
} BoxType;

/* Type of relation between boxes:
   Dep(H, V) -> the relation binds two sibling boxes
   Inc(H, V) -> the box is bound to its parent box
   Ref(H, V) -> the box is bound to a reference axis
   Dim(H, V) -> the box modifies the elastic dimension of the other box */
typedef enum
  {
    OpHorizDep, 
    OpVertDep,
    OpHorizInc,
    OpVertInc,
    OpHorizRef,
    OpVertRef,
    OpWidth,
    OpHeight
  } OpRelation;

/* Type of dim relation between boxes:
   OpSame    -> Relation on the same dimension
   OpReverse -> Relation between a width and a height
   OpIgnore  -> Just keep the reverse relation (necessary to update) */
typedef enum
  {
    OpSame,
    OpReverse, 
    OpIgnore
  } OpDim;

/* Domain of propagation of the modifications between boxes */
typedef enum
  {
    ToSiblings,
    ToChildren,
    ToAll
  } Propagation;

typedef struct _ViewSelection
{
  PtrLine        VsLine;	  /* Line containing the selection */
  PtrBox         VsBox;	    /* Number of the selection mark box */
  PtrTextBuffer  VsBuffer;	/* Selection mark buffer address */
  int            VsIndBox;	/* Selection mark character index */
  int            VsNSpaces;	/* Number of leading spaces */
  int            VsXPos;	  /* Selection box shift */
  int 		       VsIndBuf;	/* Index of the character in the buffer */
} ViewSelection;

/* Desription of a displayed line */
typedef struct _Line
{
  PtrLine         LiPrevious;	/* Lines linking */
  PtrLine         LiNext;
  int             LiXOrg;	/* X origin from the block */
  int             LiYOrg;	/* Y origin from the block */
  int	            LiXMax;	/* Maximum X in pixels */
  int	            LiRealLength;	/* Current width */
  int	            LiMinLength;	/* Current compressed width */
  int	            LiHeight;	/* Current height */
  int	            LiHorizRef;	/* Current base */
  int	            LiSpaceWidth; /* Size in pixels of the adjusted spaces */
  int	            LiNSpaces;	/* Number of spaces in the line */
  int	            LiNPixels;	/* Remaining pixels after adjustment */
  PtrBox          LiFirstBox;	/* Index of the first contained box */
  PtrBox          LiFirstPiece;	/* Index if split box */
  PtrBox          LiLastBox;	/* Index of last contained box */
  PtrBox          LiLastPiece;	/* Index if split box */
  ThotBool        LiNoOverlap;  /* The line cannot overlap */
} ThotLine;

/* Desription of a list of float */
typedef struct _BFloat *PtrFloat;
typedef struct _BFloat
{
  PtrFloat       FlPrevious;	/* Floats linking */
  PtrFloat       FlNext;
  PtrBox         FlBox;	        /* the floating box */
} BFloat;

typedef struct _BoxRelation
{
  PtrBox         ReBox;	        /* Index of the depending box */
  BoxEdge        ReRefEdge;	/* Reference of the box */
  OpRelation     ReOp;		/* Applied relation */
} BoxRelation;

typedef struct _PosRelations *PtrPosRelations;
typedef struct _PosRelations
{
  PtrPosRelations  PosRNext;	/* Next block */
  BoxRelation      PosRTable[MAX_RELAT_POS];
} PosRelations;

typedef struct _DimRelations *PtrDimRelations;
typedef struct _DimRelations
{
  PtrDimRelations DimRNext;	/* Next block */
  PtrBox          DimRTable[MAX_RELAT_DIM];
  OpDim           DimROp[MAX_RELAT_DIM]; /* Description of the relation */
} DimRelations;

/* Structure to store table information */
typedef struct _TabRelations *PtrTabRelations;
typedef struct _TabRelations
{
  PtrTabRelations  TaRNext;	/* Next block */
  PtrAbstractBox   TaRTable[MAX_RELAT_DIM];
  int              TaRTWidths[MAX_RELAT_DIM];
  int              TaRTPercents[MAX_RELAT_DIM];
} TabRelations;

typedef struct _TabSpan *PtrTabSpan;
typedef struct _TabSpan
{
  PtrTabSpan       TaSpanNext;	/* Next block */
  PtrAbstractBox   TaSpanCell[MAX_RELAT_DIM];
  int              TaSpanNumber[MAX_RELAT_DIM];
} TabSpan;

/* Structure to store table updates */
typedef struct _TabUpdate *PtrTabUpdate;
typedef struct _TabUpdate
{
  PtrTabUpdate     TaUNext;	/* Next block */
  PtrAbstractBox   TaUTable;
  PtrAbstractBox   TaUColumn;
  int              TaUFrame;
} TabUpdate;

typedef struct _Box
{
  PtrAbstractBox  BxAbstractBox;     /* Pointer to the associated abstract box */
  PtrBox          BxPrevious;	       /* Previous displayable box */
  PtrBox          BxNext;	           /* Next displayable box */
  int	            BxNChars;	         /* Total number of characters in the box */
  int             BxIndChar;	       /* 0 or position of the split box */
  int             BxXOrg;	           /* X origin from the root */
  int             BxYOrg;	           /* Y origin from the root */
  int             BxHeight;	         /* Box height including margins */
  int             BxWidth;	         /* Box width including margins */
  int             BxH;	        	   /* Inner height */
  int             BxW;	        	   /* Inner Width including spaces */
  int             BxTMargin;	       /* Top Margin */
  int             BxLMargin;	       /* Left Margin */
  int             BxBMargin;	       /* Bottom Margin */
  int             BxRMargin;	       /* Right Margin */
  int             BxTBorder;	       /* Top Border */
  int             BxLBorder;	       /* Left Border */
  int             BxBBorder;	       /* Bottom Border */
  int             BxRBorder;	       /* Right Border */

  int             BxTPadding;	       /* Top Padding */
  int             BxLPadding;	       /* Left Padding */
  int             BxBPadding;	       /* Bottom Padding */
  int             BxRPadding;	       /* Right Padding */
#ifdef _GL
  int             BxClipX; 
  int             BxClipY; 
  int             BxClipW;
  int             BxClipH;
  int             DisplayList;        /*Video Memory index of precomputed visual*/
  void            *Pre_computed_Pic;  /*Pic of the rendered content, used
                                        for group, for example*/
  void            *Post_computed_Pic; /*Pic of the rendered content, used
                                        for group, for example*/
#endif /*_GL*/
  
  int             BxHorizRef;	        /* Current base */
  int             BxVertRef;	        /* Current vertical reference */
  int             BxEndOfBloc;	      /* Fill length:
                                         >0 if last box of a line block
                                         AlignLeftDots. */
  int		          BxUnderline;	      /* Underlining type */
  int             BxThickness;	      /* Line thickness */
  PtrPosRelations BxPosRelations;	    /* Dependencies on positions */
  PtrDimRelations BxWidthRelations;	  /* Dependencies in width */
  PtrDimRelations BxHeightRelations;	/* Dependencies in height */
  SpecFont        BxFont;	            /* Font bound to the box */
  PtrBox          BxMoved;	          /* Linking of moved boxes */
  PtrBox          BxHorizInc;	        /* Box linking to the enclosing one */
  PtrBox          BxVertInc;	        /* Box linking to the enclosing one */
  BoxEdge         BxHorizEdge;		    /* Position point fixed in X */
  BoxEdge         BxVertEdge;		      /* Position point fixed in Y */
  ThotBool        BxXOutOfStruct;	    /* Out of structure horizontal pos. */
  ThotBool        BxYOutOfStruct;	    /* Out of structure vertical pos. */
  ThotBool        BxWOutOfStruct;	    /* Out of structure width */
  ThotBool        BxHOutOfStruct;	    /* Out of structure height */
  ThotBool        BxHorizInverted;	  /* Inverted horizontal marks */
  ThotBool        BxVertInverted;	    /* Inverted vertical marks */
  ThotBool        BxHorizFlex;        /* The box is elastic */
  ThotBool        BxVertFlex;         /* The box is elastic */
  ThotBool        BxXToCompute;       /* Box being placed in X */
  ThotBool        BxYToCompute;       /* Box being placed in Y */
  ThotBool        BxShrink;           /* Box width should be shrunk */
  ThotBool	      BxNew;	            /* Newly displayed box */
  ThotBool	      BxContentHeight;	  /* Real height is the content height */
  ThotBool	      BxContentWidth;	    /* Real width is the content width */
  ThotBool        BxShadow;		        /* Characters are showed as '*' */
  ThotBool        BxDisplay;	        /* The box has borders or background */
#ifdef _GL
  ThotBool        BxBoundinBoxComputed;
  ThotBool        VisibleModification;    
#endif /* _GL */
  int		          BxRuleHeight;       /* Content height or minimum */
  int		          BxRuleWidth;	      /* Rule width */
  int        	    BxMaxWidth;         /* Inside width */
  PtrTextBuffer   BxBuffer;	          /* Pointer on the buffer list */
  BoxType         BxType;
  union
  {
    struct /* BoPiece */
    {
      PtrBox     _BxNexChild_;	      /* Next split box */
      int	       _BxNSpaces_;	        /* Number of spaces in the text */
      int	       _BxNPixels_;	        /* Number of pixels to share out */
      int	       _BxSpaceWidth_;      /* >0 of the box is justified */
      int	       _BxFirstChar_;	      /* First character in buffer */
      char       _BxScript_;          /* Script of the current text */
      char       _BxFirstScript_;     /*Script of the first element*/
      char       _BxLastScript_;      /*Script of the last element*/
    } s0;
    struct /* BoPicture - used for pictures, polylines and paths */
    {
      union
        {
        int	      *_BxPictInfo_;      /* Image pointer in memory
                                         List of control points for a spline
                                         + twisting ratio of the control
                                         points */
        PtrPathSeg _BxFirstPathSeg_;  /* pointer to the first path segment */
        } u;
      float 	     _BxXRatio_;
      float 	     _BxYRation_;
    } s1;
    struct /* BoBlock*/
    {
      PtrLine 	 _BxFirstLine_;	/* First line if applicable */
      PtrLine 	 _BxLastLine_;	/* Last line */
      int        _BxMinWidth_;  /* Mininmum width */
      int        _BxCycles_;    /* count reformatting cycles */
      int        _BxPacking_;   /* Packing */
      PtrFloat   _BxLeftFloat_; /* list of left floated boxes */
      PtrFloat   _BxRightFloat_;/* list of right floated boxes */
    } s2;
    struct /* BoTable BoColumn BoRow */
    {
      PtrTabRelations 	_BxColumns_;	/* list of columns or table box */
      PtrTabRelations	  _BxRows_;	    /* list of rows within a table */
      int             	_BxMinWidth_; /* Mininmum width */
      int               _BxCycles_;   /* count reformatting cycles */
      int               _BxPacking_;  /* Packing */
      PtrTabSpan        _BxSpans_;	  /* list of spanned cells */
    } s3;
    struct /* BoComplete for Graphics = 'C' */
    {
      int        	_BxRx_;         /* Horizontal radius */
      int        	_BxRy_;         /* Vertical radius */
    } s4;
  } u;
} Box;

#define BxNexChild u.s0._BxNexChild_
#define BxNSpaces u.s0._BxNSpaces_
#define BxNPixels u.s0._BxNPixels_
#define BxSpaceWidth u.s0._BxSpaceWidth_
#define BxFirstChar u.s0._BxFirstChar_
#define BxScript u.s0._BxScript_

#define BxFirstScript u.s0._BxFirstScript_
#define BxLastScript u.s0._BxLastScript_

#define BxPictInfo u.s1.u._BxPictInfo_
#define BxFirstPathSeg u.s1.u._BxFirstPathSeg_
#define BxXRatio u.s1._BxXRatio_
#define BxYRatio u.s1._BxYRation_
#define BxFirstLine u.s2._BxFirstLine_
#define BxLastLine u.s2._BxLastLine_
#define BxMinWidth u.s2._BxMinWidth_
#define BxCycles u.s2._BxCycles_
#define BxPacking u.s2._BxPacking_
#define BxLeftFloat u.s2._BxLeftFloat_
#define BxRightFloat u.s2._BxRightFloat_
#define BxColumns u.s3._BxColumns_
#define BxTable u.s3._BxColumns_
#define BxRows u.s3._BxRows_
#define BxSpans u.s3._BxSpans_
#define BxRx u.s4._BxRx_
#define BxRy u.s4._BxRy_

typedef struct C_points_
{
  float lx, ly, rx, ry;
} C_points; /* Storage of the splines's control points */

/* Description of the relative position of two abstract boxes */
typedef struct _AbPosition
{
  PtrAbstractBox  PosAbRef;	/* Pointer of the reference abstract box */
  int             PosDistance;	/* Distance between the two of them */
  int             PosDistDelta; /* Distance increment */
  BoxEdge         PosEdge;	/* Positioned abstract box mark */
  BoxEdge         PosRefEdge;	/* Reference abstract box mark */
  TypeUnit        PosUnit;	/* Unit used for distance */
  TypeUnit        PosDeltaUnit; /* Unit used for the distance increment */
  ThotBool	      PosUserSpecified;	/* User specified distance */
} AbPosition;

typedef struct _AbDimension
{
  ThotBool	  DimIsPosition;
  union
  {
    struct
    {
      AbPosition  _DimPosition_;
    } s0;
    struct
    {
      PtrAbstractBox _DimAbRef_;	/* Reference abstract box */
      int 	         _DimValue_;	/* Abstract box mandatory dimension
                                     -1: content-defined dimension
                                     0: null size */
      TypeUnit	    _DimUnit_;		/* Dimension in %, picas, etc. */
      ThotBool	    _DimSameDimension_;	/* On the same dimension */
      ThotBool	    _DimUserSpecified_;	/* User-specified dimension */
      ThotBool	    _DimMinimum_;	/* Given dimension is a minimum value */
     } s1;
  } u;
} AbDimension;

#define DimPosition u.s0._DimPosition_
#define DimAbRef u.s1._DimAbRef_
#define DimValue u.s1._DimValue_
#define DimUnit u.s1._DimUnit_
#define DimSameDimension u.s1._DimSameDimension_
#define DimUserSpecified u.s1._DimUserSpecified_
#define DimMinimum u.s1._DimMinimum_

/* Element describing a pending presentation rule */
typedef struct _DelayedPRule *PtrDelayedPRule;
typedef struct _DelayedPRule
{
  PtrPRule        DpPRule;	/* Pointer on the pending rule */
  PtrAbstractBox  DpAbsBox;	/* Pointer on the abstract box on which the
                               rule is to be applied */
  PtrPSchema      DpPSchema;	/* Pointer on the presentation schema owning
                                 the rule */
  PtrAttribute    DpAttribute;	/* Pointer on the attribute to which the rule
                                   corresponds, nil if not attribute rule */
  PtrDelayedPRule DpNext;	/* Next element */
} DelayedPRule;

typedef struct _Positioning
{
  int             PnTopDistance;
  int             PnRightDistance;
  int             PnBottomDistance;
  int             PnLeftDistance;
  PosAlgorithm    PnAlgorithm;
  TypeUnit        PnTopUnit;
  TypeUnit        PnRightUnit;
  TypeUnit        PnBottomUnit;
  TypeUnit        PnLeftUnit;
} Positioning;

/* Description of an abstract images of a document view */
typedef struct _AbstractBox
{
  PtrElement      AbElement;	/* Corresponding element in the I.R. */
  PtrBox          AbBox;	/* Box descriptor index */
  PtrAbstractBox  AbEnclosing;	/* Linking towards the enclosing asbstr. box */
  PtrAbstractBox  AbNext;	/* Linking towards the next sibling abstract box */
  PtrAbstractBox  AbPrevious;	/* Linking towards the previous abstract box */
  PtrAbstractBox  AbFirstEnclosed;  /* Linking towards the first child
                                       abstract box */
  PtrAbstractBox  AbNextRepeated;   /* Linking towards the next repeated
                                       abstract box (laid out??) */
  PtrAbstractBox  AbPreviousRepeated; /* Linking towards the previous
                                         repeated abstract box */
  PtrPSchema      AbPSchema;	   /* Presentation schema of the abstract box*/
  int             AbDocView;	   /* Document view number */
  PtrCopyDescr	  AbCopyDescr;	   /* Descriptor of the copied element if the
                                      abstract box is produced by a Copy rule*/
  PtrAttribute    AbCreatorAttr;   /* Pointer on the attribute that created the
                                      abstract box, if it is an attribute
                                      created presentation abstract box */
  PtrDelayedPRule AbDelayedPRule;  /* Used by the editor */
  int             AbVolume;	   /* Equivalent characters number */
  int	            AbTypeNum;	   /* Type number/presentation box number */
  int             AbVarNum;        /* number of the variable that defines the
                                      content of this box (pres. boxes only) */
  int	            AbNum;	   /* Abstract box number for debug */
  AbPosition      AbVertRef;	   /* Vertical reference mark position */
  AbPosition      AbHorizRef;	   /* Horizontal reference mark position */
  AbPosition      AbVertPos;	   /* Vertical position in the box */
  AbPosition      AbHorizPos;	   /* Horizontal position in the box */
  AbDimension     AbHeight;	   /* Box height */
  AbDimension     AbWidth;	   /* Box width */
  int             AbUnderline;	   /* Underlining type */
  int             AbThickness;	   /* Underlining thickness */
  int             AbIndent;	   /* Indentation for line breaking */
  int             AbDepth;	   /* Abstract box display plane */
  int	            AbVisibility;    /* Abstract box visibility degree */
  int             AbFont;	   /* Font family: index in the family table */
  int             AbFontStyle;	   /* Font style: roman, italic, oblique */
  int             AbFontWeight;	   /* Font weight: normal, bold */
  int             AbSize;	   /* Character logical/real size */
  int             AbLineWeight;    /* Line thickness */
  int             AbLineSpacing;   /* Linespacing */
  int             AbFillPattern;   /* Fill pattern */	
  int             AbBackground;    /* Background color */
  int             AbForeground;    /* Drawing color */
  int             AbFillOpacity;   /* opacity of the fill part of element*/
  int             AbStrokeOpacity; /* opacity of the stroke part element*/
  int             AbOpacity;       /* opacity of all the element*/
  int             AbTopBColor;     /* Border Top color */
  int             AbRightBColor;   /* Border Right color */
  int             AbBottomBColor;  /* Border Bottom color */
  int             AbLeftBColor;    /* Border Left color */
  int             AbTopStyle;      /* Border Top style */
  int             AbRightStyle;    /* Border Right style */
  int             AbBottomStyle;   /* Border Bottom style */
  int             AbLeftStyle;     /* Border Left style */
  int             AbTopMargin;     /* Top Margin */
  int             AbRightMargin;   /* Right Margin */
  int             AbBottomMargin;  /* Bottom Margin */
  int             AbLeftMargin;    /* Left Margin */
  int             AbTopPadding;    /* Top Padding */
  int             AbRightPadding;  /* Right Padding */
  int             AbBottomPadding; /* Bottom Padding */
  int             AbLeftPadding;   /* Left Padding */
  int             AbTopBorder;     /* Top Border */
  int             AbRightBorder;   /* Right Border */
  int             AbBottomBorder;  /* Bottom Border */
  int             AbLeftBorder;    /* Left Border */
  char            AbDirection;        /* Writing direction */
  char            AbUnicodeBidi;      /* Unicode Bidi */
  char            AbLineStyle;        /* Line style */
  char            AbDisplay;          /* Display mode */
  char            AbVis;              /* CSS visibility */
  char            AbListStyleType;    /* type of the list item marker */
  char            AbListStylePosition;/* position of the list item marker */
  char            AbListStyleImage;   /* 'Y' = display an image instead of the
                                         list item marker */
  char            AbFloat;            /* Float mode */
  char            AbClear;            /* Clear mode */
  BAlignment      AbAdjust;	      /* Alignment of lines in the box */
  TypeUnit        AbSizeUnit;         /* Unit for the size */
  TypeUnit        AbIndentUnit;       /* Indentation unit */
  TypeUnit        AbLineWeightUnit;   /* Unit of thickness */
  TypeUnit        AbLineSpacingUnit;  /* Interlining unit */

  TypeUnit        AbTopMarginUnit;    /* Top Margin Unit (includes auto) */
  TypeUnit        AbRightMarginUnit;  /* Right Margin Unit (includes auto) */
  TypeUnit        AbBottomMarginUnit; /* Bottom Margin Unit (includes auto) */
  TypeUnit        AbLeftMarginUnit;   /* Left Margin Unit (includes auto) */
  TypeUnit        AbTopPaddingUnit;   /* Top Padding Unit */
  TypeUnit        AbRightPaddingUnit; /* Right Padding Unit */
  TypeUnit        AbBottomPaddingUnit;/* Bottom Padding Unit */
  TypeUnit        AbLeftPaddingUnit;  /* Left Padding Unit */
  TypeUnit        AbTopBorderUnit;    /* Top Border Unit */
  TypeUnit        AbRightBorderUnit;  /* Right Border Unit */
  TypeUnit        AbBottomBorderUnit; /* Bottom Border Unit */
  TypeUnit        AbLeftBorderUnit;   /* Left Border Unit */

  ThotBool        AbPseudoElBefore;   /* CSS pseudo-element generated by
                                         :before */
  ThotBool        AbPseudoElAfter;    /* CSS pseudo-element generated by
                                         :after */
  ThotBool        AbBuildAll;         /* All descendant abstract boxes must
                                         always be built */
  ThotBool        AbAcceptLineBreak;  /* Can be split in lines */
  ThotBool        AbAcceptPageBreak;  /* Can be split by page breaks */
  ThotBool        AbHyphenate;	      /* Contents can be hyphenated */
  ThotBool        AbOnPageBreak;      /* The box crosses the page limit */
  ThotBool        AbAfterPageBreak;   /* Abstract box beyond the page limit*/
  ThotBool        AbNotInLine;	 /* The abstract box is not part of the line */
  ThotBool        AbHorizEnclosing;   /* True: horizontally enclosed box */
  ThotBool        AbVertEnclosing;    /* True: vertically enclosed box */
  ThotBool        AbCanBeModified;    /* Modification is allowed */
  ThotBool        AbSelected;	      /* The abstract box is selected */
  ThotBool        AbPresentationBox;  /* A presentation box */
  ThotBool        AbRepeatedPresBox;  /* A repeated presentation box */
  ThotBool        AbSensitive;	      /* True: the abstract box is active */
  ThotBool        AbReadOnly;	      /* Abstract box is read only */
  /* Indications of modification for the abstract box */
  ThotBool        AbNew;	      /* Newly created abstract box */
  ThotBool        AbDead;             /* Abstract box to be destroyed */
  ThotBool        AbWidthChange;      /* Change the horizontal dimension */
  ThotBool        AbHeightChange;     /* Change the vertical dimension */
  ThotBool        AbHorizPosChange;   /* Change the horizontal position */
  ThotBool        AbVertPosChange;    /* Change the vertical axis */
  ThotBool        AbHorizRefChange;   /* Change the horizontal axis */
  ThotBool        AbVertRefChange;    /* Change the vertical positioning */
  ThotBool        AbSizeChange;	      /* Change the character size */
  ThotBool        AbAspectChange;     /* Change the graphical aspect: plane,
				         color, pattern, line style */
  ThotBool        AbMBPChange;	      /* Change margins, borders, paddings */
  ThotBool        AbFloatChange;      /* Change the floatting information */
  ThotBool        AbPositionChange;   /* Change positioning algorithm */
  ThotBool        AbChange;	      /* Change of another type */
  LeafType        AbLeafType;
  union
  {
    struct /* AbLeafType = LtCompound */
    {
      int         *_AbPictBackground_;    /* background picture */
      int         *_AbPictListStyle_;     /* list-style image */
      Positioning *_AbPositioning_;       /* 0 if normal flow (static) */
      ThotBool     _AbFillBox_;           /* True: a fill box is displayed */
      ThotBool	   _AbInLine_;
      /* The following two fields only make sense if AbInLine = False */
      ThotBool	   _AbTruncatedHead_; /* Beginning of box contents is missing*/
      ThotBool	   _AbTruncatedTail_; /* End of box contents is missing */
    } s0;
    struct /* AbLeafType = LtText */
    {
      PtrTextBuffer _AbText_;     /* On first text buffer */
      Language      _AbLang_;     /* Language or script used */
    } s1;
    struct /* AbLeafType = LtGraphics or LtSymbol */
    {
      char          _AbShape_;         /* Drawing code */
      char          _AbGraphScript_; /* Script used*/
      char          _AbRealShape_;     /* Effective drawing code */
      int           _AbRx_;            /* Horizontal radius */
      int           _AbRy_;            /* Vertical radius */     
      TypeUnit      _AbRxUnit_;        /* Unit for the horizontal radius */
      TypeUnit      _AbRyUnit_;        /* Unit for the vertical radius */
    } s2;
    struct /* AbLeafType = LtPicture */
    {
      int          *_AbPictInfo_;
    } s3;
    struct /* AbLeafType = LtPolyline  */
    {
      PtrTextBuffer _AbPolyLineBuffer_; /* First buffer */
      char          _AbPolyLineShape_;  /* Drawing type */
    } s4;
    struct /* AbLeafType = LtPath  */
    {
      PtrPathSeg    _AbFirstPathSeg_;   /* First path segment */
    } s5;
  } u;
} AbstractBox;

#define AbPictBackground u.s0._AbPictBackground_
#define AbPictListStyle u.s0._AbPictListStyle_
#define AbPositioning u.s0._AbPositioning_
#define AbFillBox u.s0._AbFillBox_
#define AbInLine u.s0._AbInLine_
#define AbTruncatedHead u.s0._AbTruncatedHead_
#define AbTruncatedTail u.s0._AbTruncatedTail_
#define AbText u.s1._AbText_
#define AbLang u.s1._AbLang_
#define AbShape u.s2._AbShape_
#define AbGraphScript u.s2._AbGraphScript_
#define AbRealShape u.s2._AbRealShape_
#define AbRx u.s2._AbRx_
#define AbRy u.s2._AbRy_
#define AbRxUnit u.s2._AbRxUnit_
#define AbRyUnit u.s2._AbRyUnit_
#define AbPictInfo u.s3._AbPictInfo_
#define AbPolyLineBuffer u.s4._AbPolyLineBuffer_
#define AbPolyLineShape u.s4._AbPolyLineShape_
#define AbFirstPathSeg u.s5._AbFirstPathSeg_

typedef struct _Flow *PtrFlow;
typedef struct _Flow
{
  PtrAbstractBox  FlRootBox;  /* Pointer to the associated root abstract box */
  PtrFlow         FlPrevious; /* Previous Flow */
  PtrFlow         FlNext;     /* Next Flow */
  PosAlgorithm    FlType;     /* Flow type: PnRelative, PnAbsolute, PnFixed */
  int             FlXStart;   /* Clipping zone of this flow */
  int             FlYStart;
}Flow;

typedef struct _ViewFrame
{
  PtrAbstractBox  FrAbstractBox;/* Pointer on the root abstract box of the View */
  int             FrXOrg;	/* X origin from root */
  int             FrYOrg;       /* Y origin from root */
#ifdef _GL
  int             OldFrXOrg;	   /* X origin from root for not opengl computed boxes*/
  int             OldFrYOrg;       /* Y origin from root for not opengl computed boxes*/
#endif /*_GL*/
  int             FrVolume;	/* Character volume in the window */
  int             FrClipXBegin;	/* X beginning of the display rectangle */
  int             FrClipXEnd;	/* X ending of the display rectangle */
  int             FrClipYBegin;	/* Y beginning of the display rectangle */
  int             FrClipYEnd;	/* Y ending of the display rectangle */
  ThotBool        FrReady;	/* The window can be displayed */
  ThotBool        FrSelectOneBox;	/* Only one box is selected */
  ThotBool        FrSelectShown;	/* The selection is shown */
  ThotBool	      FrSelectOnePosition;  /* The selection is limited */
  ViewSelection   FrSelectionBegin;	/* Beginning mark of the selection */
  ViewSelection   FrSelectionEnd;	/* End mark of the selection */
  int             FrVisibility;		/* Window visibility threshold */
  int             FrMagnification;	/* Window zoom factor */
  PtrFlow         FrFlow;       /* Pointer to extra flows */
} ViewFrame;

typedef struct _VueDeDoc
{
  int             VdView;
  Name            VdViewName;
  PtrSSchema      VdSSchema;
  ThotBool        VdOpen;
  ThotBool        VdExist;
  ThotBool        VdNature;
  ThotBool        VdPaginated;
} DocumentView;

typedef DocumentView AvailableView[MAX_VIEW_OPEN];

/* Declaration of a research domain context */
typedef struct _SearchContext
{
  PtrDocument	SDocument;	/* Document where the search is on */
  int		      STree;		/* Number of the current tree for a
                           document-wide search */
  PtrElement	SStartElement;	/* Research starting element */
  int		      SStartChar;	/* Research starting character */
  PtrElement	SEndElement;	/* Research ending element */
  int         SEndChar;	/* Research ending character */
  ThotBool    SStartToEnd;	/* Forward search */
  ThotBool    SWholeDocument;	/* Document-wide search */
} SearchContext;
typedef SearchContext *PtrSearchContext;

/* Declaration for dialogue */

/* List of the pointers used */
typedef char    FontName[30];

#endif