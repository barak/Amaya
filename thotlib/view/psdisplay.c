/*
 *
 *  (c) COPYRIGHT INRIA, Grif, 1996.
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

/*
 * psdisplay.c : All the Postscript generation routines.
 *
 * Author: I. Vatton (INRIA)
 *         R. Guetari (W3C/INRIA) - Printing routines for Windows.
 *
 */

#include "thot_sys.h"
#ifdef SYSV
#endif
#include "message.h"
#include "constmedia.h"
#include "typemedia.h"
#include "frame.h"
#include "picture.h"

#undef THOT_EXPORT
#define THOT_EXPORT extern
#include "boxes_tv.h"
#include "font_tv.h"
#include "frame_tv.h"
#ifdef _WINDOWS
#include "thotcolor_tv.h"
#endif /* _WINDOWS */

#define VoidPixmap (Pixmap)(-1)
#define EmptyPixmap (Pixmap)(-2)
#define HL 4

static char        *Patterns_PS[] =
{
   "2222222222222222",		/*horiz1 */
   "6666666666666666",
   "7777777777777777",
   "0000ff000000ff00",		/*vert1 */
   "00ffff0000ffff00",
   "ffffff00ffffff00",
   "1122448811224488",		/*left */
   "993366cc993366cc",
   "ddbb77eeddbb77ee",
   "8844221188442211",		/*right1 */
   "cc663399cc663399",
   "ee77bbddee77bbdd",
   "11ff111111ff1111",		/*square1 */
   "33ffff3333ffff33",
   "77ffffff77ffffff",
   "11aa44aa11aa44aa",		/*diamond */
   "2222223e222222e3",		/*brick */
   "4244241c244442c1",		/*tile */
   "6688888884444222",		/*sea */
   "11b87c3a11a3c78b"		/*bottomket */
};


/* Handling of loaded fonts */
extern ptrfont      PoscriptFont;
extern int          ColorPs;
extern int          LastPageNumber, LastPageWidth, LastPageHeight;
static char        *Scale = NULL;
int                 X, Y;
static int          SameBox = 0; /* 1 if the text is in the same box */
static int          NbWhiteSp;

#ifdef _WINDOWS 
extern int PrinterDPI;
#endif /* _WINDOWS */

#include "buildlines_f.h"
#include "font_f.h"
#include "units_f.h"
#include "initpses_f.h"

#ifdef _WINDOWS

#include "win_f.h"

/*----------------------------------------------------------------------
  DoDrawOneLine draw one line starting from (x1, y1) to (x2, y2) in frame.
  ----------------------------------------------------------------------*/
#ifdef __STDC__
static void         DoPrintOneLine (int color, int x1, int y1, int x2, int y2)
#else  /* __STDC__ */
static void         DoDrawOneLine (color, x1, y1, x2, y2)
int                 color;
int                 x1;
int                 y1;
int                 x2;
int                 y2;

#endif /* __STDC__ */
{
   HPEN pen ;
   HPEN hOldPen;

   pen = CreatePen (PS_SOLID, 1, RGB (RGB_colors[color].red, RGB_colors[color].green, RGB_colors[color].blue));
   hOldPen = SelectObject (TtPrinterDC, pen);

   MoveToEx (TtPrinterDC, x1, y1, NULL);
   LineTo (TtPrinterDC, x2, y2);
   SelectObject (TtPrinterDC, hOldPen);
   if (!DeleteObject (pen))
      WinErrorBox (WIN_Main_Wd);
}
#endif /* _WINDOWS */

/*----------------------------------------------------------------------
   WriteCar writes s1 or s2 depending on encoding.
  ----------------------------------------------------------------------*/
#ifdef __STDC__
static void         WriteCar (FILE * fout, int encoding, char *s1, char *s2)

#else  /* __STDC__ */
static void         WriteCar (fout, encoding, s1, s2)
FILE               *fout;
int                 encoding;
char               *s1;
char               *s2;

#endif /* __STDC__ */

{
   if (encoding == 0)
      fputs (s1, fout);
   else
      fputs (s2, fout);
}

/*----------------------------------------------------------------------
   Transcode emit the Poscript code for the given char.
  ----------------------------------------------------------------------*/

#ifdef __STDC__
static void         Transcode (FILE * fout, int encoding, char car)

#else  /* __STDC__ */
static void         Transcode (fout, encoding, car)
FILE               *fout;
int                 encoding;
char                car;

#endif /* __STDC__ */

{
   if (car >= ' ' && car <= '~' && car != '(' && car != ')' && car != '\\')
      fprintf (fout, "%c", car);
   else
      switch (car)
	    {
	       case '(':
		  fputs ("\\(", fout);
		  break;
	       case ')':
		  fputs ("\\)", fout);
		  break;
	       case '*':
		  WriteCar (fout, encoding, "*", "\\267");	/* bullet */
		  break;
	       case '\\':
		  fputs ("\\\\", fout);
		  break;
	       default:
		  fprintf (fout, "\\%o", (unsigned char) car);
	    }
}


/*----------------------------------------------------------------------
   CurrentColor compares the last RGB Postscript color loaded
   and the one asked, and load it if needed.
   num is an index in the Thot internal color table.
  ----------------------------------------------------------------------*/

#ifdef __STDC__
static void         CurrentColor (FILE * fout, int num)

#else  /* __STDC__ */
static void         CurrentColor (fout, num)
FILE               *fout;
int                 num;

#endif /* __STDC__ */

{
   unsigned short      red;
   unsigned short      green;
   unsigned short      blue;
   float               fact;

   /* Compare the color asked with the current one */
   if (num != ColorPs) {
      /* Ask for the RedGreenBlue values */
      TtaGiveThotRGB (num, &red, &green, &blue);
      /* Emit the Poscript command */
      fact = 255;
#     ifdef _WINDOWS
      if (TtPrinterDC) {
         SetTextColor (TtPrinterDC, RGB (red, green, blue));
	  } else
           fprintf (fout, "%f %f %f setrgbcolor\n", ((float) red) / fact, ((float) green) / fact, ((float) blue) / fact);
#     else /* !_WINDOWS */
      fprintf (fout, "%f %f %f setrgbcolor\n", ((float) red) / fact, ((float) green) / fact, ((float) blue) / fact);
#     endif /* _WINDOWS */
	  ColorPs = num;
   }
}

#ifdef _WINDOWS
/*----------------------------------------------------------------------
  WIN_DrawChar draw a char at location (x, y) in frame and with font.
  RO indicates whether it's a read-only box active
  indicates if the box is active parameter fg indicates the drawing color
  ----------------------------------------------------------------------*/
#ifdef __STDC__
void                WIN_DrawChar (unsigned char car, int frame, int x, int y, ptrfont font, int RO, int active, int fg)
#else  /* __STDC__ */
void                WIN_DrawChar (car, frame, x, y, font, RO, active, fg)
unsigned char       car;
int                 frame;
int                 x;
int                 y;
ptrfont             font;
int                 RO;
int                 active;
int                 fg;

#endif /* __STDC__ */
{
   char  str[2] = {car, 0};
   HFONT hOldFont;

   CurrentColor (NULL, fg);

   WinLoadGC (TtPrinterDC, fg, RO);
   SetMapperFlags (TtPrinterDC, 1);
   hOldFont = WinLoadFont (TtPrinterDC, font);
   TextOut (TtPrinterDC, x, y, (unsigned char*) str, 1);   
   SelectObject (TtPrinterDC, hOldFont);
}

/*----------------------------------------------------------------------
  WIN_DrawMonoSymb draw a one glyph symbol.
  RO indicates whether it's a read-only box
  active indicates if the box is active
  parameter fg indicates the drawing color
  ----------------------------------------------------------------------*/
#ifdef __STDC__
static void WIN_DrawMonoSymb (char symb, int frame, int x, int y, int l, int h, int RO, int active, ptrfont font, int fg)
#else  /* __STDC__ */
static void WIN_DrawMonoSymb (symb, frame, x, y, l, h, RO, active, font, fg)
char                symb;
int                 frame;
int                 x;
int                 y;
int                 l;
int                 h;
int                 RO;
int                 active;
ptrfont             font;
int                 fg;
#endif /* __STDC__ */
{
   int                 xm, yf;

   xm = x + ((l - CharacterWidth (symb, font)) / 2);
   yf = y + ((h - CharacterHeight (symb, font)) / 2) - FontAscent (font) + CharacterAscent (symb, font);

   WIN_DrawChar (symb, frame, xm, yf, font, RO, active, fg);
}
#endif /* _WINDOWS */


/*----------------------------------------------------------------------
   FillWithPattern fills in the current stroke with a black and white
   pattern, or the drawing color, or the background color,
   or keep it transparent, depending on pattern value.
  ----------------------------------------------------------------------*/
#ifdef __STDC__
static void         FillWithPattern (FILE * fout, int fg, int bg, int pattern)
#else  /* __STDC__ */
static void         FillWithPattern (fout, fg, bg, pattern)
FILE               *fout;
int                 fg;
int                 bg;
int                 pattern;
#endif /* __STDC__ */
{
   unsigned short      red;
   unsigned short      green;
   unsigned short      blue;
   float               fact;

   fact = 255;
   /* Do the current stroke need to be filled ? */
   if (pattern == 0)
      /* no filling */
      fprintf (fout, "0\n");
   else if (pattern == 1)
     {
	/* Ask for the RedGreenBlue values */
	TtaGiveThotRGB (fg, &red, &green, &blue);
	/* Emit the Poscript command */
	fprintf (fout, "%f %f %f -1\n", ((float) red) / fact,
		 ((float) green) / fact, ((float) blue) / fact);
     }
   else if (pattern == 2)
     {
	/* Ask for the RedGreenBlue values */
	TtaGiveThotRGB (bg, &red, &green, &blue);
	/* Emit the Poscript command */
	fprintf (fout, "%f %f %f -1\n", ((float) red) / fact,
		 ((float) green) / fact, ((float) blue) / fact);
     }
   else if (pattern >= 10)
     {
	/* Use of a fill pattern */
	/*fprintf(fout, "<d1e3c5885c3e1d88> 8 "); */
	fprintf (fout, "<%s> 8\n", Patterns_PS[pattern - 10]);
     }
   else
      /* Shade of grey */
      fprintf (fout, "%d\n", pattern - 2);
}


/*----------------------------------------------------------------------
   CurrentFont compute the correct PostScript font needed,
   and emit the code to load it, if necessary.
   Returns 0 if it is a Latin font and 1 for a Greek one.
  ----------------------------------------------------------------------*/
#ifdef __STDC__
static int          CurrentFont (FILE * fout, ptrfont font)
#else  /* __STDC__ */
static int          CurrentFont (fout, font)
FILE               *fout;
ptrfont             font;
#endif /* __STDC__ */
{
   int                 i, retour;
   char                c1, c2;

   /* browse the table of fonts */
   i = 0;
   retour = 0;			/* BUG */
   while ((TtFonts[i] != font) && (i < MAX_FONT))
     {
	i++;
     }
   if (i >= MAX_FONT)
      i = 0;
   i = i * 8;
   if (font != PoscriptFont)
     {
	PoscriptFont = font;
	if (TtPsFontName[i] == 'g')	/* Greek alphabet */
	  {
	     c1 = TtPsFontName[i];
	     c2 = 'r';		/* Symbol only has one style available */
	     retour = 1;
	  }
	else
	  {
	     /* Latin Alphabet */
	     c1 = TtPsFontName[i + 1];	/* font Helvetica Times Courrier */
	     /* convert lowercase to uppercase */
	     c2 = TtPsFontName[i + 2];	/* Style normal bold italique */
	     retour = 0;
	  }

	/* update the scaling factor */
	Scale = &TtPsFontName[i + 3];
	fprintf (fout, "%c%c%c %s sf\n", TtPsFontName[i], c1, c2, Scale);
	return retour;
     }
   /* returns the indicator for the family of fonts */
   else if (TtPsFontName[i] == 'g')
      return (1);
   else
      return (0);
}

/*----------------------------------------------------------------------
   DrawString draw a char string of lg chars beginning at buff[i].
   Drawing starts at (x, y) in frame and using font.
   lgboite gives the width of the final box or zero,
   this is used only by the thot formmating engine.
   bl indicate taht there is a space before the string
   hyphen indicate whether an hyphen char has to be added.
   debutbloc is 1 if the text is at a paragraph beginning
   (no justification of first spaces).
   RO indicate whether it's a read-only box
   active indicate if the box is active
   parameter fg indicate the drawing color
 
   Returns the lenght of the string drawn.
  ----------------------------------------------------------------------*/
#ifdef __STDC__
int                 DrawString (char *buff, int i, int lg, int frame, int x, int y, ptrfont font, int lgboite, int bl, int hyphen, int StartOfCurrentBlock, int RO, int active, int fg)
#else  /* __STDC__ */
int                 DrawString (buff, i, lg, frame, x, y, font, lgboite, bl, hyphen, StartOfCurrentBlock, RO, active, fg)
char               *buff;
int                 i;
int                 lg;
int                 frame;
int                 x;
int                 y;
ptrfont             font;
int                 lgboite;
int                 bl;
int                 hyphen;
int                 StartOfCurrentBlock;
int                 RO;
int                 active;
int                 fg;
#endif /* __STDC__ */
{
   char               *ptcar;
   int                 j, encoding, width;
   int                 NonJustifiedWhiteSp;
   FILE               *fout;
#  ifdef _WINDOWS
   unsigned short      red, green, blue;
   HFONT               hOldFont;
   SIZE                size;
#  endif /* _WINDOWS */

#  ifdef _WINDOWS
   if (TtPrinterDC == NULL)
      fout = (FILE *) FrRef[frame];
#  else  /* _WINDOWS */
   fout = (FILE *) FrRef[frame];
#  endif /* _WINDOWS */
   encoding = 0;		/* BUG */
   if (y < 0)
      return 0;
   /* NonJustifiedWhiteSp is > 0 if writing a fixed lenght is needed */
   /* and equal to 0 if a justified space is to be printed */

   NonJustifiedWhiteSp = StartOfCurrentBlock;

   /* Is this a new box ? */
   if (SameBox == 0) {
      /* Beginning of a new box */
      SameBox = 1;
      X = PixelToPoint (x);
      Y = PixelToPoint (y + FontBase (font));
      NbWhiteSp = 0;

      /* Do we need to change the current color ? */
#     ifdef _WINDOWS  
      if (TtPrinterDC) {
         TtaGiveThotRGB (fg, &red, &green, &blue);
         SetTextColor (TtPrinterDC, RGB (red, green, blue));
	  } else
           CurrentColor (fout, fg);
#     else  /* _WINDOWS */
      CurrentColor (fout, fg);
#     endif /* _WINDOWS */

      /* Do we need to change the current font ? */
#     ifdef _WINDOWS
      if (TtPrinterDC)
         hOldFont = SelectObject (TtPrinterDC, font->FiFont);
      else {
          encoding = CurrentFont (fout, font);
          fprintf (fout, "(");
	  }
#     else  /* _WINDOWS */
      encoding = CurrentFont (fout, font);
      fprintf (fout, "(");
#     endif /* _WINDOWS */
   }

   /* Add the justified white space */
#  ifdef _WINDOWS
   if (TtPrinterDC) {
      ptcar = &buff[i - 1];
      SetMapperFlags (TtPrinterDC, 1);
      GetTextExtentPoint (TtPrinterDC, ptcar, lg, &size);
      width = size.cx;
      if (ptcar[0] == '\212') {
         /* skip the Control return char */
         ptcar++;
         lg--;
      }
      if (lg != 0)
         /* if (!TextOut (TtPrinterDC, X, Y, (unsigned char*) ptcar, lg)) */
         if (!TextOut (TtPrinterDC, x, y, (unsigned char*) ptcar, lg))
            WinErrorBox (NULL);
      if (hyphen) /* draw the hyphen */
         if (!TextOut (TtPrinterDC, X + width, Y, "\255", 1))
            WinErrorBox (NULL);
      if (lgboite != 0)
         SameBox = 0;
   } else {
        if (bl > 0) {
           NbWhiteSp++;
           Transcode (fout, encoding, ' ');
		}

        /* Emit the chars */
        ptcar = &buff[i - 1];
        for (j = 0; j < lg; j++) {
            /* enumerate the white spaces */
            if (ptcar[j] == ' ')
               if (NonJustifiedWhiteSp == 0) {
                  /* write a justified white space */
                  NbWhiteSp++;
                  Transcode (fout, encoding, ptcar[j]);
			   } else /* write a fixed lenght white space */
                    fputs ("\\240", fout);
            else {
               NonJustifiedWhiteSp = 0;
               Transcode (fout, encoding, ptcar[j]);
			}
		}

        /* Is an hyphen needed ? */
        if (hyphen)
           Transcode (fout, encoding, '\255');

        /* is this the end of the box */
        if (lgboite != 0) {
           lgboite = PixelToPoint (lgboite);
           /* Is justification needed ? */
           if (NbWhiteSp == 0)
              fprintf (fout, ") %d %d -%d s\n", lgboite, X, Y);
           else
              fprintf (fout, ") %d %d %d -%d j\n", NbWhiteSp, lgboite, X, Y);
           SameBox = 0;
		}
   }
#  else  /* _WINDOWS */
   if (bl > 0) {
      NbWhiteSp++;
      Transcode (fout, encoding, ' ');
   }

   /* Emit the chars */
   ptcar = &buff[i - 1];
   for (j = 0; j < lg; j++) {
       /* enumerate the white spaces */
       if (ptcar[j] == ' ')
          if (NonJustifiedWhiteSp == 0) {
             /* write a justified white space */
             NbWhiteSp++;
             Transcode (fout, encoding, ptcar[j]);
		  } else /* write a fixed lenght white space */
               fputs ("\\240", fout);
       else {
          NonJustifiedWhiteSp = 0;
          Transcode (fout, encoding, ptcar[j]);
	   }
   }

   /* Is an hyphen needed ? */
   if (hyphen)
      Transcode (fout, encoding, '\255');

   /* is this the end of the box */
   if (lgboite != 0) {
      lgboite = PixelToPoint (lgboite);
      /* Is justification needed ? */
      if (NbWhiteSp == 0)
         fprintf (fout, ") %d %d -%d s\n", lgboite, X, Y);
      else
         fprintf (fout, ") %d %d %d -%d j\n", NbWhiteSp, lgboite, X, Y);
      SameBox = 0;
   }
#  endif /* _WINDOWS */
   if (lg > 0) {
      /* compute the width of the string */
      width = 0;
      j = 0;
      while (j < lg)
            width += CharacterWidth (ptcar[j++], font);
      return (width);
   } 
   return (0);
}


/*----------------------------------------------------------------------
   DisplayUnderline draw the underline, overline or cross line
  ----------------------------------------------------------------------*/
#ifdef __STDC__
void                DisplayUnderline (int frame, int x, int y, ptrfont font, int type, int thick, int lg, int RO, int func, int fg)
#else  /* __STDC__ */
void                DisplayUnderline (frame, x, y, font, type, thick, lg, RO, func, fg)
int                 frame;
int                 x;
int                 y;
ptrfont             font;
int                 type;
int                 thick;
int                 lg;
int                 RO;
int                 func;
int                 fg;
#endif /* __STDC__ */
{
   int                 fheight;	/* font height           */
   int                 ascent;	/* font ascent           */
   int                 bottom;	/* underline position    */
   int                 middle;	/* cross-over position   */
   int                 height;	/* overline position     */
   int                 thickness;	/* thickness of drawing */
   int                 l_start;	/* start of the line     */
   int                 l_end;	/* end of the line       */
   int                 shift;	/* shifting of drawing   */
   FILE               *fout;
#  ifdef _WINDOWS
   if (TtPrinterDC) {
      if (lg > 0) {
         fheight = FontHeight (font);
         ascent = FontAscent (font);
         thickness = ((fheight / 20) + 1) * (thick + 1);
         shift = thick * thickness;
         height = y + shift;
         bottom = y + ascent + 2 + shift;
         middle = y + fheight / 2 - shift;

         /*
          * for an underline independant of the font add
          * the following lines here :
          *         thickness = 1;
          *         height = y + 2 * thickness;
          *         bottom = y + ascent + 3;
          */

         switch (type) {
                case 1: /* underlined */
                        DoPrintOneLine (fg, x - lg, bottom, x, bottom);
                        break;

                case 2: /* overlined */
                        DoPrintOneLine (fg, x - lg, height, x, height);
                        break;

                case 3: /* cross-over */
                        DoPrintOneLine (fg, x - lg, middle, x, middle);
                        break;

                default: /* not underlined */
                         break;
		 } 
	  } 
   } else {
        fout = (FILE *) FrRef[frame];
        if (y < 0)
           return;
        /* The last box must be finished */
        if (SameBox == 0) {
           fheight = FontHeight (font);
           ascent = FontAscent (font);
           thickness = ((fheight / 20) + 1) * (thick + 1);
           shift = thick * thickness;
           height = y + shift;
           bottom = y + ascent + 2 + shift;
           middle = y + fheight / 2 - shift;
           l_start = X;		/* get current X value (cf DrawString) */
           l_end = X + PixelToPoint (lg);	/* compute the end coordinate */

           /*
            * for an underline independant of the font add
            * the following lines here :
            *         thickness = 1;
            *         height = y + 2 * thickness;
            *         bottom = y + ascent + 3;
            */

           switch (type) {
                  case 0:	/* nothing */
                          break;

                  case 1:	/* underlined */
                          fprintf (fout, "%d -%d %d -%d %d %d %d Seg\n", l_end, PixelToPoint (bottom), l_start, PixelToPoint (bottom), 0, thickness, 2);
                          break;

                  case 2:	/* overlined */
                          fprintf (fout, "%d -%d %d -%d %d %d %d Seg\n", l_end, PixelToPoint (height), l_start, PixelToPoint (height), 0, thickness, 2);
                          break;

                  case 3:	/* cross-over */
                          fprintf (fout, "%d -%d %d -%d %d %d %d Seg\n", l_end, PixelToPoint (middle), l_start, PixelToPoint (middle), 0, thickness, 2);
                          break;
		   }
		}
   }
#  else  /* _WINDOWS */
   fout = (FILE *) FrRef[frame];
  if (y < 0)
    return;
   /* The last box must be finished */
   if (SameBox == 0)
     {
	fheight = FontHeight (font);
	ascent = FontAscent (font);
	thickness = ((fheight / 20) + 1) * (thick + 1);
	shift = thick * thickness;
	height = y + shift;
	bottom = y + ascent + 2 + shift;
	middle = y + fheight / 2 - shift;
	l_start = X;		/* get current X value (cf DrawString) */
	l_end = X + PixelToPoint (lg);	/* compute the end coordinate */

	/*
	 * for an underline independant of the font add
	 * the following lines here :
	 *         thickness = 1;
	 *         height = y + 2 * thickness;
	 *         bottom = y + ascent + 3;
	 */

	switch (type)
	      {
		 case 0:	/* nothing */
		    break;

		 case 1:	/* underlined */
		    fprintf (fout, "%d -%d %d -%d %d %d %d Seg\n",
			     l_end, PixelToPoint (bottom), l_start, PixelToPoint (bottom), 0, thickness, 2);
		    break;

		 case 2:	/* overlined */
		    fprintf (fout, "%d -%d %d -%d %d %d %d Seg\n",
			     l_end, PixelToPoint (height), l_start, PixelToPoint (height), 0, thickness, 2);
		    break;

		 case 3:	/* cross-over */
		    fprintf (fout, "%d -%d %d -%d %d %d %d Seg\n",
			     l_end, PixelToPoint (middle), l_start, PixelToPoint (middle), 0, thickness, 2);
		    break;
	      }
     }
#    endif /* _WINDOWS */
}


/*----------------------------------------------------------------------
   DrawRadical Draw a radical symbol.
  ----------------------------------------------------------------------*/
#ifdef __STDC__
void                DrawRadical (int frame, int thick, int x, int y, int l, int h, ptrfont font, int RO, int func, int fg)
#else  /* __STDC__ */
void                DrawRadical (frame, thick, x, y, l, h, font, RO, func, fg)
int                 frame;
int                 thick;
int                 x;
int                 y;
int                 l;
int                 h;
ptrfont             font;
int                 RO;
int                 func;
int                 fg;
#endif /* __STDC__ */
{
#  ifdef _WINDOWS
   if (y < 0)
      return;
   if (thick < 0)
      return;

   if (TtPrinterDC) {
      int xm, xp, fh;

      fh = FontHeight (font);
      xm = x + (fh / 2);
      xp = x + (fh / 4);
      /* vertical part */
      DoPrintOneLine (fg, x, y + (2 * (h / 3)), xp - (thick / 2), y + h);

      /* Acending part */
      DoPrintOneLine (fg, xp, y + h, xm, y);
      /* Upper part */
      DoPrintOneLine (fg, xm, y, x + l, y);
   } else {
        int   ex, fh;
        FILE* fout;

        fout = (FILE *) FrRef[frame];

        /* Do we need to change the current color ? */
        CurrentColor (fout, fg);

        fh = FontHeight (font);
        ex = h / 3;
        if ((ex = h / 3) < 6)
           ex = 6;

        if (h <= (3 * fh))
           fprintf (fout, "%d -%d %d -%d %d -%d %d -%d r\n",
                    PixelToPoint (x + l), PixelToPoint (y), 
                    PixelToPoint (x + (fh / 2)), PixelToPoint (y),
                    PixelToPoint (x + (fh / 4)), PixelToPoint (y + h),
                    PixelToPoint (x), PixelToPoint (y + (2 * (h / 3))));

        else
            fprintf (fout, "%d -%d %d -%d %d -%d %d -%d r\n",
                     PixelToPoint (x + l), PixelToPoint (y),
                     PixelToPoint (x + (fh / 2)), PixelToPoint (y),
                     PixelToPoint (x + (fh / 2)), PixelToPoint (y + h),
                     PixelToPoint (x), PixelToPoint (y + (2 * (h / 3))));
   }
#  else  /* !_WINDOWS */
   int                 ex, fh;
   FILE               *fout;

   fout = (FILE *) FrRef[frame];
  if (y < 0)
    return;

   /* Do we need to change the current color ? */
   CurrentColor (fout, fg);

   fh = FontHeight (font);
   ex = h / 3;
   if ((ex = h / 3) < 6)
      ex = 6;

   if (h <= (3 * fh))
      fprintf (fout, "%d -%d %d -%d %d -%d %d -%d r\n",
	       PixelToPoint (x + l), PixelToPoint (y),
	       PixelToPoint (x + (fh / 2)), PixelToPoint (y),
	       PixelToPoint (x + (fh / 4)), PixelToPoint (y + h),
	       PixelToPoint (x), PixelToPoint (y + (2 * (h / 3))));

   else
      fprintf (fout, "%d -%d %d -%d %d -%d %d -%d r\n",
	       PixelToPoint (x + l), PixelToPoint (y),
	       PixelToPoint (x + (fh / 2)), PixelToPoint (y),
	       PixelToPoint (x + (fh / 2)), PixelToPoint (y + h),
	       PixelToPoint (x), PixelToPoint (y + (2 * (h / 3))));
#  endif /* _WINDOWS */

}


/*----------------------------------------------------------------------
   DrawIntegral draw an integral. depending on type :
   - simple if type = 0
   - contour if type = 1
   - double if type = 2.
  ----------------------------------------------------------------------*/
#ifdef __STDC__
void                DrawIntegral (int frame, int thick, int x, int y, int l, int h, int type, ptrfont font, int RO, int func, int fg)
#else  /* __STDC__ */
void                DrawIntegral (frame, thick, x, y, l, h, type, font, RO, func, fg)
int                 frame;
int                 thick;
int                 x;
int                 y;
int                 l;
int                 h;
int                 type;
ptrfont             font;
int                 RO;
int                 func;
int                 fg;
#endif /* __STDC__ */
{
#  ifdef _WINDOWS
   if (y < 0)
      return;
   if (TtPrinterDC) {
      int xm, yf, yend, exnum, delta;
      int wd, asc, hd;

      exnum = 0;
      if (FontHeight (font) *1.2 >= h) { /* display a single glyph */
         xm = x + ((l - CharacterWidth ('\362', font)) / 2);
         yf = y + ((h - CharacterHeight ('\362', font)) / 2) - FontAscent (font) +
         CharacterAscent ('\362', font);
         WIN_DrawChar ('\362', frame, xm, yf, font, RO, func, fg);
      } else { /* Need more than one glyph */
           xm = x + ((l - CharacterWidth ('\363', font)) / 2);
           yf = y - FontAscent (font) + CharacterAscent ('\363', font);
           WIN_DrawChar ('\363', frame, xm, yf, font, RO, func, fg);
           yend = y + h - CharacterHeight ('\365', font) - FontAscent (font) +
           CharacterAscent ('\365', font) - 1;
           WIN_DrawChar ('\365', frame, xm, yend, font, RO, func, fg);

           yf += CharacterHeight ('\363', font);
           delta = yend - yf;
           asc = CharacterAscent ('\364', font)  - FontAscent (font) - 1;
           hd = CharacterHeight ('\364', font) - 1;
           wd = (CharacterWidth ('\363', font) - CharacterWidth ('\364', font)) / 2;
           if (delta >= 0) {
              for (yf += asc, yend -= hd; yf < yend; yf += CharacterHeight ('\364', font), exnum++)
                  WIN_DrawChar ('\364', frame, xm+wd, yf, font, RO, func, fg);
              if (exnum)
                 WIN_DrawChar ('\364', frame, xm+wd, yend, font, RO, func, fg);
              else
                  WIN_DrawChar ('\364', frame, xm+wd, yf + ((delta - hd) / 2), font, RO, func, fg);
		   }
      }

      if (type == 2) /* double integral */
         DrawIntegral (frame, thick, x + (CharacterWidth ('\364', font) / 2), y, l, h, -1, font, RO, func, fg);

      else if (type == 1) /* contour integral */
           WIN_DrawChar ('o', frame, x + ((l - CharacterWidth ('o', font)) / 2),
		                 y + (h - CharacterHeight ('o', font)) / 2 - FontAscent (font) + CharacterAscent ('o', font),
		                 font, RO, func, fg);
   } else {
        FILE* fout;
        int   ey, ym, yf;

        fout = (FILE *) FrRef[frame];
        if (y < 0)
           return;

        /* Do we need to change the current color ? */
        CurrentColor (fout, fg);

        /* Do we need to change the current font ? */
        CurrentFont (fout, font);

        l--;
        h--;
        ey = FontHeight (font);
        h -= ey;
        y += FontBase (font);
        x = PixelToPoint (x + (l / 2));
        yf = PixelToPoint (y + h);
        ym = PixelToPoint (y + (h / 2));
        y = PixelToPoint (y) + 1;
        if (h < ey / 4) { /* Made of only one glyph */
           if (type == 2) { /* double integral */
              fprintf (fout, "-%d %d (\\362) c\n", ym, x - PixelToPoint (CharacterWidth ('\362', font) / 4));
              fprintf (fout, "-%d %d (\\362) c\n", ym, x + PixelToPoint (CharacterWidth ('\362', font) / 4));
		   } else {
                fprintf (fout, "-%d %d (\\362) c\n", ym, x);
                if (type == 1) /* contour integral */
                   fprintf (fout, "-%d %d (o) c\n", ym, x);
		   }
		} else { /* Drawn with more than one glyph */
             if (type == 2) { /* double integral */
                fprintf (fout, "%d -%d -%d %s (\\363) (\\364) (\\365) s3\n",
                         x - PixelToPoint (CharacterWidth ('\364', font) / 4), yf, y, Scale);
                fprintf (fout, "%d -%d -%d %s (\\363) (\\364) (\\365) s3\n",
                         x + PixelToPoint (CharacterWidth ('\364', font) / 4), yf, y, Scale);
			 } else {
                  fprintf (fout, "%d -%d -%d %s (\\363) (\\364) (\\365) s3\n", x, yf, y, Scale);
                  if (type == 1) /* contour integral */
                     fprintf (fout, "-%d %d (o) c\n", ym, x);
			 }
		}
   }
#  else  /* _WINDOWS */
   FILE               *fout;
   int                 ey, ym, yf;

   fout = (FILE *) FrRef[frame];
  if (y < 0)
    return;

   /* Do we need to change the current color ? */
   CurrentColor (fout, fg);

   /* Do we need to change the current font ? */
   CurrentFont (fout, font);

   l--;
   h--;
   ey = FontHeight (font);
   h -= ey;
   y += FontBase (font);
   x = PixelToPoint (x + (l / 2));
   yf = PixelToPoint (y + h);
   ym = PixelToPoint (y + (h / 2));
   y = PixelToPoint (y) + 1;
   if (h < ey / 4)
     {
	/* Made of only one glyph */
	if (type == 2)
	  {
	     /* double integral */
	     fprintf (fout, "-%d %d (\\362) c\n", ym, x - PixelToPoint (CharacterWidth ('\362', font) / 4));
	     fprintf (fout, "-%d %d (\\362) c\n", ym, x + PixelToPoint (CharacterWidth ('\362', font) / 4));
	  }
	else
	  {
	     fprintf (fout, "-%d %d (\\362) c\n", ym, x);
	     if (type == 1)	/* contour integral */
		fprintf (fout, "-%d %d (o) c\n", ym, x);
	  }
     }
   else
     {
	/* Drawn with more than one glyph */
	if (type == 2)
	  {
	     /* double integral */
	     fprintf (fout, "%d -%d -%d %s (\\363) (\\364) (\\365) s3\n",
	      x - PixelToPoint (CharacterWidth ('\364', font) / 4), yf, y, Scale);
	     fprintf (fout, "%d -%d -%d %s (\\363) (\\364) (\\365) s3\n",
	      x + PixelToPoint (CharacterWidth ('\364', font) / 4), yf, y, Scale);
	  }
	else
	  {
	     fprintf (fout, "%d -%d -%d %s (\\363) (\\364) (\\365) s3\n", x, yf, y, Scale);
	     if (type == 1)	/* contour integral */
		fprintf (fout, "-%d %d (o) c\n", ym, x);
	  }
     }
#  endif /* _WINDOWS */
}


/*----------------------------------------------------------------------
   DrawSigma draw a Sigma symbol.
  ----------------------------------------------------------------------*/
#ifdef __STDC__
void                DrawSigma (int frame, int x, int y, int l, int h, ptrfont font, int RO, int func, int fg)
#else  /* __STDC__ */
void                DrawSigma (frame, x, y, l, h, font, RO, func, fg)
int                 frame;
int                 x;
int                 y;
int                 l;
int                 h;
ptrfont             font;
int                 RO;
int                 func;
int                 fg;
#endif /* __STDC__ */
{
#  ifdef _WINDOWS
   if (y < 0)
      return;

   if (TtPrinterDC) {
      int xm, ym, fh;

      fh = FontHeight (font);
      if (h < fh * 2 && l <= CharacterWidth ('\345', font)) /* Only one glyph needed */
         WIN_DrawMonoSymb ('\345', frame, x, y, l, h, RO, func, font, fg);
      else {
         xm = x + (l / 3);
         ym = y + (h / 2) - 1;
         /* Center */
         DoPrintOneLine (fg, x, y + 1, xm, ym);
         DoPrintOneLine (fg, x, y + h - 2, xm, ym);

         /* Borders */
         DoPrintOneLine (frame, x, y, x + l, y);
         DoPrintOneLine (frame, x, y + h - 2, x + l, y + h - 2);
      }
   } else {
        FILE               *fout;

        fout = (FILE *) FrRef[frame];

        /* Do we need to change the current color ? */
        CurrentColor (fout, fg);

        /* Change the current font */
        PoscriptFont = NULL;
        fprintf (fout, "(Symbol) %.0f sf\n", FontHeight (font) * 0.9);
        x = PixelToPoint (x + (l / 2));
        y = PixelToPoint (y + h - FontHeight (font) + FontBase (font));
        fprintf (fout, "-%d %d (\\345) c\n", y, x);
   }
#  else  /* !_WINDOWS */
   FILE               *fout;

   fout = (FILE *) FrRef[frame];
  if (y < 0)
    return;

   /* Do we need to change the current color ? */
   CurrentColor (fout, fg);

   /* Change the current font */
   PoscriptFont = NULL;
   fprintf (fout, "(Symbol) %.0f sf\n", FontHeight (font) * 0.9);
   x = PixelToPoint (x + (l / 2));
   y = PixelToPoint (y + h - FontHeight (font) + FontBase (font));
   fprintf (fout, "-%d %d (\\345) c\n", y, x);
#  endif /* _WINDOWS */
}


/*----------------------------------------------------------------------
   DrawPi draw a PI symbol.
  ----------------------------------------------------------------------*/
#ifdef __STDC__
void                DrawPi (int frame, int x, int y, int l, int h, ptrfont font, int RO, int func, int fg)
#else  /* __STDC__ */
void                DrawPi (frame, x, y, l, h, font, RO, func, fg)
int                 frame;
int                 x;
int                 y;
int                 l;
int                 h;
ptrfont             font;
int                 RO;
int                 func;
int                 fg;

#endif /* __STDC__ */
{
#  ifdef _WINDOWS
   if (y < 0)
      return;

   if (TtPrinterDC) {
      int fh;

      fh = FontHeight (font);
      if (h < fh * 2 && l <= CharacterWidth ('\325', font)) /* Only one glyph needed */
         WIN_DrawMonoSymb ('\325', frame, x, y, l, h, RO, func, font, fg);
      else {
         /* Vertical part */
         DoPrintOneLine (fg, x + 2, y + 1, x + 2, y + h);
         DoPrintOneLine (fg, x + l - 3, y + 1, x + l - 3, y + h);

         /* Upper part */
         DoPrintOneLine (frame, x + 1, y + 1, x + l, y);
      }
   } else {
        FILE* fout;

        fout = (FILE *) FrRef[frame];

        /* Do we need to change the current color ? */
        CurrentColor (fout, fg);

        /* Change the current font */
        PoscriptFont = NULL;
        fprintf (fout, "(Symbol) %.0f sf\n", FontHeight (font) * 0.9);
        x = PixelToPoint (x + (l / 2));
        y = PixelToPoint (y + h - FontHeight (font) + FontBase (font));
        fprintf (fout, "-%d %d (\\325) c\n", y, x);
   }
#  else  /* !_WINDOWS */
   FILE               *fout;

   fout = (FILE *) FrRef[frame];
  if (y < 0)
    return;

   /* Do we need to change the current color ? */
   CurrentColor (fout, fg);

   /* Change the current font */
   PoscriptFont = NULL;
   fprintf (fout, "(Symbol) %.0f sf\n", FontHeight (font) * 0.9);
   x = PixelToPoint (x + (l / 2));
   y = PixelToPoint (y + h - FontHeight (font) + FontBase (font));
   fprintf (fout, "-%d %d (\\325) c\n", y, x);
#  endif /* _WINDOWS */
}


/*----------------------------------------------------------------------
   DrawUnion draw an Union symbol.
  ----------------------------------------------------------------------*/
#ifdef __STDC__
void                DrawUnion (int frame, int x, int y, int l, int h, ptrfont font, int RO, int func, int fg)
#else  /* __STDC__ */
void                DrawUnion (frame, x, y, l, h, font, RO, func, fg)
int                 frame;
int                 x;
int                 y;
int                 l;
int                 h;
ptrfont             font;
int                 RO;
int                 func;
int                 fg;

#endif /* __STDC__ */
{
#  ifdef _WINDOWS 
   if (y < 0)
      return;

   if (TtPrinterDC) {
   } else {
        FILE* fout;

        fout = (FILE *) FrRef[frame];

        /* Do we need to change the current color ? */
        CurrentColor (fout, fg);

        /* Change the current font */
        PoscriptFont = NULL;
        fprintf (fout, "(Symbol) %.0f sf\n", FontHeight (font) * 0.9);
        x = PixelToPoint (x + (l / 2));
        y = PixelToPoint (y + h - FontHeight (font) + FontBase (font));
        fprintf (fout, "-%d %d (\\310) c\n", y, x);
   } 
#  else  /* _WINDOWS */
   FILE               *fout;

   fout = (FILE *) FrRef[frame];
  if (y < 0)
    return;

   /* Do we need to change the current color ? */
   CurrentColor (fout, fg);

   /* Change the current font */
   PoscriptFont = NULL;
   fprintf (fout, "(Symbol) %.0f sf\n", FontHeight (font) * 0.9);
   x = PixelToPoint (x + (l / 2));
   y = PixelToPoint (y + h - FontHeight (font) + FontBase (font));
   fprintf (fout, "-%d %d (\\310) c\n", y, x);
#  endif /* _WINDOWS */
}


/*----------------------------------------------------------------------
   DrawIntersection draw an intersection symbol.
  ----------------------------------------------------------------------*/
#ifdef __STDC__
void                DrawIntersection (int frame, int x, int y, int l, int h, ptrfont font, int RO, int func, int fg)
#else  /* __STDC__ */
void                DrawIntersection (frame, x, y, l, h, font, RO, func, fg)
int                 frame;
int                 x;
int                 y;
int                 l;
int                 h;
ptrfont             font;
int                 RO;
int                 func;
int                 fg;

#endif /* __STDC__ */
{
#  ifdef _WINDOWS
   if (y < 0)
      return;

   if (TtPrinterDC) {
   } else {
        FILE* fout;

        fout = (FILE *) FrRef[frame];

        /* Do we need to change the current color ? */
        CurrentColor (fout, fg);

        /* Change the current font */
        PoscriptFont = NULL;
        fprintf (fout, "(Symbol) %.0f sf\n", FontHeight (font) * 0.9);
        x = PixelToPoint (x + (l / 2));
        y = PixelToPoint (y + h - FontHeight (font) + FontBase (font));
        fprintf (fout, "-%d %d (\\307) c\n", y, x);
   }
#  else  /* _WINDOWS */
   FILE               *fout;

   fout = (FILE *) FrRef[frame];
  if (y < 0)
    return;

   /* Do we need to change the current color ? */
   CurrentColor (fout, fg);

   /* Change the current font */
   PoscriptFont = NULL;
   fprintf (fout, "(Symbol) %.0f sf\n", FontHeight (font) * 0.9);
   x = PixelToPoint (x + (l / 2));
   y = PixelToPoint (y + h - FontHeight (font) + FontBase (font));
   fprintf (fout, "-%d %d (\\307) c\n", y, x);
#  endif /* _WINDOWS */
}


/*----------------------------------------------------------------------
   DrawArrow draw an arrow following the indicated direction in degrees :
   0 (right arrow), 45, 90, 135, 180,
   225, 270 ou 315.
  ----------------------------------------------------------------------*/
#ifdef __STDC__
void                DrawArrow (int frame, int thick, int style, int x, int y, int l, int h, int direction, int RO, int func, int fg)
#else  /* __STDC__ */
void                DrawArrow (frame, thick, style, x, y, l, h, direction, RO, func, fg)
int                 frame;
int                 thick;
int                 style;
int                 x;
int                 y;
int                 l;
int                 h;
int                 direction;
int                 RO;
int                 func;
int                 fg;
#endif /* __STDC__ */
{
   int                 xm, ym, xf, yf, lg;
   FILE               *fout;

   if (l == 0 && h == 0)
      return;

   fout = (FILE *) FrRef[frame];
  if (y < 0)
    return;

   if (thick <= 0)
      return;

   /* Do we need to change the current color ? */
   CurrentColor (fout, fg);

   l--;
   h--;
   xm = PixelToPoint (x + l / 2);
   xf = PixelToPoint (x + l);
   ym = PixelToPoint (y + h / 2);
   yf = PixelToPoint (y + h);
   lg = HL + thick;		/* lenght of the arrow head */
   x = PixelToPoint (x);
   y = PixelToPoint (y);

   if (direction == 0)
     {
	/* draw a right arrow */
	fprintf (fout, "%d -%d %d -%d %d %d %d Seg\n", x, ym, xf, ym, style, thick, 2);
	fprintf (fout, "%d %d -%d %d -%d %d %d %d arr\n", style, x, ym, xf, ym, thick, lg, lg);
     }
   else if (direction == 45)
     {
	fprintf (fout, "%d -%d %d -%d %d %d %d Seg\n", x, yf, xf, y, style, thick, 2);
	fprintf (fout, "%d %d -%d %d -%d %d %d %d arr\n", style, x, yf, xf, y, thick, lg, lg);
     }
   else if (direction == 90)
     {
	/* draw a bottom-up arrow */
	fprintf (fout, "%d -%d %d -%d %d %d %d Seg\n", xm, yf, xm, y, style, thick, 2);
	fprintf (fout, "%d %d -%d %d -%d %d %d %d arr\n", style, xm, yf, xm, y, thick, lg, lg);
     }
   else if (direction == 135)
     {
	fprintf (fout, "%d -%d %d -%d %d %d %d Seg\n", xf, yf, x, y, style, thick, 2);
	fprintf (fout, "%d %d -%d %d -%d %d %d %d arr\n", style, xf, yf, x, y, thick, lg, lg);
     }
   else if (direction == 180)
     {
	/* draw a left arrow */
	fprintf (fout, "%d -%d %d -%d %d %d %d Seg\n", xf, ym, x, ym, style, thick, 2);
	fprintf (fout, "%d %d -%d %d -%d %d %d %d arr\n", style, xf, ym, x, ym, thick, lg, lg);
     }
   else if (direction == 225)
     {
	fprintf (fout, "%d -%d %d -%d %d %d %d Seg\n", xf, y, x, yf, style, thick, 2);
	fprintf (fout, "%d %d -%d %d -%d %d %d %d arr\n", style, xf, y, x, yf, thick, lg, lg);
     }
   else if (direction == 270)
     {
	/* draw a top-down arrow */
	fprintf (fout, "%d -%d %d -%d %d %d %d Seg\n", xm, y, xm, yf, style, thick, 2);
	fprintf (fout, "%d %d -%d %d -%d %d %d %d arr\n", style, xm, y, xm, yf, thick, lg, lg);
     }
   else if (direction == 315)
     {
	fprintf (fout, "%d -%d %d -%d %d %d %d Seg\n", x, y, xf, yf, style, thick, 2);
	fprintf (fout, "%d %d -%d %d -%d %d %d %d arr\n", style, x, y, xf, yf, thick, lg, lg);
     }
}


/*----------------------------------------------------------------------
   DrawBracket draw an opening or closing bracket (depending on direction)
  ----------------------------------------------------------------------*/
#ifdef __STDC__
void                DrawBracket (int frame, int thick, int x, int y, int l, int h, int direction, ptrfont font, int RO, int func, int fg)
#else  /* __STDC__ */
void                DrawBracket (frame, thick, x, y, l, h, direction, font, RO, func, fg)
int                 frame;
int                 thick;
int                 x;
int                 y;
int                 l;
int                 h;
int                 direction;
ptrfont             font;
int                 RO;
int                 func;
int                 fg;
#endif /* __STDC__ */
{
   int                 ey, yf;
   FILE               *fout;

   fout = (FILE *) FrRef[frame];
  if (y < 0)
    return;

   /* Do we need to change the current color ? */
   CurrentColor (fout, fg);

   /* Do we need to change the current font ? */
   CurrentFont (fout, font);

   l--;
   h--;
   ey = FontHeight (font);
   h -= ey;
   y += FontBase (font);
   yf = PixelToPoint (y + h);
   y = PixelToPoint (y) + 1;
   x = PixelToPoint (x);

   if (h < ey / 4)
     {
	/* Made of only one glyph */
	if (direction == 0)
	   fprintf (fout, "-%d %d ([) c\n", yf, x);
	else
	   fprintf (fout, "-%d %d (])c\n", yf, x);
     }
   else
     {
	/* Drawn with more than one glyph */
	if (direction == 0)	/* Trace un crochet ouvrant */
	   fprintf (fout, "%d -%d -%d %s (\\351) (\\352) (\\353) s3\n", x + 1, yf, y, Scale);
	else
	   fprintf (fout, "%d -%d -%d %s (\\371) (\\372) (\\373) s3\n", x, yf, y, Scale);
     }
}


/*----------------------------------------------------------------------
   DrawParenthesis draw a closing or opening parenthesis (direction).
  ----------------------------------------------------------------------*/
#ifdef __STDC__
void                DrawParenthesis (int frame, int thick, int x, int y, int l, int h, int direction, ptrfont font, int RO, int func, int fg)
#else  /* __STDC__ */
void                DrawParenthesis (frame, thick, x, y, l, h, direction, font, RO, func, fg)
int                 frame;
int                 thick;
int                 x;
int                 y;
int                 l;
int                 h;
int                 direction;
ptrfont             font;
int                 RO;
int                 func;
int                 fg;
#endif /* __STDC__ */
{
#  ifdef _WINDOWS
   if (y < 0)
      return;
   if (thick < 0)
      return;

   if (TtPrinterDC) {
      int xm, yf, yend, exnum, delta;

      exnum = 0;

      if (h <= (int) (1.3 * FontHeight (font))) { /* With only one glyph */
		 if (direction == 0) { /* draw a opening parenthesis */
            xm = x + ((l - CharacterWidth ('(', font)) / 2);
            yf = y + ((h - CharacterHeight ('(', font)) / 2) - FontAscent (font) + CharacterAscent ('(', font);
            WIN_DrawChar ('(', frame, xm, yf, font, RO, func, fg);
		 } else { /* draw a closing parenthesis */
               xm = x + ((l - CharacterWidth (')', font)) / 2);
               yf = y + ((h - CharacterHeight (')', font)) / 2) - FontAscent (font) + CharacterAscent (')', font);
               WIN_DrawChar (')', frame, xm, yf, font, RO, func, fg);
		}
	  } else { /* Need more than one glyph */
           if (direction == 0) {
              /* draw a opening parenthesis */
              xm = x + ((l - CharacterWidth ('\346', font)) / 2);
              yf = y - FontAscent (font) + CharacterAscent ('\346', font);
              WIN_DrawChar ('\346', frame, xm, yf, font, RO, func, fg);
              yend = y + h - CharacterHeight ('\350', font) - FontAscent (font) + CharacterAscent ('\350', font) - 1;
              WIN_DrawChar ('\350', frame, xm, yend, font, RO, func, fg);

              yf += CharacterHeight ('\346', font) - 1;
              delta = yend - yf;
              if (delta >= 0) {
                 for (yf += CharacterAscent ('\347', font) - FontAscent (font),
                 yend -= CharacterHeight ('\347', font) - 1;
                 yf < yend;
                 yf += CharacterHeight ('\347', font), exnum++)
                 WIN_DrawChar ('\347', frame, xm, yf, font, RO, func, fg);
                 if (exnum)
                    WIN_DrawChar ('\347', frame, xm, yend, font, RO, func, fg);
                 else
                    WIN_DrawChar ('\347', frame, xm, yf + ((delta - CharacterHeight ('\347', font)) / 2), font, RO, func, fg);
			  }
		   } else {
                /* draw a closing parenthesis */
                xm = x + ((l - CharacterWidth ('\366', font)) / 2);
                yf = y - FontAscent (font) + CharacterAscent ('\366', font);
                WIN_DrawChar ('\366', frame, xm, yf, font, RO, func, fg);
                yend = y + h - CharacterHeight ('\370', font) - FontAscent (font) + CharacterAscent ('\370', font) - 1;
                WIN_DrawChar ('\370', frame, xm, yend, font, RO, func, fg);

                yf += CharacterHeight ('\366', font) - 1;
                delta = yend - yf;
                if (delta >= 0) {
                   for (yf += CharacterAscent ('\367', font) - FontAscent (font),
                        yend -= CharacterHeight ('\367', font) - 1;
                        yf < yend;
                        yf += CharacterHeight ('\367', font), exnum++)
                       WIN_DrawChar ('\367', frame, xm, yf, font, RO, func, fg);
                   if (exnum)
                      WIN_DrawChar ('\367', frame, xm, yend, font, RO, func, fg);
                   else
                       WIN_DrawChar ('\367', frame, xm, yf + ((delta - CharacterHeight ('\367', font)) / 2), font, RO, func, fg);
				}
		   }
      }
   } else {
         int   ey, yf;
         FILE* fout;

         fout = (FILE *) FrRef[frame];

         /* Do we need to change the current color ? */
         CurrentColor (fout, fg);

         /* Do we need to change the current font ? */
         CurrentFont (fout, font);

         l--;
         h--;
         ey = FontHeight (font);
         h -= ey;
         y += FontBase (font);
         x = PixelToPoint (x);
         yf = PixelToPoint (y + h);
         y = PixelToPoint (y) + 1;

         if (h < ey / 4) { /* Made of only one glyph */
            if (direction == 0)
               fprintf (fout, "-%d %d (\\() c\n", yf, x);
            else
                fprintf (fout, "-%d %d (\\)) c\n", yf, x);
		 } else { /* Drawn with more than one glyph */
               if (direction == 0)
                  fprintf (fout, "%d -%d -%d %s (\\346) (\\347) (\\350) s3\n", x + 1, yf, y, Scale);
               else
                  fprintf (fout, "%d -%d -%d %s (\\366) (\\367) (\\370) s3\n", x, yf, y, Scale);
		 }
	}
#   else  /* !_WINDOWS */
   int                 ey, yf;
   FILE               *fout;

   fout = (FILE *) FrRef[frame];
  if (y < 0)
    return;

   /* Do we need to change the current color ? */
   CurrentColor (fout, fg);

   /* Do we need to change the current font ? */
   CurrentFont (fout, font);

   l--;
   h--;
   ey = FontHeight (font);
   h -= ey;
   y += FontBase (font);
   x = PixelToPoint (x);
   yf = PixelToPoint (y + h);
   y = PixelToPoint (y) + 1;

   if (h < ey / 4)
     {
	/* Made of only one glyph */
	if (direction == 0)
	   fprintf (fout, "-%d %d (\\() c\n", yf, x);
	else
	   fprintf (fout, "-%d %d (\\)) c\n", yf, x);
     }
   else
     {
	/* Drawn with more than one glyph */
	if (direction == 0)
	   fprintf (fout, "%d -%d -%d %s (\\346) (\\347) (\\350) s3\n", x + 1, yf, y, Scale);
	else
	   fprintf (fout, "%d -%d -%d %s (\\366) (\\367) (\\370) s3\n", x, yf, y, Scale);
     }
#   endif /* _WINDOWS */
}


/*----------------------------------------------------------------------
   DrawBrace draw an opening of closing brace (depending on direction).
  ----------------------------------------------------------------------*/
#ifdef __STDC__
void                DrawBrace (int frame, int thick, int x, int y, int l, int h, int direction, ptrfont font, int RO, int func, int fg)
#else  /* __STDC__ */
void                DrawBrace (frame, thick, x, y, l, h, direction, font, RO, func, fg)
int                 frame;
int                 thick;
int                 x;
int                 y;
int                 l;
int                 h;
int                 direction;
ptrfont             font;
int                 RO;
int                 func;
int                 fg;
#endif /* __STDC__ */
{
   int                 ey, yf;
   FILE               *fout;

   fout = (FILE *) FrRef[frame];
  if (y < 0)
    return;

   /* Do we need to change the current color ? */
   CurrentColor (fout, fg);

   /* Do we need to change the current font ? */
   CurrentFont (fout, font);

   l--;
   h--;
   ey = FontHeight (font);
   h -= ey;
   y += FontBase (font);
   x = PixelToPoint (x + (l / 2));
   yf = PixelToPoint (y + h);
   y = PixelToPoint (y) + 1;

   if (h < ey - 1)
     {
	/* Made of only one glyph */
	if (direction == 0)
	   fprintf (fout, "-%d %d ({) c\n", yf, x);
	else
	   fprintf (fout, "-%d %d (}) c\n", yf, x);
     }
   else
     {
	/* Drawn with more than one glyph */
	if (direction == 0)
	   fprintf (fout, "%d -%d -%d %s (\\354) (\\355) (\\356) (\\357) s4\n", x, yf, y, Scale);
	else
	   fprintf (fout, "%d -%d -%d %s (\\374) (\\375) (\\376) (\\357) s4\n", x, yf, y, Scale);
     }
}


/*----------------------------------------------------------------------
   DrawRectangle draw a rectangle located at (x, y) in frame,
   of geometry width x height.
   thick indicate the thickness of the lines.
   Parameters fg, bg, and pattern are for drawing
   color, background color and fill pattern.
  ----------------------------------------------------------------------*/
#ifdef __STDC__
void                DrawRectangle (int frame, int thick, int style, int x, int y, int larg, int height, int RO, int active, int fg, int bg, int pattern)

#else  /* __STDC__ */
void                DrawRectangle (frame, thick, style, x, y, larg, height, RO, active, fg, bg, pattern)
int                 frame;
int                 thick;
int                 style;
int                 x;
int                 y;
int                 larg;
int                 height;
int                 RO;
int                 active;
int                 fg;
int                 bg;
int                 pattern;
#endif /* __STDC__ */
{
#  ifdef _WINDOWS
   int    xf, yf;
   Pixmap pat;  
   HPEN   hPen = 0, hOldPen;
   HBRUSH hBrush, hOldBrush;

   if (y < 0)   
      return ;

   if (TtPrinterDC == (HDC) 0) {
      xf = PixelToPoint (x + larg);
      yf = PixelToPoint (y + height);
      x  = PixelToPoint (x);
      y  = PixelToPoint (y);
   } else {
        xf = x + larg;
        yf = y + height;
   }

   /* Fill in the rectangle */
   if (TtPrinterDC) {
      if (larg > thick + 1)
         larg = larg - thick - 1;
      if (height > thick + 1)
         height = height - thick - 1;
      x += thick / 2;
      y += thick / 2;

      pat = (Pixmap) CreatePattern (0, RO, active, fg, bg, pattern);
      if (pat != 0) {
         WinLoadGC (TtPrinterDC, fg, RO);
   
         hBrush = CreateSolidBrush (Pix_Color[bg]);
         hOldBrush = SelectObject (TtPrinterDC, hBrush);
         PatBlt (TtPrinterDC, x, y, larg, height, PATCOPY);
         SelectObject (TtPrinterDC, hOldBrush);
         if (!DeleteObject (hBrush))
            WinErrorBox (WIN_Main_Wd);
	  }

      if (thick > 0) {
         if (!(hPen = CreatePen (PS_SOLID, thick, Pix_Color [fg])))
            WinErrorBox (WIN_Main_Wd);
         hOldPen = SelectObject (TtPrinterDC, hPen) ;
         SelectObject (TtPrinterDC, GetStockObject (NULL_BRUSH)) ;
         Rectangle (TtPrinterDC, x, y, xf, yf);
         SelectObject (TtPrinterDC, hOldPen);
         DeleteObject (hPen);
	  }
   } else {
         FILE               *fout;
         fout = (FILE *) FrRef[frame];

         /* Do we need to change the current color ? */
         if (thick > 0)
            CurrentColor (fout, fg);

         FillWithPattern (fout, fg, bg, pattern);
         fprintf (fout, "%d -%d %d -%d %d -%d  %d -%d %d %d %d Poly\n", x, y, x, yf, xf, yf, xf, y, style, thick, 4);
   }
#  else  /* !_WINDOWS */
   int                 xf, yf;
   FILE               *fout;
   fout = (FILE *) FrRef[frame];
  if (y < 0)
    return;

   /* Do we need to change the current color ? */
   if (thick > 0)
      CurrentColor (fout, fg);

   xf = PixelToPoint (x + larg);
   yf = PixelToPoint (y + height);
   x = PixelToPoint (x);
   y = PixelToPoint (y);

   FillWithPattern (fout, fg, bg, pattern);
   fprintf (fout, "%d -%d %d -%d %d -%d  %d -%d %d %d %d Poly\n", x, y, x, yf, xf, yf, xf, y, style, thick, 4);
#  endif /* _WINDOWS */
}


/*----------------------------------------------------------------------
   DrawSegments draw a set of segments.
   Parameter buffer is a pointer to the list of control points.
   nb indicate the number of points.
   The first point is a fake one containing the geometry.
   RO indicate whether it's a read-only box
   active indicate if the box is active
   fg parameter gives the drawing color.
   arrow parameter indicate whether :
   - no arrow have to be drawn (0)
   - a forward arrow has to be drawn (1)
   - a backward arrow has to be drawn (2)
   - both backward and forward arrows have to be drawn (3)
  ----------------------------------------------------------------------*/
#ifdef __STDC__
void                DrawSegments (int frame, int thick, int style, int x, int y, PtrTextBuffer buffer, int nb, int RO, int active, int fg, int arrow)
#else  /* __STDC__ */
void                DrawSegments (frame, thick, style, x, y, buffer, nb, RO, active, fg, arrow)
int                 frame;
int                 thick;
int                 style;
int                 x;
int                 y;
PtrTextBuffer       buffer;
int                 nb;
int                 RO;
int                 active;
int                 fg;
int                 arrow;
#endif /* __STDC__ */
{
   int                 i, j;
   float               xp, yp;
   int                 prevx, prevy;
   int                 lg;
   PtrTextBuffer       adbuff;
   FILE               *fout;

   fout = (FILE *) FrRef[frame];
  if (y < 0)
    return;
   xp = yp = 0;
   prevx = prevy = 0;
   if (thick == 0)
      return;

   lg = HL + thick;

   /* Do we need to change the current color ? */
   CurrentColor (fout, fg);
   x = PixelToPoint (x);
   y = PixelToPoint (y);
   adbuff = buffer;

   /* backward arrow  */
   if (arrow == 2 || arrow == 3)
      fprintf (fout, "%d %d -%d %d -%d %d %d %d arr\n", style,
	       FloatToInt ((float) buffer->BuPoints[2].XCoord / 1000 + x),
	       FloatToInt ((float) buffer->BuPoints[2].YCoord / 1000 + y),
	       FloatToInt ((float) buffer->BuPoints[1].XCoord / 1000 + x),
	       FloatToInt ((float) buffer->BuPoints[1].YCoord / 1000 + y), thick, lg, lg);

   j = 1;
   for (i = 1; i < nb; i++)
     {
	if (j >= adbuff->BuLength)
	  {
	     if (adbuff->BuNext != NULL)
	       {
		  /* Next buffer */
		  adbuff = adbuff->BuNext;
		  j = 0;
	       }
	  }
	if (i == nb - 1)
	  {
	     /* keep last coordinates for drawing the arrows */
	     prevx = FloatToInt (xp);
	     prevy = FloatToInt (yp);
	  }
	/* Coordinate for next point */
	xp = (float) adbuff->BuPoints[j].XCoord / 1000 + x;
	yp = (float) adbuff->BuPoints[j].YCoord / 1000 + y;
	fprintf (fout, "%f -%f\n", xp, yp);
	j++;
     }
   /* Extra characteristics for drawing */
   fprintf (fout, " %d %d %d Seg\n", style, thick, nb - 1);

   /* forward arrow  */
   j--;
   if (arrow == 1 || arrow == 3)
      fprintf (fout, "%d %d -%d %d -%d %d %d %d arr\n", style, prevx, prevy,
	       FloatToInt (xp), FloatToInt (yp), thick, lg, lg);
}


/*----------------------------------------------------------------------
   DrawPolygon draw a polygone.
   Parameter buffer is a pointer to the list of control points.
   nb indicate the number of points.
   The first point is a fake one containing the geometry.
   RO indicate whether it's a read-only box
   active indicate if the box is active
   Parameters fg, bg, and pattern are for drawing
   color, background color and fill pattern.
  ----------------------------------------------------------------------*/
#ifdef __STDC__
void                DrawPolygon (int frame, int thick, int style, int x, int y, PtrTextBuffer buffer, int nb, int RO, int active, int fg, int bg, int pattern)
#else  /* __STDC__ */
void                DrawPolygon (frame, thick, style, x, y, buffer, nb, RO, active, fg, bg, pattern)
int                 frame;
int                 thick;
int                 style;
int                 x;
int                 y;
PtrTextBuffer       buffer;
int                 nb;
int                 RO;
int                 active;
int                 fg;
int                 bg;
int                 pattern;
#endif /* __STDC__ */
{
   int                 i, j;
   float               xp, yp;
   PtrTextBuffer       adbuff;
   FILE               *fout;

   fout = (FILE *) FrRef[frame];
  if (y < 0)
    return;

   /* Do we need to change the current color ? */
   CurrentColor (fout, fg);
   FillWithPattern (fout, fg, bg, pattern);
   x = PixelToPoint (x);
   y = PixelToPoint (y);
   adbuff = buffer;
   j = 1;

   for (i = 1; i < nb; i++)
     {
	if (j >= adbuff->BuLength)
	  {
	     if (adbuff->BuNext != NULL)
	       {
		  /* Next buffer */
		  adbuff = adbuff->BuNext;
		  j = 0;
	       }
	  }
	/* Coordinate for next point */
	xp = (float) adbuff->BuPoints[j].XCoord / 1000. + x;
	yp = (float) adbuff->BuPoints[j].YCoord / 1000. + y;
	fprintf (fout, "%f -%f\n", xp, yp);
	j++;
     }
   /* Extra characteristics for drawing */
   fprintf (fout, "%d %d %d  Poly\n", style, thick, nb - 1);
}


/*----------------------------------------------------------------------
   DrawCurb draw an open curb.
   Parameter buffer is a pointer to the list of control points.
   nb indicate the number of points.
   The first point is a fake one containing the geometry.
   fg indicate the drawing color
   arrow parameter indicate whether :
   - no arrow have to be drawn (0)
   - a forward arrow has to be drawn (1)
   - a backward arrow has to be drawn (2)
   - both backward and forward arrows have to be drawn (3)
   Parameter control indicate the control points.
  ----------------------------------------------------------------------*/
#ifdef __STDC__
void                DrawCurb (int frame, int thick, int style, int x, int y, PtrTextBuffer buffer, int nb, int RO, int active, int fg, int arrow, C_points * controls)
#else  /* __STDC__ */
void                DrawCurb (frame, thick, style, x, y, buffer, nb, RO, active, fg, arrow, controls)
int                 frame;
int                 thick;
int                 style;
int                 x;
int                 y;
PtrTextBuffer       buffer;
int                 nb;
int                 RO;
int                 active;
int                 fg;
int                 arrow;
C_points           *controls;
#endif /* __STDC__ */
{
   PtrTextBuffer       adbuff;
   int                 i, j;
   int                 lg;
   int                 lastx, lasty, newx, newy;
   float               x1, y1, x2, y2, x3, y3;
   FILE               *fout;

   fout = (FILE *) FrRef[frame];
  if (y < 0)
    return;
   if (thick == 0)
      return;

   /* Do we need to change the current color ? */
   CurrentColor (fout, fg);

   lg = HL + thick;
   x = PixelToPoint (x);
   y = PixelToPoint (y);
   j = 1;
   i = 2;
   adbuff = buffer;
   lastx = adbuff->BuPoints[j].XCoord;
   lasty = adbuff->BuPoints[j].YCoord;
   j++;
   newx = adbuff->BuPoints[j].XCoord;
   newy = adbuff->BuPoints[j].YCoord;
   /* control points for first arc */
   x1 = (float) lastx / 1000 + x;
   y1 = (float) lasty / 1000 + y;
   x2 = (float) (PixelToPoint ((int) (controls[i].lx * 3000)) + lastx) / 4000 + x;
   y2 = (float) (PixelToPoint ((int) (controls[i].ly * 3000)) + lasty) / 4000 + y;
   x3 = (float) (PixelToPoint ((int) (controls[i].lx * 3000)) + newx) / 4000 + x;
   y3 = (float) (PixelToPoint ((int) (controls[i].ly * 3000)) + newy) / 4000 + y;

   /* backward arrow  */
   if (arrow == 2 || arrow == 3)
      fprintf (fout, "%d %d -%d %d -%d %d %d %d arr\n", style, FloatToInt (x2), FloatToInt (y2), FloatToInt (x1), FloatToInt (y1), thick, lg, lg);

   for (i = 2; i < nb; i++)
     {
	/* 3 points needed to define the arc */
	fprintf (fout, "%f -%f %f -%f %f -%f\n", x3, y3, x2, y2, x1, y1);
	/* skip to next arc */
	j++;
	if (j >= adbuff->BuLength)
	  {
	     if (adbuff->BuNext != NULL)
	       {
		  /* Next buffer */
		  adbuff = adbuff->BuNext;
		  j = 0;
	       }
	  }
	lastx = newx;
	lasty = newy;
	newx = adbuff->BuPoints[j].XCoord;
	newy = adbuff->BuPoints[j].YCoord;
	x1 = (float) lastx / 1000 + x;
	y1 = (float) lasty / 1000 + y;
	if (i < nb - 2)
	  {
	     x2 = (float) PixelToPoint ((int) (controls[i].rx * 1000)) / 1000 + x;
	     y2 = (float) PixelToPoint ((int) (controls[i].ry * 1000)) / 1000 + y;
	     x3 = (float) PixelToPoint ((int) (controls[i + 1].lx * 1000)) / 1000 + x;
	     y3 = (float) PixelToPoint ((int) (controls[i + 1].ly * 1000)) / 1000 + y;
	  }
	else if (i == nb - 2)
	  {
	     x2 = (float) (PixelToPoint ((int) (controls[i].rx * 3000)) + lastx) / 4000 + x;
	     y2 = (float) (PixelToPoint ((int) (controls[i].ry * 3000)) + lasty) / 4000 + y;
	     x3 = (float) (PixelToPoint ((int) (controls[i].rx * 3000)) + newx) / 4000 + x;
	     y3 = (float) (PixelToPoint ((int) (controls[i].ry * 3000)) + newy) / 4000 + y;
	  }
     }
   fprintf (fout, "%f -%f %d %d %d Curv\n", x1, y1, style, thick, nb - 1);

   /* forward arrow */
   if (arrow == 1 || arrow == 3)
      fprintf (fout, "%d %d -%d %d -%d %d %d %d arr\n", style, FloatToInt (x3), FloatToInt (y3), FloatToInt (x1), FloatToInt (y1), thick, lg, lg);
}


/*----------------------------------------------------------------------
   DrawSpline draw a closed curb.
   Parameter buffer is a pointer to the list of control points.
   nb indicate the number of points.
   The first point is a fake one containing the geometry.
   RO indicate whether it's a read-only box
   active indicate if the box is active
   Parameters fg, bg, and pattern are for drawing
   color, background color and fill pattern.
   Parameter controls contains the list of control points.
  ----------------------------------------------------------------------*/
#ifdef __STDC__
void                DrawSpline (int frame, int thick, int style, int x, int y, PtrTextBuffer buffer, int nb, int RO, int active, int fg, int bg, int pattern, C_points * controls)
#else  /* __STDC__ */
void                DrawSpline (frame, thick, style, x, y, buffer, nb, RO, active, fg, bg, pattern, controls)
int                 frame;
int                 thick;
int                 style;
int                 x;
int                 y;
PtrTextBuffer       buffer;
int                 nb;
int                 RO;
int                 active;
int                 fg;
int                 bg;
int                 pattern;
C_points           *controls;
#endif /* __STDC__ */
{
   PtrTextBuffer       adbuff;
   int                 i, j;
   float               x0, y0, x1, y1, x2, y2, x3, y3;
   FILE               *fout;

   fout = (FILE *) FrRef[frame];
  if (y < 0)
    return;

   /* Do we need to change the current color ? */
   CurrentColor (fout, fg);
   FillWithPattern (fout, fg, bg, pattern);
   x = PixelToPoint (x);
   y = PixelToPoint (y);
   j = 1;
   i = 1;
   adbuff = buffer;
   x0 = x1 = (float) adbuff->BuPoints[j].XCoord / 1000 + x;
   y0 = y1 = (float) adbuff->BuPoints[j].YCoord / 1000 + y;
   x2 = (float) PixelToPoint ((int) ((controls[i].rx * 1000))) / 1000 + x;
   y2 = (float) PixelToPoint ((int) ((controls[i].ry * 1000))) / 1000 + y;

   for (i = 2; i < nb; i++)
     {
	x3 = (float) PixelToPoint ((int) ((controls[i].lx * 1000))) / 1000 + x;
	y3 = (float) PixelToPoint ((int) ((controls[i].ly * 1000))) / 1000 + y;
	fprintf (fout, "%f -%f %f -%f %f -%f\n", x3, y3, x2, y2, x1, y1);
	j++;
	if (j >= adbuff->BuLength)
	  {
	     if (adbuff->BuNext != NULL)
	       {
		  /* Next buffer */
		  adbuff = adbuff->BuNext;
		  j = 0;
	       }
	  }
	x1 = (float) adbuff->BuPoints[j].XCoord / 1000 + x;
	y1 = (float) adbuff->BuPoints[j].YCoord / 1000 + y;
	x2 = (float) PixelToPoint ((int) ((controls[i].rx * 1000))) / 1000 + x;
	y2 = (float) PixelToPoint ((int) ((controls[i].ry * 1000))) / 1000 + y;
     }

   /* Close the stroke */
   x3 = (float) PixelToPoint ((int) ((controls[1].lx * 1000))) / 1000 + x;
   y3 = (float) PixelToPoint ((int) ((controls[1].ly * 1000))) / 1000 + y;
   fprintf (fout, "%f -%f %f -%f %f -%f\n", x3, y3, x2, y2, x1, y1);
   fprintf (fout, "%f -%f %d %d %d Splin\n", x0, y0, style, thick, nb);

}


/*----------------------------------------------------------------------
   DrawDiamond draw a diamond.
   Parameters fg, bg, and pattern are for drawing
   color, background color and fill pattern.
  ----------------------------------------------------------------------*/
#ifdef __STDC__
void                DrawDiamond (int frame, int thick, int style, int x, int y, int larg, int height, int RO, int active, int fg, int bg, int pattern)
#else  /* __STDC__ */
void                DrawDiamond (frame, thick, style, x, y, larg, height, RO, active, fg, bg, pattern)
int                 frame;
int                 thick;
int                 style;
int                 x;
int                 y;
int                 larg;
int                 height;
int                 RO;
int                 active;
int                 fg;
int                 bg;
int                 pattern;
#endif /* __STDC__ */
{
   int                 xm, xf, ym, yf;
   FILE               *fout;

   fout = (FILE *) FrRef[frame];
  if (y < 0)
    return;

   /* Do we need to change the current color ? */
   CurrentColor (fout, fg);
   xm = PixelToPoint (x + larg / 2);
   ym = PixelToPoint (y + height / 2);
   xf = PixelToPoint (x + larg);
   yf = PixelToPoint (y + height);
   x = PixelToPoint (x);
   y = PixelToPoint (y);

   FillWithPattern (fout, fg, bg, pattern);
   fprintf (fout, "%d -%d %d -%d %d -%d %d -%d %d %d %d Poly\n", xm, y, x, ym, xm, yf, xf, ym, style, thick, 4);
}


/*----------------------------------------------------------------------
   DrawOval draw a rectangle with smoothed corners.
   Parameters fg, bg, and pattern are for drawing
   color, background color and fill pattern.
  ----------------------------------------------------------------------*/
#ifdef __STDC__
void                DrawOval (int frame, int thick, int style, int x, int y, int larg, int height, int RO, int active, int fg, int bg, int pattern)
#else  /* __STDC__ */
void                DrawOval (frame, thick, style, x, y, larg, height, RO, active, fg, bg, pattern)
int                 frame;
int                 thick;
int                 style;
int                 x;
int                 y;
int                 larg;
int                 height;
int                 RO;
int                 active;
int                 fg;
int                 bg;
int                 pattern;
#endif /* __STDC__ */
{
   int                 arc, xf, yf;
   FILE               *fout;

   fout = (FILE *) FrRef[frame];
  if (y < 0)
    return;

   /* Do we need to change the current color ? */
   if (thick > 0)
      CurrentColor (fout, fg);

   arc = 3 * 72 / 25.4;
   xf = PixelToPoint (x + larg - 1);
   yf = PixelToPoint (y + height - 1);
   x = PixelToPoint (x);
   y = PixelToPoint (y);

   FillWithPattern (fout, fg, bg, pattern);
   fprintf (fout, "%d %d %d -%d %d -%d %d -%d %d -%d %d -%d %d -%d %d ov\n",
	    style, thick,
	    /*5 */ x, y, /*4 */ x, yf, /*3 */ xf, yf, /*2 */ xf, y, /*1 */ x, y, /*o */ x, yf - arc,
	    arc);
}


/*----------------------------------------------------------------------
   DrawEllips draw an ellips (or a circle).
   Parameters fg, bg, and pattern are for drawing
   color, background color and fill pattern.
  ----------------------------------------------------------------------*/
#ifdef __STDC__
void                DrawEllips (int frame, int thick, int style, int x, int y, int larg, int height, int RO, int active, int fg, int bg, int pattern)
#else  /* __STDC__ */
void                DrawEllips (frame, thick, style, x, y, larg, height, RO, active, fg, bg, pattern)
int                 frame;
int                 thick;
int                 style;
int                 x;
int                 y;
int                 larg;
int                 height;
int                 RO;
int                 active;
int                 fg;
int                 bg;
int                 pattern;
#endif /* __STDC__ */
{
#  ifdef _WINDOWS 
   int    xm, ym;
   Pixmap pat;  
   HPEN   hPen = 0, hOldPen;
   HBRUSH hBrush, hOldBrush;

   if (y < 0)   
      return ;

   larg = larg / 2;
   height = height / 2;
   if (TtPrinterDC == (HDC) 0) {
      xm = PixelToPoint (x + larg);
      ym = PixelToPoint (y + height);
      larg = PixelToPoint (larg);
      height = PixelToPoint (height);
   } else {
        xm = x + larg;
        ym = y + height;
   }

   if (TtPrinterDC) {
#     if 0 /* Fill an ellipse */
      pat = (Pixmap) CreatePattern (0, RO, active, fg, bg, pattern);
      if (pat != 0) {
         WinLoadGC (TtPrinterDC, fg, RO);
         hBrush = CreateSolidBrush (Pix_Color[bg]);
         hOldBrush = SelectObject (TtPrinterDC, hBrush);
         PatBlt (TtPrinterDC, x, y, larg, height, PATCOPY);
         SelectObject (TtPrinterDC, hOldBrush);
         if (!DeleteObject (hBrush))
            WinErrorBox (WIN_Main_Wd);
	  }
#     endif /* 0 */

      if (thick > 0) {
         if (!(hPen = CreatePen (PS_SOLID, thick, Pix_Color [fg])))
            WinErrorBox (WIN_Main_Wd);
         hOldPen = SelectObject (TtPrinterDC, hPen) ;
         SelectObject (TtPrinterDC, GetStockObject (NULL_BRUSH)) ;
	     Ellipse (TtPrinterDC, x, y, x + larg, y + height);
         SelectObject (TtPrinterDC, hOldPen);
         if (!DeleteObject (hPen))
            WinErrorBox (WIN_Main_Wd);
	  }
   } else {
         FILE               *fout;
         fout = (FILE *) FrRef[frame];

         if (y < 0)
            return;
         /* Do we need to change the current color ? */
         if (thick > 0)
            CurrentColor (fout, fg);
         larg = larg / 2;
         height = height / 2;
         xm = PixelToPoint (x + larg);
         ym = PixelToPoint (y + height);
         larg = PixelToPoint (larg);
         height = PixelToPoint (height);

         FillWithPattern (fout, fg, bg, pattern);
        if (larg == height) /* Draw a circle */
           fprintf (fout, "%d %d %d -%d %d cer\n", style, thick, xm, ym, larg);
        else /* Draw an ellips */
             fprintf (fout, "%d %d %d %d %d %d ellipse\n", style, thick, xm, -ym, larg, height);
   }
#  else /* !_WINDOWS */
   int                 xm, ym;
   FILE               *fout;

   fout = (FILE *) FrRef[frame];
   if (y < 0)
      return;
   /* Do we need to change the current color ? */
   if (thick > 0)
      CurrentColor (fout, fg);
   larg = larg / 2;
   height = height / 2;
   xm = PixelToPoint (x + larg);
   ym = PixelToPoint (y + height);
   larg = PixelToPoint (larg);
   height = PixelToPoint (height);

   FillWithPattern (fout, fg, bg, pattern);
   if (larg == height)
     {
	/* Draw a circle */
	fprintf (fout, "%d %d %d -%d %d cer\n", style, thick, xm, ym, larg);
     }
   else
     {
	/* Draw an ellips */
	fprintf (fout, "%d %d %d %d %d %d ellipse\n", style, thick,
		 xm, -ym, larg, height);
     }
#  endif /* _WINDOWS */
}

/*----------------------------------------------------------------------
   DrawCorner draw two contiguous edges of a rectangle.
  ----------------------------------------------------------------------*/
#ifdef __STDC__
void                DrawCorner (int frame, int thick, int style, int x, int y, int l, int h, int corner, int RO, int func, int fg)
#else  /* __STDC__ */
void                DrawCorner (frame, thick, style, x, y, l, h, corner, RO, func, fg)
int                 frame;
int                 thick;
int                 style;
int                 x;
int                 y;
int                 l;
int                 h;
int                 corner;
int                 RO;
int                 func;
int                 fg;
#endif /* __STDC__ */
{
#  ifdef _WINDOWS
   int xf, yf;

   if (TtPrinterDC) {
      HPEN      pen;
      HPEN      hOldPen;
      ThotPoint point[3];

      if (y < 0)
         return;
      if (thick <= 0)
         return;

      xf = PixelToPoint (x + l);
      yf = PixelToPoint (y + h);
      x  = PixelToPoint (x);
      y  = PixelToPoint (y);

      switch (corner) {
             case 0: point[0].x = x;
                     point[0].y = y;
                     point[1].x = xf;
                     point[1].y = y;
                     point[2].x = xf;
                     point[2].y = yf;
                     break;

             case 1: point[0].x = xf;
                     point[0].y = y;
                     point[1].x = xf;
                     point[1].y = yf;
                     point[2].x = x;
                     point[2].y = yf;
                     break;

             case 2: point[0].x = xf;
                     point[0].y = yf;
                     point[1].x = x;
                     point[1].y = yf;
                     point[2].x = x;
                     point[2].y = y;
                     break;

             case 3: point[0].x = x;
                     point[0].y = yf;
                     point[1].x = x;
                     point[1].y = y;
                     point[2].x = xf;
                     point[2].y = y;
                    break;
	  }
      WinLoadGC (TtPrinterDC, fg, RO);
      pen = CreatePen (PS_SOLID, 1, Pix_Color [fg]);
      hOldPen = SelectObject (TtPrinterDC, pen);
      Polyline (TtPrinterDC, point, 3);
      SelectObject (TtPrinterDC, hOldPen);
   } else {
         FILE* fout;

         fout = (FILE *) FrRef[frame];
         if (y < 0)
            return;
         if (thick <= 0)
            return;

         /* Do we need to change the current color ? */
         CurrentColor (fout, fg);
         xf = PixelToPoint (x + l);
         yf = PixelToPoint (y + h);
         x  = PixelToPoint (x);
         y  = PixelToPoint (y);

         switch (corner) {
                case 0: /* Top Right */
                        fprintf (fout, "%d -%d %d -%d %d -%d %d %d %d Seg\n", x, y, xf, y, xf, yf, style, thick, 3);
                        break;
                case 1: /* Right Bottom */
                        fprintf (fout, "%d -%d %d -%d %d -%d %d %d %d Seg\n", xf, y, xf, yf, x, yf, style, thick, 3);
                        break;
                case 2: /* Bottom Left */
                        fprintf (fout, "%d -%d %d -%d %d -%d %d %d %d Seg\n", xf, yf, x, yf, x, y, style, thick, 3);
                        break;
                case 3: /* Left Top */
                        fprintf (fout, "%d -%d %d -%d %d -%d %d %d %d Seg\n", x, yf, x, y, xf, y, style, thick, 3);
                        break;
		 }
   }
#  else  /* !_WINDOWS */
   int                 xf, yf;
   FILE               *fout;

   fout = (FILE *) FrRef[frame];
  if (y < 0)
    return;
   if (thick <= 0)
      return;

   /* Do we need to change the current color ? */
   CurrentColor (fout, fg);
   xf = PixelToPoint (x + l);
   yf = PixelToPoint (y + h);
   x = PixelToPoint (x);
   y = PixelToPoint (y);

   switch (corner)
	 {
	    case 0:		/* Top Right */
	       fprintf (fout, "%d -%d %d -%d %d -%d %d %d %d Seg\n", x, y, xf, y, xf, yf, style, thick, 3);
	       break;
	    case 1:		/* Right Bottom */
	       fprintf (fout, "%d -%d %d -%d %d -%d %d %d %d Seg\n", xf, y, xf, yf, x, yf, style, thick, 3);
	       break;
	    case 2:		/* Bottom Left */
	       fprintf (fout, "%d -%d %d -%d %d -%d %d %d %d Seg\n", xf, yf, x, yf, x, y, style, thick, 3);
	       break;
	    case 3:		/* Left Top */
	       fprintf (fout, "%d -%d %d -%d %d -%d %d %d %d Seg\n", x, yf, x, y, xf, y, style, thick, 3);
	       break;
	 }
#  endif /* _WINDOWS */
}


/*----------------------------------------------------------------------
   DrawRectangleFrame draw a rectangle with smoothed corners (3mm radius)
   and with an horizontal line at 6mm from top.
   Parameters fg, bg, and pattern are for drawing
   color, background color and fill pattern.
  ----------------------------------------------------------------------*/
#ifdef __STDC__
void                DrawRectangleFrame (int frame, int thick, int style, int x, int y, int larg, int height, int RO, int active, int fg, int bg, int pattern)
#else  /* __STDC__ */
void                DrawRectangleFrame (frame, thick, style, x, y, larg, height, RO, active, fg, bg, pattern)
int                 frame;
int                 thick;
int                 style;
int                 x;
int                 y;
int                 larg;
int                 height;
int                 RO;
int                 active;
int                 fg;
int                 bg;
int                 pattern;
#endif /* __STDC__ */
{
   int                 arc, xf, yf;
   FILE               *fout;

   fout = (FILE *) FrRef[frame];
  if (y < 0)
    return;
   /* Do we need to change the current color ? */
   if (thick > 0)
      CurrentColor (fout, fg);

   arc = 3 * 72 / 25.4;
   xf = PixelToPoint (x + larg - 1);
   yf = PixelToPoint (y + height - 1);
   x = PixelToPoint (x);
   y = PixelToPoint (y);

   FillWithPattern (fout, fg, bg, pattern);
   fprintf (fout, "%d %d %d -%d %d -%d %d -%d %d -%d %d -%d %d -%d %d ov\n",
	  style, thick, x, y, x, yf, xf, yf, xf, y, x, y, x, yf - arc, arc);

   y += 2 * arc;
   fprintf (fout, "%d -%d %d -%d %d %d %d Seg\n", x, y, xf, y, style, thick, 2);
}


/*----------------------------------------------------------------------
   DrawEllips draw an ellips (or a circle).
   Parameters fg, bg, and pattern are for drawing
   color, background color and fill pattern.
  ----------------------------------------------------------------------*/
#ifdef __STDC__
void                DrawEllipsFrame (int frame, int thick, int style, int x, int y, int larg, int height, int RO, int active, int fg, int bg, int pattern)
#else  /* __STDC__ */
void                DrawEllipsFrame (frame, thick, style, x, y, larg, height, RO, active, fg, bg, pattern)
int                 frame;
int                 thick;
int                 style;
int                 x;
int                 y;
int                 larg;
int                 height;
int                 RO;
int                 active;
int                 fg;
int                 bg;
int                 pattern;
#endif /* __STDC__ */
{
   int                 px7mm, shiftX;
   int                 xm, ym;
   FILE               *fout;
   double              A;

   fout = (FILE *) FrRef[frame];
  if (y < 0)
    return;
   /* Do we need to change the current color ? */
   if (thick > 0)
      CurrentColor (fout, fg);

   larg = larg / 2;
   height = height / 2;
   xm = PixelToPoint (x + larg);
   ym = PixelToPoint (y + height);
   larg = PixelToPoint (larg);
   height = PixelToPoint (height);

   FillWithPattern (fout, fg, bg, pattern);
   if (larg == height)
     {
	/* draw a circle */
	fprintf (fout, "%d %d %d -%d %d cer\n", style, thick, xm, ym, larg);
     }
   else
     {
	/* draw an ellipse */
	fprintf (fout, "%d %d %d %d %d %d ellipse\n", style, thick, xm, -ym, larg, height);
     }
   px7mm = 7 * 72 / 25.4 + 0.5;
   if (height > px7mm)
     {
	y = (ym - height + px7mm);
	A = ((double) height - px7mm) / height;
	shiftX = larg * sqrt (1 - A * A) + 0.5;
	fprintf (fout, "%d -%d  %d -%d %d %d %d Seg\n",
		 xm - shiftX, y, xm + shiftX, y, style, thick, 2);
     }
}


/*----------------------------------------------------------------------
   DrawHorizontalLine draw a vertical line aligned top center or bottom
   depending on align value.
  ----------------------------------------------------------------------*/
#ifdef __STDC__
void                DrawHorizontalLine (int frame, int thick, int style, int x, int y, int l, int h, int align, int RO, int func, int fg)
#else  /* __STDC__ */
void                DrawHorizontalLine (frame, thick, style, x, y, l, h, align, RO, func, fg)
int                 frame;
int                 thick;
int                 style;
int                 x;
int                 y;
int                 l;
int                 h;
int                 align;
int                 RO;
int                 func;
int                 fg;
#endif /* __STDC__ */
{
   int                 ym, yf, xf;
   FILE               *fout;

#  ifdef _WINDOWS 
   if (TtPrinterDC) {
      register int        Y;

      if (align == 1)
         Y = y + (h - thick) / 2;
      else if (align == 2)
           Y = y + h - thick - 1;
      else
          Y = y;

      if (thick > 0)
         DoPrintOneLine (fg, x, Y, x + l - 1, Y);
   } else {
        fout = (FILE *) FrRef[frame];
        if (y < 0)
           return;
        if (thick <= 0)
           return;

        /* Do we need to change the current color ? */
        CurrentColor (fout, fg);

        l--;
        h--;
        xf = PixelToPoint (x + l);
        ym = PixelToPoint (y + h / 2);
        yf = PixelToPoint (y + h);
        x = PixelToPoint (x);
        y = PixelToPoint (y);

        if (align == 0)
           fprintf (fout, "%d -%d %d -%d %d %d %d Seg\n", xf, y, x, y, style, thick, 2);
        else if (align == 1)
             fprintf (fout, "%d -%d %d -%d %d %d %d Seg\n", xf, ym, x, ym, style, thick, 2);
        else
           fprintf (fout, "%d -%d %d -%d %d %d %d Seg\n", xf, yf, x, yf, style, thick, 2);
   }
#  else  /* _WINDOWS */
   fout = (FILE *) FrRef[frame];
   if (y < 0)
      return;
   if (thick <= 0)
      return;

   /* Do we need to change the current color ? */
   CurrentColor (fout, fg);

   l--;
   h--;
   xf = PixelToPoint (x + l);
   ym = PixelToPoint (y + h / 2);
   yf = PixelToPoint (y + h);
   x = PixelToPoint (x);
   y = PixelToPoint (y);

   if (align == 0)
      fprintf (fout, "%d -%d %d -%d %d %d %d Seg\n", xf, y, x, y, style, thick, 2);
   else if (align == 1)
      fprintf (fout, "%d -%d %d -%d %d %d %d Seg\n", xf, ym, x, ym, style, thick, 2);
   else
      fprintf (fout, "%d -%d %d -%d %d %d %d Seg\n", xf, yf, x, yf, style, thick, 2);
#  endif /* _WINDOWS */
}


/*----------------------------------------------------------------------
   DrawVerticalLine draw a vertical line aligned left center or right
   depending on align value.
  ----------------------------------------------------------------------*/
#ifdef __STDC__
void                DrawVerticalLine (int frame, int thick, int style, int x, int y, int l, int h, int align, int RO, int func, int fg)
#else  /* __STDC__ */
void                DrawVerticalLine (frame, thick, style, x, y, l, h, align, RO, func, fg)
int                 frame;
int                 thick;
int                 style;
int                 x;
int                 y;
int                 l;
int                 h;
int                 align;
int                 RO;
int                 func;
int                 fg;
#endif /* __STDC__ */
{
   int                 xm, yf, xf;
   FILE               *fout;

#  ifdef _WINDOWS
   if (TtPrinterDC) {
      register int        X;

      if (align == 1)
         X = x + (l - thick) / 2;
      else if (align == 2)
           X = x + l - thick;
      else
          X = x;

      if (thick > 0)
         DoPrintOneLine (fg, X, y, X, y + h);
   } else {
        if (thick <= 0)
           return;

        fout = (FILE *) FrRef[frame];
        if (y < 0)
           return;
        /* Do we need to change the current color ? */
        CurrentColor (fout, fg);

        l--;
        h--;
        xf = PixelToPoint (x + l);
        xm = PixelToPoint (x + l / 2);
        yf = PixelToPoint (y + h);
        x = PixelToPoint (x);
        y = PixelToPoint (y);

        if (align == 0)
           fprintf (fout, "%d -%d %d -%d %d %d %d Seg\n", x, yf, x, y, style, thick, 2);
        else if (align == 1)
             fprintf (fout, "%d -%d %d -%d %d %d %d Seg\n", xm, yf, xm, y, style, thick, 2);
        else
            fprintf (fout, "%d -%d %d -%d %d %d %d Seg\n", xf, yf, xf, y, style, thick, 2);
   }
#  else  /* _WINDOWS */
   if (thick <= 0)
      return;

   fout = (FILE *) FrRef[frame];
  if (y < 0)
    return;
   /* Do we need to change the current color ? */
   CurrentColor (fout, fg);

   l--;
   h--;
   xf = PixelToPoint (x + l);
   xm = PixelToPoint (x + l / 2);
   yf = PixelToPoint (y + h);
   x = PixelToPoint (x);
   y = PixelToPoint (y);

   if (align == 0)
      fprintf (fout, "%d -%d %d -%d %d %d %d Seg\n", x, yf, x, y, style, thick, 2);
   else if (align == 1)
      fprintf (fout, "%d -%d %d -%d %d %d %d Seg\n", xm, yf, xm, y, style, thick, 2);
   else
      fprintf (fout, "%d -%d %d -%d %d %d %d Seg\n", xf, yf, xf, y, style, thick, 2);
#  endif /* _WINDOWS */
}


/*----------------------------------------------------------------------
   DrawPoints draw a line of dot.
  ----------------------------------------------------------------------*/
#ifdef __STDC__
void                DrawPoints (int frame, int x, int y, int lgboite, int RO, int func, int fg)
#else  /* __STDC__ */
void                DrawPoints (frame, x, y, lgboite, RO, func, fg)
int                 frame;
int                 x;
int                 y;
int                 lgboite;
int                 RO;
int                 func;
int                 fg;
#endif /* __STDC__ */
{
   int                 xcour, ycour;	/*encoding */
   FILE               *fout;
#  ifdef _WINDOWS
   HPEN  hPen, hOldPen;
   POINT ptArray [2];
   int   r, g, b;
#  endif /* _WINDOWS */

   /* Do we need to change the current color ? */
   CurrentColor (fout, fg);
   if (y < 0)
      return;

   if (lgboite > 0) {
#     ifdef _WINDOWS 
      xcour = PixelToPoint (x);
      xcour = (x * 72 + PrinterDPI / 2) / PrinterDPI;
	  xcour = x;
      ycour = PixelToPoint (y);
      ycour = (y * 72 + PrinterDPI / 2) / PrinterDPI;
	  ycour = y;
      if (TtPrinterDC) {
         TtaGiveThotRGB (fg, &r, &g, &b);
         hPen = CreatePen (PS_DOT, 1, RGB (r, g, b));
		 hOldPen = SelectObject (TtPrinterDC, hPen);
         ptArray [0].x = xcour;
         ptArray [0].y = ycour;
         ptArray [1].x = xcour + lgboite;
         /* ptArray [1].x = xcour + PixelToPoint (lgboite); */
         ptArray [1].x = xcour + (lgboite * 72 + PrinterDPI / 2) / PrinterDPI;
         ptArray [1].y = ycour;
		 Polyline (TtPrinterDC, &ptArray, 2);
		 SelectObject (TtPrinterDC, hOldPen);
		 DeleteObject (hPen);
	  } else {
           fout = (FILE *) FrRef[frame];
           xcour = PixelToPoint (x);
           ycour = PixelToPoint (y);

           fprintf (fout, "%d -%d %d Pes\n", xcour, ycour, PixelToPoint (lgboite));
	  }
#     else  /* !_WINDOWS */
      fout = (FILE *) FrRef[frame];
      xcour = PixelToPoint (x);
      ycour = PixelToPoint (y);

      fprintf (fout, "%d -%d %d Pes\n", xcour, ycour, PixelToPoint (lgboite));
#     endif /* WINDIWS */
   }
}


/*----------------------------------------------------------------------
   DrawSlash draw a slash or backslash depending on direction.
  ----------------------------------------------------------------------*/
#ifdef __STDC__
void                DrawSlash (int frame, int thick, int style, int x, int y, int l, int h, int direction, int RO, int func, int fg)
#else  /* __STDC__ */
void                DrawSlash (frame, thick, style, x, y, l, h, direction, RO, func, fg)
int                 frame;
int                 thick;
int                 style;
int                 x;
int                 y;
int                 l;
int                 h;
int                 direction;
int                 RO;
int                 func;
int                 fg;
#endif /* __STDC__ */
{
   int                 xf, yf;
   FILE               *fout;

   fout = (FILE *) FrRef[frame];
  if (y < 0)
    return;
   if (thick <= 0)
      return;

   /* Do we need to change the current color ? */
   CurrentColor (fout, fg);

   l--;
   h--;
   xf = PixelToPoint (x + l);
   yf = PixelToPoint (y + h);
   x = PixelToPoint (x);
   y = PixelToPoint (y);

   if (direction == 0)
      fprintf (fout, "%d -%d %d -%d %d %d %d Seg\n", x, yf, xf, y, style, thick, 2);
   else
      fprintf (fout, "%d -%d %d -%d %d %d %d Seg\n", x, y, xf, yf, style, thick, 2);
}


/*----------------------------------------------------------------------
   StorePageInfo store the page number, width and height of the page,
   used later by DrawPage.
  ----------------------------------------------------------------------*/
#ifdef __STDC__
void                StorePageInfo (int pagenum, int width, int height)
#else  /* __STDC__ */
void                StorePageInfo (pagenum, width, height)
int                 pagenum;
int                 width;
int                 height;
#endif /* __STDC__ */
{
   LastPageNumber = pagenum;
   LastPageWidth = width;
   LastPageHeight = height;
}


/*----------------------------------------------------------------------
   psBoundingBox output the %%BoundingBox macro for Postscript.
  ----------------------------------------------------------------------*/
#ifdef __STDC__
void                psBoundingBox (int frame, int width, int height)
#else  /* __STDC__ */
void                psBoundingBox (frame, width, height)
int                 frame;
int                 width;
int                 height;
#endif /* __STDC__ */
{
   FILE               *fout;

   fout = (FILE *) FrRef[frame];

   /* Since the origin of Postscript coordinates is the lower-left    */
   /* corner of the page, that an A4 page is 2970 mm (i.e 2970*72/254 */
   /* = 841 pts) and that Thot add a 50 pts margin on top and height  */
   /* of the output image, here is the correct values :               */

   fprintf (fout, "%%%%BoundingBox: %d %d %d %d\n",
	    50, 791 - PixelToPoint (height),
	    50 + PixelToPoint (width), 791);
}


/*----------------------------------------------------------------------
   EndOfString check wether string end by suffix.
  ----------------------------------------------------------------------*/
#ifdef __STDC__
int                 EndOfString (char *string, char *suffix)
#else  /* __STDC__ */
int                 EndOfString (string, suffix)
char               *string;
char               *suffix;
#endif /* __STDC__ */
{
   int                 string_lenght, suffix_lenght;

   string_lenght = strlen (string);
   suffix_lenght = strlen (suffix);
   if (string_lenght < suffix_lenght)
      return 0;
   else
      return (strcmp (string + string_lenght - suffix_lenght, suffix) == 0);
}


/*----------------------------------------------------------------------
   PaintWithPattern fill the rectangle associated to a window w (or frame if w= 0)
   located on (x , y) and geometry width x height, using the
   given pattern.
   Parameters fg, bg, and pattern are for drawing
   color, background color and fill pattern.
  ----------------------------------------------------------------------*/
#ifdef __STDC__
void                PaintWithPattern (int frame, int x, int y, int width, int height, ThotWindow w, int RO, int active, int fg, int bg, int pattern)
#else  /* __STDC__ */
void                PaintWithPattern (frame, x, y, width, height, w, RO, active, fg, bg, pattern)
int                 frame;
int                 x;
int                 y;
int                 width;
int                 height;
ThotWindow          w;
int                 RO;
int                 active;
int                 fg;
int                 bg;
int                 pattern;
#endif /* __STDC__ */
{
   int                 xf, yf;
   FILE               *fout;

   fout = (FILE *) FrRef[frame];
  if (y < 0)
    return;
   /* Do we need to change the current color ? */
   CurrentColor (fout, fg);

   if (pattern >= 0)
     {
	xf = PixelToPoint (x + width - 1);
	yf = PixelToPoint (y + height - 1);
	x = PixelToPoint (x);
	y = PixelToPoint (y);
	fprintf (fout, "%d %d -%d %d -%d %d -%d %d -%d trm\n", pattern, x, yf, xf, yf, xf, y, x, y);
     }
}
