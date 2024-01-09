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

#pragma comment(lib,"winmm.lib\0")

#pragma comment(lib,"GLaux.lib\0")

#pragma comment(lib,"OpenGL32.lib\0")

#pragma comment(lib,"GLu32.lib\0")// symbol _gluBuild2DMipmaps@28

//#pragma comment(lib,"GLaux.lib\0")

//-------------------------------------------------------------------//

#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NON_CONFORMING_SWPRINTFS

#ifndef __cplusplus
#define __cplusplus
#endif

#ifndef UNICODE
//#define UNICODE
#endif

//-------------------------------------------------------------------//

#include <windows.h>
#include <assert.h>
#include <list> // ->>>> ScheduleList
#include <map> // ->>>> playeritems y stringfinder
#include <math.h>
#include <stdio.h>
#include <string>
#include <time.h>
#include <TLHELP32.H>
#include <vector>

#include <fstream>

using namespace std;

#include <gl\gl.h>
#include <gl\glu.h>
//#include <gl\glut.h>
#include <gl\glaux.h>
//#include "glaux.h"

//-------------------------------------------------------------------//

#define MAX_PATH_ARRAY_SIZE 400

//-------------------------------------------------------------------//

#include "CVARS.h"
#include "timehandling.h"

#include "client_headers.h"
#include "client.h"

#include "res/resource.h"
//#include "peb.h"

#include "AUTOOFFSETS.h"

#include "antiss/antiss.h"
#include "antiss/bmpresize.h"
#include "antiss/opengl_callgates.h"
#include "antiss/readpixels.h"
#include "antiss/screenshot.h"

#include "draw.h"
#include "drawgl.h"
#include "menu/menu_nk.h"
#include "HWBP.h"
#include "WINAPI.h"
#include "XENGINE.h"
#include "xorstr.h"

//-------------------------------------------------------------------//

bool FileExists(const char* filename);
const char* getOgcDirFile(const char* basename);
void GetFileFullPathFromTEMP(char* wsPath, const char* wsFilename);
void logme1(const char *fmt, ... );

//-------------------------------------------------------------------//


