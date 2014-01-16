#include "templates.h"

#include "thot_sys.h"
#include "tree.h"
#include "document.h"
#include "containers.h"
#include "insertelem_f.h"


#define THOT_EXPORT extern
#include "templateDeclarations.h"

#include "mydictionary_f.h"
#include "templateDeclarations_f.h"
#include "templateUtils_f.h"
#include "templateInstantiate_f.h"
#include "AHTURLTools_f.h"
#include "HTMLactions_f.h"
#include "init_f.h"

#ifdef TEMPLATES
#include "Template.h"
/* Information needed for the callback after loading a template.
   Just the path of the template, which identifies it. */
typedef struct _TemplateCtxt
{
	char			*templatePath;
} TemplateCtxt;
#endif

/*----------------------------------------------------------------------
  Creates an Element type and stores all needed information. 
  ----------------------------------------------------------------------*/
void AddElementDeclaration (XTigerTemplate t, Element el)
{
#ifdef TEMPLATES
	char *name;

  if(!t)
    return;

	name = GetAttributeStringValueFromNum (el, Template_ATTR_name, NULL);
  if(name)
  {
    NewElement (t, name);
    TtaFreeMemory (name);
  }
#endif /* TEMPLATES */
}

/*----------------------------------------------------------------------
  Creates a Union type and stores all needed information. 
  ----------------------------------------------------------------------*/
void AddUnionDeclaration (XTigerTemplate t, Element el)
{
#ifdef TEMPLATES
	char *name, *include, *exclude;
  
  if(!t)
    return;
	
	name	  = GetAttributeStringValueFromNum (el, Template_ATTR_name, NULL);
	include   = GetAttributeStringValueFromNum (el, Template_ATTR_includeAt, NULL);
	exclude   = GetAttributeStringValueFromNum (el, Template_ATTR_exclude, NULL);
  if(name && include)
  {
  	NewUnion (t, name, 
             Dictionary_CreateFromList (include), 
             Dictionary_CreateFromList (exclude));
  }
  TtaFreeMemory (name);
	TtaFreeMemory (include);
	TtaFreeMemory (exclude);
#endif /* TEMPLATES */
}

/*----------------------------------------------------------------------
  Creates a Component type and stores all needed information. 
  ----------------------------------------------------------------------*/
void AddComponentDeclaration (XTigerTemplate t, Element el)
{
#ifdef TEMPLATES
	char *name;
  
  if(!t)
    return;
	
	name = GetAttributeStringValueFromNum (el, Template_ATTR_name, NULL);
  if(name)
  	NewComponent (t, name, el);	
	TtaFreeMemory (name);
#endif /* TEMPLATES */
}

/*----------------------------------------------------------------------
  Load (if needed) a library and adds all its declarations to a template
  ----------------------------------------------------------------------*/
void AddImportedLibrary (XTigerTemplate t, Element el)
{
#ifdef TEMPLATES
#ifdef TODO_XTIGER
  if(t)
  {
  	XTigerTemplate lib = NULL;
  	//Load the library
  	AddLibraryDeclarations (t,lib);
  }
#endif
#endif /* TEMPLATES */
}

/*----------------------------------------------------------------------
  ----------------------------------------------------------------------*/
void CheckTypesAttribute (XTigerTemplate t, Element el)
{
#ifdef TEMPLATES
	char *types;
	DicDictionary dic;
  
  if(!t)
    return;

	types = GetAttributeStringValueFromNum (el, Template_ATTR_types, NULL);
  if(types)
  {
  	dic = Dictionary_CreateFromList (types);
  	
  	for (Dictionary_First (dic); !Dictionary_IsDone (dic); Dictionary_Next (dic))
  		if ( Template_GetDeclaration (t, Dictionary_CurrentKey (dic)) == NULL)
  			//TODO_XTIGER We must add the current namespace
  			NewElement (t, Dictionary_CurrentKey (dic));
  	
  	TtaFreeMemory (types);
  	Dictionary_Clean (dic);
  }
#endif /* TEMPLATES */
}

/*----------------------------------------------------------------------
  AddHeadParameters
  Add template parameter (version and templateVersion) to the template descriptor.
  ----------------------------------------------------------------------*/
void AddHeadParameters(XTigerTemplate t, Element el)
{
#ifdef TEMPLATES
  if(!t)
    return;

  t->version = GetAttributeStringValueFromNum(el, Template_ATTR_version, NULL);
  t->templateVersion = GetAttributeStringValueFromNum(el, Template_ATTR_templateVersion, NULL);
#endif /* TEMPLATES */
}

/*----------------------------------------------------------------------
  ----------------------------------------------------------------------*/
void ParseDeclarations (XTigerTemplate t, Element el)
{
#ifdef TEMPLATES
	ElementType type = TtaGetElementType (el);
  
  if(!t)
    return;
	
	if (!strcmp (TtaGetSSchemaName (type.ElSSchema),"Template"))
    {
      switch (type.ElTypeNum)
        {
        case Template_EL_head:
          AddHeadParameters(t,el);
          break;
        case Template_EL_component:
          AddComponentDeclaration (t,el);
          break;
        case Template_EL_union:
          AddUnionDeclaration (t,el);
          break;
        case Template_EL_import:
          AddImportedLibrary (t, el);
          break;
        case Template_EL_bag:
          CheckTypesAttribute (t, el);
          break;
        case Template_EL_useEl:
        case Template_EL_useSimple:
          CheckTypesAttribute (t, el);
          break;
        default:
          break;
        }
    }
	
	Element child = TtaGetFirstChild (el);
	while (child)
    {
      ParseDeclarations (t, child);
      TtaNextSibling (&child);
    }
#endif /* TEMPLATES */
}

static ThotBool Waiting_template = FALSE;
/*----------------------------------------------------------------------
  LoadTemplate_callback: Called after loading a template.
  ----------------------------------------------------------------------*/
void LoadTemplate_callback (int newdoc, int status,  char *urlName,
                            char *outputfile, char* proxyName,
                            AHTHeaders *http_headers, void * context)
{	
#ifdef TEMPLATES
  char         *templatename = NULL;
#ifdef AMAYA_DEBUG 
	char          localname[MAX_LENGTH];
	FILE         *file;
#endif /* AMAYA_DEBUG */
  Element       el;
	TemplateCtxt *ctx = (TemplateCtxt*)context;
	
  if (newdoc)
    {
      // the template is now loaded
      XTigerTemplate t = NewXTigerTemplate (ctx->templatePath, TRUE);
      SetTemplateDocument (t, newdoc);
      el = TtaGetMainRoot (newdoc);
      ParseDeclarations  (t, el);
      PreInstantiateComponents (t);
  
#ifdef AMAYA_DEBUG	
      DumpDeclarations (t);
      strcpy (localname, TempFileDirectory);
      strcat (localname, DIR_STR);
      strcat (localname, "template.debug");
      file = TtaWriteOpen (localname);
      TtaListAbstractTree (TtaGetMainRoot (newdoc), file);
      TtaWriteClose (file);
#endif
      templatename = ctx->templatePath;
      TtaFreeMemory (ctx);
      DoInstanceTemplate (templatename);
      DocumentTypes[newdoc] = docTemplate;
    }
  Waiting_template = FALSE;
#endif /* TEMPLATES */
}


/*----------------------------------------------------------------------
  ----------------------------------------------------------------------*/
void LoadTemplate (Document doc, char* templatename)
{
#ifdef TEMPLATES
  Document      newdoc = 0;
	char			   *s, *directory;
	unsigned int	size = strlen (templatename) + 1;

  if (!IsW3Path (templatename))
    {
      //Stores the template path for show it in next instanciation forms
      directory	= (char*) TtaGetMemory (size);
      s	= (char*) TtaGetMemory (size);
      TtaExtractName (templatename, directory, s);	
      TtaSetEnvString ("TEMPLATES_DIRECTORY", directory, TRUE);
      TtaFreeMemory (directory);
      TtaFreeMemory (s);
    }

	//If types are not loaded we load the template and we parse it
	if (!Dictionary_Get (Templates_Dic, templatename))
    {	
      //Creation of the callback context
      TemplateCtxt *ctx	= (TemplateCtxt *)TtaGetMemory (sizeof (TemplateCtxt));
      ctx->templatePath	= TtaStrdup (templatename);
      Waiting_template = TRUE;
      newdoc = GetAmayaDoc (templatename, NULL, 0, 0, CE_TEMPLATE, FALSE, 
                            (void (*)(int, int, char*, char*, char*, const AHTHeaders*, void*)) LoadTemplate_callback,
                            (void *) ctx);
      while (Waiting_template)
        TtaHandlePendingEvents ();
    }
#endif /* TEMPLATES */
}
