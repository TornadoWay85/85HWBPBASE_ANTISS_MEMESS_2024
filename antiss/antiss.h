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

extern bool bAntiSSInstalledOK;

//-------------------------------------------------------------------//

extern bool bAntiSSStarted;
extern GLubyte* g_CleanSS;
extern unsigned char* g_MemeSS;
extern StopTimer screentime;
extern unsigned int frames_ss;
extern bool bAntissOrder;
extern int message_hook;
extern bool bRedrawMark;

//-------------------------------------------------------------------//

void TakeSS(unsigned int h, unsigned int w);
void TakeTestSS();
void WatchSS();
void DrawAntiSSInfo();

//-------------------------------------------------------------------//

void func_testss();
void func_seess();
void func_memess();
void func_antissactive();
void func_antissenable();
void func_launchantiss();

//-------------------------------------------------------------------//

void register_antiss_commands();
void register_antiss_engine_commands();

//-------------------------------------------------------------------//












