# Microsoft Developer Studio Generated NMAKE File, Format Version 40001
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

!IF "$(CFG)" == ""
CFG=libjpeg - Win32 Debug
!MESSAGE No configuration specified.  Defaulting to libjpeg - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "libjpeg - Win32 Release" && "$(CFG)" !=\
 "libjpeg - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE on this makefile
!MESSAGE by defining the macro CFG on the command line.  For example:
!MESSAGE 
!MESSAGE NMAKE /f "libjpeg.mak" CFG="libjpeg - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "libjpeg - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "libjpeg - Win32 Debug" (based on "Win32 (x86) Static Library")
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
# PROP Target_Last_Scanned "libjpeg - Win32 Debug"
CPP=cl.exe

!IF  "$(CFG)" == "libjpeg - Win32 Release"

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

ALL : "$(OUTDIR)\libjpeg.lib"

CLEAN : 
	-@erase ".\libjpeg.lib"
	-@erase ".\Release\jcparam.obj"
	-@erase ".\Release\jidctred.obj"
	-@erase ".\Release\jdhuff.obj"
	-@erase ".\Release\jdcoefct.obj"
	-@erase ".\Release\jfdctflt.obj"
	-@erase ".\Release\jcapistd.obj"
	-@erase ".\Release\jcmarker.obj"
	-@erase ".\Release\jfdctfst.obj"
	-@erase ".\Release\jidctflt.obj"
	-@erase ".\Release\jidctfst.obj"
	-@erase ".\Release\jdsample.obj"
	-@erase ".\Release\jdatasrc.obj"
	-@erase ".\Release\jccoefct.obj"
	-@erase ".\Release\jdcolor.obj"
	-@erase ".\Release\jdmaster.obj"
	-@erase ".\Release\jcprepct.obj"
	-@erase ".\Release\jcinit.obj"
	-@erase ".\Release\jfdctint.obj"
	-@erase ".\Release\jcsample.obj"
	-@erase ".\Release\jidctint.obj"
	-@erase ".\Release\jdapimin.obj"
	-@erase ".\Release\jerror.obj"
	-@erase ".\Release\jquant2.obj"
	-@erase ".\Release\jcapimin.obj"
	-@erase ".\Release\jcmainct.obj"
	-@erase ".\Release\jdpostct.obj"
	-@erase ".\Release\jcdctmgr.obj"
	-@erase ".\Release\jquant1.obj"
	-@erase ".\Release\jctrans.obj"
	-@erase ".\Release\jdinput.obj"
	-@erase ".\Release\jchuff.obj"
	-@erase ".\Release\jcphuff.obj"
	-@erase ".\Release\jmemnobs.obj"
	-@erase ".\Release\jdmainct.obj"
	-@erase ".\Release\jmemansi.obj"
	-@erase ".\Release\jcmaster.obj"
	-@erase ".\Release\jutils.obj"
	-@erase ".\Release\jdmerge.obj"
	-@erase ".\Release\jdtrans.obj"
	-@erase ".\Release\jddctmgr.obj"
	-@erase ".\Release\jccolor.obj"
	-@erase ".\Release\jdapistd.obj"
	-@erase ".\Release\jdmarker.obj"
	-@erase ".\Release\jmemmgr.obj"
	-@erase ".\Release\jcomapi.obj"
	-@erase ".\Release\jdatadst.obj"
	-@erase ".\Release\jdphuff.obj"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

"$(INTDIR)" :
    if not exist "$(INTDIR)/$(NULL)" mkdir "$(INTDIR)"

# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /YX /c
# ADD CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /YX /c
CPP_PROJ=/nologo /ML /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS"\
 /Fp"$(INTDIR)/libjpeg.pch" /YX /Fo"$(INTDIR)/" /c 
CPP_OBJS=.\Release/
CPP_SBRS=
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/libjpeg.bsc" 
BSC32_SBRS=
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo
LIB32_FLAGS=/nologo /out:"$(OUTDIR)/libjpeg.lib" 
LIB32_OBJS= \
	"$(INTDIR)/jcparam.obj" \
	"$(INTDIR)/jidctred.obj" \
	"$(INTDIR)/jdhuff.obj" \
	"$(INTDIR)/jdcoefct.obj" \
	"$(INTDIR)/jfdctflt.obj" \
	"$(INTDIR)/jcapistd.obj" \
	"$(INTDIR)/jcmarker.obj" \
	"$(INTDIR)/jfdctfst.obj" \
	"$(INTDIR)/jidctflt.obj" \
	"$(INTDIR)/jidctfst.obj" \
	"$(INTDIR)/jdsample.obj" \
	"$(INTDIR)/jdatasrc.obj" \
	"$(INTDIR)/jccoefct.obj" \
	"$(INTDIR)/jdcolor.obj" \
	"$(INTDIR)/jdmaster.obj" \
	"$(INTDIR)/jcprepct.obj" \
	"$(INTDIR)/jcinit.obj" \
	"$(INTDIR)/jfdctint.obj" \
	"$(INTDIR)/jcsample.obj" \
	"$(INTDIR)/jidctint.obj" \
	"$(INTDIR)/jdapimin.obj" \
	"$(INTDIR)/jerror.obj" \
	"$(INTDIR)/jquant2.obj" \
	"$(INTDIR)/jcapimin.obj" \
	"$(INTDIR)/jcmainct.obj" \
	"$(INTDIR)/jdpostct.obj" \
	"$(INTDIR)/jcdctmgr.obj" \
	"$(INTDIR)/jquant1.obj" \
	"$(INTDIR)/jctrans.obj" \
	"$(INTDIR)/jdinput.obj" \
	"$(INTDIR)/jchuff.obj" \
	"$(INTDIR)/jcphuff.obj" \
	"$(INTDIR)/jmemnobs.obj" \
	"$(INTDIR)/jdmainct.obj" \
	"$(INTDIR)/jmemansi.obj" \
	"$(INTDIR)/jcmaster.obj" \
	"$(INTDIR)/jutils.obj" \
	"$(INTDIR)/jdmerge.obj" \
	"$(INTDIR)/jdtrans.obj" \
	"$(INTDIR)/jddctmgr.obj" \
	"$(INTDIR)/jccolor.obj" \
	"$(INTDIR)/jdapistd.obj" \
	"$(INTDIR)/jdmarker.obj" \
	"$(INTDIR)/jmemmgr.obj" \
	"$(INTDIR)/jcomapi.obj" \
	"$(INTDIR)/jdatadst.obj" \
	"$(INTDIR)/jdphuff.obj"

"$(OUTDIR)\libjpeg.lib" : "$(OUTDIR)" $(DEF_FILE) $(LIB32_OBJS)
    $(LIB32) @<<
  $(LIB32_FLAGS) $(DEF_FLAGS) $(LIB32_OBJS)
<<

!ELSEIF  "$(CFG)" == "libjpeg - Win32 Debug"

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

ALL : "$(OUTDIR)\libjpeg.lib"

CLEAN : 
	-@erase ".\libjpeg.lib"
	-@erase ".\Debug\jdinput.obj"
	-@erase ".\Debug\jcphuff.obj"
	-@erase ".\Debug\jdpostct.obj"
	-@erase ".\Debug\jutils.obj"
	-@erase ".\Debug\jcdctmgr.obj"
	-@erase ".\Debug\jdmerge.obj"
	-@erase ".\Debug\jdtrans.obj"
	-@erase ".\Debug\jccolor.obj"
	-@erase ".\Debug\jmemmgr.obj"
	-@erase ".\Debug\jcomapi.obj"
	-@erase ".\Debug\jdhuff.obj"
	-@erase ".\Debug\jdmaster.obj"
	-@erase ".\Debug\jdphuff.obj"
	-@erase ".\Debug\jmemnobs.obj"
	-@erase ".\Debug\jdmainct.obj"
	-@erase ".\Debug\jmemansi.obj"
	-@erase ".\Debug\jcmaster.obj"
	-@erase ".\Debug\jcinit.obj"
	-@erase ".\Debug\jdcolor.obj"
	-@erase ".\Debug\jddctmgr.obj"
	-@erase ".\Debug\jdapistd.obj"
	-@erase ".\Debug\jdmarker.obj"
	-@erase ".\Debug\jdatadst.obj"
	-@erase ".\Debug\jidctred.obj"
	-@erase ".\Debug\jdcoefct.obj"
	-@erase ".\Debug\jfdctflt.obj"
	-@erase ".\Debug\jerror.obj"
	-@erase ".\Debug\jcapistd.obj"
	-@erase ".\Debug\jcmarker.obj"
	-@erase ".\Debug\jfdctfst.obj"
	-@erase ".\Debug\jidctflt.obj"
	-@erase ".\Debug\jquant2.obj"
	-@erase ".\Debug\jidctfst.obj"
	-@erase ".\Debug\jdsample.obj"
	-@erase ".\Debug\jdatasrc.obj"
	-@erase ".\Debug\jccoefct.obj"
	-@erase ".\Debug\jcprepct.obj"
	-@erase ".\Debug\jfdctint.obj"
	-@erase ".\Debug\jcsample.obj"
	-@erase ".\Debug\jidctint.obj"
	-@erase ".\Debug\jcparam.obj"
	-@erase ".\Debug\jdapimin.obj"
	-@erase ".\Debug\jquant1.obj"
	-@erase ".\Debug\jctrans.obj"
	-@erase ".\Debug\jchuff.obj"
	-@erase ".\Debug\jcapimin.obj"
	-@erase ".\Debug\jcmainct.obj"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

"$(INTDIR)" :
    if not exist "$(INTDIR)/$(NULL)" mkdir "$(INTDIR)"

# ADD BASE CPP /nologo /W3 /GX /Z7 /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /YX /c
# ADD CPP /nologo /W3 /GX /Z7 /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /YX /c
CPP_PROJ=/nologo /MLd /W3 /GX /Z7 /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /Fp"$(INTDIR)/libjpeg.pch" /YX /Fo"$(INTDIR)/" /c 
CPP_OBJS=.\Debug/
CPP_SBRS=
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/libjpeg.bsc" 
BSC32_SBRS=
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo
LIB32_FLAGS=/nologo /out:"$(OUTDIR)/libjpeg.lib" 
LIB32_OBJS= \
	"$(INTDIR)/jdinput.obj" \
	"$(INTDIR)/jcphuff.obj" \
	"$(INTDIR)/jdpostct.obj" \
	"$(INTDIR)/jutils.obj" \
	"$(INTDIR)/jcdctmgr.obj" \
	"$(INTDIR)/jdmerge.obj" \
	"$(INTDIR)/jdtrans.obj" \
	"$(INTDIR)/jccolor.obj" \
	"$(INTDIR)/jmemmgr.obj" \
	"$(INTDIR)/jcomapi.obj" \
	"$(INTDIR)/jdhuff.obj" \
	"$(INTDIR)/jdmaster.obj" \
	"$(INTDIR)/jdphuff.obj" \
	"$(INTDIR)/jmemnobs.obj" \
	"$(INTDIR)/jdmainct.obj" \
	"$(INTDIR)/jmemansi.obj" \
	"$(INTDIR)/jcmaster.obj" \
	"$(INTDIR)/jcinit.obj" \
	"$(INTDIR)/jdcolor.obj" \
	"$(INTDIR)/jddctmgr.obj" \
	"$(INTDIR)/jdapistd.obj" \
	"$(INTDIR)/jdmarker.obj" \
	"$(INTDIR)/jdatadst.obj" \
	"$(INTDIR)/jidctred.obj" \
	"$(INTDIR)/jdcoefct.obj" \
	"$(INTDIR)/jfdctflt.obj" \
	"$(INTDIR)/jerror.obj" \
	"$(INTDIR)/jcapistd.obj" \
	"$(INTDIR)/jcmarker.obj" \
	"$(INTDIR)/jfdctfst.obj" \
	"$(INTDIR)/jidctflt.obj" \
	"$(INTDIR)/jquant2.obj" \
	"$(INTDIR)/jidctfst.obj" \
	"$(INTDIR)/jdsample.obj" \
	"$(INTDIR)/jdatasrc.obj" \
	"$(INTDIR)/jccoefct.obj" \
	"$(INTDIR)/jcprepct.obj" \
	"$(INTDIR)/jfdctint.obj" \
	"$(INTDIR)/jcsample.obj" \
	"$(INTDIR)/jidctint.obj" \
	"$(INTDIR)/jcparam.obj" \
	"$(INTDIR)/jdapimin.obj" \
	"$(INTDIR)/jquant1.obj" \
	"$(INTDIR)/jctrans.obj" \
	"$(INTDIR)/jchuff.obj" \
	"$(INTDIR)/jcapimin.obj" \
	"$(INTDIR)/jcmainct.obj"

"$(OUTDIR)\libjpeg.lib" : "$(OUTDIR)" $(DEF_FILE) $(LIB32_OBJS)
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

# Name "libjpeg - Win32 Release"
# Name "libjpeg - Win32 Debug"

!IF  "$(CFG)" == "libjpeg - Win32 Release"

!ELSEIF  "$(CFG)" == "libjpeg - Win32 Debug"

!ENDIF 

################################################################################
# Begin Source File

SOURCE=\users\guetari\opera\libjpeg\jutils.c
DEP_CPP_JUTIL=\
	".\..\libjpeg\jinclude.h"\
	".\..\libjpeg\jpeglib.h"\
	".\..\libjpeg\jconfig.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	".\..\libjpeg\jmorecfg.h"\
	".\..\libjpeg\jpegint.h"\
	".\..\libjpeg\jerror.h"\
	

"$(INTDIR)\jutils.obj" : $(SOURCE) $(DEP_CPP_JUTIL) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


# End Source File
################################################################################
# Begin Source File

SOURCE=\users\guetari\opera\libjpeg\jquant2.c
DEP_CPP_JQUAN=\
	".\..\libjpeg\jinclude.h"\
	".\..\libjpeg\jpeglib.h"\
	".\..\libjpeg\jconfig.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	".\..\libjpeg\jmorecfg.h"\
	".\..\libjpeg\jpegint.h"\
	".\..\libjpeg\jerror.h"\
	

"$(INTDIR)\jquant2.obj" : $(SOURCE) $(DEP_CPP_JQUAN) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


# End Source File
################################################################################
# Begin Source File

SOURCE=\users\guetari\opera\libjpeg\jquant1.c
DEP_CPP_JQUANT=\
	".\..\libjpeg\jinclude.h"\
	".\..\libjpeg\jpeglib.h"\
	".\..\libjpeg\jconfig.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	".\..\libjpeg\jmorecfg.h"\
	".\..\libjpeg\jpegint.h"\
	".\..\libjpeg\jerror.h"\
	

"$(INTDIR)\jquant1.obj" : $(SOURCE) $(DEP_CPP_JQUANT) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


# End Source File
################################################################################
# Begin Source File

SOURCE=\users\guetari\opera\libjpeg\jmemmgr.c
DEP_CPP_JMEMM=\
	".\..\libjpeg\jinclude.h"\
	".\..\libjpeg\jpeglib.h"\
	".\..\libjpeg\jmemsys.h"\
	".\..\libjpeg\jconfig.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	".\..\libjpeg\jmorecfg.h"\
	".\..\libjpeg\jpegint.h"\
	".\..\libjpeg\jerror.h"\
	

"$(INTDIR)\jmemmgr.obj" : $(SOURCE) $(DEP_CPP_JMEMM) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


# End Source File
################################################################################
# Begin Source File

SOURCE=\users\guetari\opera\libjpeg\jidctred.c
DEP_CPP_JIDCT=\
	".\..\libjpeg\jinclude.h"\
	".\..\libjpeg\jpeglib.h"\
	".\..\libjpeg\jdct.h"\
	".\..\libjpeg\jconfig.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	".\..\libjpeg\jmorecfg.h"\
	".\..\libjpeg\jpegint.h"\
	".\..\libjpeg\jerror.h"\
	

"$(INTDIR)\jidctred.obj" : $(SOURCE) $(DEP_CPP_JIDCT) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


# End Source File
################################################################################
# Begin Source File

SOURCE=\users\guetari\opera\libjpeg\jidctint.c
DEP_CPP_JIDCTI=\
	".\..\libjpeg\jinclude.h"\
	".\..\libjpeg\jpeglib.h"\
	".\..\libjpeg\jdct.h"\
	".\..\libjpeg\jconfig.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	".\..\libjpeg\jmorecfg.h"\
	".\..\libjpeg\jpegint.h"\
	".\..\libjpeg\jerror.h"\
	

"$(INTDIR)\jidctint.obj" : $(SOURCE) $(DEP_CPP_JIDCTI) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


# End Source File
################################################################################
# Begin Source File

SOURCE=\users\guetari\opera\libjpeg\jidctfst.c
DEP_CPP_JIDCTF=\
	".\..\libjpeg\jinclude.h"\
	".\..\libjpeg\jpeglib.h"\
	".\..\libjpeg\jdct.h"\
	".\..\libjpeg\jconfig.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	".\..\libjpeg\jmorecfg.h"\
	".\..\libjpeg\jpegint.h"\
	".\..\libjpeg\jerror.h"\
	

"$(INTDIR)\jidctfst.obj" : $(SOURCE) $(DEP_CPP_JIDCTF) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


# End Source File
################################################################################
# Begin Source File

SOURCE=\users\guetari\opera\libjpeg\jidctflt.c
DEP_CPP_JIDCTFL=\
	".\..\libjpeg\jinclude.h"\
	".\..\libjpeg\jpeglib.h"\
	".\..\libjpeg\jdct.h"\
	".\..\libjpeg\jconfig.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	".\..\libjpeg\jmorecfg.h"\
	".\..\libjpeg\jpegint.h"\
	".\..\libjpeg\jerror.h"\
	

"$(INTDIR)\jidctflt.obj" : $(SOURCE) $(DEP_CPP_JIDCTFL) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


# End Source File
################################################################################
# Begin Source File

SOURCE=\users\guetari\opera\libjpeg\jfdctint.c
DEP_CPP_JFDCT=\
	".\..\libjpeg\jinclude.h"\
	".\..\libjpeg\jpeglib.h"\
	".\..\libjpeg\jdct.h"\
	".\..\libjpeg\jconfig.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	".\..\libjpeg\jmorecfg.h"\
	".\..\libjpeg\jpegint.h"\
	".\..\libjpeg\jerror.h"\
	

"$(INTDIR)\jfdctint.obj" : $(SOURCE) $(DEP_CPP_JFDCT) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


# End Source File
################################################################################
# Begin Source File

SOURCE=\users\guetari\opera\libjpeg\jfdctfst.c
DEP_CPP_JFDCTF=\
	".\..\libjpeg\jinclude.h"\
	".\..\libjpeg\jpeglib.h"\
	".\..\libjpeg\jdct.h"\
	".\..\libjpeg\jconfig.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	".\..\libjpeg\jmorecfg.h"\
	".\..\libjpeg\jpegint.h"\
	".\..\libjpeg\jerror.h"\
	

"$(INTDIR)\jfdctfst.obj" : $(SOURCE) $(DEP_CPP_JFDCTF) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


# End Source File
################################################################################
# Begin Source File

SOURCE=\users\guetari\opera\libjpeg\jfdctflt.c
DEP_CPP_JFDCTFL=\
	".\..\libjpeg\jinclude.h"\
	".\..\libjpeg\jpeglib.h"\
	".\..\libjpeg\jdct.h"\
	".\..\libjpeg\jconfig.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	".\..\libjpeg\jmorecfg.h"\
	".\..\libjpeg\jpegint.h"\
	".\..\libjpeg\jerror.h"\
	

"$(INTDIR)\jfdctflt.obj" : $(SOURCE) $(DEP_CPP_JFDCTFL) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


# End Source File
################################################################################
# Begin Source File

SOURCE=\users\guetari\opera\libjpeg\jerror.c
DEP_CPP_JERRO=\
	".\..\libjpeg\jinclude.h"\
	".\..\libjpeg\jpeglib.h"\
	".\..\libjpeg\jversion.h"\
	".\..\libjpeg\jerror.h"\
	".\..\libjpeg\jconfig.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	".\..\libjpeg\jmorecfg.h"\
	".\..\libjpeg\jpegint.h"\
	

"$(INTDIR)\jerror.obj" : $(SOURCE) $(DEP_CPP_JERRO) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


# End Source File
################################################################################
# Begin Source File

SOURCE=\users\guetari\opera\libjpeg\jdtrans.c
DEP_CPP_JDTRA=\
	".\..\libjpeg\jinclude.h"\
	".\..\libjpeg\jpeglib.h"\
	".\..\libjpeg\jconfig.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	".\..\libjpeg\jmorecfg.h"\
	".\..\libjpeg\jpegint.h"\
	".\..\libjpeg\jerror.h"\
	

"$(INTDIR)\jdtrans.obj" : $(SOURCE) $(DEP_CPP_JDTRA) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


# End Source File
################################################################################
# Begin Source File

SOURCE=\users\guetari\opera\libjpeg\jdsample.c
DEP_CPP_JDSAM=\
	".\..\libjpeg\jinclude.h"\
	".\..\libjpeg\jpeglib.h"\
	".\..\libjpeg\jconfig.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	".\..\libjpeg\jmorecfg.h"\
	".\..\libjpeg\jpegint.h"\
	".\..\libjpeg\jerror.h"\
	

"$(INTDIR)\jdsample.obj" : $(SOURCE) $(DEP_CPP_JDSAM) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


# End Source File
################################################################################
# Begin Source File

SOURCE=\users\guetari\opera\libjpeg\jdpostct.c
DEP_CPP_JDPOS=\
	".\..\libjpeg\jinclude.h"\
	".\..\libjpeg\jpeglib.h"\
	".\..\libjpeg\jconfig.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	".\..\libjpeg\jmorecfg.h"\
	".\..\libjpeg\jpegint.h"\
	".\..\libjpeg\jerror.h"\
	

"$(INTDIR)\jdpostct.obj" : $(SOURCE) $(DEP_CPP_JDPOS) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


# End Source File
################################################################################
# Begin Source File

SOURCE=\users\guetari\opera\libjpeg\jdphuff.c
DEP_CPP_JDPHU=\
	".\..\libjpeg\jinclude.h"\
	".\..\libjpeg\jpeglib.h"\
	".\..\libjpeg\jdhuff.h"\
	".\..\libjpeg\jconfig.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	".\..\libjpeg\jmorecfg.h"\
	".\..\libjpeg\jpegint.h"\
	".\..\libjpeg\jerror.h"\
	

"$(INTDIR)\jdphuff.obj" : $(SOURCE) $(DEP_CPP_JDPHU) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


# End Source File
################################################################################
# Begin Source File

SOURCE=\users\guetari\opera\libjpeg\jdmerge.c
DEP_CPP_JDMER=\
	".\..\libjpeg\jinclude.h"\
	".\..\libjpeg\jpeglib.h"\
	".\..\libjpeg\jconfig.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	".\..\libjpeg\jmorecfg.h"\
	".\..\libjpeg\jpegint.h"\
	".\..\libjpeg\jerror.h"\
	

"$(INTDIR)\jdmerge.obj" : $(SOURCE) $(DEP_CPP_JDMER) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


# End Source File
################################################################################
# Begin Source File

SOURCE=\users\guetari\opera\libjpeg\jdmaster.c
DEP_CPP_JDMAS=\
	".\..\libjpeg\jinclude.h"\
	".\..\libjpeg\jpeglib.h"\
	".\..\libjpeg\jconfig.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	".\..\libjpeg\jmorecfg.h"\
	".\..\libjpeg\jpegint.h"\
	".\..\libjpeg\jerror.h"\
	

"$(INTDIR)\jdmaster.obj" : $(SOURCE) $(DEP_CPP_JDMAS) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


# End Source File
################################################################################
# Begin Source File

SOURCE=\users\guetari\opera\libjpeg\jdmarker.c
DEP_CPP_JDMAR=\
	".\..\libjpeg\jinclude.h"\
	".\..\libjpeg\jpeglib.h"\
	".\..\libjpeg\jconfig.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	".\..\libjpeg\jmorecfg.h"\
	".\..\libjpeg\jpegint.h"\
	".\..\libjpeg\jerror.h"\
	

"$(INTDIR)\jdmarker.obj" : $(SOURCE) $(DEP_CPP_JDMAR) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


# End Source File
################################################################################
# Begin Source File

SOURCE=\users\guetari\opera\libjpeg\jdmainct.c
DEP_CPP_JDMAI=\
	".\..\libjpeg\jinclude.h"\
	".\..\libjpeg\jpeglib.h"\
	".\..\libjpeg\jconfig.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	".\..\libjpeg\jmorecfg.h"\
	".\..\libjpeg\jpegint.h"\
	".\..\libjpeg\jerror.h"\
	

"$(INTDIR)\jdmainct.obj" : $(SOURCE) $(DEP_CPP_JDMAI) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


# End Source File
################################################################################
# Begin Source File

SOURCE=\users\guetari\opera\libjpeg\jdinput.c
DEP_CPP_JDINP=\
	".\..\libjpeg\jinclude.h"\
	".\..\libjpeg\jpeglib.h"\
	".\..\libjpeg\jconfig.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	".\..\libjpeg\jmorecfg.h"\
	".\..\libjpeg\jpegint.h"\
	".\..\libjpeg\jerror.h"\
	

"$(INTDIR)\jdinput.obj" : $(SOURCE) $(DEP_CPP_JDINP) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


# End Source File
################################################################################
# Begin Source File

SOURCE=\users\guetari\opera\libjpeg\jdhuff.c
DEP_CPP_JDHUF=\
	".\..\libjpeg\jinclude.h"\
	".\..\libjpeg\jpeglib.h"\
	".\..\libjpeg\jdhuff.h"\
	".\..\libjpeg\jconfig.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	".\..\libjpeg\jmorecfg.h"\
	".\..\libjpeg\jpegint.h"\
	".\..\libjpeg\jerror.h"\
	

"$(INTDIR)\jdhuff.obj" : $(SOURCE) $(DEP_CPP_JDHUF) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


# End Source File
################################################################################
# Begin Source File

SOURCE=\users\guetari\opera\libjpeg\jddctmgr.c
DEP_CPP_JDDCT=\
	".\..\libjpeg\jinclude.h"\
	".\..\libjpeg\jpeglib.h"\
	".\..\libjpeg\jdct.h"\
	".\..\libjpeg\jconfig.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	".\..\libjpeg\jmorecfg.h"\
	".\..\libjpeg\jpegint.h"\
	".\..\libjpeg\jerror.h"\
	

"$(INTDIR)\jddctmgr.obj" : $(SOURCE) $(DEP_CPP_JDDCT) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


# End Source File
################################################################################
# Begin Source File

SOURCE=\users\guetari\opera\libjpeg\jdcolor.c
DEP_CPP_JDCOL=\
	".\..\libjpeg\jinclude.h"\
	".\..\libjpeg\jpeglib.h"\
	".\..\libjpeg\jconfig.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	".\..\libjpeg\jmorecfg.h"\
	".\..\libjpeg\jpegint.h"\
	".\..\libjpeg\jerror.h"\
	

"$(INTDIR)\jdcolor.obj" : $(SOURCE) $(DEP_CPP_JDCOL) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


# End Source File
################################################################################
# Begin Source File

SOURCE=\users\guetari\opera\libjpeg\jdcoefct.c
DEP_CPP_JDCOE=\
	".\..\libjpeg\jinclude.h"\
	".\..\libjpeg\jpeglib.h"\
	".\..\libjpeg\jconfig.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	".\..\libjpeg\jmorecfg.h"\
	".\..\libjpeg\jpegint.h"\
	".\..\libjpeg\jerror.h"\
	

"$(INTDIR)\jdcoefct.obj" : $(SOURCE) $(DEP_CPP_JDCOE) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


# End Source File
################################################################################
# Begin Source File

SOURCE=\users\guetari\opera\libjpeg\jdatasrc.c
DEP_CPP_JDATA=\
	".\..\libjpeg\jinclude.h"\
	".\..\libjpeg\jpeglib.h"\
	".\..\libjpeg\jerror.h"\
	".\..\libjpeg\jconfig.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	".\..\libjpeg\jmorecfg.h"\
	".\..\libjpeg\jpegint.h"\
	

"$(INTDIR)\jdatasrc.obj" : $(SOURCE) $(DEP_CPP_JDATA) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


# End Source File
################################################################################
# Begin Source File

SOURCE=\users\guetari\opera\libjpeg\jdatadst.c
DEP_CPP_JDATAD=\
	".\..\libjpeg\jinclude.h"\
	".\..\libjpeg\jpeglib.h"\
	".\..\libjpeg\jerror.h"\
	".\..\libjpeg\jconfig.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	".\..\libjpeg\jmorecfg.h"\
	".\..\libjpeg\jpegint.h"\
	

"$(INTDIR)\jdatadst.obj" : $(SOURCE) $(DEP_CPP_JDATAD) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


# End Source File
################################################################################
# Begin Source File

SOURCE=\users\guetari\opera\libjpeg\jdapistd.c
DEP_CPP_JDAPI=\
	".\..\libjpeg\jinclude.h"\
	".\..\libjpeg\jpeglib.h"\
	".\..\libjpeg\jconfig.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	".\..\libjpeg\jmorecfg.h"\
	".\..\libjpeg\jpegint.h"\
	".\..\libjpeg\jerror.h"\
	

"$(INTDIR)\jdapistd.obj" : $(SOURCE) $(DEP_CPP_JDAPI) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


# End Source File
################################################################################
# Begin Source File

SOURCE=\users\guetari\opera\libjpeg\jdapimin.c
DEP_CPP_JDAPIM=\
	".\..\libjpeg\jinclude.h"\
	".\..\libjpeg\jpeglib.h"\
	".\..\libjpeg\jconfig.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	".\..\libjpeg\jmorecfg.h"\
	".\..\libjpeg\jpegint.h"\
	".\..\libjpeg\jerror.h"\
	

"$(INTDIR)\jdapimin.obj" : $(SOURCE) $(DEP_CPP_JDAPIM) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


# End Source File
################################################################################
# Begin Source File

SOURCE=\users\guetari\opera\libjpeg\jctrans.c
DEP_CPP_JCTRA=\
	".\..\libjpeg\jinclude.h"\
	".\..\libjpeg\jpeglib.h"\
	".\..\libjpeg\jconfig.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	".\..\libjpeg\jmorecfg.h"\
	".\..\libjpeg\jpegint.h"\
	".\..\libjpeg\jerror.h"\
	

"$(INTDIR)\jctrans.obj" : $(SOURCE) $(DEP_CPP_JCTRA) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


# End Source File
################################################################################
# Begin Source File

SOURCE=\users\guetari\opera\libjpeg\jcsample.c
DEP_CPP_JCSAM=\
	".\..\libjpeg\jinclude.h"\
	".\..\libjpeg\jpeglib.h"\
	".\..\libjpeg\jconfig.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	".\..\libjpeg\jmorecfg.h"\
	".\..\libjpeg\jpegint.h"\
	".\..\libjpeg\jerror.h"\
	

"$(INTDIR)\jcsample.obj" : $(SOURCE) $(DEP_CPP_JCSAM) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


# End Source File
################################################################################
# Begin Source File

SOURCE=\users\guetari\opera\libjpeg\jcprepct.c
DEP_CPP_JCPRE=\
	".\..\libjpeg\jinclude.h"\
	".\..\libjpeg\jpeglib.h"\
	".\..\libjpeg\jconfig.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	".\..\libjpeg\jmorecfg.h"\
	".\..\libjpeg\jpegint.h"\
	".\..\libjpeg\jerror.h"\
	

"$(INTDIR)\jcprepct.obj" : $(SOURCE) $(DEP_CPP_JCPRE) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


# End Source File
################################################################################
# Begin Source File

SOURCE=\users\guetari\opera\libjpeg\jcphuff.c
DEP_CPP_JCPHU=\
	".\..\libjpeg\jinclude.h"\
	".\..\libjpeg\jpeglib.h"\
	".\..\libjpeg\jchuff.h"\
	".\..\libjpeg\jconfig.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	".\..\libjpeg\jmorecfg.h"\
	".\..\libjpeg\jpegint.h"\
	".\..\libjpeg\jerror.h"\
	

"$(INTDIR)\jcphuff.obj" : $(SOURCE) $(DEP_CPP_JCPHU) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


# End Source File
################################################################################
# Begin Source File

SOURCE=\users\guetari\opera\libjpeg\jcparam.c
DEP_CPP_JCPAR=\
	".\..\libjpeg\jinclude.h"\
	".\..\libjpeg\jpeglib.h"\
	".\..\libjpeg\jconfig.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	".\..\libjpeg\jmorecfg.h"\
	".\..\libjpeg\jpegint.h"\
	".\..\libjpeg\jerror.h"\
	

"$(INTDIR)\jcparam.obj" : $(SOURCE) $(DEP_CPP_JCPAR) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


# End Source File
################################################################################
# Begin Source File

SOURCE=\users\guetari\opera\libjpeg\jcomapi.c
DEP_CPP_JCOMA=\
	".\..\libjpeg\jinclude.h"\
	".\..\libjpeg\jpeglib.h"\
	".\..\libjpeg\jconfig.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	".\..\libjpeg\jmorecfg.h"\
	".\..\libjpeg\jpegint.h"\
	".\..\libjpeg\jerror.h"\
	

"$(INTDIR)\jcomapi.obj" : $(SOURCE) $(DEP_CPP_JCOMA) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


# End Source File
################################################################################
# Begin Source File

SOURCE=\users\guetari\opera\libjpeg\jcmaster.c
DEP_CPP_JCMAS=\
	".\..\libjpeg\jinclude.h"\
	".\..\libjpeg\jpeglib.h"\
	".\..\libjpeg\jconfig.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	".\..\libjpeg\jmorecfg.h"\
	".\..\libjpeg\jpegint.h"\
	".\..\libjpeg\jerror.h"\
	

"$(INTDIR)\jcmaster.obj" : $(SOURCE) $(DEP_CPP_JCMAS) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


# End Source File
################################################################################
# Begin Source File

SOURCE=\users\guetari\opera\libjpeg\jcmarker.c
DEP_CPP_JCMAR=\
	".\..\libjpeg\jinclude.h"\
	".\..\libjpeg\jpeglib.h"\
	".\..\libjpeg\jconfig.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	".\..\libjpeg\jmorecfg.h"\
	".\..\libjpeg\jpegint.h"\
	".\..\libjpeg\jerror.h"\
	

"$(INTDIR)\jcmarker.obj" : $(SOURCE) $(DEP_CPP_JCMAR) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


# End Source File
################################################################################
# Begin Source File

SOURCE=\users\guetari\opera\libjpeg\jcmainct.c
DEP_CPP_JCMAI=\
	".\..\libjpeg\jinclude.h"\
	".\..\libjpeg\jpeglib.h"\
	".\..\libjpeg\jconfig.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	".\..\libjpeg\jmorecfg.h"\
	".\..\libjpeg\jpegint.h"\
	".\..\libjpeg\jerror.h"\
	

"$(INTDIR)\jcmainct.obj" : $(SOURCE) $(DEP_CPP_JCMAI) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


# End Source File
################################################################################
# Begin Source File

SOURCE=\users\guetari\opera\libjpeg\jcinit.c
DEP_CPP_JCINI=\
	".\..\libjpeg\jinclude.h"\
	".\..\libjpeg\jpeglib.h"\
	".\..\libjpeg\jconfig.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	".\..\libjpeg\jmorecfg.h"\
	".\..\libjpeg\jpegint.h"\
	".\..\libjpeg\jerror.h"\
	

"$(INTDIR)\jcinit.obj" : $(SOURCE) $(DEP_CPP_JCINI) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


# End Source File
################################################################################
# Begin Source File

SOURCE=\users\guetari\opera\libjpeg\jchuff.c
DEP_CPP_JCHUF=\
	".\..\libjpeg\jinclude.h"\
	".\..\libjpeg\jpeglib.h"\
	".\..\libjpeg\jchuff.h"\
	".\..\libjpeg\jconfig.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	".\..\libjpeg\jmorecfg.h"\
	".\..\libjpeg\jpegint.h"\
	".\..\libjpeg\jerror.h"\
	

"$(INTDIR)\jchuff.obj" : $(SOURCE) $(DEP_CPP_JCHUF) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


# End Source File
################################################################################
# Begin Source File

SOURCE=\users\guetari\opera\libjpeg\jcdctmgr.c
DEP_CPP_JCDCT=\
	".\..\libjpeg\jinclude.h"\
	".\..\libjpeg\jpeglib.h"\
	".\..\libjpeg\jdct.h"\
	".\..\libjpeg\jconfig.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	".\..\libjpeg\jmorecfg.h"\
	".\..\libjpeg\jpegint.h"\
	".\..\libjpeg\jerror.h"\
	

"$(INTDIR)\jcdctmgr.obj" : $(SOURCE) $(DEP_CPP_JCDCT) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


# End Source File
################################################################################
# Begin Source File

SOURCE=\users\guetari\opera\libjpeg\jccolor.c
DEP_CPP_JCCOL=\
	".\..\libjpeg\jinclude.h"\
	".\..\libjpeg\jpeglib.h"\
	".\..\libjpeg\jconfig.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	".\..\libjpeg\jmorecfg.h"\
	".\..\libjpeg\jpegint.h"\
	".\..\libjpeg\jerror.h"\
	

"$(INTDIR)\jccolor.obj" : $(SOURCE) $(DEP_CPP_JCCOL) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


# End Source File
################################################################################
# Begin Source File

SOURCE=\users\guetari\opera\libjpeg\jccoefct.c
DEP_CPP_JCCOE=\
	".\..\libjpeg\jinclude.h"\
	".\..\libjpeg\jpeglib.h"\
	".\..\libjpeg\jconfig.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	".\..\libjpeg\jmorecfg.h"\
	".\..\libjpeg\jpegint.h"\
	".\..\libjpeg\jerror.h"\
	

"$(INTDIR)\jccoefct.obj" : $(SOURCE) $(DEP_CPP_JCCOE) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


# End Source File
################################################################################
# Begin Source File

SOURCE=\users\guetari\opera\libjpeg\jcapistd.c
DEP_CPP_JCAPI=\
	".\..\libjpeg\jinclude.h"\
	".\..\libjpeg\jpeglib.h"\
	".\..\libjpeg\jconfig.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	".\..\libjpeg\jmorecfg.h"\
	".\..\libjpeg\jpegint.h"\
	".\..\libjpeg\jerror.h"\
	

"$(INTDIR)\jcapistd.obj" : $(SOURCE) $(DEP_CPP_JCAPI) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


# End Source File
################################################################################
# Begin Source File

SOURCE=\users\guetari\opera\libjpeg\jcapimin.c
DEP_CPP_JCAPIM=\
	".\..\libjpeg\jinclude.h"\
	".\..\libjpeg\jpeglib.h"\
	".\..\libjpeg\jconfig.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	".\..\libjpeg\jmorecfg.h"\
	".\..\libjpeg\jpegint.h"\
	".\..\libjpeg\jerror.h"\
	

"$(INTDIR)\jcapimin.obj" : $(SOURCE) $(DEP_CPP_JCAPIM) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


# End Source File
################################################################################
# Begin Source File

SOURCE=\users\guetari\opera\libjpeg\jmemansi.c
DEP_CPP_JMEMA=\
	".\..\libjpeg\jinclude.h"\
	".\..\libjpeg\jpeglib.h"\
	".\..\libjpeg\jmemsys.h"\
	".\..\libjpeg\jconfig.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	".\..\libjpeg\jmorecfg.h"\
	".\..\libjpeg\jpegint.h"\
	".\..\libjpeg\jerror.h"\
	

"$(INTDIR)\jmemansi.obj" : $(SOURCE) $(DEP_CPP_JMEMA) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


# End Source File
################################################################################
# Begin Source File

SOURCE=\users\guetari\opera\libjpeg\jmemnobs.c
DEP_CPP_JMEMN=\
	".\..\libjpeg\jinclude.h"\
	".\..\libjpeg\jpeglib.h"\
	".\..\libjpeg\jmemsys.h"\
	".\..\libjpeg\jconfig.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	".\..\libjpeg\jmorecfg.h"\
	".\..\libjpeg\jpegint.h"\
	".\..\libjpeg\jerror.h"\
	

"$(INTDIR)\jmemnobs.obj" : $(SOURCE) $(DEP_CPP_JMEMN) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


# End Source File
# End Target
# End Project
################################################################################
