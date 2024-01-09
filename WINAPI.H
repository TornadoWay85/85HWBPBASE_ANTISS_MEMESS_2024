///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// 85 HARDWARE BREAKPOINT BASE
//
// BY _85_ , (2024)
//
// Credits: Russian bases, OGC and Kyros Base code and ideas, gamedeception guys, unknowncheats.me, and VALVE!
//
// Tested on latest Steam CS version (Jan2024), beta versions, non-steam v43, maybe others
//
// https://cs85-etkboyscout.blogspot.com
// https://www.youtube.com/@TornadoWayOfficial
// david_85_arg@hotmail.com
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

//-------------------------------------------------------------------//

typedef FARPROC (WINAPI* h_GetProcAddress)(HMODULE hModule,LPCSTR  lpProcName);
extern h_GetProcAddress pGetProcAddress;

typedef BOOL (WINAPI* h_GetThreadContext)(
HANDLE    hThread,
LPCONTEXT lpContext
);

typedef BOOL (WINAPI* h_SetThreadContext)(
HANDLE        hThread,
const CONTEXT *lpContext
);

typedef HMODULE (WINAPI* h_GetModuleHandleA)(
LPCSTR lpModuleName
);

typedef HANDLE (WINAPI* h_GetCurrentThread)();

typedef DWORD (WINAPI* h_SuspendThread)(
HANDLE hThread
);

typedef DWORD (WINAPI* h_ResumeThread)(
HANDLE hThread
);

typedef BOOL (WINAPI* h_CloseHandle)(
HANDLE hObject
);

typedef HANDLE (WINAPI* h_CreateRemoteThread)(
HANDLE                 hProcess,
LPSECURITY_ATTRIBUTES  lpThreadAttributes,
SIZE_T                 dwStackSize,
LPTHREAD_START_ROUTINE lpStartAddress,
LPVOID                 lpParameter,
DWORD                  dwCreationFlags,
LPDWORD                lpThreadId
);

typedef HANDLE (WINAPI* h_GetCurrentProcess)();

typedef BOOL (WINAPI* h_DisableThreadLibraryCalls)(HMODULE hLibModule);

extern h_GetProcAddress pGetProcAddress;
extern h_GetThreadContext pGetThreadContext;
extern h_SetThreadContext pSetThreadContext;
extern h_GetModuleHandleA pGetModuleHandleA;
extern h_GetCurrentThread pGetCurrentThread;
extern h_SuspendThread pSuspendThread;
extern h_ResumeThread pResumeThread;
extern h_CloseHandle pCloseHandle;
extern h_CreateRemoteThread pCreateRemoteThread;
extern h_GetCurrentProcess pGetCurrentProcess;
extern h_DisableThreadLibraryCalls pDisableThreadLibraryCalls;

#define CONTEXT_ALL (CONTEXT_CONTROL | CONTEXT_INTEGER | CONTEXT_SEGMENTS | CONTEXT_FLOATING_POINT | CONTEXT_DEBUG_REGISTERS)
//typedef (WINAPI *PVECTORED_EXCEPTION_HANDLER)(struct _EXCEPTION_POINTERS *ExceptionInfo);
typedef LONG (WINAPI *PVECTORED_EXCEPTION_HANDLER)(PEXCEPTION_POINTERS);
typedef HANDLE (WINAPI* h_OpenThread)(DWORD dwDesiredAccess,BOOL  bInheritHandle,DWORD dwThreadId);
typedef PVOID (WINAPI* h_AddVectoredExceptionHandler)(ULONG FirstHandler,PVECTORED_EXCEPTION_HANDLER VectoredHandler);
typedef ULONG (WINAPI* h_RemoveVectoredExceptionHandler)(PVOID VectoredHandlerHandle);
extern h_OpenThread pOpenThread;
extern h_AddVectoredExceptionHandler pAddVectoredExceptionHandler;
extern h_RemoveVectoredExceptionHandler pRemoveVectoredExceptionHandler;

typedef DWORD (WINAPI* h_GetModuleFileNameA)(HMODULE hModule,LPSTR   lpFilename,DWORD   nSize);
extern h_GetModuleFileNameA pGetModuleFileNameA;

typedef void (WINAPI* t_Sleep)(DWORD dwMilliseconds);// TRAMPA!!!!!!!!!!
extern t_Sleep pSleep;

typedef DWORD (WINAPI* h_GetCurrentProcessId)();
extern h_GetCurrentProcessId pGetCurrentProcessId;

//-------------------------------------------------------------------//

int InitWINAPICallGates1();

//-------------------------------------------------------------------//
