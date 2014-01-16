/*
 *
 *  (c) COPYRIGHT MIT and INRIA, 1996-2005
 *  Please first read the full copyright statement in file COPYRIGHT.
 *
 */

#ifndef _CONTENT_H_
#define _CONTENT_H_

#include "language.h"
#include "tree.h"
typedef enum _PicType
  {
    xbm_type, eps_type, xpm_type, gif_type, png_type, jpeg_type,
    svg_type, html_type, mathml_type, unknown_type
  }
PicType;

typedef int     *PathSegment;

#ifndef __CEXTRACT__


/*----------------------------------------------------------------------
   TtaSetTextContent

   Changes the content of a Text basic element. The full content (if any) is
   deleted and replaced by the new one.
   This function can also be used for changing the content (the file name)
   of a Picture basic element.
   Parameters:
   element: the Text element to be modified.
   content: new content for that element coded in ISO-Latin or UTF-8.
   language: language of that Text element.
   document: the document containing that element.
  ----------------------------------------------------------------------*/
extern void TtaSetTextContent (Element element, unsigned char *content,
			       Language language, Document document);

/*----------------------------------------------------------------------
   TtaSetPictureContent

   Changes the content of a Text basic element. The full content (if any) is
   deleted and replaced by the new one.
   This function can also be used for changing the content (the file name)
   of a Picture basic element.
   Parameters:
   element: the Text element to be modified.
   content: new content for that element coded in ISO-Latin or UTF-8.
   language: language of that Text element.
   document: the document containing that element.
   mime_type: MIME type of the picture, if known. NULL, otherwise
  ----------------------------------------------------------------------*/
extern void TtaSetPictureContent (Element element, unsigned char *content,
				  Language language, Document document, char *mime_type);

/*----------------------------------------------------------------------
   TtaAppendTextContent

   Appends a character string at the end of a Text basic element.
   Parameters:
   element: the Text element to be modified.
   content: the character string to be appended coded in ISO-Latin or UTF-8.
   document: the document containing that element.
  ----------------------------------------------------------------------*/
extern void TtaAppendTextContent (Element element, unsigned char *content,
				  Document document);

/*----------------------------------------------------------------------
   TtaHasFinalSpace

   Returns TRUE if the text element ends with a space or a NEWLINE
   Parameters:
   element: the Text element to be modified.
   document: the document containing that element.
  ----------------------------------------------------------------------*/
extern ThotBool TtaHasFinalSpace (Element element, Document document);

/*----------------------------------------------------------------------
   TtaRemoveInitialSpaces

   Removes spaces and NEWLINE at the beginning of the text element
   Parameters:
   element: the Text element to be modified.
   document: the document containing that element.
  ----------------------------------------------------------------------*/
extern void TtaRemoveInitialSpaces (Element element, Document document);

/*----------------------------------------------------------------------
   TtaRemoveFinalSpaces

   Removes spaces and NEWLINE at the end of the text element
   Parameters:
   element: the Text element to be modified.
   document: the document containing that element.
   all: when TRUE removes all spaces, when FALSE only the last space.
  ----------------------------------------------------------------------*/
extern void TtaRemoveFinalSpaces (Element element, Document document,
				  ThotBool all);

/*----------------------------------------------------------------------
  TtaSearchText looks for the text forward or backward in the document.
  If the string is found the function returns the element that includes
  it. It return NULL if the string is not found.
  ----------------------------------------------------------------------*/
extern Element TtaSearchText (Document document, Element element, ThotBool forward,
			      char *text, CHARSET encoding);

/* ----------------------------------------------------------------------
   TtaInsertTextContent

   Inserts a character string in a text basic element.
   Parameters:
   element: the Text element to be modified.
   position: rank of the character after which the new string must
   be inserted. 0 for inserting before the first character.
   content: the character string to be inserted coded in ISO-Latin or UTF-8.
   document: the document containing the text element.
  ----------------------------------------------------------------------*/
extern void TtaInsertTextContent (Element element, int position,
				  unsigned char *content, Document document);

/*----------------------------------------------------------------------
   TtaDeleteTextContent

   Deletes a character string in a text basic element.
   Parameters:
   element: the Text element to be modified.
   position: rank of the first character to be deleted.
   length: length of the character string to be deleted.
   document: the document containing the text element.
  ----------------------------------------------------------------------*/
extern void TtaDeleteTextContent (Element element, int position, int length,
				  Document document);

/*----------------------------------------------------------------------
   TtaSplitText

   Divides a text element into two elements.
   Parameters:
   element: the text element to be divided. A new text element containing
   the second part of the text is created as the next sibling.
   position: rank of the character before which the element must be cut.
   document: the document to which the element belongs.
  ----------------------------------------------------------------------*/
extern void TtaSplitText (Element element, int position, Document document);

/*----------------------------------------------------------------------
   TtaMergeText

   Merges two text elements.
   Parameters:
   element: the first text element. Merging occurs only if
   the next sibling is a text element with the same attributes.
   document: the document to which the text element belongs.
   Return value:
   TRUE if merging has been done.
  ----------------------------------------------------------------------*/
extern ThotBool TtaMergeText (Element element, Document document);

/*----------------------------------------------------------------------
   TtaSetGraphicsShape

   Changes the shape of a Graphics or Symbol basic element.
   Parameters:
   element: the element to be changed. This element must
   be a basic element of type Graphics or Symbol.
   shape: new shape for that element.
   document: the document containing that element.
  ----------------------------------------------------------------------*/
extern void TtaSetGraphicsShape (Element element, char shape, Document document);

/*----------------------------------------------------------------------
   TtaSetSymbolCode

   Changes the wide char code associated with a Symbol basic element.
   Parameters:
   element: the element to be changed. This element must
   be a basic element of type Symbol whose shape is '?'
   code: wide char code
   document: the document containing that element.
  ----------------------------------------------------------------------*/
extern void TtaSetSymbolCode (Element element, wchar_t code, Document document);

/*----------------------------------------------------------------------
   TtaAddPointInPolyline

   Adds a new point in a Polyline basic element.
   Parameters:
   element: the element to be changed. This element must
   be a basic element of type Polyline.
   document: the document containing the polyline element.
   rank: rank of the new point to be inserted. If rank is greater
   than the actual number of points, the new point is appended.
   rank must be strictly positive.
   x, y: coordinate of the new point, in millipoints, relatively to
   the upper left corner of the box. x and y
   must be positive or null.
   unit: UnPixel or UnPoint.
  ----------------------------------------------------------------------*/
extern void TtaAddPointInPolyline (Element element, int rank, TypeUnit unit,
				   int x, int y, Document document);

/*----------------------------------------------------------------------
   TtaDeletePointInPolyline

   Deletes a point in a Polyline basic element.
   Parameters:
   element: the element to be changed. This element must
   be a basic element of type Polyline.
   rank: rank of the point to be deleted. If rank is greater
   than the actual number of points, the last point is deleted.
   rank must be strictly positive.
   document: the document containing the polyline element.
  ----------------------------------------------------------------------*/
extern void TtaDeletePointInPolyline (Element element, int rank, Document document);

/*----------------------------------------------------------------------
   TtaModifyPointInPolyline

   Changes the coordinates of a point in a Polyline basic element.
   Parameters:
   element: the element to be changed. This element must
   be a basic element of type Polyline.
   rank: rank of the point to be modified. If rank is greater
   than the actual number of points, the last point is changed.
   rank must be strictly positive.
   x, y: new coordinates of the point, in millipoints, relatively to
   the upper left corner of the enclosing rectangle. x and y
   must be positive or null.
   document: the document containing the polyline element.
   unit: UnPixel or UnPoint.
  ----------------------------------------------------------------------*/
extern void TtaModifyPointInPolyline (Element element, int rank, TypeUnit unit,
				      int x, int y, Document document);

/*----------------------------------------------------------------------
   TtaChangeLimitOfPolyline

   Changes the coordinates of the lower left corner of the box containing
   a Polyline basic element.
   Parameters:
   element: the element to be changed. This element must
   be a basic element of type Polyline.
   unit: UnPixel or UnPoint.
   x, y: new coordinates of the lower left corner, in millipoints,
   relatively to the upper left corner of the box. x and y
   must be positive or null and the box must contain all
   points of the polyline.
   document: the document containing the polyline element.
  ----------------------------------------------------------------------*/
extern void TtaChangeLimitOfPolyline (Element element, TypeUnit unit, int x,
				      int y, Document document);

/*----------------------------------------------------------------------
   TtaTransformCurveIntoPath

   Transform a polyline element into a path and return the SVG
   representation of that path.
   Parameters:
   el: the element to be transformed
   Return value:
   the SVG path expression. - don't forget to free that buffer.
   ---------------------------------------------------------------------- */
extern char *TtaTransformCurveIntoPath (Element el);

/*----------------------------------------------------------------------
   TtaNewPathSegLine

   Creates a new path segment of type line.
   Parameters:
   xstart: absolute X coordinate for the start point of the path segment
   ystart: absolute X coordinate for the start point of the path segment
   xend:   absolute Y coordinate for the end point of the path segment
   yend:   absolute Y coordinate for the end point of the path segment
   newSubpath: this segment starts a new subpath
   Return value:
   the created path segment.
   ---------------------------------------------------------------------- */
extern PathSegment TtaNewPathSegLine (int xstart, int ystart, int xend,
				      int yend, ThotBool newSubpath);

/*----------------------------------------------------------------------
   TtaNewPathSegCubic

   Creates a new path segment of type cubic Bezier curve.
   Parameters:
   xstart: absolute X coordinate for the start point of the path segment
   ystart: absolute X coordinate for the start point of the path segment
   xend:   absolute Y coordinate for the end point of the path segment
   yend:   absolute Y coordinate for the end point of the path segment
   xctrl1: absolute X coordinate for the first control point
   yctrl1: absolute Y coordinate for the first control point
   xctrl2: absolute X coordinate for the second control point
   yctrl2: absolute Y coordinate for the second control point
   newSubpath: this segment starts a new subpath
   Return value:
   the created path segment.
   ---------------------------------------------------------------------- */
extern PathSegment TtaNewPathSegCubic (int xstart, int ystart, int xend,
				       int yend, int xctrl1, int yctrl1,
				       int xctrl2, int yctrl2, ThotBool newSubpath);

/*----------------------------------------------------------------------
   TtaNewPathSegQuadratic

   Creates a new path segment of type quadratic Bezier curve.

   Parameters:
   xstart: absolute X coordinate for the start point of the path segment
   ystart: absolute X coordinate for the start point of the path segment
   xend:   absolute Y coordinate for the end point of the path segment
   yend:   absolute Y coordinate for the end point of the path segment
   xctrl:  absolute X coordinate for the control point
   yctrl:  absolute Y coordinate for the control point
   newSubpath: this segment starts a new subpath

   Return value:
   the created path segment.

   ---------------------------------------------------------------------- */
extern PathSegment TtaNewPathSegQuadratic (int xstart, int ystart, int xend,
					   int yend, int xctrl, int yctrl,
					   ThotBool newSubpath);

/*----------------------------------------------------------------------
   TtaNewPathSegArc

   Creates a new path segment of type elliptical arc.
   Parameters:
   xstart:  absolute X coordinate for the start point of the path segment
   ystart:  absolute X coordinate for the start point of the path segment
   xend:    absolute Y coordinate for the end point of the path segment
   yend:    absolute Y coordinate for the end point of the path segment
   xradius: x-axis radius for the ellipse
   yradius: y-axis radius for the ellipse
   angle:   rotation angle in degrees for the ellipse's x-axis relative to
            the x-axis
   largearc:value for the large-arc-flag parameter
   sweep:   value for the sweep-flag parameter
   newSubpath: this segment starts a new subpath
   Return value:
   the created path segment.
   ---------------------------------------------------------------------- */
extern PathSegment TtaNewPathSegArc (int xstart, int ystart, int xend, int yend,
				     int xradius, int yradius, int angle,
				     ThotBool largearc, ThotBool sweep,
				     ThotBool newSubpath);

/*----------------------------------------------------------------------
   TtaAppendPathSeg

   Appends a path segment at the end of a Graphics basic element
   Parameters:
   element: the Graphics element to be modified.
   segment: the path segment to be appended.
   document: the document containing the element.
  ----------------------------------------------------------------------*/
extern void TtaAppendPathSeg (Element element, PathSegment segment,
			      Document document);

/*----------------------------------------------------------------------
   TtaTransform
  ----------------------------------------------------------------------*/
extern void TtaInsertTransform (Element element, void *transform, 
				 Document document);
extern void TtaReplaceTransform (Element element, void *transform, 
				 Document document);
extern void TtaAppendTransform (Element element, void *transform, 
				Document document);

extern void *TtaNewTransformScale (float x_scale, float y_scale);
extern void *TtaNewTransformTranslate (float x, float y);
extern void *TtaNewTransformRotate (float angle, float x_scale, float y_scale);
extern void *TtaNewTransformSkewX (float factor);
extern void *TtaNewTransformSkewY (float factor);
extern void *TtaNewTransformMatrix (float a, float b, float c,
				    float d, float e, float f);
extern void *TtaNewTransformViewBox (float x, float y, float w, float h, int align, int meetOrSlice);

extern void TtaFreeTransform (void *transform);

extern void TtaSetElCoordinateSystem (Element element);

extern void TtaPlay (Document doc, View view);
extern void TtaNoPlay (int frame);
/*----------------------------------------------------------------------
   TtaAppendTransform
   Copy a Linked List of transform into another struct
  ----------------------------------------------------------------------*/
void *TtaCopyTransform (void *pPa);
void *TtaNewTransformAnimTranslate (float x, float y);
void *TtaNewTransformAnimRotate (float angle, float x_scale, 
				 float y_scale);
/*----------------------------------------------------------------------
   TtaAnim
  ----------------------------------------------------------------------*/
extern void *TtaNewAnimInfo ();

extern void *TtaNewAnimation ();
extern void TtaAddAnimPath (void *info, void *anim);

extern void TtaAddAnimMotionPath (void *info, void *anim);
extern void TtaAddAnimMotionFromTo (void *info, void *anim);
extern void TtaAddAnimMotionValues (void *info, void *anim);

extern void TtaAnimPathAddPoint (void *anim, float x, float y);

extern void *TtaCopyTransform ( void *pPa );
extern void TtaAppendAnim (Element element, void *anim);

extern void TtaSetAnimationTime (void *anim_info, double start, double duration);

extern void TtaSetAnimReplace (void *anim, ThotBool is_replace);

extern void TtaAddAnimFreeze (void *anim);
extern void TtaAddAnimRemove (void *anim);

extern void TtaAddAnimRepeatCount (int repeat, void *anim);

extern void TtaAddAnimTo (void *info, void *anim);
extern void TtaAddAnimFrom (void *info, void *anim);
extern void TtaAddAnimAttrName (void *info, void *anim);

extern void TtaSetAnimTypetoSet (void *anim);

extern void TtaAppendPathSegToAnim (void *anim, PathSegment segment, Document doc);
extern void *TtaNewAnimPath (Document doc);


extern void TtaSetAnimTypetoColor (void *anim);
extern void TtaSetAnimTypetoAnimate (void *anim);
extern void TtaSetAnimTypetoTransform (void *anim);
extern void TtaSetAnimTypetoMotion (void *anim);

extern void TtaFreeAnimation (void *anim);
extern void TtaSetDocumentCurrentTime (double current_time, Document basedoc);
extern void TtaDisableScrollbars (Document doc, View view);

extern void TtaRegisterTimeEvent(void (*pfunc) (Document doc, double current_time));
/*----------------------------------------------------------------------
  TtaCopyTransform
  Copy a Linked List of transforms into another struct
  ----------------------------------------------------------------------*/
extern void *TtaCopyTransform (void *void_pPa);
/*----------------------------------------------------------------------
   TtaCopyAnim : Copy anim linked list 
  ----------------------------------------------------------------------*/
extern void *TtaCopyAnim (void *src);

/*----------------------------------------------------------------------
   TtaSetLinearGradient
   ----------------------------------------------------------------------*/
void TtaSetLinearGradient (Element el);
void TtaSetLinearx1Gradient (int value, Element el);
void TtaSetLineary1Gradient (int value, Element el);
void TtaSetLinearx2Gradient (int value, Element el);
void TtaSetLineary2Gradient (int value, Element el);
void TtaSetStopColorGradient (unsigned short red, unsigned short green,
			      unsigned short blue, Element el);
void TtaSetStopOffsetColorGradient (float offset, Element el);
     
/*----------------------------------------------------------------------
   TtaCopyPage

   Copies the page element source into the page element destination.
   Both page elements must be in an abstract tree.
   Parameters:
   destination: identifier of the page element to be modified.
   source : identifier of the source page element.
  ----------------------------------------------------------------------*/
extern void TtaCopyPage (Element destination, Element source);

/*----------------------------------------------------------------------
   TtaGetPictureType

   Returns the type of Picture element.
   Parameter:
   element: the element of interest. This element must be a Picture.
   Return value:
   PicType: type of the element.
  ----------------------------------------------------------------------*/
extern PicType TtaGetPictureType (Element element);

/*----------------------------------------------------------------------
   TtaSetPictureType

   Sets the type of a Picture element.
   Parameter:
   mime_type: mime type of an image.
  ----------------------------------------------------------------------*/
extern void TtaSetPictureType (Element element, char *mime_type);

/*----------------------------------------------------------------------
   TtaGetTextLength

   Returns the length of a Text basic element.
   Parameter:
   element: the element of interest. This element must be a basic
   element of type Text.
   Return value:
   textLength: the number of characters contained in the element.
   In _I18N mode the length corresponds to the UTF-8 string.
  ----------------------------------------------------------------------*/
extern int TtaGetTextLength (Element element);

/*----------------------------------------------------------------------
   TtaGiveTextContent

   Returns the content of a Text basic element.
   Parameters:
   element: the element of interest. This element must be a basic
   element of type Text.
   buffer: the buffer that will contain the text. This buffer
   must be at least of size length.
   length: maximum length of that buffer.
   In _I18N mode the length corresponds to the UTF-8 string.
   Return parameters:
   buffer: (the buffer contains the text).
   length: actual length of the text in the buffer.
   language: language of the text.
   In _I18N mode returns a UTF-8 string.
  ----------------------------------------------------------------------*/
extern void TtaGiveTextContent (Element element, unsigned char *buffer,
				int *length, Language *language);

/*----------------------------------------------------------------------
   TtaGiveBufferContent

   Returns a sub buffer from a Text basic element limited to the first
   Buffer length.
   Parameters:
   element: the element of interest. This element must be a basic
   element of type Text.
   buffer: the buffer that will contain the returned string. This buffer
   must be at least of size length.
   The length corresponds to the buffer length.
   length: the length of the substring. Must be strictly positive.
   Return parameter:
   buffer: (the buffer contains the substring).
   language: language of the text.
  ----------------------------------------------------------------------*/
extern void TtaGiveBufferContent (Element element, CHAR_T *buffer, int length,
				  Language *language);

/*----------------------------------------------------------------------
   TtaSetBufferContent

   Changes the content of a Text basic element. The full content (if any) is
   deleted and replaced by the new one.
   Parameters:
   element: the Text element to be modified.
   content: new content for that element coded as a string of CHAR_T
   characters.
   language: language of that Text element.
   document: the document containing that element.
  ----------------------------------------------------------------------*/
extern void TtaSetBufferContent (Element element, CHAR_T *content,
				 Language language, Document document);

/*----------------------------------------------------------------------
   TtaGetFirstBufferContent

   Returns the first CHAR_T character of the string.
   Parameters:
   element: the element of interest. This element must be a basic
   element of type Text.
   Return parameter:
   buffer: the first character.
  ----------------------------------------------------------------------*/
extern CHAR_T TtaGetFirstBufferContent (Element element);

/*----------------------------------------------------------------------
   TtaGetLastBufferContent

   Returns the last CHAR_T character of the string.
   Parameters:
   element: the element of interest. This element must be a basic
   element of type Text.
   Return parameter:
   buffer: the last character.
  ----------------------------------------------------------------------*/
extern CHAR_T TtaGetLastBufferContent (Element element);

/*----------------------------------------------------------------------
   TtaGiveSubString

   Returns a substring from a Text basic element.
   Parameters:
   element: the element of interest. This element must be a basic
   element of type Text.
   buffer: the buffer that will contain the substring. This buffer
   must be at least of size length.
   In _I18N mode the length corresponds to the UTF-8 string.
   position: the rank of the first character of the substring.
   rank must be strictly positive.
   length: the length of the substring. Must be strictly positive.
   Return parameter:
   buffer: (the buffer contains the substring).
   In _I18N mode returns a UTF-8 string.
  ----------------------------------------------------------------------*/
extern void TtaGiveSubString (Element element, unsigned char *buffer,
			      int position, int length);

/*----------------------------------------------------------------------
   TtaGetGraphicsShape

   Returns the content of a Graphics or Symbol basic element.
   Parameter:
   element: the element of interest. This element must be a basic
   element of type Graphics or Symbol.
   Return value:
   a single character representing the shape of the graphics element or
   symbol contained in the element.
  ----------------------------------------------------------------------*/
extern char TtaGetGraphicsShape (Element element);

/*----------------------------------------------------------------------
   TtaGetPolylineLength

   Returns the number of points in a Polyline basic element.
   Parameter:
   element: the Polyline element. This element must
   be a basic element of type Polyline.
  ----------------------------------------------------------------------*/
extern int TtaGetPolylineLength (Element element);

/*----------------------------------------------------------------------
   TtaGivePolylinePoint

   Returns the coordinates of a point in a Polyline basic element.
   Parameters:
   element: the Polyline element. This element must
   be a basic element of type Polyline.
   rank: rank of the point in the PloyLine. If rank is greater
   than the actual number of points, an error is raised.
   rank must be strictly positive.
   unit: UnPixel or UnPoint.
   Return values:
   x, y: coordinates of the point, in unit, relatively to
   the upper left corner of the enclosing rectangle.
  ----------------------------------------------------------------------*/
extern void TtaGivePolylinePoint (Element element, int rank, TypeUnit unit,
				  /*OUT*/ int *x, /*OUT*/ int *y);

/*----------------------------------------------------------------------
   TtaGetPageNumber
   Returns the page number of a Page basic element.
   Parameter:
   pageElement: the page element.
   Return value:
   page number of that page element.
  ----------------------------------------------------------------------*/
extern int TtaGetPageNumber (Element pageElement);

/*----------------------------------------------------------------------
   TtaGetPageView
   Returns the view corresponding to a Page basic element.
   Parameter:
   pageElement: the page element.
   Return value:
   view of that page.
  ----------------------------------------------------------------------*/
extern int TtaGetPageView (Element pageElement);

/*----------------------------------------------------------------------
  TtcPasteFormBuffer pastes at the current insert position the content
  of the buffer.
  ----------------------------------------------------------------------*/
extern void TtaPasteFromBuffer (unsigned char *src, int length, CHARSET charset);

#endif /* __CEXTRACT__ */

#endif







