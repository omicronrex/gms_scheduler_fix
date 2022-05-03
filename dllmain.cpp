#include <windows.h>

// We need to export very specific symbol names,
// and name mangling gets in the way of that, so override
// the name mangler with an explicit EXPORT option
#define DLLEXP(_type, _funcname, _argsize) \
	__pragma(comment (linker, "/EXPORT:" #_funcname "=_" #_funcname "_overload@" #_argsize)); \
	extern "C" _type __stdcall _funcname ## _overload

#define DLLEXP4(_type, _funcname) DLLEXP(_type, _funcname, 4)(int)
#define DLLEXP8(_type, _funcname) DLLEXP(_type, _funcname, 8)(int,int)
#define DLLEXP12(_type, _funcname) DLLEXP(_type, _funcname, 12)(int,int,int)
#define DLLEXP16(_type, _funcname) DLLEXP(_type, _funcname, 16)(int,int,int,int)
#define DLLEXP20(_type, _funcname) DLLEXP(_type, _funcname, 20)(int,int,int,int,int)
#define DLLEXP24(_type, _funcname) DLLEXP(_type, _funcname, 24)(int,int,int,int,int,int)
#define DLLEXP28(_type, _funcname) DLLEXP(_type, _funcname, 28)(int,int,int,int,int,int,int)

//dbghelp.dll
#ifdef _DBGHELP
DLLEXP12(BOOL, SymInitialize) {return TRUE;}
DLLEXP28(BOOL, MiniDumpWriteDump) {return TRUE;}
DLLEXP16(BOOL, SymFromAddr) {return TRUE;}
DLLEXP16(BOOL, SymGetSymFromAddr) {return TRUE;}
DLLEXP4(BOOL, SymSetOptions) {return TRUE;}
DLLEXP4(DWORD, SymGetOptions) {return 0;}
DLLEXP12(DWORD, WNetGetConnectionA) {return 0;}
DLLEXP24(DWORD, SymLoadModule64) {return 4096;}
DLLEXP12(BOOL, SymGetModuleInfo64) {return TRUE;}
DLLEXP16(BOOL, SymGetLineFromAddr64) {return TRUE;}
DLLEXP16(BOOL, SymGetSymFromAddr64) {return TRUE;}
#endif

//winspool.drv
#ifdef _WINSPOOL
DLLEXP4(BOOL, ClosePrinter) {return TRUE;}
DLLEXP24(LONG, DocumentPropertiesW) {return 0;}
DLLEXP24(LONG, DocumentPropertiesA) {return 0;}
DLLEXP28(BOOL, EnumPrintersW) {return TRUE;}
DLLEXP28(BOOL, EnumPrintersA) {return TRUE;}
DLLEXP8(BOOL, GetDefaultPrinterW) {return TRUE;}
DLLEXP8(BOOL, GetDefaultPrinterA) {return TRUE;}
DLLEXP12(BOOL, OpenPrinterW) {return TRUE;}
DLLEXP12(BOOL, OpenPrinterA) {return TRUE;}
#endif

BOOL WINAPI DllMain(HINSTANCE hinstDLL,DWORD fdwReason,LPVOID lpvReserved)
{
	timeBeginPeriod(1);
	return TRUE;
}
