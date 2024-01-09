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
// WINAPI usada..

h_OpenThread pOpenThread=0;
h_AddVectoredExceptionHandler pAddVectoredExceptionHandler=0;
h_RemoveVectoredExceptionHandler pRemoveVectoredExceptionHandler=0;
h_GetProcAddress pGetProcAddress = 0;
h_GetThreadContext pGetThreadContext = 0;
h_SetThreadContext pSetThreadContext=0;
h_GetModuleHandleA pGetModuleHandleA=0;
h_GetCurrentThread pGetCurrentThread =0;
h_SuspendThread pSuspendThread=0;
h_ResumeThread pResumeThread=0;
h_CloseHandle pCloseHandle=0;
h_CreateRemoteThread pCreateRemoteThread=0;
h_GetCurrentProcess pGetCurrentProcess = 0;
h_DisableThreadLibraryCalls pDisableThreadLibraryCalls = 0;
h_GetModuleFileNameA pGetModuleFileNameA=0;
t_Sleep pSleep = 0;
h_GetCurrentProcessId pGetCurrentProcessId=0;

//-------------------------------------------------------------------//

int InitWINAPICallGates1()
{
	int iRet = 0;

	//

	pGetModuleHandleA=(h_GetModuleHandleA)pGetProcAddress(
		GetModuleHandle(/*KERNEL32.dll\0*/XorStr<0x3F,14,0xB1811D0D>("\x74\x05\x13\x0C\x06\x08\x76\x74\x69\x2C\x25\x26\x4B"+0xB1811D0D).s)
		, /*GetModuleHandleA\0*/XorStr<0x95,18,0xAA67AEAB>("\xD2\xF3\xE3\xD5\xF6\xFE\xEE\xF0\xF8\xD6\xFE\xCE\xC5\xCE\xC6\xE5\xA5"+0xAA67AEAB).s);
	if(!pGetModuleHandleA) iRet = -1;

//	MessageBox(0,"1\0",0,0);

//	char JJ[200];
//	sprintf(JJ, "pGetModuleHandleA 0x%X (0x%X)\0", pGetModuleHandleA, GetModuleHandle);
//	MessageBox(0,JJ,0,0);

	//

	pGetThreadContext =(h_GetThreadContext)pGetProcAddress(
		pGetModuleHandleA(/*KERNEL32.dll\0*/XorStr<0x3F,14,0xB1811D0D>("\x74\x05\x13\x0C\x06\x08\x76\x74\x69\x2C\x25\x26\x4B"+0xB1811D0D).s), /*GetThreadContext\0*/XorStr<0xED,18,0x05209688>("\xAA\x8B\x9B\xA4\x99\x80\x96\x95\x91\xB5\x98\x96\x8D\x9F\x83\x88\xFD"+0x05209688).s);
	if(!pGetThreadContext) iRet = -2;

	pCloseHandle=(h_CloseHandle)pGetProcAddress(
		pGetModuleHandleA(/*KERNEL32.dll\0*/XorStr<0x3F,14,0xB1811D0D>("\x74\x05\x13\x0C\x06\x08\x76\x74\x69\x2C\x25\x26\x4B"+0xB1811D0D).s), /*CloseHandle\0*/XorStr<0xFF,13,0x3C5B74F7>("\xBC\x6C\x6E\x71\x66\x4C\x64\x68\x63\x64\x6C\x0A"+0x3C5B74F7).s);
	if(!pCloseHandle) iRet = -3;

	pCreateRemoteThread=(h_CreateRemoteThread)pGetProcAddress(
		pGetModuleHandleA(/*KERNEL32.dll\0*/XorStr<0x3F,14,0xB1811D0D>("\x74\x05\x13\x0C\x06\x08\x76\x74\x69\x2C\x25\x26\x4B"+0xB1811D0D).s), /*CreateRemoteThread\0*/XorStr<0x61,20,0x963FEEE0>("\x22\x10\x06\x05\x11\x03\x35\x0D\x04\x05\x1F\x09\x39\x06\x1D\x15\x10\x16\x73"+0x963FEEE0).s);
	if(!pCreateRemoteThread) iRet = -4;

	//

	pSetThreadContext=(h_SetThreadContext)pGetProcAddress(
		pGetModuleHandleA(/*KERNEL32.dll\0*/XorStr<0x3F,14,0xB1811D0D>("\x74\x05\x13\x0C\x06\x08\x76\x74\x69\x2C\x25\x26\x4B"+0xB1811D0D).s), /*SetThreadContext\0*/XorStr<0xE3,18,0x30D60D0C>("\xB0\x81\x91\xB2\x8F\x9A\x8C\x8B\x8F\xAF\x82\x80\x9B\x95\x89\x86\xF3"+0x30D60D0C).s);
	if(!pSetThreadContext) iRet = -5;

	pGetCurrentThread =(h_GetCurrentThread)pGetProcAddress(
		pGetModuleHandleA(/*KERNEL32.dll\0*/XorStr<0x3F,14,0xB1811D0D>("\x74\x05\x13\x0C\x06\x08\x76\x74\x69\x2C\x25\x26\x4B"+0xB1811D0D).s), /*GetCurrentThread\0*/XorStr<0x95,18,0x5CA0DBF9>("\xD2\xF3\xE3\xDB\xEC\xE8\xE9\xF9\xF3\xEA\xCB\xC8\xD3\xC7\xC2\xC0\xA5"+0x5CA0DBF9).s);
	if(!pGetCurrentThread) iRet = -6;

	pSuspendThread=(h_SuspendThread)pGetProcAddress(
		pGetModuleHandleA(/*KERNEL32.dll\0*/XorStr<0x3F,14,0xB1811D0D>("\x74\x05\x13\x0C\x06\x08\x76\x74\x69\x2C\x25\x26\x4B"+0xB1811D0D).s), /*SuspendThread\0*/XorStr<0x35,15,0xA9F98F71>("\x66\x43\x44\x48\x5C\x54\x5F\x68\x55\x4C\x5A\x21\x25\x42"+0xA9F98F71).s);
	if(!pSuspendThread) iRet = -7;

	pResumeThread=(h_ResumeThread)pGetProcAddress(
		pGetModuleHandleA(/*KERNEL32.dll\0*/XorStr<0x3F,14,0xB1811D0D>("\x74\x05\x13\x0C\x06\x08\x76\x74\x69\x2C\x25\x26\x4B"+0xB1811D0D).s), /*ResumeThread\0*/XorStr<0x50,14,0x7400546B>("\x02\x34\x21\x26\x39\x30\x02\x3F\x2A\x3C\x3B\x3F\x5C"+0x7400546B).s);
	if(!pResumeThread) iRet = -8;

	//

	pGetCurrentProcess = (h_GetCurrentProcess)pGetProcAddress(
		pGetModuleHandleA(/*KERNEL32.dll\0*/XorStr<0x3F,14,0xB1811D0D>("\x74\x05\x13\x0C\x06\x08\x76\x74\x69\x2C\x25\x26\x4B"+0xB1811D0D).s), /*GetCurrentProcess\0*/XorStr<0x30,19,0x6E6AEB3F>("\x77\x54\x46\x70\x41\x47\x44\x52\x56\x4D\x6A\x49\x53\x5E\x5B\x4C\x33\x41"+0x6E6AEB3F).s);

	if(!pGetCurrentProcess) iRet = -9;


	pDisableThreadLibraryCalls = (h_DisableThreadLibraryCalls)pGetProcAddress(
		pGetModuleHandleA(/*KERNEL32.dll\0*/XorStr<0x3F,14,0xB1811D0D>("\x74\x05\x13\x0C\x06\x08\x76\x74\x69\x2C\x25\x26\x4B"+0xB1811D0D).s), /*DisableThreadLibraryCalls\0*/XorStr<0x26,27,0x821D6E7B>("\x62\x4E\x5B\x48\x48\x47\x49\x79\x46\x5D\x55\x50\x56\x7F\x5D\x57\x44\x56\x4A\x40\x79\x5A\x50\x51\x4D\x3F"+0x821D6E7B).s);

	if(!pDisableThreadLibraryCalls) iRet = -10;

	//

	pOpenThread=(h_OpenThread)pGetProcAddress(
		pGetModuleHandleA(
		
		/*KERNEL32.dll\0*/XorStr<0x3F,14,0xB1811D0D>("\x74\x05\x13\x0C\x06\x08\x76\x74\x69\x2C\x25\x26\x4B"+0xB1811D0D).s
		)
		, 
		
		/*OpenThread\0*/XorStr<0x59,12,0xBA70E583>("\x16\x2A\x3E\x32\x09\x36\x2D\x05\x00\x06\x63"+0xBA70E583).s
		);

	if(!pOpenThread)
	{
		iRet = -11;
	}

	//

	pAddVectoredExceptionHandler=(h_AddVectoredExceptionHandler)pGetProcAddress(
		pGetModuleHandleA(
		
		/*KERNEL32.dll\0*/XorStr<0x3F,14,0xB1811D0D>("\x74\x05\x13\x0C\x06\x08\x76\x74\x69\x2C\x25\x26\x4B"+0xB1811D0D).s
		)
		, 
		/*AddVectoredExceptionHandler\0*/XorStr<0x16,29,0x6457BCF9>("\x57\x73\x7C\x4F\x7F\x78\x68\x72\x6C\x7A\x44\x64\x5A\x40\x41\x55\x52\x4E\x47\x47\x62\x4A\x42\x49\x42\x4A\x42\x31"+0x6457BCF9).s
		);

	if(!pAddVectoredExceptionHandler)
	{
		iRet = -12;
	}

	//

	pRemoveVectoredExceptionHandler=(h_RemoveVectoredExceptionHandler)pGetProcAddress(
		pGetModuleHandleA(

		/*KERNEL32.dll\0*/XorStr<0x3F,14,0xB1811D0D>("\x74\x05\x13\x0C\x06\x08\x76\x74\x69\x2C\x25\x26\x4B"+0xB1811D0D).s
		)
		, 
		/*RemoveVectoredExceptionHandler\0*/XorStr<0xC6,32,0x364A6077>("\x94\xA2\xA5\xA6\xBC\xAE\x9A\xA8\xAD\xBB\xBF\xA3\xB7\xB7\x91\xAD\xB5\xB2\xA8\xAD\xB3\xB4\xB2\x95\xBF\xB1\x84\x8D\x87\x91\xE4"+0x364A6077).s
		);

	if(!pRemoveVectoredExceptionHandler)
	{
		iRet = -13;
	}

	//

	pGetModuleFileNameA = (h_GetModuleFileNameA)pGetProcAddress(
		pGetModuleHandleA(/*KERNEL32.dll\0*/XorStr<0x3F,14,0xB1811D0D>("\x74\x05\x13\x0C\x06\x08\x76\x74\x69\x2C\x25\x26\x4B"+0xB1811D0D).s), 
		/*GetModuleFileNameA\0*/XorStr<0x2A,20,0x873F3515>("\x6D\x4E\x58\x60\x41\x4B\x45\x5D\x57\x75\x5D\x59\x53\x79\x59\x54\x5F\x7A\x3C"+0x873F3515).s);

	if(!pGetModuleFileNameA) iRet = -14;


	//

	pSleep = (t_Sleep)pGetProcAddress(
		pGetModuleHandleA(/*KERNEL32.dll\0*/XorStr<0x3F,14,0xB1811D0D>("\x74\x05\x13\x0C\x06\x08\x76\x74\x69\x2C\x25\x26\x4B"+0xB1811D0D).s), 
		/*Sleep\0*/XorStr<0xE0,7,0x9D207CF7>("\xB3\x8D\x87\x86\x94\xE5"+0x9D207CF7).s);

	if(!pSleep) iRet = -15;


	//
	
	pGetCurrentProcessId=(h_GetCurrentProcessId)pGetProcAddress(
		pGetModuleHandleA(/*KERNEL32.dll\0*/XorStr<0x3F,14,0xB1811D0D>("\x74\x05\x13\x0C\x06\x08\x76\x74\x69\x2C\x25\x26\x4B"+0xB1811D0D).s), 
		/*GetCurrentProcessId\0*/XorStr<0x8C,21,0xCB5B5405>("\xCB\xE8\xFA\xCC\xE5\xE3\xE0\xF6\xFA\xE1\xC6\xE5\xF7\xFA\xFF\xE8\xEF\xD4\xFA\x9F"+0xCB5B5405).s);

	if(!pGetCurrentProcessId) iRet = -16;


	return iRet;
}

//-------------------------------------------------------------------//












































