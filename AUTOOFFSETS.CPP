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

cl_clientfunc_t * g_pClient=0;
cl_clientfunc_t g_Client;
//ClientDll_t gClientDll;

cl_enginefuncs_s * pEngfuncs = (cl_enginefuncs_s *)0;
struct cl_enginefuncs_s gEngfuncs;

engine_studio_api_s * pstudio = (engine_studio_api_s*)0;
struct engine_studio_api_s IEngineStudio;

//-------------------------------------------------------------------//

DWORD HL_EXE_HANDLE = 0;
DWORD HL_EXE_BASE = 0;
DWORD HL_EXE_SIZE = 0;
DWORD HL_EXE_END = 0;

DWORD SW_MODULE_HANDLE = 0;
DWORD SW_MODULE_BASE = 0;
DWORD SW_MODULE_SIZE = 0;

DWORD HW_MODULE_HANDLE = 0;
DWORD HW_MODULE_BASE = 0;
DWORD HW_MODULE_SIZE = 0;
DWORD HW_MODULE_END = 0;

DWORD CLIENT_MODULE_HANDLE = 0;
DWORD CLIENT_MODULE_BASE = 0;
DWORD CLIENT_MODULE_SIZE = 0;
DWORD CLIENT_MODULE_END = 0;

DWORD VgBase = 0;
DWORD VgSize = 0;
DWORD VgEnd = 0;

//-------------------------------------------------------------------//

DWORD GetModuleSize( DWORD Address )
{
	return PIMAGE_NT_HEADERS( Address + (DWORD)PIMAGE_DOS_HEADER( Address )->e_lfanew )->OptionalHeader.SizeOfImage;
}

//-------------------------------------------------------------------//

void GetRenderType()
{
	char hw_dll[] = { 'h','w','.','d','l','l',0 };
	char sw_dll[] = { 's','w','.','d','l','l',0 };
	
	HW_MODULE_HANDLE = (DWORD)pGetModuleHandleA( hw_dll );
	SW_MODULE_HANDLE = (DWORD)pGetModuleHandleA( sw_dll );
	HL_EXE_HANDLE = (DWORD)pGetModuleHandleA( NULL );
}

//-------------------------------------------------------------------//

bool GetModuleInfo()// INITIALIZE INFORMATION
{
	char client_dll[] = { 'c','l','i','e','n','t','.','d','l','l',0 };
	char gameui_dll[] = { 'G','a','m','e','U','I','.','d','l','l',0 };

	GetRenderType();

	if ( HW_MODULE_HANDLE )
		HW_MODULE_BASE = HW_MODULE_HANDLE;
	else if ( SW_MODULE_HANDLE )
		HW_MODULE_BASE = SW_MODULE_HANDLE;
	else
		HW_MODULE_BASE = HL_EXE_HANDLE;

	HW_MODULE_SIZE = GetModuleSize( HW_MODULE_BASE );
	HW_MODULE_END = HW_MODULE_BASE + HW_MODULE_SIZE - 1;

	HL_EXE_BASE = HL_EXE_HANDLE;
	HL_EXE_SIZE = (DWORD)GetModuleSize( HL_EXE_BASE );
	HL_EXE_END = HL_EXE_BASE + HL_EXE_SIZE - 1;

	CLIENT_MODULE_BASE = (DWORD)pGetModuleHandleA( client_dll );

	if ( CLIENT_MODULE_BASE )
	{
		CLIENT_MODULE_SIZE = GetModuleSize( CLIENT_MODULE_BASE );
		CLIENT_MODULE_END = CLIENT_MODULE_BASE + CLIENT_MODULE_SIZE - 1;
	}
	else
	{
		CLIENT_MODULE_BASE = HW_MODULE_BASE;
		CLIENT_MODULE_END = HW_MODULE_END;
		CLIENT_MODULE_SIZE = HW_MODULE_SIZE;
	}
		
	VgBase = (DWORD)pGetModuleHandleA( gameui_dll );
	
	if ( VgBase )
	{
		VgSize = (DWORD)GetModuleSize( VgBase );
		VgEnd = VgBase + VgSize - 1;
	}

	return ( HW_MODULE_BASE && CLIENT_MODULE_BASE && HL_EXE_BASE && VgBase );
}

//-------------------------------------------------------------------//
//-------------------------------------------------------------------//
//-------------------------------------------------------------------//
//-------------------------------------------------------------------//
//-------------------------------------------------------------------//

DWORD FarProc( DWORD Address , DWORD LB , DWORD HB )
{
	return ( ( Address < LB ) || ( Address > HB ) );
}

//-------------------------------------------------------------------//

#define CompareMemory(Buff1, Buff2, Size) __comparemem((const UCHAR *)Buff1, (const UCHAR *)Buff2, (UINT)Size)
#define FindMemoryClone(Start, End, Clone, Size) __findmemoryclone((const ULONG)Start, (const ULONG)End, (const ULONG)Clone, (UINT)Size)
#define FindReference(Start, End, Address) __findreference((const ULONG)Start, (const ULONG)End, (const ULONG)Address)

BOOL __comparemem(const UCHAR *buff1, const UCHAR *buff2, UINT size)
{
	for (UINT i = 0; i < size; i++, buff1++, buff2++)
	{
		if ((*buff1 != *buff2) && (*buff2 != 0xFF))
			return FALSE;
	}
	return TRUE;
}

ULONG __findmemoryclone(const ULONG start, const ULONG end, const ULONG clone, UINT size)
{
	for (ULONG ul = start; (ul + size) < end; ul++)
	{
		if (CompareMemory(ul, clone, size))
			return ul;
	}
	return NULL;
}

ULONG __findreference(const ULONG start, const ULONG end, const ULONG address)
{
	UCHAR Pattern[5];
	Pattern[0] = 0x68;
	*(ULONG*)&Pattern[1] = address;
	return FindMemoryClone(start, end, Pattern, sizeof(Pattern)-1);
}

//-------------------------------------------------------------------//

void* ClientFuncs(void)
{
	bool bMustLeave = false;

	PCHAR String = "ScreenFade\0";
//	PCHAR String = (char*)/*ScreenFade\0*/XorStr<0x71,12,0xC92AD028>("\x22\x11\x01\x11\x10\x18\x31\x19\x1D\x1F\x7B"+0xC92AD028).s;
	DWORD Address = (DWORD)FindMemoryClone(HW_MODULE_BASE, HW_MODULE_BASE+HW_MODULE_SIZE, String, strlen(String));
	PVOID ClientPtr = (PVOID)*(PDWORD)(FindReference(HW_MODULE_BASE, HW_MODULE_BASE+HW_MODULE_SIZE, Address) + 0x13);
	
	if ( FarProc((DWORD)ClientPtr,HW_MODULE_BASE,HW_MODULE_END) )
	{
//		Error((char*)"Couldn't find ClientPtr pointer.\0");
		bMustLeave = true;
	}
	
	if(!bMustLeave)
	{
		return ClientPtr;
	}

	return 0;
}

//-------------------------------------------------------------------//

void* EngineFuncs(void)
{
	bool bMustLeave = false;

	PCHAR String = "ScreenFade\0";
//	PCHAR String = (char*)/*ScreenFade\0*/XorStr<0x71,12,0xC92AD028>("\x22\x11\x01\x11\x10\x18\x31\x19\x1D\x1F\x7B"+0xC92AD028).s;
	DWORD Address = FindMemoryClone(HW_MODULE_BASE, HW_MODULE_BASE+HW_MODULE_SIZE, String, strlen(String));
	PVOID EnginePtr = (PVOID)*(PDWORD)(FindReference(HW_MODULE_BASE, HW_MODULE_BASE+HW_MODULE_SIZE, Address) + 0x0D);
	
	if ( FarProc((DWORD)EnginePtr,HW_MODULE_BASE,HW_MODULE_END) )
	{
//		Error((char*)"Couldn't find EnginePtr pointer.\0");
		bMustLeave = true;
	}

	if(!bMustLeave)
	{
		return EnginePtr;
	}

	return 0;
}

//-------------------------------------------------------------------//

bool CheckByte(DWORD Address, BYTE Value, int Offset)
{
	if (*(PBYTE)((DWORD)Address + Offset) == Value)
		return true;
	else
		return false;
}

//-------------------------------------------------------------------//

DWORD EngineStudio(void)
{
	bool bMustLeave = false;

//start_ptr:
	bool badptr = false;
	DWORD OLD = 0;
	DWORD dwStudioone = 0;
	PCHAR String = "Couldn't get client .dll studio model rendering interface.\0";
//	PCHAR String = (char*)/*Couldn't get client .dll studio model rendering interface.\0*/XorStr<0x75,60,0x116A3BA5>("\x36\x19\x02\x14\x1D\x14\x5C\x08\x5D\x19\x1A\xF4\xA1\xE1\xEF\xED\xE0\xE8\xF3\xA8\xA7\xEE\xE7\xE0\xAD\xFD\xFB\xE5\xF5\xFB\xFC\xB4\xF8\xF9\xF3\xFD\xF5\xBA\xE9\xF9\xF3\xFA\xFA\xD2\xC8\xCC\xC4\x84\xCC\xC8\xD3\xCD\xDB\xCC\xCA\xCF\xC8\x80\xAF"+0x116A3BA5).s;
	DWORD Address = FindMemoryClone(HW_MODULE_BASE, HW_MODULE_BASE+HW_MODULE_SIZE, String, strlen(String));
	PVOID EngineStudioPtr = (PVOID)*(PDWORD)(FindReference(HW_MODULE_BASE, HW_MODULE_BASE+HW_MODULE_SIZE, Address) - 0x14);

	if ( FarProc((DWORD)EngineStudioPtr,HW_MODULE_BASE,HW_MODULE_END) )
	{
//		Error((char*)"Couldn't find EngineStudioPtr #1 pointer.\0");
		bMustLeave = true;
	}

	if(!bMustLeave)
	{
		if(!g_pClient)
		{
			return  0;
		}

	for(DWORD i = 0;i <= 60;i++)
	{
		dwStudioone = (DWORD)g_pClient->HUD_GetStudioModelInterface + i;

		if ( CheckByte(dwStudioone,0xB8,0) || CheckByte(dwStudioone,0xBF,0) )
		{
			dwStudioone++;

			if ( IsBadReadPtr((PDWORD)(*(PDWORD)dwStudioone),sizeof(engine_studio_api_s)) )
				badptr = true;
			else
				badptr = false;

			if ( badptr == false ) 
			{
				if ( *(PWORD)(PDWORD)EngineStudioPtr == *(PWORD)(PDWORD)(*(PDWORD)dwStudioone) )
				{
					return *(PDWORD)dwStudioone;
				}
			}
		}
	}
	}

//	goto start_ptr;
	return  0;
}

//-------------------------------------------------------------------//
//-------------------------------------------------------------------//
//-------------------------------------------------------------------//
//-------------------------------------------------------------------//
//-------------------------------------------------------------------//

int LoadOffsets()
{
	GetModuleInfo();
	g_pClient = (cl_clientfunc_t*)ClientFuncs();
	pEngfuncs = (cl_enginefunc_t*)EngineFuncs();
	pstudio = (engine_studio_api_t*)EngineStudio();

	if(!g_pClient)
	{
		return -101;
	}
	if(!pEngfuncs)
	{
		return -102;
	}
	if(!pstudio)
	{
		return -103;
	}

	memcpy( &g_Client, (LPVOID)g_pClient, sizeof( cl_clientfunc_t ) );
	memcpy( &gEngfuncs, pEngfuncs, sizeof(cl_enginefunc_t) );
	memcpy( &IEngineStudio, pstudio, sizeof(engine_studio_api_t) );
	//	RtlCopyMemory(&g_Client, (LPVOID)g_pClient, sizeof(cl_enginefunc_t));
	//	RtlCopyMemory(&gEngfuncs, pEngfuncs, sizeof(cl_enginefunc_t));
	//	RtlCopyMemory(&IEngineStudio, pstudio, sizeof(engine_studio_api_t));

	return 0;
}

//-------------------------------------------------------------------//
