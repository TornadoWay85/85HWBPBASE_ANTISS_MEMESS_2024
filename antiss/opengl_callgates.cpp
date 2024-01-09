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

#include "../mainheaders.h"

//-------------------------------------------------------------------//

/*
unsigned int counter_glPixelStorei=0;
unsigned int counter_glReadPixels=0;
DWORD funcs_glPixelStorei[2]={0};
DWORD funcs_glReadPixels[2]={0};
*/

/*
typedef void (APIENTRY* t_glPixelStorei) (GLenum pname, GLint param);
typedef void (APIENTRY* t_glReadPixels) (GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid *pixels);
*/

t_glPixelStorei pOrig_glPixelStorei=0;
t_glReadPixels pOrig_glReadPixels=0;

//-----------------------------------------------------------------------------------------------------------------------------------------------------

__declspec(naked) 
void __stdcall CallGate_glReadPixels_5(GLint x, GLint y, 
									   GLsizei width,GLsizei height, 
									   GLenum format, GLenum type, GLvoid* pixels)
{
//	__asm push ebp
//	__asm mov ebp, esp
//	__asm pop ebp
//	__asm MOV EDX,DWORD PTR FS:[0x18]

	__asm MOV EDI,EDI
	__asm PUSH EBP
	__asm MOV EBP,ESP
	__asm jmp pOrig_glReadPixels //5 (HARCODED FOR WIN10 64 HOME)
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------

__declspec(naked) 
void __stdcall CallGate_glPixelStorei_5(GLenum pname, GLint param)
{
//	__asm push ebp
//	__asm mov ebp, esp
//	__asm pop ebp
//	__asm MOV EDX,DWORD PTR FS:[0x18]

	__asm MOV EDI,EDI
	__asm PUSH EBP
	__asm MOV EBP,ESP
	__asm jmp pOrig_glPixelStorei //5 (HARCODED FOR WIN10 64 HOME)
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------

int InitOpenGLPointers()
{
	int iReturnValue = 0;

	pOrig_glPixelStorei=(t_glPixelStorei)pGetProcAddress(pGetModuleHandleA(/*Opengl32.dll\0*/XorStr<0x79,14,0xC8374514>("\x36\x0A\x1E\x12\x1A\x12\x4C\xB2\xAF\xE6\xEF\xE8\x85"+0xC8374514).s), 
		/*glPixelStorei\0*/XorStr<0xB6,15,0x8F3FA6E3>("\xD1\xDB\xE8\xD0\xC2\xDE\xD0\xEE\xCA\xD0\xB2\xA4\xAB\xC3"+0x8F3FA6E3).s
	);

	if(pOrig_glPixelStorei)
	{
		pOrig_glPixelStorei = (t_glPixelStorei)((DWORD)pOrig_glPixelStorei+5);//5 (HARCODED FOR WIN10 64 HOME)
	}
	else
	{
		iReturnValue = -1;
	}

	pOrig_glReadPixels=(t_glReadPixels)pGetProcAddress(pGetModuleHandleA(/*Opengl32.dll\0*/XorStr<0x6F,14,0x83FEDAF6>("\x20\x00\x14\x1C\x14\x18\x46\x44\x59\x1C\x15\x16\x7B"+0x83FEDAF6).s), 
		/*glReadPixels\0*/XorStr<0xA3,14,0x01751038>("\xC4\xC8\xF7\xC3\xC6\xCC\xF9\xC3\xD3\xC9\xC1\xDD\xAF"+0x01751038).s
	);

	if(pOrig_glReadPixels)
	{
		pOrig_glReadPixels = (t_glReadPixels)((DWORD)pOrig_glReadPixels+5);//5 (HARCODED FOR WIN10 64 HOME)
	}
	else
	{
		iReturnValue = -2;
	}

	return iReturnValue;
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------









































