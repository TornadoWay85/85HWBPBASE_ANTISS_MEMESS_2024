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

float  ClientTime::mapTime    = 0;
double ClientTime::current    = 0;
DWORD  ClientTime::current_ms = 0;

//-------------------------------------------------------------------//

void ClientTime::reportMapTime(float mapTimeNew)
{
	mapTime = mapTimeNew;
	updateCurrentTime();	
}

//-------------------------------------------------------------------//

void ClientTime::updateCurrentTime()
{
	current_ms = timeGetTime();
	current = (double)current_ms / 1000.0;
}

//-------------------------------------------------------------------//


