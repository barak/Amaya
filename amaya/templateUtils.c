/*
 *
 *  COPYRIGHT INRIA and W3C, 2006-2007
 *  Please first read the full copyright statement in file COPYRIGHT.
 *
 */

#include "templates.h"

/*----------------------------------------------------------------------
GetSchemaFromDocType: Returns the name of the schema corresponding to 
a doc type.
----------------------------------------------------------------------*/
char *GetSchemaFromDocType (DocumentType docType)
{
#ifdef TEMPLATES
	switch (docType)
    {
    case docAnnot :
		return "Annot";
    case docBookmark :
		return "Topics";
    case docSVG :
		return "SVG";
    case docMath :
		return "MathML";
    case docXml :
		return "XML";
    default :
		return "HTML";
    }
#endif // TEMPLATES
	return "HTML";
}

/*----------------------------------------------------------------------
Set the value of a string attribute 
----------------------------------------------------------------------*/
void SetAttributeStringValue (Element el, int att, char* value)
{
#ifdef TEMPLATES
  Document      doc = TtaGetDocument(el);
  AttributeType attType;
  Attribute     attribute;

  if (doc == 0 || !TtaGetDocumentAccessMode(doc))
    return;
  attType.AttrSSchema = TtaGetElementType(el).ElSSchema;
  attType.AttrTypeNum = att;
  attribute = TtaGetAttribute(el, attType);
  if (attribute == NULL)
    {
      attribute = TtaNewAttribute (attType);
      TtaAttachAttribute(el, attribute, doc);
    }
  TtaSetAttributeText(attribute, value, el, doc);
#endif /* TEMPLATES */
}

/*----------------------------------------------------------------------
Set the value of a string attribute and registering it in undo sequence.
----------------------------------------------------------------------*/
void SetAttributeStringValueWithUndo (Element el, int att, char* value)
{
#ifdef TEMPLATES
  Document      doc = TtaGetDocument(el);
  AttributeType attType;
  Attribute     attribute;

  if (doc == 0 || !TtaGetDocumentAccessMode(doc))
    return;
  attType.AttrSSchema = TtaGetElementType(el).ElSSchema;
  attType.AttrTypeNum = att;
  attribute = TtaGetAttribute(el, attType);
  if (attribute == NULL)
    {
      attribute = TtaNewAttribute (attType);
      TtaAttachAttribute(el, attribute, doc);
      TtaRegisterAttributeCreate(attribute, el, doc);
    }
  TtaSetAttributeText(attribute, value, el, doc);
  TtaRegisterAttributeReplace(attribute, el, doc);
#endif /* TEMPLATES */
}

/*----------------------------------------------------------------------
Returns the value of a string attribute without copy it 
----------------------------------------------------------------------*/
void GiveAttributeStringValueFromNum (Element el, int att, char* buff, int* sz)
{
#ifdef TEMPLATES
  AttributeType attType;
  Attribute     attribute;
  int           size;

  attType.AttrSSchema = TtaGetElementType(el).ElSSchema;
  attType.AttrTypeNum = att;
  attribute = TtaGetAttribute(el, attType);
  
  size = TtaGetTextAttributeLength(attribute);
  TtaGiveTextAttributeValue (attribute, buff, &size);
  buff[size] = EOS;
  if(sz)
    *sz = size;
#endif /* TEMPLATES */
}



/*----------------------------------------------------------------------
Returns the value of a string attribute 
----------------------------------------------------------------------*/
char *GetAttributeStringValueFromNum (Element el, int att, int* sz)
{
#ifdef TEMPLATES
	AttributeType attType;
  Attribute     attribute;
  char         *aux;
  int           size;

	attType.AttrSSchema = TtaGetElementType(el).ElSSchema;
	attType.AttrTypeNum = att;
	attribute = TtaGetAttribute(el, attType);
	
	size = TtaGetTextAttributeLength(attribute);
	aux = (char*) TtaGetMemory(size+1);
	TtaGiveTextAttributeValue (attribute, aux, &size);
  aux[size] = EOS;
  if(sz)
    *sz = size;
	return aux;
#else
	return NULL;
#endif /* TEMPLATES */
}

/*----------------------------------------------------------------------
Returns the value of a string attribute 
----------------------------------------------------------------------*/
char *GetAttributeStringValue (Element el, Attribute attribute, int* sz)
{
#ifdef TEMPLATES
	int size = TtaGetTextAttributeLength(attribute);
	char *aux = (char*) TtaGetMemory(size+1);

	TtaGiveTextAttributeValue (attribute, aux, &size);
  aux[size] = EOS;
  if(sz)
    *sz = size;
	return aux;
#else
	return NULL;
#endif /* TEMPLATES */
}


/*----------------------------------------------------------------------
GetFirstEditableElement
Returns the first descendant element which is modifiable.
----------------------------------------------------------------------*/
Element GetFirstEditableElement (Element el)
{
  Element res = NULL;
  Element current = TtaGetFirstChild(el);
  
  while(!res && current)
  {
    res = GetFirstEditableElement(current);
    TtaNextSibling(&current);
  }
  
  if(!res && !TtaIsReadOnly(el))
    res = el;
  
  return res;
}
