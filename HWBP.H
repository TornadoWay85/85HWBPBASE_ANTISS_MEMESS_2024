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

void* GetMainThread();
void SetMainThread(DWORD dwVal/*GetMainThread()*/);

DWORD GetMainThreadTID();
void SetMainThreadTID(DWORD dwVal/*GetMainThreadTID()*/);

//-------------------------------------------------------------------//

int InstallHardwareBreakpoints();
void SetReturnValue(int iRetX);
int GetReturnValue();
DWORD WINAPI SetupHWBPHooks( LPVOID param );
void INITHWBP();

//-------------------------------------------------------------------//




