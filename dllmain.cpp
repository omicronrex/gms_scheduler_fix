#include <windows.h>

extern "C" __declspec(dllexport) __stdcall BOOL SymInitialize(void* a, void* b, void* c) {
	return TRUE;
}
extern "C" __declspec(dllexport) __stdcall BOOL MiniDumpWriteDump(void* a, void* b, void* c, void* d, void* e, void* f, void* g) {
	return TRUE;
}
extern "C" __declspec(dllexport) __stdcall BOOL SymFromAddr(void* a, void* b, void* c, void* d) {
	return TRUE;
}


BOOL WINAPI DllMain(HINSTANCE hinstDLL,DWORD fdwReason,LPVOID lpvReserved)
{
	switch(fdwReason)
	{
		case DLL_PROCESS_ATTACH:
		{
			timeBeginPeriod((UINT)1);
			break;
		}
		case DLL_PROCESS_DETACH:
		{
			timeEndPeriod((UINT)1);
			break;
		}
		case DLL_THREAD_ATTACH:
		{
			break;
		}
		case DLL_THREAD_DETACH:
		{
			break;
		}
	}
	
	/* Return TRUE on success, FALSE on failure */
	return TRUE;
}
