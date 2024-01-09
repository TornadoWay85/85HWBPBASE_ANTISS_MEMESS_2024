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

#include "mainheaders.h"

//-------------------------------------------------------------------//

HANDLE g_MainThread = 0;
DWORD g_TID=0;

//-------------------------------------------------------------------//

DWORD dwBreakAddress1 = 0;
DWORD dwBreakAddress2 = 0;
DWORD dwBreakAddress3 = 0;
DWORD dwBreakAddress4 = 0;
//
void* handlerx1 = 0;
void* handlerx2 = 0;
void* handlerx3 = 0;
void* handlerx4 = 0;
//
bool bHWBP1Used = false;
bool bHWBP2Used = false;
bool bHWBP3Used = false;
bool bHWBP4Used = false;
//
bool g_bHWBP1Installed = false;
bool g_bHWBP2Installed = false;
bool g_bHWBP3Installed = false;
bool g_bHWBP4Installed = false;
//
DWORD dwCallGate1 = (DWORD)&CallGate_GL_Read_Pixels;// hook READPIXELS.cpp
DWORD dwCallGate2 = 0;
DWORD dwCallGate3 = 0;
DWORD dwCallGate4 = 0;

//-------------------------------------------------------------------//

DWORD GetBreakAddress1();
DWORD GetBreakAddress2();
DWORD GetBreakAddress3();
DWORD GetBreakAddress4();

//-------------------------------------------------------------------//

DWORD GetProcessThreadId(unsigned long ProcessId)
{ 
    HANDLE hSnapThread = CreateToolhelp32Snapshot(TH32CS_SNAPTHREAD, ProcessId);
    if(hSnapThread == INVALID_HANDLE_VALUE) return NULL;
    THREADENTRY32 te;
    te.dwSize = sizeof(THREADENTRY32);
    if(Thread32First(hSnapThread, &te)){
       do{
		   if(te.th32OwnerProcessID == ProcessId){
			   pCloseHandle(hSnapThread);
			   return te.th32ThreadID;
            }
       } while(Thread32Next(hSnapThread, &te));
    }
    pCloseHandle(hSnapThread);
    return 0;
}

//-------------------------------------------------------------------//

void* GetMainThread(){
	return (void*)pGetCurrentThread();
}

void SetMainThread(DWORD dwVal/*GetMainThread()*/){
	g_MainThread = (void*)dwVal;
}

//-------------------------------------------------------------------//

DWORD GetMainThreadTID(){
	DWORD ProcessId1 = pGetCurrentProcessId();
	if(ProcessId1<1) return 0;
	DWORD dwThreadId = GetProcessThreadId(ProcessId1);
	return dwThreadId;
}

void SetMainThreadTID(DWORD dwVal/*GetMainThreadTID()*/){
	g_TID=dwVal;
}

//-------------------------------------------------------------------//
//-------------------------------------------------------------------//
//-------------------------------------------------------------------//
//-------------------------------------------------------------------//
//-------------------------------------------------------------------//

LONG WINAPI HANDLER_BREAKPOINT1(struct _EXCEPTION_POINTERS* ExceptionInfo){
	if(ExceptionInfo->ExceptionRecord->ExceptionCode == EXCEPTION_SINGLE_STEP){
		if (ExceptionInfo->ExceptionRecord->ExceptionAddress == (HANDLE)GetBreakAddress1()){
			ExceptionInfo->ContextRecord->Eip = (DWORD)dwCallGate1;
			return EXCEPTION_CONTINUE_EXECUTION;
		}}
	return EXCEPTION_CONTINUE_SEARCH;
}

LONG WINAPI HANDLER_BREAKPOINT2(struct _EXCEPTION_POINTERS* ExceptionInfo){
	if(ExceptionInfo->ExceptionRecord->ExceptionCode == EXCEPTION_SINGLE_STEP){
		if (ExceptionInfo->ExceptionRecord->ExceptionAddress == (HANDLE)GetBreakAddress2()){
			ExceptionInfo->ContextRecord->Eip = (DWORD)dwCallGate2;
			return EXCEPTION_CONTINUE_EXECUTION;
		}}
	return EXCEPTION_CONTINUE_SEARCH;
}

LONG WINAPI HANDLER_BREAKPOINT3(struct _EXCEPTION_POINTERS* ExceptionInfo){
	if(ExceptionInfo->ExceptionRecord->ExceptionCode == EXCEPTION_SINGLE_STEP){
		if (ExceptionInfo->ExceptionRecord->ExceptionAddress == (HANDLE)GetBreakAddress3()){
			ExceptionInfo->ContextRecord->Eip = (DWORD)dwCallGate3;
			return EXCEPTION_CONTINUE_EXECUTION;
		}}
	return EXCEPTION_CONTINUE_SEARCH;
}

LONG WINAPI HANDLER_BREAKPOINT4(struct _EXCEPTION_POINTERS* ExceptionInfo){
	if(ExceptionInfo->ExceptionRecord->ExceptionCode == EXCEPTION_SINGLE_STEP){
		if (ExceptionInfo->ExceptionRecord->ExceptionAddress == (HANDLE)GetBreakAddress4()){
			ExceptionInfo->ContextRecord->Eip = (DWORD)dwCallGate4;
			return EXCEPTION_CONTINUE_EXECUTION;
		}}
	return EXCEPTION_CONTINUE_SEARCH;
}

//-------------------------------------------------------------------//

void InitBreakAddresses()// inicializar tus funciones para interceptar con HWBP aquíii
{
	dwBreakAddress1 = (DWORD)pGetProcAddress(pGetModuleHandleA(/*Opengl32.dll\0*/XorStr<0x47,14,0xC84F04B6>("\x08\x38\x2C\x24\x2C\x20\x7E\x7C\x61\x34\x3D\x3E\x53"+0xC84F04B6).s), 
		/*glReadPixels\0*/XorStr<0xA3,14,0x01751038>("\xC4\xC8\xF7\xC3\xC6\xCC\xF9\xC3\xD3\xC9\xC1\xDD\xAF"+0x01751038).s);

//	char GG[200];
//	sprintf(GG, "dwBreakAddress1 0x%X (0x%X)\0", dwBreakAddress1, glReadPixels);
//	MessageBox(0,GG,0,0);

	dwBreakAddress2 = 0;
	dwBreakAddress3 = 0;
	dwBreakAddress4 = 0;
}

//-------------------------------------------------------------------//

void InitHandlers()// los CallGate's se inicializan globalmente (se puede hacer aquí tmb)
{
	InitBreakAddresses();

	if(dwBreakAddress1){
		if(dwCallGate1){
			handlerx1 = &HANDLER_BREAKPOINT1;
			bHWBP1Used = true;
		}
	}
/*	if(dwBreakAddress2){
		if(dwCallGate2){
			handlerx2 = &HANDLER_BREAKPOINT2;
			bHWBP2Used = true;
		}
	}
	if(dwBreakAddress3){
		if(dwCallGate3){
			handlerx3 = &HANDLER_BREAKPOINT3;
			bHWBP3Used = true;
		}
	}
	if(dwBreakAddress4){
		if(dwCallGate4){
			handlerx4 = &HANDLER_BREAKPOINT4;
			bHWBP4Used = true;
		}
	}*/
}

//-------------------------------------------------------------------//

DWORD GetBreakAddress1() {return dwBreakAddress1;}
DWORD GetBreakAddress2() {return dwBreakAddress2;}
DWORD GetBreakAddress3() {return dwBreakAddress3;}
DWORD GetBreakAddress4() {return dwBreakAddress4;}

//-------------------------------------------------------------------//

void* AddVEHAddress(unsigned long uiFirst, void* hHandler, bool bBP)
{
	//First
	//The order in which the handler should be called. 
	//If the parameter is nonzero, the handler is the first handler to be called. 
	//If the parameter is zero, the handler is the last handler to be called.

	HANDLE pHandler = 0;				
	if(bBP)
		pHandler = pAddVectoredExceptionHandler(uiFirst, (PVECTORED_EXCEPTION_HANDLER)hHandler);
	return pHandler;
}

//-------------------------------------------------------------------//

void InitGlobalFlags()
{
	//
	g_bHWBP1Installed = true;
//	g_bHWBP2Installed = true;
//	g_bHWBP3Installed = true;
//	g_bHWBP4Installed = true;

}

//-------------------------------------------------------------------//

bool GetHWBPState(unsigned int iIndex)
{
	if(iIndex==1) return g_bHWBP1Installed;
	if(iIndex==2) return g_bHWBP2Installed;
	if(iIndex==3) return g_bHWBP3Installed;
	if(iIndex==4) return g_bHWBP4Installed;
	return false;
}

//-------------------------------------------------------------------//

int InstallHardwareBreakpoints()// se debe llamar desde un hilo secundario
{
	int iReturnValue = 0;

	if(!g_TID)
	{
		iReturnValue = -601;
	}

	if(!iReturnValue)
	{
		InitHandlers();
		//
		//
		HANDLE hMainT=pOpenThread(
			THREAD_ALL_ACCESS
			,FALSE
			,g_TID
			);

		if(hMainT)
		{
		//	if(!hMainT)
			if(hMainT == pGetCurrentThread())
			{
				pCloseHandle(hMainT);
				iReturnValue = -602;
			}

			if(!iReturnValue)
			{
				DWORD dwSuspend = pSuspendThread(hMainT);
				if(dwSuspend == (DWORD) -1)
				{
				//	pCloseHandle(hMainT);
					iReturnValue = -603;
				}

				if(!iReturnValue)
				{
					CONTEXT sContext;
				//	CONTEXT sContext2;
					//
				//	sContext.ContextFlags=CONTEXT_ALL;
					sContext.ContextFlags=CONTEXT_FULL|CONTEXT_DEBUG_REGISTERS;
					//
					int iThreadContext = pGetThreadContext(hMainT,&sContext);
					if(!iThreadContext)
					{
					//	pResumeThread(hMainT);
					//	pCloseHandle(hMainT);
						iReturnValue = -604;
					}

					if(!iReturnValue)
					{
					//	memcpy(&sContext2, &sContext, sizeof(CONTEXT));

						//

						sContext.Dr6 = 0x00000000;
						sContext.Dr7 = 0x00000000;

						if(bHWBP1Used)
						{
							sContext.Dr0 = (DWORD)GetBreakAddress1();
						//	sContext.Dr1 = (DWORD)GetBreakAddress2();
						//	sContext.Dr2 = (DWORD)GetBreakAddress3();
						//	sContext.Dr3 = (DWORD)GetBreakAddress4();
							//
							sContext.Dr7 |= 1 << ( 2 * 0 ) | 0x100;
						}

						//

						int iSetContext = pSetThreadContext(hMainT, &sContext);
						if(!iSetContext)
						{
						//	pResumeThread(hMainT);
						//	pCloseHandle(hMainT);
							iReturnValue = -605;
						}

						if(!iReturnValue)
						{

							if(!AddVEHAddress(1, handlerx1, bHWBP1Used))
							{
							//	pSetThreadContext(hMainT, &sContext1);//Restaura
							//	pResumeThread(hMainT);
							//	pCloseHandle(hMainT);
								iReturnValue = -606;
							}

					/*		if(!AddVEHAddress(1, handlerx2, bHWBP2Used))
							{
							//	pSetThreadContext(hMainT, &sContext1);//Restaura
							//	pResumeThread(hMainT);
							//	pCloseHandle(hMainT);
								iReturnValue = -607;
							}

							if(!AddVEHAddress(1, handlerx3, bHWBP3Used))
							{
							//	pSetThreadContext(hMainT, &sContext1);//Restaura
							//	pResumeThread(hMainT);
							//	pCloseHandle(hMainT);
								iReturnValue = -608;
							}

							if(!AddVEHAddress(1, handlerx4, bHWBP4Used))
							{
							//	pSetThreadContext(hMainT, &sContext1);//Restaura
							//	pResumeThread(hMainT);
							//	pCloseHandle(hMainT);
								iReturnValue = -609;
							}*/

							if(!iReturnValue)
							{
								DWORD dwResume = pResumeThread(hMainT);
							//	if(dwResume == (DWORD) -1) 
							//	{
							//	}

							//	pRemoveVectoredExceptionHandler(handlerx1);
							//	pRemoveVectoredExceptionHandler(handlerx2);
							//	pRemoveVectoredExceptionHandler(handlerx3);
							//	pRemoveVectoredExceptionHandler(handlerx4);
							}
						}
					}
				}
			}

			pCloseHandle(hMainT);
		}

		//
		InitGlobalFlags();

	}

	return iReturnValue;
}

//-------------------------------------------------------------------//

int g_iRetValHWBP = 0;

void SetReturnValue(int iRetX)
{
	g_iRetValHWBP = iRetX;
}

int GetReturnValue()
{
	return g_iRetValHWBP;
}

//-------------------------------------------------------------------//

DWORD WINAPI SetupHWBPHooks( LPVOID param )
{
	if(!GetReturnValue())
	{
		int iResult = InstallHardwareBreakpoints();
		if(iResult<0)
		{
		//	logme1("InstallHardwareBreakpoints() ERRORCODE = %d\0", iResult);
			SetReturnValue(-1005);
		}
	}

	//
	//

	if(!GetReturnValue())// esta parte es específica del ANTISS
	{
		bAntiSSInstalledOK = GetHWBPState(1);
		if(!bAntiSSInstalledOK)
		{
			SetReturnValue(-1006);
		}
	}

	return 0;
}

//-------------------------------------------------------------------//

void INITHWBP()
{
	if(!GetReturnValue())
	{
		SetMainThread((DWORD)GetMainThread());
		if(!GetMainThread()) SetReturnValue(-1001);
	}

	if(!GetReturnValue())
	{
		SetMainThreadTID(GetMainThreadTID());
		if(!GetMainThreadTID()) SetReturnValue(-1002);
	}

	if(!GetReturnValue())
	{
		int iInit = InitOpenGLPointers();
		if(iInit == -1) SetReturnValue(-1003);
		if(iInit == -2) SetReturnValue(-1004);
	}

}

//-------------------------------------------------------------------//
