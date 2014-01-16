# Microsoft Developer Studio Generated NMAKE File, Format Version 40001
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

!IF "$(CFG)" == ""
CFG=libpng - Win32 Debug
!MESSAGE No configuration specified.  Defaulting to libpng - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "libpng - Win32 Release" && "$(CFG)" != "libpng - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE on this makefile
!MESSAGE by defining the macro CFG on the command line.  For example:
!MESSAGE 
!MESSAGE NMAKE /f "libpng.mak" CFG="libpng - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "libpng - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "libpng - Win32 Debug" (based on "Win32 (x86) Static Library")
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
# PROP Target_Last_Scanned "libpng - Win32 Debug"
CPP=cl.exe

!IF  "$(CFG)" == "libpng - Win32 Release"

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

ALL : "$(OUTDIR)\Libpng.lib"

CLEAN : 
	-@erase ".\Libpng.lib"
	-@erase ".\Release\pngerror.obj"
	-@erase ".\Release\pngio.obj"
	-@erase ".\Release\pngtrans.obj"
	-@erase ".\Release\pngrtran.obj"
	-@erase ".\Release\pngrutil.obj"
	-@erase ".\Release\pngwutil.obj"
	-@erase ".\Release\pngmem.obj"
	-@erase ".\Release\pngread.obj"
	-@erase ".\Release\pngwrite.obj"
	-@erase ".\Release\pngpread.obj"
	-@erase ".\Release\pngrcb.obj"
	-@erase ".\Release\png.obj"
	-@erase ".\Release\pngwtran.obj"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

"$(INTDIR)" :
    if not exist "$(INTDIR)/$(NULL)" mkdir "$(INTDIR)"

# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /YX /c
# ADD CPP /nologo /W3 /GX /O2 /I "..\libpng\zlib" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /YX /c
CPP_PROJ=/nologo /ML /W3 /GX /O2 /I "..\libpng\zlib" /D "WIN32" /D "NDEBUG" /D\
 "_WINDOWS" /Fp"$(INTDIR)/libpng.pch" /YX /Fo"$(INTDIR)/" /c 
CPP_OBJS=.\Release/
CPP_SBRS=
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/libpng.bsc" 
BSC32_SBRS=
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo
LIB32_FLAGS=/nologo /out:"$(OUTDIR)/Libpng.lib" 
LIB32_OBJS= \
	"$(INTDIR)/pngerror.obj" \
	"$(INTDIR)/pngio.obj" \
	"$(INTDIR)/pngtrans.obj" \
	"$(INTDIR)/pngrtran.obj" \
	"$(INTDIR)/pngrutil.obj" \
	"$(INTDIR)/pngwutil.obj" \
	"$(INTDIR)/pngmem.obj" \
	"$(INTDIR)/pngread.obj" \
	"$(INTDIR)/pngwrite.obj" \
	"$(INTDIR)/pngpread.obj" \
	"$(INTDIR)/pngrcb.obj" \
	"$(INTDIR)/png.obj" \
	"$(INTDIR)/pngwtran.obj" \
	".\Release\Zlib.lib"

"$(OUTDIR)\Libpng.lib" : "$(OUTDIR)" $(DEF_FILE) $(LIB32_OBJS)
    $(LIB32) @<<
  $(LIB32_FLAGS) $(DEF_FLAGS) $(LIB32_OBJS)
<<

!ELSEIF  "$(CFG)" == "libpng - Win32 Debug"

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

ALL : "$(OUTDIR)\Libpng.lib"

CLEAN : 
	-@erase ".\Libpng.lib"
	-@erase ".\Debug\pngrutil.obj"
	-@erase ".\Debug\pngwutil.obj"
	-@erase ".\Debug\pngwrite.obj"
	-@erase ".\Debug\pngpread.obj"
	-@erase ".\Debug\pngwtran.obj"
	-@erase ".\Debug\pngread.obj"
	-@erase ".\Debug\pngerror.obj"
	-@erase ".\Debug\pngrcb.obj"
	-@erase ".\Debug\png.obj"
	-@erase ".\Debug\pngtrans.obj"
	-@erase ".\Debug\pngrtran.obj"
	-@erase ".\Debug\pngmem.obj"
	-@erase ".\Debug\pngio.obj"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

"$(INTDIR)" :
    if not exist "$(INTDIR)/$(NULL)" mkdir "$(INTDIR)"

# ADD BASE CPP /nologo /W3 /GX /Z7 /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /YX /c
# ADD CPP /nologo /W3 /GX /Z7 /Od /I "..\libpng\zlib" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /YX /c
CPP_PROJ=/nologo /MLd /W3 /GX /Z7 /Od /I "..\libpng\zlib" /D "WIN32" /D\
 "_DEBUG" /D "_WINDOWS" /Fp"$(INTDIR)/libpng.pch" /YX /Fo"$(INTDIR)/" /c 
CPP_OBJS=.\Debug/
CPP_SBRS=
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/libpng.bsc" 
BSC32_SBRS=
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo
LIB32_FLAGS=/nologo /out:"$(OUTDIR)/Libpng.lib" 
LIB32_OBJS= \
	"$(INTDIR)/pngrutil.obj" \
	"$(INTDIR)/pngwutil.obj" \
	"$(INTDIR)/pngwrite.obj" \
	"$(INTDIR)/pngpread.obj" \
	"$(INTDIR)/pngwtran.obj" \
	"$(INTDIR)/pngread.obj" \
	"$(INTDIR)/pngerror.obj" \
	"$(INTDIR)/pngrcb.obj" \
	"$(INTDIR)/png.obj" \
	"$(INTDIR)/pngtrans.obj" \
	"$(INTDIR)/pngrtran.obj" \
	"$(INTDIR)/pngmem.obj" \
	"$(INTDIR)/pngio.obj" \
	".\Release\Zlib.lib"

"$(OUTDIR)\Libpng.lib" : "$(OUTDIR)" $(DEF_FILE) $(LIB32_OBJS)
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

# Name "libpng - Win32 Release"
# Name "libpng - Win32 Debug"

!IF  "$(CFG)" == "libpng - Win32 Release"

!ELSEIF  "$(CFG)" == "libpng - Win32 Debug"

!ENDIF 

################################################################################
# Begin Source File

SOURCE=\users\guetari\opera\libpng\pngwutil.c
DEP_CPP_PNGWU=\
	".\..\libpng\png.h"\
	"e:\users\guetari\opera\libpng\zlib\zlib.h"\
	".\..\libpng\pngconf.h"\
	".\..\libpng\zlib\zconf.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	
NODEP_CPP_PNGWU=\
	".\..\libpng\alloc.h"\
	

"$(INTDIR)\pngwutil.obj" : $(SOURCE) $(DEP_CPP_PNGWU) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


# End Source File
################################################################################
# Begin Source File

SOURCE=\users\guetari\opera\libpng\pngwtran.c
DEP_CPP_PNGWT=\
	".\..\libpng\png.h"\
	"e:\users\guetari\opera\libpng\zlib\zlib.h"\
	".\..\libpng\pngconf.h"\
	".\..\libpng\zlib\zconf.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	
NODEP_CPP_PNGWT=\
	".\..\libpng\alloc.h"\
	

"$(INTDIR)\pngwtran.obj" : $(SOURCE) $(DEP_CPP_PNGWT) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


# End Source File
################################################################################
# Begin Source File

SOURCE=\users\guetari\opera\libpng\pngwrite.c
DEP_CPP_PNGWR=\
	".\..\libpng\png.h"\
	"e:\users\guetari\opera\libpng\zlib\zlib.h"\
	".\..\libpng\pngconf.h"\
	".\..\libpng\zlib\zconf.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	
NODEP_CPP_PNGWR=\
	".\..\libpng\alloc.h"\
	

"$(INTDIR)\pngwrite.obj" : $(SOURCE) $(DEP_CPP_PNGWR) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


# End Source File
################################################################################
# Begin Source File

SOURCE=\users\guetari\opera\libpng\pngtrans.c
DEP_CPP_PNGTR=\
	".\..\libpng\png.h"\
	"e:\users\guetari\opera\libpng\zlib\zlib.h"\
	".\..\libpng\pngconf.h"\
	".\..\libpng\zlib\zconf.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	
NODEP_CPP_PNGTR=\
	".\..\libpng\alloc.h"\
	

"$(INTDIR)\pngtrans.obj" : $(SOURCE) $(DEP_CPP_PNGTR) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


# End Source File
################################################################################
# Begin Source File

SOURCE=\users\guetari\opera\libpng\pngrutil.c
DEP_CPP_PNGRU=\
	".\..\libpng\png.h"\
	"e:\users\guetari\opera\libpng\zlib\zlib.h"\
	".\..\libpng\pngconf.h"\
	".\..\libpng\zlib\zconf.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	
NODEP_CPP_PNGRU=\
	".\..\libpng\alloc.h"\
	

"$(INTDIR)\pngrutil.obj" : $(SOURCE) $(DEP_CPP_PNGRU) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


# End Source File
################################################################################
# Begin Source File

SOURCE=\users\guetari\opera\libpng\pngrtran.c
DEP_CPP_PNGRT=\
	".\..\libpng\png.h"\
	"e:\users\guetari\opera\libpng\zlib\zlib.h"\
	".\..\libpng\pngconf.h"\
	".\..\libpng\zlib\zconf.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	
NODEP_CPP_PNGRT=\
	".\..\libpng\alloc.h"\
	

"$(INTDIR)\pngrtran.obj" : $(SOURCE) $(DEP_CPP_PNGRT) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


# End Source File
################################################################################
# Begin Source File

SOURCE=\users\guetari\opera\libpng\pngread.c
DEP_CPP_PNGRE=\
	".\..\libpng\png.h"\
	"e:\users\guetari\opera\libpng\zlib\zlib.h"\
	".\..\libpng\pngconf.h"\
	".\..\libpng\zlib\zconf.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	
NODEP_CPP_PNGRE=\
	".\..\libpng\alloc.h"\
	

"$(INTDIR)\pngread.obj" : $(SOURCE) $(DEP_CPP_PNGRE) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


# End Source File
################################################################################
# Begin Source File

SOURCE=\users\guetari\opera\libpng\pngrcb.c
DEP_CPP_PNGRC=\
	".\..\libpng\png.h"\
	"e:\users\guetari\opera\libpng\zlib\zlib.h"\
	".\..\libpng\pngconf.h"\
	".\..\libpng\zlib\zconf.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	
NODEP_CPP_PNGRC=\
	".\..\libpng\alloc.h"\
	

"$(INTDIR)\pngrcb.obj" : $(SOURCE) $(DEP_CPP_PNGRC) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


# End Source File
################################################################################
# Begin Source File

SOURCE=\users\guetari\opera\libpng\pngpread.c
DEP_CPP_PNGPR=\
	".\..\libpng\png.h"\
	"e:\users\guetari\opera\libpng\zlib\zlib.h"\
	".\..\libpng\pngconf.h"\
	".\..\libpng\zlib\zconf.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	
NODEP_CPP_PNGPR=\
	".\..\libpng\alloc.h"\
	

"$(INTDIR)\pngpread.obj" : $(SOURCE) $(DEP_CPP_PNGPR) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


# End Source File
################################################################################
# Begin Source File

SOURCE=\users\guetari\opera\libpng\pngmem.c
DEP_CPP_PNGME=\
	".\..\libpng\png.h"\
	"e:\users\guetari\opera\libpng\zlib\zlib.h"\
	".\..\libpng\pngconf.h"\
	".\..\libpng\zlib\zconf.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	
NODEP_CPP_PNGME=\
	".\..\libpng\alloc.h"\
	

"$(INTDIR)\pngmem.obj" : $(SOURCE) $(DEP_CPP_PNGME) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


# End Source File
################################################################################
# Begin Source File

SOURCE=\users\guetari\opera\libpng\pngio.c
DEP_CPP_PNGIO=\
	".\..\libpng\png.h"\
	"e:\users\guetari\opera\libpng\zlib\zlib.h"\
	".\..\libpng\pngconf.h"\
	".\..\libpng\zlib\zconf.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	
NODEP_CPP_PNGIO=\
	".\..\libpng\alloc.h"\
	

"$(INTDIR)\pngio.obj" : $(SOURCE) $(DEP_CPP_PNGIO) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


# End Source File
################################################################################
# Begin Source File

SOURCE=\users\guetari\opera\libpng\pngerror.c
DEP_CPP_PNGER=\
	".\..\libpng\png.h"\
	"e:\users\guetari\opera\libpng\zlib\zlib.h"\
	".\..\libpng\pngconf.h"\
	".\..\libpng\zlib\zconf.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	
NODEP_CPP_PNGER=\
	".\..\libpng\alloc.h"\
	

"$(INTDIR)\pngerror.obj" : $(SOURCE) $(DEP_CPP_PNGER) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


# End Source File
################################################################################
# Begin Source File

SOURCE=\users\guetari\opera\libpng\png.c
DEP_CPP_PNG_C=\
	".\..\libpng\png.h"\
	"e:\users\guetari\opera\libpng\zlib\zlib.h"\
	".\..\libpng\pngconf.h"\
	".\..\libpng\zlib\zconf.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	
NODEP_CPP_PNG_C=\
	".\..\libpng\alloc.h"\
	

"$(INTDIR)\png.obj" : $(SOURCE) $(DEP_CPP_PNG_C) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


# End Source File
################################################################################
# Begin Source File

SOURCE=.\Release\Zlib.lib

!IF  "$(CFG)" == "libpng - Win32 Release"

!ELSEIF  "$(CFG)" == "libpng - Win32 Debug"

!ENDIF 

# End Source File
# End Target
# End Project
################################################################################
