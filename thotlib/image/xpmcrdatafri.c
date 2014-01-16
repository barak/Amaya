
/*
 * Copyright (C) 1989-94 GROUPE BULL
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * GROUPE BULL BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN
 * AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * Except as contained in this notice, the name of GROUPE BULL shall not be
 * used in advertising or otherwise to promote the sale, use or other dealings
 * in this Software without prior written authorization from GROUPE BULL.
 */

/*
 * Warning:
 * This module is part of the Thot library, which was originally
 * developed in French. That's why some comments are still in
 * French, but their translation is in progress and the full module
 * will be available in English in the next release.
 * 
 */

/*****************************************************************************\
* XpmCrDataFI.c:                                                              *
*                                                                             *
*  XPM library                                                                *
*  Scan an image and possibly its PicMask and create an XPM array                *
*                                                                             *
*  Developed by Arnaud Le Hors                                                *
\*****************************************************************************/

#include "thot_gui.h"
#include "thot_sys.h"

#include "xpmP.h"

LFUNC (CreateColors, int, (char **dataptr, unsigned int *data_size,
			   XpmColor * colors, unsigned int ncolors,
			   unsigned int cpp));

LFUNC (CreatePixels, void, (char **dataptr, unsigned int width,
			    unsigned int height, unsigned int cpp,
			    unsigned int *pixels, XpmColor * colors));

LFUNC (CountExtensions, void, (XpmExtension * ext, unsigned int num,
			       unsigned int *ext_size,
			       unsigned int *ext_nlines));

LFUNC (CreateExtensions, void, (char **dataptr, unsigned int offset,
				XpmExtension * ext, unsigned int num,
				unsigned int ext_nlines));

#ifdef __STDC__
int
                    XpmCreateDataFromImage (Display * display, char ***data_return, XImage * image, XImage * shapeimage, XpmAttributes * attributes)

#else  /* __STDC__ */
int
                    XpmCreateDataFromImage (display, data_return, image, shapeimage, attributes)
Display            *display;
char             ***data_return;
XImage             *image;
XImage             *shapeimage;
XpmAttributes      *attributes;

#endif /* __STDC__ */

{
   XpmImage            xpmimage;
   XpmInfo             info;
   int                 ErrorStatus;

   /* initialize return value */
   if (data_return)
      *data_return = NULL;

   /* create an XpmImage from the image */
   ErrorStatus = XpmCreateXpmImageFromImage (display, image, shapeimage,
					     &xpmimage, attributes);
   if (ErrorStatus != XpmSuccess)
      return (ErrorStatus);

   /* create the data from the XpmImage */
   if (attributes)
     {
	xpmSetInfo (&info, attributes);
	ErrorStatus = XpmCreateDataFromXpmImage (data_return, &xpmimage, &info);
     }
   else
      ErrorStatus = XpmCreateDataFromXpmImage (data_return, &xpmimage, NULL);

   /* free the XpmImage */
   XpmFreeXpmImage (&xpmimage);

   return (ErrorStatus);
}
#undef RETURN
#define RETURN(status) \
{ \
    if (header) { \
	for (l = 0; l < header_nlines; l++) \
	    if (header[l]) \
		XpmFree(header[l]); \
		XpmFree(header); \
    } \
    return(status); \
}
#ifdef __STDC__
int
                    XpmCreateDataFromXpmImage (char ***data_return, XpmImage * image, XpmInfo * info)

#else  /* __STDC__ */
int
                    XpmCreateDataFromXpmImage (data_return, image, info)
char             ***data_return;
XpmImage           *image;
XpmInfo            *info;

#endif /* __STDC__ */

{
   /* calculation variables */
   int                 ErrorStatus;
   char                buf[BUFSIZ];
   char              **header = NULL, **data, **sptr, **sptr2, *s;
   unsigned int        header_size, header_nlines;
   unsigned int        data_size, data_nlines;
   unsigned int        extensions = 0, ext_size = 0, ext_nlines = 0;
   unsigned int        offset, l, n;

   *data_return = NULL;

   extensions = info && (info->valuemask & XpmExtensions)
      && info->nextensions;

   /* compute the number of extensions lines and size */
   if (extensions)
      CountExtensions (info->extensions, info->nextensions,
		       &ext_size, &ext_nlines);

   /*
    * alloc a temporary array of char pointer for the header section which
    * is the hints line + the color table lines
    */
   header_nlines = 1 + image->ncolors;
   header_size = sizeof (char *) * header_nlines;
   header = (char **) XpmCalloc (header_size, sizeof (char *));

   if (!header)
      return (XpmNoMemory);

   /* print the hints line */
   s = buf;
   sprintf (s, "%d %d %d %d", image->width, image->height,
	    image->ncolors, image->cpp);
   s += strlen (s);

   if (info && (info->valuemask & XpmHotspot))
     {
	sprintf (s, " %d %d", info->x_hotspot, info->y_hotspot);
	s += strlen (s);
     }
   if (extensions)
      sprintf (s, " XPMEXT");

   l = strlen (buf) + 1;
   *header = (char *) XpmMalloc (l);
   if (!*header)
      RETURN (XpmNoMemory);
   header_size += l;
   strcpy (*header, buf);

   /* print colors */
   ErrorStatus = CreateColors (header + 1, &header_size,
			     image->colorTable, image->ncolors, image->cpp);

   if (ErrorStatus != XpmSuccess)
      RETURN (ErrorStatus);

   /* now we know the size needed, alloc the data and copy the header lines */
   offset = image->width * image->cpp + 1;
   data_size = header_size + (image->height + ext_nlines) * sizeof (char *)
   +                   image->height * offset + ext_size;

   data = (char **) XpmMalloc (data_size);
   if (!data)
      RETURN (XpmNoMemory);

   data_nlines = header_nlines + image->height + ext_nlines;
   *data = (char *) (data + data_nlines);
   n = image->ncolors;
   for (l = 0, sptr = data, sptr2 = header; l <= n; l++, sptr++, sptr2++)
     {
	strcpy (*sptr, *sptr2);
	*(sptr + 1) = *sptr + strlen (*sptr2) + 1;
     }

   /* print pixels */
   data[header_nlines] = (char *) data + header_size
      + (image->height + ext_nlines) * sizeof (char *);

   CreatePixels (data + header_nlines, image->width, image->height,
		 image->cpp, image->data, image->colorTable);

   /* print extensions */
   if (extensions)
      CreateExtensions (data + header_nlines + image->height - 1, offset,
			info->extensions, info->nextensions,
			ext_nlines);

   *data_return = data;

   RETURN (XpmSuccess);
}

#ifdef __STDC__
static int
                    CreateColors (char **dataptr, unsigned int *data_size, XpmColor * colors, unsigned int ncolors, unsigned int cpp)

#else  /* __STDC__ */
static int
                    CreateColors (dataptr, data_size, colors, ncolors, cpp)
char              **dataptr;
unsigned int       *data_size;
XpmColor           *colors;
unsigned int        ncolors;
unsigned int        cpp;

#endif /* __STDC__ */

{
   char                buf[BUFSIZ];
   unsigned int        a, key, l;
   char               *s, *s2;
   char              **defaults;

   for (a = 0; a < ncolors; a++, colors++, dataptr++)
     {

	defaults = (char **) colors;
	strncpy (buf, *defaults++, cpp);
	s = buf + cpp;

	for (key = 1; key <= NKEYS; key++, defaults++)
	  {
	     if ((s2 = *defaults))
	       {
		  sprintf (s, "\t%s %s", xpmColorKeys[key - 1], s2);
		  s += strlen (s);
	       }
	  }
	l = strlen (buf) + 1;
	s = (char *) XpmMalloc (l);
	if (!s)
	   return (XpmNoMemory);
	*data_size += l;
	strcpy (s, buf);
	*dataptr = s;
     }
   return (XpmSuccess);
}

#ifdef __STDC__
static void
                    CreatePixels (char **dataptr, unsigned int width, unsigned int height, unsigned int cpp, unsigned int *pixels, XpmColor * colors)

#else  /* __STDC__ */
static void
                    CreatePixels (dataptr, width, height, cpp, pixels, colors)
char              **dataptr;
unsigned int        width;
unsigned int        height;
unsigned int        cpp;
unsigned int       *pixels;
XpmColor           *colors;

#endif /* __STDC__ */

{
   char               *s;
   unsigned int        x, y, h, offset;

   h = height - 1;
   offset = width * cpp + 1;
   for (y = 0; y < h; y++, dataptr++)
     {
	s = *dataptr;
	for (x = 0; x < width; x++, pixels++)
	  {
	     strncpy (s, colors[*pixels].string, cpp);
	     s += cpp;
	  }
	*s = '\0';
	*(dataptr + 1) = *dataptr + offset;
     }
   /* duplicate some code to avoid a test in the loop */
   s = *dataptr;
   for (x = 0; x < width; x++, pixels++)
     {
	strncpy (s, colors[*pixels].string, cpp);
	s += cpp;
     }
   *s = '\0';
}

#ifdef __STDC__
static void
                    CountExtensions (XpmExtension * ext, unsigned int num, unsigned int *ext_size, unsigned int *ext_nlines)

#else  /* __STDC__ */
static void
                    CountExtensions (ext, num, ext_size, ext_nlines)
XpmExtension       *ext;
unsigned int        num;
unsigned int       *ext_size;
unsigned int       *ext_nlines;

#endif /* __STDC__ */

{
   unsigned int        x, y, a, size, nlines;
   char              **line;

   size = 0;
   nlines = 0;
   for (x = 0; x < num; x++, ext++)
     {
	/* 1 for the name */
	nlines += ext->nlines + 1;
	/* 8 = 7 (for "XPMEXT ") + 1 (for 0) */
	size += strlen (ext->name) + 8;
	a = ext->nlines;
	for (y = 0, line = ext->lines; y < a; y++, line++)
	   size += strlen (*line) + 1;
     }
   /* 10 and 1 are for the ending "XPMENDEXT" */
   *ext_size = size + 10;
   *ext_nlines = nlines + 1;
}

#ifdef __STDC__
static void
                    CreateExtensions (char **dataptr, unsigned int offset, XpmExtension * ext, unsigned int num, unsigned int ext_nlines)

#else  /* __STDC__ */
static void
                    CreateExtensions (dataptr, offset, ext, num, ext_nlines)
char              **dataptr;
unsigned int        offset;
XpmExtension       *ext;
unsigned int        num;
unsigned int        ext_nlines;

#endif /* __STDC__ */

{
   unsigned int        x, y, a, b;
   char              **line;

   *(dataptr + 1) = *dataptr + offset;
   dataptr++;
   a = 0;
   for (x = 0; x < num; x++, ext++)
     {
	sprintf (*dataptr, "XPMEXT %s", ext->name);
	a++;
	if (a < ext_nlines)
	   *(dataptr + 1) = *dataptr + strlen (ext->name) + 8;
	dataptr++;
	b = ext->nlines;
	for (y = 0, line = ext->lines; y < b; y++, line++)
	  {
	     strcpy (*dataptr, *line);
	     a++;
	     if (a < ext_nlines)
		*(dataptr + 1) = *dataptr + strlen (*line) + 1;
	     dataptr++;
	  }
     }
   strcpy (*dataptr, "XPMENDEXT");
}