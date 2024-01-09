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

extern cl_clientfunc_t *g_pClient;
extern cl_clientfunc_t g_Client;
//extern ClientDll_t gClientDll;

extern cl_enginefuncs_s * pEngfuncs;
extern struct cl_enginefuncs_s gEngfuncs;

extern engine_studio_api_s * pstudio;
extern struct engine_studio_api_s IEngineStudio;

//-------------------------------------------------------------------//

bool GetModuleInfo();
void* ClientFuncs(void);
void* EngineFuncs(void);
DWORD EngineStudio(void);

//-------------------------------------------------------------------//

int LoadOffsets();

//-------------------------------------------------------------------//
