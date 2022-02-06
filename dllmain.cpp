#define WNetGetConnectionA WNetGetConnectionA_orig
#include <windows.h>
#undef WNetGetConnectionA
#define DLLEXP extern "C" __declspec(dllexport) __stdcall

//dbghelp.dll
DLLEXP BOOL SymInitialize(void* a, void* b, void* c) {
	return TRUE;
}
DLLEXP BOOL MiniDumpWriteDump(void* a, void* b, void* c, void* d, void* e, void* f, void* g) {
	return TRUE;
}
DLLEXP BOOL SymFromAddr(void* a, void* b, void* c, void* d) {
	return TRUE;
}
DLLEXP BOOL SymGetSymFromAddr(void* a, void* b, void* c, void* d) {
	return TRUE;
}
DLLEXP BOOL SymSetOptions(void* a) {
	return TRUE;
}
DLLEXP DWORD SymGetOptions(void* a) {
	return 0;
}
DLLEXP DWORD WNetGetConnectionA(void* a, void* b, void* c) {
	return 0;
}
DLLEXP DWORD SymLoadModule64(void* a, void* b, void* c, void* d, void* e, void* f) {
	return 4096;
}
DLLEXP BOOL SymGetModuleInfo64(void* a, void* b, void* c) {
	return TRUE;
}
DLLEXP BOOL SymGetLineFromAddr64(void* a, void* b, void* c, void* d) {
	return TRUE;
}
DLLEXP BOOL SymGetSymFromAddr64(void* a, void* b, void* c, void* d) {
	return TRUE;
}


#define ClosePrinter ClosePrinter_orig
#undef ClosePrinter
#define DocumentPropertiesW DocumentPropertiesW_orig
#undef DocumentPropertiesW
#define EnumPrintersW EnumPrintersW_orig
#undef EnumPrintersW
#define GetDefaultPrinterW GetDefaultPrinterW_orig
#undef GetDefaultPrinterW
#define OpenPrinterW OpenPrinterW_orig
#undef OpenPrinterW
#define DocumentPropertiesA DocumentPropertiesA_orig
#undef DocumentPropertiesA
#define EnumPrintersA EnumPrintersA_orig
#undef EnumPrintersA
#define GetDefaultPrinterA GetDefaultPrinterA_orig
#undef GetDefaultPrinterA
#define OpenPrinterA OpenPrinterA_orig
#undef OpenPrinterA

//winspool.drv
DLLEXP WINBOOL ClosePrinter(HANDLE a) {return TRUE;}
DLLEXP LONG DocumentPropertiesW(HWND a, HANDLE b, LPWSTR c, PDEVMODEW d, PDEVMODEW e, DWORD f) {return 0;}
DLLEXP WINBOOL EnumPrintersW(DWORD a, LPWSTR b, DWORD c, LPBYTE d, DWORD e, LPDWORD f, LPDWORD g) {return TRUE;}
DLLEXP WINBOOL GetDefaultPrinterW(LPWSTR a, LPDWORD b) {return TRUE;}
DLLEXP WINBOOL OpenPrinterW(LPWSTR a, LPHANDLE b, LPPRINTER_DEFAULTSW c) {return TRUE;}
DLLEXP LONG DocumentPropertiesA(HWND a, HANDLE b, LPSTR c, PDEVMODEA d, PDEVMODEA e, DWORD f) {return 0;}
DLLEXP WINBOOL EnumPrintersA(DWORD a, LPSTR b, DWORD c, LPBYTE d, DWORD e, LPDWORD f, LPDWORD g) {return TRUE;}
DLLEXP WINBOOL GetDefaultPrinterA(LPSTR a, LPDWORD b) {return TRUE;}
DLLEXP WINBOOL OpenPrinterA(LPSTR a, LPHANDLE b, LPPRINTER_DEFAULTSA c) {return TRUE;}

BOOL WINAPI DllMain(HINSTANCE hinstDLL,DWORD fdwReason,LPVOID lpvReserved)
{
	timeBeginPeriod(1);
	return TRUE;
}
