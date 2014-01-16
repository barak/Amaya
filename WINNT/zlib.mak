# Microsoft Developer Studio Generated NMAKE File, Format Version 40001
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

!IF "$(CFG)" == ""
CFG=zlib - Win32 Debug
!MESSAGE No configuration specified.  Defaulting to zlib - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "zlib - Win32 Release" && "$(CFG)" != "zlib - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE on this makefile
!MESSAGE by defining the macro CFG on the command line.  For example:
!MESSAGE 
!MESSAGE NMAKE /f "zlib.mak" CFG="zlib - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "zlib - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "zlib - Win32 Debug" (based on "Win32 (x86) Static Library")
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
# PROP Target_Last_Scanned "zlib - Win32 Debug"
CPP=cl.exe

!IF  "$(CFG)" == "zlib - Win32 Release"

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

ALL : "$(OUTDIR)\Zlib.lib"

CLEAN : 
	-@erase ".\Zlib.lib"
	-@erase ".\Release\gzio.obj"
	-@erase ".\Release\crc32.obj"
	-@erase ".\Release\infcodes.obj"
	-@erase ".\Release\inffast.obj"
	-@erase ".\Release\trees.obj"
	-@erase ".\Release\zutil.obj"
	-@erase ".\Release\deflate.obj"
	-@erase ".\Release\uncompr.obj"
	-@erase ".\Release\compress.obj"
	-@erase ".\Release\adler32.obj"
	-@erase ".\Release\inflate.obj"
	-@erase ".\Release\infblock.obj"
	-@erase ".\Release\inftrees.obj"
	-@erase ".\Release\infutil.obj"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

"$(INTDIR)" :
    if not exist "$(INTDIR)/$(NULL)" mkdir "$(INTDIR)"

# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /YX /c
# ADD CPP /nologo /W3 /GX /O2 /I "..\libpng\zlib" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /YX /c
CPP_PROJ=/nologo /ML /W3 /GX /O2 /I "..\libpng\zlib" /D "WIN32" /D "NDEBUG" /D\
 "_WINDOWS" /Fp"$(INTDIR)/zlib.pch" /YX /Fo"$(INTDIR)/" /c 
CPP_OBJS=.\Release/
CPP_SBRS=
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/zlib.bsc" 
BSC32_SBRS=
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo
LIB32_FLAGS=/nologo /out:"$(OUTDIR)/Zlib.lib" 
LIB32_OBJS= \
	"$(INTDIR)/gzio.obj" \
	"$(INTDIR)/crc32.obj" \
	"$(INTDIR)/infcodes.obj" \
	"$(INTDIR)/inffast.obj" \
	"$(INTDIR)/trees.obj" \
	"$(INTDIR)/zutil.obj" \
	"$(INTDIR)/deflate.obj" \
	"$(INTDIR)/uncompr.obj" \
	"$(INTDIR)/compress.obj" \
	"$(INTDIR)/adler32.obj" \
	"$(INTDIR)/inflate.obj" \
	"$(INTDIR)/infblock.obj" \
	"$(INTDIR)/inftrees.obj" \
	"$(INTDIR)/infutil.obj"

"$(OUTDIR)\Zlib.lib" : "$(OUTDIR)" $(DEF_FILE) $(LIB32_OBJS)
    $(LIB32) @<<
  $(LIB32_FLAGS) $(DEF_FLAGS) $(LIB32_OBJS)
<<

!ELSEIF  "$(CFG)" == "zlib - Win32 Debug"

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

ALL : "$(OUTDIR)\Zlib.lib"

CLEAN : 
	-@erase ".\Zlib.lib"
	-@erase ".\Debug\inflate.obj"
	-@erase ".\Debug\compress.obj"
	-@erase ".\Debug\infutil.obj"
	-@erase ".\Debug\gzio.obj"
	-@erase ".\Debug\trees.obj"
	-@erase ".\Debug\zutil.obj"
	-@erase ".\Debug\infblock.obj"
	-@erase ".\Debug\inftrees.obj"
	-@erase ".\Debug\adler32.obj"
	-@erase ".\Debug\inffast.obj"
	-@erase ".\Debug\infcodes.obj"
	-@erase ".\Debug\deflate.obj"
	-@erase ".\Debug\uncompr.obj"
	-@erase ".\Debug\crc32.obj"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

"$(INTDIR)" :
    if not exist "$(INTDIR)/$(NULL)" mkdir "$(INTDIR)"

# ADD BASE CPP /nologo /W3 /GX /Z7 /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /YX /c
# ADD CPP /nologo /W3 /GX /Z7 /Od /I "..\libpng\zlib" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /YX /c
CPP_PROJ=/nologo /MLd /W3 /GX /Z7 /Od /I "..\libpng\zlib" /D "WIN32" /D\
 "_DEBUG" /D "_WINDOWS" /Fp"$(INTDIR)/zlib.pch" /YX /Fo"$(INTDIR)/" /c 
CPP_OBJS=.\Debug/
CPP_SBRS=
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/zlib.bsc" 
BSC32_SBRS=
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo
LIB32_FLAGS=/nologo /out:"$(OUTDIR)/Zlib.lib" 
LIB32_OBJS= \
	"$(INTDIR)/inflate.obj" \
	"$(INTDIR)/compress.obj" \
	"$(INTDIR)/infutil.obj" \
	"$(INTDIR)/gzio.obj" \
	"$(INTDIR)/trees.obj" \
	"$(INTDIR)/zutil.obj" \
	"$(INTDIR)/infblock.obj" \
	"$(INTDIR)/inftrees.obj" \
	"$(INTDIR)/adler32.obj" \
	"$(INTDIR)/inffast.obj" \
	"$(INTDIR)/infcodes.obj" \
	"$(INTDIR)/deflate.obj" \
	"$(INTDIR)/uncompr.obj" \
	"$(INTDIR)/crc32.obj"

"$(OUTDIR)\Zlib.lib" : "$(OUTDIR)" $(DEF_FILE) $(LIB32_OBJS)
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

# Name "zlib - Win32 Release"
# Name "zlib - Win32 Debug"

!IF  "$(CFG)" == "zlib - Win32 Release"

!ELSEIF  "$(CFG)" == "zlib - Win32 Debug"

!ENDIF 

################################################################################
# Begin Source File

SOURCE=\users\guetari\opera\libpng\zlib\zutil.c
DEP_CPP_ZUTIL=\
	".\..\libpng\zlib\zutil.h"\
	".\..\libpng\zlib\zlib.h"\
	".\..\libpng\zlib\zconf.h"\
	

"$(INTDIR)\zutil.obj" : $(SOURCE) $(DEP_CPP_ZUTIL) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


# End Source File
################################################################################
# Begin Source File

SOURCE=\users\guetari\opera\libpng\zlib\uncompr.c
DEP_CPP_UNCOM=\
	".\..\libpng\zlib\zlib.h"\
	".\..\libpng\zlib\zconf.h"\
	

"$(INTDIR)\uncompr.obj" : $(SOURCE) $(DEP_CPP_UNCOM) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


# End Source File
################################################################################
# Begin Source File

SOURCE=\users\guetari\opera\libpng\zlib\trees.c
DEP_CPP_TREES=\
	".\..\libpng\zlib\deflate.h"\
	".\..\libpng\zlib\zutil.h"\
	".\..\libpng\zlib\zlib.h"\
	".\..\libpng\zlib\zconf.h"\
	

"$(INTDIR)\trees.obj" : $(SOURCE) $(DEP_CPP_TREES) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


# End Source File
################################################################################
# Begin Source File

SOURCE=\users\guetari\opera\libpng\zlib\infutil.c
DEP_CPP_INFUT=\
	".\..\libpng\zlib\zutil.h"\
	".\..\libpng\zlib\infblock.h"\
	".\..\libpng\zlib\inftrees.h"\
	".\..\libpng\zlib\infcodes.h"\
	".\..\libpng\zlib\infutil.h"\
	".\..\libpng\zlib\zlib.h"\
	".\..\libpng\zlib\zconf.h"\
	

"$(INTDIR)\infutil.obj" : $(SOURCE) $(DEP_CPP_INFUT) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


# End Source File
################################################################################
# Begin Source File

SOURCE=\users\guetari\opera\libpng\zlib\inftrees.c
DEP_CPP_INFTR=\
	".\..\libpng\zlib\zutil.h"\
	".\..\libpng\zlib\inftrees.h"\
	".\..\libpng\zlib\zlib.h"\
	".\..\libpng\zlib\zconf.h"\
	

"$(INTDIR)\inftrees.obj" : $(SOURCE) $(DEP_CPP_INFTR) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


# End Source File
################################################################################
# Begin Source File

SOURCE=\users\guetari\opera\libpng\zlib\inflate.c
DEP_CPP_INFLA=\
	".\..\libpng\zlib\zutil.h"\
	".\..\libpng\zlib\infblock.h"\
	".\..\libpng\zlib\zlib.h"\
	".\..\libpng\zlib\zconf.h"\
	

"$(INTDIR)\inflate.obj" : $(SOURCE) $(DEP_CPP_INFLA) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


# End Source File
################################################################################
# Begin Source File

SOURCE=\users\guetari\opera\libpng\zlib\inffast.c
DEP_CPP_INFFA=\
	".\..\libpng\zlib\zutil.h"\
	".\..\libpng\zlib\inftrees.h"\
	".\..\libpng\zlib\infblock.h"\
	".\..\libpng\zlib\infcodes.h"\
	".\..\libpng\zlib\infutil.h"\
	".\..\libpng\zlib\inffast.h"\
	".\..\libpng\zlib\zlib.h"\
	".\..\libpng\zlib\zconf.h"\
	

"$(INTDIR)\inffast.obj" : $(SOURCE) $(DEP_CPP_INFFA) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


# End Source File
################################################################################
# Begin Source File

SOURCE=\users\guetari\opera\libpng\zlib\infcodes.c
DEP_CPP_INFCO=\
	".\..\libpng\zlib\zutil.h"\
	".\..\libpng\zlib\inftrees.h"\
	".\..\libpng\zlib\infblock.h"\
	".\..\libpng\zlib\infcodes.h"\
	".\..\libpng\zlib\infutil.h"\
	".\..\libpng\zlib\inffast.h"\
	".\..\libpng\zlib\zlib.h"\
	".\..\libpng\zlib\zconf.h"\
	

"$(INTDIR)\infcodes.obj" : $(SOURCE) $(DEP_CPP_INFCO) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


# End Source File
################################################################################
# Begin Source File

SOURCE=\users\guetari\opera\libpng\zlib\infblock.c
DEP_CPP_INFBL=\
	".\..\libpng\zlib\zutil.h"\
	".\..\libpng\zlib\infblock.h"\
	".\..\libpng\zlib\inftrees.h"\
	".\..\libpng\zlib\infcodes.h"\
	".\..\libpng\zlib\infutil.h"\
	".\..\libpng\zlib\zlib.h"\
	".\..\libpng\zlib\zconf.h"\
	

"$(INTDIR)\infblock.obj" : $(SOURCE) $(DEP_CPP_INFBL) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


# End Source File
################################################################################
# Begin Source File

SOURCE=\users\guetari\opera\libpng\zlib\gzio.c
DEP_CPP_GZIO_=\
	".\..\libpng\zlib\zutil.h"\
	".\..\libpng\zlib\zlib.h"\
	".\..\libpng\zlib\zconf.h"\
	

"$(INTDIR)\gzio.obj" : $(SOURCE) $(DEP_CPP_GZIO_) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


# End Source File
################################################################################
# Begin Source File

SOURCE=\users\guetari\opera\libpng\zlib\deflate.c
DEP_CPP_DEFLA=\
	".\..\libpng\zlib\deflate.h"\
	".\..\libpng\zlib\zutil.h"\
	".\..\libpng\zlib\zlib.h"\
	".\..\libpng\zlib\zconf.h"\
	

"$(INTDIR)\deflate.obj" : $(SOURCE) $(DEP_CPP_DEFLA) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


# End Source File
################################################################################
# Begin Source File

SOURCE=\users\guetari\opera\libpng\zlib\crc32.c
DEP_CPP_CRC32=\
	".\..\libpng\zlib\zlib.h"\
	".\..\libpng\zlib\zconf.h"\
	

"$(INTDIR)\crc32.obj" : $(SOURCE) $(DEP_CPP_CRC32) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


# End Source File
################################################################################
# Begin Source File

SOURCE=\users\guetari\opera\libpng\zlib\compress.c
DEP_CPP_COMPR=\
	".\..\libpng\zlib\zlib.h"\
	".\..\libpng\zlib\zconf.h"\
	

"$(INTDIR)\compress.obj" : $(SOURCE) $(DEP_CPP_COMPR) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


# End Source File
################################################################################
# Begin Source File

SOURCE=\users\guetari\opera\libpng\zlib\adler32.c
DEP_CPP_ADLER=\
	".\..\libpng\zlib\zlib.h"\
	".\..\libpng\zlib\zconf.h"\
	

"$(INTDIR)\adler32.obj" : $(SOURCE) $(DEP_CPP_ADLER) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


# End Source File
# End Target
# End Project
################################################################################
