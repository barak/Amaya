/*
 *
 *  (c) COPYRIGHT INRIA, 1996.
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
 *
 * Author: N. Layaida (INRIA)
 *         R. Guetari (W3C/INRIA) Windows 95/NT routines
 */
 
#include "thot_gui.h"
#include "thot_sys.h"
#include "constmedia.h"
#include "jpeglib.h"

#define HAVE_BOOLEAN
#include "typemedia.h"
#include "picture.h"
#include "frame.h"
#include "message.h"
#include "application.h"


#define THOT_EXPORT extern
#include "picture_tv.h"
#include "frame_tv.h"
#include "picture_f.h"
#include "font_f.h"
#include "units_f.h"
#include "gifhandler_f.h"

struct my_error_mgr
  {
     struct jpeg_error_mgr pub;	           /* "public" fields */
     jmp_buf               setjmp_buffer;  /* for return to caller */
  };

typedef struct my_error_mgr *my_error_ptr;

#ifdef _WINDOWS
extern int bgRed;
extern int bgGreen;
extern int bgBlue;
#endif /* _WINDOWS */

#ifdef __STDC__
static void my_error_exit (j_common_ptr cinfo)
#else  /* !__STDC__ */
static void my_error_exit (j_common_ptr cinfo)
#endif /* __STDC__ */
{
    my_error_ptr        myerr = (my_error_ptr) cinfo->err;

#   if 0
    fprintf (stderr, "Error reading JPEG image: ");
    (*cinfo->err->output_message) (cinfo);
#   endif
    longjmp (myerr->setjmp_buffer, 1);
}

struct jpeg_decompress_struct cinfo;
struct my_error_mgr           jerr;

#ifdef _WINDOWS 
extern BOOL pic2print;
#endif /* _WINDOWS */

#include "jinclude.h"


/*----------------------------------------------------------------------
  ----------------------------------------------------------------------*/
#ifdef __STDC__
unsigned char      *ReadJPEG (FILE* infile, int* width, int* height, ThotColorStruct colrs[256])
#else  /* !__STDC__ */
unsigned char      *ReadJPEG (infile, width, height, colrs[256])
FILE*           infile; 
int*            width; 
int*            height; 
ThotColorStruct colrs[256];
#endif /* __STDC__ */
{
   unsigned char      *retBuffer = 0;	/* Output image buffer */
   unsigned char      *r;
   JSAMPROW            buffer[1];	/* row pointer array for read_scanlines */
   int                 row_stride;	/* physical row width in output buffer */
   int                 i;

   /* We set up the normal JPEG error routines, 
      then override error_exit.     */
   cinfo.err = jpeg_std_error (&jerr.pub);
   jerr.pub.error_exit = my_error_exit;

   /* Establish the setjmp return context for my_error_exit to use. */

   if (setjmp (jerr.setjmp_buffer))
     {
	/* If we get here, the JPEG code has signaled an error. */
	jpeg_destroy_decompress (&cinfo);
	fclose (infile);

	if (retBuffer)
	   TtaFreeMemory (retBuffer);
	return 0;
     }

   jpeg_create_decompress (&cinfo);

   jpeg_stdio_src (&cinfo, infile);

   (void) jpeg_read_header (&cinfo, TRUE);

   /* We can ignore the return value from jpeg_read_header since
      *   (a) suspension is not possible with the stdio data source, and
      *   (b) we passed TRUE to reject a tables-only JPEG file as an error.
      * See libjpeg.doc for more info.
    */

   cinfo.quantize_colors = TRUE;
   /*cinfo.desired_number_of_colors = value defined by thot */
   /* Waiting for a good policy *** to be discussed with Vincent  */

   cinfo.desired_number_of_colors = 100;
   cinfo.two_pass_quantize = TRUE;

   jpeg_start_decompress (&cinfo);

   if (!(retBuffer = (unsigned char*) TtaGetMemory (cinfo.output_width
			  * cinfo.output_height * cinfo.output_components)))
     {
	jpeg_destroy_decompress (&cinfo);
	fprintf (stderr, "Couldn't create space for JPEG read\n");
	return (0);
     }

   r = retBuffer;

   row_stride = cinfo.output_width * cinfo.output_components;
   while (cinfo.output_scanline < cinfo.output_height)
     {
	buffer[0] = r;
	(void) jpeg_read_scanlines (&cinfo, buffer, 1);
	r += row_stride;
     }

   *width = cinfo.output_width;
   *height = cinfo.output_height;

   /* Initialize our colormap until a clear policy for the 32-bit screen */

   if (cinfo.out_color_components == 3)
     {
	for (i = 0; i < cinfo.actual_number_of_colors; i++)
	  {
#            ifndef _WINDOWS
	     colrs[i].red = cinfo.colormap[0][i] << 8;
	     colrs[i].green = cinfo.colormap[1][i] << 8;
	     colrs[i].blue = cinfo.colormap[2][i] << 8;
	     colrs[i].pixel = i;
	     colrs[i].flags = DoRed | DoGreen | DoBlue;
#            else /* _WINDOWS */
	     colrs[i].red = cinfo.colormap[0][i];
	     colrs[i].green = cinfo.colormap[1][i];
	     colrs[i].blue = cinfo.colormap[2][i];
#            endif /* _WINDOWS */
	  }
     }
   else
     {
	for (i = 0; i < cinfo.actual_number_of_colors; i++)
	  {
#            ifndef _WINDOWS
	     colrs[i].red = colrs[i].green = colrs[i].blue = cinfo.colormap[0][i] << 8;
	     colrs[i].pixel = i;
	     colrs[i].flags = DoRed | DoGreen | DoBlue;
#            else /* _WINDOWS */
	     colrs[i].red = colrs[i].green = colrs[i].blue = cinfo.colormap[0][i];
#            endif /* _WINDOWS */
	  }
     }


   (void) jpeg_finish_decompress (&cinfo);
   jpeg_destroy_decompress (&cinfo);

   return retBuffer;
}

/*----------------------------------------------------------------------
   ReadJpegToData  Just open the file and pass it to the ReadJpeg     
  ----------------------------------------------------------------------*/
#ifdef __STDC__
unsigned char      *ReadJpegToData (char* datafile, int* w, int* h, ThotColorStruct colrs[256])
#else  /* __STDC__ */
unsigned char      *ReadJpegToData (datafile, w, h, colrs)
char               *datafile;
int                *w;
int                *h;
ThotColorStruct     colrs[256];

#endif /* __STDC__ */
{
   unsigned char      *bit_data;
   FILE               *fp;


   fp = fopen (datafile, "rb");

   if (fp != NULL)
     {
	bit_data = (unsigned char *) ReadJPEG (fp, w, h, colrs);
	if (bit_data != NULL)
	  {
	     if (fp != stdin)
		fclose (fp);
	     return (bit_data);
	  }
	if (fp != stdin)
	   fclose (fp);
     }
   return ((unsigned char *) NULL);
}

/*----------------------------------------------------------------------
  ----------------------------------------------------------------------*/
#ifdef __STDC__
void                JpegPrintErrorMsg (int ErrorNumber)
#else  /* __STDC__ */
void                JpegPrintErrorMsg (ErrorNumber)
int                 ErrorNumber;

#endif /* __STDC__ */
{
}


/*----------------------------------------------------------------------
  ----------------------------------------------------------------------*/
#ifdef __STDC__
ThotBitmap          JpegCreate (char *fn, PictureScaling pres, int *xif, int *yif, int *wif, int *hif, unsigned long BackGroundPixel, ThotBitmap *mask1, int *width, int *height, int zoom)
#else  /* __STDC__ */
ThotBitmap          JpegCreate (fn, pres, xif, yif, wif, hif, BackGroundPixel, mask1, width, height, zoom)
char               *fn;
PictureScaling      pres;
int                *xif;
int                *yif;
int                *wif;
int                *hif;
unsigned long       BackGroundPixel;
ThotBitmap         *mask1;
int                *width;
int                *height;
int                 zoom;
#endif /* __STDC__ */
{
  int                 w, h;
  Pixmap              pixmap;
  ThotColorStruct     colrs[256];
  unsigned char      *buffer,*buffer2;

# ifdef _WINDOWS
  bgRed   = -1;
  bgGreen = -1;
  bgBlue  = -1;
# endif /* _WINDOWS */

  /* effective load of the Picture from Jpeg Library */
  buffer = ReadJpegToData (fn, &w, &h, colrs);
  /* return image dimensions */
  *width = w;
  *height = h;
  if (!buffer)
    return (ThotBitmapNone);

  if (zoom != 0 && *xif == 0 && *yif == 0)
    {
      /* take zoom into account */
      *xif = PixelValue (w, UnPixel, NULL, zoom);
      *yif = PixelValue (h, UnPixel, NULL, zoom);
    }
  else
    {
      if (*xif == 0 && *yif != 0)
	*xif = PixelValue (w, UnPixel, NULL, zoom);
      if (*xif != 0 && *yif == 0)
	*yif = PixelValue (h, UnPixel, NULL, zoom);
    }

  if ((*xif != 0 && *yif != 0) && (w != *xif || h != *yif))
    {   
      /* xif and yif contain width and height of the box */
      buffer2 = ZoomPicture (buffer, w , h, *xif, *yif, 1);
      TtaFreeMemory (buffer);
      buffer = buffer2;
      buffer2 = NULL;
      w = *xif;
      h = *yif;
    }
  
  if (buffer == NULL)
    return (ThotBitmapNone);	

  pixmap = DataToPixmap (buffer, w, h, 100, colrs);
  TtaFreeMemory (buffer);  
  if (pixmap == None)
    return (ThotBitmapNone);
  else
    {
      *wif = w;
      *hif = h;
      *xif = 0;
      *yif = 0;
      return ((ThotBitmap) pixmap);
    }
}


/*----------------------------------------------------------------------
   JpegPrint produces postscript from a jpeg picture file          
  ----------------------------------------------------------------------*/
#ifdef __STDC__
void                JpegPrint (char *fn, PictureScaling pres, int xif, int yif, int wif, int hif, int PicXArea, int PicYArea, int PicWArea, int PicHArea, int fd, unsigned long BackGroundPixel)
#else  /* __STDC__ */
void                JpegPrint (fn, pres, xif, yif, wif, hif, PicXArea, PicYArea, PicWArea, PicHArea, fd, BackGroundPixel)
char               *fn;
PictureScaling      pres;
int                 xif;
int                 yif;
int                 wif;
int                 hif;
int                 PicXArea;
int                 PicYArea;
int                 PicWArea;
int                 PicHArea;
int                 fd;
unsigned long       BackGroundPixel;

#endif /* __STDC__ */
{
   int                 delta;
   int                 xtmp, ytmp;
   unsigned char      *pt;
   int                 x, y, w, h;
   int                 wim;
   unsigned int        NbCharPerLine;

   ThotColorStruct     colrs[256];
   unsigned char      *buffer;


   buffer = ReadJpegToData (fn, &w, &h, colrs);


   if (!buffer)
     {
	/* feed the editor with the appropriate message */
	return;
     }

   PicWArea = w;
   PicHArea = h;

   xtmp = 0;
   ytmp = 0;

   switch (pres)
     {
     case RealSize:
     case FillFrame:
     case XRepeat:
     case YRepeat:
       delta = (wif - PicWArea) / 2;
       if (delta > 0)
	 {
	   xif += delta;
	   wif = PicWArea;
	 }
       else
	 {
	   xtmp = -delta;
	   PicWArea = wif;
	 }
       delta = (hif - PicHArea) / 2;
       if (delta > 0)
	 {
	   yif += delta;
	   hif = PicHArea;
	 }
       else
	 {
	   
	   ytmp = -delta;
	   PicHArea = hif;
	 }
       fprintf ((FILE *) fd, "gsave %d -%d translate\n", PixelToPoint (xif), PixelToPoint (yif + hif));
       fprintf ((FILE *)fd, "%d %d %d %d DumpImage2\n", PicWArea, PicHArea, PixelToPoint (wif), PixelToPoint (hif));
       break;
     case ReScale:
       fprintf ((FILE *)fd, "gsave %d -%d translate\n", PixelToPoint (xif), PixelToPoint (yif + hif));
       fprintf ((FILE *)fd, "%d %d %d %d DumpImage2\n", PicWArea, PicHArea, PixelToPoint (wif), PixelToPoint (hif));
       wif = PicWArea;
       hif = PicHArea;
       break;
     default:
       break;
     }

   wim = w;
   fprintf ((FILE *) fd, "\n");
   NbCharPerLine = wim;

   for (y = 0; y < hif; y++)
     {
	pt = (unsigned char *) (buffer + ((ytmp + y) * NbCharPerLine) + xtmp);

	for (x = 0; x < wif; x++)
	  {


	     fprintf ((FILE *) fd, "%02x%02x%02x",
		      (colrs[*pt].red) >> 8,
		      (colrs[*pt].green) >> 8,
		      (colrs[*pt].blue) >> 8);
	     pt++;
	  }
	fprintf ((FILE *) fd, "\n");
     }

   fprintf ((FILE *) fd, "\n");
   fprintf ((FILE *) fd, "grestore\n");
   fprintf ((FILE *) fd, "\n");
   free (buffer);

}


/*----------------------------------------------------------------------
   IsJpegFormat checks if the file header conforms the jpeg one    
  ----------------------------------------------------------------------*/
#ifdef __STDC__
boolean             IsJpegFormat (char *fn)
#else  /* __STDC__ */
boolean             IsJpegFormat (fn)
char               *fn;

#endif /* __STDC__ */
{ 
   /*JSAMPROW buffer[1]; *//* row pointer array for read_scanlines */
   FILE               *fd;

   if ((fd = fopen (fn, "rb")) == NULL)
     {
	fprintf (stderr, "can't open %s\n", fn);
	return FALSE;
     }

   /* We set up the normal JPEG error routines, 
      then override error_exit.     */
   cinfo.err = jpeg_std_error (&jerr.pub);
   jerr.pub.error_exit = my_error_exit;

   /* Establish the setjmp return context for my_error_exit to use. */

   if (setjmp (jerr.setjmp_buffer))
     {
	/* If we get here, the JPEG code has signaled an error. */
	jpeg_destroy_decompress (&cinfo);
	fclose (fd);
	return FALSE;
     }

   jpeg_create_decompress (&cinfo);

   jpeg_stdio_src (&cinfo, fd);

   (void) jpeg_read_header (&cinfo, TRUE);
   jpeg_destroy_decompress (&cinfo);
   fclose (fd);

   return TRUE;
}
