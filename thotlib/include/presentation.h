/*
 *
 *  (c) COPYRIGHT MIT and INRIA, 1996.
 *  Please first read the full copyright statement in file COPYRIGHT.
 *
 */

/*
 * Warning:
 * This module is part of the Thot library, which was originally
 * developed in French. That's why some comments are still in
 * French, but their translation is in progress and the full module
 * will be available in English in the next release.
 * 
 */
 
#ifndef _PRESENTATION_H_
#define _PRESENTATION_H_
#include "view.h"
/* presentation rule */
typedef int        *PRule;

/* Types of presentation rule */

#define PRVisibility 0
#define PRFunction 1
#define PRVertRef 2
#define PRHorizRef 3
#define PRHeight 4
#define PRWidth 5
#define PRVertPos 6
#define PRHorizPos 7
#define PRSize 8
#define PRStyle 9
#define PRFont 10
#define PRUnderline 11
#define PRThickness 12
#define PRIndent 13
#define PRLineSpacing 14
#define PRDepth 15
#define PRAdjust 16
#define PRJustify 17
#define PRLineStyle 18
#define PRLineWeight 19
#define PRFillPattern 20
#define PRBackground 21
#define PRForeground 22
#define PRHyphenate 23
#define PRNoBreak1 24
#define PRNoBreak2 25
#define PRShowBox 26
#define PRNotInLine 27

/* values for rule PRStyle */
#define StyleRoman 1
#define StyleBold 2
#define StyleItalics 3
#define StyleOblique 4
#define StyleBoldItalics 5
#define StyleBoldOblique 6

/* values for rule PRFont */
#define FontTimes 1
#define FontHelvetica 2
#define FontCourier 3

/* values for rule PRUnderline */
#define NoUnderline 1
#define Underline 2
#define Overline 3
#define CrossOut 4

/* values for rule PRThickness */
#define ThinUnderline 1
#define ThickUnderline 2

/* values for rule PRAdjust */
#define AdjustLeft 1
#define AdjustRight 2
#define Centered 3
#define LeftWithDots 4

/* values for rule PRJustify */
#define Justified 1
#define NotJustified 2

/* values for rule PRLineStyle */
#define SolidLine 1
#define DashedLine 2
#define DottedLine 3


/* values for rule PRHyphenate */
#define Hyphenation 1
#define NoHyphenation 2

#ifndef __CEXTRACT__
#ifdef __STDC__


/*----------------------------------------------------------------------
   TtaNewPRule

   Creates a new presentation rule of a given type for a given view of a given
   document.

   Parameter:
   presentationType: type of the presentation rule to be created. Available
   values are PRSize, PRStyle, PRFont, PRUnderline, PRThickness, PRIndent,
   PRLineSpacing, PRDepth, PRAdjust, PRJustify, PRLineStyle, PRLineWeight,
   PRFillPattern, PRBackground, PRForeground, PRHyphenate.
   view: the view (this view must be open).
   document: the document.

   Return value:
   new presentation rule.

  ----------------------------------------------------------------------*/
extern PRule        TtaNewPRule (int presentationType, View view, Document document);

/*----------------------------------------------------------------------
   TtaNewPRuleForView

   Creates a new presentation rule of a given type for a given view of a given
   document. The view is identified by its number.

   Parameter:
   presentationType: type of the presentation rule to be created. Available
   values are PRSize, PRStyle, PRFont, PRUnderline, PRThickness, PRIndent,
   PRLineSpacing, PRDepth, PRAdjust, PRJustify, PRLineStyle, PRLineWeight,
   PRFillPattern, PRBackground, PRForeground, PRHyphenate.
   viewName: the name of the view (this view does not need to be open).
   document: the document.

   Return value:
   new presentation rule.

  ----------------------------------------------------------------------*/
extern PRule        TtaNewPRuleForView (int presentationType, int view, Document document);

/*----------------------------------------------------------------------
   TtaNewPRuleForNamedView

   Creates a new presentation rule of a given type for a given view of a given
   document. The view is identified by its name.

   Parameter:
   presentationType: type of the presentation rule to be created. Available
   values are PRSize, PRStyle, PRFont, PRUnderline, PRThickness, PRIndent,
   PRLineSpacing, PRDepth, PRAdjust, PRJustify, PRLineStyle, PRLineWeight,
   PRFillPattern, PRBackground, PRForeground, PRHyphenate.
   viewName: the name of the view (this view does not need to be open).
   document: the document.

   Return value:
   new presentation rule.

  ----------------------------------------------------------------------*/
extern PRule        TtaNewPRuleForNamedView (int presentationType, char *viewName, Document document);

/*----------------------------------------------------------------------
   TtaCopyPRule

   Creates a new presentation rule and initializes it with a copy of an existing
   presentation rule.

   Parameter:
   pRule: presentation rule to be copied.

   Return value:
   new presentation rule.

  ----------------------------------------------------------------------*/
extern PRule        TtaCopyPRule (PRule pRule);

/*----------------------------------------------------------------------
   TtaAttachPRule

   Attaches a presentation rule to an element.

   Parameters:
   element: the element to which the presentation rule
   has to be attached.
   pRule: the presentation rule to be attached.
   document: the document to which the element belongs.

  ----------------------------------------------------------------------*/
extern void         TtaAttachPRule (Element element, PRule pRule, Document document);

/*----------------------------------------------------------------------
   TtaRemovePRule

   Removes a presentation rule from an element and release that rule.

   Parameters:
   element: the element with which the presentation rule is associated.
   pRule: the presentation rule to be removed.
   document: the document to which the element belongs.

  ----------------------------------------------------------------------*/
extern void         TtaRemovePRule (Element element, PRule pRule, Document document);

/*----------------------------------------------------------------------
   TtaSetPRuleValue

   Changes the value of a presentation rule. The presentation rule must
   be attached to an element that is part of a document.

   Parameters:
   element: the element to which the presentation rule is attached.
   pRule: the presentation rule to be changed.
   value: the value to be set.
   document: the document to which the element belongs.

   Valid values according to rule type:
   RSize: an integer between 6 and 72 (body size in points).
   PtStyle: StyleRoman, StyleBold, StyleItalics, StyleOblique,
   StyleBoldItalics, StyleBoldOblique.
   RFont: FontTimes, FontHelvetica, FontCourier.
   RUnderline: NoUnderline, Underline, Overline, CrossOut.
   RThickness: ThinUnderline, ThickUnderline.
   PtIndent: a positive, null or negative integer (indentation in points).
   RLineSpacing: a positive integer (line spacing in points).
   RDepth: a positive integer (depth of the element).
   RAdjust: AdjustLeft, AdjustRight, Centered, LeftWithDots.
   RJustify: Justified, NotJustified.
   RHyphenate: Hyphenation, NoHyphenation.
   RLineStyle: SolidLine, DashedLine, DottedLine.
   RLineWeight: a positive or null integer (stroke width for graphics).
   RFillPattern: rank of the pattern in the file thot.pattern.
   RBackground: rank of the background color in the file thot.color.
   RForeground: rank of the foreground color in the file thot.color.

  ----------------------------------------------------------------------*/
extern void         TtaSetPRuleValue (Element element, PRule pRule, int value, Document document);

/*----------------------------------------------------------------------
   TtaSetPRuleView

   Sets the view to which a presentation rule applies. The presentation rule
   must not be attached yet to an element.

   Parameters:
   pRule: the presentation rule to be changed.
   view: the value to be set.

  ----------------------------------------------------------------------*/
extern void         TtaSetPRuleView (PRule pRule, int view);

/*----------------------------------------------------------------------
   TtaChangeBoxSize

   Changes the height and width of the box corresponding to an element in
   a given view.

   Parameters:
   element: the element of interest.
   document: the document to which the element belongs.
   view: the view.
   deltaX: width increment in points (positive, negative or zero).
   deltaY: height increment in points (positive, negative or zero).
   unit: the unit used for the values.

  ----------------------------------------------------------------------*/
extern void         TtaChangeBoxSize (Element element, Document document, View view, int deltaX, int deltaY, TypeUnit unit);

/*----------------------------------------------------------------------
   TtaChangeBoxPosition

   Moves the box of an element in a given view.

   Parameters:
   element: the element of interest.
   document: the document to which the element belongs.
   view: the view.
   deltaX: horizontal shift in points (positive, negative or zero).
   deltaY: vertical shift in points (positive, negative or zero).
   unit: the unit used for the values.

  ----------------------------------------------------------------------*/
extern void         TtaChangeBoxPosition (Element element, Document document, View view, int X, int Y, TypeUnit unit);

/*----------------------------------------------------------------------
   TtaGiveBoxSize

   Returns the height and width of the box corresponding to an element in
   a given view.

   Parameters:
   element: the element of interest.
   view: the view.
   unit: the unit used for the values.

   Return parameters:
   width: box width in points.
   height: box height in points.

  ----------------------------------------------------------------------*/
extern void         TtaGiveBoxSize (Element element, Document document, View view, TypeUnit unit, /*OUT*/ int *width, /*OUT*/ int *height);

/*----------------------------------------------------------------------
   TtaGiveBoxPosition

   Returns the x and y coordinates of the box corresponding to an element in
   a given view. The returned coordinates indicate the distance in points
   between the upper left corner of the box and the upper left corner of its
   parent box.

   Parameters:
   element: the element of interest.
   view: the view.
   unit: the unit used for the values.

   Return parameters:
   xCoord: distance from the left edge of the parent box to the left
   edge of the box, in points.
   yCoord:  distance from the upper edge of the parent box to the upper
   edge of the box, in points.

  ----------------------------------------------------------------------*/
extern void         TtaGiveBoxPosition (Element element, Document document, View view, TypeUnit unit, /*OUT*/ int *xCoord, /*OUT*/ int *yCoord);

/*----------------------------------------------------------------------
 *   TtaGiveRGB returns the RGB of the color.
 ----------------------------------------------------------------------*/
extern void         TtaGiveRGB ( char *colname, /*OUT*/ unsigned short *red, /*OUT*/ unsigned short *green, /*OUT*/ unsigned short *blue );

/*----------------------------------------------------------------------
   TtaGiveThotRGB returns the Red Green and Blue values corresponding
   to color number num.
   If the color doesn't exist the function returns the values
   for the default color.
  ----------------------------------------------------------------------*/
extern void         TtaGiveThotRGB (int num, /*OUT*/ unsigned short *red, /*OUT*/ unsigned short *green, /*OUT*/ unsigned short *blue);

/*----------------------------------------------------------------------
   TtaNextPRule

   Returns the first presentation rule associated with a given
   element (if pRule is NULL) or the presentation rule that
   follows a given rule of a given element.

   Parameters:
   element: the element of interest.
   pRule: a presentation rule of that element, or NULL
   if the first rule is asked.

   Return parameter:
   pRule: the next presentation rule, or NULL if
   pRule is the last rule of the element.

  ----------------------------------------------------------------------*/
extern void         TtaNextPRule (Element element, /*INOUT*/ PRule * pRule);

/*----------------------------------------------------------------------
   TtaGetPRuleType

   Returns the type of a presentation rule.

   Parameters:
   pRule: the presentation rule of interest.

   Return value:
   type of that presentation rule. Available values are RSize, PtStyle,
   RFont, RUnderline, RThickness, PtIndent, RLineSpacing, RDepth, RAdjust,
   RJustify, RLineStyle, RLineWeight, RFillPattern, RBackground,
   RForeground, RHyphenate.

  ----------------------------------------------------------------------*/
extern PRule        TtaGetPRule (Element element, int presentationType);

/*----------------------------------------------------------------------
   TtaGetPRuleType

   Returns the type of a presentation rule.

   Parameters:
   pRule: the presentation rule of interest.

   Return value:
   type of that presentation rule. Available values are RSize, PtStyle,
   RFont, RUnderline, RThickness, PtIndent, RLineSpacing, RDepth, RAdjust,
   RJustify, RLineStyle, RLineWeight, RFillPattern, RBackground,
   RForeground, RHyphenate.

  ----------------------------------------------------------------------*/
extern int          TtaGetPRuleType (PRule pRule);

/*----------------------------------------------------------------------
   TtaSamePRules

   Compares two presentation rules associated with the same element or with
   different elements.

   Parameters:
   pRule1: first presentation rule to be compared.
   pRule2: second presentation rule to be compared.

   Return value:
   0 if both rules are different, 1 if they are identical.

  ----------------------------------------------------------------------*/
extern int          TtaGetPRuleValue (PRule pRule);

/*----------------------------------------------------------------------
   TtaGetPRuleView

   Returns the number of the view to which a presentation rule applies.

   Parameters:
       pRule: the presentation rule of interest.

   Return value:
       number of the view to which the presentation rule applies.

  ----------------------------------------------------------------------*/
extern int          TtaGetPRuleView (PRule pRule);

/*----------------------------------------------------------------------
   TtaSamePRules

   Compares two presentation rules associated with the same element or with
   different elements.

   Parameters:
   pRule1: first presentation rule to be compared.
   pRule2: second presentation rule to be compared.

   Return value:
   0 if both rules are different, 1 if they are identical.

  ----------------------------------------------------------------------*/
extern int          TtaSamePRules (PRule pRule1, PRule pRule2);

#else  /* __STDC__ */

extern PRule        TtaNewPRule ( /* int presentationType, View view, Document document */ );
extern PRule        TtaNewPRuleForView (/* int presentationType, int view, Document document */);
extern PRule        TtaNewPRuleForNamedView ( /* int presentationType, char *viewName, Document document */ );
extern PRule        TtaCopyPRule ( /* PRule pRule */ );
extern void         TtaAttachPRule ( /* Element element, PRule pRule, Document document */ );
extern void         TtaRemovePRule ( /* Element element, PRule pRule, Document document */ );
extern void         TtaSetPRuleValue ( /* Element element, PRule pRule, int value, Document document */ );
extern void         TtaSetPRuleView ( /* PRule pRule, int view */ );
extern void         TtaChangeBoxSize ( /* Element element, View view, Document document, int deltaX, int deltaY, TypeUnit unit */ );
extern void         TtaChangeBoxPosition ( /* Element element, Document document, View view, int X, int Y, TypeUnit unit */ );
extern void         TtaGiveBoxSize ( /* Element element, Document document, View view, TypeUnit unit, int *width, int *height */ );
extern void         TtaGiveBoxPosition ( /* Element element, Document document, View view, TypeUnit unit, int *xCoord, int *yCoord */ );
extern void         TtaGiveRGB ( /*char *colname, unsigned short *red, unsigned short *green, unsigned short *blue*/ );
extern void         TtaGiveThotRGB (/*int num, unsigned short *red, unsigned short *green, unsigned short *blue*/);
extern void         TtaNextPRule ( /* Element element, PRule *pRule */ );
extern PRule        TtaGetPRule ( /* Element element, int presentationType */ );
extern int          TtaGetPRuleType ( /* PRule pRule */ );
extern int          TtaGetPRuleValue ( /* PRule pRule */ );
extern int          TtaGetPRuleView ( /* PRule pRule */ );
extern int          TtaSamePRules ( /* PRule pRule1, PRule pRule2 */ );

#endif /* __STDC__ */
#endif /* __CEXTRACT__ */

#endif
