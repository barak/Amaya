/*
 *
 *  (c) COPYRIGHT INRIA, 1996-2005
 *  Please first read the full copyright statement in file COPYRIGHT.
 *
 */

/*
 * gldisplay.c : handling of low level drawing routines, 
 *               with Opengl library both for
 *                   MS-Windows (incomplete).
 *                   Unix
 *
 * Author: P. Cheyrou-lagreze (INRIA)
 *
 */
#ifdef _GL

#ifdef _GTK
  #include <gtkgl/gtkglarea.h>
#endif /* #ifdef _GTK */

#ifdef _WINGUI
  #include <windows.h>
#endif /* _WINGUI */

#ifdef _WX
  #include "wx/wx.h"
#else /* _WX */
  #include <GL/gl.h>
#endif /* _WX */

#include "ustring.h"
#include "math.h"
#include "thot_sys.h"
#include "constmedia.h"
#include "typemedia.h"
#include "frame.h"

#undef THOT_EXPORT
#define THOT_EXPORT extern
#include "boxes_tv.h"
#include "font_tv.h"
#include "frame_tv.h"
#include "units_tv.h"
#include "edit_tv.h"
#include "thotcolor_tv.h"

#define ALLOC_POINTS    300

#include "boxlocate_f.h"
#include "buildlines_f.h"
#include "context_f.h"
#include "font_f.h"
#include "inites_f.h"
#include "memory_f.h"
#include "units_f.h"
#include "xwindowdisplay_f.h"
#include "tesse_f.h"
#include "spline_f.h"
#include "stix_f.h"
#include "glwindowdisplay.h"
#include "glprint.h"

/*
 * Math Macros conversion from
 * degrees to radians and so on...
 * All for EllipticSplit and/or GL_DrawArc
 */
#include <math.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
#define M_PI_DOUBLE (6.2831853718027492)

/* ((A)*(M_PI/180.0)) */
#define DEG_TO_RAD(A)   ((double)A)/57.29577957795135
#define RAD_TO_DEG(A)   ((double)A)*57.29577957795135

#define IS_ZERO(arg)                    (fabs(arg)<1.e-20)

/*If we should use a static table instead for
  performance bottleneck...*/
#define DCOS(A) ((double)cos (A))
#define DSIN(A) ((double)sin (A))
#define DACOS(A) ((double)acos (A))
#define A_DEGREE 0.017453293

/* Precision of a degree/1 
   If we need more precision 
   dision is our friend 
   1/2 degree = 0.0087266465
   1/4 degree = 0.0043633233
   or the inverse 
   24 degree = 0.41887903
   5 degree = 0.087266465
   2 degree = 0.034906586
   but best is a degree...
*/
#define TRIGO_PRECISION 1;
#define A_DEGREE_PART A_DEGREE/TRIGO_RECISION

/* Must find better one... 
   Bits methods...*/
/*for double => ( pow (N, 2))*/
/*for int  => (((int)N)<<1)*/
#define P2(N) (N*N)

#define	MAX_STACK	50
#define	MIDDLE_OF(v1, v2) (((v1)+(v2))/2.0)
#define ALLOC_POINTS    300

#define MESA

/*----------------------------------------------------------------------
  FontOrig update and (x, y) location before DrawString
  accordingly to the ascent of the font used.
  ----------------------------------------------------------------------*/
void FontOrig (ThotFont font, char firstchar, int *pX, int *pY)
{
   if (!font)
      return;
   /**pY += ((XFontStruct *) font)->ascent;*/
}


/*----------------------------------------------------------------------
  LoadColor load the given color in the drawing Graphic Context.
  The parameter fg gives the drawing color
  ----------------------------------------------------------------------*/
static void LoadColor (int fg)
{
    GL_SetForeground (fg);
}

/*----------------------------------------------------------------------
  DoDrawOneLine draw one line starting from (x1, y1) to (x2, y2) in frame.
  ----------------------------------------------------------------------*/
static void DoDrawOneLine (int frame, int x1, int y1, int x2, int y2)
{
  GL_DrawLine (x1, y1, x2, y2, FALSE);
}


/*----------------------------------------------------------------------
  DrawChar draw a char at location (x, y) in frame and with font.
  The parameter fg indicates the drawing color
  ----------------------------------------------------------------------*/
void DrawChar (char car, int frame, int x, int y, ThotFont font, int fg)
{
  ThotWindow          w = None;

#ifdef _GTK
  w = FrRef[frame];
#endif /* _GTK */
#ifdef _WX
  w = (ThotWindow)FrameTable[frame].WdFrame;
#endif /* _WX */ 
  if (w == None)
    return;
   
  y = y + FrameTable[frame].FrTopMargin;
  GL_DrawUnicodeChar ((CHAR_T) car, (float) x, (float) y, font, fg);
}

/*----------------------------------------------------------------------
  DrawString draw a char string of lg chars beginning in buff.
  Drawing starts at (x, y) in frame and using font.
  boxWidth gives the width of the final box or zero,
  this is used only by the thot formmating engine.
  bl indicates that there are one or more spaces before the string
  hyphen indicates whether an hyphen char has to be added.
  startABlock is 1 if the text is at a paragraph beginning
  (no justification of first spaces).
  parameter fg indicates the drawing color
  Returns the lenght of the string drawn.
  ----------------------------------------------------------------------*/
int DrawString (unsigned char *buff, int lg, int frame, int x, int y,
		ThotFont font, int boxWidth, int bl, int hyphen,
		int startABlock, int fg)
{
  ThotWindow          w = None;
  int                 width;

#ifdef _GTK
  w = FrRef[frame];
#endif /* _GTK */
#ifdef _WX
  w = (ThotWindow)FrameTable[frame].WdFrame;
#endif /* _WX */ 
  y += FrameTable[frame].FrTopMargin; 
  /* compute the width of the string */
  width = 0;
  if (w && fg >= 0)
    {
      /* Dealing with BR tag for windows */
      if (Printing)
	width = GLString (buff, lg, frame, x, y, font, boxWidth, bl, hyphen, 
			  startABlock, fg);
      else if (lg > 0)
	width = GL_DrawString (fg, (CHAR_T *) buff, 
			       (float) x, (float) y, hyphen, font, lg);
    }
  return (width);
}

#ifndef _WIN_PRINT
/*----------------------------------------------------------------------
  WDrawString draw a char string of lg chars beginning in buff.
  Drawing starts at (x, y) in frame and using font.
  boxWidth gives the width of the final box or zero,
  this is used only by the thot formmating engine.
  bl indicates that there are one or more spaces before the string
  hyphen indicates whether an hyphen char has to be added.
  startABlock is 1 if the text is at a paragraph beginning
  (no justification of first spaces).
  parameter fg indicates the drawing color
  Returns the lenght of the string drawn.
  ----------------------------------------------------------------------*/
int WDrawString (wchar_t *buff, int lg, int frame, int x, int y,
		 ThotFont font, int boxWidth, int bl, int hyphen,
		 int startABlock, int fg)
{
  if (lg < 0)
    return 0;
  
  y += FrameTable[frame].FrTopMargin;
  return (GL_DrawString (fg, buff, (float) x, (float) y, hyphen,
			 (void *) font, lg));
}
#endif /*_WIN_PRINT*/

/*----------------------------------------------------------------------
  DisplayUnderline draw the underline, overline or cross line
  added to some text of lenght lg, using font and located
  at (x, y) in frame. 
  The parameter fg indicates the drawing color ad type indicates the kind
  of drawing:
  - 0 = none
  - 1 = underlined
  - 2 = overlined
  - 3 = cross-over
                  (x,y)
          _________________________________________________\_/__ top
          /|\    I    I          /|\       /|\   /|\        
           |     I\  /I           |         |     |       
           |  ___I_\/_I_______    |ascent   |     |  
   fheight |     I    I  I  \     |         |     |
           |     I    I  I  |     |         |  __\|/ middle
           |  ___I____I__I__/____\|/        | 
           |             I                  |
	       |             I                  |
	      \|/____________I_________________\|/_ bottom
  ----------------------------------------------------------------------*/
void DisplayUnderline (int frame, int x, int y, int h, int type,
		       int lg, int fg)
{
   ThotWindow          w = None;
   int                 bottom;	/* underline position    */
   int                 middle;	/* cross-over position   */
   int                 thickness;	/* thickness of drawing */

   if (fg < 0)
     return;
   if (lg > 0)
     {
#ifdef _GTK
	w = FrRef[frame];
#endif /* _GTK */
#ifdef _WX
	w = (ThotWindow)FrameTable[frame].WdFrame;
#endif /* _WX */ 

	if (w == None)
	   return;
	thickness = (h / 20) + 1;
	y += FrameTable[frame].FrTopMargin;
	bottom = y + h - thickness;
	middle = y + h / 2;

	/*
	 * for an underline independant of the font add
	 * the following lines here :
	 *         thickness = 1;
	 *         top = y + 2 * thickness;
	 *         bottom = y + ascent + 3;
	 */
	InitDrawing (5, thickness, fg);
	switch (type)
	  {
	  case 1:
	    /* underlined */
	    DoDrawOneLine (frame, x - lg, bottom, x, bottom);
	    break;
	    
	  case 2:
	    /* overlined */
	    DoDrawOneLine (frame, x - lg, y, x, y);
	    break;
	    
	  case 3:
	    /* cross-over */
	    DoDrawOneLine (frame, x - lg, middle, x, middle);
	    break;
	    
	  default:
	    /* not underlined */
	    break;
	  }
     }
}

/*----------------------------------------------------------------------
  DrawPoints draw a line of dot.
  The parameter fg indicates the drawing color
  ----------------------------------------------------------------------*/
void DrawPoints (int frame, int x, int y, int boxWidth, int fg)
{
   ThotWindow          w = None;
   ThotFont            font;
   SpecFont            spec;
   char               *ptcar;
   int                 xcour, width, nb;

   spec = ThotLoadFont ('L', 1, 0, 6, UnPoint, frame);
   GetFontAndIndexFromSpec (SPACE, spec, &font);
   if (boxWidth > 0)
     {
#ifdef _GTK
	w = FrRef[frame];
#endif /* _GTK */
#ifdef _WX
	w = (ThotWindow)FrameTable[frame].WdFrame;
#endif /* _WX */ 
	ptcar = " . ";

	/* compute lenght of the string " ." */
	width = CharacterWidth (SPACE, font) + CharacterWidth (46, font);
	/* compute the number of string to write */
	nb = boxWidth / width;
	xcour = x + (boxWidth % width);
	y = y + FrameTable[frame].FrTopMargin;
	/* draw the points */
	FontOrig (font, *ptcar, &x, &y);
	while (nb > 0)
	  {
	    xcour += GL_DrawString (fg, (CHAR_T *) ptcar, (float) xcour,
				    (float) y, 0, font, 2);
	    nb--;
	  }
     }
}

/*----------------------------------------------------------------------
  DrawRadical Draw a radical symbol.
  The parameter fg indicates the drawing color
  ----------------------------------------------------------------------*/
void DrawRadical (int frame, int thick, int x, int y, int l, int h,
		  ThotFont font, int fg)
{
  int                 xm, xp, fh;

   if (fg < 0)
     return;

   fh = FontHeight (font);

   xm = x + (fh / 2);
   xp = x + (fh / 4);
   y += FrameTable[frame].FrTopMargin;

   if (fh > 14)
     InitDrawing (5, 1, fg);
   else
     InitDrawing (5, 0, fg);
   /* vertical part */
   DoDrawOneLine (frame, x, y + (2 * (h / 3)), xp - (thick / 2), y + h);

   InitDrawing (5, thick, fg);
   /* Acending part */
   DoDrawOneLine (frame, xp, y + h, xm, y);
   /* Upper part */
   DoDrawOneLine (frame, xm, y, x + l, y);
}



/*----------------------------------------------------------------------
  DrawMonoSymb draw a one glyph symbol.
  parameter fg indicates the drawing color
  ----------------------------------------------------------------------*/
static int DrawMonoSymb (CHAR_T symb, int frame, int x, int y, int l,
			  int h, ThotFont font, int fg)
{
  int xm, yf;

  xm = x + ((l - CharacterWidth (symb, font)) / 2);
  yf = y + ((h - CharacterHeight (symb, font)) / 2) + CharacterAscent (symb, font);
  DrawChar ((char) (symb), frame, xm, yf, font, fg);
  return 0;
}

/*----------------------------------------------------------------------
  DrawSigma draw a Sigma symbol.
  active indicates if the box is active
  parameter fg indicates the drawing color
  ----------------------------------------------------------------------*/
void DrawSigma (int frame, int x, int y, int l, int h, ThotFont font, int fg)
{
   int                 xm, ym, fh;

   if (fg < 0)
     return;

   fh = FontHeight (font);
   y += FrameTable[frame].FrTopMargin;
   xm = x + (l / 3);
   ym = y + (h / 2) - 1;
   
   InitDrawing (5, 1, fg);
   /* Center */
   DoDrawOneLine (frame, x, y + 1, xm, ym);
   DoDrawOneLine (frame, x, y + h - 2, xm, ym);
   
   InitDrawing (5, 2, fg);
   /* Borders */
   DoDrawOneLine (frame, x, y, x + l, y);
   DoDrawOneLine (frame, x, y + h - 2, x + l, y + h - 2);
}

/*----------------------------------------------------------------------
  DrawPi draw a PI symbol.
  parameter fg indicates the drawing color
  ----------------------------------------------------------------------*/
void DrawPi (int frame, int x, int y, int l, int h, ThotFont font, int fg)
{
   int                 fh;

   if (fg < 0)
     return;
   fh = FontHeight (font);
   if (0 && h < fh * 2 && l <= CharacterWidth (213, font))
     {
	/* Only one glyph needed */
	DrawMonoSymb ((CHAR_T)'\325', frame, x, y, l, h, font, fg);
     }
   else
     {
        y += FrameTable[frame].FrTopMargin;
	InitDrawing (5, 0, fg);
	/* Vertical part */
	DoDrawOneLine (frame, x + 2, y + 1, x + 2, y + h);
	DoDrawOneLine (frame, x + l - 3, y + 1, x + l - 3, y + h);

	InitDrawing (5, 2, fg);
	/* Upper part */
	DoDrawOneLine (frame, x + 1, y + 1, x + l, y);
     }
}

/*----------------------------------------------------------------------
  DrawIntersection draw an intersection symbol.
  parameter fg indicates the drawing color
  ----------------------------------------------------------------------*/
void DrawIntersection (int frame, int x, int y, int l, int h, ThotFont font,
		       int fg)
{
   if (fg < 0)
     return;
   
   DrawCenteredStixChar (font, 88, x, y, l, h, fg, frame);
}

/*----------------------------------------------------------------------
  DrawUnion draw an Union symbol.
  parameter fg indicates the drawing color
  ----------------------------------------------------------------------*/
void DrawUnion (int frame, int x, int y, int l, int h, ThotFont font, int fg)
{
   if (fg < 0)
     return;

   DrawCenteredStixChar (font, 87, x, y,  l, h, fg, frame);
}

/*----------------------------------------------------------------------
  ArrowDrawing draw the end of an arrow.
  ----------------------------------------------------------------------*/
static void ArrowDrawing (int frame, int x1, int y1, int x2, int y2,
			  int thick, int fg)
{
   double              x, y, xb, yb, dx, dy, l, sina, cosa;
   int                 xc, yc, xd, yd;
   double              width, height;
   ThotPoint           point[3];

   width = (double) (5 + thick);
   height = 10;
   dx = (double) (x2 - x1);
   dy = (double) (y1 - y2);
   l = (double) sqrt ((double) (dx * dx + dy * dy));
   if (IS_ZERO(l)) 
      return;
   sina = dy / l;
   cosa = dx / l;
   xb = x2 * cosa - y2 * sina;
   yb = x2 * sina + y2 * cosa;
   x = xb - height;
   y = yb - width / 2;
   xc = (int)(x * cosa + y * sina + .5);
   yc = (int)(-x * sina + y * cosa + .5);
   y = yb + width / 2;
   xd = (int)(x * cosa + y * sina + .5);
   yd = (int)(-x * sina + y * cosa + .5);

   /* draw */
   point[0].x = x2;
   point[0].y = y2;
   point[1].x = xc;
   point[1].y = yc;
   point[2].x = xd;
   point[2].y = yd;

   GL_DrawPolygon (point, 3);
    
}

/*----------------------------------------------------------------------
  DrawArrow draw an arrow following the indicated direction in degrees :
  0 (right arrow), 45, 90, 135, 180,
  225, 270 ou 315.
  parameter fg indicates the drawing color
  ----------------------------------------------------------------------*/
void DrawArrow (int frame, int thick, int style, int x, int y, int l, int h,
		int orientation, int fg)
{
   int                 xm, ym, xf, yf;

   if (fg < 0)
     return;
   if (thick <= 0)
      return;
   y += FrameTable[frame].FrTopMargin;
   xm = x + ((l - thick) / 2);
   xf = x + l - 1;
   ym = y + ((h - thick) / 2);
   yf = y + h - 1;

   InitDrawing (style, thick, fg);
   if (orientation == 0)
     {
	/* draw a right arrow */
	DoDrawOneLine (frame, x, ym, xf, ym);
	ArrowDrawing (frame, x, ym, xf, ym, thick, fg);
     }
   else if (orientation == 45)
     {
	DoDrawOneLine (frame, x, yf, xf - thick + 1, y);
	ArrowDrawing (frame, x, yf, xf - thick + 1, y, thick, fg);
     }
   else if (orientation == 90)
     {
	/* draw a bottom-up arrow */
	DoDrawOneLine (frame, xm, y, xm, yf);
	ArrowDrawing (frame, xm, yf, xm, y, thick, fg);
     }
   else if (orientation == 135)
     {
	DoDrawOneLine (frame, x, y, xf - thick + 1, yf);
	ArrowDrawing (frame, xf - thick + 1, yf, x, y, thick, fg);
     }
   else if (orientation == 180)
     {
	/* draw a left arrow */
	DoDrawOneLine (frame, x, ym, xf, ym);
	ArrowDrawing (frame, xf, ym, x, ym, thick, fg);
     }
   else if (orientation == 225)
     {
	DoDrawOneLine (frame, x, yf, xf - thick + 1, y);
	ArrowDrawing (frame, xf - thick + 1, y, x, yf, thick, fg);
     }
   else if (orientation == 270)
     {
	/* draw a top-down arrow */
	DoDrawOneLine (frame, xm, y, xm, yf);
	ArrowDrawing (frame, xm, y, xm, yf, thick, fg);
     }
   else if (orientation == 315)
     {
	DoDrawOneLine (frame, x, y, xf - thick + 1, yf);
	ArrowDrawing (frame, x, y, xf - thick + 1, yf, thick, fg);
     }
}

/*----------------------------------------------------------------------
  DrawIntegral draws an integral. depending on type :
  - simple if type = 0
  - contour if type = 1
  - double if type = 2.
  parameter fg indicates the drawing color
  ----------------------------------------------------------------------*/
void DrawIntegral (int frame, int thick, int x, int y, int l, int h,
		   int type, ThotFont font, int fg)
{
  int                 yf;
  int                 yend, delta;
  int                 wd, asc, hd;

  if (FontHeight (font) *1.2 >= h)
     /* display a single glyph */
     {
     yf = y + ((h - CharacterHeight (242, font)) / 2) + CharacterAscent (242, font);
     DrawChar ('\362', frame, x, yf, font, fg);
     }
   else
     {
     /* Need more than one glyph */
     yf = y + CharacterAscent (243, font);
     DrawChar ('\363', frame, x, yf, font, fg);
     yend = y + h - CharacterHeight (245, font) 
       + CharacterAscent (245, font) - 1;
     DrawChar ('\365', frame, x, yend, font, fg);
     asc = CharacterAscent (244, font);
     hd = CharacterHeight (244, font);
     delta = yend - yf - asc;
     yf += asc;
     wd = (CharacterWidth (243, font) - CharacterWidth (244, font)) / 2;
     if (delta > 0 && hd > 0)
       {
	 while (yf < yend)
	   {
	     DrawChar ('\364', frame, x + wd, yf, font, fg);
	     yf += hd;
	   }
       }
     }
   if (type == 2)		/* double integral */
      DrawIntegral (frame, thick, x + (CharacterWidth (244, font) / 2),
		    y, l, h, -1, font, fg);

   else if (type == 1)		/* contour integral */
      DrawChar ('o', frame, x + ((l - CharacterWidth (111, font)) / 2),
		y + (h - CharacterHeight (111, font)) / 2 + CharacterAscent (111, font),
		font, fg);
}

/*----------------------------------------------------------------------
  DrawBracket draw an opening or closing bracket (depending on direction)
  parameter fg indicates the drawing color
  ----------------------------------------------------------------------*/
void DrawBracket (int frame, int thick, int x, int y, int l, int h,
		  int direction, ThotFont font, int fg, int baseline)
{
  int                 xm, yf, yend;

  /* Symbol */
  if (h <= (int) (1.3 * FontHeight (font)) )
    {
      /* With only one glyph */
      if (direction == 0)
	{
	  /* Draw a opening bracket */
	  xm = x + ((l - CharacterWidth (91, font)) / 2);
	  if (baseline)
	    yf = baseline;
	  else
	    yf = y + ((h - CharacterHeight (91, font)) / 2) +
	         CharacterAscent (91, font);
	  DrawChar ('[', frame, xm, yf, font, fg);
	}
      else
	{
	  /* Draw a closing bracket */
	  xm = x + ((l - CharacterWidth (93, font)) / 2);
	  if (baseline)
	    yf = baseline;
	  else
	    yf = y + ((h - CharacterHeight (93, font)) / 2) +
	         CharacterAscent (93, font);
	  DrawChar (']', frame, xm, yf, font, fg);
	}
     }
   else
     {
       /* Need more than one glyph */
       if (direction == 0)
	 {
	   /* Draw a opening bracket */
	   xm = x + ((l - CharacterWidth (233, font)) / 2);
	   yf = y + CharacterAscent (233, font);
	   DrawChar ('\351', frame, xm, yf, font, fg);
	   yend = y + h - CharacterHeight (235, font) + CharacterAscent (235, font);
	   DrawChar ('\353', frame, xm, yend, font, fg);
	   if (CharacterHeight (234, font) > 0)
	     for (yf = yf + CharacterHeight (233, font) + CharacterAscent (234, font);
		  yf < yend;
		  yf += CharacterHeight (234, font))
	       DrawChar ('\352', frame, xm, yf, font, fg);
	 }
       else
	 {
	   /* Draw a closing bracket */
	   xm = x + ((l - CharacterWidth (249, font)) / 2);
	   yf = y + CharacterAscent (249, font);
	   DrawChar ('\371', frame, xm, yf, font, fg);
	   yend = y + h - CharacterHeight (251, font) + CharacterAscent (251, font);
	   DrawChar ('\373', frame, xm, yend, font, fg);
	   if (CharacterHeight (250, font) > 0)
	     for (yf = yf + CharacterHeight (249, font) + CharacterAscent (250, font);
		  yf < yend;
		  yf += CharacterHeight (250, font))
	       DrawChar ('\372', frame, xm, yf, font, fg);
	 }
     }
}

/*----------------------------------------------------------------------
  DrawPointyBracket draw an opening or closing pointy bracket (depending
  on direction)
  parameter fg indicates the drawing color
  ----------------------------------------------------------------------*/
void DrawPointyBracket (int frame, int thick, int x, int y, int l, int h,
			int direction, ThotFont font, int fg)
{
  int         xm, yf;

  if (fg < 0)
    return;

  /*symbol*/
  if (FontHeight (font) >= h)
    {
      /* With only one glyph */
      if (direction == 0)
	{
	  /* Draw a opening bracket */
	  xm = x + ((l - CharacterWidth (225, font)) / 2);
	  yf = y + ((h - CharacterHeight (225, font)) / 2) + CharacterAscent (225, font);

	  DrawChar ('\341', frame, xm, yf, font, fg);
	}
      else
	{
	  /* Draw a closing bracket */
	  xm = x + ((l - CharacterWidth (241, font)) / 2);
	  yf = y + ((h - CharacterHeight (241, font)) / 2) + CharacterAscent (241, font);
	  DrawChar ('\361', frame, xm, yf, font, fg);
	}
    }
  else
    {
      /* Need more than one glyph */
      y += FrameTable[frame].FrTopMargin;
      InitDrawing (5, 4, fg);
      if (direction == 0)
	{
	  /* Draw a opening bracket */
	  DoDrawOneLine (frame, x + l, y, x, y + (h / 2));
	  DoDrawOneLine (frame, x, y + (h / 2), x + l, y + h);
	}
      else
	{
	  /* Draw a closing bracket */
	  DoDrawOneLine (frame, x, y, x + l, y + (h / 2));
	  DoDrawOneLine (frame, x + l, y + (h / 2), x, y + h);
	}
    }
}

/*----------------------------------------------------------------------
  DrawParenthesis draw a closing or opening parenthesis (direction).
  parameter fg indicates the drawing color
  ----------------------------------------------------------------------*/
void DrawParenthesis (int frame, int thick, int x, int y, int l, int h,
		      int direction, ThotFont font, int fg, int baseline)
{
  int                 xm, yf, yend, delta, asc, hd;


  /* Symbol */
   if (h <= (int) (1.3 * FontHeight (font)) )
    {
      /* With only one glyph */
      if (direction == 0)
	{
	  /* draw a opening parenthesis */
	  xm = x + ((l - CharacterWidth (40, font)) / 2);
	  if (baseline)
	    yf = baseline;
	  else
	    yf = y + ((h - CharacterHeight (40, font)) / 2) +
	         CharacterAscent (40, font);
	  DrawChar ('(', frame, xm, yf, font, fg);
	}
      else
	{
	  /* draw a closing parenthesis */
	  xm = x + ((l - CharacterWidth (41, font)) / 2);
	  if (baseline)
	    yf = baseline;
	  else	    
	    yf = y + ((h - CharacterHeight (41, font)) / 2) +
                 CharacterAscent (41, font);
	  DrawChar (')', frame, xm, yf, font, fg);
	}
    }
  else
    {
      /* Need more than one glyph */
      if (direction == 0)
	{
	  /* draw a opening parenthesis */
	  xm = x + ((l - CharacterWidth (230, font)) / 2);
	  yf = y + CharacterAscent (230, font);
	  DrawChar ('\346', frame, xm, yf, font, fg);
	  yend = y + h - CharacterHeight (232, font) + CharacterAscent (232, font) - 1;
	  DrawChar ('\350', frame, xm, yend, font, fg);
	  asc = CharacterAscent (231, font);
	  hd = CharacterHeight (231, font);
	  delta = yend - yf - hd;
	  yf += asc;
	  if (delta > 0 && hd > 0)
	    {
	      while (yf < yend)
		{
		  DrawChar ('\347', frame, xm, yf, font, fg);
		  yf += hd;
		}
	    }
	}
      else
	{
	  /* draw a closing parenthesis */
	  xm = x + ((l - CharacterWidth (246, font)) / 2);
	  yf = y + CharacterAscent (246, font);
	  DrawChar ('\366', frame, xm, yf, font, fg);
	  yend = y + h - CharacterHeight (248, font) 
	    + CharacterAscent (248, font) - 1;
	  DrawChar ('\370', frame, xm, yend, font, fg);
	  asc = CharacterAscent (247, font);
	  hd = CharacterHeight (247, font);
	  delta = yend - yf - hd;
	  yf += asc;
	  if (delta > 0 && hd > 0)
	    {
	      while (yf < yend)
		{
		  DrawChar ('\367', frame, xm, yf, font, fg);
		  yf += hd;
		}
	    }
	}
    }
}

/*----------------------------------------------------------------------
  DrawBrace draw an opening of closing brace (depending on direction).
  parameter fg indicates the drawing color
  ----------------------------------------------------------------------*/
void DrawBrace (int frame, int thick, int x, int y, int l, int h,
		int direction, ThotFont font, int fg, int baseline)
{
  int                 xm, ym, yf, yend, delta, hd, asc;

  /* symbol */
  if (h <= (int) (1.3 * FontHeight (font)) )
    {
      /* need only one char */
      if (direction == 0)
	{
	  /* just use the opening brace glyph */
	  xm = x + ((l - CharacterWidth (123, font)) / 2);
	  if (baseline)
	    yf = baseline;
	  else
	    yf = y + ((h - CharacterHeight (123, font)) / 2) +
	         CharacterAscent (123, font);
	  DrawChar ('{', frame, xm, yf, font, fg);
	}
      else
	{
	  /* just use the closing brace glyph */
	  xm = x + ((l - CharacterWidth (125, font)) / 2);
	  if (baseline)
	    yf = baseline;
	  else
	    yf = y + ((h - CharacterHeight (125, font)) / 2) +
	         CharacterAscent (125, font);
	  DrawChar ('}', frame, xm, yf, font, fg);
	}
    }
  else
    {
      /* Brace drawn with more than one glyph */
      if (direction == 0)
	{
	  /* top */
	  xm = x + ((l - CharacterWidth (236, font)) / 2);
	  yf = y + CharacterAscent (236, font);
	  DrawChar ('\354', frame, xm, yf, font, fg);
	  /* vertical line */
	  ym = y + ((h - CharacterHeight (237, font)) / 2) + CharacterAscent (237, font);
	  DrawChar ('\355', frame, xm, ym, font, fg);
	  /* bottom */
	  yend = y + h - CharacterHeight (238, font) + CharacterAscent (238, font);
	  DrawChar ('\356', frame, xm, yend, font, fg);
	  /* finish top */
	  asc = CharacterAscent (239, font);
	  hd = CharacterHeight (239, font);
	  delta = ym - yf - hd;
	  yf += asc;
	  if (delta > 0 && hd > 0)
	    {
	      while (yf < yend)
		{
		  DrawChar ('\357', frame, xm, yf, font, fg);
		  yf += hd;
		}
	    }
	  /* finish bottom */
	  yf = ym + CharacterHeight ('\355', font);
	  delta = yend - yf - hd;
	  yf += asc;
	  if (delta > 0 && hd > 0)
	    {
	      while (yf < yend)
		{
		  DrawChar ('\357', frame, xm, yf, font, fg);
		  yf += hd;
		}
	    }
	}
      else
	{
	  /* top */
	  xm = x + ((l - CharacterWidth (252, font)) / 2);
	  yf = y + CharacterAscent (252, font);
	  DrawChar ('\374', frame, xm, yf, font, fg);
	  /* center */
	  ym = y + ((h - CharacterHeight (253, font)) / 2) + CharacterAscent (253, font);
	  DrawChar ('\375', frame, xm, ym, font, fg);
	  /* bottom */
	  yend = y + h - CharacterHeight (254, font) + CharacterAscent (254, font);
	  DrawChar ('\376', frame, xm, yend, font, fg);
	  /* finish top */
	  asc = CharacterAscent (239, font);
	  hd = CharacterHeight (239, font);
	  delta = ym - yf - hd;
	  yf += asc;
	  if (delta > 0 && hd > 0)
	    {
	      while (yf < yend)
		{
		  DrawChar ('\357', frame, xm, yf, font, fg);
		  yf += hd;
		}
	    }
	  /* finish bottom */
	  yf = ym + CharacterHeight ('\375', font);
	  delta = yend - yf - hd;
	  yf += asc;
	  if (delta > 0 && hd > 0)
	    {
	      while (yf < yend)
		{
		  DrawChar ('\357', frame, xm, yf, font, fg);
		  yf += hd;
		}
	    }
	}
    }
}
/*----------------------------------------------------------------------
  DrawRectangle draw a rectangle located at (x, y) in frame,
  of geometry width x height.
  thick indicates the thickness of the lines.
  Parameters fg, bg, and pattern are for drawing
  color, background color and fill pattern.
  ----------------------------------------------------------------------*/
void DrawRectangle (int frame, int thick, int style, int x, int y, int width,
		    int height, int fg, int bg, int pattern)
{
  float        th;
  const GLubyte gPat1[] = {
    0x88, 0x88, 0x88, 0x88, 0x22, 0x22, 0x22, 0x22,
    0x88, 0x88, 0x88, 0x88, 0x22, 0x22, 0x22, 0x22,
    0x88, 0x88, 0x88, 0x88, 0x22, 0x22, 0x22, 0x22,
    0x88, 0x88, 0x88, 0x88, 0x22, 0x22, 0x22, 0x22,
    0x88, 0x88, 0x88, 0x88, 0x22, 0x22, 0x22, 0x22,
    0x88, 0x88, 0x88, 0x88, 0x22, 0x22, 0x22, 0x22,
    0x88, 0x88, 0x88, 0x88, 0x22, 0x22, 0x22, 0x22,
    0x88, 0x88, 0x88, 0x88, 0x22, 0x22, 0x22, 0x22,
    0x88, 0x88, 0x88, 0x88, 0x22, 0x22, 0x22, 0x22,
    0x88, 0x88, 0x88, 0x88, 0x22, 0x22, 0x22, 0x22,
    0x88, 0x88, 0x88, 0x88, 0x22, 0x22, 0x22, 0x22,
    0x88, 0x88, 0x88, 0x88, 0x22, 0x22, 0x22, 0x22,
    0x88, 0x88, 0x88, 0x88, 0x22, 0x22, 0x22, 0x22,
    0x88, 0x88, 0x88, 0x88, 0x22, 0x22, 0x22, 0x22,
    0x88, 0x88, 0x88, 0x88, 0x22, 0x22, 0x22, 0x22,
    0x88, 0x88, 0x88, 0x88, 0x22, 0x22, 0x22, 0x22 };

  if (width <= 0 || height <= 0)
    return;
  if (thick == 0 && pattern == 0)
    return;

  y += FrameTable[frame].FrTopMargin;
  th = (float) thick/2.;
  /* pattern = 4 => we're drawing a math empty place*/
  if (pattern == 4)
    {
      glEnable (GL_POLYGON_STIPPLE);   
      glPolygonStipple (gPat1);
      GL_DrawRectangle (fg, (float) x, (float) y,
			(float) width, (float) height);
    }
  else if (pattern == 2)
      GL_DrawRectangle (bg, (float) x + th, (float)y + th, 
			(float)width - th, (float)height - th);

  /* Draw the border */
  if (thick > 0 && fg >= 0)
    {
      if (width > thick)
	width = width - thick;
      if (height > thick)
	height = height - thick;
      InitDrawing (style, thick, fg); 
      GL_DrawEmptyRectangle (fg, (float) x + th, (float) y + th,
			     (float) width, (float) height,
			     (float) thick);
    }

  if (pattern == 4)
    glDisable (GL_POLYGON_STIPPLE);      
}

/*----------------------------------------------------------------------
  DrawDiamond draw a diamond.
  Parameters fg, bg, and pattern are for drawing
  color, background color and fill pattern.
  ----------------------------------------------------------------------*/
void DrawDiamond (int frame, int thick, int style, int x, int y, int width,
		  int height, int fg, int bg, int pattern)
{
  ThotPoint           point[5];

  if (width > thick + 1)
    width = width - thick - 1;
  if (height > thick + 1)
    height = height - thick - 1;
  x += thick / 2;
  y = y + thick / 2 + FrameTable[frame].FrTopMargin;

  point[0].x = x + (width / 2);
  point[0].y = y;
  point[4].x = point[0].x;
  point[4].y = point[0].y;
  point[1].x = x + width;
  point[1].y = y + (height / 2);
  point[2].x = point[0].x;
  point[2].y = y + height;
  point[3].x = x;
  point[3].y = point[1].y;

  /* Fill in the diamond */
  if (pattern == 2)
    {
      LoadColor (bg);
      GL_DrawPolygon (point, 5);
    }

  /* Draw the border */
  if (thick > 0 && fg >= 0)
    {
      InitDrawing (style, thick, fg);
      GL_DrawPolygon (point, 5);
    }
}

/*----------------------------------------------------------------------
  DrawSegments draw a set of segments.
  Parameter buffer is a pointer to the list of control points.
  nb indicates the number of points.
  The first point is a fake one containing the geometry.
  fg parameter gives the drawing color.
  arrow parameter indicates whether :
  - no arrow have to be drawn (0)
  - a forward arrow has to be drawn (1)
  - a backward arrow has to be drawn (2)
  - both backward and forward arrows have to be drawn (3)
  ----------------------------------------------------------------------*/
void DrawSegments (int frame, int thick, int style, int x, int y,
		   PtrTextBuffer buffer, int nb, int fg, int arrow, int bg,
		   int pattern)
{
  int                 k;
  ThotPoint          *points;
  int                 i, j;
  PtrTextBuffer       adbuff;
  
  /* fill the included polygon */
  DrawPolygon (frame, 0, style, x, y, buffer, nb, fg, bg, pattern);
  if (thick == 0 || fg < 0)
    return;
  
  /* Allocate a table of points */
  points = (ThotPoint *) TtaGetMemory (sizeof (ThotPoint) * (nb - 1));
  adbuff = buffer;
  y += FrameTable[frame].FrTopMargin;
  j = 1;
  for (i = 1; i < nb; i++)
    {
      if (j >= adbuff->BuLength &&
          adbuff->BuNext != NULL)
        {
          /* Next buffer */
          adbuff = adbuff->BuNext;
          j = 0;
        }
      points[i - 1].x = x + PixelValue (adbuff->BuPoints[j].XCoord,
                                        UnPixel, NULL,
                                        ViewFrameTable[frame - 1].FrMagnification);
      points[i - 1].y = y + PixelValue (adbuff->BuPoints[j].YCoord,
                                        UnPixel, NULL,
                                        ViewFrameTable[frame - 1].FrMagnification);
      //      printf("nb=%d XCoord=%d YCoord=%d\n", j, adbuff->BuPoints[j].XCoord, adbuff->BuPoints[j].YCoord );
      j++;
    }
  
  /* backward arrow  */
  if (arrow == 2 || arrow == 3)
    ArrowDrawing (frame,
                  (int)points[1].x, (int)points[1].y,
                  (int)points[0].x, (int)points[0].y,
                  thick, fg);
  
  /* Draw the border */
  InitDrawing (style, thick, fg);
  for (k=0; k< nb-2; k++)
    GL_DrawLine((int)points[k].x, (int)points[k].y,
                (int)points[k+1].x, (int)points[k+1].y, TRUE);
  
  /* Forward arrow */
  if (arrow == 1 || arrow == 3)
    ArrowDrawing (frame,
                  (int)points[nb - 3].x, (int)points[nb - 3].y,
                  (int)points[nb - 2].x, (int)points[nb - 2].y,
                  thick, fg);
  
  /* free the table of points */
  TtaFreeMemory (points);
}

/*----------------------------------------------------------------------
  DoDrawLines
  Draw a polygon whose points are stored in buffer points
  Parameters fg, bg, and pattern are for drawing
  color, background color and fill pattern.
  ----------------------------------------------------------------------*/
static void DoDrawLines (int frame, int thick, int style,
			 ThotPoint *points, int npoints, int fg, int bg,
			 int pattern)
{

  /* Fill in the polygon */
  if (pattern == 2) 
    {
      /*  InitDrawing (style, thick, bg); */
      GL_SetForeground (bg);
      GL_DrawPolygon (points, npoints);
    }

  /* Draw the border */
  if (thick > 0 && fg >= 0)
    {
      InitDrawing (style, thick, fg);
      GL_DrawLines (points, npoints);
    }
}

/*----------------------------------------------------------------------
  DrawPolygon draw a polygon.
  Parameter buffer is a pointer to the list of control points.
  nb indicates the number of points.
  The first point is a fake one containing the geometry.
  Parameters fg, bg, and pattern are for drawing
  color, background color and fill pattern.
  ----------------------------------------------------------------------*/
void DrawPolygon (int frame, int thick, int style, int x, int y,
		  PtrTextBuffer buffer, int nb, int fg, int bg, int pattern)
{
  ThotPoint          *points;
  int                 i, j;
  PtrTextBuffer       adbuff;

  /* Allocate a table of points */
  points = (ThotPoint *) TtaGetMemory (sizeof (ThotPoint) * nb);
  adbuff = buffer;
  y += FrameTable[frame].FrTopMargin;
  j = 1;
  for (i = 1; i < nb; i++)
    {
      if (j >= adbuff->BuLength && adbuff->BuNext != NULL)
	{
	  /* Next buffer */
	  adbuff = adbuff->BuNext;
	  j = 0;
	}
      points[i - 1].x = x + PixelValue (adbuff->BuPoints[j].XCoord,
					UnPixel, NULL,
					ViewFrameTable[frame - 1].FrMagnification);
      points[i - 1].y = y + PixelValue (adbuff->BuPoints[j].YCoord,
					UnPixel, NULL,
					ViewFrameTable[frame - 1].FrMagnification);
      j++;
    }
  /* Close the polygon */
  points[nb - 1].x = points[0].x;
  points[nb - 1].y = points[0].y;
  DoDrawLines (frame, thick, style, points, nb, fg, bg, pattern);
  /* free the table of points */
  TtaFreeMemory (points);
}

/*----------------------------------------------------------------------
  DrawCurve draw an open curve.
  Parameter buffer is a pointer to the list of control points.
  nb indicates the number of points.
  The first point is a fake one containing the geometry.
  fg indicates the drawing color
  arrow parameter indicates whether :
  - no arrow have to be drawn (0)
  - a forward arrow has to be drawn (1)
  - a backward arrow has to be drawn (2)
  - both backward and forward arrows have to be drawn (3)
  Parameter control indicates the control points.
  ----------------------------------------------------------------------*/
void DrawCurve (int frame, int thick, int style, int x, int y,
		PtrTextBuffer buffer, int nb, int fg, int arrow,
		C_points *controls)
{
  ThotPoint           *points;
  int                 npoints, maxpoints;
  PtrTextBuffer       adbuff;
  int                 i, j;
  double              x1, y1, x2, y2;
  double              cx1, cy1, cx2, cy2;

  if (thick == 0 || fg < 0)
    return;

  /* alloue la liste des points */
  npoints = 0;
  maxpoints = ALLOC_POINTS;

  points = (ThotPoint *) TtaGetMemory (sizeof (ThotPoint) * maxpoints);
  adbuff = buffer;
  y += FrameTable[frame].FrTopMargin;
  j = 1;
  x1 = (double) (x + PixelValue (adbuff->BuPoints[j].XCoord,
				UnPixel, NULL,
				ViewFrameTable[frame - 1].FrMagnification));
  y1 = (double) (y + PixelValue (adbuff->BuPoints[j].YCoord,
				UnPixel, NULL,
				ViewFrameTable[frame - 1].FrMagnification));
  j++;
  cx1 = (controls[j].lx * 3 + x1 - x) / 4 + x;
  cy1 = (controls[j].ly * 3 + y1 - y) / 4 + y;
  x2 = (double) (x + PixelValue (adbuff->BuPoints[j].XCoord,
				UnPixel, NULL,
				ViewFrameTable[frame - 1].FrMagnification));
  y2 = (double) (y + PixelValue (adbuff->BuPoints[j].YCoord,
				UnPixel, NULL,
				ViewFrameTable[frame - 1].FrMagnification));
  cx2 = (controls[j].lx * 3 + x2 - x) / 4 + x;
  cy2 = (controls[j].ly * 3 + y2 - y) / 4 + y;

  /* backward arrow  */
  if (arrow == 2 || arrow == 3)
    ArrowDrawing (frame,
		  FloatToInt ((float)cx1), FloatToInt ((float)cy1),
		  (int) x1, (int) y1,
		  thick, fg);
  
  for (i = 2; i < nb; i++)
    {
      PolySplit (x1, y1, cx1, cy1, cx2, cy2, x2, y2, &points, &npoints,
		 &maxpoints);
      /* skip to next points */
      x1 = x2;
      y1 = y2;
      cx1 = controls[i].rx + x;
      cy1 = controls[i].ry + y;
      if (i < nb - 1)
	{
	  /* not finished */
	  j++;
	  if (j >= adbuff->BuLength &&
	      adbuff->BuNext != NULL)
	    {
	      /* Next buffer */
	      adbuff = adbuff->BuNext;
	      j = 0;
	    }
	  x2 = (double) (x + PixelValue (adbuff->BuPoints[j].XCoord,
					UnPixel, NULL,
					ViewFrameTable[frame - 1].FrMagnification));
	  y2 = (double) (y + PixelValue (adbuff->BuPoints[j].YCoord,
					UnPixel, NULL,
					ViewFrameTable[frame - 1].FrMagnification));
	  if (i == nb - 2)
	    {
	      cx1 = (controls[i].rx * 3 + x1 - x) / 4 + x;
	      cy1 = (controls[i].ry * 3 + y1 - y) / 4 + y;
	      cx2 = (controls[i].rx * 3 + x2 - x) / 4 + x;
	      cy2 = (controls[i].ry * 3 + y2 - y) / 4 + y;
	    }
	  else
	    {
	      cx2 = controls[i + 1].lx + x;
	      cy2 = controls[i + 1].ly + y;
	    }
	}
    }
  PolyNewPoint (x2, y2, &points, &npoints, &maxpoints);

  /* Draw the border */
  InitDrawing (style, thick, fg);
  GL_DrawLines(points, npoints);
  /* Forward arrow */
  if (arrow == 1 || arrow == 3)
    ArrowDrawing (frame,
		  FloatToInt ((float)cx2), FloatToInt ((float)cy2),
		  (int) x2, (int) y2,
		  thick, fg);

  /* free the table of points */
  TtaFreeMemory (points);
}

/*----------------------------------------------------------------------
  DrawSpline draw a closed curve.
  Parameter buffer is a pointer to the list of control points.
  nb indicates the number of points.
  The first point is a fake one containing the geometry.
  Parameters fg, bg, and pattern are for drawing
  color, background color and fill pattern.
  Parameter controls contains the list of control points.
  ----------------------------------------------------------------------*/
void DrawSpline (int frame, int thick, int style, int x, int y,
		 PtrTextBuffer buffer, int nb, int fg, int bg, int pattern,
		 C_points *controls)
{
  ThotPoint           *points;
  int                  npoints, maxpoints;
  PtrTextBuffer        adbuff;
  int                  i, j;
  double               x1, y1, x2, y2;
  double               cx1, cy1, cx2, cy2;

  /* allocate the list of points */
  npoints = 0;
  maxpoints = ALLOC_POINTS;
  points = (ThotPoint *) TtaGetMemory (sizeof (ThotPoint) * maxpoints);
  adbuff = buffer;
  y += FrameTable[frame].FrTopMargin;
  j = 1;
  x1 = (double) (x + PixelValue (adbuff->BuPoints[j].XCoord,
				UnPixel, NULL,
				ViewFrameTable[frame - 1].FrMagnification));
  y1 = (double) (y + PixelValue (adbuff->BuPoints[j].YCoord,
				UnPixel, NULL,
				ViewFrameTable[frame - 1].FrMagnification));
  cx1 = controls[j].rx + x;
  cy1 = controls[j].ry + y;
  j++;
  x2 = (double) (x + PixelValue (adbuff->BuPoints[j].XCoord,
				UnPixel, NULL,
				ViewFrameTable[frame - 1].FrMagnification));
  y2 = (double) (y + PixelValue (adbuff->BuPoints[j].YCoord,
				UnPixel, NULL,
				ViewFrameTable[frame - 1].FrMagnification));
  cx2 = controls[j].lx + x;
  cy2 = controls[j].ly + y;

  for (i = 2; i < nb; i++)
    {
      PolySplit (x1, y1, cx1, cy1, cx2, cy2, x2, y2, &points, &npoints,
		 &maxpoints);
      /* next points */
      x1 = x2;
      y1 = y2;
      cx1 = controls[i].rx + x;
      cy1 = controls[i].ry + y;
      if (i < nb - 1)
	{
	  /* not the last loop */
	  j++;
	  if (j >= adbuff->BuLength &&
	      adbuff->BuNext != NULL)
	    {
	      /* Next buffer */
	      adbuff = adbuff->BuNext;
	      j = 0;
	    }
	  x2 = (double) (x + PixelValue (adbuff->BuPoints[j].XCoord,
					UnPixel, NULL,
					ViewFrameTable[frame - 1].FrMagnification));
	  y2 = (double) (y + PixelValue (adbuff->BuPoints[j].YCoord,
					UnPixel, NULL,
					ViewFrameTable[frame - 1].FrMagnification));
	  cx2 = controls[i + 1].lx + x;
	  cy2 = controls[i + 1].ly + y;
	}
      else
	{
	  /* loop around the origin point */
	  x2 = (double) (x + PixelValue (buffer->BuPoints[1].XCoord,
					UnPixel, NULL,
					ViewFrameTable[frame - 1].FrMagnification));
	  y2 = (double) (y + PixelValue (buffer->BuPoints[1].YCoord,
					UnPixel, NULL,
					ViewFrameTable[frame - 1].FrMagnification));
	  cx2 = controls[1].lx + x;
	  cy2 = controls[1].ly + y;
	}
    }

  /* close the polyline */
  PolySplit (x1, y1, cx1, cy1, cx2, cy2, x2, y2, &points, &npoints, &maxpoints);
  PolyNewPoint ((int) x2, (int) y2, &points, &npoints, &maxpoints);

  /* Fill in the polygone */
  if (pattern == 2)
    {
      GL_SetForeground (bg);
      GL_DrawPolygon (points, npoints);
    }

  /* Draw the border */
  if (thick > 0 && fg >= 0)
    {
      InitDrawing (style, thick, fg);
      GL_DrawPolygon (points, npoints);
    }

  /* free the table of points */
  TtaFreeMemory (points);
}


/*----------------------------------------------------------------------
  DoDrawMesh : Draw Path as lines or polygons
  ----------------------------------------------------------------------*/
static void DoDrawMesh (int frame, int thick, int style,
			void *mesh, int fg, int bg,
			int pattern)
{
  /* Fill in the polygon */
  if (pattern == 2) 
    {
      /*  InitDrawing (style, thick, bg); */
      GL_SetForeground (bg); 
      MakeMesh (mesh);  
    }
  /* Draw the border */
  if (thick > 0 && fg >= 0)
    {
      InitDrawing (style, thick, fg);
      MakeMeshLines (mesh);
    }
}

/*----------------------------------------------------------------------
  PixelValueDble : check if we need calculation
  ----------------------------------------------------------------------*/
static double PixelValueDble (int nb, int real_nb, int frame)
{
  if (ViewFrameTable[frame - 1].FrMagnification)
    return (double) (nb + PixelValue (real_nb, UnPixel, NULL,
				     ViewFrameTable[frame - 1].FrMagnification));
  else
    return (double) (nb + real_nb);
}

/*----------------------------------------------------------------------
  DrawPath draws a path.
  Parameter path is a pointer to the list of path segments
  fg indicates the drawing color
  ----------------------------------------------------------------------*/
void DrawPath (int frame, int thick, int style, int x, int y,
	       PtrPathSeg path, int fg, int bg, int pattern)
{
  PtrPathSeg   pPa;
  double       x1, y1, cx1, cy1, x2, y2, cx2, cy2;
  void        *mesh;  

  if (thick > 0 || fg >= 0)
    {
      y += FrameTable[frame].FrTopMargin;
      mesh = GetNewMesh ();
      pPa = path;
      while (pPa)
	{
	  if (pPa->PaNewSubpath)
	    CountourCountAdd (mesh);
	  switch (pPa->PaShape)
	    {
	    case PtLine:
	      x1 = PixelValueDble (x, pPa->XStart, frame);	      
	      y1 = PixelValueDble (y, pPa->YStart, frame);
	      x2 = PixelValueDble (x, pPa->XEnd, frame);
	      y2 = PixelValueDble (y, pPa->YEnd, frame);
	      MeshNewPoint (x1, y1, mesh);
	      MeshNewPoint (x2, y2, mesh);
	      break;

	    case PtCubicBezier:
	      x1 = PixelValueDble (x, pPa->XStart, frame);
	      y1 = PixelValueDble (y, pPa->YStart, frame);
	      x2 = PixelValueDble (x, pPa->XEnd, frame);
	      y2 = PixelValueDble (y, pPa->YEnd, frame);
	      cx1 = PixelValueDble (x, pPa->XCtrlStart, frame);
	      cy1 = PixelValueDble (y, pPa->YCtrlStart, frame);
	      cx2 = PixelValueDble (x, pPa->XCtrlEnd, frame);
	      cy2 = PixelValueDble (y, pPa->YCtrlEnd, frame);
	      PolySplit2 (x1, y1, cx1, cy1, cx2, cy2, x2, y2, mesh);
	      MeshNewPoint (x2, y2, mesh);
	      break;

	    case PtQuadraticBezier:
	      x1 = PixelValueDble (x, pPa->XStart, frame);
	      y1 = PixelValueDble (y, pPa->YStart, frame);
	      x2 = PixelValueDble (x, pPa->XEnd, frame);
	      y2 = PixelValueDble (y, pPa->YEnd, frame);
	      cx1 = PixelValueDble (x, pPa->XCtrlStart, frame);
	      cy1 = PixelValueDble (y, pPa->YCtrlStart, frame);
	      QuadraticSplit2 (x1, y1, cx1, cy1, x2, y2, mesh);
	      MeshNewPoint (x2, y2, mesh);
	      break;

	    case PtEllipticalArc:
	      x1 = PixelValueDble (x, pPa->XStart, frame);
	      y1 = PixelValueDble (y, pPa->YStart, frame);
	      x2 = PixelValueDble (x, pPa->XEnd, frame);
	      y2 = PixelValueDble (y, pPa->YEnd, frame);
	      cx1 = (double) pPa->XRadius; 
	      cy1 = (double) pPa->YRadius; 
	      EllipticSplit2 (frame, x, y,
			      x1, y1, 
			      x2, y2, 
			      cx1, cy1,
			      fmod (pPa->XAxisRotation, 360), 
			      pPa->LargeArc, pPa->Sweep,
			      mesh);
	      MeshNewPoint (x2, y2, mesh);
	      break;
	    }
	  pPa = pPa->PaNext;
	}
      CountourCountAdd (mesh);
      DoDrawMesh (frame, thick, style, mesh, fg, bg, pattern);     
      /* free the table of points */
      FreeMesh (mesh);
    }  
}

/*----------------------------------------------------------------------
  DrawOval draw a rectangle with rounded corners.
  Parameters fg, bg, and pattern are for drawing
  color, background color and fill pattern.
  ----------------------------------------------------------------------*/
void DrawOval (int frame, int thick, int style, int x, int y, int width,
	       int height, int rx, int ry, int fg, int bg, int pattern)
{
  int                 i;
  int                 arc, dx, dy;
  int                 xf, yf;
  ThotArc             xarc[4];
  ThotSegment         seg[4];
  ThotPoint           point[13];

  /* width -= thick; */
/*   height -= thick; */
/*   x += thick / 2; */
/*   y += thick / 2; */

  y += FrameTable[frame].FrTopMargin;

  /* radius of arcs */
  if (rx == 0 && ry != 0)
    rx = ry;
  else if (ry == 0 && rx != 0)
    ry = rx;
  arc = width / 2;
  if (rx > arc)
    rx = arc;
  arc = height / 2;
  if (ry > arc)
    ry = arc;
  dx = rx;
  dy = ry;
  rx = rx * 2;
  ry = ry * 2;
  xf = x + width - 1;
  yf = y + height - 1;

  xarc[0].x = x;
  xarc[0].y = y;
  xarc[0].width = rx;
  xarc[0].height = ry;
  xarc[0].angle1 = 90;
  xarc[0].angle2 = 90;

  xarc[1].x = xf - rx;
  xarc[1].y = xarc[0].y;
  xarc[1].width = rx;
  xarc[1].height = ry;
  xarc[1].angle1 = 0;
  xarc[1].angle2 = xarc[0].angle2;

  xarc[2].x = xarc[0].x;
  xarc[2].y = yf - ry;
  xarc[2].width = rx;
  xarc[2].height = ry;
  xarc[2].angle1 = 180;
  xarc[2].angle2 = xarc[0].angle2;

  xarc[3].x = xarc[1].x;
  xarc[3].y = xarc[2].y;
  xarc[3].width = rx;
  xarc[3].height = ry;
  xarc[3].angle1 = 270;
  xarc[3].angle2 = xarc[0].angle2;

  seg[0].x1 = x + dx;
  seg[0].x2 = xf - dx;
  seg[0].y1 = y;
  seg[0].y2 = seg[0].y1;

  seg[1].x1 = xf;
  seg[1].x2 = seg[1].x1;
  seg[1].y1 = y + dy;
  seg[1].y2 = yf - dy;

  seg[2].x1 = seg[0].x1;
  seg[2].x2 = seg[0].x2;
  seg[2].y1 = yf;
  seg[2].y2 = seg[2].y1;

  seg[3].x1 = x;
  seg[3].x2 = seg[3].x1;
  seg[3].y1 = seg[1].y1;
  seg[3].y2 = seg[1].y2;

  /* Fill in the figure */
  if (pattern == 2)
    {
      /* Polygone inscrit: (seg0)       */
      /*                   0--1         */
      /*                10-|  |-3       */
      /*         (seg3) |       |(seg1) */
      /*                9--|  |-4       */
      /*                   7--6         */
      /*                   (seg2)       */
      point[0].x = seg[0].x1;
      point[0].y = seg[0].y1;

      point[1].x = seg[0].x2;
      point[1].y = point[0].y;
      point[2].x = point[1].x;
      point[2].y = seg[1].y1;

      point[3].x = seg[1].x1;
      point[3].y = point[2].y;
      point[4].x = point[3].x;
      point[4].y = seg[1].y2;

      point[5].x = seg[2].x2;
      point[5].y = point[4].y;
      point[6].x = point[5].x;
      point[6].y = seg[2].y2;

      point[7].x = seg[2].x1;
      point[7].y = point[6].y;
      point[8].x = point[7].x;
      point[8].y = seg[3].y2;

      point[9].x = seg[3].x2;
      point[9].y = point[8].y;
      point[10].x = point[9].x;
      point[10].y = seg[3].y1;

      point[11].x = point[0].x;
      point[11].y = point[10].y;
      point[12].x = point[0].x;
      point[12].y = point[0].y;

      GL_SetForeground (bg);
      GL_DrawPolygon (point, 13);
      for (i=0;i<4;i++)
	{
	  GL_DrawArc (xarc[i].x + thick/4, xarc[i].y + thick/4, 
		      xarc[i].width - thick/4, xarc[i].height-thick/4, 
		      xarc[i].angle1, xarc[i].angle2,
		      TRUE); 
	}
    }

  /* Draw the border */
  if (thick > 0 && fg >= 0)
    {
      InitDrawing (style, thick, fg);
      for (i=0;i<4;i++)
	GL_DrawArc (xarc[i].x, xarc[i].y, 
		    xarc[i].width, xarc[i].height, 
		    xarc[i].angle1, xarc[i].angle2,
		    FALSE);
      GL_DrawSegments (seg, 4);
    }
}

/*----------------------------------------------------------------------
  DrawEllips draw an ellips (or a circle).
  Parameters fg, bg, and pattern are for drawing color, background color
  and fill pattern.
  ----------------------------------------------------------------------*/
void DrawEllips (int frame, int thick, int style, int x, int y, int width,
		 int height, int fg, int bg, int pattern)
{
   
 
   
  /* Fill in the rectangle */
  if (pattern != 2 && thick <= 0 && pattern != fg)
    return;

  if (pattern == fg)
    bg = fg;
 

  y = y + FrameTable[frame].FrTopMargin;

  if (pattern == 2 || (bg == fg && bg == pattern))
    {

      /* InitDrawing (style, thick, bg); */
      GL_SetForeground (bg);
      GL_DrawArc (x + thick/2, y + thick/2, 
		  width - thick/2, height - thick/2, 
		  0, 360, TRUE);
    }
  /* Draw the border */
  if (thick > 0 && fg >= 0)
    {
      InitDrawing (style, thick, fg);
      GL_DrawArc (x, y, width, height, 0, 360, FALSE);
    }


}

/*----------------------------------------------------------------------
  DrawHorizontalLine draw a horizontal line aligned top center or bottom
  depending on align value.
  The parameter fg indicates the drawing color.
  ----------------------------------------------------------------------*/
void DrawHorizontalLine (int frame, int thick, int style, int x, int y,
			 int l, int h, int align, int fg)
{
  int        Y;

  if (thick > 0 && fg >= 0)
    {
      y += FrameTable[frame].FrTopMargin;

      if (align == 1)
	Y = y + (h - thick) / 2;
      else if (align == 2)
	Y = y + h - (thick + 1) / 2;
      else
	Y = y + thick / 2;

      /* x += thick / 2; */
      /*       l -= thick; */
            
      InitDrawing (style, thick, fg);
      DoDrawOneLine (frame, x, Y, x + l, Y);
    }
}
/*----------------------------------------------------------------------
  DrawVerticalLine draw a vertical line aligned left center or right
  depending on align value.
  parameter fg indicates the drawing color
  ----------------------------------------------------------------------*/
void DrawVerticalLine (int frame, int thick, int style, int x, int y,
		       int l, int h, int align, int fg)
{
  int        X;

  if (thick > 0 && fg >= 0)
    {
      if (align == 1)
	X = x + (l - thick) / 2;
      else if (align == 2)
	X = x + l - (thick + 1) / 2;
      else
	X = x + thick / 2;
      
      /* y += thick / 2; */
      /*       h -= thick; */

      y += FrameTable[frame].FrTopMargin;
      InitDrawing (style, thick, fg);
      DoDrawOneLine (frame, X, y, X, y + h);
    }
}

/*----------------------------------------------------------------------
  DrawDoubleVerticalLine draw a double vertical line aligned left center
  or right depending on align value.
  parameter fg indicates the drawing color
  ----------------------------------------------------------------------*/
void DrawDoubleVerticalLine (int frame, int thick, int style, int x, int y,
			     int l, int h, int align, int fg)
{
  int        X;

  if (thick > 0 && fg >= 0)
    {
      if (align == 1)
	X = x + (l - thick) / 2;
      else if (align == 2)
	X = x + l - (thick + 1) / 2;
      else
	X = x + thick / 2;
      
      y += FrameTable[frame].FrTopMargin;

      /* y += thick / 2; */
      /*       h -= thick;   */

      InitDrawing (style, thick, fg);
      DoDrawOneLine (frame, X, y, X, y + h);
      DoDrawOneLine (frame, X + (3 * thick), y, X + (3 * thick), y + h);
    }
}

/*----------------------------------------------------------------------
  DrawHorizontalBrace draw a horizontal brace aligned top or bottom
  depending on align value.
  The parameter fg indicates the drawing color.
  ----------------------------------------------------------------------*/
void DrawHorizontalBrace (int frame, int thick, int style, int x, int y,
			  int l, int h, int align, int fg)
{
  int        Y;

  if (thick > 0 && fg >= 0)
    {
      y += FrameTable[frame].FrTopMargin;
      Y = y + (h - thick) / 2;
      InitDrawing (style, thick, fg);
      DoDrawOneLine (frame, x, Y, x + l, Y);
      if (align == 0)
	/* Over brace */
	{
	  DoDrawOneLine (frame, x, Y, x, y + h);
	  DoDrawOneLine (frame, x + (l / 2), Y, x + (l / 2), y);
	  DoDrawOneLine (frame, x + l - thick, Y, x + l - thick, y + h);
	}
      else
	/* Underbrace */
	{
	  DoDrawOneLine (frame, x, Y, x, y);
	  DoDrawOneLine (frame, x + (l / 2), Y, x + (l / 2), y + h);
	  DoDrawOneLine (frame, x + l - thick, Y, x + l - thick, y);
	}
    }
}



/*----------------------------------------------------------------------
  DrawSlash draw a slash or backslash depending on direction.
  Le parame`tre indique la couleur du trace'.
  ----------------------------------------------------------------------*/
void DrawSlash (int frame, int thick, int style, int x, int y, int l, int h,
		int direction, int fg)
{
  int                 xf, yf;

  y += FrameTable[frame].FrTopMargin;
  xf = x + l;
  yf = y + h;
  if (thick > 0 && fg >= 0)
    {
      InitDrawing (style, thick, fg);
      if (direction == 0)
	DoDrawOneLine (frame, x, yf, xf, y);
      else
	DoDrawOneLine (frame, x, y, xf, yf);
    }
}

/*----------------------------------------------------------------------
  DrawCorner draw a corner.
  parameter fg indicates the drawing color
  ----------------------------------------------------------------------*/
void DrawCorner (int frame, int thick, int style, int x, int y, int l,
		 int h, int corner, int fg)
{
  ThotPoint           point[3];
  int                 xf, yf;

  if (thick <= 0)
    return;

  y += FrameTable[frame].FrTopMargin;
  xf = x + l - thick;
  yf = y + h - thick;
  InitDrawing (style, thick, fg);
  switch (corner)
    {
    case 0:
      point[0].x = x;
      point[0].y = y;
      point[1].x = xf;
      point[1].y = y;
      point[2].x = xf;
      point[2].y = yf;
      break;
    case 1:
      point[0].x = xf;
      point[0].y = y;
      point[1].x = xf;
      point[1].y = yf;
      point[2].x = x;
      point[2].y = yf;
      break;
    case 2:
      point[0].x = xf;
      point[0].y = yf;
      point[1].x = x;
      point[1].y = yf;
      point[2].x = x;
      point[2].y = y;
      break;
    case 3:
      point[0].x = x;
      point[0].y = yf;
      point[1].x = x;
      point[1].y = y;
      point[2].x = xf;
      point[2].y = y;
      break;
    }
  GL_DrawLines (point, 3);
}

/*----------------------------------------------------------------------
  DrawRectangleFrame draw a rectangle with smoothed corners (3mm radius)
  and with an horizontal line at 6mm from top.
  Parameters fg, bg, and pattern are for drawing
  color, background color and fill pattern.
  ----------------------------------------------------------------------*/
void DrawRectangleFrame (int frame, int thick, int style, int x, int y,
			 int width, int height, int fg, int bg, int pattern)
{
  int                 i;
  int                 arc, arc2, xf, yf;
  ThotArc             xarc[4];
  ThotSegment         seg[5];
  ThotPoint           point[13];

  y = y + FrameTable[frame].FrTopMargin;

  width -= thick;
  height -= thick;
  x += thick / 2;
  y = y + thick / 2;

  /* radius of arcs is 3mm */
  arc = (int)((3 * DOT_PER_INCH) / 25.4 + 0.5);
  arc2 = 2 * arc;

  xf = x + width;
  yf = y + height;

  xarc[0].x = x;
  xarc[0].y = y;
  xarc[0].width = arc2;
  xarc[0].height = arc2;
  xarc[0].angle1 = 90 * 64;
  xarc[0].angle2 = 90 * 64;

  xarc[1].x = xf - arc2;
  xarc[1].y = y;
  xarc[1].width = xarc[0].width;
  xarc[1].height = xarc[0].width;
  xarc[1].angle1 = 0;
  xarc[1].angle2 = xarc[0].angle2;

  xarc[2].x = x;
  xarc[2].y = yf - arc2;
  xarc[2].width = xarc[0].width;
  xarc[2].height = xarc[0].width;
  xarc[2].angle1 = 180 * 64;
  xarc[2].angle2 = xarc[0].angle2;

  xarc[3].x = xarc[1].x;
  xarc[3].y = xarc[2].y;
  xarc[3].width = xarc[0].width;
  xarc[3].height = xarc[0].width;
  xarc[3].angle1 = 270 * 64;
  xarc[3].angle2 = xarc[0].angle2;

  seg[0].x1 = x + arc;
  seg[0].y1 = y;
  seg[0].x2 = xf - arc;
  seg[0].y2 = y;

  seg[1].x1 = xf;
  seg[1].y1 = y + arc;
  seg[1].x2 = xf;
  seg[1].y2 = yf - arc;

  seg[2].x1 = seg[0].x1;
  seg[2].y1 = yf;
  seg[2].x2 = seg[0].x2;
  seg[2].y2 = yf;

  seg[3].x1 = x;
  seg[3].y1 = seg[1].y1;
  seg[3].x2 = x;
  seg[3].y2 = seg[1].y2;

  /* horizontal line at 6mm from top */
  if (arc2 < height / 2)
    {
      /* not under half-height */
      seg[4].x1 = x;
      seg[4].y1 = y + arc2;
      seg[4].x2 = xf;
      seg[4].y2 = y + arc2;
    }

  /* Fill in the figure */
  if (pattern == 2)
    {
      /* Polygone:         (seg0)       */
      /*                   0--1         */
      /*                10-|  |-3       */
      /*         (seg3) |       |(seg1) */
      /*                9--|  |-4       */
      /*                   7--6         */
      /*                   (seg2)       */
      point[0].x = seg[0].x1;
      point[0].y = seg[0].y1;

      point[1].x = seg[0].x2;
      point[1].y = point[0].y;
      point[2].x = point[1].x;
      point[2].y = seg[1].y1;

      point[3].x = seg[1].x1;
      point[3].y = point[2].y;
      point[4].x = point[3].x;
      point[4].y = seg[1].y2;

      point[5].x = seg[2].x2;
      point[5].y = point[4].y;
      point[6].x = point[5].x;
      point[6].y = seg[2].y2;

      point[7].x = seg[2].x1;
      point[7].y = point[6].y;
      point[8].x = point[7].x;
      point[8].y = seg[3].y2;

      point[9].x = seg[3].x2;
      point[9].y = point[8].y;
      point[10].x = point[9].x;
      point[10].y = seg[3].y1;

      point[11].x = point[0].x;
      point[11].y = point[10].y;
      point[12].x = point[0].x;
      point[12].y = point[0].y;

      GL_SetForeground (bg);
      GL_DrawPolygon (point, 13);
      for (i = 0; i < 4; i++)
	{  
	  GL_DrawArc	(xarc[i].x, xarc[i].y, 
			 xarc[i].width, xarc[i].height, 
			 xarc[i].angle1, xarc[i].angle2,
			 TRUE);
	}
    }

  /* Draw the border */
  if (thick > 0 && fg >= 0)
    {
      InitDrawing (style, thick, fg);
      for (i = 0 ; i < 4; i++)
	{  
	  GL_DrawArc (xarc[i].x, xarc[i].y, 
		      xarc[i].width, xarc[i].height, 
		      xarc[i].angle1, xarc[i].angle2,
		      FALSE); 
	}
      if (arc2 < height / 2)
	GL_DrawSegments(seg, 5);
      else
	GL_DrawSegments(seg, 4);
     }
}


/*----------------------------------------------------------------------
  DrawEllipsFrame draw an ellipse at 7mm under the top of the
  enclosing box.
  Parameters fg, bg, and pattern are for drawing
  color, background color and fill pattern.
  ----------------------------------------------------------------------*/
void DrawEllipsFrame (int frame, int thick, int style, int x, int y,
		      int width, int height, int fg, int bg, int pattern)
{
   int                 px7mm, shiftX;
   double              A;

   width -= thick + 1;
   height -= thick + 1;
   x += thick / 2;
   y += thick / 2;
   y +=  FrameTable[frame].FrTopMargin;

   /* Fill in the rectangle */
   if (pattern == 2)
     {
	GL_SetForeground (bg);
	GL_DrawArc (x, y, width, height, 0, 360, TRUE);
     }

   /* Draw the border */
   if (thick > 0 && fg >= 0)
     {
	InitDrawing (style, thick, fg);
	GL_DrawArc(x, y, width, height, 0, 360, FALSE); 
	px7mm = (int)((7 * DOT_PER_INCH) / 25.4 + 0.5);
	if (height > 2 * px7mm)
	  {
	     A = ((double) height - 2 * px7mm) / height;
	     A = 1.0 - sqrt (1 - A * A);
	     shiftX = (int)(width * A * 0.5 + 0.5);
	     GL_DrawLine(x + shiftX, y + px7mm, x + width - shiftX, y + px7mm, TRUE);
	  }
     }
}

/*----------------------------------------------------------------------
  WChaine draw a string in frame, at location (x, y) and using font.
  ----------------------------------------------------------------------*/
void WChaine (ThotWindow w, char *string, int x, int y, ThotFont font,
	      ThotGC GClocal)
{

/* GL_DRAWSTRING*/
}


/*----------------------------------------------------------------------
  VideoInvert switch to inverse video the area of frame located at
  (x,y) and of size width x height.
  ----------------------------------------------------------------------*/
void VideoInvert (int frame, int width, int height, int x, int y)
{
   GL_VideoInvert(width, height, x, y + FrameTable[frame].FrTopMargin);
}


/*----------------------------------------------------------------------
  Scroll do a scrolling/Bitblt of frame of a width x height area
  from (xd,yd) to (xf,yf).
  ----------------------------------------------------------------------*/
void Scroll (int frame, int width, int height, int xd, int yd, int xf, int yf)
{
#ifndef _WX
  if (FrRef[frame] != None)
    GL_window_copy_area (frame,
			 xf, 
			 yf + FrameTable[frame].FrTopMargin,
			 xd, 
			 yd + FrameTable[frame].FrTopMargin,
			 width, 
			 height);
#else /* _WX */
  if (FrameTable[frame].WdFrame != None)
    GL_window_copy_area (frame,
			 xf, 
			 yf + FrameTable[frame].FrTopMargin,
			 xd, 
			 yd + FrameTable[frame].FrTopMargin,
			 width, 
			 height);
#endif /* _WX */
}


/*----------------------------------------------------------------------
  PaintWithPattern fill the rectangle associated to a window w (or frame
  if w = 0) located on (x , y) and geometry width x height, using the
  given pattern.
  Parameters fg, bg, and pattern are for drawing color, background color
  and fill pattern.
  ----------------------------------------------------------------------*/
void PaintWithPattern (int frame, int x, int y, int width, int height,
		       ThotWindow w, int fg, int bg, int pattern)
{
  /* Fill the rectangle associated to the given frame */
  if (pattern == 2)
    {
      if (w == 0)
	y += FrameTable[frame].FrTopMargin;
      GL_DrawRectangle (pattern, (float) x, (float) y,
			(float) width, (float) height);
   }
}
#endif /* _GL*/
