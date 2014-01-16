# Microsoft Developer Studio Generated NMAKE File, Format Version 40001
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

!IF "$(CFG)" == ""
CFG=LibThotEditor - Win32 Debug
!MESSAGE No configuration specified.  Defaulting to LibThotEditor - Win32\
 Debug.
!ENDIF 

!IF "$(CFG)" != "LibThotEditor - Win32 Release" && "$(CFG)" !=\
 "LibThotEditor - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE on this makefile
!MESSAGE by defining the macro CFG on the command line.  For example:
!MESSAGE 
!MESSAGE NMAKE /f "LibThotEditor.mak" CFG="LibThotEditor - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "LibThotEditor - Win32 Release" (based on\
 "Win32 (x86) Static Library")
!MESSAGE "LibThotEditor - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 
################################################################################
# Begin Project
# PROP Target_Last_Scanned "LibThotEditor - Win32 Debug"
CPP=cl.exe

!IF  "$(CFG)" == "LibThotEditor - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "."
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
OUTDIR=.\.
INTDIR=.\Release

ALL : "$(OUTDIR)\LibThotEditor.lib"

CLEAN : 
	-@erase ".\LibThotEditor.lib"
	-@erase ".\Release\attributes.obj"
	-@erase ".\Release\referenceapi.obj"
	-@erase ".\Release\Readprs.obj"
	-@erase ".\Release\Search.obj"
	-@erase ".\Release\createdoc.obj"
	-@erase ".\Release\appdialogue.obj"
	-@erase ".\Release\searchref.obj"
	-@erase ".\Release\Browser.obj"
	-@erase ".\Release\fileaccess.obj"
	-@erase ".\Release\presvariables.obj"
	-@erase ".\Release\Paginate.obj"
	-@erase ".\Release\pnghandler.obj"
	-@erase ".\Release\visibility.obj"
	-@erase ".\Release\Openview.obj"
	-@erase ".\Release\pagecommands.obj"
	-@erase ".\Release\Memory.obj"
	-@erase ".\Release\Tree.obj"
	-@erase ".\Release\structchange.obj"
	-@erase ".\Release\Context.obj"
	-@erase ".\Release\attributeapi.obj"
	-@erase ".\Release\windowdisplay.obj"
	-@erase ".\Release\structcreation.obj"
	-@erase ".\Release\Resgen.obj"
	-@erase ".\Release\Zoom.obj"
	-@erase ".\Release\abspictures.obj"
	-@erase ".\Release\references.obj"
	-@erase ".\Release\pictureapi.obj"
	-@erase ".\Release\Inites.obj"
	-@erase ".\Release\Geom.obj"
	-@erase ".\Release\structselect.obj"
	-@erase ".\Release\picturebase.obj"
	-@erase ".\Release\Pivot.obj"
	-@erase ".\Release\structcommands.obj"
	-@erase ".\Release\selectionapi.obj"
	-@erase ".\Release\checkaccess.obj"
	-@erase ".\Release\boxparams.obj"
	-@erase ".\Release\Platform.obj"
	-@erase ".\Release\Opendoc.obj"
	-@erase ".\Release\Res.obj"
	-@erase ".\Release\writepivot.obj"
	-@erase ".\Release\Viewapi.obj"
	-@erase ".\Release\viewcommands.obj"
	-@erase ".\Release\Picture.obj"
	-@erase ".\Release\documentapi.obj"
	-@erase ".\Release\changeabsbox.obj"
	-@erase ".\Release\Font.obj"
	-@erase ".\Release\buildlines.obj"
	-@erase ".\Release\Input.obj"
	-@erase ".\Release\labelalloc.obj"
	-@erase ".\Release\specificdriver.obj"
	-@erase ".\Release\displaybox.obj"
	-@erase ".\Release\Colors.obj"
	-@erase ".\Release\printmenu.obj"
	-@erase ".\Release\externalref.obj"
	-@erase ".\Release\textcommands.obj"
	-@erase ".\Release\unstructchange.obj"
	-@erase ".\Release\checkermenu.obj"
	-@erase ".\Release\Registry.obj"
	-@erase ".\Release\Readstr.obj"
	-@erase ".\Release\Hyphen.obj"
	-@erase ".\Release\callbackinit.obj"
	-@erase ".\Release\structmodif.obj"
	-@erase ".\Release\gifhandler.obj"
	-@erase ".\Release\structlocate.obj"
	-@erase ".\Release\Config.obj"
	-@erase ".\Release\Readtra.obj"
	-@erase ".\Release\Absboxes.obj"
	-@erase ".\Release\createabsbox.obj"
	-@erase ".\Release\Resmatch.obj"
	-@erase ".\Release\genericdriver.obj"
	-@erase ".\Release\changepresent.obj"
	-@erase ".\Release\searchmenu.obj"
	-@erase ".\Release\Closedoc.obj"
	-@erase ".\Release\Docs.obj"
	-@erase ".\Release\Message.obj"
	-@erase ".\Release\Savedoc.obj"
	-@erase ".\Release\interface.obj"
	-@erase ".\Release\displayselect.obj"
	-@erase ".\Release\jpeghandler.obj"
	-@erase ".\Release\Schemas.obj"
	-@erase ".\Release\presentdriver.obj"
	-@erase ".\Release\boxselection.obj"
	-@erase ".\Release\Treeapi.obj"
	-@erase ".\Release\Appli.obj"
	-@erase ".\Release\structlist.obj"
	-@erase ".\Release\Word.obj"
	-@erase ".\Release\createpages.obj"
	-@erase ".\Release\extprintmenu.obj"
	-@erase ".\Release\Callback.obj"
	-@erase ".\Release\presentmenu.obj"
	-@erase ".\Release\picturemenu.obj"
	-@erase ".\Release\xpmhandler.obj"
	-@erase ".\Release\unstructlocate.obj"
	-@erase ".\Release\keyboards.obj"
	-@erase ".\Release\exceptions.obj"
	-@erase ".\Release\Attrmenu.obj"
	-@erase ".\Release\Units.obj"
	-@erase ".\Release\boxlocate.obj"
	-@erase ".\Release\readpivot.obj"
	-@erase ".\Release\Quit.obj"
	-@erase ".\Release\presrules.obj"
	-@erase ".\Release\Frame.obj"
	-@erase ".\Release\pschemaapi.obj"
	-@erase ".\Release\presentationapi.obj"
	-@erase ".\Release\modiftype.obj"
	-@erase ".\Release\dialogapi.obj"
	-@erase ".\Release\boxpositions.obj"
	-@erase ".\Release\Scroll.obj"
	-@erase ".\Release\Lookup.obj"
	-@erase ".\Release\LiteClue.obj"
	-@erase ".\Release\searchmenustr.obj"
	-@erase ".\Release\Language.obj"
	-@erase ".\Release\boxrelations.obj"
	-@erase ".\Release\Schtrad.obj"
	-@erase ".\Release\epshandler.obj"
	-@erase ".\Release\Views.obj"
	-@erase ".\Release\buildboxes.obj"
	-@erase ".\Release\xbmhandler.obj"
	-@erase ".\Release\attrpresent.obj"
	-@erase ".\Release\Thotmsg.obj"
	-@erase ".\Release\applicationapi.obj"
	-@erase ".\Release\editcommands.obj"
	-@erase ".\Release\Alloca.obj"
	-@erase ".\Release\dictionary.obj"
	-@erase ".\Release\Draw.obj"
	-@erase ".\Release\Boxmoves.obj"
	-@erase ".\Release\contentapi.obj"
	-@erase ".\Release\translation.obj"
	-@erase ".\Release\creationmenu.obj"
	-@erase ".\Release\Content.obj"
	-@erase ".\Release\Actions.obj"
	-@erase ".\Release\structschema.obj"
	-@erase ".\Release\spellchecker.obj"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

"$(INTDIR)" :
    if not exist "$(INTDIR)/$(NULL)" mkdir "$(INTDIR)"

# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /YX /c
# ADD CPP /nologo /W3 /GX /I "..\thotlib\include" /I "..\thotlib\internals\h" /I "..\thotlib\internals\var" /I "..\thotlib\internals\f" /I "..\libjpeg" /I "..\libpng" /I "..\libpng\zlib" /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "__STDC__" /D "STDC_HEADERS" /YX /c
CPP_PROJ=/nologo /ML /W3 /GX /I "..\thotlib\include" /I\
 "..\thotlib\internals\h" /I "..\thotlib\internals\var" /I\
 "..\thotlib\internals\f" /I "..\libjpeg" /I "..\libpng" /I "..\libpng\zlib" /D\
 "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "__STDC__" /D "STDC_HEADERS"\
 /Fp"$(INTDIR)/LibThotEditor.pch" /YX /Fo"$(INTDIR)/" /c 
CPP_OBJS=.\Release/
CPP_SBRS=
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/LibThotEditor.bsc" 
BSC32_SBRS=
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo
LIB32_FLAGS=/nologo /out:"$(OUTDIR)/LibThotEditor.lib" 
LIB32_OBJS= \
	"$(INTDIR)/attributes.obj" \
	"$(INTDIR)/referenceapi.obj" \
	"$(INTDIR)/Readprs.obj" \
	"$(INTDIR)/Search.obj" \
	"$(INTDIR)/createdoc.obj" \
	"$(INTDIR)/appdialogue.obj" \
	"$(INTDIR)/searchref.obj" \
	"$(INTDIR)/Browser.obj" \
	"$(INTDIR)/fileaccess.obj" \
	"$(INTDIR)/presvariables.obj" \
	"$(INTDIR)/Paginate.obj" \
	"$(INTDIR)/pnghandler.obj" \
	"$(INTDIR)/visibility.obj" \
	"$(INTDIR)/Openview.obj" \
	"$(INTDIR)/pagecommands.obj" \
	"$(INTDIR)/Memory.obj" \
	"$(INTDIR)/Tree.obj" \
	"$(INTDIR)/structchange.obj" \
	"$(INTDIR)/Context.obj" \
	"$(INTDIR)/attributeapi.obj" \
	"$(INTDIR)/windowdisplay.obj" \
	"$(INTDIR)/structcreation.obj" \
	"$(INTDIR)/Resgen.obj" \
	"$(INTDIR)/Zoom.obj" \
	"$(INTDIR)/abspictures.obj" \
	"$(INTDIR)/references.obj" \
	"$(INTDIR)/pictureapi.obj" \
	"$(INTDIR)/Inites.obj" \
	"$(INTDIR)/Geom.obj" \
	"$(INTDIR)/structselect.obj" \
	"$(INTDIR)/picturebase.obj" \
	"$(INTDIR)/Pivot.obj" \
	"$(INTDIR)/structcommands.obj" \
	"$(INTDIR)/selectionapi.obj" \
	"$(INTDIR)/checkaccess.obj" \
	"$(INTDIR)/boxparams.obj" \
	"$(INTDIR)/Platform.obj" \
	"$(INTDIR)/Opendoc.obj" \
	"$(INTDIR)/Res.obj" \
	"$(INTDIR)/writepivot.obj" \
	"$(INTDIR)/Viewapi.obj" \
	"$(INTDIR)/viewcommands.obj" \
	"$(INTDIR)/Picture.obj" \
	"$(INTDIR)/documentapi.obj" \
	"$(INTDIR)/changeabsbox.obj" \
	"$(INTDIR)/Font.obj" \
	"$(INTDIR)/buildlines.obj" \
	"$(INTDIR)/Input.obj" \
	"$(INTDIR)/labelalloc.obj" \
	"$(INTDIR)/specificdriver.obj" \
	"$(INTDIR)/displaybox.obj" \
	"$(INTDIR)/Colors.obj" \
	"$(INTDIR)/printmenu.obj" \
	"$(INTDIR)/externalref.obj" \
	"$(INTDIR)/textcommands.obj" \
	"$(INTDIR)/unstructchange.obj" \
	"$(INTDIR)/checkermenu.obj" \
	"$(INTDIR)/Registry.obj" \
	"$(INTDIR)/Readstr.obj" \
	"$(INTDIR)/Hyphen.obj" \
	"$(INTDIR)/callbackinit.obj" \
	"$(INTDIR)/structmodif.obj" \
	"$(INTDIR)/gifhandler.obj" \
	"$(INTDIR)/structlocate.obj" \
	"$(INTDIR)/Config.obj" \
	"$(INTDIR)/Readtra.obj" \
	"$(INTDIR)/Absboxes.obj" \
	"$(INTDIR)/createabsbox.obj" \
	"$(INTDIR)/Resmatch.obj" \
	"$(INTDIR)/genericdriver.obj" \
	"$(INTDIR)/changepresent.obj" \
	"$(INTDIR)/searchmenu.obj" \
	"$(INTDIR)/Closedoc.obj" \
	"$(INTDIR)/Docs.obj" \
	"$(INTDIR)/Message.obj" \
	"$(INTDIR)/Savedoc.obj" \
	"$(INTDIR)/interface.obj" \
	"$(INTDIR)/displayselect.obj" \
	"$(INTDIR)/jpeghandler.obj" \
	"$(INTDIR)/Schemas.obj" \
	"$(INTDIR)/presentdriver.obj" \
	"$(INTDIR)/boxselection.obj" \
	"$(INTDIR)/Treeapi.obj" \
	"$(INTDIR)/Appli.obj" \
	"$(INTDIR)/structlist.obj" \
	"$(INTDIR)/Word.obj" \
	"$(INTDIR)/createpages.obj" \
	"$(INTDIR)/extprintmenu.obj" \
	"$(INTDIR)/Callback.obj" \
	"$(INTDIR)/presentmenu.obj" \
	"$(INTDIR)/picturemenu.obj" \
	"$(INTDIR)/xpmhandler.obj" \
	"$(INTDIR)/unstructlocate.obj" \
	"$(INTDIR)/keyboards.obj" \
	"$(INTDIR)/exceptions.obj" \
	"$(INTDIR)/Attrmenu.obj" \
	"$(INTDIR)/Units.obj" \
	"$(INTDIR)/boxlocate.obj" \
	"$(INTDIR)/readpivot.obj" \
	"$(INTDIR)/Quit.obj" \
	"$(INTDIR)/presrules.obj" \
	"$(INTDIR)/Frame.obj" \
	"$(INTDIR)/pschemaapi.obj" \
	"$(INTDIR)/presentationapi.obj" \
	"$(INTDIR)/modiftype.obj" \
	"$(INTDIR)/dialogapi.obj" \
	"$(INTDIR)/boxpositions.obj" \
	"$(INTDIR)/Scroll.obj" \
	"$(INTDIR)/Lookup.obj" \
	"$(INTDIR)/LiteClue.obj" \
	"$(INTDIR)/searchmenustr.obj" \
	"$(INTDIR)/Language.obj" \
	"$(INTDIR)/boxrelations.obj" \
	"$(INTDIR)/Schtrad.obj" \
	"$(INTDIR)/epshandler.obj" \
	"$(INTDIR)/Views.obj" \
	"$(INTDIR)/buildboxes.obj" \
	"$(INTDIR)/xbmhandler.obj" \
	"$(INTDIR)/attrpresent.obj" \
	"$(INTDIR)/Thotmsg.obj" \
	"$(INTDIR)/applicationapi.obj" \
	"$(INTDIR)/editcommands.obj" \
	"$(INTDIR)/Alloca.obj" \
	"$(INTDIR)/dictionary.obj" \
	"$(INTDIR)/Draw.obj" \
	"$(INTDIR)/Boxmoves.obj" \
	"$(INTDIR)/contentapi.obj" \
	"$(INTDIR)/translation.obj" \
	"$(INTDIR)/creationmenu.obj" \
	"$(INTDIR)/Content.obj" \
	"$(INTDIR)/Actions.obj" \
	"$(INTDIR)/structschema.obj" \
	"$(INTDIR)/spellchecker.obj"

"$(OUTDIR)\LibThotEditor.lib" : "$(OUTDIR)" $(DEF_FILE) $(LIB32_OBJS)
    $(LIB32) @<<
  $(LIB32_FLAGS) $(DEF_FLAGS) $(LIB32_OBJS)
<<

!ELSEIF  "$(CFG)" == "LibThotEditor - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "."
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
OUTDIR=.\.
INTDIR=.\Debug

ALL : "$(OUTDIR)\LibThotEditor.lib"

CLEAN : 
	-@erase ".\LibThotEditor.lib"
	-@erase ".\Debug\spellchecker.obj"
	-@erase ".\Debug\Closedoc.obj"
	-@erase ".\Debug\Scroll.obj"
	-@erase ".\Debug\Lookup.obj"
	-@erase ".\Debug\referenceapi.obj"
	-@erase ".\Debug\appdialogue.obj"
	-@erase ".\Debug\boxselection.obj"
	-@erase ".\Debug\Pivot.obj"
	-@erase ".\Debug\windowdisplay.obj"
	-@erase ".\Debug\printmenu.obj"
	-@erase ".\Debug\Schtrad.obj"
	-@erase ".\Debug\pagecommands.obj"
	-@erase ".\Debug\structlist.obj"
	-@erase ".\Debug\Alloca.obj"
	-@erase ".\Debug\Draw.obj"
	-@erase ".\Debug\jpeghandler.obj"
	-@erase ".\Debug\attributeapi.obj"
	-@erase ".\Debug\xpmhandler.obj"
	-@erase ".\Debug\Input.obj"
	-@erase ".\Debug\structcreation.obj"
	-@erase ".\Debug\Callback.obj"
	-@erase ".\Debug\exceptions.obj"
	-@erase ".\Debug\Content.obj"
	-@erase ".\Debug\Search.obj"
	-@erase ".\Debug\Actions.obj"
	-@erase ".\Debug\searchmenustr.obj"
	-@erase ".\Debug\Attrmenu.obj"
	-@erase ".\Debug\structselect.obj"
	-@erase ".\Debug\createpages.obj"
	-@erase ".\Debug\structcommands.obj"
	-@erase ".\Debug\presentmenu.obj"
	-@erase ".\Debug\Readprs.obj"
	-@erase ".\Debug\selectionapi.obj"
	-@erase ".\Debug\pschemaapi.obj"
	-@erase ".\Debug\interface.obj"
	-@erase ".\Debug\Browser.obj"
	-@erase ".\Debug\checkaccess.obj"
	-@erase ".\Debug\boxpositions.obj"
	-@erase ".\Debug\Memory.obj"
	-@erase ".\Debug\viewcommands.obj"
	-@erase ".\Debug\boxrelations.obj"
	-@erase ".\Debug\writepivot.obj"
	-@erase ".\Debug\Tree.obj"
	-@erase ".\Debug\Resgen.obj"
	-@erase ".\Debug\LiteClue.obj"
	-@erase ".\Debug\Zoom.obj"
	-@erase ".\Debug\Savedoc.obj"
	-@erase ".\Debug\Language.obj"
	-@erase ".\Debug\Inites.obj"
	-@erase ".\Debug\buildboxes.obj"
	-@erase ".\Debug\Context.obj"
	-@erase ".\Debug\Geom.obj"
	-@erase ".\Debug\specificdriver.obj"
	-@erase ".\Debug\labelalloc.obj"
	-@erase ".\Debug\boxparams.obj"
	-@erase ".\Debug\presvariables.obj"
	-@erase ".\Debug\dictionary.obj"
	-@erase ".\Debug\textcommands.obj"
	-@erase ".\Debug\Treeapi.obj"
	-@erase ".\Debug\externalref.obj"
	-@erase ".\Debug\genericdriver.obj"
	-@erase ".\Debug\contentapi.obj"
	-@erase ".\Debug\changepresent.obj"
	-@erase ".\Debug\unstructchange.obj"
	-@erase ".\Debug\checkermenu.obj"
	-@erase ".\Debug\callbackinit.obj"
	-@erase ".\Debug\structschema.obj"
	-@erase ".\Debug\Boxmoves.obj"
	-@erase ".\Debug\structlocate.obj"
	-@erase ".\Debug\structmodif.obj"
	-@erase ".\Debug\boxlocate.obj"
	-@erase ".\Debug\gifhandler.obj"
	-@erase ".\Debug\Appli.obj"
	-@erase ".\Debug\attributes.obj"
	-@erase ".\Debug\createabsbox.obj"
	-@erase ".\Debug\attrpresent.obj"
	-@erase ".\Debug\displayselect.obj"
	-@erase ".\Debug\presentdriver.obj"
	-@erase ".\Debug\Opendoc.obj"
	-@erase ".\Debug\Font.obj"
	-@erase ".\Debug\Viewapi.obj"
	-@erase ".\Debug\fileaccess.obj"
	-@erase ".\Debug\modiftype.obj"
	-@erase ".\Debug\Picture.obj"
	-@erase ".\Debug\translation.obj"
	-@erase ".\Debug\pnghandler.obj"
	-@erase ".\Debug\Paginate.obj"
	-@erase ".\Debug\visibility.obj"
	-@erase ".\Debug\Colors.obj"
	-@erase ".\Debug\Units.obj"
	-@erase ".\Debug\Openview.obj"
	-@erase ".\Debug\structchange.obj"
	-@erase ".\Debug\Hyphen.obj"
	-@erase ".\Debug\Config.obj"
	-@erase ".\Debug\Frame.obj"
	-@erase ".\Debug\Res.obj"
	-@erase ".\Debug\references.obj"
	-@erase ".\Debug\Readstr.obj"
	-@erase ".\Debug\pictureapi.obj"
	-@erase ".\Debug\extprintmenu.obj"
	-@erase ".\Debug\Thotmsg.obj"
	-@erase ".\Debug\Readtra.obj"
	-@erase ".\Debug\picturemenu.obj"
	-@erase ".\Debug\Docs.obj"
	-@erase ".\Debug\unstructlocate.obj"
	-@erase ".\Debug\createdoc.obj"
	-@erase ".\Debug\Views.obj"
	-@erase ".\Debug\searchref.obj"
	-@erase ".\Debug\abspictures.obj"
	-@erase ".\Debug\changeabsbox.obj"
	-@erase ".\Debug\Platform.obj"
	-@erase ".\Debug\Message.obj"
	-@erase ".\Debug\buildlines.obj"
	-@erase ".\Debug\picturebase.obj"
	-@erase ".\Debug\Schemas.obj"
	-@erase ".\Debug\Word.obj"
	-@erase ".\Debug\keyboards.obj"
	-@erase ".\Debug\displaybox.obj"
	-@erase ".\Debug\documentapi.obj"
	-@erase ".\Debug\presentationapi.obj"
	-@erase ".\Debug\readpivot.obj"
	-@erase ".\Debug\Registry.obj"
	-@erase ".\Debug\epshandler.obj"
	-@erase ".\Debug\presrules.obj"
	-@erase ".\Debug\applicationapi.obj"
	-@erase ".\Debug\xbmhandler.obj"
	-@erase ".\Debug\editcommands.obj"
	-@erase ".\Debug\Quit.obj"
	-@erase ".\Debug\Absboxes.obj"
	-@erase ".\Debug\creationmenu.obj"
	-@erase ".\Debug\Resmatch.obj"
	-@erase ".\Debug\dialogapi.obj"
	-@erase ".\Debug\searchmenu.obj"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

"$(INTDIR)" :
    if not exist "$(INTDIR)/$(NULL)" mkdir "$(INTDIR)"

# ADD BASE CPP /nologo /W3 /GX /Z7 /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /YX /c
# ADD CPP /nologo /W3 /GX /Z7 /I "..\thotlib\include" /I "..\thotlib\internals\h" /I "..\thotlib\internals\var" /I "..\thotlib\internals\f" /I "..\libjpeg" /I "..\libpng" /I "..\libpng\zlib" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "__STDC__" /D "STDC_HEADERS" /YX /c
CPP_PROJ=/nologo /MLd /W3 /GX /Z7 /I "..\thotlib\include" /I\
 "..\thotlib\internals\h" /I "..\thotlib\internals\var" /I\
 "..\thotlib\internals\f" /I "..\libjpeg" /I "..\libpng" /I "..\libpng\zlib" /D\
 "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "__STDC__" /D "STDC_HEADERS"\
 /Fp"$(INTDIR)/LibThotEditor.pch" /YX /Fo"$(INTDIR)/" /c 
CPP_OBJS=.\Debug/
CPP_SBRS=
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/LibThotEditor.bsc" 
BSC32_SBRS=
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo
LIB32_FLAGS=/nologo /out:"$(OUTDIR)/LibThotEditor.lib" 
LIB32_OBJS= \
	"$(INTDIR)/spellchecker.obj" \
	"$(INTDIR)/Closedoc.obj" \
	"$(INTDIR)/Scroll.obj" \
	"$(INTDIR)/Lookup.obj" \
	"$(INTDIR)/referenceapi.obj" \
	"$(INTDIR)/appdialogue.obj" \
	"$(INTDIR)/boxselection.obj" \
	"$(INTDIR)/Pivot.obj" \
	"$(INTDIR)/windowdisplay.obj" \
	"$(INTDIR)/printmenu.obj" \
	"$(INTDIR)/Schtrad.obj" \
	"$(INTDIR)/pagecommands.obj" \
	"$(INTDIR)/structlist.obj" \
	"$(INTDIR)/Alloca.obj" \
	"$(INTDIR)/Draw.obj" \
	"$(INTDIR)/jpeghandler.obj" \
	"$(INTDIR)/attributeapi.obj" \
	"$(INTDIR)/xpmhandler.obj" \
	"$(INTDIR)/Input.obj" \
	"$(INTDIR)/structcreation.obj" \
	"$(INTDIR)/Callback.obj" \
	"$(INTDIR)/exceptions.obj" \
	"$(INTDIR)/Content.obj" \
	"$(INTDIR)/Search.obj" \
	"$(INTDIR)/Actions.obj" \
	"$(INTDIR)/searchmenustr.obj" \
	"$(INTDIR)/Attrmenu.obj" \
	"$(INTDIR)/structselect.obj" \
	"$(INTDIR)/createpages.obj" \
	"$(INTDIR)/structcommands.obj" \
	"$(INTDIR)/presentmenu.obj" \
	"$(INTDIR)/Readprs.obj" \
	"$(INTDIR)/selectionapi.obj" \
	"$(INTDIR)/pschemaapi.obj" \
	"$(INTDIR)/interface.obj" \
	"$(INTDIR)/Browser.obj" \
	"$(INTDIR)/checkaccess.obj" \
	"$(INTDIR)/boxpositions.obj" \
	"$(INTDIR)/Memory.obj" \
	"$(INTDIR)/viewcommands.obj" \
	"$(INTDIR)/boxrelations.obj" \
	"$(INTDIR)/writepivot.obj" \
	"$(INTDIR)/Tree.obj" \
	"$(INTDIR)/Resgen.obj" \
	"$(INTDIR)/LiteClue.obj" \
	"$(INTDIR)/Zoom.obj" \
	"$(INTDIR)/Savedoc.obj" \
	"$(INTDIR)/Language.obj" \
	"$(INTDIR)/Inites.obj" \
	"$(INTDIR)/buildboxes.obj" \
	"$(INTDIR)/Context.obj" \
	"$(INTDIR)/Geom.obj" \
	"$(INTDIR)/specificdriver.obj" \
	"$(INTDIR)/labelalloc.obj" \
	"$(INTDIR)/boxparams.obj" \
	"$(INTDIR)/presvariables.obj" \
	"$(INTDIR)/dictionary.obj" \
	"$(INTDIR)/textcommands.obj" \
	"$(INTDIR)/Treeapi.obj" \
	"$(INTDIR)/externalref.obj" \
	"$(INTDIR)/genericdriver.obj" \
	"$(INTDIR)/contentapi.obj" \
	"$(INTDIR)/changepresent.obj" \
	"$(INTDIR)/unstructchange.obj" \
	"$(INTDIR)/checkermenu.obj" \
	"$(INTDIR)/callbackinit.obj" \
	"$(INTDIR)/structschema.obj" \
	"$(INTDIR)/Boxmoves.obj" \
	"$(INTDIR)/structlocate.obj" \
	"$(INTDIR)/structmodif.obj" \
	"$(INTDIR)/boxlocate.obj" \
	"$(INTDIR)/gifhandler.obj" \
	"$(INTDIR)/Appli.obj" \
	"$(INTDIR)/attributes.obj" \
	"$(INTDIR)/createabsbox.obj" \
	"$(INTDIR)/attrpresent.obj" \
	"$(INTDIR)/displayselect.obj" \
	"$(INTDIR)/presentdriver.obj" \
	"$(INTDIR)/Opendoc.obj" \
	"$(INTDIR)/Font.obj" \
	"$(INTDIR)/Viewapi.obj" \
	"$(INTDIR)/fileaccess.obj" \
	"$(INTDIR)/modiftype.obj" \
	"$(INTDIR)/Picture.obj" \
	"$(INTDIR)/translation.obj" \
	"$(INTDIR)/pnghandler.obj" \
	"$(INTDIR)/Paginate.obj" \
	"$(INTDIR)/visibility.obj" \
	"$(INTDIR)/Colors.obj" \
	"$(INTDIR)/Units.obj" \
	"$(INTDIR)/Openview.obj" \
	"$(INTDIR)/structchange.obj" \
	"$(INTDIR)/Hyphen.obj" \
	"$(INTDIR)/Config.obj" \
	"$(INTDIR)/Frame.obj" \
	"$(INTDIR)/Res.obj" \
	"$(INTDIR)/references.obj" \
	"$(INTDIR)/Readstr.obj" \
	"$(INTDIR)/pictureapi.obj" \
	"$(INTDIR)/extprintmenu.obj" \
	"$(INTDIR)/Thotmsg.obj" \
	"$(INTDIR)/Readtra.obj" \
	"$(INTDIR)/picturemenu.obj" \
	"$(INTDIR)/Docs.obj" \
	"$(INTDIR)/unstructlocate.obj" \
	"$(INTDIR)/createdoc.obj" \
	"$(INTDIR)/Views.obj" \
	"$(INTDIR)/searchref.obj" \
	"$(INTDIR)/abspictures.obj" \
	"$(INTDIR)/changeabsbox.obj" \
	"$(INTDIR)/Platform.obj" \
	"$(INTDIR)/Message.obj" \
	"$(INTDIR)/buildlines.obj" \
	"$(INTDIR)/picturebase.obj" \
	"$(INTDIR)/Schemas.obj" \
	"$(INTDIR)/Word.obj" \
	"$(INTDIR)/keyboards.obj" \
	"$(INTDIR)/displaybox.obj" \
	"$(INTDIR)/documentapi.obj" \
	"$(INTDIR)/presentationapi.obj" \
	"$(INTDIR)/readpivot.obj" \
	"$(INTDIR)/Registry.obj" \
	"$(INTDIR)/epshandler.obj" \
	"$(INTDIR)/presrules.obj" \
	"$(INTDIR)/applicationapi.obj" \
	"$(INTDIR)/xbmhandler.obj" \
	"$(INTDIR)/editcommands.obj" \
	"$(INTDIR)/Quit.obj" \
	"$(INTDIR)/Absboxes.obj" \
	"$(INTDIR)/creationmenu.obj" \
	"$(INTDIR)/Resmatch.obj" \
	"$(INTDIR)/dialogapi.obj" \
	"$(INTDIR)/searchmenu.obj"

"$(OUTDIR)\LibThotEditor.lib" : "$(OUTDIR)" $(DEF_FILE) $(LIB32_OBJS)
    $(LIB32) @<<
  $(LIB32_FLAGS) $(DEF_FLAGS) $(LIB32_OBJS)
<<

!ENDIF 

.c{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.cpp{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.cxx{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.c{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

.cpp{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

.cxx{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

################################################################################
# Begin Target

# Name "LibThotEditor - Win32 Release"
# Name "LibThotEditor - Win32 Debug"

!IF  "$(CFG)" == "LibThotEditor - Win32 Release"

!ELSEIF  "$(CFG)" == "LibThotEditor - Win32 Debug"

!ENDIF 

################################################################################
# Begin Source File

SOURCE=\users\Guetari\Opera\Thotlib\Base\Alloca.c
NODEP_CPP_ALLOC=\
	".\..\Thotlib\Base\config.h"\
	

"$(INTDIR)\Alloca.obj" : $(SOURCE) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


# End Source File
################################################################################
# Begin Source File

SOURCE=\users\Guetari\Opera\Thotlib\Base\Actions.c

!IF  "$(CFG)" == "LibThotEditor - Win32 Release"

DEP_CPP_ACTIO=\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\appdialogue.h"\
	".\..\thotlib\internals\var\appdialogue_tv.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\constint.h"\
	".\..\thotlib\internals\h\thotkey.h"\
	".\..\thotlib\internals\h\conststr.h"\
	".\..\thotlib\internals\h\constprs.h"\
	".\..\thotlib\internals\h\frame.h"\
	".\..\thotlib\internals\h\constmenu.h"\
	
NODEP_CPP_ACTIO=\
	".\..\thotlib\include\HTVMSUtils.h"\
	

"$(INTDIR)\Actions.obj" : $(SOURCE) $(DEP_CPP_ACTIO) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "LibThotEditor - Win32 Debug"

DEP_CPP_ACTIO=\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\appdialogue.h"\
	".\..\thotlib\internals\var\appdialogue_tv.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\frame.h"\
	".\..\thotlib\internals\h\constmenu.h"\
	

"$(INTDIR)\Actions.obj" : $(SOURCE) $(DEP_CPP_ACTIO) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\Guetari\Opera\Thotlib\Base\Config.c

!IF  "$(CFG)" == "LibThotEditor - Win32 Release"

DEP_CPP_CONFI=\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\thotdir.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\constmenu.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\internals\h\frame.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\application.h"\
	".\..\thotlib\internals\h\appdialogue.h"\
	".\..\thotlib\include\fileaccess.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\internals\var\platform_tv.h"\
	".\..\thotlib\internals\var\edit_tv.h"\
	".\..\thotlib\internals\var\frame_tv.h"\
	".\..\thotlib\internals\var\units_tv.h"\
	".\..\thotlib\internals\var\appdialogue_tv.h"\
	".\..\thotlib\internals\f\views_f.h"\
	".\..\thotlib\internals\f\inites_f.h"\
	".\..\thotlib\internals\f\memory_f.h"\
	".\..\thotlib\internals\f\message_f.h"\
	".\..\thotlib\internals\f\thotmsg_f.h"\
	".\..\thotlib\internals\f\fileaccess_f.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\thotlib\internals\h\constint.h"\
	".\..\thotlib\internals\h\thotkey.h"\
	".\..\thotlib\internals\h\conststr.h"\
	".\..\thotlib\internals\h\constprs.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\include\registry.h"\
	
NODEP_CPP_CONFI=\
	".\..\thotlib\include\HTVMSUtils.h"\
	

"$(INTDIR)\Config.obj" : $(SOURCE) $(DEP_CPP_CONFI) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "LibThotEditor - Win32 Debug"

DEP_CPP_CONFI=\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\thotdir.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\constmenu.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\internals\h\frame.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\application.h"\
	".\..\thotlib\internals\h\appdialogue.h"\
	".\..\thotlib\include\fileaccess.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\internals\var\platform_tv.h"\
	".\..\thotlib\internals\var\edit_tv.h"\
	".\..\thotlib\internals\var\frame_tv.h"\
	".\..\thotlib\internals\var\units_tv.h"\
	".\..\thotlib\internals\var\appdialogue_tv.h"\
	".\..\thotlib\internals\f\views_f.h"\
	".\..\thotlib\internals\f\inites_f.h"\
	".\..\thotlib\internals\f\memory_f.h"\
	".\..\thotlib\internals\f\message_f.h"\
	".\..\thotlib\internals\f\thotmsg_f.h"\
	".\..\thotlib\internals\f\fileaccess_f.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\include\registry.h"\
	

"$(INTDIR)\Config.obj" : $(SOURCE) $(DEP_CPP_CONFI) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\Guetari\Opera\Thotlib\Base\fileaccess.c

!IF  "$(CFG)" == "LibThotEditor - Win32 Release"

DEP_CPP_FILEA=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\include\fileaccess.h"\
	".\..\thotlib\internals\h\thotdir.h"\
	".\..\thotlib\internals\var\platform_tv.h"\
	".\..\thotlib\internals\f\fileaccess_f.h"\
	".\..\thotlib\internals\f\platform_f.h"\
	".\..\thotlib\internals\f\registry_f.h"\
	".\..\thotlib\include\sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\thotlib\internals\h\constint.h"\
	".\..\thotlib\internals\h\thotkey.h"\
	".\..\thotlib\internals\h\conststr.h"\
	".\..\thotlib\internals\h\constprs.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	
NODEP_CPP_FILEA=\
	".\..\thotlib\include\HTVMSUtils.h"\
	

"$(INTDIR)\fileaccess.obj" : $(SOURCE) $(DEP_CPP_FILEA) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "LibThotEditor - Win32 Debug"

DEP_CPP_FILEA=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\include\fileaccess.h"\
	".\..\thotlib\internals\h\thotdir.h"\
	".\..\thotlib\internals\var\platform_tv.h"\
	".\..\thotlib\internals\f\fileaccess_f.h"\
	".\..\thotlib\internals\f\platform_f.h"\
	".\..\thotlib\internals\f\registry_f.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	

"$(INTDIR)\fileaccess.obj" : $(SOURCE) $(DEP_CPP_FILEA) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\Guetari\Opera\Thotlib\Base\Memory.c

!IF  "$(CFG)" == "LibThotEditor - Win32 Release"

DEP_CPP_MEMOR=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\include\libmsg.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\include\fileaccess.h"\
	".\..\thotlib\internals\var\boxes_tv.h"\
	".\..\thotlib\internals\var\edit_tv.h"\
	".\..\thotlib\internals\f\memory_f.h"\
	".\..\thotlib\internals\f\fileaccess_f.h"\
	".\..\thotlib\include\sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\thotlib\internals\h\constint.h"\
	".\..\thotlib\internals\h\thotkey.h"\
	".\..\thotlib\internals\h\conststr.h"\
	".\..\thotlib\internals\h\constprs.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	
NODEP_CPP_MEMOR=\
	".\..\thotlib\include\HTVMSUtils.h"\
	

"$(INTDIR)\Memory.obj" : $(SOURCE) $(DEP_CPP_MEMOR) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "LibThotEditor - Win32 Debug"

DEP_CPP_MEMOR=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\include\libmsg.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\include\fileaccess.h"\
	".\..\thotlib\internals\var\boxes_tv.h"\
	".\..\thotlib\internals\var\edit_tv.h"\
	".\..\thotlib\internals\f\memory_f.h"\
	".\..\thotlib\internals\f\fileaccess_f.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	

"$(INTDIR)\Memory.obj" : $(SOURCE) $(DEP_CPP_MEMOR) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\Guetari\Opera\Thotlib\Base\Message.c

!IF  "$(CFG)" == "LibThotEditor - Win32 Release"

DEP_CPP_MESSA=\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\include\libmsg.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\include\dialog.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\internals\f\dialogapi_f.h"\
	".\..\thotlib\internals\f\memory_f.h"\
	".\..\thotlib\internals\f\message_f.h"\
	".\..\thotlib\internals\f\registry_f.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\thotlib\internals\h\constint.h"\
	".\..\thotlib\internals\h\thotkey.h"\
	".\..\thotlib\internals\h\conststr.h"\
	".\..\thotlib\internals\h\constprs.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	
NODEP_CPP_MESSA=\
	".\..\thotlib\include\HTVMSUtils.h"\
	

"$(INTDIR)\Message.obj" : $(SOURCE) $(DEP_CPP_MESSA) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "LibThotEditor - Win32 Debug"

DEP_CPP_MESSA=\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\include\libmsg.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\include\dialog.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\internals\f\dialogapi_f.h"\
	".\..\thotlib\internals\f\memory_f.h"\
	".\..\thotlib\internals\f\message_f.h"\
	".\..\thotlib\internals\f\registry_f.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	

"$(INTDIR)\Message.obj" : $(SOURCE) $(DEP_CPP_MESSA) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\Guetari\Opera\Thotlib\Base\Platform.c

!IF  "$(CFG)" == "LibThotEditor - Win32 Release"

DEP_CPP_PLATF=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\thotdir.h"\
	".\..\thotlib\include\fileaccess.h"\
	".\..\thotlib\include\sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\thotlib\internals\h\constint.h"\
	".\..\thotlib\internals\h\thotkey.h"\
	".\..\thotlib\internals\h\conststr.h"\
	".\..\thotlib\internals\h\constprs.h"\
	".\..\thotlib\include\typebase.h"\
	
NODEP_CPP_PLATF=\
	".\..\thotlib\include\HTVMSUtils.h"\
	

"$(INTDIR)\Platform.obj" : $(SOURCE) $(DEP_CPP_PLATF) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "LibThotEditor - Win32 Debug"

DEP_CPP_PLATF=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\thotdir.h"\
	".\..\thotlib\include\fileaccess.h"\
	".\..\thotlib\include\typebase.h"\
	

"$(INTDIR)\Platform.obj" : $(SOURCE) $(DEP_CPP_PLATF) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\Guetari\Opera\Thotlib\Base\Registry.c

!IF  "$(CFG)" == "LibThotEditor - Win32 Release"

DEP_CPP_REGIS=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\include\registry.h"\
	".\..\thotlib\include\application.h"\
	".\..\thotlib\internals\h\thotdir.h"\
	".\..\thotlib\internals\var\platform_tv.h"\
	".\..\thotlib\internals\f\fileaccess_f.h"\
	".\..\thotlib\internals\f\platform_f.h"\
	".\..\thotlib\include\sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\thotlib\internals\h\constint.h"\
	".\..\thotlib\internals\h\thotkey.h"\
	".\..\thotlib\internals\h\conststr.h"\
	".\..\thotlib\internals\h\constprs.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\include\fileaccess.h"\
	
NODEP_CPP_REGIS=\
	".\..\thotlib\include\HTVMSUtils.h"\
	

"$(INTDIR)\Registry.obj" : $(SOURCE) $(DEP_CPP_REGIS) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "LibThotEditor - Win32 Debug"

DEP_CPP_REGIS=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\include\registry.h"\
	".\..\thotlib\include\application.h"\
	".\..\thotlib\internals\h\thotdir.h"\
	".\..\thotlib\internals\var\platform_tv.h"\
	".\..\thotlib\internals\f\fileaccess_f.h"\
	".\..\thotlib\internals\f\platform_f.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\include\fileaccess.h"\
	

"$(INTDIR)\Registry.obj" : $(SOURCE) $(DEP_CPP_REGIS) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\Guetari\Opera\Thotlib\Base\structlist.c

!IF  "$(CFG)" == "LibThotEditor - Win32 Release"

DEP_CPP_STRUC=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\internals\h\picture.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\application.h"\
	".\..\thotlib\include\libmsg.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\include\fileaccess.h"\
	".\..\thotlib\internals\var\edit_tv.h"\
	".\..\thotlib\internals\var\boxes_tv.h"\
	".\..\thotlib\internals\f\absboxes_f.h"\
	".\..\thotlib\internals\f\fileaccess_f.h"\
	".\..\thotlib\internals\f\presrules_f.h"\
	".\..\thotlib\internals\f\structlist_f.h"\
	".\..\thotlib\internals\f\thotmsg_f.h"\
	".\..\thotlib\internals\f\tree_f.h"\
	".\..\thotlib\internals\f\viewapi_f.h"\
	".\..\thotlib\include\sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\thotlib\internals\h\constint.h"\
	".\..\thotlib\internals\h\thotkey.h"\
	".\..\thotlib\internals\h\conststr.h"\
	".\..\thotlib\internals\h\constprs.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\include\registry.h"\
	
NODEP_CPP_STRUC=\
	".\..\thotlib\include\HTVMSUtils.h"\
	

"$(INTDIR)\structlist.obj" : $(SOURCE) $(DEP_CPP_STRUC) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "LibThotEditor - Win32 Debug"

DEP_CPP_STRUC=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\internals\h\picture.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\application.h"\
	".\..\thotlib\include\libmsg.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\include\fileaccess.h"\
	".\..\thotlib\internals\var\edit_tv.h"\
	".\..\thotlib\internals\var\boxes_tv.h"\
	".\..\thotlib\internals\f\absboxes_f.h"\
	".\..\thotlib\internals\f\fileaccess_f.h"\
	".\..\thotlib\internals\f\presrules_f.h"\
	".\..\thotlib\internals\f\structlist_f.h"\
	".\..\thotlib\internals\f\thotmsg_f.h"\
	".\..\thotlib\internals\f\tree_f.h"\
	".\..\thotlib\internals\f\viewapi_f.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\include\registry.h"\
	

"$(INTDIR)\structlist.obj" : $(SOURCE) $(DEP_CPP_STRUC) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\Guetari\Opera\Thotlib\Base\Thotmsg.c

!IF  "$(CFG)" == "LibThotEditor - Win32 Release"

DEP_CPP_THOTM=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\include\libmsg.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\include\application.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\internals\f\viewcommands_f.h"\
	".\..\thotlib\include\sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\thotlib\internals\h\constint.h"\
	".\..\thotlib\internals\h\thotkey.h"\
	".\..\thotlib\internals\h\conststr.h"\
	".\..\thotlib\internals\h\constprs.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\include\fileaccess.h"\
	".\..\thotlib\include\registry.h"\
	
NODEP_CPP_THOTM=\
	".\..\thotlib\include\HTVMSUtils.h"\
	

"$(INTDIR)\Thotmsg.obj" : $(SOURCE) $(DEP_CPP_THOTM) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "LibThotEditor - Win32 Debug"

DEP_CPP_THOTM=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\include\libmsg.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\include\application.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\internals\f\viewcommands_f.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\include\fileaccess.h"\
	".\..\thotlib\include\registry.h"\
	

"$(INTDIR)\Thotmsg.obj" : $(SOURCE) $(DEP_CPP_THOTM) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\Guetari\Opera\Thotlib\Base\Units.c

!IF  "$(CFG)" == "LibThotEditor - Win32 Release"

DEP_CPP_UNITS=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\internals\h\frame.h"\
	".\..\thotlib\internals\var\units_tv.h"\
	".\..\thotlib\internals\var\frame_tv.h"\
	".\..\thotlib\include\sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\thotlib\internals\h\constint.h"\
	".\..\thotlib\internals\h\thotkey.h"\
	".\..\thotlib\internals\h\conststr.h"\
	".\..\thotlib\internals\h\constprs.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\internals\h\constmenu.h"\
	
NODEP_CPP_UNITS=\
	".\..\thotlib\include\HTVMSUtils.h"\
	

"$(INTDIR)\Units.obj" : $(SOURCE) $(DEP_CPP_UNITS) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "LibThotEditor - Win32 Debug"

DEP_CPP_UNITS=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\internals\h\frame.h"\
	".\..\thotlib\internals\var\units_tv.h"\
	".\..\thotlib\internals\var\frame_tv.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\internals\h\constmenu.h"\
	

"$(INTDIR)\Units.obj" : $(SOURCE) $(DEP_CPP_UNITS) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\Guetari\Opera\Thotlib\Document\Docs.c

!IF  "$(CFG)" == "LibThotEditor - Win32 Release"

DEP_CPP_DOCS_=\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmenu.h"\
	".\..\thotlib\include\libmsg.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\include\fileaccess.h"\
	".\..\thotlib\internals\h\appdialogue.h"\
	".\..\thotlib\internals\h\thotdir.h"\
	".\..\thotlib\internals\var\platform_tv.h"\
	".\..\thotlib\internals\var\print_tv.h"\
	".\..\thotlib\internals\var\modif_tv.h"\
	".\..\thotlib\internals\var\page_tv.h"\
	".\..\thotlib\internals\var\select_tv.h"\
	".\..\thotlib\internals\var\edit_tv.h"\
	".\..\thotlib\internals\var\frame_tv.h"\
	".\..\thotlib\internals\var\appdialogue_tv.h"\
	".\..\thotlib\internals\f\absboxes_f.h"\
	".\..\thotlib\internals\f\appli_f.h"\
	".\..\thotlib\internals\f\appdialogue_f.h"\
	".\..\thotlib\internals\f\applicationapi_f.h"\
	".\..\thotlib\internals\f\attributes_f.h"\
	".\..\thotlib\internals\f\boxselection_f.h"\
	".\..\thotlib\internals\f\buildboxes_f.h"\
	".\..\thotlib\internals\f\callback_f.h"\
	".\..\thotlib\internals\f\changeabsbox_f.h"\
	".\..\thotlib\internals\f\config_f.h"\
	".\..\thotlib\internals\f\createabsbox_f.h"\
	".\..\thotlib\internals\f\createpages_f.h"\
	".\..\thotlib\internals\f\docs_f.h"\
	".\..\thotlib\internals\f\draw_f.h"\
	".\..\thotlib\internals\f\fileaccess_f.h"\
	".\..\thotlib\internals\f\memory_f.h"\
	".\..\thotlib\internals\f\paginate_f.h"\
	".\..\thotlib\internals\f\platform_f.h"\
	".\..\thotlib\internals\f\presvariables_f.h"\
	".\..\thotlib\internals\f\readpivot_f.h"\
	".\..\thotlib\internals\f\references_f.h"\
	".\..\thotlib\internals\f\search_f.h"\
	".\..\thotlib\internals\f\searchref_f.h"\
	".\..\thotlib\internals\f\structschema_f.h"\
	".\..\thotlib\internals\f\structmodif_f.h"\
	".\..\thotlib\internals\f\structcommands_f.h"\
	".\..\thotlib\internals\f\structcreation_f.h"\
	".\..\thotlib\internals\f\structselect_f.h"\
	".\..\thotlib\internals\f\tree_f.h"\
	".\..\thotlib\internals\f\views_f.h"\
	".\..\thotlib\internals\f\viewapi_f.h"\
	".\..\thotlib\internals\f\viewcommands_f.h"\
	".\..\thotlib\internals\f\schemas_f.h"\
	".\..\thotlib\internals\f\writepivot_f.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\thotlib\internals\h\constint.h"\
	".\..\thotlib\internals\h\thotkey.h"\
	".\..\thotlib\internals\h\conststr.h"\
	".\..\thotlib\internals\h\constprs.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\internals\h\frame.h"\
	
NODEP_CPP_DOCS_=\
	".\..\thotlib\include\HTVMSUtils.h"\
	

"$(INTDIR)\Docs.obj" : $(SOURCE) $(DEP_CPP_DOCS_) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "LibThotEditor - Win32 Debug"

DEP_CPP_DOCS_=\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmenu.h"\
	".\..\thotlib\include\libmsg.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\include\fileaccess.h"\
	".\..\thotlib\internals\h\appdialogue.h"\
	".\..\thotlib\internals\h\thotdir.h"\
	".\..\thotlib\internals\var\platform_tv.h"\
	".\..\thotlib\internals\var\print_tv.h"\
	".\..\thotlib\internals\var\modif_tv.h"\
	".\..\thotlib\internals\var\page_tv.h"\
	".\..\thotlib\internals\var\select_tv.h"\
	".\..\thotlib\internals\var\edit_tv.h"\
	".\..\thotlib\internals\var\frame_tv.h"\
	".\..\thotlib\internals\var\appdialogue_tv.h"\
	".\..\thotlib\internals\f\absboxes_f.h"\
	".\..\thotlib\internals\f\appli_f.h"\
	".\..\thotlib\internals\f\appdialogue_f.h"\
	".\..\thotlib\internals\f\applicationapi_f.h"\
	".\..\thotlib\internals\f\attributes_f.h"\
	".\..\thotlib\internals\f\boxselection_f.h"\
	".\..\thotlib\internals\f\buildboxes_f.h"\
	".\..\thotlib\internals\f\callback_f.h"\
	".\..\thotlib\internals\f\changeabsbox_f.h"\
	".\..\thotlib\internals\f\config_f.h"\
	".\..\thotlib\internals\f\createabsbox_f.h"\
	".\..\thotlib\internals\f\createpages_f.h"\
	".\..\thotlib\internals\f\docs_f.h"\
	".\..\thotlib\internals\f\draw_f.h"\
	".\..\thotlib\internals\f\fileaccess_f.h"\
	".\..\thotlib\internals\f\memory_f.h"\
	".\..\thotlib\internals\f\paginate_f.h"\
	".\..\thotlib\internals\f\platform_f.h"\
	".\..\thotlib\internals\f\presvariables_f.h"\
	".\..\thotlib\internals\f\readpivot_f.h"\
	".\..\thotlib\internals\f\references_f.h"\
	".\..\thotlib\internals\f\search_f.h"\
	".\..\thotlib\internals\f\searchref_f.h"\
	".\..\thotlib\internals\f\structschema_f.h"\
	".\..\thotlib\internals\f\structmodif_f.h"\
	".\..\thotlib\internals\f\structcommands_f.h"\
	".\..\thotlib\internals\f\structcreation_f.h"\
	".\..\thotlib\internals\f\structselect_f.h"\
	".\..\thotlib\internals\f\tree_f.h"\
	".\..\thotlib\internals\f\views_f.h"\
	".\..\thotlib\internals\f\viewapi_f.h"\
	".\..\thotlib\internals\f\viewcommands_f.h"\
	".\..\thotlib\internals\f\schemas_f.h"\
	".\..\thotlib\internals\f\writepivot_f.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\internals\h\frame.h"\
	

"$(INTDIR)\Docs.obj" : $(SOURCE) $(DEP_CPP_DOCS_) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\Guetari\Opera\Thotlib\Document\documentapi.c

!IF  "$(CFG)" == "LibThotEditor - Win32 Release"

DEP_CPP_DOCUM=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\include\application.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\fileaccess.h"\
	".\..\thotlib\internals\h\constpiv.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\appdialogue.h"\
	".\..\thotlib\internals\h\thotdir.h"\
	".\..\thotlib\internals\var\select_tv.h"\
	".\..\thotlib\internals\var\edit_tv.h"\
	".\..\thotlib\internals\var\platform_tv.h"\
	".\..\thotlib\internals\var\modif_tv.h"\
	".\..\thotlib\internals\var\appdialogue_tv.h"\
	".\..\thotlib\internals\f\tree_f.h"\
	".\..\thotlib\internals\f\attributes_f.h"\
	".\..\thotlib\internals\f\config_f.h"\
	".\..\thotlib\internals\f\views_f.h"\
	".\..\thotlib\internals\f\viewapi_f.h"\
	".\..\thotlib\internals\f\draw_f.h"\
	".\..\thotlib\internals\f\translation_f.h"\
	".\..\thotlib\internals\f\memory_f.h"\
	".\..\thotlib\internals\f\writepivot_f.h"\
	".\..\thotlib\internals\f\readpivot_f.h"\
	".\..\thotlib\internals\f\readstr_f.h"\
	".\..\thotlib\internals\f\references_f.h"\
	".\..\thotlib\internals\f\externalref_f.h"\
	".\..\thotlib\internals\f\schemas_f.h"\
	".\..\thotlib\internals\f\fileaccess_f.h"\
	".\..\thotlib\internals\f\structschema_f.h"\
	".\..\thotlib\internals\f\thotmsg_f.h"\
	".\..\thotlib\internals\f\docs_f.h"\
	".\..\thotlib\internals\f\applicationapi_f.h"\
	".\..\thotlib\internals\f\platform_f.h"\
	".\..\thotlib\internals\f\appdialogue_f.h"\
	".\..\thotlib\include\sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\thotlib\internals\h\constint.h"\
	".\..\thotlib\internals\h\thotkey.h"\
	".\..\thotlib\internals\h\conststr.h"\
	".\..\thotlib\internals\h\constprs.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\include\registry.h"\
	".\..\thotlib\internals\h\frame.h"\
	".\..\thotlib\internals\h\constmenu.h"\
	
NODEP_CPP_DOCUM=\
	".\..\thotlib\include\HTVMSUtils.h"\
	

"$(INTDIR)\documentapi.obj" : $(SOURCE) $(DEP_CPP_DOCUM) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "LibThotEditor - Win32 Debug"

DEP_CPP_DOCUM=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\include\application.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\fileaccess.h"\
	".\..\thotlib\internals\h\constpiv.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\appdialogue.h"\
	".\..\thotlib\internals\h\thotdir.h"\
	".\..\thotlib\internals\var\select_tv.h"\
	".\..\thotlib\internals\var\edit_tv.h"\
	".\..\thotlib\internals\var\platform_tv.h"\
	".\..\thotlib\internals\var\modif_tv.h"\
	".\..\thotlib\internals\var\appdialogue_tv.h"\
	".\..\thotlib\internals\f\tree_f.h"\
	".\..\thotlib\internals\f\attributes_f.h"\
	".\..\thotlib\internals\f\config_f.h"\
	".\..\thotlib\internals\f\views_f.h"\
	".\..\thotlib\internals\f\viewapi_f.h"\
	".\..\thotlib\internals\f\draw_f.h"\
	".\..\thotlib\internals\f\translation_f.h"\
	".\..\thotlib\internals\f\memory_f.h"\
	".\..\thotlib\internals\f\writepivot_f.h"\
	".\..\thotlib\internals\f\readpivot_f.h"\
	".\..\thotlib\internals\f\readstr_f.h"\
	".\..\thotlib\internals\f\references_f.h"\
	".\..\thotlib\internals\f\externalref_f.h"\
	".\..\thotlib\internals\f\schemas_f.h"\
	".\..\thotlib\internals\f\fileaccess_f.h"\
	".\..\thotlib\internals\f\structschema_f.h"\
	".\..\thotlib\internals\f\thotmsg_f.h"\
	".\..\thotlib\internals\f\docs_f.h"\
	".\..\thotlib\internals\f\applicationapi_f.h"\
	".\..\thotlib\internals\f\platform_f.h"\
	".\..\thotlib\internals\f\appdialogue_f.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\include\registry.h"\
	".\..\thotlib\internals\h\frame.h"\
	".\..\thotlib\internals\h\constmenu.h"\
	

"$(INTDIR)\documentapi.obj" : $(SOURCE) $(DEP_CPP_DOCUM) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\Guetari\Opera\Thotlib\Document\externalref.c

!IF  "$(CFG)" == "LibThotEditor - Win32 Release"

DEP_CPP_EXTER=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\constpiv.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\include\fileaccess.h"\
	".\..\thotlib\internals\var\edit_tv.h"\
	".\..\thotlib\internals\f\tree_f.h"\
	".\..\thotlib\internals\f\memory_f.h"\
	".\..\thotlib\internals\f\references_f.h"\
	".\..\thotlib\internals\f\readpivot_f.h"\
	".\..\thotlib\internals\f\fileaccess_f.h"\
	".\..\thotlib\internals\f\message_f.h"\
	".\..\thotlib\include\sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\thotlib\internals\h\constint.h"\
	".\..\thotlib\internals\h\thotkey.h"\
	".\..\thotlib\internals\h\conststr.h"\
	".\..\thotlib\internals\h\constprs.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	
NODEP_CPP_EXTER=\
	".\..\thotlib\include\HTVMSUtils.h"\
	

"$(INTDIR)\externalref.obj" : $(SOURCE) $(DEP_CPP_EXTER) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "LibThotEditor - Win32 Debug"

DEP_CPP_EXTER=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\constpiv.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\include\fileaccess.h"\
	".\..\thotlib\internals\var\edit_tv.h"\
	".\..\thotlib\internals\f\tree_f.h"\
	".\..\thotlib\internals\f\memory_f.h"\
	".\..\thotlib\internals\f\references_f.h"\
	".\..\thotlib\internals\f\readpivot_f.h"\
	".\..\thotlib\internals\f\fileaccess_f.h"\
	".\..\thotlib\internals\f\message_f.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	

"$(INTDIR)\externalref.obj" : $(SOURCE) $(DEP_CPP_EXTER) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\Guetari\Opera\Thotlib\Document\Language.c

!IF  "$(CFG)" == "LibThotEditor - Win32 Release"

DEP_CPP_LANGU=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\include\libmsg.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\application.h"\
	".\..\thotlib\internals\h\dictionary.h"\
	".\..\thotlib\internals\f\thotmsg_f.h"\
	".\..\thotlib\include\sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\thotlib\internals\h\constint.h"\
	".\..\thotlib\internals\h\thotkey.h"\
	".\..\thotlib\internals\h\conststr.h"\
	".\..\thotlib\internals\h\constprs.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\include\fileaccess.h"\
	".\..\thotlib\include\registry.h"\
	
NODEP_CPP_LANGU=\
	".\..\thotlib\include\HTVMSUtils.h"\
	

"$(INTDIR)\Language.obj" : $(SOURCE) $(DEP_CPP_LANGU) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "LibThotEditor - Win32 Debug"

DEP_CPP_LANGU=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\include\libmsg.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\application.h"\
	".\..\thotlib\internals\h\dictionary.h"\
	".\..\thotlib\internals\f\thotmsg_f.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\include\fileaccess.h"\
	".\..\thotlib\include\registry.h"\
	

"$(INTDIR)\Language.obj" : $(SOURCE) $(DEP_CPP_LANGU) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\Guetari\Opera\Thotlib\Document\Pivot.c

!IF  "$(CFG)" == "LibThotEditor - Win32 Release"

DEP_CPP_PIVOT=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\include\fileaccess.h"\
	".\..\thotlib\include\application.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\constpiv.h"\
	".\..\thotlib\include\labelAllocator.h"\
	".\..\thotlib\internals\f\tree_f.h"\
	".\..\thotlib\internals\f\thotmsg_f.h"\
	".\..\thotlib\internals\f\structschema_f.h"\
	".\..\thotlib\internals\f\applicationapi_f.h"\
	".\..\thotlib\internals\f\writepivot_f.h"\
	".\..\thotlib\internals\f\readpivot_f.h"\
	".\..\thotlib\internals\f\fileaccess_f.h"\
	".\..\thotlib\internals\f\callback_f.h"\
	".\..\thotlib\internals\f\externalref_f.h"\
	".\..\thotlib\internals\f\labelalloc_f.h"\
	".\..\thotlib\internals\var\edit_tv.h"\
	".\..\thotlib\include\sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\thotlib\internals\h\constint.h"\
	".\..\thotlib\internals\h\thotkey.h"\
	".\..\thotlib\internals\h\conststr.h"\
	".\..\thotlib\internals\h\constprs.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\include\registry.h"\
	
NODEP_CPP_PIVOT=\
	".\..\thotlib\include\HTVMSUtils.h"\
	

"$(INTDIR)\Pivot.obj" : $(SOURCE) $(DEP_CPP_PIVOT) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "LibThotEditor - Win32 Debug"

DEP_CPP_PIVOT=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\include\fileaccess.h"\
	".\..\thotlib\include\application.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\constpiv.h"\
	".\..\thotlib\include\labelAllocator.h"\
	".\..\thotlib\internals\f\tree_f.h"\
	".\..\thotlib\internals\f\thotmsg_f.h"\
	".\..\thotlib\internals\f\structschema_f.h"\
	".\..\thotlib\internals\f\applicationapi_f.h"\
	".\..\thotlib\internals\f\writepivot_f.h"\
	".\..\thotlib\internals\f\readpivot_f.h"\
	".\..\thotlib\internals\f\fileaccess_f.h"\
	".\..\thotlib\internals\f\callback_f.h"\
	".\..\thotlib\internals\f\externalref_f.h"\
	".\..\thotlib\internals\f\labelalloc_f.h"\
	".\..\thotlib\internals\var\edit_tv.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\include\registry.h"\
	

"$(INTDIR)\Pivot.obj" : $(SOURCE) $(DEP_CPP_PIVOT) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\Guetari\Opera\Thotlib\Document\readpivot.c

!IF  "$(CFG)" == "LibThotEditor - Win32 Release"

DEP_CPP_READP=\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\constpiv.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\internals\h\picture.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\libmsg.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\include\fileaccess.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\appdialogue.h"\
	".\..\thotlib\include\labelAllocator.h"\
	".\..\thotlib\include\registry.h"\
	".\..\thotlib\internals\var\edit_tv.h"\
	".\..\thotlib\internals\var\appdialogue_tv.h"\
	".\..\thotlib\internals\var\platform_tv.h"\
	".\..\thotlib\internals\f\abspictures_f.h"\
	".\..\thotlib\internals\f\applicationapi_f.h"\
	".\..\thotlib\internals\f\callback_f.h"\
	".\..\thotlib\internals\f\changeabsbox_f.h"\
	".\..\thotlib\internals\f\content_f.h"\
	".\..\thotlib\internals\f\externalref_f.h"\
	".\..\thotlib\internals\f\exceptions_f.h"\
	".\..\thotlib\internals\f\fileaccess_f.h"\
	".\..\thotlib\internals\f\font_f.h"\
	".\..\thotlib\internals\f\labelalloc_f.h"\
	".\..\thotlib\internals\f\language_f.h"\
	".\..\thotlib\internals\f\memory_f.h"\
	".\..\thotlib\internals\f\message_f.h"\
	".\..\thotlib\internals\f\readpivot_f.h"\
	".\..\thotlib\internals\f\references_f.h"\
	".\..\thotlib\internals\f\schemas_f.h"\
	".\..\thotlib\internals\f\structcreation_f.h"\
	".\..\thotlib\internals\f\structschema_f.h"\
	".\..\thotlib\internals\f\tree_f.h"\
	".\..\thotlib\internals\f\units_f.h"\
	".\..\thotlib\internals\f\viewcommands_f.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\thotlib\internals\h\constint.h"\
	".\..\thotlib\internals\h\thotkey.h"\
	".\..\thotlib\internals\h\conststr.h"\
	".\..\thotlib\internals\h\constprs.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\internals\h\frame.h"\
	".\..\thotlib\internals\h\constmenu.h"\
	
NODEP_CPP_READP=\
	".\..\thotlib\include\HTVMSUtils.h"\
	

"$(INTDIR)\readpivot.obj" : $(SOURCE) $(DEP_CPP_READP) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "LibThotEditor - Win32 Debug"

DEP_CPP_READP=\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\constpiv.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\internals\h\picture.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\libmsg.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\include\fileaccess.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\appdialogue.h"\
	".\..\thotlib\include\labelAllocator.h"\
	".\..\thotlib\include\registry.h"\
	".\..\thotlib\internals\var\edit_tv.h"\
	".\..\thotlib\internals\var\appdialogue_tv.h"\
	".\..\thotlib\internals\var\platform_tv.h"\
	".\..\thotlib\internals\f\abspictures_f.h"\
	".\..\thotlib\internals\f\applicationapi_f.h"\
	".\..\thotlib\internals\f\callback_f.h"\
	".\..\thotlib\internals\f\changeabsbox_f.h"\
	".\..\thotlib\internals\f\content_f.h"\
	".\..\thotlib\internals\f\externalref_f.h"\
	".\..\thotlib\internals\f\exceptions_f.h"\
	".\..\thotlib\internals\f\fileaccess_f.h"\
	".\..\thotlib\internals\f\font_f.h"\
	".\..\thotlib\internals\f\labelalloc_f.h"\
	".\..\thotlib\internals\f\language_f.h"\
	".\..\thotlib\internals\f\memory_f.h"\
	".\..\thotlib\internals\f\message_f.h"\
	".\..\thotlib\internals\f\readpivot_f.h"\
	".\..\thotlib\internals\f\references_f.h"\
	".\..\thotlib\internals\f\schemas_f.h"\
	".\..\thotlib\internals\f\structcreation_f.h"\
	".\..\thotlib\internals\f\structschema_f.h"\
	".\..\thotlib\internals\f\tree_f.h"\
	".\..\thotlib\internals\f\units_f.h"\
	".\..\thotlib\internals\f\viewcommands_f.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\internals\h\frame.h"\
	".\..\thotlib\internals\h\constmenu.h"\
	

"$(INTDIR)\readpivot.obj" : $(SOURCE) $(DEP_CPP_READP) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\Guetari\Opera\Thotlib\Document\Readprs.c

!IF  "$(CFG)" == "LibThotEditor - Win32 Release"

DEP_CPP_READPR=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\constpiv.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\include\fileaccess.h"\
	".\..\thotlib\include\libmsg.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\internals\var\platform_tv.h"\
	".\..\thotlib\internals\f\fileaccess_f.h"\
	".\..\thotlib\internals\f\memory_f.h"\
	".\..\thotlib\internals\f\readstr_f.h"\
	".\..\thotlib\internals\f\readprs_f.h"\
	".\..\thotlib\include\sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\thotlib\internals\h\constint.h"\
	".\..\thotlib\internals\h\thotkey.h"\
	".\..\thotlib\internals\h\conststr.h"\
	".\..\thotlib\internals\h\constprs.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	
NODEP_CPP_READPR=\
	".\..\thotlib\include\HTVMSUtils.h"\
	

"$(INTDIR)\Readprs.obj" : $(SOURCE) $(DEP_CPP_READPR) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "LibThotEditor - Win32 Debug"

DEP_CPP_READPR=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\constpiv.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\include\fileaccess.h"\
	".\..\thotlib\include\libmsg.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\internals\var\platform_tv.h"\
	".\..\thotlib\internals\f\fileaccess_f.h"\
	".\..\thotlib\internals\f\memory_f.h"\
	".\..\thotlib\internals\f\readstr_f.h"\
	".\..\thotlib\internals\f\readprs_f.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	

"$(INTDIR)\Readprs.obj" : $(SOURCE) $(DEP_CPP_READPR) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\Guetari\Opera\Thotlib\Document\Readstr.c

!IF  "$(CFG)" == "LibThotEditor - Win32 Release"

DEP_CPP_READS=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\include\libmsg.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\include\fileaccess.h"\
	".\..\thotlib\internals\var\platform_tv.h"\
	".\..\thotlib\internals\f\fileaccess_f.h"\
	".\..\thotlib\internals\f\readstr_f.h"\
	".\..\thotlib\internals\f\memory_f.h"\
	".\..\thotlib\include\sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\thotlib\internals\h\constint.h"\
	".\..\thotlib\internals\h\thotkey.h"\
	".\..\thotlib\internals\h\conststr.h"\
	".\..\thotlib\internals\h\constprs.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	
NODEP_CPP_READS=\
	".\..\thotlib\include\HTVMSUtils.h"\
	

"$(INTDIR)\Readstr.obj" : $(SOURCE) $(DEP_CPP_READS) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "LibThotEditor - Win32 Debug"

DEP_CPP_READS=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\include\libmsg.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\include\fileaccess.h"\
	".\..\thotlib\internals\var\platform_tv.h"\
	".\..\thotlib\internals\f\fileaccess_f.h"\
	".\..\thotlib\internals\f\readstr_f.h"\
	".\..\thotlib\internals\f\memory_f.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	

"$(INTDIR)\Readstr.obj" : $(SOURCE) $(DEP_CPP_READS) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\Guetari\Opera\Thotlib\Document\Readtra.c

!IF  "$(CFG)" == "LibThotEditor - Win32 Release"

DEP_CPP_READT=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\include\libmsg.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\include\fileaccess.h"\
	".\..\thotlib\internals\var\platform_tv.h"\
	".\..\thotlib\internals\f\readtra_f.h"\
	".\..\thotlib\internals\f\memory_f.h"\
	".\..\thotlib\internals\f\fileaccess_f.h"\
	".\..\thotlib\internals\f\message_f.h"\
	".\..\thotlib\include\sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\thotlib\internals\h\constint.h"\
	".\..\thotlib\internals\h\thotkey.h"\
	".\..\thotlib\internals\h\conststr.h"\
	".\..\thotlib\internals\h\constprs.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	
NODEP_CPP_READT=\
	".\..\thotlib\include\HTVMSUtils.h"\
	

"$(INTDIR)\Readtra.obj" : $(SOURCE) $(DEP_CPP_READT) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "LibThotEditor - Win32 Debug"

DEP_CPP_READT=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\include\libmsg.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\include\fileaccess.h"\
	".\..\thotlib\internals\var\platform_tv.h"\
	".\..\thotlib\internals\f\readtra_f.h"\
	".\..\thotlib\internals\f\memory_f.h"\
	".\..\thotlib\internals\f\fileaccess_f.h"\
	".\..\thotlib\internals\f\message_f.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	

"$(INTDIR)\Readtra.obj" : $(SOURCE) $(DEP_CPP_READT) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\Guetari\Opera\Thotlib\Document\Schemas.c

!IF  "$(CFG)" == "LibThotEditor - Win32 Release"

DEP_CPP_SCHEM=\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\include\libmsg.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\include\fileaccess.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\internals\h\appdialogue.h"\
	".\..\thotlib\internals\var\edit_tv.h"\
	".\..\thotlib\internals\var\appdialogue_tv.h"\
	".\..\thotlib\internals\f\config_f.h"\
	".\..\thotlib\internals\f\memory_f.h"\
	".\..\thotlib\internals\f\readstr_f.h"\
	".\..\thotlib\internals\f\readprs_f.h"\
	".\..\thotlib\internals\f\schemas_f.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\thotlib\internals\h\constint.h"\
	".\..\thotlib\internals\h\thotkey.h"\
	".\..\thotlib\internals\h\conststr.h"\
	".\..\thotlib\internals\h\constprs.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\frame.h"\
	".\..\thotlib\internals\h\constmenu.h"\
	
NODEP_CPP_SCHEM=\
	".\..\thotlib\include\HTVMSUtils.h"\
	

"$(INTDIR)\Schemas.obj" : $(SOURCE) $(DEP_CPP_SCHEM) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "LibThotEditor - Win32 Debug"

DEP_CPP_SCHEM=\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\include\libmsg.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\include\fileaccess.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\internals\h\appdialogue.h"\
	".\..\thotlib\internals\var\edit_tv.h"\
	".\..\thotlib\internals\var\appdialogue_tv.h"\
	".\..\thotlib\internals\f\config_f.h"\
	".\..\thotlib\internals\f\memory_f.h"\
	".\..\thotlib\internals\f\readstr_f.h"\
	".\..\thotlib\internals\f\readprs_f.h"\
	".\..\thotlib\internals\f\schemas_f.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\frame.h"\
	".\..\thotlib\internals\h\constmenu.h"\
	

"$(INTDIR)\Schemas.obj" : $(SOURCE) $(DEP_CPP_SCHEM) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\Guetari\Opera\Thotlib\Document\Schtrad.c

!IF  "$(CFG)" == "LibThotEditor - Win32 Release"

DEP_CPP_SCHTR=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\include\libmsg.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\var\edit_tv.h"\
	".\..\thotlib\internals\f\readstr_f.h"\
	".\..\thotlib\internals\f\readtra_f.h"\
	".\..\thotlib\internals\f\schemas_f.h"\
	".\..\thotlib\internals\f\schtrad_f.h"\
	".\..\thotlib\include\sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\thotlib\internals\h\constint.h"\
	".\..\thotlib\internals\h\thotkey.h"\
	".\..\thotlib\internals\h\conststr.h"\
	".\..\thotlib\internals\h\constprs.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	
NODEP_CPP_SCHTR=\
	".\..\thotlib\include\HTVMSUtils.h"\
	

"$(INTDIR)\Schtrad.obj" : $(SOURCE) $(DEP_CPP_SCHTR) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "LibThotEditor - Win32 Debug"

DEP_CPP_SCHTR=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\include\libmsg.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\var\edit_tv.h"\
	".\..\thotlib\internals\f\readstr_f.h"\
	".\..\thotlib\internals\f\readtra_f.h"\
	".\..\thotlib\internals\f\schemas_f.h"\
	".\..\thotlib\internals\f\schtrad_f.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	

"$(INTDIR)\Schtrad.obj" : $(SOURCE) $(DEP_CPP_SCHTR) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\Guetari\Opera\Thotlib\Document\translation.c

!IF  "$(CFG)" == "LibThotEditor - Win32 Release"

DEP_CPP_TRANS=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\fileaccess.h"\
	".\..\thotlib\include\libmsg.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\internals\var\platform_tv.h"\
	".\..\thotlib\internals\var\thotcolor_tv.h"\
	".\..\thotlib\internals\var\select_tv.h"\
	".\..\thotlib\internals\var\edit_tv.h"\
	".\..\thotlib\internals\f\tree_f.h"\
	".\..\thotlib\internals\f\callback_f.h"\
	".\..\thotlib\internals\f\translation_f.h"\
	".\..\thotlib\internals\f\absboxes_f.h"\
	".\..\thotlib\internals\f\memory_f.h"\
	".\..\thotlib\internals\f\readprs_f.h"\
	".\..\thotlib\internals\f\references_f.h"\
	".\..\thotlib\internals\f\externalref_f.h"\
	".\..\thotlib\internals\f\schemas_f.h"\
	".\..\thotlib\internals\f\schtrad_f.h"\
	".\..\thotlib\internals\f\fileaccess_f.h"\
	".\..\thotlib\internals\f\structschema_f.h"\
	".\..\thotlib\internals\f\content_f.h"\
	".\..\thotlib\internals\f\applicationapi_f.h"\
	".\..\thotlib\include\sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\thotlib\internals\h\constint.h"\
	".\..\thotlib\internals\h\thotkey.h"\
	".\..\thotlib\internals\h\conststr.h"\
	".\..\thotlib\internals\h\constprs.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\internals\h\thotcolor.h"\
	
NODEP_CPP_TRANS=\
	".\..\thotlib\include\HTVMSUtils.h"\
	

"$(INTDIR)\translation.obj" : $(SOURCE) $(DEP_CPP_TRANS) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "LibThotEditor - Win32 Debug"

DEP_CPP_TRANS=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\fileaccess.h"\
	".\..\thotlib\include\libmsg.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\internals\var\platform_tv.h"\
	".\..\thotlib\internals\var\thotcolor_tv.h"\
	".\..\thotlib\internals\var\select_tv.h"\
	".\..\thotlib\internals\var\edit_tv.h"\
	".\..\thotlib\internals\f\tree_f.h"\
	".\..\thotlib\internals\f\callback_f.h"\
	".\..\thotlib\internals\f\translation_f.h"\
	".\..\thotlib\internals\f\absboxes_f.h"\
	".\..\thotlib\internals\f\memory_f.h"\
	".\..\thotlib\internals\f\readprs_f.h"\
	".\..\thotlib\internals\f\references_f.h"\
	".\..\thotlib\internals\f\externalref_f.h"\
	".\..\thotlib\internals\f\schemas_f.h"\
	".\..\thotlib\internals\f\schtrad_f.h"\
	".\..\thotlib\internals\f\fileaccess_f.h"\
	".\..\thotlib\internals\f\structschema_f.h"\
	".\..\thotlib\internals\f\content_f.h"\
	".\..\thotlib\internals\f\applicationapi_f.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\internals\h\thotcolor.h"\
	

"$(INTDIR)\translation.obj" : $(SOURCE) $(DEP_CPP_TRANS) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\Guetari\Opera\Thotlib\Document\Views.c

!IF  "$(CFG)" == "LibThotEditor - Win32 Release"

DEP_CPP_VIEWS=\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmenu.h"\
	".\..\thotlib\include\libmsg.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\include\fileaccess.h"\
	".\..\thotlib\internals\h\appdialogue.h"\
	".\..\thotlib\internals\h\thotdir.h"\
	".\..\thotlib\internals\var\platform_tv.h"\
	".\..\thotlib\internals\var\modif_tv.h"\
	".\..\thotlib\internals\var\page_tv.h"\
	".\..\thotlib\internals\var\select_tv.h"\
	".\..\thotlib\internals\var\edit_tv.h"\
	".\..\thotlib\internals\var\frame_tv.h"\
	".\..\thotlib\internals\var\appdialogue_tv.h"\
	".\..\thotlib\internals\f\appli_f.h"\
	".\..\thotlib\internals\f\applicationapi_f.h"\
	".\..\thotlib\internals\f\tree_f.h"\
	".\..\thotlib\internals\f\attributes_f.h"\
	".\..\thotlib\internals\f\search_f.h"\
	".\..\thotlib\internals\f\searchref_f.h"\
	".\..\thotlib\internals\f\config_f.h"\
	".\..\thotlib\internals\f\structcreation_f.h"\
	".\..\thotlib\internals\f\createabsbox_f.h"\
	".\..\thotlib\internals\f\createpages_f.h"\
	".\..\thotlib\internals\f\views_f.h"\
	".\..\thotlib\internals\f\viewapi_f.h"\
	".\..\thotlib\internals\f\viewcommands_f.h"\
	".\..\thotlib\internals\f\draw_f.h"\
	".\..\thotlib\internals\f\callback_f.h"\
	".\..\thotlib\internals\f\platform_f.h"\
	".\..\thotlib\internals\f\absboxes_f.h"\
	".\..\thotlib\internals\f\buildboxes_f.h"\
	".\..\thotlib\internals\f\structmodif_f.h"\
	".\..\thotlib\internals\f\structcommands_f.h"\
	".\..\thotlib\internals\f\memory_f.h"\
	".\..\thotlib\internals\f\changeabsbox_f.h"\
	".\..\thotlib\internals\f\paginate_f.h"\
	".\..\thotlib\internals\f\writepivot_f.h"\
	".\..\thotlib\internals\f\schemas_f.h"\
	".\..\thotlib\internals\f\boxselection_f.h"\
	".\..\thotlib\internals\f\structselect_f.h"\
	".\..\thotlib\internals\f\fileaccess_f.h"\
	".\..\thotlib\internals\f\references_f.h"\
	".\..\thotlib\internals\f\structschema_f.h"\
	".\..\thotlib\internals\f\presvariables_f.h"\
	".\..\thotlib\internals\f\appdialogue_f.h"\
	".\..\thotlib\internals\f\actions_f.h"\
	".\..\thotlib\internals\f\docs_f.h"\
	".\..\thotlib\internals\f\frame_f.h"\
	".\..\thotlib\internals\f\closedoc_f.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\thotlib\internals\h\constint.h"\
	".\..\thotlib\internals\h\thotkey.h"\
	".\..\thotlib\internals\h\conststr.h"\
	".\..\thotlib\internals\h\constprs.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\internals\h\frame.h"\
	
NODEP_CPP_VIEWS=\
	".\..\thotlib\include\HTVMSUtils.h"\
	

"$(INTDIR)\Views.obj" : $(SOURCE) $(DEP_CPP_VIEWS) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "LibThotEditor - Win32 Debug"

DEP_CPP_VIEWS=\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmenu.h"\
	".\..\thotlib\include\libmsg.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\include\fileaccess.h"\
	".\..\thotlib\internals\h\appdialogue.h"\
	".\..\thotlib\internals\h\thotdir.h"\
	".\..\thotlib\internals\var\platform_tv.h"\
	".\..\thotlib\internals\var\modif_tv.h"\
	".\..\thotlib\internals\var\page_tv.h"\
	".\..\thotlib\internals\var\select_tv.h"\
	".\..\thotlib\internals\var\edit_tv.h"\
	".\..\thotlib\internals\var\frame_tv.h"\
	".\..\thotlib\internals\var\appdialogue_tv.h"\
	".\..\thotlib\internals\f\appli_f.h"\
	".\..\thotlib\internals\f\applicationapi_f.h"\
	".\..\thotlib\internals\f\tree_f.h"\
	".\..\thotlib\internals\f\attributes_f.h"\
	".\..\thotlib\internals\f\search_f.h"\
	".\..\thotlib\internals\f\searchref_f.h"\
	".\..\thotlib\internals\f\config_f.h"\
	".\..\thotlib\internals\f\structcreation_f.h"\
	".\..\thotlib\internals\f\createabsbox_f.h"\
	".\..\thotlib\internals\f\createpages_f.h"\
	".\..\thotlib\internals\f\views_f.h"\
	".\..\thotlib\internals\f\viewapi_f.h"\
	".\..\thotlib\internals\f\viewcommands_f.h"\
	".\..\thotlib\internals\f\draw_f.h"\
	".\..\thotlib\internals\f\callback_f.h"\
	".\..\thotlib\internals\f\platform_f.h"\
	".\..\thotlib\internals\f\absboxes_f.h"\
	".\..\thotlib\internals\f\buildboxes_f.h"\
	".\..\thotlib\internals\f\structmodif_f.h"\
	".\..\thotlib\internals\f\structcommands_f.h"\
	".\..\thotlib\internals\f\memory_f.h"\
	".\..\thotlib\internals\f\changeabsbox_f.h"\
	".\..\thotlib\internals\f\paginate_f.h"\
	".\..\thotlib\internals\f\writepivot_f.h"\
	".\..\thotlib\internals\f\schemas_f.h"\
	".\..\thotlib\internals\f\boxselection_f.h"\
	".\..\thotlib\internals\f\structselect_f.h"\
	".\..\thotlib\internals\f\fileaccess_f.h"\
	".\..\thotlib\internals\f\references_f.h"\
	".\..\thotlib\internals\f\structschema_f.h"\
	".\..\thotlib\internals\f\presvariables_f.h"\
	".\..\thotlib\internals\f\appdialogue_f.h"\
	".\..\thotlib\internals\f\actions_f.h"\
	".\..\thotlib\internals\f\docs_f.h"\
	".\..\thotlib\internals\f\frame_f.h"\
	".\..\thotlib\internals\f\closedoc_f.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\internals\h\frame.h"\
	

"$(INTDIR)\Views.obj" : $(SOURCE) $(DEP_CPP_VIEWS) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\Guetari\Opera\Thotlib\Document\writepivot.c

!IF  "$(CFG)" == "LibThotEditor - Win32 Release"

DEP_CPP_WRITE=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\include\libmsg.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\internals\h\picture.h"\
	".\..\thotlib\internals\h\constpiv.h"\
	".\..\thotlib\include\fileaccess.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\thotdir.h"\
	".\..\thotlib\include\labelAllocator.h"\
	".\..\thotlib\internals\var\modif_tv.h"\
	".\..\thotlib\internals\var\platform_tv.h"\
	".\..\thotlib\internals\f\tree_f.h"\
	".\..\thotlib\internals\f\attributes_f.h"\
	".\..\thotlib\internals\f\callback_f.h"\
	".\..\thotlib\internals\f\units_f.h"\
	".\..\thotlib\internals\f\memory_f.h"\
	".\..\thotlib\internals\f\structmodif_f.h"\
	".\..\thotlib\internals\f\changepresent_f.h"\
	".\..\thotlib\internals\f\language_f.h"\
	".\..\thotlib\internals\f\writepivot_f.h"\
	".\..\thotlib\internals\f\references_f.h"\
	".\..\thotlib\internals\f\externalref_f.h"\
	".\..\thotlib\internals\f\schemas_f.h"\
	".\..\thotlib\internals\f\fileaccess_f.h"\
	".\..\thotlib\internals\f\structschema_f.h"\
	".\..\thotlib\internals\f\content_f.h"\
	".\..\thotlib\internals\f\applicationapi_f.h"\
	".\..\thotlib\internals\f\platform_f.h"\
	".\..\thotlib\internals\f\readpivot_f.h"\
	".\..\thotlib\internals\f\labelalloc_f.h"\
	".\..\thotlib\include\sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\thotlib\internals\h\constint.h"\
	".\..\thotlib\internals\h\thotkey.h"\
	".\..\thotlib\internals\h\conststr.h"\
	".\..\thotlib\internals\h\constprs.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\simx.h"\
	
NODEP_CPP_WRITE=\
	".\..\thotlib\include\HTVMSUtils.h"\
	

"$(INTDIR)\writepivot.obj" : $(SOURCE) $(DEP_CPP_WRITE) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "LibThotEditor - Win32 Debug"

DEP_CPP_WRITE=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\include\libmsg.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\internals\h\picture.h"\
	".\..\thotlib\internals\h\constpiv.h"\
	".\..\thotlib\include\fileaccess.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\thotdir.h"\
	".\..\thotlib\include\labelAllocator.h"\
	".\..\thotlib\internals\var\modif_tv.h"\
	".\..\thotlib\internals\var\platform_tv.h"\
	".\..\thotlib\internals\f\tree_f.h"\
	".\..\thotlib\internals\f\attributes_f.h"\
	".\..\thotlib\internals\f\callback_f.h"\
	".\..\thotlib\internals\f\units_f.h"\
	".\..\thotlib\internals\f\memory_f.h"\
	".\..\thotlib\internals\f\structmodif_f.h"\
	".\..\thotlib\internals\f\changepresent_f.h"\
	".\..\thotlib\internals\f\language_f.h"\
	".\..\thotlib\internals\f\writepivot_f.h"\
	".\..\thotlib\internals\f\references_f.h"\
	".\..\thotlib\internals\f\externalref_f.h"\
	".\..\thotlib\internals\f\schemas_f.h"\
	".\..\thotlib\internals\f\fileaccess_f.h"\
	".\..\thotlib\internals\f\structschema_f.h"\
	".\..\thotlib\internals\f\content_f.h"\
	".\..\thotlib\internals\f\applicationapi_f.h"\
	".\..\thotlib\internals\f\platform_f.h"\
	".\..\thotlib\internals\f\readpivot_f.h"\
	".\..\thotlib\internals\f\labelalloc_f.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\simx.h"\
	

"$(INTDIR)\writepivot.obj" : $(SOURCE) $(DEP_CPP_WRITE) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\Guetari\Opera\Thotlib\Tree\Resmatch.c

!IF  "$(CFG)" == "LibThotEditor - Win32 Release"

DEP_CPP_RESMA=\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\include\application.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\selection.h"\
	".\..\thotlib\internals\h\conststr.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\constres.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\thotlib\include\fileaccess.h"\
	".\..\thotlib\include\registry.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	
NODEP_CPP_RESMA=\
	".\..\thotlib\include\HTVMSUtils.h"\
	

"$(INTDIR)\Resmatch.obj" : $(SOURCE) $(DEP_CPP_RESMA) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "LibThotEditor - Win32 Debug"

DEP_CPP_RESMA=\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\include\application.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\selection.h"\
	".\..\thotlib\internals\h\conststr.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\constres.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\fileaccess.h"\
	".\..\thotlib\include\registry.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	

"$(INTDIR)\Resmatch.obj" : $(SOURCE) $(DEP_CPP_RESMA) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\Guetari\Opera\Thotlib\Tree\attributes.c

!IF  "$(CFG)" == "LibThotEditor - Win32 Release"

DEP_CPP_ATTRI=\
	".\..\thotlib\include\libmsg.h"\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\internals\h\appdialogue.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\var\page_tv.h"\
	".\..\thotlib\internals\var\select_tv.h"\
	".\..\thotlib\internals\var\edit_tv.h"\
	".\..\thotlib\internals\var\appdialogue_tv.h"\
	".\..\thotlib\internals\f\tree_f.h"\
	".\..\thotlib\internals\f\attrpresent_f.h"\
	".\..\thotlib\internals\f\attrmenu_f.h"\
	".\..\thotlib\internals\f\structcreation_f.h"\
	".\..\thotlib\internals\f\createabsbox_f.h"\
	".\..\thotlib\internals\f\draw_f.h"\
	".\..\thotlib\internals\f\callback_f.h"\
	".\..\thotlib\internals\f\exceptions_f.h"\
	".\..\thotlib\internals\f\buildboxes_f.h"\
	".\..\thotlib\internals\f\memory_f.h"\
	".\..\thotlib\internals\f\structmodif_f.h"\
	".\..\thotlib\internals\f\changeabsbox_f.h"\
	".\..\thotlib\internals\f\references_f.h"\
	".\..\thotlib\internals\f\boxselection_f.h"\
	".\..\thotlib\internals\f\structselect_f.h"\
	".\..\thotlib\internals\f\structschema_f.h"\
	".\..\thotlib\internals\f\content_f.h"\
	".\..\thotlib\internals\f\presvariables_f.h"\
	".\..\thotlib\internals\f\applicationapi_f.h"\
	".\..\thotlib\internals\f\frame_f.h"\
	".\..\thotlib\include\sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\thotlib\internals\h\constint.h"\
	".\..\thotlib\internals\h\thotkey.h"\
	".\..\thotlib\internals\h\conststr.h"\
	".\..\thotlib\internals\h\constprs.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\frame.h"\
	".\..\thotlib\internals\h\constmenu.h"\
	
NODEP_CPP_ATTRI=\
	".\..\thotlib\include\HTVMSUtils.h"\
	

"$(INTDIR)\attributes.obj" : $(SOURCE) $(DEP_CPP_ATTRI) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "LibThotEditor - Win32 Debug"

DEP_CPP_ATTRI=\
	".\..\thotlib\include\libmsg.h"\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\internals\h\appdialogue.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\var\page_tv.h"\
	".\..\thotlib\internals\var\select_tv.h"\
	".\..\thotlib\internals\var\edit_tv.h"\
	".\..\thotlib\internals\var\appdialogue_tv.h"\
	".\..\thotlib\internals\f\tree_f.h"\
	".\..\thotlib\internals\f\attrpresent_f.h"\
	".\..\thotlib\internals\f\attrmenu_f.h"\
	".\..\thotlib\internals\f\structcreation_f.h"\
	".\..\thotlib\internals\f\createabsbox_f.h"\
	".\..\thotlib\internals\f\draw_f.h"\
	".\..\thotlib\internals\f\callback_f.h"\
	".\..\thotlib\internals\f\exceptions_f.h"\
	".\..\thotlib\internals\f\buildboxes_f.h"\
	".\..\thotlib\internals\f\memory_f.h"\
	".\..\thotlib\internals\f\structmodif_f.h"\
	".\..\thotlib\internals\f\changeabsbox_f.h"\
	".\..\thotlib\internals\f\references_f.h"\
	".\..\thotlib\internals\f\boxselection_f.h"\
	".\..\thotlib\internals\f\structselect_f.h"\
	".\..\thotlib\internals\f\structschema_f.h"\
	".\..\thotlib\internals\f\content_f.h"\
	".\..\thotlib\internals\f\presvariables_f.h"\
	".\..\thotlib\internals\f\applicationapi_f.h"\
	".\..\thotlib\internals\f\frame_f.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\frame.h"\
	".\..\thotlib\internals\h\constmenu.h"\
	

"$(INTDIR)\attributes.obj" : $(SOURCE) $(DEP_CPP_ATTRI) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\Guetari\Opera\Thotlib\Tree\checkaccess.c

!IF  "$(CFG)" == "LibThotEditor - Win32 Release"

DEP_CPP_CHECK=\
	".\..\thotlib\include\libmsg.h"\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\include\fileaccess.h"\
	".\..\thotlib\internals\h\res.h"\
	".\..\thotlib\include\labelAllocator.h"\
	".\..\thotlib\internals\h\appdialogue.h"\
	".\..\thotlib\internals\var\select_tv.h"\
	".\..\thotlib\internals\var\edit_tv.h"\
	".\..\thotlib\internals\var\appdialogue_tv.h"\
	".\..\thotlib\internals\f\memory_f.h"\
	".\..\thotlib\internals\f\schemas_f.h"\
	".\..\thotlib\internals\f\absboxes_f.h"\
	".\..\thotlib\internals\f\draw_f.h"\
	".\..\thotlib\internals\f\content_f.h"\
	".\..\thotlib\internals\f\references_f.h"\
	".\..\thotlib\internals\f\fileaccess_f.h"\
	".\..\thotlib\internals\f\structschema_f.h"\
	".\..\thotlib\internals\f\labelalloc_f.h"\
	".\..\thotlib\internals\f\actions_f.h"\
	".\..\thotlib\internals\f\tree_f.h"\
	".\..\thotlib\internals\f\exceptions_f.h"\
	".\..\thotlib\internals\f\abspictures_f.h"\
	".\..\thotlib\internals\f\externalref_f.h"\
	".\..\thotlib\include\sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\thotlib\internals\h\constint.h"\
	".\..\thotlib\internals\h\thotkey.h"\
	".\..\thotlib\internals\h\conststr.h"\
	".\..\thotlib\internals\h\constprs.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\internals\h\SelectRestruct.h"\
	".\..\thotlib\internals\h\resdynmsg.h"\
	".\..\thotlib\internals\h\frame.h"\
	".\..\thotlib\internals\h\constmenu.h"\
	
NODEP_CPP_CHECK=\
	".\..\thotlib\include\HTVMSUtils.h"\
	

"$(INTDIR)\checkaccess.obj" : $(SOURCE) $(DEP_CPP_CHECK) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "LibThotEditor - Win32 Debug"

DEP_CPP_CHECK=\
	".\..\thotlib\include\libmsg.h"\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\include\fileaccess.h"\
	".\..\thotlib\internals\h\res.h"\
	".\..\thotlib\include\labelAllocator.h"\
	".\..\thotlib\internals\h\appdialogue.h"\
	".\..\thotlib\internals\var\select_tv.h"\
	".\..\thotlib\internals\var\edit_tv.h"\
	".\..\thotlib\internals\var\appdialogue_tv.h"\
	".\..\thotlib\internals\f\memory_f.h"\
	".\..\thotlib\internals\f\schemas_f.h"\
	".\..\thotlib\internals\f\absboxes_f.h"\
	".\..\thotlib\internals\f\draw_f.h"\
	".\..\thotlib\internals\f\content_f.h"\
	".\..\thotlib\internals\f\references_f.h"\
	".\..\thotlib\internals\f\fileaccess_f.h"\
	".\..\thotlib\internals\f\structschema_f.h"\
	".\..\thotlib\internals\f\labelalloc_f.h"\
	".\..\thotlib\internals\f\actions_f.h"\
	".\..\thotlib\internals\f\tree_f.h"\
	".\..\thotlib\internals\f\exceptions_f.h"\
	".\..\thotlib\internals\f\abspictures_f.h"\
	".\..\thotlib\internals\f\externalref_f.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\internals\h\SelectRestruct.h"\
	".\..\thotlib\internals\h\resdynmsg.h"\
	".\..\thotlib\internals\h\frame.h"\
	".\..\thotlib\internals\h\constmenu.h"\
	

"$(INTDIR)\checkaccess.obj" : $(SOURCE) $(DEP_CPP_CHECK) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\Guetari\Opera\Thotlib\Tree\Draw.c

!IF  "$(CFG)" == "LibThotEditor - Win32 Release"

DEP_CPP_DRAW_=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\include\libmsg.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\internals\f\tree_f.h"\
	".\..\thotlib\internals\f\memory_f.h"\
	".\..\thotlib\internals\f\exceptions_f.h"\
	".\..\thotlib\internals\f\structselect_f.h"\
	".\..\thotlib\internals\f\draw_f.h"\
	".\..\thotlib\include\sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\thotlib\internals\h\constint.h"\
	".\..\thotlib\internals\h\thotkey.h"\
	".\..\thotlib\internals\h\conststr.h"\
	".\..\thotlib\internals\h\constprs.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	
NODEP_CPP_DRAW_=\
	".\..\thotlib\include\HTVMSUtils.h"\
	

"$(INTDIR)\Draw.obj" : $(SOURCE) $(DEP_CPP_DRAW_) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "LibThotEditor - Win32 Debug"

DEP_CPP_DRAW_=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\include\libmsg.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\internals\f\tree_f.h"\
	".\..\thotlib\internals\f\memory_f.h"\
	".\..\thotlib\internals\f\exceptions_f.h"\
	".\..\thotlib\internals\f\structselect_f.h"\
	".\..\thotlib\internals\f\draw_f.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	

"$(INTDIR)\Draw.obj" : $(SOURCE) $(DEP_CPP_DRAW_) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\Guetari\Opera\Thotlib\Tree\exceptions.c

!IF  "$(CFG)" == "LibThotEditor - Win32 Release"

DEP_CPP_EXCEP=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\internals\var\edit_tv.h"\
	".\..\thotlib\internals\f\exceptions_f.h"\
	".\..\thotlib\internals\f\structschema_f.h"\
	".\..\thotlib\include\sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\thotlib\include\libmsg.h"\
	".\..\thotlib\internals\h\constint.h"\
	".\..\thotlib\internals\h\thotkey.h"\
	".\..\thotlib\internals\h\conststr.h"\
	".\..\thotlib\internals\h\constprs.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	
NODEP_CPP_EXCEP=\
	".\..\thotlib\include\HTVMSUtils.h"\
	

"$(INTDIR)\exceptions.obj" : $(SOURCE) $(DEP_CPP_EXCEP) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "LibThotEditor - Win32 Debug"

DEP_CPP_EXCEP=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\internals\var\edit_tv.h"\
	".\..\thotlib\internals\f\exceptions_f.h"\
	".\..\thotlib\internals\f\structschema_f.h"\
	".\..\thotlib\include\libmsg.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	

"$(INTDIR)\exceptions.obj" : $(SOURCE) $(DEP_CPP_EXCEP) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\Guetari\Opera\Thotlib\Tree\labelalloc.c

!IF  "$(CFG)" == "LibThotEditor - Win32 Release"

DEP_CPP_LABEL=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constint.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\labelAllocator.h"\
	".\..\thotlib\internals\f\applicationapi_f.h"\
	".\..\thotlib\include\sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\thotlib\internals\h\conststr.h"\
	".\..\thotlib\internals\h\constprs.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	
NODEP_CPP_LABEL=\
	".\..\thotlib\include\HTVMSUtils.h"\
	

"$(INTDIR)\labelalloc.obj" : $(SOURCE) $(DEP_CPP_LABEL) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "LibThotEditor - Win32 Debug"

DEP_CPP_LABEL=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constint.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\labelAllocator.h"\
	".\..\thotlib\internals\f\applicationapi_f.h"\
	".\..\thotlib\internals\h\conststr.h"\
	".\..\thotlib\internals\h\constprs.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	

"$(INTDIR)\labelalloc.obj" : $(SOURCE) $(DEP_CPP_LABEL) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\Guetari\Opera\Thotlib\Tree\pagecommands.c

!IF  "$(CFG)" == "LibThotEditor - Win32 Release"

DEP_CPP_PAGEC=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\internals\var\page_tv.h"\
	".\..\thotlib\internals\f\buildboxes_f.h"\
	".\..\thotlib\internals\f\absboxes_f.h"\
	".\..\thotlib\internals\f\changeabsbox_f.h"\
	".\..\thotlib\internals\f\presrules_f.h"\
	".\..\thotlib\internals\f\boxpositions_f.h"\
	".\..\thotlib\internals\f\pagecommands_f.h"\
	".\..\thotlib\include\sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\thotlib\internals\h\constint.h"\
	".\..\thotlib\internals\h\thotkey.h"\
	".\..\thotlib\internals\h\conststr.h"\
	".\..\thotlib\internals\h\constprs.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	
NODEP_CPP_PAGEC=\
	".\..\thotlib\include\HTVMSUtils.h"\
	

"$(INTDIR)\pagecommands.obj" : $(SOURCE) $(DEP_CPP_PAGEC) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "LibThotEditor - Win32 Debug"

DEP_CPP_PAGEC=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\internals\var\page_tv.h"\
	".\..\thotlib\internals\f\buildboxes_f.h"\
	".\..\thotlib\internals\f\absboxes_f.h"\
	".\..\thotlib\internals\f\changeabsbox_f.h"\
	".\..\thotlib\internals\f\presrules_f.h"\
	".\..\thotlib\internals\f\boxpositions_f.h"\
	".\..\thotlib\internals\f\pagecommands_f.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	

"$(INTDIR)\pagecommands.obj" : $(SOURCE) $(DEP_CPP_PAGEC) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\Guetari\Opera\Thotlib\Tree\Paginate.c

!IF  "$(CFG)" == "LibThotEditor - Win32 Release"

DEP_CPP_PAGIN=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\include\libmsg.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\internals\h\appdialogue.h"\
	".\..\thotlib\include\fileaccess.h"\
	".\..\thotlib\internals\var\appdialogue_tv.h"\
	".\..\thotlib\internals\var\page_tv.h"\
	".\..\thotlib\internals\f\applicationapi_f.h"\
	".\..\thotlib\internals\f\attributes_f.h"\
	".\..\thotlib\internals\f\buildboxes_f.h"\
	".\..\thotlib\internals\f\boxpositions_f.h"\
	".\..\thotlib\internals\f\absboxes_f.h"\
	".\..\thotlib\internals\f\tree_f.h"\
	".\..\thotlib\internals\f\structcreation_f.h"\
	".\..\thotlib\internals\f\createabsbox_f.h"\
	".\..\thotlib\internals\f\createpages_f.h"\
	".\..\thotlib\internals\f\structlist_f.h"\
	".\..\thotlib\internals\f\callback_f.h"\
	".\..\thotlib\internals\f\exceptions_f.h"\
	".\..\thotlib\internals\f\font_f.h"\
	".\..\thotlib\internals\f\structmodif_f.h"\
	".\..\thotlib\internals\f\changeabsbox_f.h"\
	".\..\thotlib\internals\f\changepresent_f.h"\
	".\..\thotlib\internals\f\presrules_f.h"\
	".\..\thotlib\internals\f\paginate_f.h"\
	".\..\thotlib\internals\f\pagecommands_f.h"\
	".\..\thotlib\internals\f\structselect_f.h"\
	".\..\thotlib\internals\f\content_f.h"\
	".\..\thotlib\internals\f\presvariables_f.h"\
	".\..\thotlib\internals\f\print_f.h"\
	".\..\thotlib\internals\f\writepivot_f.h"\
	".\..\thotlib\include\sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\thotlib\internals\h\constint.h"\
	".\..\thotlib\internals\h\thotkey.h"\
	".\..\thotlib\internals\h\conststr.h"\
	".\..\thotlib\internals\h\constprs.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\internals\h\frame.h"\
	".\..\thotlib\internals\h\constmenu.h"\
	
NODEP_CPP_PAGIN=\
	".\..\thotlib\include\HTVMSUtils.h"\
	

"$(INTDIR)\Paginate.obj" : $(SOURCE) $(DEP_CPP_PAGIN) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "LibThotEditor - Win32 Debug"

DEP_CPP_PAGIN=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\include\libmsg.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\internals\h\appdialogue.h"\
	".\..\thotlib\include\fileaccess.h"\
	".\..\thotlib\internals\var\appdialogue_tv.h"\
	".\..\thotlib\internals\var\page_tv.h"\
	".\..\thotlib\internals\f\applicationapi_f.h"\
	".\..\thotlib\internals\f\attributes_f.h"\
	".\..\thotlib\internals\f\buildboxes_f.h"\
	".\..\thotlib\internals\f\boxpositions_f.h"\
	".\..\thotlib\internals\f\absboxes_f.h"\
	".\..\thotlib\internals\f\tree_f.h"\
	".\..\thotlib\internals\f\structcreation_f.h"\
	".\..\thotlib\internals\f\createabsbox_f.h"\
	".\..\thotlib\internals\f\createpages_f.h"\
	".\..\thotlib\internals\f\structlist_f.h"\
	".\..\thotlib\internals\f\callback_f.h"\
	".\..\thotlib\internals\f\exceptions_f.h"\
	".\..\thotlib\internals\f\font_f.h"\
	".\..\thotlib\internals\f\structmodif_f.h"\
	".\..\thotlib\internals\f\changeabsbox_f.h"\
	".\..\thotlib\internals\f\changepresent_f.h"\
	".\..\thotlib\internals\f\presrules_f.h"\
	".\..\thotlib\internals\f\paginate_f.h"\
	".\..\thotlib\internals\f\pagecommands_f.h"\
	".\..\thotlib\internals\f\structselect_f.h"\
	".\..\thotlib\internals\f\content_f.h"\
	".\..\thotlib\internals\f\presvariables_f.h"\
	".\..\thotlib\internals\f\print_f.h"\
	".\..\thotlib\internals\f\writepivot_f.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\internals\h\frame.h"\
	".\..\thotlib\internals\h\constmenu.h"\
	

"$(INTDIR)\Paginate.obj" : $(SOURCE) $(DEP_CPP_PAGIN) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\Guetari\Opera\Thotlib\Tree\referenceapi.c

!IF  "$(CFG)" == "LibThotEditor - Win32 Release"

DEP_CPP_REFER=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\include\application.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\reference.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\include\fileaccess.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\internals\var\edit_tv.h"\
	".\..\thotlib\internals\f\references_f.h"\
	".\..\thotlib\internals\f\tree_f.h"\
	".\..\thotlib\internals\f\search_f.h"\
	".\..\thotlib\internals\f\fileaccess_f.h"\
	".\..\thotlib\internals\f\thotmsg_f.h"\
	".\..\thotlib\internals\f\structmodif_f.h"\
	".\..\thotlib\internals\f\memory_f.h"\
	".\..\thotlib\internals\f\readpivot_f.h"\
	".\..\thotlib\internals\f\schemastr_f.h"\
	".\..\thotlib\internals\f\structschema_f.h"\
	".\..\thotlib\internals\f\applicationapi_f.h"\
	".\..\thotlib\internals\f\viewapi_f.h"\
	".\..\thotlib\include\sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\thotlib\internals\h\constint.h"\
	".\..\thotlib\internals\h\thotkey.h"\
	".\..\thotlib\internals\h\conststr.h"\
	".\..\thotlib\internals\h\constprs.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\include\registry.h"\
	".\..\thotlib\include\libmsg.h"\
	
NODEP_CPP_REFER=\
	".\..\thotlib\include\HTVMSUtils.h"\
	

"$(INTDIR)\referenceapi.obj" : $(SOURCE) $(DEP_CPP_REFER) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "LibThotEditor - Win32 Debug"

DEP_CPP_REFER=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\include\application.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\reference.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\include\fileaccess.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\internals\var\edit_tv.h"\
	".\..\thotlib\internals\f\references_f.h"\
	".\..\thotlib\internals\f\tree_f.h"\
	".\..\thotlib\internals\f\search_f.h"\
	".\..\thotlib\internals\f\fileaccess_f.h"\
	".\..\thotlib\internals\f\thotmsg_f.h"\
	".\..\thotlib\internals\f\structmodif_f.h"\
	".\..\thotlib\internals\f\memory_f.h"\
	".\..\thotlib\internals\f\readpivot_f.h"\
	".\..\thotlib\internals\f\schemastr_f.h"\
	".\..\thotlib\internals\f\structschema_f.h"\
	".\..\thotlib\internals\f\applicationapi_f.h"\
	".\..\thotlib\internals\f\viewapi_f.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\include\registry.h"\
	".\..\thotlib\include\libmsg.h"\
	

"$(INTDIR)\referenceapi.obj" : $(SOURCE) $(DEP_CPP_REFER) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\Guetari\Opera\Thotlib\Tree\references.c

!IF  "$(CFG)" == "LibThotEditor - Win32 Release"

DEP_CPP_REFERE=\
	".\..\thotlib\include\libmsg.h"\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\include\fileaccess.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\internals\var\edit_tv.h"\
	".\..\thotlib\internals\f\tree_f.h"\
	".\..\thotlib\internals\f\references_f.h"\
	".\..\thotlib\internals\f\memory_f.h"\
	".\..\thotlib\internals\f\callback_f.h"\
	".\..\thotlib\internals\f\fileaccess_f.h"\
	".\..\thotlib\internals\f\content_f.h"\
	".\..\thotlib\internals\f\structschema_f.h"\
	".\..\thotlib\internals\f\readpivot_f.h"\
	".\..\thotlib\internals\f\applicationapi_f.h"\
	".\..\thotlib\internals\f\schemas_f.h"\
	".\..\thotlib\include\sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\thotlib\internals\h\constint.h"\
	".\..\thotlib\internals\h\thotkey.h"\
	".\..\thotlib\internals\h\conststr.h"\
	".\..\thotlib\internals\h\constprs.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	
NODEP_CPP_REFERE=\
	".\..\thotlib\include\HTVMSUtils.h"\
	

"$(INTDIR)\references.obj" : $(SOURCE) $(DEP_CPP_REFERE) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "LibThotEditor - Win32 Debug"

DEP_CPP_REFERE=\
	".\..\thotlib\include\libmsg.h"\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\include\fileaccess.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\internals\var\edit_tv.h"\
	".\..\thotlib\internals\f\tree_f.h"\
	".\..\thotlib\internals\f\references_f.h"\
	".\..\thotlib\internals\f\memory_f.h"\
	".\..\thotlib\internals\f\callback_f.h"\
	".\..\thotlib\internals\f\fileaccess_f.h"\
	".\..\thotlib\internals\f\content_f.h"\
	".\..\thotlib\internals\f\structschema_f.h"\
	".\..\thotlib\internals\f\readpivot_f.h"\
	".\..\thotlib\internals\f\applicationapi_f.h"\
	".\..\thotlib\internals\f\schemas_f.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	

"$(INTDIR)\references.obj" : $(SOURCE) $(DEP_CPP_REFERE) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\Guetari\Opera\Thotlib\Tree\Res.c

!IF  "$(CFG)" == "LibThotEditor - Win32 Release"

DEP_CPP_RES_C=\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\include\application.h"\
	".\..\thotlib\include\content.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\selection.h"\
	".\..\thotlib\internals\h\conststr.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\constres.h"\
	".\..\thotlib\internals\f\resmatch_f.h"\
	".\..\thotlib\internals\f\resgen_f.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\thotlib\include\fileaccess.h"\
	".\..\thotlib\include\registry.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	
NODEP_CPP_RES_C=\
	".\..\thotlib\include\HTVMSUtils.h"\
	

"$(INTDIR)\Res.obj" : $(SOURCE) $(DEP_CPP_RES_C) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "LibThotEditor - Win32 Debug"

DEP_CPP_RES_C=\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\include\application.h"\
	".\..\thotlib\include\content.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\selection.h"\
	".\..\thotlib\internals\h\conststr.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\constres.h"\
	".\..\thotlib\internals\f\resmatch_f.h"\
	".\..\thotlib\internals\f\resgen_f.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\fileaccess.h"\
	".\..\thotlib\include\registry.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	

"$(INTDIR)\Res.obj" : $(SOURCE) $(DEP_CPP_RES_C) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\Guetari\Opera\Thotlib\Tree\Resgen.c

!IF  "$(CFG)" == "LibThotEditor - Win32 Release"

DEP_CPP_RESGE=\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\include\application.h"\
	".\..\thotlib\include\content.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\selection.h"\
	".\..\thotlib\internals\h\conststr.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\constres.h"\
	".\..\thotlib\internals\f\resmatch_f.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\thotlib\include\fileaccess.h"\
	".\..\thotlib\include\registry.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	
NODEP_CPP_RESGE=\
	".\..\thotlib\include\HTVMSUtils.h"\
	

"$(INTDIR)\Resgen.obj" : $(SOURCE) $(DEP_CPP_RESGE) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "LibThotEditor - Win32 Debug"

DEP_CPP_RESGE=\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\include\application.h"\
	".\..\thotlib\include\content.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\selection.h"\
	".\..\thotlib\internals\h\conststr.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\constres.h"\
	".\..\thotlib\internals\f\resmatch_f.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\fileaccess.h"\
	".\..\thotlib\include\registry.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	

"$(INTDIR)\Resgen.obj" : $(SOURCE) $(DEP_CPP_RESGE) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\Guetari\Opera\Thotlib\Tree\attributeapi.c

!IF  "$(CFG)" == "LibThotEditor - Win32 Release"

DEP_CPP_ATTRIB=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\include\application.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\var\edit_tv.h"\
	".\..\thotlib\internals\f\tree_f.h"\
	".\..\thotlib\internals\f\attributes_f.h"\
	".\..\thotlib\internals\f\attributeapi_f.h"\
	".\..\thotlib\internals\f\draw_f.h"\
	".\..\thotlib\internals\f\memory_f.h"\
	".\..\thotlib\internals\f\references_f.h"\
	".\..\thotlib\internals\f\structschema_f.h"\
	".\..\thotlib\internals\f\content_f.h"\
	".\..\thotlib\internals\f\thotmsg_f.h"\
	".\..\thotlib\internals\f\viewapi_f.h"\
	".\..\thotlib\include\sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\thotlib\internals\h\constint.h"\
	".\..\thotlib\internals\h\thotkey.h"\
	".\..\thotlib\internals\h\conststr.h"\
	".\..\thotlib\internals\h\constprs.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\include\fileaccess.h"\
	".\..\thotlib\include\registry.h"\
	
NODEP_CPP_ATTRIB=\
	".\..\thotlib\include\HTVMSUtils.h"\
	

"$(INTDIR)\attributeapi.obj" : $(SOURCE) $(DEP_CPP_ATTRIB) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "LibThotEditor - Win32 Debug"

DEP_CPP_ATTRIB=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\include\application.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\var\edit_tv.h"\
	".\..\thotlib\internals\f\tree_f.h"\
	".\..\thotlib\internals\f\attributes_f.h"\
	".\..\thotlib\internals\f\attributeapi_f.h"\
	".\..\thotlib\internals\f\draw_f.h"\
	".\..\thotlib\internals\f\memory_f.h"\
	".\..\thotlib\internals\f\references_f.h"\
	".\..\thotlib\internals\f\structschema_f.h"\
	".\..\thotlib\internals\f\content_f.h"\
	".\..\thotlib\internals\f\thotmsg_f.h"\
	".\..\thotlib\internals\f\viewapi_f.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\include\fileaccess.h"\
	".\..\thotlib\include\registry.h"\
	

"$(INTDIR)\attributeapi.obj" : $(SOURCE) $(DEP_CPP_ATTRIB) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\Guetari\Opera\Thotlib\Tree\structschema.c

!IF  "$(CFG)" == "LibThotEditor - Win32 Release"

DEP_CPP_STRUCT=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\include\libmsg.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\internals\h\appdialogue.h"\
	".\..\thotlib\internals\var\edit_tv.h"\
	".\..\thotlib\internals\var\platform_tv.h"\
	".\..\thotlib\internals\var\appdialogue_tv.h"\
	".\..\thotlib\internals\f\tree_f.h"\
	".\..\thotlib\internals\f\exceptions_f.h"\
	".\..\thotlib\internals\f\memory_f.h"\
	".\..\thotlib\internals\f\schemastr_f.h"\
	".\..\thotlib\internals\f\structschema_f.h"\
	".\..\thotlib\include\sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\thotlib\internals\h\constint.h"\
	".\..\thotlib\internals\h\thotkey.h"\
	".\..\thotlib\internals\h\conststr.h"\
	".\..\thotlib\internals\h\constprs.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\internals\h\frame.h"\
	".\..\thotlib\internals\h\constmenu.h"\
	
NODEP_CPP_STRUCT=\
	".\..\thotlib\include\HTVMSUtils.h"\
	

"$(INTDIR)\structschema.obj" : $(SOURCE) $(DEP_CPP_STRUCT) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "LibThotEditor - Win32 Debug"

DEP_CPP_STRUCT=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\include\libmsg.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\internals\h\appdialogue.h"\
	".\..\thotlib\internals\var\edit_tv.h"\
	".\..\thotlib\internals\var\platform_tv.h"\
	".\..\thotlib\internals\var\appdialogue_tv.h"\
	".\..\thotlib\internals\f\tree_f.h"\
	".\..\thotlib\internals\f\exceptions_f.h"\
	".\..\thotlib\internals\f\memory_f.h"\
	".\..\thotlib\internals\f\schemastr_f.h"\
	".\..\thotlib\internals\f\structschema_f.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\internals\h\frame.h"\
	".\..\thotlib\internals\h\constmenu.h"\
	

"$(INTDIR)\structschema.obj" : $(SOURCE) $(DEP_CPP_STRUCT) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\Guetari\Opera\Thotlib\Tree\Tree.c

!IF  "$(CFG)" == "LibThotEditor - Win32 Release"

DEP_CPP_TREE_=\
	".\..\thotlib\include\libmsg.h"\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\include\fileaccess.h"\
	".\..\thotlib\internals\h\res.h"\
	".\..\thotlib\include\labelAllocator.h"\
	".\..\thotlib\internals\h\appdialogue.h"\
	".\..\thotlib\internals\var\select_tv.h"\
	".\..\thotlib\internals\var\edit_tv.h"\
	".\..\thotlib\internals\var\appdialogue_tv.h"\
	".\..\thotlib\internals\f\memory_f.h"\
	".\..\thotlib\internals\f\schemas_f.h"\
	".\..\thotlib\internals\f\absboxes_f.h"\
	".\..\thotlib\internals\f\draw_f.h"\
	".\..\thotlib\internals\f\content_f.h"\
	".\..\thotlib\internals\f\references_f.h"\
	".\..\thotlib\internals\f\fileaccess_f.h"\
	".\..\thotlib\internals\f\structschema_f.h"\
	".\..\thotlib\internals\f\labelalloc_f.h"\
	".\..\thotlib\internals\f\tree_f.h"\
	".\..\thotlib\internals\f\exceptions_f.h"\
	".\..\thotlib\internals\f\abspictures_f.h"\
	".\..\thotlib\internals\f\externalref_f.h"\
	".\..\thotlib\include\sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\thotlib\internals\h\constint.h"\
	".\..\thotlib\internals\h\thotkey.h"\
	".\..\thotlib\internals\h\conststr.h"\
	".\..\thotlib\internals\h\constprs.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\internals\h\SelectRestruct.h"\
	".\..\thotlib\internals\h\resdynmsg.h"\
	".\..\thotlib\internals\h\frame.h"\
	".\..\thotlib\internals\h\constmenu.h"\
	
NODEP_CPP_TREE_=\
	".\..\thotlib\include\HTVMSUtils.h"\
	

"$(INTDIR)\Tree.obj" : $(SOURCE) $(DEP_CPP_TREE_) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "LibThotEditor - Win32 Debug"

DEP_CPP_TREE_=\
	".\..\thotlib\include\libmsg.h"\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\include\fileaccess.h"\
	".\..\thotlib\internals\h\res.h"\
	".\..\thotlib\include\labelAllocator.h"\
	".\..\thotlib\internals\h\appdialogue.h"\
	".\..\thotlib\internals\var\select_tv.h"\
	".\..\thotlib\internals\var\edit_tv.h"\
	".\..\thotlib\internals\var\appdialogue_tv.h"\
	".\..\thotlib\internals\f\memory_f.h"\
	".\..\thotlib\internals\f\schemas_f.h"\
	".\..\thotlib\internals\f\absboxes_f.h"\
	".\..\thotlib\internals\f\draw_f.h"\
	".\..\thotlib\internals\f\content_f.h"\
	".\..\thotlib\internals\f\references_f.h"\
	".\..\thotlib\internals\f\fileaccess_f.h"\
	".\..\thotlib\internals\f\structschema_f.h"\
	".\..\thotlib\internals\f\labelalloc_f.h"\
	".\..\thotlib\internals\f\tree_f.h"\
	".\..\thotlib\internals\f\exceptions_f.h"\
	".\..\thotlib\internals\f\abspictures_f.h"\
	".\..\thotlib\internals\f\externalref_f.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\internals\h\SelectRestruct.h"\
	".\..\thotlib\internals\h\resdynmsg.h"\
	".\..\thotlib\internals\h\frame.h"\
	".\..\thotlib\internals\h\constmenu.h"\
	

"$(INTDIR)\Tree.obj" : $(SOURCE) $(DEP_CPP_TREE_) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\Guetari\Opera\Thotlib\Tree\Treeapi.c

!IF  "$(CFG)" == "LibThotEditor - Win32 Release"

DEP_CPP_TREEA=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\include\application.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\fileaccess.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\appdialogue.h"\
	".\..\thotlib\include\labelAllocator.h"\
	".\..\thotlib\internals\var\edit_tv.h"\
	".\..\thotlib\internals\var\modif_tv.h"\
	".\..\thotlib\internals\var\platform_tv.h"\
	".\..\thotlib\internals\var\appdialogue_tv.h"\
	".\..\thotlib\internals\f\tree_f.h"\
	".\..\thotlib\internals\f\attributes_f.h"\
	".\..\thotlib\internals\f\attributeapi_f.h"\
	".\..\thotlib\internals\f\structcreation_f.h"\
	".\..\thotlib\internals\f\structmodif_f.h"\
	".\..\thotlib\internals\f\references_f.h"\
	".\..\thotlib\internals\f\externalref_f.h"\
	".\..\thotlib\internals\f\structschema_f.h"\
	".\..\thotlib\internals\f\translation_f.h"\
	".\..\thotlib\internals\f\thotmsg_f.h"\
	".\..\thotlib\internals\f\viewapi_f.h"\
	".\..\thotlib\internals\f\documentapi_f.h"\
	".\..\thotlib\internals\f\applicationapi_f.h"\
	".\..\thotlib\internals\f\labelalloc_f.h"\
	".\..\thotlib\include\sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\thotlib\internals\h\constint.h"\
	".\..\thotlib\internals\h\thotkey.h"\
	".\..\thotlib\internals\h\conststr.h"\
	".\..\thotlib\internals\h\constprs.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\include\registry.h"\
	".\..\thotlib\internals\h\frame.h"\
	".\..\thotlib\internals\h\constmenu.h"\
	
NODEP_CPP_TREEA=\
	".\..\thotlib\include\HTVMSUtils.h"\
	

"$(INTDIR)\Treeapi.obj" : $(SOURCE) $(DEP_CPP_TREEA) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "LibThotEditor - Win32 Debug"

DEP_CPP_TREEA=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\include\application.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\fileaccess.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\appdialogue.h"\
	".\..\thotlib\include\labelAllocator.h"\
	".\..\thotlib\internals\var\edit_tv.h"\
	".\..\thotlib\internals\var\modif_tv.h"\
	".\..\thotlib\internals\var\platform_tv.h"\
	".\..\thotlib\internals\var\appdialogue_tv.h"\
	".\..\thotlib\internals\f\tree_f.h"\
	".\..\thotlib\internals\f\attributes_f.h"\
	".\..\thotlib\internals\f\attributeapi_f.h"\
	".\..\thotlib\internals\f\structcreation_f.h"\
	".\..\thotlib\internals\f\structmodif_f.h"\
	".\..\thotlib\internals\f\references_f.h"\
	".\..\thotlib\internals\f\externalref_f.h"\
	".\..\thotlib\internals\f\structschema_f.h"\
	".\..\thotlib\internals\f\translation_f.h"\
	".\..\thotlib\internals\f\thotmsg_f.h"\
	".\..\thotlib\internals\f\viewapi_f.h"\
	".\..\thotlib\internals\f\documentapi_f.h"\
	".\..\thotlib\internals\f\applicationapi_f.h"\
	".\..\thotlib\internals\f\labelalloc_f.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\include\registry.h"\
	".\..\thotlib\internals\h\frame.h"\
	".\..\thotlib\internals\h\constmenu.h"\
	

"$(INTDIR)\Treeapi.obj" : $(SOURCE) $(DEP_CPP_TREEA) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\Guetari\Opera\Thotlib\Image\xpmhandler.c

!IF  "$(CFG)" == "LibThotEditor - Win32 Release"

DEP_CPP_XPMHA=\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\internals\h\picture.h"\
	".\..\thotlib\internals\h\frame.h"\
	".\..\thotlib\include\libmsg.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\internals\var\picture_tv.h"\
	".\..\thotlib\internals\var\frame_tv.h"\
	".\..\thotlib\internals\h\xpmP.h"\
	".\..\thotlib\internals\h\xpm.h"\
	".\..\thotlib\internals\f\picture_f.h"\
	".\..\thotlib\internals\f\inites_f.h"\
	".\..\thotlib\internals\f\font_f.h"\
	".\..\thotlib\internals\f\units_f.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\thotlib\internals\h\constint.h"\
	".\..\thotlib\internals\h\thotkey.h"\
	".\..\thotlib\internals\h\conststr.h"\
	".\..\thotlib\internals\h\constprs.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\internals\h\constmenu.h"\
	
NODEP_CPP_XPMHA=\
	".\..\thotlib\include\HTVMSUtils.h"\
	

"$(INTDIR)\xpmhandler.obj" : $(SOURCE) $(DEP_CPP_XPMHA) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "LibThotEditor - Win32 Debug"

DEP_CPP_XPMHA=\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\internals\h\picture.h"\
	".\..\thotlib\internals\h\frame.h"\
	".\..\thotlib\include\libmsg.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\internals\var\picture_tv.h"\
	".\..\thotlib\internals\var\frame_tv.h"\
	".\..\thotlib\internals\h\xpmP.h"\
	".\..\thotlib\internals\h\xpm.h"\
	".\..\thotlib\internals\f\picture_f.h"\
	".\..\thotlib\internals\f\inites_f.h"\
	".\..\thotlib\internals\f\font_f.h"\
	".\..\thotlib\internals\f\units_f.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\internals\h\constmenu.h"\
	

"$(INTDIR)\xpmhandler.obj" : $(SOURCE) $(DEP_CPP_XPMHA) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\Guetari\Opera\Thotlib\Image\epshandler.c

!IF  "$(CFG)" == "LibThotEditor - Win32 Release"

DEP_CPP_EPSHA=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\include\libmsg.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\internals\h\picture.h"\
	".\..\thotlib\internals\h\frame.h"\
	".\..\thotlib\internals\var\picture_tv.h"\
	".\..\thotlib\internals\var\frame_tv.h"\
	".\..\thotlib\internals\var\font_tv.h"\
	".\..\thotlib\internals\f\units_f.h"\
	".\..\thotlib\internals\f\picture_f.h"\
	".\..\thotlib\internals\f\font_f.h"\
	".\..\thotlib\internals\f\memory_f.h"\
	".\..\thotlib\include\sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\thotlib\internals\h\constint.h"\
	".\..\thotlib\internals\h\thotkey.h"\
	".\..\thotlib\internals\h\conststr.h"\
	".\..\thotlib\internals\h\constprs.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\internals\h\constmenu.h"\
	
NODEP_CPP_EPSHA=\
	".\..\thotlib\include\HTVMSUtils.h"\
	

"$(INTDIR)\epshandler.obj" : $(SOURCE) $(DEP_CPP_EPSHA) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "LibThotEditor - Win32 Debug"

DEP_CPP_EPSHA=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\include\libmsg.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\internals\h\picture.h"\
	".\..\thotlib\internals\h\frame.h"\
	".\..\thotlib\internals\var\picture_tv.h"\
	".\..\thotlib\internals\var\frame_tv.h"\
	".\..\thotlib\internals\var\font_tv.h"\
	".\..\thotlib\internals\f\units_f.h"\
	".\..\thotlib\internals\f\picture_f.h"\
	".\..\thotlib\internals\f\font_f.h"\
	".\..\thotlib\internals\f\memory_f.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\internals\h\constmenu.h"\
	

"$(INTDIR)\epshandler.obj" : $(SOURCE) $(DEP_CPP_EPSHA) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\Guetari\Opera\Thotlib\Image\gifhandler.c

!IF  "$(CFG)" == "LibThotEditor - Win32 Release"

DEP_CPP_GIFHA=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\internals\h\picture.h"\
	".\..\thotlib\internals\h\frame.h"\
	".\..\thotlib\include\libmsg.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\include\application.h"\
	".\..\thotlib\internals\h\xpmP.h"\
	".\..\thotlib\internals\h\xpm.h"\
	".\..\thotlib\internals\h\thotcolor.h"\
	".\..\thotlib\internals\h\winsys.h"\
	".\..\thotlib\internals\var\picture_tv.h"\
	".\..\thotlib\internals\var\frame_tv.h"\
	".\..\thotlib\internals\var\thotcolor_tv.h"\
	".\..\thotlib\internals\f\font_f.h"\
	".\..\thotlib\internals\f\units_f.h"\
	".\..\thotlib\internals\f\inites_f.h"\
	".\..\thotlib\internals\f\gifhandler_f.h"\
	".\..\thotlib\internals\f\picture_f.h"\
	".\..\thotlib\include\sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\thotlib\internals\h\constint.h"\
	".\..\thotlib\internals\h\thotkey.h"\
	".\..\thotlib\internals\h\conststr.h"\
	".\..\thotlib\internals\h\constprs.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\internals\h\constmenu.h"\
	".\..\thotlib\include\fileaccess.h"\
	".\..\thotlib\include\registry.h"\
	
NODEP_CPP_GIFHA=\
	".\..\thotlib\include\HTVMSUtils.h"\
	

"$(INTDIR)\gifhandler.obj" : $(SOURCE) $(DEP_CPP_GIFHA) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "LibThotEditor - Win32 Debug"

DEP_CPP_GIFHA=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\internals\h\picture.h"\
	".\..\thotlib\internals\h\frame.h"\
	".\..\thotlib\include\libmsg.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\include\application.h"\
	".\..\thotlib\internals\h\xpmP.h"\
	".\..\thotlib\internals\h\xpm.h"\
	".\..\thotlib\internals\h\thotcolor.h"\
	".\..\thotlib\internals\h\winsys.h"\
	".\..\thotlib\internals\var\picture_tv.h"\
	".\..\thotlib\internals\var\frame_tv.h"\
	".\..\thotlib\internals\var\thotcolor_tv.h"\
	".\..\thotlib\internals\f\font_f.h"\
	".\..\thotlib\internals\f\units_f.h"\
	".\..\thotlib\internals\f\inites_f.h"\
	".\..\thotlib\internals\f\gifhandler_f.h"\
	".\..\thotlib\internals\f\picture_f.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\internals\h\constmenu.h"\
	".\..\thotlib\include\fileaccess.h"\
	".\..\thotlib\include\registry.h"\
	

"$(INTDIR)\gifhandler.obj" : $(SOURCE) $(DEP_CPP_GIFHA) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\Guetari\Opera\Thotlib\Image\jpeghandler.c

!IF  "$(CFG)" == "LibThotEditor - Win32 Release"

DEP_CPP_JPEGH=\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\libjpeg\jpeglib.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\internals\h\picture.h"\
	".\..\thotlib\internals\h\frame.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\include\application.h"\
	".\..\thotlib\internals\var\picture_tv.h"\
	".\..\thotlib\internals\var\frame_tv.h"\
	".\..\thotlib\internals\f\picture_f.h"\
	".\..\thotlib\internals\f\font_f.h"\
	".\..\thotlib\internals\f\units_f.h"\
	".\..\thotlib\internals\f\gifhandler_f.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\thotlib\internals\h\constint.h"\
	".\..\thotlib\internals\h\thotkey.h"\
	".\..\thotlib\internals\h\conststr.h"\
	".\..\thotlib\internals\h\constprs.h"\
	".\..\libjpeg\jconfig.h"\
	".\..\libjpeg\jmorecfg.h"\
	".\..\libjpeg\jpegint.h"\
	".\..\libjpeg\jerror.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\internals\h\constmenu.h"\
	".\..\thotlib\include\libmsg.h"\
	".\..\thotlib\include\fileaccess.h"\
	".\..\thotlib\include\registry.h"\
	
NODEP_CPP_JPEGH=\
	".\..\thotlib\include\HTVMSUtils.h"\
	

"$(INTDIR)\jpeghandler.obj" : $(SOURCE) $(DEP_CPP_JPEGH) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "LibThotEditor - Win32 Debug"

DEP_CPP_JPEGH=\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\libjpeg\jpeglib.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\internals\h\picture.h"\
	".\..\thotlib\internals\h\frame.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\include\application.h"\
	".\..\thotlib\internals\var\picture_tv.h"\
	".\..\thotlib\internals\var\frame_tv.h"\
	".\..\thotlib\internals\f\picture_f.h"\
	".\..\thotlib\internals\f\font_f.h"\
	".\..\thotlib\internals\f\units_f.h"\
	".\..\thotlib\internals\f\gifhandler_f.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\libjpeg\jconfig.h"\
	".\..\libjpeg\jmorecfg.h"\
	".\..\libjpeg\jpegint.h"\
	".\..\libjpeg\jerror.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\internals\h\constmenu.h"\
	".\..\thotlib\include\libmsg.h"\
	".\..\thotlib\include\fileaccess.h"\
	".\..\thotlib\include\registry.h"\
	

"$(INTDIR)\jpeghandler.obj" : $(SOURCE) $(DEP_CPP_JPEGH) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\Guetari\Opera\Thotlib\Image\Picture.c

!IF  "$(CFG)" == "LibThotEditor - Win32 Release"

DEP_CPP_PICTU=\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\internals\h\lost.xpm"\
	".\..\thotlib\internals\h\picture.h"\
	".\..\thotlib\internals\h\frame.h"\
	".\..\thotlib\internals\h\epsflogo.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\fileaccess.h"\
	".\..\thotlib\internals\h\thotdir.h"\
	".\..\libpng\png.h"\
	".\..\thotlib\internals\h\winsys.h"\
	".\..\thotlib\internals\var\boxes_tv.h"\
	".\..\thotlib\internals\var\frame_tv.h"\
	".\..\thotlib\internals\var\font_tv.h"\
	".\..\thotlib\internals\var\platform_tv.h"\
	".\..\thotlib\internals\var\picture_tv.h"\
	".\..\thotlib\internals\f\appli_f.h"\
	".\..\thotlib\internals\f\tree_f.h"\
	".\..\thotlib\internals\f\views_f.h"\
	".\..\thotlib\internals\f\platform_f.h"\
	".\..\thotlib\internals\f\font_f.h"\
	".\..\thotlib\internals\f\frame_f.h"\
	".\..\thotlib\internals\f\picture_f.h"\
	".\..\thotlib\internals\f\presrules_f.h"\
	".\..\thotlib\internals\f\inites_f.h"\
	".\..\thotlib\internals\f\gifhandler_f.h"\
	".\..\thotlib\internals\f\jpeghandler_f.h"\
	".\..\thotlib\internals\f\xbmhandler_f.h"\
	".\..\thotlib\internals\f\xpmhandler_f.h"\
	".\..\thotlib\internals\f\pnghandler_f.h"\
	".\..\thotlib\internals\f\epshandler_f.h"\
	".\..\thotlib\internals\f\fileaccess_f.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\thotlib\internals\h\constint.h"\
	".\..\thotlib\internals\h\thotkey.h"\
	".\..\thotlib\internals\h\conststr.h"\
	".\..\thotlib\internals\h\constprs.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\internals\h\constmenu.h"\
	".\..\libpng\zlib\zlib.h"\
	".\..\libpng\pngconf.h"\
	".\..\libpng\zlib\zconf.h"\
	
NODEP_CPP_PICTU=\
	".\..\thotlib\include\HTVMSUtils.h"\
	".\..\libpng\alloc.h"\
	

"$(INTDIR)\Picture.obj" : $(SOURCE) $(DEP_CPP_PICTU) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "LibThotEditor - Win32 Debug"

DEP_CPP_PICTU=\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\internals\h\lost.xpm"\
	".\..\thotlib\internals\h\picture.h"\
	".\..\thotlib\internals\h\frame.h"\
	".\..\thotlib\internals\h\epsflogo.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\fileaccess.h"\
	".\..\thotlib\internals\h\thotdir.h"\
	".\..\libpng\png.h"\
	".\..\thotlib\internals\h\winsys.h"\
	".\..\thotlib\internals\var\boxes_tv.h"\
	".\..\thotlib\internals\var\frame_tv.h"\
	".\..\thotlib\internals\var\font_tv.h"\
	".\..\thotlib\internals\var\platform_tv.h"\
	".\..\thotlib\internals\var\picture_tv.h"\
	".\..\thotlib\internals\f\appli_f.h"\
	".\..\thotlib\internals\f\tree_f.h"\
	".\..\thotlib\internals\f\views_f.h"\
	".\..\thotlib\internals\f\platform_f.h"\
	".\..\thotlib\internals\f\font_f.h"\
	".\..\thotlib\internals\f\frame_f.h"\
	".\..\thotlib\internals\f\picture_f.h"\
	".\..\thotlib\internals\f\presrules_f.h"\
	".\..\thotlib\internals\f\inites_f.h"\
	".\..\thotlib\internals\f\gifhandler_f.h"\
	".\..\thotlib\internals\f\jpeghandler_f.h"\
	".\..\thotlib\internals\f\xbmhandler_f.h"\
	".\..\thotlib\internals\f\xpmhandler_f.h"\
	".\..\thotlib\internals\f\pnghandler_f.h"\
	".\..\thotlib\internals\f\epshandler_f.h"\
	".\..\thotlib\internals\f\fileaccess_f.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\internals\h\constmenu.h"\
	".\..\libpng\zlib\zlib.h"\
	".\..\libpng\pngconf.h"\
	".\..\libpng\zlib\zconf.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	
NODEP_CPP_PICTU=\
	".\..\libpng\alloc.h"\
	

"$(INTDIR)\Picture.obj" : $(SOURCE) $(DEP_CPP_PICTU) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\Guetari\Opera\Thotlib\Image\pictureapi.c

!IF  "$(CFG)" == "LibThotEditor - Win32 Release"

DEP_CPP_PICTUR=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\internals\h\frame.h"\
	".\..\thotlib\internals\h\xpmP.h"\
	".\..\thotlib\internals\h\xpm.h"\
	".\..\thotlib\internals\var\frame_tv.h"\
	".\..\thotlib\internals\var\platform_tv.h"\
	".\..\thotlib\internals\f\memory_f.h"\
	".\..\thotlib\include\sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\thotlib\internals\h\constint.h"\
	".\..\thotlib\internals\h\thotkey.h"\
	".\..\thotlib\internals\h\conststr.h"\
	".\..\thotlib\internals\h\constprs.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\internals\h\constmenu.h"\
	
NODEP_CPP_PICTUR=\
	".\..\thotlib\include\HTVMSUtils.h"\
	

"$(INTDIR)\pictureapi.obj" : $(SOURCE) $(DEP_CPP_PICTUR) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "LibThotEditor - Win32 Debug"

DEP_CPP_PICTUR=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\internals\h\frame.h"\
	".\..\thotlib\internals\h\xpmP.h"\
	".\..\thotlib\internals\h\xpm.h"\
	".\..\thotlib\internals\var\frame_tv.h"\
	".\..\thotlib\internals\var\platform_tv.h"\
	".\..\thotlib\internals\f\memory_f.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\internals\h\constmenu.h"\
	

"$(INTDIR)\pictureapi.obj" : $(SOURCE) $(DEP_CPP_PICTUR) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\Guetari\Opera\Thotlib\Image\picturebase.c

!IF  "$(CFG)" == "LibThotEditor - Win32 Release"

DEP_CPP_PICTURE=\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\internals\h\frame.h"\
	".\..\thotlib\internals\h\picture.h"\
	".\..\thotlib\include\fileaccess.h"\
	".\..\thotlib\include\content.h"\
	".\..\thotlib\internals\h\xpmP.h"\
	".\..\thotlib\internals\h\xpm.h"\
	".\..\thotlib\internals\var\frame_tv.h"\
	".\..\thotlib\internals\var\platform_tv.h"\
	".\..\thotlib\internals\f\fileaccess_f.h"\
	".\..\thotlib\internals\f\picture_f.h"\
	".\..\thotlib\internals\f\memory_f.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\thotlib\internals\h\constint.h"\
	".\..\thotlib\internals\h\thotkey.h"\
	".\..\thotlib\internals\h\conststr.h"\
	".\..\thotlib\internals\h\constprs.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\internals\h\constmenu.h"\
	
NODEP_CPP_PICTURE=\
	".\..\thotlib\include\HTVMSUtils.h"\
	

"$(INTDIR)\picturebase.obj" : $(SOURCE) $(DEP_CPP_PICTURE) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "LibThotEditor - Win32 Debug"

DEP_CPP_PICTURE=\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\internals\h\frame.h"\
	".\..\thotlib\internals\h\picture.h"\
	".\..\thotlib\include\fileaccess.h"\
	".\..\thotlib\include\content.h"\
	".\..\thotlib\internals\h\xpmP.h"\
	".\..\thotlib\internals\h\xpm.h"\
	".\..\thotlib\internals\var\frame_tv.h"\
	".\..\thotlib\internals\var\platform_tv.h"\
	".\..\thotlib\internals\f\fileaccess_f.h"\
	".\..\thotlib\internals\f\picture_f.h"\
	".\..\thotlib\internals\f\memory_f.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\internals\h\constmenu.h"\
	

"$(INTDIR)\picturebase.obj" : $(SOURCE) $(DEP_CPP_PICTURE) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\Guetari\Opera\Thotlib\Image\pnghandler.c

!IF  "$(CFG)" == "LibThotEditor - Win32 Release"

DEP_CPP_PNGHA=\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\thot_sys.h"\
	".\..\libpng\png.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\internals\h\picture.h"\
	".\..\thotlib\internals\h\frame.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\internals\var\picture_tv.h"\
	".\..\thotlib\internals\f\font_f.h"\
	".\..\thotlib\internals\f\units_f.h"\
	".\..\thotlib\internals\var\frame_tv.h"\
	".\..\thotlib\internals\f\picture_f.h"\
	".\..\thotlib\internals\f\gifhandler_f.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\libpng\zlib\zlib.h"\
	".\..\libpng\pngconf.h"\
	".\..\libpng\zlib\zconf.h"\
	".\..\thotlib\internals\h\constint.h"\
	".\..\thotlib\internals\h\thotkey.h"\
	".\..\thotlib\internals\h\conststr.h"\
	".\..\thotlib\internals\h\constprs.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\internals\h\constmenu.h"\
	".\..\thotlib\include\libmsg.h"\
	
NODEP_CPP_PNGHA=\
	".\..\thotlib\include\HTVMSUtils.h"\
	".\..\libpng\alloc.h"\
	

"$(INTDIR)\pnghandler.obj" : $(SOURCE) $(DEP_CPP_PNGHA) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "LibThotEditor - Win32 Debug"

DEP_CPP_PNGHA=\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\thot_sys.h"\
	".\..\libpng\png.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\internals\h\picture.h"\
	".\..\thotlib\internals\h\frame.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\internals\var\picture_tv.h"\
	".\..\thotlib\internals\f\font_f.h"\
	".\..\thotlib\internals\f\units_f.h"\
	".\..\thotlib\internals\var\frame_tv.h"\
	".\..\thotlib\internals\f\picture_f.h"\
	".\..\thotlib\internals\f\gifhandler_f.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\libpng\zlib\zlib.h"\
	".\..\libpng\pngconf.h"\
	".\..\libpng\zlib\zconf.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\internals\h\constmenu.h"\
	".\..\thotlib\include\libmsg.h"\
	
NODEP_CPP_PNGHA=\
	".\..\libpng\alloc.h"\
	

"$(INTDIR)\pnghandler.obj" : $(SOURCE) $(DEP_CPP_PNGHA) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\Guetari\Opera\Thotlib\Image\xbmhandler.c

!IF  "$(CFG)" == "LibThotEditor - Win32 Release"

DEP_CPP_XBMHA=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\internals\h\picture.h"\
	".\..\thotlib\internals\h\frame.h"\
	".\..\thotlib\internals\var\picture_tv.h"\
	".\..\thotlib\internals\var\frame_tv.h"\
	".\..\thotlib\internals\f\picture_f.h"\
	".\..\thotlib\internals\f\font_f.h"\
	".\..\thotlib\internals\f\units_f.h"\
	".\..\thotlib\include\sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\thotlib\internals\h\constint.h"\
	".\..\thotlib\internals\h\thotkey.h"\
	".\..\thotlib\internals\h\conststr.h"\
	".\..\thotlib\internals\h\constprs.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\internals\h\constmenu.h"\
	
NODEP_CPP_XBMHA=\
	".\..\thotlib\include\HTVMSUtils.h"\
	

"$(INTDIR)\xbmhandler.obj" : $(SOURCE) $(DEP_CPP_XBMHA) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "LibThotEditor - Win32 Debug"

DEP_CPP_XBMHA=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\internals\h\picture.h"\
	".\..\thotlib\internals\h\frame.h"\
	".\..\thotlib\internals\var\picture_tv.h"\
	".\..\thotlib\internals\var\frame_tv.h"\
	".\..\thotlib\internals\f\picture_f.h"\
	".\..\thotlib\internals\f\font_f.h"\
	".\..\thotlib\internals\f\units_f.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\internals\h\constmenu.h"\
	

"$(INTDIR)\xbmhandler.obj" : $(SOURCE) $(DEP_CPP_XBMHA) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\Guetari\Opera\Thotlib\Image\abspictures.c

!IF  "$(CFG)" == "LibThotEditor - Win32 Release"

DEP_CPP_ABSPI=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\internals\h\picture.h"\
	".\..\thotlib\internals\f\picture_f.h"\
	".\..\thotlib\internals\f\memory_f.h"\
	".\..\thotlib\include\sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\thotlib\internals\h\constint.h"\
	".\..\thotlib\internals\h\thotkey.h"\
	".\..\thotlib\internals\h\conststr.h"\
	".\..\thotlib\internals\h\constprs.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	
NODEP_CPP_ABSPI=\
	".\..\thotlib\include\HTVMSUtils.h"\
	

"$(INTDIR)\abspictures.obj" : $(SOURCE) $(DEP_CPP_ABSPI) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "LibThotEditor - Win32 Debug"

DEP_CPP_ABSPI=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\internals\h\picture.h"\
	".\..\thotlib\internals\f\picture_f.h"\
	".\..\thotlib\internals\f\memory_f.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	

"$(INTDIR)\abspictures.obj" : $(SOURCE) $(DEP_CPP_ABSPI) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\Guetari\Opera\Thotlib\Content\Content.c

!IF  "$(CFG)" == "LibThotEditor - Win32 Release"

DEP_CPP_CONTE=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\f\applicationapi_f.h"\
	".\..\thotlib\internals\f\memory_f.h"\
	".\..\thotlib\internals\f\tree_f.h"\
	".\..\thotlib\internals\f\references_f.h"\
	".\..\thotlib\internals\f\callback_f.h"\
	".\..\thotlib\internals\f\changeabsbox_f.h"\
	".\..\thotlib\internals\var\select_tv.h"\
	".\..\thotlib\include\sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\thotlib\internals\h\constint.h"\
	".\..\thotlib\internals\h\thotkey.h"\
	".\..\thotlib\internals\h\conststr.h"\
	".\..\thotlib\internals\h\constprs.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	
NODEP_CPP_CONTE=\
	".\..\thotlib\include\HTVMSUtils.h"\
	

"$(INTDIR)\Content.obj" : $(SOURCE) $(DEP_CPP_CONTE) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "LibThotEditor - Win32 Debug"

DEP_CPP_CONTE=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\f\applicationapi_f.h"\
	".\..\thotlib\internals\f\memory_f.h"\
	".\..\thotlib\internals\f\tree_f.h"\
	".\..\thotlib\internals\f\references_f.h"\
	".\..\thotlib\internals\f\callback_f.h"\
	".\..\thotlib\internals\f\changeabsbox_f.h"\
	".\..\thotlib\internals\var\select_tv.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	

"$(INTDIR)\Content.obj" : $(SOURCE) $(DEP_CPP_CONTE) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\Guetari\Opera\Thotlib\Content\contentapi.c

!IF  "$(CFG)" == "LibThotEditor - Win32 Release"

DEP_CPP_CONTEN=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\internals\h\picture.h"\
	".\..\thotlib\include\application.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\selection.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\fileaccess.h"\
	".\..\thotlib\include\content.h"\
	".\..\thotlib\internals\h\frame.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\f\tree_f.h"\
	".\..\thotlib\internals\f\attributes_f.h"\
	".\..\thotlib\internals\f\font_f.h"\
	".\..\thotlib\internals\f\units_f.h"\
	".\..\thotlib\internals\f\picture_f.h"\
	".\..\thotlib\internals\f\changepresent_f.h"\
	".\..\thotlib\internals\f\changeabsbox_f.h"\
	".\..\thotlib\internals\f\memory_f.h"\
	".\..\thotlib\internals\f\structselect_f.h"\
	".\..\thotlib\internals\f\boxselection_f.h"\
	".\..\thotlib\internals\f\content_f.h"\
	".\..\thotlib\internals\f\thotmsg_f.h"\
	".\..\thotlib\internals\f\writepivot_f.h"\
	".\..\thotlib\internals\f\viewapi_f.h"\
	".\..\thotlib\internals\var\edit_tv.h"\
	".\..\thotlib\internals\var\frame_tv.h"\
	".\..\thotlib\include\sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\thotlib\internals\h\constint.h"\
	".\..\thotlib\internals\h\thotkey.h"\
	".\..\thotlib\internals\h\conststr.h"\
	".\..\thotlib\internals\h\constprs.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\include\registry.h"\
	".\..\thotlib\internals\h\constmenu.h"\
	
NODEP_CPP_CONTEN=\
	".\..\thotlib\include\HTVMSUtils.h"\
	

"$(INTDIR)\contentapi.obj" : $(SOURCE) $(DEP_CPP_CONTEN) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "LibThotEditor - Win32 Debug"

DEP_CPP_CONTEN=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\internals\h\picture.h"\
	".\..\thotlib\include\application.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\selection.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\fileaccess.h"\
	".\..\thotlib\include\content.h"\
	".\..\thotlib\internals\h\frame.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\f\tree_f.h"\
	".\..\thotlib\internals\f\attributes_f.h"\
	".\..\thotlib\internals\f\font_f.h"\
	".\..\thotlib\internals\f\units_f.h"\
	".\..\thotlib\internals\f\picture_f.h"\
	".\..\thotlib\internals\f\changepresent_f.h"\
	".\..\thotlib\internals\f\changeabsbox_f.h"\
	".\..\thotlib\internals\f\memory_f.h"\
	".\..\thotlib\internals\f\structselect_f.h"\
	".\..\thotlib\internals\f\boxselection_f.h"\
	".\..\thotlib\internals\f\content_f.h"\
	".\..\thotlib\internals\f\thotmsg_f.h"\
	".\..\thotlib\internals\f\writepivot_f.h"\
	".\..\thotlib\internals\f\viewapi_f.h"\
	".\..\thotlib\internals\var\edit_tv.h"\
	".\..\thotlib\internals\var\frame_tv.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\include\registry.h"\
	".\..\thotlib\internals\h\constmenu.h"\
	

"$(INTDIR)\contentapi.obj" : $(SOURCE) $(DEP_CPP_CONTEN) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\Guetari\Opera\Thotlib\Content\dictionary.c

!IF  "$(CFG)" == "LibThotEditor - Win32 Release"

DEP_CPP_DICTI=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\include\application.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\internals\h\constmenu.h"\
	".\..\thotlib\include\fileaccess.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\include\libmsg.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\internals\h\dictionary.h"\
	".\..\thotlib\internals\h\thotdir.h"\
	".\..\thotlib\internals\f\memory_f.h"\
	".\..\thotlib\internals\f\fileaccess_f.h"\
	".\..\thotlib\internals\f\thotmsg_f.h"\
	".\..\thotlib\internals\f\platform_f.h"\
	".\..\thotlib\include\sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\thotlib\internals\h\constint.h"\
	".\..\thotlib\internals\h\thotkey.h"\
	".\..\thotlib\internals\h\conststr.h"\
	".\..\thotlib\internals\h\constprs.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\include\registry.h"\
	
NODEP_CPP_DICTI=\
	".\..\thotlib\include\HTVMSUtils.h"\
	

"$(INTDIR)\dictionary.obj" : $(SOURCE) $(DEP_CPP_DICTI) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "LibThotEditor - Win32 Debug"

DEP_CPP_DICTI=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\include\application.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\internals\h\constmenu.h"\
	".\..\thotlib\include\fileaccess.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\include\libmsg.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\internals\h\dictionary.h"\
	".\..\thotlib\internals\h\thotdir.h"\
	".\..\thotlib\internals\f\memory_f.h"\
	".\..\thotlib\internals\f\fileaccess_f.h"\
	".\..\thotlib\internals\f\thotmsg_f.h"\
	".\..\thotlib\internals\f\platform_f.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\include\registry.h"\
	

"$(INTDIR)\dictionary.obj" : $(SOURCE) $(DEP_CPP_DICTI) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\Guetari\Opera\Thotlib\Content\Search.c

!IF  "$(CFG)" == "LibThotEditor - Win32 Release"

DEP_CPP_SEARC=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\include\fileaccess.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\var\platform_tv.h"\
	".\..\thotlib\internals\var\edit_tv.h"\
	".\..\thotlib\internals\f\applicationapi_f.h"\
	".\..\thotlib\internals\f\tree_f.h"\
	".\..\thotlib\internals\f\attrpresent_f.h"\
	".\..\thotlib\internals\f\search_f.h"\
	".\..\thotlib\internals\f\searchmenu_f.h"\
	".\..\thotlib\internals\f\structcreation_f.h"\
	".\..\thotlib\internals\f\createabsbox_f.h"\
	".\..\thotlib\internals\f\changeabsbox_f.h"\
	".\..\thotlib\internals\f\scroll_f.h"\
	".\..\thotlib\internals\f\views_f.h"\
	".\..\thotlib\internals\f\callback_f.h"\
	".\..\thotlib\internals\f\viewcommands_f.h"\
	".\..\thotlib\internals\f\exceptions_f.h"\
	".\..\thotlib\internals\f\absboxes_f.h"\
	".\..\thotlib\internals\f\memory_f.h"\
	".\..\thotlib\internals\f\structmodif_f.h"\
	".\..\thotlib\internals\f\references_f.h"\
	".\..\thotlib\internals\f\schemas_f.h"\
	".\..\thotlib\internals\f\boxselection_f.h"\
	".\..\thotlib\internals\f\structselect_f.h"\
	".\..\thotlib\internals\f\fileaccess_f.h"\
	".\..\thotlib\internals\f\structschema_f.h"\
	".\..\thotlib\include\sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\thotlib\internals\h\constint.h"\
	".\..\thotlib\internals\h\thotkey.h"\
	".\..\thotlib\internals\h\conststr.h"\
	".\..\thotlib\internals\h\constprs.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\libmsg.h"\
	
NODEP_CPP_SEARC=\
	".\..\thotlib\include\HTVMSUtils.h"\
	

"$(INTDIR)\Search.obj" : $(SOURCE) $(DEP_CPP_SEARC) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "LibThotEditor - Win32 Debug"

DEP_CPP_SEARC=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\include\fileaccess.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\var\platform_tv.h"\
	".\..\thotlib\internals\var\edit_tv.h"\
	".\..\thotlib\internals\f\applicationapi_f.h"\
	".\..\thotlib\internals\f\tree_f.h"\
	".\..\thotlib\internals\f\attrpresent_f.h"\
	".\..\thotlib\internals\f\search_f.h"\
	".\..\thotlib\internals\f\searchmenu_f.h"\
	".\..\thotlib\internals\f\structcreation_f.h"\
	".\..\thotlib\internals\f\createabsbox_f.h"\
	".\..\thotlib\internals\f\changeabsbox_f.h"\
	".\..\thotlib\internals\f\scroll_f.h"\
	".\..\thotlib\internals\f\views_f.h"\
	".\..\thotlib\internals\f\callback_f.h"\
	".\..\thotlib\internals\f\viewcommands_f.h"\
	".\..\thotlib\internals\f\exceptions_f.h"\
	".\..\thotlib\internals\f\absboxes_f.h"\
	".\..\thotlib\internals\f\memory_f.h"\
	".\..\thotlib\internals\f\structmodif_f.h"\
	".\..\thotlib\internals\f\references_f.h"\
	".\..\thotlib\internals\f\schemas_f.h"\
	".\..\thotlib\internals\f\boxselection_f.h"\
	".\..\thotlib\internals\f\structselect_f.h"\
	".\..\thotlib\internals\f\fileaccess_f.h"\
	".\..\thotlib\internals\f\structschema_f.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\libmsg.h"\
	

"$(INTDIR)\Search.obj" : $(SOURCE) $(DEP_CPP_SEARC) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\Guetari\Opera\Thotlib\Content\searchref.c

!IF  "$(CFG)" == "LibThotEditor - Win32 Release"

DEP_CPP_SEARCH=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\include\libmsg.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\include\fileaccess.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\appdialogue.h"\
	".\..\thotlib\include\labelAllocator.h"\
	".\..\thotlib\internals\var\platform_tv.h"\
	".\..\thotlib\internals\var\edit_tv.h"\
	".\..\thotlib\internals\var\modif_tv.h"\
	".\..\thotlib\internals\var\appdialogue_tv.h"\
	".\..\thotlib\internals\f\tree_f.h"\
	".\..\thotlib\internals\f\attrpresent_f.h"\
	".\..\thotlib\internals\f\search_f.h"\
	".\..\thotlib\internals\f\searchmenu_f.h"\
	".\..\thotlib\internals\f\structcreation_f.h"\
	".\..\thotlib\internals\f\createabsbox_f.h"\
	".\..\thotlib\internals\f\scroll_f.h"\
	".\..\thotlib\internals\f\views_f.h"\
	".\..\thotlib\internals\f\callback_f.h"\
	".\..\thotlib\internals\f\viewcommands_f.h"\
	".\..\thotlib\internals\f\exceptions_f.h"\
	".\..\thotlib\internals\f\absboxes_f.h"\
	".\..\thotlib\internals\f\memory_f.h"\
	".\..\thotlib\internals\f\structmodif_f.h"\
	".\..\thotlib\internals\f\changeabsbox_f.h"\
	".\..\thotlib\internals\f\labelalloc_f.h"\
	".\..\thotlib\internals\f\references_f.h"\
	".\..\thotlib\internals\f\externalref_f.h"\
	".\..\thotlib\internals\f\schemas_f.h"\
	".\..\thotlib\internals\f\boxselection_f.h"\
	".\..\thotlib\internals\f\structselect_f.h"\
	".\..\thotlib\internals\f\fileaccess_f.h"\
	".\..\thotlib\internals\f\structschema_f.h"\
	".\..\thotlib\internals\f\docs_f.h"\
	".\..\thotlib\internals\f\readpivot_f.h"\
	".\..\thotlib\include\sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\thotlib\internals\h\constint.h"\
	".\..\thotlib\internals\h\thotkey.h"\
	".\..\thotlib\internals\h\conststr.h"\
	".\..\thotlib\internals\h\constprs.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\internals\h\frame.h"\
	".\..\thotlib\internals\h\constmenu.h"\
	
NODEP_CPP_SEARCH=\
	".\..\thotlib\include\HTVMSUtils.h"\
	

"$(INTDIR)\searchref.obj" : $(SOURCE) $(DEP_CPP_SEARCH) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "LibThotEditor - Win32 Debug"

DEP_CPP_SEARCH=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\include\libmsg.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\include\fileaccess.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\appdialogue.h"\
	".\..\thotlib\include\labelAllocator.h"\
	".\..\thotlib\internals\var\platform_tv.h"\
	".\..\thotlib\internals\var\edit_tv.h"\
	".\..\thotlib\internals\var\modif_tv.h"\
	".\..\thotlib\internals\var\appdialogue_tv.h"\
	".\..\thotlib\internals\f\tree_f.h"\
	".\..\thotlib\internals\f\attrpresent_f.h"\
	".\..\thotlib\internals\f\search_f.h"\
	".\..\thotlib\internals\f\searchmenu_f.h"\
	".\..\thotlib\internals\f\structcreation_f.h"\
	".\..\thotlib\internals\f\createabsbox_f.h"\
	".\..\thotlib\internals\f\scroll_f.h"\
	".\..\thotlib\internals\f\views_f.h"\
	".\..\thotlib\internals\f\callback_f.h"\
	".\..\thotlib\internals\f\viewcommands_f.h"\
	".\..\thotlib\internals\f\exceptions_f.h"\
	".\..\thotlib\internals\f\absboxes_f.h"\
	".\..\thotlib\internals\f\memory_f.h"\
	".\..\thotlib\internals\f\structmodif_f.h"\
	".\..\thotlib\internals\f\changeabsbox_f.h"\
	".\..\thotlib\internals\f\labelalloc_f.h"\
	".\..\thotlib\internals\f\references_f.h"\
	".\..\thotlib\internals\f\externalref_f.h"\
	".\..\thotlib\internals\f\schemas_f.h"\
	".\..\thotlib\internals\f\boxselection_f.h"\
	".\..\thotlib\internals\f\structselect_f.h"\
	".\..\thotlib\internals\f\fileaccess_f.h"\
	".\..\thotlib\internals\f\structschema_f.h"\
	".\..\thotlib\internals\f\docs_f.h"\
	".\..\thotlib\internals\f\readpivot_f.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\internals\h\frame.h"\
	".\..\thotlib\internals\h\constmenu.h"\
	

"$(INTDIR)\searchref.obj" : $(SOURCE) $(DEP_CPP_SEARCH) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\Guetari\Opera\Thotlib\Content\Word.c

!IF  "$(CFG)" == "LibThotEditor - Win32 Release"

DEP_CPP_WORD_=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\internals\f\structselect_f.h"\
	".\..\thotlib\internals\f\tree_f.h"\
	".\..\thotlib\internals\f\hyphen_f.h"\
	".\..\thotlib\include\sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\thotlib\internals\h\constint.h"\
	".\..\thotlib\internals\h\thotkey.h"\
	".\..\thotlib\internals\h\conststr.h"\
	".\..\thotlib\internals\h\constprs.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	
NODEP_CPP_WORD_=\
	".\..\thotlib\include\HTVMSUtils.h"\
	

"$(INTDIR)\Word.obj" : $(SOURCE) $(DEP_CPP_WORD_) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "LibThotEditor - Win32 Debug"

DEP_CPP_WORD_=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\internals\f\structselect_f.h"\
	".\..\thotlib\internals\f\tree_f.h"\
	".\..\thotlib\internals\f\hyphen_f.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	

"$(INTDIR)\Word.obj" : $(SOURCE) $(DEP_CPP_WORD_) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\Guetari\Opera\Thotlib\Dialogue\appdialogue.c

!IF  "$(CFG)" == "LibThotEditor - Win32 Release"

DEP_CPP_APPDI=\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\internals\h\modif.h"\
	".\..\thotlib\internals\h\appdialogue.h"\
	".\..\thotlib\include\dialog.h"\
	".\..\thotlib\internals\h\logowindow.h"\
	".\..\thotlib\include\application.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\include\libmsg.h"\
	".\..\thotlib\internals\h\LiteClue.h"\
	".\..\thotlib\internals\var\font_tv.h"\
	".\..\thotlib\internals\var\edit_tv.h"\
	".\..\thotlib\internals\var\frame_tv.h"\
	".\..\thotlib\internals\var\units_tv.h"\
	".\..\thotlib\internals\var\appdialogue_tv.h"\
	".\..\thotlib\internals\f\applicationapi_f.h"\
	".\..\thotlib\internals\f\inites_f.h"\
	".\..\thotlib\internals\f\LiteClue_f.h"\
	".\..\thotlib\internals\f\appli_f.h"\
	".\..\thotlib\internals\f\textcommands_f.h"\
	".\..\thotlib\internals\f\structcreation_f.h"\
	".\..\thotlib\internals\f\scroll_f.h"\
	".\..\thotlib\internals\f\boxlocate_f.h"\
	".\..\thotlib\internals\f\dialogapi_f.h"\
	".\..\thotlib\internals\f\views_f.h"\
	".\..\thotlib\internals\f\appdialogue_f.h"\
	".\..\thotlib\internals\f\actions_f.h"\
	".\..\thotlib\internals\f\callback_f.h"\
	".\..\thotlib\internals\f\windowdisplay_f.h"\
	".\..\thotlib\internals\f\font_f.h"\
	".\..\thotlib\internals\f\absboxes_f.h"\
	".\..\thotlib\internals\f\buildboxes_f.h"\
	".\..\thotlib\internals\f\input_f.h"\
	".\..\thotlib\internals\f\memory_f.h"\
	".\..\thotlib\internals\f\structmodif_f.h"\
	".\..\thotlib\internals\f\boxparams_f.h"\
	".\..\thotlib\internals\f\boxselection_f.h"\
	".\..\thotlib\internals\f\structselect_f.h"\
	".\..\thotlib\internals\f\thotmsg_f.h"\
	".\..\thotlib\internals\f\context_f.h"\
	".\..\thotlib\internals\f\dictionary_f.h"\
	".\..\thotlib\internals\f\viewapi_f.h"\
	".\..\thotlib\internals\f\sortmenu_f.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\thotlib\internals\h\constint.h"\
	".\..\thotlib\internals\h\thotkey.h"\
	".\..\thotlib\internals\h\conststr.h"\
	".\..\thotlib\internals\h\constprs.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\internals\h\frame.h"\
	".\..\thotlib\internals\h\constmenu.h"\
	".\..\thotlib\include\fileaccess.h"\
	".\..\thotlib\include\registry.h"\
	
NODEP_CPP_APPDI=\
	".\..\thotlib\include\HTVMSUtils.h"\
	

"$(INTDIR)\appdialogue.obj" : $(SOURCE) $(DEP_CPP_APPDI) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "LibThotEditor - Win32 Debug"

DEP_CPP_APPDI=\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\internals\h\modif.h"\
	".\..\thotlib\internals\h\appdialogue.h"\
	".\..\thotlib\include\dialog.h"\
	".\..\thotlib\internals\h\logowindow.h"\
	".\..\thotlib\include\application.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\include\libmsg.h"\
	".\..\thotlib\internals\h\LiteClue.h"\
	".\..\thotlib\internals\var\font_tv.h"\
	".\..\thotlib\internals\var\edit_tv.h"\
	".\..\thotlib\internals\var\frame_tv.h"\
	".\..\thotlib\internals\var\units_tv.h"\
	".\..\thotlib\internals\var\appdialogue_tv.h"\
	".\..\thotlib\internals\f\applicationapi_f.h"\
	".\..\thotlib\internals\f\inites_f.h"\
	".\..\thotlib\internals\f\LiteClue_f.h"\
	".\..\thotlib\internals\f\appli_f.h"\
	".\..\thotlib\internals\f\textcommands_f.h"\
	".\..\thotlib\internals\f\structcreation_f.h"\
	".\..\thotlib\internals\f\scroll_f.h"\
	".\..\thotlib\internals\f\boxlocate_f.h"\
	".\..\thotlib\internals\f\dialogapi_f.h"\
	".\..\thotlib\internals\f\views_f.h"\
	".\..\thotlib\internals\f\appdialogue_f.h"\
	".\..\thotlib\internals\f\actions_f.h"\
	".\..\thotlib\internals\f\callback_f.h"\
	".\..\thotlib\internals\f\windowdisplay_f.h"\
	".\..\thotlib\internals\f\font_f.h"\
	".\..\thotlib\internals\f\absboxes_f.h"\
	".\..\thotlib\internals\f\buildboxes_f.h"\
	".\..\thotlib\internals\f\input_f.h"\
	".\..\thotlib\internals\f\memory_f.h"\
	".\..\thotlib\internals\f\structmodif_f.h"\
	".\..\thotlib\internals\f\boxparams_f.h"\
	".\..\thotlib\internals\f\boxselection_f.h"\
	".\..\thotlib\internals\f\structselect_f.h"\
	".\..\thotlib\internals\f\thotmsg_f.h"\
	".\..\thotlib\internals\f\context_f.h"\
	".\..\thotlib\internals\f\dictionary_f.h"\
	".\..\thotlib\internals\f\viewapi_f.h"\
	".\..\thotlib\internals\f\sortmenu_f.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\internals\h\frame.h"\
	".\..\thotlib\internals\h\constmenu.h"\
	".\..\thotlib\include\fileaccess.h"\
	".\..\thotlib\include\registry.h"\
	

"$(INTDIR)\appdialogue.obj" : $(SOURCE) $(DEP_CPP_APPDI) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\Guetari\Opera\Thotlib\Dialogue\Appli.c

!IF  "$(CFG)" == "LibThotEditor - Win32 Release"

DEP_CPP_APPLI=\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\thot_key.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\constmenu.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\include\dialog.h"\
	".\..\thotlib\include\application.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\internals\h\appdialogue.h"\
	".\..\thotlib\internals\var\boxes_tv.h"\
	".\..\thotlib\internals\var\font_tv.h"\
	".\..\thotlib\internals\var\edit_tv.h"\
	".\..\thotlib\internals\var\frame_tv.h"\
	".\..\thotlib\internals\var\appdialogue_tv.h"\
	".\..\thotlib\internals\f\absboxes_f.h"\
	".\..\thotlib\internals\f\appli_f.h"\
	".\..\thotlib\internals\f\applicationapi_f.h"\
	".\..\thotlib\internals\f\boxlocate_f.h"\
	".\..\thotlib\internals\f\boxparams_f.h"\
	".\..\thotlib\internals\f\boxselection_f.h"\
	".\..\thotlib\internals\f\buildboxes_f.h"\
	".\..\thotlib\internals\f\callback_f.h"\
	".\..\thotlib\internals\f\context_f.h"\
	".\..\thotlib\internals\f\editcommands_f.h"\
	".\..\thotlib\internals\f\font_f.h"\
	".\..\thotlib\internals\f\frame_f.h"\
	".\..\thotlib\internals\f\input_f.h"\
	".\..\thotlib\internals\f\keyboards_f.h"\
	".\..\thotlib\internals\f\memory_f.h"\
	".\..\thotlib\internals\f\message_f.h"\
	".\..\thotlib\internals\f\scroll_f.h"\
	".\..\thotlib\internals\f\selectmenu_f.h"\
	".\..\thotlib\internals\f\structcommands_f.h"\
	".\..\thotlib\internals\f\structcreation_f.h"\
	".\..\thotlib\internals\f\structmodif_f.h"\
	".\..\thotlib\internals\f\structselect_f.h"\
	".\..\thotlib\internals\f\textcommands_f.h"\
	".\..\thotlib\internals\f\thotmsg_f.h"\
	".\..\thotlib\internals\f\views_f.h"\
	".\..\thotlib\internals\f\viewcommands_f.h"\
	".\..\thotlib\internals\f\viewapi_f.h"\
	".\..\thotlib\internals\f\windowdisplay_f.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\thotlib\internals\h\constint.h"\
	".\..\thotlib\internals\h\thotkey.h"\
	".\..\thotlib\internals\h\conststr.h"\
	".\..\thotlib\internals\h\constprs.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\include\libmsg.h"\
	".\..\thotlib\include\fileaccess.h"\
	".\..\thotlib\include\registry.h"\
	".\..\thotlib\internals\h\frame.h"\
	
NODEP_CPP_APPLI=\
	".\..\thotlib\include\HTVMSUtils.h"\
	

"$(INTDIR)\Appli.obj" : $(SOURCE) $(DEP_CPP_APPLI) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "LibThotEditor - Win32 Debug"

DEP_CPP_APPLI=\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\thot_key.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\constmenu.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\include\dialog.h"\
	".\..\thotlib\include\application.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\internals\h\appdialogue.h"\
	".\..\thotlib\internals\var\boxes_tv.h"\
	".\..\thotlib\internals\var\font_tv.h"\
	".\..\thotlib\internals\var\edit_tv.h"\
	".\..\thotlib\internals\var\frame_tv.h"\
	".\..\thotlib\internals\var\appdialogue_tv.h"\
	".\..\thotlib\internals\f\absboxes_f.h"\
	".\..\thotlib\internals\f\appli_f.h"\
	".\..\thotlib\internals\f\applicationapi_f.h"\
	".\..\thotlib\internals\f\boxlocate_f.h"\
	".\..\thotlib\internals\f\boxparams_f.h"\
	".\..\thotlib\internals\f\boxselection_f.h"\
	".\..\thotlib\internals\f\buildboxes_f.h"\
	".\..\thotlib\internals\f\callback_f.h"\
	".\..\thotlib\internals\f\context_f.h"\
	".\..\thotlib\internals\f\editcommands_f.h"\
	".\..\thotlib\internals\f\font_f.h"\
	".\..\thotlib\internals\f\frame_f.h"\
	".\..\thotlib\internals\f\input_f.h"\
	".\..\thotlib\internals\f\keyboards_f.h"\
	".\..\thotlib\internals\f\memory_f.h"\
	".\..\thotlib\internals\f\message_f.h"\
	".\..\thotlib\internals\f\scroll_f.h"\
	".\..\thotlib\internals\f\selectmenu_f.h"\
	".\..\thotlib\internals\f\structcommands_f.h"\
	".\..\thotlib\internals\f\structcreation_f.h"\
	".\..\thotlib\internals\f\structmodif_f.h"\
	".\..\thotlib\internals\f\structselect_f.h"\
	".\..\thotlib\internals\f\textcommands_f.h"\
	".\..\thotlib\internals\f\thotmsg_f.h"\
	".\..\thotlib\internals\f\views_f.h"\
	".\..\thotlib\internals\f\viewcommands_f.h"\
	".\..\thotlib\internals\f\viewapi_f.h"\
	".\..\thotlib\internals\f\windowdisplay_f.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\include\libmsg.h"\
	".\..\thotlib\include\fileaccess.h"\
	".\..\thotlib\include\registry.h"\
	".\..\thotlib\internals\h\frame.h"\
	

"$(INTDIR)\Appli.obj" : $(SOURCE) $(DEP_CPP_APPLI) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\Guetari\Opera\Thotlib\Dialogue\Attrmenu.c

!IF  "$(CFG)" == "LibThotEditor - Win32 Release"

DEP_CPP_ATTRM=\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\include\dialog.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\include\libmsg.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\internals\h\constmenu.h"\
	".\..\thotlib\internals\h\appdialogue.h"\
	".\..\thotlib\internals\h\winsys.h"\
	".\..\thotlib\internals\var\select_tv.h"\
	".\..\thotlib\internals\var\edit_tv.h"\
	".\..\thotlib\internals\var\frame_tv.h"\
	".\..\thotlib\internals\var\appdialogue_tv.h"\
	".\..\thotlib\internals\f\appli_f.h"\
	".\..\thotlib\internals\f\tree_f.h"\
	".\..\thotlib\internals\f\attrpresent_f.h"\
	".\..\thotlib\internals\f\attributes_f.h"\
	".\..\thotlib\internals\f\structcreation_f.h"\
	".\..\thotlib\internals\f\appdialogue_f.h"\
	".\..\thotlib\internals\f\actions_f.h"\
	".\..\thotlib\internals\f\callback_f.h"\
	".\..\thotlib\internals\f\exceptions_f.h"\
	".\..\thotlib\internals\f\memory_f.h"\
	".\..\thotlib\internals\f\changeabsbox_f.h"\
	".\..\thotlib\internals\f\structselect_f.h"\
	".\..\thotlib\internals\f\selectmenu_f.h"\
	".\..\thotlib\internals\f\structschema_f.h"\
	".\..\thotlib\internals\f\content_f.h"\
	".\..\thotlib\internals\f\applicationapi_f.h"\
	".\..\thotlib\internals\f\language_f.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\thotlib\internals\h\constint.h"\
	".\..\thotlib\internals\h\thotkey.h"\
	".\..\thotlib\internals\h\conststr.h"\
	".\..\thotlib\internals\h\constprs.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\internals\h\frame.h"\
	
NODEP_CPP_ATTRM=\
	".\..\thotlib\include\HTVMSUtils.h"\
	

"$(INTDIR)\Attrmenu.obj" : $(SOURCE) $(DEP_CPP_ATTRM) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "LibThotEditor - Win32 Debug"

DEP_CPP_ATTRM=\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\include\dialog.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\include\libmsg.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\internals\h\constmenu.h"\
	".\..\thotlib\internals\h\appdialogue.h"\
	".\..\thotlib\internals\h\winsys.h"\
	".\..\thotlib\internals\var\select_tv.h"\
	".\..\thotlib\internals\var\edit_tv.h"\
	".\..\thotlib\internals\var\frame_tv.h"\
	".\..\thotlib\internals\var\appdialogue_tv.h"\
	".\..\thotlib\internals\f\appli_f.h"\
	".\..\thotlib\internals\f\tree_f.h"\
	".\..\thotlib\internals\f\attrpresent_f.h"\
	".\..\thotlib\internals\f\attributes_f.h"\
	".\..\thotlib\internals\f\structcreation_f.h"\
	".\..\thotlib\internals\f\appdialogue_f.h"\
	".\..\thotlib\internals\f\actions_f.h"\
	".\..\thotlib\internals\f\callback_f.h"\
	".\..\thotlib\internals\f\exceptions_f.h"\
	".\..\thotlib\internals\f\memory_f.h"\
	".\..\thotlib\internals\f\changeabsbox_f.h"\
	".\..\thotlib\internals\f\structselect_f.h"\
	".\..\thotlib\internals\f\selectmenu_f.h"\
	".\..\thotlib\internals\f\structschema_f.h"\
	".\..\thotlib\internals\f\content_f.h"\
	".\..\thotlib\internals\f\applicationapi_f.h"\
	".\..\thotlib\internals\f\language_f.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\internals\h\frame.h"\
	

"$(INTDIR)\Attrmenu.obj" : $(SOURCE) $(DEP_CPP_ATTRM) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\Guetari\Opera\Thotlib\Dialogue\Browser.c

!IF  "$(CFG)" == "LibThotEditor - Win32 Release"

DEP_CPP_BROWS=\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\thotdir.h"\
	".\..\thotlib\include\dialog.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\include\application.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\thotlib\include\libmsg.h"\
	".\..\thotlib\include\fileaccess.h"\
	".\..\thotlib\include\registry.h"\
	
NODEP_CPP_BROWS=\
	".\..\thotlib\include\HTVMSUtils.h"\
	

"$(INTDIR)\Browser.obj" : $(SOURCE) $(DEP_CPP_BROWS) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "LibThotEditor - Win32 Debug"

DEP_CPP_BROWS=\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\thotdir.h"\
	".\..\thotlib\include\dialog.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\include\application.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\libmsg.h"\
	".\..\thotlib\include\fileaccess.h"\
	".\..\thotlib\include\registry.h"\
	

"$(INTDIR)\Browser.obj" : $(SOURCE) $(DEP_CPP_BROWS) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\Guetari\Opera\Thotlib\Dialogue\Callback.c

!IF  "$(CFG)" == "LibThotEditor - Win32 Release"

DEP_CPP_CALLB=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\internals\h\modif.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\internals\var\edit_tv.h"\
	".\..\thotlib\internals\var\appevents_tv.h"\
	".\..\thotlib\internals\f\readstr_f.h"\
	".\..\thotlib\internals\f\callbackinit_f.h"\
	".\..\thotlib\include\sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\thotlib\internals\h\constint.h"\
	".\..\thotlib\internals\h\thotkey.h"\
	".\..\thotlib\internals\h\conststr.h"\
	".\..\thotlib\internals\h\constprs.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	
NODEP_CPP_CALLB=\
	".\..\thotlib\include\HTVMSUtils.h"\
	

"$(INTDIR)\Callback.obj" : $(SOURCE) $(DEP_CPP_CALLB) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "LibThotEditor - Win32 Debug"

DEP_CPP_CALLB=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\internals\h\modif.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\internals\var\edit_tv.h"\
	".\..\thotlib\internals\var\appevents_tv.h"\
	".\..\thotlib\internals\f\readstr_f.h"\
	".\..\thotlib\internals\f\callbackinit_f.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	

"$(INTDIR)\Callback.obj" : $(SOURCE) $(DEP_CPP_CALLB) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\Guetari\Opera\Thotlib\Dialogue\callbackinit.c

!IF  "$(CFG)" == "LibThotEditor - Win32 Release"

DEP_CPP_CALLBA=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\internals\h\modif.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\internals\f\memory_f.h"\
	".\..\thotlib\internals\f\readstr_f.h"\
	".\..\thotlib\internals\var\appevents_tv.h"\
	".\..\thotlib\include\sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\thotlib\internals\h\constint.h"\
	".\..\thotlib\internals\h\thotkey.h"\
	".\..\thotlib\internals\h\conststr.h"\
	".\..\thotlib\internals\h\constprs.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	
NODEP_CPP_CALLBA=\
	".\..\thotlib\include\HTVMSUtils.h"\
	

"$(INTDIR)\callbackinit.obj" : $(SOURCE) $(DEP_CPP_CALLBA) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "LibThotEditor - Win32 Debug"

DEP_CPP_CALLBA=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\internals\h\modif.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\internals\f\memory_f.h"\
	".\..\thotlib\internals\f\readstr_f.h"\
	".\..\thotlib\internals\var\appevents_tv.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	

"$(INTDIR)\callbackinit.obj" : $(SOURCE) $(DEP_CPP_CALLBA) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\Guetari\Opera\Thotlib\Dialogue\Closedoc.c

!IF  "$(CFG)" == "LibThotEditor - Win32 Release"

DEP_CPP_CLOSE=\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmenu.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\internals\h\appdialogue.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\include\dialog.h"\
	".\..\thotlib\internals\var\edit_tv.h"\
	".\..\thotlib\internals\var\frame_tv.h"\
	".\..\thotlib\internals\var\appdialogue_tv.h"\
	".\..\thotlib\internals\f\views_f.h"\
	".\..\thotlib\internals\f\appdialogue_f.h"\
	".\..\thotlib\internals\f\actions_f.h"\
	".\..\thotlib\internals\f\docs_f.h"\
	".\..\thotlib\internals\f\viewcommands_f.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\thotlib\internals\h\constint.h"\
	".\..\thotlib\internals\h\thotkey.h"\
	".\..\thotlib\internals\h\conststr.h"\
	".\..\thotlib\internals\h\constprs.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\frame.h"\
	".\..\thotlib\include\libmsg.h"\
	
NODEP_CPP_CLOSE=\
	".\..\thotlib\include\HTVMSUtils.h"\
	

"$(INTDIR)\Closedoc.obj" : $(SOURCE) $(DEP_CPP_CLOSE) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "LibThotEditor - Win32 Debug"

DEP_CPP_CLOSE=\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmenu.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\internals\h\appdialogue.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\include\dialog.h"\
	".\..\thotlib\internals\var\edit_tv.h"\
	".\..\thotlib\internals\var\frame_tv.h"\
	".\..\thotlib\internals\var\appdialogue_tv.h"\
	".\..\thotlib\internals\f\views_f.h"\
	".\..\thotlib\internals\f\appdialogue_f.h"\
	".\..\thotlib\internals\f\actions_f.h"\
	".\..\thotlib\internals\f\docs_f.h"\
	".\..\thotlib\internals\f\viewcommands_f.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\frame.h"\
	".\..\thotlib\include\libmsg.h"\
	

"$(INTDIR)\Closedoc.obj" : $(SOURCE) $(DEP_CPP_CLOSE) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\Guetari\Opera\Thotlib\Dialogue\Colors.c

!IF  "$(CFG)" == "LibThotEditor - Win32 Release"

DEP_CPP_COLOR=\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\internals\h\constmenu.h"\
	".\..\thotlib\internals\h\appdialogue.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\include\dialog.h"\
	".\..\thotlib\internals\h\thotcolor.h"\
	".\..\thotlib\internals\h\winsys.h"\
	".\..\thotlib\internals\var\edit_tv.h"\
	".\..\thotlib\internals\var\frame_tv.h"\
	".\..\thotlib\internals\var\font_tv.h"\
	".\..\thotlib\internals\var\select_tv.h"\
	".\..\thotlib\internals\var\appdialogue_tv.h"\
	".\..\thotlib\internals\var\thotcolor_tv.h"\
	".\..\thotlib\internals\f\config_f.h"\
	".\..\thotlib\internals\f\appdialogue_f.h"\
	".\..\thotlib\internals\f\actions_f.h"\
	".\..\thotlib\internals\f\windowdisplay_f.h"\
	".\..\thotlib\internals\f\font_f.h"\
	".\..\thotlib\internals\f\changepresent_f.h"\
	".\..\thotlib\internals\f\structselect_f.h"\
	".\..\thotlib\internals\f\inites_f.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\thotlib\internals\h\constint.h"\
	".\..\thotlib\internals\h\thotkey.h"\
	".\..\thotlib\internals\h\conststr.h"\
	".\..\thotlib\internals\h\constprs.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\internals\h\frame.h"\
	".\..\thotlib\include\libmsg.h"\
	
NODEP_CPP_COLOR=\
	".\..\thotlib\include\HTVMSUtils.h"\
	

"$(INTDIR)\Colors.obj" : $(SOURCE) $(DEP_CPP_COLOR) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "LibThotEditor - Win32 Debug"

DEP_CPP_COLOR=\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\internals\h\constmenu.h"\
	".\..\thotlib\internals\h\appdialogue.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\include\dialog.h"\
	".\..\thotlib\internals\h\thotcolor.h"\
	".\..\thotlib\internals\h\winsys.h"\
	".\..\thotlib\internals\var\edit_tv.h"\
	".\..\thotlib\internals\var\frame_tv.h"\
	".\..\thotlib\internals\var\font_tv.h"\
	".\..\thotlib\internals\var\select_tv.h"\
	".\..\thotlib\internals\var\appdialogue_tv.h"\
	".\..\thotlib\internals\var\thotcolor_tv.h"\
	".\..\thotlib\internals\f\config_f.h"\
	".\..\thotlib\internals\f\appdialogue_f.h"\
	".\..\thotlib\internals\f\actions_f.h"\
	".\..\thotlib\internals\f\windowdisplay_f.h"\
	".\..\thotlib\internals\f\font_f.h"\
	".\..\thotlib\internals\f\changepresent_f.h"\
	".\..\thotlib\internals\f\structselect_f.h"\
	".\..\thotlib\internals\f\inites_f.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\internals\h\frame.h"\
	".\..\thotlib\include\libmsg.h"\
	

"$(INTDIR)\Colors.obj" : $(SOURCE) $(DEP_CPP_COLOR) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\Guetari\Opera\Thotlib\Dialogue\Context.c

!IF  "$(CFG)" == "LibThotEditor - Win32 Release"

DEP_CPP_CONTEX=\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\include\libmsg.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\internals\h\picture.h"\
	".\..\thotlib\internals\h\appdialogue.h"\
	".\..\thotlib\internals\var\frame_tv.h"\
	".\..\thotlib\internals\var\boxes_tv.h"\
	".\..\thotlib\internals\var\thotcolor_tv.h"\
	".\..\thotlib\internals\var\appdialogue_tv.h"\
	".\..\thotlib\internals\f\appli_f.h"\
	".\..\thotlib\internals\f\textcommands_f.h"\
	".\..\thotlib\internals\f\editcommands_f.h"\
	".\..\thotlib\internals\f\checkermenu_f.h"\
	".\..\thotlib\internals\f\font_f.h"\
	".\..\thotlib\internals\f\picture_f.h"\
	".\..\thotlib\internals\f\inites_f.h"\
	".\..\thotlib\internals\f\memory_f.h"\
	".\..\thotlib\internals\f\registry_f.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\thotlib\internals\h\constint.h"\
	".\..\thotlib\internals\h\thotkey.h"\
	".\..\thotlib\internals\h\conststr.h"\
	".\..\thotlib\internals\h\constprs.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\internals\h\frame.h"\
	".\..\thotlib\internals\h\constmenu.h"\
	".\..\thotlib\internals\h\thotcolor.h"\
	
NODEP_CPP_CONTEX=\
	".\..\thotlib\include\HTVMSUtils.h"\
	

"$(INTDIR)\Context.obj" : $(SOURCE) $(DEP_CPP_CONTEX) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "LibThotEditor - Win32 Debug"

DEP_CPP_CONTEX=\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\include\libmsg.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\internals\h\picture.h"\
	".\..\thotlib\internals\h\appdialogue.h"\
	".\..\thotlib\internals\var\frame_tv.h"\
	".\..\thotlib\internals\var\boxes_tv.h"\
	".\..\thotlib\internals\var\thotcolor_tv.h"\
	".\..\thotlib\internals\var\appdialogue_tv.h"\
	".\..\thotlib\internals\f\appli_f.h"\
	".\..\thotlib\internals\f\textcommands_f.h"\
	".\..\thotlib\internals\f\editcommands_f.h"\
	".\..\thotlib\internals\f\checkermenu_f.h"\
	".\..\thotlib\internals\f\font_f.h"\
	".\..\thotlib\internals\f\picture_f.h"\
	".\..\thotlib\internals\f\inites_f.h"\
	".\..\thotlib\internals\f\memory_f.h"\
	".\..\thotlib\internals\f\registry_f.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\internals\h\frame.h"\
	".\..\thotlib\internals\h\constmenu.h"\
	".\..\thotlib\internals\h\thotcolor.h"\
	

"$(INTDIR)\Context.obj" : $(SOURCE) $(DEP_CPP_CONTEX) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\Guetari\Opera\Thotlib\Dialogue\createdoc.c

!IF  "$(CFG)" == "LibThotEditor - Win32 Release"

DEP_CPP_CREAT=\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmenu.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\internals\h\appdialogue.h"\
	".\..\thotlib\include\libmsg.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\include\dialog.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\fileaccess.h"\
	".\..\thotlib\internals\h\thotdir.h"\
	".\..\thotlib\internals\var\edit_tv.h"\
	".\..\thotlib\internals\var\appdialogue_tv.h"\
	".\..\thotlib\internals\var\platform_tv.h"\
	".\..\thotlib\internals\f\structschema_f.h"\
	".\..\thotlib\internals\f\browser_f.h"\
	".\..\thotlib\internals\f\platform_f.h"\
	".\..\thotlib\internals\f\appdialogue_f.h"\
	".\..\thotlib\internals\f\actions_f.h"\
	".\..\thotlib\internals\f\views_f.h"\
	".\..\thotlib\internals\f\config_f.h"\
	".\..\thotlib\internals\f\opendoc_f.h"\
	".\..\thotlib\internals\f\docs_f.h"\
	".\..\thotlib\internals\f\applicationapi_f.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\constint.h"\
	".\..\thotlib\internals\h\thotkey.h"\
	".\..\thotlib\internals\h\conststr.h"\
	".\..\thotlib\internals\h\constprs.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\internals\h\frame.h"\
	
NODEP_CPP_CREAT=\
	".\..\thotlib\include\HTVMSUtils.h"\
	

"$(INTDIR)\createdoc.obj" : $(SOURCE) $(DEP_CPP_CREAT) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "LibThotEditor - Win32 Debug"

DEP_CPP_CREAT=\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmenu.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\internals\h\appdialogue.h"\
	".\..\thotlib\include\libmsg.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\include\dialog.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\fileaccess.h"\
	".\..\thotlib\internals\h\thotdir.h"\
	".\..\thotlib\internals\var\edit_tv.h"\
	".\..\thotlib\internals\var\appdialogue_tv.h"\
	".\..\thotlib\internals\var\platform_tv.h"\
	".\..\thotlib\internals\f\structschema_f.h"\
	".\..\thotlib\internals\f\browser_f.h"\
	".\..\thotlib\internals\f\platform_f.h"\
	".\..\thotlib\internals\f\appdialogue_f.h"\
	".\..\thotlib\internals\f\actions_f.h"\
	".\..\thotlib\internals\f\views_f.h"\
	".\..\thotlib\internals\f\config_f.h"\
	".\..\thotlib\internals\f\opendoc_f.h"\
	".\..\thotlib\internals\f\docs_f.h"\
	".\..\thotlib\internals\f\applicationapi_f.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\internals\h\frame.h"\
	

"$(INTDIR)\createdoc.obj" : $(SOURCE) $(DEP_CPP_CREAT) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\Guetari\Opera\Thotlib\Dialogue\creationmenu.c

!IF  "$(CFG)" == "LibThotEditor - Win32 Release"

DEP_CPP_CREATI=\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\include\dialog.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\constmenu.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\internals\var\modif_tv.h"\
	".\..\thotlib\internals\var\select_tv.h"\
	".\..\thotlib\internals\var\platform_tv.h"\
	".\..\thotlib\internals\var\edit_tv.h"\
	".\..\thotlib\internals\f\structcreation_f.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\thotlib\include\libmsg.h"\
	".\..\thotlib\internals\h\constint.h"\
	".\..\thotlib\internals\h\thotkey.h"\
	".\..\thotlib\internals\h\conststr.h"\
	".\..\thotlib\internals\h\constprs.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	
NODEP_CPP_CREATI=\
	".\..\thotlib\include\HTVMSUtils.h"\
	

"$(INTDIR)\creationmenu.obj" : $(SOURCE) $(DEP_CPP_CREATI) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "LibThotEditor - Win32 Debug"

DEP_CPP_CREATI=\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\include\dialog.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\constmenu.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\internals\var\modif_tv.h"\
	".\..\thotlib\internals\var\select_tv.h"\
	".\..\thotlib\internals\var\platform_tv.h"\
	".\..\thotlib\internals\var\edit_tv.h"\
	".\..\thotlib\internals\f\structcreation_f.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\libmsg.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	

"$(INTDIR)\creationmenu.obj" : $(SOURCE) $(DEP_CPP_CREATI) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\Guetari\Opera\Thotlib\Dialogue\dialogapi.c

!IF  "$(CFG)" == "LibThotEditor - Win32 Release"

DEP_CPP_DIALO=\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\internals\h\copyright.xbm"\
	".\..\thotlib\include\dialog.h"\
	".\..\thotlib\include\application.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\internals\h\appdialogue.h"\
	".\..\thotlib\internals\f\appli_f.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\internals\h\winsys.h"\
	".\..\thotlib\internals\var\thotcolor_tv.h"\
	".\..\thotlib\internals\var\frame_tv.h"\
	".\..\thotlib\internals\var\font_tv.h"\
	".\..\thotlib\internals\var\appdialogue_tv.h"\
	".\..\thotlib\internals\f\appdialogue_f.h"\
	".\..\thotlib\internals\f\memory_f.h"\
	".\..\thotlib\internals\f\thotmsg_f.h"\
	".\..\Thotlib\Dialogue\winerrdata.c"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\thotlib\internals\h\constint.h"\
	".\..\thotlib\internals\h\thotkey.h"\
	".\..\thotlib\internals\h\conststr.h"\
	".\..\thotlib\internals\h\constprs.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\include\fileaccess.h"\
	".\..\thotlib\include\registry.h"\
	".\..\thotlib\internals\h\frame.h"\
	".\..\thotlib\internals\h\constmenu.h"\
	".\..\thotlib\include\libmsg.h"\
	".\..\thotlib\internals\h\thotcolor.h"\
	
NODEP_CPP_DIALO=\
	".\..\thotlib\include\HTVMSUtils.h"\
	

"$(INTDIR)\dialogapi.obj" : $(SOURCE) $(DEP_CPP_DIALO) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "LibThotEditor - Win32 Debug"

DEP_CPP_DIALO=\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\internals\h\copyright.xbm"\
	".\..\thotlib\include\dialog.h"\
	".\..\thotlib\include\application.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\internals\h\appdialogue.h"\
	".\..\thotlib\internals\f\appli_f.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\internals\h\winsys.h"\
	".\..\thotlib\internals\var\thotcolor_tv.h"\
	".\..\thotlib\internals\var\frame_tv.h"\
	".\..\thotlib\internals\var\font_tv.h"\
	".\..\thotlib\internals\var\appdialogue_tv.h"\
	".\..\thotlib\internals\f\appdialogue_f.h"\
	".\..\thotlib\internals\f\memory_f.h"\
	".\..\thotlib\internals\f\thotmsg_f.h"\
	".\..\Thotlib\Dialogue\winerrdata.c"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\include\fileaccess.h"\
	".\..\thotlib\include\registry.h"\
	".\..\thotlib\internals\h\frame.h"\
	".\..\thotlib\internals\h\constmenu.h"\
	".\..\thotlib\include\libmsg.h"\
	".\..\thotlib\internals\h\thotcolor.h"\
	

"$(INTDIR)\dialogapi.obj" : $(SOURCE) $(DEP_CPP_DIALO) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\Guetari\Opera\Thotlib\Dialogue\extprintmenu.c

!IF  "$(CFG)" == "LibThotEditor - Win32 Release"

DEP_CPP_EXTPR=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\include\libmsg.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\internals\h\constmenu.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\dialog.h"\
	".\..\thotlib\internals\h\appdialogue.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\print.h"\
	".\..\thotlib\internals\var\print_tv.h"\
	".\..\thotlib\internals\var\edit_tv.h"\
	".\..\thotlib\internals\var\appdialogue_tv.h"\
	".\..\thotlib\internals\f\printmenu_f.h"\
	".\..\thotlib\internals\f\views_f.h"\
	".\..\thotlib\internals\f\actions_f.h"\
	".\..\thotlib\include\sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\thotlib\internals\h\constint.h"\
	".\..\thotlib\internals\h\thotkey.h"\
	".\..\thotlib\internals\h\conststr.h"\
	".\..\thotlib\internals\h\constprs.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\internals\h\frame.h"\
	
NODEP_CPP_EXTPR=\
	".\..\thotlib\include\HTVMSUtils.h"\
	

"$(INTDIR)\extprintmenu.obj" : $(SOURCE) $(DEP_CPP_EXTPR) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "LibThotEditor - Win32 Debug"

DEP_CPP_EXTPR=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\include\libmsg.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\internals\h\constmenu.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\dialog.h"\
	".\..\thotlib\internals\h\appdialogue.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\print.h"\
	".\..\thotlib\internals\var\print_tv.h"\
	".\..\thotlib\internals\var\edit_tv.h"\
	".\..\thotlib\internals\var\appdialogue_tv.h"\
	".\..\thotlib\internals\f\printmenu_f.h"\
	".\..\thotlib\internals\f\views_f.h"\
	".\..\thotlib\internals\f\actions_f.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\internals\h\frame.h"\
	

"$(INTDIR)\extprintmenu.obj" : $(SOURCE) $(DEP_CPP_EXTPR) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\Guetari\Opera\Thotlib\Dialogue\Font.c

!IF  "$(CFG)" == "LibThotEditor - Win32 Release"

DEP_CPP_FONT_=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\include\libmsg.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\internals\h\frame.h"\
	".\..\thotlib\internals\h\xpmP.h"\
	".\..\thotlib\internals\var\frame_tv.h"\
	".\..\thotlib\internals\var\units_tv.h"\
	".\..\thotlib\internals\var\font_tv.h"\
	".\..\thotlib\internals\f\memory_f.h"\
	".\..\thotlib\internals\f\font_f.h"\
	".\..\thotlib\internals\f\units_f.h"\
	".\..\thotlib\internals\f\windowdisplay_f.h"\
	".\..\thotlib\internals\f\buildlines_f.h"\
	".\..\thotlib\internals\f\registry_f.h"\
	".\..\thotlib\include\sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\thotlib\internals\h\constint.h"\
	".\..\thotlib\internals\h\thotkey.h"\
	".\..\thotlib\internals\h\conststr.h"\
	".\..\thotlib\internals\h\constprs.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\internals\h\constmenu.h"\
	".\..\thotlib\internals\h\xpm.h"\
	
NODEP_CPP_FONT_=\
	".\..\thotlib\include\HTVMSUtils.h"\
	

"$(INTDIR)\Font.obj" : $(SOURCE) $(DEP_CPP_FONT_) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "LibThotEditor - Win32 Debug"

DEP_CPP_FONT_=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\include\libmsg.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\internals\h\frame.h"\
	".\..\thotlib\internals\h\xpmP.h"\
	".\..\thotlib\internals\var\frame_tv.h"\
	".\..\thotlib\internals\var\units_tv.h"\
	".\..\thotlib\internals\var\font_tv.h"\
	".\..\thotlib\internals\f\memory_f.h"\
	".\..\thotlib\internals\f\font_f.h"\
	".\..\thotlib\internals\f\units_f.h"\
	".\..\thotlib\internals\f\windowdisplay_f.h"\
	".\..\thotlib\internals\f\buildlines_f.h"\
	".\..\thotlib\internals\f\registry_f.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\internals\h\constmenu.h"\
	".\..\thotlib\internals\h\xpm.h"\
	

"$(INTDIR)\Font.obj" : $(SOURCE) $(DEP_CPP_FONT_) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\Guetari\Opera\Thotlib\Dialogue\Geom.c

!IF  "$(CFG)" == "LibThotEditor - Win32 Release"

DEP_CPP_GEOM_=\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\internals\h\frame.h"\
	".\..\thotlib\include\libmsg.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\internals\var\frame_tv.h"\
	".\..\thotlib\internals\f\appli_f.h"\
	".\..\thotlib\internals\f\windowdisplay_f.h"\
	".\..\thotlib\internals\f\font_f.h"\
	".\..\thotlib\internals\f\units_f.h"\
	".\..\thotlib\internals\f\memory_f.h"\
	".\..\thotlib\internals\f\content_f.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\thotlib\internals\h\constint.h"\
	".\..\thotlib\internals\h\thotkey.h"\
	".\..\thotlib\internals\h\conststr.h"\
	".\..\thotlib\internals\h\constprs.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\internals\h\constmenu.h"\
	
NODEP_CPP_GEOM_=\
	".\..\thotlib\include\HTVMSUtils.h"\
	

"$(INTDIR)\Geom.obj" : $(SOURCE) $(DEP_CPP_GEOM_) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "LibThotEditor - Win32 Debug"

DEP_CPP_GEOM_=\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\internals\h\frame.h"\
	".\..\thotlib\include\libmsg.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\internals\var\frame_tv.h"\
	".\..\thotlib\internals\f\appli_f.h"\
	".\..\thotlib\internals\f\windowdisplay_f.h"\
	".\..\thotlib\internals\f\font_f.h"\
	".\..\thotlib\internals\f\units_f.h"\
	".\..\thotlib\internals\f\memory_f.h"\
	".\..\thotlib\internals\f\content_f.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\internals\h\constmenu.h"\
	

"$(INTDIR)\Geom.obj" : $(SOURCE) $(DEP_CPP_GEOM_) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\Guetari\Opera\Thotlib\Dialogue\Input.c

!IF  "$(CFG)" == "LibThotEditor - Win32 Release"

DEP_CPP_INPUT=\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\thot_key.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\include\libmsg.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\internals\h\appdialogue.h"\
	".\..\thotlib\internals\var\boxes_tv.h"\
	".\..\thotlib\internals\var\frame_tv.h"\
	".\..\thotlib\internals\var\edit_tv.h"\
	".\..\thotlib\internals\var\appdialogue_tv.h"\
	".\..\thotlib\internals\f\appli_f.h"\
	".\..\thotlib\internals\f\applicationapi_f.h"\
	".\..\thotlib\internals\f\context_f.h"\
	".\..\thotlib\internals\f\editcommands_f.h"\
	".\..\thotlib\internals\f\input_f.h"\
	".\..\thotlib\internals\f\memory_f.h"\
	".\..\thotlib\internals\f\message_f.h"\
	".\..\thotlib\internals\f\registry_f.h"\
	".\..\thotlib\internals\f\structcommands_f.h"\
	".\..\thotlib\internals\f\structmodif_f.h"\
	".\..\thotlib\internals\f\structselect_f.h"\
	".\..\thotlib\internals\f\textcommands_f.h"\
	".\..\thotlib\internals\f\windowdisplay_f.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\thotlib\internals\h\constint.h"\
	".\..\thotlib\internals\h\thotkey.h"\
	".\..\thotlib\internals\h\conststr.h"\
	".\..\thotlib\internals\h\constprs.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\internals\h\frame.h"\
	".\..\thotlib\internals\h\constmenu.h"\
	
NODEP_CPP_INPUT=\
	".\..\thotlib\include\HTVMSUtils.h"\
	

"$(INTDIR)\Input.obj" : $(SOURCE) $(DEP_CPP_INPUT) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "LibThotEditor - Win32 Debug"

DEP_CPP_INPUT=\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\thot_key.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\include\libmsg.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\internals\h\appdialogue.h"\
	".\..\thotlib\internals\var\boxes_tv.h"\
	".\..\thotlib\internals\var\frame_tv.h"\
	".\..\thotlib\internals\var\edit_tv.h"\
	".\..\thotlib\internals\var\appdialogue_tv.h"\
	".\..\thotlib\internals\f\appli_f.h"\
	".\..\thotlib\internals\f\applicationapi_f.h"\
	".\..\thotlib\internals\f\context_f.h"\
	".\..\thotlib\internals\f\editcommands_f.h"\
	".\..\thotlib\internals\f\input_f.h"\
	".\..\thotlib\internals\f\memory_f.h"\
	".\..\thotlib\internals\f\message_f.h"\
	".\..\thotlib\internals\f\registry_f.h"\
	".\..\thotlib\internals\f\structcommands_f.h"\
	".\..\thotlib\internals\f\structmodif_f.h"\
	".\..\thotlib\internals\f\structselect_f.h"\
	".\..\thotlib\internals\f\textcommands_f.h"\
	".\..\thotlib\internals\f\windowdisplay_f.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\internals\h\frame.h"\
	".\..\thotlib\internals\h\constmenu.h"\
	

"$(INTDIR)\Input.obj" : $(SOURCE) $(DEP_CPP_INPUT) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\Guetari\Opera\Thotlib\Dialogue\interface.c

!IF  "$(CFG)" == "LibThotEditor - Win32 Release"

DEP_CPP_INTER=\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmenu.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\internals\h\picture.h"\
	".\..\thotlib\include\libmsg.h"\
	".\..\thotlib\include\dialog.h"\
	".\..\thotlib\include\application.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\internals\h\appdialogue.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\var\edit_tv.h"\
	".\..\thotlib\internals\var\font_tv.h"\
	".\..\thotlib\internals\var\boxes_tv.h"\
	".\..\thotlib\internals\var\frame_tv.h"\
	".\..\thotlib\internals\var\appdialogue_tv.h"\
	".\..\thotlib\internals\f\displaybox_f.h"\
	".\..\thotlib\internals\f\appli_f.h"\
	".\..\thotlib\internals\f\context_f.h"\
	".\..\thotlib\internals\f\dialogapi_f.h"\
	".\..\thotlib\internals\f\views_f.h"\
	".\..\thotlib\internals\f\appdialogue_f.h"\
	".\..\thotlib\internals\f\actions_f.h"\
	".\..\thotlib\internals\f\callback_f.h"\
	".\..\thotlib\internals\f\font_f.h"\
	".\..\thotlib\internals\f\inites_f.h"\
	".\..\thotlib\internals\f\input_f.h"\
	".\..\thotlib\internals\f\keyboards_f.h"\
	".\..\thotlib\internals\f\message_f.h"\
	".\..\thotlib\internals\f\thotmsg_f.h"\
	".\..\thotlib\internals\f\viewapi_f.h"\
	".\..\thotlib\internals\f\applicationapi_f.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\thotlib\internals\h\constint.h"\
	".\..\thotlib\internals\h\thotkey.h"\
	".\..\thotlib\internals\h\conststr.h"\
	".\..\thotlib\internals\h\constprs.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\include\fileaccess.h"\
	".\..\thotlib\include\registry.h"\
	".\..\thotlib\internals\h\frame.h"\
	
NODEP_CPP_INTER=\
	".\..\thotlib\include\HTVMSUtils.h"\
	

"$(INTDIR)\interface.obj" : $(SOURCE) $(DEP_CPP_INTER) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "LibThotEditor - Win32 Debug"

DEP_CPP_INTER=\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmenu.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\internals\h\picture.h"\
	".\..\thotlib\include\libmsg.h"\
	".\..\thotlib\include\dialog.h"\
	".\..\thotlib\include\application.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\internals\h\appdialogue.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\var\edit_tv.h"\
	".\..\thotlib\internals\var\font_tv.h"\
	".\..\thotlib\internals\var\boxes_tv.h"\
	".\..\thotlib\internals\var\frame_tv.h"\
	".\..\thotlib\internals\var\appdialogue_tv.h"\
	".\..\thotlib\internals\f\displaybox_f.h"\
	".\..\thotlib\internals\f\appli_f.h"\
	".\..\thotlib\internals\f\context_f.h"\
	".\..\thotlib\internals\f\dialogapi_f.h"\
	".\..\thotlib\internals\f\views_f.h"\
	".\..\thotlib\internals\f\appdialogue_f.h"\
	".\..\thotlib\internals\f\actions_f.h"\
	".\..\thotlib\internals\f\callback_f.h"\
	".\..\thotlib\internals\f\font_f.h"\
	".\..\thotlib\internals\f\inites_f.h"\
	".\..\thotlib\internals\f\input_f.h"\
	".\..\thotlib\internals\f\keyboards_f.h"\
	".\..\thotlib\internals\f\message_f.h"\
	".\..\thotlib\internals\f\thotmsg_f.h"\
	".\..\thotlib\internals\f\viewapi_f.h"\
	".\..\thotlib\internals\f\applicationapi_f.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\include\fileaccess.h"\
	".\..\thotlib\include\registry.h"\
	".\..\thotlib\internals\h\frame.h"\
	

"$(INTDIR)\interface.obj" : $(SOURCE) $(DEP_CPP_INTER) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\Guetari\Opera\Thotlib\Dialogue\keyboards.c

!IF  "$(CFG)" == "LibThotEditor - Win32 Release"

DEP_CPP_KEYBO=\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\internals\h\constmenu.h"\
	".\..\thotlib\internals\h\appdialogue.h"\
	".\..\thotlib\include\dialog.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\internals\var\edit_tv.h"\
	".\..\thotlib\internals\var\frame_tv.h"\
	".\..\thotlib\internals\var\font_tv.h"\
	".\..\thotlib\internals\var\select_tv.h"\
	".\..\thotlib\internals\var\appdialogue_tv.h"\
	".\..\thotlib\internals\f\actions_f.h"\
	".\..\thotlib\internals\f\appdialogue_f.h"\
	".\..\thotlib\internals\f\applicationapi_f.h"\
	".\..\thotlib\internals\f\config_f.h"\
	".\..\thotlib\internals\f\editcommands_f.h"\
	".\..\thotlib\internals\f\font_f.h"\
	".\..\thotlib\internals\f\structselect_f.h"\
	".\..\thotlib\internals\f\textcommands_f.h"\
	".\..\thotlib\internals\f\windowdisplay_f.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\thotlib\internals\h\constint.h"\
	".\..\thotlib\internals\h\thotkey.h"\
	".\..\thotlib\internals\h\conststr.h"\
	".\..\thotlib\internals\h\constprs.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\internals\h\frame.h"\
	".\..\thotlib\include\libmsg.h"\
	
NODEP_CPP_KEYBO=\
	".\..\thotlib\include\HTVMSUtils.h"\
	

"$(INTDIR)\keyboards.obj" : $(SOURCE) $(DEP_CPP_KEYBO) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "LibThotEditor - Win32 Debug"

DEP_CPP_KEYBO=\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\internals\h\constmenu.h"\
	".\..\thotlib\internals\h\appdialogue.h"\
	".\..\thotlib\include\dialog.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\internals\var\edit_tv.h"\
	".\..\thotlib\internals\var\frame_tv.h"\
	".\..\thotlib\internals\var\font_tv.h"\
	".\..\thotlib\internals\var\select_tv.h"\
	".\..\thotlib\internals\var\appdialogue_tv.h"\
	".\..\thotlib\internals\f\actions_f.h"\
	".\..\thotlib\internals\f\appdialogue_f.h"\
	".\..\thotlib\internals\f\applicationapi_f.h"\
	".\..\thotlib\internals\f\config_f.h"\
	".\..\thotlib\internals\f\editcommands_f.h"\
	".\..\thotlib\internals\f\font_f.h"\
	".\..\thotlib\internals\f\structselect_f.h"\
	".\..\thotlib\internals\f\textcommands_f.h"\
	".\..\thotlib\internals\f\windowdisplay_f.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\internals\h\frame.h"\
	".\..\thotlib\include\libmsg.h"\
	

"$(INTDIR)\keyboards.obj" : $(SOURCE) $(DEP_CPP_KEYBO) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\Guetari\Opera\Thotlib\Dialogue\LiteClue.c

!IF  "$(CFG)" == "LibThotEditor - Win32 Release"

DEP_CPP_LITEC=\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\LiteClueP.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\thotlib\internals\h\LiteClue.h"\
	
NODEP_CPP_LITEC=\
	".\..\thotlib\include\HTVMSUtils.h"\
	

"$(INTDIR)\LiteClue.obj" : $(SOURCE) $(DEP_CPP_LITEC) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "LibThotEditor - Win32 Debug"

DEP_CPP_LITEC=\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\LiteClueP.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\internals\h\LiteClue.h"\
	

"$(INTDIR)\LiteClue.obj" : $(SOURCE) $(DEP_CPP_LITEC) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\Guetari\Opera\Thotlib\Dialogue\Lookup.c

!IF  "$(CFG)" == "LibThotEditor - Win32 Release"

DEP_CPP_LOOKU=\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\thotlib\include\view.h"\
	
NODEP_CPP_LOOKU=\
	".\..\thotlib\include\HTVMSUtils.h"\
	

"$(INTDIR)\Lookup.obj" : $(SOURCE) $(DEP_CPP_LOOKU) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "LibThotEditor - Win32 Debug"

DEP_CPP_LOOKU=\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\view.h"\
	

"$(INTDIR)\Lookup.obj" : $(SOURCE) $(DEP_CPP_LOOKU) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\Guetari\Opera\Thotlib\Dialogue\modiftype.c

!IF  "$(CFG)" == "LibThotEditor - Win32 Release"

DEP_CPP_MODIF=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\internals\h\constmenu.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\internals\h\appdialogue.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\include\dialog.h"\
	".\..\thotlib\internals\var\edit_tv.h"\
	".\..\thotlib\internals\var\select_tv.h"\
	".\..\thotlib\internals\var\appdialogue_tv.h"\
	".\..\thotlib\internals\f\appli_f.h"\
	".\..\thotlib\internals\f\tree_f.h"\
	".\..\thotlib\internals\f\attrmenu_f.h"\
	".\..\thotlib\internals\f\search_f.h"\
	".\..\thotlib\internals\f\structcreation_f.h"\
	".\..\thotlib\internals\f\creationmenu_f.h"\
	".\..\thotlib\internals\f\createabsbox_f.h"\
	".\..\thotlib\internals\f\views_f.h"\
	".\..\thotlib\internals\f\appdialogue_f.h"\
	".\..\thotlib\internals\f\actions_f.h"\
	".\..\thotlib\internals\f\viewcommands_f.h"\
	".\..\thotlib\internals\f\exceptions_f.h"\
	".\..\thotlib\internals\f\input_f.h"\
	".\..\thotlib\internals\f\keyboards_f.h"\
	".\..\thotlib\internals\f\picturemenu_f.h"\
	".\..\thotlib\internals\f\structmodif_f.h"\
	".\..\thotlib\internals\f\structselect_f.h"\
	".\..\thotlib\internals\f\structschema_f.h"\
	".\..\thotlib\include\sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\thotlib\internals\h\constint.h"\
	".\..\thotlib\internals\h\thotkey.h"\
	".\..\thotlib\internals\h\conststr.h"\
	".\..\thotlib\internals\h\constprs.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\frame.h"\
	".\..\thotlib\include\libmsg.h"\
	
NODEP_CPP_MODIF=\
	".\..\thotlib\include\HTVMSUtils.h"\
	

"$(INTDIR)\modiftype.obj" : $(SOURCE) $(DEP_CPP_MODIF) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "LibThotEditor - Win32 Debug"

DEP_CPP_MODIF=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\internals\h\constmenu.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\internals\h\appdialogue.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\include\dialog.h"\
	".\..\thotlib\internals\var\edit_tv.h"\
	".\..\thotlib\internals\var\select_tv.h"\
	".\..\thotlib\internals\var\appdialogue_tv.h"\
	".\..\thotlib\internals\f\appli_f.h"\
	".\..\thotlib\internals\f\tree_f.h"\
	".\..\thotlib\internals\f\attrmenu_f.h"\
	".\..\thotlib\internals\f\search_f.h"\
	".\..\thotlib\internals\f\structcreation_f.h"\
	".\..\thotlib\internals\f\creationmenu_f.h"\
	".\..\thotlib\internals\f\createabsbox_f.h"\
	".\..\thotlib\internals\f\views_f.h"\
	".\..\thotlib\internals\f\appdialogue_f.h"\
	".\..\thotlib\internals\f\actions_f.h"\
	".\..\thotlib\internals\f\viewcommands_f.h"\
	".\..\thotlib\internals\f\exceptions_f.h"\
	".\..\thotlib\internals\f\input_f.h"\
	".\..\thotlib\internals\f\keyboards_f.h"\
	".\..\thotlib\internals\f\picturemenu_f.h"\
	".\..\thotlib\internals\f\structmodif_f.h"\
	".\..\thotlib\internals\f\structselect_f.h"\
	".\..\thotlib\internals\f\structschema_f.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\frame.h"\
	".\..\thotlib\include\libmsg.h"\
	

"$(INTDIR)\modiftype.obj" : $(SOURCE) $(DEP_CPP_MODIF) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\Guetari\Opera\Thotlib\Dialogue\Opendoc.c

!IF  "$(CFG)" == "LibThotEditor - Win32 Release"

DEP_CPP_OPEND=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmenu.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\internals\h\appdialogue.h"\
	".\..\thotlib\include\libmsg.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\include\dialog.h"\
	".\..\thotlib\include\application.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\fileaccess.h"\
	".\..\thotlib\internals\h\thotdir.h"\
	".\..\thotlib\internals\var\edit_tv.h"\
	".\..\thotlib\internals\var\appdialogue_tv.h"\
	".\..\thotlib\internals\var\platform_tv.h"\
	".\..\thotlib\internals\f\browser_f.h"\
	".\..\thotlib\internals\f\config_f.h"\
	".\..\thotlib\internals\f\views_f.h"\
	".\..\thotlib\internals\f\appdialogue_f.h"\
	".\..\thotlib\internals\f\actions_f.h"\
	".\..\thotlib\internals\f\viewcommands_f.h"\
	".\..\thotlib\internals\f\platform_f.h"\
	".\..\thotlib\internals\f\opendoc_f.h"\
	".\..\thotlib\internals\f\structschema_f.h"\
	".\..\thotlib\internals\f\fileaccess_f.h"\
	".\..\thotlib\internals\f\docs_f.h"\
	".\..\thotlib\include\sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\thotlib\internals\h\constint.h"\
	".\..\thotlib\internals\h\thotkey.h"\
	".\..\thotlib\internals\h\conststr.h"\
	".\..\thotlib\internals\h\constprs.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\frame.h"\
	".\..\thotlib\include\registry.h"\
	
NODEP_CPP_OPEND=\
	".\..\thotlib\include\HTVMSUtils.h"\
	

"$(INTDIR)\Opendoc.obj" : $(SOURCE) $(DEP_CPP_OPEND) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "LibThotEditor - Win32 Debug"

DEP_CPP_OPEND=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmenu.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\internals\h\appdialogue.h"\
	".\..\thotlib\include\libmsg.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\include\dialog.h"\
	".\..\thotlib\include\application.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\fileaccess.h"\
	".\..\thotlib\internals\h\thotdir.h"\
	".\..\thotlib\internals\var\edit_tv.h"\
	".\..\thotlib\internals\var\appdialogue_tv.h"\
	".\..\thotlib\internals\var\platform_tv.h"\
	".\..\thotlib\internals\f\browser_f.h"\
	".\..\thotlib\internals\f\config_f.h"\
	".\..\thotlib\internals\f\views_f.h"\
	".\..\thotlib\internals\f\appdialogue_f.h"\
	".\..\thotlib\internals\f\actions_f.h"\
	".\..\thotlib\internals\f\viewcommands_f.h"\
	".\..\thotlib\internals\f\platform_f.h"\
	".\..\thotlib\internals\f\opendoc_f.h"\
	".\..\thotlib\internals\f\structschema_f.h"\
	".\..\thotlib\internals\f\fileaccess_f.h"\
	".\..\thotlib\internals\f\docs_f.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\frame.h"\
	".\..\thotlib\include\registry.h"\
	

"$(INTDIR)\Opendoc.obj" : $(SOURCE) $(DEP_CPP_OPEND) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\Guetari\Opera\Thotlib\Dialogue\Openview.c

!IF  "$(CFG)" == "LibThotEditor - Win32 Release"

DEP_CPP_OPENV=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmenu.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\internals\h\appdialogue.h"\
	".\..\thotlib\include\libmsg.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\include\dialog.h"\
	".\..\thotlib\internals\var\edit_tv.h"\
	".\..\thotlib\internals\var\appdialogue_tv.h"\
	".\..\thotlib\internals\var\frame_tv.h"\
	".\..\thotlib\internals\f\views_f.h"\
	".\..\thotlib\internals\f\appdialogue_f.h"\
	".\..\thotlib\internals\f\viewapi_f.h"\
	".\..\thotlib\include\sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\thotlib\internals\h\constint.h"\
	".\..\thotlib\internals\h\thotkey.h"\
	".\..\thotlib\internals\h\conststr.h"\
	".\..\thotlib\internals\h\constprs.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\frame.h"\
	
NODEP_CPP_OPENV=\
	".\..\thotlib\include\HTVMSUtils.h"\
	

"$(INTDIR)\Openview.obj" : $(SOURCE) $(DEP_CPP_OPENV) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "LibThotEditor - Win32 Debug"

DEP_CPP_OPENV=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmenu.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\internals\h\appdialogue.h"\
	".\..\thotlib\include\libmsg.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\include\dialog.h"\
	".\..\thotlib\internals\var\edit_tv.h"\
	".\..\thotlib\internals\var\appdialogue_tv.h"\
	".\..\thotlib\internals\var\frame_tv.h"\
	".\..\thotlib\internals\f\views_f.h"\
	".\..\thotlib\internals\f\appdialogue_f.h"\
	".\..\thotlib\internals\f\viewapi_f.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\frame.h"\
	

"$(INTDIR)\Openview.obj" : $(SOURCE) $(DEP_CPP_OPENV) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\Guetari\Opera\Thotlib\Dialogue\picturemenu.c

!IF  "$(CFG)" == "LibThotEditor - Win32 Release"

DEP_CPP_PICTUREM=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmenu.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\internals\h\appdialogue.h"\
	".\..\thotlib\include\libmsg.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\include\dialog.h"\
	".\..\thotlib\include\application.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\internals\h\picture.h"\
	".\..\thotlib\internals\f\browser_f.h"\
	".\..\thotlib\internals\f\fileaccess_f.h"\
	".\..\thotlib\internals\f\picture_f.h"\
	".\..\thotlib\internals\f\actions_f.h"\
	".\..\thotlib\internals\f\savedoc_f.h"\
	".\..\thotlib\include\sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\thotlib\internals\h\constint.h"\
	".\..\thotlib\internals\h\thotkey.h"\
	".\..\thotlib\internals\h\conststr.h"\
	".\..\thotlib\internals\h\constprs.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\frame.h"\
	".\..\thotlib\include\fileaccess.h"\
	".\..\thotlib\include\registry.h"\
	
NODEP_CPP_PICTUREM=\
	".\..\thotlib\include\HTVMSUtils.h"\
	

"$(INTDIR)\picturemenu.obj" : $(SOURCE) $(DEP_CPP_PICTUREM) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "LibThotEditor - Win32 Debug"

DEP_CPP_PICTUREM=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmenu.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\internals\h\appdialogue.h"\
	".\..\thotlib\include\libmsg.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\include\dialog.h"\
	".\..\thotlib\include\application.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\internals\h\picture.h"\
	".\..\thotlib\internals\f\browser_f.h"\
	".\..\thotlib\internals\f\fileaccess_f.h"\
	".\..\thotlib\internals\f\picture_f.h"\
	".\..\thotlib\internals\f\actions_f.h"\
	".\..\thotlib\internals\f\savedoc_f.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\frame.h"\
	".\..\thotlib\include\fileaccess.h"\
	".\..\thotlib\include\registry.h"\
	

"$(INTDIR)\picturemenu.obj" : $(SOURCE) $(DEP_CPP_PICTUREM) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\Guetari\Opera\Thotlib\Dialogue\presentmenu.c

!IF  "$(CFG)" == "LibThotEditor - Win32 Release"

DEP_CPP_PRESE=\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\include\libmsg.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\include\dialog.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\internals\h\appdialogue.h"\
	".\..\thotlib\internals\var\page_tv.h"\
	".\..\thotlib\internals\var\edit_tv.h"\
	".\..\thotlib\internals\var\select_tv.h"\
	".\..\thotlib\internals\var\appdialogue_tv.h"\
	".\..\thotlib\internals\f\tree_f.h"\
	".\..\thotlib\internals\f\attributes_f.h"\
	".\..\thotlib\internals\f\config_f.h"\
	".\..\thotlib\internals\f\structcreation_f.h"\
	".\..\thotlib\internals\f\createabsbox_f.h"\
	".\..\thotlib\internals\f\viewcommands_f.h"\
	".\..\thotlib\internals\f\exceptions_f.h"\
	".\..\thotlib\internals\f\font_f.h"\
	".\..\thotlib\internals\f\inites_f.h"\
	".\..\thotlib\internals\f\structmodif_f.h"\
	".\..\thotlib\internals\f\changeabsbox_f.h"\
	".\..\thotlib\internals\f\changepresent_f.h"\
	".\..\thotlib\internals\f\presrules_f.h"\
	".\..\thotlib\internals\f\boxselection_f.h"\
	".\..\thotlib\internals\f\structselect_f.h"\
	".\..\thotlib\internals\f\unstructchange_f.h"\
	".\..\thotlib\internals\f\actions_f.h"\
	".\..\thotlib\internals\f\units_f.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\thotlib\internals\h\constint.h"\
	".\..\thotlib\internals\h\thotkey.h"\
	".\..\thotlib\internals\h\conststr.h"\
	".\..\thotlib\internals\h\constprs.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\internals\h\frame.h"\
	".\..\thotlib\internals\h\constmenu.h"\
	
NODEP_CPP_PRESE=\
	".\..\thotlib\include\HTVMSUtils.h"\
	

"$(INTDIR)\presentmenu.obj" : $(SOURCE) $(DEP_CPP_PRESE) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "LibThotEditor - Win32 Debug"

DEP_CPP_PRESE=\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\include\libmsg.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\include\dialog.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\internals\h\appdialogue.h"\
	".\..\thotlib\internals\var\page_tv.h"\
	".\..\thotlib\internals\var\edit_tv.h"\
	".\..\thotlib\internals\var\select_tv.h"\
	".\..\thotlib\internals\var\appdialogue_tv.h"\
	".\..\thotlib\internals\f\tree_f.h"\
	".\..\thotlib\internals\f\attributes_f.h"\
	".\..\thotlib\internals\f\config_f.h"\
	".\..\thotlib\internals\f\structcreation_f.h"\
	".\..\thotlib\internals\f\createabsbox_f.h"\
	".\..\thotlib\internals\f\viewcommands_f.h"\
	".\..\thotlib\internals\f\exceptions_f.h"\
	".\..\thotlib\internals\f\font_f.h"\
	".\..\thotlib\internals\f\inites_f.h"\
	".\..\thotlib\internals\f\structmodif_f.h"\
	".\..\thotlib\internals\f\changeabsbox_f.h"\
	".\..\thotlib\internals\f\changepresent_f.h"\
	".\..\thotlib\internals\f\presrules_f.h"\
	".\..\thotlib\internals\f\boxselection_f.h"\
	".\..\thotlib\internals\f\structselect_f.h"\
	".\..\thotlib\internals\f\unstructchange_f.h"\
	".\..\thotlib\internals\f\actions_f.h"\
	".\..\thotlib\internals\f\units_f.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\internals\h\frame.h"\
	".\..\thotlib\internals\h\constmenu.h"\
	

"$(INTDIR)\presentmenu.obj" : $(SOURCE) $(DEP_CPP_PRESE) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\Guetari\Opera\Thotlib\Dialogue\printmenu.c

!IF  "$(CFG)" == "LibThotEditor - Win32 Release"

DEP_CPP_PRINT=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\include\libmsg.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\internals\h\constmenu.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\dialog.h"\
	".\..\thotlib\internals\h\appdialogue.h"\
	".\..\thotlib\internals\h\frame.h"\
	".\..\thotlib\include\fileaccess.h"\
	".\..\thotlib\include\application.h"\
	".\..\thotlib\include\print.h"\
	".\..\thotlib\internals\var\platform_tv.h"\
	".\..\thotlib\internals\var\edit_tv.h"\
	".\..\thotlib\internals\var\appdialogue_tv.h"\
	".\..\thotlib\internals\var\frame_tv.h"\
	".\..\thotlib\internals\f\appli_f.h"\
	".\..\thotlib\internals\f\actions_f.h"\
	".\..\thotlib\internals\f\applicationapi_f.h"\
	".\..\thotlib\internals\f\attrmenu_f.h"\
	".\..\thotlib\internals\f\tree_f.h"\
	".\..\thotlib\internals\f\browser_f.h"\
	".\..\thotlib\internals\f\search_f.h"\
	".\..\thotlib\internals\f\searchmenu_f.h"\
	".\..\thotlib\internals\f\textcommands_f.h"\
	".\..\thotlib\internals\f\config_f.h"\
	".\..\thotlib\internals\f\structcreation_f.h"\
	".\..\thotlib\internals\f\creationmenu_f.h"\
	".\..\thotlib\internals\f\dialogapi_f.h"\
	".\..\thotlib\internals\f\views_f.h"\
	".\..\thotlib\internals\f\viewapi_f.h"\
	".\..\thotlib\internals\f\thotmsg_f.h"\
	".\..\thotlib\internals\f\viewcommands_f.h"\
	".\..\thotlib\internals\f\exceptions_f.h"\
	".\..\thotlib\internals\f\structmodif_f.h"\
	".\..\thotlib\internals\f\presentmenu_f.h"\
	".\..\thotlib\internals\f\printmenu_f.h"\
	".\..\thotlib\internals\f\structselect_f.h"\
	".\..\thotlib\internals\f\selectmenu_f.h"\
	".\..\thotlib\internals\f\memory_f.h"\
	".\..\thotlib\internals\f\registry_f.h"\
	".\..\thotlib\internals\f\docs_f.h"\
	".\..\thotlib\internals\var\print_tv.h"\
	".\..\thotlib\include\sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\thotlib\internals\h\constint.h"\
	".\..\thotlib\internals\h\thotkey.h"\
	".\..\thotlib\internals\h\conststr.h"\
	".\..\thotlib\internals\h\constprs.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\include\registry.h"\
	
NODEP_CPP_PRINT=\
	".\..\thotlib\include\HTVMSUtils.h"\
	

"$(INTDIR)\printmenu.obj" : $(SOURCE) $(DEP_CPP_PRINT) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "LibThotEditor - Win32 Debug"

DEP_CPP_PRINT=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\include\libmsg.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\internals\h\constmenu.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\dialog.h"\
	".\..\thotlib\internals\h\appdialogue.h"\
	".\..\thotlib\internals\h\frame.h"\
	".\..\thotlib\include\fileaccess.h"\
	".\..\thotlib\include\application.h"\
	".\..\thotlib\include\print.h"\
	".\..\thotlib\internals\var\platform_tv.h"\
	".\..\thotlib\internals\var\edit_tv.h"\
	".\..\thotlib\internals\var\appdialogue_tv.h"\
	".\..\thotlib\internals\var\frame_tv.h"\
	".\..\thotlib\internals\f\appli_f.h"\
	".\..\thotlib\internals\f\actions_f.h"\
	".\..\thotlib\internals\f\applicationapi_f.h"\
	".\..\thotlib\internals\f\attrmenu_f.h"\
	".\..\thotlib\internals\f\tree_f.h"\
	".\..\thotlib\internals\f\browser_f.h"\
	".\..\thotlib\internals\f\search_f.h"\
	".\..\thotlib\internals\f\searchmenu_f.h"\
	".\..\thotlib\internals\f\textcommands_f.h"\
	".\..\thotlib\internals\f\config_f.h"\
	".\..\thotlib\internals\f\structcreation_f.h"\
	".\..\thotlib\internals\f\creationmenu_f.h"\
	".\..\thotlib\internals\f\dialogapi_f.h"\
	".\..\thotlib\internals\f\views_f.h"\
	".\..\thotlib\internals\f\viewapi_f.h"\
	".\..\thotlib\internals\f\thotmsg_f.h"\
	".\..\thotlib\internals\f\viewcommands_f.h"\
	".\..\thotlib\internals\f\exceptions_f.h"\
	".\..\thotlib\internals\f\structmodif_f.h"\
	".\..\thotlib\internals\f\presentmenu_f.h"\
	".\..\thotlib\internals\f\printmenu_f.h"\
	".\..\thotlib\internals\f\structselect_f.h"\
	".\..\thotlib\internals\f\selectmenu_f.h"\
	".\..\thotlib\internals\f\memory_f.h"\
	".\..\thotlib\internals\f\registry_f.h"\
	".\..\thotlib\internals\f\docs_f.h"\
	".\..\thotlib\internals\var\print_tv.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\include\registry.h"\
	

"$(INTDIR)\printmenu.obj" : $(SOURCE) $(DEP_CPP_PRINT) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\Guetari\Opera\Thotlib\Dialogue\Quit.c

!IF  "$(CFG)" == "LibThotEditor - Win32 Release"

DEP_CPP_QUIT_=\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmenu.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\internals\h\appdialogue.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\include\dialog.h"\
	".\..\thotlib\internals\f\appdialogue_f.h"\
	".\..\thotlib\internals\f\applicationapi_f.h"\
	".\..\thotlib\internals\f\callback_f.h"\
	".\..\thotlib\internals\f\closedoc_f.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\constint.h"\
	".\..\thotlib\internals\h\thotkey.h"\
	".\..\thotlib\internals\h\conststr.h"\
	".\..\thotlib\internals\h\constprs.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\internals\h\frame.h"\
	".\..\thotlib\include\libmsg.h"\
	
NODEP_CPP_QUIT_=\
	".\..\thotlib\include\HTVMSUtils.h"\
	

"$(INTDIR)\Quit.obj" : $(SOURCE) $(DEP_CPP_QUIT_) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "LibThotEditor - Win32 Debug"

DEP_CPP_QUIT_=\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmenu.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\internals\h\appdialogue.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\include\dialog.h"\
	".\..\thotlib\internals\f\appdialogue_f.h"\
	".\..\thotlib\internals\f\applicationapi_f.h"\
	".\..\thotlib\internals\f\callback_f.h"\
	".\..\thotlib\internals\f\closedoc_f.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\internals\h\frame.h"\
	".\..\thotlib\include\libmsg.h"\
	

"$(INTDIR)\Quit.obj" : $(SOURCE) $(DEP_CPP_QUIT_) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\Guetari\Opera\Thotlib\Dialogue\Savedoc.c

!IF  "$(CFG)" == "LibThotEditor - Win32 Release"

DEP_CPP_SAVED=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmenu.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\internals\h\appdialogue.h"\
	".\..\thotlib\include\libmsg.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\include\dialog.h"\
	".\..\thotlib\include\application.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\fileaccess.h"\
	".\..\thotlib\internals\h\thotdir.h"\
	".\..\thotlib\internals\var\edit_tv.h"\
	".\..\thotlib\internals\var\appdialogue_tv.h"\
	".\..\thotlib\internals\var\platform_tv.h"\
	".\..\thotlib\internals\var\boxes_tv.h"\
	".\..\thotlib\internals\var\frame_tv.h"\
	".\..\thotlib\internals\f\opendoc_f.h"\
	".\..\thotlib\internals\f\createdoc_f.h"\
	".\..\thotlib\internals\f\font_f.h"\
	".\..\thotlib\internals\f\docs_f.h"\
	".\..\thotlib\internals\f\applicationapi_f.h"\
	".\..\thotlib\internals\f\callback_f.h"\
	".\..\thotlib\internals\f\fileaccess_f.h"\
	".\..\thotlib\internals\f\translation_f.h"\
	".\..\thotlib\internals\f\browser_f.h"\
	".\..\thotlib\internals\f\config_f.h"\
	".\..\thotlib\internals\f\platform_f.h"\
	".\..\thotlib\internals\f\viewapi_f.h"\
	".\..\thotlib\internals\f\actions_f.h"\
	".\..\thotlib\include\sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\thotlib\internals\h\constint.h"\
	".\..\thotlib\internals\h\thotkey.h"\
	".\..\thotlib\internals\h\conststr.h"\
	".\..\thotlib\internals\h\constprs.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\frame.h"\
	".\..\thotlib\include\registry.h"\
	
NODEP_CPP_SAVED=\
	".\..\thotlib\include\HTVMSUtils.h"\
	

"$(INTDIR)\Savedoc.obj" : $(SOURCE) $(DEP_CPP_SAVED) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "LibThotEditor - Win32 Debug"

DEP_CPP_SAVED=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmenu.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\internals\h\appdialogue.h"\
	".\..\thotlib\include\libmsg.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\include\dialog.h"\
	".\..\thotlib\include\application.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\fileaccess.h"\
	".\..\thotlib\internals\h\thotdir.h"\
	".\..\thotlib\internals\var\edit_tv.h"\
	".\..\thotlib\internals\var\appdialogue_tv.h"\
	".\..\thotlib\internals\var\platform_tv.h"\
	".\..\thotlib\internals\var\boxes_tv.h"\
	".\..\thotlib\internals\var\frame_tv.h"\
	".\..\thotlib\internals\f\opendoc_f.h"\
	".\..\thotlib\internals\f\createdoc_f.h"\
	".\..\thotlib\internals\f\font_f.h"\
	".\..\thotlib\internals\f\docs_f.h"\
	".\..\thotlib\internals\f\applicationapi_f.h"\
	".\..\thotlib\internals\f\callback_f.h"\
	".\..\thotlib\internals\f\fileaccess_f.h"\
	".\..\thotlib\internals\f\translation_f.h"\
	".\..\thotlib\internals\f\browser_f.h"\
	".\..\thotlib\internals\f\config_f.h"\
	".\..\thotlib\internals\f\platform_f.h"\
	".\..\thotlib\internals\f\viewapi_f.h"\
	".\..\thotlib\internals\f\actions_f.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\frame.h"\
	".\..\thotlib\include\registry.h"\
	

"$(INTDIR)\Savedoc.obj" : $(SOURCE) $(DEP_CPP_SAVED) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\Guetari\Opera\Thotlib\Dialogue\searchmenu.c

!IF  "$(CFG)" == "LibThotEditor - Win32 Release"

DEP_CPP_SEARCHM=\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\include\dialog.h"\
	".\..\thotlib\include\libmsg.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\include\fileaccess.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\internals\h\appdialogue.h"\
	".\..\thotlib\internals\var\platform_tv.h"\
	".\..\thotlib\internals\var\edit_tv.h"\
	".\..\thotlib\internals\var\appdialogue_tv.h"\
	".\..\thotlib\internals\f\tree_f.h"\
	".\..\thotlib\internals\f\structcreation_f.h"\
	".\..\thotlib\internals\f\references_f.h"\
	".\..\thotlib\internals\f\structmodif_f.h"\
	".\..\thotlib\internals\f\viewcommands_f.h"\
	".\..\thotlib\internals\f\absboxes_f.h"\
	".\..\thotlib\internals\f\actions_f.h"\
	".\..\thotlib\internals\f\changeabsbox_f.h"\
	".\..\thotlib\internals\f\schemas_f.h"\
	".\..\thotlib\internals\f\createabsbox_f.h"\
	".\..\thotlib\internals\f\search_f.h"\
	".\..\thotlib\internals\f\exceptions_f.h"\
	".\..\thotlib\internals\f\word_f.h"\
	".\..\thotlib\internals\f\appli_f.h"\
	".\..\thotlib\internals\f\searchmenu_f.h"\
	".\..\thotlib\internals\f\structschema_f.h"\
	".\..\thotlib\internals\f\fileaccess_f.h"\
	".\..\thotlib\internals\f\memory_f.h"\
	".\..\thotlib\internals\f\regexp_f.h"\
	".\..\thotlib\internals\f\views_f.h"\
	".\..\thotlib\internals\f\structselect_f.h"\
	".\..\thotlib\internals\f\content_f.h"\
	".\..\thotlib\internals\f\searchref_f.h"\
	".\..\thotlib\internals\f\docs_f.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\thotlib\internals\h\constint.h"\
	".\..\thotlib\internals\h\thotkey.h"\
	".\..\thotlib\internals\h\conststr.h"\
	".\..\thotlib\internals\h\constprs.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\internals\h\frame.h"\
	".\..\thotlib\internals\h\constmenu.h"\
	
NODEP_CPP_SEARCHM=\
	".\..\thotlib\include\HTVMSUtils.h"\
	

"$(INTDIR)\searchmenu.obj" : $(SOURCE) $(DEP_CPP_SEARCHM) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "LibThotEditor - Win32 Debug"

DEP_CPP_SEARCHM=\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\include\dialog.h"\
	".\..\thotlib\include\libmsg.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\include\fileaccess.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\internals\h\appdialogue.h"\
	".\..\thotlib\internals\var\platform_tv.h"\
	".\..\thotlib\internals\var\edit_tv.h"\
	".\..\thotlib\internals\var\appdialogue_tv.h"\
	".\..\thotlib\internals\f\tree_f.h"\
	".\..\thotlib\internals\f\structcreation_f.h"\
	".\..\thotlib\internals\f\references_f.h"\
	".\..\thotlib\internals\f\structmodif_f.h"\
	".\..\thotlib\internals\f\viewcommands_f.h"\
	".\..\thotlib\internals\f\absboxes_f.h"\
	".\..\thotlib\internals\f\actions_f.h"\
	".\..\thotlib\internals\f\changeabsbox_f.h"\
	".\..\thotlib\internals\f\schemas_f.h"\
	".\..\thotlib\internals\f\createabsbox_f.h"\
	".\..\thotlib\internals\f\search_f.h"\
	".\..\thotlib\internals\f\exceptions_f.h"\
	".\..\thotlib\internals\f\word_f.h"\
	".\..\thotlib\internals\f\appli_f.h"\
	".\..\thotlib\internals\f\searchmenu_f.h"\
	".\..\thotlib\internals\f\structschema_f.h"\
	".\..\thotlib\internals\f\fileaccess_f.h"\
	".\..\thotlib\internals\f\memory_f.h"\
	".\..\thotlib\internals\f\regexp_f.h"\
	".\..\thotlib\internals\f\views_f.h"\
	".\..\thotlib\internals\f\structselect_f.h"\
	".\..\thotlib\internals\f\content_f.h"\
	".\..\thotlib\internals\f\searchref_f.h"\
	".\..\thotlib\internals\f\docs_f.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\internals\h\frame.h"\
	".\..\thotlib\internals\h\constmenu.h"\
	

"$(INTDIR)\searchmenu.obj" : $(SOURCE) $(DEP_CPP_SEARCHM) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\Guetari\Opera\Thotlib\Dialogue\searchmenustr.c

!IF  "$(CFG)" == "LibThotEditor - Win32 Release"

DEP_CPP_SEARCHME=\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\include\dialog.h"\
	".\..\thotlib\include\libmsg.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\include\fileaccess.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\internals\h\appdialogue.h"\
	".\..\thotlib\internals\var\platform_tv.h"\
	".\..\thotlib\internals\var\edit_tv.h"\
	".\..\thotlib\internals\var\appdialogue_tv.h"\
	".\..\thotlib\internals\f\tree_f.h"\
	".\..\thotlib\internals\f\structcreation_f.h"\
	".\..\thotlib\internals\f\references_f.h"\
	".\..\thotlib\internals\f\structmodif_f.h"\
	".\..\thotlib\internals\f\viewcommands_f.h"\
	".\..\thotlib\internals\f\absboxes_f.h"\
	".\..\thotlib\internals\f\changeabsbox_f.h"\
	".\..\thotlib\internals\f\schemas_f.h"\
	".\..\thotlib\internals\f\createabsbox_f.h"\
	".\..\thotlib\internals\f\search_f.h"\
	".\..\thotlib\internals\f\exceptions_f.h"\
	".\..\thotlib\internals\f\actions_f.h"\
	".\..\thotlib\internals\f\word_f.h"\
	".\..\thotlib\internals\f\appli_f.h"\
	".\..\thotlib\internals\f\searchmenu_f.h"\
	".\..\thotlib\internals\f\structschema_f.h"\
	".\..\thotlib\internals\f\fileaccess_f.h"\
	".\..\thotlib\internals\f\memory_f.h"\
	".\..\thotlib\internals\f\regexp_f.h"\
	".\..\thotlib\internals\f\views_f.h"\
	".\..\thotlib\internals\f\structselect_f.h"\
	".\..\thotlib\internals\f\content_f.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\thotlib\internals\h\constint.h"\
	".\..\thotlib\internals\h\thotkey.h"\
	".\..\thotlib\internals\h\conststr.h"\
	".\..\thotlib\internals\h\constprs.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\internals\h\frame.h"\
	".\..\thotlib\internals\h\constmenu.h"\
	
NODEP_CPP_SEARCHME=\
	".\..\thotlib\include\HTVMSUtils.h"\
	

"$(INTDIR)\searchmenustr.obj" : $(SOURCE) $(DEP_CPP_SEARCHME) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "LibThotEditor - Win32 Debug"

DEP_CPP_SEARCHME=\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\include\dialog.h"\
	".\..\thotlib\include\libmsg.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\include\fileaccess.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\internals\h\appdialogue.h"\
	".\..\thotlib\internals\var\platform_tv.h"\
	".\..\thotlib\internals\var\edit_tv.h"\
	".\..\thotlib\internals\var\appdialogue_tv.h"\
	".\..\thotlib\internals\f\tree_f.h"\
	".\..\thotlib\internals\f\structcreation_f.h"\
	".\..\thotlib\internals\f\references_f.h"\
	".\..\thotlib\internals\f\structmodif_f.h"\
	".\..\thotlib\internals\f\viewcommands_f.h"\
	".\..\thotlib\internals\f\absboxes_f.h"\
	".\..\thotlib\internals\f\changeabsbox_f.h"\
	".\..\thotlib\internals\f\schemas_f.h"\
	".\..\thotlib\internals\f\createabsbox_f.h"\
	".\..\thotlib\internals\f\search_f.h"\
	".\..\thotlib\internals\f\exceptions_f.h"\
	".\..\thotlib\internals\f\actions_f.h"\
	".\..\thotlib\internals\f\word_f.h"\
	".\..\thotlib\internals\f\appli_f.h"\
	".\..\thotlib\internals\f\searchmenu_f.h"\
	".\..\thotlib\internals\f\structschema_f.h"\
	".\..\thotlib\internals\f\fileaccess_f.h"\
	".\..\thotlib\internals\f\memory_f.h"\
	".\..\thotlib\internals\f\regexp_f.h"\
	".\..\thotlib\internals\f\views_f.h"\
	".\..\thotlib\internals\f\structselect_f.h"\
	".\..\thotlib\internals\f\content_f.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\internals\h\frame.h"\
	".\..\thotlib\internals\h\constmenu.h"\
	

"$(INTDIR)\searchmenustr.obj" : $(SOURCE) $(DEP_CPP_SEARCHME) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\Guetari\Opera\Thotlib\Dialogue\visibility.c

!IF  "$(CFG)" == "LibThotEditor - Win32 Release"

DEP_CPP_VISIB=\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmenu.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\internals\h\appdialogue.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\include\dialog.h"\
	".\..\thotlib\internals\var\frame_tv.h"\
	".\..\thotlib\internals\var\appdialogue_tv.h"\
	".\..\thotlib\internals\f\appdialogue_f.h"\
	".\..\thotlib\internals\f\actions_f.h"\
	".\..\thotlib\internals\f\boxparams_f.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\thotlib\internals\h\constint.h"\
	".\..\thotlib\internals\h\thotkey.h"\
	".\..\thotlib\internals\h\conststr.h"\
	".\..\thotlib\internals\h\constprs.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\frame.h"\
	".\..\thotlib\include\libmsg.h"\
	
NODEP_CPP_VISIB=\
	".\..\thotlib\include\HTVMSUtils.h"\
	

"$(INTDIR)\visibility.obj" : $(SOURCE) $(DEP_CPP_VISIB) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "LibThotEditor - Win32 Debug"

DEP_CPP_VISIB=\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmenu.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\internals\h\appdialogue.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\include\dialog.h"\
	".\..\thotlib\internals\var\frame_tv.h"\
	".\..\thotlib\internals\var\appdialogue_tv.h"\
	".\..\thotlib\internals\f\appdialogue_f.h"\
	".\..\thotlib\internals\f\actions_f.h"\
	".\..\thotlib\internals\f\boxparams_f.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\frame.h"\
	".\..\thotlib\include\libmsg.h"\
	

"$(INTDIR)\visibility.obj" : $(SOURCE) $(DEP_CPP_VISIB) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\Guetari\Opera\Thotlib\Dialogue\Zoom.c

!IF  "$(CFG)" == "LibThotEditor - Win32 Release"

DEP_CPP_ZOOM_=\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\internals\h\constmenu.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\internals\h\appdialogue.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\include\dialog.h"\
	".\..\thotlib\internals\var\frame_tv.h"\
	".\..\thotlib\internals\var\appdialogue_tv.h"\
	".\..\thotlib\internals\f\appdialogue_f.h"\
	".\..\thotlib\internals\f\actions_f.h"\
	".\..\thotlib\internals\f\boxparams_f.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\thotlib\internals\h\constint.h"\
	".\..\thotlib\internals\h\thotkey.h"\
	".\..\thotlib\internals\h\conststr.h"\
	".\..\thotlib\internals\h\constprs.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\frame.h"\
	".\..\thotlib\include\libmsg.h"\
	
NODEP_CPP_ZOOM_=\
	".\..\thotlib\include\HTVMSUtils.h"\
	

"$(INTDIR)\Zoom.obj" : $(SOURCE) $(DEP_CPP_ZOOM_) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "LibThotEditor - Win32 Debug"

DEP_CPP_ZOOM_=\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\internals\h\constmenu.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\internals\h\appdialogue.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\include\dialog.h"\
	".\..\thotlib\internals\var\frame_tv.h"\
	".\..\thotlib\internals\var\appdialogue_tv.h"\
	".\..\thotlib\internals\f\appdialogue_f.h"\
	".\..\thotlib\internals\f\actions_f.h"\
	".\..\thotlib\internals\f\boxparams_f.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\frame.h"\
	".\..\thotlib\include\libmsg.h"\
	

"$(INTDIR)\Zoom.obj" : $(SOURCE) $(DEP_CPP_ZOOM_) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\Guetari\Opera\Thotlib\Editing\applicationapi.c

!IF  "$(CFG)" == "LibThotEditor - Win32 Release"

DEP_CPP_APPLIC=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmenu.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\include\libmsg.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\application.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\dialog.h"\
	".\..\thotlib\internals\h\thotpattern.h"\
	".\..\thotlib\internals\h\appdialogue.h"\
	".\..\thotlib\internals\h\dictionary.h"\
	".\..\thotlib\internals\var\platform_tv.h"\
	".\..\thotlib\internals\var\appevents_tv.h"\
	".\..\thotlib\internals\var\units_tv.h"\
	".\..\thotlib\internals\var\print_tv.h"\
	".\..\thotlib\internals\var\edit_tv.h"\
	".\..\thotlib\internals\h\thotcolor.h"\
	".\..\thotlib\internals\var\thotcolor_tv.h"\
	".\..\thotlib\internals\var\thotpalette_tv.h"\
	".\..\thotlib\internals\var\frame_tv.h"\
	".\..\thotlib\internals\var\appdialogue_tv.h"\
	".\..\thotlib\internals\f\checkaccess_f.h"\
	".\..\thotlib\internals\f\config_f.h"\
	".\..\thotlib\internals\f\dialogapi_f.h"\
	".\..\thotlib\internals\f\input_f.h"\
	".\..\thotlib\internals\f\language_f.h"\
	".\..\thotlib\internals\f\memory_f.h"\
	".\..\thotlib\internals\f\references_f.h"\
	".\..\thotlib\internals\f\schemas_f.h"\
	".\..\thotlib\internals\f\schtrad_f.h"\
	".\..\thotlib\internals\f\searchmenu_f.h"\
	".\..\thotlib\internals\f\structschema_f.h"\
	".\..\thotlib\internals\f\structselect_f.h"\
	".\..\thotlib\internals\f\tree_f.h"\
	".\..\thotlib\include\sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\thotlib\internals\h\constint.h"\
	".\..\thotlib\internals\h\thotkey.h"\
	".\..\thotlib\internals\h\conststr.h"\
	".\..\thotlib\internals\h\constprs.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\fileaccess.h"\
	".\..\thotlib\include\registry.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\internals\h\frame.h"\
	
NODEP_CPP_APPLIC=\
	".\..\thotlib\include\HTVMSUtils.h"\
	

"$(INTDIR)\applicationapi.obj" : $(SOURCE) $(DEP_CPP_APPLIC) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "LibThotEditor - Win32 Debug"

DEP_CPP_APPLIC=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmenu.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\include\libmsg.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\application.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\dialog.h"\
	".\..\thotlib\internals\h\thotpattern.h"\
	".\..\thotlib\internals\h\appdialogue.h"\
	".\..\thotlib\internals\h\dictionary.h"\
	".\..\thotlib\internals\var\platform_tv.h"\
	".\..\thotlib\internals\var\appevents_tv.h"\
	".\..\thotlib\internals\var\units_tv.h"\
	".\..\thotlib\internals\var\print_tv.h"\
	".\..\thotlib\internals\var\edit_tv.h"\
	".\..\thotlib\internals\h\thotcolor.h"\
	".\..\thotlib\internals\var\thotcolor_tv.h"\
	".\..\thotlib\internals\var\thotpalette_tv.h"\
	".\..\thotlib\internals\var\frame_tv.h"\
	".\..\thotlib\internals\var\appdialogue_tv.h"\
	".\..\thotlib\internals\f\checkaccess_f.h"\
	".\..\thotlib\internals\f\config_f.h"\
	".\..\thotlib\internals\f\dialogapi_f.h"\
	".\..\thotlib\internals\f\input_f.h"\
	".\..\thotlib\internals\f\language_f.h"\
	".\..\thotlib\internals\f\memory_f.h"\
	".\..\thotlib\internals\f\references_f.h"\
	".\..\thotlib\internals\f\schemas_f.h"\
	".\..\thotlib\internals\f\schtrad_f.h"\
	".\..\thotlib\internals\f\searchmenu_f.h"\
	".\..\thotlib\internals\f\structschema_f.h"\
	".\..\thotlib\internals\f\structselect_f.h"\
	".\..\thotlib\internals\f\tree_f.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\fileaccess.h"\
	".\..\thotlib\include\registry.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\internals\h\frame.h"\
	

"$(INTDIR)\applicationapi.obj" : $(SOURCE) $(DEP_CPP_APPLIC) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\Guetari\Opera\Thotlib\Editing\checkermenu.c

!IF  "$(CFG)" == "LibThotEditor - Win32 Release"

DEP_CPP_CHECKE=\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\corrmsg.h"\
	".\..\thotlib\include\libmsg.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\constmenu.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\internals\h\constcorr.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\dialog.h"\
	".\..\thotlib\internals\h\corrmenu.h"\
	".\..\thotlib\internals\h\appdialogue.h"\
	".\..\thotlib\internals\var\edit_tv.h"\
	".\..\thotlib\internals\var\appdialogue_tv.h"\
	".\..\thotlib\internals\var\spell_tv.h"\
	".\..\thotlib\internals\f\spellchecker_f.h"\
	".\..\thotlib\internals\f\dictionary_f.h"\
	".\..\thotlib\internals\f\word_f.h"\
	".\..\thotlib\internals\f\appli_f.h"\
	".\..\thotlib\internals\f\actions_f.h"\
	".\..\thotlib\internals\f\memory_f.h"\
	".\..\thotlib\internals\f\views_f.h"\
	".\..\thotlib\internals\f\savedoc_f.h"\
	".\..\thotlib\internals\f\structselect_f.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\thotlib\internals\h\constint.h"\
	".\..\thotlib\internals\h\thotkey.h"\
	".\..\thotlib\internals\h\conststr.h"\
	".\..\thotlib\internals\h\constprs.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\internals\h\frame.h"\
	
NODEP_CPP_CHECKE=\
	".\..\thotlib\include\HTVMSUtils.h"\
	

"$(INTDIR)\checkermenu.obj" : $(SOURCE) $(DEP_CPP_CHECKE) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "LibThotEditor - Win32 Debug"

DEP_CPP_CHECKE=\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\corrmsg.h"\
	".\..\thotlib\include\libmsg.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\constmenu.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\internals\h\constcorr.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\dialog.h"\
	".\..\thotlib\internals\h\corrmenu.h"\
	".\..\thotlib\internals\h\appdialogue.h"\
	".\..\thotlib\internals\var\edit_tv.h"\
	".\..\thotlib\internals\var\appdialogue_tv.h"\
	".\..\thotlib\internals\var\spell_tv.h"\
	".\..\thotlib\internals\f\spellchecker_f.h"\
	".\..\thotlib\internals\f\dictionary_f.h"\
	".\..\thotlib\internals\f\word_f.h"\
	".\..\thotlib\internals\f\appli_f.h"\
	".\..\thotlib\internals\f\actions_f.h"\
	".\..\thotlib\internals\f\memory_f.h"\
	".\..\thotlib\internals\f\views_f.h"\
	".\..\thotlib\internals\f\savedoc_f.h"\
	".\..\thotlib\internals\f\structselect_f.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\internals\h\frame.h"\
	

"$(INTDIR)\checkermenu.obj" : $(SOURCE) $(DEP_CPP_CHECKE) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\Guetari\Opera\Thotlib\Editing\editcommands.c

!IF  "$(CFG)" == "LibThotEditor - Win32 Release"

DEP_CPP_EDITC=\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\include\libmsg.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\internals\h\picture.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\internals\h\appdialogue.h"\
	".\..\thotlib\internals\var\boxes_tv.h"\
	".\..\thotlib\internals\var\frame_tv.h"\
	".\..\thotlib\internals\var\edit_tv.h"\
	".\..\thotlib\internals\var\select_tv.h"\
	".\..\thotlib\internals\var\appdialogue_tv.h"\
	".\..\thotlib\internals\f\abspictures_f.h"\
	".\..\thotlib\internals\f\appdialogue_f.h"\
	".\..\thotlib\internals\f\actions_f.h"\
	".\..\thotlib\internals\f\appli_f.h"\
	".\..\thotlib\internals\f\boxmoves_f.h"\
	".\..\thotlib\internals\f\boxlocate_f.h"\
	".\..\thotlib\internals\f\boxparams_f.h"\
	".\..\thotlib\internals\f\boxselection_f.h"\
	".\..\thotlib\internals\f\buildboxes_f.h"\
	".\..\thotlib\internals\f\buildlines_f.h"\
	".\..\thotlib\internals\f\content_f.h"\
	".\..\thotlib\internals\f\editcommands_f.h"\
	".\..\thotlib\internals\f\callback_f.h"\
	".\..\thotlib\internals\f\units_f.h"\
	".\..\thotlib\internals\f\font_f.h"\
	".\..\thotlib\internals\f\geom_f.h"\
	".\..\thotlib\internals\f\picture_f.h"\
	".\..\thotlib\internals\f\memory_f.h"\
	".\..\thotlib\internals\f\structmodif_f.h"\
	".\..\thotlib\internals\f\structcommands_f.h"\
	".\..\thotlib\internals\f\structselect_f.h"\
	".\..\thotlib\internals\f\scroll_f.h"\
	".\..\thotlib\internals\f\structcreation_f.h"\
	".\..\thotlib\internals\f\textcommands_f.h"\
	".\..\thotlib\internals\f\tree_f.h"\
	".\..\thotlib\internals\f\unstructchange_f.h"\
	".\..\thotlib\internals\f\views_f.h"\
	".\..\thotlib\internals\f\windowdisplay_f.h"\
	".\..\thotlib\internals\f\applicationapi_f.h"\
	".\..\thotlib\internals\f\viewapi_f.h"\
	".\..\thotlib\internals\f\frame_f.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\thotlib\internals\h\constint.h"\
	".\..\thotlib\internals\h\thotkey.h"\
	".\..\thotlib\internals\h\conststr.h"\
	".\..\thotlib\internals\h\constprs.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\frame.h"\
	".\..\thotlib\internals\h\constmenu.h"\
	
NODEP_CPP_EDITC=\
	".\..\thotlib\include\HTVMSUtils.h"\
	

"$(INTDIR)\editcommands.obj" : $(SOURCE) $(DEP_CPP_EDITC) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "LibThotEditor - Win32 Debug"

DEP_CPP_EDITC=\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\include\libmsg.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\internals\h\picture.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\internals\h\appdialogue.h"\
	".\..\thotlib\internals\var\boxes_tv.h"\
	".\..\thotlib\internals\var\frame_tv.h"\
	".\..\thotlib\internals\var\edit_tv.h"\
	".\..\thotlib\internals\var\select_tv.h"\
	".\..\thotlib\internals\var\appdialogue_tv.h"\
	".\..\thotlib\internals\f\abspictures_f.h"\
	".\..\thotlib\internals\f\appdialogue_f.h"\
	".\..\thotlib\internals\f\actions_f.h"\
	".\..\thotlib\internals\f\appli_f.h"\
	".\..\thotlib\internals\f\boxmoves_f.h"\
	".\..\thotlib\internals\f\boxlocate_f.h"\
	".\..\thotlib\internals\f\boxparams_f.h"\
	".\..\thotlib\internals\f\boxselection_f.h"\
	".\..\thotlib\internals\f\buildboxes_f.h"\
	".\..\thotlib\internals\f\buildlines_f.h"\
	".\..\thotlib\internals\f\content_f.h"\
	".\..\thotlib\internals\f\editcommands_f.h"\
	".\..\thotlib\internals\f\callback_f.h"\
	".\..\thotlib\internals\f\units_f.h"\
	".\..\thotlib\internals\f\font_f.h"\
	".\..\thotlib\internals\f\geom_f.h"\
	".\..\thotlib\internals\f\picture_f.h"\
	".\..\thotlib\internals\f\memory_f.h"\
	".\..\thotlib\internals\f\structmodif_f.h"\
	".\..\thotlib\internals\f\structcommands_f.h"\
	".\..\thotlib\internals\f\structselect_f.h"\
	".\..\thotlib\internals\f\scroll_f.h"\
	".\..\thotlib\internals\f\structcreation_f.h"\
	".\..\thotlib\internals\f\textcommands_f.h"\
	".\..\thotlib\internals\f\tree_f.h"\
	".\..\thotlib\internals\f\unstructchange_f.h"\
	".\..\thotlib\internals\f\views_f.h"\
	".\..\thotlib\internals\f\windowdisplay_f.h"\
	".\..\thotlib\internals\f\applicationapi_f.h"\
	".\..\thotlib\internals\f\viewapi_f.h"\
	".\..\thotlib\internals\f\frame_f.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\frame.h"\
	".\..\thotlib\internals\h\constmenu.h"\
	

"$(INTDIR)\editcommands.obj" : $(SOURCE) $(DEP_CPP_EDITC) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\Guetari\Opera\Thotlib\Editing\Scroll.c

!IF  "$(CFG)" == "LibThotEditor - Win32 Release"

DEP_CPP_SCROL=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\internals\var\boxes_tv.h"\
	".\..\thotlib\internals\f\absboxes_f.h"\
	".\..\thotlib\internals\f\appli_f.h"\
	".\..\thotlib\internals\f\boxselection_f.h"\
	".\..\thotlib\internals\f\frame_f.h"\
	".\..\thotlib\internals\f\structselect_f.h"\
	".\..\thotlib\internals\f\textcommands_f.h"\
	".\..\thotlib\internals\f\windowdisplay_f.h"\
	".\..\thotlib\internals\f\applicationapi_f.h"\
	".\..\thotlib\include\sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\thotlib\internals\h\constint.h"\
	".\..\thotlib\internals\h\thotkey.h"\
	".\..\thotlib\internals\h\conststr.h"\
	".\..\thotlib\internals\h\constprs.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	
NODEP_CPP_SCROL=\
	".\..\thotlib\include\HTVMSUtils.h"\
	

"$(INTDIR)\Scroll.obj" : $(SOURCE) $(DEP_CPP_SCROL) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "LibThotEditor - Win32 Debug"

DEP_CPP_SCROL=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\internals\var\boxes_tv.h"\
	".\..\thotlib\internals\f\absboxes_f.h"\
	".\..\thotlib\internals\f\appli_f.h"\
	".\..\thotlib\internals\f\boxselection_f.h"\
	".\..\thotlib\internals\f\frame_f.h"\
	".\..\thotlib\internals\f\structselect_f.h"\
	".\..\thotlib\internals\f\textcommands_f.h"\
	".\..\thotlib\internals\f\windowdisplay_f.h"\
	".\..\thotlib\internals\f\applicationapi_f.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	

"$(INTDIR)\Scroll.obj" : $(SOURCE) $(DEP_CPP_SCROL) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\Guetari\Opera\Thotlib\Editing\selectionapi.c

!IF  "$(CFG)" == "LibThotEditor - Win32 Release"

DEP_CPP_SELEC=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\include\application.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\var\edit_tv.h"\
	".\..\thotlib\internals\var\select_tv.h"\
	".\..\thotlib\internals\f\applicationapi_f.h"\
	".\..\thotlib\internals\f\structselect_f.h"\
	".\..\thotlib\internals\f\thotmsg_f.h"\
	".\..\thotlib\internals\f\viewapi_f.h"\
	".\..\thotlib\include\sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\thotlib\internals\h\constint.h"\
	".\..\thotlib\internals\h\thotkey.h"\
	".\..\thotlib\internals\h\conststr.h"\
	".\..\thotlib\internals\h\constprs.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\include\fileaccess.h"\
	".\..\thotlib\include\registry.h"\
	
NODEP_CPP_SELEC=\
	".\..\thotlib\include\HTVMSUtils.h"\
	

"$(INTDIR)\selectionapi.obj" : $(SOURCE) $(DEP_CPP_SELEC) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "LibThotEditor - Win32 Debug"

DEP_CPP_SELEC=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\include\application.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\var\edit_tv.h"\
	".\..\thotlib\internals\var\select_tv.h"\
	".\..\thotlib\internals\f\applicationapi_f.h"\
	".\..\thotlib\internals\f\structselect_f.h"\
	".\..\thotlib\internals\f\thotmsg_f.h"\
	".\..\thotlib\internals\f\viewapi_f.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\include\fileaccess.h"\
	".\..\thotlib\include\registry.h"\
	

"$(INTDIR)\selectionapi.obj" : $(SOURCE) $(DEP_CPP_SELEC) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\Guetari\Opera\Thotlib\Editing\spellchecker.c

!IF  "$(CFG)" == "LibThotEditor - Win32 Release"

DEP_CPP_SPELL=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\include\libmsg.h"\
	".\..\thotlib\internals\h\corrmsg.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\internals\h\constmot.h"\
	".\..\thotlib\internals\h\constcorr.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\include\fileaccess.h"\
	".\..\thotlib\internals\h\dictionary.h"\
	".\..\thotlib\internals\var\spell_tv.h"\
	".\..\thotlib\internals\var\word_tv.h"\
	".\..\thotlib\internals\f\applicationapi_f.h"\
	".\..\thotlib\internals\f\dictionary_f.h"\
	".\..\thotlib\internals\f\exceptions_f.h"\
	".\..\thotlib\internals\f\fileaccess_f.h"\
	".\..\thotlib\internals\f\hyphen_f.h"\
	".\..\thotlib\internals\f\registry_f.h"\
	".\..\thotlib\internals\f\search_f.h"\
	".\..\thotlib\internals\f\spellchecker_f.h"\
	".\..\thotlib\internals\f\structselect_f.h"\
	".\..\thotlib\internals\f\word_f.h"\
	".\..\thotlib\include\sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\thotlib\internals\h\constint.h"\
	".\..\thotlib\internals\h\thotkey.h"\
	".\..\thotlib\internals\h\conststr.h"\
	".\..\thotlib\internals\h\constprs.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	
NODEP_CPP_SPELL=\
	".\..\thotlib\include\HTVMSUtils.h"\
	

"$(INTDIR)\spellchecker.obj" : $(SOURCE) $(DEP_CPP_SPELL) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "LibThotEditor - Win32 Debug"

DEP_CPP_SPELL=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\include\libmsg.h"\
	".\..\thotlib\internals\h\corrmsg.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\internals\h\constmot.h"\
	".\..\thotlib\internals\h\constcorr.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\include\fileaccess.h"\
	".\..\thotlib\internals\h\dictionary.h"\
	".\..\thotlib\internals\var\spell_tv.h"\
	".\..\thotlib\internals\var\word_tv.h"\
	".\..\thotlib\internals\f\applicationapi_f.h"\
	".\..\thotlib\internals\f\dictionary_f.h"\
	".\..\thotlib\internals\f\exceptions_f.h"\
	".\..\thotlib\internals\f\fileaccess_f.h"\
	".\..\thotlib\internals\f\hyphen_f.h"\
	".\..\thotlib\internals\f\registry_f.h"\
	".\..\thotlib\internals\f\search_f.h"\
	".\..\thotlib\internals\f\spellchecker_f.h"\
	".\..\thotlib\internals\f\structselect_f.h"\
	".\..\thotlib\internals\f\word_f.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	

"$(INTDIR)\spellchecker.obj" : $(SOURCE) $(DEP_CPP_SPELL) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\Guetari\Opera\Thotlib\Editing\structchange.c

!IF  "$(CFG)" == "LibThotEditor - Win32 Release"

DEP_CPP_STRUCTC=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\constmenu.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\internals\h\modif.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\fileaccess.h"\
	".\..\thotlib\include\libmsg.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\internals\h\appdialogue.h"\
	".\..\thotlib\include\dialog.h"\
	".\..\thotlib\include\content.h"\
	".\..\thotlib\internals\var\creation_tv.h"\
	".\..\thotlib\internals\var\modif_tv.h"\
	".\..\thotlib\internals\var\select_tv.h"\
	".\..\thotlib\internals\var\edit_tv.h"\
	".\..\thotlib\internals\var\appdialogue_tv.h"\
	".\..\thotlib\internals\f\appli_f.h"\
	".\..\thotlib\internals\f\actions_f.h"\
	".\..\thotlib\internals\f\applicationapi_f.h"\
	".\..\thotlib\internals\f\tree_f.h"\
	".\..\thotlib\internals\f\attrpresent_f.h"\
	".\..\thotlib\internals\f\attributes_f.h"\
	".\..\thotlib\internals\f\search_f.h"\
	".\..\thotlib\internals\f\textcommands_f.h"\
	".\..\thotlib\internals\f\editcommands_f.h"\
	".\..\thotlib\internals\f\contentapi_f.h"\
	".\..\thotlib\internals\f\structcreation_f.h"\
	".\..\thotlib\internals\f\createabsbox_f.h"\
	".\..\thotlib\internals\f\views_f.h"\
	".\..\thotlib\internals\f\callback_f.h"\
	".\..\thotlib\internals\f\exceptions_f.h"\
	".\..\thotlib\internals\f\absboxes_f.h"\
	".\..\thotlib\internals\f\buildboxes_f.h"\
	".\..\thotlib\internals\f\memory_f.h"\
	".\..\thotlib\internals\f\structmodif_f.h"\
	".\..\thotlib\internals\f\changeabsbox_f.h"\
	".\..\thotlib\internals\f\changepresent_f.h"\
	".\..\thotlib\internals\f\presrules_f.h"\
	".\..\thotlib\internals\f\references_f.h"\
	".\..\thotlib\internals\f\externalref_f.h"\
	".\..\thotlib\internals\f\boxselection_f.h"\
	".\..\thotlib\internals\f\structselect_f.h"\
	".\..\thotlib\internals\f\selectmenu_f.h"\
	".\..\thotlib\internals\f\fileaccess_f.h"\
	".\..\thotlib\internals\f\structschema_f.h"\
	".\..\thotlib\internals\f\content_f.h"\
	".\..\thotlib\internals\f\searchref_f.h"\
	".\..\thotlib\internals\f\structlocate_f.h"\
	".\..\thotlib\include\sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\thotlib\internals\h\constint.h"\
	".\..\thotlib\internals\h\thotkey.h"\
	".\..\thotlib\internals\h\conststr.h"\
	".\..\thotlib\internals\h\constprs.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\internals\h\frame.h"\
	
NODEP_CPP_STRUCTC=\
	".\..\thotlib\include\HTVMSUtils.h"\
	

"$(INTDIR)\structchange.obj" : $(SOURCE) $(DEP_CPP_STRUCTC) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "LibThotEditor - Win32 Debug"

DEP_CPP_STRUCTC=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\constmenu.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\internals\h\modif.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\fileaccess.h"\
	".\..\thotlib\include\libmsg.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\internals\h\appdialogue.h"\
	".\..\thotlib\include\dialog.h"\
	".\..\thotlib\include\content.h"\
	".\..\thotlib\internals\var\creation_tv.h"\
	".\..\thotlib\internals\var\modif_tv.h"\
	".\..\thotlib\internals\var\select_tv.h"\
	".\..\thotlib\internals\var\edit_tv.h"\
	".\..\thotlib\internals\var\appdialogue_tv.h"\
	".\..\thotlib\internals\f\appli_f.h"\
	".\..\thotlib\internals\f\actions_f.h"\
	".\..\thotlib\internals\f\applicationapi_f.h"\
	".\..\thotlib\internals\f\tree_f.h"\
	".\..\thotlib\internals\f\attrpresent_f.h"\
	".\..\thotlib\internals\f\attributes_f.h"\
	".\..\thotlib\internals\f\search_f.h"\
	".\..\thotlib\internals\f\textcommands_f.h"\
	".\..\thotlib\internals\f\editcommands_f.h"\
	".\..\thotlib\internals\f\contentapi_f.h"\
	".\..\thotlib\internals\f\structcreation_f.h"\
	".\..\thotlib\internals\f\createabsbox_f.h"\
	".\..\thotlib\internals\f\views_f.h"\
	".\..\thotlib\internals\f\callback_f.h"\
	".\..\thotlib\internals\f\exceptions_f.h"\
	".\..\thotlib\internals\f\absboxes_f.h"\
	".\..\thotlib\internals\f\buildboxes_f.h"\
	".\..\thotlib\internals\f\memory_f.h"\
	".\..\thotlib\internals\f\structmodif_f.h"\
	".\..\thotlib\internals\f\changeabsbox_f.h"\
	".\..\thotlib\internals\f\changepresent_f.h"\
	".\..\thotlib\internals\f\presrules_f.h"\
	".\..\thotlib\internals\f\references_f.h"\
	".\..\thotlib\internals\f\externalref_f.h"\
	".\..\thotlib\internals\f\boxselection_f.h"\
	".\..\thotlib\internals\f\structselect_f.h"\
	".\..\thotlib\internals\f\selectmenu_f.h"\
	".\..\thotlib\internals\f\fileaccess_f.h"\
	".\..\thotlib\internals\f\structschema_f.h"\
	".\..\thotlib\internals\f\content_f.h"\
	".\..\thotlib\internals\f\searchref_f.h"\
	".\..\thotlib\internals\f\structlocate_f.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\internals\h\frame.h"\
	

"$(INTDIR)\structchange.obj" : $(SOURCE) $(DEP_CPP_STRUCTC) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\Guetari\Opera\Thotlib\Editing\structcommands.c

!IF  "$(CFG)" == "LibThotEditor - Win32 Release"

DEP_CPP_STRUCTCO=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\constmenu.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\internals\h\modif.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\libmsg.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\include\fileaccess.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\internals\h\appdialogue.h"\
	".\..\thotlib\include\dialog.h"\
	".\..\thotlib\include\content.h"\
	".\..\thotlib\include\registry.h"\
	".\..\thotlib\internals\var\creation_tv.h"\
	".\..\thotlib\internals\var\modif_tv.h"\
	".\..\thotlib\internals\var\select_tv.h"\
	".\..\thotlib\internals\var\edit_tv.h"\
	".\..\thotlib\internals\var\appdialogue_tv.h"\
	".\..\thotlib\internals\f\res_f.h"\
	".\..\thotlib\internals\f\appli_f.h"\
	".\..\thotlib\internals\f\applicationapi_f.h"\
	".\..\thotlib\internals\f\tree_f.h"\
	".\..\thotlib\internals\f\attrpresent_f.h"\
	".\..\thotlib\internals\f\attributes_f.h"\
	".\..\thotlib\internals\f\search_f.h"\
	".\..\thotlib\internals\f\textcommands_f.h"\
	".\..\thotlib\internals\f\editcommands_f.h"\
	".\..\thotlib\internals\f\contentapi_f.h"\
	".\..\thotlib\internals\f\structcreation_f.h"\
	".\..\thotlib\internals\f\createabsbox_f.h"\
	".\..\thotlib\internals\f\views_f.h"\
	".\..\thotlib\internals\f\callback_f.h"\
	".\..\thotlib\internals\f\exceptions_f.h"\
	".\..\thotlib\internals\f\absboxes_f.h"\
	".\..\thotlib\internals\f\buildboxes_f.h"\
	".\..\thotlib\internals\f\memory_f.h"\
	".\..\thotlib\internals\f\structmodif_f.h"\
	".\..\thotlib\internals\f\changeabsbox_f.h"\
	".\..\thotlib\internals\f\changepresent_f.h"\
	".\..\thotlib\internals\f\presrules_f.h"\
	".\..\thotlib\internals\f\references_f.h"\
	".\..\thotlib\internals\f\externalref_f.h"\
	".\..\thotlib\internals\f\boxselection_f.h"\
	".\..\thotlib\internals\f\structselect_f.h"\
	".\..\thotlib\internals\f\selectmenu_f.h"\
	".\..\thotlib\internals\f\fileaccess_f.h"\
	".\..\thotlib\internals\f\structschema_f.h"\
	".\..\thotlib\internals\f\content_f.h"\
	".\..\thotlib\include\sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\thotlib\internals\h\constint.h"\
	".\..\thotlib\internals\h\thotkey.h"\
	".\..\thotlib\internals\h\conststr.h"\
	".\..\thotlib\internals\h\constprs.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\frame.h"\
	
NODEP_CPP_STRUCTCO=\
	".\..\thotlib\include\HTVMSUtils.h"\
	

"$(INTDIR)\structcommands.obj" : $(SOURCE) $(DEP_CPP_STRUCTCO) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "LibThotEditor - Win32 Debug"

DEP_CPP_STRUCTCO=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\constmenu.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\internals\h\modif.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\libmsg.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\include\fileaccess.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\internals\h\appdialogue.h"\
	".\..\thotlib\include\dialog.h"\
	".\..\thotlib\include\content.h"\
	".\..\thotlib\include\registry.h"\
	".\..\thotlib\internals\var\creation_tv.h"\
	".\..\thotlib\internals\var\modif_tv.h"\
	".\..\thotlib\internals\var\select_tv.h"\
	".\..\thotlib\internals\var\edit_tv.h"\
	".\..\thotlib\internals\var\appdialogue_tv.h"\
	".\..\thotlib\internals\f\res_f.h"\
	".\..\thotlib\internals\f\appli_f.h"\
	".\..\thotlib\internals\f\applicationapi_f.h"\
	".\..\thotlib\internals\f\tree_f.h"\
	".\..\thotlib\internals\f\attrpresent_f.h"\
	".\..\thotlib\internals\f\attributes_f.h"\
	".\..\thotlib\internals\f\search_f.h"\
	".\..\thotlib\internals\f\textcommands_f.h"\
	".\..\thotlib\internals\f\editcommands_f.h"\
	".\..\thotlib\internals\f\contentapi_f.h"\
	".\..\thotlib\internals\f\structcreation_f.h"\
	".\..\thotlib\internals\f\createabsbox_f.h"\
	".\..\thotlib\internals\f\views_f.h"\
	".\..\thotlib\internals\f\callback_f.h"\
	".\..\thotlib\internals\f\exceptions_f.h"\
	".\..\thotlib\internals\f\absboxes_f.h"\
	".\..\thotlib\internals\f\buildboxes_f.h"\
	".\..\thotlib\internals\f\memory_f.h"\
	".\..\thotlib\internals\f\structmodif_f.h"\
	".\..\thotlib\internals\f\changeabsbox_f.h"\
	".\..\thotlib\internals\f\changepresent_f.h"\
	".\..\thotlib\internals\f\presrules_f.h"\
	".\..\thotlib\internals\f\references_f.h"\
	".\..\thotlib\internals\f\externalref_f.h"\
	".\..\thotlib\internals\f\boxselection_f.h"\
	".\..\thotlib\internals\f\structselect_f.h"\
	".\..\thotlib\internals\f\selectmenu_f.h"\
	".\..\thotlib\internals\f\fileaccess_f.h"\
	".\..\thotlib\internals\f\structschema_f.h"\
	".\..\thotlib\internals\f\content_f.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\frame.h"\
	

"$(INTDIR)\structcommands.obj" : $(SOURCE) $(DEP_CPP_STRUCTCO) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\Guetari\Opera\Thotlib\Editing\structcreation.c

!IF  "$(CFG)" == "LibThotEditor - Win32 Release"

DEP_CPP_STRUCTCR=\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\constmenu.h"\
	".\..\thotlib\include\libmsg.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\include\fileaccess.h"\
	".\..\thotlib\internals\h\picture.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\dialog.h"\
	".\..\thotlib\internals\h\appdialogue.h"\
	".\..\thotlib\internals\var\modif_tv.h"\
	".\..\thotlib\internals\var\select_tv.h"\
	".\..\thotlib\internals\var\platform_tv.h"\
	".\..\thotlib\internals\var\edit_tv.h"\
	".\..\thotlib\internals\var\appdialogue_tv.h"\
	".\..\thotlib\internals\var\creation_tv.h"\
	".\..\thotlib\internals\f\absboxes_f.h"\
	".\..\thotlib\internals\f\abspictures_f.h"\
	".\..\thotlib\internals\f\appli_f.h"\
	".\..\thotlib\internals\f\applicationapi_f.h"\
	".\..\thotlib\internals\f\attrpresent_f.h"\
	".\..\thotlib\internals\f\attributes_f.h"\
	".\..\thotlib\internals\f\boxselection_f.h"\
	".\..\thotlib\internals\f\buildboxes_f.h"\
	".\..\thotlib\internals\f\callback_f.h"\
	".\..\thotlib\internals\f\changeabsbox_f.h"\
	".\..\thotlib\internals\f\config_f.h"\
	".\..\thotlib\internals\f\content_f.h"\
	".\..\thotlib\internals\f\creationmenu_f.h"\
	".\..\thotlib\internals\f\createabsbox_f.h"\
	".\..\thotlib\internals\f\createpages_f.h"\
	".\..\thotlib\internals\f\docs_f.h"\
	".\..\thotlib\internals\f\draw_f.h"\
	".\..\thotlib\internals\f\editcommands_f.h"\
	".\..\thotlib\internals\f\exceptions_f.h"\
	".\..\thotlib\internals\f\frame_f.h"\
	".\..\thotlib\internals\f\memory_f.h"\
	".\..\thotlib\internals\f\presvariables_f.h"\
	".\..\thotlib\internals\f\readpivot_f.h"\
	".\..\thotlib\internals\f\references_f.h"\
	".\..\thotlib\internals\f\schemas_f.h"\
	".\..\thotlib\internals\f\structcreation_f.h"\
	".\..\thotlib\internals\f\structmodif_f.h"\
	".\..\thotlib\internals\f\structselect_f.h"\
	".\..\thotlib\internals\f\structschema_f.h"\
	".\..\thotlib\internals\f\tree_f.h"\
	".\..\thotlib\internals\f\viewcommands_f.h"\
	".\..\thotlib\internals\f\views_f.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\thotlib\internals\h\constint.h"\
	".\..\thotlib\internals\h\thotkey.h"\
	".\..\thotlib\internals\h\conststr.h"\
	".\..\thotlib\internals\h\constprs.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\frame.h"\
	
NODEP_CPP_STRUCTCR=\
	".\..\thotlib\include\HTVMSUtils.h"\
	

"$(INTDIR)\structcreation.obj" : $(SOURCE) $(DEP_CPP_STRUCTCR) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "LibThotEditor - Win32 Debug"

DEP_CPP_STRUCTCR=\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\constmenu.h"\
	".\..\thotlib\include\libmsg.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\include\fileaccess.h"\
	".\..\thotlib\internals\h\picture.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\dialog.h"\
	".\..\thotlib\internals\h\appdialogue.h"\
	".\..\thotlib\internals\var\modif_tv.h"\
	".\..\thotlib\internals\var\select_tv.h"\
	".\..\thotlib\internals\var\platform_tv.h"\
	".\..\thotlib\internals\var\edit_tv.h"\
	".\..\thotlib\internals\var\appdialogue_tv.h"\
	".\..\thotlib\internals\var\creation_tv.h"\
	".\..\thotlib\internals\f\absboxes_f.h"\
	".\..\thotlib\internals\f\abspictures_f.h"\
	".\..\thotlib\internals\f\appli_f.h"\
	".\..\thotlib\internals\f\applicationapi_f.h"\
	".\..\thotlib\internals\f\attrpresent_f.h"\
	".\..\thotlib\internals\f\attributes_f.h"\
	".\..\thotlib\internals\f\boxselection_f.h"\
	".\..\thotlib\internals\f\buildboxes_f.h"\
	".\..\thotlib\internals\f\callback_f.h"\
	".\..\thotlib\internals\f\changeabsbox_f.h"\
	".\..\thotlib\internals\f\config_f.h"\
	".\..\thotlib\internals\f\content_f.h"\
	".\..\thotlib\internals\f\creationmenu_f.h"\
	".\..\thotlib\internals\f\createabsbox_f.h"\
	".\..\thotlib\internals\f\createpages_f.h"\
	".\..\thotlib\internals\f\docs_f.h"\
	".\..\thotlib\internals\f\draw_f.h"\
	".\..\thotlib\internals\f\editcommands_f.h"\
	".\..\thotlib\internals\f\exceptions_f.h"\
	".\..\thotlib\internals\f\frame_f.h"\
	".\..\thotlib\internals\f\memory_f.h"\
	".\..\thotlib\internals\f\presvariables_f.h"\
	".\..\thotlib\internals\f\readpivot_f.h"\
	".\..\thotlib\internals\f\references_f.h"\
	".\..\thotlib\internals\f\schemas_f.h"\
	".\..\thotlib\internals\f\structcreation_f.h"\
	".\..\thotlib\internals\f\structmodif_f.h"\
	".\..\thotlib\internals\f\structselect_f.h"\
	".\..\thotlib\internals\f\structschema_f.h"\
	".\..\thotlib\internals\f\tree_f.h"\
	".\..\thotlib\internals\f\viewcommands_f.h"\
	".\..\thotlib\internals\f\views_f.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\frame.h"\
	

"$(INTDIR)\structcreation.obj" : $(SOURCE) $(DEP_CPP_STRUCTCR) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\Guetari\Opera\Thotlib\Editing\structmodif.c

!IF  "$(CFG)" == "LibThotEditor - Win32 Release"

DEP_CPP_STRUCTM=\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\internals\h\modif.h"\
	".\..\thotlib\internals\h\res.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\libmsg.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\include\fileaccess.h"\
	".\..\thotlib\internals\h\appdialogue.h"\
	".\..\thotlib\include\content.h"\
	".\..\thotlib\internals\var\modif_tv.h"\
	".\..\thotlib\internals\var\creation_tv.h"\
	".\..\thotlib\internals\var\select_tv.h"\
	".\..\thotlib\internals\var\edit_tv.h"\
	".\..\thotlib\internals\var\appdialogue_tv.h"\
	".\..\thotlib\internals\f\appli_f.h"\
	".\..\thotlib\internals\f\applicationapi_f.h"\
	".\..\thotlib\internals\f\tree_f.h"\
	".\..\thotlib\internals\f\attrpresent_f.h"\
	".\..\thotlib\internals\f\attributes_f.h"\
	".\..\thotlib\internals\f\search_f.h"\
	".\..\thotlib\internals\f\textcommands_f.h"\
	".\..\thotlib\internals\f\contentapi_f.h"\
	".\..\thotlib\internals\f\structcreation_f.h"\
	".\..\thotlib\internals\f\createabsbox_f.h"\
	".\..\thotlib\internals\f\views_f.h"\
	".\..\thotlib\internals\f\appdialogue_f.h"\
	".\..\thotlib\internals\f\callback_f.h"\
	".\..\thotlib\internals\f\exceptions_f.h"\
	".\..\thotlib\internals\f\absboxes_f.h"\
	".\..\thotlib\internals\f\buildboxes_f.h"\
	".\..\thotlib\internals\f\memory_f.h"\
	".\..\thotlib\internals\f\structmodif_f.h"\
	".\..\thotlib\internals\f\changeabsbox_f.h"\
	".\..\thotlib\internals\f\changepresent_f.h"\
	".\..\thotlib\internals\f\presrules_f.h"\
	".\..\thotlib\internals\f\references_f.h"\
	".\..\thotlib\internals\f\externalref_f.h"\
	".\..\thotlib\internals\f\boxselection_f.h"\
	".\..\thotlib\internals\f\structselect_f.h"\
	".\..\thotlib\internals\f\selectmenu_f.h"\
	".\..\thotlib\internals\f\fileaccess_f.h"\
	".\..\thotlib\internals\f\structschema_f.h"\
	".\..\thotlib\internals\f\content_f.h"\
	".\..\thotlib\internals\f\frame_f.h"\
	".\..\thotlib\internals\f\searchref_f.h"\
	".\..\thotlib\internals\f\docs_f.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\thotlib\internals\h\constint.h"\
	".\..\thotlib\internals\h\thotkey.h"\
	".\..\thotlib\internals\h\conststr.h"\
	".\..\thotlib\internals\h\constprs.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\internals\h\SelectRestruct.h"\
	".\..\thotlib\internals\h\resdynmsg.h"\
	".\..\thotlib\internals\h\frame.h"\
	".\..\thotlib\internals\h\constmenu.h"\
	
NODEP_CPP_STRUCTM=\
	".\..\thotlib\include\HTVMSUtils.h"\
	

"$(INTDIR)\structmodif.obj" : $(SOURCE) $(DEP_CPP_STRUCTM) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "LibThotEditor - Win32 Debug"

DEP_CPP_STRUCTM=\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\internals\h\modif.h"\
	".\..\thotlib\internals\h\res.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\libmsg.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\include\fileaccess.h"\
	".\..\thotlib\internals\h\appdialogue.h"\
	".\..\thotlib\include\content.h"\
	".\..\thotlib\internals\var\modif_tv.h"\
	".\..\thotlib\internals\var\creation_tv.h"\
	".\..\thotlib\internals\var\select_tv.h"\
	".\..\thotlib\internals\var\edit_tv.h"\
	".\..\thotlib\internals\var\appdialogue_tv.h"\
	".\..\thotlib\internals\f\appli_f.h"\
	".\..\thotlib\internals\f\applicationapi_f.h"\
	".\..\thotlib\internals\f\tree_f.h"\
	".\..\thotlib\internals\f\attrpresent_f.h"\
	".\..\thotlib\internals\f\attributes_f.h"\
	".\..\thotlib\internals\f\search_f.h"\
	".\..\thotlib\internals\f\textcommands_f.h"\
	".\..\thotlib\internals\f\contentapi_f.h"\
	".\..\thotlib\internals\f\structcreation_f.h"\
	".\..\thotlib\internals\f\createabsbox_f.h"\
	".\..\thotlib\internals\f\views_f.h"\
	".\..\thotlib\internals\f\appdialogue_f.h"\
	".\..\thotlib\internals\f\callback_f.h"\
	".\..\thotlib\internals\f\exceptions_f.h"\
	".\..\thotlib\internals\f\absboxes_f.h"\
	".\..\thotlib\internals\f\buildboxes_f.h"\
	".\..\thotlib\internals\f\memory_f.h"\
	".\..\thotlib\internals\f\structmodif_f.h"\
	".\..\thotlib\internals\f\changeabsbox_f.h"\
	".\..\thotlib\internals\f\changepresent_f.h"\
	".\..\thotlib\internals\f\presrules_f.h"\
	".\..\thotlib\internals\f\references_f.h"\
	".\..\thotlib\internals\f\externalref_f.h"\
	".\..\thotlib\internals\f\boxselection_f.h"\
	".\..\thotlib\internals\f\structselect_f.h"\
	".\..\thotlib\internals\f\selectmenu_f.h"\
	".\..\thotlib\internals\f\fileaccess_f.h"\
	".\..\thotlib\internals\f\structschema_f.h"\
	".\..\thotlib\internals\f\content_f.h"\
	".\..\thotlib\internals\f\frame_f.h"\
	".\..\thotlib\internals\f\searchref_f.h"\
	".\..\thotlib\internals\f\docs_f.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\internals\h\SelectRestruct.h"\
	".\..\thotlib\internals\h\resdynmsg.h"\
	".\..\thotlib\internals\h\frame.h"\
	".\..\thotlib\internals\h\constmenu.h"\
	

"$(INTDIR)\structmodif.obj" : $(SOURCE) $(DEP_CPP_STRUCTM) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\Guetari\Opera\Thotlib\Editing\structselect.c

!IF  "$(CFG)" == "LibThotEditor - Win32 Release"

DEP_CPP_STRUCTS=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\libmsg.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\internals\h\appdialogue.h"\
	".\..\thotlib\internals\var\edit_tv.h"\
	".\..\thotlib\internals\var\frame_tv.h"\
	".\..\thotlib\internals\var\appdialogue_tv.h"\
	".\..\thotlib\internals\var\select_tv.h"\
	".\..\thotlib\internals\f\appli_f.h"\
	".\..\thotlib\internals\f\applicationapi_f.h"\
	".\..\thotlib\internals\f\tree_f.h"\
	".\..\thotlib\internals\f\search_f.h"\
	".\..\thotlib\internals\f\config_f.h"\
	".\..\thotlib\internals\f\createabsbox_f.h"\
	".\..\thotlib\internals\f\scroll_f.h"\
	".\..\thotlib\internals\f\views_f.h"\
	".\..\thotlib\internals\f\draw_f.h"\
	".\..\thotlib\internals\f\callback_f.h"\
	".\..\thotlib\internals\f\exceptions_f.h"\
	".\..\thotlib\internals\f\windowdisplay_f.h"\
	".\..\thotlib\internals\f\absboxes_f.h"\
	".\..\thotlib\internals\f\keyboards_f.h"\
	".\..\thotlib\internals\f\structmodif_f.h"\
	".\..\thotlib\internals\f\boxselection_f.h"\
	".\..\thotlib\internals\f\structselect_f.h"\
	".\..\thotlib\internals\f\selectmenu_f.h"\
	".\..\thotlib\internals\f\displayselect_f.h"\
	".\..\thotlib\internals\f\searchref_f.h"\
	".\..\thotlib\include\sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\thotlib\internals\h\constint.h"\
	".\..\thotlib\internals\h\thotkey.h"\
	".\..\thotlib\internals\h\conststr.h"\
	".\..\thotlib\internals\h\constprs.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\internals\h\frame.h"\
	".\..\thotlib\internals\h\constmenu.h"\
	
NODEP_CPP_STRUCTS=\
	".\..\thotlib\include\HTVMSUtils.h"\
	

"$(INTDIR)\structselect.obj" : $(SOURCE) $(DEP_CPP_STRUCTS) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "LibThotEditor - Win32 Debug"

DEP_CPP_STRUCTS=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\libmsg.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\internals\h\appdialogue.h"\
	".\..\thotlib\internals\var\edit_tv.h"\
	".\..\thotlib\internals\var\frame_tv.h"\
	".\..\thotlib\internals\var\appdialogue_tv.h"\
	".\..\thotlib\internals\var\select_tv.h"\
	".\..\thotlib\internals\f\appli_f.h"\
	".\..\thotlib\internals\f\applicationapi_f.h"\
	".\..\thotlib\internals\f\tree_f.h"\
	".\..\thotlib\internals\f\search_f.h"\
	".\..\thotlib\internals\f\config_f.h"\
	".\..\thotlib\internals\f\createabsbox_f.h"\
	".\..\thotlib\internals\f\scroll_f.h"\
	".\..\thotlib\internals\f\views_f.h"\
	".\..\thotlib\internals\f\draw_f.h"\
	".\..\thotlib\internals\f\callback_f.h"\
	".\..\thotlib\internals\f\exceptions_f.h"\
	".\..\thotlib\internals\f\windowdisplay_f.h"\
	".\..\thotlib\internals\f\absboxes_f.h"\
	".\..\thotlib\internals\f\keyboards_f.h"\
	".\..\thotlib\internals\f\structmodif_f.h"\
	".\..\thotlib\internals\f\boxselection_f.h"\
	".\..\thotlib\internals\f\structselect_f.h"\
	".\..\thotlib\internals\f\selectmenu_f.h"\
	".\..\thotlib\internals\f\displayselect_f.h"\
	".\..\thotlib\internals\f\searchref_f.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\internals\h\frame.h"\
	".\..\thotlib\internals\h\constmenu.h"\
	

"$(INTDIR)\structselect.obj" : $(SOURCE) $(DEP_CPP_STRUCTS) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\Guetari\Opera\Thotlib\Editing\textcommands.c

!IF  "$(CFG)" == "LibThotEditor - Win32 Release"

DEP_CPP_TEXTC=\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\include\libmsg.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\internals\h\picture.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\internals\h\appdialogue.h"\
	".\..\thotlib\internals\var\boxes_tv.h"\
	".\..\thotlib\internals\var\frame_tv.h"\
	".\..\thotlib\internals\var\edit_tv.h"\
	".\..\thotlib\internals\var\appdialogue_tv.h"\
	".\..\thotlib\internals\f\applicationapi_f.h"\
	".\..\thotlib\internals\f\appli_f.h"\
	".\..\thotlib\internals\f\tree_f.h"\
	".\..\thotlib\internals\f\textcommands_f.h"\
	".\..\thotlib\internals\f\editcommands_f.h"\
	".\..\thotlib\internals\f\structcreation_f.h"\
	".\..\thotlib\internals\f\scroll_f.h"\
	".\..\thotlib\internals\f\boxmoves_f.h"\
	".\..\thotlib\internals\f\boxlocate_f.h"\
	".\..\thotlib\internals\f\views_f.h"\
	".\..\thotlib\internals\f\callback_f.h"\
	".\..\thotlib\internals\f\windowdisplay_f.h"\
	".\..\thotlib\internals\f\font_f.h"\
	".\..\thotlib\internals\f\geom_f.h"\
	".\..\thotlib\internals\f\buildboxes_f.h"\
	".\..\thotlib\internals\f\picture_f.h"\
	".\..\thotlib\internals\f\abspictures_f.h"\
	".\..\thotlib\internals\f\buildlines_f.h"\
	".\..\thotlib\internals\f\memory_f.h"\
	".\..\thotlib\internals\f\structmodif_f.h"\
	".\..\thotlib\internals\f\boxparams_f.h"\
	".\..\thotlib\internals\f\boxselection_f.h"\
	".\..\thotlib\internals\f\structselect_f.h"\
	".\..\thotlib\internals\f\content_f.h"\
	".\..\thotlib\internals\f\viewapi_f.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\thotlib\internals\h\constint.h"\
	".\..\thotlib\internals\h\thotkey.h"\
	".\..\thotlib\internals\h\conststr.h"\
	".\..\thotlib\internals\h\constprs.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\frame.h"\
	".\..\thotlib\internals\h\constmenu.h"\
	
NODEP_CPP_TEXTC=\
	".\..\thotlib\include\HTVMSUtils.h"\
	

"$(INTDIR)\textcommands.obj" : $(SOURCE) $(DEP_CPP_TEXTC) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "LibThotEditor - Win32 Debug"

DEP_CPP_TEXTC=\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\include\libmsg.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\internals\h\picture.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\internals\h\appdialogue.h"\
	".\..\thotlib\internals\var\boxes_tv.h"\
	".\..\thotlib\internals\var\frame_tv.h"\
	".\..\thotlib\internals\var\edit_tv.h"\
	".\..\thotlib\internals\var\appdialogue_tv.h"\
	".\..\thotlib\internals\f\applicationapi_f.h"\
	".\..\thotlib\internals\f\appli_f.h"\
	".\..\thotlib\internals\f\tree_f.h"\
	".\..\thotlib\internals\f\textcommands_f.h"\
	".\..\thotlib\internals\f\editcommands_f.h"\
	".\..\thotlib\internals\f\structcreation_f.h"\
	".\..\thotlib\internals\f\scroll_f.h"\
	".\..\thotlib\internals\f\boxmoves_f.h"\
	".\..\thotlib\internals\f\boxlocate_f.h"\
	".\..\thotlib\internals\f\views_f.h"\
	".\..\thotlib\internals\f\callback_f.h"\
	".\..\thotlib\internals\f\windowdisplay_f.h"\
	".\..\thotlib\internals\f\font_f.h"\
	".\..\thotlib\internals\f\geom_f.h"\
	".\..\thotlib\internals\f\buildboxes_f.h"\
	".\..\thotlib\internals\f\picture_f.h"\
	".\..\thotlib\internals\f\abspictures_f.h"\
	".\..\thotlib\internals\f\buildlines_f.h"\
	".\..\thotlib\internals\f\memory_f.h"\
	".\..\thotlib\internals\f\structmodif_f.h"\
	".\..\thotlib\internals\f\boxparams_f.h"\
	".\..\thotlib\internals\f\boxselection_f.h"\
	".\..\thotlib\internals\f\structselect_f.h"\
	".\..\thotlib\internals\f\content_f.h"\
	".\..\thotlib\internals\f\viewapi_f.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\frame.h"\
	".\..\thotlib\internals\h\constmenu.h"\
	

"$(INTDIR)\textcommands.obj" : $(SOURCE) $(DEP_CPP_TEXTC) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\Guetari\Opera\Thotlib\Editing\unstructchange.c

!IF  "$(CFG)" == "LibThotEditor - Win32 Release"

DEP_CPP_UNSTR=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\constmenu.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\internals\h\modif.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\fileaccess.h"\
	".\..\thotlib\include\libmsg.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\internals\h\appdialogue.h"\
	".\..\thotlib\include\dialog.h"\
	".\..\thotlib\include\content.h"\
	".\..\thotlib\internals\var\creation_tv.h"\
	".\..\thotlib\internals\var\modif_tv.h"\
	".\..\thotlib\internals\var\select_tv.h"\
	".\..\thotlib\internals\var\edit_tv.h"\
	".\..\thotlib\internals\var\appdialogue_tv.h"\
	".\..\thotlib\internals\f\appli_f.h"\
	".\..\thotlib\internals\f\applicationapi_f.h"\
	".\..\thotlib\internals\f\tree_f.h"\
	".\..\thotlib\internals\f\attrpresent_f.h"\
	".\..\thotlib\internals\f\attributes_f.h"\
	".\..\thotlib\internals\f\search_f.h"\
	".\..\thotlib\internals\f\textcommands_f.h"\
	".\..\thotlib\internals\f\editcommands_f.h"\
	".\..\thotlib\internals\f\contentapi_f.h"\
	".\..\thotlib\internals\f\structcreation_f.h"\
	".\..\thotlib\internals\f\createabsbox_f.h"\
	".\..\thotlib\internals\f\views_f.h"\
	".\..\thotlib\internals\f\viewapi_f.h"\
	".\..\thotlib\internals\f\callback_f.h"\
	".\..\thotlib\internals\f\exceptions_f.h"\
	".\..\thotlib\internals\f\absboxes_f.h"\
	".\..\thotlib\internals\f\buildboxes_f.h"\
	".\..\thotlib\internals\f\memory_f.h"\
	".\..\thotlib\internals\f\structmodif_f.h"\
	".\..\thotlib\internals\f\changeabsbox_f.h"\
	".\..\thotlib\internals\f\changepresent_f.h"\
	".\..\thotlib\internals\f\presrules_f.h"\
	".\..\thotlib\internals\f\references_f.h"\
	".\..\thotlib\internals\f\externalref_f.h"\
	".\..\thotlib\internals\f\boxselection_f.h"\
	".\..\thotlib\internals\f\structselect_f.h"\
	".\..\thotlib\internals\f\selectmenu_f.h"\
	".\..\thotlib\internals\f\fileaccess_f.h"\
	".\..\thotlib\internals\f\structschema_f.h"\
	".\..\thotlib\internals\f\content_f.h"\
	".\..\thotlib\internals\f\searchref_f.h"\
	".\..\thotlib\internals\f\unstructlocate_f.h"\
	".\..\thotlib\internals\f\structcommands_f.h"\
	".\..\thotlib\internals\f\actions_f.h"\
	".\..\thotlib\include\sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\thotlib\internals\h\constint.h"\
	".\..\thotlib\internals\h\thotkey.h"\
	".\..\thotlib\internals\h\conststr.h"\
	".\..\thotlib\internals\h\constprs.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\internals\h\frame.h"\
	
NODEP_CPP_UNSTR=\
	".\..\thotlib\include\HTVMSUtils.h"\
	

"$(INTDIR)\unstructchange.obj" : $(SOURCE) $(DEP_CPP_UNSTR) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "LibThotEditor - Win32 Debug"

DEP_CPP_UNSTR=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\constmenu.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\internals\h\modif.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\fileaccess.h"\
	".\..\thotlib\include\libmsg.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\internals\h\appdialogue.h"\
	".\..\thotlib\include\dialog.h"\
	".\..\thotlib\include\content.h"\
	".\..\thotlib\internals\var\creation_tv.h"\
	".\..\thotlib\internals\var\modif_tv.h"\
	".\..\thotlib\internals\var\select_tv.h"\
	".\..\thotlib\internals\var\edit_tv.h"\
	".\..\thotlib\internals\var\appdialogue_tv.h"\
	".\..\thotlib\internals\f\appli_f.h"\
	".\..\thotlib\internals\f\applicationapi_f.h"\
	".\..\thotlib\internals\f\tree_f.h"\
	".\..\thotlib\internals\f\attrpresent_f.h"\
	".\..\thotlib\internals\f\attributes_f.h"\
	".\..\thotlib\internals\f\search_f.h"\
	".\..\thotlib\internals\f\textcommands_f.h"\
	".\..\thotlib\internals\f\editcommands_f.h"\
	".\..\thotlib\internals\f\contentapi_f.h"\
	".\..\thotlib\internals\f\structcreation_f.h"\
	".\..\thotlib\internals\f\createabsbox_f.h"\
	".\..\thotlib\internals\f\views_f.h"\
	".\..\thotlib\internals\f\viewapi_f.h"\
	".\..\thotlib\internals\f\callback_f.h"\
	".\..\thotlib\internals\f\exceptions_f.h"\
	".\..\thotlib\internals\f\absboxes_f.h"\
	".\..\thotlib\internals\f\buildboxes_f.h"\
	".\..\thotlib\internals\f\memory_f.h"\
	".\..\thotlib\internals\f\structmodif_f.h"\
	".\..\thotlib\internals\f\changeabsbox_f.h"\
	".\..\thotlib\internals\f\changepresent_f.h"\
	".\..\thotlib\internals\f\presrules_f.h"\
	".\..\thotlib\internals\f\references_f.h"\
	".\..\thotlib\internals\f\externalref_f.h"\
	".\..\thotlib\internals\f\boxselection_f.h"\
	".\..\thotlib\internals\f\structselect_f.h"\
	".\..\thotlib\internals\f\selectmenu_f.h"\
	".\..\thotlib\internals\f\fileaccess_f.h"\
	".\..\thotlib\internals\f\structschema_f.h"\
	".\..\thotlib\internals\f\content_f.h"\
	".\..\thotlib\internals\f\searchref_f.h"\
	".\..\thotlib\internals\f\unstructlocate_f.h"\
	".\..\thotlib\internals\f\structcommands_f.h"\
	".\..\thotlib\internals\f\actions_f.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\internals\h\frame.h"\
	

"$(INTDIR)\unstructchange.obj" : $(SOURCE) $(DEP_CPP_UNSTR) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\Guetari\Opera\Thotlib\Editing\viewcommands.c

!IF  "$(CFG)" == "LibThotEditor - Win32 Release"

DEP_CPP_VIEWC=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\internals\h\constmenu.h"\
	".\..\thotlib\include\libmsg.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\include\fileaccess.h"\
	".\..\thotlib\internals\h\appdialogue.h"\
	".\..\thotlib\include\application.h"\
	".\..\thotlib\include\dialog.h"\
	".\..\thotlib\internals\var\creation_tv.h"\
	".\..\thotlib\internals\var\platform_tv.h"\
	".\..\thotlib\internals\var\modif_tv.h"\
	".\..\thotlib\internals\var\page_tv.h"\
	".\..\thotlib\internals\var\select_tv.h"\
	".\..\thotlib\internals\var\appdialogue_tv.h"\
	".\..\thotlib\internals\var\print_tv.h"\
	".\..\thotlib\internals\var\edit_tv.h"\
	".\..\thotlib\internals\f\appli_f.h"\
	".\..\thotlib\internals\f\tree_f.h"\
	".\..\thotlib\internals\f\attributes_f.h"\
	".\..\thotlib\internals\f\search_f.h"\
	".\..\thotlib\internals\f\textcommands_f.h"\
	".\..\thotlib\internals\f\config_f.h"\
	".\..\thotlib\internals\f\structcreation_f.h"\
	".\..\thotlib\internals\f\createabsbox_f.h"\
	".\..\thotlib\internals\f\createpages_f.h"\
	".\..\thotlib\internals\f\structlist_f.h"\
	".\..\thotlib\internals\f\savedoc_f.h"\
	".\..\thotlib\internals\f\views_f.h"\
	".\..\thotlib\internals\f\viewapi_f.h"\
	".\..\thotlib\internals\f\appdialogue_f.h"\
	".\..\thotlib\internals\f\callback_f.h"\
	".\..\thotlib\internals\f\viewcommands_f.h"\
	".\..\thotlib\internals\f\exceptions_f.h"\
	".\..\thotlib\internals\f\absboxes_f.h"\
	".\..\thotlib\internals\f\buildboxes_f.h"\
	".\..\thotlib\internals\f\memory_f.h"\
	".\..\thotlib\internals\f\structmodif_f.h"\
	".\..\thotlib\internals\f\changeabsbox_f.h"\
	".\..\thotlib\internals\f\schemas_f.h"\
	".\..\thotlib\internals\f\structselect_f.h"\
	".\..\thotlib\internals\f\structschema_f.h"\
	".\..\thotlib\internals\f\content_f.h"\
	".\..\thotlib\internals\f\thotmsg_f.h"\
	".\..\thotlib\internals\f\applicationapi_f.h"\
	".\..\thotlib\internals\f\docs_f.h"\
	".\..\thotlib\internals\f\frame_f.h"\
	".\..\thotlib\internals\f\fileaccess_f.h"\
	".\..\thotlib\include\sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\thotlib\internals\h\constint.h"\
	".\..\thotlib\internals\h\thotkey.h"\
	".\..\thotlib\internals\h\conststr.h"\
	".\..\thotlib\internals\h\constprs.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\internals\h\frame.h"\
	".\..\thotlib\include\registry.h"\
	
NODEP_CPP_VIEWC=\
	".\..\thotlib\include\HTVMSUtils.h"\
	

"$(INTDIR)\viewcommands.obj" : $(SOURCE) $(DEP_CPP_VIEWC) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "LibThotEditor - Win32 Debug"

DEP_CPP_VIEWC=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\internals\h\constmenu.h"\
	".\..\thotlib\include\libmsg.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\include\fileaccess.h"\
	".\..\thotlib\internals\h\appdialogue.h"\
	".\..\thotlib\include\application.h"\
	".\..\thotlib\include\dialog.h"\
	".\..\thotlib\internals\var\creation_tv.h"\
	".\..\thotlib\internals\var\platform_tv.h"\
	".\..\thotlib\internals\var\modif_tv.h"\
	".\..\thotlib\internals\var\page_tv.h"\
	".\..\thotlib\internals\var\select_tv.h"\
	".\..\thotlib\internals\var\appdialogue_tv.h"\
	".\..\thotlib\internals\var\print_tv.h"\
	".\..\thotlib\internals\var\edit_tv.h"\
	".\..\thotlib\internals\f\appli_f.h"\
	".\..\thotlib\internals\f\tree_f.h"\
	".\..\thotlib\internals\f\attributes_f.h"\
	".\..\thotlib\internals\f\search_f.h"\
	".\..\thotlib\internals\f\textcommands_f.h"\
	".\..\thotlib\internals\f\config_f.h"\
	".\..\thotlib\internals\f\structcreation_f.h"\
	".\..\thotlib\internals\f\createabsbox_f.h"\
	".\..\thotlib\internals\f\createpages_f.h"\
	".\..\thotlib\internals\f\structlist_f.h"\
	".\..\thotlib\internals\f\savedoc_f.h"\
	".\..\thotlib\internals\f\views_f.h"\
	".\..\thotlib\internals\f\viewapi_f.h"\
	".\..\thotlib\internals\f\appdialogue_f.h"\
	".\..\thotlib\internals\f\callback_f.h"\
	".\..\thotlib\internals\f\viewcommands_f.h"\
	".\..\thotlib\internals\f\exceptions_f.h"\
	".\..\thotlib\internals\f\absboxes_f.h"\
	".\..\thotlib\internals\f\buildboxes_f.h"\
	".\..\thotlib\internals\f\memory_f.h"\
	".\..\thotlib\internals\f\structmodif_f.h"\
	".\..\thotlib\internals\f\changeabsbox_f.h"\
	".\..\thotlib\internals\f\schemas_f.h"\
	".\..\thotlib\internals\f\structselect_f.h"\
	".\..\thotlib\internals\f\structschema_f.h"\
	".\..\thotlib\internals\f\content_f.h"\
	".\..\thotlib\internals\f\thotmsg_f.h"\
	".\..\thotlib\internals\f\applicationapi_f.h"\
	".\..\thotlib\internals\f\docs_f.h"\
	".\..\thotlib\internals\f\frame_f.h"\
	".\..\thotlib\internals\f\fileaccess_f.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\internals\h\frame.h"\
	".\..\thotlib\include\registry.h"\
	

"$(INTDIR)\viewcommands.obj" : $(SOURCE) $(DEP_CPP_VIEWC) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\Guetari\Opera\Thotlib\presentation\presrules.c

!IF  "$(CFG)" == "LibThotEditor - Win32 Release"

DEP_CPP_PRESR=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\include\fileaccess.h"\
	".\..\thotlib\internals\h\picture.h"\
	".\..\thotlib\internals\h\appdialogue.h"\
	".\..\thotlib\internals\var\platform_tv.h"\
	".\..\thotlib\internals\var\appdialogue_tv.h"\
	".\..\thotlib\internals\f\tree_f.h"\
	".\..\thotlib\internals\f\structcreation_f.h"\
	".\..\thotlib\internals\f\createabsbox_f.h"\
	".\..\thotlib\internals\f\createpages_f.h"\
	".\..\thotlib\internals\f\appdialogue_f.h"\
	".\..\thotlib\internals\f\viewcommands_f.h"\
	".\..\thotlib\internals\f\exceptions_f.h"\
	".\..\thotlib\internals\f\fileaccess_f.h"\
	".\..\thotlib\internals\f\absboxes_f.h"\
	".\..\thotlib\internals\f\abspictures_f.h"\
	".\..\thotlib\internals\f\buildboxes_f.h"\
	".\..\thotlib\internals\f\memory_f.h"\
	".\..\thotlib\internals\f\structmodif_f.h"\
	".\..\thotlib\internals\f\changeabsbox_f.h"\
	".\..\thotlib\internals\f\boxpositions_f.h"\
	".\..\thotlib\internals\f\presrules_f.h"\
	".\..\thotlib\internals\f\references_f.h"\
	".\..\thotlib\internals\f\schemas_f.h"\
	".\..\thotlib\internals\f\boxselection_f.h"\
	".\..\thotlib\internals\f\content_f.h"\
	".\..\thotlib\internals\f\presvariables_f.h"\
	".\..\thotlib\internals\f\font_f.h"\
	".\..\thotlib\internals\f\units_f.h"\
	".\..\thotlib\include\sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\thotlib\internals\h\constint.h"\
	".\..\thotlib\internals\h\thotkey.h"\
	".\..\thotlib\internals\h\conststr.h"\
	".\..\thotlib\internals\h\constprs.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\internals\h\frame.h"\
	".\..\thotlib\internals\h\constmenu.h"\
	
NODEP_CPP_PRESR=\
	".\..\thotlib\include\HTVMSUtils.h"\
	

"$(INTDIR)\presrules.obj" : $(SOURCE) $(DEP_CPP_PRESR) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "LibThotEditor - Win32 Debug"

DEP_CPP_PRESR=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\include\fileaccess.h"\
	".\..\thotlib\internals\h\picture.h"\
	".\..\thotlib\internals\h\appdialogue.h"\
	".\..\thotlib\internals\var\platform_tv.h"\
	".\..\thotlib\internals\var\appdialogue_tv.h"\
	".\..\thotlib\internals\f\tree_f.h"\
	".\..\thotlib\internals\f\structcreation_f.h"\
	".\..\thotlib\internals\f\createabsbox_f.h"\
	".\..\thotlib\internals\f\createpages_f.h"\
	".\..\thotlib\internals\f\appdialogue_f.h"\
	".\..\thotlib\internals\f\viewcommands_f.h"\
	".\..\thotlib\internals\f\exceptions_f.h"\
	".\..\thotlib\internals\f\fileaccess_f.h"\
	".\..\thotlib\internals\f\absboxes_f.h"\
	".\..\thotlib\internals\f\abspictures_f.h"\
	".\..\thotlib\internals\f\buildboxes_f.h"\
	".\..\thotlib\internals\f\memory_f.h"\
	".\..\thotlib\internals\f\structmodif_f.h"\
	".\..\thotlib\internals\f\changeabsbox_f.h"\
	".\..\thotlib\internals\f\boxpositions_f.h"\
	".\..\thotlib\internals\f\presrules_f.h"\
	".\..\thotlib\internals\f\references_f.h"\
	".\..\thotlib\internals\f\schemas_f.h"\
	".\..\thotlib\internals\f\boxselection_f.h"\
	".\..\thotlib\internals\f\content_f.h"\
	".\..\thotlib\internals\f\presvariables_f.h"\
	".\..\thotlib\internals\f\font_f.h"\
	".\..\thotlib\internals\f\units_f.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\internals\h\frame.h"\
	".\..\thotlib\internals\h\constmenu.h"\
	

"$(INTDIR)\presrules.obj" : $(SOURCE) $(DEP_CPP_PRESR) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\Guetari\Opera\Thotlib\presentation\changepresent.c

!IF  "$(CFG)" == "LibThotEditor - Win32 Release"

DEP_CPP_CHANG=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\include\libmsg.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\internals\h\constmenu.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\internals\h\appdialogue.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\internals\h\picture.h"\
	".\..\thotlib\internals\var\page_tv.h"\
	".\..\thotlib\internals\var\select_tv.h"\
	".\..\thotlib\internals\var\edit_tv.h"\
	".\..\thotlib\internals\var\appdialogue_tv.h"\
	".\..\thotlib\internals\f\abspictures_f.h"\
	".\..\thotlib\internals\f\appli_f.h"\
	".\..\thotlib\internals\f\applicationapi_f.h"\
	".\..\thotlib\internals\f\attributes_f.h"\
	".\..\thotlib\internals\f\boxselection_f.h"\
	".\..\thotlib\internals\f\createabsbox_f.h"\
	".\..\thotlib\internals\f\callback_f.h"\
	".\..\thotlib\internals\f\exceptions_f.h"\
	".\..\thotlib\internals\f\font_f.h"\
	".\..\thotlib\internals\f\memory_f.h"\
	".\..\thotlib\internals\f\changeabsbox_f.h"\
	".\..\thotlib\internals\f\changepresent_f.h"\
	".\..\thotlib\internals\f\boxpositions_f.h"\
	".\..\thotlib\internals\f\presrules_f.h"\
	".\..\thotlib\internals\f\structcreation_f.h"\
	".\..\thotlib\internals\f\structmodif_f.h"\
	".\..\thotlib\internals\f\structselect_f.h"\
	".\..\thotlib\internals\f\unstructchange_f.h"\
	".\..\thotlib\internals\f\tree_f.h"\
	".\..\thotlib\include\sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\thotlib\internals\h\constint.h"\
	".\..\thotlib\internals\h\thotkey.h"\
	".\..\thotlib\internals\h\conststr.h"\
	".\..\thotlib\internals\h\constprs.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\internals\h\frame.h"\
	
NODEP_CPP_CHANG=\
	".\..\thotlib\include\HTVMSUtils.h"\
	

"$(INTDIR)\changepresent.obj" : $(SOURCE) $(DEP_CPP_CHANG) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "LibThotEditor - Win32 Debug"

DEP_CPP_CHANG=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\include\libmsg.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\internals\h\constmenu.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\internals\h\appdialogue.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\internals\h\picture.h"\
	".\..\thotlib\internals\var\page_tv.h"\
	".\..\thotlib\internals\var\select_tv.h"\
	".\..\thotlib\internals\var\edit_tv.h"\
	".\..\thotlib\internals\var\appdialogue_tv.h"\
	".\..\thotlib\internals\f\abspictures_f.h"\
	".\..\thotlib\internals\f\appli_f.h"\
	".\..\thotlib\internals\f\applicationapi_f.h"\
	".\..\thotlib\internals\f\attributes_f.h"\
	".\..\thotlib\internals\f\boxselection_f.h"\
	".\..\thotlib\internals\f\createabsbox_f.h"\
	".\..\thotlib\internals\f\callback_f.h"\
	".\..\thotlib\internals\f\exceptions_f.h"\
	".\..\thotlib\internals\f\font_f.h"\
	".\..\thotlib\internals\f\memory_f.h"\
	".\..\thotlib\internals\f\changeabsbox_f.h"\
	".\..\thotlib\internals\f\changepresent_f.h"\
	".\..\thotlib\internals\f\boxpositions_f.h"\
	".\..\thotlib\internals\f\presrules_f.h"\
	".\..\thotlib\internals\f\structcreation_f.h"\
	".\..\thotlib\internals\f\structmodif_f.h"\
	".\..\thotlib\internals\f\structselect_f.h"\
	".\..\thotlib\internals\f\unstructchange_f.h"\
	".\..\thotlib\internals\f\tree_f.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\internals\h\frame.h"\
	

"$(INTDIR)\changepresent.obj" : $(SOURCE) $(DEP_CPP_CHANG) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\Guetari\Opera\Thotlib\presentation\genericdriver.c

!IF  "$(CFG)" == "LibThotEditor - Win32 Release"

DEP_CPP_GENER=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\include\libmsg.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\include\application.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\internals\var\edit_tv.h"\
	".\..\thotlib\internals\f\changepresent_f.h"\
	".\..\thotlib\include\genericdriver.h"\
	".\..\thotlib\internals\f\memory_f.h"\
	".\..\thotlib\internals\f\presentdriver_f.h"\
	".\..\thotlib\include\sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\thotlib\internals\h\constint.h"\
	".\..\thotlib\internals\h\thotkey.h"\
	".\..\thotlib\internals\h\conststr.h"\
	".\..\thotlib\internals\h\constprs.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\include\fileaccess.h"\
	".\..\thotlib\include\registry.h"\
	".\..\thotlib\include\presentdriver.h"\
	
NODEP_CPP_GENER=\
	".\..\thotlib\include\HTVMSUtils.h"\
	

"$(INTDIR)\genericdriver.obj" : $(SOURCE) $(DEP_CPP_GENER) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "LibThotEditor - Win32 Debug"

DEP_CPP_GENER=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\include\libmsg.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\include\application.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\internals\var\edit_tv.h"\
	".\..\thotlib\internals\f\changepresent_f.h"\
	".\..\thotlib\include\genericdriver.h"\
	".\..\thotlib\internals\f\memory_f.h"\
	".\..\thotlib\internals\f\presentdriver_f.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\include\fileaccess.h"\
	".\..\thotlib\include\registry.h"\
	".\..\thotlib\include\presentdriver.h"\
	

"$(INTDIR)\genericdriver.obj" : $(SOURCE) $(DEP_CPP_GENER) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\Guetari\Opera\Thotlib\presentation\presentationapi.c

!IF  "$(CFG)" == "LibThotEditor - Win32 Release"

DEP_CPP_PRESEN=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\include\application.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\var\edit_tv.h"\
	".\..\thotlib\internals\f\appli_f.h"\
	".\..\thotlib\internals\f\compilmsg_f.h"\
	".\..\thotlib\internals\f\font_f.h"\
	".\..\thotlib\internals\f\memory_f.h"\
	".\..\thotlib\internals\f\changepresent_f.h"\
	".\..\thotlib\internals\f\boxpositions_f.h"\
	".\..\thotlib\internals\f\viewapi_f.h"\
	".\..\thotlib\include\sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\thotlib\internals\h\constint.h"\
	".\..\thotlib\internals\h\thotkey.h"\
	".\..\thotlib\internals\h\conststr.h"\
	".\..\thotlib\internals\h\constprs.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\include\fileaccess.h"\
	".\..\thotlib\include\registry.h"\
	
NODEP_CPP_PRESEN=\
	".\..\thotlib\include\HTVMSUtils.h"\
	

"$(INTDIR)\presentationapi.obj" : $(SOURCE) $(DEP_CPP_PRESEN) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "LibThotEditor - Win32 Debug"

DEP_CPP_PRESEN=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\include\application.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\var\edit_tv.h"\
	".\..\thotlib\internals\f\appli_f.h"\
	".\..\thotlib\internals\f\compilmsg_f.h"\
	".\..\thotlib\internals\f\font_f.h"\
	".\..\thotlib\internals\f\memory_f.h"\
	".\..\thotlib\internals\f\changepresent_f.h"\
	".\..\thotlib\internals\f\boxpositions_f.h"\
	".\..\thotlib\internals\f\viewapi_f.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\include\fileaccess.h"\
	".\..\thotlib\include\registry.h"\
	

"$(INTDIR)\presentationapi.obj" : $(SOURCE) $(DEP_CPP_PRESEN) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\Guetari\Opera\Thotlib\presentation\presentdriver.c

!IF  "$(CFG)" == "LibThotEditor - Win32 Release"

DEP_CPP_PRESENT=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\internals\h\conststr.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\constprs.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\application.h"\
	".\..\thotlib\include\presentdriver.h"\
	".\..\thotlib\include\sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\thotlib\include\libmsg.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\include\fileaccess.h"\
	".\..\thotlib\include\registry.h"\
	
NODEP_CPP_PRESENT=\
	".\..\thotlib\include\HTVMSUtils.h"\
	

"$(INTDIR)\presentdriver.obj" : $(SOURCE) $(DEP_CPP_PRESENT) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "LibThotEditor - Win32 Debug"

DEP_CPP_PRESENT=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\internals\h\conststr.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\constprs.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\application.h"\
	".\..\thotlib\include\presentdriver.h"\
	".\..\thotlib\include\libmsg.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\include\fileaccess.h"\
	".\..\thotlib\include\registry.h"\
	

"$(INTDIR)\presentdriver.obj" : $(SOURCE) $(DEP_CPP_PRESENT) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\Guetari\Opera\Thotlib\presentation\attrpresent.c

!IF  "$(CFG)" == "LibThotEditor - Win32 Release"

DEP_CPP_ATTRP=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\internals\f\memory_f.h"\
	".\..\thotlib\internals\f\references_f.h"\
	".\..\thotlib\internals\f\tree_f.h"\
	".\..\thotlib\internals\f\attributes_f.h"\
	".\..\thotlib\internals\f\content_f.h"\
	".\..\thotlib\internals\f\presrules_f.h"\
	".\..\thotlib\internals\f\changeabsbox_f.h"\
	".\..\thotlib\include\sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\thotlib\internals\h\constint.h"\
	".\..\thotlib\internals\h\thotkey.h"\
	".\..\thotlib\internals\h\conststr.h"\
	".\..\thotlib\internals\h\constprs.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	
NODEP_CPP_ATTRP=\
	".\..\thotlib\include\HTVMSUtils.h"\
	

"$(INTDIR)\attrpresent.obj" : $(SOURCE) $(DEP_CPP_ATTRP) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "LibThotEditor - Win32 Debug"

DEP_CPP_ATTRP=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\internals\f\memory_f.h"\
	".\..\thotlib\internals\f\references_f.h"\
	".\..\thotlib\internals\f\tree_f.h"\
	".\..\thotlib\internals\f\attributes_f.h"\
	".\..\thotlib\internals\f\content_f.h"\
	".\..\thotlib\internals\f\presrules_f.h"\
	".\..\thotlib\internals\f\changeabsbox_f.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	

"$(INTDIR)\attrpresent.obj" : $(SOURCE) $(DEP_CPP_ATTRP) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\Guetari\Opera\Thotlib\presentation\presvariables.c

!IF  "$(CFG)" == "LibThotEditor - Win32 Release"

DEP_CPP_PRESV=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\include\fileaccess.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\internals\f\tree_f.h"\
	".\..\thotlib\internals\f\memory_f.h"\
	".\..\thotlib\internals\f\changeabsbox_f.h"\
	".\..\thotlib\internals\f\presrules_f.h"\
	".\..\thotlib\internals\f\fileaccess_f.h"\
	".\..\thotlib\internals\f\structschema_f.h"\
	".\..\thotlib\internals\f\content_f.h"\
	".\..\thotlib\internals\f\presvariables_f.h"\
	".\..\thotlib\include\sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\thotlib\internals\h\constint.h"\
	".\..\thotlib\internals\h\thotkey.h"\
	".\..\thotlib\internals\h\conststr.h"\
	".\..\thotlib\internals\h\constprs.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	
NODEP_CPP_PRESV=\
	".\..\thotlib\include\HTVMSUtils.h"\
	

"$(INTDIR)\presvariables.obj" : $(SOURCE) $(DEP_CPP_PRESV) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "LibThotEditor - Win32 Debug"

DEP_CPP_PRESV=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\include\fileaccess.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\internals\f\tree_f.h"\
	".\..\thotlib\internals\f\memory_f.h"\
	".\..\thotlib\internals\f\changeabsbox_f.h"\
	".\..\thotlib\internals\f\presrules_f.h"\
	".\..\thotlib\internals\f\fileaccess_f.h"\
	".\..\thotlib\internals\f\structschema_f.h"\
	".\..\thotlib\internals\f\content_f.h"\
	".\..\thotlib\internals\f\presvariables_f.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	

"$(INTDIR)\presvariables.obj" : $(SOURCE) $(DEP_CPP_PRESV) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\Guetari\Opera\Thotlib\presentation\pschemaapi.c

!IF  "$(CFG)" == "LibThotEditor - Win32 Release"

DEP_CPP_PSCHE=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\include\application.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\internals\var\edit_tv.h"\
	".\..\thotlib\internals\f\memory_f.h"\
	".\..\thotlib\internals\f\schemas_f.h"\
	".\..\thotlib\internals\f\compilmsg_f.h"\
	".\..\thotlib\include\sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\thotlib\internals\h\constint.h"\
	".\..\thotlib\internals\h\thotkey.h"\
	".\..\thotlib\internals\h\conststr.h"\
	".\..\thotlib\internals\h\constprs.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\include\fileaccess.h"\
	".\..\thotlib\include\registry.h"\
	
NODEP_CPP_PSCHE=\
	".\..\thotlib\include\HTVMSUtils.h"\
	

"$(INTDIR)\pschemaapi.obj" : $(SOURCE) $(DEP_CPP_PSCHE) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "LibThotEditor - Win32 Debug"

DEP_CPP_PSCHE=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\include\application.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\internals\var\edit_tv.h"\
	".\..\thotlib\internals\f\memory_f.h"\
	".\..\thotlib\internals\f\schemas_f.h"\
	".\..\thotlib\internals\f\compilmsg_f.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\include\fileaccess.h"\
	".\..\thotlib\include\registry.h"\
	

"$(INTDIR)\pschemaapi.obj" : $(SOURCE) $(DEP_CPP_PSCHE) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\Guetari\Opera\Thotlib\presentation\specificdriver.c

!IF  "$(CFG)" == "LibThotEditor - Win32 Release"

DEP_CPP_SPECI=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\internals\h\constint.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\application.h"\
	".\..\thotlib\internals\var\edit_tv.h"\
	".\..\thotlib\include\specificdriver.h"\
	".\..\thotlib\internals\f\presentationapi_f.h"\
	".\..\thotlib\internals\f\changepresent_f.h"\
	".\..\thotlib\internals\f\memory_f.h"\
	".\..\thotlib\internals\f\presentdriver_f.h"\
	".\..\thotlib\include\sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\thotlib\include\libmsg.h"\
	".\..\thotlib\internals\h\conststr.h"\
	".\..\thotlib\internals\h\constprs.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\thotkey.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\include\fileaccess.h"\
	".\..\thotlib\include\registry.h"\
	".\..\thotlib\include\presentdriver.h"\
	
NODEP_CPP_SPECI=\
	".\..\thotlib\include\HTVMSUtils.h"\
	

"$(INTDIR)\specificdriver.obj" : $(SOURCE) $(DEP_CPP_SPECI) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "LibThotEditor - Win32 Debug"

DEP_CPP_SPECI=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\internals\h\constint.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\application.h"\
	".\..\thotlib\internals\var\edit_tv.h"\
	".\..\thotlib\include\specificdriver.h"\
	".\..\thotlib\internals\f\presentationapi_f.h"\
	".\..\thotlib\internals\f\changepresent_f.h"\
	".\..\thotlib\internals\f\memory_f.h"\
	".\..\thotlib\internals\f\presentdriver_f.h"\
	".\..\thotlib\include\libmsg.h"\
	".\..\thotlib\internals\h\conststr.h"\
	".\..\thotlib\internals\h\constprs.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\include\fileaccess.h"\
	".\..\thotlib\include\registry.h"\
	".\..\thotlib\include\presentdriver.h"\
	

"$(INTDIR)\specificdriver.obj" : $(SOURCE) $(DEP_CPP_SPECI) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\Guetari\Opera\Thotlib\View\boxlocate.c

!IF  "$(CFG)" == "LibThotEditor - Win32 Release"

DEP_CPP_BOXLO=\
	".\..\thotlib\include\libmsg.h"\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\internals\h\appdialogue.h"\
	".\..\thotlib\internals\var\boxes_tv.h"\
	".\..\thotlib\internals\var\frame_tv.h"\
	".\..\thotlib\internals\var\units_tv.h"\
	".\..\thotlib\internals\var\platform_tv.h"\
	".\..\thotlib\internals\var\appdialogue_tv.h"\
	".\..\thotlib\internals\f\appli_f.h"\
	".\..\thotlib\internals\f\boxmoves_f.h"\
	".\..\thotlib\internals\f\boxlocate_f.h"\
	".\..\thotlib\internals\f\views_f.h"\
	".\..\thotlib\internals\f\callback_f.h"\
	".\..\thotlib\internals\f\font_f.h"\
	".\..\thotlib\internals\f\units_f.h"\
	".\..\thotlib\internals\f\geom_f.h"\
	".\..\thotlib\internals\f\absboxes_f.h"\
	".\..\thotlib\internals\f\buildboxes_f.h"\
	".\..\thotlib\internals\f\buildlines_f.h"\
	".\..\thotlib\internals\f\changepresent_f.h"\
	".\..\thotlib\internals\f\boxselection_f.h"\
	".\..\thotlib\internals\f\structcreation_f.h"\
	".\..\thotlib\internals\f\structselect_f.h"\
	".\..\thotlib\internals\f\textcommands_f.h"\
	".\..\thotlib\internals\f\tree_f.h"\
	".\..\thotlib\internals\f\exceptions_f.h"\
	".\..\thotlib\internals\f\applicationapi_f.h"\
	".\..\thotlib\internals\f\frame_f.h"\
	".\..\thotlib\include\sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\thotlib\internals\h\constint.h"\
	".\..\thotlib\internals\h\thotkey.h"\
	".\..\thotlib\internals\h\conststr.h"\
	".\..\thotlib\internals\h\constprs.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\internals\h\frame.h"\
	".\..\thotlib\internals\h\constmenu.h"\
	
NODEP_CPP_BOXLO=\
	".\..\thotlib\include\HTVMSUtils.h"\
	

"$(INTDIR)\boxlocate.obj" : $(SOURCE) $(DEP_CPP_BOXLO) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "LibThotEditor - Win32 Debug"

DEP_CPP_BOXLO=\
	".\..\thotlib\include\libmsg.h"\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\internals\h\appdialogue.h"\
	".\..\thotlib\internals\var\boxes_tv.h"\
	".\..\thotlib\internals\var\frame_tv.h"\
	".\..\thotlib\internals\var\units_tv.h"\
	".\..\thotlib\internals\var\platform_tv.h"\
	".\..\thotlib\internals\var\appdialogue_tv.h"\
	".\..\thotlib\internals\f\appli_f.h"\
	".\..\thotlib\internals\f\boxmoves_f.h"\
	".\..\thotlib\internals\f\boxlocate_f.h"\
	".\..\thotlib\internals\f\views_f.h"\
	".\..\thotlib\internals\f\callback_f.h"\
	".\..\thotlib\internals\f\font_f.h"\
	".\..\thotlib\internals\f\units_f.h"\
	".\..\thotlib\internals\f\geom_f.h"\
	".\..\thotlib\internals\f\absboxes_f.h"\
	".\..\thotlib\internals\f\buildboxes_f.h"\
	".\..\thotlib\internals\f\buildlines_f.h"\
	".\..\thotlib\internals\f\changepresent_f.h"\
	".\..\thotlib\internals\f\boxselection_f.h"\
	".\..\thotlib\internals\f\structcreation_f.h"\
	".\..\thotlib\internals\f\structselect_f.h"\
	".\..\thotlib\internals\f\textcommands_f.h"\
	".\..\thotlib\internals\f\tree_f.h"\
	".\..\thotlib\internals\f\exceptions_f.h"\
	".\..\thotlib\internals\f\applicationapi_f.h"\
	".\..\thotlib\internals\f\frame_f.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\internals\h\frame.h"\
	".\..\thotlib\internals\h\constmenu.h"\
	

"$(INTDIR)\boxlocate.obj" : $(SOURCE) $(DEP_CPP_BOXLO) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\Guetari\Opera\Thotlib\View\Absboxes.c

!IF  "$(CFG)" == "LibThotEditor - Win32 Release"

DEP_CPP_ABSBO=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\internals\h\picture.h"\
	".\..\thotlib\internals\var\page_tv.h"\
	".\..\thotlib\internals\f\tree_f.h"\
	".\..\thotlib\internals\f\createabsbox_f.h"\
	".\..\thotlib\internals\f\createpages_f.h"\
	".\..\thotlib\internals\f\scroll_f.h"\
	".\..\thotlib\internals\f\structlist_f.h"\
	".\..\thotlib\internals\f\views_f.h"\
	".\..\thotlib\internals\f\viewcommands_f.h"\
	".\..\thotlib\internals\f\absboxes_f.h"\
	".\..\thotlib\internals\f\abspictures_f.h"\
	".\..\thotlib\internals\f\buildboxes_f.h"\
	".\..\thotlib\internals\f\memory_f.h"\
	".\..\thotlib\internals\f\changeabsbox_f.h"\
	".\..\thotlib\internals\f\presrules_f.h"\
	".\..\thotlib\internals\f\structselect_f.h"\
	".\..\thotlib\internals\f\content_f.h"\
	".\..\thotlib\include\sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\thotlib\internals\h\constint.h"\
	".\..\thotlib\internals\h\thotkey.h"\
	".\..\thotlib\internals\h\conststr.h"\
	".\..\thotlib\internals\h\constprs.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	
NODEP_CPP_ABSBO=\
	".\..\thotlib\include\HTVMSUtils.h"\
	

"$(INTDIR)\Absboxes.obj" : $(SOURCE) $(DEP_CPP_ABSBO) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "LibThotEditor - Win32 Debug"

DEP_CPP_ABSBO=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\internals\h\picture.h"\
	".\..\thotlib\internals\var\page_tv.h"\
	".\..\thotlib\internals\f\tree_f.h"\
	".\..\thotlib\internals\f\createabsbox_f.h"\
	".\..\thotlib\internals\f\createpages_f.h"\
	".\..\thotlib\internals\f\scroll_f.h"\
	".\..\thotlib\internals\f\structlist_f.h"\
	".\..\thotlib\internals\f\views_f.h"\
	".\..\thotlib\internals\f\viewcommands_f.h"\
	".\..\thotlib\internals\f\absboxes_f.h"\
	".\..\thotlib\internals\f\abspictures_f.h"\
	".\..\thotlib\internals\f\buildboxes_f.h"\
	".\..\thotlib\internals\f\memory_f.h"\
	".\..\thotlib\internals\f\changeabsbox_f.h"\
	".\..\thotlib\internals\f\presrules_f.h"\
	".\..\thotlib\internals\f\structselect_f.h"\
	".\..\thotlib\internals\f\content_f.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	

"$(INTDIR)\Absboxes.obj" : $(SOURCE) $(DEP_CPP_ABSBO) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\Guetari\Opera\Thotlib\View\Boxmoves.c

!IF  "$(CFG)" == "LibThotEditor - Win32 Release"

DEP_CPP_BOXMO=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\internals\var\boxes_tv.h"\
	".\..\thotlib\internals\f\boxmoves_f.h"\
	".\..\thotlib\internals\f\windowdisplay_f.h"\
	".\..\thotlib\internals\f\frame_f.h"\
	".\..\thotlib\internals\f\font_f.h"\
	".\..\thotlib\internals\f\buildboxes_f.h"\
	".\..\thotlib\internals\f\buildlines_f.h"\
	".\..\thotlib\internals\f\memory_f.h"\
	".\..\thotlib\internals\f\boxrelations_f.h"\
	".\..\thotlib\include\sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\thotlib\internals\h\constint.h"\
	".\..\thotlib\internals\h\thotkey.h"\
	".\..\thotlib\internals\h\conststr.h"\
	".\..\thotlib\internals\h\constprs.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	
NODEP_CPP_BOXMO=\
	".\..\thotlib\include\HTVMSUtils.h"\
	

"$(INTDIR)\Boxmoves.obj" : $(SOURCE) $(DEP_CPP_BOXMO) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "LibThotEditor - Win32 Debug"

DEP_CPP_BOXMO=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\internals\var\boxes_tv.h"\
	".\..\thotlib\internals\f\boxmoves_f.h"\
	".\..\thotlib\internals\f\windowdisplay_f.h"\
	".\..\thotlib\internals\f\frame_f.h"\
	".\..\thotlib\internals\f\font_f.h"\
	".\..\thotlib\internals\f\buildboxes_f.h"\
	".\..\thotlib\internals\f\buildlines_f.h"\
	".\..\thotlib\internals\f\memory_f.h"\
	".\..\thotlib\internals\f\boxrelations_f.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	

"$(INTDIR)\Boxmoves.obj" : $(SOURCE) $(DEP_CPP_BOXMO) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\Guetari\Opera\Thotlib\View\boxparams.c

!IF  "$(CFG)" == "LibThotEditor - Win32 Release"

DEP_CPP_BOXPA=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\internals\h\appdialogue.h"\
	".\..\thotlib\internals\var\boxes_tv.h"\
	".\..\thotlib\internals\var\edit_tv.h"\
	".\..\thotlib\internals\var\frame_tv.h"\
	".\..\thotlib\internals\f\applicationapi_f.h"\
	".\..\thotlib\internals\f\buildboxes_f.h"\
	".\..\thotlib\internals\f\textcommands_f.h"\
	".\..\thotlib\internals\f\font_f.h"\
	".\..\thotlib\internals\f\frame_f.h"\
	".\..\thotlib\internals\f\boxselection_f.h"\
	".\..\thotlib\internals\f\boxparams_f.h"\
	".\..\thotlib\include\sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\thotlib\internals\h\constint.h"\
	".\..\thotlib\internals\h\thotkey.h"\
	".\..\thotlib\internals\h\conststr.h"\
	".\..\thotlib\internals\h\constprs.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\internals\h\frame.h"\
	".\..\thotlib\internals\h\constmenu.h"\
	
NODEP_CPP_BOXPA=\
	".\..\thotlib\include\HTVMSUtils.h"\
	

"$(INTDIR)\boxparams.obj" : $(SOURCE) $(DEP_CPP_BOXPA) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "LibThotEditor - Win32 Debug"

DEP_CPP_BOXPA=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\internals\h\appdialogue.h"\
	".\..\thotlib\internals\var\boxes_tv.h"\
	".\..\thotlib\internals\var\edit_tv.h"\
	".\..\thotlib\internals\var\frame_tv.h"\
	".\..\thotlib\internals\f\applicationapi_f.h"\
	".\..\thotlib\internals\f\buildboxes_f.h"\
	".\..\thotlib\internals\f\textcommands_f.h"\
	".\..\thotlib\internals\f\font_f.h"\
	".\..\thotlib\internals\f\frame_f.h"\
	".\..\thotlib\internals\f\boxselection_f.h"\
	".\..\thotlib\internals\f\boxparams_f.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\internals\h\frame.h"\
	".\..\thotlib\internals\h\constmenu.h"\
	

"$(INTDIR)\boxparams.obj" : $(SOURCE) $(DEP_CPP_BOXPA) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\Guetari\Opera\Thotlib\View\boxpositions.c

!IF  "$(CFG)" == "LibThotEditor - Win32 Release"

DEP_CPP_BOXPO=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\include\libmsg.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\internals\var\boxes_tv.h"\
	".\..\thotlib\internals\var\platform_tv.h"\
	".\..\thotlib\internals\f\memory_f.h"\
	".\..\thotlib\internals\f\absboxes_f.h"\
	".\..\thotlib\internals\f\buildboxes_f.h"\
	".\..\thotlib\internals\f\boxmoves_f.h"\
	".\..\thotlib\internals\f\boxrelations_f.h"\
	".\..\thotlib\internals\f\boxpositions_f.h"\
	".\..\thotlib\internals\f\font_f.h"\
	".\..\thotlib\internals\f\units_f.h"\
	".\..\thotlib\include\sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\thotlib\internals\h\constint.h"\
	".\..\thotlib\internals\h\thotkey.h"\
	".\..\thotlib\internals\h\conststr.h"\
	".\..\thotlib\internals\h\constprs.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	
NODEP_CPP_BOXPO=\
	".\..\thotlib\include\HTVMSUtils.h"\
	

"$(INTDIR)\boxpositions.obj" : $(SOURCE) $(DEP_CPP_BOXPO) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "LibThotEditor - Win32 Debug"

DEP_CPP_BOXPO=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\include\libmsg.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\internals\var\boxes_tv.h"\
	".\..\thotlib\internals\var\platform_tv.h"\
	".\..\thotlib\internals\f\memory_f.h"\
	".\..\thotlib\internals\f\absboxes_f.h"\
	".\..\thotlib\internals\f\buildboxes_f.h"\
	".\..\thotlib\internals\f\boxmoves_f.h"\
	".\..\thotlib\internals\f\boxrelations_f.h"\
	".\..\thotlib\internals\f\boxpositions_f.h"\
	".\..\thotlib\internals\f\font_f.h"\
	".\..\thotlib\internals\f\units_f.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	

"$(INTDIR)\boxpositions.obj" : $(SOURCE) $(DEP_CPP_BOXPO) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\Guetari\Opera\Thotlib\View\boxrelations.c

!IF  "$(CFG)" == "LibThotEditor - Win32 Release"

DEP_CPP_BOXRE=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\libmsg.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\internals\h\frame.h"\
	".\..\thotlib\internals\var\boxes_tv.h"\
	".\..\thotlib\internals\f\memory_f.h"\
	".\..\thotlib\internals\f\appli_f.h"\
	".\..\thotlib\internals\f\boxmoves_f.h"\
	".\..\thotlib\internals\f\absboxes_f.h"\
	".\..\thotlib\internals\f\font_f.h"\
	".\..\thotlib\include\sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\internals\h\constint.h"\
	".\..\thotlib\internals\h\thotkey.h"\
	".\..\thotlib\internals\h\conststr.h"\
	".\..\thotlib\internals\h\constprs.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\internals\h\constmenu.h"\
	
NODEP_CPP_BOXRE=\
	".\..\thotlib\include\HTVMSUtils.h"\
	

"$(INTDIR)\boxrelations.obj" : $(SOURCE) $(DEP_CPP_BOXRE) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "LibThotEditor - Win32 Debug"

DEP_CPP_BOXRE=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\libmsg.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\internals\h\frame.h"\
	".\..\thotlib\internals\var\boxes_tv.h"\
	".\..\thotlib\internals\f\memory_f.h"\
	".\..\thotlib\internals\f\appli_f.h"\
	".\..\thotlib\internals\f\boxmoves_f.h"\
	".\..\thotlib\internals\f\absboxes_f.h"\
	".\..\thotlib\internals\f\font_f.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\internals\h\constmenu.h"\
	

"$(INTDIR)\boxrelations.obj" : $(SOURCE) $(DEP_CPP_BOXRE) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\Guetari\Opera\Thotlib\View\boxselection.c

!IF  "$(CFG)" == "LibThotEditor - Win32 Release"

DEP_CPP_BOXSE=\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\internals\h\appdialogue.h"\
	".\..\thotlib\internals\var\creation_tv.h"\
	".\..\thotlib\internals\var\boxes_tv.h"\
	".\..\thotlib\internals\var\frame_tv.h"\
	".\..\thotlib\internals\var\select_tv.h"\
	".\..\thotlib\internals\var\appdialogue_tv.h"\
	".\..\thotlib\internals\f\appli_f.h"\
	".\..\thotlib\internals\f\textcommands_f.h"\
	".\..\thotlib\internals\f\editcommands_f.h"\
	".\..\thotlib\internals\f\structcreation_f.h"\
	".\..\thotlib\internals\f\scroll_f.h"\
	".\..\thotlib\internals\f\boxmoves_f.h"\
	".\..\thotlib\internals\f\boxlocate_f.h"\
	".\..\thotlib\internals\f\font_f.h"\
	".\..\thotlib\internals\f\buildboxes_f.h"\
	".\..\thotlib\internals\f\memory_f.h"\
	".\..\thotlib\internals\f\boxselection_f.h"\
	".\..\thotlib\internals\f\displayselect_f.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\thotlib\internals\h\constint.h"\
	".\..\thotlib\internals\h\thotkey.h"\
	".\..\thotlib\internals\h\conststr.h"\
	".\..\thotlib\internals\h\constprs.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\include\libmsg.h"\
	".\..\thotlib\internals\h\frame.h"\
	".\..\thotlib\internals\h\constmenu.h"\
	
NODEP_CPP_BOXSE=\
	".\..\thotlib\include\HTVMSUtils.h"\
	

"$(INTDIR)\boxselection.obj" : $(SOURCE) $(DEP_CPP_BOXSE) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "LibThotEditor - Win32 Debug"

DEP_CPP_BOXSE=\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\internals\h\appdialogue.h"\
	".\..\thotlib\internals\var\creation_tv.h"\
	".\..\thotlib\internals\var\boxes_tv.h"\
	".\..\thotlib\internals\var\frame_tv.h"\
	".\..\thotlib\internals\var\select_tv.h"\
	".\..\thotlib\internals\var\appdialogue_tv.h"\
	".\..\thotlib\internals\f\appli_f.h"\
	".\..\thotlib\internals\f\textcommands_f.h"\
	".\..\thotlib\internals\f\editcommands_f.h"\
	".\..\thotlib\internals\f\structcreation_f.h"\
	".\..\thotlib\internals\f\scroll_f.h"\
	".\..\thotlib\internals\f\boxmoves_f.h"\
	".\..\thotlib\internals\f\boxlocate_f.h"\
	".\..\thotlib\internals\f\font_f.h"\
	".\..\thotlib\internals\f\buildboxes_f.h"\
	".\..\thotlib\internals\f\memory_f.h"\
	".\..\thotlib\internals\f\boxselection_f.h"\
	".\..\thotlib\internals\f\displayselect_f.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\include\libmsg.h"\
	".\..\thotlib\internals\h\frame.h"\
	".\..\thotlib\internals\h\constmenu.h"\
	

"$(INTDIR)\boxselection.obj" : $(SOURCE) $(DEP_CPP_BOXSE) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\Guetari\Opera\Thotlib\View\buildboxes.c

!IF  "$(CFG)" == "LibThotEditor - Win32 Release"

DEP_CPP_BUILD=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\internals\h\picture.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\libmsg.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\internals\h\appdialogue.h"\
	".\..\thotlib\internals\var\boxes_tv.h"\
	".\..\thotlib\internals\var\font_tv.h"\
	".\..\thotlib\internals\var\edit_tv.h"\
	".\..\thotlib\internals\var\frame_tv.h"\
	".\..\thotlib\internals\f\appli_f.h"\
	".\..\thotlib\internals\f\applicationapi_f.h"\
	".\..\thotlib\internals\f\boxmoves_f.h"\
	".\..\thotlib\internals\f\boxlocate_f.h"\
	".\..\thotlib\internals\f\boxpositions_f.h"\
	".\..\thotlib\internals\f\boxrelations_f.h"\
	".\..\thotlib\internals\f\boxselection_f.h"\
	".\..\thotlib\internals\f\buildlines_f.h"\
	".\..\thotlib\internals\f\displayselect_f.h"\
	".\..\thotlib\internals\f\content_f.h"\
	".\..\thotlib\internals\f\font_f.h"\
	".\..\thotlib\internals\f\units_f.h"\
	".\..\thotlib\internals\f\frame_f.h"\
	".\..\thotlib\internals\f\picture_f.h"\
	".\..\thotlib\internals\f\memory_f.h"\
	".\..\thotlib\internals\f\structselect_f.h"\
	".\..\thotlib\internals\f\textcommands_f.h"\
	".\..\thotlib\include\sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\thotlib\internals\h\constint.h"\
	".\..\thotlib\internals\h\thotkey.h"\
	".\..\thotlib\internals\h\conststr.h"\
	".\..\thotlib\internals\h\constprs.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\internals\h\frame.h"\
	".\..\thotlib\internals\h\constmenu.h"\
	
NODEP_CPP_BUILD=\
	".\..\thotlib\include\HTVMSUtils.h"\
	

"$(INTDIR)\buildboxes.obj" : $(SOURCE) $(DEP_CPP_BUILD) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "LibThotEditor - Win32 Debug"

DEP_CPP_BUILD=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\internals\h\picture.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\libmsg.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\internals\h\appdialogue.h"\
	".\..\thotlib\internals\var\boxes_tv.h"\
	".\..\thotlib\internals\var\font_tv.h"\
	".\..\thotlib\internals\var\edit_tv.h"\
	".\..\thotlib\internals\var\frame_tv.h"\
	".\..\thotlib\internals\f\appli_f.h"\
	".\..\thotlib\internals\f\applicationapi_f.h"\
	".\..\thotlib\internals\f\boxmoves_f.h"\
	".\..\thotlib\internals\f\boxlocate_f.h"\
	".\..\thotlib\internals\f\boxpositions_f.h"\
	".\..\thotlib\internals\f\boxrelations_f.h"\
	".\..\thotlib\internals\f\boxselection_f.h"\
	".\..\thotlib\internals\f\buildlines_f.h"\
	".\..\thotlib\internals\f\displayselect_f.h"\
	".\..\thotlib\internals\f\content_f.h"\
	".\..\thotlib\internals\f\font_f.h"\
	".\..\thotlib\internals\f\units_f.h"\
	".\..\thotlib\internals\f\frame_f.h"\
	".\..\thotlib\internals\f\picture_f.h"\
	".\..\thotlib\internals\f\memory_f.h"\
	".\..\thotlib\internals\f\structselect_f.h"\
	".\..\thotlib\internals\f\textcommands_f.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\internals\h\frame.h"\
	".\..\thotlib\internals\h\constmenu.h"\
	

"$(INTDIR)\buildboxes.obj" : $(SOURCE) $(DEP_CPP_BUILD) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\Guetari\Opera\Thotlib\View\buildlines.c

!IF  "$(CFG)" == "LibThotEditor - Win32 Release"

DEP_CPP_BUILDL=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\internals\var\boxes_tv.h"\
	".\..\thotlib\internals\f\boxmoves_f.h"\
	".\..\thotlib\internals\f\boxlocate_f.h"\
	".\..\thotlib\internals\f\buildboxes_f.h"\
	".\..\thotlib\internals\f\memory_f.h"\
	".\..\thotlib\internals\f\boxselection_f.h"\
	".\..\thotlib\internals\f\buildlines_f.h"\
	".\..\thotlib\internals\f\font_f.h"\
	".\..\thotlib\internals\f\frame_f.h"\
	".\..\thotlib\internals\f\hyphen_f.h"\
	".\..\thotlib\include\sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\thotlib\internals\h\constint.h"\
	".\..\thotlib\internals\h\thotkey.h"\
	".\..\thotlib\internals\h\conststr.h"\
	".\..\thotlib\internals\h\constprs.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	
NODEP_CPP_BUILDL=\
	".\..\thotlib\include\HTVMSUtils.h"\
	

"$(INTDIR)\buildlines.obj" : $(SOURCE) $(DEP_CPP_BUILDL) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "LibThotEditor - Win32 Debug"

DEP_CPP_BUILDL=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\internals\var\boxes_tv.h"\
	".\..\thotlib\internals\f\boxmoves_f.h"\
	".\..\thotlib\internals\f\boxlocate_f.h"\
	".\..\thotlib\internals\f\buildboxes_f.h"\
	".\..\thotlib\internals\f\memory_f.h"\
	".\..\thotlib\internals\f\boxselection_f.h"\
	".\..\thotlib\internals\f\buildlines_f.h"\
	".\..\thotlib\internals\f\font_f.h"\
	".\..\thotlib\internals\f\frame_f.h"\
	".\..\thotlib\internals\f\hyphen_f.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	

"$(INTDIR)\buildlines.obj" : $(SOURCE) $(DEP_CPP_BUILDL) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\Guetari\Opera\Thotlib\View\changeabsbox.c

!IF  "$(CFG)" == "LibThotEditor - Win32 Release"

DEP_CPP_CHANGE=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\include\fileaccess.h"\
	".\..\thotlib\internals\var\platform_tv.h"\
	".\..\thotlib\internals\var\page_tv.h"\
	".\..\thotlib\internals\f\absboxes_f.h"\
	".\..\thotlib\internals\f\attributes_f.h"\
	".\..\thotlib\internals\f\attrpresent_f.h"\
	".\..\thotlib\internals\f\buildboxes_f.h"\
	".\..\thotlib\internals\f\changeabsbox_f.h"\
	".\..\thotlib\internals\f\changepresent_f.h"\
	".\..\thotlib\internals\f\content_f.h"\
	".\..\thotlib\internals\f\createabsbox_f.h"\
	".\..\thotlib\internals\f\createpages_f.h"\
	".\..\thotlib\internals\f\frame_f.h"\
	".\..\thotlib\internals\f\memory_f.h"\
	".\..\thotlib\internals\f\presrules_f.h"\
	".\..\thotlib\internals\f\presvariables_f.h"\
	".\..\thotlib\internals\f\references_f.h"\
	".\..\thotlib\internals\f\search_f.h"\
	".\..\thotlib\internals\f\searchref_f.h"\
	".\..\thotlib\internals\f\structlist_f.h"\
	".\..\thotlib\internals\f\tree_f.h"\
	".\..\thotlib\internals\f\writepivot_f.h"\
	".\..\thotlib\include\sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\thotlib\internals\h\constint.h"\
	".\..\thotlib\internals\h\thotkey.h"\
	".\..\thotlib\internals\h\conststr.h"\
	".\..\thotlib\internals\h\constprs.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	
NODEP_CPP_CHANGE=\
	".\..\thotlib\include\HTVMSUtils.h"\
	

"$(INTDIR)\changeabsbox.obj" : $(SOURCE) $(DEP_CPP_CHANGE) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "LibThotEditor - Win32 Debug"

DEP_CPP_CHANGE=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\include\fileaccess.h"\
	".\..\thotlib\internals\var\platform_tv.h"\
	".\..\thotlib\internals\var\page_tv.h"\
	".\..\thotlib\internals\f\absboxes_f.h"\
	".\..\thotlib\internals\f\attributes_f.h"\
	".\..\thotlib\internals\f\attrpresent_f.h"\
	".\..\thotlib\internals\f\buildboxes_f.h"\
	".\..\thotlib\internals\f\changeabsbox_f.h"\
	".\..\thotlib\internals\f\changepresent_f.h"\
	".\..\thotlib\internals\f\content_f.h"\
	".\..\thotlib\internals\f\createabsbox_f.h"\
	".\..\thotlib\internals\f\createpages_f.h"\
	".\..\thotlib\internals\f\frame_f.h"\
	".\..\thotlib\internals\f\memory_f.h"\
	".\..\thotlib\internals\f\presrules_f.h"\
	".\..\thotlib\internals\f\presvariables_f.h"\
	".\..\thotlib\internals\f\references_f.h"\
	".\..\thotlib\internals\f\search_f.h"\
	".\..\thotlib\internals\f\searchref_f.h"\
	".\..\thotlib\internals\f\structlist_f.h"\
	".\..\thotlib\internals\f\tree_f.h"\
	".\..\thotlib\internals\f\writepivot_f.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	

"$(INTDIR)\changeabsbox.obj" : $(SOURCE) $(DEP_CPP_CHANGE) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\Guetari\Opera\Thotlib\View\createabsbox.c

!IF  "$(CFG)" == "LibThotEditor - Win32 Release"

DEP_CPP_CREATE=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\internals\h\picture.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\internals\h\appdialogue.h"\
	".\..\thotlib\internals\var\page_tv.h"\
	".\..\thotlib\internals\var\platform_tv.h"\
	".\..\thotlib\internals\var\edit_tv.h"\
	".\..\thotlib\internals\var\appdialogue_tv.h"\
	".\..\thotlib\internals\f\tree_f.h"\
	".\..\thotlib\internals\f\attrpresent_f.h"\
	".\..\thotlib\internals\f\attributes_f.h"\
	".\..\thotlib\internals\f\createabsbox_f.h"\
	".\..\thotlib\internals\f\createpages_f.h"\
	".\..\thotlib\internals\f\exceptions_f.h"\
	".\..\thotlib\internals\f\absboxes_f.h"\
	".\..\thotlib\internals\f\abspictures_f.h"\
	".\..\thotlib\internals\f\memory_f.h"\
	".\..\thotlib\internals\f\structmodif_f.h"\
	".\..\thotlib\internals\f\changeabsbox_f.h"\
	".\..\thotlib\internals\f\presrules_f.h"\
	".\..\thotlib\internals\f\references_f.h"\
	".\..\thotlib\internals\f\schemas_f.h"\
	".\..\thotlib\internals\f\boxselection_f.h"\
	".\..\thotlib\internals\f\content_f.h"\
	".\..\thotlib\internals\f\presvariables_f.h"\
	".\..\thotlib\include\sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\thotlib\internals\h\constint.h"\
	".\..\thotlib\internals\h\thotkey.h"\
	".\..\thotlib\internals\h\conststr.h"\
	".\..\thotlib\internals\h\constprs.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\include\libmsg.h"\
	".\..\thotlib\internals\h\frame.h"\
	".\..\thotlib\internals\h\constmenu.h"\
	
NODEP_CPP_CREATE=\
	".\..\thotlib\include\HTVMSUtils.h"\
	

"$(INTDIR)\createabsbox.obj" : $(SOURCE) $(DEP_CPP_CREATE) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "LibThotEditor - Win32 Debug"

DEP_CPP_CREATE=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\internals\h\picture.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\internals\h\appdialogue.h"\
	".\..\thotlib\internals\var\page_tv.h"\
	".\..\thotlib\internals\var\platform_tv.h"\
	".\..\thotlib\internals\var\edit_tv.h"\
	".\..\thotlib\internals\var\appdialogue_tv.h"\
	".\..\thotlib\internals\f\tree_f.h"\
	".\..\thotlib\internals\f\attrpresent_f.h"\
	".\..\thotlib\internals\f\attributes_f.h"\
	".\..\thotlib\internals\f\createabsbox_f.h"\
	".\..\thotlib\internals\f\createpages_f.h"\
	".\..\thotlib\internals\f\exceptions_f.h"\
	".\..\thotlib\internals\f\absboxes_f.h"\
	".\..\thotlib\internals\f\abspictures_f.h"\
	".\..\thotlib\internals\f\memory_f.h"\
	".\..\thotlib\internals\f\structmodif_f.h"\
	".\..\thotlib\internals\f\changeabsbox_f.h"\
	".\..\thotlib\internals\f\presrules_f.h"\
	".\..\thotlib\internals\f\references_f.h"\
	".\..\thotlib\internals\f\schemas_f.h"\
	".\..\thotlib\internals\f\boxselection_f.h"\
	".\..\thotlib\internals\f\content_f.h"\
	".\..\thotlib\internals\f\presvariables_f.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\include\libmsg.h"\
	".\..\thotlib\internals\h\frame.h"\
	".\..\thotlib\internals\h\constmenu.h"\
	

"$(INTDIR)\createabsbox.obj" : $(SOURCE) $(DEP_CPP_CREATE) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\Guetari\Opera\Thotlib\View\createpages.c

!IF  "$(CFG)" == "LibThotEditor - Win32 Release"

DEP_CPP_CREATEP=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\internals\var\page_tv.h"\
	".\..\thotlib\internals\var\platform_tv.h"\
	".\..\thotlib\internals\var\edit_tv.h"\
	".\..\thotlib\internals\f\tree_f.h"\
	".\..\thotlib\internals\f\attributes_f.h"\
	".\..\thotlib\internals\f\attrpresent_f.h"\
	".\..\thotlib\internals\f\createabsbox_f.h"\
	".\..\thotlib\internals\f\createpages_f.h"\
	".\..\thotlib\internals\f\structlist_f.h"\
	".\..\thotlib\internals\f\thotmsg_f.h"\
	".\..\thotlib\internals\f\absboxes_f.h"\
	".\..\thotlib\internals\f\abspictures_f.h"\
	".\..\thotlib\internals\f\buildboxes_f.h"\
	".\..\thotlib\internals\f\memory_f.h"\
	".\..\thotlib\internals\f\structmodif_f.h"\
	".\..\thotlib\internals\f\changeabsbox_f.h"\
	".\..\thotlib\internals\f\presrules_f.h"\
	".\..\thotlib\internals\f\boxpositions_f.h"\
	".\..\thotlib\internals\f\schemas_f.h"\
	".\..\thotlib\internals\f\presvariables_f.h"\
	".\..\thotlib\include\sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\thotlib\internals\h\constint.h"\
	".\..\thotlib\internals\h\thotkey.h"\
	".\..\thotlib\internals\h\conststr.h"\
	".\..\thotlib\internals\h\constprs.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\include\libmsg.h"\
	
NODEP_CPP_CREATEP=\
	".\..\thotlib\include\HTVMSUtils.h"\
	

"$(INTDIR)\createpages.obj" : $(SOURCE) $(DEP_CPP_CREATEP) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "LibThotEditor - Win32 Debug"

DEP_CPP_CREATEP=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\internals\var\page_tv.h"\
	".\..\thotlib\internals\var\platform_tv.h"\
	".\..\thotlib\internals\var\edit_tv.h"\
	".\..\thotlib\internals\f\tree_f.h"\
	".\..\thotlib\internals\f\attributes_f.h"\
	".\..\thotlib\internals\f\attrpresent_f.h"\
	".\..\thotlib\internals\f\createabsbox_f.h"\
	".\..\thotlib\internals\f\createpages_f.h"\
	".\..\thotlib\internals\f\structlist_f.h"\
	".\..\thotlib\internals\f\thotmsg_f.h"\
	".\..\thotlib\internals\f\absboxes_f.h"\
	".\..\thotlib\internals\f\abspictures_f.h"\
	".\..\thotlib\internals\f\buildboxes_f.h"\
	".\..\thotlib\internals\f\memory_f.h"\
	".\..\thotlib\internals\f\structmodif_f.h"\
	".\..\thotlib\internals\f\changeabsbox_f.h"\
	".\..\thotlib\internals\f\presrules_f.h"\
	".\..\thotlib\internals\f\boxpositions_f.h"\
	".\..\thotlib\internals\f\schemas_f.h"\
	".\..\thotlib\internals\f\presvariables_f.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\include\libmsg.h"\
	

"$(INTDIR)\createpages.obj" : $(SOURCE) $(DEP_CPP_CREATEP) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\Guetari\Opera\Thotlib\View\displayselect.c

!IF  "$(CFG)" == "LibThotEditor - Win32 Release"

DEP_CPP_DISPL=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\internals\var\boxes_tv.h"\
	".\..\thotlib\internals\var\platform_tv.h"\
	".\..\thotlib\internals\var\select_tv.h"\
	".\..\thotlib\internals\var\edit_tv.h"\
	".\..\thotlib\internals\f\windowdisplay_f.h"\
	".\..\thotlib\internals\f\displayselect_f.h"\
	".\..\thotlib\internals\f\font_f.h"\
	".\..\thotlib\internals\f\units_f.h"\
	".\..\thotlib\internals\f\exceptions_f.h"\
	".\..\thotlib\include\sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\thotlib\internals\h\constint.h"\
	".\..\thotlib\internals\h\thotkey.h"\
	".\..\thotlib\internals\h\conststr.h"\
	".\..\thotlib\internals\h\constprs.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	
NODEP_CPP_DISPL=\
	".\..\thotlib\include\HTVMSUtils.h"\
	

"$(INTDIR)\displayselect.obj" : $(SOURCE) $(DEP_CPP_DISPL) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "LibThotEditor - Win32 Debug"

DEP_CPP_DISPL=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\internals\var\boxes_tv.h"\
	".\..\thotlib\internals\var\platform_tv.h"\
	".\..\thotlib\internals\var\select_tv.h"\
	".\..\thotlib\internals\var\edit_tv.h"\
	".\..\thotlib\internals\f\windowdisplay_f.h"\
	".\..\thotlib\internals\f\displayselect_f.h"\
	".\..\thotlib\internals\f\font_f.h"\
	".\..\thotlib\internals\f\units_f.h"\
	".\..\thotlib\internals\f\exceptions_f.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	

"$(INTDIR)\displayselect.obj" : $(SOURCE) $(DEP_CPP_DISPL) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\Guetari\Opera\Thotlib\View\Frame.c

!IF  "$(CFG)" == "LibThotEditor - Win32 Release"

DEP_CPP_FRAME=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\internals\h\picture.h"\
	".\..\thotlib\include\libmsg.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\internals\var\boxes_tv.h"\
	".\..\thotlib\internals\var\platform_tv.h"\
	".\..\thotlib\internals\f\absboxes_f.h"\
	".\..\thotlib\internals\f\appli_f.h"\
	".\..\thotlib\internals\f\boxlocate_f.h"\
	".\..\thotlib\internals\f\boxmoves_f.h"\
	".\..\thotlib\internals\f\displayselect_f.h"\
	".\..\thotlib\internals\f\font_f.h"\
	".\..\thotlib\internals\f\frame_f.h"\
	".\..\thotlib\internals\f\picture_f.h"\
	".\..\thotlib\internals\f\windowdisplay_f.h"\
	".\..\thotlib\include\sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\thotlib\internals\h\constint.h"\
	".\..\thotlib\internals\h\thotkey.h"\
	".\..\thotlib\internals\h\conststr.h"\
	".\..\thotlib\internals\h\constprs.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	
NODEP_CPP_FRAME=\
	".\..\thotlib\include\HTVMSUtils.h"\
	

"$(INTDIR)\Frame.obj" : $(SOURCE) $(DEP_CPP_FRAME) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "LibThotEditor - Win32 Debug"

DEP_CPP_FRAME=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\internals\h\picture.h"\
	".\..\thotlib\include\libmsg.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\internals\var\boxes_tv.h"\
	".\..\thotlib\internals\var\platform_tv.h"\
	".\..\thotlib\internals\f\absboxes_f.h"\
	".\..\thotlib\internals\f\appli_f.h"\
	".\..\thotlib\internals\f\boxlocate_f.h"\
	".\..\thotlib\internals\f\boxmoves_f.h"\
	".\..\thotlib\internals\f\displayselect_f.h"\
	".\..\thotlib\internals\f\font_f.h"\
	".\..\thotlib\internals\f\frame_f.h"\
	".\..\thotlib\internals\f\picture_f.h"\
	".\..\thotlib\internals\f\windowdisplay_f.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	

"$(INTDIR)\Frame.obj" : $(SOURCE) $(DEP_CPP_FRAME) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\Guetari\Opera\Thotlib\View\Hyphen.c

!IF  "$(CFG)" == "LibThotEditor - Win32 Release"

DEP_CPP_HYPHE=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\internals\h\dictionary.h"\
	".\..\thotlib\internals\var\boxes_tv.h"\
	".\..\thotlib\internals\f\font_f.h"\
	".\..\thotlib\include\sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\thotlib\internals\h\constint.h"\
	".\..\thotlib\internals\h\thotkey.h"\
	".\..\thotlib\internals\h\conststr.h"\
	".\..\thotlib\internals\h\constprs.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	
NODEP_CPP_HYPHE=\
	".\..\thotlib\include\HTVMSUtils.h"\
	

"$(INTDIR)\Hyphen.obj" : $(SOURCE) $(DEP_CPP_HYPHE) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "LibThotEditor - Win32 Debug"

DEP_CPP_HYPHE=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\internals\h\dictionary.h"\
	".\..\thotlib\internals\var\boxes_tv.h"\
	".\..\thotlib\internals\f\font_f.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	

"$(INTDIR)\Hyphen.obj" : $(SOURCE) $(DEP_CPP_HYPHE) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\Guetari\Opera\Thotlib\View\Inites.c

!IF  "$(CFG)" == "LibThotEditor - Win32 Release"

DEP_CPP_INITE=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\constmenu.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\internals\h\frame.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\internals\h\pattern.h"\
	".\..\thotlib\internals\var\frame_tv.h"\
	".\..\thotlib\internals\var\thotcolor_tv.h"\
	".\..\thotlib\internals\f\registry_f.h"\
	".\..\thotlib\internals\f\context_f.h"\
	".\..\thotlib\include\sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\thotlib\internals\h\constint.h"\
	".\..\thotlib\internals\h\thotkey.h"\
	".\..\thotlib\internals\h\conststr.h"\
	".\..\thotlib\internals\h\constprs.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\include\libmsg.h"\
	".\..\thotlib\internals\h\thotcolor.h"\
	
NODEP_CPP_INITE=\
	".\..\thotlib\include\HTVMSUtils.h"\
	

"$(INTDIR)\Inites.obj" : $(SOURCE) $(DEP_CPP_INITE) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "LibThotEditor - Win32 Debug"

DEP_CPP_INITE=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\constmenu.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\internals\h\frame.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\internals\h\pattern.h"\
	".\..\thotlib\internals\var\frame_tv.h"\
	".\..\thotlib\internals\var\thotcolor_tv.h"\
	".\..\thotlib\internals\f\registry_f.h"\
	".\..\thotlib\internals\f\context_f.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\include\libmsg.h"\
	".\..\thotlib\internals\h\thotcolor.h"\
	

"$(INTDIR)\Inites.obj" : $(SOURCE) $(DEP_CPP_INITE) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\Guetari\Opera\Thotlib\View\structlocate.c

!IF  "$(CFG)" == "LibThotEditor - Win32 Release"

DEP_CPP_STRUCTL=\
	".\..\thotlib\include\libmsg.h"\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\internals\h\appdialogue.h"\
	".\..\thotlib\internals\var\boxes_tv.h"\
	".\..\thotlib\internals\var\frame_tv.h"\
	".\..\thotlib\internals\var\platform_tv.h"\
	".\..\thotlib\internals\var\appdialogue_tv.h"\
	".\..\thotlib\internals\f\appli_f.h"\
	".\..\thotlib\internals\f\structcreation_f.h"\
	".\..\thotlib\internals\f\boxmoves_f.h"\
	".\..\thotlib\internals\f\boxlocate_f.h"\
	".\..\thotlib\internals\f\views_f.h"\
	".\..\thotlib\internals\f\callback_f.h"\
	".\..\thotlib\internals\f\font_f.h"\
	".\..\thotlib\internals\f\geom_f.h"\
	".\..\thotlib\internals\f\absboxes_f.h"\
	".\..\thotlib\internals\f\buildboxes_f.h"\
	".\..\thotlib\internals\f\buildlines_f.h"\
	".\..\thotlib\internals\f\changepresent_f.h"\
	".\..\thotlib\internals\f\boxselection_f.h"\
	".\..\thotlib\include\sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\thotlib\internals\h\constint.h"\
	".\..\thotlib\internals\h\thotkey.h"\
	".\..\thotlib\internals\h\conststr.h"\
	".\..\thotlib\internals\h\constprs.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\internals\h\frame.h"\
	".\..\thotlib\internals\h\constmenu.h"\
	
NODEP_CPP_STRUCTL=\
	".\..\thotlib\include\HTVMSUtils.h"\
	

"$(INTDIR)\structlocate.obj" : $(SOURCE) $(DEP_CPP_STRUCTL) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "LibThotEditor - Win32 Debug"

DEP_CPP_STRUCTL=\
	".\..\thotlib\include\libmsg.h"\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\internals\h\appdialogue.h"\
	".\..\thotlib\internals\var\boxes_tv.h"\
	".\..\thotlib\internals\var\frame_tv.h"\
	".\..\thotlib\internals\var\platform_tv.h"\
	".\..\thotlib\internals\var\appdialogue_tv.h"\
	".\..\thotlib\internals\f\appli_f.h"\
	".\..\thotlib\internals\f\structcreation_f.h"\
	".\..\thotlib\internals\f\boxmoves_f.h"\
	".\..\thotlib\internals\f\boxlocate_f.h"\
	".\..\thotlib\internals\f\views_f.h"\
	".\..\thotlib\internals\f\callback_f.h"\
	".\..\thotlib\internals\f\font_f.h"\
	".\..\thotlib\internals\f\geom_f.h"\
	".\..\thotlib\internals\f\absboxes_f.h"\
	".\..\thotlib\internals\f\buildboxes_f.h"\
	".\..\thotlib\internals\f\buildlines_f.h"\
	".\..\thotlib\internals\f\changepresent_f.h"\
	".\..\thotlib\internals\f\boxselection_f.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\internals\h\frame.h"\
	".\..\thotlib\internals\h\constmenu.h"\
	

"$(INTDIR)\structlocate.obj" : $(SOURCE) $(DEP_CPP_STRUCTL) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\Guetari\Opera\Thotlib\View\unstructlocate.c

!IF  "$(CFG)" == "LibThotEditor - Win32 Release"

DEP_CPP_UNSTRU=\
	".\..\thotlib\include\libmsg.h"\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\internals\h\appdialogue.h"\
	".\..\thotlib\internals\var\boxes_tv.h"\
	".\..\thotlib\internals\var\frame_tv.h"\
	".\..\thotlib\internals\var\platform_tv.h"\
	".\..\thotlib\internals\var\appdialogue_tv.h"\
	".\..\thotlib\internals\f\appli_f.h"\
	".\..\thotlib\internals\f\structcreation_f.h"\
	".\..\thotlib\internals\f\boxmoves_f.h"\
	".\..\thotlib\internals\f\boxlocate_f.h"\
	".\..\thotlib\internals\f\views_f.h"\
	".\..\thotlib\internals\f\callback_f.h"\
	".\..\thotlib\internals\f\font_f.h"\
	".\..\thotlib\internals\f\geom_f.h"\
	".\..\thotlib\internals\f\absboxes_f.h"\
	".\..\thotlib\internals\f\buildboxes_f.h"\
	".\..\thotlib\internals\f\buildlines_f.h"\
	".\..\thotlib\internals\f\changepresent_f.h"\
	".\..\thotlib\internals\f\boxselection_f.h"\
	".\..\thotlib\include\sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\thotlib\internals\h\constint.h"\
	".\..\thotlib\internals\h\thotkey.h"\
	".\..\thotlib\internals\h\conststr.h"\
	".\..\thotlib\internals\h\constprs.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\internals\h\frame.h"\
	".\..\thotlib\internals\h\constmenu.h"\
	
NODEP_CPP_UNSTRU=\
	".\..\thotlib\include\HTVMSUtils.h"\
	

"$(INTDIR)\unstructlocate.obj" : $(SOURCE) $(DEP_CPP_UNSTRU) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "LibThotEditor - Win32 Debug"

DEP_CPP_UNSTRU=\
	".\..\thotlib\include\libmsg.h"\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\include\message.h"\
	".\..\thotlib\internals\h\appdialogue.h"\
	".\..\thotlib\internals\var\boxes_tv.h"\
	".\..\thotlib\internals\var\frame_tv.h"\
	".\..\thotlib\internals\var\platform_tv.h"\
	".\..\thotlib\internals\var\appdialogue_tv.h"\
	".\..\thotlib\internals\f\appli_f.h"\
	".\..\thotlib\internals\f\structcreation_f.h"\
	".\..\thotlib\internals\f\boxmoves_f.h"\
	".\..\thotlib\internals\f\boxlocate_f.h"\
	".\..\thotlib\internals\f\views_f.h"\
	".\..\thotlib\internals\f\callback_f.h"\
	".\..\thotlib\internals\f\font_f.h"\
	".\..\thotlib\internals\f\geom_f.h"\
	".\..\thotlib\internals\f\absboxes_f.h"\
	".\..\thotlib\internals\f\buildboxes_f.h"\
	".\..\thotlib\internals\f\buildlines_f.h"\
	".\..\thotlib\internals\f\changepresent_f.h"\
	".\..\thotlib\internals\f\boxselection_f.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\internals\h\frame.h"\
	".\..\thotlib\internals\h\constmenu.h"\
	

"$(INTDIR)\unstructlocate.obj" : $(SOURCE) $(DEP_CPP_UNSTRU) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\Guetari\Opera\Thotlib\View\Viewapi.c

!IF  "$(CFG)" == "LibThotEditor - Win32 Release"

DEP_CPP_VIEWA=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\include\fileaccess.h"\
	".\..\thotlib\include\application.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\selection.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\thotcolor.h"\
	".\..\thotlib\internals\h\appdialogue.h"\
	".\..\thotlib\internals\var\platform_tv.h"\
	".\..\thotlib\internals\var\page_tv.h"\
	".\..\thotlib\internals\var\select_tv.h"\
	".\..\thotlib\internals\var\frame_tv.h"\
	".\..\thotlib\internals\var\edit_tv.h"\
	".\..\thotlib\internals\var\boxes_tv.h"\
	".\..\thotlib\internals\var\thotcolor_tv.h"\
	".\..\thotlib\internals\var\appdialogue_tv.h"\
	".\..\thotlib\internals\f\appli_f.h"\
	".\..\thotlib\internals\f\tree_f.h"\
	".\..\thotlib\internals\f\attrpresent_f.h"\
	".\..\thotlib\internals\f\attributes_f.h"\
	".\..\thotlib\internals\f\context_f.h"\
	".\..\thotlib\internals\f\structcreation_f.h"\
	".\..\thotlib\internals\f\createabsbox_f.h"\
	".\..\thotlib\internals\f\scroll_f.h"\
	".\..\thotlib\internals\f\views_f.h"\
	".\..\thotlib\internals\f\viewapi_f.h"\
	".\..\thotlib\internals\f\absboxes_f.h"\
	".\..\thotlib\internals\f\appdialogue_f.h"\
	".\..\thotlib\internals\f\applicationapi_f.h"\
	".\..\thotlib\internals\f\boxlocate_f.h"\
	".\..\thotlib\internals\f\boxparams_f.h"\
	".\..\thotlib\internals\f\boxselection_f.h"\
	".\..\thotlib\internals\f\buildboxes_f.h"\
	".\..\thotlib\internals\f\changeabsbox_f.h"\
	".\..\thotlib\internals\f\changepresent_f.h"\
	".\..\thotlib\internals\f\fileaccess_f.h"\
	".\..\thotlib\internals\f\frame_f.h"\
	".\..\thotlib\internals\f\inites_f.h"\
	".\..\thotlib\internals\f\paginate_f.h"\
	".\..\thotlib\internals\f\presrules_f.h"\
	".\..\thotlib\internals\f\structschema_f.h"\
	".\..\thotlib\internals\f\structselect_f.h"\
	".\..\thotlib\internals\f\schemas_f.h"\
	".\..\thotlib\internals\f\structmodif_f.h"\
	".\..\thotlib\internals\f\thotmsg_f.h"\
	".\..\thotlib\include\sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\thotlib\internals\h\constint.h"\
	".\..\thotlib\internals\h\thotkey.h"\
	".\..\thotlib\internals\h\conststr.h"\
	".\..\thotlib\internals\h\constprs.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\include\registry.h"\
	".\..\thotlib\internals\h\frame.h"\
	".\..\thotlib\internals\h\constmenu.h"\
	
NODEP_CPP_VIEWA=\
	".\..\thotlib\include\HTVMSUtils.h"\
	

"$(INTDIR)\Viewapi.obj" : $(SOURCE) $(DEP_CPP_VIEWA) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "LibThotEditor - Win32 Debug"

DEP_CPP_VIEWA=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\include\fileaccess.h"\
	".\..\thotlib\include\application.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\selection.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\thotcolor.h"\
	".\..\thotlib\internals\h\appdialogue.h"\
	".\..\thotlib\internals\var\platform_tv.h"\
	".\..\thotlib\internals\var\page_tv.h"\
	".\..\thotlib\internals\var\select_tv.h"\
	".\..\thotlib\internals\var\frame_tv.h"\
	".\..\thotlib\internals\var\edit_tv.h"\
	".\..\thotlib\internals\var\boxes_tv.h"\
	".\..\thotlib\internals\var\thotcolor_tv.h"\
	".\..\thotlib\internals\var\appdialogue_tv.h"\
	".\..\thotlib\internals\f\appli_f.h"\
	".\..\thotlib\internals\f\tree_f.h"\
	".\..\thotlib\internals\f\attrpresent_f.h"\
	".\..\thotlib\internals\f\attributes_f.h"\
	".\..\thotlib\internals\f\context_f.h"\
	".\..\thotlib\internals\f\structcreation_f.h"\
	".\..\thotlib\internals\f\createabsbox_f.h"\
	".\..\thotlib\internals\f\scroll_f.h"\
	".\..\thotlib\internals\f\views_f.h"\
	".\..\thotlib\internals\f\viewapi_f.h"\
	".\..\thotlib\internals\f\absboxes_f.h"\
	".\..\thotlib\internals\f\appdialogue_f.h"\
	".\..\thotlib\internals\f\applicationapi_f.h"\
	".\..\thotlib\internals\f\boxlocate_f.h"\
	".\..\thotlib\internals\f\boxparams_f.h"\
	".\..\thotlib\internals\f\boxselection_f.h"\
	".\..\thotlib\internals\f\buildboxes_f.h"\
	".\..\thotlib\internals\f\changeabsbox_f.h"\
	".\..\thotlib\internals\f\changepresent_f.h"\
	".\..\thotlib\internals\f\fileaccess_f.h"\
	".\..\thotlib\internals\f\frame_f.h"\
	".\..\thotlib\internals\f\inites_f.h"\
	".\..\thotlib\internals\f\paginate_f.h"\
	".\..\thotlib\internals\f\presrules_f.h"\
	".\..\thotlib\internals\f\structschema_f.h"\
	".\..\thotlib\internals\f\structselect_f.h"\
	".\..\thotlib\internals\f\schemas_f.h"\
	".\..\thotlib\internals\f\structmodif_f.h"\
	".\..\thotlib\internals\f\thotmsg_f.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\include\registry.h"\
	".\..\thotlib\internals\h\frame.h"\
	".\..\thotlib\internals\h\constmenu.h"\
	

"$(INTDIR)\Viewapi.obj" : $(SOURCE) $(DEP_CPP_VIEWA) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\Guetari\Opera\Thotlib\View\windowdisplay.c

!IF  "$(CFG)" == "LibThotEditor - Win32 Release"

DEP_CPP_WINDO=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\internals\h\frame.h"\
	".\..\thotlib\internals\var\font_tv.h"\
	".\..\thotlib\internals\var\frame_tv.h"\
	".\..\thotlib\internals\var\units_tv.h"\
	".\..\thotlib\internals\var\edit_tv.h"\
	".\..\thotlib\internals\var\thotcolor_tv.h"\
	".\..\thotlib\internals\f\font_f.h"\
	".\..\thotlib\internals\f\units_f.h"\
	".\..\thotlib\internals\f\context_f.h"\
	".\..\thotlib\internals\f\memory_f.h"\
	".\..\thotlib\internals\f\inites_f.h"\
	".\..\thotlib\internals\f\buildlines_f.h"\
	".\..\thotlib\include\sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\thotlib\internals\h\constint.h"\
	".\..\thotlib\internals\h\thotkey.h"\
	".\..\thotlib\internals\h\conststr.h"\
	".\..\thotlib\internals\h\constprs.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\internals\h\constmenu.h"\
	".\..\thotlib\internals\h\thotcolor.h"\
	
NODEP_CPP_WINDO=\
	".\..\thotlib\include\HTVMSUtils.h"\
	

"$(INTDIR)\windowdisplay.obj" : $(SOURCE) $(DEP_CPP_WINDO) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "LibThotEditor - Win32 Debug"

DEP_CPP_WINDO=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\internals\h\frame.h"\
	".\..\thotlib\internals\var\font_tv.h"\
	".\..\thotlib\internals\var\frame_tv.h"\
	".\..\thotlib\internals\var\units_tv.h"\
	".\..\thotlib\internals\var\edit_tv.h"\
	".\..\thotlib\internals\var\thotcolor_tv.h"\
	".\..\thotlib\internals\f\font_f.h"\
	".\..\thotlib\internals\f\units_f.h"\
	".\..\thotlib\internals\f\context_f.h"\
	".\..\thotlib\internals\f\memory_f.h"\
	".\..\thotlib\internals\f\inites_f.h"\
	".\..\thotlib\internals\f\buildlines_f.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\internals\h\constmenu.h"\
	".\..\thotlib\internals\h\thotcolor.h"\
	

"$(INTDIR)\windowdisplay.obj" : $(SOURCE) $(DEP_CPP_WINDO) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\Guetari\Opera\Thotlib\View\displaybox.c

!IF  "$(CFG)" == "LibThotEditor - Win32 Release"

DEP_CPP_DISPLA=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\internals\h\picture.h"\
	".\..\thotlib\internals\h\appdialogue.h"\
	".\..\thotlib\internals\var\boxes_tv.h"\
	".\..\thotlib\internals\var\edit_tv.h"\
	".\..\thotlib\internals\var\frame_tv.h"\
	".\..\thotlib\internals\var\appdialogue_tv.h"\
	".\..\thotlib\internals\f\font_f.h"\
	".\..\thotlib\internals\f\units_f.h"\
	".\..\thotlib\internals\f\displaybox_f.h"\
	".\..\thotlib\internals\f\picture_f.h"\
	".\..\thotlib\internals\f\buildboxes_f.h"\
	".\..\thotlib\internals\f\windowdisplay_f.h"\
	".\..\thotlib\include\sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\thotlib\internals\h\constint.h"\
	".\..\thotlib\internals\h\thotkey.h"\
	".\..\thotlib\internals\h\conststr.h"\
	".\..\thotlib\internals\h\constprs.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\internals\h\frame.h"\
	".\..\thotlib\internals\h\constmenu.h"\
	
NODEP_CPP_DISPLA=\
	".\..\thotlib\include\HTVMSUtils.h"\
	

"$(INTDIR)\displaybox.obj" : $(SOURCE) $(DEP_CPP_DISPLA) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "LibThotEditor - Win32 Debug"

DEP_CPP_DISPLA=\
	".\..\thotlib\include\thot_sys.h"\
	".\..\thotlib\internals\h\constmedia.h"\
	".\..\thotlib\internals\h\typemedia.h"\
	".\..\thotlib\internals\h\picture.h"\
	".\..\thotlib\internals\h\appdialogue.h"\
	".\..\thotlib\internals\var\boxes_tv.h"\
	".\..\thotlib\internals\var\edit_tv.h"\
	".\..\thotlib\internals\var\frame_tv.h"\
	".\..\thotlib\internals\var\appdialogue_tv.h"\
	".\..\thotlib\internals\f\font_f.h"\
	".\..\thotlib\internals\f\units_f.h"\
	".\..\thotlib\internals\f\displaybox_f.h"\
	".\..\thotlib\internals\f\picture_f.h"\
	".\..\thotlib\internals\f\buildboxes_f.h"\
	".\..\thotlib\internals\f\windowdisplay_f.h"\
	".\..\thotlib\internals\h\typeint.h"\
	".\..\thotlib\internals\h\typecorr.h"\
	".\..\thotlib\internals\h\typetra.h"\
	".\..\thotlib\internals\h\typestr.h"\
	".\..\thotlib\internals\h\typeprs.h"\
	".\..\thotlib\include\language.h"\
	".\..\thotlib\include\app.h"\
	".\..\thotlib\include\interface.h"\
	".\..\thotlib\include\appaction.h"\
	".\..\thotlib\include\thot_gui.h"\
	".\..\thotlib\include\view.h"\
	".\..\thotlib\include\typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\thotlib\include\document.h"\
	".\..\thotlib\include\pschema.h"\
	".\..\thotlib\include\attribute.h"\
	".\..\thotlib\include\presentation.h"\
	".\..\thotlib\internals\h\consttra.h"\
	".\..\thotlib\internals\h\frame.h"\
	".\..\thotlib\internals\h\constmenu.h"\
	

"$(INTDIR)\displaybox.obj" : $(SOURCE) $(DEP_CPP_DISPLA) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

# End Source File
# End Target
# End Project
################################################################################
