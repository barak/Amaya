/* -*- Mode: c; c-basic-offset: 2 -*-
 *
 * raptor_qname.c - Raptor XML qname class
 *
 * $Id: raptor_qname.c,v 1.1.1.1 2005/07/06 09:38:37 gully Exp $
 *
 * Copyright (C) 2002 David Beckett - http://purl.org/net/dajobe/
 * Institute for Learning and Research Technology - http://www.ilrt.org/
 * University of Bristol - http://www.bristol.ac.uk/
 * 
 * This package is Free Software or Open Source available under the
 * following licenses (these are alternatives):
 *   1. GNU Lesser General Public License (LGPL)
 *   2. GNU General Public License (GPL)
 *   3. Mozilla Public License (MPL)
 * 
 * See LICENSE.html or LICENSE.txt at the top of this package for the
 * full license terms.
 * 
 */


#ifdef HAVE_CONFIG_H
#include <raptor_config.h>
#endif

#ifdef WIN32
#include <win32_config.h>
#endif


#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdarg.h>
#ifdef HAVE_ERRNO_H
#include <errno.h>
#endif
#ifdef HAVE_STDLIB_H
#include <stdlib.h>
#endif

/* Raptor includes */
#include "raptor.h"
#include "raptor_internal.h"


/*
 * Namespaces in XML
 * http://www.w3.org/TR/1999/REC-xml-names-19990114/#defaulting
 * says:
 *
 * --------------------------------------------------------------------
 *  5.2 Namespace Defaulting
 *
 *  A default namespace is considered to apply to the element where it
 *  is declared (if that element has no namespace prefix), and to all
 *  elements with no prefix within the content of that element. 
 *
 *  If the URI reference in a default namespace declaration is empty,
 *  then unprefixed elements in the scope of the declaration are not
 *  considered to be in any namespace.
 *
 *  Note that default namespaces do not apply directly to attributes.
 *
 * [...]
 *
 *  5.3 Uniqueness of Attributes
 *
 *  In XML documents conforming to this specification, no tag may
 *  contain two attributes which:
 *
 *    1. have identical names, or 
 *
 *    2. have qualified names with the same local part and with
 *    prefixes which have been bound to namespace names that are
 *    identical.
 * --------------------------------------------------------------------
 */

/**
 * raptor_new_qname - Create a new XML qname
 * @nstack: namespace stack to look up for namespaces
 * @name: element or attribute name
 * @value: attribute value (else is an element)
 * @error_handler: function to call on an error
 * @error_data: user data for error function
 * 
 * Create a new qname from the local element/attribute name,
 * with optional (attribute) value.  The namespace stack is used
 * to look up the name and find the namespace and generate the
 * URI of the qname.
 * 
 * Return value: a new &raptor_qname object or NULL on failure
 **/
raptor_qname*
raptor_new_qname(raptor_namespace_stack *nstack, 
                 const unsigned char *name,
                 const unsigned char *value,
                 raptor_simple_message_handler error_handler,
                 void *error_data)
{
  raptor_qname* qname;
  const unsigned char *p;
  raptor_namespace* ns;
  unsigned char* new_name;
  int prefix_length;
  int local_name_length=0;

#if RAPTOR_DEBUG > 1
  RAPTOR_DEBUG2("name %s\n", name);
#endif  

  qname=(raptor_qname*)RAPTOR_CALLOC(raptor_qname, sizeof(raptor_qname), 1);
  if(!qname)
    return NULL;


  if(value) {
    int value_length=strlen((char*)value);
    unsigned char* new_value=(unsigned char*)RAPTOR_MALLOC(cstring, value_length+1);

    if(!new_value) {
      RAPTOR_FREE(raptor_qname, qname);
      return NULL;
    } 
    strcpy((char*)new_value, (char*)value);
    qname->value=new_value;
    qname->value_length=value_length;
  }


  /* Find : */
  for(p=name; *p && *p != ':'; p++)
    ;


  if(!*p) {
    local_name_length=p-name;

    /* No : in the name */
    new_name=(unsigned char*)RAPTOR_MALLOC(cstring, local_name_length+1);
    if(!new_name) {
      raptor_free_qname(qname);
      return NULL;
    }
    strcpy((char*)new_name, (char*)name);
    qname->local_name=new_name;
    qname->local_name_length=local_name_length;

    /* For elements only, pick up the default namespace if there is one */
    if(!value) {
      ns=raptor_namespaces_get_default_namespace(nstack);
      
      if(ns) {
        qname->nspace=ns;
#if RAPTOR_DEBUG > 1
        RAPTOR_DEBUG2("Found default namespace %s\n", ns->uri);
#endif
      } else {
#if RAPTOR_DEBUG > 1
        RAPTOR_DEBUG1("No default namespace defined\n");
#endif
      }
    } /* if is_element */

  } else {
    /* There is a namespace prefix */

    prefix_length=p-name;
    p++; 

    /* p now is at start of local_name */
    local_name_length=strlen((char*)p);
    new_name=(unsigned char*)RAPTOR_MALLOC(cstring, local_name_length+1);
    if(!new_name) {
      raptor_free_qname(qname);
      return NULL;
    }
    strcpy((char*)new_name, (char*)p);
    qname->local_name=new_name;
    qname->local_name_length=local_name_length;

    /* Find the namespace */
    ns=raptor_namespaces_find_namespace(nstack, name, prefix_length);

    if(!ns) {
      /* failed to find namespace - now what? */
      if(error_handler)
        error_handler((raptor_parser*)error_data, "The namespace prefix in \"%s\" was not declared.", name);
    } else {
#if RAPTOR_DEBUG > 1
      RAPTOR_DEBUG3("Found namespace prefix %s URI %s\n", ns->prefix, ns->uri);
#endif
      qname->nspace=ns;
    }
  }



  /* If namespace has a URI and a local_name is defined, create the URI
   * for this element 
   */
  if(qname->nspace && local_name_length) {
    raptor_uri *uri=raptor_namespace_get_uri(qname->nspace);
    if(uri)
      uri=raptor_new_uri_from_uri_local_name(uri, new_name);

    qname->uri=uri;
  }


  return qname;
}


/**
 * raptor_new_qname_from_namespace_local_name - Create a new XML qname
 * @ns: namespace of qname
 * @local_name: element or attribute name
 * @value: attribute value (else is an element)
 * 
 * Create a new qname from the namespace and local element/attribute name,
 * with optional (attribute) value.
 * 
 * Return value: a new &raptor_qname object or NULL on failure
 **/
raptor_qname*
raptor_new_qname_from_namespace_local_name(raptor_namespace *ns, 
                                           const unsigned char *local_name,
                                           const unsigned char *value)
{
  raptor_qname* qname;
  unsigned char* new_name;
  int local_name_length=strlen((char*)local_name);

  if(!ns || !local_name)
    return NULL;

  qname=(raptor_qname*)RAPTOR_CALLOC(raptor_qname, sizeof(raptor_qname), 1);
  if(!qname)
    return NULL;

  if(value) {
    int value_length=strlen((char*)value);
    unsigned char* new_value=(unsigned char*)RAPTOR_MALLOC(cstring, value_length+1);

    if(!new_value) {
      RAPTOR_FREE(raptor_qname, qname);
      return NULL;
    } 
    strcpy((char*)new_value, (char*)value);
    qname->value=new_value;
    qname->value_length=value_length;
  }

  new_name=(unsigned char*)RAPTOR_MALLOC(cstring, local_name_length+1);
  if(!new_name) {
    raptor_free_qname(qname);
    return NULL;
  }
  strcpy((char*)new_name, (char*)local_name);
  qname->local_name=new_name;
  qname->local_name_length=local_name_length;

  qname->nspace=ns;

  qname->uri=raptor_namespace_get_uri(qname->nspace);
  if(qname->uri)
    qname->uri=raptor_new_uri_from_uri_local_name(qname->uri, new_name);
  
  return qname;
}


#ifdef RAPTOR_DEBUG
void
raptor_qname_print(FILE *stream, raptor_qname* name) 
{
  if(name->nspace) {
    const unsigned char *prefix=raptor_namespace_get_prefix(name->nspace);
    if(prefix)
      fprintf(stream, "%s:%s", prefix, name->local_name);
    else
      fprintf(stream, "(default):%s", name->local_name);
  } else
    fputs((char*)name->local_name, stream);
}
#endif

void
raptor_free_qname(raptor_qname* name) 
{
  if(name->local_name)
    RAPTOR_FREE(cstring, (void*)name->local_name);

  if(name->uri)
    raptor_free_uri(name->uri);

  if(name->value)
    RAPTOR_FREE(cstring, (void*)name->value);
  RAPTOR_FREE(raptor_qname, name);
}


int
raptor_qname_equal(raptor_qname *name1, raptor_qname *name2)
{
  if(name1->nspace != name2->nspace)
    return 0;
  if(name1->local_name_length != name2->local_name_length)
    return 0;
  if(strcmp((char*)name1->local_name, (char*)name2->local_name))
    return 0;
  return 1;
}



/**
 * raptor_qname_string_to_uri - get the URI for a qname
 * @nstack: &raptor_namespace_stack to decode the namespace
 * @name: QName string or NULL
 * @name_len: QName string length
 * @error_handler: function to call on an error
 * @error_data: user data for error function
 * 
 * Utility function to turn a string representing a QName in the
 * N3 style, into a new URI representing it.  A NULL name or name ":"
 * returns the default namespace URI.  A name "p:" returns
 * namespace name (URI) for the namespace with prefix "p".
 * 
 * Partially equivalent to 
 *   qname=raptor_new_qname(nstack, name, NULL, error_handler, error_data);
 *   uri=raptor_uri_copy(qname->uri);
 *   raptor_free_qname(qname)
 * but without making the qname, and it also handles the NULL and
 * ":" name cases as well as error checking.
 *
 * Return value: new &raptor_uri object or NULL on failure
 **/
raptor_uri*
raptor_qname_string_to_uri(raptor_namespace_stack *nstack, 
                           const unsigned char *name, size_t name_len,
                           raptor_simple_message_handler error_handler,
                           void *error_data)
{
  raptor_uri *uri=NULL;
  const unsigned char *p;
  const unsigned char *original_name=name;
  const unsigned char *local_name=NULL;
  int local_name_length=0;
  raptor_namespace* ns;

  /* Empty string is default namespace URI */
  if(!name) {
    ns=raptor_namespaces_get_default_namespace(nstack);
  } else {
    /* If starts with :, it is relative to default namespace, so skip it */
    if(*name == ':') {
      name++;
      name_len--;
    }
    
    for(p=name; *p && *p != ':'; p++)
      ;
    
    /* If ends with :, it is the URI of a namespace */
    if(p-name == (int)(name_len-1)) {
      ns=raptor_namespaces_find_namespace(nstack, name, name_len-1);
    } else {
      if(!*p) {
        local_name=name;
        local_name_length=p-name;
        
        /* pick up the default namespace if there is one */
        ns=raptor_namespaces_get_default_namespace(nstack);
      } else {
        /* There is a namespace prefix */
        int prefix_length=p-name;
        p++;

        local_name=p;
        local_name_length=strlen((char*)p);
        
        /* Find the namespace */
        ns=raptor_namespaces_find_namespace(nstack, name, prefix_length);
      }
    }
  }
  
  if(!ns) {
    if(error_handler)
      error_handler((raptor_parser*)error_data, "The namespace prefix in \"%s\" was not declared.", original_name);
  }



  /* If namespace has a URI and a local_name is defined, return the URI
   * for this name
   */
  if(ns && (uri=raptor_namespace_get_uri(ns))) {
    if(local_name_length)
      uri=raptor_new_uri_from_uri_local_name(uri, local_name);
    else
      uri=raptor_uri_copy(uri);
  }

  return uri;
}


/*
 * Local Variables:
 * mode:c
 * c-basic-offset: 2
 * End:
 */
