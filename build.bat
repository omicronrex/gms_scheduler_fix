@echo off

REM Stub DBGHELP.DLL and winspool.drv build script, must be run
REM from command prompt with microsoft development tools
REM (cl, dumpbin, link, etc.)

REM Let the user clean the build directory
if "%1"=="clean" goto l_clean

REM Let the user keep all files
if "%1"=="all" set DBGHELP_DEL_EXTRA_FILES=NO

REM Compiler options:
REM   /TP = C++ input
REM   /W2 = Warning level 2
REM   /WX = Treat warnings as errors
REM   /nologo = Don't print compiler information
REM   /fp:fast = Fast, even if inaccurate, floating point operations
REM   /GS- = Disable buffer security checking
REM   /EHa- = Disable exception handling
REM   /O1 = Optimize for size
REM   /GL = Enable whole program optimization
REM   /Gw = Optimize global data
REM   /GR- = Disable runtime type information
REM   /fp:except- = Disable floating point exceptions
REM   /DNDEBUG = Define NDEBUG to signify release build
REM   /D_DBGHELP = Define _DBGHELP in source
REM   /D_WINSPOOL = Define _WINSPOOL in source
REM
REM Linker options:
REM   /LTCG = Enable link-time code generation
REM   /ENTRY:DllMain = Make DllMain the entry point
REM   /NODEFAULTLIB = Don't link with the CRT
REM   /DLL = Output dynamic link library
REM   /OUT:<filename> = Make <filename> the output filename
REM   /INCREMENTAL:NO = Disable incremental linkage
cl.exe dllmain.cpp /TP /W2 /WX /nologo /fp:fast /GS- /EHa- /O1 /GL /Gw /GR- /fp:except- /DNDEBUG /D_DBGHELP /link /LTCG /ENTRY:DllMain /NODEFAULTLIB winmm.lib /DLL /OUT:DBGHELP.dll /INCREMENTAL:NO
cl.exe dllmain.cpp /TP /W2 /WX /nologo /fp:fast /GS- /EHa- /O1 /GL /Gw /GR- /fp:except- /DNDEBUG /D_WINSPOOL /link /LTCG /ENTRY:DllMain /NODEFAULTLIB winmm.lib /DLL /OUT:winspool.drv /INCREMENTAL:NO

if not "%DBGHELP_DEL_EXTRA_FILES%"=="NO" del DBGHELP.exp DBGHELP.lib winspool.exp winspool.lib dllmain.obj

goto l_end

:l_clean
del DBGHELP.dll DBGHELP.exp DBGHELP.lib winspool.drv winspool.exp winspool.lib dllmain.obj
goto l_end

:l_end
REM Don't keep variable set between multiple runs
set DBGHELP_DEL_EXTRA_FILES=YES
