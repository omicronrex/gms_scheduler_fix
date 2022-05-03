#include <windows.h>

// We need to export very specific symbol names,
// and name mangling gets in the way of that, so override
// the name mangler with an explicit EXPORT option
#define DLLEXP(_type, _funcname, _argsize) \
	__pragma(comment (linker, "/EXPORT:" #_funcname "=_" #_funcname "_overload@" #_argsize)); \
	extern "C" _type __stdcall _funcname ## _overload

//dbghelp.dll
DLLEXP(BOOL, SymInitialize, 12)(void* a, void* b, void* c) {
	return TRUE;
}
DLLEXP(BOOL, MiniDumpWriteDump, 28)(void* a, void* b, void* c, void* d, void* e, void* f, void* g) {
	return TRUE;
}
DLLEXP(BOOL, SymFromAddr, 16)(void* a, void* b, void* c, void* d) {
	return TRUE;
}
DLLEXP(BOOL, SymGetSymFromAddr, 16)(void* a, void* b, void* c, void* d) {
	return TRUE;
}
DLLEXP(BOOL, SymSetOptions, 4)(void* a) {
	return TRUE;
}
DLLEXP(DWORD, SymGetOptions, 4)(void* a) {
	return 0;
}
DLLEXP(DWORD, WNetGetConnectionA, 12)(void* a, void* b, void* c) {
	return 0;
}
DLLEXP(DWORD, SymLoadModule64, 24)(void* a, void* b, void* c, void* d, void* e, void* f) {
	return 4096;
}
DLLEXP(BOOL, SymGetModuleInfo64, 12)(void* a, void* b, void* c) {
	return TRUE;
}
DLLEXP(BOOL, SymGetLineFromAddr64, 16)(void* a, void* b, void* c, void* d) {
	return TRUE;
}
DLLEXP(BOOL, SymGetSymFromAddr64, 16)(void* a, void* b, void* c, void* d) {
	return TRUE;
}

//winspool.drv
DLLEXP(BOOL, ClosePrinter, 4)(HANDLE a) {return TRUE;}
DLLEXP(LONG, DocumentPropertiesW, 24)(HWND a, HANDLE b, LPWSTR c, PDEVMODEW d, PDEVMODEW e, DWORD f) {return 0;}
DLLEXP(BOOL, EnumPrintersW, 28)(DWORD a, LPWSTR b, DWORD c, LPBYTE d, DWORD e, LPDWORD f, LPDWORD g) {return TRUE;}
DLLEXP(BOOL, GetDefaultPrinterW, 8)(LPWSTR a, LPDWORD b) {return TRUE;}
DLLEXP(BOOL, OpenPrinterW, 12)(LPWSTR a, LPHANDLE b, LPPRINTER_DEFAULTSW c) {return TRUE;}
DLLEXP(LONG, DocumentPropertiesA, 24)(HWND a, HANDLE b, LPSTR c, PDEVMODEA d, PDEVMODEA e, DWORD f) {return 0;}
DLLEXP(BOOL, EnumPrintersA, 28)(DWORD a, LPSTR b, DWORD c, LPBYTE d, DWORD e, LPDWORD f, LPDWORD g) {return TRUE;}
DLLEXP(BOOL, GetDefaultPrinterA, 8)(LPSTR a, LPDWORD b) {return TRUE;}
DLLEXP(BOOL, OpenPrinterA, 12)(LPSTR a, LPHANDLE b, LPPRINTER_DEFAULTSA c) {return TRUE;}

BOOL WINAPI DllMain(HINSTANCE hinstDLL,DWORD fdwReason,LPVOID lpvReserved)
{
	timeBeginPeriod(1);
	return TRUE;
}
