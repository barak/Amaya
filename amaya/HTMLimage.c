/*
 *
 *  (c) COPYRIGHT MIT and INRIA, 1996.
 *  Please first read the full copyright statement in file COPYRIGHT.
 *
 */

/*
 * Amaya browser functions called form Thot and declared in HTML.A
 * These functions concern Image elements.
 *
 * Author: I. Vatton
 *
 */

/* Included headerfiles */
#define THOT_EXPORT extern
#include "amaya.h"


#include "init_f.h"
#if !defined(AMAYA_JAVA) && !defined(AMAYA_ILU)
#include "query_f.h"
#endif
#include "AHTURLTools_f.h"
#include "EDITimage_f.h"
#include "HTMLactions_f.h"
#include "HTMLedit_f.h"


/*----------------------------------------------------------------------
   AddLoadedImage adds a new image into image descriptor table.	
   Local images are not stored into this table and the function    
   returns no descriptor and the value FALSE.                      
   If the remote image is new, adds a descriptor for this image    
   notes its local name and returns TRUE.                          
   For already loaded remote images the function returns the      
   descriptor entry and the value FALSE.                           
  ----------------------------------------------------------------------*/
#ifdef __STDC__
boolean             AddLoadedImage (char *name, char *pathname, Document doc, LoadedImageDesc ** desc)
#else  /* __STDC__ */
boolean             AddLoadedImage (name, pathname, doc, desc)
char               *name;
char               *pathname;
Document            doc;
LoadedImageDesc   **desc;

#endif /* __STDC__ */
{
   LoadedImageDesc    *pImage, *previous, *sameImage;
   char*               localname;

   *desc = NULL;
   sameImage = NULL;
   if (pathname == NULL || name == NULL)
      return (FALSE);
   else if (IsHTTPPath (pathname))
     localname = GetLocalPath (doc, pathname);
   else
      /* it is a local image */
      return (FALSE);		/* nothing to do */

   pImage = ImageURLs;
   previous = NULL;
   while (pImage != NULL)
     {
	if (strcmp (pathname, pImage->originalName) == 0)
	  {
	     /* image already loaded */
	     sameImage = pImage;
	     if (pImage->document == doc)
	       {
		  *desc = pImage;
		  return (FALSE);
	       }
	     else
	       {
		  /* see the next descriptor */
		  previous = pImage;
		  pImage = pImage->nextImage;
	       }
	  }
	else
	  {
	     /* see the next descriptor */
	     previous = pImage;
	     pImage = pImage->nextImage;
	  }
     }

   /* It is a new loaded image */
   pImage = (LoadedImageDesc *) TtaGetMemory (sizeof (LoadedImageDesc));
   pImage->originalName = TtaGetMemory (strlen (pathname) + 1);
   strcpy (pImage->originalName, pathname);
   pImage->localName = TtaGetMemory (strlen (localname) + 1);
   strcpy (pImage->localName, localname);
   pImage->prevImage = previous;
   if (previous != NULL)
      previous->nextImage = pImage;
   else
      ImageURLs = pImage;
   pImage->nextImage = NULL;
   pImage->document = doc;
   pImage->elImage = NULL;
   *desc = pImage;
   TtaFreeMemory (localname);
   if (sameImage != NULL)
     {
	/* the image file exist for a different document */
	pImage->status = IMAGE_LOADED;
	TtaFileCopy (sameImage->localName, pImage->localName);
	return (FALSE);
     }
   else
     {
	pImage->status = IMAGE_NOT_LOADED;
	return (TRUE);
     }
}


/*----------------------------------------------------------------------
   SearchLoadedImage searches the image descriptor of a loaded image using
   its local name.
   The function returns the descriptor entry or NULL.
  ----------------------------------------------------------------------*/
#ifdef __STDC__
LoadedImageDesc    *SearchLoadedImage (char *localpath, Document doc)
#else  /* __STDC__ */
LoadedImageDesc    *SearchLoadedImage (localpath, doc)
char               *localpath;
Document            doc;
#endif /* __STDC__ */
{
  LoadedImageDesc    *pImage;
  
  if (localpath == NULL)
    return (NULL);
  else
    {
      pImage = ImageURLs;
      while (pImage != NULL)
	{
	  if (strcmp (localpath, pImage->localName) == 0 && 
	      ((doc == 0) || (pImage->document == doc)))
	    /* image found */
	    return (pImage);
	  else
	    /* see the next descriptor */
	    pImage = pImage->nextImage;
	}
    }
  return (NULL);
}


/*----------------------------------------------------------------------
  ----------------------------------------------------------------------*/
#ifdef __STDC__
void                DisplayImage (Document doc, Element el, char *imageName)
#else  /* __STDC__ */
void                DisplayImage (doc, el, imageName)
Document            doc;
Element             el;
char               *imageName;
#endif /* __STDC__ */
{
  ElementType         elType;
  int                 modified;

  modified = TtaIsDocumentModified (doc);
  elType = TtaGetElementType (el);
  if (elType.ElTypeNum == HTML_EL_PICTURE_UNIT)
    {
      /* display the content of a picture element */
      TtaSetTextContent (el, imageName, SPACE, doc);
      UpdateImageMap (el, doc);
    }
  else
    {
fprintf(stderr,"Background image !\n");
      /* create a background image for the element */
      /* set the value */
    }
  
  /* if the document was not modified before this update reset it unmodified */
  if (!modified)
    TtaSetDocumentUnmodified (doc);
}

/*----------------------------------------------------------------------
   HandleImageLoaded is the callback procedure when the image is loaded	
   		from the web.						
  ----------------------------------------------------------------------*/
#ifdef __STDC__
void                HandleImageLoaded (int doc, int status, char *urlName,
                                     char *outputfile, void * context)
#else  /* __STDC__ */
void                HandleImageLoaded (doc, status, urlName, outputfile, context)
int doc;
int status;
char *urlName;
char *outputfile;
void *context;

#endif /* __STDC__ */
{
   char               *pathname;
   char*               tempfile; /* [MAX_LENGTH]; */
   LoadedImageDesc    *desc = (LoadedImageDesc *) context;
   ElemImage          *ctxEl, *ctxPrev;
   ElementType         elType;

#if defined(AMAYA_JAVA) || defined(AMAYA_ILU)
   FilesLoading[doc]--;
#endif
   if (DocumentURLs[doc] != NULL)
     {
	/* the image could not be loaded */
	if ((status != 200) && (status != 0))
	   return;
    tempfile = (char*) TtaGetMemory (sizeof (char) * MAX_LENGTH);
	/* rename the local file of the image */
	strcpy (tempfile, desc->localName);
	TtaFileUnlink (tempfile);
#   ifndef _WINDOWS
	rename (outputfile, tempfile);
#   else /* _WINDOWS */
	if (rename (outputfile, tempfile) != 0)
		sprintf (tempfile, "%s", outputfile); 
#   endif /* _WINDOWS */

	/* save pathname */
	TtaFreeMemory (desc->originalName);
	pathname = urlName;
	desc->originalName = TtaGetMemory (strlen (pathname) + 1);
	desc->status = IMAGE_LOADED;
	strcpy (desc->originalName, pathname);
	/* display for each elements in the list */
	ctxEl = desc->elImage;
	desc->elImage = NULL;
	while (ctxEl != NULL)
	  {
	    elType = TtaGetElementType (ctxEl->currentElement);
	    if (elType.ElTypeNum == HTML_EL_PICTURE_UNIT)
	      DisplayImage (doc, ctxEl->currentElement, tempfile);
	    else if (ctxEl->callback != NULL)
	      ctxEl->callback(doc, ctxEl->currentElement, tempfile, ctxEl->extra);
	     ctxPrev = ctxEl;
	     ctxEl = ctxEl->nextElement;
	     TtaFreeMemory ((char *) ctxPrev);
	  }
     }
   TtaFreeMemory (tempfile);
}

/*----------------------------------------------------------------------
   libWWWImageLoaded is the libWWW callback procedure when the image
                is loaded from the web.
  ----------------------------------------------------------------------*/
#ifdef __STDC__
void                libWWWImageLoaded (int doc, int status, char *urlName,
                                     char *outputfile, char *content_type,
				       void * context)
#else  /* __STDC__ */
void                libWWWImageLoaded (doc, status, urlName, outputfile, 
				       content_type, context)
int doc;
int status;
char *urlName;
char *outputfile;
char *content_type;
void *context;

#endif /* __STDC__ */
{
  if (DocumentURLs[doc] != NULL)
    {
      /* an image of the document is now loaded */

#if !defined(AMAYA_JAVA) && !defined(AMAYA_ILU)
      /* update the stop button status */
      ResetStop (doc);
#endif /* AMAYA_JAVA */

      /* the image could not be loaded */
      if (status != 0)
	return;

      /* rename the local file of the image */
      HandleImageLoaded (doc, status, urlName,
			 outputfile, context);
     }
}

/*----------------------------------------------------------------------
   GetActiveImageInfo returns the URL information if the current      
   element is an image map and NULL if it is not.          
   The non-null returned string has the form "?X,Y"        
  ----------------------------------------------------------------------*/
#ifdef __STDC__
char               *GetActiveImageInfo (Document document, Element element)
#else  /* __STDC__ */
char               *GetActiveImageInfo (document, element)
Document            document;
Element             element;

#endif /* __STDC__ */
{
   char               *ptr;
   int                 X, Y;

   ptr = NULL;
   if (element != NULL)
     {
       /* initialize X and Y. The user may click in any view. If it's not */
       /* the formatted view (view 1), TtaGiveSelectPosition does not */
       /* change variables X and Y. */
       X = Y = 0;
       /* Get the coordinates of the mouse within the image */
       TtaGiveSelectPosition (document, element, 1, &X, &Y);
       if (X < 0)
	 X = 0;
       if (Y < 0)
	 Y = 0;
       /* create the search string to be appended to the URL */
       ptr = TtaGetMemory (27);
       sprintf (ptr, "?%d,%d", X, Y);
     }
   return ptr;
}

/*----------------------------------------------------------------------
   FetchImage loads an IMG from local file or from the web. The flags
   may indicate extra transfer parameters, for example bypassing the cache.		
  ----------------------------------------------------------------------*/
#ifdef __STDC__
void                FetchImage (Document doc, Element el, char *URL, int flags,
                                LoadedImageCallback callback, void *extra)
#else  /* __STDC__ */
void                FetchImage (doc, el, URL, flags, callback, extra)
Document            doc;
Element             el;
char               *URL;
int                 flags;
LoadedImageCallback callback;
void               *extra;

#endif /* __STDC__ */
{
  int                 length, i;
  char               *imageName;
  AttributeType       attrType;
  Attribute           attr;
  LoadedImageDesc    *desc;
  char*               pathname = (char*) TtaGetMemory (sizeof (char) * MAX_LENGTH);
  char*               tempfile = (char*) TtaGetMemory (sizeof (char) * MAX_LENGTH);
  boolean             update;
  boolean             newImage;
  ElemImage          *ctxEl;

  pathname[0] = EOS;
  tempfile[0] = EOS;
  imageName = NULL;
  attr = NULL;
  if (el != NULL && DocumentURLs[doc] != NULL)
    {
      if (URL == NULL)
	{
	  /* prepare the attribute to be searched */
	  attrType.AttrSSchema = TtaGetDocumentSSchema (doc);
	  attrType.AttrTypeNum = HTML_ATTR_SRC;
	  attr = TtaGetAttribute (el, attrType);
	  if (attr != NULL)
	    /* an element with an attribute SRC has been found */
	    {
	      /* get the attribute value */
	      length = TtaGetTextAttributeLength (attr);
	      if (length > 0)
		{
		  /* allocate some memory: length of name + 6 cars for noname */
		  imageName = TtaGetMemory (length + 7);
		  TtaGiveTextAttributeValue (attr, imageName, &length);
		}
	    }
	}
      else
	imageName = URL;

      if (imageName)
	{
	  update = TRUE;
	  /* add BASE to image name, if necessary */
	  NormalizeURL (imageName, doc, pathname, imageName);
	  /* is the image already loaded ? */
	  newImage = AddLoadedImage (imageName, pathname, doc, &desc);
	  if (newImage)
	    {
	      /* the current element has to be updated when the image 
		 will be loaded */
	      ctxEl = (ElemImage *) TtaGetMemory (sizeof (ElemImage));
	      desc->elImage = ctxEl;
	      ctxEl->currentElement = el;
	      ctxEl->nextElement = NULL;
	      ctxEl->callback = callback;
	      ctxEl->extra = extra;
	      update = FALSE;	/* the image is not loaded yet */
#if defined(AMAYA_JAVA) || defined(AMAYA_ILU)
	      FilesLoading[doc]++;
	      i = GetObjectWWW (doc, pathname, NULL, tempfile,
		                AMAYA_ASYNC | flags, NULL, NULL,
				(void *) libWWWImageLoaded,
				(void *) desc, NO, NULL);
#else /* !AMAYA_JAVA && !AMAYA_ILU */
	      UpdateTransfer(doc);
	      i = GetObjectWWW (doc, pathname, NULL, tempfile,
	                        AMAYA_ASYNC, NULL, NULL,
				(void *) libWWWImageLoaded,
				(void *) desc, NO, NULL);
#endif /* !AMAYA_JAVA && !AMAYA_ILU */
	      if (i != -1) 
		desc->status = IMAGE_LOADED;
	      else
		{
		  update = TRUE;
		  desc->status = IMAGE_NOT_LOADED;
		}
	    }

	  /* display the image within the document */
	  if (update)
	    {
	      if (desc == NULL)
		{
		  /* it is a local image */
		if (callback)
		  {
		    if (!strncmp(pathname, "file:/", 6))
		      callback(doc, el, &pathname[6], extra);
		    else
		      callback(doc, el, &pathname[0], extra);
		  }
		else
		  DisplayImage (doc, el, pathname);
	      }
	      else
		if (TtaFileExist (desc->localName))
		  {
		    /* remote image, but already here */
		    if (callback)
		      callback(doc, el, desc->localName, extra);
		    else
		      DisplayImage (doc, el, desc->localName);
		  }
		else
		  {
		    /* chain this new element as waiting for this image */
		    ctxEl = desc->elImage;
		    if (ctxEl != NULL && ctxEl->currentElement != el)
		      {
			/* concerned elements are different */
			while (ctxEl->nextElement != NULL)
			  ctxEl = ctxEl->nextElement;
			ctxEl->nextElement = (ElemImage *) TtaGetMemory (sizeof (ElemImage));
			ctxEl = ctxEl->nextElement;
			ctxEl->callback = callback;
			ctxEl->extra = extra;
			ctxEl->currentElement = el;
			ctxEl->nextElement = NULL;
		      }
		  }
	    }
	}
      
      if (attr != NULL && imageName)
	TtaFreeMemory (imageName);
    }
  TtaFreeMemory (pathname);
  TtaFreeMemory (tempfile);
  TtaHandlePendingEvents ();
}

/*----------------------------------------------------------------------
   FetchAndDisplayImages   fetch and display all images referred   
   by document doc. The flags may indicate extra transfer parameters,
   for example bypassing the cache.
  ----------------------------------------------------------------------*/
#ifdef __STDC__
void                FetchAndDisplayImages (Document doc, int flags)
#else  /* __STDC__ */
void                FetchAndDisplayImages (doc, flags)
Document            doc;
int                 flags;

#endif /* __STDC__ */
{
   AttributeType       attrType;
   Attribute           attr;
   Element             el, elFound;
   ElementType         elType;

#if defined(AMAYA_JAVA) || defined(AMAYA_ILU)
   if (FilesLoading[doc] == 0)
     {
#else 
   /* JK: verify if StopTransfer was previously called */
   if (DocNetworkStatus[doc] & AMAYA_NET_INACTIVE)
     {
       /* transfer interrupted */
       TtaSetStatus (doc, 1, TtaGetMessage (AMAYA, AM_LOAD_ABORT), NULL);
       DocNetworkStatus[doc] |= AMAYA_NET_ERROR;
#endif  /* AMAYA_JAVA || AMAYA_ILU */
       return;
     }

   /* get the root element */
   el = TtaGetMainRoot (doc);
   /* prepare the type of element to be searched */
   elType = TtaGetElementType (el);
   /* prepare the attribute to be searched */
   attrType.AttrSSchema = elType.ElSSchema;
   attrType.AttrTypeNum = HTML_ATTR_SRC;
#if !defined(AMAYA_JAVA) && !defined(AMAYA_ILU)
   /* We are currently fetching images for this document */
   /* during this time LoadImage has not to stop transfer */
#endif
   /* search all elements having an attribute SRC */
   do
     {
	TtaHandlePendingEvents ();
	/* verify if StopTransfer is called */
#if !defined(AMAYA_JAVA) && !defined(AMAYA_ILU)
	if (DocNetworkStatus[doc] & AMAYA_NET_INACTIVE)
	   return;
#endif
	/* search the next element having an attribute SRC */
	TtaSearchAttribute (attrType, SearchForward, el, &elFound, &attr);
	el = elFound;
	/* FetchImage increments FilesLoading[doc] for each new get request */
	if (el != NULL)
	    FetchImage (doc, el, NULL, flags, NULL, NULL);
     }
   while (el != NULL);

   /* Images fetching is now finished */
}





