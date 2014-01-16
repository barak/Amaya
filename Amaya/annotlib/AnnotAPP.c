/* File generated by app - do not edit! */
/* #################################### */
/* Included files */
#include "string.h"
#include "thot_gui.h"
#include "thot_sys.h"
#include "application.h"
#include "appstruct.h"
#include "interface.h"
#include "Annot.h"

/*----------------------------------------------------------------------
 -----------------------------------------------------------------------*/
void AnnotApplicationInitialise ()
{
 PtrEventsSet appliActions;

  /* Create the new application context*/
  appliActions = TteNewEventsSet (35147, "Annot");
   /* Generate event/action entries */
  TteAddActionEvent (appliActions, 0, TteElemActivate, 1, "Annot_RaiseSourceDoc");
  TteAddActionEvent (appliActions, 18, TteElemActivate, 1, "Annot_RaiseSourceDoc");
  TteAddActionEvent (appliActions, 19, TteElemActivate, 1, "Annot_Types");
  TteAddActionEvent (appliActions, 13, TteElemTextModify, 0, "Annot_UpdateTitle");
  TteAddActionEvent (appliActions, 0, TteDocClose, 0, "DocumentClosed");

}

/*########## Init Appplication action-list #################*/
extern ThotBool Annot_RaiseSourceDoc (NotifyElement *event);
extern void DocumentClosed (NotifyDialog *event);
extern ThotBool Annot_Types (NotifyElement *event);
extern void Annot_UpdateTitle (NotifyOnTarget *event);
void AnnotActionListInit ()
{
  TteAddAction ("Annot_RaiseSourceDoc", (Proc)Annot_RaiseSourceDoc);
  TteAddAction ("DocumentClosed", (Proc)DocumentClosed);
  TteAddAction ("Annot_Types", (Proc)Annot_Types);
  TteAddAction ("Annot_UpdateTitle", (Proc)Annot_UpdateTitle);
}

void AnnotLoadResources ()
{
  AnnotActionListInit ();
  AnnotApplicationInitialise ();
}
