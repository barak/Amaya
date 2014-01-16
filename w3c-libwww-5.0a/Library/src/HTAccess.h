/*                                                W3C Reference Library libwww Accessing URLs
                                      ACCESSING URLS
                                             
 */
/*
**      (c) COPYRIGHT MIT 1995.
**      Please first read the full copyright statement in the file COPYRIGH.
*/
/*

   This module is the application interface module to the Request class. It contains a lot
   of methods for loading URLs and also for uploading URLs using PUTor POST, for example.
   You can use the Request class directly but this module makes it easier to use by
   providing a lot of small request functions using the Request class in different ways.
   It contains help functions for accessing documents and for uploading documents to a
   remote server.
   
   This module is implemented by HTAccess.c, and it is a part of the W3C Reference
   Library.
   
 */
#ifndef HTACCESS_H
#define HTACCESS_H

#include "HTReq.h"
#include "HTAnchor.h"
/*

LOAD A DOCUMENT (METHOD = GET)

   URLs can be accesses using a character string, for example "http://www.w3.org" or it
   can be accessed by using the libwww representation of a URL called an Anchor object.
   Note that we call all objects accessible through URLs for _documents_ - this is a
   notion we have inherited from the hypertext world.
   
  Load a Document from Absolute URL
  
   Request a document referencd by an _absolute_ URL. The output from the request is
   passed to the Stream Pipe Manager that figures out where to pump the data. This can for
   example be to the display or to a local file depending on the set of converters
   registered by the application.
   
 */
extern BOOL HTLoadAbsolute (const char * url, HTRequest * request);
/*

  Load a Document from Relative URL
  
   Request a document referenced by a _relative_ URL. The relative URL is made absolute by
   resolving it relative to the address of the '_base_' anchor.
   
 */
extern BOOL HTLoadRelative (const char *        relative,
                            HTParentAnchor *    base,
                            HTRequest *         request);
/*

  Load a Document into Memory
  
   Request a document referred to by the URL and load it into a chunk object. A chunk
   object is a dynamic string so in the end you will have a single memory buffer
   containing the document.
   
 */
extern HTChunk * HTLoadToChunk (const char * url, HTRequest * request);
/*

  Load a Document and Save as a Local File
  
   This function loads a URL and saves the contents in the specifed file. The file should
   not  be open, as the load function both opens and closes the file. If the file already
   exists then it asks the user whether the file should be overwritten or not. the
   contents is saved _ASIS_ - that is - we do not touch the contents of the file!
   
 */
extern BOOL HTLoadToFile (const char * url, HTRequest * request,
                          const char * filename);
/*

  Load a Document and put the Contents into a Stream
  
   Request a document referenced by an absolute URL and sending the data down a stream.
   This stream can be anny stream you like, for eample one from the Stream Interface.
   
 */
extern BOOL HTLoadToStream (const char * url, HTStream * output,
                            HTRequest * request);
/*

  Load a Document using an Anchor
  
   Here the URL is represented by an Anchor object. You can get an anchor object
   representing a URL by passing the URL to the appropriate method in the Anchor class.
   
 */
extern BOOL HTLoadAnchor (HTAnchor * anchor, HTRequest * request);
/*

  Load a Document into Memory using an Anchor
  
   This is the same as HTLoadToChunkbut instead of passing a URL string you pass an anchor
   object. Internally, all URLs are represented as anchors which contains all the
   information we have about the resource.
   
 */
extern HTChunk * HTLoadAnchorToChunk (HTAnchor * anchor, HTRequest * request);
/*

  Recursively Request a Document using Anchors
  
   Same as HTLoadAnchor()but the information in the error stack in the request object is
   kept, so that any error messages in one. This function is almost identical to
   HTLoadAnchor, but it doesn't clear the error stack so that the information in there is
   kept.
   
 */
extern BOOL HTLoadAnchorRecursive (HTAnchor * anchor, HTRequest * request);
/*

LOAD SPECIAL DOCUMENTS

   We also have a set of functions for loading special files like rules files which also
   are referenced by a URL but which do have to be treated specially.
   
  Load a Rule File
  
   Rule files can be loaded just like any other URL but yuou can also just use this
   function which does all the work for you :-) It loads a rule find with the URL
   specified and add the set of rules to the existing set.
   
 */
extern BOOL HTLoadRules (const char * url);
/*

SEARCH A DOCUMENT (METHOD = GET)

   The search methods all use GETas the method in the HTTP request. The functions take the
   keywords and encode them according to RFC 1866 (Hypertext Markup language). That is,
   the query part is separated from the rest of the URL by a "?" nu is treated as being
   part of the URL path.
   
   The keywords are passed to the function as a Chunk Object and each keyword _must_ be
   separated by a space ' '. This will then be converted into a '+' before added to the
   URL.
   
  Search a Document from Absolute URL
  
 */
extern BOOL HTSearchAbsolute (HTChunk *         keywords,
                              const char *      base,
                              HTRequest *       request);
/*

  Search a Document from Relative URL
  
   Search a document referenced by a _relative_ URL. The relative URL is made absolute by
   resolving it relative to the address of the '_base_' anchor.
   
 */
extern BOOL HTSearchRelative (HTChunk *         keywords,
                              const char *      relative,
                              HTParentAnchor *  base,
                              HTRequest *       request);
/*

  Search a Document using an Anchor
  
 */
extern BOOL HTSearchAnchor (HTChunk *           keywords,
                            HTAnchor *          anchor,
                            HTRequest *         request);
/*

  Search a Document using an Anchor Using a String
  
   This works exactly as the HTSearchAnchor()function but takes a C string instead of a
   chunk object.
   
 */
extern BOOL HTSearchString (const char *        keywords,
                            HTAnchor *          anchor,
                            HTRequest *         request);
/*

HANDLE FORMS USING GET METHOD

   Form data can be sent to a HTTP server in two ways - it can either use a GETmethod or
   it can use a POSTmethod. The difference is whether the request "has side effects" or
   not. For example, if you are ordering a pizza then the (hopefully positive) sideeffect
   is that you actually get one delivered. However, if you are issuing search data - for
   example to Alta Vista, then there is no sideeffect. In the former example you would use
   the GETform and in the latter you would use the POSTform.
   
  Send a Form from Absolute URL using GET
  
   Request a GETform referencd by an absolute URL appended with the formdata given. The
   URL can _NOT_ contain any fragment identifier! The list of form data must be given as
   an association list where the name is the field name and the value is the value of the
   field. Enter the fields in the same order as they are setup in the HTML file, the it
   will work.
   
 */
extern BOOL HTGetFormAbsolute (HTAssocList *    formdata,
                               const char *     base,
                               HTRequest *      request);
/*

  Send a Form from Relative URL using GET
  
   Request a GETform referencd by a relative URL appended with the formdata given. The
   list of formdata must be given as an association list where the name is the field name
   and the value is the value of the field.
   
 */
extern BOOL HTGetFormRelative (HTAssocList *    formdata,
                               const char *     relative,
                               HTParentAnchor * base,
                               HTRequest *      request);
/*

  Send a Form using an Anchor and the GET Method
  
   Request a GETform referencd by an anchor object appended with the formdata given. The
   URL can _NOT_ contain any fragment identifier! The list of form data must be given as
   an association list where the name is the field name and the value is the value of the
   field.
   
 */
extern BOOL HTGetFormAnchor (HTAssocList *      formdata,
                             HTAnchor *         anchor,
                             HTRequest *        request);
/*

HANDLE FORMS USING POST METHOD

   The main difference between a GETform and a POSTform is that the data in a POSTform is
   sent as the body part of the HTTP message whereas a GETform wraps it all up into the
   URL. In order to be able to use the POSTdata object at a later point in time, we create
   a new anchor on the fly. This anchor has a URL file location which points into the
   temporary area given by the User Profile Object. That is - you can actually save the
   anchor using a PUTrequest and then be able to retrive the form data at a later point in
   time. Even though this may seem "ambitious" for posting form data, it is really just a
   special example of sending any kind of data to a remote server. All POSTform functions
   return the new anchor or NULLif they fail.
   
  Send a Form from Absolute URL using POST
  
   Request a POSTform referencd by an absolute URL appended with the formdata given. The
   URL can _NOT_ contain any fragment identifier! The list of form data must be given as
   an association list where the name is the field name and the value is the value of the
   field.
   
 */
extern HTParentAnchor * HTPostFormAbsolute (HTAssocList *       formdata,
                                            const char *        base,
                                            HTRequest * request);
/*

  Send a Form from a Relative URL using GET
  
   Request a POSTform referencd by a relative URL appended with the formdata given. The
   URL can _NOT_ contain any fragment identifier! The list of form data must be given as
   an association list where the name is the field name and the value is the value of the
   field.
   
 */
extern HTParentAnchor * HTPostFormRelative (HTAssocList *       formdata,
                                            const char *        relative,
                                            HTParentAnchor *    base,
                                            HTRequest *         request);
/*

  Send a Form using an Anchor and the POST Method
  
   Request a POSTform referencd by an anchor object appended with the formdata given. The
   URL can NOT contain any fragment identifier! The list of form data must be given as an
   association list where the name is the field name and the value is the value of the
   field.
   
 */
extern HTParentAnchor * HTPostFormAnchor (HTAssocList * formdata,
                                          HTAnchor *    anchor,
                                          HTRequest *   request);
/*

GET METAINFORMATION ABOUT A DOCUMENT (METHOD = HEAD)

   If you are not interested in the document itself but only in the _metainformation_ that
   you can get _describing_ the document then you should use the HEADmethod in your
   request.
   
  Get Metainformation about a Document from Absolute URL
  
   Request metainfomration about a document referencd by an _absolute_ URL.
   
 */
extern BOOL HTHeadAbsolute (const char * url, HTRequest * request);
/*

  Get Metainformation about a Document from Relative URL
  
   Request metainformation about a document referenced by a _relative_ URL.
   
 */
extern BOOL HTHeadRelative (const char *        relative,
                            HTParentAnchor *    base,
                            HTRequest *         request);
/*

  Get Metainformation about a Document using an Anchor
  
   Here the URL is represented by an Anchor object. You can get an anchor object
   representing a URL by passing the URL to the approproiate method in the Anchor class.
   
 */
extern BOOL HTHeadAnchor (HTAnchor * anchor, HTRequest * request);
/*

DELETE A DOCUMENT (METHOD = DELETE)

   If you want to delete a document (or make the document inaccessible for future
   references) then you can use the DELETEmethod in your request.
   
  Delete a Document from Absolute URL
  
   Request metainfomration about a document referencd by an _absolute_ URL.
   
 */
extern BOOL HTDeleteAbsolute (const char * url, HTRequest * request);
/*

  Delete a Document from Relative URL
  
   Request metainformation about a document referenced by a _relative_ URL.
   
 */
extern BOOL HTDeleteRelative (const char *      relative,
                            HTParentAnchor *    base,
                            HTRequest *         request);
/*

  Delete a Document using an Anchor
  
   Here the URL is represented by an Anchor object. You can get an anchor object
   representing a URL by passing the URL to the approproiate method in the Anchor class.
   
 */
extern BOOL HTDeleteAnchor (HTAnchor * anchor, HTRequest * request);
/*

SAVE A DOCUMENT ASIS (METHOD = PUT)

   You can upload a document to a remote server using the following methods. The document
   that you want to PUT must be in the form of an anchor. The reason for this is that when
   we are put'ing a document we must have some metainformation available. Metainformation
   can be the media type, the document length, the lamguage, or any other metainformation
   that you can find associated with the Anchor object.
   
   This set of functions takes the contents of the anchor _ASIS_ - that it the _exact_
   content of the document associated with this anchor will be sent to the remote server.
   If your anchor represents a structured content and the document itself is a parse tree,
   for example, then you can use the more flexible structure PUT interface below.
   
   If your application is an Web editor, then you may want to create a new anchor on the
   fly for temporary backups on local disk before you save it to a remote server. An easy
   way to get a new anchor with a local file URL pointing into local file space is by
   using the HTTmpAnchor() function which is part of the WWWApp interface.
   
  Save a Document ASIS from Absolute URL using PUT
  
   Upload a document referenced by an absolute URL. The URL can _NOT_ contain any fragment
   identifier - that is, it must be a parent anchor! The list of form data must be given
   as an association list where the name is the field name and the value is the value of
   the field.
   
 */
extern BOOL HTPutAbsolute (HTParentAnchor *     source,
                           const char *         destination,
                           HTRequest *          request);
/*

  Save a Document ASIS from Relative URL using PUT
  
   Upload a document referenced by a relative URL appended. The URL can _NOT_ contain any
   fragment identifier! The list of form data must be given as an association list where
   the name is the field name and the value is the value of the field.
   
 */
extern BOOL HTPutRelative (HTParentAnchor *     source,
                           const char *         relative,
                           HTParentAnchor *     destination_base,
                           HTRequest *          request);
/*

  Save a Document ASIS Using an Anchor and the PUT Method
  
   Upload a document referenced by an anchor object appended The URL can _NOT_ contain any
   fragment identifier! The list of form data must be given as an association list where
   the name is the field name and the value is the value of the field.
   
 */
extern BOOL HTPutAnchor (HTParentAnchor *       source,
                         HTAnchor *             dest,
                         HTRequest *            request);
/*

SAVE A STRUCTURED DOCUMENT (USING PUT)

   If the content of the document associated with the anchor contains structured
   information and can't be uploaded _ASIS_ then you can use this interface. The only
   difference is that the caller must provide the function that provides data while
   sending it accross the network. You can find several examples in the HTAccess module on
   how to write a data source function. You can for example have a look at the
   HTEntity_callbackfunction which is used in the _ASIS_ interface.
   
  Save a Structured Document to Absolute URL using PUT
  
   Upload a document referenced by an absolute URL appended. The URL can NOT contain any
   fragment identifier! The list of form data must be given as an association list where
   the name is the field name and the value is the value of the field.
   
 */
extern BOOL HTPutStructuredAbsolute (HTParentAnchor *   source,
                                     const char *       destination,
                                     HTRequest *        request,
                                     HTPostCallback *   input);
/*

  Save a Structured Document to Relative URL using PUT
  
   Upload a document referenced by a relative URL appended. The URL can NOT contain any
   fragment identifier! The list of form data must be given as an association list where
   the name is the field name and the value is the value of the field.
   
 */
extern BOOL HTPutStructuredRelative (HTParentAnchor *   source,
                                     const char *       relative,
                                     HTParentAnchor *   destination_base,
                                     HTRequest *        request,
                                     HTPostCallback *   input);
/*

  Save a Structured Document Using an Anchor and the PUT Method
  
   Upload a document referenced by an anchor object appended The URL can NOT contain any
   fragment identifier! The list of form data must be given as an association list where
   the name is the field name and the value is the value of the field. The HTPostCallback
   function type is declared in the HTRequest object.
   
 */
extern BOOL HTPutStructuredAnchor (HTParentAnchor *     source,
                                   HTAnchor *           destination,
                                   HTRequest *          request,
                                   HTPostCallback *     input);
/*

SAVE A DOCUMENT (USING PUT)

   If the content of the document associated with the anchor contains document information
   and can't be uploaded _ASIS_ then you can use this interface. The only difference is
   that the caller must provide the function that provides data while sending it accross
   the network. You can find several examples in the HTAccess module on how to write a
   data source function. You can for example have a look at the HTEntity_callbackfunction
   which is used in the _ASIS_ interface.
   
  Save a Document from Absolute URL using PUT
  
   Upload a document referenced by an absolute URL appended. The URL can NOT contain any
   fragment identifier! The list of form data must be given as an association list where
   the name is the field name and the value is the value of the field.
   
 */
extern BOOL HTPutDocumentAbsolute (HTParentAnchor *     source,
                                   const char *         destination,
                                   HTRequest *          request);
/*

  Save a Document from Relative URL using PUT
  
   Upload a document referenced by a relative URL appended. The URL can NOT contain any
   fragment identifier! The list of form data must be given as an association list where
   the name is the field name and the value is the value of the field.
   
 */
extern BOOL HTPutDocumentRelative (HTParentAnchor *     source,
                                   const char *         relative,
                                   HTParentAnchor *     destination_base,
                                   HTRequest *          request);
/*

  Save a Document Using an Anchor and the PUT Method
  
   Upload a document referenced by an anchor object appended The URL can NOT contain any
   fragment identifier! The list of form data must be given as an association list where
   the name is the field name and the value is the value of the field. The HTPostCallback
   function type is declared in the HTRequest object.
   
 */
extern BOOL HTPutDocumentAnchor (HTParentAnchor *       source,
                                 HTAnchor *             destination,
                                 HTRequest *            request);
/*

SAVE A DOCUMENT ASIS (METHOD = POST)

   You can upload a document to a remote server using the following methods. The document
   that you want to POST must be in the form of an anchor. The reason for this is that
   when we are posting a document we must have some metainformation available.
   Metainformation can be the media type, the document length, the lamguage, or any other
   metainformation that you can find associated with the Anchor object.
   
   This set of functions takes the contents of the anchor _ASIS_ - that it the _exact_
   content of the document associated with this anchor will be sent to the remote server.
   
   If your application is an Web editor, then you may want to create a new anchor on the
   fly for temporary backups on local disk before you save it to a remote server. An easy
   way to get a new anchor with a local file URL pointing into local file space is by
   using the HTTmpAnchor() function which is part of the WWWApp interface.
   
  Save a Document ASIS from Absolute URL using POST
  
   Upload a document referenced by an absolute URL. The URL can _NOT_ contain any fragment
   identifier - that is, it must be a parent anchor! The list of form data must be given
   as an association list where the name is the field name and the value is the value of
   the field.
   
 */
extern BOOL HTPostAbsolute (HTParentAnchor *    source,
                           const char *         destination,
                           HTRequest *          request);
/*

  Save a Document ASIS from Relative URL using POST
  
   Upload a document referenced by a relative URL appended. The URL can _NOT_ contain any
   fragment identifier! The list of form data must be given as an association list where
   the name is the field name and the value is the value of the field.
   
 */
extern BOOL HTPostRelative (HTParentAnchor *    source,
                           const char *         relative,
                           HTParentAnchor *     destination_base,
                           HTRequest *          request);
/*

  Save a Document ASIS Using an Anchor and the POST Method
  
   Upload a document referenced by an anchor object appended The URL can _NOT_ contain any
   fragment identifier! The list of form data must be given as an association list where
   the name is the field name and the value is the value of the field.
   
 */
extern BOOL HTPostAnchor (HTParentAnchor *      source,
                         HTAnchor *             dest,
                         HTRequest *            request);
/*

GET AVAILABLE OPTIONS FOR A DOCUMENT (METHOD = OPTIONS)

   If you want to get information about a document then you can use the the OPTIONSmethod
   in your request. The OPTIONSmethod represents a request for information about the
   communication options available on the request/response chain identified by the
   Request-URI. This method allows the client to determine the options and/or requirements
   associated with a resource, or the capabilities of a server, without implying a
   resource action or initiating a resource retrieval.
   
   A speciality about the OPTIONSmethod is that the client can issue a request with no
   pathinfo at all but only with a "*". That is, the request line can look like this
   "OPTIONS * HTTP/1.1". This means that we request information about the server as a
   whole and not only about a single URL. You can get this effect by using a URL
   containing the hostname alone with _NO_ extra slash at the end, for example
   http://www.w3.org, http://www.cern.ch.
   
  Options Available for Document from Absolute URL
  
   Request options about a document referencd by an _absolute_ URL.
   
 */
extern BOOL HTOptionsAbsolute (const char * url, HTRequest * request);
/*

  Options Available for Document from Relative URL
  
   Request options about a document referenced by a _relative_ URL.
   
 */
extern BOOL HTOptionsRelative (const char *     relative,
                            HTParentAnchor *    base,
                            HTRequest *         request);
/*

  Options Available for Document using an Anchor
  
   Here the URL is represented by an Anchor object. You can get an anchor object
   representing a URL by passing the URL to the appropriate method in the Anchor class.
   
 */
extern BOOL HTOptionsAnchor (HTAnchor * anchor, HTRequest * request);
/*

GET TRACE LOOP BACK INFORMATION FOR A DOCUMENT (METHOD = TRACE)

   The TRACE method is used to invoke a remote, application-layer loop-back of the request
   message. The final recipient of the request SHOULD reflect the message received back to
   the client as the entity-body of a 200 (OK) response. The final recipient is either the
   origin server or the first proxy or gateway to receive a Max-Forwards value of zero (0)
   in the request (see section 14.31). A TRACE request MUST NOT include an entity.
   
   TRACE allows the client to see what is being received at the other end of the request
   chain and use that data for testing or diagnostic information. The value of the Via
   header field (section 14.44) is of particular interest, since it acts as a trace of the
   request chain. Use of the Max-Forwards header field allows the client to limit the
   length of the request chain, which is useful for testing a chain of proxies forwarding
   messages in an infinite loop.
   
   If successful, the response SHOULD contain the entire request message in the
   entity-body, with a Content-Type of "message/http". Responses to this method MUST NOT
   be cached.
   
  Traces Available for Document from Absolute URL
  
   Request traces about a document referencd by an _absolute_ URL.
   
 */
extern BOOL HTTraceAbsolute (const char * url, HTRequest * request);
/*

  Traces Available for Document from Relative URL
  
   Request traces about a document referenced by a _relative_ URL.
   
 */
extern BOOL HTTraceRelative (const char *       relative,
                             HTParentAnchor *   base,
                             HTRequest *        request);
/*

  Traces Available for Document using an Anchor
  
   Here the URL is represented by an Anchor object. You can get an anchor object
   representing a URL by passing the URL to the appropriate method in the Anchor class.
   
 */
extern BOOL HTTraceAnchor (HTAnchor * anchor, HTRequest * request);
/*

SAVE A URL TO MULTIPLE DESTINATIONS

   __Note:_ This is not as stable as the other functions yet!_
   
   These are the generic versions of the PUTand POSTfunctions. They can be used to send
   documents to multiple destinations simultanously using the PostWeb model.
   
  Copy an anchor
  
   Fetch the URL from either local file store _or_ from a remote HTTP server and send it
   using either PUT or POST to the remote destination using HTTP. The caller can decide
   the exact method used and which HTTP header fields to transmit by setting the user
   fields in the request structure. If posting to NNTP then we can't dispatch at this
   level but must pass the source anchor to the news module that then takes all the refs
   to NNTP and puts into the "newsgroups" header Returns YES if request accepted, else NO
   
 */
extern BOOL HTCopyAnchor (HTAnchor * src_anchor, HTRequest * main_req);
/*

  Upload an Anchor
  
   This function can be used to send data along with a request to a remote server. It can
   for example be used to POST form data to a remote HTTP server - or it can be used to
   post a newsletter to a NNTP server. In either case, you pass a callback function which
   the request calls when the remote destination is ready to accept data. In this callback
   you get the current request object and a stream into where you can write data. It is
   very important that you return the value returned by this stream to the Library so that
   it knows what to do next. The reason is that the outgoing stream might block or an
   error may occur and in that case the Library must know about it. If you do not want to
   handle the stream interface yourself then you can use the HTUpload_callbackwhich is
   declared below. The source anchor represents the data object in memory and it points to
   the destination anchor by using the POSTWeb method. The source anchor contains
   metainformation about the data object in memory and the destination anchor represents
   the reponse from the remote server. Returns YES if request accepted, else NO
   
 */
extern BOOL HTUploadAnchor (HTAnchor *          source_anchor,
                            HTRequest *         request,
                            HTPostCallback *    callback);
/*

  POST Callback Handler
  
   Is you do not want to handle the stream interface on your own, you can use this
   "middleman" function which does the actual writing to the target stream for the anchor
   upload and also handles the return value from the stream. Now, your application is
   called via the callback function that you may associate with a request object. You
   indicate when you have sent all the data you want by returning HT_LOADED from the
   callback.
   
 */
extern int HTUpload_callback (HTRequest * request, HTStream * target);
/*

 */
#endif /* HTACCESS_H */
/*

   
   ___________________________________
   
                          @(#) $Id: HTAccess.h,v 1.1.1.1 1996/10/15 13:08:39 cvs Exp $
                                                                                          
    */
