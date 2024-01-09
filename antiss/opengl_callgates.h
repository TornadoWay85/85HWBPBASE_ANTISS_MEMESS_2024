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

typedef void (APIENTRY* t_glPixelStorei) (GLenum pname, GLint param);
typedef void (APIENTRY* t_glReadPixels) (GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid *pixels);

extern t_glPixelStorei pOrig_glPixelStorei;
extern t_glReadPixels pOrig_glReadPixels;

void __stdcall CallGate_glReadPixels_5(GLint x, GLint y, 
									   GLsizei width,GLsizei height, 
									   GLenum format, GLenum type, GLvoid* pixels);
void __stdcall CallGate_glPixelStorei_5(GLenum pname, GLint param);

//-------------------------------------------------------------------//

int InitOpenGLPointers();

//-------------------------------------------------------------------//

