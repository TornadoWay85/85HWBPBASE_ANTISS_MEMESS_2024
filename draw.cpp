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
//-------------------------------------------------------------------//

void DrawConString (int x, int y, int r, int g, int b, const char* fmt, ... )
{
	va_list va_alist;
	char buf[256]="\0";
	va_start(va_alist, fmt);
	_vsnprintf(buf, sizeof(buf), fmt, va_alist);
	va_end(va_alist);
	int length, height;
	y += 4;

	gEngfuncs.pfnDrawConsoleStringLen( buf, &length, &height );
	gEngfuncs.pfnDrawSetTextColor(r/255.0f, g/255.0f, b/255.0f);
	gEngfuncs.pfnDrawConsoleString(x,y,buf);
}

//-------------------------------------------------------------------//

void DrawConStringCenter (int x, int y, int r, int g, int b, const char* fmt, ... )
{
	va_list va_alist;
	char buf[256]="\0";
	va_start(va_alist, fmt);
	_vsnprintf(buf, sizeof(buf), fmt, va_alist);
	va_end(va_alist);
	int length, height;
	gEngfuncs.pfnDrawConsoleStringLen( buf, &length, &height );
	x -= length/2;
	y += 4;
	gEngfuncs.pfnDrawSetTextColor(r/255.0f, g/255.0f, b/255.0f);
	gEngfuncs.pfnDrawConsoleString(x,y,buf);
}

//-------------------------------------------------------------------//

void DrawHudString (int x, int y, int r, int g, int b, const char* fmt, ... )
{
	va_list va_alist;
	char buf[256]="\0";
	va_start (va_alist, fmt);
	_vsnprintf (buf, sizeof(buf), fmt, va_alist);
	va_end (va_alist);

	gEngfuncs.pfnDrawSetTextColor(r/255.0,g/255.0,b/255.0);
	gEngfuncs.pfnDrawConsoleString(x,y,buf);
//	gEngfuncs.pfnDrawSetTextColor(/*(float)*/r/255.0,/*(float)*/g/255.0,/*(float)*/b/255.0);
//	gEngfuncs.pfnDrawConsoleString(x,y,buf);
}

//-------------------------------------------------------------------//







